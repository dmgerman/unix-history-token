begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNCP_NCP_NCP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNCP_NCP_NCP_H_
end_define

begin_define
define|#
directive|define
name|NCP_ALLOC_SLOT
value|0x1111
end_define

begin_define
define|#
directive|define
name|NCP_REQUEST
value|0x2222
end_define

begin_define
define|#
directive|define
name|NCP_REPLY
value|0x3333
end_define

begin_define
define|#
directive|define
name|NCP_FREE_SLOT
value|0x5555
end_define

begin_define
define|#
directive|define
name|NCP_PACKET_BURST
value|0x7777
end_define

begin_define
define|#
directive|define
name|NCP_POSITIVE_ACK
value|0x9999
end_define

begin_comment
comment|/*  * Bits for connection state field in ncp_rphdr  */
end_comment

begin_define
define|#
directive|define
name|NCP_CS_BAD_CONN
value|0x01
end_define

begin_comment
comment|/* no such connection */
end_comment

begin_define
define|#
directive|define
name|NCP_CS_NO_SLOTS
value|0x04
end_define

begin_comment
comment|/* no connection slots available */
end_comment

begin_define
define|#
directive|define
name|NCP_CS_SERVER_DOWN
value|0x10
end_define

begin_comment
comment|/* server in down state */
end_comment

begin_define
define|#
directive|define
name|NCP_CS_HAVE_BROADCAST
value|0x40
end_define

begin_comment
comment|/* server holds broadcast for us */
end_comment

begin_define
define|#
directive|define
name|NCP_RETRY_COUNT
value|5
end_define

begin_define
define|#
directive|define
name|NCP_RETRY_TIMEOUT
value|10
end_define

begin_define
define|#
directive|define
name|NCP_RESTORE_COUNT
value|2
end_define

begin_comment
comment|/* how many times try to restore per  					 * single request, should be an _even_ */
end_comment

begin_struct
struct|struct
name|ncp_rqhdr
block|{
name|u_int16_t
name|type
decl_stmt|;
name|u_int8_t
name|seq
decl_stmt|;
name|u_int8_t
name|conn_low
decl_stmt|;
name|u_int8_t
name|task
decl_stmt|;
name|u_int8_t
name|conn_high
decl_stmt|;
name|u_int8_t
name|fn
decl_stmt|;
name|u_int8_t
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|ncp_rphdr
block|{
name|u_int16_t
name|type
decl_stmt|;
name|u_int8_t
name|seq
decl_stmt|;
name|u_int8_t
name|conn_low
decl_stmt|;
name|u_int8_t
name|task
decl_stmt|;
name|u_int8_t
name|conn_high
decl_stmt|;
name|u_int8_t
name|completion_code
decl_stmt|;
name|u_int8_t
name|connection_state
decl_stmt|;
name|u_int8_t
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|BFL_ABT
value|0x04
end_define

begin_define
define|#
directive|define
name|BFL_EOB
value|0x10
end_define

begin_define
define|#
directive|define
name|BFL_SYS
value|0x80
end_define

begin_define
define|#
directive|define
name|BOP_READ
value|1L
end_define

begin_define
define|#
directive|define
name|BOP_WRITE
value|2L
end_define

begin_define
define|#
directive|define
name|BERR_NONE
value|0
end_define

begin_define
define|#
directive|define
name|BERR_INIT
value|1
end_define

begin_define
define|#
directive|define
name|BERR_IO
value|2
end_define

begin_define
define|#
directive|define
name|BERR_NODATA
value|3
end_define

begin_define
define|#
directive|define
name|BERR_WRITE
value|4
end_define

begin_struct
struct|struct
name|ncp_bursthdr
block|{
name|u_short
name|bh_type
decl_stmt|;
name|u_char
name|bh_flags
decl_stmt|;
name|u_char
name|bh_streamtype
decl_stmt|;
name|u_long
name|bh_srcid
decl_stmt|;
name|u_long
name|bh_dstid
decl_stmt|;
name|u_long
name|bh_seq
decl_stmt|;
comment|/* HL */
name|u_long
name|bh_send_delay
decl_stmt|;
comment|/* HL */
name|u_short
name|bh_bseq
decl_stmt|;
comment|/* HL */
name|u_short
name|bh_aseq
decl_stmt|;
comment|/* HL */
name|u_long
name|bh_blen
decl_stmt|;
comment|/* HL */
name|u_long
name|bh_dofs
decl_stmt|;
comment|/* HL */
name|u_short
name|bh_dlen
decl_stmt|;
comment|/* HL */
name|u_short
name|bh_misfrags
decl_stmt|;
comment|/* HL */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ncp_conn
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ncp_conn_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ncp_rq
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ncp_request
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|,
name|struct
name|ncp_rq
modifier|*
name|rqp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_ncp_connect
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_ncp_disconnect
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_reconnect
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_connect
parameter_list|(
name|struct
name|ncp_conn_args
modifier|*
name|li
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|ncp_conn
modifier|*
modifier|*
name|aconn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_disconnect
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_login
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|,
name|char
modifier|*
name|user
parameter_list|,
name|int
name|objtype
parameter_list|,
name|char
modifier|*
name|password
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NCP_NCP_H_ */
end_comment

end_unit

