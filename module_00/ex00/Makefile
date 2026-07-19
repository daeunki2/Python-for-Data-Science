# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/18 14:15:31 by daeunki2          #+#    #+#              #
#    Updated: 2026/07/18 14:20:02 by daeunki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ex00

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj

SRC_FILES := \
	main.cpp \
	Account.cpp \
	Bank.cpp

SRCS := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CPPFLAGS := -I$(INC_DIR)
DEPFLAGS := -MMD -MP

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re