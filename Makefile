CC = gcc
CFLAGS = -Wall -g

# Lista tus archivos fuente aquí
SRCS = main.c funciones.c otra_archivo.c
OBJS = $(SRCS:.c=.o)
TARGET = programa

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
