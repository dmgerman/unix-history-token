begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)operators.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * Tree node classes.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"operators.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|public
end_ifndef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|numargs
decl_stmt|;
name|char
name|opflags
decl_stmt|;
name|String
name|opstring
decl_stmt|;
block|}
name|Opinfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|O_NOP
block|,
name|O_NAME
block|,
name|O_SYM
block|,
name|O_LCON
block|,
name|O_CCON
block|,
name|O_FCON
block|,
name|O_SCON
block|,
name|O_RVAL
block|,
name|O_INDEX
block|,
name|O_INDIR
block|,
name|O_DOT
block|,
name|O_COMMA
block|,
name|O_ITOF
block|,
name|O_ADD
block|,
name|O_ADDF
block|,
name|O_SUB
block|,
name|O_SUBF
block|,
name|O_NEG
block|,
name|O_NEGF
block|,
name|O_MUL
block|,
name|O_MULF
block|,
name|O_DIVF
block|,
name|O_DIV
block|,
name|O_MOD
block|,
name|O_AND
block|,
name|O_OR
block|,
name|O_LT
block|,
name|O_LTF
block|,
name|O_LE
block|,
name|O_LEF
block|,
name|O_GT
block|,
name|O_GTF
block|,
name|O_GE
block|,
name|O_GEF
block|,
name|O_EQ
block|,
name|O_EQF
block|,
name|O_NE
block|,
name|O_NEF
block|,
name|O_ALIAS
block|,
comment|/* rename a command */
name|O_ASSIGN
block|,
comment|/* assign a value to a program variable */
name|O_CALL
block|,
comment|/* call a procedure in the program */
name|O_CATCH
block|,
comment|/* catch a signal before program does */
name|O_CHFILE
block|,
comment|/* change (or print) the current source file */
name|O_CONT
block|,
comment|/* continue execution */
name|O_DEBUG
block|,
comment|/* invoke a dbx internal debugging routine */
name|O_DELETE
block|,
comment|/* remove a trace/stop */
name|O_DUMP
block|,
comment|/* dump out variables */
name|O_EDIT
block|,
comment|/* edit a file (or function) */
name|O_FUNC
block|,
comment|/* set the current function */
name|O_GRIPE
block|,
comment|/* send mail to debugger support person */
name|O_HELP
block|,
comment|/* print a synopsis of debugger commands */
name|O_IGNORE
block|,
comment|/* let program catch signal */
name|O_LIST
block|,
comment|/* list source lines */
name|O_PRINT
block|,
comment|/* print the values of a list of expressions */
name|O_PSYM
block|,
comment|/* print symbol information */
name|O_RUN
block|,
comment|/* start up program */
name|O_SKIP
block|,
comment|/* skip the current line */
name|O_SOURCE
block|,
comment|/* read commands from a file */
name|O_STATUS
block|,
comment|/* display currently active trace/stop's */
name|O_STEP
block|,
comment|/* execute a single line */
name|O_STOP
block|,
comment|/* stop on an event */
name|O_STOPI
block|,
comment|/* stop on an event at an instruction boundary */
name|O_TRACE
block|,
comment|/* trace something on an event */
name|O_TRACEI
block|,
comment|/* trace at the instruction level */
name|O_WHATIS
block|,
comment|/* print the declaration of a variable */
name|O_WHERE
block|,
comment|/* print a stack trace */
name|O_WHEREIS
block|,
comment|/* print all the symbols with the given name */
name|O_WHICH
block|,
comment|/* print out full qualification of a symbol */
name|O_EXAMINE
block|,
comment|/* examine program instructions/data */
name|O_ADDEVENT
block|,
comment|/* add an event */
name|O_ENDX
block|,
comment|/* end of program reached */
name|O_IF
block|,
comment|/* if first arg is true, do commands in second arg */
name|O_ONCE
block|,
comment|/* add a "one-time" event, delete when first reached */
name|O_PRINTCALL
block|,
comment|/* print out the current procedure and its arguments */
name|O_PRINTIFCHANGED
block|,
comment|/* print the value of the argument if it has changed */
name|O_PRINTRTN
block|,
comment|/* print out the routine and value that just returned */
name|O_PRINTSRCPOS
block|,
comment|/* print out the current source position */
name|O_PROCRTN
block|,
comment|/* call completed */
name|O_QLINE
block|,
comment|/* filename, line number */
name|O_STOPIFCHANGED
block|,
comment|/* stop if the value of the argument has changed */
name|O_STOPX
block|,
comment|/* stop execution */
name|O_TRACEON
block|,
comment|/* begin tracing source line, variable, or all lines */
name|O_TRACEOFF
block|,
comment|/* end tracing source line, variable, or all lines */
name|O_TYPERENAME
block|,
comment|/* state the type of an expression */
name|O_RERUN
block|,
comment|/* re-run program with the same arguments as before */
name|O_RETURN
block|,
comment|/* continue execution until procedure returns */
name|O_UP
block|,
comment|/* move current function up the call stack */
name|O_DOWN
block|,
comment|/* move current function down the call stack */
name|O_CALLPROC
block|,
comment|/* call command */
name|O_SEARCH
block|,
comment|/* regular expression pattern search through source */
name|O_SET
block|,
comment|/* set a debugger variable */
name|O_UNSET
block|,
comment|/* unset a debugger variable */
name|O_UNALIAS
block|,
comment|/* remove an alias */
name|O_LASTOP
block|}
name|Operator
typedef|;
end_typedef

begin_comment
comment|/*  * Operator flags and predicates.  */
end_comment

begin_define
define|#
directive|define
name|null
value|0
end_define

begin_define
define|#
directive|define
name|LEAF
value|01
end_define

begin_define
define|#
directive|define
name|UNARY
value|02
end_define

begin_define
define|#
directive|define
name|BINARY
value|04
end_define

begin_define
define|#
directive|define
name|BOOL
value|010
end_define

begin_define
define|#
directive|define
name|REALOP
value|020
end_define

begin_define
define|#
directive|define
name|INTOP
value|040
end_define

begin_define
define|#
directive|define
name|isbitset
parameter_list|(
name|a
parameter_list|,
name|m
parameter_list|)
value|((a&m) == m)
end_define

begin_define
define|#
directive|define
name|isleaf
parameter_list|(
name|o
parameter_list|)
value|isbitset(opinfo[ord(o)].opflags, LEAF)
end_define

begin_define
define|#
directive|define
name|isunary
parameter_list|(
name|o
parameter_list|)
value|isbitset(opinfo[ord(o)].opflags, UNARY)
end_define

begin_define
define|#
directive|define
name|isbinary
parameter_list|(
name|o
parameter_list|)
value|isbitset(opinfo[ord(o)].opflags, BINARY)
end_define

begin_define
define|#
directive|define
name|isreal
parameter_list|(
name|o
parameter_list|)
value|isbitset(opinfo[ord(o)].opflags, REALOP)
end_define

begin_define
define|#
directive|define
name|isint
parameter_list|(
name|o
parameter_list|)
value|isbitset(opinfo[ord(o)].opflags, INTOP)
end_define

begin_define
define|#
directive|define
name|isboolean
parameter_list|(
name|o
parameter_list|)
value|isbitset(opinfo[ord(o)].opflags, BOOL)
end_define

begin_define
define|#
directive|define
name|degree
parameter_list|(
name|o
parameter_list|)
value|(opinfo[ord(o)].opflags&(LEAF|UNARY|BINARY))
end_define

begin_define
define|#
directive|define
name|nargs
parameter_list|(
name|o
parameter_list|)
value|(opinfo[ord(o)].numargs)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Operator information structure.  */
end_comment

begin_decl_stmt
name|public
name|Opinfo
name|opinfo
index|[]
init|=
block|{
comment|/* O_NOP */
literal|0
block|,
name|null
block|,
literal|0
block|,
comment|/* O_NAME */
operator|-
literal|1
block|,
name|LEAF
block|,
literal|0
block|,
comment|/* O_SYM */
operator|-
literal|1
block|,
name|LEAF
block|,
literal|0
block|,
comment|/* O_LCON */
operator|-
literal|1
block|,
name|LEAF
block|,
literal|0
block|,
comment|/* O_CCON */
operator|-
literal|1
block|,
name|LEAF
block|,
literal|0
block|,
comment|/* O_FCON */
operator|-
literal|1
block|,
name|LEAF
block|,
literal|0
block|,
comment|/* O_SCON */
operator|-
literal|1
block|,
name|LEAF
block|,
literal|0
block|,
comment|/* O_RVAL */
literal|1
block|,
name|UNARY
block|,
literal|0
block|,
comment|/* O_INDEX */
literal|2
block|,
name|null
block|,
literal|0
block|,
comment|/* O_INDIR */
literal|1
block|,
name|UNARY
block|,
literal|"^"
block|,
comment|/* O_DOT */
literal|2
block|,
name|null
block|,
literal|"."
block|,
comment|/* O_COMMA */
literal|2
block|,
name|null
block|,
literal|","
block|,
comment|/* O_ITOF */
literal|1
block|,
name|UNARY
operator||
name|INTOP
block|,
literal|0
block|,
comment|/* O_ADD */
literal|2
block|,
name|BINARY
operator||
name|INTOP
block|,
literal|"+"
block|,
comment|/* O_ADDF */
literal|2
block|,
name|BINARY
operator||
name|REALOP
block|,
literal|"+"
block|,
comment|/* O_SUB */
literal|2
block|,
name|BINARY
operator||
name|INTOP
block|,
literal|"-"
block|,
comment|/* O_SUBF */
literal|2
block|,
name|BINARY
operator||
name|REALOP
block|,
literal|"-"
block|,
comment|/* O_NEG */
literal|1
block|,
name|UNARY
operator||
name|INTOP
block|,
literal|"-"
block|,
comment|/* O_NEGF */
literal|1
block|,
name|UNARY
operator||
name|REALOP
block|,
literal|"-"
block|,
comment|/* O_MUL */
literal|2
block|,
name|BINARY
operator||
name|INTOP
block|,
literal|"*"
block|,
comment|/* O_MULF */
literal|2
block|,
name|BINARY
operator||
name|REALOP
block|,
literal|"*"
block|,
comment|/* O_DIVF */
literal|2
block|,
name|BINARY
operator||
name|REALOP
block|,
literal|"/"
block|,
comment|/* O_DIV */
literal|2
block|,
name|BINARY
operator||
name|INTOP
block|,
literal|" div "
block|,
comment|/* O_MOD */
literal|2
block|,
name|BINARY
operator||
name|INTOP
block|,
literal|" mod "
block|,
comment|/* O_AND */
literal|2
block|,
name|BINARY
operator||
name|INTOP
block|,
literal|" and "
block|,
comment|/* O_OR */
literal|2
block|,
name|BINARY
operator||
name|INTOP
block|,
literal|" or "
block|,
comment|/* O_LT */
literal|2
block|,
name|BINARY
operator||
name|INTOP
block|,
literal|"< "
block|,
comment|/* O_LTF */
literal|2
block|,
name|BINARY
operator||
name|REALOP
block|,
literal|"< "
block|,
comment|/* O_LE */
literal|2
block|,
name|BINARY
operator||
name|INTOP
block|,
literal|"<= "
block|,
comment|/* O_LEF */
literal|2
block|,
name|BINARY
operator||
name|REALOP
block|,
literal|"<= "
block|,
comment|/* O_GT */
literal|2
block|,
name|BINARY
operator||
name|INTOP
block|,
literal|"> "
block|,
comment|/* O_GTF */
literal|2
block|,
name|BINARY
operator||
name|REALOP
block|,
literal|"> "
block|,
comment|/* O_GE */
literal|2
block|,
name|BINARY
operator||
name|INTOP
block|,
literal|">= "
block|,
comment|/* O_GEF */
literal|2
block|,
name|BINARY
operator||
name|REALOP
block|,
literal|">= "
block|,
comment|/* O_EQ */
literal|2
block|,
name|BINARY
operator||
name|INTOP
block|,
literal|" = "
block|,
comment|/* O_EQF */
literal|2
block|,
name|BINARY
operator||
name|REALOP
block|,
literal|" = "
block|,
comment|/* O_NE */
literal|2
block|,
name|BINARY
operator||
name|INTOP
block|,
literal|"<> "
block|,
comment|/* O_NEF */
literal|2
block|,
name|BINARY
operator||
name|REALOP
block|,
literal|"<> "
block|,
comment|/* O_ALIAS */
literal|2
block|,
name|null
block|,
literal|"alias"
block|,
comment|/* O_ASSIGN */
literal|2
block|,
name|null
block|,
literal|" := "
block|,
comment|/* O_CALL */
literal|2
block|,
name|null
block|,
literal|"call"
block|,
comment|/* O_CATCH */
literal|0
block|,
name|null
block|,
literal|"catch"
block|,
comment|/* O_CHFILE */
literal|0
block|,
name|null
block|,
literal|"file"
block|,
comment|/* O_CONT */
literal|0
block|,
name|null
block|,
literal|"cont"
block|,
comment|/* O_DEBUG */
literal|0
block|,
name|null
block|,
literal|"debug"
block|,
comment|/* O_DELETE */
literal|1
block|,
name|null
block|,
literal|"delete"
block|,
comment|/* O_DUMP */
literal|1
block|,
name|null
block|,
literal|"dump"
block|,
comment|/* O_EDIT */
literal|0
block|,
name|null
block|,
literal|"edit"
block|,
comment|/* O_FUNC */
literal|1
block|,
name|null
block|,
literal|"func"
block|,
comment|/* O_GRIPE */
literal|0
block|,
name|null
block|,
literal|"gripe"
block|,
comment|/* O_HELP */
literal|0
block|,
name|null
block|,
literal|"help"
block|,
comment|/* O_IGNORE */
literal|0
block|,
name|null
block|,
literal|"ignore"
block|,
comment|/* O_LIST */
literal|2
block|,
name|null
block|,
literal|"list"
block|,
comment|/* O_PRINT */
literal|1
block|,
name|null
block|,
literal|"print"
block|,
comment|/* O_PSYM */
literal|1
block|,
name|null
block|,
literal|"psym"
block|,
comment|/* O_RUN */
literal|0
block|,
name|null
block|,
literal|"run"
block|,
comment|/* O_SKIP */
literal|0
block|,
name|null
block|,
literal|"skip"
block|,
comment|/* O_SOURCE */
literal|0
block|,
name|null
block|,
literal|"source"
block|,
comment|/* O_STATUS */
literal|0
block|,
name|null
block|,
literal|"status"
block|,
comment|/* O_STEP */
literal|0
block|,
name|null
block|,
literal|"step"
block|,
comment|/* O_STOP */
literal|3
block|,
name|null
block|,
literal|"stop"
block|,
comment|/* O_STOPI */
literal|3
block|,
name|null
block|,
literal|"stopi"
block|,
comment|/* O_TRACE */
literal|3
block|,
name|null
block|,
literal|"trace"
block|,
comment|/* O_TRACEI */
literal|3
block|,
name|null
block|,
literal|"tracei"
block|,
comment|/* O_WHATIS */
literal|1
block|,
name|null
block|,
literal|"whatis"
block|,
comment|/* O_WHERE */
literal|0
block|,
name|null
block|,
literal|"where"
block|,
comment|/* O_WHEREIS */
literal|1
block|,
name|null
block|,
literal|"whereis"
block|,
comment|/* O_WHICH */
literal|1
block|,
name|null
block|,
literal|"which"
block|,
comment|/* O_EXAMINE */
literal|0
block|,
name|null
block|,
literal|"examine"
block|,
comment|/* O_ADDEVENT */
literal|0
block|,
name|null
block|,
literal|"when"
block|,
comment|/* O_ENDX */
literal|0
block|,
name|null
block|,
name|nil
block|,
comment|/* O_IF */
literal|0
block|,
name|null
block|,
literal|"if"
block|,
comment|/* O_ONCE */
literal|0
block|,
name|null
block|,
literal|"once"
block|,
comment|/* O_PRINTCALL */
literal|1
block|,
name|null
block|,
literal|"printcall"
block|,
comment|/* O_PRINTIFCHANGED */
literal|1
block|,
name|null
block|,
literal|"printifchanged"
block|,
comment|/* O_PRINTRTN */
literal|1
block|,
name|null
block|,
literal|"printrtn"
block|,
comment|/* O_PRINTSRCPOS */
literal|1
block|,
name|null
block|,
literal|"printsrcpos"
block|,
comment|/* O_PROCRTN */
literal|1
block|,
name|null
block|,
literal|"procrtn"
block|,
comment|/* O_QLINE */
literal|2
block|,
name|null
block|,
name|nil
block|,
comment|/* O_STOPIFCHANGED */
literal|1
block|,
name|null
block|,
literal|"stopifchanged"
block|,
comment|/* O_STOPX */
literal|0
block|,
name|null
block|,
literal|"stop"
block|,
comment|/* O_TRACEON */
literal|1
block|,
name|null
block|,
literal|"traceon"
block|,
comment|/* O_TRACEOFF */
literal|1
block|,
name|null
block|,
literal|"traceoff"
block|,
comment|/* O_TYPERENAME */
literal|2
block|,
name|UNARY
block|,
literal|"type rename"
block|,
comment|/* O_RERUN */
literal|0
block|,
name|null
block|,
literal|"rerun"
block|,
comment|/* O_RETURN */
literal|1
block|,
name|null
block|,
literal|"return"
block|,
comment|/* O_UP */
literal|1
block|,
name|UNARY
block|,
literal|"up"
block|,
comment|/* O_DOWN */
literal|1
block|,
name|UNARY
block|,
literal|"down"
block|,
comment|/* O_CALLPROC */
literal|2
block|,
name|null
block|,
literal|"call"
block|,
comment|/* O_SEARCH */
literal|2
block|,
name|null
block|,
literal|"search"
block|,
comment|/* O_SET */
literal|2
block|,
name|null
block|,
literal|"set"
block|,
comment|/* O_UNSET */
literal|1
block|,
name|null
block|,
literal|"unset"
block|,
comment|/* O_UNALIAS */
literal|1
block|,
name|null
block|,
literal|"unalias"
block|, }
decl_stmt|;
end_decl_stmt

end_unit

