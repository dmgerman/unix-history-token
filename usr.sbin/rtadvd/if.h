begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: if.h,v 1.10 2003/02/24 11:29:10 ono Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (C) 1995, 1996, 1997, 1998, and 1999 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|UPDATE_IFINFO_ALL
value|0
end_define

begin_struct
struct|struct
name|sockinfo
block|{
name|int
name|si_fd
decl_stmt|;
specifier|const
name|char
modifier|*
name|si_name
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|sockinfo
name|sock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockinfo
name|rtsock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockinfo
name|ctrlsock
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|lladdropt_length
parameter_list|(
name|struct
name|sockaddr_dl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lladdropt_fill
parameter_list|(
name|struct
name|sockaddr_dl
modifier|*
parameter_list|,
name|struct
name|nd_opt_hdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rtbuf_len
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_next_msg
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in6_addr
modifier|*
name|get_addr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_rtm_ifindex
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_prefixlen
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prefixlen
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifinfo
modifier|*
name|update_ifinfo
parameter_list|(
name|struct
name|ifilist_head_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|update_ifinfo_nd_flags
parameter_list|(
name|struct
name|ifinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifinfo
modifier|*
name|update_persist_ifinfo
parameter_list|(
name|struct
name|ifilist_head_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sock_mc_join
parameter_list|(
name|struct
name|sockinfo
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sock_mc_leave
parameter_list|(
name|struct
name|sockinfo
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sock_mc_rr_update
parameter_list|(
name|struct
name|sockinfo
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getinet6sysctl
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

