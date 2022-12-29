all:derle bagla calistir

derle:
	g++ -g -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o
	g++ -g -c -I "./include" ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -g -c -I "./include" ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o
	g++ -g -c -I "./include" ./src/Kuyruk.cpp -o ./lib/Kuyruk.o
	g++ -g -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -g -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o
	g++ -g -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -g -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o
	g++ -g -c -I "./include" ./src/Sistem.cpp -o ./lib/Sistem.o

bagla:
	g++ -g ./lib/Sistem.o ./lib/Radix.o ./lib/Organizma.o ./lib/Hucre.o ./lib/Doku.o ./lib/IkiliAramaAgaci.o ./lib/main.o ./lib/Kuyruk.o ./lib/Organ.o -o ./bin/program

calistir:
	./bin/program.exe