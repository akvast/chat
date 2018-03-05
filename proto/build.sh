#!/usr/bin/env bash

rm -rf ../gen

mkdir ../gen
mkdir ../gen/cpp

../djinni/src/run \
   --java-out ../gen/java/com/github/akvast/securechat \
   --java-package com.github.akvast.securechat \
   --ident-java-field mFooBar \
   \
   --cpp-out ../gen/cpp \
   --cpp-namespace generated \
   --ident-cpp-file FooBar \
   --cpp-optional-template "boost::optional" \
   --cpp-optional-header "<boost/optional.hpp>" \
   \
   --jni-out ../gen/jni \
   --ident-jni-class JFooBar \
   --ident-jni-file JFooBar \
   --jni-include-cpp-prefix "../cpp/" \
   \
   --objc-out ../gen/objc \
   --objcpp-out ../gen/objc \
   --ident-objc-type OFooBar \
   --ident-objc-file OFooBar \
   \
   --idl ./all.djinni

protoc \
   --cpp_out=../gen/cpp \
   network.proto \
   network_structs.proto