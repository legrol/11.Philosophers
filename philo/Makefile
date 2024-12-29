# ══ Names ══════════════════════════════════════════════════════════════════ #
#    -----                                                                    #

NAME 				= philo

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

# ══ Directories ════════════════════════════════════════════════════════════ #
#    -----------                                                              #

SRC_DIR				= ./src
ERRORS_DIR			= ./errors
INIT_DIR			= ./init
UTILS_DIR			= ./utils
OBJ_DIR				= ./obj
INCLUDES_DIR		= ./includes
MGE_PHILOS			= ./manage_philos
MGE_THREADS			= ./manage_threads

# ══ Flags ══════════════════════════════════════════════════════════════════ #
#    -----                                                                    #

# CFLAGS 				= -Wall -Werror -Wextra
CFLAGS 				= -Wall -Werror -Wextra -fsanitize=thread
IFLAGS				= -I${INCLUDES_DIR}
LFLAGS				= -lpthread				

# ══ Sources ════════════════════════════════════════════════════════════════ #
#    -------                                                                  #

SRC 				= ${SRC_DIR}/philosophers.c

ERR					= ${ERRORS_DIR}/ft_manage_err.c

INT					= ${INIT_DIR}/ft_init_struct.c \
						${INIT_DIR}/ft_init.c

MPH					= ${MGE_PHILOS}/ft_philos.c \
						${MGE_PHILOS}/ft_philos_tools.c

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

# ═══ Rules ═════════════════════════════════════════════════════════════════ #
#     -----                                                                   #

all: ${NAME}

${NAME}: ${OBJS}
	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJS} ${LFLAGS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

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

fclean: clean
	@echo "$(YELLOW)Removing executables ...$(DEF_COLOR)"
	@${RM} ${NAME}
	@echo "$(RED)Executable removed $(DEF_COLOR)"

re:	fclean all

.PHONY : all clean fclean re
