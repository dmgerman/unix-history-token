begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_comment
comment|/* maximum length of a line (including '\0').  Currently cannot    be larger than a logical disk block. */
end_comment

begin_define
define|#
directive|define
name|LBSIZE
value|JBUFSIZ
end_define

begin_comment
comment|/* buffer types */
end_comment

begin_define
define|#
directive|define
name|B_SCRATCH
value|1
end_define

begin_comment
comment|/* for internal things, e.g. minibuffer ... */
end_comment

begin_define
define|#
directive|define
name|B_FILE
value|2
end_define

begin_comment
comment|/* normal file (we auto-save these.) */
end_comment

begin_define
define|#
directive|define
name|B_PROCESS
value|3
end_define

begin_comment
comment|/* unix process output in this buffer */
end_comment

begin_comment
comment|/* major modes */
end_comment

begin_define
define|#
directive|define
name|FUNDAMENTAL
value|0
end_define

begin_comment
comment|/* Fundamental mode */
end_comment

begin_define
define|#
directive|define
name|TEXT
value|1
end_define

begin_comment
comment|/* Text mode */
end_comment

begin_define
define|#
directive|define
name|CMODE
value|2
end_define

begin_comment
comment|/* C mode */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LISP
end_ifdef

begin_define
define|#
directive|define
name|LISPMODE
value|3
end_define

begin_comment
comment|/* Lisp mode */
end_comment

begin_define
define|#
directive|define
name|NMAJORS
value|4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NMAJORS
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MajorMode
parameter_list|(
name|x
parameter_list|)
value|(curbuf->b_major == (x))
end_define

begin_define
define|#
directive|define
name|SetMajor
parameter_list|(
name|x
parameter_list|)
value|{ curbuf->b_major = (x); UpdModLine = YES; }
end_define

begin_comment
comment|/* minor modes */
end_comment

begin_define
define|#
directive|define
name|Indent
value|(1<< 0)
end_define

begin_comment
comment|/* indent same as previous line after return */
end_comment

begin_define
define|#
directive|define
name|ShowMatch
value|(1<< 1)
end_define

begin_comment
comment|/* paren flash mode */
end_comment

begin_define
define|#
directive|define
name|Fill
value|(1<< 2)
end_define

begin_comment
comment|/* text fill mode */
end_comment

begin_define
define|#
directive|define
name|OverWrite
value|(1<< 3)
end_define

begin_comment
comment|/* over write mode */
end_comment

begin_define
define|#
directive|define
name|Abbrev
value|(1<< 4)
end_define

begin_comment
comment|/* abbrev mode */
end_comment

begin_define
define|#
directive|define
name|ReadOnly
value|(1<< 5)
end_define

begin_comment
comment|/* buffer is read only */
end_comment

begin_define
define|#
directive|define
name|BufMinorMode
parameter_list|(
name|b
parameter_list|,
name|x
parameter_list|)
value|((b)->b_minor& (x))
end_define

begin_define
define|#
directive|define
name|MinorMode
parameter_list|(
name|x
parameter_list|)
value|BufMinorMode(curbuf, (x))
end_define

begin_comment
comment|/* global line scratch buffers */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMUNIX
argument_list|)
operator|||
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|char
name|genbuf
index|[
name|LBSIZE
index|]
decl_stmt|,
name|linebuf
index|[
name|LBSIZE
index|]
decl_stmt|,
name|iobuff
index|[
name|LBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|genbuf
decl_stmt|,
comment|/* scratch pad points at s_genbuf (see main()) */
modifier|*
name|linebuf
decl_stmt|,
comment|/* points at s_linebuf */
modifier|*
name|iobuff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for file reading ... points at s_iobuff */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|line
block|{
name|Line
modifier|*
name|l_prev
decl_stmt|,
comment|/* pointer to prev */
modifier|*
name|l_next
decl_stmt|;
comment|/* pointer to next */
name|daddr
name|l_dline
decl_stmt|;
comment|/* pointer to disk location */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mark
block|{
name|Line
modifier|*
name|m_line
decl_stmt|;
name|int
name|m_char
decl_stmt|;
name|Mark
modifier|*
name|m_next
decl_stmt|;
comment|/* list of marks */
define|#
directive|define
name|M_FIXED
value|00
define|#
directive|define
name|M_FLOATER
value|01
define|#
directive|define
name|M_BIG_DELETE
value|02
name|char
name|m_flags
decl_stmt|;
comment|/* FLOATERing mark? */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|buffer
block|{
ifdef|#
directive|ifdef
name|MAC
name|int
name|Type
decl_stmt|;
comment|/* kludge... to look like a data_obj */
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* Name will not be used */
endif|#
directive|endif
name|Buffer
modifier|*
name|b_next
decl_stmt|;
comment|/* next buffer in chain */
name|char
modifier|*
name|b_name
decl_stmt|,
comment|/* buffer name */
modifier|*
name|b_fname
decl_stmt|;
comment|/* file name associated with buffer */
name|dev_t
name|b_dev
decl_stmt|;
comment|/* device of file name. */
name|ino_t
name|b_ino
decl_stmt|;
comment|/* inode of file name */
name|time_t
name|b_mtime
decl_stmt|;
comment|/* last modify time ... 					   to detect two people writing 					   to the same file */
name|Line
modifier|*
name|b_first
decl_stmt|,
comment|/* pointer to first line in list */
modifier|*
name|b_dot
decl_stmt|,
comment|/* current line */
modifier|*
name|b_last
decl_stmt|;
comment|/* last line in list */
name|int
name|b_char
decl_stmt|;
comment|/* current character in line */
define|#
directive|define
name|NMARKS
value|8
comment|/* number of marks in the ring */
name|Mark
modifier|*
name|b_markring
index|[
name|NMARKS
index|]
decl_stmt|,
comment|/* new marks are pushed here */
define|#
directive|define
name|b_curmark
parameter_list|(
name|b
parameter_list|)
value|((b)->b_markring[(b)->b_themark])
define|#
directive|define
name|curmark
value|b_curmark(curbuf)
modifier|*
name|b_marks
decl_stmt|;
comment|/* all the marks for this buffer */
name|char
name|b_themark
decl_stmt|,
comment|/* current mark (in b_markring) */
name|b_type
decl_stmt|,
comment|/* file, scratch, process, iprocess */
name|b_ntbf
decl_stmt|,
comment|/* needs to be found when we 					   first select? */
name|b_modified
decl_stmt|;
comment|/* is the buffer modified? */
name|int
name|b_major
decl_stmt|,
comment|/* major mode */
name|b_minor
decl_stmt|;
comment|/* and minor mode */
name|struct
name|keymap
modifier|*
name|b_map
decl_stmt|;
comment|/* local bindings (if any) */
ifdef|#
directive|ifdef
name|IPROCS
name|Process
modifier|*
name|b_process
decl_stmt|;
comment|/* process we're attached to */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|Buffer
modifier|*
name|world
decl_stmt|,
comment|/* first buffer */
modifier|*
name|curbuf
decl_stmt|,
comment|/* pointer into world for current buffer */
modifier|*
name|lastbuf
decl_stmt|,
comment|/* Last buffer we were in so we have a default 				   buffer during a select buffer. */
modifier|*
name|perr_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer with error messages */
end_comment

begin_define
define|#
directive|define
name|curline
value|(curbuf->b_dot)
end_define

begin_define
define|#
directive|define
name|curchar
value|(curbuf->b_char)
end_define

begin_comment
comment|/* kill buffer */
end_comment

begin_define
define|#
directive|define
name|NUMKILLS
value|10
end_define

begin_comment
comment|/* number of kills saved in the kill ring */
end_comment

begin_decl_stmt
specifier|extern
name|Line
modifier|*
name|killbuf
index|[
name|NUMKILLS
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|position
block|{
name|Line
modifier|*
name|p_line
decl_stmt|;
name|int
name|p_char
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|killptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index into killbuf */
end_comment

begin_decl_stmt
specifier|extern
name|Buffer
modifier|*
name|buf_exists
name|proto
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|do_find
name|proto
argument_list|(
operator|(
expr|struct
name|window
operator|*
name|w
operator|,
name|char
operator|*
name|fname
operator|,
name|int
name|force
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|do_select
name|proto
argument_list|(
operator|(
expr|struct
name|window
operator|*
name|w
operator|,
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|file_exists
name|proto
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ask_buf
name|proto
argument_list|(
operator|(
expr|struct
name|buffer
operator|*
name|def
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|ralloc
name|proto
argument_list|(
operator|(
name|char
operator|*
name|obj
operator|,
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_struct_decl
struct_decl|struct
name|macro
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|TogMinor
name|proto
argument_list|(
operator|(
name|int
name|bit
operator|)
argument_list|)
decl_stmt|,
name|bufname
name|proto
argument_list|(
operator|(
expr|struct
name|buffer
operator|*
name|b
operator|)
argument_list|)
decl_stmt|,
name|initlist
name|proto
argument_list|(
operator|(
expr|struct
name|buffer
operator|*
name|b
operator|)
argument_list|)
decl_stmt|,
name|setbname
name|proto
argument_list|(
operator|(
expr|struct
name|buffer
operator|*
name|b
operator|,
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|,
name|setfname
name|proto
argument_list|(
operator|(
expr|struct
name|buffer
operator|*
name|b
operator|,
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|,
name|set_ino
name|proto
argument_list|(
operator|(
expr|struct
name|buffer
operator|*
name|b
operator|)
argument_list|)
decl_stmt|,
name|SetABuf
name|proto
argument_list|(
operator|(
expr|struct
name|buffer
operator|*
name|b
operator|)
argument_list|)
decl_stmt|,
name|SetBuf
name|proto
argument_list|(
operator|(
expr|struct
name|buffer
operator|*
name|newbuf
operator|)
argument_list|)
decl_stmt|,
name|AllMarkSet
name|proto
argument_list|(
operator|(
expr|struct
name|buffer
operator|*
name|b
operator|,
expr|struct
name|line
operator|*
name|line
operator|,
name|int
name|col
operator|)
argument_list|)
decl_stmt|,
name|DFixMarks
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line1
operator|,
name|int
name|char1
operator|,
expr|struct
name|line
operator|*
name|line2
operator|,
name|int
name|char2
operator|)
argument_list|)
decl_stmt|,
name|DelMark
name|proto
argument_list|(
operator|(
expr|struct
name|mark
operator|*
name|m
operator|)
argument_list|)
decl_stmt|,
name|IFixMarks
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line1
operator|,
name|int
name|char1
operator|,
expr|struct
name|line
operator|*
name|line2
operator|,
name|int
name|char2
operator|)
argument_list|)
decl_stmt|,
name|MarkSet
name|proto
argument_list|(
operator|(
expr|struct
name|mark
operator|*
name|m
operator|,
expr|struct
name|line
operator|*
name|line
operator|,
name|int
name|column
operator|)
argument_list|)
decl_stmt|,
name|ToMark
name|proto
argument_list|(
operator|(
expr|struct
name|mark
operator|*
name|m
operator|)
argument_list|)
decl_stmt|,
name|flush_marks
name|proto
argument_list|(
operator|(
name|Buffer
operator|*
operator|)
argument_list|)
decl_stmt|,
name|b_char
name|proto
argument_list|(
operator|(
name|int
name|n
operator|)
argument_list|)
decl_stmt|,
name|b_word
name|proto
argument_list|(
operator|(
name|int
name|num
operator|)
argument_list|)
decl_stmt|,
name|del_char
name|proto
argument_list|(
operator|(
name|int
name|dir
operator|,
name|int
name|num
operator|,
name|int
name|OK_kill
operator|)
argument_list|)
decl_stmt|,
name|do_macro
name|proto
argument_list|(
operator|(
expr|struct
name|macro
operator|*
name|mac
operator|)
argument_list|)
decl_stmt|,
name|do_set_mark
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|l
operator|,
name|int
name|c
operator|)
argument_list|)
decl_stmt|,
name|f_char
name|proto
argument_list|(
operator|(
name|int
name|n
operator|)
argument_list|)
decl_stmt|,
name|f_word
name|proto
argument_list|(
operator|(
name|int
name|num
operator|)
argument_list|)
decl_stmt|,
name|freeline
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line
operator|)
argument_list|)
decl_stmt|,
name|ins_str
name|proto
argument_list|(
operator|(
name|char
operator|*
name|str
operator|,
name|int
name|ok_nl
operator|)
argument_list|)
decl_stmt|,
name|insert_c
name|proto
argument_list|(
operator|(
name|int
name|c
operator|,
name|int
name|n
operator|)
argument_list|)
decl_stmt|,
name|lfreelist
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|first
operator|)
argument_list|)
decl_stmt|,
name|lfreereg
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line1
operator|,
expr|struct
name|line
operator|*
name|line2
operator|)
argument_list|)
decl_stmt|,
name|line_move
name|proto
argument_list|(
operator|(
name|int
name|dir
operator|,
name|int
name|n
operator|,
name|int
name|line_cmd
operator|)
argument_list|)
decl_stmt|,
name|lremove
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line1
operator|,
expr|struct
name|line
operator|*
name|line2
operator|)
argument_list|)
decl_stmt|,
name|mac_putc
name|proto
argument_list|(
operator|(
name|int
name|c
operator|)
argument_list|)
decl_stmt|,
name|n_indent
name|proto
argument_list|(
operator|(
name|int
name|goal
operator|)
argument_list|)
decl_stmt|,
name|open_lines
name|proto
argument_list|(
operator|(
name|int
name|n
operator|)
argument_list|)
decl_stmt|,
name|reg_kill
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line2
operator|,
name|int
name|char2
operator|,
name|int
name|dot_moved
operator|)
argument_list|)
decl_stmt|,
name|set_mark
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|unwind_macro_stack
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|buf_init
name|proto
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
name|ModMacs
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|in_macro
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|mac_getc
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|how_far
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line
operator|,
name|int
name|col
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|line
modifier|*
name|lastline
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|lp
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|listput
name|proto
argument_list|(
operator|(
expr|struct
name|buffer
operator|*
name|buf
operator|,
expr|struct
name|line
operator|*
name|after
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|max_line
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|l1
operator|,
expr|struct
name|line
operator|*
name|l2
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|min_line
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|l1
operator|,
expr|struct
name|line
operator|*
name|l2
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|nbufline
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|next_line
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line
operator|,
name|int
name|num
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|prev_line
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line
operator|,
name|int
name|num
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|reg_delete
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line1
operator|,
name|int
name|char1
operator|,
expr|struct
name|line
operator|*
name|line2
operator|,
name|int
name|char2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Mark
modifier|*
name|CurMark
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|MakeMark
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line
operator|,
name|int
name|column
operator|,
name|int
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

