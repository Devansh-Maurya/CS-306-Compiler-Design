obj-m += hello_1.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:
	sudo dmesg -C
	sudo insmod hello_1.ko
	sudo rmmod hello_1.ko
	dmesg
	modinfo hello_1.ko
