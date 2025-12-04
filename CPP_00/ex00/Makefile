NAME = megaphone
RUN = ./$(NAME)
SENTINEL = .build_completed

# ************************ STYLING ****************************** #

ESC = \033[

PINK    = 38;5;218m
LAVENDER = 38;5;183m
MINT    = 38;5;121m
SKY     = 38;5;117m
PEACH   = 38;5;216m
BUTTER  = 38;5;229m
FAIRY   = 38;5;225m
CLEAN   = 38;5;250m
NEON_PULSE = $(BOLD);$(BLINKING)
SPACING = @printf "\n$(ESC)$(BUTTER)--------------------------------------$(RESET)\n"
RESET   = \033[0m

BOLD = 1
FAINT = 2
ITALIC = 3
UNDERLINE = 4
BLINKING = 5
REVERSE =7
HIDDEN = 8
STRIKE = 9

define SUCCESS_MESSAGE
$(SPACING)
@echo "$(ESC)$(BOLD);$(ITALIC);$(MINT)✨ Project compiled successfully with flags: $(CFLAGS)!$(RESET)"
@echo "$(ESC)$(BOLD);$(ITALIC);$(BUTTER)-> To run the program, write: $(RUN) <input_string>$(RESET)"
$(SPACING)
@echo "$(ESC)$(NEON_PULSE);$(FAIRY)Author: liovino$(RESET)"
endef

# ************************ COMPILATION ************************* #


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJ = $(SRC:%.cpp=%.o)

RM = rm -rf

%.o: %.cpp
	@printf "$(ESC)$(BOLD);$(ITALIC);$(LAVENDER) \r\nCompiling $< ...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) check_status

$(NAME): $(OBJ)
	@$(RM) $(SENTINEL)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	$(SUCCESS_MESSAGE)
	@touch $(SENTINEL)

check_status:
	@if [ -f $(SENTINEL) ]; then \
		$(RM) -f $(SENTINEL); \
	else \
		echo "$(ESC)$(BOLD);$(ITALIC);$(SKY)✨ Project already up to date!$(RESET)"; \
	fi

clean: 
	@$(RM) $(OBJ) $(SENTINEL)
	@echo "$(ESC)$(BOLD);$(ITALIC);$(PINK)💫 All object files cleaned!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(ESC)$(BOLD);$(ITALIC);$(LAVENDER)🧚 $(NAME) cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re success check_status