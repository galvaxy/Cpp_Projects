free_end_wave: main.o initialize.o calculate.o 
	g++ main.o initialize.o calculate.o -o free_end_wave

main.o: main.cpp
	g++ -c main.cpp -std=c++11

initialize.o: initialize.cpp
	g++ -c initialize.cpp -std=c++11

calculate.o: calculate.cpp
	g++ -c calculate.cpp -std=c++11

clean:
	rm *.o free_end_wave animation 