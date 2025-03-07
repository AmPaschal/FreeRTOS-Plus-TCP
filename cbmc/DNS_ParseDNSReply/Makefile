# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/source/FreeRTOS_DNS_Parser.c # $(ROOT)/source/FreeRTOS_IP_Utils.c $(ROOT)/source/FreeRTOS_IP.c

# Harness to utilize, omit the extension!
H_ENTRY = DNS_ParseDNSReply

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1 --unwindset DNS_ReadNameField.0:2 --unwindset DNS_ReadNameField.1:2 --unwindset DNS_ParseDNSReply.0:2


H_DEF = 

H_INC = -I$(ROOT) -I../include/ -I$(ROOT)/sys/include/  \
        -I$(ROOT)/test/FreeRTOS-Kernel/include \
        -I$(ROOT)/source/include

ENABLE_BUILD = 0

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
