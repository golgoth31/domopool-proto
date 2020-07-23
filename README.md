# Domopool-proto

Proto file and generated artifacts for the [domopool project](https://github.com/golgoth31/domopool).

## nanopb

### Install

```bash
pip install nanopb --user
```

## Generate

### All

```bash
make all
```

### C++

```bash
nanopb_generator -D. domopool.proto
```

### golang

```bash
docker run --rm -v $(pwd):$(pwd) -w $(pwd) thethingsindustries/protoc:3.1.26 -I. --go_out=${GOPATH}/src domopool.proto
```
