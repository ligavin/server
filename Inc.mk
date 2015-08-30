CC = gcc
CXX = g++
RANLIB = ranlib
AR = ar
AROPT=-scurv
 
BUILD=BUILD_DEV
#BUILD=BUILD_RELEASE

ifeq ($(BUILD), BUILD_DEV)
CFLAGS = -Wall -g -DDEBUGU
endif
ifeq ($(BUILD), BUILD_DEBUG)
CFLAGS = -Wall -g -DDEBUGU
endif
ifeq ($(BUILD), BUILD_NORMAL)
CFLAGS = -Wall -g -O -DREENTRANT
endif
ifeq ($(BUILD), BUILD_RELEASE)
CFLAGS = -Wall -g -O3 -pipe -DREENTRANT -DMSG_NEW
endif

CFLAGS += #-DNDS_WITH_SHM_AND_BOOST_SUPPOR

LIB_COMM = -L/usr/lib/x86_64-redhat-linux5E/lib64/