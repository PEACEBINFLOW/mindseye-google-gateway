FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
  build-essential cmake git ca-certificates \
  libprotobuf-dev protobuf-compiler \
  && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . /app

RUN mkdir -p build && cd build && cmake .. && cmake --build . -j

ENV PORT=8080
EXPOSE 8080
CMD ["./build/mindseye_google_gateway"]
