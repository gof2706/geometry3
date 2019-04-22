CFLAGS = -Wall -Werror
OBJ = g++ $(CFAGS) -c $< -o $@

.PHONY: clean

all: target1 target2 bin/geometry.exe

target1:
	mkdir -p build

target2:
	mkdir -p bin

bin/geometry.exe: build/main.o build/getperim.o build/getarea.o
	g++ $(CFLAGS) $^ -o $@

build/main.o: src/main.cpp src/geometry.h
	$(OBJ)

build/getarea.o: src/getarea.cpp src/geometry.h
	$(OBJ)

build/getperim.o: src/getperim.cpp src/geometry.h
	$(OBJ)

clean:
	rm build/*.o
	rm bin/*.exe
	rm -R build
	rm -R bin

