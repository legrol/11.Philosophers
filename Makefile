# ══ Names ══════════════════════════════════════════════════════════════════ #
#    -----                                                                    #

NAME 				= philo
NAME_BONUS			= philo_bonus
EXEC_PATH			= ./philo/$(NAME)
EXEC_PATH_BONUS		= ./philo_bonus/$(NAME)

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
MK 					= make -C -g
MKD					= mkdir -p
MCL 				= make clean -C
MFCL 				= make fclean -C
MK_					= && make

# ══ Directories ════════════════════════════════════════════════════════════ #
#    -----------                                                              #

SRC_DIR				= ./philo/src
ERRORS_DIR			= ./philo/errors
INIT_DIR			= ./philo/init
UTILS_DIR			= ./philo/utils
OBJ_DIR				= ./philo/obj
INCLUDES_DIR		= ./philo/includes
MGE_PHILOS			= ./philo/manage_philos
MGE_THREADS			= ./philo/manage_threads

# # ══ Directories Bonus ════════════════════════════════════════════════════ #
# #    -----------------                                                      #

SRC_DIR_BONUS		= ./philo_bonus/src
ERRORS_DIR_BONUS	= ./philo_bonus/errors
INIT_DIR_BONUS		= ./philo_bonus/init
UTILS_DIR_BONUS		= ./philo_bonus/utils
OBJ_DIR_BONUS		= ./philo_bonus/obj
INCLUDES_DIR_BONUS	= ./philo_bonus/includes
MGE_PHILOS_BONUS	= ./philo/manage_philos

# ══ Flags ══════════════════════════════════════════════════════════════════ #
#    -----                                                                    #

CFLAGS 				= -Wall -Werror -Wextra
IFLAGS				= -I${INCLUDES_DIR}
LFLAGS				= -lpthread				

# # ══ Flags Bonus ══════════════════════════════════════════════════════════ #
# #    -------                                                                #

CFLAGS_BONUS 		= -Wall -Werror -Wextra
IFLAGS_BONUS		= -I${INCLUDES_DIR_BONUS}

# ══ Sources ════════════════════════════════════════════════════════════════ #
#    -------                                                                  #

SRC 				= ${SRC_DIR}/philosophers.c

ERR					= ${ERRORS_DIR}/ft_manage_err.c

INT					= ${INIT_DIR}/ft_init_struct.c \
						${INIT_DIR}/ft_init.c

MPH					= ${MGE_PHILOS}/ft_philos.c

MTH					= ${MGE_THREADS}/ft_threads.c

UTL					= ${UTILS_DIR}/ft_banner.c \
						${UTILS_DIR}/ft_utils.c \
						${UTILS_DIR}/ft_utils_2.c

OBJ_SRC				= $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})
OBJ_ERR				= $(patsubst ${ERRORS_DIR}/%.c, ${OBJ_DIR}/%.o, ${ERR})
OBJ_INT				= $(patsubst ${INIT_DIR}/%.c, ${OBJ_DIR}/%.o, ${INT})
OBJ_MPH				= $(patsubst ${MGE_PHILOS}/%.c, ${OBJ_DIR}/%.o, ${MPH})
OBJ_MTH				= $(patsubst ${MGE_THREADS}/%.c, ${OBJ_DIR}/%.o, ${MTH})
OBJ_UTL				= $(patsubst ${UTILS_DIR}/%.c, ${OBJ_DIR}/%.o, ${UTL})

OBJS				= ${OBJ_SRC} ${OBJ_ERR} ${OBJ_INT} \
					  	${OBJ_MPH} ${OBJ_MTH} ${OBJ_UTL}

# # ══ Sources Bonus ════════════════════════════════════════════════════════ #
# #    -------------                                                          #

SRC_BONUS 			= ${SRC_DIR_BONUS}/philosophers_bonus.c

ERR_BONUS			= ${ERRORS_DIR_BONUS}/ft_manage_err_bonus.c

INT_BONUS			= ${INIT_DIR_BONUS}/ft_init_struct_bonus.c \
						${INIT_DIR_BONUS}/ft_init_bonus.c

MPH_BONUS			= ${MGE_PHILOS_BONUS}/ft_philos_bonus.c

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

OBJS_BONUS			= ${OBJ_SRC_BONUS} ${OBJ_ERR_BONUS} ${OBJ_INT_BONUS} \
					  	${OBJ_MPH_BONUS} ${OBJ_UTL_BONUS}

# ═══ Rules ═════════════════════════════════════════════════════════════════ #
#     -----                                                                   #

# all: ${EXEC_DIR} ${EXEC_DIR}${NAME}

# ${NAME}: 							${OBJ_SRC} ${OBJ_GNL} ${OBJ_ERR} \
# 									${OBJ_INT} ${OBJ_MPH} ${OBJ_MTH} \
# 									${OBJ_UTL}

# all: ${NAME}

all: ${EXEC_PATH}

# ${NAME}: ${OBJS}
# 	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
# 	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJS} ${LFLAGS}
# 	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${EXEC_PATH}: ${OBJS}
	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${EXEC_PATH} ${OBJS} ${LFLAGS}
	@echo "$(GREEN)Executable created: ${EXEC_PATH} ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${ERRORS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${INIT_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${MGE_PHILOS}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@	

${OBJ_DIR}/%.o: ${MGE_THREADS}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${UTILS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

clean:
	@echo "$(YELLOW)Removing object files ...$(DEF_COLOR)"
	@$(RM) ${OBJ_DIR}/*.o
	@echo "$(RED)Object files removed $(DEF_COLOR)"

# fclean:	clean
# 	@echo "$(YELLOW)Removing binaries ...$(DEF_COLOR)"
# 	@${RM} ${NAME}
# 	@echo "$(GREEN)Binary removed!$(DEF_COLOR)"

fclean: clean
	@echo "$(YELLOW)Removing executables ...$(DEF_COLOR)"
	@${RM} ${EXEC_PATH}
	@echo "$(RED)Executable removed $(DEF_COLOR)"

re:	fclean all

.PHONY : all clean fclean bonus re

# # ═══ Rules Bonus ═════════════════════════════════════════════════════════ #
# #     -----------                                                           #

# all: ${EXEC_DIR} ${EXEC_DIR}${NAME}

# ${NAME}: 							${OBJ_SRC} ${OBJ_GNL} ${OBJ_ERR} \
# 									${OBJ_INT} ${OBJ_MPH} ${OBJ_MTH} \
# 									${OBJ_UTL}

# all: ${NAME}

all: ${EXEC_PATH_BONUS}

# ${NAME}: ${OBJS}
# 	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
# 	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJS} ${LFLAGS}
# 	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${EXEC_PATH_BONUS}: ${OBJS_BONUS}
	@echo "$(YELLOW)Compiling bonus root ...$(DEF_COLOR)"
	@${CC} ${CFLAGS_BONUS} ${IFLAGS_BONUS} -o ${EXEC_PATH_BONUS} ${OBJS_BONUS}
	@echo "$(GREEN)Executable created: ${EXEC_PATH_BONUS} ✓$(DEF_COLOR)"

${OBJ_DIR_BONUS}/%.o: ${SRC_DIR_BONUS}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS_BONUS} ${IFLAGS_BONUS} -c $< -o $@

${OBJ_DIR_BONUS}/%.o: ${ERRORS_DIR_BONUS}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS_BONUS} ${IFLAGS_BONUS} -c $< -o $@

${OBJ_DIR_BONUS}/%.o: ${INIT_DIR_BONUS}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS_BONUS} ${IFLAGS_BONUS} -c $< -o $@

${OBJ_DIR_BONUS}/%.o: ${MGE_PHILOS_BONUS}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS_BONUS} ${IFLAGS_BONUS} -c $< -o $@	

${OBJ_DIR_BONUS}/%.o: ${UTILS_DIR_BONUS}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS_BONUS} ${IFLAGS_BONUS} -c $< -o $@

clean:
	@echo "$(YELLOW)Removing object files ...$(DEF_COLOR)"
	@$(RM) ${OBJ_DIR_BONUS}/*.o
	@echo "$(RED)Object files removed $(DEF_COLOR)"

# fclean:	clean
# 	@echo "$(YELLOW)Removing binaries ...$(DEF_COLOR)"
# 	@${RM} ${NAME}
# 	@echo "$(GREEN)Binary removed!$(DEF_COLOR)"

fclean: clean
	@echo "$(YELLOW)Removing executables ...$(DEF_COLOR)"
	@${RM} ${EXEC_PATH_BONUS}
	@echo "$(RED)Executable removed $(DEF_COLOR)"

re:	fclean all

.PHONY : all clean fclean bonus re
