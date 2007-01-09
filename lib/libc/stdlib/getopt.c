begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: getopt.c,v 1.26 2003/08/07 16:43:40 agc Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1987, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)getopt.c	8.3 (Berkeley) 4/27/95"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
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
file|"namespace.h"
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_decl_stmt
name|int
name|opterr
init|=
literal|1
decl_stmt|,
comment|/* if error message should be printed */
name|optind
init|=
literal|1
decl_stmt|,
comment|/* index into parent argv vector */
name|optopt
decl_stmt|,
comment|/* character checked for validity */
name|optreset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reset getopt */
end_comment

begin_decl_stmt
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argument associated with option */
end_comment

begin_define
define|#
directive|define
name|BADCH
value|(int)'?'
end_define

begin_define
define|#
directive|define
name|BADARG
value|(int)':'
end_define

begin_define
define|#
directive|define
name|EMSG
value|""
end_define

begin_comment
comment|/*  * getopt --  *	Parse argc/argv argument vector.  */
end_comment

begin_function
name|int
name|getopt
parameter_list|(
name|nargc
parameter_list|,
name|nargv
parameter_list|,
name|ostr
parameter_list|)
name|int
name|nargc
decl_stmt|;
name|char
modifier|*
specifier|const
name|nargv
index|[]
decl_stmt|;
specifier|const
name|char
modifier|*
name|ostr
decl_stmt|;
block|{
specifier|static
name|char
modifier|*
name|place
init|=
name|EMSG
decl_stmt|;
comment|/* option letter processing */
name|char
modifier|*
name|oli
decl_stmt|;
comment|/* option letter list index */
if|if
condition|(
name|optreset
operator|||
operator|*
name|place
operator|==
literal|0
condition|)
block|{
comment|/* update scanning pointer */
name|optreset
operator|=
literal|0
expr_stmt|;
name|place
operator|=
name|nargv
index|[
name|optind
index|]
expr_stmt|;
if|if
condition|(
name|optind
operator|>=
name|nargc
operator|||
operator|*
name|place
operator|++
operator|!=
literal|'-'
condition|)
block|{
comment|/* Argument is absent or is not an option */
name|place
operator|=
name|EMSG
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|optopt
operator|=
operator|*
name|place
operator|++
expr_stmt|;
if|if
condition|(
name|optopt
operator|==
literal|'-'
operator|&&
operator|*
name|place
operator|==
literal|0
condition|)
block|{
comment|/* "--" => end of options */
operator|++
name|optind
expr_stmt|;
name|place
operator|=
name|EMSG
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|optopt
operator|==
literal|0
condition|)
block|{
comment|/* Solitary '-', treat as a '-' option 			   if the program (eg su) is looking for it. */
name|place
operator|=
name|EMSG
expr_stmt|;
if|if
condition|(
name|strchr
argument_list|(
name|ostr
argument_list|,
literal|'-'
argument_list|)
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|optopt
operator|=
literal|'-'
expr_stmt|;
block|}
block|}
else|else
name|optopt
operator|=
operator|*
name|place
operator|++
expr_stmt|;
comment|/* See if option letter is one the caller wanted... */
if|if
condition|(
name|optopt
operator|==
literal|':'
operator|||
operator|(
name|oli
operator|=
name|strchr
argument_list|(
name|ostr
argument_list|,
name|optopt
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
operator|*
name|place
operator|==
literal|0
condition|)
operator|++
name|optind
expr_stmt|;
if|if
condition|(
name|opterr
operator|&&
operator|*
name|ostr
operator|!=
literal|':'
condition|)
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: illegal option -- %c\n"
argument_list|,
name|_getprogname
argument_list|()
argument_list|,
name|optopt
argument_list|)
expr_stmt|;
return|return
operator|(
name|BADCH
operator|)
return|;
block|}
comment|/* Does this option need an argument? */
if|if
condition|(
name|oli
index|[
literal|1
index|]
operator|!=
literal|':'
condition|)
block|{
comment|/* don't need argument */
name|optarg
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|*
name|place
operator|==
literal|0
condition|)
operator|++
name|optind
expr_stmt|;
block|}
else|else
block|{
comment|/* Option-argument is either the rest of this argument or the 		   entire next argument. */
if|if
condition|(
operator|*
name|place
condition|)
name|optarg
operator|=
name|place
expr_stmt|;
elseif|else
if|if
condition|(
name|nargc
operator|>
operator|++
name|optind
condition|)
name|optarg
operator|=
name|nargv
index|[
name|optind
index|]
expr_stmt|;
else|else
block|{
comment|/* option-argument absent */
name|place
operator|=
name|EMSG
expr_stmt|;
if|if
condition|(
operator|*
name|ostr
operator|==
literal|':'
condition|)
return|return
operator|(
name|BADARG
operator|)
return|;
if|if
condition|(
name|opterr
condition|)
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: option requires an argument -- %c\n"
argument_list|,
name|_getprogname
argument_list|()
argument_list|,
name|optopt
argument_list|)
expr_stmt|;
return|return
operator|(
name|BADCH
operator|)
return|;
block|}
name|place
operator|=
name|EMSG
expr_stmt|;
operator|++
name|optind
expr_stmt|;
block|}
return|return
operator|(
name|optopt
operator|)
return|;
comment|/* return option letter */
block|}
end_function

end_unit

