NAME = megaphone

SRC = megaphone.cpp

OBJT_DIR = objt

OBJT = $(addprefix $(OBJT_DIR)/, $(patsubst %.cpp, %.o, $(SRC)))

C++ = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

MAKEFLAGS += --quiet

all: $(NAME)

$(NAME): $(OBJT)
	$(C++) $(CFLAGS) $(OBJT) -o $(NAME) 

$(OBJT_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(C++) $(CFLAGS) -c $< -o $@ 

clean:
		$(RM) -r $(OBJT_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
