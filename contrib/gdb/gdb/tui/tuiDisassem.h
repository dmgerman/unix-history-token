begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_TUI_DISASSEM_H
end_ifndef

begin_define
define|#
directive|define
name|_TUI_DISASSEM_H
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
name|TuiStatus
name|tuiSetDisassemContent
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
operator|,
name|Opaque
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiShowDisassem
name|PARAMS
argument_list|(
operator|(
name|Opaque
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiShowDisassemAndUpdateSource
name|PARAMS
argument_list|(
operator|(
name|Opaque
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiVerticalDisassemScroll
name|PARAMS
argument_list|(
operator|(
name|TuiScrollDirection
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Opaque
name|tuiGetBeginAsmAddress
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
comment|/*_TUI_DISASSEM_H*/
end_comment

end_unit

