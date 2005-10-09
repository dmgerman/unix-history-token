begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)strerror.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: strerror.c,v 1.3.2.1 2001/11/02 17:45:31 gson Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_comment
comment|/*  * Copyright (c) 1988, 1993  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"port_before.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"port_after.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NEED_STRERROR
end_ifndef

begin_decl_stmt
name|int
name|__strerror_unneeded__
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SYSERROR_LIST
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|const
name|char
modifier|*
name|isc_strerror
parameter_list|(
name|int
name|num
parameter_list|)
block|{
define|#
directive|define
name|UPREFIX
value|"Unknown error: "
specifier|static
name|char
name|ebuf
index|[
literal|40
index|]
init|=
name|UPREFIX
decl_stmt|;
comment|/* 64-bit number + slop */
name|u_int
name|errnum
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|t
decl_stmt|;
specifier|const
name|char
modifier|*
name|ret
decl_stmt|;
name|char
name|tmp
index|[
literal|40
index|]
decl_stmt|;
name|errnum
operator|=
name|num
expr_stmt|;
comment|/* convert to unsigned */
ifdef|#
directive|ifdef
name|USE_SYSERROR_LIST
if|if
condition|(
name|errnum
operator|<
name|sys_nerr
condition|)
return|return
operator|(
name|sys_errlist
index|[
name|errnum
index|]
operator|)
return|;
else|#
directive|else
undef|#
directive|undef
name|strerror
name|ret
operator|=
name|strerror
argument_list|(
name|num
argument_list|)
expr_stmt|;
comment|/* call strerror() in libc */
if|if
condition|(
name|ret
operator|!=
name|NULL
condition|)
return|return
operator|(
name|ret
operator|)
return|;
endif|#
directive|endif
comment|/* Do this by hand, so we don't include stdio(3). */
name|t
operator|=
name|tmp
expr_stmt|;
do|do
block|{
operator|*
name|t
operator|++
operator|=
literal|"0123456789"
index|[
name|errnum
operator|%
literal|10
index|]
expr_stmt|;
block|}
do|while
condition|(
name|errnum
operator|/=
literal|10
condition|)
do|;
for|for
control|(
name|p
operator|=
name|ebuf
operator|+
sizeof|sizeof
argument_list|(
name|UPREFIX
argument_list|)
operator|-
literal|1
init|;
condition|;
control|)
block|{
operator|*
name|p
operator|++
operator|=
operator|*
operator|--
name|t
expr_stmt|;
if|if
condition|(
name|t
operator|<=
name|tmp
condition|)
break|break;
block|}
return|return
operator|(
name|ebuf
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*NEED_STRERROR*/
end_comment

end_unit

