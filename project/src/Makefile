# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: machine.elf

#additional rules for files
machine.elf: ${COMMON_OBJECTS} main.o buzzer.o switches.o p1_interrupt_handler.o stateMachines.o led.o wdInterruptHandler.o ../lib/libTimer.a 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: machine.elf
	msp430loader.sh machine.elf
	make clean

switches.o: switches.h led.h buzzer.h stateMachines.h

p1_interrupt_handler.o: switches.h

stateMachines.o: stateMachines.h led.h buzzer.h

led.o: led.h

buzzer.o: buzzer.h

wdInterruptHandler.o: stateMachines.h buzzer.h led.h switches.h


clean:
	rm -f *.o *.elf
