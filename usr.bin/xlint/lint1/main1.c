begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: main1.c,v 1.11 2002/01/29 02:43:38 tv Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Jochen Pohl  * All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jochen Pohl for  *	The NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__RCSID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: main1.c,v 1.11 2002/01/29 02:43:38 tv Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|"lint1.h"
end_include

begin_comment
comment|/* set yydebug to 1*/
end_comment

begin_decl_stmt
name|int
name|yflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Print warnings if an assignment of an integertype to another integertype  * causes an implizit narrowing conversion. If aflag is 1, these warnings  * are printed only if the source type is at least as wide as long. If aflag  * is greater than 1, they are always printed.  */
end_comment

begin_decl_stmt
name|int
name|aflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print a warning if a break statement cannot be reached. */
end_comment

begin_decl_stmt
name|int
name|bflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print warnings for pointer casts. */
end_comment

begin_decl_stmt
name|int
name|cflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print various debug information. */
end_comment

begin_decl_stmt
name|int
name|dflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Perform stricter checking of enum types and operations on enum types. */
end_comment

begin_decl_stmt
name|int
name|eflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print complete pathnames, not only the basename. */
end_comment

begin_decl_stmt
name|int
name|Fflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Enable some extensions of gcc */
end_comment

begin_decl_stmt
name|int
name|gflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Treat warnings as errors */
end_comment

begin_decl_stmt
name|int
name|wflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Apply a number of heuristic tests to attempt to intuit bugs, improve  * style, and reduce waste.  */
end_comment

begin_decl_stmt
name|int
name|hflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Attempt to check portability to other dialects of C. */
end_comment

begin_decl_stmt
name|int
name|pflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * In case of redeclarations/redefinitions print the location of the  * previous declaration/definition.  */
end_comment

begin_decl_stmt
name|int
name|rflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Strict ANSI C mode. */
end_comment

begin_decl_stmt
name|int
name|sflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Traditional C mode. */
end_comment

begin_decl_stmt
name|int
name|tflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Complain about functions and external variables used and not defined,  * or defined and not used.  */
end_comment

begin_decl_stmt
name|int
name|uflag
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Complain about unused function arguments. */
end_comment

begin_decl_stmt
name|int
name|vflag
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Complain about structures which are never defined. */
end_comment

begin_decl_stmt
name|int
name|zflag
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|err_set
name|msgset
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|c
decl_stmt|;
name|char
modifier|*
name|ptr
decl_stmt|;
name|setprogname
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|ERR_ZERO
argument_list|(
operator|&
name|msgset
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"abcdeghmprstuvwyzFX:"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'a'
case|:
name|aflag
operator|++
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
name|bflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'c'
case|:
name|cflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
name|dflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'e'
case|:
name|eflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'F'
case|:
name|Fflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'g'
case|:
name|gflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'h'
case|:
name|hflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'p'
case|:
name|pflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
name|rflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|sflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'t'
case|:
name|tflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
name|uflag
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'w'
case|:
name|wflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'v'
case|:
name|vflag
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'y'
case|:
name|yflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'z'
case|:
name|zflag
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
name|msglist
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|'X'
case|:
for|for
control|(
name|ptr
operator|=
name|strtok
argument_list|(
name|optarg
argument_list|,
literal|","
argument_list|)
init|;
name|ptr
condition|;
name|ptr
operator|=
name|strtok
argument_list|(
name|NULL
argument_list|,
literal|","
argument_list|)
control|)
block|{
name|char
modifier|*
name|eptr
decl_stmt|;
name|long
name|msg
init|=
name|strtol
argument_list|(
name|ptr
argument_list|,
operator|&
name|eptr
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|msg
operator|==
name|LONG_MIN
operator|||
name|msg
operator|==
name|LONG_MAX
operator|)
operator|&&
name|errno
operator|==
name|ERANGE
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"invalid error message id '%s'"
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|eptr
operator|||
name|ptr
operator|==
name|eptr
operator|||
name|msg
operator|<
literal|0
operator|||
name|msg
operator|>=
name|ERR_SETSIZE
condition|)
name|errx
argument_list|(
literal|1
argument_list|,
literal|"invalid error message id '%s'"
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
name|ERR_SET
argument_list|(
name|msg
argument_list|,
operator|&
name|msgset
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'?'
case|:
default|default:
name|usage
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
name|argc
operator|-=
name|optind
expr_stmt|;
name|argv
operator|+=
name|optind
expr_stmt|;
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
name|usage
argument_list|()
expr_stmt|;
comment|/* open the input file */
if|if
condition|(
operator|(
name|yyin
operator|=
name|fopen
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"cannot open '%s'"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* initialize output */
name|outopen
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|yflag
condition|)
name|yydebug
operator|=
literal|1
expr_stmt|;
name|initmem
argument_list|()
expr_stmt|;
name|initdecl
argument_list|()
expr_stmt|;
name|initscan
argument_list|()
expr_stmt|;
name|initmtab
argument_list|()
expr_stmt|;
name|yyparse
argument_list|()
expr_stmt|;
comment|/* Following warnings cannot be suppressed by LINTED */
name|nowarn
operator|=
literal|0
expr_stmt|;
name|chkglsyms
argument_list|()
expr_stmt|;
name|outclose
argument_list|()
expr_stmt|;
return|return
operator|(
name|nerr
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Usage: %s [-abcdeghmprstuvwyzF] [-X<id>[,<id>]... src dest\n"
argument_list|,
name|getprogname
argument_list|()
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|norecover
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* cannot recover from previous errors */
name|error
argument_list|(
literal|224
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

