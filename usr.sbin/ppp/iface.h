begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct_decl
struct_decl|struct
name|ifa_msghdr
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|iface_addr
block|{
name|struct
name|in_addr
name|ifa
decl_stmt|;
comment|/* local address */
name|struct
name|in_addr
name|mask
decl_stmt|;
comment|/* netmask */
name|int
name|bits
decl_stmt|;
comment|/* netmask bits - -1 if not contiguous */
name|struct
name|in_addr
name|brd
decl_stmt|;
comment|/* peer address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iface
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Interface name (malloc'd) */
name|int
name|index
decl_stmt|;
comment|/* Interface index */
name|int
name|flags
decl_stmt|;
comment|/* Interface flags (IFF_*) */
name|int
name|mtu
decl_stmt|;
comment|/* struct tuninfo MTU */
name|int
name|in_addrs
decl_stmt|;
comment|/* How many in_addr's */
name|struct
name|iface_addr
modifier|*
name|in_addr
decl_stmt|;
comment|/* Array of addresses (malloc'd) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IFACE_CLEAR_ALL
value|0
end_define

begin_comment
comment|/* Nuke 'em all */
end_comment

begin_define
define|#
directive|define
name|IFACE_CLEAR_ALIASES
value|1
end_define

begin_comment
comment|/* Leave the IPCP address */
end_comment

begin_define
define|#
directive|define
name|IFACE_ADD_LAST
value|0
end_define

begin_comment
comment|/* Just another alias */
end_comment

begin_define
define|#
directive|define
name|IFACE_ADD_FIRST
value|1
end_define

begin_comment
comment|/* The IPCP address */
end_comment

begin_define
define|#
directive|define
name|IFACE_FORCE_ADD
value|2
end_define

begin_comment
comment|/* OR'd with IFACE_ADD_{FIRST,LAST} */
end_comment

begin_define
define|#
directive|define
name|iface_Clear
value|iface_inClear
end_define

begin_comment
comment|/* Same for now */
end_comment

begin_function_decl
specifier|extern
name|struct
name|iface
modifier|*
name|iface_Create
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iface_inClear
parameter_list|(
name|struct
name|iface
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iface_inAdd
parameter_list|(
name|struct
name|iface
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iface_inDelete
parameter_list|(
name|struct
name|iface
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iface_Show
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iface_SetFlags
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iface_ClearFlags
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iface_Destroy
parameter_list|(
name|struct
name|iface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iface_ParseHdr
parameter_list|(
name|struct
name|ifa_msghdr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
type|[
function_decl|RTAX_MAX]
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

end_unit

