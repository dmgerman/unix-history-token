begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TUI_LAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|TUI_LAYOUT_H
end_define

begin_decl_stmt
specifier|extern
name|void
name|showLayout
name|PARAMS
argument_list|(
operator|(
name|TuiLayoutType
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiAddWinToLayout
name|PARAMS
argument_list|(
operator|(
name|TuiWinType
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tui_vAddWinToLayout
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
name|int
name|tuiDefaultWinHeight
name|PARAMS
argument_list|(
operator|(
name|TuiWinType
operator|,
name|TuiLayoutType
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tuiDefaultWinViewportHeight
name|PARAMS
argument_list|(
operator|(
name|TuiWinType
operator|,
name|TuiLayoutType
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiStatus
name|tuiSetLayout
name|PARAMS
argument_list|(
operator|(
name|TuiLayoutType
operator|,
name|TuiRegisterDisplayType
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiStatus
name|tui_vSetLayoutTo
name|PARAMS
argument_list|(
operator|(
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*TUI_LAYOUT_H*/
end_comment

end_unit

