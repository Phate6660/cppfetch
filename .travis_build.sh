#!/bin/bash
set -ev
meson build/ --reconfigure
ninja -C build/
./build/cppfetch l
