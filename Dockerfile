FROM conanio/clang10 as builder

ADD . ./

RUN git submodule update --init

RUN mkdir build

WORKDIR build

RUN conan install ../ --build=missing

RUN cmake -DCMAKE_BUILD_TYPE=Release ..

RUN cmake --build .

FROM ubuntu

COPY --from=builder build/bin/service /usr/local/bin/service

EXPOSE 8000

ENTRYPOINT service