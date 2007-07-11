begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP server/peer: EAP-GPSK shared routines  * Copyright (c) 2006-2007, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_GPSK_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_GPSK_COMMON_H
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_OPCODE_GPSK_1
value|1
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_OPCODE_GPSK_2
value|2
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_OPCODE_GPSK_3
value|3
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_OPCODE_GPSK_4
value|4
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_OPCODE_FAIL
value|5
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_OPCODE_PROTECTED_FAIL
value|6
end_define

begin_comment
comment|/* Failure-Code in GPSK-Fail and GPSK-Protected-Fail */
end_comment

begin_define
define|#
directive|define
name|EAP_GPSK_FAIL_PSK_NOT_FOUND
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_FAIL_AUTHENTICATION_FAILURE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_FAIL_AUTHORIZATION_FAILURE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_RAND_LEN
value|32
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_MAX_SK_LEN
value|32
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_MAX_PK_LEN
value|32
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_MAX_MIC_LEN
value|32
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_VENDOR_IETF
value|0x000000
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_CIPHER_RESERVED
value|0x000000
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_CIPHER_AES
value|0x000001
end_define

begin_define
define|#
directive|define
name|EAP_GPSK_CIPHER_SHA256
value|0x000002
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_struct
struct|struct
name|eap_gpsk_csuite
block|{
name|u8
name|vendor
index|[
literal|3
index|]
decl_stmt|;
name|u8
name|specifier
index|[
literal|3
index|]
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_function_decl
name|int
name|eap_gpsk_supported_ciphersuite
parameter_list|(
name|int
name|vendor
parameter_list|,
name|int
name|specifier
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_gpsk_derive_keys
parameter_list|(
specifier|const
name|u8
modifier|*
name|psk
parameter_list|,
name|size_t
name|psk_len
parameter_list|,
name|int
name|vendor
parameter_list|,
name|int
name|specifier
parameter_list|,
specifier|const
name|u8
modifier|*
name|rand_client
parameter_list|,
specifier|const
name|u8
modifier|*
name|rand_server
parameter_list|,
specifier|const
name|u8
modifier|*
name|id_client
parameter_list|,
name|size_t
name|id_client_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|id_server
parameter_list|,
name|size_t
name|id_server_len
parameter_list|,
name|u8
modifier|*
name|msk
parameter_list|,
name|u8
modifier|*
name|emsk
parameter_list|,
name|u8
modifier|*
name|sk
parameter_list|,
name|size_t
modifier|*
name|sk_len
parameter_list|,
name|u8
modifier|*
name|pk
parameter_list|,
name|size_t
modifier|*
name|pk_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|eap_gpsk_mic_len
parameter_list|(
name|int
name|vendor
parameter_list|,
name|int
name|specifier
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_gpsk_compute_mic
parameter_list|(
specifier|const
name|u8
modifier|*
name|sk
parameter_list|,
name|size_t
name|sk_len
parameter_list|,
name|int
name|vendor
parameter_list|,
name|int
name|specifier
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|,
name|u8
modifier|*
name|mic
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_GPSK_COMMON_H */
end_comment

end_unit

