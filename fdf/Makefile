# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohouhou <mohouhou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 17:49:49 by mohouhou          #+#    #+#              #
#    Updated: 2022/10/15 23:05:53 by mohouhou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME	=		fdf

LIBFT	=		Libft/libft.a 

SRC		=		get_next_line.c \
				get_next_line_utils.c \
				test.c \
				main.c \
				plotline.c \
				fdf.c \
			
CC		=		gcc -g3

CFLAGS	=		-Wall -Werror -Wextra

OBJS	=		$(SRC:.c=.o)



$(NAME)	:	$(OBJS)
			$(MAKE) -C ./Libft
			$(MAKE) -C ./mlx
			mkdir -p objsdir
			cp Libft/*.o objsdir
			cp mlx/*.o objsdir
			cp $(OBJS) objsdir
			$(CC) $(CFLAGS) objsdir/*.o -Lmlx ./mlx/libmlx.a -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

%.o		:	%.c
			$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

test:	
		$(MAKE) -C ./mlx
		$(CC) $(CFLAGS) test.c -Lmlx ./mlx/libmlx.a -lmlx -framework OpenGL -framework AppKit -o test
			
all		:	$(NAME)

clean	:
			rm -f objsdir/*.o
			rm *.o

fclean	:	clean
			rm -f $(NAME)
			cd Libft && $(MAKE) fclean && cd ..
			cd mlx && $(MAKE) clean && cd ..
			

re		:	fclean all