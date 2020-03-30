#!/bin/bash

cd build
# -C Debug is for Visual Studio only
ctest -C Debug -VV
