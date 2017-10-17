begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA definitions shared between hostapd and wpa_supplicant  * Copyright (c) 2002-2015, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPA_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|WPA_COMMON_H
end_define

begin_comment
comment|/* IEEE 802.11i */
end_comment

begin_define
define|#
directive|define
name|PMKID_LEN
value|16
end_define

begin_define
define|#
directive|define
name|PMK_LEN
value|32
end_define

begin_define
define|#
directive|define
name|WPA_REPLAY_COUNTER_LEN
value|8
end_define

begin_define
define|#
directive|define
name|WPA_NONCE_LEN
value|32
end_define

begin_define
define|#
directive|define
name|WPA_KEY_RSC_LEN
value|8
end_define

begin_define
define|#
directive|define
name|WPA_GMK_LEN
value|32
end_define

begin_define
define|#
directive|define
name|WPA_GTK_MAX_LEN
value|32
end_define

begin_define
define|#
directive|define
name|WPA_ALLOWED_PAIRWISE_CIPHERS
define|\
value|(WPA_CIPHER_CCMP | WPA_CIPHER_GCMP | WPA_CIPHER_TKIP | WPA_CIPHER_NONE | \ WPA_CIPHER_GCMP_256 | WPA_CIPHER_CCMP_256)
end_define

begin_define
define|#
directive|define
name|WPA_ALLOWED_GROUP_CIPHERS
define|\
value|(WPA_CIPHER_CCMP | WPA_CIPHER_GCMP | WPA_CIPHER_TKIP | \ WPA_CIPHER_GCMP_256 | WPA_CIPHER_CCMP_256 | \ WPA_CIPHER_GTK_NOT_USED)
end_define

begin_define
define|#
directive|define
name|WPA_SELECTOR_LEN
value|4
end_define

begin_define
define|#
directive|define
name|WPA_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|RSN_SELECTOR_LEN
value|4
end_define

begin_define
define|#
directive|define
name|RSN_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|RSN_SELECTOR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
define|\
value|((((u32) (a))<< 24) | (((u32) (b))<< 16) | (((u32) (c))<< 8) | \ 	 (u32) (d))
end_define

begin_define
define|#
directive|define
name|WPA_AUTH_KEY_MGMT_NONE
value|RSN_SELECTOR(0x00, 0x50, 0xf2, 0)
end_define

begin_define
define|#
directive|define
name|WPA_AUTH_KEY_MGMT_UNSPEC_802_1X
value|RSN_SELECTOR(0x00, 0x50, 0xf2, 1)
end_define

begin_define
define|#
directive|define
name|WPA_AUTH_KEY_MGMT_PSK_OVER_802_1X
value|RSN_SELECTOR(0x00, 0x50, 0xf2, 2)
end_define

begin_define
define|#
directive|define
name|WPA_AUTH_KEY_MGMT_CCKM
value|RSN_SELECTOR(0x00, 0x40, 0x96, 0)
end_define

begin_define
define|#
directive|define
name|WPA_CIPHER_SUITE_NONE
value|RSN_SELECTOR(0x00, 0x50, 0xf2, 0)
end_define

begin_define
define|#
directive|define
name|WPA_CIPHER_SUITE_TKIP
value|RSN_SELECTOR(0x00, 0x50, 0xf2, 2)
end_define

begin_define
define|#
directive|define
name|WPA_CIPHER_SUITE_CCMP
value|RSN_SELECTOR(0x00, 0x50, 0xf2, 4)
end_define

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_UNSPEC_802_1X
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 1)
end_define

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_PSK_OVER_802_1X
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 2)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_IEEE80211R
end_ifdef

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_FT_802_1X
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 3)
end_define

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_FT_PSK
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_IEEE80211R */
end_comment

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_802_1X_SHA256
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 5)
end_define

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_PSK_SHA256
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 6)
end_define

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_TPK_HANDSHAKE
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 7)
end_define

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_SAE
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 8)
end_define

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_FT_SAE
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 9)
end_define

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_802_1X_SUITE_B
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 11)
end_define

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_802_1X_SUITE_B_192
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 12)
end_define

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_FT_802_1X_SUITE_B_192
define|\
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 13)
end_define

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_CCKM
value|RSN_SELECTOR(0x00, 0x40, 0x96, 0x00)
end_define

begin_define
define|#
directive|define
name|RSN_AUTH_KEY_MGMT_OSEN
value|RSN_SELECTOR(0x50, 0x6f, 0x9a, 0x01)
end_define

begin_define
define|#
directive|define
name|RSN_CIPHER_SUITE_NONE
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 0)
end_define

begin_define
define|#
directive|define
name|RSN_CIPHER_SUITE_TKIP
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 2)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|RSN_CIPHER_SUITE_WRAP
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RSN_CIPHER_SUITE_CCMP
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 4)
end_define

begin_define
define|#
directive|define
name|RSN_CIPHER_SUITE_AES_128_CMAC
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 6)
end_define

begin_define
define|#
directive|define
name|RSN_CIPHER_SUITE_NO_GROUP_ADDRESSED
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 7)
end_define

begin_define
define|#
directive|define
name|RSN_CIPHER_SUITE_GCMP
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 8)
end_define

begin_define
define|#
directive|define
name|RSN_CIPHER_SUITE_GCMP_256
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 9)
end_define

begin_define
define|#
directive|define
name|RSN_CIPHER_SUITE_CCMP_256
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 10)
end_define

begin_define
define|#
directive|define
name|RSN_CIPHER_SUITE_BIP_GMAC_128
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 11)
end_define

begin_define
define|#
directive|define
name|RSN_CIPHER_SUITE_BIP_GMAC_256
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 12)
end_define

begin_define
define|#
directive|define
name|RSN_CIPHER_SUITE_BIP_CMAC_256
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 13)
end_define

begin_comment
comment|/* EAPOL-Key Key Data Encapsulation  * GroupKey and PeerKey require encryption, otherwise, encryption is optional.  */
end_comment

begin_define
define|#
directive|define
name|RSN_KEY_DATA_GROUPKEY
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 1)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|RSN_KEY_DATA_STAKEY
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RSN_KEY_DATA_MAC_ADDR
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 3)
end_define

begin_define
define|#
directive|define
name|RSN_KEY_DATA_PMKID
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 4)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_PEERKEY
end_ifdef

begin_define
define|#
directive|define
name|RSN_KEY_DATA_SMK
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 5)
end_define

begin_define
define|#
directive|define
name|RSN_KEY_DATA_NONCE
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 6)
end_define

begin_define
define|#
directive|define
name|RSN_KEY_DATA_LIFETIME
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 7)
end_define

begin_define
define|#
directive|define
name|RSN_KEY_DATA_ERROR
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_PEERKEY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_IEEE80211W
end_ifdef

begin_define
define|#
directive|define
name|RSN_KEY_DATA_IGTK
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 9)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_IEEE80211W */
end_comment

begin_define
define|#
directive|define
name|RSN_KEY_DATA_KEYID
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 10)
end_define

begin_define
define|#
directive|define
name|RSN_KEY_DATA_MULTIBAND_GTK
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 11)
end_define

begin_define
define|#
directive|define
name|RSN_KEY_DATA_MULTIBAND_KEYID
value|RSN_SELECTOR(0x00, 0x0f, 0xac, 12)
end_define

begin_define
define|#
directive|define
name|WFA_KEY_DATA_IP_ADDR_REQ
value|RSN_SELECTOR(0x50, 0x6f, 0x9a, 4)
end_define

begin_define
define|#
directive|define
name|WFA_KEY_DATA_IP_ADDR_ALLOC
value|RSN_SELECTOR(0x50, 0x6f, 0x9a, 5)
end_define

begin_define
define|#
directive|define
name|WPA_OUI_TYPE
value|RSN_SELECTOR(0x00, 0x50, 0xf2, 1)
end_define

begin_define
define|#
directive|define
name|RSN_SELECTOR_PUT
parameter_list|(
name|a
parameter_list|,
name|val
parameter_list|)
value|WPA_PUT_BE32((u8 *) (a), (val))
end_define

begin_define
define|#
directive|define
name|RSN_SELECTOR_GET
parameter_list|(
name|a
parameter_list|)
value|WPA_GET_BE32((const u8 *) (a))
end_define

begin_define
define|#
directive|define
name|RSN_NUM_REPLAY_COUNTERS_1
value|0
end_define

begin_define
define|#
directive|define
name|RSN_NUM_REPLAY_COUNTERS_2
value|1
end_define

begin_define
define|#
directive|define
name|RSN_NUM_REPLAY_COUNTERS_4
value|2
end_define

begin_define
define|#
directive|define
name|RSN_NUM_REPLAY_COUNTERS_16
value|3
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

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_IEEE80211W
end_ifdef

begin_define
define|#
directive|define
name|WPA_IGTK_LEN
value|16
end_define

begin_define
define|#
directive|define
name|WPA_IGTK_MAX_LEN
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_IEEE80211W */
end_comment

begin_comment
comment|/* IEEE 802.11, 7.3.2.25.3 RSN Capabilities */
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
name|WPA_CAPABILITY_NO_PAIRWISE
value|BIT(1)
end_define

begin_comment
comment|/* B2-B3: PTKSA Replay Counter */
end_comment

begin_comment
comment|/* B4-B5: GTKSA Replay Counter */
end_comment

begin_define
define|#
directive|define
name|WPA_CAPABILITY_MFPR
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|WPA_CAPABILITY_MFPC
value|BIT(7)
end_define

begin_comment
comment|/* B8: Reserved */
end_comment

begin_define
define|#
directive|define
name|WPA_CAPABILITY_PEERKEY_ENABLED
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|WPA_CAPABILITY_SPP_A_MSDU_CAPABLE
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|WPA_CAPABILITY_SPP_A_MSDU_REQUIRED
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|WPA_CAPABILITY_PBAC
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|WPA_CAPABILITY_EXT_KEY_ID_FOR_UNICAST
value|BIT(13)
end_define

begin_comment
comment|/* B14-B15: Reserved */
end_comment

begin_comment
comment|/* IEEE 802.11r */
end_comment

begin_define
define|#
directive|define
name|MOBILITY_DOMAIN_ID_LEN
value|2
end_define

begin_define
define|#
directive|define
name|FT_R0KH_ID_MAX_LEN
value|48
end_define

begin_define
define|#
directive|define
name|FT_R1KH_ID_LEN
value|6
end_define

begin_define
define|#
directive|define
name|WPA_PMK_NAME_LEN
value|16
end_define

begin_comment
comment|/* IEEE 802.11, 8.5.2 EAPOL-Key frames */
end_comment

begin_define
define|#
directive|define
name|WPA_KEY_INFO_TYPE_MASK
value|((u16) (BIT(0) | BIT(1) | BIT(2)))
end_define

begin_define
define|#
directive|define
name|WPA_KEY_INFO_TYPE_AKM_DEFINED
value|0
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
name|WPA_KEY_INFO_TYPE_AES_128_CMAC
value|3
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
name|WPA_KEY_INFO_SMK_MESSAGE
value|BIT(13)
end_define

begin_struct
struct|struct
name|wpa_eapol_key
block|{
name|u8
name|type
decl_stmt|;
comment|/* Note: key_info, key_length, and key_data_length are unaligned */
name|u8
name|key_info
index|[
literal|2
index|]
decl_stmt|;
comment|/* big endian */
name|u8
name|key_length
index|[
literal|2
index|]
decl_stmt|;
comment|/* big endian */
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
name|WPA_KEY_RSC_LEN
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
name|u8
name|key_data_length
index|[
literal|2
index|]
decl_stmt|;
comment|/* big endian */
comment|/* followed by key_data_length bytes of key_data */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|wpa_eapol_key_192
block|{
name|u8
name|type
decl_stmt|;
comment|/* Note: key_info, key_length, and key_data_length are unaligned */
name|u8
name|key_info
index|[
literal|2
index|]
decl_stmt|;
comment|/* big endian */
name|u8
name|key_length
index|[
literal|2
index|]
decl_stmt|;
comment|/* big endian */
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
name|WPA_KEY_RSC_LEN
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
literal|24
index|]
decl_stmt|;
name|u8
name|key_data_length
index|[
literal|2
index|]
decl_stmt|;
comment|/* big endian */
comment|/* followed by key_data_length bytes of key_data */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_define
define|#
directive|define
name|WPA_EAPOL_KEY_MIC_MAX_LEN
value|24
end_define

begin_define
define|#
directive|define
name|WPA_KCK_MAX_LEN
value|24
end_define

begin_define
define|#
directive|define
name|WPA_KEK_MAX_LEN
value|32
end_define

begin_define
define|#
directive|define
name|WPA_TK_MAX_LEN
value|32
end_define

begin_comment
comment|/**  * struct wpa_ptk - WPA Pairwise Transient Key  * IEEE Std 802.11i-2004 - 8.5.1.2 Pairwise key hierarchy  */
end_comment

begin_struct
struct|struct
name|wpa_ptk
block|{
name|u8
name|kck
index|[
name|WPA_KCK_MAX_LEN
index|]
decl_stmt|;
comment|/* EAPOL-Key Key Confirmation Key (KCK) */
name|u8
name|kek
index|[
name|WPA_KEK_MAX_LEN
index|]
decl_stmt|;
comment|/* EAPOL-Key Key Encryption Key (KEK) */
name|u8
name|tk
index|[
name|WPA_TK_MAX_LEN
index|]
decl_stmt|;
comment|/* Temporal Key (TK) */
name|size_t
name|kck_len
decl_stmt|;
name|size_t
name|kek_len
decl_stmt|;
name|size_t
name|tk_len
decl_stmt|;
name|int
name|installed
decl_stmt|;
comment|/* 1 if key has already been installed to driver */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wpa_gtk
block|{
name|u8
name|gtk
index|[
name|WPA_GTK_MAX_LEN
index|]
decl_stmt|;
name|size_t
name|gtk_len
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_IEEE80211W
end_ifdef

begin_struct
struct|struct
name|wpa_igtk
block|{
name|u8
name|igtk
index|[
name|WPA_IGTK_MAX_LEN
index|]
decl_stmt|;
name|size_t
name|igtk_len
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_IEEE80211W */
end_comment

begin_comment
comment|/* WPA IE version 1  * 00-50-f2:1 (OUI:OUI type)  * 0x01 0x00 (version; little endian)  * (all following fields are optional:)  * Group Suite Selector (4 octets) (default: TKIP)  * Pairwise Suite Count (2 octets, little endian) (default: 1)  * Pairwise Suite List (4 * n octets) (default: TKIP)  * Authenticated Key Management Suite Count (2 octets, little endian)  *    (default: 1)  * Authenticated Key Management Suite List (4 * n octets)  *    (default: unspec 802.1X)  * WPA Capabilities (2 octets, little endian) (default: 0)  */
end_comment

begin_struct
struct|struct
name|wpa_ie_hdr
block|{
name|u8
name|elem_id
decl_stmt|;
name|u8
name|len
decl_stmt|;
name|u8
name|oui
index|[
literal|4
index|]
decl_stmt|;
comment|/* 24-bit OUI followed by 8-bit OUI type */
name|u8
name|version
index|[
literal|2
index|]
decl_stmt|;
comment|/* little endian */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_comment
comment|/* 1/4: PMKID  * 2/4: RSN IE  * 3/4: one or two RSN IEs + GTK IE (encrypted)  * 4/4: empty  * 1/2: GTK IE (encrypted)  * 2/2: empty  */
end_comment

begin_comment
comment|/* RSN IE version 1  * 0x01 0x00 (version; little endian)  * (all following fields are optional:)  * Group Suite Selector (4 octets) (default: CCMP)  * Pairwise Suite Count (2 octets, little endian) (default: 1)  * Pairwise Suite List (4 * n octets) (default: CCMP)  * Authenticated Key Management Suite Count (2 octets, little endian)  *    (default: 1)  * Authenticated Key Management Suite List (4 * n octets)  *    (default: unspec 802.1X)  * RSN Capabilities (2 octets, little endian) (default: 0)  * PMKID Count (2 octets) (default: 0)  * PMKID List (16 * n octets)  * Management Group Cipher Suite (4 octets) (default: AES-128-CMAC)  */
end_comment

begin_struct
struct|struct
name|rsn_ie_hdr
block|{
name|u8
name|elem_id
decl_stmt|;
comment|/* WLAN_EID_RSN */
name|u8
name|len
decl_stmt|;
name|u8
name|version
index|[
literal|2
index|]
decl_stmt|;
comment|/* little endian */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_PEERKEY
end_ifdef

begin_enum
enum|enum
block|{
name|STK_MUI_4WAY_STA_AP
init|=
literal|1
block|,
name|STK_MUI_4WAY_STAT_STA
init|=
literal|2
block|,
name|STK_MUI_GTK
init|=
literal|3
block|,
name|STK_MUI_SMK
init|=
literal|4
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|STK_ERR_STA_NR
init|=
literal|1
block|,
name|STK_ERR_STA_NRSN
init|=
literal|2
block|,
name|STK_ERR_CPHR_NS
init|=
literal|3
block|,
name|STK_ERR_NO_STSL
init|=
literal|4
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_PEERKEY */
end_comment

begin_struct
struct|struct
name|rsn_error_kde
block|{
name|be16
name|mui
decl_stmt|;
name|be16
name|error_type
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_IEEE80211W
end_ifdef

begin_define
define|#
directive|define
name|WPA_IGTK_KDE_PREFIX_LEN
value|(2 + 6)
end_define

begin_struct
struct|struct
name|wpa_igtk_kde
block|{
name|u8
name|keyid
index|[
literal|2
index|]
decl_stmt|;
name|u8
name|pn
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|igtk
index|[
name|WPA_IGTK_MAX_LEN
index|]
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_IEEE80211W */
end_comment

begin_struct
struct|struct
name|rsn_mdie
block|{
name|u8
name|mobility_domain
index|[
name|MOBILITY_DOMAIN_ID_LEN
index|]
decl_stmt|;
name|u8
name|ft_capab
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_define
define|#
directive|define
name|RSN_FT_CAPAB_FT_OVER_DS
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|RSN_FT_CAPAB_FT_RESOURCE_REQ_SUPP
value|BIT(1)
end_define

begin_struct
struct|struct
name|rsn_ftie
block|{
name|u8
name|mic_control
index|[
literal|2
index|]
decl_stmt|;
name|u8
name|mic
index|[
literal|16
index|]
decl_stmt|;
name|u8
name|anonce
index|[
name|WPA_NONCE_LEN
index|]
decl_stmt|;
name|u8
name|snonce
index|[
name|WPA_NONCE_LEN
index|]
decl_stmt|;
comment|/* followed by optional parameters */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_define
define|#
directive|define
name|FTIE_SUBELEM_R1KH_ID
value|1
end_define

begin_define
define|#
directive|define
name|FTIE_SUBELEM_GTK
value|2
end_define

begin_define
define|#
directive|define
name|FTIE_SUBELEM_R0KH_ID
value|3
end_define

begin_define
define|#
directive|define
name|FTIE_SUBELEM_IGTK
value|4
end_define

begin_struct
struct|struct
name|rsn_rdie
block|{
name|u8
name|id
decl_stmt|;
name|u8
name|descr_count
decl_stmt|;
name|le16
name|status_code
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
name|wpa_eapol_key_mic
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|,
name|int
name|akmp
parameter_list|,
name|int
name|ver
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
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

begin_function_decl
name|int
name|wpa_pmk_to_ptk
parameter_list|(
specifier|const
name|u8
modifier|*
name|pmk
parameter_list|,
name|size_t
name|pmk_len
parameter_list|,
specifier|const
name|char
modifier|*
name|label
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr1
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr2
parameter_list|,
specifier|const
name|u8
modifier|*
name|nonce1
parameter_list|,
specifier|const
name|u8
modifier|*
name|nonce2
parameter_list|,
name|struct
name|wpa_ptk
modifier|*
name|ptk
parameter_list|,
name|int
name|akmp
parameter_list|,
name|int
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_IEEE80211R
end_ifdef

begin_function_decl
name|int
name|wpa_ft_mic
parameter_list|(
specifier|const
name|u8
modifier|*
name|kck
parameter_list|,
name|size_t
name|kck_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|sta_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|ap_addr
parameter_list|,
name|u8
name|transaction_seqnum
parameter_list|,
specifier|const
name|u8
modifier|*
name|mdie
parameter_list|,
name|size_t
name|mdie_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|ftie
parameter_list|,
name|size_t
name|ftie_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|rsnie
parameter_list|,
name|size_t
name|rsnie_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|ric
parameter_list|,
name|size_t
name|ric_len
parameter_list|,
name|u8
modifier|*
name|mic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_derive_pmk_r0
parameter_list|(
specifier|const
name|u8
modifier|*
name|xxkey
parameter_list|,
name|size_t
name|xxkey_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|ssid
parameter_list|,
name|size_t
name|ssid_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|mdid
parameter_list|,
specifier|const
name|u8
modifier|*
name|r0kh_id
parameter_list|,
name|size_t
name|r0kh_id_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|s0kh_id
parameter_list|,
name|u8
modifier|*
name|pmk_r0
parameter_list|,
name|u8
modifier|*
name|pmk_r0_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_derive_pmk_r1_name
parameter_list|(
specifier|const
name|u8
modifier|*
name|pmk_r0_name
parameter_list|,
specifier|const
name|u8
modifier|*
name|r1kh_id
parameter_list|,
specifier|const
name|u8
modifier|*
name|s1kh_id
parameter_list|,
name|u8
modifier|*
name|pmk_r1_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_derive_pmk_r1
parameter_list|(
specifier|const
name|u8
modifier|*
name|pmk_r0
parameter_list|,
specifier|const
name|u8
modifier|*
name|pmk_r0_name
parameter_list|,
specifier|const
name|u8
modifier|*
name|r1kh_id
parameter_list|,
specifier|const
name|u8
modifier|*
name|s1kh_id
parameter_list|,
name|u8
modifier|*
name|pmk_r1
parameter_list|,
name|u8
modifier|*
name|pmk_r1_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_pmk_r1_to_ptk
parameter_list|(
specifier|const
name|u8
modifier|*
name|pmk_r1
parameter_list|,
specifier|const
name|u8
modifier|*
name|snonce
parameter_list|,
specifier|const
name|u8
modifier|*
name|anonce
parameter_list|,
specifier|const
name|u8
modifier|*
name|sta_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
specifier|const
name|u8
modifier|*
name|pmk_r1_name
parameter_list|,
name|struct
name|wpa_ptk
modifier|*
name|ptk
parameter_list|,
name|u8
modifier|*
name|ptk_name
parameter_list|,
name|int
name|akmp
parameter_list|,
name|int
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_IEEE80211R */
end_comment

begin_struct
struct|struct
name|wpa_ie_data
block|{
name|int
name|proto
decl_stmt|;
name|int
name|pairwise_cipher
decl_stmt|;
name|int
name|group_cipher
decl_stmt|;
name|int
name|key_mgmt
decl_stmt|;
name|int
name|capabilities
decl_stmt|;
name|size_t
name|num_pmkid
decl_stmt|;
specifier|const
name|u8
modifier|*
name|pmkid
decl_stmt|;
name|int
name|mgmt_group_cipher
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|wpa_parse_wpa_ie_rsn
parameter_list|(
specifier|const
name|u8
modifier|*
name|rsn_ie
parameter_list|,
name|size_t
name|rsn_ie_len
parameter_list|,
name|struct
name|wpa_ie_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_parse_wpa_ie_wpa
parameter_list|(
specifier|const
name|u8
modifier|*
name|wpa_ie
parameter_list|,
name|size_t
name|wpa_ie_len
parameter_list|,
name|struct
name|wpa_ie_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rsn_pmkid
parameter_list|(
specifier|const
name|u8
modifier|*
name|pmk
parameter_list|,
name|size_t
name|pmk_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|aa
parameter_list|,
specifier|const
name|u8
modifier|*
name|spa
parameter_list|,
name|u8
modifier|*
name|pmkid
parameter_list|,
name|int
name|use_sha256
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_SUITEB
end_ifdef

begin_function_decl
name|int
name|rsn_pmkid_suite_b
parameter_list|(
specifier|const
name|u8
modifier|*
name|kck
parameter_list|,
name|size_t
name|kck_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|aa
parameter_list|,
specifier|const
name|u8
modifier|*
name|spa
parameter_list|,
name|u8
modifier|*
name|pmkid
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_SUITEB */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|rsn_pmkid_suite_b
parameter_list|(
specifier|const
name|u8
modifier|*
name|kck
parameter_list|,
name|size_t
name|kck_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|aa
parameter_list|,
specifier|const
name|u8
modifier|*
name|spa
parameter_list|,
name|u8
modifier|*
name|pmkid
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_SUITEB */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_SUITEB192
end_ifdef

begin_function_decl
name|int
name|rsn_pmkid_suite_b_192
parameter_list|(
specifier|const
name|u8
modifier|*
name|kck
parameter_list|,
name|size_t
name|kck_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|aa
parameter_list|,
specifier|const
name|u8
modifier|*
name|spa
parameter_list|,
name|u8
modifier|*
name|pmkid
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_SUITEB192 */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|rsn_pmkid_suite_b_192
parameter_list|(
specifier|const
name|u8
modifier|*
name|kck
parameter_list|,
name|size_t
name|kck_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|aa
parameter_list|,
specifier|const
name|u8
modifier|*
name|spa
parameter_list|,
name|u8
modifier|*
name|pmkid
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_SUITEB192 */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|wpa_cipher_txt
parameter_list|(
name|int
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|wpa_key_mgmt_txt
parameter_list|(
name|int
name|key_mgmt
parameter_list|,
name|int
name|proto
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u32
name|wpa_akm_to_suite
parameter_list|(
name|int
name|akm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_compare_rsn_ie
parameter_list|(
name|int
name|ft_initial_assoc
parameter_list|,
specifier|const
name|u8
modifier|*
name|ie1
parameter_list|,
name|size_t
name|ie1len
parameter_list|,
specifier|const
name|u8
modifier|*
name|ie2
parameter_list|,
name|size_t
name|ie2len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_insert_pmkid
parameter_list|(
name|u8
modifier|*
name|ies
parameter_list|,
name|size_t
name|ies_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|pmkid
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|wpa_ft_ies
block|{
specifier|const
name|u8
modifier|*
name|mdie
decl_stmt|;
name|size_t
name|mdie_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|ftie
decl_stmt|;
name|size_t
name|ftie_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|r1kh_id
decl_stmt|;
specifier|const
name|u8
modifier|*
name|gtk
decl_stmt|;
name|size_t
name|gtk_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|r0kh_id
decl_stmt|;
name|size_t
name|r0kh_id_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|rsn
decl_stmt|;
name|size_t
name|rsn_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|rsn_pmkid
decl_stmt|;
specifier|const
name|u8
modifier|*
name|tie
decl_stmt|;
name|size_t
name|tie_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|igtk
decl_stmt|;
name|size_t
name|igtk_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|ric
decl_stmt|;
name|size_t
name|ric_len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|wpa_ft_parse_ies
parameter_list|(
specifier|const
name|u8
modifier|*
name|ies
parameter_list|,
name|size_t
name|ies_len
parameter_list|,
name|struct
name|wpa_ft_ies
modifier|*
name|parse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_cipher_key_len
parameter_list|(
name|int
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_cipher_rsc_len
parameter_list|(
name|int
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_cipher_to_alg
parameter_list|(
name|int
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_cipher_valid_group
parameter_list|(
name|int
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_cipher_valid_pairwise
parameter_list|(
name|int
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_cipher_valid_mgmt_group
parameter_list|(
name|int
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u32
name|wpa_cipher_to_suite
parameter_list|(
name|int
name|proto
parameter_list|,
name|int
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rsn_cipher_put_suites
parameter_list|(
name|u8
modifier|*
name|pos
parameter_list|,
name|int
name|ciphers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_cipher_put_suites
parameter_list|(
name|u8
modifier|*
name|pos
parameter_list|,
name|int
name|ciphers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_pick_pairwise_cipher
parameter_list|(
name|int
name|ciphers
parameter_list|,
name|int
name|none_allowed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_pick_group_cipher
parameter_list|(
name|int
name|ciphers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_parse_cipher
parameter_list|(
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_write_ciphers
parameter_list|(
name|char
modifier|*
name|start
parameter_list|,
name|char
modifier|*
name|end
parameter_list|,
name|int
name|ciphers
parameter_list|,
specifier|const
name|char
modifier|*
name|delim
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_select_ap_group_cipher
parameter_list|(
name|int
name|wpa
parameter_list|,
name|int
name|wpa_pairwise
parameter_list|,
name|int
name|rsn_pairwise
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|wpa_mic_len
parameter_list|(
name|int
name|akmp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPA_COMMON_H */
end_comment

end_unit

