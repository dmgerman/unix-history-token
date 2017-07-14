begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 John Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SYS_REFCOUNT_H__
end_ifndef

begin_define
define|#
directive|define
name|__SYS_REFCOUNT_H__
end_define

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KASSERT
parameter_list|(
name|exp
parameter_list|,
name|msg
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|void
name|refcount_init
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|count
parameter_list|,
name|u_int
name|value
parameter_list|)
block|{
operator|*
name|count
operator|=
name|value
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|refcount_acquire
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|count
parameter_list|)
block|{
name|KASSERT
argument_list|(
operator|*
name|count
operator|<
name|UINT_MAX
argument_list|,
operator|(
literal|"refcount %p overflowed"
operator|,
name|count
operator|)
argument_list|)
expr_stmt|;
name|atomic_add_int
argument_list|(
name|count
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|refcount_release
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|count
parameter_list|)
block|{
name|u_int
name|old
decl_stmt|;
name|atomic_thread_fence_rel
argument_list|()
expr_stmt|;
name|old
operator|=
name|atomic_fetchadd_int
argument_list|(
name|count
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|old
operator|>
literal|0
argument_list|,
operator|(
literal|"negative refcount %p"
operator|,
name|count
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|old
operator|>
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* 	 * Last reference.  Signal the user to call the destructor. 	 * 	 * Ensure that the destructor sees all updates.  The fence_rel 	 * at the start of the function synchronized with this fence. 	 */
name|atomic_thread_fence_acq
argument_list|()
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __SYS_REFCOUNT_H__ */
end_comment

end_unit

