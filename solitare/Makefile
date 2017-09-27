TARGET=solitare
CC=g++
CPPFLAGS=-Wall -I/usr/include/GL -fpermissive -I../
LDFLAGS= -pthread 
# LIBS=

OBJS=solitare.o main.o
SRC=.solitare.cpp main.cpp
INCLUDES=

$(TARGET): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(OBJ): $(SRC) $(INCLUDES)
	$(CC) $(CPPFLAGS) -c $(@:.o=.cpp) $(LDFLAGS)

clean:
	@rm -f $(OBJS) $(TARGET)
