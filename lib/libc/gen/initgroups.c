begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)initgroups.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
name|int
name|initgroups
parameter_list|(
name|uname
parameter_list|,
name|agroup
parameter_list|)
specifier|const
name|char
modifier|*
name|uname
decl_stmt|;
name|gid_t
name|agroup
decl_stmt|;
block|{
name|int
name|ngroups
decl_stmt|;
comment|/* 	 * Provide space for one group more than NGROUPS to allow 	 * setgroups to fail and set errno. 	 */
name|gid_t
name|groups
index|[
name|NGROUPS
operator|+
literal|1
index|]
decl_stmt|;
name|ngroups
operator|=
name|NGROUPS
operator|+
literal|1
expr_stmt|;
name|getgrouplist
argument_list|(
name|uname
argument_list|,
name|agroup
argument_list|,
name|groups
argument_list|,
operator|&
name|ngroups
argument_list|)
expr_stmt|;
return|return
operator|(
name|setgroups
argument_list|(
name|ngroups
argument_list|,
name|groups
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

