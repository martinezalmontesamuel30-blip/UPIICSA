CC = gcc
CFLAGS = -Wall -g

# Reemplaza main.c por el nombre real de tu archivo
SRCS = Holamundo.c
OBJS = $(SRCS:.c=.o)
TARGET = programa

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
