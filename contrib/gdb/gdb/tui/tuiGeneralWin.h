begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TUI_GENERAL_WIN_H
end_ifndef

begin_define
define|#
directive|define
name|TUI_GENERAL_WIN_H
end_define

begin_comment
comment|/* ** Functions */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|tuiClearWin
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unhighlightWin
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
name|makeVisible
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|makeAllVisible
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
name|scrollWinForward
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|scrollWinBackward
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|makeWindow
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiWinInfoPtr
name|copyWin
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
name|boxWin
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|highlightWin
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
name|checkAndDisplayHighlightIfNeeded
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
name|refreshAll
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiDelwin
name|PARAMS
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiRefreshWin
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ** Macros */
end_comment

begin_define
define|#
directive|define
name|m_beVisible
parameter_list|(
name|winInfo
parameter_list|)
value|makeVisible((TuiGenWinInfoPtr)(winInfo), TRUE)
end_define

begin_define
define|#
directive|define
name|m_beInvisible
parameter_list|(
name|winInfo
parameter_list|)
define|\
value|makeVisible((TuiGenWinInfoPtr)(winInfo), FALSE)
end_define

begin_define
define|#
directive|define
name|m_allBeVisible
parameter_list|()
value|makeAllVisible(TRUE)
end_define

begin_define
define|#
directive|define
name|m_allBeInvisible
parameter_list|()
value|makeAllVisible(FALSE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*TUI_GENERAL_WIN_H*/
end_comment

end_unit

