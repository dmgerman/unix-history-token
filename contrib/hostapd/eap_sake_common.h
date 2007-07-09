begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP server/peer: EAP-SAKE shared routines  * Copyright (c) 2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_SAKE_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_SAKE_COMMON_H
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_VERSION
value|2
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_SUBTYPE_CHALLENGE
value|1
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_SUBTYPE_CONFIRM
value|2
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_SUBTYPE_AUTH_REJECT
value|3
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_SUBTYPE_IDENTITY
value|4
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_RAND_S
value|1
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_RAND_P
value|2
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_MIC_S
value|3
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_MIC_P
value|4
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_SERVERID
value|5
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_PEERID
value|6
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_SPI_S
value|7
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_SPI_P
value|8
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_ANY_ID_REQ
value|9
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_PERM_ID_REQ
value|10
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_ENCR_DATA
value|128
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_IV
value|129
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_PADDING
value|130
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_NEXT_TMPID
value|131
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_AT_MSK_LIFE
value|132
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_RAND_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_MIC_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_ROOT_SECRET_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_SMS_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_TEK_AUTH_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_TEK_CIPHER_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_SAKE_TEK_LEN
value|(EAP_SAKE_TEK_AUTH_LEN + EAP_SAKE_TEK_CIPHER_LEN)
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
name|eap_sake_hdr
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
name|u8
name|type
decl_stmt|;
comment|/* EAP_TYPE_SAKE */
name|u8
name|version
decl_stmt|;
comment|/* EAP_SAKE_VERSION */
name|u8
name|session_id
decl_stmt|;
name|u8
name|subtype
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

begin_struct
struct|struct
name|eap_sake_parse_attr
block|{
specifier|const
name|u8
modifier|*
name|rand_s
decl_stmt|;
specifier|const
name|u8
modifier|*
name|rand_p
decl_stmt|;
specifier|const
name|u8
modifier|*
name|mic_s
decl_stmt|;
specifier|const
name|u8
modifier|*
name|mic_p
decl_stmt|;
specifier|const
name|u8
modifier|*
name|serverid
decl_stmt|;
name|size_t
name|serverid_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|peerid
decl_stmt|;
name|size_t
name|peerid_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|spi_s
decl_stmt|;
name|size_t
name|spi_s_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|spi_p
decl_stmt|;
name|size_t
name|spi_p_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|any_id_req
decl_stmt|;
specifier|const
name|u8
modifier|*
name|perm_id_req
decl_stmt|;
specifier|const
name|u8
modifier|*
name|encr_data
decl_stmt|;
name|size_t
name|encr_data_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|iv
decl_stmt|;
name|size_t
name|iv_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|next_tmpid
decl_stmt|;
name|size_t
name|next_tmpid_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|msk_life
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|eap_sake_parse_attributes
parameter_list|(
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|struct
name|eap_sake_parse_attr
modifier|*
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sake_derive_keys
parameter_list|(
specifier|const
name|u8
modifier|*
name|root_secret_a
parameter_list|,
specifier|const
name|u8
modifier|*
name|root_secret_b
parameter_list|,
specifier|const
name|u8
modifier|*
name|rand_s
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
parameter_list|,
name|u8
modifier|*
name|emsk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_sake_compute_mic
parameter_list|(
specifier|const
name|u8
modifier|*
name|tek_auth
parameter_list|,
specifier|const
name|u8
modifier|*
name|rand_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|rand_p
parameter_list|,
specifier|const
name|u8
modifier|*
name|serverid
parameter_list|,
name|size_t
name|serverid_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|peerid
parameter_list|,
name|size_t
name|peerid_len
parameter_list|,
name|int
name|peer
parameter_list|,
specifier|const
name|u8
modifier|*
name|eap
parameter_list|,
name|size_t
name|eap_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|mic_pos
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
comment|/* EAP_SAKE_COMMON_H */
end_comment

end_unit

