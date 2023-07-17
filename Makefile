# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 10:15:21 by pdelanno          #+#    #+#              #
#    Updated: 2023/05/21 10:15:24 by pdelanno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

SRCS1 = server.c printf/flags.c printf/ft_eval_format.c \
printf/ft_print_address.c printf/ft_print_char.c printf/ft_printf.c \
printf/ft_print_hexalo.c printf/ft_print_hexaup.c printf/ft_print_int.c \
printf/ft_print_str.c printf/ft_print_unsignedint.c

SRCS2 = client.c printf/flags.c printf/ft_eval_format.c \
printf/ft_print_address.c printf/ft_print_char.c printf/ft_printf.c \
printf/ft_print_hexalo.c printf/ft_print_hexaup.c printf/ft_print_int.c \
printf/ft_print_str.c printf/ft_print_unsignedint.c

//OBJS1 = $(patsubst %.c, %.o, $(wildcard $(SRCS1)))

//OBJS2 = $(patsubst %.c, %.o, $(wildcard $(SRCS2)))

OBJS1 = ${SRCS1:.c=.o}

OBJS2 = ${SRCS2:.c=.o}

HEADERS = minitalk.h

CFLAGS = -Werror -Wall -Wextra

.c.o:
			@cc ${CFLAGS} -c $^ -o $@

all:		${SERVER} ${CLIENT}

$(SERVER):	${OBJS1}
					@cc ${OBJS1} $(CFLAGS) -o $(SERVER)
					@echo "Server compiled!"

$(CLIENT):	${OBJS2}
					@cc ${OBJS2} $(CFLAGS) -o $(CLIENT)
					@echo "Client compiled!"

clean:
			@rm -f ${OBJS1}
			@rm -f ${OBJS2}

fclean:		clean
			@cd printf && rm -f ${SERVER}
			@rm -f ${SERVER}
			@rm -f ${CLIENT}
			@echo "All clean!"

re: fclean all

.PHONY: all clean fclean re
