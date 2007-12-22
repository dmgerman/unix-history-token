begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RADLIB_VS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RADLIB_VS_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_define
define|#
directive|define
name|RAD_VENDOR_MICROSOFT
value|311
end_define

begin_comment
comment|/* rfc2548 */
end_comment

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_CHAP_RESPONSE
value|1
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_CHAP_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_CHAP_PW_1
value|3
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_CHAP_PW_2
value|4
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_CHAP_LM_ENC_PW
value|5
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_CHAP_NT_ENC_PW
value|6
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_MPPE_ENCRYPTION_POLICY
value|7
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_MPPE_ENCRYPTION_TYPES
value|8
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_RAS_VENDOR
value|9
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_CHAP_DOMAIN
value|10
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_CHAP_CHALLENGE
value|11
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_CHAP_MPPE_KEYS
value|12
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_BAP_USAGE
value|13
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_LINK_UTILIZATION_THRESHOLD
value|14
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_LINK_DROP_TIME_LIMIT
value|15
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_MPPE_SEND_KEY
value|16
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_MPPE_RECV_KEY
value|17
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_RAS_VERSION
value|18
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_OLD_ARAP_PASSWORD
value|19
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_NEW_ARAP_PASSWORD
value|20
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_ARAP_PASSWORD_CHANGE_REASON
value|21
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_FILTER
value|22
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_ACCT_AUTH_TYPE
value|23
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_ACCT_EAP_TYPE
value|24
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_CHAP2_RESPONSE
value|25
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_CHAP2_SUCCESS
value|26
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_CHAP2_PW
value|27
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_PRIMARY_DNS_SERVER
value|28
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_SECONDARY_DNS_SERVER
value|29
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_PRIMARY_NBNS_SERVER
value|30
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_SECONDARY_NBNS_SERVER
value|31
end_define

begin_define
define|#
directive|define
name|RAD_MICROSOFT_MS_ARAP_CHALLENGE
value|33
end_define

begin_define
define|#
directive|define
name|SALT_LEN
value|2
end_define

begin_struct_decl
struct_decl|struct
name|rad_handle
struct_decl|;
end_struct_decl

begin_function_decl
name|__BEGIN_DECLS
name|int
name|rad_get_vendor_attr
parameter_list|(
name|u_int32_t
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rad_put_vendor_addr
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rad_put_vendor_attr
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
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
name|rad_put_vendor_int
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rad_put_vendor_string
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
modifier|*
name|rad_demangle_mppe_key
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
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
comment|/* _RADLIB_VS_H_ */
end_comment

end_unit

