hespi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/AramaAgac.o -c ./src/AramaAgac.cpp
	g++ -I ./include/ -o ./lib/islem.o -c ./src/islem.cpp
	g++ -I ./include/ -o ./lib/Kuyruk.o -c ./src/Kuyruk.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/AramaAgac.o ./lib/islem.o ./src/Test.cpp
	
calistir:
	./bin/Test