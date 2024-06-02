CC := cc

CFLAGS := -Wall -Wextra -g #-fsanitize=address#-Werror
SRC_DIR := linked_list_utils
NAME := push_swap
# CFILES := ./linked_list_utils/ft_stack_addback.c linked_list_utils/ft_stacksize.c linked_list_utils/ft_stacklast.c linked_list_utils/ft_delnode.c linked_list_utils/ft_stack_addfront.c linked_list_utils/ft_newnode.c linked_list_utils/ft_stackfill.c \
# operations/op_swap.c operations/op_rotate.c operations/op_push.c operations/op_rev_rotate.c string_utils/str_utils.c

CFILES =  $(wildcard string_utils/*.c) $(wildcard *.c) $(wildcard operations/*.c) $(wildcard linked_list_utils/*.c) 
OFILES := $(CFILES:.c=.o)
LIBFT = ./libft
INC =  -Iheaders
LIBS = -L$(LIBFT) -lft

#echo:
#	@echo  $(wildcard string_utils/*.c) $(wildcard *.c) $(wildcard operations/*.c) $(wildcard linked_list_utils/*.c) 
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
