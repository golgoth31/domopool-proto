PROTOC_IMAGE := thethingsindustries/protoc:3.1.26

#-----------------------------------------------------------------------------
# BUILD
#-----------------------------------------------------------------------------

.PHONY: all
all:
	nanopb_generator -D src domopool.proto
	docker run --rm -v $$(pwd):$$(pwd) -w $$(pwd) $(PROTOC_IMAGE) \
		-I. \
		--go_out=$(GOPATH)/src \
		domopool.proto
