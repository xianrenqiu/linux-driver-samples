KERNELDIR = /lib/modules/`uname -r`/build

#Kernel modules
obj-m += export.o

#EXTRA_CFLAGS=-g -o0

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean