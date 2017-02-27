CC = g++
HEADERS = -I/usr/include/qt5/QtWidgets -I/usr/include/qt5
QT_LIBS = -lQtGui
GNURADIO_LIBS = -lboost_system -lgnuradio-runtime -lgnuradio-analog -lgnuradio-blocks -lgnuradio-qtgui
FLAGS = -fPIE
test: test.cpp
	$(CC) test.cpp $(HEADERS) $(GNURADIO_LIBS) $(QT_LIBS) $(FLAGS) -o test
