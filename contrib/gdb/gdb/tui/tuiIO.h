begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_TUI_IO_H
end_ifndef

begin_define
define|#
directive|define
name|_TUI_IO_H
end_define

begin_comment
comment|/* ** This header contains defitions to support tuiIO.c */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|extern
name|void
name|tuiPuts_unfiltered
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|GDB_FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|tuiGetc
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
name|unsigned
name|int
name|tuiBufferGetc
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
name|tuiRead
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
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
name|tuiStartNewLines
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
name|tui_vStartNewLines
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
name|unsigned
name|int
name|tui_vwgetch
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
name|tuiTermSetup
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
name|tuiTermUnsetup
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

begin_define
define|#
directive|define
name|m_tuiStartNewLine
value|tuiStartNewLines(1)
end_define

begin_define
define|#
directive|define
name|m_isStartSequence
parameter_list|(
name|ch
parameter_list|)
value|(ch == 27)
end_define

begin_define
define|#
directive|define
name|m_isEndSequence
parameter_list|(
name|ch
parameter_list|)
value|(ch == 126)
end_define

begin_define
define|#
directive|define
name|m_isBackspace
parameter_list|(
name|ch
parameter_list|)
value|(ch == 8)
end_define

begin_define
define|#
directive|define
name|m_isDeleteChar
parameter_list|(
name|ch
parameter_list|)
value|(ch == KEY_DC)
end_define

begin_define
define|#
directive|define
name|m_isDeleteLine
parameter_list|(
name|ch
parameter_list|)
value|(ch == KEY_DL)
end_define

begin_define
define|#
directive|define
name|m_isDeleteToEol
parameter_list|(
name|ch
parameter_list|)
value|(ch == KEY_EOL)
end_define

begin_define
define|#
directive|define
name|m_isNextPage
parameter_list|(
name|ch
parameter_list|)
value|(ch == KEY_NPAGE)
end_define

begin_define
define|#
directive|define
name|m_isPrevPage
parameter_list|(
name|ch
parameter_list|)
value|(ch == KEY_PPAGE)
end_define

begin_define
define|#
directive|define
name|m_isLeftArrow
parameter_list|(
name|ch
parameter_list|)
value|(ch == KEY_LEFT)
end_define

begin_define
define|#
directive|define
name|m_isRightArrow
parameter_list|(
name|ch
parameter_list|)
value|(ch == KEY_RIGHT)
end_define

begin_define
define|#
directive|define
name|m_isCommandChar
parameter_list|(
name|ch
parameter_list|)
value|(m_isNextPage(ch) || m_isPrevPage(ch) || \                                 m_isLeftArrow(ch) || m_isRightArrow(ch) || \                                 (ch == KEY_UP) || (ch == KEY_DOWN) || \                                 (ch == KEY_SF) || (ch == KEY_SR) || \                                 (ch == (int)'\f') || m_isStartSequence(ch))
end_define

begin_define
define|#
directive|define
name|m_isXdbStyleCommandChar
parameter_list|(
name|ch
parameter_list|)
value|(m_isNextPage(ch) || m_isPrevPage(ch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_TUI_IO_H*/
end_comment

end_unit

