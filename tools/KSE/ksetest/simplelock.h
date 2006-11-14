begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 David Xu (davidxu@freebsd.org).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIMPLELOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_SIMPLELOCK_H
end_define

begin_include
include|#
directive|include
file|<machine/asmacros.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_struct
struct|struct
name|simplelock
block|{
name|int
name|s_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|void
name|simplelock_init
parameter_list|(
name|struct
name|simplelock
modifier|*
name|lock
parameter_list|)
block|{
name|lock
operator|->
name|s_lock
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|simplelock_lock
parameter_list|(
name|struct
name|simplelock
modifier|*
name|lock
parameter_list|)
block|{
while|while
condition|(
operator|!
name|atomic_cmpset_int
argument_list|(
operator|&
name|lock
operator|->
name|s_lock
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
condition|)
empty_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|simplelock_unlock
parameter_list|(
name|struct
name|simplelock
modifier|*
name|lock
parameter_list|)
block|{
name|atomic_store_rel_int
argument_list|(
operator|&
name|lock
operator|->
name|s_lock
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

