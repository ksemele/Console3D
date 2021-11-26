NAME		= 3dconsole

CPP			= g++
CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I$(INC_DIR)
INC_DIR		= ./inc/
INC_LIST	= vectors.hpp
INC			= $(addprefix $(INC_DIR), $(INC_LIST))

SRC_DIR		= src/
SRC_LIST	= main.cpp
SRC			= $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR		= obj/
OBJ_LIST	= $(SRC_LIST:.cpp=.o)
OBJ			= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

GRN = \033[0;32m
RED = \033[0;31m
YEL = \033[1;33m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(INC)
		@$(CPP) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
		@echo "$(GRN)$(NAME) created$(END)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
		$(CPP) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo "$(GRN)$(OBJ_DIR) folder created$(END)"

clean:
		@rm -rf $(OBJ_DIR)
		@echo "$(RED)$(OBJ_DIR) folder deleted$(END)"
		@echo "$(RED)*.o files deleted$(END)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(RED)$(NAME) deleted$(END)"

re:
		@$(MAKE) fclean
		@$(MAKE) all
