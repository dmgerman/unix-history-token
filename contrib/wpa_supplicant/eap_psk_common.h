begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / EAP-PSK shared routines  * Copyright (c) 2004-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_PSK_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_PSK_COMMON_H
end_define

begin_define
define|#
directive|define
name|EAP_PSK_RAND_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_PSK_MAC_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_PSK_TEK_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_PSK_MSK_LEN
value|64
end_define

begin_define
define|#
directive|define
name|EAP_PSK_PSK_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_PSK_AK_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_PSK_KDK_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_PSK_R_FLAG_CONT
value|1
end_define

begin_define
define|#
directive|define
name|EAP_PSK_R_FLAG_DONE_SUCCESS
value|2
end_define

begin_define
define|#
directive|define
name|EAP_PSK_R_FLAG_DONE_FAILURE
value|3
end_define

begin_define
define|#
directive|define
name|EAP_PSK_E_FLAG
value|0x20
end_define

begin_comment
comment|/* Shared prefix for all EAP-PSK frames */
end_comment

begin_struct
struct|struct
name|eap_psk_hdr
block|{
name|u8
name|code
decl_stmt|;
name|u8
name|identifier
decl_stmt|;
name|u16
name|length
decl_stmt|;
comment|/* including code, identifier, and length */
name|u8
name|type
decl_stmt|;
comment|/* EAP_TYPE_PSK */
name|u8
name|flags
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

begin_comment
comment|/* EAP-PSK First Message (AS -> Supplicant) */
end_comment

begin_struct
struct|struct
name|eap_psk_hdr_1
block|{
name|u8
name|code
decl_stmt|;
name|u8
name|identifier
decl_stmt|;
name|u16
name|length
decl_stmt|;
comment|/* including code, identifier, and length */
name|u8
name|type
decl_stmt|;
comment|/* EAP_TYPE_PSK */
name|u8
name|flags
decl_stmt|;
name|u8
name|rand_s
index|[
name|EAP_PSK_RAND_LEN
index|]
decl_stmt|;
comment|/* Followed by variable length ID_S */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* EAP-PSK Second Message (Supplicant -> AS) */
end_comment

begin_struct
struct|struct
name|eap_psk_hdr_2
block|{
name|u8
name|code
decl_stmt|;
name|u8
name|identifier
decl_stmt|;
name|u16
name|length
decl_stmt|;
comment|/* including code, identifier, and length */
name|u8
name|type
decl_stmt|;
comment|/* EAP_TYPE_PSK */
name|u8
name|flags
decl_stmt|;
name|u8
name|rand_s
index|[
name|EAP_PSK_RAND_LEN
index|]
decl_stmt|;
name|u8
name|rand_p
index|[
name|EAP_PSK_RAND_LEN
index|]
decl_stmt|;
name|u8
name|mac_p
index|[
name|EAP_PSK_MAC_LEN
index|]
decl_stmt|;
comment|/* Followed by variable length ID_P */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* EAP-PSK Third Message (AS -> Supplicant) */
end_comment

begin_struct
struct|struct
name|eap_psk_hdr_3
block|{
name|u8
name|code
decl_stmt|;
name|u8
name|identifier
decl_stmt|;
name|u16
name|length
decl_stmt|;
comment|/* including code, identifier, and length */
name|u8
name|type
decl_stmt|;
comment|/* EAP_TYPE_PSK */
name|u8
name|flags
decl_stmt|;
name|u8
name|rand_s
index|[
name|EAP_PSK_RAND_LEN
index|]
decl_stmt|;
name|u8
name|mac_s
index|[
name|EAP_PSK_MAC_LEN
index|]
decl_stmt|;
comment|/* Followed by variable length PCHANNEL */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* EAP-PSK Fourth Message (Supplicant -> AS) */
end_comment

begin_struct
struct|struct
name|eap_psk_hdr_4
block|{
name|u8
name|code
decl_stmt|;
name|u8
name|identifier
decl_stmt|;
name|u16
name|length
decl_stmt|;
comment|/* including code, identifier, and length */
name|u8
name|type
decl_stmt|;
comment|/* EAP_TYPE_PSK */
name|u8
name|flags
decl_stmt|;
name|u8
name|rand_s
index|[
name|EAP_PSK_RAND_LEN
index|]
decl_stmt|;
comment|/* Followed by variable length PCHANNEL */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_function_decl
name|void
name|eap_psk_key_setup
parameter_list|(
specifier|const
name|u8
modifier|*
name|psk
parameter_list|,
name|u8
modifier|*
name|ak
parameter_list|,
name|u8
modifier|*
name|kdk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_psk_derive_keys
parameter_list|(
specifier|const
name|u8
modifier|*
name|kdk
parameter_list|,
specifier|const
name|u8
modifier|*
name|rand_p
parameter_list|,
name|u8
modifier|*
name|tek
parameter_list|,
name|u8
modifier|*
name|msk
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_PSK_COMMON_H */
end_comment

end_unit

