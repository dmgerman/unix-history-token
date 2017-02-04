begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Edward Tomasz Napierala under sponsorship  * from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCSICTL_H
end_ifndef

begin_define
define|#
directive|define
name|ISCSICTL_H
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<libutil.h>
end_include

begin_define
define|#
directive|define
name|DEFAULT_CONFIG_PATH
value|"/etc/iscsi.conf"
end_define

begin_define
define|#
directive|define
name|DEFAULT_IQN
value|"iqn.1994-09.org.freebsd:"
end_define

begin_define
define|#
directive|define
name|MAX_NAME_LEN
value|223
end_define

begin_define
define|#
directive|define
name|AUTH_METHOD_UNSPECIFIED
value|0
end_define

begin_define
define|#
directive|define
name|AUTH_METHOD_NONE
value|1
end_define

begin_define
define|#
directive|define
name|AUTH_METHOD_CHAP
value|2
end_define

begin_define
define|#
directive|define
name|DIGEST_UNSPECIFIED
value|0
end_define

begin_define
define|#
directive|define
name|DIGEST_NONE
value|1
end_define

begin_define
define|#
directive|define
name|DIGEST_CRC32C
value|2
end_define

begin_define
define|#
directive|define
name|SESSION_TYPE_UNSPECIFIED
value|0
end_define

begin_define
define|#
directive|define
name|SESSION_TYPE_NORMAL
value|1
end_define

begin_define
define|#
directive|define
name|SESSION_TYPE_DISCOVERY
value|2
end_define

begin_define
define|#
directive|define
name|PROTOCOL_UNSPECIFIED
value|0
end_define

begin_define
define|#
directive|define
name|PROTOCOL_ISCSI
value|1
end_define

begin_define
define|#
directive|define
name|PROTOCOL_ISER
value|2
end_define

begin_define
define|#
directive|define
name|ENABLE_UNSPECIFIED
value|0
end_define

begin_define
define|#
directive|define
name|ENABLE_ON
value|1
end_define

begin_define
define|#
directive|define
name|ENABLE_OFF
value|2
end_define

begin_struct
struct|struct
name|target
block|{
name|TAILQ_ENTRY
argument_list|(
argument|target
argument_list|)
name|t_next
expr_stmt|;
name|struct
name|conf
modifier|*
name|t_conf
decl_stmt|;
name|char
modifier|*
name|t_nickname
decl_stmt|;
name|char
modifier|*
name|t_name
decl_stmt|;
name|char
modifier|*
name|t_address
decl_stmt|;
name|char
modifier|*
name|t_initiator_name
decl_stmt|;
name|char
modifier|*
name|t_initiator_address
decl_stmt|;
name|char
modifier|*
name|t_initiator_alias
decl_stmt|;
name|int
name|t_header_digest
decl_stmt|;
name|int
name|t_data_digest
decl_stmt|;
name|int
name|t_auth_method
decl_stmt|;
name|int
name|t_session_type
decl_stmt|;
name|int
name|t_enable
decl_stmt|;
name|int
name|t_protocol
decl_stmt|;
name|char
modifier|*
name|t_offload
decl_stmt|;
name|char
modifier|*
name|t_user
decl_stmt|;
name|char
modifier|*
name|t_secret
decl_stmt|;
name|char
modifier|*
name|t_mutual_user
decl_stmt|;
name|char
modifier|*
name|t_mutual_secret
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|conf
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|target
argument_list|)
name|conf_targets
expr_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|conf
modifier|*
name|conf_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|conf
modifier|*
name|conf_new_from_file
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|conf_delete
parameter_list|(
name|struct
name|conf
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|conf_verify
parameter_list|(
name|struct
name|conf
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|target
modifier|*
name|target_new
parameter_list|(
name|struct
name|conf
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|target
modifier|*
name|target_find
parameter_list|(
name|struct
name|conf
modifier|*
name|conf
parameter_list|,
specifier|const
name|char
modifier|*
name|nickname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|target_delete
parameter_list|(
name|struct
name|target
modifier|*
name|ic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_periphs
parameter_list|(
name|int
name|session_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|valid_iscsi_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_enable
parameter_list|(
specifier|const
name|char
modifier|*
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ISCSICTL_H */
end_comment

end_unit

