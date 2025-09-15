CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Point
SRC = bsp.cpp  Fixed.cpp  main.cpp Operators.cpp  Point.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: