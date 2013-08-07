begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAPOL definitions shared between hostapd and wpa_supplicant  * Copyright (c) 2002-2007, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAPOL_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAPOL_COMMON_H
end_define

begin_comment
comment|/* IEEE Std 802.1X-2004 */
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
name|ieee802_1x_hdr
block|{
name|u8
name|version
decl_stmt|;
name|u8
name|type
decl_stmt|;
name|be16
name|length
decl_stmt|;
comment|/* followed by length octets of data */
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

begin_define
define|#
directive|define
name|EAPOL_VERSION
value|2
end_define

begin_enum
enum|enum
block|{
name|IEEE802_1X_TYPE_EAP_PACKET
init|=
literal|0
block|,
name|IEEE802_1X_TYPE_EAPOL_START
init|=
literal|1
block|,
name|IEEE802_1X_TYPE_EAPOL_LOGOFF
init|=
literal|2
block|,
name|IEEE802_1X_TYPE_EAPOL_KEY
init|=
literal|3
block|,
name|IEEE802_1X_TYPE_EAPOL_ENCAPSULATED_ASF_ALERT
init|=
literal|4
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|EAPOL_KEY_TYPE_RC4
init|=
literal|1
block|,
name|EAPOL_KEY_TYPE_RSN
init|=
literal|2
block|,
name|EAPOL_KEY_TYPE_WPA
init|=
literal|254
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IEEE8021X_REPLAY_COUNTER_LEN
value|8
end_define

begin_define
define|#
directive|define
name|IEEE8021X_KEY_SIGN_LEN
value|16
end_define

begin_define
define|#
directive|define
name|IEEE8021X_KEY_IV_LEN
value|16
end_define

begin_define
define|#
directive|define
name|IEEE8021X_KEY_INDEX_FLAG
value|0x80
end_define

begin_define
define|#
directive|define
name|IEEE8021X_KEY_INDEX_MASK
value|0x03
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
name|ieee802_1x_eapol_key
block|{
name|u8
name|type
decl_stmt|;
comment|/* Note: key_length is unaligned */
name|u8
name|key_length
index|[
literal|2
index|]
decl_stmt|;
comment|/* does not repeat within the life of the keying material used to 	 * encrypt the Key field; 64-bit NTP timestamp MAY be used here */
name|u8
name|replay_counter
index|[
name|IEEE8021X_REPLAY_COUNTER_LEN
index|]
decl_stmt|;
name|u8
name|key_iv
index|[
name|IEEE8021X_KEY_IV_LEN
index|]
decl_stmt|;
comment|/* cryptographically random number */
name|u8
name|key_index
decl_stmt|;
comment|/* key flag in the most significant bit: 		       * 0 = broadcast (default key), 		       * 1 = unicast (key mapping key); key index is in the 		       * 7 least significant bits */
comment|/* HMAC-MD5 message integrity check computed with MS-MPPE-Send-Key as 	 * the key */
name|u8
name|key_signature
index|[
name|IEEE8021X_KEY_SIGN_LEN
index|]
decl_stmt|;
comment|/* followed by key: if packet body length = 44 + key length, then the 	 * key field (of key_length bytes) contains the key in encrypted form; 	 * if packet body length = 44, key field is absent and key_length 	 * represents the number of least significant octets from 	 * MS-MPPE-Send-Key attribute to be used as the keying material; 	 * RC4 key used in encryption = Key-IV + MS-MPPE-Recv-Key */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAPOL_COMMON_H */
end_comment

end_unit

