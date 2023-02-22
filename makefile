hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include -o ./lib/AVL.o -c ./src/AVL.cpp
	g++ -I ./include -o ./bin/Test ./lib/Radix.o ./lib/Node.o ./lib/AVL.o ./src/Test.cpp
	
calistir:
	./bin/Test