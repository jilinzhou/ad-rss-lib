#!/bin/bash

# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (c) 2019 Intel Corporation
#
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its contributors
#    may be used to endorse or promote products derived from this software without
#    specific prior written permission.
#
#    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
#    IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
#    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
#    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
#    OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
#    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
#    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#    POSSIBILITY OF SUCH DAMAGE.
#
# ----------------- END LICENSE BLOCK -----------------------------------
##

rm -rf build

mkdir build
cd build

if [ "$1" == "gcc" ]; then
  version=`gcc --version | grep "gcc" | awk '{ print $4}'`
  echo "Using gcc $version"
elif [ "$1" == "gcc-4" ]; then
  version=`/usr/bin/gcc-4.8 --version | grep "gcc" | awk '{ print $4}'`
  echo "Using gcc $version"
  export CC=/usr/bin/gcc-4.8
  export CXX=/usr/bin/g++-4.8
elif [ "$1" == "gcc-5" ]; then
  version=`/usr/bin/gcc-5 --version | grep "gcc" | awk '{ print $4}'`
  echo "Using gcc $version"
  export CC=/usr/bin/gcc-5
  export CXX=/usr/bin/g++-5
elif [ "$1" == "gcc-7" ]; then
  version=`/usr/bin/gcc-7 --version | grep "gcc" | awk '{ print $4}'`
  echo "Using gcc $version"
  export CC=/usr/bin/gcc-7
  export CXX=/usr/bin/g++-7
elif [ "$1" == "clang-5" ]; then
  version=`gcc --version | grep "clang" | awk '{ print $3}'`
  echo "Using clang $version"
  export CC=/usr/bin/clang-5
  export CXX=/usr/bin/clang++-5
elif [ "$1" == "clang-6" ]; then
  version=`gcc --version | grep "clang" | awk '{ print $3}'`
  echo "Using clang $version"
  export CC=/usr/bin/clang-6
  export CXX=/usr/bin/clang++-6
else
  echo "Unsupported compiler"
  exit 1
fi

if [ "$2" == "release" ]; then
  cmake .. -DBUILD_HARDENING=ON -DBUILD_COVERAGE=ON
elif [ "$2" == "debug" ]; then
  cmake .. -DBUILD_HARDENING=ON -DBUILD_COVERAGE=ON -DCMAKE_BUILD_TYPE=DEBUG
else
  echo "Unsupported mode"
  exit 1
fi

make

if [ "$3" == "test" ]; then
  ctest -V
fi

cd ..


