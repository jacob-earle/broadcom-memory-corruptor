obj-m += tg3_corruptor.o corruptor_chrdev.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

reader:
	gcc read_mapping.c -o read_mapping

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm read_mapping
