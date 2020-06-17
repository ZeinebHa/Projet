LFLAGS = `sdl-config --libs` -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
OBJS   = main.o fc.o
programme = prog
CXX = gcc

all: $(programme)

%.o: %.c %.h 
	$(CXX) $(CFLAGS) -c -s $<

$(programme): $(OBJS)
	$(CXX) $(OBJS) -o $(programme) $(LFLAGS)


clean:
	rm $(programme) *.o
