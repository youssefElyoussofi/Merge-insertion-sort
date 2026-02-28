CXX=c++
CXXFLAGS= -std=c++98 -g
SRC= MergeInsert.cpp main.cpp algo_part_1_.cpp algo_part_2_.cpp
OBJ=$(SRC:.cpp=.o)
NAME=algoExecution

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	rm -f $(OBJ)

all: $(NAME)

clean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re