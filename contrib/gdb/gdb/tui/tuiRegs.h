begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_TUI_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|_TUI_REGS_H
end_define

begin_comment
comment|/* ** This header file supports the display of registers in the data window. */
end_comment

begin_comment
comment|/***************************************** ** TYPE DEFINITIONS                        ** ******************************************/
end_comment

begin_comment
comment|/***************************************** ** PUBLIC FUNCTION EXTERNAL DECLS        ** ******************************************/
end_comment

begin_decl_stmt
specifier|extern
name|void
name|tuiCheckRegisterValues
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiShowRegisters
name|PARAMS
argument_list|(
operator|(
name|TuiRegisterDisplayType
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiDisplayRegistersFrom
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
name|tuiDisplayRegistersFromLine
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tuiLastRegsLineNo
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tuiFirstRegElementInLine
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
name|tuiLastRegElementInLine
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
name|tuiLineFromRegElementNo
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
name|void
name|tuiToggleFloatRegs
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tuiCalculateRegsColumnCount
name|PARAMS
argument_list|(
operator|(
name|TuiRegisterDisplayType
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_TUI_REGS_H*/
end_comment

end_unit

