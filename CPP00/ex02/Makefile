NAME = accounts

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp	\
	tests.cpp

OBJS = $(SRC:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
