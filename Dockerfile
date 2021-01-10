FROM thethingsindustries/protoc:3.1.31

RUN apk add --no-cache py3-pip \
  && python3 -m pip install nanopb
ENTRYPOINT []
