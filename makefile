CFLAGS = -Wall -Werror
OBJ = g++ -std=c++11 $(CFLAGS) -c $< -o $@
TOBJT = g++ -std=c++11 $(CFLAGS) -I thirtdparty/catch2 -c $< -o $@
CFLAGS = -Wall -Werror
OBJ = g++ -std=c++11 $(CFLAGS) -c $< -o $@
TOBJT = g++ -std=c++11 $(CFLAGS) -I thirdparty/catch2 -c $< -o $@

.PHONY: clean

all: target1 target2 target3 target4 bin/geometry.exe

target1:
	mkdir -p build

target2:
	mkdir -p bin

target3:
	mkdir -p build/src

target4:
	mkdir -p build/test

bin/geometry.exe: build/src/main.o build/src/getperim.o build/src/getarea.o
	g++ -std=c++11 $(CFLAGS) $^ -o $@

build/src/main.o: src/main.cpp src/geometry.h
	$(OBJ)

build/src/getarea.o: src/getarea.cpp src/geometry.h
	$(OBJ)

build/src/getperim.o: src/getperim.cpp src/geometry.h
	$(OBJ)


bin/geometry-test: build/test/test.o build/test/getarea.o build/test/getperim.o
	g++ -std=c++11 $(CFLAGS)  $^ -o $@

build/test/test.o: test/test.cpp test/TESTgeometry.h
	$(TOBJT)

build/test/getarea.o: test/TESTgetarea.cpp test/TESTgeometry.h
	$(TOBJT)

build/test/getperim.o: test/TESTgetperim.cpp test/TESTgeometry.h
	$(TOBJT)


clean:
	rm build/*.o
	rm bin/*.exe
	rm -R -f build
	rm -R -f bin

