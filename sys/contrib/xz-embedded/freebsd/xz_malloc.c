begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2012 Aleksandr Rybalko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|"xz_malloc.h"
end_include

begin_comment
comment|/* Wraper for XZ decompressor memmory pool */
end_comment

begin_expr_stmt
specifier|static
name|MALLOC_DEFINE
argument_list|(
name|XZ_DEC
argument_list|,
literal|"XZ_DEC"
argument_list|,
literal|"XZ decompressor data"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
modifier|*
name|xz_malloc
parameter_list|(
name|unsigned
name|long
name|size
parameter_list|)
block|{
name|void
modifier|*
name|addr
decl_stmt|;
name|addr
operator|=
name|malloc
argument_list|(
name|size
argument_list|,
name|XZ_DEC
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
return|return
operator|(
name|addr
operator|)
return|;
block|}
end_function

begin_function
name|void
name|xz_free
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|free
argument_list|(
name|addr
argument_list|,
name|XZ_DEC
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

