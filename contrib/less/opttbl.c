begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1984-2000  Mark Nudelman  *  * You may distribute under the terms of either the GNU General Public  * License or the Less License, as specified in the README file.  *  * For more information about less, or for information on how to   * contact the author, see the README file.  */
end_comment

begin_comment
comment|/*  * The option table.  */
end_comment

begin_include
include|#
directive|include
file|"less.h"
end_include

begin_include
include|#
directive|include
file|"option.h"
end_include

begin_comment
comment|/*  * Variables controlled by command line options.  */
end_comment

begin_decl_stmt
name|public
name|int
name|quiet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Should we suppress the audible bell? */
end_comment

begin_decl_stmt
name|public
name|int
name|how_search
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where should forward searches start? */
end_comment

begin_decl_stmt
name|public
name|int
name|top_scroll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Repaint screen from top? 				   (alternative is scroll from bottom) */
end_comment

begin_decl_stmt
name|public
name|int
name|pr_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Type of prompt (short, medium, long) */
end_comment

begin_decl_stmt
name|public
name|int
name|bs_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* How to process backspaces */
end_comment

begin_decl_stmt
name|public
name|int
name|know_dumb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't complain about dumb terminals */
end_comment

begin_decl_stmt
name|public
name|int
name|quit_at_eof
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Quit after hitting end of file twice */
end_comment

begin_decl_stmt
name|public
name|int
name|quit_if_one_screen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Quit if EOF on first screen */
end_comment

begin_decl_stmt
name|public
name|int
name|squeeze
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Squeeze multiple blank lines into one */
end_comment

begin_decl_stmt
name|public
name|int
name|tabstop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tab settings */
end_comment

begin_decl_stmt
name|public
name|int
name|back_scroll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Repaint screen on backwards movement */
end_comment

begin_decl_stmt
name|public
name|int
name|forw_scroll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Repaint screen on forward movement */
end_comment

begin_decl_stmt
name|public
name|int
name|caseless
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do "caseless" searches */
end_comment

begin_decl_stmt
name|public
name|int
name|linenums
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use line numbers */
end_comment

begin_decl_stmt
name|public
name|int
name|cbufs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current number of buffers */
end_comment

begin_decl_stmt
name|public
name|int
name|autobuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Automatically allocate buffers as needed */
end_comment

begin_decl_stmt
name|public
name|int
name|ctldisp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send control chars to screen untranslated */
end_comment

begin_decl_stmt
name|public
name|int
name|force_open
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open the file even if not regular file */
end_comment

begin_decl_stmt
name|public
name|int
name|swindow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of scrolling window */
end_comment

begin_decl_stmt
name|public
name|int
name|jump_sline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Screen line of "jump target" */
end_comment

begin_decl_stmt
name|public
name|int
name|chopline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Truncate displayed lines at screen width */
end_comment

begin_decl_stmt
name|public
name|int
name|no_init
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Disable sending ti/te termcap strings */
end_comment

begin_decl_stmt
name|public
name|int
name|twiddle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Show tildes after EOF */
end_comment

begin_decl_stmt
name|public
name|int
name|show_attn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hilite first unread line */
end_comment

begin_decl_stmt
name|public
name|int
name|shift_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of positions to shift horizontally */
end_comment

begin_decl_stmt
name|public
name|int
name|status_col
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display a status column */
end_comment

begin_if
if|#
directive|if
name|HILITE_SEARCH
end_if

begin_decl_stmt
name|public
name|int
name|hilite_search
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Highlight matched search patterns? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Long option names.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|optname
name|a_optname
init|=
block|{
literal|"search-skip-screen"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|b_optname
init|=
block|{
literal|"buffers"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|B__optname
init|=
block|{
literal|"auto-buffers"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|c_optname
init|=
block|{
literal|"clear-screen"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|d_optname
init|=
block|{
literal|"dumb"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|MSDOS_COMPILER
end_if

begin_decl_stmt
specifier|static
name|struct
name|optname
name|D__optname
init|=
block|{
literal|"color"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|struct
name|optname
name|e_optname
init|=
block|{
literal|"quit-at-eof"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|f_optname
init|=
block|{
literal|"force"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|F__optname
init|=
block|{
literal|"quit-if-one-screen"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|HILITE_SEARCH
end_if

begin_decl_stmt
specifier|static
name|struct
name|optname
name|g_optname
init|=
block|{
literal|"hilite-search"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|struct
name|optname
name|h_optname
init|=
block|{
literal|"max-back-scroll"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|i_optname
init|=
block|{
literal|"ignore-case"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|j_optname
init|=
block|{
literal|"jump-target"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|J__optname
init|=
block|{
literal|"status-column"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|USERFILE
end_if

begin_decl_stmt
specifier|static
name|struct
name|optname
name|k_optname
init|=
block|{
literal|"lesskey-file"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|struct
name|optname
name|m_optname
init|=
block|{
literal|"long-prompt"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|n_optname
init|=
block|{
literal|"line-numbers"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|LOGFILE
end_if

begin_decl_stmt
specifier|static
name|struct
name|optname
name|o_optname
init|=
block|{
literal|"log-file"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|O__optname
init|=
block|{
literal|"LOG-FILE"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|struct
name|optname
name|p_optname
init|=
block|{
literal|"pattern"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|P__optname
init|=
block|{
literal|"prompt"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|q2_optname
init|=
block|{
literal|"silent"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|q_optname
init|=
block|{
literal|"quiet"
block|,
operator|&
name|q2_optname
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|r_optname
init|=
block|{
literal|"raw-control-chars"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|s_optname
init|=
block|{
literal|"squeeze-blank-lines"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|S__optname
init|=
block|{
literal|"chop-long-lines"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|TAGS
end_if

begin_decl_stmt
specifier|static
name|struct
name|optname
name|t_optname
init|=
block|{
literal|"tag"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|T__optname
init|=
block|{
literal|"tag-file"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|struct
name|optname
name|u_optname
init|=
block|{
literal|"underline-special"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|V__optname
init|=
block|{
literal|"version"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|w_optname
init|=
block|{
literal|"hilite-unread"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|x_optname
init|=
block|{
literal|"tabs"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|X__optname
init|=
block|{
literal|"no-init"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|y_optname
init|=
block|{
literal|"max-forw-scroll"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|z_optname
init|=
block|{
literal|"window"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|quote_optname
init|=
block|{
literal|"quotes"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|tilde_optname
init|=
block|{
literal|"tilde"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|query_optname
init|=
block|{
literal|"help"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|optname
name|pound_optname
init|=
block|{
literal|"shift"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Table of all options and their semantics.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|option
name|option
index|[]
init|=
block|{
block|{
literal|'a'
block|,
operator|&
name|a_optname
block|,
name|BOOL
block|,
name|OPT_OFF
block|,
operator|&
name|how_search
block|,
name|NULL
block|,
literal|"Search includes displayed screen"
block|,
literal|"Search skips displayed screen"
block|,
name|NULL
block|}
block|,
block|{
literal|'b'
block|,
operator|&
name|b_optname
block|,
name|NUMBER
block|,
literal|10
block|,
operator|&
name|cbufs
block|,
name|opt_b
block|,
literal|"Buffers: "
block|,
literal|"%d buffers"
block|,
name|NULL
block|}
block|,
block|{
literal|'B'
block|,
operator|&
name|B__optname
block|,
name|BOOL
block|,
name|OPT_ON
block|,
operator|&
name|autobuf
block|,
name|NULL
block|,
literal|"Don't automatically allocate buffers"
block|,
literal|"Automatically allocate buffers when needed"
block|,
name|NULL
block|}
block|,
block|{
literal|'c'
block|,
operator|&
name|c_optname
block|,
name|TRIPLE
block|,
name|OPT_OFF
block|,
operator|&
name|top_scroll
block|,
name|NULL
block|,
literal|"Repaint by scrolling from bottom of screen"
block|,
literal|"Repaint by clearing each line"
block|,
literal|"Repaint by painting from top of screen"
block|}
block|,
block|{
literal|'d'
block|,
operator|&
name|d_optname
block|,
name|BOOL
operator||
name|NO_TOGGLE
block|,
name|OPT_OFF
block|,
operator|&
name|know_dumb
block|,
name|NULL
block|,
literal|"Assume intelligent terminal"
block|,
literal|"Assume dumb terminal"
block|,
name|NULL
block|}
block|,
if|#
directive|if
name|MSDOS_COMPILER
block|{
literal|'D'
block|,
operator|&
name|D__optname
block|,
name|STRING
operator||
name|REPAINT
operator||
name|NO_QUERY
block|,
literal|0
block|,
name|NULL
block|,
name|opt_D
block|,
literal|"color desc: "
block|,
name|NULL
block|,
name|NULL
block|}
block|,
endif|#
directive|endif
block|{
literal|'e'
block|,
operator|&
name|e_optname
block|,
name|TRIPLE
block|,
name|OPT_OFF
block|,
operator|&
name|quit_at_eof
block|,
name|NULL
block|,
literal|"Don't quit at end-of-file"
block|,
literal|"Quit at end-of-file"
block|,
literal|"Quit immediately at end-of-file"
block|}
block|,
block|{
literal|'f'
block|,
operator|&
name|f_optname
block|,
name|BOOL
block|,
name|OPT_OFF
block|,
operator|&
name|force_open
block|,
name|NULL
block|,
literal|"Open only regular files"
block|,
literal|"Open even non-regular files"
block|,
name|NULL
block|}
block|,
block|{
literal|'F'
block|,
operator|&
name|F__optname
block|,
name|BOOL
block|,
name|OPT_OFF
block|,
operator|&
name|quit_if_one_screen
block|,
name|NULL
block|,
literal|"Don't quit if end-of-file on first screen"
block|,
literal|"Quit if end-of-file on first screen"
block|,
name|NULL
block|}
block|,
if|#
directive|if
name|HILITE_SEARCH
block|{
literal|'g'
block|,
operator|&
name|g_optname
block|,
name|TRIPLE
operator||
name|HL_REPAINT
block|,
name|OPT_ONPLUS
block|,
operator|&
name|hilite_search
block|,
name|NULL
block|,
literal|"Don't highlight search matches"
block|,
literal|"Highlight matches for previous search only"
block|,
literal|"Highlight all matches for previous search pattern"
block|, 	}
block|,
endif|#
directive|endif
block|{
literal|'h'
block|,
operator|&
name|h_optname
block|,
name|NUMBER
block|,
operator|-
literal|1
block|,
operator|&
name|back_scroll
block|,
name|NULL
block|,
literal|"Backwards scroll limit: "
block|,
literal|"Backwards scroll limit is %d lines"
block|,
name|NULL
block|}
block|,
block|{
literal|'i'
block|,
operator|&
name|i_optname
block|,
name|TRIPLE
operator||
name|HL_REPAINT
block|,
name|OPT_OFF
block|,
operator|&
name|caseless
block|,
name|opt_i
block|,
literal|"Case is significant in searches"
block|,
literal|"Ignore case in searches"
block|,
literal|"Ignore case in searches and in patterns"
block|}
block|,
block|{
literal|'j'
block|,
operator|&
name|j_optname
block|,
name|NUMBER
block|,
literal|1
block|,
operator|&
name|jump_sline
block|,
name|NULL
block|,
literal|"Target line: "
block|,
literal|"Position target at screen line %d"
block|,
name|NULL
block|}
block|,
block|{
literal|'J'
block|,
operator|&
name|J__optname
block|,
name|BOOL
operator||
name|REPAINT
block|,
name|OPT_OFF
block|,
operator|&
name|status_col
block|,
name|NULL
block|,
literal|"Don't display a status column"
block|,
literal|"Display a status column"
block|,
name|NULL
block|}
block|,
if|#
directive|if
name|USERFILE
block|{
literal|'k'
block|,
operator|&
name|k_optname
block|,
name|STRING
operator||
name|NO_TOGGLE
operator||
name|NO_QUERY
block|,
literal|0
block|,
name|NULL
block|,
name|opt_k
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
endif|#
directive|endif
block|{
literal|'l'
block|,
name|NULL
block|,
name|STRING
operator||
name|NO_TOGGLE
operator||
name|NO_QUERY
block|,
literal|0
block|,
name|NULL
block|,
name|opt_l
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'m'
block|,
operator|&
name|m_optname
block|,
name|TRIPLE
block|,
name|OPT_OFF
block|,
operator|&
name|pr_type
block|,
name|NULL
block|,
literal|"Short prompt"
block|,
literal|"Medium prompt"
block|,
literal|"Long prompt"
block|}
block|,
block|{
literal|'n'
block|,
operator|&
name|n_optname
block|,
name|TRIPLE
operator||
name|REPAINT
block|,
name|OPT_ON
block|,
operator|&
name|linenums
block|,
name|NULL
block|,
literal|"Don't use line numbers"
block|,
literal|"Use line numbers"
block|,
literal|"Constantly display line numbers"
block|}
block|,
if|#
directive|if
name|LOGFILE
block|{
literal|'o'
block|,
operator|&
name|o_optname
block|,
name|STRING
block|,
literal|0
block|,
name|NULL
block|,
name|opt_o
block|,
literal|"log file: "
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'O'
block|,
operator|&
name|O__optname
block|,
name|STRING
block|,
literal|0
block|,
name|NULL
block|,
name|opt__O
block|,
literal|"Log file: "
block|,
name|NULL
block|,
name|NULL
block|}
block|,
endif|#
directive|endif
block|{
literal|'p'
block|,
operator|&
name|p_optname
block|,
name|STRING
operator||
name|NO_TOGGLE
operator||
name|NO_QUERY
block|,
literal|0
block|,
name|NULL
block|,
name|opt_p
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'P'
block|,
operator|&
name|P__optname
block|,
name|STRING
block|,
literal|0
block|,
name|NULL
block|,
name|opt__P
block|,
literal|"prompt: "
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'q'
block|,
operator|&
name|q_optname
block|,
name|TRIPLE
block|,
name|OPT_OFF
block|,
operator|&
name|quiet
block|,
name|NULL
block|,
literal|"Ring the bell for errors AND at eof/bof"
block|,
literal|"Ring the bell for errors but not at eof/bof"
block|,
literal|"Never ring the bell"
block|}
block|,
block|{
literal|'r'
block|,
operator|&
name|r_optname
block|,
name|TRIPLE
operator||
name|REPAINT
block|,
name|OPT_OFF
block|,
operator|&
name|ctldisp
block|,
name|NULL
block|,
literal|"Display control characters as ^X"
block|,
literal|"Display control characters directly"
block|,
literal|"Display control characters directly, processing ANSI sequences"
block|}
block|,
block|{
literal|'s'
block|,
operator|&
name|s_optname
block|,
name|BOOL
operator||
name|REPAINT
block|,
name|OPT_OFF
block|,
operator|&
name|squeeze
block|,
name|NULL
block|,
literal|"Display all blank lines"
block|,
literal|"Squeeze multiple blank lines"
block|,
name|NULL
block|}
block|,
block|{
literal|'S'
block|,
operator|&
name|S__optname
block|,
name|BOOL
operator||
name|REPAINT
block|,
name|OPT_OFF
block|,
operator|&
name|chopline
block|,
name|NULL
block|,
literal|"Fold long lines"
block|,
literal|"Chop long lines"
block|,
name|NULL
block|}
block|,
if|#
directive|if
name|TAGS
block|{
literal|'t'
block|,
operator|&
name|t_optname
block|,
name|STRING
operator||
name|NO_QUERY
block|,
literal|0
block|,
name|NULL
block|,
name|opt_t
block|,
literal|"tag: "
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'T'
block|,
operator|&
name|T__optname
block|,
name|STRING
block|,
literal|0
block|,
name|NULL
block|,
name|opt__T
block|,
literal|"tags file: "
block|,
name|NULL
block|,
name|NULL
block|}
block|,
endif|#
directive|endif
block|{
literal|'u'
block|,
operator|&
name|u_optname
block|,
name|TRIPLE
operator||
name|REPAINT
block|,
name|OPT_OFF
block|,
operator|&
name|bs_mode
block|,
name|NULL
block|,
literal|"Display underlined text in underline mode"
block|,
literal|"Backspaces cause overstrike"
block|,
literal|"Print backspace as ^H"
block|}
block|,
block|{
literal|'V'
block|,
operator|&
name|V__optname
block|,
name|NOVAR
block|,
literal|0
block|,
name|NULL
block|,
name|opt__V
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'w'
block|,
operator|&
name|w_optname
block|,
name|TRIPLE
operator||
name|REPAINT
block|,
name|OPT_OFF
block|,
operator|&
name|show_attn
block|,
name|NULL
block|,
literal|"Don't highlight first unread line"
block|,
literal|"Highlight first unread line after forward-screen"
block|,
literal|"Highlight first unread line after any forward movement"
block|, 	}
block|,
block|{
literal|'x'
block|,
operator|&
name|x_optname
block|,
name|NUMBER
operator||
name|REPAINT
block|,
literal|8
block|,
operator|&
name|tabstop
block|,
name|NULL
block|,
literal|"Tab stops: "
block|,
literal|"Tab stops every %d spaces"
block|,
name|NULL
block|}
block|,
block|{
literal|'X'
block|,
operator|&
name|X__optname
block|,
name|BOOL
operator||
name|NO_TOGGLE
block|,
name|OPT_OFF
block|,
operator|&
name|no_init
block|,
name|NULL
block|,
literal|"Send init/deinit strings to terminal"
block|,
literal|"Don't use init/deinit strings"
block|,
name|NULL
block|}
block|,
block|{
literal|'y'
block|,
operator|&
name|y_optname
block|,
name|NUMBER
block|,
operator|-
literal|1
block|,
operator|&
name|forw_scroll
block|,
name|NULL
block|,
literal|"Forward scroll limit: "
block|,
literal|"Forward scroll limit is %d lines"
block|,
name|NULL
block|}
block|,
block|{
literal|'z'
block|,
operator|&
name|z_optname
block|,
name|NUMBER
block|,
operator|-
literal|1
block|,
operator|&
name|swindow
block|,
name|NULL
block|,
literal|"Scroll window size: "
block|,
literal|"Scroll window size is %d lines"
block|,
name|NULL
block|}
block|,
block|{
literal|'"'
block|,
operator|&
name|quote_optname
block|,
name|STRING
block|,
literal|0
block|,
name|NULL
block|,
name|opt_quote
block|,
literal|"quotes: "
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'~'
block|,
operator|&
name|tilde_optname
block|,
name|BOOL
operator||
name|REPAINT
block|,
name|OPT_ON
block|,
operator|&
name|twiddle
block|,
name|NULL
block|,
literal|"Don't show tildes after end of file"
block|,
literal|"Show tildes after end of file"
block|,
name|NULL
block|}
block|,
block|{
literal|'?'
block|,
operator|&
name|query_optname
block|,
name|NOVAR
block|,
literal|0
block|,
name|NULL
block|,
name|opt_query
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|'#'
block|,
operator|&
name|pound_optname
block|,
name|NUMBER
block|,
literal|0
block|,
operator|&
name|shift_count
block|,
name|NULL
block|,
literal|"Horizontal shift: "
block|,
literal|"Horizontal shift %d positions"
block|,
name|NULL
block|}
block|,
block|{
literal|'\0'
block|,
name|NULL
block|,
name|NOVAR
block|,
literal|0
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Initialize each option to its default value.  */
end_comment

begin_function
name|public
name|void
name|init_option
parameter_list|()
block|{
specifier|register
name|struct
name|option
modifier|*
name|o
decl_stmt|;
for|for
control|(
name|o
operator|=
name|option
init|;
name|o
operator|->
name|oletter
operator|!=
literal|'\0'
condition|;
name|o
operator|++
control|)
block|{
comment|/* 		 * Set each variable to its default. 		 */
if|if
condition|(
name|o
operator|->
name|ovar
operator|!=
name|NULL
condition|)
operator|*
operator|(
name|o
operator|->
name|ovar
operator|)
operator|=
name|o
operator|->
name|odefault
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Find an option in the option table, given its option letter.  */
end_comment

begin_function
name|public
name|struct
name|option
modifier|*
name|findopt
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
specifier|register
name|struct
name|option
modifier|*
name|o
decl_stmt|;
for|for
control|(
name|o
operator|=
name|option
init|;
name|o
operator|->
name|oletter
operator|!=
literal|'\0'
condition|;
name|o
operator|++
control|)
block|{
if|if
condition|(
name|o
operator|->
name|oletter
operator|==
name|c
condition|)
return|return
operator|(
name|o
operator|)
return|;
if|if
condition|(
operator|(
name|o
operator|->
name|otype
operator|&
name|TRIPLE
operator|)
operator|&&
name|toupper
argument_list|(
name|o
operator|->
name|oletter
argument_list|)
operator|==
name|c
condition|)
return|return
operator|(
name|o
operator|)
return|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Find an option in the option table, given its option name.  * p_optname is the (possibly partial) name to look for, and  * is updated to point after the matched name.  * p_oname if non-NULL is set to point to the full option name.  */
end_comment

begin_function
name|public
name|struct
name|option
modifier|*
name|findopt_name
parameter_list|(
name|p_optname
parameter_list|,
name|p_oname
parameter_list|,
name|p_err
parameter_list|)
name|char
modifier|*
modifier|*
name|p_optname
decl_stmt|;
name|char
modifier|*
modifier|*
name|p_oname
decl_stmt|;
name|int
modifier|*
name|p_err
decl_stmt|;
block|{
name|char
modifier|*
name|optname
init|=
operator|*
name|p_optname
decl_stmt|;
specifier|register
name|struct
name|option
modifier|*
name|o
decl_stmt|;
specifier|register
name|struct
name|optname
modifier|*
name|oname
decl_stmt|;
specifier|register
name|int
name|len
decl_stmt|;
name|int
name|uppercase
decl_stmt|;
name|struct
name|option
modifier|*
name|maxo
init|=
name|NULL
decl_stmt|;
name|struct
name|optname
modifier|*
name|maxoname
init|=
name|NULL
decl_stmt|;
name|int
name|maxlen
init|=
literal|0
decl_stmt|;
name|int
name|ambig
init|=
literal|0
decl_stmt|;
name|int
name|exact
init|=
literal|0
decl_stmt|;
comment|/* 	 * Check all options. 	 */
for|for
control|(
name|o
operator|=
name|option
init|;
name|o
operator|->
name|oletter
operator|!=
literal|'\0'
condition|;
name|o
operator|++
control|)
block|{
comment|/* 		 * Check all names for this option. 		 */
for|for
control|(
name|oname
operator|=
name|o
operator|->
name|onames
init|;
name|oname
operator|!=
name|NULL
condition|;
name|oname
operator|=
name|oname
operator|->
name|onext
control|)
block|{
comment|/*  			 * Try normal match first (uppercase == 0), 			 * then, then if it's a TRIPLE option, 			 * try uppercase match (uppercase == 1). 			 */
for|for
control|(
name|uppercase
operator|=
literal|0
init|;
name|uppercase
operator|<=
literal|1
condition|;
name|uppercase
operator|++
control|)
block|{
name|len
operator|=
name|sprefix
argument_list|(
name|optname
argument_list|,
name|oname
operator|->
name|oname
argument_list|,
name|uppercase
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|exact
operator|&&
name|len
operator|==
name|maxlen
condition|)
comment|/* 					 * Already had a partial match, 					 * and now there's another one that 					 * matches the same length. 					 */
name|ambig
operator|=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|len
operator|>
name|maxlen
condition|)
block|{
comment|/* 					 * Found a better match than 					 * the one we had. 					 */
name|maxo
operator|=
name|o
expr_stmt|;
name|maxoname
operator|=
name|oname
expr_stmt|;
name|maxlen
operator|=
name|len
expr_stmt|;
name|ambig
operator|=
literal|0
expr_stmt|;
name|exact
operator|=
operator|(
name|len
operator|==
name|strlen
argument_list|(
name|oname
operator|->
name|oname
argument_list|)
operator|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
operator|(
name|o
operator|->
name|otype
operator|&
name|TRIPLE
operator|)
condition|)
break|break;
block|}
block|}
block|}
if|if
condition|(
name|ambig
condition|)
block|{
comment|/* 		 * Name matched more than one option. 		 */
if|if
condition|(
name|p_err
operator|!=
name|NULL
condition|)
operator|*
name|p_err
operator|=
name|OPT_AMBIG
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
operator|*
name|p_optname
operator|=
name|optname
operator|+
name|maxlen
expr_stmt|;
if|if
condition|(
name|p_oname
operator|!=
name|NULL
condition|)
operator|*
name|p_oname
operator|=
name|maxoname
operator|->
name|oname
expr_stmt|;
return|return
operator|(
name|maxo
operator|)
return|;
block|}
end_function

end_unit

