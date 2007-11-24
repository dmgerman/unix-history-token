begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / Network configuration structures  * Copyright (c) 2003-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_SSID_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_SSID_H
end_define

begin_define
define|#
directive|define
name|WPA_CIPHER_NONE
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WPA_CIPHER_WEP40
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WPA_CIPHER_WEP104
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WPA_CIPHER_TKIP
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WPA_CIPHER_CCMP
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_IEEE8021X
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_PSK
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_NONE
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_IEEE8021X_NO_WPA
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_WPA_NONE
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|WPA_PROTO_WPA
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WPA_PROTO_RSN
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WPA_AUTH_ALG_OPEN
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WPA_AUTH_ALG_SHARED
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WPA_AUTH_ALG_LEAP
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|MAX_SSID_LEN
value|32
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
name|EAP_PSK_LEN
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_EAP_WORKAROUND
value|((unsigned int) -1)
end_define

begin_define
define|#
directive|define
name|DEFAULT_EAPOL_FLAGS
value|(EAPOL_FLAG_REQUIRE_KEY_UNICAST | \ 			     EAPOL_FLAG_REQUIRE_KEY_BROADCAST)
end_define

begin_define
define|#
directive|define
name|DEFAULT_PROTO
value|(WPA_PROTO_WPA | WPA_PROTO_RSN)
end_define

begin_define
define|#
directive|define
name|DEFAULT_KEY_MGMT
value|(WPA_KEY_MGMT_PSK | WPA_KEY_MGMT_IEEE8021X)
end_define

begin_define
define|#
directive|define
name|DEFAULT_PAIRWISE
value|(WPA_CIPHER_CCMP | WPA_CIPHER_TKIP)
end_define

begin_define
define|#
directive|define
name|DEFAULT_GROUP
value|(WPA_CIPHER_CCMP | WPA_CIPHER_TKIP | \ 		       WPA_CIPHER_WEP104 | WPA_CIPHER_WEP40)
end_define

begin_comment
comment|/**  * struct wpa_ssid - Network configuration data  *  * This structure includes all the configuration variables for a network. This  * data is included in the per-interface configuration data as an element of  * the network list, struct wpa_config::ssid. Each network block in the  * configuration is mapped to a struct wpa_ssid instance.  */
end_comment

begin_struct
struct|struct
name|wpa_ssid
block|{
comment|/** 	 * next - Next network in global list 	 * 	 * This pointer can be used to iterate over all networks. The head of 	 * this list is stored in the ssid field of struct wpa_config. 	 */
name|struct
name|wpa_ssid
modifier|*
name|next
decl_stmt|;
comment|/** 	 * pnext - Next network in per-priority list 	 * 	 * This pointer can be used to iterate over all networks in the same 	 * priority class. The heads of these list are stored in the pssid 	 * fields of struct wpa_config. 	 */
name|struct
name|wpa_ssid
modifier|*
name|pnext
decl_stmt|;
comment|/** 	 * id - Unique id for the network 	 * 	 * This identifier is used as a unique identifier for each network 	 * block when using the control interface. Each network is allocated an 	 * id when it is being created, either when reading the configuration 	 * file or when a new network is added through the control interface. 	 */
name|int
name|id
decl_stmt|;
comment|/** 	 * priority - Priority group 	 * 	 * By default, all networks will get same priority group (0). If some 	 * of the networks are more desirable, this field can be used to change 	 * the order in which wpa_supplicant goes through the networks when 	 * selecting a BSS. The priority groups will be iterated in decreasing 	 * priority (i.e., the larger the priority value, the sooner the 	 * network is matched against the scan results). Within each priority 	 * group, networks will be selected based on security policy, signal 	 * strength, etc. 	 * 	 * Please note that AP scanning with scan_ssid=1 and ap_scan=2 mode are 	 * not using this priority to select the order for scanning. Instead, 	 * they try the networks in the order that used in the configuration 	 * file. 	 */
name|int
name|priority
decl_stmt|;
comment|/** 	 * ssid - Service set identifier (network name) 	 * 	 * This is the SSID for the network. For wireless interfaces, this is 	 * used to select which network will be used. If set to %NULL (or 	 * ssid_len=0), any SSID can be used. For wired interfaces, this must 	 * be set to %NULL. Note: SSID may contain any characters, even nul 	 * (ASCII 0) and as such, this should not be assumed to be a nul 	 * terminated string. ssid_len defines how many characters are valid 	 * and the ssid field is not guaranteed to be nul terminated. 	 */
name|u8
modifier|*
name|ssid
decl_stmt|;
comment|/** 	 * ssid_len - Length of the SSID 	 */
name|size_t
name|ssid_len
decl_stmt|;
comment|/** 	 * bssid - BSSID 	 * 	 * If set, this network block is used only when associating with the AP 	 * using the configured BSSID 	 */
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** 	 * bssid_set - Whether BSSID is configured for this network 	 */
name|int
name|bssid_set
decl_stmt|;
comment|/** 	 * psk - WPA pre-shared key (256 bits) 	 */
name|u8
name|psk
index|[
name|PMK_LEN
index|]
decl_stmt|;
comment|/** 	 * psk_set - Whether PSK field is configured 	 */
name|int
name|psk_set
decl_stmt|;
comment|/** 	 * passphrase - WPA ASCII passphrase 	 * 	 * If this is set, psk will be generated using the SSID and passphrase 	 * configured for the network. ASCII passphrase must be between 8 and 	 * 63 characters (inclusive). 	 */
name|char
modifier|*
name|passphrase
decl_stmt|;
comment|/** 	 * pairwise_cipher - Bitfield of allowed pairwise ciphers, WPA_CIPHER_* 	 */
name|int
name|pairwise_cipher
decl_stmt|;
comment|/** 	 * group_cipher - Bitfield of allowed group ciphers, WPA_CIPHER_* 	 */
name|int
name|group_cipher
decl_stmt|;
comment|/** 	 * key_mgmt - Bitfield of allowed key management protocols 	 * 	 * WPA_KEY_MGMT_* 	 */
name|int
name|key_mgmt
decl_stmt|;
comment|/** 	 * proto - Bitfield of allowed protocols, WPA_PROTO_* 	 */
name|int
name|proto
decl_stmt|;
comment|/** 	 * auth_alg -  Bitfield of allowed authentication algorithms 	 * 	 * WPA_AUTH_ALG_* 	 */
name|int
name|auth_alg
decl_stmt|;
comment|/** 	 * scan_ssid - Scan this SSID with Probe Requests 	 * 	 * scan_ssid can be used to scan for APs using hidden SSIDs. 	 * Note: Many drivers do not support this. ap_mode=2 can be used with 	 * such drivers to use hidden SSIDs. 	 */
name|int
name|scan_ssid
decl_stmt|;
comment|/** 	 * identity - EAP Identity 	 */
name|u8
modifier|*
name|identity
decl_stmt|;
comment|/** 	 * identity_len - EAP Identity length 	 */
name|size_t
name|identity_len
decl_stmt|;
comment|/** 	 * anonymous_identity -  Anonymous EAP Identity 	 * 	 * This field is used for unencrypted use with EAP types that support 	 * different tunnelled identity, e.g., EAP-TTLS, in order to reveal the 	 * real identity (identity field) only to the authentication server. 	 */
name|u8
modifier|*
name|anonymous_identity
decl_stmt|;
comment|/** 	 * anonymous_identity_len - Length of anonymous_identity 	 */
name|size_t
name|anonymous_identity_len
decl_stmt|;
comment|/** 	 * eappsk - EAP-PSK pre-shared key 	 */
name|u8
modifier|*
name|eappsk
decl_stmt|;
comment|/** 	 * eappsk_len - EAP-PSK pre-shared key length 	 * 	 * This field is always 16 for the current version of EAP-PSK. 	 */
name|size_t
name|eappsk_len
decl_stmt|;
comment|/** 	 * nai - User NAI (for EAP-PSK) 	 */
name|u8
modifier|*
name|nai
decl_stmt|;
comment|/** 	 * nai_len - Length of nai field 	 */
name|size_t
name|nai_len
decl_stmt|;
comment|/** 	 * password - Password string for EAP 	 */
name|u8
modifier|*
name|password
decl_stmt|;
comment|/** 	 * password_len - Length of password field 	 */
name|size_t
name|password_len
decl_stmt|;
comment|/** 	 * ca_cert - File path to CA certificate file (PEM/DER) 	 * 	 * This file can have one or more trusted CA certificates. If ca_cert 	 * and ca_path are not included, server certificate will not be 	 * verified. This is insecure and a trusted CA certificate should 	 * always be configured when using EAP-TLS/TTLS/PEAP. Full path to the 	 * file should be used since working directory may change when 	 * wpa_supplicant is run in the background. 	 * 	 * Alternatively, a named configuration blob can be used by setting 	 * this to blob://<blob name>. 	 * 	 * On Windows, trusted CA certificates can be loaded from the system 	 * certificate store by setting this to cert_store://<name>, e.g., 	 * ca_cert="cert_store://CA" or ca_cert="cert_store://ROOT". 	 */
name|u8
modifier|*
name|ca_cert
decl_stmt|;
comment|/** 	 * ca_path - Directory path for CA certificate files (PEM) 	 * 	 * This path may contain multiple CA certificates in OpenSSL format. 	 * Common use for this is to point to system trusted CA list which is 	 * often installed into directory like /etc/ssl/certs. If configured, 	 * these certificates are added to the list of trusted CAs. ca_cert 	 * may also be included in that case, but it is not required. 	 */
name|u8
modifier|*
name|ca_path
decl_stmt|;
comment|/** 	 * client_cert - File path to client certificate file (PEM/DER) 	 * 	 * This field is used with EAP method that use TLS authentication. 	 * Usually, this is only configured for EAP-TLS, even though this could 	 * in theory be used with EAP-TTLS and EAP-PEAP, too. Full path to the 	 * file should be used since working directory may change when 	 * wpa_supplicant is run in the background. 	 * 	 * Alternatively, a named configuration blob can be used by setting 	 * this to blob://<blob name>. 	 */
name|u8
modifier|*
name|client_cert
decl_stmt|;
comment|/** 	 * private_key - File path to client private key file (PEM/DER/PFX) 	 * 	 * When PKCS#12/PFX file (.p12/.pfx) is used, client_cert should be 	 * commented out. Both the private key and certificate will be read 	 * from the PKCS#12 file in this case. Full path to the file should be 	 * used since working directory may change when wpa_supplicant is run 	 * in the background. 	 * 	 * Windows certificate store can be used by leaving client_cert out and 	 * configuring private_key in one of the following formats: 	 * 	 * cert://substring_to_match 	 * 	 * hash://certificate_thumbprint_in_hex 	 * 	 * For example: private_key="hash://63093aa9c47f56ae88334c7b65a4" 	 * 	 * Alternatively, a named configuration blob can be used by setting 	 * this to blob://<blob name>. 	 */
name|u8
modifier|*
name|private_key
decl_stmt|;
comment|/** 	 * private_key_passwd - Password for private key file 	 * 	 * If left out, this will be asked through control interface. 	 */
name|u8
modifier|*
name|private_key_passwd
decl_stmt|;
comment|/** 	 * dh_file - File path to DH/DSA parameters file (in PEM format) 	 * 	 * This is an optional configuration file for setting parameters for an 	 * ephemeral DH key exchange. In most cases, the default RSA 	 * authentication does not use this configuration. However, it is 	 * possible setup RSA to use ephemeral DH key exchange. In addition, 	 * ciphers with DSA keys always use ephemeral DH keys. This can be used 	 * to achieve forward secrecy. If the file is in DSA parameters format, 	 * it will be automatically converted into DH params. Full path to the 	 * file should be used since working directory may change when 	 * wpa_supplicant is run in the background. 	 * 	 * Alternatively, a named configuration blob can be used by setting 	 * this to blob://<blob name>. 	 */
name|u8
modifier|*
name|dh_file
decl_stmt|;
comment|/** 	 * subject_match - Constraint for server certificate subject 	 * 	 * This substring is matched against the subject of the authentication 	 * server certificate. If this string is set, the server sertificate is 	 * only accepted if it contains this string in the subject. The subject 	 * string is in following format: 	 * 	 * /C=US/ST=CA/L=San Francisco/CN=Test AS/emailAddress=as@n.example.com 	 */
name|u8
modifier|*
name|subject_match
decl_stmt|;
comment|/** 	 * altsubject_match - Constraint for server certificate alt. subject 	 * 	 * This substring is matched against the alternative subject name of 	 * the authentication server certificate. If this string is set, the 	 * server sertificate is only accepted if it contains this string in an 	 * alternative subject name extension. 	 * 	 * altSubjectName string is in following format: TYPE:VALUE 	 * 	 * Example: DNS:server.example.com 	 * 	 * Following types are supported: EMAIL, DNS, URI 	 */
name|u8
modifier|*
name|altsubject_match
decl_stmt|;
comment|/** 	 * ca_cert2 - File path to CA certificate file (PEM/DER) (Phase 2) 	 * 	 * This file can have one or more trusted CA certificates. If ca_cert2 	 * and ca_path2 are not included, server certificate will not be 	 * verified. This is insecure and a trusted CA certificate should 	 * always be configured. Full path to the file should be used since 	 * working directory may change when wpa_supplicant is run in the 	 * background. 	 * 	 * This field is like ca_cert, but used for phase 2 (inside 	 * EAP-TTLS/PEAP/FAST tunnel) authentication. 	 * 	 * Alternatively, a named configuration blob can be used by setting 	 * this to blob://<blob name>. 	 */
name|u8
modifier|*
name|ca_cert2
decl_stmt|;
comment|/** 	 * ca_path2 - Directory path for CA certificate files (PEM) (Phase 2) 	 * 	 * This path may contain multiple CA certificates in OpenSSL format. 	 * Common use for this is to point to system trusted CA list which is 	 * often installed into directory like /etc/ssl/certs. If configured, 	 * these certificates are added to the list of trusted CAs. ca_cert 	 * may also be included in that case, but it is not required. 	 * 	 * This field is like ca_path, but used for phase 2 (inside 	 * EAP-TTLS/PEAP/FAST tunnel) authentication. 	 */
name|u8
modifier|*
name|ca_path2
decl_stmt|;
comment|/** 	 * client_cert2 - File path to client certificate file 	 * 	 * This field is like client_cert, but used for phase 2 (inside 	 * EAP-TTLS/PEAP/FAST tunnel) authentication. Full path to the 	 * file should be used since working directory may change when 	 * wpa_supplicant is run in the background. 	 * 	 * Alternatively, a named configuration blob can be used by setting 	 * this to blob://<blob name>. 	 */
name|u8
modifier|*
name|client_cert2
decl_stmt|;
comment|/** 	 * private_key2 - File path to client private key file 	 * 	 * This field is like private_key, but used for phase 2 (inside 	 * EAP-TTLS/PEAP/FAST tunnel) authentication. Full path to the 	 * file should be used since working directory may change when 	 * wpa_supplicant is run in the background. 	 * 	 * Alternatively, a named configuration blob can be used by setting 	 * this to blob://<blob name>. 	 */
name|u8
modifier|*
name|private_key2
decl_stmt|;
comment|/** 	 * private_key2_passwd -  Password for private key file 	 * 	 * This field is like private_key_passwd, but used for phase 2 (inside 	 * EAP-TTLS/PEAP/FAST tunnel) authentication. 	 */
name|u8
modifier|*
name|private_key2_passwd
decl_stmt|;
comment|/** 	 * dh_file2 - File path to DH/DSA parameters file (in PEM format) 	 * 	 * This field is like dh_file, but used for phase 2 (inside 	 * EAP-TTLS/PEAP/FAST tunnel) authentication. Full path to the 	 * file should be used since working directory may change when 	 * wpa_supplicant is run in the background. 	 * 	 * Alternatively, a named configuration blob can be used by setting 	 * this to blob://<blob name>. 	 */
name|u8
modifier|*
name|dh_file2
decl_stmt|;
comment|/** 	 * subject_match2 - Constraint for server certificate subject 	 * 	 * This field is like subject_match, but used for phase 2 (inside 	 * EAP-TTLS/PEAP/FAST tunnel) authentication. 	 */
name|u8
modifier|*
name|subject_match2
decl_stmt|;
comment|/** 	 * altsubject_match2 - Constraint for server certificate alt. subject 	 * 	 * This field is like altsubject_match, but used for phase 2 (inside 	 * EAP-TTLS/PEAP/FAST tunnel) authentication. 	 */
name|u8
modifier|*
name|altsubject_match2
decl_stmt|;
comment|/** 	 * eap_methods - Allowed EAP methods 	 * 	 * Zero (EAP_TYPE_NONE) terminated list of allowed EAP methods or %NULL 	 * if all methods are accepted. 	 */
name|u8
modifier|*
name|eap_methods
decl_stmt|;
comment|/** 	 * phase1 - Phase 1 (outer authentication) parameters 	 * 	 * String with field-value pairs, e.g., "peapver=0" or 	 * "peapver=1 peaplabel=1". 	 * 	 * 'peapver' can be used to force which PEAP version (0 or 1) is used. 	 * 	 * 'peaplabel=1' can be used to force new label, "client PEAP 	 * encryption",	to be used during key derivation when PEAPv1 or newer. 	 * 	 * Most existing PEAPv1 implementation seem to be using the old label, 	 * "client EAP encryption", and wpa_supplicant is now using that as the 	 * default value. 	 * 	 * Some servers, e.g., Radiator, may require peaplabel=1 configuration 	 * to interoperate with PEAPv1; see eap_testing.txt for more details. 	 * 	 * 'peap_outer_success=0' can be used to terminate PEAP authentication 	 * on tunneled EAP-Success. This is required with some RADIUS servers 	 * that implement draft-josefsson-pppext-eap-tls-eap-05.txt (e.g., 	 * Lucent NavisRadius v4.4.0 with PEAP in "IETF Draft 5" mode). 	 * 	 * include_tls_length=1 can be used to force wpa_supplicant to include 	 * TLS Message Length field in all TLS messages even if they are not 	 * fragmented. 	 * 	 * sim_min_num_chal=3 can be used to configure EAP-SIM to require three 	 * challenges (by default, it accepts 2 or 3). 	 * 	 * fast_provisioning=1 can be used to enable in-line provisioning of 	 * EAP-FAST credentials (PAC) 	 */
name|char
modifier|*
name|phase1
decl_stmt|;
comment|/** 	 * phase2 - Phase2 (inner authentication with TLS tunnel) parameters 	 * 	 * String with field-value pairs, e.g., "auth=MSCHAPV2" for EAP-PEAP or 	 * "autheap=MSCHAPV2 autheap=MD5" for EAP-TTLS. 	 */
name|char
modifier|*
name|phase2
decl_stmt|;
comment|/** 	 * pcsc - Parameters for PC/SC smartcard interface for USIM and GSM SIM 	 * 	 * This field is used to configure PC/SC smartcard interface. 	 * Currently, the only configuration is whether this field is %NULL (do 	 * not use PC/SC) or non-NULL (e.g., "") to enable PC/SC. 	 * 	 * This field is used for EAP-SIM and EAP-AKA. 	 */
name|char
modifier|*
name|pcsc
decl_stmt|;
comment|/** 	 * pin - PIN for USIM, GSM SIM, and smartcards 	 * 	 * This field is used to configure PIN for SIM and smartcards for 	 * EAP-SIM and EAP-AKA. In addition, this is used with EAP-TLS if a 	 * smartcard is used for private key operations. 	 * 	 * If left out, this will be asked through control interface. 	 */
name|char
modifier|*
name|pin
decl_stmt|;
comment|/** 	 * engine - Enable OpenSSL engine (e.g., for smartcard access) 	 * 	 * This is used if private key operations for EAP-TLS are performed 	 * using a smartcard. 	 */
name|int
name|engine
decl_stmt|;
comment|/** 	 * engine_id - Engine ID for OpenSSL engine 	 * 	 * "opensc" to select OpenSC engine or "pkcs11" to select PKCS#11 	 * engine. 	 * 	 * This is used if private key operations for EAP-TLS are performed 	 * using a smartcard. 	 */
name|char
modifier|*
name|engine_id
decl_stmt|;
comment|/** 	 * key_id - Key ID for OpenSSL engine 	 * 	 * This is used if private key operations for EAP-TLS are performed 	 * using a smartcard. 	 */
name|char
modifier|*
name|key_id
decl_stmt|;
define|#
directive|define
name|EAPOL_FLAG_REQUIRE_KEY_UNICAST
value|BIT(0)
define|#
directive|define
name|EAPOL_FLAG_REQUIRE_KEY_BROADCAST
value|BIT(1)
comment|/** 	 * eapol_flags - Bit field of IEEE 802.1X/EAPOL options (EAPOL_FLAG_*) 	 */
name|int
name|eapol_flags
decl_stmt|;
define|#
directive|define
name|NUM_WEP_KEYS
value|4
define|#
directive|define
name|MAX_WEP_KEY_LEN
value|16
comment|/** 	 * wep_key - WEP keys 	 */
name|u8
name|wep_key
index|[
name|NUM_WEP_KEYS
index|]
index|[
name|MAX_WEP_KEY_LEN
index|]
decl_stmt|;
comment|/** 	 * wep_key_len - WEP key lengths 	 */
name|size_t
name|wep_key_len
index|[
name|NUM_WEP_KEYS
index|]
decl_stmt|;
comment|/** 	 * wep_tx_keyidx - Default key index for TX frames using WEP 	 */
name|int
name|wep_tx_keyidx
decl_stmt|;
comment|/** 	 * proactive_key_caching - Enable proactive key caching 	 * 	 * This field can be used to enable proactive key caching which is also 	 * known as opportunistic PMKSA caching for WPA2. This is disabled (0) 	 * by default. Enable by setting this to 1. 	 * 	 * Proactive key caching is used to make supplicant assume that the APs 	 * are using the same PMK and generate PMKSA cache entries without 	 * doing RSN pre-authentication. This requires support from the AP side 	 * and is normally used with wireless switches that co-locate the 	 * authenticator. 	 */
name|int
name|proactive_key_caching
decl_stmt|;
comment|/** 	 * otp - One-time-password 	 * 	 * This field should not be set in configuration step. It is only used 	 * internally when OTP is entered through the control interface. 	 */
name|u8
modifier|*
name|otp
decl_stmt|;
comment|/** 	 * otp_len - Length of the otp field 	 */
name|size_t
name|otp_len
decl_stmt|;
comment|/** 	 * pending_req_identity - Whether there is a pending identity request 	 * 	 * This field should not be set in configuration step. It is only used 	 * internally when control interface is used to request needed 	 * information. 	 */
name|int
name|pending_req_identity
decl_stmt|;
comment|/** 	 * pending_req_password - Whether there is a pending password request 	 * 	 * This field should not be set in configuration step. It is only used 	 * internally when control interface is used to request needed 	 * information. 	 */
name|int
name|pending_req_password
decl_stmt|;
comment|/** 	 * pending_req_pin - Whether there is a pending PIN request 	 * 	 * This field should not be set in configuration step. It is only used 	 * internally when control interface is used to request needed 	 * information. 	 */
name|int
name|pending_req_pin
decl_stmt|;
comment|/** 	 * pending_req_new_password - Pending password update request 	 * 	 * This field should not be set in configuration step. It is only used 	 * internally when control interface is used to request needed 	 * information. 	 */
name|int
name|pending_req_new_password
decl_stmt|;
comment|/** 	 * pending_req_passphrase - Pending passphrase request 	 * 	 * This field should not be set in configuration step. It is only used 	 * internally when control interface is used to request needed 	 * information. 	 */
name|int
name|pending_req_passphrase
decl_stmt|;
comment|/** 	 * pending_req_otp - Whether there is a pending OTP request 	 * 	 * This field should not be set in configuration step. It is only used 	 * internally when control interface is used to request needed 	 * information. 	 */
name|char
modifier|*
name|pending_req_otp
decl_stmt|;
comment|/** 	 * pending_req_otp_len - Length of the pending OTP request 	 */
name|size_t
name|pending_req_otp_len
decl_stmt|;
comment|/** 	 * leap - Number of EAP methods using LEAP 	 * 	 * This field should be set to 1 if LEAP is enabled. This is used to 	 * select IEEE 802.11 authentication algorithm. 	 */
name|int
name|leap
decl_stmt|;
comment|/** 	 * non_leap - Number of EAP methods not using LEAP 	 * 	 * This field should be set to>0 if any EAP method other than LEAP is 	 * enabled. This is used to select IEEE 802.11 authentication 	 * algorithm. 	 */
name|int
name|non_leap
decl_stmt|;
comment|/** 	 * eap_workaround - EAP workarounds enabled 	 * 	 * wpa_supplicant supports number of "EAP workarounds" to work around 	 * interoperability issues with incorrectly behaving authentication 	 * servers. This is recommended to be enabled by default because some 	 * of the issues are present in large number of authentication servers. 	 * 	 * Strict EAP conformance mode can be configured by disabling 	 * workarounds with eap_workaround = 0. 	 */
name|unsigned
name|int
name|eap_workaround
decl_stmt|;
comment|/** 	 * pac_file - File path or blob name for the PAC entries (EAP-FAST) 	 * 	 * wpa_supplicant will need to be able to create this file and write 	 * updates to it when PAC is being provisioned or refreshed. Full path 	 * to the file should be used since working directory may change when 	 * wpa_supplicant is run in the background. 	 * Alternatively, a named configuration blob can be used by setting 	 * this to blob://<blob name>. 	 */
name|char
modifier|*
name|pac_file
decl_stmt|;
comment|/** 	 * mode - IEEE 802.11 operation mode (Infrastucture/IBSS) 	 * 	 * 0 = infrastructure (Managed) mode, i.e., associate with an AP. 	 * 	 * 1 = IBSS (ad-hoc, peer-to-peer) 	 * 	 * Note: IBSS can only be used with key_mgmt NONE (plaintext and 	 * static WEP) and key_mgmt=WPA-NONE (fixed group key TKIP/CCMP). In 	 * addition, ap_scan has to be set to 2 for IBSS. WPA-None requires 	 * following network block options: proto=WPA, key_mgmt=WPA-NONE, 	 * pairwise=NONE, group=TKIP (or CCMP, but not both), and psk must also 	 * be set (either directly or using ASCII passphrase). 	 */
name|int
name|mode
decl_stmt|;
comment|/** 	 * mschapv2_retry - MSCHAPv2 retry in progress 	 * 	 * This field is used internally by EAP-MSCHAPv2 and should not be set 	 * as part of configuration. 	 */
name|int
name|mschapv2_retry
decl_stmt|;
comment|/** 	 * new_password - New password for password update 	 * 	 * This field is used during MSCHAPv2 password update. This is normally 	 * requested from the user through the control interface and not set 	 * from configuration. 	 */
name|u8
modifier|*
name|new_password
decl_stmt|;
comment|/** 	 * new_password_len - Length of new_password field 	 */
name|size_t
name|new_password_len
decl_stmt|;
comment|/** 	 * disabled - Whether this network is currently disabled 	 * 	 * 0 = this network can be used (default). 	 * 1 = this network block is disabled (can be enabled through 	 * ctrl_iface, e.g., with wpa_cli or wpa_gui). 	 */
name|int
name|disabled
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|wpa_config_allowed_eap_method
parameter_list|(
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|,
name|int
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_SSID_H */
end_comment

end_unit

