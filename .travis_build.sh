#!/bin/bash
set -ev
meson build/
ninja -C build/
./build/cppfetch l
