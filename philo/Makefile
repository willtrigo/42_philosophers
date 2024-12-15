# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 17:07:46 by dande-je          #+#    #+#              #
#    Updated: 2024/12/15 00:26:37 by dande-je         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                   COLOR                                      #
#******************************************************************************#

RED                             := \033[0;31m
GREEN                           := \033[0;32m
YELLOW                          := \033[0;33m
PURPLE                          := \033[0;35m
CYAN                            := \033[0;36m
RESET                           := \033[0m

#******************************************************************************#
#                                   PATH                                       #
#******************************************************************************#

SRCS_DIR                        := src/
SRCS_PARSE_DIR                  := $(SRCS_DIR)parse/
SRCS_ROUTINE_DIR                := $(SRCS_DIR)routine/
SRCS_HANDLER_DIR                := $(SRCS_ROUTINE_DIR)handler/
SRCS_MONITOR_DIR                := $(SRCS_ROUTINE_DIR)monitor/
SRCS_UTILS_DIR                  := $(SRCS_DIR)utils/
INCS                            := src/
BUILD_DIR                       := build/

#******************************************************************************#
#                                  COMMANDS                                    #
#******************************************************************************#

RM                              := rm -rf
MKDIR                           := mkdir -p
MAKEFLAGS                       += --no-print-directory
SLEEP                           := sleep 0.01

#******************************************************************************#
#                                   FILES                                      #
#******************************************************************************#

NAME                            = philo

SRCS_FILES                      += $(addprefix $(SRCS_DIR), main.c)
SRCS_FILES                      += $(addprefix $(SRCS_PARSE_DIR), arguments.c)
SRCS_FILES                      += $(addprefix $(SRCS_ROUTINE_DIR), info.c \
								   routine.c)
SRCS_FILES                      += $(addprefix $(SRCS_HANDLER_DIR), handler_malloc.c \
								   handler_mutex.c \
								   handler_thread.c)
SRCS_FILES                      += $(addprefix $(SRCS_MONITOR_DIR), fork.c \
								   monitor.c \
								   philo.c)
SRCS_FILES                      += $(addprefix $(SRCS_UTILS_DIR), output.c \
								   ft_putendl_fd.c \
								   ft_strtoll.c)

OBJS                            += $(SRCS_FILES:%.c=$(BUILD_DIR)%.o)

DEPS                            += $(OBJS:.o=.d)

#******************************************************************************#
#                               OUTPUTS MESSAGES                               #
#******************************************************************************#

COUNT                           = 0
OBJS_COUNT                      = 0
MATH                            = 0
CLEAN_MESSAGE                   := Philo objects deleted
FCLEAN_MESSAGE                  := Philo deleted
EXE_MESSAGE                     = $(RESET)[100%%] $(GREEN)Built target philo
COMP_MESSAGE                    = Building C object

#******************************************************************************#
#                               COMPILATION                                    #
#******************************************************************************#

CC                             := cc
CFLAGS                         = -Wall -Wextra -Werror -Ofast -pthread -Wunreachable-code -Wpedantic
CPPFLAGS                       := $(addprefix -I,$(INCS)) -MMD -MP
DFLAGS                         := -Wall -Wextra -Werror -g3 -pthread
LFLAGS                         := -march=native
LDFLAGS                        := $(addprefix -L,$(dir $(LIBS))) -pthread
COMPILE_OBJS                   = $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMPILE_EXE                    = $(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

#******************************************************************************#
#                                   DEFINE                                     #
#******************************************************************************#

ifdef WITH_DEBUG
	CFLAGS                     = $(DFLAGS)
endif

#******************************************************************************#
#                                  FUNCTION                                    #
#******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMPILE_OBJS)
	$(eval MATH=$(shell expr "$(COUNT)" \* 100 \/ "$(OBJS_COUNT)"))
	$(eval MATH=$(shell if [ $(COUNT) -lt 1 ]; then echo $(shell expr "$(MATH)" + 100) ; else echo $(MATH) ; fi))
	printf "[%3d%%] $(YELLOW)$(COMP_MESSAGE) $@ \r$(RESET)\n" $$(echo $(MATH))
endef

define comp_exe
	$(COMPILE_EXE)
	$(SLEEP)
	printf "$(EXE_MESSAGE)\n$(RESET)"
endef

define clean
	$(RM) $(BUILD_DIR)
	$(SLEEP)
	printf "$(RED)$(CLEAN_MESSAGE)$(RESET)\n"
endef

define fclean
	$(RM) $(NAME)
	$(SLEEP)
	printf "$(RED)$(FCLEAN_MESSAGE)$(RESET)\n"
endef

define debug
	$(call clean)
	$(call fclean)
	$(MAKE) WITH_DEBUG=TRUE
endef

define reset_count
	$(eval COUNT=$(1))
	$(eval OBJS_COUNT=$(words $(SRCS_FILES)))
endef

#******************************************************************************#
#                                   TARGETS                                    #
#******************************************************************************#

all: $(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(call reset_count, -$(words $(OBJS))) $(OBJS)
	$(call comp_exe)

clean:
	$(call clean)

fclean: clean
	$(call fclean)

re: fclean all

debug:
	$(call debug)

.PHONY: all clean fclean re debug
.DEFAULT_GOAL := all
.SILENT:

-include $(DEPS)
