begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_TUI_WIN_H
end_ifndef

begin_define
define|#
directive|define
name|_TUI_WIN_H
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
name|void
name|tuiScrollForward
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiScrollBackward
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiScrollLeft
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiScrollRight
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tui_vScroll
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiSetWinFocusTo
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiClearWinFocusFrom
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiClearWinFocus
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
name|void
name|tuiResizeAll
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
name|void
name|tuiRefreshAll
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
name|void
name|tuiSigwinchHandler
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_TUI_WIN_H*/
end_comment

end_unit

