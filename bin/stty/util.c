begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static char sccsid[] = "@(#)util.c	8.3 (Berkeley) 4/2/94";
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
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"stty.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_comment
comment|/*  * Gross, but since we're changing the control descriptor from 1 to 0, most  * users will be probably be doing "stty> /dev/sometty" by accident.  If 1  * and 2 are both ttys, but not the same, assume that 1 was incorrectly  * redirected.  */
end_comment

begin_function
name|void
name|checkredirect
parameter_list|()
block|{
name|struct
name|stat
name|sb1
decl_stmt|,
name|sb2
decl_stmt|;
if|if
condition|(
name|isatty
argument_list|(
name|STDOUT_FILENO
argument_list|)
operator|&&
name|isatty
argument_list|(
name|STDERR_FILENO
argument_list|)
operator|&&
operator|!
name|fstat
argument_list|(
name|STDOUT_FILENO
argument_list|,
operator|&
name|sb1
argument_list|)
operator|&&
operator|!
name|fstat
argument_list|(
name|STDERR_FILENO
argument_list|,
operator|&
name|sb2
argument_list|)
operator|&&
operator|(
name|sb1
operator|.
name|st_rdev
operator|!=
name|sb2
operator|.
name|st_rdev
operator|)
condition|)
name|warnx
argument_list|(
literal|"stdout appears redirected, but stdin is the control descriptor"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

