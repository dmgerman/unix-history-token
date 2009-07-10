begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /p/tcsh/cvsroot/tcsh/ed.h,v 3.49 2006/08/23 15:03:13 christos Exp $ */
end_comment

begin_comment
comment|/*  * ed.h: Editor declarations and globals  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_ed
end_ifndef

begin_define
define|#
directive|define
name|_h_ed
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|EXTERN
end_ifndef

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXMACROLEVELS
value|10
end_define

begin_comment
comment|/* max number of nested kbd macros */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WINNT_NATIVE
end_ifndef

begin_define
define|#
directive|define
name|NT_NUM_KEYS
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINNT_NATIVE */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* stuff for the different states returned by the character editor routines */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CCRETVAL
value|char
end_define

begin_comment
comment|/* size needed for the different char editor */
end_comment

begin_comment
comment|/* return values */
end_comment

begin_define
define|#
directive|define
name|KEYCMD
value|unsigned char
end_define

begin_comment
comment|/* size needed to index into CcFuncTbl */
end_comment

begin_comment
comment|/* Must be unsigned 		       */
end_comment

begin_typedef
typedef|typedef
name|CCRETVAL
function_decl|(
modifier|*
name|PFCmd
function_decl|)
parameter_list|(
name|Char
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* pointer to function returning CCRETVAL */
end_comment

begin_struct
struct|struct
name|KeyFuncs
block|{
comment|/* for the "bind" shell command */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* function name for bind command */
name|int
name|func
decl_stmt|;
comment|/* function numeric value */
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* description of function */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|PFCmd
name|CcFuncTbl
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table of available commands */
end_comment

begin_decl_stmt
specifier|extern
name|KEYCMD
name|CcKeyMap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keymap table, each index into above tbl */
end_comment

begin_decl_stmt
specifier|extern
name|KEYCMD
name|CcAltMap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Alt keymap table */
end_comment

begin_decl_stmt
specifier|extern
name|KEYCMD
name|CcEmacsMap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keymap table for Emacs default bindings */
end_comment

begin_decl_stmt
specifier|extern
name|KEYCMD
name|CcViCmdMap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for Vi command mode defaults */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|KeyFuncs
name|FuncNames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string names vs. CcFuncTbl indices */
end_comment

begin_decl_stmt
specifier|extern
name|KEYCMD
name|NumFuns
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of KEYCMDs in above table */
end_comment

begin_define
define|#
directive|define
name|CC_ERROR
value|100
end_define

begin_comment
comment|/* there should NOT be 100 different... */
end_comment

begin_define
define|#
directive|define
name|CC_FATAL
value|101
end_define

begin_comment
comment|/* fatal error: inconsistant, must 					 * reset */
end_comment

begin_define
define|#
directive|define
name|CC_NORM
value|0
end_define

begin_define
define|#
directive|define
name|CC_NEWLINE
value|1
end_define

begin_define
define|#
directive|define
name|CC_EOF
value|2
end_define

begin_define
define|#
directive|define
name|CC_COMPLETE
value|3
end_define

begin_define
define|#
directive|define
name|CC_LIST_CHOICES
value|4
end_define

begin_define
define|#
directive|define
name|CC_LIST_GLOB
value|5
end_define

begin_define
define|#
directive|define
name|CC_EXPAND_GLOB
value|6
end_define

begin_define
define|#
directive|define
name|CC_HELPME
value|9
end_define

begin_define
define|#
directive|define
name|CC_CORRECT
value|10
end_define

begin_define
define|#
directive|define
name|CC_WHICH
value|11
end_define

begin_define
define|#
directive|define
name|CC_ARGHACK
value|12
end_define

begin_define
define|#
directive|define
name|CC_CORRECT_L
value|13
end_define

begin_define
define|#
directive|define
name|CC_REFRESH
value|14
end_define

begin_define
define|#
directive|define
name|CC_EXPAND_VARS
value|15
end_define

begin_define
define|#
directive|define
name|CC_NORMALIZE_PATH
value|16
end_define

begin_define
define|#
directive|define
name|CC_LIST_ALL
value|17
end_define

begin_define
define|#
directive|define
name|CC_COMPLETE_ALL
value|18
end_define

begin_define
define|#
directive|define
name|CC_COMPLETE_FWD
value|19
end_define

begin_define
define|#
directive|define
name|CC_COMPLETE_BACK
value|20
end_define

begin_define
define|#
directive|define
name|CC_NORMALIZE_COMMAND
value|21
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Char
modifier|*
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
name|CStr
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
comment|/* value passed to the Xkey routines */
name|KEYCMD
name|cmd
decl_stmt|;
name|CStr
name|str
decl_stmt|;
block|}
name|XmapVal
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XK_NOD
value|-1
end_define

begin_comment
comment|/* Internal tree node */
end_comment

begin_define
define|#
directive|define
name|XK_CMD
value|0
end_define

begin_comment
comment|/* X-key was an editor command */
end_comment

begin_define
define|#
directive|define
name|XK_STR
value|1
end_define

begin_comment
comment|/* X-key was a string macro */
end_comment

begin_define
define|#
directive|define
name|XK_EXE
value|2
end_define

begin_comment
comment|/* X-key was a unix command */
end_comment

begin_comment
comment|/****************************/
end_comment

begin_comment
comment|/* Editor state and buffers */
end_comment

begin_comment
comment|/****************************/
end_comment

begin_decl_stmt
name|EXTERN
name|KEYCMD
modifier|*
name|CurrentKeyMap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current command key map */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|inputmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* insert, replace, replace1 mode */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|GettingInput
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if getting an input line (mostly) */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|NeedsRedraw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for editor and twenex error messages */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|InputBuf
index|[
name|INBUFSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the real input data */
end_comment

begin_comment
comment|/*FIXBUF*/
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|LastChar
decl_stmt|,
modifier|*
name|Cursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* point to the next open space */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|InputLim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* limit of size of InputBuf */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|MetaNext
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flags for ^V and ^[ functions */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|AltKeyMap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Using alternative command map (for vi mode) */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|VImode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if running in vi mode (PWP 6-27-88) */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|Mark
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the emacs "mark" (dot is Cursor) */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|MarkIsSet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if the mark has been set explicitly */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|DoingArg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if we have an argument */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|Argument
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "universal" argument value */
end_comment

begin_decl_stmt
name|EXTERN
name|KEYCMD
name|LastCmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* previous command executed */
end_comment

begin_decl_stmt
name|EXTERN
name|CStr
modifier|*
name|KillRing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kill ring */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|KillRingMax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max length of kill ring */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|KillRingLen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current length of kill ring */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|KillPos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* points to next kill */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|YankPos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* points to next yank */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|UndoBuf
index|[
name|INBUFSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*FIXBUF*/
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|UndoPtr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|UndoSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|UndoAction
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|struct
name|Strbuf
name|HistBuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* = Strbuf_INIT; history buffer */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|Hist_num
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* what point up the history we are at now. */
end_comment

begin_comment
comment|/* buffer for which command and others */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|Strbuf
name|SavedBuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* = Strbuf_INIT; */
end_comment

begin_decl_stmt
name|EXTERN
name|size_t
name|LastSaved
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* points to end of saved buffer */
end_comment

begin_decl_stmt
name|EXTERN
name|size_t
name|CursSaved
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* points to the cursor point in saved buf */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|HistSaved
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hist_num is saved in this */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|RestoreSaved
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if SavedBuf should be restored */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|IncMatchLen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current match length during incremental search */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|Expand
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if we are expanding a line */
end_comment

begin_decl_stmt
specifier|extern
name|Char
name|HistLit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if history lines are shown literal */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|CurrentHistLit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Literal status of current show history line */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Tty_raw_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * These are truly extern  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|MacroLvl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Char
modifier|*
name|litptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Entries start at offsets divisible by LIT_FACTOR */
end_comment

begin_define
define|#
directive|define
name|LIT_FACTOR
value|4
end_define

begin_decl_stmt
specifier|extern
name|int
name|didsetty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
name|KeyMacro
index|[
name|MAXMACROLEVELS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CHAR_DBWIDTH in Display and Vdisplay means the non-first column of a character    that is wider than one "regular" position. The cursor should never point    in the middle of a multiple-column character. */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
modifier|*
name|Display
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* display buffer seed vector */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|CursorV
decl_stmt|,
comment|/* real cursor vertical (line) */
name|CursorH
decl_stmt|,
comment|/* real cursor horisontal (column) */
name|TermV
decl_stmt|,
comment|/* number of real screen lines 				 * (sizeof(DisplayBuf) / width */
name|TermH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* screen width */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
modifier|*
modifier|*
name|Vdisplay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* new buffer */
end_comment

begin_comment
comment|/* Variables that describe terminal ability */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|T_Lines
decl_stmt|,
name|T_Cols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Rows and Cols of the terminal */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|T_CanIns
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if I can insert characters */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|T_CanDel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dito for delete characters */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|T_Tabs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if tty interface is passing tabs */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|T_Margin
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MARGIN_AUTO
value|1
end_define

begin_comment
comment|/* term has auto margins */
end_comment

begin_define
define|#
directive|define
name|MARGIN_MAGIC
value|2
end_define

begin_comment
comment|/* concept glitch */
end_comment

begin_decl_stmt
name|EXTERN
name|speed_t
name|T_Speed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tty input Baud rate */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|T_CanCEOL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if we can clear to end of line */
end_comment

begin_decl_stmt
name|EXTERN
name|Char
name|T_CanUP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if this term can do reverse linefeen */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|T_HasMeta
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if we have a meta key */
end_comment

begin_comment
comment|/* note the extra characters in the Strchr() call in this macro */
end_comment

begin_define
define|#
directive|define
name|isword
parameter_list|(
name|c
parameter_list|)
value|(Isalpha(c)||Isdigit(c)||Strchr(word_chars,c))
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)<(y))?(x):(y))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)>(y))?(x):(y))
end_define

begin_define
define|#
directive|define
name|MODE_INSERT
value|0
end_define

begin_define
define|#
directive|define
name|MODE_REPLACE
value|1
end_define

begin_define
define|#
directive|define
name|MODE_REPLACE_1
value|2
end_define

begin_define
define|#
directive|define
name|EX_IO
value|0
end_define

begin_comment
comment|/* while we are executing	*/
end_comment

begin_define
define|#
directive|define
name|ED_IO
value|1
end_define

begin_comment
comment|/* while we are editing		*/
end_comment

begin_define
define|#
directive|define
name|TS_IO
value|2
end_define

begin_comment
comment|/* new mode from terminal	*/
end_comment

begin_define
define|#
directive|define
name|QU_IO
value|2
end_define

begin_comment
comment|/* used only for quoted chars	*/
end_comment

begin_define
define|#
directive|define
name|NN_IO
value|3
end_define

begin_comment
comment|/* The number of entries	*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|POSIX
argument_list|)
operator|||
name|defined
argument_list|(
name|TERMIO
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_INPUT
value|0
end_define

begin_define
define|#
directive|define
name|M_OUTPUT
value|1
end_define

begin_define
define|#
directive|define
name|M_CONTROL
value|2
end_define

begin_define
define|#
directive|define
name|M_LINED
value|3
end_define

begin_define
define|#
directive|define
name|M_CHAR
value|4
end_define

begin_define
define|#
directive|define
name|M_NN
value|5
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* GSTTY */
end_comment

begin_define
define|#
directive|define
name|M_CONTROL
value|0
end_define

begin_define
define|#
directive|define
name|M_LOCAL
value|1
end_define

begin_define
define|#
directive|define
name|M_CHAR
value|2
end_define

begin_define
define|#
directive|define
name|M_NN
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TERMIO */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|t_name
decl_stmt|;
name|unsigned
name|int
name|t_setmask
decl_stmt|;
name|unsigned
name|int
name|t_clrmask
decl_stmt|;
block|}
name|ttyperm_t
index|[
name|NN_IO
index|]
index|[
name|M_NN
index|]
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ttyperm_t
name|ttylist
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"ed.term.h"
end_include

begin_include
include|#
directive|include
file|"ed.decls.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|POSIX
end_ifndef

begin_comment
comment|/*  * We don't prototype these, cause some systems have them wrong!  */
end_comment

begin_function_decl
specifier|extern
name|int
name|tgetent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tgetstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tgetflag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tgetnum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tgoto
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PUTPURE
value|putpure
end_define

begin_define
define|#
directive|define
name|PUTRAW
value|putraw
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|int
name|tgetent
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tgetstr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tgetflag
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tgetnum
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tgoto
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tputs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PUTPURE
value|((void (*)(int)) putpure)
end_define

begin_define
define|#
directive|define
name|PUTRAW
value|((void (*)(int)) putraw)
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
comment|/* _h_ed */
end_comment

end_unit

