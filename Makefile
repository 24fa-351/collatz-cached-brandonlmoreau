


CC = gcc

CFLAGS = -Wall -g

SRCS = Collatz.c Cache.c CollatzMethods.c

OBJS = $(SRCS:.c=.o)

TARGET = collatz_program

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
