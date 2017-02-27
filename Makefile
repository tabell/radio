CC = g++
LIBS = -lboost_system -lgnuradio-runtime -lgnuradio-analog -lgnuradio-blocks
test: test.cpp
	$(CC) test.cpp $(LIBS) -o test
