PROTOC_IMAGE := thethingsindustries/protoc:3.1.31

#-----------------------------------------------------------------------------
# BUILD
#-----------------------------------------------------------------------------

.PHONY: all
all:
	nanopb_generator -D src domopool.proto
	docker run --rm -v $$(pwd):$$(pwd) -w $$(pwd) $(PROTOC_IMAGE) \
		-I. \
		--go_out=$(GOPATH)/src \
		--js_out=import_style=commonjs,binary:js \
		domopool.proto
