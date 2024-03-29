CC = gcc
CFLAGS = -Wall -std=c99

SRCS = main.c book.c
OBJS = $(SRCS:.c=.o)
EXEC = book_manager

all: $(EXEC)

$(EXEC): $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(EXEC)