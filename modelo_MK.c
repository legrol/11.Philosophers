// # ═══ Rules ══════════════════════════════════════════════════════════════════ #
// #     -----                                                                    #

// all: ${NAME} 

// ${NAME}: ftlibft ftprintf ${OBJ_S} ${OBJ_C}
// 	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
// 	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME_S} ${OBJ_S} ${LFLAGS}
// 	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME_C} ${OBJ_C} ${LFLAGS}
// 	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

// %.o: %.c
// 	@$(CC) $(FLAGS) -c $< -o $@

// ftlibft:
// 	@cd ${LIBFT_DIR} ${MK_} all

// ftprintf:
// 	@cd ${PRINTFT_DIR} ${MK_} all

// bonus: ${NAME_BONUS}

// ${NAME_BONUS}: ftlibft ftprintf ${OBJ_S_BN} ${OBJ_C_BN}
// 	@echo "$(YELLOW)Compiling bonus root ...$(DEF_COLOR)"
// 	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME_S_BN} ${OBJ_S_BN} ${LFLAGS}
// 	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME_C_BN} ${OBJ_C_BN} ${LFLAGS}
// 	@echo "$(GREEN) $(NAME_BONUS) all bonus created ✓$(DEF_COLOR)"

// clean:
// 	@echo "$(YELLOW)Remove main .o  ...$(DEF_COLOR)"

// 	@cd ${LIBFT_DIR} ${MK_} clean
// 	@cd ${PRINTFT_DIR} ${MK_} clean
// 	@$(RM) $(OBJ_S) $(OBJ_C)
// 	@$(RM) $(OBJ_S_BN) $(OBJ_C_BN)
// 	@${RM} ${NAME_S} ${NAME_C}
// 	@${RM} ${NAME_S_BN} ${NAME_C_BN}

// 	@echo "$(RED)OBJS deleted $(DEF_COLOR)"

// fclean:	clean
// 	@echo "$(YELLOW)Remove main lib ...$(DEF_COLOR)"

// 	@cd ${LIBFT_DIR} ${MK_} fclean
// 	@cd ${PRINTFT_DIR} ${MK_} fclean

// 	@echo "$(RED)$(NAME)|$(NAME_BONUS) deleted$(DEF_COLOR)"

// re:	fclean all

// .PHONY : all libft printf clean fclean bonus re








// bonus: $(EXEC_PATH_BONUS)

// $(EXEC_PATH_BONUS): $(OBJS_BONUS)
// 	@echo "$(YELLOW)Compiling bonus root ...$(DEF_COLOR)"
// 	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR_BONUS) -o $(EXEC_PATH_BONUS) $(OBJS_BONUS) $(LFLAGS)
// 	@echo "$(GREEN)Executable created: $(EXEC_PATH_BONUS) ✓$(DEF_COLOR)"

// $(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
// 	@$(MKD) $(dir $@)
// 	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR_BONUS) -c $< -o $@

// clean:
// 	@echo "$(YELLOW)Removing object files ...$(DEF_COLOR)"
	// @$(RM) $(OBJS) $(OBJS_BONUS)
	// @$(RM) -r $(OBJ_DIR) $(OBJ_DIR_BONUS)
	// @echo "$(RED)Object files removed $(DEF_COLOR)"

// fclean: clean
// 	@echo "$(YELLOW)Removing executables ...$(DEF_COLOR)"
// 	@$(RM) $(EXEC_PATH) $(EXEC_PATH_BONUS)
// 	@echo "$(RED)Executables removed $(DEF_COLOR)"

// re: fclean all

// .PHONY: all bonus clean fclean re