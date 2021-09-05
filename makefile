#Automatic compilation using make                                                                                                                                                                                                             
#Just type in terminal 'make' and this will compile it for you                                                                                                                                                                                
CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++17 		     #compiler flags                                                                                                                                     
LIBS = -lm -lsfml-graphics -lsfml-window -lsfml-system   #adding required libraries                                                                                                                          

all: main.o ball.o paddle.o menu.o
	$(CC) $(CFLAGS) obj/main.o obj/ball.o obj/paddle.o obj/menu.o -o game $(LIBS)

main.o: src/main.cpp inc/ball.hh inc/paddle.hh
	$(CC) $(CFLAGS) src/main.cpp -c -o obj/main.o $(LIBS)

ball.o: src/ball.cpp inc/ball.hh
	$(CC) $(CFLAGS) src/ball.cpp -c -o obj/ball.o $(LIBS)

paddle.o: src/paddle.cpp inc/paddle.hh
	$(CC) $(CFLAGS) src/paddle.cpp -c -o obj/paddle.o $(LIBS)

menu.o: src/menu.cpp inc/menu.hh
	$(CC) $(CFLAGS) src/menu.cpp -c -o obj/menu.o $(LIBS)


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