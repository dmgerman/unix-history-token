begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OPENBSD ORIGINAL: lib/libc/stdlib/getopt.c */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GETOPT
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|HAVE_GETOPT_OPTRESET
argument_list|)
end_if

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
modifier|*
name|rcsid
init|=
literal|"$OpenBSD: getopt.c,v 1.5 2003/06/02 20:18:37 millert Exp $"
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

begin_decl_stmt
name|int
name|BSDopterr
init|=
literal|1
decl_stmt|,
comment|/* if error message should be printed */
name|BSDoptind
init|=
literal|1
decl_stmt|,
comment|/* index into parent argv vector */
name|BSDoptopt
decl_stmt|,
comment|/* character checked for validity */
name|BSDoptreset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reset getopt */
end_comment

begin_decl_stmt
name|char
modifier|*
name|BSDoptarg
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
name|BSDgetopt
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
modifier|*
name|nargv
decl_stmt|;
specifier|const
name|char
modifier|*
name|ostr
decl_stmt|;
block|{
specifier|extern
name|char
modifier|*
name|__progname
decl_stmt|;
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
name|ostr
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|BSDoptreset
operator|||
operator|!
operator|*
name|place
condition|)
block|{
comment|/* update scanning pointer */
name|BSDoptreset
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|BSDoptind
operator|>=
name|nargc
operator|||
operator|*
operator|(
name|place
operator|=
name|nargv
index|[
name|BSDoptind
index|]
operator|)
operator|!=
literal|'-'
condition|)
block|{
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
name|place
index|[
literal|1
index|]
operator|&&
operator|*
operator|++
name|place
operator|==
literal|'-'
condition|)
block|{
comment|/* found "--" */
operator|++
name|BSDoptind
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
block|}
comment|/* option letter okay? */
if|if
condition|(
operator|(
name|BSDoptopt
operator|=
operator|(
name|int
operator|)
operator|*
name|place
operator|++
operator|)
operator|==
operator|(
name|int
operator|)
literal|':'
operator|||
operator|!
operator|(
name|oli
operator|=
name|strchr
argument_list|(
name|ostr
argument_list|,
name|BSDoptopt
argument_list|)
operator|)
condition|)
block|{
comment|/* 		 * if the user didn't specify '-' as an option, 		 * assume it means -1. 		 */
if|if
condition|(
name|BSDoptopt
operator|==
operator|(
name|int
operator|)
literal|'-'
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
operator|!
operator|*
name|place
condition|)
operator|++
name|BSDoptind
expr_stmt|;
if|if
condition|(
name|BSDopterr
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
name|__progname
argument_list|,
name|BSDoptopt
argument_list|)
expr_stmt|;
return|return
operator|(
name|BADCH
operator|)
return|;
block|}
if|if
condition|(
operator|*
operator|++
name|oli
operator|!=
literal|':'
condition|)
block|{
comment|/* don't need argument */
name|BSDoptarg
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|place
condition|)
operator|++
name|BSDoptind
expr_stmt|;
block|}
else|else
block|{
comment|/* need an argument */
if|if
condition|(
operator|*
name|place
condition|)
comment|/* no white space */
name|BSDoptarg
operator|=
name|place
expr_stmt|;
elseif|else
if|if
condition|(
name|nargc
operator|<=
operator|++
name|BSDoptind
condition|)
block|{
comment|/* no arg */
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
name|BSDopterr
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
name|__progname
argument_list|,
name|BSDoptopt
argument_list|)
expr_stmt|;
return|return
operator|(
name|BADCH
operator|)
return|;
block|}
else|else
comment|/* white space */
name|BSDoptarg
operator|=
name|nargv
index|[
name|BSDoptind
index|]
expr_stmt|;
name|place
operator|=
name|EMSG
expr_stmt|;
operator|++
name|BSDoptind
expr_stmt|;
block|}
return|return
operator|(
name|BSDoptopt
operator|)
return|;
comment|/* dump back option letter */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_GETOPT) || !defined(HAVE_OPTRESET) */
end_comment

end_unit

