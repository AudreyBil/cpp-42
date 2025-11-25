NAME = mutant

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \

OBJDIR = obj

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

all: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
