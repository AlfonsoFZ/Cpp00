NAME = phonebook

# ifeq ($(shell uname), Darwin)
# 	INCFLAGS =  -DEBUG=1 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
# else
# 	INCFLAGS = -ldl -DEBUG=1 -Iinclude -lglfw -L"usr/lib/x86_64-linux-gnu/"
# endif

SRC = 	main.cpp 		\
		PhoneBook.cpp	\
		Contact.cpp

OBJT_DIR = objt

OBJT = $(addprefix $(OBJT_DIR)/, $(patsubst %.cpp, %.o, $(SRC)))

C++ = c++
# en Mac compila con la G mayúscula - si no funciona así, cambiarlo

CFLAGS = -Wall -Wextra -Werror -std=c++98 -D DEBUG=$(DEBUG) 

RM = rm -f

MAKEFLAGS += --quiet

ifdef DEBUG
	DEBUG = 1
else
	DEBUG = 0
endif

all: $(NAME)

$(NAME): $(OBJT)
	$(C++) $(CFLAGS) $(OBJT) -o $(NAME) 

$(OBJT_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(C++) $(CFLAGS) -c $< -o $@ 

debug:
	make re DEBUG=1

clean:
		$(RM) -r $(OBJT_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
