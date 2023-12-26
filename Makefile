CC = g++
CFLAGS = -Wall -g
OBJDIR = objects

main: $(OBJDIR)/main.o $(OBJDIR)/field.o $(OBJDIR)/InputHandler.o
	$(CC) $(CFLAGS) -o main $^

$(OBJDIR)/main.o: main.cpp field.h InputHandler.h
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/field.o: field.h field.cpp
	$(CC) $(CFLAGS) -c field.cpp -o $(OBJDIR)/field.o

$(OBJDIR)/InputHandler.o: InputHandler.h InputHandler.cpp field.h
	$(CC) $(CFLAGS) -c InputHandler.cpp -o $(OBJDIR)/InputHandler.o