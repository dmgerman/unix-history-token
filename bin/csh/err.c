begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_else
unit|static char sccsid[] = "@(#)err.c	8.1 (Berkeley) 5/31/93";
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: err.c,v 1.5 1997/08/07 21:42:06 steve Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"csh.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|seterr
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Holds last error if there was one */
end_comment

begin_define
define|#
directive|define
name|ERR_FLAGS
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|ERR_NAME
value|0x10000000
end_define

begin_define
define|#
directive|define
name|ERR_SILENT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|ERR_OLD
value|0x40000000
end_define

begin_decl_stmt
specifier|static
name|char
modifier|*
name|errorlist
index|[]
init|=
block|{
define|#
directive|define
name|ERR_SYNTAX
value|0
literal|"Syntax Error"
block|,
define|#
directive|define
name|ERR_NOTALLOWED
value|1
literal|"%s is not allowed"
block|,
define|#
directive|define
name|ERR_WTOOLONG
value|2
literal|"Word too long"
block|,
define|#
directive|define
name|ERR_LTOOLONG
value|3
literal|"$< line too long"
block|,
define|#
directive|define
name|ERR_DOLZERO
value|4
literal|"No file for $0"
block|,
define|#
directive|define
name|ERR_DOLQUEST
value|5
literal|"$? not allowed here"
block|,
define|#
directive|define
name|ERR_INCBR
value|6
literal|"Incomplete [] modifier"
block|,
define|#
directive|define
name|ERR_EXPORD
value|7
literal|"$ expansion must end before ]"
block|,
define|#
directive|define
name|ERR_BADMOD
value|8
literal|"Bad : modifier in $ (%c)"
block|,
define|#
directive|define
name|ERR_SUBSCRIPT
value|9
literal|"Subscript error"
block|,
define|#
directive|define
name|ERR_BADNUM
value|10
literal|"Badly formed number"
block|,
define|#
directive|define
name|ERR_NOMORE
value|11
literal|"No more words"
block|,
define|#
directive|define
name|ERR_FILENAME
value|12
literal|"Missing file name"
block|,
define|#
directive|define
name|ERR_GLOB
value|13
literal|"Internal glob error"
block|,
define|#
directive|define
name|ERR_COMMAND
value|14
literal|"Command not found"
block|,
define|#
directive|define
name|ERR_TOOFEW
value|15
literal|"Too few arguments"
block|,
define|#
directive|define
name|ERR_TOOMANY
value|16
literal|"Too many arguments"
block|,
define|#
directive|define
name|ERR_DANGER
value|17
literal|"Too dangerous to alias that"
block|,
define|#
directive|define
name|ERR_EMPTYIF
value|18
literal|"Empty if"
block|,
define|#
directive|define
name|ERR_IMPRTHEN
value|19
literal|"Improper then"
block|,
define|#
directive|define
name|ERR_NOPAREN
value|20
literal|"Words not parenthesized"
block|,
define|#
directive|define
name|ERR_NOTFOUND
value|21
literal|"%s not found"
block|,
define|#
directive|define
name|ERR_MASK
value|22
literal|"Improper mask"
block|,
define|#
directive|define
name|ERR_LIMIT
value|23
literal|"No such limit"
block|,
define|#
directive|define
name|ERR_TOOLARGE
value|24
literal|"Argument too large"
block|,
define|#
directive|define
name|ERR_SCALEF
value|25
literal|"Improper or unknown scale factor"
block|,
define|#
directive|define
name|ERR_UNDVAR
value|26
literal|"Undefined variable"
block|,
define|#
directive|define
name|ERR_DEEP
value|27
literal|"Directory stack not that deep"
block|,
define|#
directive|define
name|ERR_BADSIG
value|28
literal|"Bad signal number"
block|,
define|#
directive|define
name|ERR_UNKSIG
value|29
literal|"Unknown signal; kill -l lists signals"
block|,
define|#
directive|define
name|ERR_VARBEGIN
value|30
literal|"Variable name must begin with a letter"
block|,
define|#
directive|define
name|ERR_VARTOOLONG
value|31
literal|"Variable name too long"
block|,
define|#
directive|define
name|ERR_VARALNUM
value|32
literal|"Variable name must contain alphanumeric characters"
block|,
define|#
directive|define
name|ERR_JOBCONTROL
value|33
literal|"No job control in this shell"
block|,
define|#
directive|define
name|ERR_EXPRESSION
value|34
literal|"Expression Syntax"
block|,
define|#
directive|define
name|ERR_NOHOMEDIR
value|35
literal|"No home directory"
block|,
define|#
directive|define
name|ERR_CANTCHANGE
value|36
literal|"Can't change to home directory"
block|,
define|#
directive|define
name|ERR_NULLCOM
value|37
literal|"Invalid null command"
block|,
define|#
directive|define
name|ERR_ASSIGN
value|38
literal|"Assignment missing expression"
block|,
define|#
directive|define
name|ERR_UNKNOWNOP
value|39
literal|"Unknown operator"
block|,
define|#
directive|define
name|ERR_AMBIG
value|40
literal|"Ambiguous"
block|,
define|#
directive|define
name|ERR_EXISTS
value|41
literal|"%s: File exists"
block|,
define|#
directive|define
name|ERR_INTR
value|42
literal|"Interrupted"
block|,
define|#
directive|define
name|ERR_RANGE
value|43
literal|"Subscript out of range"
block|,
define|#
directive|define
name|ERR_OVERFLOW
value|44
literal|"Line overflow"
block|,
define|#
directive|define
name|ERR_VARMOD
value|45
literal|"Unknown variable modifier"
block|,
define|#
directive|define
name|ERR_NOSUCHJOB
value|46
literal|"No such job"
block|,
define|#
directive|define
name|ERR_TERMINAL
value|47
literal|"Can't from terminal"
block|,
define|#
directive|define
name|ERR_NOTWHILE
value|48
literal|"Not in while/foreach"
block|,
define|#
directive|define
name|ERR_NOPROC
value|49
literal|"No more processes"
block|,
define|#
directive|define
name|ERR_NOMATCH
value|50
literal|"No match"
block|,
define|#
directive|define
name|ERR_MISSING
value|51
literal|"Missing %c"
block|,
define|#
directive|define
name|ERR_UNMATCHED
value|52
literal|"Unmatched %c"
block|,
define|#
directive|define
name|ERR_NOMEM
value|53
literal|"Out of memory"
block|,
define|#
directive|define
name|ERR_PIPE
value|54
literal|"Can't make pipe"
block|,
define|#
directive|define
name|ERR_SYSTEM
value|55
literal|"%s: %s"
block|,
define|#
directive|define
name|ERR_STRING
value|56
literal|"%s"
block|,
define|#
directive|define
name|ERR_JOBS
value|57
literal|"Usage: jobs [ -l ]"
block|,
define|#
directive|define
name|ERR_JOBARGS
value|58
literal|"Arguments should be jobs or process id's"
block|,
define|#
directive|define
name|ERR_JOBCUR
value|59
literal|"No current job"
block|,
define|#
directive|define
name|ERR_JOBPREV
value|60
literal|"No previous job"
block|,
define|#
directive|define
name|ERR_JOBPAT
value|61
literal|"No job matches pattern"
block|,
define|#
directive|define
name|ERR_NESTING
value|62
literal|"Fork nesting> %d; maybe `...` loop"
block|,
define|#
directive|define
name|ERR_JOBCTRLSUB
value|63
literal|"No job control in subshells"
block|,
define|#
directive|define
name|ERR_BADPLPS
value|64
literal|"Badly placed ()'s"
block|,
define|#
directive|define
name|ERR_STOPPED
value|65
literal|"%sThere are suspended jobs"
block|,
define|#
directive|define
name|ERR_NODIR
value|66
literal|"No other directory"
block|,
define|#
directive|define
name|ERR_EMPTY
value|67
literal|"Directory stack empty"
block|,
define|#
directive|define
name|ERR_BADDIR
value|68
literal|"Bad directory"
block|,
define|#
directive|define
name|ERR_DIRUS
value|69
literal|"Usage: %s [-lvn]%s"
block|,
define|#
directive|define
name|ERR_HFLAG
value|70
literal|"No operand for -h flag"
block|,
define|#
directive|define
name|ERR_NOTLOGIN
value|71
literal|"Not a login shell"
block|,
define|#
directive|define
name|ERR_DIV0
value|72
literal|"Division by 0"
block|,
define|#
directive|define
name|ERR_MOD0
value|73
literal|"Mod by 0"
block|,
define|#
directive|define
name|ERR_BADSCALE
value|74
literal|"Bad scaling; did you mean \"%s\"?"
block|,
define|#
directive|define
name|ERR_SUSPLOG
value|75
literal|"Can't suspend a login shell (yet)"
block|,
define|#
directive|define
name|ERR_UNKUSER
value|76
literal|"Unknown user: %s"
block|,
define|#
directive|define
name|ERR_NOHOME
value|77
literal|"No $home variable set"
block|,
define|#
directive|define
name|ERR_HISTUS
value|78
literal|"Usage: history [-rh] [# number of events]"
block|,
define|#
directive|define
name|ERR_SPDOLLT
value|79
literal|"$, ! or< not allowed with $# or $?"
block|,
define|#
directive|define
name|ERR_NEWLINE
value|80
literal|"Newline in variable name"
block|,
define|#
directive|define
name|ERR_SPSTAR
value|81
literal|"* not allowed with $# or $?"
block|,
define|#
directive|define
name|ERR_DIGIT
value|82
literal|"$?<digit> or $#<digit> not allowed"
block|,
define|#
directive|define
name|ERR_VARILL
value|83
literal|"Illegal variable name"
block|,
define|#
directive|define
name|ERR_NLINDEX
value|84
literal|"Newline in variable index"
block|,
define|#
directive|define
name|ERR_EXPOVFL
value|85
literal|"Expansion buffer overflow"
block|,
define|#
directive|define
name|ERR_VARSYN
value|86
literal|"Variable syntax"
block|,
define|#
directive|define
name|ERR_BADBANG
value|87
literal|"Bad ! form"
block|,
define|#
directive|define
name|ERR_NOSUBST
value|88
literal|"No previous substitute"
block|,
define|#
directive|define
name|ERR_BADSUBST
value|89
literal|"Bad substitute"
block|,
define|#
directive|define
name|ERR_LHS
value|90
literal|"No previous left hand side"
block|,
define|#
directive|define
name|ERR_RHSLONG
value|91
literal|"Right hand side too long"
block|,
define|#
directive|define
name|ERR_BADBANGMOD
value|92
literal|"Bad ! modifier: %c"
block|,
define|#
directive|define
name|ERR_MODFAIL
value|93
literal|"Modifier failed"
block|,
define|#
directive|define
name|ERR_SUBOVFL
value|94
literal|"Substitution buffer overflow"
block|,
define|#
directive|define
name|ERR_BADBANGARG
value|95
literal|"Bad ! arg selector"
block|,
define|#
directive|define
name|ERR_NOSEARCH
value|96
literal|"No prev search"
block|,
define|#
directive|define
name|ERR_NOEVENT
value|97
literal|"%s: Event not found"
block|,
define|#
directive|define
name|ERR_TOOMANYRP
value|98
literal|"Too many )'s"
block|,
define|#
directive|define
name|ERR_TOOMANYLP
value|99
literal|"Too many ('s"
block|,
define|#
directive|define
name|ERR_BADPLP
value|100
literal|"Badly placed ("
block|,
define|#
directive|define
name|ERR_MISRED
value|101
literal|"Missing name for redirect"
block|,
define|#
directive|define
name|ERR_OUTRED
value|102
literal|"Ambiguous output redirect"
block|,
define|#
directive|define
name|ERR_REDPAR
value|103
literal|"Can't<< within ()'s"
block|,
define|#
directive|define
name|ERR_INRED
value|104
literal|"Ambiguous input redirect"
block|,
define|#
directive|define
name|ERR_ALIASLOOP
value|105
literal|"Alias loop"
block|,
define|#
directive|define
name|ERR_HISTLOOP
value|106
literal|"!# History loop"
block|,
define|#
directive|define
name|ERR_ARCH
value|107
literal|"%s: %s. Wrong Architecture"
block|,
define|#
directive|define
name|ERR_FILEINQ
value|108
literal|"Malformed file inquiry"
block|,
define|#
directive|define
name|ERR_SELOVFL
value|109
literal|"Selector overflow"
block|,
define|#
directive|define
name|ERR_INVALID
value|110
literal|"Invalid Error"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The parser and scanner set up errors for later by calling seterr,  * which sets the variable err as a side effect; later to be tested,  * e.g. in process.  */
end_comment

begin_function
name|void
if|#
directive|if
name|__STDC__
name|seterror
parameter_list|(
name|int
name|id
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|seterror
parameter_list|(
name|id
parameter_list|,
name|va_alist
parameter_list|)
name|int
name|id
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
if|if
condition|(
name|seterr
operator|==
literal|0
condition|)
block|{
name|char
name|berr
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|va_list
name|va
decl_stmt|;
if|#
directive|if
name|__STDC__
name|va_start
argument_list|(
name|va
argument_list|,
name|id
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|va
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|id
operator|<
literal|0
operator|||
name|id
operator|>
sizeof|sizeof
argument_list|(
name|errorlist
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|errorlist
index|[
literal|0
index|]
argument_list|)
condition|)
name|id
operator|=
name|ERR_INVALID
expr_stmt|;
name|vsnprintf
argument_list|(
name|berr
argument_list|,
sizeof|sizeof
argument_list|(
name|berr
argument_list|)
argument_list|,
name|errorlist
index|[
name|id
index|]
argument_list|,
name|va
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
name|seterr
operator|=
name|strsave
argument_list|(
name|berr
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Print the error with the given id.  *  * Special ids:  *	ERR_SILENT: Print nothing.  *	ERR_OLD: Print the previously set error if one was there.  *	         otherwise return.  *	ERR_NAME: If this bit is set, print the name of the function  *		  in bname  *  * This routine always resets or exits.  The flag haderr  * is set so the routine who catches the unwind can propogate  * it if they want.  *  * Note that any open files at the point of error will eventually  * be closed in the routine process in sh.c which is the only  * place error unwinds are ever caught.  */
end_comment

begin_function
name|void
if|#
directive|if
name|__STDC__
name|stderror
parameter_list|(
name|int
name|id
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|stderror
parameter_list|(
name|id
parameter_list|,
name|va_alist
parameter_list|)
name|int
name|id
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
name|va_list
name|va
decl_stmt|;
name|Char
modifier|*
modifier|*
name|v
decl_stmt|;
name|int
name|flags
init|=
name|id
operator|&
name|ERR_FLAGS
decl_stmt|;
name|id
operator|&=
operator|~
name|ERR_FLAGS
expr_stmt|;
if|if
condition|(
operator|(
name|flags
operator|&
name|ERR_OLD
operator|)
operator|&&
name|seterr
operator|==
name|NULL
condition|)
return|return;
if|if
condition|(
name|id
operator|<
literal|0
operator|||
name|id
operator|>
sizeof|sizeof
argument_list|(
name|errorlist
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|errorlist
index|[
literal|0
index|]
argument_list|)
condition|)
name|id
operator|=
name|ERR_INVALID
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|cshout
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|csherr
argument_list|)
expr_stmt|;
name|haderr
operator|=
literal|1
expr_stmt|;
comment|/* Now to diagnostic output */
name|timflg
operator|=
literal|0
expr_stmt|;
comment|/* This isn't otherwise reset */
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|ERR_SILENT
operator|)
condition|)
block|{
if|if
condition|(
name|flags
operator|&
name|ERR_NAME
condition|)
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|csherr
argument_list|,
literal|"%s: "
argument_list|,
name|bname
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|flags
operator|&
name|ERR_OLD
operator|)
condition|)
comment|/* Old error. */
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|csherr
argument_list|,
literal|"%s.\n"
argument_list|,
name|seterr
argument_list|)
expr_stmt|;
else|else
block|{
if|#
directive|if
name|__STDC__
name|va_start
argument_list|(
name|va
argument_list|,
name|id
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|va
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|(
name|void
operator|)
name|vfprintf
argument_list|(
name|csherr
argument_list|,
name|errorlist
index|[
name|id
index|]
argument_list|,
name|va
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|csherr
argument_list|,
literal|".\n"
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|seterr
condition|)
block|{
name|xfree
argument_list|(
operator|(
name|ptr_t
operator|)
name|seterr
argument_list|)
expr_stmt|;
name|seterr
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|v
operator|=
name|pargv
operator|)
operator|!=
name|NULL
condition|)
name|pargv
operator|=
literal|0
operator|,
name|blkfree
argument_list|(
name|v
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|v
operator|=
name|gargv
operator|)
operator|!=
name|NULL
condition|)
name|gargv
operator|=
literal|0
operator|,
name|blkfree
argument_list|(
name|v
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|cshout
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|csherr
argument_list|)
expr_stmt|;
name|didfds
operator|=
literal|0
expr_stmt|;
comment|/* Forget about 0,1,2 */
comment|/*      * Go away if -e or we are a child shell      */
if|if
condition|(
name|exiterr
operator|||
name|child
condition|)
name|xexit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/*      * Reset the state of the input. This buffered seek to end of file will      * also clear the while/foreach stack.      */
name|btoeof
argument_list|()
expr_stmt|;
name|set
argument_list|(
name|STRstatus
argument_list|,
name|Strsave
argument_list|(
name|STR1
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|tpgrp
operator|>
literal|0
condition|)
operator|(
name|void
operator|)
name|tcsetpgrp
argument_list|(
name|FSHTTY
argument_list|,
name|tpgrp
argument_list|)
expr_stmt|;
name|reset
argument_list|()
expr_stmt|;
comment|/* Unwind */
block|}
end_function

end_unit

