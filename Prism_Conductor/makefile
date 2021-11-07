prism_conductor: main.o initialize.o calculate.o check_save.o 
	g++ main.o initialize.o calculate.o check_save.o -o prism_conductor

main.o: main.cpp
	g++ -c main.cpp -std=c++11

initialize.o: initialize.cpp
	g++ -c initialize.cpp -std=c++11

calculate.o: calculate.cpp
	g++ -c calculate.cpp -std=c++11

check_save.o: check_save.cpp
	g++ -c check_save.cpp -std=c++11

clean:
	rm *.o prism_conductor