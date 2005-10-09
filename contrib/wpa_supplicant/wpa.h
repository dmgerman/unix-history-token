begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|WPA_H
end_ifndef

begin_define
define|#
directive|define
name|WPA_H
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|n
parameter_list|)
value|(1<< (n))
end_define

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
name|u16
name|length
decl_stmt|;
comment|/* followed by length octets of data */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

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

begin_struct
struct|struct
name|ieee802_1x_eapol_key
block|{
name|u8
name|type
decl_stmt|;
name|u16
name|key_length
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|WPA_NONCE_LEN
value|32
end_define

begin_define
define|#
directive|define
name|WPA_REPLAY_COUNTER_LEN
value|8
end_define

begin_struct
struct|struct
name|wpa_eapol_key
block|{
name|u8
name|type
decl_stmt|;
name|u16
name|key_info
decl_stmt|;
name|u16
name|key_length
decl_stmt|;
name|u8
name|replay_counter
index|[
name|WPA_REPLAY_COUNTER_LEN
index|]
decl_stmt|;
name|u8
name|key_nonce
index|[
name|WPA_NONCE_LEN
index|]
decl_stmt|;
name|u8
name|key_iv
index|[
literal|16
index|]
decl_stmt|;
name|u8
name|key_rsc
index|[
literal|8
index|]
decl_stmt|;
name|u8
name|key_id
index|[
literal|8
index|]
decl_stmt|;
comment|/* Reserved in IEEE 802.11i/RSN */
name|u8
name|key_mic
index|[
literal|16
index|]
decl_stmt|;
name|u16
name|key_data_length
decl_stmt|;
comment|/* followed by key_data_length bytes of key_data */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|WPA_KEY_INFO_TYPE_MASK
value|(BIT(0) | BIT(1) | BIT(2))
end_define

begin_define
define|#
directive|define
name|WPA_KEY_INFO_TYPE_HMAC_MD5_RC4
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_INFO_TYPE_HMAC_SHA1_AES
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_INFO_KEY_TYPE
value|BIT(3)
end_define

begin_comment
comment|/* 1 = Pairwise, 0 = Group key */
end_comment

begin_comment
comment|/* bit4..5 is used in WPA, but is reserved in IEEE 802.11i/RSN */
end_comment

begin_define
define|#
directive|define
name|WPA_KEY_INFO_KEY_INDEX_MASK
value|(BIT(4) | BIT(5))
end_define

begin_define
define|#
directive|define
name|WPA_KEY_INFO_KEY_INDEX_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|WPA_KEY_INFO_INSTALL
value|BIT(6)
end_define

begin_comment
comment|/* pairwise */
end_comment

begin_define
define|#
directive|define
name|WPA_KEY_INFO_TXRX
value|BIT(6)
end_define

begin_comment
comment|/* group */
end_comment

begin_define
define|#
directive|define
name|WPA_KEY_INFO_ACK
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_INFO_MIC
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_INFO_SECURE
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_INFO_ERROR
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_INFO_REQUEST
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_INFO_ENCR_KEY_DATA
value|BIT(12)
end_define

begin_comment
comment|/* IEEE 802.11i/RSN only */
end_comment

begin_define
define|#
directive|define
name|WPA_CAPABILITY_PREAUTH
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|GENERIC_INFO_ELEM
value|0xdd
end_define

begin_define
define|#
directive|define
name|RSN_INFO_ELEM
value|0x30
end_define

begin_enum
enum|enum
block|{
name|REASON_UNSPECIFIED
init|=
literal|1
block|,
name|REASON_DEAUTH_LEAVING
init|=
literal|3
block|,
name|REASON_INVALID_IE
init|=
literal|13
block|,
name|REASON_MICHAEL_MIC_FAILURE
init|=
literal|14
block|,
name|REASON_4WAY_HANDSHAKE_TIMEOUT
init|=
literal|15
block|,
name|REASON_GROUP_KEY_UPDATE_TIMEOUT
init|=
literal|16
block|,
name|REASON_IE_IN_4WAY_DIFFERS
init|=
literal|17
block|,
name|REASON_GROUP_CIPHER_NOT_VALID
init|=
literal|18
block|,
name|REASON_PAIRWISE_CIPHER_NOT_VALID
init|=
literal|19
block|,
name|REASON_AKMP_NOT_VALID
init|=
literal|20
block|,
name|REASON_UNSUPPORTED_RSN_IE_VERSION
init|=
literal|21
block|,
name|REASON_INVALID_RSN_IE_CAPAB
init|=
literal|22
block|,
name|REASON_IEEE_802_1X_AUTH_FAILED
init|=
literal|23
block|,
name|REASON_CIPHER_SUITE_REJECTED
init|=
literal|24
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPA_H */
end_comment

end_unit

