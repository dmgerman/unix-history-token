begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Copyright (c) 1995 John Hay.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)af.h	5.1 (Berkeley) 6/4/85 (routed/af.h)  *  *	@(#)af.h	8.1 (Berkeley) 6/5/93  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Routing table management daemon.  */
end_comment

begin_comment
comment|/*  * Structure returned by af_hash routines.  */
end_comment

begin_struct
struct|struct
name|afhash
block|{
name|u_int
name|afh_hosthash
decl_stmt|;
comment|/* host based hash */
name|u_int
name|afh_nethash
decl_stmt|;
comment|/* network based hash */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per address family routines.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|af_hash_t
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|afhash
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|af_netmatch_t
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|af_output_t
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|af_portmatch_t
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|af_portcheck_t
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|af_checkhost_t
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|af_ishost_t
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|af_canon_t
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|afswitch
block|{
name|af_hash_t
modifier|*
name|af_hash
decl_stmt|;
comment|/* returns keys based on address */
name|af_netmatch_t
modifier|*
name|af_netmatch
decl_stmt|;
comment|/* verifies net # matching */
name|af_output_t
modifier|*
name|af_output
decl_stmt|;
comment|/* interprets address for sending */
name|af_portmatch_t
modifier|*
name|af_portmatch
decl_stmt|;
comment|/* packet from some other router? */
name|af_portcheck_t
modifier|*
name|af_portcheck
decl_stmt|;
comment|/* packet from privileged peer? */
name|af_checkhost_t
modifier|*
name|af_checkhost
decl_stmt|;
comment|/* tells if address for host or net */
name|af_ishost_t
modifier|*
name|af_ishost
decl_stmt|;
comment|/* tells if address is valid */
name|af_canon_t
modifier|*
name|af_canon
decl_stmt|;
comment|/* canonicalize address for compares */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|afswitch
name|afswitch
index|[
name|AF_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table proper */
end_comment

end_unit

