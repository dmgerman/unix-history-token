begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Cimarron D. Taylor of the University of California, Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1990, 1993, 1994\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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

begin_endif
unit|static char sccsid[] = "@(#)main.c	8.4 (Berkeley) 5/4/95";
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
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<fts.h>
end_include

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"find.h"
end_include

begin_decl_stmt
name|time_t
name|now
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time find was run */
end_comment

begin_decl_stmt
name|int
name|dotfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* starting directory */
end_comment

begin_decl_stmt
name|int
name|ftsoptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* options for the ftsopen(3) call */
end_comment

begin_decl_stmt
name|int
name|isdeprecated
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* using deprecated syntax */
end_comment

begin_decl_stmt
name|int
name|isdepth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do directories on post-order visit */
end_comment

begin_decl_stmt
name|int
name|isoutput
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user specified output operator */
end_comment

begin_decl_stmt
name|int
name|issort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do hierarchies in lexicographical order */
end_comment

begin_decl_stmt
name|int
name|isxargs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't permit xargs delimiting chars */
end_comment

begin_decl_stmt
name|int
name|mindepth
init|=
operator|-
literal|1
decl_stmt|,
name|maxdepth
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum and maximum depth */
end_comment

begin_decl_stmt
name|int
name|regexp_flags
init|=
name|REG_BASIC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use the "basic" regexp by default*/
end_comment

begin_function_decl
specifier|static
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|char
modifier|*
modifier|*
name|p
decl_stmt|,
modifier|*
modifier|*
name|start
decl_stmt|;
name|int
name|Hflag
decl_stmt|,
name|Lflag
decl_stmt|,
name|ch
decl_stmt|;
operator|(
name|void
operator|)
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
literal|""
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|time
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
comment|/* initialize the time-of-day */
name|p
operator|=
name|start
operator|=
name|argv
expr_stmt|;
name|Hflag
operator|=
name|Lflag
operator|=
literal|0
expr_stmt|;
name|ftsoptions
operator|=
name|FTS_NOSTAT
operator||
name|FTS_PHYSICAL
expr_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"EHLPXdf:sx"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'E'
case|:
name|regexp_flags
operator||=
name|REG_EXTENDED
expr_stmt|;
break|break;
case|case
literal|'H'
case|:
name|Hflag
operator|=
literal|1
expr_stmt|;
name|Lflag
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'L'
case|:
name|Lflag
operator|=
literal|1
expr_stmt|;
name|Hflag
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'P'
case|:
name|Hflag
operator|=
name|Lflag
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'X'
case|:
name|isxargs
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
name|isdepth
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
operator|*
name|p
operator|++
operator|=
name|optarg
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|issort
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
name|ftsoptions
operator||=
name|FTS_XDEV
expr_stmt|;
break|break;
case|case
literal|'?'
case|:
default|default:
break|break;
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
name|Hflag
condition|)
name|ftsoptions
operator||=
name|FTS_COMFOLLOW
expr_stmt|;
if|if
condition|(
name|Lflag
condition|)
block|{
name|ftsoptions
operator|&=
operator|~
name|FTS_PHYSICAL
expr_stmt|;
name|ftsoptions
operator||=
name|FTS_LOGICAL
expr_stmt|;
block|}
comment|/* 	 * Find first option to delimit the file list.  The first argument 	 * that starts with a -, or is a ! or a ( must be interpreted as a 	 * part of the find expression, according to POSIX .2. 	 */
for|for
control|(
init|;
operator|*
name|argv
operator|!=
name|NULL
condition|;
operator|*
name|p
operator|++
operator|=
operator|*
name|argv
operator|++
control|)
block|{
if|if
condition|(
name|argv
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|==
literal|'-'
condition|)
break|break;
if|if
condition|(
operator|(
name|argv
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|==
literal|'!'
operator|||
name|argv
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|==
literal|'('
operator|)
operator|&&
name|argv
index|[
literal|0
index|]
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
break|break;
block|}
if|if
condition|(
name|p
operator|==
name|start
condition|)
name|usage
argument_list|()
expr_stmt|;
operator|*
name|p
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|(
name|dotfd
operator|=
name|open
argument_list|(
literal|"."
argument_list|,
name|O_RDONLY
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"."
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|find_execute
argument_list|(
name|find_formplan
argument_list|(
name|argv
argument_list|)
argument_list|,
name|start
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|usage
parameter_list|()
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: find [-H | -L | -P] [-EXdsx] [-f file] [file ...] [expression]\n"
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

