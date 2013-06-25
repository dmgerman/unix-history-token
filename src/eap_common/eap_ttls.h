begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP server/peer: EAP-TTLS (RFC 5281)  * Copyright (c) 2004-2007, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_TTLS_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_TTLS_H
end_define

begin_struct
struct|struct
name|ttls_avp
block|{
name|be32
name|avp_code
decl_stmt|;
name|be32
name|avp_length
decl_stmt|;
comment|/* 8-bit flags, 24-bit length; 			  * length includes AVP header */
comment|/* optional 32-bit Vendor-ID */
comment|/* Data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ttls_avp_vendor
block|{
name|be32
name|avp_code
decl_stmt|;
name|be32
name|avp_length
decl_stmt|;
comment|/* 8-bit flags, 24-bit length; 			  * length includes AVP header */
name|be32
name|vendor_id
decl_stmt|;
comment|/* Data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AVP_FLAGS_VENDOR
value|0x80
end_define

begin_define
define|#
directive|define
name|AVP_FLAGS_MANDATORY
value|0x40
end_define

begin_define
define|#
directive|define
name|AVP_PAD
parameter_list|(
name|start
parameter_list|,
name|pos
parameter_list|)
define|\
value|do { \ 	int __pad; \ 	__pad = (4 - (((pos) - (start))& 3))& 3; \ 	os_memset((pos), 0, __pad); \ 	pos += __pad; \ } while (0)
end_define

begin_comment
comment|/* RFC 2865 */
end_comment

begin_define
define|#
directive|define
name|RADIUS_ATTR_USER_NAME
value|1
end_define

begin_define
define|#
directive|define
name|RADIUS_ATTR_USER_PASSWORD
value|2
end_define

begin_define
define|#
directive|define
name|RADIUS_ATTR_CHAP_PASSWORD
value|3
end_define

begin_define
define|#
directive|define
name|RADIUS_ATTR_REPLY_MESSAGE
value|18
end_define

begin_define
define|#
directive|define
name|RADIUS_ATTR_CHAP_CHALLENGE
value|60
end_define

begin_define
define|#
directive|define
name|RADIUS_ATTR_EAP_MESSAGE
value|79
end_define

begin_comment
comment|/* RFC 2548 */
end_comment

begin_define
define|#
directive|define
name|RADIUS_VENDOR_ID_MICROSOFT
value|311
end_define

begin_define
define|#
directive|define
name|RADIUS_ATTR_MS_CHAP_RESPONSE
value|1
end_define

begin_define
define|#
directive|define
name|RADIUS_ATTR_MS_CHAP_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|RADIUS_ATTR_MS_CHAP_NT_ENC_PW
value|6
end_define

begin_define
define|#
directive|define
name|RADIUS_ATTR_MS_CHAP_CHALLENGE
value|11
end_define

begin_define
define|#
directive|define
name|RADIUS_ATTR_MS_CHAP2_RESPONSE
value|25
end_define

begin_define
define|#
directive|define
name|RADIUS_ATTR_MS_CHAP2_SUCCESS
value|26
end_define

begin_define
define|#
directive|define
name|RADIUS_ATTR_MS_CHAP2_CPW
value|27
end_define

begin_define
define|#
directive|define
name|EAP_TTLS_MSCHAPV2_CHALLENGE_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_TTLS_MSCHAPV2_RESPONSE_LEN
value|50
end_define

begin_define
define|#
directive|define
name|EAP_TTLS_MSCHAP_CHALLENGE_LEN
value|8
end_define

begin_define
define|#
directive|define
name|EAP_TTLS_MSCHAP_RESPONSE_LEN
value|50
end_define

begin_define
define|#
directive|define
name|EAP_TTLS_CHAP_CHALLENGE_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_TTLS_CHAP_PASSWORD_LEN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_TTLS_H */
end_comment

end_unit

