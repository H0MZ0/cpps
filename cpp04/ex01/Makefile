CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
NAME = Animal
SRC = Animal.cpp  Cat.cpp  Dog.cpp  main.cpp Brain.cpp
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

run: all
	./$(NAME)

.SECONDARY: