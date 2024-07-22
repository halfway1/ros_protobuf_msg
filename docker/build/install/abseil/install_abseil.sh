#!/usr/bin/env bash

set -e

cd "$(dirname "${BASH_SOURCE[0]}")"
# ....../abseil

#https://github.com/abseil/abseil-cpp/archive/refs/tags/20230802.0.tar.gz
# Install abseil.
THREAD_NUM=$(nproc)
VERSION="20230802.0"
PKG_NAME="abseil-cpp-${VERSION}.tar.gz"

tar xzf "${PKG_NAME}"
pushd "abseil-cpp-${VERSION}"
    mkdir build && cd build
    cmake .. \
        -DBUILD_SHARED_LIBS=ON \
        -DCMAKE_CXX_STANDARD=14 \
        -DCMAKE_INSTALL_PREFIX=/usr/local
    make -j${THREAD_NUM}
    make install
popd

# -DBUILD_SHARED_LIBS=ON：指定构建共享库
# -DCMAKE_INSTALL_PREFIX=/usr/local：指定安装路径为 /usr/local

ldconfig
# 在构建和安装新软件包后，运行 ldconfig 是个常见步骤，以确保系统能够找到并使用新安装的共享库

# Clean up
rm -rf "abseil-cpp-${VERSION}" "${PKG_NAME}"
