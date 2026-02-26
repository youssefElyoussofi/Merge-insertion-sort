CXX=c++
CFLAGS= -std=c++98
SRC= MergeInsert.cpp parsing.cpp main.cpp
OBJ=$(SRC:.cpp=.o)
NAME=algoExecution

$(NAME):$(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)
	rm -f $(OBJ)

all: $(NAME)

clean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re