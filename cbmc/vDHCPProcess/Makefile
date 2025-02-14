# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/source/FreeRTOS_DHCP.c $(ROOT)/source/FreeRTOS_IP.c $(ROOT)/source/FreeRTOS_ARP.c $(ROOT)/source/FreeRTOS_IP_Timers.c

# Harness to utilize, omit the extension!
H_ENTRY = vDHCPProcess


# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --unwindset memcmp.0:7 --unwindset prvProcessDHCPReplies.0:4 --unwindset strlen.0:10


H_DEF =

H_INC = -I$(ROOT) -I../include/ -I$(ROOT)/sys/include/  \
        -I$(ROOT)/test/FreeRTOS-Kernel/include \
        -I$(ROOT)/source/include

# Include our special build file
include ../Makefile.include
