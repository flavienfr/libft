SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c \
ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_memmove.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strclen.c \


SRCSb = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
ft_lstiter.c ft_lstmap.c $(SRCS)

NAME = libft.a

OBJS = ${SRCS:.c=.o}
OBJSb = ${SRCSb:.c=.o}

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : ${OBJS}
		ar rc $(NAME) ${OBJS}
		ranlib $(NAME)

.c.o : ${SRCSb}
		gcc ${FLAGS} -c $< -o ${<:.c=.o}

bonus : fclean ${OBJSb}
		ar rc $(NAME) ${OBJSb}
		ranlib $(NAME) 

clean :
		rm -f ${OBJSb}

fclean : clean
		rm -f $(NAME)

re : fclean
		make all

.PHONY: all clean fclean re bonus
