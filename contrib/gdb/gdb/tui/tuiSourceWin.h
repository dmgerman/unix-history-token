begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_TUI_SOURCEWIN_H
end_ifndef

begin_define
define|#
directive|define
name|_TUI_SOURCEWIN_H
end_define

begin_comment
comment|/* ** This header file supports */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|tuiDisplayMainFunction
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
name|tuiUpdateSourceWindow
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|,
expr|struct
name|symtab
operator|*
operator|,
name|Opaque
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiUpdateSourceWindowAsIs
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|,
expr|struct
name|symtab
operator|*
operator|,
name|Opaque
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiUpdateSourceWindowsWithAddr
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
name|tui_vUpdateSourceWindowsWithAddr
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
name|tuiUpdateSourceWindowsWithLine
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tui_vUpdateSourceWindowsWithLine
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
name|tuiUpdateSourceWindowsFromLocator
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
name|tuiClearSourceContent
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
name|tuiClearAllSourceWinsContent
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
name|tuiEraseSourceContent
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
name|tuiEraseAllSourceWinsContent
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
name|tuiSetSourceContentNil
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiShowSourceContent
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
name|tuiShowAllSourceWinsContent
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
name|tuiHorizontalSourceScroll
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|,
name|TuiScrollDirection
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiUpdateOnEnd
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
name|TuiStatus
name|tuiSetExecInfoContent
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
name|tuiShowExecInfoContent
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
name|tuiShowAllExecInfosContent
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
name|tuiEraseExecInfoContent
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
name|tuiEraseAllExecInfosContent
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
name|tuiClearExecInfoContent
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
name|tuiClearAllExecInfosContent
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
name|tuiUpdateExecInfo
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
name|tuiUpdateAllExecInfos
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
name|tuiSetIsExecPointAt
name|PARAMS
argument_list|(
operator|(
name|Opaque
operator|,
name|TuiWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiSetHasBreakAt
name|PARAMS
argument_list|(
operator|(
expr|struct
name|breakpoint
operator|*
operator|,
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
name|tuiAllSetHasBreakAt
name|PARAMS
argument_list|(
operator|(
expr|struct
name|breakpoint
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tui_vAllSetHasBreakAt
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
name|TuiStatus
name|tuiAllocSourceBuffer
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
name|int
name|tuiLineIsDisplayed
name|PARAMS
argument_list|(
operator|(
name|Opaque
operator|,
name|TuiWinInfoPtr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ** Constant definitions */
end_comment

begin_define
define|#
directive|define
name|SCROLL_THRESHOLD
value|2
end_define

begin_comment
comment|/* threshold for lazy scroll */
end_comment

begin_comment
comment|/* ** Macros  */
end_comment

begin_define
define|#
directive|define
name|m_tuiSetBreakAt
parameter_list|(
name|bp
parameter_list|,
name|winInfo
parameter_list|)
value|tuiSetHasBreakAt((bp, winInfo, TRUE)
end_define

begin_define
define|#
directive|define
name|m_tuiClearBreakAt
parameter_list|(
name|bp
parameter_list|,
name|winInfo
parameter_list|)
value|tuiSetHasBreakAt(bp, winInfo, FALSE)
end_define

begin_define
define|#
directive|define
name|m_tuiAllSetBreakAt
parameter_list|(
name|bp
parameter_list|)
value|tuiAllSetHasBreakAt(bp, TRUE)
end_define

begin_define
define|#
directive|define
name|m_tuiAllClearBreakAt
parameter_list|(
name|bp
parameter_list|)
value|tuiAllSetHasBreakAt(bp, FALSE)
end_define

begin_define
define|#
directive|define
name|m_tuiSrcLineDisplayed
parameter_list|(
name|lineNo
parameter_list|)
value|tuiLineIsDisplayed((Opaque)(lineNo), srcWin, FALSE)
end_define

begin_define
define|#
directive|define
name|m_tuiSrcAddrDisplayed
parameter_list|(
name|addr
parameter_list|)
value|tuiLineIsDisplayed((Opaque)(addr), disassemWin, FALSE)
end_define

begin_define
define|#
directive|define
name|m_tuiSrcLineDisplayedWithinThreshold
parameter_list|(
name|lineNo
parameter_list|)
define|\
value|tuiLineIsDisplayed((Opaque)(lineNo), srcWin, TRUE)
end_define

begin_define
define|#
directive|define
name|m_tuiSrcAddrDisplayedWithinThreshold
parameter_list|(
name|addr
parameter_list|)
define|\
value|tuiLineIsDisplayed((Opaque)(addr), disassemWin, TRUE)
end_define

begin_define
define|#
directive|define
name|m_tuiLineDisplayedWithinThreshold
parameter_list|(
name|winInfo
parameter_list|,
name|lineOrAddr
parameter_list|)
define|\
value|( (winInfo == srcWin) ?                                    \                                         m_tuiSrcLineDisplayedWithinThreshold(lineOrAddr) :    \                                         m_tuiSrcAddrDisplayedWithinThreshold(lineOrAddr) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_TUI_SOURCEWIN_H */
end_comment

end_unit

