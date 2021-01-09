# PROTOC_IMAGE := thethingsindustries/protoc:3.1.31
PROTOC_IMAGE := protoc

#-----------------------------------------------------------------------------
# BUILD
#-----------------------------------------------------------------------------

.PHONY: all
all:
	docker run --rm -v $$(pwd):$$(pwd) -w $$(pwd) $(PROTOC_IMAGE) \
		nanopb_generator \
		-D src \
		-x "github.com/gogo/protobuf/gogoproto/gogo.proto" \
		domopool.proto

	docker run --rm -v $$(pwd):$$(pwd) -w $$(pwd) $(PROTOC_IMAGE) \
		protoc-wrapper \
		-I/usr/include \
		-I. \
		--gogoslick_out=$(GOPATH)/src \
		--js_out=import_style=commonjs,binary:js \
		domopool.proto
