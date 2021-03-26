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
machine.elf: ${COMMON_OBJECTS} main.o clocksTimer.o p1_interrupt_handler.o switches.o stateMachines.o led.o wdInterruptHandler.o buzzer.o libTimer.a 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: machine.elf
	msp430loader.sh machine.elf
	make clean

main.o: libTimer.h led.h buzzer.h switches.h

clocksTimer.o: libTimer.h

p1_interrupt_handler.o: switches.h

switches.o: switches.h led.h

stateMachines.o: stateMachines.h led.h buzzer.h

led.o: led.h

wdInterruptHandler.o: stateMachines.h

buzzer.o: libTimer.h buzzer.h
clean:
	rm -f *.o *.elf
