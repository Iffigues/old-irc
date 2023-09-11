CXX = g++
CXXFLAGS = -std=c++98 -Ilibrary
SOURCES = src/main.cpp src/Hosting.cpp src/Param.cpp src/ParamBuilder.cpp src/Serve.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = ircserv
all: $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

.PHONY: all clean

