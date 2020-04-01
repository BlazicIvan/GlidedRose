#!/bin/bash

./build_tests.sh

cd build
ctest -VV
