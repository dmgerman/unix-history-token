begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_comment
comment|/* jove.h header file to be included by EVERYONE */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TUNED
end_ifndef

begin_include
include|#
directive|include
file|"tune.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|MAC
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|IBMPC
argument_list|)
operator|||
name|defined
argument_list|(
name|MAC
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|TERMCAP
end_define

begin_define
define|#
directive|define
name|ASCII
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ASCII
end_ifdef

begin_comment
comment|/* seven bit characters */
end_comment

begin_define
define|#
directive|define
name|NCHARS
value|0200
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NCHARS
value|0400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CHARMASK
value|(NCHARS -1)
end_define

begin_define
define|#
directive|define
name|private
value|static
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BSD4_2
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MENLO_JCL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|EUNICE
end_ifndef

begin_define
define|#
directive|define
name|signal
value|sigset
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MENLO_JCL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EOF
value|-1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_define
define|#
directive|define
name|NULL
value|((char *)0)
end_define

begin_define
define|#
directive|define
name|NIL
value|((char *)0)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_define
define|#
directive|define
name|NULL
value|0L
end_define

begin_define
define|#
directive|define
name|NIL
value|0L
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_define
define|#
directive|define
name|NIL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

begin_comment
comment|/* kinds of regular expression compiles */
end_comment

begin_define
define|#
directive|define
name|NORM
value|0
end_define

begin_comment
comment|/* nothing special */
end_comment

begin_define
define|#
directive|define
name|OKAY_RE
value|1
end_define

begin_comment
comment|/* allow regular expressions */
end_comment

begin_define
define|#
directive|define
name|IN_CB
value|2
end_define

begin_comment
comment|/* in curly brace; implies OKAY_RE */
end_comment

begin_comment
comment|/* return codes for command completion (all< 0 because>= 0 are    legitimate offsets into array of strings */
end_comment

begin_define
define|#
directive|define
name|AMBIGUOUS
value|-2
end_define

begin_comment
comment|/* matches more than one at this point */
end_comment

begin_define
define|#
directive|define
name|UNIQUE
value|-3
end_define

begin_comment
comment|/* matches only one string */
end_comment

begin_define
define|#
directive|define
name|ORIGINAL
value|-4
end_define

begin_comment
comment|/* matches no strings at all! */
end_comment

begin_define
define|#
directive|define
name|NULLSTRING
value|-5
end_define

begin_comment
comment|/* just hit return without typing anything */
end_comment

begin_comment
comment|/* values for the `flags' argument to complete */
end_comment

begin_define
define|#
directive|define
name|NOTHING
value|0
end_define

begin_comment
comment|/* opposite of RET_STATE */
end_comment

begin_define
define|#
directive|define
name|RET_STATE
value|1
end_define

begin_comment
comment|/* return state when we hit return */
end_comment

begin_define
define|#
directive|define
name|RCOMMAND
value|2
end_define

begin_comment
comment|/* we are reading a joverc file */
end_comment

begin_define
define|#
directive|define
name|CASEIND
value|4
end_define

begin_comment
comment|/* map all to lower case */
end_comment

begin_define
define|#
directive|define
name|SAVE
value|01
end_define

begin_comment
comment|/* this macro needs saving to a file */
end_comment

begin_define
define|#
directive|define
name|LBSIZE
value|BUFSIZ
end_define

begin_comment
comment|/* same as a logical disk block */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS
end_ifndef

begin_define
define|#
directive|define
name|FILESIZE
value|256
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MSDOS */
end_comment

begin_define
define|#
directive|define
name|FILESIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

begin_define
define|#
directive|define
name|FORWARD
value|1
end_define

begin_define
define|#
directive|define
name|BACKWARD
value|-1
end_define

begin_define
define|#
directive|define
name|CTL
parameter_list|(
name|c
parameter_list|)
value|(c& 037)
end_define

begin_define
define|#
directive|define
name|META
parameter_list|(
name|c
parameter_list|)
value|(c | 0200)
end_define

begin_define
define|#
directive|define
name|RUBOUT
value|'\177'
end_define

begin_define
define|#
directive|define
name|LF
value|CTL('J')
end_define

begin_define
define|#
directive|define
name|CR
value|CTL('M')
end_define

begin_define
define|#
directive|define
name|BS
value|CTL('H')
end_define

begin_define
define|#
directive|define
name|ESC
value|'\033'
end_define

begin_define
define|#
directive|define
name|HALF
parameter_list|(
name|wp
parameter_list|)
value|((wp->w_height - 1) / 2)
end_define

begin_define
define|#
directive|define
name|IsModified
parameter_list|(
name|b
parameter_list|)
value|(b->b_modified)
end_define

begin_define
define|#
directive|define
name|SIZE
parameter_list|(
name|wp
parameter_list|)
value|(wp->w_height - 1)
end_define

begin_define
define|#
directive|define
name|SavLine
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a->l_dline = putline(b))
end_define

begin_define
define|#
directive|define
name|SetLine
parameter_list|(
name|line
parameter_list|)
value|DotTo(line, 0)
end_define

begin_define
define|#
directive|define
name|bobp
parameter_list|()
value|(firstp(curline)&& bolp())
end_define

begin_define
define|#
directive|define
name|bolp
parameter_list|()
value|(curchar == 0)
end_define

begin_define
define|#
directive|define
name|eobp
parameter_list|()
value|(lastp(curline)&& eolp())
end_define

begin_define
define|#
directive|define
name|eolp
parameter_list|()
value|(linebuf[curchar] == '\0')
end_define

begin_define
define|#
directive|define
name|firstp
parameter_list|(
name|line
parameter_list|)
value|(line == curbuf->b_first)
end_define

begin_define
define|#
directive|define
name|getDOT
parameter_list|()
value|getline(curline->l_dline, linebuf)
end_define

begin_define
define|#
directive|define
name|isdirty
parameter_list|(
name|line
parameter_list|)
value|(line->l_dline& DIRTY)
end_define

begin_define
define|#
directive|define
name|lastp
parameter_list|(
name|line
parameter_list|)
value|(line == curbuf->b_last)
end_define

begin_define
define|#
directive|define
name|makedirty
parameter_list|(
name|line
parameter_list|)
value|line->l_dline |= DIRTY
end_define

begin_define
define|#
directive|define
name|one_windp
parameter_list|()
value|(fwind->w_next == fwind)
end_define

begin_define
define|#
directive|define
name|CharUpcase
parameter_list|(
name|c
parameter_list|)
value|(CaseEquiv[c])
end_define

begin_decl_stmt
specifier|extern
name|int
name|BufSize
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ARG_CMD
value|1
end_define

begin_define
define|#
directive|define
name|LINECMD
value|2
end_define

begin_define
define|#
directive|define
name|KILLCMD
value|3
end_define

begin_comment
comment|/* so we can merge kills */
end_comment

begin_define
define|#
directive|define
name|YANKCMD
value|4
end_define

begin_comment
comment|/* so we can do ESC Y (yank-pop) */
end_comment

begin_comment
comment|/* Buffer type */
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
comment|/* normal file (We Auto-save these.) */
end_comment

begin_define
define|#
directive|define
name|B_PROCESS
value|3
end_define

begin_comment
comment|/* process output in this buffer */
end_comment

begin_comment
comment|/* Major modes */
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

begin_comment
comment|/* Minor Modes */
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
name|BufMinorMode
parameter_list|(
name|b
parameter_list|,
name|x
parameter_list|)
value|(b->b_minor& x)
end_define

begin_define
define|#
directive|define
name|MinorMode
parameter_list|(
name|x
parameter_list|)
value|BufMinorMode(curbuf, x)
end_define

begin_define
define|#
directive|define
name|MajorMode
parameter_list|(
name|x
parameter_list|)
value|(curbuf->b_major == x)
end_define

begin_define
define|#
directive|define
name|SetMajor
parameter_list|(
name|x
parameter_list|)
value|((curbuf->b_major = x), UpdModLine = YES)
end_define

begin_decl_stmt
specifier|extern
name|char
name|CharTable
index|[
name|NMAJORS
index|]
index|[
name|NCHARS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|CaseEquiv
index|[
name|NCHARS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* setjmp/longjmp args for DoKeys() mainjmp */
end_comment

begin_define
define|#
directive|define
name|FIRSTCALL
value|0
end_define

begin_define
define|#
directive|define
name|ERROR
value|1
end_define

begin_define
define|#
directive|define
name|COMPLAIN
value|2
end_define

begin_comment
comment|/* do the error without a getDOT */
end_comment

begin_define
define|#
directive|define
name|QUIT
value|3
end_define

begin_comment
comment|/* leave this level of recursion */
end_comment

begin_define
define|#
directive|define
name|QUIET
value|1
end_define

begin_comment
comment|/* sure, why not? */
end_comment

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_define
define|#
directive|define
name|NO
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|ON
value|1
end_define

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_define
define|#
directive|define
name|YES_NODIGIT
value|2
end_define

begin_define
define|#
directive|define
name|INT_OKAY
value|0
end_define

begin_define
define|#
directive|define
name|INT_BAD
value|-1
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Mainbuf
decl_stmt|,
modifier|*
name|HomeDir
decl_stmt|,
comment|/* home directory */
name|key_strokes
index|[]
decl_stmt|,
comment|/* strokes that make up current command */
modifier|*
name|Inputp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|HomeLen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of home directory */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|NullStr
index|[]
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|int
name|InJoverc
decl_stmt|,
name|Interactive
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|READ
value|0
end_define

begin_define
define|#
directive|define
name|WRITE
value|1
end_define

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|mainjmp
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|IPROCS
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|process
name|Process
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|window
name|Window
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|position
name|Bufpos
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mark
name|Mark
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|buffer
name|Buffer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|line
name|Line
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|iobuf
name|IOBUF
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|data_obj
block|{
name|int
name|Type
decl_stmt|;
name|char
modifier|*
name|Name
decl_stmt|;
block|}
name|data_obj
typedef|;
end_typedef

begin_comment
comment|/* points to cmd, macro, or variable */
end_comment

begin_typedef
typedef|typedef
name|data_obj
modifier|*
name|keymap
index|[
name|NCHARS
index|]
typedef|;
end_typedef

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
name|disk_line
name|l_dline
decl_stmt|;
comment|/* pointer to disk location */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|IPROCS
end_ifdef

begin_struct
struct|struct
name|process
block|{
name|Process
modifier|*
name|p_next
decl_stmt|;
ifdef|#
directive|ifdef
name|PIPEPROCS
name|int
name|p_toproc
decl_stmt|,
comment|/* read p_fromproc and write p_toproc */
name|p_portpid
decl_stmt|,
comment|/* pid of child (the portsrv) */
name|p_pid
decl_stmt|;
comment|/* pid of real child i.e. not portsrv */
else|#
directive|else
name|int
name|p_fd
decl_stmt|,
comment|/* file descriptor of pty? opened r/w */
name|p_pid
decl_stmt|;
comment|/* pid of child (the shell) */
endif|#
directive|endif
name|Buffer
modifier|*
name|p_buffer
decl_stmt|;
comment|/* add output to end of this buffer */
name|char
modifier|*
name|p_name
decl_stmt|;
comment|/* ... */
name|char
name|p_state
decl_stmt|,
comment|/* State */
name|p_howdied
decl_stmt|,
comment|/* Killed? or Exited? */
name|p_reason
decl_stmt|;
comment|/* If signaled, p_reason is the signal; else 				   it is the the exit code */
name|Mark
modifier|*
name|p_mark
decl_stmt|;
comment|/* where output left us */
name|data_obj
modifier|*
name|p_cmd
decl_stmt|;
comment|/* command to call when process dies */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPROCS */
end_comment

begin_struct
struct|struct
name|window
block|{
name|Window
modifier|*
name|w_prev
decl_stmt|,
comment|/* circular list */
modifier|*
name|w_next
decl_stmt|;
name|Buffer
modifier|*
name|w_bufp
decl_stmt|;
comment|/* buffer associated with this window */
name|Line
modifier|*
name|w_top
decl_stmt|,
comment|/* top line */
modifier|*
name|w_line
decl_stmt|;
comment|/* current line */
name|int
name|w_char
decl_stmt|,
name|w_height
decl_stmt|,
comment|/* window height */
name|w_topnum
decl_stmt|,
comment|/* line number of the topline */
name|w_dotcol
decl_stmt|,
comment|/* UpdWindow sets this ... */
name|w_dotline
decl_stmt|,
comment|/* ... and this */
name|w_flags
decl_stmt|,
define|#
directive|define
name|W_TOPGONE
value|01
define|#
directive|define
name|W_CURGONE
value|02
comment|/* topline (curline) of window has been deleted 				   since the last time a redisplay was called */
define|#
directive|define
name|W_VISSPACE
value|04
define|#
directive|define
name|W_NUMLINES
value|010
name|w_LRscroll
decl_stmt|;
comment|/* amount of LeftRight scrolling in window */
ifdef|#
directive|ifdef
name|MAC
name|int
name|w_topline
decl_stmt|;
comment|/* row number of top line in window */
name|char
modifier|*
modifier|*
name|w_control
decl_stmt|;
comment|/* scroll bar for window */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|Window
modifier|*
name|fwind
decl_stmt|,
comment|/* first window in list */
modifier|*
name|curwind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current window */
end_comment

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
name|keymap
modifier|*
name|b_keybinds
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

begin_struct
struct|struct
name|macro
block|{
name|int
name|Type
decl_stmt|;
comment|/* in this case a macro */
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* name is always second ... */
name|int
name|m_len
decl_stmt|,
comment|/* length of macro so we can use ^@ */
name|m_buflen
decl_stmt|,
comment|/* memory allocated for it */
name|m_flags
decl_stmt|;
name|char
modifier|*
name|m_body
decl_stmt|;
comment|/* actual body of the macro */
name|struct
name|macro
modifier|*
name|m_nextm
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|variable
block|{
name|int
name|Type
decl_stmt|;
comment|/* in this case a variable */
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* name is always second */
name|int
modifier|*
name|v_value
decl_stmt|,
name|v_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cmd
block|{
name|int
name|Type
decl_stmt|;
name|char
modifier|*
name|Name
decl_stmt|;
ifdef|#
directive|ifdef
name|MAC
name|void
function_decl|(
modifier|*
name|c_proc
function_decl|)
parameter_list|()
function_decl|;
else|#
directive|else
name|int
function_decl|(
modifier|*
name|c_proc
function_decl|)
parameter_list|()
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MAC
name|char
name|c_map
decl_stmt|;
comment|/* prefix map for About Jove... */
name|char
name|c_key
decl_stmt|;
comment|/* key binding for About Jove... */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|keymap
name|mainmap
decl_stmt|,
comment|/* various key maps */
name|pref1map
decl_stmt|,
name|pref2map
decl_stmt|,
name|miscmap
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_comment
comment|/* used in About Jove... */
end_comment

begin_define
define|#
directive|define
name|F_MAINMAP
value|'\001'
end_define

begin_define
define|#
directive|define
name|F_PREF1MAP
value|'\002'
end_define

begin_define
define|#
directive|define
name|F_PREF2MAP
value|'\003'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|data_obj
modifier|*
name|LastCmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last command invoked */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ProcFmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cmd
name|commands
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|macro
modifier|*
name|macros
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|variable
name|variables
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|macro
modifier|*
name|macstack
index|[]
decl_stmt|,
name|KeyMacro
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FUNCTION
value|1
end_define

begin_define
define|#
directive|define
name|VARIABLE
value|2
end_define

begin_define
define|#
directive|define
name|MACRO
value|3
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_define
define|#
directive|define
name|BUFFER
value|6
end_define

begin_comment
comment|/* menus can point to buffers, too */
end_comment

begin_define
define|#
directive|define
name|STRING
value|7
end_define

begin_comment
comment|/* a menu string or divider */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TYPEMASK
value|07
end_define

begin_define
define|#
directive|define
name|MAJOR_MODE
value|010
end_define

begin_define
define|#
directive|define
name|MINOR_MODE
value|020
end_define

begin_define
define|#
directive|define
name|DefMajor
parameter_list|(
name|x
parameter_list|)
value|(FUNCTION|MAJOR_MODE|(x<< 8))
end_define

begin_define
define|#
directive|define
name|DefMinor
parameter_list|(
name|x
parameter_list|)
value|(FUNCTION|MINOR_MODE|(x<< 8))
end_define

begin_decl_stmt
specifier|extern
name|Buffer
modifier|*
name|world
decl_stmt|,
comment|/* first buffer */
modifier|*
name|curbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer into world for current buffer */
end_comment

begin_define
define|#
directive|define
name|curline
value|curbuf->b_dot
end_define

begin_define
define|#
directive|define
name|curchar
value|curbuf->b_char
end_define

begin_define
define|#
directive|define
name|NUMKILLS
value|10
end_define

begin_comment
comment|/* number of kills saved in the kill ring */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_comment
comment|/* when doing ~DIRTY, we need high bits set */
end_comment

begin_define
define|#
directive|define
name|DIRTY
value|(disk_line) 01
end_define

begin_comment
comment|/* just needs updating for some reason */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DIRTY
value|01
end_define

begin_comment
comment|/* just needs updating for some reason */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MODELINE
value|02
end_define

begin_comment
comment|/* this is a modeline */
end_comment

begin_define
define|#
directive|define
name|L_MOD
value|04
end_define

begin_comment
comment|/* this line has been modified internally */
end_comment

begin_struct
struct|struct
name|scrimage
block|{
name|int
name|s_offset
decl_stmt|,
comment|/* offset to start printing at */
name|s_flags
decl_stmt|,
comment|/* various flags */
name|s_id
decl_stmt|,
comment|/* which buffer line */
name|s_vln
decl_stmt|;
comment|/* Visible Line Number */
name|Line
modifier|*
name|s_lp
decl_stmt|;
comment|/* so we can turn off red bit */
name|Window
modifier|*
name|s_window
decl_stmt|;
comment|/* window that contains this line */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|scrimage
modifier|*
name|DesiredScreen
decl_stmt|,
comment|/* what we want */
modifier|*
name|PhysScreen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* what we got */
end_comment

begin_comment
comment|/* Variable flags (that can be set). */
end_comment

begin_define
define|#
directive|define
name|V_BASE10
value|01
end_define

begin_comment
comment|/* is integer in base 10 */
end_comment

begin_define
define|#
directive|define
name|V_BASE8
value|02
end_define

begin_comment
comment|/* is integer in base 8 */
end_comment

begin_define
define|#
directive|define
name|V_BOOL
value|04
end_define

begin_comment
comment|/* is a boolean */
end_comment

begin_define
define|#
directive|define
name|V_STRING
value|010
end_define

begin_comment
comment|/* is a string */
end_comment

begin_define
define|#
directive|define
name|V_CHAR
value|020
end_define

begin_comment
comment|/* is a character */
end_comment

begin_define
define|#
directive|define
name|V_FILENAME
value|040
end_define

begin_comment
comment|/* a file name (implies V_STRING) */
end_comment

begin_define
define|#
directive|define
name|V_TYPEMASK
value|077
end_define

begin_comment
comment|/* mask off the extra bits */
end_comment

begin_define
define|#
directive|define
name|V_MODELINE
value|0100
end_define

begin_comment
comment|/* update modeline */
end_comment

begin_define
define|#
directive|define
name|V_CLRSCREEN
value|0200
end_define

begin_comment
comment|/* clear and redraw screen */
end_comment

begin_define
define|#
directive|define
name|V_TTY_RESET
value|0400
end_define

begin_comment
comment|/* redo the tty modes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TXT_TO_C
end_ifdef

begin_decl_stmt
name|int
comment|/* kludge, so setmaps will compile with variables */
else|#
directive|else
specifier|extern
name|int
endif|#
directive|endif
comment|/* TXT_TO_C */
else|#
directive|else
specifier|extern
name|int
endif|#
directive|endif
comment|/* MAC */
name|OKXonXoff
decl_stmt|,
comment|/* disable start/stop characters */
name|MetaKey
decl_stmt|,
comment|/* this terminal has a meta key */
name|VisBell
decl_stmt|,
comment|/* use visible bell (if possible) */
name|WrapScan
decl_stmt|,
comment|/* make searches wrap */
ifndef|#
directive|ifndef
name|MAC
name|phystab
decl_stmt|,
comment|/* terminal's tabstop settings */
endif|#
directive|endif
name|tabstop
decl_stmt|,
comment|/* expand tabs to this number of spaces */
ifdef|#
directive|ifdef
name|BACKUPFILES
name|BkupOnWrite
decl_stmt|,
comment|/* make backup files when writing */
endif|#
directive|endif
name|RMargin
decl_stmt|,
comment|/* right margin */
name|LMargin
decl_stmt|,
comment|/* left margin */
name|ScrollStep
decl_stmt|,
comment|/* how should we scroll */
ifndef|#
directive|ifndef
name|MAC
name|WtOnMk
decl_stmt|,
comment|/* write files on compile-it command */
endif|#
directive|endif
name|EndWNewline
decl_stmt|,
comment|/* end files with a blank line */
name|MarkThresh
decl_stmt|,
comment|/* moves greater than MarkThresh will SetMark */
name|PDelay
decl_stmt|,
comment|/* paren flash delay in tenths of a second */
name|CIndIncrmt
decl_stmt|,
comment|/* how much each indentation level pushes 				   over in C mode */
name|CreatMode
decl_stmt|,
comment|/* default mode for creat'ing files */
name|CaseIgnore
decl_stmt|,
comment|/* case ignore search */
ifdef|#
directive|ifdef
name|ABBREV
name|AutoCaseAbbrev
decl_stmt|,
comment|/* automatically do case on abbreviations */
endif|#
directive|endif
name|MarksShouldFloat
decl_stmt|,
comment|/* adjust marks on insertion/deletion */
name|UseRE
decl_stmt|,
comment|/* use regular expressions in search */
name|SyncFreq
decl_stmt|,
comment|/* how often to sync the file pointers */
name|BriteMode
decl_stmt|,
comment|/* make the mode line inverse? */
name|OkayBadChars
decl_stmt|,
comment|/* allow bad characters in files created 				   by JOVE */
name|UpdFreq
decl_stmt|,
comment|/* how often to update modeline */
name|UseBuffers
decl_stmt|,
comment|/* use buffers with Typeout() */
ifdef|#
directive|ifdef
name|BIFF
name|BiffChk
decl_stmt|,
comment|/* turn off/on biff with entering/exiting jove */
endif|#
directive|endif
name|MailInt
decl_stmt|,
comment|/* mail check interval */
ifdef|#
directive|ifdef
name|ID_CHAR
name|UseIC
decl_stmt|,
comment|/* whether or not to use i/d char 				   processesing */
endif|#
directive|endif
name|SExitChar
decl_stmt|,
comment|/* type this to stop i-search */
name|AbortChar
decl_stmt|,
comment|/* cancels command input */
name|IntChar
decl_stmt|,
comment|/* ttysets this to generate QUIT */
name|DoEVexpand
decl_stmt|,
comment|/* treat $foo as environment variable */
ifdef|#
directive|ifdef
name|F_COMPLETION
name|DispBadFs
decl_stmt|,
comment|/* display filenames with bad extensions? */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|IBMPC
name|Fgcolor
decl_stmt|,
name|Bgcolor
decl_stmt|,
name|Mdcolor
decl_stmt|,
endif|#
directive|endif
comment|/* IBMPC */
ifdef|#
directive|ifdef
name|F_COMPLETION
name|DispBadFs
decl_stmt|,
comment|/* display filenames with bad extensions? */
endif|#
directive|endif
name|ScrollAll
decl_stmt|,
comment|/* we current line scrolls, scroll whole window? */
ifndef|#
directive|ifndef
name|MAC
name|EWSize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size to make the error window */
end_comment

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|Macmode
operator|,
comment|/* see mac.c */
name|Keyonly
operator|,
name|Bufchange
operator|,
name|Modechange
operator|,
name|Windchange
operator|,
name|EventCmd
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TXT_TO_C
end_ifdef

begin_comment
comment|/* kludge, for setmaps with variables */
end_comment

begin_decl_stmt
name|char
else|#
directive|else
specifier|extern
name|char
endif|#
directive|endif
comment|/* TXT_TO_C */
else|#
directive|else
specifier|extern
name|char
endif|#
directive|endif
comment|/* MAC */
ifndef|#
directive|ifndef
name|MAC
name|ErrFmtStr
index|[
literal|256
index|]
decl_stmt|,
comment|/* format string for parse errors */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|IPROCS
name|proc_prompt
index|[
literal|128
index|]
decl_stmt|,
comment|/* process prompt */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|F_COMPLETION
name|BadExtensions
index|[
literal|128
index|]
decl_stmt|,
comment|/* extensions (e.g., ".o" to ignore) */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CMT_FMT
name|CmtFmt
index|[
literal|80
index|]
decl_stmt|,
endif|#
directive|endif
name|ModeFmt
index|[
literal|120
index|]
decl_stmt|,
comment|/* mode line format string */
ifdef|#
directive|ifdef
name|UNIX
name|Mailbox
index|[
name|FILESIZE
index|]
decl_stmt|,
comment|/* mailbox name */
endif|#
directive|endif
comment|/* UNIX */
name|TmpFilePath
index|[
name|FILESIZE
index|]
decl_stmt|,
comment|/* directory/device to store tmp files */
name|TagFile
index|[
name|FILESIZE
index|]
decl_stmt|,
comment|/* default tag file */
name|Shell
index|[
name|FILESIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shell to use */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|TOabort
decl_stmt|,
comment|/* flag set by Typeout() */
name|io
decl_stmt|,
comment|/* file descriptor for reading and writing files */
name|errormsg
decl_stmt|,
comment|/* last message was an error message 			   so don't erase the error before it 			   has been read */
name|this_cmd
decl_stmt|,
comment|/* ... */
name|last_cmd
decl_stmt|,
comment|/* last command ... to implement appending 			   to kill buffer */
name|RecDepth
decl_stmt|,
comment|/* recursion depth */
name|InputPending
decl_stmt|,
comment|/* nonzero if there is input waiting to 			   be processed */
name|killptr
decl_stmt|,
comment|/* index into killbuf */
name|CanScroll
decl_stmt|,
comment|/* can this terminal scroll? */
name|Crashing
decl_stmt|,
comment|/* we are in the middle of crashing */
name|Asking
decl_stmt|,
comment|/* are we on read a string from the terminal? */
name|inIOread
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* so we know whether we can do a redisplay. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Minibuf
index|[
name|LBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|curmark
value|(curbuf->b_markring[curbuf->b_themark])
end_define

begin_define
define|#
directive|define
name|b_curmark
parameter_list|(
name|b
parameter_list|)
value|(b->b_markring[b->b_themark])
end_define

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

begin_comment
comment|/* array of pointers to killed stuff */
end_comment

begin_define
define|#
directive|define
name|MESG_SIZE
value|128
end_define

begin_decl_stmt
specifier|extern
name|char
name|mesgbuf
index|[
name|MESG_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|screenline
block|{
name|char
modifier|*
name|s_line
decl_stmt|,
modifier|*
name|s_length
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|LastKeyStruck
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|InMacDefine
decl_stmt|,
comment|/* are we defining a macro right now? */
name|CapLine
decl_stmt|,
comment|/* cursor line and cursor column */
name|CapCol
decl_stmt|,
name|UpdModLine
decl_stmt|,
comment|/* whether we want to update the mode line */
name|UpdMesg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* update the message line */
end_comment

begin_define
define|#
directive|define
name|CATCH
define|\
value|{\ 	jmp_buf	sav_jmp; \ \ 	push_env(sav_jmp); \ 	if (setjmp(mainjmp) == 0) {
end_define

begin_define
define|#
directive|define
name|ONERROR
define|\
value|} else { \  #define ENDCATCH \ 	} \ 	pop_env(sav_jmp); \ }
end_define

begin_include
include|#
directive|include
file|"externs.h"
end_include

end_unit

