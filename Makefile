point2D.o: point2D.h point2D.cpp
	g++ -c point2D.cpp

bin/testPoint2D: testPoint2D.cpp point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o point2D.o

Shape.o: Shape.h Shape.cpp point2D.h
	g++ -c Shape.cpp

Circle.o: Circle.h Circle.cpp Shape.h point2D.h
	g++ -c Circle.cpp

bin/testCircle: testCircle.cpp Circle.o Shape.o point2D.o
	g++ -c testCircle.cpp
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o point2D.o

Rectangle.o: Rectangle.h Rectangle.cpp Shape.h point2D.h
	g++ -c Rectangle.cpp

bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o point2D.o
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.cpp Rectangle.o Shape.o point2D.o

Square.o: Square.h Square.cpp Rectangle.h Shape.h point2D.h
	g++ -c Square.cpp

bin/testSquare: testSquare.cpp Square.o Rectangle.o Shape.o point2D.o
	mkdir -p bin
	g++ -o bin/testSquare testSquare.cpp Square.o Rectangle.o Shape.o point2D.o

Drawing.o: Drawing.h Drawing.cpp Drawing.h Drawing.cpp Shape.h Circle.h Square.h ListArray.h List.h Shape.h point2D.h
	g++ -c Drawing.cpp

bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o point2D.o
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o point2D.o

clean:
	rm -f *.o bin/
