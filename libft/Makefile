# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acristin <acristin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 07:03:56 by trurgot           #+#    #+#              #
#    Updated: 2022/03/30 13:59:04 by acristin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# gcc -Wall -Wextra -Werror -c *.c
# ar rc libft.a *.o
# ranlib libft.a;
# rm *.o;
# 
# $@ is the name of the target being generated, and $< the first prerequisite 
# (usually a source file). 
# You can find a list of all these special variables in the GNU Make manual.  
# For example, consider the following declaration:  
# 	all: library.cpp main.cpp  
# In this case:  
# $@ evaluates to all  
# $< evaluates to library.cpp  
# $^ evaluates to library.cpp main.cpp
# 
# -O - оптимизация

NAME	= libft.a
HEAD	= libft.h
SRCS	= 	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_dblclstaddback.c \
			ft_dblclstaddfront.c \
			ft_dblclstclear.c \
			ft_dblclstdelelem.c \
			ft_dblclstinit.c \
			ft_dblclstsize.c \
			ft_dblclstswap.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putnbr.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c 

OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

.PHONY : all re clean fclean

all : $(NAME)

$(NAME) : $(OBJS)
		@ar rcs $(NAME) $?

%.o : %.c $(HEAD)
		@$(CC) $(CFLAGS) -c $< -o $@

clean :
		@rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
		@rm -f $(NAME)

re : fclean all
