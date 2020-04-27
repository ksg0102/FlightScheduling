out: main.o planefunctions.o crewfunctions.o flightfunctions.o
	g++ main.o planefunctions.o crewfunctions.o flightfunctions.o -o out

main.o: main.cpp planedata.h planecollections.h crewdata.h crewcollections.h flightdata.h flightcollections.h
	g++ -c main.cpp

planefunctions.o: planefunctions.cpp planedata.h planecollections.h
	g++ -c planefunctions.cpp

crewfunctions.o: crewfunctions.cpp crewdata.h crewcollections.h
	g++ -c crewfunctions.cpp

flightfunctions.o: flightfunctions.cpp flightdata.h flightcollections.h
	g++ -c flightfunctions.cpp

clean:
	rm *.o out

 