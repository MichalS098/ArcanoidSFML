#Automatic compilation using make                                                                                                                                                                                                             
#Just type in terminal 'make' and this will compile it for you                                                                                                                                                                                
CC = g++
CFLAGS = -Wall -Wextra -pedantic 		      			 #compiler flags                                                                                                                                     
LIBS = -lm -lsfml-graphics -lsfml-window -lsfml-system   #adding required libraries                                                                                                                          

all: main.o ball.o
	$(CC) $(CFLAGS) obj/main.o obj/ball.o -o game $(LIBS)

main.o: src/main.cpp inc/ball.hh
	$(CC) $(CFLAGS) src/main.cpp -c -o obj/main.o $(LIBS)

ball.o: src/ball.cpp inc/ball.hh
	$(CC) $(CFLAGS) src/ball.cpp -c -o obj/ball.o $(LIBS)

run: 
	./game
	
clean:
	rm -f obj/*.o game
#command 'make clean' will delete files with .o extension

help:
	@echo
	@echo   make - compiles program
	@echo 	make run - runs program
	@echo	make clean - deleteing files with .o extension and executable
	@echo