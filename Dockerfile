# FROM thethingsindustries/protoc:3.1.32
FROM myprotoc:latest

RUN apk add --no-cache py3-pip \
  && python3 -m pip install nanopb
ENTRYPOINT []
