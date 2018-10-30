all: main

main: main.o subway_entrance.o subway_station.o disj_sets.o subway_system.o subway_station_hash.o line.o subway_line_hash.o 
	g++ -std=c++11 -o main main.o subway_entrance.o subway_station.o disj_sets.o subway_system.o subway_station_hash.o line.o subway_line_hash.o 

main.o: main.cpp subway_entrance.cpp subway_entrance.h subway_station.h subway_system.h 
	g++ -std=c++11 -c  main.cpp

subway_entrance.o: subway_entrance.cpp subway_entrance.h
	g++ -std=c++11 -c subway_entrance.cpp

disj_sets.o: disj_sets.cpp disj_sets.h subway_entrance.h haversine.cpp
	g++ -std=c++11 -c disj_sets.cpp

subway_station.o: subway_station.cpp subway_station.h subway_entrance.h disj_sets.h
	g++ -std=c++11 -c subway_station.cpp

subway_system.o: subway_system.cpp subway_system.h subway_station.h subway_entrance.h haver.cpp
	g++ -std=c++11 -c subway_system.cpp

subway_station_hash.o: subway_station_hash.cpp subway_station_hash.h subway_station.h subway_entrance.h 
	g++ -std=c++11 -c subway_station_hash.cpp

line.o: line.cpp line.h subway_station.h
	g++ -std=c++11 -c line.cpp

subway_line_hash.o: subway_line_hash.cpp line.h subway_station.h
	g++ -std=c++11 -c subway_line_hash.cpp
run:
	./main test.csv command.txt