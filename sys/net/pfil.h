begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Matthew R. Green  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/queue.h>
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
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|int
name|pfil_flags
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
name|ph_init
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|packet_filter_hook
modifier|*
name|pfil_hook_get
parameter_list|(
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
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|)
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
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|)
parameter_list|,
name|int
parameter_list|,
name|struct
name|pfil_head
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_ipfilter.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|IPFILTER
operator|>
literal|0
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|PFIL_HOOKS
end_ifdef

begin_undef
undef|#
directive|undef
name|PFIL_HOOKS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PFIL_HOOKS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPFILTER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_PFIL_H_ */
end_comment

end_unit

