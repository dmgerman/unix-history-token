begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/proc.h>
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

begin_comment
comment|/*  * By defining CONFIG_NO_MUTEX_SKIP LinuxKPI mutexes and asserts will  * not be skipped during panic().  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NO_MUTEX_SKIP
end_ifdef

begin_define
define|#
directive|define
name|MUTEX_SKIP
parameter_list|(
name|void
parameter_list|)
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MUTEX_SKIP
parameter_list|(
name|void
parameter_list|)
value|unlikely(SCHEDULER_STOPPED() || kdb_active)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mutex_lock
parameter_list|(
name|_m
parameter_list|)
value|do {			\ 	if (MUTEX_SKIP())			\ 		break;				\ 	sx_xlock(&(_m)->sx);			\ } while (0)
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
name|mutex_lock_nest_lock
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
value|({		\ 	MUTEX_SKIP() ? 0 :			\ 	(sx_xlock_sig(&(_m)->sx) ? -EINTR : 0);	\ })
end_define

begin_define
define|#
directive|define
name|mutex_unlock
parameter_list|(
name|_m
parameter_list|)
value|do {			\ 	if (MUTEX_SKIP())			\ 		break;				\ 	sx_xunlock(&(_m)->sx);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|mutex_trylock
parameter_list|(
name|_m
parameter_list|)
value|({			\ 	MUTEX_SKIP() ? 1 :			\ 	!!sx_try_xlock(&(_m)->sx);		\ })
end_define

begin_define
define|#
directive|define
name|mutex_init
parameter_list|(
name|_m
parameter_list|)
define|\
value|linux_mutex_init(_m, mutex_name(#_m), SX_NOWITNESS)
end_define

begin_define
define|#
directive|define
name|mutex_init_witness
parameter_list|(
name|_m
parameter_list|)
define|\
value|linux_mutex_init(_m, mutex_name(#_m), SX_DUPOK)
end_define

begin_define
define|#
directive|define
name|mutex_destroy
parameter_list|(
name|_m
parameter_list|)
define|\
value|linux_mutex_destroy(_m)
end_define

begin_function
specifier|static
specifier|inline
name|bool
name|mutex_is_locked
parameter_list|(
name|mutex_t
modifier|*
name|m
parameter_list|)
block|{
return|return
operator|(
operator|(
expr|struct
name|thread
operator|*
operator|)
name|SX_OWNER
argument_list|(
name|m
operator|->
name|sx
operator|.
name|sx_lock
argument_list|)
operator|!=
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|bool
name|mutex_is_owned
parameter_list|(
name|mutex_t
modifier|*
name|m
parameter_list|)
block|{
return|return
operator|(
name|sx_xlocked
argument_list|(
operator|&
name|m
operator|->
name|sx
argument_list|)
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|WITNESS_ALL
end_ifdef

begin_comment
comment|/* NOTE: the maximum WITNESS name is 64 chars */
end_comment

begin_define
define|#
directive|define
name|__mutex_name
parameter_list|(
name|name
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|(((const char *){file ":" #line "-" name}) + 	\ 	(sizeof(file)> 16 ? sizeof(file) - 16 : 0))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__mutex_name
parameter_list|(
name|name
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_mutex_name
parameter_list|(
modifier|...
parameter_list|)
value|__mutex_name(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|mutex_name
parameter_list|(
name|name
parameter_list|)
value|_mutex_name(name, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|DEFINE_MUTEX
parameter_list|(
name|lock
parameter_list|)
define|\
value|mutex_t lock;							\ 	SX_SYSINIT_FLAGS(lock,&(lock).sx, mutex_name(#lock), SX_DUPOK)
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
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|memset
argument_list|(
name|m
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|m
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
name|name
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|linux_mutex_destroy
parameter_list|(
name|mutex_t
modifier|*
name|m
parameter_list|)
block|{
if|if
condition|(
name|mutex_is_owned
argument_list|(
name|m
argument_list|)
condition|)
name|mutex_unlock
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|sx_destroy
argument_list|(
operator|&
name|m
operator|->
name|sx
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_MUTEX_H_ */
end_comment

end_unit

