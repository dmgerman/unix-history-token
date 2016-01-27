begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_RCUPDATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_RCUPDATE_H_
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

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|linux_global_rcu_lock
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|rcu_head
block|{ }
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|rcu_callback_t
function_decl|)
parameter_list|(
name|struct
name|rcu_head
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function
specifier|static
specifier|inline
name|void
name|call_rcu
parameter_list|(
name|struct
name|rcu_head
modifier|*
name|ptr
parameter_list|,
name|rcu_callback_t
name|func
parameter_list|)
block|{
name|sx_xlock
argument_list|(
operator|&
name|linux_global_rcu_lock
argument_list|)
expr_stmt|;
name|func
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
name|sx_xunlock
argument_list|(
operator|&
name|linux_global_rcu_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|rcu_read_lock
parameter_list|(
name|void
parameter_list|)
block|{
name|sx_slock
argument_list|(
operator|&
name|linux_global_rcu_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|rcu_read_unlock
parameter_list|(
name|void
parameter_list|)
block|{
name|sx_sunlock
argument_list|(
operator|&
name|linux_global_rcu_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|rcu_barrier
parameter_list|(
name|void
parameter_list|)
block|{
name|sx_xlock
argument_list|(
operator|&
name|linux_global_rcu_lock
argument_list|)
expr_stmt|;
name|sx_xunlock
argument_list|(
operator|&
name|linux_global_rcu_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|synchronize_rcu
parameter_list|(
name|void
parameter_list|)
block|{
name|sx_xlock
argument_list|(
operator|&
name|linux_global_rcu_lock
argument_list|)
expr_stmt|;
name|sx_xunlock
argument_list|(
operator|&
name|linux_global_rcu_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|hlist_add_head_rcu
parameter_list|(
name|n
parameter_list|,
name|h
parameter_list|)
define|\
value|do {						\   	sx_xlock(&linux_global_rcu_lock);	\ 	hlist_add_head(n, h);			\ 	sx_xunlock(&linux_global_rcu_lock);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|hlist_del_init_rcu
parameter_list|(
name|n
parameter_list|)
define|\
value|do {						\     	sx_xlock(&linux_global_rcu_lock);	\ 	hlist_del_init(n);			\ 	sx_xunlock(&linux_global_rcu_lock);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|hlist_del_rcu
parameter_list|(
name|n
parameter_list|)
define|\
value|do {						\     	sx_xlock(&linux_global_rcu_lock);	\ 	hlist_del(n);				\ 	sx_xunlock(&linux_global_rcu_lock);	\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_RCUPDATE_H_ */
end_comment

end_unit

