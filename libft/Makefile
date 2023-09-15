NAME := libft.a
HEADER := libft.h
CC := cc
CFLAGS := -Wall -Werror -Wextra
SRCS := ft_atoi.c		ft_bzero.c		ft_calloc.c		\
		ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
		ft_isdigit.c	ft_isprint.c	ft_memchr.c		\
		ft_memcmp.c		ft_memcpy.c		ft_memmove.c	\
		ft_memset.c		ft_strchr.c		ft_strdup.c		\
		ft_strlcat.c	ft_strlcpy.c	ft_strlen.c		\
		ft_strncmp.c	ft_strnstr.c	ft_strrchr.c	\
		ft_tolower.c	ft_toupper.c

SRCS += ft_substr.c		ft_strjoin.c	ft_strtrim.c	\
		ft_split.c		ft_itoa.c		ft_strmapi.c	\
		ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	\
		ft_putendl_fd.c	ft_putnbr_fd.c

# Add GNL
SRCS += ft_get_next_line.c	ft_cpyline.c

#Add FT_PRINTF
SRCS += ft_printf.c	ft_strnchr.c	ft_utoa_base.c		\
		ft_putstr.c	ft_putchar.c	ft_specifier_c.c	\
		ft_specifier_d.c	ft_specifier_p.c			\
		ft_specifier_percent.c	ft_specifier_s.c		\
		ft_specifier_u.c	ft_specifier_upperx.c		\
		ft_specifier_x.c

# Add FDF
SRCS += ft_abs.c

OBJS := $(SRCS:.c=.o)

BONUS_SRCS :=	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	\
				ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c	\
				ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

BONUS_OBJS := $(BONUS_SRCS:.c=.o)

GREEN		:= \033[1;32m
RED			:= \033[1;31m
WHT			:= \033[1;37m
EOC			:= \033[1;0m

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	@ar -rc $(NAME) $^
	@ranlib $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re, .o