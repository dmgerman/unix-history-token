begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_TUI_COMMAND_H
end_ifndef

begin_define
define|#
directive|define
name|_TUI_COMMAND_H
end_define

begin_comment
comment|/* ** This header file supports */
end_comment

begin_comment
comment|/***************************************** ** TYPE DEFINITIONS                        ** ******************************************/
end_comment

begin_comment
comment|/***************************************** ** PUBLIC FUNCTION EXTERNAL DECLS        ** ******************************************/
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|tuiDispatchCtrlChar
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tuiIncrCommandCharCountBy
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tuiDecrCommandCharCountBy
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tuiSetCommandCharCountTo
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tuiClearCommandCharCount
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_TUI_COMMAND_H*/
end_comment

end_unit

