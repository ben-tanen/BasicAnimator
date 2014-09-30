#
#  Makefile for BasicAnimator project
#

animator: main.o Canvas.o Sprite.o
	g++ -g -o animator main.o Canvas.o Sprite.o

main.o:  main.cpp Canvas.h
	g++ -g -Wall -Wextra -o main.o main.cpp -c

Canvas.o:  Canvas.cpp Canvas.h Sprite.h
	g++ -g -Wall -Wextra -o Canvas.o Canvas.cpp -c

Sprite.o:  Sprite.cpp Sprite.h
	g++ -g -Wall -Wextra -o Sprite.o Sprite.cpp -c

clean:
	rm -rf animator main.o Canvas.o Sprite.o
