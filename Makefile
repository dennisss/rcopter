BUILD_PATH = bin
CC = gcc
AR = ar
CFLAGS += -g -w -fpermissive -pthread

rcopter_TARGET = bin/rcopter
rcopter_SRCS = src/rcopter.o src/motor.o src/pwm.o 

.SECONDARY: $(wildcard *.o)

rcopter: $(rcopter_SRCS)
	$(CC) $(CFLAGS) -o $(rcopter_TARGET) $?

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $?

clean:
	rm -f src/*.o
	rm -f bin/*
