CXX = g++
CXXFLAGS = -Wall -pedantic -I.

SOURCES = main.cpp server.cpp sensor.cpp scheduler.cpp temperature.cpp humidity.cpp light.cpp sound.cpp
OBJECTS = main.o server.o sensor.o scheduler.o temperature.o humidity.o light.o sound.o

.o: .cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.o main