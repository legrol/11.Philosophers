# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all: ${NAME} 

${NAME}: ftlibft ftprintf ${OBJ_S} ${OBJ_C}
	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME_S} ${OBJ_S} ${LFLAGS}
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME_C} ${OBJ_C} ${LFLAGS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

ftlibft:
	@cd ${LIBFT_DIR} ${MK_} all

ftprintf:
	@cd ${PRINTFT_DIR} ${MK_} all

bonus: ${NAME_BONUS}

${NAME_BONUS}: ftlibft ftprintf ${OBJ_S_BN} ${OBJ_C_BN}
	@echo "$(YELLOW)Compiling bonus root ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME_S_BN} ${OBJ_S_BN} ${LFLAGS}
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME_C_BN} ${OBJ_C_BN} ${LFLAGS}
	@echo "$(GREEN) $(NAME_BONUS) all bonus created ✓$(DEF_COLOR)"

clean:
	@echo "$(YELLOW)Remove main .o  ...$(DEF_COLOR)"

	@cd ${LIBFT_DIR} ${MK_} clean
	@cd ${PRINTFT_DIR} ${MK_} clean
	@$(RM) $(OBJ_S) $(OBJ_C)
	@$(RM) $(OBJ_S_BN) $(OBJ_C_BN)
	@${RM} ${NAME_S} ${NAME_C}
	@${RM} ${NAME_S_BN} ${NAME_C_BN}

	@echo "$(RED)OBJS deleted $(DEF_COLOR)"

fclean:	clean
	@echo "$(YELLOW)Remove main lib ...$(DEF_COLOR)"

	@cd ${LIBFT_DIR} ${MK_} fclean
	@cd ${PRINTFT_DIR} ${MK_} fclean

	@echo "$(RED)$(NAME)|$(NAME_BONUS) deleted$(DEF_COLOR)"

re:	fclean all

.PHONY : all libft printf clean fclean bonus re