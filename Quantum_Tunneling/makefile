quantum_tunneling: main.o initialize.o calc_save.o normalize.o
	g++ main.o initialize.o calc_save.o normalize.o -o quantum_tunneling

main.o: main.cpp 
	g++ -c main.cpp 

initialize.o: initialize.cpp
	g++ -c initialize.cpp 

calc_save.o: calc_save.cpp
	g++ -c calc_save.cpp

normalize.o: normalize.cpp 
	g++ -c normalize.cpp

clean:
	rm *.o quantum_tunneling