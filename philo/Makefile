# Directories
OBJ_DIR		= obj
SRC_DIR		= ./
INC_DIR		= $(SRC_DIR)
BIN_DIR		= ./

# Targets
NAME		= philo

# Flags setup
CC		= cc
OPT		= 3
WARN	= all extra error pedantic
EXTRA	= -MP -MMD -g

# Compiler flags
override CFLAGS 	+= $(EXTRA) $(OPT:%=-O%) $(INC_DIR:%=-I%) $(WARN:%=-W%)

# Sources
SRCS =				\
timestamp.c			\
ft_isdigit.c		\
ft_isspace.c		\
ft_strtonum.c		\
philo.c				\
philo_util.c		\
philo_actions.c		\
template.c			\
ft_strlen.c			\
ft_putstr_fd.c		\
config.c			\
config_impl.c		\
fork.c				\
simulation.c		\
simulation_init.c	\
main.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

DEPS = $(SRCS:%.c=$(OBJ_DIR)/%.d)

.PHONY: all clean fclean re norm debug

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BIN_DIR) $(OBJ_DIR):
	@mkdir -p $@

re: fclean all

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

debug: fclean
	make $(NAME) CFLAGS="-g -fsanitize=address"

norm:
	norminette | grep -v "OK" || echo "All OK!"

vpath %.c $(SRC_DIR)
-include $(DEPS)