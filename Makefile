# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/03 18:24:45 by kalhouda          #+#    #+#              #
#    Updated: 2026/10/04 19:28:35 by kalhouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = libftprintf.a


CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 

OBJS = $(SRCS:.c=.o)

all = $(Name)

$(Name): $(OBJS)
	ar rcs $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all