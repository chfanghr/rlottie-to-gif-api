FROM conanio/clang10 as builder

ADD . ./

RUN mkdir build

WORKDIR build

RUN cmake -DCMAKE_BUILD_TYPE=Release ..

RUN cmake --build .

FROM ubuntu

COPY --from=builder /home/conan/build/service /usr/local/bin/service

EXPOSE 8000

ENTRYPOINT service