# PROTOC_IMAGE := thethingsindustries/protoc:3.1.31
PROTOC_IMAGE := protoc

#-----------------------------------------------------------------------------
# BUILD
#-----------------------------------------------------------------------------

.PHONY: all
all:
	docker build -t protoc .
	docker run --rm -v $$(pwd):$$(pwd) -w $$(pwd) $(PROTOC_IMAGE) \
		nanopb_generator \
		-D src \
		domopool.proto
		# -x "github.com/gogo/protobuf/gogoproto/gogo.proto" \

	docker run --rm -v $$(pwd):$$(pwd) -w $$(pwd) $(PROTOC_IMAGE) \
		protoc-wrapper \
		-I/usr/include \
		-I. \
		--go_out=$(GOPATH)/src \
		--js_out=import_style=commonjs,binary:js \
		domopool.proto

	# docker run --rm -v $$(pwd):$$(pwd) -w $$(pwd) $(PROTOC_IMAGE) \
	# 	protoc-wrapper \
	# 	-I/usr/include \
	# 	-I. \
	# 	--js_out=import_style=commonjs,binary:js \
	# 	domopool.proto /usr/include/github.com/gogo/protobuf/gogoproto/gogo.proto
