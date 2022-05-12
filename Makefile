# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 15:07:52 by lucas-ma          #+#    #+#              #
#    Updated: 2022/05/11 11:33:54 by lucas-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################ PROGRAM ################

NAME	    =    so_long
NAME_BONUS =

################ TERMINAL ###############

RMV        =        rm -f
MKD        =        mkdir
PRT        =        printf
MKE        =        make
CPY        =        cp

################# COLORS ################

--GRN    =        \033[32m
--RED    =        \033[31m
--WHT    =        \033[39m

################# DIRS ##################

_SRC    =        src/
_OBJ 	=		 obj/
_LIB    =        libs/
_BIN    =        ./

############### COMPILER ################

CC        =        gcc
CF        =        -Wall -Werror -Wextra      

################ FILES ##################

SRCS    =        $(_SRC)sl_main.c $(_SRC)check_map.c $(_SRC)map.c $(_SRC)print_game.c \
				 $(_SRC)move_player.c $(_SRC)finish_game.c $(_SRC)move_enemy.c
OBJS    =        $(patsubst $(_SRC)%.c,$(_OBJ)%.o,$(SRCS))
OBJS_BONUS	=	 $(patsubst $(_SRC)%.c,$(_OBJ)%.o,$(SRCS_BONUS))
DEPS    =        libft.a
LIBS    =        -lft -lmlx

################ RULES ##################

all: deps $(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(CC) $(CF) -Imlx -c $< -o $@

$(NAME): deps $(OBJS)
	$(CC) $(CF) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBS) $(OBJS) -o $(NAME) -L $(_LIB)

$(NAME_BONUS): deps $(OBJS_BONUS)
	$(CC) $(CF) $(LIBS) $(OBJS_BONUS) -o $(NAME_BONUS) -L $(_LIB)

################ DEPS ###################

deps: $(DEPS)

libft.a:
	$(MKE) bonus -C libft/

############## STRUCTURE ################

$(_OBJ):
	$(MKD) $(_OBJ)

$(_LIB):
	$(MKD) $(_LIB)

$(_SRC):
	$(MKD) $(_SRC)

$(_BIN):
	$(MKD) $(_BIN)

################### CLEAN ###############

clean:
	$(RMV) -r $(_OBJ)

fclean: clean
	$(RMV) -r $(NAME)
	$(RMV) -r $(NAME_BONUS)
	$(RMV) -r $(_LIB)libft.a

re: fclean all

rebonus: fclean bonus

.PHONY: all deps clean fclean re 
