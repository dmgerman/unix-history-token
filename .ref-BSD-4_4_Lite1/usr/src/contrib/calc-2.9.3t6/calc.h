begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  *  * Definitions for calculator program.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CALC_H
end_ifndef

begin_define
define|#
directive|define
name|CALC_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|"value.h"
end_include

begin_comment
comment|/*  * Configuration definitions  */
end_comment

begin_define
define|#
directive|define
name|CALCPATH
value|"CALCPATH"
end_define

begin_comment
comment|/* environment variable for files */
end_comment

begin_define
define|#
directive|define
name|CALCRC
value|"CALCRC"
end_define

begin_comment
comment|/* environment variable for startup */
end_comment

begin_define
define|#
directive|define
name|CALCBINDINGS
value|"CALCBINDINGS"
end_define

begin_comment
comment|/* environment variable for hist bindings */
end_comment

begin_define
define|#
directive|define
name|HOME
value|"HOME"
end_define

begin_comment
comment|/* environment variable for home dir */
end_comment

begin_define
define|#
directive|define
name|PAGER
value|"PAGER"
end_define

begin_comment
comment|/* environment variable for help */
end_comment

begin_define
define|#
directive|define
name|SHELL
value|"SHELL"
end_define

begin_comment
comment|/* environment variable for shell */
end_comment

begin_define
define|#
directive|define
name|DEFAULTCALCHELP
value|"help"
end_define

begin_comment
comment|/* help file that -h prints */
end_comment

begin_define
define|#
directive|define
name|DEFAULTSHELL
value|"sh"
end_define

begin_comment
comment|/* default shell to use */
end_comment

begin_define
define|#
directive|define
name|CALCEXT
value|".cal"
end_define

begin_comment
comment|/* extension for files read in */
end_comment

begin_define
define|#
directive|define
name|PATHSIZE
value|1024
end_define

begin_comment
comment|/* maximum length of path name */
end_comment

begin_define
define|#
directive|define
name|HOMECHAR
value|'~'
end_define

begin_comment
comment|/* char which indicates home directory */
end_comment

begin_define
define|#
directive|define
name|DOTCHAR
value|'.'
end_define

begin_comment
comment|/* char which indicates current directory */
end_comment

begin_define
define|#
directive|define
name|PATHCHAR
value|'/'
end_define

begin_comment
comment|/* char which separates path components */
end_comment

begin_define
define|#
directive|define
name|LISTCHAR
value|':'
end_define

begin_comment
comment|/* char which separates paths in a list */
end_comment

begin_define
define|#
directive|define
name|MAXCMD
value|1024
end_define

begin_comment
comment|/* maximum length of command invocation */
end_comment

begin_define
define|#
directive|define
name|MAXERROR
value|512
end_define

begin_comment
comment|/* maximum length of error message string */
end_comment

begin_define
define|#
directive|define
name|SYMBOLSIZE
value|256
end_define

begin_comment
comment|/* maximum symbol name size */
end_comment

begin_define
define|#
directive|define
name|MAXINDICES
value|20
end_define

begin_comment
comment|/* maximum number of indices for objects */
end_comment

begin_define
define|#
directive|define
name|MAXLABELS
value|100
end_define

begin_comment
comment|/* maximum number of user labels in function */
end_comment

begin_define
define|#
directive|define
name|MAXOBJECTS
value|10
end_define

begin_comment
comment|/* maximum number of object types */
end_comment

begin_define
define|#
directive|define
name|MAXSTRING
value|1024
end_define

begin_comment
comment|/* maximum size of string constant */
end_comment

begin_define
define|#
directive|define
name|MAXSTACK
value|1000
end_define

begin_comment
comment|/* maximum depth of evaluation stack */
end_comment

begin_define
define|#
directive|define
name|MAXFILES
value|20
end_define

begin_comment
comment|/* maximum number of opened files */
end_comment

begin_define
define|#
directive|define
name|PROMPT1
value|"> "
end_define

begin_comment
comment|/* normal prompt */
end_comment

begin_define
define|#
directive|define
name|PROMPT2
value|">> "
end_define

begin_comment
comment|/* prompt when inside multi-line input */
end_comment

begin_define
define|#
directive|define
name|TRACE_NORMAL
value|0x00
end_define

begin_comment
comment|/* normal trace flags */
end_comment

begin_define
define|#
directive|define
name|TRACE_OPCODES
value|0x01
end_define

begin_comment
comment|/* trace every opcode */
end_comment

begin_define
define|#
directive|define
name|TRACE_NODEBUG
value|0x02
end_define

begin_comment
comment|/* suppress debugging opcodes */
end_comment

begin_define
define|#
directive|define
name|TRACE_MAX
value|0x03
end_define

begin_comment
comment|/* maximum value for trace flag */
end_comment

begin_define
define|#
directive|define
name|DISPLAY_DEFAULT
value|20
end_define

begin_comment
comment|/* default digits for float display */
end_comment

begin_define
define|#
directive|define
name|EPSILON_DEFAULT
value|"1e-20"
end_define

begin_comment
comment|/* allowed error for float calculations */
end_comment

begin_define
define|#
directive|define
name|MAXPRINT_DEFAULT
value|16
end_define

begin_comment
comment|/* default number of elements printed */
end_comment

begin_define
define|#
directive|define
name|ABORT_NONE
value|0
end_define

begin_comment
comment|/* abort not needed yet */
end_comment

begin_define
define|#
directive|define
name|ABORT_STATEMENT
value|1
end_define

begin_comment
comment|/* abort on statement boundary */
end_comment

begin_define
define|#
directive|define
name|ABORT_OPCODE
value|2
end_define

begin_comment
comment|/* abort on any opcode boundary */
end_comment

begin_define
define|#
directive|define
name|ABORT_MATH
value|3
end_define

begin_comment
comment|/* abort on any math operation */
end_comment

begin_define
define|#
directive|define
name|ABORT_NOW
value|4
end_define

begin_comment
comment|/* abort right away */
end_comment

begin_define
define|#
directive|define
name|CONFIG_MODE
value|1
end_define

begin_comment
comment|/* types of configuration parameters */
end_comment

begin_define
define|#
directive|define
name|CONFIG_DISPLAY
value|2
end_define

begin_define
define|#
directive|define
name|CONFIG_EPSILON
value|3
end_define

begin_define
define|#
directive|define
name|CONFIG_TRACE
value|4
end_define

begin_define
define|#
directive|define
name|CONFIG_MAXPRINT
value|5
end_define

begin_define
define|#
directive|define
name|CONFIG_MUL2
value|6
end_define

begin_define
define|#
directive|define
name|CONFIG_SQ2
value|7
end_define

begin_define
define|#
directive|define
name|CONFIG_POW2
value|8
end_define

begin_define
define|#
directive|define
name|CONFIG_REDC2
value|9
end_define

begin_define
define|#
directive|define
name|CONFIG_TILDE
value|10
end_define

begin_define
define|#
directive|define
name|CONFIG_TAB
value|11
end_define

begin_comment
comment|/*  * File ids corresponding to standard in, out, error, and when not in use.  */
end_comment

begin_define
define|#
directive|define
name|FILEID_STDIN
value|((FILEID) 0)
end_define

begin_define
define|#
directive|define
name|FILEID_STDOUT
value|((FILEID) 1)
end_define

begin_define
define|#
directive|define
name|FILEID_STDERR
value|((FILEID) 2)
end_define

begin_define
define|#
directive|define
name|FILEID_NONE
value|((FILEID) -1)
end_define

begin_comment
comment|/*  * File I/O routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILEID
name|openid
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILEID
name|indexid
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|validid
name|MATH_PROTO
argument_list|(
operator|(
name|FILEID
name|id
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|errorid
name|MATH_PROTO
argument_list|(
operator|(
name|FILEID
name|id
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|eofid
name|MATH_PROTO
argument_list|(
operator|(
name|FILEID
name|id
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|closeid
name|MATH_PROTO
argument_list|(
operator|(
name|FILEID
name|id
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getcharid
name|MATH_PROTO
argument_list|(
operator|(
name|FILEID
name|id
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|idprintf
name|MATH_PROTO
argument_list|(
operator|(
name|FILEID
name|id
operator|,
name|char
operator|*
name|fmt
operator|,
name|int
name|count
operator|,
name|VALUE
operator|*
operator|*
name|vals
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|printid
name|MATH_PROTO
argument_list|(
operator|(
name|FILEID
name|id
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flushid
name|MATH_PROTO
argument_list|(
operator|(
name|FILEID
name|id
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|readid
name|MATH_PROTO
argument_list|(
operator|(
name|FILEID
name|id
operator|,
name|char
operator|*
operator|*
name|retptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Input routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|f_open
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|openstring
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|openterminal
name|MATH_PROTO
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
name|opensearchfile
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|pathlist
operator|,
name|char
operator|*
name|exten
operator|,
name|int
name|reopen_ok
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|nextline
name|MATH_PROTO
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
name|nextchar
name|MATH_PROTO
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
name|reread
name|MATH_PROTO
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
name|resetinput
name|MATH_PROTO
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
name|setprompt
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|inputisterminal
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|inputname
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|linenumber
name|MATH_PROTO
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
name|runrcfiles
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Other routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|NUMBER
modifier|*
name|constvalue
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|addnumber
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|addqconstant
name|MATH_PROTO
argument_list|(
operator|(
name|NUMBER
operator|*
name|q
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|initstack
name|MATH_PROTO
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
name|version
name|MATH_PROTO
argument_list|(
operator|(
name|FILE
operator|*
name|stream
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|getcommands
name|MATH_PROTO
argument_list|(
operator|(
name|BOOL
name|toplevel
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|givehelp
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|getconfig
name|MATH_PROTO
argument_list|(
operator|(
name|int
name|type
operator|,
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setconfig
name|MATH_PROTO
argument_list|(
operator|(
name|int
name|type
operator|,
name|VALUE
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|configtype
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Global data definitions.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|maxprint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of elements to print */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|abortlevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current level of aborts */
end_comment

begin_decl_stmt
specifier|extern
name|BOOL
name|inputwait
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if in a terminal input wait */
end_comment

begin_decl_stmt
specifier|extern
name|FLAG
name|traceflags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tracing flags */
end_comment

begin_decl_stmt
specifier|extern
name|VALUE
modifier|*
name|stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* execution stack */
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
name|jmpbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for errors */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|calcpath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $CALCPATH or default */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|calcrc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $CALCRC or default */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|calcbindings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $CALCBINDINGS or default */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|home
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $HOME or default */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|shell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $SHELL or default */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END CODE */
end_comment

end_unit

