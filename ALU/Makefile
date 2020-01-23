#
CC=/usr/bin/g++
ARCH := $(shell arch)
SYSTEMC_HOME=/usr/local/SystemC-2.3.0

# 64bit or 32bit libaries to link to
LINUXLIB := $(shell if [ ${ARCH} = "i686" ]; \
                    then \
                         echo lib-linux; \
                    else \
                         echo lib-linux64; \
                    fi)

INCLUDES = -I$(SYSTEMC_HOME)/include -I.

LIBRARIES = -L. -L$(SYSTEMC_HOME)/$(LINUXLIB) -lsystemc -lm

RPATH = -Wl,-rpath=$(SYSTEMC_HOME)/$(LINUXLIB)

PROGRAM = ALU_complete.x
SRCS    =  barrelshift.cpp ALU.cpp sc_main.cpp
OBJS    =  barrelshift.o ALU.o sc_main.o

all : $(PROGRAM)

$(OBJS)	: $(SRCS)
	$(CC) $(INCLUDES) -c $(SRCS)

$(PROGRAM) : $(OBJS)
	$(CC) $(INCLUDES) $(LIBRARIES) $(RPATH) -o $(PROGRAM) $(OBJS)

clean:
	@rm -f $(OBJS) $(PROGRAM) *.cpp~ *.h~
