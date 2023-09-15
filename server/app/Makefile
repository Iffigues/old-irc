CXX = g++

CXXFLAGS = -std=c++98 -Ilibrary

SOURCE = main	\
	Hosting	\
	Param	\
	ParamBuilder	\
	Serve

SOURCES = $(addsuffix .cpp,$(addprefix src/,$(SOURCE)))

OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = ircserv

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re

