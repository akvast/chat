
mkdir ../gen
mkdir ../gen/cpp

protoc \
   --cpp_out=../gen/cpp \
   network.proto