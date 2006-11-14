begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * server.h  *  * Copyright (c) 2004 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: server.h,v 1.5 2004/01/13 01:54:39 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SERVER_H_
end_ifndef

begin_define
define|#
directive|define
name|_SERVER_H_
end_define

begin_comment
comment|/*  * File descriptor index entry  */
end_comment

begin_struct
struct|struct
name|fd_idx
block|{
name|unsigned
name|valid
range|:
literal|1
decl_stmt|;
comment|/* descriptor is valid */
name|unsigned
name|server
range|:
literal|1
decl_stmt|;
comment|/* descriptor is listening */
name|unsigned
name|control
range|:
literal|1
decl_stmt|;
comment|/* descriptor is a control socket */
name|unsigned
name|priv
range|:
literal|1
decl_stmt|;
comment|/* descriptor is privileged */
name|unsigned
name|reserved
range|:
literal|1
decl_stmt|;
name|unsigned
name|rsp_cs
range|:
literal|11
decl_stmt|;
comment|/* response continuation state */
name|uint16_t
name|rsp_size
decl_stmt|;
comment|/* response size */
name|uint16_t
name|rsp_limit
decl_stmt|;
comment|/* response limit */
name|uint16_t
name|omtu
decl_stmt|;
comment|/* outgoing MTU */
name|uint8_t
modifier|*
name|rsp
decl_stmt|;
comment|/* outgoing buffer */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fd_idx
name|fd_idx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fd_idx
modifier|*
name|fd_idx_p
typedef|;
end_typedef

begin_comment
comment|/*  * SDP server  */
end_comment

begin_struct
struct|struct
name|server
block|{
name|uint32_t
name|imtu
decl_stmt|;
comment|/* incoming MTU */
name|uint8_t
modifier|*
name|req
decl_stmt|;
comment|/* incoming buffer */
name|int32_t
name|maxfd
decl_stmt|;
comment|/* max. descriptor is the set */
name|fd_set
name|fdset
decl_stmt|;
comment|/* current descriptor set */
name|fd_idx_p
name|fdidx
decl_stmt|;
comment|/* descriptor index */
name|struct
name|sockaddr_l2cap
name|req_sa
decl_stmt|;
comment|/* local address */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|server
name|server_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|server
modifier|*
name|server_p
typedef|;
end_typedef

begin_comment
comment|/*  * External API  */
end_comment

begin_function_decl
name|int32_t
name|server_init
parameter_list|(
name|server_p
name|srv
parameter_list|,
specifier|const
name|char
modifier|*
name|control
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|server_shutdown
parameter_list|(
name|server_p
name|srv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|server_do
parameter_list|(
name|server_p
name|srv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|server_prepare_service_search_response
parameter_list|(
name|server_p
name|srv
parameter_list|,
name|int32_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|server_send_service_search_response
parameter_list|(
name|server_p
name|srv
parameter_list|,
name|int32_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|server_prepare_service_attribute_response
parameter_list|(
name|server_p
name|srv
parameter_list|,
name|int32_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|server_send_service_attribute_response
parameter_list|(
name|server_p
name|srv
parameter_list|,
name|int32_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|server_prepare_service_search_attribute_response
parameter_list|(
name|server_p
name|srv
parameter_list|,
name|int32_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|server_send_service_search_attribute_response
define|\
value|server_send_service_attribute_response
end_define

begin_function_decl
name|int32_t
name|server_prepare_service_register_response
parameter_list|(
name|server_p
name|srv
parameter_list|,
name|int32_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|server_send_service_register_response
parameter_list|(
name|server_p
name|srv
parameter_list|,
name|int32_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|server_prepare_service_unregister_response
parameter_list|(
name|server_p
name|srv
parameter_list|,
name|int32_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|server_send_service_unregister_response
define|\
value|server_send_service_register_response
end_define

begin_function_decl
name|int32_t
name|server_prepare_service_change_response
parameter_list|(
name|server_p
name|srv
parameter_list|,
name|int32_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|server_send_service_change_response
define|\
value|server_send_service_register_response
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _SERVER_H_ */
end_comment

end_unit

