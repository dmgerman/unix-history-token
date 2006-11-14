begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2004 Tim J. Robbins.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_include
include|#
directive|include
file|"mblocal.h"
end_include

begin_function
name|size_t
name|mbsrtowcs
parameter_list|(
name|wchar_t
modifier|*
name|__restrict
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|__restrict
name|src
parameter_list|,
name|size_t
name|len
parameter_list|,
name|mbstate_t
modifier|*
name|__restrict
name|ps
parameter_list|)
block|{
specifier|static
name|mbstate_t
name|mbs
decl_stmt|;
if|if
condition|(
name|ps
operator|==
name|NULL
condition|)
name|ps
operator|=
operator|&
name|mbs
expr_stmt|;
return|return
operator|(
name|__mbsnrtowcs
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|SIZE_T_MAX
argument_list|,
name|len
argument_list|,
name|ps
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

