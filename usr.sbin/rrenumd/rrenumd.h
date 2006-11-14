begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: rrenumd.h,v 1.2 2000/07/03 02:54:09 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by WIDE Project and  *    its contributors.  * 4. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|dst_list
block|{
name|struct
name|dst_list
modifier|*
name|dl_next
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|dl_dst
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|dst_list
modifier|*
name|dl_head
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|payload_list
block|{
name|struct
name|payload_list
modifier|*
name|pl_next
decl_stmt|;
name|struct
name|iovec
name|pl_sndiov
decl_stmt|;
name|struct
name|icmp6_router_renum
name|pl_irr
decl_stmt|;
name|struct
name|rr_pco_match
name|pl_rpm
decl_stmt|;
comment|/* currently, support only 1 rr_pco_use field per packet */
name|struct
name|rr_pco_use
name|pl_rpu
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|payload_list
modifier|*
name|pl_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|retry
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|with_v4dest
decl_stmt|,
name|with_v6dest
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEF_VLTIME
value|2592000
end_define

begin_define
define|#
directive|define
name|DEF_PLTIME
value|604800
end_define

end_unit

