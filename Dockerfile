FROM rvolosatovs/protoc:3.2.0

RUN apk add --no-cache py3-pip \
  && python3 -m pip install nanopb
ENTRYPOINT []
