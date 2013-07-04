begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP server/peer: Shared EAP definitions  * Copyright (c) 2004-2007, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_DEFS_H
end_define

begin_comment
comment|/* RFC 3748 - Extensible Authentication Protocol (EAP) */
end_comment

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
name|eap_hdr
block|{
name|u8
name|code
decl_stmt|;
name|u8
name|identifier
decl_stmt|;
name|be16
name|length
decl_stmt|;
comment|/* including code and identifier; network byte order */
comment|/* followed by length-4 octets of data */
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

begin_enum
enum|enum
block|{
name|EAP_CODE_REQUEST
init|=
literal|1
block|,
name|EAP_CODE_RESPONSE
init|=
literal|2
block|,
name|EAP_CODE_SUCCESS
init|=
literal|3
block|,
name|EAP_CODE_FAILURE
init|=
literal|4
block|}
enum|;
end_enum

begin_comment
comment|/* EAP Request and Response data begins with one octet Type. Success and  * Failure do not have additional data. */
end_comment

begin_comment
comment|/*  * EAP Method Types as allocated by IANA:  * http://www.iana.org/assignments/eap-numbers  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EAP_TYPE_NONE
init|=
literal|0
block|,
name|EAP_TYPE_IDENTITY
init|=
literal|1
comment|/* RFC 3748 */
block|,
name|EAP_TYPE_NOTIFICATION
init|=
literal|2
comment|/* RFC 3748 */
block|,
name|EAP_TYPE_NAK
init|=
literal|3
comment|/* Response only, RFC 3748 */
block|,
name|EAP_TYPE_MD5
init|=
literal|4
block|,
comment|/* RFC 3748 */
name|EAP_TYPE_OTP
init|=
literal|5
comment|/* RFC 3748 */
block|,
name|EAP_TYPE_GTC
init|=
literal|6
block|,
comment|/* RFC 3748 */
name|EAP_TYPE_TLS
init|=
literal|13
comment|/* RFC 2716 */
block|,
name|EAP_TYPE_LEAP
init|=
literal|17
comment|/* Cisco proprietary */
block|,
name|EAP_TYPE_SIM
init|=
literal|18
comment|/* RFC 4186 */
block|,
name|EAP_TYPE_TTLS
init|=
literal|21
comment|/* RFC 5281 */
block|,
name|EAP_TYPE_AKA
init|=
literal|23
comment|/* RFC 4187 */
block|,
name|EAP_TYPE_PEAP
init|=
literal|25
comment|/* draft-josefsson-pppext-eap-tls-eap-06.txt */
block|,
name|EAP_TYPE_MSCHAPV2
init|=
literal|26
comment|/* draft-kamath-pppext-eap-mschapv2-00.txt */
block|,
name|EAP_TYPE_TLV
init|=
literal|33
comment|/* draft-josefsson-pppext-eap-tls-eap-07.txt */
block|,
name|EAP_TYPE_TNC
init|=
literal|38
comment|/* TNC IF-T v1.0-r3; note: tentative assignment; 			   * type 38 has previously been allocated for 			   * EAP-HTTP Digest, (funk.com) */
block|,
name|EAP_TYPE_FAST
init|=
literal|43
comment|/* RFC 4851 */
block|,
name|EAP_TYPE_PAX
init|=
literal|46
comment|/* RFC 4746 */
block|,
name|EAP_TYPE_PSK
init|=
literal|47
comment|/* RFC 4764 */
block|,
name|EAP_TYPE_SAKE
init|=
literal|48
comment|/* RFC 4763 */
block|,
name|EAP_TYPE_IKEV2
init|=
literal|49
comment|/* RFC 5106 */
block|,
name|EAP_TYPE_AKA_PRIME
init|=
literal|50
comment|/* RFC 5448 */
block|,
name|EAP_TYPE_GPSK
init|=
literal|51
comment|/* RFC 5433 */
block|,
name|EAP_TYPE_PWD
init|=
literal|52
comment|/* RFC 5931 */
block|,
name|EAP_TYPE_EXPANDED
init|=
literal|254
comment|/* RFC 3748 */
block|}
name|EapType
typedef|;
end_typedef

begin_comment
comment|/* SMI Network Management Private Enterprise Code for vendor specific types */
end_comment

begin_enum
enum|enum
block|{
name|EAP_VENDOR_IETF
init|=
literal|0
block|,
name|EAP_VENDOR_MICROSOFT
init|=
literal|0x000137
comment|/* Microsoft */
block|,
name|EAP_VENDOR_WFA
init|=
literal|0x00372A
comment|/* Wi-Fi Alliance */
block|,
name|EAP_VENDOR_HOSTAP
init|=
literal|39068
comment|/* hostapd/wpa_supplicant project */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|EAP_VENDOR_UNAUTH_TLS
value|EAP_VENDOR_HOSTAP
end_define

begin_define
define|#
directive|define
name|EAP_VENDOR_TYPE_UNAUTH_TLS
value|1
end_define

begin_define
define|#
directive|define
name|EAP_MSK_LEN
value|64
end_define

begin_define
define|#
directive|define
name|EAP_EMSK_LEN
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_DEFS_H */
end_comment

end_unit

