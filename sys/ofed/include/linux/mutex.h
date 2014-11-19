begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_MUTEX_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_MUTEX_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<linux/spinlock.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|mutex
block|{
name|struct
name|sx
name|sx
decl_stmt|;
block|}
name|mutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|mutex_lock
parameter_list|(
name|_m
parameter_list|)
value|sx_xlock(&(_m)->sx)
end_define

begin_define
define|#
directive|define
name|mutex_lock_nested
parameter_list|(
name|_m
parameter_list|,
name|_s
parameter_list|)
value|mutex_lock(_m)
end_define

begin_define
define|#
directive|define
name|mutex_lock_interruptible
parameter_list|(
name|_m
parameter_list|)
value|({ mutex_lock((_m)); 0; })
end_define

begin_define
define|#
directive|define
name|mutex_unlock
parameter_list|(
name|_m
parameter_list|)
value|sx_xunlock(&(_m)->sx)
end_define

begin_define
define|#
directive|define
name|mutex_trylock
parameter_list|(
name|_m
parameter_list|)
value|!!sx_try_xlock(&(_m)->sx)
end_define

begin_define
define|#
directive|define
name|DEFINE_MUTEX
parameter_list|(
name|lock
parameter_list|)
define|\
value|mutex_t lock;							\ 	SX_SYSINIT_FLAGS(lock,&(lock).sx, "lnxmtx", SX_NOWITNESS)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|linux_mutex_init
parameter_list|(
name|mutex_t
modifier|*
name|m
parameter_list|)
block|{
name|memset
argument_list|(
operator|&
name|m
operator|->
name|sx
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|m
operator|->
name|sx
argument_list|)
argument_list|)
expr_stmt|;
name|sx_init_flags
argument_list|(
operator|&
name|m
operator|->
name|sx
argument_list|,
literal|"lnxmtx"
argument_list|,
name|SX_NOWITNESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|mutex_init
value|linux_mutex_init
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_MUTEX_H_ */
end_comment

end_unit

