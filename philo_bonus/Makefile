# ══ Names ══════════════════════════════════════════════════════════════════ #
#    -----                                                                    #

NAME_BONUS			= philo_bonus

# ══ Colors ═════════════════════════════════════════════════════════════════ #
#    ------                                                                   #

DEL_LINE 			= \033[2K
ITALIC 				= \033[3m
BOLD 				= \033[1m
DEF_COLOR 			= \033[0;39m
GRAY 				= \033[0;90m
RED 				= \033[0;91m
GREEN 				= \033[0;92m
YELLOW 				= \033[0;93m
BLUE 				= \033[0;94m
MAGENTA 			= \033[0;95m
CYAN 				= \033[0;96m
WHITE 				= \033[0;97m
BLACK 				= \033[0;99m
ORANGE 				= \033[38;5;209m
BROWN 				= \033[38;2;184;143;29m
DARK_GRAY 			= \033[38;5;234m
MID_GRAY 			= \033[38;5;245m
DARK_GREEN 			= \033[38;2;75;179;82m
DARK_YELLOW 		= \033[38;5;143m

# ══ Compilation═════════════════════════════════════════════════════════════ #
#    -----------                                                              #

CC 					= clang
AR 					= ar rcs
RM 					= rm -f
RMR					= rm -f -r
MK 					= make -C -g
MKD					= mkdir -p
MCL 				= make clean -C
MFCL 				= make fclean -C
MK_					= && make

# # ══ Directories Bonus ════════════════════════════════════════════════════ #
# #    -----------------                                                      #

SRC_DIR_BONUS		= ./src
ERRORS_DIR_BONUS	= ./errors
INIT_DIR_BONUS		= ./init
UTILS_DIR_BONUS		= ./utils
OBJ_DIR_BONUS		= ./obj
INCLUDES_DIR_BONUS	= ./includes
MGE_PHILOS_BONUS	= ./manage_philos

# # ══ Flags Bonus ══════════════════════════════════════════════════════════ #
# #    -------                                                                #

CFLAGS 				= -Wall -Werror -Wextra -g
IFLAGS_BONUS		= -I${INCLUDES_DIR_BONUS}
LFLAGS				= -lpthread

# # ══ Sources Bonus ════════════════════════════════════════════════════════ #
# #    -------------                                                          #

SRC_BONUS 			= ${SRC_DIR_BONUS}/philosophers_bonus.c


ERR_BONUS			= ${ERRORS_DIR_BONUS}/ft_manage_err_bonus.c

INT_BONUS			= ${INIT_DIR_BONUS}/ft_init_bonus.c \
						${INIT_DIR_BONUS}/ft_init_struct_bonus.c

MPH_BONUS			= ${MGE_PHILOS_BONUS}/ft_philos_bonus.c \
						${MGE_PHILOS_BONUS}/ft_philos_tools_bonus.c

UTL_BONUS			= ${UTILS_DIR_BONUS}/ft_banner_bonus.c \
						${UTILS_DIR_BONUS}/ft_utils_bonus.c \
						${UTILS_DIR_BONUS}/ft_utils_2_bonus.c

OBJ_SRC_BONUS		= $(patsubst ${SRC_DIR_BONUS}/%.c, \
						${OBJ_DIR_BONUS}/%.o, ${SRC_BONUS})
OBJ_ERR_BONUS		= $(patsubst ${ERRORS_DIR_BONUS}/%.c, \
						${OBJ_DIR_BONUS}/%.o, ${ERR_BONUS})
OBJ_INT_BONUS		= $(patsubst ${INIT_DIR_BONUS}/%.c, \
						${OBJ_DIR_BONUS}/%.o, ${INT_BONUS})
OBJ_MPH_BONUS		= $(patsubst ${MGE_PHILOS_BONUS}/%.c, \
						${OBJ_DIR_BONUS}/%.o, ${MPH_BONUS})
OBJ_UTL_BONUS		= $(patsubst ${UTILS_DIR_BONUS}/%.c, \
						${OBJ_DIR_BONUS}/%.o, ${UTL_BONUS})

OBJS_BONUS			= ${OBJ_SRC_BONUS} ${OBJ_CLN_BONUS} ${OBJ_ERR_BONUS} \
						${OBJ_INT_BONUS} ${OBJ_MPH_BONUS} ${OBJ_UTL_BONUS}

# # ═══ Rules Bonus ═════════════════════════════════════════════════════════ #
# #     -----------                                                           #

all: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}	
	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS_BONUS} -o ${NAME_BONUS} ${OBJS_BONUS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${OBJ_DIR_BONUS}/%.o: ${SRC_DIR_BONUS}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS_BONUS} -c $< -o $@

${OBJ_DIR_BONUS}/%.o: ${ERRORS_DIR_BONUS}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS_BONUS} -c $< -o $@

${OBJ_DIR_BONUS}/%.o: ${INIT_DIR_BONUS}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS_BONUS} -c $< -o $@

${OBJ_DIR_BONUS}/%.o: ${MGE_PHILOS_BONUS}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS_BONUS} -c $< -o $@	

${OBJ_DIR_BONUS}/%.o: ${UTILS_DIR_BONUS}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS_BONUS} -c $< -o $@

clean:
	@echo "$(YELLOW)Removing object files ...$(DEF_COLOR)"
	@$(RM) ${OBJ_DIR_BONUS}/*.o
	@echo "$(RED)Object files removed $(DEF_COLOR)"

fclean: clean
	@echo "$(YELLOW)Removing executables ...$(DEF_COLOR)"
	@${RM} ${NAME_BONUS}
	@echo "$(RED)Executable removed $(DEF_COLOR)"

re:	fclean all

.PHONY : all clean fclean re
