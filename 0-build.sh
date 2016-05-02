#!/bin/sh

#!/bin/sh

# Fails on GCC 5, prereq
# sudo ln -s /usr/bin/arm-linux-gnueabi-gcc-4.7 /usr/local/bin/arm-linux-gnueabi-gcc

CROSS_COMPILE=arm-linux-gnueabi- ARCH=arm make clean
CROSS_COMPILE=arm-linux-gnueabi- ARCH=arm make smdk5410_config
CROSS_COMPILE=arm-linux-gnueabi- ARCH=arm make -j4
