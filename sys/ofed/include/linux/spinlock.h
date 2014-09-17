begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_SPINLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_SPINLOCK_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<linux/compiler.h>
end_include

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_include
include|#
directive|include
file|<linux/rwlock.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|mtx
name|m
decl_stmt|;
block|}
name|spinlock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|spin_lock
parameter_list|(
name|_l
parameter_list|)
value|mtx_lock(&(_l)->m)
end_define

begin_define
define|#
directive|define
name|spin_unlock
parameter_list|(
name|_l
parameter_list|)
value|mtx_unlock(&(_l)->m)
end_define

begin_define
define|#
directive|define
name|spin_trylock
parameter_list|(
name|_l
parameter_list|)
value|mtx_trylock(&(_l)->m)
end_define

begin_define
define|#
directive|define
name|spin_lock_nested
parameter_list|(
name|_l
parameter_list|,
name|_n
parameter_list|)
value|mtx_lock_flags(&(_l)->m, MTX_DUPOK)
end_define

begin_define
define|#
directive|define
name|spin_lock_irq
parameter_list|(
name|lock
parameter_list|)
value|spin_lock(lock)
end_define

begin_define
define|#
directive|define
name|spin_unlock_irq
parameter_list|(
name|lock
parameter_list|)
value|spin_unlock(lock)
end_define

begin_define
define|#
directive|define
name|spin_lock_irqsave
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|)
define|\
value|do {(flags) = 0; spin_lock(lock); } while (0)
end_define

begin_define
define|#
directive|define
name|spin_unlock_irqrestore
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|)
define|\
value|do { spin_unlock(lock); } while (0)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|spin_lock_init
parameter_list|(
name|spinlock_t
modifier|*
name|lock
parameter_list|)
block|{
name|memset
argument_list|(
operator|&
name|lock
operator|->
name|m
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|lock
operator|->
name|m
argument_list|)
argument_list|)
expr_stmt|;
name|mtx_init
argument_list|(
operator|&
name|lock
operator|->
name|m
argument_list|,
literal|"lnxspin"
argument_list|,
name|NULL
argument_list|,
name|MTX_DEF
operator||
name|MTX_NOWITNESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|DEFINE_SPINLOCK
parameter_list|(
name|lock
parameter_list|)
define|\
value|spinlock_t lock;						\ 	MTX_SYSINIT(lock,&(lock).m, "lnxspin", MTX_DEF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_SPINLOCK_H_ */
end_comment

end_unit

