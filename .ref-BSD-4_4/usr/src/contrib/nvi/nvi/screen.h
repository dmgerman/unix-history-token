begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)screen.h	8.1 (Berkeley) 6/9/93  */
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

begin_enum
enum|enum
name|confirmation
block|{
name|YES
block|,
name|NO
block|,
name|QUIT
block|}
enum|;
end_enum

begin_comment
comment|/* Confirmation routine interface. */
end_comment

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
comment|/* Standard continue message. */
end_comment

begin_define
define|#
directive|define
name|CONTMSG
value|"Enter return to continue: "
end_define

begin_comment
comment|/*  * Structure for building argc/argv vector of ex arguments.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_args
block|{
name|char
modifier|*
name|bp
decl_stmt|;
comment|/* Buffer. */
name|size_t
name|len
decl_stmt|;
comment|/* Buffer length. */
define|#
directive|define
name|A_ALLOCATED
value|0x01
comment|/* If allocated space. */
name|u_char
name|flags
decl_stmt|;
block|}
name|ARGS
typedef|;
end_typedef

begin_comment
comment|/*  * Structure for mapping lines to the screen.  An SMAP is an array of  * structures, one per screen line, holding a physical line and screen  * offset into the line.  For example, the pair 2:1 would be the first  * screen of line 2, and 2:2 would be the second.  If doing left-right  * scrolling, all of the offsets will be the same, i.e. for the second  * screen, 1:2, 2:2, 3:2, etc.  If doing the standard, but unbelievably  * stupid, vi scrolling, it will be staggered, i.e. 1:1, 1:2, 1:3, 2:1,  * 3:1, etc.  *  * The SMAP is always as large as the physical screen, so that when split  * screens close, there is room to add in the newly available lines.  */
end_comment

begin_comment
comment|/* Map positions. */
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

begin_typedef
typedef|typedef
struct|struct
name|_smap
block|{
name|recno_t
name|lno
decl_stmt|;
comment|/* 1-N: Physical file line number. */
name|size_t
name|off
decl_stmt|;
comment|/* 1-N: Screen offset in the line. */
block|}
name|SMAP
typedef|;
end_typedef

begin_comment
comment|/*  * scr --  *	The screen structure.  Most of the traditional ex/vi options and  *	values follow the screen, and therefore are kept here.  For those  *	of you that didn't follow that sentence, read "dumping ground".  *	For example, things like tags and mapped character sequences are  *	stored here.  Each new screen that is added to the editor will  *	almost certainly have to keep its own stuff in here as well.  */
end_comment

begin_struct_decl
struct_decl|struct
name|_exf
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|_scr
block|{
comment|/* INITIALIZED AT SCREEN CREATE. */
name|struct
name|_scr
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
comment|/* Linked list of screens. */
comment|/* Underlying file information. */
name|struct
name|_exf
modifier|*
name|ep
decl_stmt|;
comment|/* Screen's current file. */
name|struct
name|_exf
modifier|*
name|enext
decl_stmt|;
comment|/* Next file to edit. */
name|struct
name|_exf
modifier|*
name|eprev
decl_stmt|;
comment|/* Last file edited. */
comment|/* Split screen information. */
name|struct
name|_scr
modifier|*
name|child
decl_stmt|;
comment|/* Child screen. */
name|struct
name|_scr
modifier|*
name|parent
decl_stmt|;
comment|/* Parent screen. */
name|struct
name|_scr
modifier|*
name|snext
decl_stmt|;
comment|/* Next screen to display. */
comment|/* Physical screen information. */
name|struct
name|_smap
modifier|*
name|h_smap
decl_stmt|;
comment|/* First entry in screen/row map. */
name|struct
name|_smap
modifier|*
name|t_smap
decl_stmt|;
comment|/*  Last entry in screen/row map. */
name|recno_t
name|lno
decl_stmt|;
comment|/* 1-N:     cursor file line. */
name|recno_t
name|olno
decl_stmt|;
comment|/* 1-N: old cursor file line. */
name|size_t
name|cno
decl_stmt|;
comment|/* 0-N:     file cursor column. */
name|size_t
name|ocno
decl_stmt|;
comment|/* 0-N: old file cursor column. */
name|size_t
name|sc_row
decl_stmt|;
comment|/* 0-N: logical screen cursor row. */
name|size_t
name|sc_col
decl_stmt|;
comment|/* 0-N: logical screen cursor column. */
name|size_t
name|rows
decl_stmt|;
comment|/* 1-N:      rows per screen. */
name|size_t
name|cols
decl_stmt|;
comment|/* 1-N:   columns per screen. */
name|size_t
name|t_rows
decl_stmt|;
comment|/* 1-N: text rows per screen. */
name|size_t
name|w_rows
decl_stmt|;
comment|/* 1-N:      rows per window. */
name|size_t
name|s_off
decl_stmt|;
comment|/* 0-N: row offset in window. */
name|struct
name|_msg
modifier|*
name|msgp
decl_stmt|;
comment|/* User message list. */
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
name|L_READ
value|7
comment|/* Read lines. */
define|#
directive|define
name|L_LSHIFT
value|8
comment|/* Read lines. */
define|#
directive|define
name|L_RSHIFT
value|9
comment|/* Read lines. */
define|#
directive|define
name|L_YANKED
value|10
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
name|struct
name|_args
modifier|*
name|args
decl_stmt|;
comment|/* Ex/vi: argument buffers. */
name|int
name|argscnt
decl_stmt|;
comment|/* Argument count. */
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* Arguments. */
comment|/* Ex/vi: interface between ex/vi. */
name|FILE
modifier|*
name|stdfp
decl_stmt|;
comment|/* Ex output file pointer. */
name|size_t
name|exlinecount
decl_stmt|;
comment|/* Ex/vi overwrite count. */
name|size_t
name|extotalcount
decl_stmt|;
comment|/* Ex/vi overwrite count. */
name|size_t
name|exlcontinue
decl_stmt|;
comment|/* Ex/vi line continue value. */
comment|/* FWOPEN_NOT_AVAILABLE */
name|int
name|trapped_fd
decl_stmt|;
comment|/* Ex/vi trapped file descriptor. */
name|u_int
name|nkeybuf
decl_stmt|;
comment|/* # of keys in the input buffer. */
name|char
modifier|*
name|mappedkey
decl_stmt|;
comment|/* Mapped key return. */
name|u_int
name|nextkey
decl_stmt|;
comment|/* Index of next key in keybuf. */
name|char
name|keybuf
index|[
literal|256
index|]
decl_stmt|;
comment|/* Key buffer. */
name|fd_set
name|rdfd
decl_stmt|;
comment|/* Ex/vi: read fd select mask. */
name|struct
name|_hdr
name|bhdr
decl_stmt|;
comment|/* Ex/vi: line input. */
name|struct
name|_hdr
name|txthdr
decl_stmt|;
comment|/* Vi: text input TEXT header. */
name|char
modifier|*
name|ibp
decl_stmt|;
comment|/* Ex: line input buffer. */
name|size_t
name|ibp_len
decl_stmt|;
comment|/* Line input buffer length. */
name|struct
name|_excmdlist
modifier|*
name|lastcmd
decl_stmt|;
comment|/* Ex: last command. */
comment|/* PARTIALLY OR COMPLETELY COPIED FROM PREVIOUS SCREEN. */
name|struct
name|_gs
modifier|*
name|gp
decl_stmt|;
comment|/* Pointer to global area. */
name|char
modifier|*
name|rep
decl_stmt|;
comment|/* Vi: input replay buffer. */
name|size_t
name|rep_len
decl_stmt|;
comment|/* Vi: input replay buffer length. */
name|char
modifier|*
name|VB
decl_stmt|;
comment|/* Visual bell termcap string. */
name|char
modifier|*
name|lastbcomm
decl_stmt|;
comment|/* Ex/vi: last bang command. */
name|char
modifier|*
name|altfname
decl_stmt|;
comment|/* Ex/vi: alternate file name. */
name|u_char
name|inc_lastch
decl_stmt|;
comment|/* Vi: Last increment character. */
name|long
name|inc_lastval
decl_stmt|;
comment|/* Vi: Last increment value. */
name|struct
name|_cb
name|cuts
index|[
name|UCHAR_MAX
operator|+
literal|2
index|]
decl_stmt|;
comment|/* Ex/vi: cut buffers. */
name|char
modifier|*
name|paragraph
decl_stmt|;
comment|/* Vi: Paragraph search list. */
name|struct
name|_hdr
name|taghdr
decl_stmt|;
comment|/* Ex/vi: tag stack. */
name|struct
name|_tagf
modifier|*
modifier|*
name|tfhead
decl_stmt|;
comment|/* List of tag files. */
name|char
modifier|*
name|tlast
decl_stmt|;
comment|/* Saved last tag. */
comment|/* Ex/vi: search/substitute info. */
name|enum
name|direction
name|searchdir
decl_stmt|;
comment|/* File search direction. */
name|regex_t
name|sre
decl_stmt|;
comment|/* Last search RE. */
name|enum
name|cdirection
name|csearchdir
decl_stmt|;
comment|/* Character search direction. */
name|u_char
name|lastckey
decl_stmt|;
comment|/* Last search character. */
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
name|struct
name|_chname
modifier|*
name|cname
decl_stmt|;
comment|/* Display names of characters. */
name|u_char
name|special
index|[
name|UCHAR_MAX
index|]
decl_stmt|;
comment|/* Special character array. */
comment|/* Ex/vi: mapped chars, abbrevs. */
name|struct
name|_hdr
name|seqhdr
decl_stmt|;
comment|/* Linked list of all sequences. */
name|struct
name|_hdr
name|seq
index|[
name|UCHAR_MAX
index|]
decl_stmt|;
comment|/* Linked character sequences. */
comment|/* Ex/vi: executed buffers. */
name|char
modifier|*
name|atkey_buf
decl_stmt|;
comment|/* At key buffer. */
name|char
modifier|*
name|atkey_cur
decl_stmt|;
comment|/* At key current pointer. */
name|int
name|atkey_len
decl_stmt|;
comment|/* Remaining keys in at buffer. */
comment|/* At key stack. */
name|u_char
name|atkey_stack
index|[
name|UCHAR_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|exat_recurse
decl_stmt|;
comment|/* Ex at recursion count. */
name|int
name|exat_lbuf
decl_stmt|;
comment|/* Ex at last buffer. */
comment|/* Ex at key stack. */
name|u_char
name|exat_stack
index|[
name|UCHAR_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|OPTION
name|opts
index|[
name|O_OPTIONCOUNT
index|]
decl_stmt|;
comment|/* Ex/vi: options. */
comment|/*  * SCREEN SUPPORT ROUTINES.  * This is the set of routines that have to be written to add a screen.  */
name|void
argument_list|(
argument|*s_bell
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*s_busy_cursor
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*s_change
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
name|recno_t
operator|,
expr|enum
name|operation
operator|)
argument_list|)
expr_stmt|;
name|size_t
argument_list|(
argument|*s_chposition
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
name|recno_t
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
name|enum
name|confirmation
argument_list|(
operator|*
name|s_confirm
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
expr|struct
name|_mark
operator|*
operator|,
expr|struct
name|_mark
operator|*
operator|)
argument_list|)
decl_stmt|;
name|int
argument_list|(
argument|*s_down
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
expr|struct
name|_mark
operator|*
operator|,
name|recno_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*s_ex_cmd
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
expr|struct
name|_excmdarg
operator|*
operator|,
expr|struct
name|_mark
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*s_ex_run
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
expr|struct
name|_mark
operator|*
operator|)
argument_list|)
expr_stmt|;
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
name|int
argument_list|(
argument|*s_fill
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
name|recno_t
operator|,
expr|enum
name|position
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*s_get
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
expr|struct
name|_hdr
operator|*
operator|,
name|int
operator|,
name|u_int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*s_position
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
name|recno_t
operator|*
operator|,
name|u_long
operator|,
expr|enum
name|position
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*s_refresh
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|)
argument_list|)
expr_stmt|;
name|size_t
argument_list|(
argument|*s_relative
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
name|recno_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*s_split
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*s_suspend
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*s_up
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
expr|struct
name|_mark
operator|*
operator|,
name|recno_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Editor screens (implies edit mode, as well). */
define|#
directive|define
name|S_MODE_EX
value|0x0000001
comment|/* Ex mode. */
define|#
directive|define
name|S_MODE_VI
value|0x0000002
comment|/* Vi mode. */
comment|/* Major screen/file changes. */
define|#
directive|define
name|S_EXIT
value|0x0000004
comment|/* Exiting (not forced). */
define|#
directive|define
name|S_EXIT_FORCE
value|0x0000008
comment|/* Exiting (forced). */
define|#
directive|define
name|S_FSWITCH
value|0x0000010
comment|/* Switch files (not forced). */
define|#
directive|define
name|S_FSWITCH_FORCE
value|0x0000020
comment|/* Switch files (forced). */
define|#
directive|define
name|S_SSWITCH
value|0x0000040
comment|/* Switch screens. */
define|#
directive|define
name|__S_UNUSED
value|0x0000080
comment|/* Unused. */
define|#
directive|define
name|S_MAJOR_CHANGE
comment|/* Screen or file changes. */
define|\
value|(S_EXIT | S_EXIT_FORCE | S_FSWITCH | S_FSWITCH_FORCE | S_SSWITCH)
define|#
directive|define
name|S_ABBREV
value|0x0000100
comment|/* If have abbreviations. */
define|#
directive|define
name|S_AUTOPRINT
value|0x0000200
comment|/* Autoprint flag. */
define|#
directive|define
name|S_BELLSCHED
value|0x0000400
comment|/* Bell scheduled. */
define|#
directive|define
name|S_CUR_INVALID
value|0x0000800
comment|/* Cursor position is incalculable. */
define|#
directive|define
name|S_GLOBAL
value|0x0001000
comment|/* Doing a global command. */
define|#
directive|define
name|S_GLOBAL_QUIT
value|0x0002000
comment|/* Quitting a global command. */
define|#
directive|define
name|S_INPUT
value|0x0004000
comment|/* Doing text input. */
define|#
directive|define
name|S_ISFROMTTY
value|0x0008000
comment|/* Reading from a tty. */
define|#
directive|define
name|S_MSGREENTER
value|0x0010000
comment|/* If msg routine reentered. */
define|#
directive|define
name|S_RE_SET
value|0x0020000
comment|/* The file's RE has been set. */
define|#
directive|define
name|S_REDRAW
value|0x0040000
comment|/* Redraw the screen. */
define|#
directive|define
name|S_REFORMAT
value|0x0080000
comment|/* Reformat the screen. */
define|#
directive|define
name|S_REFRESH
value|0x0100000
comment|/* Refresh the screen. */
define|#
directive|define
name|S_RESIZE
value|0x0200000
comment|/* Resize the screen. */
define|#
directive|define
name|S_UPDATE_MODE
value|0x0400000
comment|/* Don't repaint modeline. */
define|#
directive|define
name|S_SCREEN_RETAIN
comment|/* Retain at screen create. */
define|\
value|(S_MODE_EX | S_MODE_VI | S_ISFROMTTY)
name|u_int
name|flags
decl_stmt|;
block|}
name|SCR
typedef|;
end_typedef

begin_comment
comment|/* Public interfaces to the screens. */
end_comment

begin_decl_stmt
name|int
name|scr_end
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scr_init
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_scr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sex
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
expr|struct
name|_scr
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
expr|struct
name|_scr
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

