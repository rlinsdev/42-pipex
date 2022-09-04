NAME = pipex

# Collors
GREEN 	= \033[0;32m
RED 	= \033[0;31m
BLUE 	= \033[0;34m
RESET 	= \033[0m

# Paths
HEADERS_PATH 	= ./include/
SRCS_PATH 		= ./src/
OBJS_PATH 		= ./obj/
BINS_PATH 		= ./bin/

# Compilation
CC = gcc -g
#FLAGS = -Wall -Wextra -Werror
# TODO: Voltar as flags
FLAGS =

#Chedk Leak memory
LEAK = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s

# Bash commands
RM = rm -f # -f Force
MKDIR = mkdir -p
#MAKE_NOPRINT = $(MAKE) --no-print-directory

# Files
SRC_FILES = pipex.c ft_strlen.c
#test1.c test2.c test3.c test4.c test5.c

SOURCES 	= $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES 	= $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS 	= $(addprefix $(OBJS_PATH), $(OBJ_FILES))
EXECUTABLE 	= pipex

# Targets
all: $(NAME)

# Creates static library libft.a inside ./libs/ folder
$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

# Creates object files for ft_pipex
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	$(MKDIR) $(OBJS_PATH)
	$(CC) $(FLAGS) -c $< -I $(HEADERS_PATH) -o $@

# Creates the executable file $(EXECUTABLE) to test development
main:	./apps/app.c
	@$(MKDIR) $(BINS_PATH)
	$(CC) $(FLAGS) $(OBJECTS) $< $(NAME) -I $(HEADERS_PATH) -o $(BINS_PATH)$(EXECUTABLE)

# Compile program and execute main file
run: all main
	@$(BINS_PATH)$(EXECUTABLE)

# Sanitize
clean:
	@echo "$(GREEN)$(NAME): $(RED)object (*.o) files were deleted$(RESET)"
	@$(RM) $(OBJECTS)
	@echo "$(RED)Clean in progres...$(RESET)"
	@echo "$(GREEN)$(NAME): $(BLUE)Sanitized!$(RESET)"

# Removing .o files, .a files
fclean: clean
	@echo "$(GREEN)$(NAME): $(RED)was deleted$(RESET)"
	@$(RM) $(BINS_PATH)$(EXECUTABLE)

norma:
	norminette $(SOURCES)

valgrind:
	$(LEAK) $(BINS_PATH)$(EXECUTABLE)

# Removing and running
re: fclean all

# All the variables that is not a file in source folder.
.PHONY: all run clean fclean re
