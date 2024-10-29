PRE = ./
HEADER = ./
FUNCTION = ./libft
BONUS = ./bonus/

SOURCE = main.c utils.c path_pars.c checkers.c
SOURCE_BON = checkers_bonus.c main_bonus.c limiter_bonus.c \
			 mult_pipe_bonus.c path_pars_bonus.c utils_bonus.c

SOURCES = ${addprefix $(PRE), $(SOURCE)}
SOURCES_BON = ${addprefix $(BONUS), $(SOURCE_BON)}

NAME = pipex
NAME_BONUS = pipex_bonus
LIB = $(FUNCTION)/libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g

OBJ = $(SOURCES:.c=.o)
OBJ_BON = $(SOURCES_BON:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	cc $(FLAGS) -o $@ $^

$(LIB):
	$(MAKE) -C $(FUNCTION)

.c.o:
		$(CC) $(FLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BON) $(LIB)
	cc $(FLAGS) -o $(NAME) $^

.c.o2:
		$(CC) $(FLAGS) -I $(BONUS) -c $< -o $(<:.c=.o)

clean: 
	rm -f $(OBJ) $(OBJ_BON)
	$(MAKE) clean -C $(FUNCTION)
        
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FUNCTION)

re: fclean all
