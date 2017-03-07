begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_RWSEM_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_RWSEM_H_
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
file|<sys/libkern.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_struct
struct|struct
name|rw_semaphore
block|{
name|struct
name|sx
name|sx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|down_write
parameter_list|(
name|_rw
parameter_list|)
value|sx_xlock(&(_rw)->sx)
end_define

begin_define
define|#
directive|define
name|up_write
parameter_list|(
name|_rw
parameter_list|)
value|sx_xunlock(&(_rw)->sx)
end_define

begin_define
define|#
directive|define
name|down_read
parameter_list|(
name|_rw
parameter_list|)
value|sx_slock(&(_rw)->sx)
end_define

begin_define
define|#
directive|define
name|up_read
parameter_list|(
name|_rw
parameter_list|)
value|sx_sunlock(&(_rw)->sx)
end_define

begin_define
define|#
directive|define
name|down_read_trylock
parameter_list|(
name|_rw
parameter_list|)
value|!!sx_try_slock(&(_rw)->sx)
end_define

begin_define
define|#
directive|define
name|down_write_trylock
parameter_list|(
name|_rw
parameter_list|)
value|!!sx_try_xlock(&(_rw)->sx)
end_define

begin_define
define|#
directive|define
name|downgrade_write
parameter_list|(
name|_rw
parameter_list|)
value|sx_downgrade(&(_rw)->sx)
end_define

begin_define
define|#
directive|define
name|down_read_nested
parameter_list|(
name|_rw
parameter_list|,
name|_sc
parameter_list|)
value|down_read(_rw)
end_define

begin_define
define|#
directive|define
name|init_rwsem
parameter_list|(
name|_rw
parameter_list|)
value|linux_init_rwsem(_rw, rwsem_name("lnxrwsem"))
end_define

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
name|__rwsem_name
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
name|__rwsem_name
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
name|_rwsem_name
parameter_list|(
modifier|...
parameter_list|)
value|__rwsem_name(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|rwsem_name
parameter_list|(
name|name
parameter_list|)
value|_rwsem_name(name, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|DECLARE_RWSEM
parameter_list|(
name|name
parameter_list|)
define|\
value|struct rw_semaphore name;						\ static void name##_rwsem_init(void *arg)				\ {									\ 	linux_init_rwsem(&name, rwsem_name(#name));			\ }									\ SYSINIT(name, SI_SUB_LOCK, SI_ORDER_SECOND, name##_rwsem_init, NULL)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|linux_init_rwsem
parameter_list|(
name|struct
name|rw_semaphore
modifier|*
name|rw
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|memset
argument_list|(
name|rw
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|rw
argument_list|)
argument_list|)
expr_stmt|;
name|sx_init_flags
argument_list|(
operator|&
name|rw
operator|->
name|sx
argument_list|,
name|name
argument_list|,
name|SX_NOWITNESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_RWSEM_H_ */
end_comment

end_unit

