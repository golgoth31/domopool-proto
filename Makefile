PROTOC_IMAGE := protoc

#-----------------------------------------------------------------------------
# BUILD
#-----------------------------------------------------------------------------

.PHONY: all
all:
	podman build -t protoc .
	podman run --rm -v $$(pwd):$$(pwd) -w $$(pwd) $(PROTOC_IMAGE) \
		nanopb_generator \
		-D src \
		domopool.proto

	podman run --rm -v $$(pwd):$$(pwd) -w $$(pwd) $(PROTOC_IMAGE) \
		protoc \
		-I/usr/include \
		-I. \
		--go_out=$(GOPATH)/src \
		--js_out=import_style=commonjs,binary:js \
		--rust_out=rust/src \
		domopool.proto

	# podman run --rm -v $$(pwd):$$(pwd) -w $$(pwd) $(PROTOC_IMAGE) \
	# 	protoc \
	# 	-I/usr/include \
	# 	-I. \
	# 	--rust_out=. \
	# 	domopool.proto

	# podman run --rm -v $$(pwd):$$(pwd) -w $$(pwd) $(PROTOC_IMAGE) \
	# 	protoc-wrapper \
	# 	-I/usr/include \
	# 	-I. \
	# 	--js_out=import_style=commonjs,binary:js \
	# 	domopool.proto /usr/include/github.com/gogo/protobuf/gogoproto/gogo.proto
