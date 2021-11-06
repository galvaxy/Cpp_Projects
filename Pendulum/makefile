pendulum: main.o rungeKuttaCalc.o save.o
	g++ main.o rungeKuttaCalc.o save.o -o pendulum

main.o: main.cpp
	g++ -c main.cpp -std=c++11

rungeKuttaCalc.o: rungeKuttaCalc.cpp 
	g++ -c rungeKuttaCalc.cpp -std=c++11

save.o: save.cpp
	g++ -c save.cpp -std=c++11

clean:
	rm *.o pendulum 