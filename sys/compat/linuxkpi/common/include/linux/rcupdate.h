begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016-2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<linux/compiler.h>
end_include

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_define
define|#
directive|define
name|LINUX_KFREE_RCU_OFFSET_MAX
value|4096
end_define

begin_comment
comment|/* exclusive */
end_comment

begin_define
define|#
directive|define
name|RCU_INITIALIZER
parameter_list|(
name|v
parameter_list|)
define|\
value|((__typeof(*(v)) *)(v))
end_define

begin_define
define|#
directive|define
name|RCU_INIT_POINTER
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|do {		\ 	(p) = (v);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|call_rcu
parameter_list|(
name|ptr
parameter_list|,
name|func
parameter_list|)
value|do {		\ 	linux_call_rcu(ptr, func);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|rcu_barrier
parameter_list|(
name|void
parameter_list|)
value|do {			\ 	linux_rcu_barrier();			\ } while (0)
end_define

begin_define
define|#
directive|define
name|rcu_read_lock
parameter_list|(
name|void
parameter_list|)
value|do {		\ 	linux_rcu_read_lock();			\ } while (0)
end_define

begin_define
define|#
directive|define
name|rcu_read_unlock
parameter_list|(
name|void
parameter_list|)
value|do {		\ 	linux_rcu_read_unlock();		\ } while (0)
end_define

begin_define
define|#
directive|define
name|synchronize_rcu
parameter_list|(
name|void
parameter_list|)
value|do {	\ 	linux_synchronize_rcu();	\ } while (0)
end_define

begin_define
define|#
directive|define
name|synchronize_rcu_expedited
parameter_list|(
name|void
parameter_list|)
value|do {	\ 	linux_synchronize_rcu();		\ } while (0)
end_define

begin_define
define|#
directive|define
name|kfree_rcu
parameter_list|(
name|ptr
parameter_list|,
name|rcu_head
parameter_list|)
value|do {				\ 	CTASSERT(offsetof(__typeof(*(ptr)), rcu_head)<		\ 	    LINUX_KFREE_RCU_OFFSET_MAX);			\ 	call_rcu(&(ptr)->rcu_head, (rcu_callback_t)(uintptr_t)	\ 	    offsetof(__typeof(*(ptr)), rcu_head));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|rcu_access_pointer
parameter_list|(
name|p
parameter_list|)
define|\
value|((__typeof(*p) *)(READ_ONCE(p)))
end_define

begin_define
define|#
directive|define
name|rcu_dereference_protected
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
define|\
value|((__typeof(*p) *)(p))
end_define

begin_define
define|#
directive|define
name|rcu_dereference
parameter_list|(
name|p
parameter_list|)
define|\
value|rcu_dereference_protected(p, 0)
end_define

begin_define
define|#
directive|define
name|rcu_pointer_handoff
parameter_list|(
name|p
parameter_list|)
value|(p)
end_define

begin_define
define|#
directive|define
name|rcu_assign_pointer
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|do {				\ 	atomic_store_rel_ptr((volatile uintptr_t *)&(p),	\ 	    (uintptr_t)(v));					\ } while (0)
end_define

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
specifier|extern
name|void
name|linux_call_rcu
parameter_list|(
name|struct
name|rcu_head
modifier|*
name|ptr
parameter_list|,
name|rcu_callback_t
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|linux_rcu_barrier
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|linux_rcu_read_lock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|linux_rcu_read_unlock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|linux_synchronize_rcu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_RCUPDATE_H_ */
end_comment

end_unit

