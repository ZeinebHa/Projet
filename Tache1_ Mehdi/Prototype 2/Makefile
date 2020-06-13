prog:main.o collision.o player.o
	gcc main.o collision.o player.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm
collision.o:collision.c
	gcc -c collision.c
player.o:player.c
	gcc -c player.c

main.o:main.c
	gcc -c main.c
