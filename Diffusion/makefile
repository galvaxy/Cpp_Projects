diffusion: main.o initialize.o calculate.o
	g++ main.o initialize.o calculate.o -o diffusion

main.o: main.cpp
	g++ -c main.cpp -std=c++11

initialize.o: initialize.cpp
	g++ -c initialize.cpp -std=c++11

calculate.o: calculate.cpp 
	g++ -c calculate.cpp -std=c++11

clean:
	rm *.o diffusion