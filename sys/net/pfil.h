begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: pfil.h,v 1.22 2003/06/23 12:57:08 martin Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996 Matthew R. Green  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_PFIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_PFIL_H_
end_define

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/rmlock.h>
end_include

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The packet filter hooks are designed for anything to call them to  * possibly intercept the packet.  */
end_comment

begin_struct
struct|struct
name|packet_filter_hook
block|{
name|TAILQ_ENTRY
argument_list|(
argument|packet_filter_hook
argument_list|)
name|pfil_link
expr_stmt|;
name|int
function_decl|(
modifier|*
name|pfil_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|pfil_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PFIL_IN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PFIL_OUT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PFIL_WAITOK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PFIL_ALL
value|(PFIL_IN|PFIL_OUT)
end_define

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|pfil_list
argument_list|,
argument|packet_filter_hook
argument_list|)
name|pfil_list_t
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|PFIL_TYPE_AF
value|1
end_define

begin_comment
comment|/* key is AF_* type */
end_comment

begin_define
define|#
directive|define
name|PFIL_TYPE_IFNET
value|2
end_define

begin_comment
comment|/* key is ifnet pointer */
end_comment

begin_struct
struct|struct
name|pfil_head
block|{
name|pfil_list_t
name|ph_in
decl_stmt|;
name|pfil_list_t
name|ph_out
decl_stmt|;
name|int
name|ph_type
decl_stmt|;
name|int
name|ph_nhooks
decl_stmt|;
name|struct
name|rmlock
name|ph_lock
decl_stmt|;
union|union
block|{
name|u_long
name|phu_val
decl_stmt|;
name|void
modifier|*
name|phu_ptr
decl_stmt|;
block|}
name|ph_un
union|;
define|#
directive|define
name|ph_af
value|ph_un.phu_val
define|#
directive|define
name|ph_ifnet
value|ph_un.phu_ptr
name|LIST_ENTRY
argument_list|(
argument|pfil_head
argument_list|)
name|ph_list
expr_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|pfil_add_hook
parameter_list|(
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pfil_head
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfil_remove_hook
parameter_list|(
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pfil_head
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfil_run_hooks
parameter_list|(
name|struct
name|pfil_head
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|inpcb
modifier|*
name|inp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfil_head_register
parameter_list|(
name|struct
name|pfil_head
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfil_head_unregister
parameter_list|(
name|struct
name|pfil_head
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pfil_head
modifier|*
name|pfil_head_get
parameter_list|(
name|int
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PFIL_HOOKED
parameter_list|(
name|p
parameter_list|)
value|((p)->ph_nhooks> 0)
end_define

begin_define
define|#
directive|define
name|PFIL_LOCK_INIT
parameter_list|(
name|p
parameter_list|)
define|\
value|rm_init_flags(&(p)->ph_lock, "PFil hook read/write mutex", RM_RECURSE)
end_define

begin_define
define|#
directive|define
name|PFIL_LOCK_DESTROY
parameter_list|(
name|p
parameter_list|)
value|rm_destroy(&(p)->ph_lock)
end_define

begin_define
define|#
directive|define
name|PFIL_RLOCK
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|rm_rlock(&(p)->ph_lock, (t))
end_define

begin_define
define|#
directive|define
name|PFIL_WLOCK
parameter_list|(
name|p
parameter_list|)
value|rm_wlock(&(p)->ph_lock)
end_define

begin_define
define|#
directive|define
name|PFIL_RUNLOCK
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|rm_runlock(&(p)->ph_lock, (t))
end_define

begin_define
define|#
directive|define
name|PFIL_WUNLOCK
parameter_list|(
name|p
parameter_list|)
value|rm_wunlock(&(p)->ph_lock)
end_define

begin_define
define|#
directive|define
name|PFIL_LIST_LOCK
parameter_list|()
value|mtx_lock(&pfil_global_lock)
end_define

begin_define
define|#
directive|define
name|PFIL_LIST_UNLOCK
parameter_list|()
value|mtx_unlock(&pfil_global_lock)
end_define

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|packet_filter_hook
operator|*
name|pfil_hook_get
argument_list|(
argument|int dir
argument_list|,
argument|struct pfil_head *ph
argument_list|)
block|{
if|if
condition|(
name|dir
operator|==
name|PFIL_IN
condition|)
return|return
operator|(
name|TAILQ_FIRST
argument_list|(
operator|&
name|ph
operator|->
name|ph_in
argument_list|)
operator|)
return|;
elseif|else
if|if
condition|(
name|dir
operator|==
name|PFIL_OUT
condition|)
return|return
operator|(
name|TAILQ_FIRST
argument_list|(
operator|&
name|ph
operator|->
name|ph_out
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_PFIL_H_ */
end_comment

end_unit

