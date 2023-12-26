CC = g++
CFLAGS = -Wall -g
OBJDIR = objects

main: $(OBJDIR)/main.o $(OBJDIR)/field.o
	$(CC) $(CFLAGS) -o main $^

$(OBJDIR)/main.o: main.cpp field.h
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/field.o: field.h field.cpp
	$(CC) $(CFLAGS) -c field.cpp -o $(OBJDIR)/field.o

$(OBJDIR)/inputHandler.o: inputHandler.h inputHandler.cpp
	$(CC) $(CFLAGS) -c inputHandler.cpp -o $(OBJDIR)/inputHandler.o