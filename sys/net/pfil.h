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

begin_include
include|#
directive|include
file|<net/vnet.h>
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

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pfil_func_t
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
end_typedef

begin_comment
comment|/*  * The packet filter hooks are designed for anything to call them to  * possibly intercept the packet.  Multiple filter hooks are chained  * together and after each other in the specified order.  */
end_comment

begin_struct
struct|struct
name|packet_filter_hook
block|{
name|TAILQ_ENTRY
argument_list|(
argument|packet_filter_hook
argument_list|)
name|pfil_chain
expr_stmt|;
name|pfil_func_t
name|pfil_func
decl_stmt|;
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
argument|pfil_chain
argument_list|,
argument|packet_filter_hook
argument_list|)
name|pfil_chain_t
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

begin_define
define|#
directive|define
name|PFIL_FLAG_PRIVATE_LOCK
value|0x01
end_define

begin_comment
comment|/* Personal lock instead of global */
end_comment

begin_comment
comment|/*  * A pfil head is created by each protocol or packet intercept point.  * For packet is then run through the hook chain for inspection.  */
end_comment

begin_struct
struct|struct
name|pfil_head
block|{
name|pfil_chain_t
name|ph_in
decl_stmt|;
name|pfil_chain_t
name|ph_out
decl_stmt|;
name|int
name|ph_type
decl_stmt|;
name|int
name|ph_nhooks
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
name|rwlock_t
name|ph_mtx
decl_stmt|;
else|#
directive|else
name|struct
name|rmlock
modifier|*
name|ph_plock
decl_stmt|;
comment|/* Pointer to the used lock */
name|struct
name|rmlock
name|ph_lock
decl_stmt|;
comment|/* Private lock storage */
name|int
name|flags
decl_stmt|;
endif|#
directive|endif
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

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|rmlock
argument_list|,
name|pfil_lock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_pfil_lock
value|VNET(pfil_lock)
end_define

begin_comment
comment|/* Public functions for pfil hook management by packet filters. */
end_comment

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

begin_function_decl
name|int
name|pfil_add_hook
parameter_list|(
name|pfil_func_t
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
name|pfil_func_t
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

begin_define
define|#
directive|define
name|PFIL_HOOKED
parameter_list|(
name|p
parameter_list|)
value|((p)->ph_nhooks> 0)
end_define

begin_comment
comment|/* Public functions to run the packet inspection by protocols. */
end_comment

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

begin_comment
comment|/* Public functions for pfil head management by protocols. */
end_comment

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

begin_comment
comment|/* Public pfil locking functions for self managed locks by packet filters. */
end_comment

begin_function_decl
name|int
name|pfil_try_rlock
parameter_list|(
name|struct
name|pfil_head
modifier|*
parameter_list|,
name|struct
name|rm_priotracker
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfil_rlock
parameter_list|(
name|struct
name|pfil_head
modifier|*
parameter_list|,
name|struct
name|rm_priotracker
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfil_runlock
parameter_list|(
name|struct
name|pfil_head
modifier|*
parameter_list|,
name|struct
name|rm_priotracker
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfil_wlock
parameter_list|(
name|struct
name|pfil_head
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfil_wunlock
parameter_list|(
name|struct
name|pfil_head
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfil_wowned
parameter_list|(
name|struct
name|pfil_head
modifier|*
name|ph
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_PFIL_H_ */
end_comment

end_unit

