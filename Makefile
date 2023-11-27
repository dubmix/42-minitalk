# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelanno <pdelanno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 10:15:21 by pdelanno          #+#    #+#              #
#    Updated: 2023/11/27 09:08:44 by pdelanno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

SRCS1 = server.c

SRCS2 = client.c

#OBJS1 = $(patsubst %.c, %.o, $(wildcard $(SRCS1)))

#OBJS2 = $(patsubst %.c, %.o, $(wildcard $(SRCS2)))

OBJS1 = ${SRCS1:.c=.o}

OBJS2 = ${SRCS2:.c=.o}

HEADERS = minitalk.h

CFLAGS = -Werror -Wall -Wextra -g

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
			@rm -f ${SERVER}
			@rm -f ${CLIENT}
			@echo "All clean!"

re: fclean all

.PHONY: all clean fclean re
