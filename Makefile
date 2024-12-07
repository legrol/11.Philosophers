# ══ Names ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

NAME 				= philo
NAME_BONUS			= philo_bonus

# ══ Colors ══════════════════════════════════════════════════════════════════ #
#    ------                                                                    #

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

# ══ Compilation══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

CC 					= clang
AR 					= ar rcs
RM 					= rm -f
MK 					= make -C -g
MKD					= mkdir -p
MCL 				= make clean -C
MFCL 				= make fclean -C
MK_					= && make

# ══ Directories ═════════════════════════════════════════════════════════════ #
#    -----------                                                               #

SRC_DIR				= ./philo/src
ERRORS_DIR			= ./philo/errors
# FREE_DIR			= ./philo/free
INIT_DIR			= ./philo/init
UTILS_DIR			= ./philo/utils
LIBRARIES			= ./philo/libs
OBJ_DIR				= ./philo/obj
INCLUDES_DIR		= ./philo/includes
LIBFT_DIR			= libft
PRINTFT_DIR			= printf
EXAMFT_DIR			= examft
GNL_DIR				= gnl

# ══ Directories Bonus ═══════════════════════════════════════════════════════ #
#    -----------------                                                         #

SRC_DIR_BONUS		= ./philo_bonus/src
ERRORS_DIR_BONUS	= ./philo_bonus/errors
# FREE_DIR_BONUS	= ./philo_bonus/free
INIT_DIR_BONUS		= ./philo_bonus/init
UTILS_DIR_BONUS		= ./philo_bonus/utils
LIBRARIES_BONUS		= ./philo_bonus/libs
OBJ_DIR_BONUS		= ./phphilo_bonusilo/obj
INCLUDES_DIR_BONUS	= ./philo_bonus/includes
LIBFT_DIR_BONUS		= libft
PRINTFT_DIR_BONUS	= printf
EXAMFT_DIR_BONUS	= examft
GNL_DIR_BONUS		= gnl

# ══ Library Archives ════════════════════════════════════════════════════════ #
#    ----------------                                                          #

LIBFT_A				= ${LIBRARIES}/${LIBFT_DIR}/libft.a
PRINTFT_A			= ${LIBRARIES}/${PRINTFT_DIR}/libftprintf.a
EXAMFT_A			= ${LIBRARIES}/${EXAMFT_DIR}/libexamft.a

# ══ Library Archives Bonus ══════════════════════════════════════════════════ #
#    ----------------------                                                    #

LIBFT_A_BONUS		= ${LIBRARIES_BONUS}/${LIBFT_DIR_BONUS}/libft.a
PRINTFT_A_BONUS		= ${LIBRARIES_BONUS}/${PRINTFT_DIR_BONUS}/libftprintf.a
EXAMFT_A_BONUS		= ${LIBRARIES_BONUS}/${EXAMFT_DIR_BONUS}/libexamft.a

# ══ Flags ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

CFLAGS 				= -Wall -Werror -Wextra
IFLAGS				= -I${INCLUDES_DIR}
LFLAGS				= -L${LIBRARIES}/${LIBFT_DIR} -lft \
						-L${LIBRARIES}/${PRINTFT_DIR} -lftprintf \
						-L${LIBRARIES}/${EXAMFT_DIR} -lexamft -lreadline \
						-lpthread				

# ══ Flags Bonus══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

CFLAGS_BONUS 		= -Wall -Werror -Wextra
IFLAGS_BONUS		= -I${INCLUDES_DIR_BONUS}
LFLAGS_BONUS		= -L${LIBRARIES_BONUS}/${LIBFT_DIR_BONUS} -lft \
						-L${LIBRARIES_BONUS}/${PRINTFT_DIR_BONUS} -lftprintf \
						-L${LIBRARIES_BONUS}/${EXAMFT_DIR_BONUS} -lexamft \
						-lreadline -lpthread		

# ══ Sources ═════════════════════════════════════════════════════════════════ #
#    -------                                                                   #

SRC 				= ${SRC_DIR}/philosophers.c

GNL					= ${LIBRARIES}/${GNL_DIR}/get_next_line.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_utils.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_bonus.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_utils_bonus.c

ERR					= ${ERRORS_DIR}/ft_manage_err.c

INT					= ${INIT_DIR}/ft_init_struct.c \
						${INIT_DIR}/ft_init.c

UTL					= ${UTILS_DIR}/ft_utils.c

# FRE				= ${FREE_DIR}/ft_free_envp_list.c \
# 						${FREE_DIR}/ft_free_split.c \
# 						${FREE_DIR}/ft_free_tokens.c \
# 						${FREE_DIR}/ft_free_ast.c

OBJ_SRC				= $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})
OBJ_GNL				= $(patsubst ${LIBRARIES}/${GNL_DIR}/%.c, ${OBJ_DIR}/%.o, \
						${GNL})
OBJ_ERR				= $(patsubst ${ERRORS_DIR}/%.c, ${OBJ_DIR}/%.o, ${ERR})
OBJ_INT				= $(patsubst ${INIT_DIR}/%.c, ${OBJ_DIR}/%.o, ${INT})
OBJ_UTL				= $(patsubst ${UTILS_DIR}/%.c, ${OBJ_DIR}/%.o, ${UTL})
# OBJ_FRE				= $(patsubst ${FREE_DIR}/%.c, ${OBJ_DIR}/%.o, ${FRE})

# ══ Sources Bonus ═══════════════════════════════════════════════════════════ #
#    -------------                                                             #

SRC_BONUS 			= ${SRC_DIR_BONUS}/philosophers.c

GNL_BONUS		= ${LIBRARIES_BONUS}/${GNL_DIR_BONUS}/get_next_line.c \
					${LIBRARIES_BONUS}/${GNL_DIR_BONUS}/get_next_line_utils.c \
					${LIBRARIES_BONUS}/${GNL_DIR_BONUS}/get_next_line_bonus.c \
					${LIBRARIES_BONUS}/${GNL_DIR_BONUS}/\
						get_next_line_utils_bonus.c

ERR_BONUS		= ${ERRORS_DIR_BONUS}/ft_manage_err.c

INT_BONUS		= ${INIT_DIR_BONUS}/ft_init_struct.c \
					${INIT_DIR_BONUS}/ft_init.c

UTL_BONUS		= ${UTILS_DIR_BONUS}/ft_utils.c

# FRE_BONUS		= ${FREE_DIR_BONUS}/ft_free_envp_list.c \
# 					${FREE_DIR_BONUS}/ft_free_split.c \
# 					${FREE_DIR_BONUS}/ft_free_tokens.c \
# 					${FREE_DIR_BONUS}/ft_free_ast.c

OBJ_SRC_BONUS	= $(patsubst ${SRC_DIR_BONUS}/%.c, ${OBJ_DIR_BONUS}/%.o, \
					${SRC_BONUS})
OBJ_GNL_BONUS	= $(patsubst ${LIBRARIES_BONUS}/${GNL_DIR_BONUS}/%.c, \
					${OBJ_DIR_BONUS}/%.o, ${GNL_BONUS})
OBJ_ERR_BONUS	= $(patsubst ${ERRORS_DIR_BONUS}/%.c, ${OBJ_DIR_BONUS}/%.o, \
					${ERR_BONUS})
OBJ_INT_BONUS	= $(patsubst ${INIT_DIR_BONUS}/%.c, ${OBJ_DIR_BONUS}/%.o, \
					${INT_BONUS})
OBJ_UTL_BONUS	= $(patsubst ${UTILS_DIR_BONUS}/%.c, ${OBJ_DIR_BONUS}/%.o, \
					${UTL_BONUS})
# OBJ_FRE_BONUS	= $(patsubst ${FREE_DIR_BONUS}/%.c, ${OBJ_DIR_BONUS}/%.o, \
					${FRE_BONUS})

# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all: ${NAME}

${NAME}: ftlibft ftprintf ftexamft  ${OBJ_SRC} ${OBJ_GNL} \
									${OBJ_ERR} ${OBJ_INT} ${OBJ_UTL} \
									${OBJ_FRE} ${OBJ_BUI}
	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJ_SRC} ${OBJ_GNL} ${OBJ_ERR} \
									${OBJ_INT} ${OBJ_UTL} ${OBJ_FRE} \
									${OBJ_BUI} ${LFLAGS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${LIBRARIES}/${GNL_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${ERRORS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${INIT_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${UTILS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

# ${OBJ_DIR}/%.o: ${FREE_DIR}/%.c
# 	@${MKD} $(dir $@)
# 	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

ftlibft:
	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} all

ftprintf:
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} all

ftexamft:
	@cd ${LIBRARIES}/${EXAMFT_DIR} ${MK_} all

clean:
	@echo "$(YELLOW)Removing object files ...$(DEF_COLOR)"

	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} clean
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} clean
	@cd ${LIBRARIES}/${EXAMFT_DIR} ${MK_} clean
	@$(RM) ${OBJ_DIR}/*.o

	@echo "$(RED)Object files removed $(DEF_COLOR)"

fclean:	clean
	@echo "$(YELLOW)Removing binaries ...$(DEF_COLOR)"

	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} fclean
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} fclean
	@cd ${LIBRARIES}/${EXAMFT_DIR} ${MK_} fclean
	@${RM} ${NAME} ${NAME_BONUS}

	@echo "$(RED)Binaries removed $(DEF_COLOR)"

re:	fclean all

.PHONY : all ftlibft ftprintf ftexamft clean fclean bonus re

# # ═══ Rules Bonus ════════════════════════════════════════════════════════════ #
# #     -----------                                                              #

# all: ${NAME_BONUS}

# ${NAME}: ftlibft_bonus ftprintf_bonus ftexamft_bonus  ${OBJ_SRC_BONUS} \
									${OBJ_GNL_BONUS} \
# 									${OBJ_ERR_BONUS} ${OBJ_INT_BONUS} ${OBJ_UTL_BONUS} \
# 									${OBJ_FRE_BONUS} ${OBJ_BUI_BONUS}
# 	@echo "$(YELLOW)Compiling bonus ...$(DEF_COLOR)"
# 	@${CC} ${CFLAGS_BONUS} ${IFLAGS_BONUS} -o ${NAME_BONUS} ${OBJ_SRC_BONUS} ${OBJ_GNL_BONUS} ${OBJ_ERR_BONUS} \
# 									${OBJ_INT_BONUS} ${OBJ_UTL_BONUS} ${OBJ_FRE_BONUS} \
# 									${OBJ_BUI_BONUS} ${LFLAGS_BONUS}
# 	@echo "$(GREEN) $(NAME) all bonus created ✓$(DEF_COLOR)"

# ${OBJ_DIR}/%.o: ${SRC_DIR_BONUS}/%.c
# 	@${MKD} $(dir $@)
# 	@$(CC) ${CFLAGS_BONUS} ${IFLAGS_BONUS} -c $< -o $@

# ${OBJ_DIR}/%.o: ${LIBRARIES_BONUS}/${GNL_DIR_BONUS}/%.c
# 	@${MKD} $(dir $@)
# 	@$(CC) ${CFLAGS_BONUS} ${IFLAGS_BONUS} -c $< -o $@

# ${OBJ_DIR}/%.o: ${ERRORS_DIR_BONUS}/%.c
# 	@${MKD} $(dir $@)
# 	@$(CC) ${CFLAGS_BONUS} ${IFLAGS_BONUS} -c $< -o $@

# ${OBJ_DIR}/%.o: ${INIT_DIR_BONUS}/%.c
# 	@${MKD} $(dir $@)
# 	@$(CC) ${CFLAGS_BONUS} ${IFLAGS_BONUS} -c $< -o $@

# ${OBJ_DIR}/%.o: ${UTILS_DIR_BONUS}/%.c
# 	@${MKD} $(dir $@)
# 	@$(CC) ${CFLAGS_BONUS} ${IFLAGS_BONUS} -c $< -o $@

# # ${OBJ_DIR}/%.o: ${FREE_DIR_BONUS}/%.c
# # 	@${MKD} $(dir $@)
# # 	@$(CC) ${CFLAGS_BONUS} ${IFLAGS_BONUS} -c $< -o $@

# ftlibft_bonus:
# 	@cd ${LIBRARIES_BONUS}/${LIBFT_DIR_BONUS} ${MK_} all

# ftprintf_bonus:
# 	@cd ${LIBRARIES_BONUS}/${PRINTFT_DIR_BONUS} ${MK_} all

# ftexamft_bonus:
# 	@cd ${LIBRARIES_BONUS}/${EXAMFT_DIR_BONUS} ${MK_} all

# clean:
# 	@echo "$(YELLOW)Removing object files bonus...$(DEF_COLOR)"

# 	@cd ${LIBRARIES_BONUS}/${LIBFT_DIR_BONUS} ${MK_} clean
# 	@cd ${LIBRARIES_BONUS}/${PRINTFT_DIR_BONUS} ${MK_} clean
# 	@cd ${LIBRARIES_BONUS}/${EXAMFT_DIR_BONUS} ${MK_} clean
# 	@$(RM) ${OBJ_DIR_BONUS}/*.o

# 	@echo "$(RED)Object files bonus removed $(DEF_COLOR)"

# fclean:	clean
# 	@echo "$(YELLOW)Removing binaries ...$(DEF_COLOR)"

# 	@cd ${LIBRARIES_BONUS}/${LIBFT_DIR_BONUS} ${MK_} fclean
# 	@cd ${LIBRARIES_BONUS}/${PRINTFT_DIR_BONUS} ${MK_} fclean
# 	@cd ${LIBRARIES_BONUS}/${EXAMFT_DIR_BONUS} ${MK_} fclean
# 	@${RM} ${NAME} ${NAME_BONUS}

# 	@echo "$(RED)Binaries removed $(DEF_COLOR)"

# re:	fclean all

# .PHONY : all ftlibft_bonus ftprintf_bonus ftexamft_bonus clean fclean bonus re
