ALL: compile run

compile:
	g++ -I ./include/ -o ./lib/Chromosome.o -c ./src/Chromosome.cpp
	g++ -I ./include/ -o ./lib/Main.o -c ./src/Main.cpp
	g++ -o ./bin/TEST ./lib/Chromosome.o ./lib/Main.o

run:
	./bin/TEST
