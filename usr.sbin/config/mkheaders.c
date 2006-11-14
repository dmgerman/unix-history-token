begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static char sccsid[] = "@(#)mkheaders.c	8.1 (Berkeley) 6/6/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
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
comment|/*  * Make all the .h files for the optional entries  */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"y.tab.h"
end_include

begin_function
name|void
name|headers
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|file_list
modifier|*
name|fl
decl_stmt|;
name|struct
name|device
modifier|*
name|dp
decl_stmt|;
name|int
name|match
decl_stmt|;
name|int
name|errors
decl_stmt|;
name|errors
operator|=
literal|0
expr_stmt|;
name|STAILQ_FOREACH
argument_list|(
argument|fl
argument_list|,
argument|&ftab
argument_list|,
argument|f_next
argument_list|)
block|{
if|if
condition|(
name|fl
operator|->
name|f_needs
operator|!=
literal|0
condition|)
block|{
name|match
operator|=
literal|0
expr_stmt|;
name|STAILQ_FOREACH
argument_list|(
argument|dp
argument_list|,
argument|&dtab
argument_list|,
argument|d_next
argument_list|)
block|{
if|if
condition|(
name|eq
argument_list|(
name|dp
operator|->
name|d_name
argument_list|,
name|fl
operator|->
name|f_needs
argument_list|)
condition|)
block|{
name|match
operator|++
expr_stmt|;
name|dp
operator|->
name|d_done
operator||=
name|DEVDONE
expr_stmt|;
block|}
block|}
block|}
block|}
name|STAILQ_FOREACH
argument_list|(
argument|dp
argument_list|,
argument|&dtab
argument_list|,
argument|d_next
argument_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|dp
operator|->
name|d_done
operator|&
name|DEVDONE
operator|)
condition|)
block|{
name|warnx
argument_list|(
literal|"Error: device \"%s\" is unknown"
argument_list|,
name|dp
operator|->
name|d_name
argument_list|)
expr_stmt|;
name|errors
operator|++
expr_stmt|;
block|}
block|}
if|if
condition|(
name|errors
condition|)
name|errx
argument_list|(
literal|1
argument_list|,
literal|"%d errors"
argument_list|,
name|errors
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

