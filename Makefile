MESA = /usr/share/doc/mesa-utils
FLAGS = -Wall -lglut -lGLU -lGL -lm -lpthread  -lXext -lX11 
LIBPATH = $(MESA)/lib
OBJS = $(patsubst src/%.cpp, src/%.o, $(wildcard src/*.cpp))

exec: main
	./main

main: $(OBJS)
	g++ -o $@ $^ -L$(LIBPATH) $(FLAGS)

src/%.o: src/%.cpp
	g++ $(FLAGS) -c -Iinclude -o $@ $<

restart:
	-rm main
	-rm src/*.o
