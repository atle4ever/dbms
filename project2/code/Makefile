.SUFFIXES: .cc .o

CC = g++
CFLAGS = -g -c
TARGET = simple_dbms

OBJS=Table.o Executor.o main.o
SRCS=Table.cc Executor.cc main.cc

$(TARGET): $(OBJS)
	$(CC) $(CLFAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET) .depend

%.o: %.cc *.h
	$(CC) $(CFLAGS) $< -o $@
