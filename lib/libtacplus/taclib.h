begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1998 Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TACLIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_TACLIB_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_struct_decl
struct_decl|struct
name|tac_handle
struct_decl|;
end_struct_decl

begin_comment
comment|/* Flags for tac_add_server(). */
end_comment

begin_define
define|#
directive|define
name|TAC_SRVR_SINGLE_CONNECT
value|0x04
end_define

begin_comment
comment|/* Keep connection open for multiple 					   sessions. */
end_comment

begin_comment
comment|/* Disassembly of tac_send_authen() return value. */
end_comment

begin_define
define|#
directive|define
name|TAC_AUTHEN_STATUS
parameter_list|(
name|s
parameter_list|)
value|((s)& 0xff)
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_NOECHO
parameter_list|(
name|s
parameter_list|)
value|((s)& (1<<8))
end_define

begin_comment
comment|/* Privilege levels */
end_comment

begin_define
define|#
directive|define
name|TAC_PRIV_LVL_MIN
value|0x00
end_define

begin_define
define|#
directive|define
name|TAC_PRIV_LVL_USER
value|0x01
end_define

begin_define
define|#
directive|define
name|TAC_PRIV_LVL_ROOT
value|0x0f
end_define

begin_define
define|#
directive|define
name|TAC_PRIV_LVL_MAX
value|0x0f
end_define

begin_comment
comment|/* Authentication actions */
end_comment

begin_define
define|#
directive|define
name|TAC_AUTHEN_LOGIN
value|0x01
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_CHPASS
value|0x02
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_SENDPASS
value|0x03
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_SENDAUTH
value|0x04
end_define

begin_comment
comment|/* Authentication types */
end_comment

begin_define
define|#
directive|define
name|TAC_AUTHEN_TYPE_ASCII
value|0x01
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_TYPE_PAP
value|0x02
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_TYPE_CHAP
value|0x03
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_TYPE_ARAP
value|0x04
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_TYPE_MSCHAP
value|0x05
end_define

begin_comment
comment|/* Authentication services */
end_comment

begin_define
define|#
directive|define
name|TAC_AUTHEN_SVC_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_SVC_LOGIN
value|0x01
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_SVC_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_SVC_PPP
value|0x03
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_SVC_ARAP
value|0x04
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_SVC_PT
value|0x05
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_SVC_RCMD
value|0x06
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_SVC_X25
value|0x07
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_SVC_NASI
value|0x08
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_SVC_FWPROXY
value|0x09
end_define

begin_comment
comment|/* Authentication reply status codes */
end_comment

begin_define
define|#
directive|define
name|TAC_AUTHEN_STATUS_PASS
value|0x01
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_STATUS_FAIL
value|0x02
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_STATUS_GETDATA
value|0x03
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_STATUS_GETUSER
value|0x04
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_STATUS_GETPASS
value|0x05
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_STATUS_RESTART
value|0x06
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_STATUS_ERROR
value|0x07
end_define

begin_define
define|#
directive|define
name|TAC_AUTHEN_STATUS_FOLLOW
value|0x21
end_define

begin_function_decl
name|__BEGIN_DECLS
name|int
name|tac_add_server
parameter_list|(
name|struct
name|tac_handle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tac_close
parameter_list|(
name|struct
name|tac_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tac_config
parameter_list|(
name|struct
name|tac_handle
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
name|tac_create_authen
parameter_list|(
name|struct
name|tac_handle
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|tac_get_data
parameter_list|(
name|struct
name|tac_handle
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tac_get_msg
parameter_list|(
name|struct
name|tac_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tac_handle
modifier|*
name|tac_open
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tac_send_authen
parameter_list|(
name|struct
name|tac_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tac_set_data
parameter_list|(
name|struct
name|tac_handle
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tac_set_msg
parameter_list|(
name|struct
name|tac_handle
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
name|tac_set_port
parameter_list|(
name|struct
name|tac_handle
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
name|tac_set_priv
parameter_list|(
name|struct
name|tac_handle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tac_set_rem_addr
parameter_list|(
name|struct
name|tac_handle
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
name|tac_set_user
parameter_list|(
name|struct
name|tac_handle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|tac_strerror
parameter_list|(
name|struct
name|tac_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TACLIB_H_ */
end_comment

end_unit

