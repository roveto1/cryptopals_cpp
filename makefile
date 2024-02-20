CXX=g++
CXXFLAGS=-std=c++11

all: final

final: main.o menu.o quest1.o quest2.o quest3.o quest4.o quest5.o quest6.o
	$(CXX) $(CXXFLAGS) main.o menu.o quest1.o quest2.o quest3.o quest4.o quest5.o quest6.o -o final
	rm -f main.o menu.o quest1.o quest2.o quest3.o quest4.o quest5.o quest6.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

menu.o: menu/menu.cpp
	$(CXX) $(CXXFLAGS) -c menu/menu.cpp

quest1.o: quest1/quest1.cpp
	$(CXX) $(CXXFLAGS) -c quest1/quest1.cpp

quest2.o: quest2/quest2.cpp
	$(CXX) $(CXXFLAGS) -c quest2/quest2.cpp

quest3.o: quest3/quest3.cpp
	$(CXX) $(CXXFLAGS) -c quest3/quest3.cpp

quest4.o: quest4/quest4.cpp
	$(CXX) $(CXXFLAGS) -c quest4/quest4.cpp

quest5.o: quest5/quest5.cpp
	$(CXX) $(CXXFLAGS) -c quest5/quest5.cpp

quest6.o: quest6/quest6.cpp
	$(CXX) $(CXXFLAGS) -c quest6/quest6.cpp


clean:
	rm -f final main.o menu.o quest1.o quest2.o quest3.o quest4.o quest5.o quest6.o