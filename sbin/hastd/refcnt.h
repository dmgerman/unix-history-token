begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 John Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__REFCNT_H__
end_ifndef

begin_define
define|#
directive|define
name|__REFCNT_H__
end_define

begin_include
include|#
directive|include
file|<stdatomic.h>
end_include

begin_include
include|#
directive|include
file|"pjdlog.h"
end_include

begin_typedef
typedef|typedef
name|atomic_uint
name|refcnt_t
typedef|;
end_typedef

begin_function
specifier|static
name|__inline
name|void
name|refcnt_init
parameter_list|(
name|refcnt_t
modifier|*
name|count
parameter_list|,
name|unsigned
name|int
name|v
parameter_list|)
block|{
name|atomic_init
argument_list|(
name|count
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|refcnt_acquire
parameter_list|(
name|refcnt_t
modifier|*
name|count
parameter_list|)
block|{
name|atomic_fetch_add_explicit
argument_list|(
name|count
argument_list|,
literal|1
argument_list|,
name|memory_order_acquire
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|unsigned
name|int
name|refcnt_release
parameter_list|(
name|refcnt_t
modifier|*
name|count
parameter_list|)
block|{
name|unsigned
name|int
name|old
decl_stmt|;
comment|/* XXX: Should this have a rel membar? */
name|old
operator|=
name|atomic_fetch_sub
argument_list|(
name|count
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|PJDLOG_ASSERT
argument_list|(
name|old
operator|>
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|old
operator|-
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
comment|/* ! __REFCNT_H__ */
end_comment

end_unit

