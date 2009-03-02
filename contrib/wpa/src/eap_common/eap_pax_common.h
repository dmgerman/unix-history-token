begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP server/peer: EAP-PAX shared routines  * Copyright (c) 2005-2007, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_PAX_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_PAX_COMMON_H
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
name|eap_pax_hdr
block|{
name|u8
name|op_code
decl_stmt|;
name|u8
name|flags
decl_stmt|;
name|u8
name|mac_id
decl_stmt|;
name|u8
name|dh_group_id
decl_stmt|;
name|u8
name|public_key_id
decl_stmt|;
comment|/* Followed by variable length payload and ICV */
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

begin_comment
comment|/* op_code: */
end_comment

begin_enum
enum|enum
block|{
name|EAP_PAX_OP_STD_1
init|=
literal|0x01
block|,
name|EAP_PAX_OP_STD_2
init|=
literal|0x02
block|,
name|EAP_PAX_OP_STD_3
init|=
literal|0x03
block|,
name|EAP_PAX_OP_SEC_1
init|=
literal|0x11
block|,
name|EAP_PAX_OP_SEC_2
init|=
literal|0x12
block|,
name|EAP_PAX_OP_SEC_3
init|=
literal|0x13
block|,
name|EAP_PAX_OP_SEC_4
init|=
literal|0x14
block|,
name|EAP_PAX_OP_SEC_5
init|=
literal|0x15
block|,
name|EAP_PAX_OP_ACK
init|=
literal|0x21
block|}
enum|;
end_enum

begin_comment
comment|/* flags: */
end_comment

begin_define
define|#
directive|define
name|EAP_PAX_FLAGS_MF
value|0x01
end_define

begin_define
define|#
directive|define
name|EAP_PAX_FLAGS_CE
value|0x02
end_define

begin_define
define|#
directive|define
name|EAP_PAX_FLAGS_AI
value|0x04
end_define

begin_comment
comment|/* mac_id: */
end_comment

begin_define
define|#
directive|define
name|EAP_PAX_MAC_HMAC_SHA1_128
value|0x01
end_define

begin_define
define|#
directive|define
name|EAP_PAX_HMAC_SHA256_128
value|0x02
end_define

begin_comment
comment|/* dh_group_id: */
end_comment

begin_define
define|#
directive|define
name|EAP_PAX_DH_GROUP_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|EAP_PAX_DH_GROUP_2048_MODP
value|0x01
end_define

begin_define
define|#
directive|define
name|EAP_PAX_DH_GROUP_3072_MODP
value|0x02
end_define

begin_define
define|#
directive|define
name|EAP_PAX_DH_GROUP_NIST_ECC_P_256
value|0x03
end_define

begin_comment
comment|/* public_key_id: */
end_comment

begin_define
define|#
directive|define
name|EAP_PAX_PUBLIC_KEY_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|EAP_PAX_PUBLIC_KEY_RSAES_OAEP
value|0x01
end_define

begin_define
define|#
directive|define
name|EAP_PAX_PUBLIC_KEY_RSA_PKCS1_V1_5
value|0x02
end_define

begin_define
define|#
directive|define
name|EAP_PAX_PUBLIC_KEY_EL_GAMAL_NIST_ECC
value|0x03
end_define

begin_comment
comment|/* ADE type: */
end_comment

begin_define
define|#
directive|define
name|EAP_PAX_ADE_VENDOR_SPECIFIC
value|0x01
end_define

begin_define
define|#
directive|define
name|EAP_PAX_ADE_CLIENT_CHANNEL_BINDING
value|0x02
end_define

begin_define
define|#
directive|define
name|EAP_PAX_ADE_SERVER_CHANNEL_BINDING
value|0x03
end_define

begin_define
define|#
directive|define
name|EAP_PAX_RAND_LEN
value|32
end_define

begin_define
define|#
directive|define
name|EAP_PAX_MAC_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_PAX_ICV_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_PAX_AK_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_PAX_MK_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_PAX_CK_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_PAX_ICK_LEN
value|16
end_define

begin_function_decl
name|int
name|eap_pax_kdf
parameter_list|(
name|u8
name|mac_id
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|,
specifier|const
name|char
modifier|*
name|identifier
parameter_list|,
specifier|const
name|u8
modifier|*
name|entropy
parameter_list|,
name|size_t
name|entropy_len
parameter_list|,
name|size_t
name|output_len
parameter_list|,
name|u8
modifier|*
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_pax_mac
parameter_list|(
name|u8
name|mac_id
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|data1
parameter_list|,
name|size_t
name|data1_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|data2
parameter_list|,
name|size_t
name|data2_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|data3
parameter_list|,
name|size_t
name|data3_len
parameter_list|,
name|u8
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_pax_initial_key_derivation
parameter_list|(
name|u8
name|mac_id
parameter_list|,
specifier|const
name|u8
modifier|*
name|ak
parameter_list|,
specifier|const
name|u8
modifier|*
name|e
parameter_list|,
name|u8
modifier|*
name|mk
parameter_list|,
name|u8
modifier|*
name|ck
parameter_list|,
name|u8
modifier|*
name|ick
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_PAX_COMMON_H */
end_comment

end_unit

