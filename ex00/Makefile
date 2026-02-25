NAME = Bureaucrat
SRCS = Bureaucrat.cpp				main.cpp
BUILD = ./BUILD/
OBJS = $(addprefix $(BUILD), $(SRCS:%.cpp=%.o))
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(BUILD):
	mkdir $@

$(BUILD)%.o: %.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: $(NAME)
	valgrind --leak-check=full ./$<

.PHONY: all clean fclean re run

.:EFAULT_GOAL = all
