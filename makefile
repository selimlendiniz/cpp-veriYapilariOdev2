all:derle bagla

derle:
	g++ -g -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -g -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o
	g++ -g -c -I "./include" ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -g -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o
	g++ -g -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -g -c -I "./include" ./src/Sistem.cpp -o ./lib/Sistem.o
	g++ -g -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o
	g++ -g -c -I "./include" ./src/Kuyruk.cpp -o ./lib/Kuyruk.o






bagla:
	g++ -g ./lib/main.o ./lib/Radix.o ./lib/Kuyruk.o ./lib/Doku.o ./lib/Hucre.o ./lib/Organ.o ./lib/Organizma.o ./lib/Sistem.o -o ./bin/program

calistir:
	./bin/program.exe