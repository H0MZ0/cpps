CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = whatever
SRC = main.cpp
HAD = whatever.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HAD)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: all fclean clean

.SECONDARY: