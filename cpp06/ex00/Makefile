CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = convert
SRC = ScalarConverter.cpp main.cpp
HAD = ScalarConverter.hpp
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

re: fclean all

.PHONY: all clean fclean re

.SECONDARY : $(OBJS)