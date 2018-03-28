TARGET = memory3
OBJS = memory3.o

KDIR = /lib/modules/$(shell uname -r)/build
PWD = $(shell pwd)

obj-m += $(TARGET).o

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean	
