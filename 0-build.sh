#!/bin/sh

CROSS_COMPILE=arm-linux-gnueabihf- ARCH=arm make clean
CROSS_COMPILE=arm-linux-gnueabihf- ARCH=arm make odroid_config
CROSS_COMPILE=arm-linux-gnueabihf- ARCH=arm make -j4
