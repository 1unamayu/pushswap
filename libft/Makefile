FILES = ft_isalpha.c ft_toupper.c \
		ft_isdigit.c ft_tolower.c \
		ft_isalnum.c ft_strchr.c \
		ft_isascii.c ft_strrchr.c \
		ft_isprint.c ft_strncmp.c \
		ft_strlen.c  ft_memchr.c \
		ft_memset.c  ft_memcmp.c \
		ft_bzero.c   ft_strnstr.c \
		ft_memcpy.c  ft_atoi.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \

FILES += ft_calloc.c ft_strdup.c
FILES += ft_substr.c ft_strjoin.c
FILES += ft_strtrim.c ft_split.c ft_itoa.c
FILES += ft_strmapi.c ft_striteri.c ft_putchar_fd.c
FILES += ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c
BONUS += ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c
BONUS += ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = ${FILES:.c=.o}
OBJS_BONUS = ${BONUS:.c=.o}

# ------------- COLORS
RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m
PINK			=   \033[38;5;162m
LIGHT_PINK      =   \033[38;5;200m
BLUE			= 	\033[38;5;39m
DARK_BLUE		=   \033[38;5;57m

NAME = libft.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
.c.o:
	@echo "$(GREY)Compiling Libft ......................$(LIGHT_PINK)$(@:obj/%=%)"
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "$(GREEN)DONE!$(GREY)"
	@sleep .1

$(NAME):	${OBJS}
		@ar rc ${NAME} ${OBJS}

bonus:	${OBJS} ${OBJS_BONUS}
		@ar rc ${NAME} ${OBJS} ${OBJS_BONUS}
all: ${NAME}

.PHONY: clean, fclean, re, bonus
clean:
	${RM} -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} -f ${NAME}

re: clean fclean all