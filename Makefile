
.PHONY: all clean fclean re bonus

SRCS	=	fractol.c			\
			fractal_select.c	\
			search_fractal.c	\
			draw.c				\
			key_control.c		\
			mouse_control.c		\
			puts_and_cp.c		

LIBFT	=	libft

OBJS	=	${SRCS:.c=.o}


NAME	=	fractol
P_HEAD	=	fractol.h

RM		=	rm -f
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
MLXFLAG	=	-lmlx -framework OpenGL -framework AppKit

.c.o:
			${CC} ${CFLAG} -c $< -I ${P_HEAD} -o $@


${NAME}:	${OBJS}
			${CC} ${MLXFLAG} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
