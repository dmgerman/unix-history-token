begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)screen.h	8.92 (Berkeley) 3/23/94  */
end_comment

begin_comment
comment|/*  * There are minimum values that vi has to have to display a screen.  The  * row minimum is fixed at 1 line for the text, and 1 line for any error  * messages.  The column calculation is a lot trickier.  For example, you  * have to have enough columns to display the line number, not to mention  * guaranteeing that tabstop and shiftwidth values are smaller than the  * current column value.  It's a lot simpler to have a fixed value and not  * worry about it.  *  * XXX  * MINIMUM_SCREEN_COLS is probably wrong.  */
end_comment

begin_define
define|#
directive|define
name|MINIMUM_SCREEN_ROWS
value|2
end_define

begin_define
define|#
directive|define
name|MINIMUM_SCREEN_COLS
value|20
end_define

begin_comment
comment|/* Line operations. */
end_comment

begin_enum
enum|enum
name|operation
block|{
name|LINE_APPEND
block|,
name|LINE_DELETE
block|,
name|LINE_INSERT
block|,
name|LINE_RESET
block|}
enum|;
end_enum

begin_comment
comment|/* Position values. */
end_comment

begin_enum
enum|enum
name|position
block|{
name|P_BOTTOM
block|,
name|P_FILL
block|,
name|P_MIDDLE
block|,
name|P_TOP
block|}
enum|;
end_enum

begin_comment
comment|/* Screen adjustment operations. */
end_comment

begin_enum
enum|enum
name|adjust
block|{
name|A_DECREASE
block|,
name|A_INCREASE
block|,
name|A_SET
block|}
enum|;
end_enum

begin_comment
comment|/*  * Structure for holding file references.  Each SCR structure contains a  * linked list of these (the user's argument list) as well as pointers to  * the current and previous files.  The structure contains the name of the  * file, along with the information that follows the name.  A file has up  * to three "names".  The tname field is the path of the temporary backing  * file, if any.  The name field is the name the user originally used to  * specify the file to be edited.  The cname field is the changed name if  * the user changed the name.  *  * Note that the read-only bit follows the file name, not the file itself.  *  * XXX  * The mtime field should be a struct timespec, but time_t is more portable.  */
end_comment

begin_struct
struct|struct
name|_fref
block|{
name|CIRCLEQ_ENTRY
argument_list|(
argument|_fref
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of file references. */
name|char
modifier|*
name|cname
decl_stmt|;
comment|/* Changed file name. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* File name. */
name|char
modifier|*
name|tname
decl_stmt|;
comment|/* Temporary file name. */
name|recno_t
name|lno
decl_stmt|;
comment|/* 1-N: file cursor line. */
name|size_t
name|cno
decl_stmt|;
comment|/* 0-N: file cursor column. */
name|time_t
name|mtime
decl_stmt|;
comment|/* Last modification time. */
define|#
directive|define
name|FR_CHANGEWRITE
value|0x001
comment|/* Name changed and then written. */
define|#
directive|define
name|FR_CURSORSET
value|0x002
comment|/* If lno/cno valid. */
define|#
directive|define
name|FR_EDITED
value|0x004
comment|/* If the file was ever edited. */
define|#
directive|define
name|FR_IGNORE
value|0x008
comment|/* File isn't part of argument list. */
define|#
directive|define
name|FR_NEWFILE
value|0x010
comment|/* File doesn't really exist yet. */
define|#
directive|define
name|FR_RDONLY
value|0x020
comment|/* File is read-only. */
name|u_int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * There's a file name hierarchy -- if the user has changed the name, we  * use it, otherwise, we use the original name, if there was one, othewise  * use the temporary name.  */
end_comment

begin_define
define|#
directive|define
name|FILENAME
parameter_list|(
name|frp
parameter_list|)
define|\
value|((frp)->cname != NULL) ? (frp)->cname :				\ 	((frp)->name != NULL) ? (frp)->name : (frp)->tname
end_define

begin_comment
comment|/*  * SCR --  *	The screen structure.  To the extent possible, all screen information  *	is stored in the various private areas.  The only information here  *	is used by global routines or is shared by too many screens.  */
end_comment

begin_struct
struct|struct
name|_scr
block|{
comment|/* INITIALIZED AT SCREEN CREATE. */
name|CIRCLEQ_ENTRY
argument_list|(
argument|_scr
argument_list|)
name|q
expr_stmt|;
comment|/* Screens. */
name|GS
modifier|*
name|gp
decl_stmt|;
comment|/* Pointer to global area. */
name|SCR
modifier|*
name|nextdisp
decl_stmt|;
comment|/* Next display screen. */
name|EXF
modifier|*
name|ep
decl_stmt|;
comment|/* Screen's current EXF structure. */
name|MSGH
name|msgq
decl_stmt|;
comment|/* Message list. */
comment|/* FREF list. */
name|CIRCLEQ_HEAD
argument_list|(
argument|_frefh
argument_list|,
argument|_fref
argument_list|)
name|frefq
expr_stmt|;
name|FREF
modifier|*
name|frp
decl_stmt|;
comment|/* FREF being edited. */
name|FREF
modifier|*
name|a_frp
decl_stmt|;
comment|/* Last argument list FREF edited. */
name|FREF
modifier|*
name|p_frp
decl_stmt|;
comment|/* Last FREF edited. */
name|u_long
name|ccnt
decl_stmt|;
comment|/* Command count. */
name|u_long
name|q_ccnt
decl_stmt|;
comment|/* Quit or ZZ command count. */
comment|/* Screen's: */
name|size_t
name|rows
decl_stmt|;
comment|/* 1-N: number of rows. */
name|size_t
name|cols
decl_stmt|;
comment|/* 1-N: number of columns. */
name|size_t
name|woff
decl_stmt|;
comment|/* 0-N: row offset in screen. */
name|size_t
name|t_rows
decl_stmt|;
comment|/* 1-N: cur number of text rows. */
name|size_t
name|t_maxrows
decl_stmt|;
comment|/* 1-N: max number of text rows. */
name|size_t
name|t_minrows
decl_stmt|;
comment|/* 1-N: min number of text rows. */
comment|/* Cursor's: */
name|recno_t
name|lno
decl_stmt|;
comment|/* 1-N: file line. */
name|size_t
name|cno
decl_stmt|;
comment|/* 0-N: file character in line. */
name|size_t
name|rcm
decl_stmt|;
comment|/* Vi: 0-N: Column suck. */
define|#
directive|define
name|RCM_FNB
value|0x01
comment|/* Column suck: first non-blank. */
define|#
directive|define
name|RCM_LAST
value|0x02
comment|/* Column suck: last. */
name|u_int
name|rcmflags
decl_stmt|;
define|#
directive|define
name|L_ADDED
value|0
comment|/* Added lines. */
define|#
directive|define
name|L_CHANGED
value|1
comment|/* Changed lines. */
define|#
directive|define
name|L_COPIED
value|2
comment|/* Copied lines. */
define|#
directive|define
name|L_DELETED
value|3
comment|/* Deleted lines. */
define|#
directive|define
name|L_JOINED
value|4
comment|/* Joined lines. */
define|#
directive|define
name|L_MOVED
value|5
comment|/* Moved lines. */
define|#
directive|define
name|L_PUT
value|6
comment|/* Put lines. */
define|#
directive|define
name|L_LSHIFT
value|7
comment|/* Left shift lines. */
define|#
directive|define
name|L_RSHIFT
value|8
comment|/* Right shift lines. */
define|#
directive|define
name|L_YANKED
value|9
comment|/* Yanked lines. */
name|recno_t
name|rptlines
index|[
name|L_YANKED
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Ex/vi: lines changed by last op. */
name|FILE
modifier|*
name|stdfp
decl_stmt|;
comment|/* Ex output file pointer. */
name|char
modifier|*
name|if_name
decl_stmt|;
comment|/* Ex input file name, for messages. */
name|recno_t
name|if_lno
decl_stmt|;
comment|/* Ex input file line, for messages. */
name|fd_set
name|rdfd
decl_stmt|;
comment|/* Ex/vi: read fd select mask. */
name|TEXTH
name|tiq
decl_stmt|;
comment|/* Ex/vi: text input queue. */
name|SCRIPT
modifier|*
name|script
decl_stmt|;
comment|/* Vi: script mode information .*/
name|struct
name|timeval
name|busy_tod
decl_stmt|;
comment|/* ITIMER_REAL: busy time-of-day. */
name|char
specifier|const
modifier|*
name|busy_msg
decl_stmt|;
comment|/* ITIMER_REAL: busy message. */
name|struct
name|sigaction
name|intr_act
decl_stmt|;
comment|/* Interrupt saved signal state. */
name|struct
name|termios
name|intr_term
decl_stmt|;
comment|/* Interrupt saved terminal state. */
name|int
name|intr_level
decl_stmt|;
comment|/* 0-N: Interrupt level. */
name|void
modifier|*
name|vi_private
decl_stmt|;
comment|/* Vi private area. */
name|void
modifier|*
name|ex_private
decl_stmt|;
comment|/* Ex private area. */
name|void
modifier|*
name|svi_private
decl_stmt|;
comment|/* Vi curses screen private area. */
name|void
modifier|*
name|xaw_private
decl_stmt|;
comment|/* Vi XAW screen private area. */
comment|/* PARTIALLY OR COMPLETELY COPIED FROM PREVIOUS SCREEN. */
name|char
modifier|*
name|alt_name
decl_stmt|;
comment|/* Ex/vi: alternate file name. */
comment|/* Ex/vi: search/substitute info. */
name|regex_t
name|sre
decl_stmt|;
comment|/* Last search RE. */
name|regex_t
name|subre
decl_stmt|;
comment|/* Last substitute RE. */
name|enum
name|direction
name|searchdir
decl_stmt|;
comment|/* File search direction. */
name|regmatch_t
modifier|*
name|match
decl_stmt|;
comment|/* Substitute match array. */
name|size_t
name|matchsize
decl_stmt|;
comment|/* Substitute match array size. */
name|char
modifier|*
name|repl
decl_stmt|;
comment|/* Substitute replacement. */
name|size_t
name|repl_len
decl_stmt|;
comment|/* Substitute replacement length.*/
name|size_t
modifier|*
name|newl
decl_stmt|;
comment|/* Newline offset array. */
name|size_t
name|newl_len
decl_stmt|;
comment|/* Newline array size. */
name|size_t
name|newl_cnt
decl_stmt|;
comment|/* Newlines in replacement. */
name|u_int
name|saved_vi_mode
decl_stmt|;
comment|/* Saved vi display type. */
name|OPTION
name|opts
index|[
name|O_OPTIONCOUNT
index|]
decl_stmt|;
comment|/* Options. */
comment|/*  * SCREEN SUPPORT ROUTINES.  *  * A SCR * MUST be the first argument to these routines.  */
comment|/* Ring the screen bell. */
name|void
argument_list|(
argument|*s_bell
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Background the screen. */
name|int
argument_list|(
argument|*s_bg
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Put up a busy message. */
name|int
argument_list|(
argument|*s_busy
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Change a screen line. */
name|int
argument_list|(
argument|*s_change
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|recno_t
operator|,
expr|enum
name|operation
operator|)
argument_list|)
expr_stmt|;
comment|/* Clear the screen. */
name|int
argument_list|(
argument|*s_clear
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Return column close to specified. */
name|size_t
argument_list|(
argument|*s_colpos
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|recno_t
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Return the logical cursor column. */
name|int
argument_list|(
argument|*s_column
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
expr_stmt|;
name|enum
name|confirm
comment|/* Confirm an action with the user. */
argument_list|(
operator|*
name|s_confirm
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|MARK
operator|*
operator|,
name|MARK
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Change the relative screen size. */
name|int
argument_list|(
argument|*s_crel
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|long
operator|)
argument_list|)
expr_stmt|;
comment|/* Move down the screen. */
name|int
argument_list|(
argument|*s_down
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|MARK
operator|*
operator|,
name|recno_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Edit a file. */
name|int
argument_list|(
argument|*s_edit
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* End a screen. */
name|int
argument_list|(
argument|*s_end
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Run a single ex command. */
name|int
argument_list|(
argument|*s_ex_cmd
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|EXCMDARG
operator|*
operator|,
name|MARK
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Run user's ex commands. */
name|int
argument_list|(
argument|*s_ex_run
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|MARK
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Screen's ex write function. */
name|int
argument_list|(
argument|*s_ex_write
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Foreground the screen. */
name|int
argument_list|(
argument|*s_fg
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|CHAR_T
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Fill the screen's map. */
name|int
argument_list|(
argument|*s_fill
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|recno_t
operator|,
expr|enum
name|position
operator|)
argument_list|)
expr_stmt|;
name|enum
name|input
comment|/* Get a line from the user. */
argument_list|(
operator|*
name|s_get
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|TEXTH
operator|*
operator|,
name|int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
name|enum
name|input
comment|/* Get a key from the user. */
argument_list|(
operator|*
name|s_key_read
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|*
operator|,
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Tell the screen an option changed. */
name|int
argument_list|(
argument|*s_optchange
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Return column at screen position. */
name|int
argument_list|(
argument|*s_position
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|MARK
operator|*
operator|,
name|u_long
operator|,
expr|enum
name|position
operator|)
argument_list|)
expr_stmt|;
comment|/* Change the absolute screen size. */
name|int
argument_list|(
argument|*s_rabs
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|long
operator|,
expr|enum
name|adjust
operator|)
argument_list|)
expr_stmt|;
comment|/* Return column close to selection. */
name|size_t
argument_list|(
argument|*s_rcm
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|recno_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Refresh the screen. */
name|int
argument_list|(
argument|*s_refresh
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Split the screen. */
name|int
argument_list|(
argument|*s_split
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|ARGS
operator|*
index|[]
operator|)
argument_list|)
expr_stmt|;
comment|/* Suspend the screen. */
name|int
argument_list|(
argument|*s_suspend
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Move up the screen. */
name|int
argument_list|(
argument|*s_up
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|MARK
operator|*
operator|,
name|recno_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Editor screens. */
define|#
directive|define
name|S_EX
value|0x0000001
comment|/* Ex screen. */
define|#
directive|define
name|S_VI_CURSES
value|0x0000002
comment|/* Vi: curses screen. */
define|#
directive|define
name|S_VI_XAW
value|0x0000004
comment|/* Vi: Athena widgets screen. */
define|#
directive|define
name|IN_EX_MODE
parameter_list|(
name|sp
parameter_list|)
comment|/* If in ex mode. */
define|\
value|(F_ISSET(sp, S_EX))
define|#
directive|define
name|IN_VI_MODE
parameter_list|(
name|sp
parameter_list|)
comment|/* If in vi mode. */
define|\
value|(F_ISSET(sp, S_VI_CURSES | S_VI_XAW))
define|#
directive|define
name|S_SCREENS
comment|/* Screens. */
define|\
value|(S_EX | S_VI_CURSES | S_VI_XAW)
comment|/* Major screen/file changes. */
define|#
directive|define
name|S_EXIT
value|0x0000008
comment|/* Exiting (not forced). */
define|#
directive|define
name|S_EXIT_FORCE
value|0x0000010
comment|/* Exiting (forced). */
define|#
directive|define
name|S_FSWITCH
value|0x0000020
comment|/* Switch files. */
define|#
directive|define
name|S_SSWITCH
value|0x0000040
comment|/* Switch screens. */
define|#
directive|define
name|S_MAJOR_CHANGE
comment|/* Screen or file changes. */
define|\
value|(S_EXIT | S_EXIT_FORCE | S_FSWITCH | S_SSWITCH)
define|#
directive|define
name|S_BELLSCHED
value|0x0000080
comment|/* Bell scheduled. */
define|#
directive|define
name|S_CONTINUE
value|0x0000100
comment|/* Need to ask the user to continue. */
define|#
directive|define
name|S_EXSILENT
value|0x0000200
comment|/* Ex batch script. */
define|#
directive|define
name|S_GLOBAL
value|0x0000400
comment|/* Doing a global command. */
define|#
directive|define
name|S_INPUT
value|0x0000800
comment|/* Doing text input. */
define|#
directive|define
name|S_INTERRUPTED
value|0x0001000
comment|/* If have been interrupted. */
define|#
directive|define
name|S_INTERRUPTIBLE
value|0x0002000
comment|/* If can be interrupted. */
define|#
directive|define
name|S_REDRAW
value|0x0004000
comment|/* Redraw the screen. */
define|#
directive|define
name|S_REFORMAT
value|0x0008000
comment|/* Reformat the screen. */
define|#
directive|define
name|S_REFRESH
value|0x0010000
comment|/* Refresh the screen. */
define|#
directive|define
name|S_RENUMBER
value|0x0020000
comment|/* Renumber the screen. */
define|#
directive|define
name|S_RESIZE
value|0x0040000
comment|/* Resize the screen. */
define|#
directive|define
name|S_SCRIPT
value|0x0080000
comment|/* Window is a shell script. */
define|#
directive|define
name|S_SRE_SET
value|0x0100000
comment|/* The search RE has been set. */
define|#
directive|define
name|S_SUBRE_SET
value|0x0200000
comment|/* The substitute RE has been set. */
define|#
directive|define
name|S_UPDATE_MODE
value|0x0400000
comment|/* Don't repaint modeline. */
define|#
directive|define
name|S_VLITONLY
value|0x0800000
comment|/* ^V literal next only. */
name|u_int32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Timers have no structure, so routines are here. */
end_comment

begin_decl_stmt
name|void
name|h_alrm
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|busy_on
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|busy_off
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rcv_on
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interrupts have no structure, so routines are here. */
end_comment

begin_decl_stmt
name|void
name|intr_end
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|intr_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generic routines to start/stop a screen. */
end_comment

begin_decl_stmt
name|int
name|screen_end
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|screen_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|SCR
operator|*
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Public interfaces to the underlying screens. */
end_comment

begin_decl_stmt
name|int
name|ex_screen_copy
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ex_screen_end
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ex_screen_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sex_screen_copy
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sex_screen_end
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sex_screen_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_screen_copy
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_screen_end
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_screen_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|v_screen_copy
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|v_screen_end
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|v_screen_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xaw_screen_copy
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xaw_screen_end
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xaw_screen_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

