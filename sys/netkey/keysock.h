begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: keysock.h,v 1.8 2000/03/27 05:11:06 sumikawa Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETKEY_KEYSOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETKEY_KEYSOCK_H_
end_define

begin_comment
comment|/* statistics for pfkey socket */
end_comment

begin_struct
struct|struct
name|pfkeystat
block|{
comment|/* kernel -> userland */
name|u_quad_t
name|out_total
decl_stmt|;
comment|/* # of total calls */
name|u_quad_t
name|out_bytes
decl_stmt|;
comment|/* total bytecount */
name|u_quad_t
name|out_msgtype
index|[
literal|256
index|]
decl_stmt|;
comment|/* message type histogram */
name|u_quad_t
name|out_invlen
decl_stmt|;
comment|/* invalid length field */
name|u_quad_t
name|out_invver
decl_stmt|;
comment|/* invalid version field */
name|u_quad_t
name|out_invmsgtype
decl_stmt|;
comment|/* invalid message type field */
name|u_quad_t
name|out_tooshort
decl_stmt|;
comment|/* msg too short */
name|u_quad_t
name|out_nomem
decl_stmt|;
comment|/* memory allocation failure */
name|u_quad_t
name|out_dupext
decl_stmt|;
comment|/* duplicate extension */
name|u_quad_t
name|out_invexttype
decl_stmt|;
comment|/* invalid extension type */
name|u_quad_t
name|out_invsatype
decl_stmt|;
comment|/* invalid sa type */
name|u_quad_t
name|out_invaddr
decl_stmt|;
comment|/* invalid address extension */
comment|/* userland -> kernel */
name|u_quad_t
name|in_total
decl_stmt|;
comment|/* # of total calls */
name|u_quad_t
name|in_bytes
decl_stmt|;
comment|/* total bytecount */
name|u_quad_t
name|in_msgtype
index|[
literal|256
index|]
decl_stmt|;
comment|/* message type histogram */
name|u_quad_t
name|in_msgtarget
index|[
literal|3
index|]
decl_stmt|;
comment|/* one/all/registered */
name|u_quad_t
name|in_nomem
decl_stmt|;
comment|/* memory allocation failure */
comment|/* others */
name|u_quad_t
name|sockerr
decl_stmt|;
comment|/* # of socket related errors */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KEY_SENDUP_ONE
value|0
end_define

begin_define
define|#
directive|define
name|KEY_SENDUP_ALL
value|1
end_define

begin_define
define|#
directive|define
name|KEY_SENDUP_REGISTERED
value|2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|keycb
block|{
name|struct
name|rawcb
name|kp_raw
decl_stmt|;
comment|/* rawcb */
name|int
name|kp_promisc
decl_stmt|;
comment|/* promiscuous mode */
name|int
name|kp_registered
decl_stmt|;
comment|/* registered socket */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|pfkeystat
name|pfkeystat
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|key_output
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|key_usrreq
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|key_sendup
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sadb_msg
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|key_sendup_mbuf
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|mbuf
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

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_NETKEY_KEYSOCK_H_*/
end_comment

end_unit

