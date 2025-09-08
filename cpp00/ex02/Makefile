C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Account
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(C++) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: all fclean clean

.SECONDARY: