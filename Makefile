CXXFLAGS = -std=c++17 -Wall -pthread

CXXFLAGS := $(CXXFLAGS) -O3 -march=native -flto

CXX = g++

evolution: evolution.o human.o virus.o random.o lib.o constants.h logger.o
	$(CXX) $(CXXFLAGS) -o evolution evolution.o human.o virus.o random.o lib.o logger.o

evolution.o: evolution.cc constants.h logger.h
	$(CXX) $(CXXFLAGS) -c evolution.cc

human.o: human.cc constants.h
	$(CXX) $(CXXFLAGS) -c human.cc

virus.o: virus.cc constants.h
	$(CXX) $(CXXFLAGS) -c virus.cc

random.o: random.cc constants.h
	$(CXX) $(CXXFLAGS) -c random.cc

random.o: lib.cc random.h
	$(CXX) $(CXXFLAGS) -c lib.cc

logger.o: logger.cc constants.h
	$(CXX) $(CXXFLAGS) -c logger.cc

clean:
	rm -f human.o virus.o evolution.o random.o evolution
