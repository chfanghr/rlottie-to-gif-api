FROM conanio/clang10 as builder

ADD . /source

WORKDIR /source

RUN git submodule update --init

WORKDIR /source/build

RUN conan install ../ --build=missing

RUN cmake -DCMAKE_BUILD_TYPE=Release ..

RUN cmake --build .

FROM ubuntu

COPY --from=builder /source/build/bin/service /usr/local/bin/service

EXPOSE 8000

ENTRYPOINT service