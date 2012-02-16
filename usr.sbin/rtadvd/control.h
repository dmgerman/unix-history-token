begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2011 Hiroki Sato<hrs@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_define
define|#
directive|define
name|SOCK_BACKLOG
value|5
end_define

begin_define
define|#
directive|define
name|CM_MSG_MAXLEN
value|8192
end_define

begin_define
define|#
directive|define
name|CM_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|CM_VERSION_STR
value|"1.0"
end_define

begin_define
define|#
directive|define
name|CM_TYPE_EOM
value|0
end_define

begin_define
define|#
directive|define
name|CM_TYPE_ACK
value|1
end_define

begin_define
define|#
directive|define
name|CM_TYPE_ERR
value|2
end_define

begin_define
define|#
directive|define
name|CM_TYPE_NUL
value|3
end_define

begin_define
define|#
directive|define
name|CM_TYPE_REQ_SET_PROP
value|4
end_define

begin_define
define|#
directive|define
name|CM_TYPE_REQ_GET_PROP
value|5
end_define

begin_define
define|#
directive|define
name|CM_TYPE_MAX
value|6
end_define

begin_define
define|#
directive|define
name|CM_STATE_EOM
value|0
end_define

begin_define
define|#
directive|define
name|CM_STATE_INIT
value|1
end_define

begin_define
define|#
directive|define
name|CM_STATE_MSG_DISPATCH
value|2
end_define

begin_define
define|#
directive|define
name|CM_STATE_MSG_RECV
value|3
end_define

begin_define
define|#
directive|define
name|CM_STATE_ACK_WAIT
value|4
end_define

begin_struct
struct|struct
name|ctrl_msg_hdr
block|{
name|int
name|cm_version
decl_stmt|;
name|size_t
name|cm_len
decl_stmt|;
name|int
name|cm_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctrl_msg_pl
block|{
name|char
modifier|*
name|cp_ifname
decl_stmt|;
name|char
modifier|*
name|cp_key
decl_stmt|;
name|size_t
name|cp_val_len
decl_stmt|;
name|char
modifier|*
name|cp_val
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|csock_open
parameter_list|(
name|struct
name|sockinfo
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|csock_close
parameter_list|(
name|struct
name|sockinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|csock_listen
parameter_list|(
name|struct
name|sockinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|csock_accept
parameter_list|(
name|struct
name|sockinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cm_send
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cm_recv
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|cm_pl2bin
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|ctrl_msg_pl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ctrl_msg_pl
modifier|*
name|cm_bin2pl
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|ctrl_msg_pl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|cm_str2bin
parameter_list|(
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|cm_bin2str
parameter_list|(
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

