begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: builtin.c,v 1.1 2012/05/26 22:02:29 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2012 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: builtin.c,v 1.1 2012/05/26 22:02:29 christos Exp $"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"execinfo.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__MACHINE_STACK_GROWS_UP
end_ifdef

begin_define
define|#
directive|define
name|BELOW
value|>
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BELOW
value|<
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__lint__
end_ifdef

begin_define
define|#
directive|define
name|__builtin_frame_address
parameter_list|(
name|a
parameter_list|)
value|((void *)a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|frameinfo
block|{
name|struct
name|frameinfo
modifier|*
name|next
decl_stmt|;
name|void
modifier|*
name|return_address
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|size_t
name|backtrace
parameter_list|(
name|void
modifier|*
modifier|*
name|trace
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
specifier|const
name|struct
name|frameinfo
modifier|*
name|frame
init|=
name|__builtin_frame_address
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|void
modifier|*
name|stack
init|=
operator|&
name|stack
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
specifier|const
name|void
operator|*
operator|)
name|frame
name|BELOW
name|stack
condition|)
return|return
name|i
return|;
name|trace
index|[
name|i
index|]
operator|=
name|frame
operator|->
name|return_address
expr_stmt|;
name|frame
operator|=
name|frame
operator|->
name|next
expr_stmt|;
block|}
return|return
name|len
return|;
block|}
end_function

end_unit

