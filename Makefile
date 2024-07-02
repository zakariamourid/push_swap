CC := cc

CFLAGS := -Wall -Wextra -g3 -Werror
SRC_DIR := linked_list_utils
NAME := push_swap
CFILES = string_utils/str_check_utils.c string_utils/str_utils.c free_functions.c ft_fill_array.c ft_stackfill.c ft_stacklast.c main.c small_sorts.c sort_all.c sort_all_helper.c operations/op_push.c operations/op_rev_rotate.c operations/op_rotate.c operations/op_swap.c linked_list_utils/ft_delnode.c linked_list_utils/ft_newnode.c linked_list_utils/ft_stack_addback.c linked_list_utils/ft_stack_addfront.c linked_list_utils/ft_stacksize.c
OFILES := $(CFILES:.c=.o)
LIBFT = ./libft
INC =  -Iheaders
LIBS = -L$(LIBFT) -lft

all: $(NAME)


$(NAME): $(OFILES)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS)  $(OFILES)  $(INC) $(LIBS)  -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make clean -C $(LIBFT)
	rm -f $(OFILES)


fclean: clean
	@make fclean -C $(LIBFT)
	rm -f $(NAME)
	
re: fclean all
