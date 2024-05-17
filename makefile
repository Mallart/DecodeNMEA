TARGET = nmea
SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJS = $(SOURCES:.c=.o)

all: $(OBJS)
	echo compiling files...
	gcc $(OBJS) -o $(TARGET)
	
%.o: %.c
	gcc -c $< -o $@

clean:
	rm -f $(OBJS)

.PHONY: all clean
