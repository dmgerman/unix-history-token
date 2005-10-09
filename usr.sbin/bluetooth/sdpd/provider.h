begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * provider.h  *  * Copyright (c) 2004 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: provider.h,v 1.6 2004/01/13 01:54:39 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROVIDER_H_
end_ifndef

begin_define
define|#
directive|define
name|_PROVIDER_H_
end_define

begin_comment
comment|/*  * Provider of service  */
end_comment

begin_struct_decl
struct_decl|struct
name|profile
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|provider
block|{
name|struct
name|profile
modifier|*
name|profile
decl_stmt|;
comment|/* profile */
name|void
modifier|*
name|data
decl_stmt|;
comment|/* profile data */
name|uint32_t
name|handle
decl_stmt|;
comment|/* record handle */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* provider's BDADDR */
name|int32_t
name|fd
decl_stmt|;
comment|/* session descriptor */
name|TAILQ_ENTRY
argument_list|(
argument|provider
argument_list|)
name|provider_next
expr_stmt|;
comment|/* all providers */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|provider
name|provider_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|provider
modifier|*
name|provider_p
typedef|;
end_typedef

begin_define
define|#
directive|define
name|provider_match_bdaddr
parameter_list|(
name|p
parameter_list|,
name|b
parameter_list|)
define|\
value|(memcmp(b, NG_HCI_BDADDR_ANY, sizeof(bdaddr_t)) == 0 || \ 	 memcmp(&(p)->bdaddr, NG_HCI_BDADDR_ANY, sizeof(bdaddr_t)) == 0 || \ 	 memcmp(&(p)->bdaddr, b, sizeof(bdaddr_t)) == 0)
end_define

begin_function_decl
name|int32_t
name|provider_register_sd
parameter_list|(
name|int32_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|provider_p
name|provider_register
parameter_list|(
name|profile_p
specifier|const
name|profile
parameter_list|,
name|bdaddr_p
specifier|const
name|bdaddr
parameter_list|,
name|int32_t
name|fd
parameter_list|,
name|uint8_t
specifier|const
modifier|*
name|data
parameter_list|,
name|uint32_t
name|datalen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|provider_unregister
parameter_list|(
name|provider_p
name|provider
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|provider_update
parameter_list|(
name|provider_p
name|provider
parameter_list|,
name|uint8_t
specifier|const
modifier|*
name|data
parameter_list|,
name|uint32_t
name|datalen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|provider_p
name|provider_by_handle
parameter_list|(
name|uint32_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|provider_p
name|provider_get_first
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|provider_p
name|provider_get_next
parameter_list|(
name|provider_p
name|provider
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|provider_get_change_state
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _PROVIDER_H_ */
end_comment

end_unit

