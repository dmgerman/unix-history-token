begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1998 Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TACLIB_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|TACLIB_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|"taclib.h"
end_include

begin_comment
comment|/* Defaults */
end_comment

begin_define
define|#
directive|define
name|PATH_TACPLUS_CONF
value|"/etc/tacplus.conf"
end_define

begin_define
define|#
directive|define
name|TACPLUS_PORT
value|49
end_define

begin_define
define|#
directive|define
name|TIMEOUT
value|3
end_define

begin_comment
comment|/* In seconds */
end_comment

begin_comment
comment|/* Limits */
end_comment

begin_define
define|#
directive|define
name|BODYSIZE
value|8150
end_define

begin_comment
comment|/* Maximum message body size */
end_comment

begin_define
define|#
directive|define
name|ERRSIZE
value|128
end_define

begin_comment
comment|/* Maximum error message length */
end_comment

begin_define
define|#
directive|define
name|MAXCONFLINE
value|1024
end_define

begin_comment
comment|/* Maximum config file line length */
end_comment

begin_define
define|#
directive|define
name|MAXSERVERS
value|10
end_define

begin_comment
comment|/* Maximum number of servers to try */
end_comment

begin_comment
comment|/* Protocol constants. */
end_comment

begin_define
define|#
directive|define
name|HDRSIZE
value|12
end_define

begin_comment
comment|/* Size of message header */
end_comment

begin_comment
comment|/* Protocol version number */
end_comment

begin_define
define|#
directive|define
name|TAC_VER_MAJOR
value|0xc
end_define

begin_comment
comment|/* Major version number */
end_comment

begin_comment
comment|/* Protocol packet types */
end_comment

begin_define
define|#
directive|define
name|TAC_AUTHEN
value|0x01
end_define

begin_comment
comment|/* Authentication */
end_comment

begin_define
define|#
directive|define
name|TAC_AUTHOR
value|0x02
end_define

begin_comment
comment|/* Authorization */
end_comment

begin_define
define|#
directive|define
name|TAC_ACCT
value|0x03
end_define

begin_comment
comment|/* Accouting */
end_comment

begin_comment
comment|/* Protocol header flags */
end_comment

begin_define
define|#
directive|define
name|TAC_UNENCRYPTED
value|0x01
end_define

begin_define
define|#
directive|define
name|TAC_SINGLE_CONNECT
value|0x04
end_define

begin_struct
struct|struct
name|tac_server
block|{
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
comment|/* Address of server */
name|char
modifier|*
name|secret
decl_stmt|;
comment|/* Shared secret */
name|int
name|timeout
decl_stmt|;
comment|/* Timeout in seconds */
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * An optional string of bytes specified by the client for inclusion in  * a request.  The data is always a dynamically allocated copy that  * belongs to the library.  It is copied into the request packet just  * before sending the request.  */
end_comment

begin_struct
struct|struct
name|clnt_str
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * An optional string of bytes from a server response.  The data resides  * in the response packet itself, and must not be freed.  */
end_comment

begin_struct
struct|struct
name|srvr_str
block|{
specifier|const
name|void
modifier|*
name|data
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tac_authen_start
block|{
name|u_int8_t
name|action
decl_stmt|;
name|u_int8_t
name|priv_lvl
decl_stmt|;
name|u_int8_t
name|authen_type
decl_stmt|;
name|u_int8_t
name|service
decl_stmt|;
name|u_int8_t
name|user_len
decl_stmt|;
name|u_int8_t
name|port_len
decl_stmt|;
name|u_int8_t
name|rem_addr_len
decl_stmt|;
name|u_int8_t
name|data_len
decl_stmt|;
name|unsigned
name|char
name|rest
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tac_authen_reply
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int16_t
name|msg_len
decl_stmt|;
name|u_int16_t
name|data_len
decl_stmt|;
name|unsigned
name|char
name|rest
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tac_authen_cont
block|{
name|u_int16_t
name|user_msg_len
decl_stmt|;
name|u_int16_t
name|data_len
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|unsigned
name|char
name|rest
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tac_msg
block|{
name|u_int8_t
name|version
decl_stmt|;
name|u_int8_t
name|type
decl_stmt|;
name|u_int8_t
name|seq_no
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int8_t
name|session_id
index|[
literal|4
index|]
decl_stmt|;
name|u_int32_t
name|length
decl_stmt|;
union|union
block|{
name|struct
name|tac_authen_start
name|authen_start
decl_stmt|;
name|struct
name|tac_authen_reply
name|authen_reply
decl_stmt|;
name|struct
name|tac_authen_cont
name|authen_cont
decl_stmt|;
name|unsigned
name|char
name|body
index|[
name|BODYSIZE
index|]
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tac_handle
block|{
name|int
name|fd
decl_stmt|;
comment|/* Socket file descriptor */
name|struct
name|tac_server
name|servers
index|[
name|MAXSERVERS
index|]
decl_stmt|;
comment|/* Servers to contact */
name|int
name|num_servers
decl_stmt|;
comment|/* Number of valid server entries */
name|int
name|cur_server
decl_stmt|;
comment|/* Server we are currently using */
name|int
name|single_connect
decl_stmt|;
comment|/* Use a single connection */
name|int
name|last_seq_no
decl_stmt|;
name|char
name|errmsg
index|[
name|ERRSIZE
index|]
decl_stmt|;
comment|/* Most recent error message */
name|struct
name|clnt_str
name|user
decl_stmt|;
name|struct
name|clnt_str
name|port
decl_stmt|;
name|struct
name|clnt_str
name|rem_addr
decl_stmt|;
name|struct
name|clnt_str
name|data
decl_stmt|;
name|struct
name|clnt_str
name|user_msg
decl_stmt|;
name|struct
name|tac_msg
name|request
decl_stmt|;
name|struct
name|tac_msg
name|response
decl_stmt|;
name|int
name|srvr_pos
decl_stmt|;
comment|/* Scan position in response body */
name|struct
name|srvr_str
name|srvr_msg
decl_stmt|;
name|struct
name|srvr_str
name|srvr_data
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

