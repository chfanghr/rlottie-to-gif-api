package main

import (
	"bytes"
	"encoding/json"
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

var apiEndpoint = flag.String("e", "http://localhost:8000", "")
var rlottieFilePath = flag.String("i", "", "")
var outputFilePath = flag.String("o", "", "")
var outputWidth = flag.Uint("w", 200, "")
var outputHeight = flag.Uint("h", 200, "")
var outputFps = flag.Float64("f", 60.0, "")

type RenderRequest struct {
	Width       uint32  `json:"width"`
	Height      uint32  `json:"height"`
	Fps         float64 `json:"fps"`
	IsTgs       bool    `json:"is_tgs"`
	RlottieData string  `json:"rlottie_data"`
}

type RenderError struct {
	Reason string `json:"reason"`
}

type RenderResult struct {
	Error   *RenderError `json:"error"`
	GifData []byte       `json:"gif_data"`
}

func panicIfError(err error) {
	if err != nil {
		log.Fatalf("unexpected error: %v", err)
	}
}

func main() {
	flag.Parse()

	if *rlottieFilePath == "" {
		log.Fatalln("path to rlottie file should be given")
	}

	if *outputFilePath == "" {
		*outputFilePath = *rlottieFilePath + ".gif"
	}

	rlottieData, err := ioutil.ReadFile(*rlottieFilePath)
	panicIfError(err)

	renderRequest := RenderRequest{
		Width:       uint32(*outputWidth),
		Height:      uint32(*outputHeight),
		IsTgs:       !json.Valid(rlottieData),
		Fps:         *outputFps,
		RlottieData: string(rlottieData),
	}

	jsonStr, err := json.Marshal(renderRequest)
	panicIfError(err)

	req, err := http.NewRequest("POST", *apiEndpoint, bytes.NewBuffer(jsonStr))
	panicIfError(err)
	req.Header.Set("Content-Type", "application/json")

	client := &http.Client{}
	resp, err := client.Do(req)
	panicIfError(err)

	//goland:noinspection GoUnhandledErrorResult
	defer resp.Body.Close()

	jsonDecoder := json.NewDecoder(resp.Body)
	renderResult := RenderResult{}
	panicIfError(jsonDecoder.Decode(&renderResult))

	if renderResult.Error != nil {
		panicIfError(fmt.Errorf("failed to render: %v", renderResult.Error.Reason))
	}

	panicIfError(ioutil.WriteFile(*outputFilePath, renderResult.GifData, 0666))
}
