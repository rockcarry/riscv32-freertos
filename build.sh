#!/bin/bash

set -e

export LDFLAGS="--specs=picolibc.specs"

./autogen.sh
./configure --prefix=$PWD/_install --host=riscv32-picolibc-elf --disable-shared --enable-tests

make -j8 install

riscv32-picolibc-elf-objcopy -O binary $PWD/_install/bin/test $PWD/_install/bin/test.rom

