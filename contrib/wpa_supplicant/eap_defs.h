begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant/hostapd / Shared EAP definitions  * Copyright (c) 2004-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
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
name|u16
name|length
decl_stmt|;
comment|/* including code and identifier; network byte order */
comment|/* followed by length-4 octets of data */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

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
comment|/* draft-haverinen-pppext-eap-sim-12.txt */
block|,
name|EAP_TYPE_TTLS
init|=
literal|21
comment|/* draft-ietf-pppext-eap-ttls-02.txt */
block|,
name|EAP_TYPE_AKA
init|=
literal|23
comment|/* draft-arkko-pppext-eap-aka-12.txt */
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
name|EAP_TYPE_FAST
init|=
literal|43
comment|/* draft-cam-winget-eap-fast-00.txt */
block|,
name|EAP_TYPE_PAX
init|=
literal|46
block|,
comment|/* draft-clancy-eap-pax-04.txt */
name|EAP_TYPE_EXPANDED_NAK
init|=
literal|254
comment|/* RFC 3748 */
block|,
name|EAP_TYPE_PSK
init|=
literal|255
comment|/* EXPERIMENTAL - type not yet allocated 			    * draft-bersani-eap-psk-09 */
block|}
name|EapType
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_DEFS_H */
end_comment

end_unit

