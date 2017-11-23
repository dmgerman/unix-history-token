begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: radix_mpath.h,v 1.10 2004/11/06 15:44:28 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (C) 2001 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * THE AUTHORS DO NOT GUARANTEE THAT THIS SOFTWARE DOES NOT INFRINGE  * ANY OTHERS' INTELLECTUAL PROPERTIES. IN NO EVENT SHALL THE AUTHORS  * BE LIABLE FOR ANY INFRINGEMENT OF ANY OTHERS' INTELLECTUAL  * PROPERTIES.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_RADIX_MPATH_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_RADIX_MPATH_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Radix tree API with multipath support  */
end_comment

begin_struct_decl
struct_decl|struct
name|route
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rtentry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rib_head
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|rt_mpath_capable
parameter_list|(
name|struct
name|rib_head
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rn_mpath_capable
parameter_list|(
name|struct
name|radix_head
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|radix_node
modifier|*
name|rn_mpath_next
parameter_list|(
name|struct
name|radix_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|rn_mpath_count
parameter_list|(
name|struct
name|radix_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rtentry
modifier|*
name|rt_mpath_matchgate
parameter_list|(
name|struct
name|rtentry
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rt_mpath_conflict
parameter_list|(
name|struct
name|rib_head
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtalloc_mpath_fib
parameter_list|(
name|struct
name|route
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rtentry
modifier|*
name|rt_mpath_select
parameter_list|(
name|struct
name|rtentry
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rt_mpath_deldup
parameter_list|(
name|struct
name|rtentry
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rn4_mpath_inithead
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rn6_mpath_inithead
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_RADIX_MPATH_H_ */
end_comment

end_unit

