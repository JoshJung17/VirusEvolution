CXXFLAGS = -std=c++17 -Wall -pthread

CXXFLAGS := $(CXXFLAGS) -O3 -march=native -flto

CXX = g++

evolution: evolution.o human.o virus.o random.o constants.h
	$(CXX) $(CXXFLAGS) -o evolution evolution.o human.o virus.o random.o

evolution.o: evolution.cc constants.h
	$(CXX) $(CXXFLAGS) -c evolution.cc

human.o: human.cc constants.h
	$(CXX) $(CXXFLAGS) -c human.cc

virus.o: virus.cc constants.h
	$(CXX) $(CXXFLAGS) -c virus.cc

random.o: random.cc constants.h
	$(CXX) $(CXXFLAGS) -c random.cc

clean:
	rm -f human.o virus.o evolution.o random.o evolution
