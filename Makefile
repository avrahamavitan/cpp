#avrahamavitan@gmail.com

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SRC = Graph.cpp Algorithms.cpp Queue.cpp PriorityQueue.cpp UnionFind.cpp
HEADERS = Graph.hpp Algorithms.hpp Queue.hpp PriorityQueue.hpp UnionFind.hpp

main: main.cpp $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o main main.cpp $(SRC)

test: test.cpp $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o test test.cpp $(SRC)
	./test

valgrind: main
	valgrind --leak-check=full ./main

clean:
	rm -f *.o main test
