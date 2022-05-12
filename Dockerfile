FROM registry.hub.docker.com/rvolosatovs/protoc:3.3.0

RUN apk add --no-cache py3-pip \
  && python3 -m pip install nanopb
ENTRYPOINT []
