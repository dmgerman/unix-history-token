begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_SEMAPHORE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_SEMAPHORE_H_
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
file|<sys/sema.h>
end_include

begin_comment
comment|/*  * XXX BSD semaphores are disused and slow.  They also do not provide a  * sema_wait_sig method.  This must be resolved eventually.  */
end_comment

begin_struct
struct|struct
name|semaphore
block|{
name|struct
name|sema
name|sema
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|down
parameter_list|(
name|_sem
parameter_list|)
value|sema_wait(&(_sem)->sema)
end_define

begin_define
define|#
directive|define
name|down_interruptible
parameter_list|(
name|_sem
parameter_list|)
value|sema_wait(&(_sem)->sema), 0
end_define

begin_define
define|#
directive|define
name|down_trylock
parameter_list|(
name|_sem
parameter_list|)
value|!sema_trywait(&(_sem)->sema)
end_define

begin_define
define|#
directive|define
name|up
parameter_list|(
name|_sem
parameter_list|)
value|sema_post(&(_sem)->sema)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|linux_sema_init
parameter_list|(
name|struct
name|semaphore
modifier|*
name|sem
parameter_list|,
name|int
name|val
parameter_list|)
block|{
name|memset
argument_list|(
operator|&
name|sem
operator|->
name|sema
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|sem
operator|->
name|sema
argument_list|)
argument_list|)
expr_stmt|;
name|sema_init
argument_list|(
operator|&
name|sem
operator|->
name|sema
argument_list|,
name|val
argument_list|,
literal|"lnxsema"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|init_MUTEX
parameter_list|(
name|struct
name|semaphore
modifier|*
name|sem
parameter_list|)
block|{
name|memset
argument_list|(
operator|&
name|sem
operator|->
name|sema
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|sem
operator|->
name|sema
argument_list|)
argument_list|)
expr_stmt|;
name|sema_init
argument_list|(
operator|&
name|sem
operator|->
name|sema
argument_list|,
literal|1
argument_list|,
literal|"lnxsema"
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|sema_init
value|linux_sema_init
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_SEMAPHORE_H_ */
end_comment

end_unit

