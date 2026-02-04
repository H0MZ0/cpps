CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Serializer
SRC = Serializer.cpp main.cpp
HAD = Serializer.hpp
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