begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002-2005 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_IOCTL_H_
end_define

begin_comment
comment|/*  * IEEE 802.11 ioctls.  */
end_comment

begin_include
include|#
directive|include
file|<net80211/_ieee80211.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_crypto.h>
end_include

begin_comment
comment|/*  * Per/node (station) statistics available when operating as an AP.  */
end_comment

begin_struct
struct|struct
name|ieee80211_nodestats
block|{
name|u_int32_t
name|ns_rx_data
decl_stmt|;
comment|/* rx data frames */
name|u_int32_t
name|ns_rx_mgmt
decl_stmt|;
comment|/* rx management frames */
name|u_int32_t
name|ns_rx_ctrl
decl_stmt|;
comment|/* rx control frames */
name|u_int32_t
name|ns_rx_ucast
decl_stmt|;
comment|/* rx unicast frames */
name|u_int32_t
name|ns_rx_mcast
decl_stmt|;
comment|/* rx multi/broadcast frames */
name|u_int64_t
name|ns_rx_bytes
decl_stmt|;
comment|/* rx data count (bytes) */
name|u_int64_t
name|ns_rx_beacons
decl_stmt|;
comment|/* rx beacon frames */
name|u_int32_t
name|ns_rx_proberesp
decl_stmt|;
comment|/* rx probe response frames */
name|u_int32_t
name|ns_rx_dup
decl_stmt|;
comment|/* rx discard 'cuz dup */
name|u_int32_t
name|ns_rx_noprivacy
decl_stmt|;
comment|/* rx w/ wep but privacy off */
name|u_int32_t
name|ns_rx_wepfail
decl_stmt|;
comment|/* rx wep processing failed */
name|u_int32_t
name|ns_rx_demicfail
decl_stmt|;
comment|/* rx demic failed */
name|u_int32_t
name|ns_rx_decap
decl_stmt|;
comment|/* rx decapsulation failed */
name|u_int32_t
name|ns_rx_defrag
decl_stmt|;
comment|/* rx defragmentation failed */
name|u_int32_t
name|ns_rx_disassoc
decl_stmt|;
comment|/* rx disassociation */
name|u_int32_t
name|ns_rx_deauth
decl_stmt|;
comment|/* rx deauthentication */
name|u_int32_t
name|ns_rx_decryptcrc
decl_stmt|;
comment|/* rx decrypt failed on crc */
name|u_int32_t
name|ns_rx_unauth
decl_stmt|;
comment|/* rx on unauthorized port */
name|u_int32_t
name|ns_rx_unencrypted
decl_stmt|;
comment|/* rx unecrypted w/ privacy */
name|u_int32_t
name|ns_tx_data
decl_stmt|;
comment|/* tx data frames */
name|u_int32_t
name|ns_tx_mgmt
decl_stmt|;
comment|/* tx management frames */
name|u_int32_t
name|ns_tx_ucast
decl_stmt|;
comment|/* tx unicast frames */
name|u_int32_t
name|ns_tx_mcast
decl_stmt|;
comment|/* tx multi/broadcast frames */
name|u_int64_t
name|ns_tx_bytes
decl_stmt|;
comment|/* tx data count (bytes) */
name|u_int32_t
name|ns_tx_probereq
decl_stmt|;
comment|/* tx probe request frames */
name|u_int32_t
name|ns_tx_novlantag
decl_stmt|;
comment|/* tx discard 'cuz no tag */
name|u_int32_t
name|ns_tx_vlanmismatch
decl_stmt|;
comment|/* tx discard 'cuz bad tag */
name|u_int32_t
name|ns_ps_discard
decl_stmt|;
comment|/* ps discard 'cuz of age */
comment|/* MIB-related state */
name|u_int32_t
name|ns_tx_assoc
decl_stmt|;
comment|/* [re]associations */
name|u_int32_t
name|ns_tx_assoc_fail
decl_stmt|;
comment|/* [re]association failures */
name|u_int32_t
name|ns_tx_auth
decl_stmt|;
comment|/* [re]authentications */
name|u_int32_t
name|ns_tx_auth_fail
decl_stmt|;
comment|/* [re]authentication failures*/
name|u_int32_t
name|ns_tx_deauth
decl_stmt|;
comment|/* deauthentications */
name|u_int32_t
name|ns_tx_deauth_code
decl_stmt|;
comment|/* last deauth reason */
name|u_int32_t
name|ns_tx_disassoc
decl_stmt|;
comment|/* disassociations */
name|u_int32_t
name|ns_tx_disassoc_code
decl_stmt|;
comment|/* last disassociation reason */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Summary statistics.  */
end_comment

begin_struct
struct|struct
name|ieee80211_stats
block|{
name|u_int32_t
name|is_rx_badversion
decl_stmt|;
comment|/* rx frame with bad version */
name|u_int32_t
name|is_rx_tooshort
decl_stmt|;
comment|/* rx frame too short */
name|u_int32_t
name|is_rx_wrongbss
decl_stmt|;
comment|/* rx from wrong bssid */
name|u_int32_t
name|is_rx_dup
decl_stmt|;
comment|/* rx discard 'cuz dup */
name|u_int32_t
name|is_rx_wrongdir
decl_stmt|;
comment|/* rx w/ wrong direction */
name|u_int32_t
name|is_rx_mcastecho
decl_stmt|;
comment|/* rx discard 'cuz mcast echo */
name|u_int32_t
name|is_rx_notassoc
decl_stmt|;
comment|/* rx discard 'cuz sta !assoc */
name|u_int32_t
name|is_rx_noprivacy
decl_stmt|;
comment|/* rx w/ wep but privacy off */
name|u_int32_t
name|is_rx_unencrypted
decl_stmt|;
comment|/* rx w/o wep and privacy on */
name|u_int32_t
name|is_rx_wepfail
decl_stmt|;
comment|/* rx wep processing failed */
name|u_int32_t
name|is_rx_decap
decl_stmt|;
comment|/* rx decapsulation failed */
name|u_int32_t
name|is_rx_mgtdiscard
decl_stmt|;
comment|/* rx discard mgt frames */
name|u_int32_t
name|is_rx_ctl
decl_stmt|;
comment|/* rx discard ctrl frames */
name|u_int32_t
name|is_rx_beacon
decl_stmt|;
comment|/* rx beacon frames */
name|u_int32_t
name|is_rx_rstoobig
decl_stmt|;
comment|/* rx rate set truncated */
name|u_int32_t
name|is_rx_elem_missing
decl_stmt|;
comment|/* rx required element missing*/
name|u_int32_t
name|is_rx_elem_toobig
decl_stmt|;
comment|/* rx element too big */
name|u_int32_t
name|is_rx_elem_toosmall
decl_stmt|;
comment|/* rx element too small */
name|u_int32_t
name|is_rx_elem_unknown
decl_stmt|;
comment|/* rx element unknown */
name|u_int32_t
name|is_rx_badchan
decl_stmt|;
comment|/* rx frame w/ invalid chan */
name|u_int32_t
name|is_rx_chanmismatch
decl_stmt|;
comment|/* rx frame chan mismatch */
name|u_int32_t
name|is_rx_nodealloc
decl_stmt|;
comment|/* rx frame dropped */
name|u_int32_t
name|is_rx_ssidmismatch
decl_stmt|;
comment|/* rx frame ssid mismatch  */
name|u_int32_t
name|is_rx_auth_unsupported
decl_stmt|;
comment|/* rx w/ unsupported auth alg */
name|u_int32_t
name|is_rx_auth_fail
decl_stmt|;
comment|/* rx sta auth failure */
name|u_int32_t
name|is_rx_auth_countermeasures
decl_stmt|;
comment|/* rx auth discard 'cuz CM */
name|u_int32_t
name|is_rx_assoc_bss
decl_stmt|;
comment|/* rx assoc from wrong bssid */
name|u_int32_t
name|is_rx_assoc_notauth
decl_stmt|;
comment|/* rx assoc w/o auth */
name|u_int32_t
name|is_rx_assoc_capmismatch
decl_stmt|;
comment|/* rx assoc w/ cap mismatch */
name|u_int32_t
name|is_rx_assoc_norate
decl_stmt|;
comment|/* rx assoc w/ no rate match */
name|u_int32_t
name|is_rx_assoc_badwpaie
decl_stmt|;
comment|/* rx assoc w/ bad WPA IE */
name|u_int32_t
name|is_rx_deauth
decl_stmt|;
comment|/* rx deauthentication */
name|u_int32_t
name|is_rx_disassoc
decl_stmt|;
comment|/* rx disassociation */
name|u_int32_t
name|is_rx_badsubtype
decl_stmt|;
comment|/* rx frame w/ unknown subtype*/
name|u_int32_t
name|is_rx_nobuf
decl_stmt|;
comment|/* rx failed for lack of buf */
name|u_int32_t
name|is_rx_decryptcrc
decl_stmt|;
comment|/* rx decrypt failed on crc */
name|u_int32_t
name|is_rx_ahdemo_mgt
decl_stmt|;
comment|/* rx discard ahdemo mgt frame*/
name|u_int32_t
name|is_rx_bad_auth
decl_stmt|;
comment|/* rx bad auth request */
name|u_int32_t
name|is_rx_unauth
decl_stmt|;
comment|/* rx on unauthorized port */
name|u_int32_t
name|is_rx_badkeyid
decl_stmt|;
comment|/* rx w/ incorrect keyid */
name|u_int32_t
name|is_rx_ccmpreplay
decl_stmt|;
comment|/* rx seq# violation (CCMP) */
name|u_int32_t
name|is_rx_ccmpformat
decl_stmt|;
comment|/* rx format bad (CCMP) */
name|u_int32_t
name|is_rx_ccmpmic
decl_stmt|;
comment|/* rx MIC check failed (CCMP) */
name|u_int32_t
name|is_rx_tkipreplay
decl_stmt|;
comment|/* rx seq# violation (TKIP) */
name|u_int32_t
name|is_rx_tkipformat
decl_stmt|;
comment|/* rx format bad (TKIP) */
name|u_int32_t
name|is_rx_tkipmic
decl_stmt|;
comment|/* rx MIC check failed (TKIP) */
name|u_int32_t
name|is_rx_tkipicv
decl_stmt|;
comment|/* rx ICV check failed (TKIP) */
name|u_int32_t
name|is_rx_badcipher
decl_stmt|;
comment|/* rx failed 'cuz key type */
name|u_int32_t
name|is_rx_nocipherctx
decl_stmt|;
comment|/* rx failed 'cuz key !setup */
name|u_int32_t
name|is_rx_acl
decl_stmt|;
comment|/* rx discard 'cuz acl policy */
name|u_int32_t
name|is_tx_nobuf
decl_stmt|;
comment|/* tx failed for lack of buf */
name|u_int32_t
name|is_tx_nonode
decl_stmt|;
comment|/* tx failed for no node */
name|u_int32_t
name|is_tx_unknownmgt
decl_stmt|;
comment|/* tx of unknown mgt frame */
name|u_int32_t
name|is_tx_badcipher
decl_stmt|;
comment|/* tx failed 'cuz key type */
name|u_int32_t
name|is_tx_nodefkey
decl_stmt|;
comment|/* tx failed 'cuz no defkey */
name|u_int32_t
name|is_tx_noheadroom
decl_stmt|;
comment|/* tx failed 'cuz no space */
name|u_int32_t
name|is_tx_fragframes
decl_stmt|;
comment|/* tx frames fragmented */
name|u_int32_t
name|is_tx_frags
decl_stmt|;
comment|/* tx fragments created */
name|u_int32_t
name|is_scan_active
decl_stmt|;
comment|/* active scans started */
name|u_int32_t
name|is_scan_passive
decl_stmt|;
comment|/* passive scans started */
name|u_int32_t
name|is_node_timeout
decl_stmt|;
comment|/* nodes timed out inactivity */
name|u_int32_t
name|is_crypto_nomem
decl_stmt|;
comment|/* no memory for crypto ctx */
name|u_int32_t
name|is_crypto_tkip
decl_stmt|;
comment|/* tkip crypto done in s/w */
name|u_int32_t
name|is_crypto_tkipenmic
decl_stmt|;
comment|/* tkip en-MIC done in s/w */
name|u_int32_t
name|is_crypto_tkipdemic
decl_stmt|;
comment|/* tkip de-MIC done in s/w */
name|u_int32_t
name|is_crypto_tkipcm
decl_stmt|;
comment|/* tkip counter measures */
name|u_int32_t
name|is_crypto_ccmp
decl_stmt|;
comment|/* ccmp crypto done in s/w */
name|u_int32_t
name|is_crypto_wep
decl_stmt|;
comment|/* wep crypto done in s/w */
name|u_int32_t
name|is_crypto_setkey_cipher
decl_stmt|;
comment|/* cipher rejected key */
name|u_int32_t
name|is_crypto_setkey_nokey
decl_stmt|;
comment|/* no key index for setkey */
name|u_int32_t
name|is_crypto_delkey
decl_stmt|;
comment|/* driver key delete failed */
name|u_int32_t
name|is_crypto_badcipher
decl_stmt|;
comment|/* unknown cipher */
name|u_int32_t
name|is_crypto_nocipher
decl_stmt|;
comment|/* cipher not available */
name|u_int32_t
name|is_crypto_attachfail
decl_stmt|;
comment|/* cipher attach failed */
name|u_int32_t
name|is_crypto_swfallback
decl_stmt|;
comment|/* cipher fallback to s/w */
name|u_int32_t
name|is_crypto_keyfail
decl_stmt|;
comment|/* driver key alloc failed */
name|u_int32_t
name|is_crypto_enmicfail
decl_stmt|;
comment|/* en-MIC failed */
name|u_int32_t
name|is_ibss_capmismatch
decl_stmt|;
comment|/* merge failed-cap mismatch */
name|u_int32_t
name|is_ibss_norate
decl_stmt|;
comment|/* merge failed-rate mismatch */
name|u_int32_t
name|is_ps_unassoc
decl_stmt|;
comment|/* ps-poll for unassoc. sta */
name|u_int32_t
name|is_ps_badaid
decl_stmt|;
comment|/* ps-poll w/ incorrect aid */
name|u_int32_t
name|is_ps_qempty
decl_stmt|;
comment|/* ps-poll w/ nothing to send */
name|u_int32_t
name|is_ff_badhdr
decl_stmt|;
comment|/* fast frame rx'd w/ bad hdr */
name|u_int32_t
name|is_ff_tooshort
decl_stmt|;
comment|/* fast frame rx decap error */
name|u_int32_t
name|is_ff_split
decl_stmt|;
comment|/* fast frame rx split error */
name|u_int32_t
name|is_ff_decap
decl_stmt|;
comment|/* fast frames decap'd */
name|u_int32_t
name|is_ff_encap
decl_stmt|;
comment|/* fast frames encap'd for tx */
name|u_int32_t
name|is_rx_badbintval
decl_stmt|;
comment|/* rx frame w/ bogus bintval */
name|u_int32_t
name|is_spare
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Max size of optional information elements.  We artificially  * constrain this; it's limited only by the max frame size (and  * the max parameter size of the wireless extensions).  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MAX_OPT_IE
value|256
end_define

begin_comment
comment|/*  * WPA/RSN get/set key request.  Specify the key/cipher  * type and whether the key is to be used for sending and/or  * receiving.  The key index should be set only when working  * with global keys (use IEEE80211_KEYIX_NONE for ``no index'').  * Otherwise a unicast/pairwise key is specified by the bssid  * (on a station) or mac address (on an ap).  They key length  * must include any MIC key data; otherwise it should be no  more than IEEE80211_KEYBUF_SIZE.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_key
block|{
name|u_int8_t
name|ik_type
decl_stmt|;
comment|/* key/cipher type */
name|u_int8_t
name|ik_pad
decl_stmt|;
name|u_int16_t
name|ik_keyix
decl_stmt|;
comment|/* key index */
name|u_int8_t
name|ik_keylen
decl_stmt|;
comment|/* key length in bytes */
name|u_int8_t
name|ik_flags
decl_stmt|;
comment|/* NB: IEEE80211_KEY_XMIT and IEEE80211_KEY_RECV defined elsewhere */
define|#
directive|define
name|IEEE80211_KEY_DEFAULT
value|0x80
comment|/* default xmit key */
name|u_int8_t
name|ik_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int64_t
name|ik_keyrsc
decl_stmt|;
comment|/* key receive sequence counter */
name|u_int64_t
name|ik_keytsc
decl_stmt|;
comment|/* key transmit sequence counter */
name|u_int8_t
name|ik_keydata
index|[
name|IEEE80211_KEYBUF_SIZE
operator|+
name|IEEE80211_MICBUF_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Delete a key either by index or address.  Set the index  * to IEEE80211_KEYIX_NONE when deleting a unicast key.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_del_key
block|{
name|u_int8_t
name|idk_keyix
decl_stmt|;
comment|/* key index */
name|u_int8_t
name|idk_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MLME state manipulation request.  IEEE80211_MLME_ASSOC  * only makes sense when operating as a station.  The other  * requests can be used when operating as a station or an  * ap (to effect a station).  */
end_comment

begin_struct
struct|struct
name|ieee80211req_mlme
block|{
name|u_int8_t
name|im_op
decl_stmt|;
comment|/* operation to perform */
define|#
directive|define
name|IEEE80211_MLME_ASSOC
value|1
comment|/* associate station */
define|#
directive|define
name|IEEE80211_MLME_DISASSOC
value|2
comment|/* disassociate station */
define|#
directive|define
name|IEEE80211_MLME_DEAUTH
value|3
comment|/* deauthenticate station */
define|#
directive|define
name|IEEE80211_MLME_AUTHORIZE
value|4
comment|/* authorize station */
define|#
directive|define
name|IEEE80211_MLME_UNAUTHORIZE
value|5
comment|/* unauthorize station */
name|u_int8_t
name|im_ssid_len
decl_stmt|;
comment|/* length of optional ssid */
name|u_int16_t
name|im_reason
decl_stmt|;
comment|/* 802.11 reason code */
name|u_int8_t
name|im_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|im_ssid
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*   * MAC ACL operations.  */
end_comment

begin_enum
enum|enum
block|{
name|IEEE80211_MACCMD_POLICY_OPEN
init|=
literal|0
block|,
comment|/* set policy: no ACL's */
name|IEEE80211_MACCMD_POLICY_ALLOW
init|=
literal|1
block|,
comment|/* set policy: allow traffic */
name|IEEE80211_MACCMD_POLICY_DENY
init|=
literal|2
block|,
comment|/* set policy: deny traffic */
name|IEEE80211_MACCMD_FLUSH
init|=
literal|3
block|,
comment|/* flush ACL database */
name|IEEE80211_MACCMD_DETACH
init|=
literal|4
block|,
comment|/* detach ACL policy */
name|IEEE80211_MACCMD_POLICY
init|=
literal|5
block|,
comment|/* get ACL policy */
name|IEEE80211_MACCMD_LIST
init|=
literal|6
block|,
comment|/* get ACL database */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ieee80211req_maclist
block|{
name|u_int8_t
name|ml_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Set the active channel list.  Note this list is  * intersected with the available channel list in  * calculating the set of channels actually used in  * scanning.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_chanlist
block|{
name|u_int8_t
name|ic_channels
index|[
name|IEEE80211_CHAN_BYTES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Get the active channel list info.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_chaninfo
block|{
name|u_int
name|ic_nchans
decl_stmt|;
name|struct
name|ieee80211_channel
name|ic_chans
index|[
name|IEEE80211_CHAN_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Retrieve the WPA/RSN information element for an associated station.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_wpaie
block|{
name|u_int8_t
name|wpa_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|wpa_ie
index|[
name|IEEE80211_MAX_OPT_IE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Retrieve per-node statistics.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_sta_stats
block|{
union|union
block|{
comment|/* NB: explicitly force 64-bit alignment */
name|u_int8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int64_t
name|pad
decl_stmt|;
block|}
name|is_u
union|;
name|struct
name|ieee80211_nodestats
name|is_stats
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Station information block; the mac address is used  * to retrieve other data like stats, unicast key, etc.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_sta_info
block|{
name|u_int16_t
name|isi_len
decl_stmt|;
comment|/* length (mult of 4) */
name|u_int16_t
name|isi_freq
decl_stmt|;
comment|/* MHz */
name|u_int16_t
name|isi_flags
decl_stmt|;
comment|/* channel flags */
name|u_int16_t
name|isi_state
decl_stmt|;
comment|/* state flags */
name|u_int8_t
name|isi_authmode
decl_stmt|;
comment|/* authentication algorithm */
name|u_int8_t
name|isi_rssi
decl_stmt|;
name|u_int8_t
name|isi_capinfo
decl_stmt|;
comment|/* capabilities */
name|u_int8_t
name|isi_erp
decl_stmt|;
comment|/* ERP element */
name|u_int8_t
name|isi_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|isi_nrates
decl_stmt|;
comment|/* negotiated rates */
name|u_int8_t
name|isi_rates
index|[
name|IEEE80211_RATE_MAXSIZE
index|]
decl_stmt|;
name|u_int8_t
name|isi_txrate
decl_stmt|;
comment|/* index to isi_rates[] */
name|u_int16_t
name|isi_ie_len
decl_stmt|;
comment|/* IE length */
name|u_int16_t
name|isi_associd
decl_stmt|;
comment|/* assoc response */
name|u_int16_t
name|isi_txpower
decl_stmt|;
comment|/* current tx power */
name|u_int16_t
name|isi_vlan
decl_stmt|;
comment|/* vlan tag */
name|u_int16_t
name|isi_txseqs
index|[
literal|17
index|]
decl_stmt|;
comment|/* seq to be transmitted */
name|u_int16_t
name|isi_rxseqs
index|[
literal|17
index|]
decl_stmt|;
comment|/* seq previous for qos frames*/
name|u_int16_t
name|isi_inact
decl_stmt|;
comment|/* inactivity timer */
comment|/* XXX frag state? */
comment|/* variable length IE data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Retrieve per-station information; to retrieve all  * specify a mac address of ff:ff:ff:ff:ff:ff.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_sta_req
block|{
union|union
block|{
comment|/* NB: explicitly force 64-bit alignment */
name|u_int8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int64_t
name|pad
decl_stmt|;
block|}
name|is_u
union|;
name|struct
name|ieee80211req_sta_info
name|info
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable length */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Get/set per-station tx power cap.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_sta_txpow
block|{
name|u_int8_t
name|it_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|it_txpow
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * WME parameters are set and return using i_val and i_len.  * i_val holds the value itself.  i_len specifies the AC  * and, as appropriate, then high bit specifies whether the  * operation is to be applied to the BSS or ourself.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_WMEPARAM_SELF
value|0x0000
end_define

begin_comment
comment|/* parameter applies to self */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_WMEPARAM_BSS
value|0x8000
end_define

begin_comment
comment|/* parameter applies to BSS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_WMEPARAM_VAL
value|0x7fff
end_define

begin_comment
comment|/* parameter value */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/*  * FreeBSD-style ioctls.  */
end_comment

begin_comment
comment|/* the first member must be matched with struct ifreq */
end_comment

begin_struct
struct|struct
name|ieee80211req
block|{
name|char
name|i_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if_name, e.g. "wi0" */
name|u_int16_t
name|i_type
decl_stmt|;
comment|/* req type */
name|int16_t
name|i_val
decl_stmt|;
comment|/* Index or simple value */
name|int16_t
name|i_len
decl_stmt|;
comment|/* Index or simple value */
name|void
modifier|*
name|i_data
decl_stmt|;
comment|/* Extra data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCS80211
value|_IOW('i', 234, struct ieee80211req)
end_define

begin_define
define|#
directive|define
name|SIOCG80211
value|_IOWR('i', 235, struct ieee80211req)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_SSID
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_NUMSSIDS
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_WEP
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_WEP_NOSUP
value|-1
end_define

begin_define
define|#
directive|define
name|IEEE80211_WEP_OFF
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_WEP_ON
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_WEP_MIXED
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_WEPKEY
value|4
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_NUMWEPKEYS
value|5
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_WEPTXKEY
value|6
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_AUTHMODE
value|7
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_STATIONNAME
value|8
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_CHANNEL
value|9
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_POWERSAVE
value|10
end_define

begin_define
define|#
directive|define
name|IEEE80211_POWERSAVE_NOSUP
value|-1
end_define

begin_define
define|#
directive|define
name|IEEE80211_POWERSAVE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_POWERSAVE_CAM
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_POWERSAVE_PSP
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_POWERSAVE_PSP_CAM
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_POWERSAVE_ON
value|IEEE80211_POWERSAVE_CAM
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_POWERSAVESLEEP
value|11
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_RTSTHRESHOLD
value|12
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_PROTMODE
value|13
end_define

begin_define
define|#
directive|define
name|IEEE80211_PROTMODE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_PROTMODE_CTS
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_PROTMODE_RTSCTS
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_TXPOWER
value|14
end_define

begin_comment
comment|/* global tx power limit */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_BSSID
value|15
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_ROAMING
value|16
end_define

begin_comment
comment|/* roaming mode */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_PRIVACY
value|17
end_define

begin_comment
comment|/* privacy invoked */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_DROPUNENCRYPTED
value|18
end_define

begin_comment
comment|/* discard unencrypted frames */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_WPAKEY
value|19
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_DELKEY
value|20
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_MLME
value|21
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_OPTIE
value|22
end_define

begin_comment
comment|/* optional info. element */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_SCAN_REQ
value|23
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_SCAN_RESULTS
value|24
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_COUNTERMEASURES
value|25
end_define

begin_comment
comment|/* WPA/TKIP countermeasures */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_WPA
value|26
end_define

begin_comment
comment|/* WPA mode (0,1,2) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_CHANLIST
value|27
end_define

begin_comment
comment|/* channel list */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_WME
value|28
end_define

begin_comment
comment|/* WME mode (on, off) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_HIDESSID
value|29
end_define

begin_comment
comment|/* hide SSID mode (on, off) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_APBRIDGE
value|30
end_define

begin_comment
comment|/* AP inter-sta bridging */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MCASTCIPHER
value|31
end_define

begin_comment
comment|/* multicast/default cipher */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MCASTKEYLEN
value|32
end_define

begin_comment
comment|/* multicast key length */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_UCASTCIPHERS
value|33
end_define

begin_comment
comment|/* unicast cipher suites */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_UCASTCIPHER
value|34
end_define

begin_comment
comment|/* unicast cipher */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_UCASTKEYLEN
value|35
end_define

begin_comment
comment|/* unicast key length */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_DRIVER_CAPS
value|36
end_define

begin_comment
comment|/* driver capabilities */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_KEYMGTALGS
value|37
end_define

begin_comment
comment|/* key management algorithms */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_RSNCAPS
value|38
end_define

begin_comment
comment|/* RSN capabilities */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_WPAIE
value|39
end_define

begin_comment
comment|/* WPA information element */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_STA_STATS
value|40
end_define

begin_comment
comment|/* per-station statistics */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MACCMD
value|41
end_define

begin_comment
comment|/* MAC ACL operation */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_CHANINFO
value|42
end_define

begin_comment
comment|/* channel info list */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_TXPOWMAX
value|43
end_define

begin_comment
comment|/* max tx power for channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_STA_TXPOW
value|44
end_define

begin_comment
comment|/* per-station tx power limit */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_STA_INFO
value|45
end_define

begin_comment
comment|/* station/neighbor info */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_WME_CWMIN
value|46
end_define

begin_comment
comment|/* WME: ECWmin */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_WME_CWMAX
value|47
end_define

begin_comment
comment|/* WME: ECWmax */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_WME_AIFS
value|48
end_define

begin_comment
comment|/* WME: AIFSN */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_WME_TXOPLIMIT
value|49
end_define

begin_comment
comment|/* WME: txops limit */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_WME_ACM
value|50
end_define

begin_comment
comment|/* WME: ACM (bss only) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_WME_ACKPOLICY
value|51
end_define

begin_comment
comment|/* WME: ACK policy (!bss only)*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_DTIM_PERIOD
value|52
end_define

begin_comment
comment|/* DTIM period (beacons) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_BEACON_INTERVAL
value|53
end_define

begin_comment
comment|/* beacon interval (ms) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_ADDMAC
value|54
end_define

begin_comment
comment|/* add sta to MAC ACL table */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_DELMAC
value|55
end_define

begin_comment
comment|/* del sta from MAC ACL table */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_PUREG
value|56
end_define

begin_comment
comment|/* pure 11g (no 11b stations) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MCAST_RATE
value|72
end_define

begin_comment
comment|/* tx rate for mcast frames */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_FRAGTHRESHOLD
value|73
end_define

begin_comment
comment|/* tx fragmentation threshold */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_BURST
value|75
end_define

begin_comment
comment|/* packet bursting */
end_comment

begin_comment
comment|/*  * Scan result data returned for IEEE80211_IOC_SCAN_RESULTS.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_scan_result
block|{
name|u_int16_t
name|isr_len
decl_stmt|;
comment|/* length (mult of 4) */
name|u_int16_t
name|isr_freq
decl_stmt|;
comment|/* MHz */
name|u_int16_t
name|isr_flags
decl_stmt|;
comment|/* channel flags */
name|u_int8_t
name|isr_noise
decl_stmt|;
name|u_int8_t
name|isr_rssi
decl_stmt|;
name|u_int8_t
name|isr_intval
decl_stmt|;
comment|/* beacon interval */
name|u_int8_t
name|isr_capinfo
decl_stmt|;
comment|/* capabilities */
name|u_int8_t
name|isr_erp
decl_stmt|;
comment|/* ERP element */
name|u_int8_t
name|isr_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|isr_nrates
decl_stmt|;
name|u_int8_t
name|isr_rates
index|[
name|IEEE80211_RATE_MAXSIZE
index|]
decl_stmt|;
name|u_int8_t
name|isr_ssid_len
decl_stmt|;
comment|/* SSID length */
name|u_int8_t
name|isr_ie_len
decl_stmt|;
comment|/* IE length */
name|u_int8_t
name|isr_pad
index|[
literal|5
index|]
decl_stmt|;
comment|/* variable length SSID followed by IE data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCG80211STATS
value|_IOWR('i', 236, struct ifreq)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_IOCTL_H_ */
end_comment

end_unit

