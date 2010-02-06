begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
comment|/*  * Per/node (station) statistics.  */
end_comment

begin_struct
struct|struct
name|ieee80211_nodestats
block|{
name|uint32_t
name|ns_rx_data
decl_stmt|;
comment|/* rx data frames */
name|uint32_t
name|ns_rx_mgmt
decl_stmt|;
comment|/* rx management frames */
name|uint32_t
name|ns_rx_ctrl
decl_stmt|;
comment|/* rx control frames */
name|uint32_t
name|ns_rx_ucast
decl_stmt|;
comment|/* rx unicast frames */
name|uint32_t
name|ns_rx_mcast
decl_stmt|;
comment|/* rx multi/broadcast frames */
name|uint64_t
name|ns_rx_bytes
decl_stmt|;
comment|/* rx data count (bytes) */
name|uint64_t
name|ns_rx_beacons
decl_stmt|;
comment|/* rx beacon frames */
name|uint32_t
name|ns_rx_proberesp
decl_stmt|;
comment|/* rx probe response frames */
name|uint32_t
name|ns_rx_dup
decl_stmt|;
comment|/* rx discard 'cuz dup */
name|uint32_t
name|ns_rx_noprivacy
decl_stmt|;
comment|/* rx w/ wep but privacy off */
name|uint32_t
name|ns_rx_wepfail
decl_stmt|;
comment|/* rx wep processing failed */
name|uint32_t
name|ns_rx_demicfail
decl_stmt|;
comment|/* rx demic failed */
name|uint32_t
name|ns_rx_decap
decl_stmt|;
comment|/* rx decapsulation failed */
name|uint32_t
name|ns_rx_defrag
decl_stmt|;
comment|/* rx defragmentation failed */
name|uint32_t
name|ns_rx_disassoc
decl_stmt|;
comment|/* rx disassociation */
name|uint32_t
name|ns_rx_deauth
decl_stmt|;
comment|/* rx deauthentication */
name|uint32_t
name|ns_rx_action
decl_stmt|;
comment|/* rx action */
name|uint32_t
name|ns_rx_decryptcrc
decl_stmt|;
comment|/* rx decrypt failed on crc */
name|uint32_t
name|ns_rx_unauth
decl_stmt|;
comment|/* rx on unauthorized port */
name|uint32_t
name|ns_rx_unencrypted
decl_stmt|;
comment|/* rx unecrypted w/ privacy */
name|uint32_t
name|ns_rx_drop
decl_stmt|;
comment|/* rx discard other reason */
name|uint32_t
name|ns_tx_data
decl_stmt|;
comment|/* tx data frames */
name|uint32_t
name|ns_tx_mgmt
decl_stmt|;
comment|/* tx management frames */
name|uint32_t
name|ns_tx_ctrl
decl_stmt|;
comment|/* tx control frames */
name|uint32_t
name|ns_tx_ucast
decl_stmt|;
comment|/* tx unicast frames */
name|uint32_t
name|ns_tx_mcast
decl_stmt|;
comment|/* tx multi/broadcast frames */
name|uint64_t
name|ns_tx_bytes
decl_stmt|;
comment|/* tx data count (bytes) */
name|uint32_t
name|ns_tx_probereq
decl_stmt|;
comment|/* tx probe request frames */
name|uint32_t
name|ns_tx_novlantag
decl_stmt|;
comment|/* tx discard 'cuz no tag */
name|uint32_t
name|ns_tx_vlanmismatch
decl_stmt|;
comment|/* tx discard 'cuz bad tag */
name|uint32_t
name|ns_ps_discard
decl_stmt|;
comment|/* ps discard 'cuz of age */
comment|/* MIB-related state */
name|uint32_t
name|ns_tx_assoc
decl_stmt|;
comment|/* [re]associations */
name|uint32_t
name|ns_tx_assoc_fail
decl_stmt|;
comment|/* [re]association failures */
name|uint32_t
name|ns_tx_auth
decl_stmt|;
comment|/* [re]authentications */
name|uint32_t
name|ns_tx_auth_fail
decl_stmt|;
comment|/* [re]authentication failures*/
name|uint32_t
name|ns_tx_deauth
decl_stmt|;
comment|/* deauthentications */
name|uint32_t
name|ns_tx_deauth_code
decl_stmt|;
comment|/* last deauth reason */
name|uint32_t
name|ns_tx_disassoc
decl_stmt|;
comment|/* disassociations */
name|uint32_t
name|ns_tx_disassoc_code
decl_stmt|;
comment|/* last disassociation reason */
name|uint32_t
name|ns_spare
index|[
literal|8
index|]
decl_stmt|;
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
name|uint32_t
name|is_rx_badversion
decl_stmt|;
comment|/* rx frame with bad version */
name|uint32_t
name|is_rx_tooshort
decl_stmt|;
comment|/* rx frame too short */
name|uint32_t
name|is_rx_wrongbss
decl_stmt|;
comment|/* rx from wrong bssid */
name|uint32_t
name|is_rx_dup
decl_stmt|;
comment|/* rx discard 'cuz dup */
name|uint32_t
name|is_rx_wrongdir
decl_stmt|;
comment|/* rx w/ wrong direction */
name|uint32_t
name|is_rx_mcastecho
decl_stmt|;
comment|/* rx discard 'cuz mcast echo */
name|uint32_t
name|is_rx_notassoc
decl_stmt|;
comment|/* rx discard 'cuz sta !assoc */
name|uint32_t
name|is_rx_noprivacy
decl_stmt|;
comment|/* rx w/ wep but privacy off */
name|uint32_t
name|is_rx_unencrypted
decl_stmt|;
comment|/* rx w/o wep and privacy on */
name|uint32_t
name|is_rx_wepfail
decl_stmt|;
comment|/* rx wep processing failed */
name|uint32_t
name|is_rx_decap
decl_stmt|;
comment|/* rx decapsulation failed */
name|uint32_t
name|is_rx_mgtdiscard
decl_stmt|;
comment|/* rx discard mgt frames */
name|uint32_t
name|is_rx_ctl
decl_stmt|;
comment|/* rx ctrl frames */
name|uint32_t
name|is_rx_beacon
decl_stmt|;
comment|/* rx beacon frames */
name|uint32_t
name|is_rx_rstoobig
decl_stmt|;
comment|/* rx rate set truncated */
name|uint32_t
name|is_rx_elem_missing
decl_stmt|;
comment|/* rx required element missing*/
name|uint32_t
name|is_rx_elem_toobig
decl_stmt|;
comment|/* rx element too big */
name|uint32_t
name|is_rx_elem_toosmall
decl_stmt|;
comment|/* rx element too small */
name|uint32_t
name|is_rx_elem_unknown
decl_stmt|;
comment|/* rx element unknown */
name|uint32_t
name|is_rx_badchan
decl_stmt|;
comment|/* rx frame w/ invalid chan */
name|uint32_t
name|is_rx_chanmismatch
decl_stmt|;
comment|/* rx frame chan mismatch */
name|uint32_t
name|is_rx_nodealloc
decl_stmt|;
comment|/* rx frame dropped */
name|uint32_t
name|is_rx_ssidmismatch
decl_stmt|;
comment|/* rx frame ssid mismatch  */
name|uint32_t
name|is_rx_auth_unsupported
decl_stmt|;
comment|/* rx w/ unsupported auth alg */
name|uint32_t
name|is_rx_auth_fail
decl_stmt|;
comment|/* rx sta auth failure */
name|uint32_t
name|is_rx_auth_countermeasures
decl_stmt|;
comment|/* rx auth discard 'cuz CM */
name|uint32_t
name|is_rx_assoc_bss
decl_stmt|;
comment|/* rx assoc from wrong bssid */
name|uint32_t
name|is_rx_assoc_notauth
decl_stmt|;
comment|/* rx assoc w/o auth */
name|uint32_t
name|is_rx_assoc_capmismatch
decl_stmt|;
comment|/* rx assoc w/ cap mismatch */
name|uint32_t
name|is_rx_assoc_norate
decl_stmt|;
comment|/* rx assoc w/ no rate match */
name|uint32_t
name|is_rx_assoc_badwpaie
decl_stmt|;
comment|/* rx assoc w/ bad WPA IE */
name|uint32_t
name|is_rx_deauth
decl_stmt|;
comment|/* rx deauthentication */
name|uint32_t
name|is_rx_disassoc
decl_stmt|;
comment|/* rx disassociation */
name|uint32_t
name|is_rx_badsubtype
decl_stmt|;
comment|/* rx frame w/ unknown subtype*/
name|uint32_t
name|is_rx_nobuf
decl_stmt|;
comment|/* rx failed for lack of buf */
name|uint32_t
name|is_rx_decryptcrc
decl_stmt|;
comment|/* rx decrypt failed on crc */
name|uint32_t
name|is_rx_ahdemo_mgt
decl_stmt|;
comment|/* rx discard ahdemo mgt frame*/
name|uint32_t
name|is_rx_bad_auth
decl_stmt|;
comment|/* rx bad auth request */
name|uint32_t
name|is_rx_unauth
decl_stmt|;
comment|/* rx on unauthorized port */
name|uint32_t
name|is_rx_badkeyid
decl_stmt|;
comment|/* rx w/ incorrect keyid */
name|uint32_t
name|is_rx_ccmpreplay
decl_stmt|;
comment|/* rx seq# violation (CCMP) */
name|uint32_t
name|is_rx_ccmpformat
decl_stmt|;
comment|/* rx format bad (CCMP) */
name|uint32_t
name|is_rx_ccmpmic
decl_stmt|;
comment|/* rx MIC check failed (CCMP) */
name|uint32_t
name|is_rx_tkipreplay
decl_stmt|;
comment|/* rx seq# violation (TKIP) */
name|uint32_t
name|is_rx_tkipformat
decl_stmt|;
comment|/* rx format bad (TKIP) */
name|uint32_t
name|is_rx_tkipmic
decl_stmt|;
comment|/* rx MIC check failed (TKIP) */
name|uint32_t
name|is_rx_tkipicv
decl_stmt|;
comment|/* rx ICV check failed (TKIP) */
name|uint32_t
name|is_rx_badcipher
decl_stmt|;
comment|/* rx failed 'cuz key type */
name|uint32_t
name|is_rx_nocipherctx
decl_stmt|;
comment|/* rx failed 'cuz key !setup */
name|uint32_t
name|is_rx_acl
decl_stmt|;
comment|/* rx discard 'cuz acl policy */
name|uint32_t
name|is_tx_nobuf
decl_stmt|;
comment|/* tx failed for lack of buf */
name|uint32_t
name|is_tx_nonode
decl_stmt|;
comment|/* tx failed for no node */
name|uint32_t
name|is_tx_unknownmgt
decl_stmt|;
comment|/* tx of unknown mgt frame */
name|uint32_t
name|is_tx_badcipher
decl_stmt|;
comment|/* tx failed 'cuz key type */
name|uint32_t
name|is_tx_nodefkey
decl_stmt|;
comment|/* tx failed 'cuz no defkey */
name|uint32_t
name|is_tx_noheadroom
decl_stmt|;
comment|/* tx failed 'cuz no space */
name|uint32_t
name|is_tx_fragframes
decl_stmt|;
comment|/* tx frames fragmented */
name|uint32_t
name|is_tx_frags
decl_stmt|;
comment|/* tx fragments created */
name|uint32_t
name|is_scan_active
decl_stmt|;
comment|/* active scans started */
name|uint32_t
name|is_scan_passive
decl_stmt|;
comment|/* passive scans started */
name|uint32_t
name|is_node_timeout
decl_stmt|;
comment|/* nodes timed out inactivity */
name|uint32_t
name|is_crypto_nomem
decl_stmt|;
comment|/* no memory for crypto ctx */
name|uint32_t
name|is_crypto_tkip
decl_stmt|;
comment|/* tkip crypto done in s/w */
name|uint32_t
name|is_crypto_tkipenmic
decl_stmt|;
comment|/* tkip en-MIC done in s/w */
name|uint32_t
name|is_crypto_tkipdemic
decl_stmt|;
comment|/* tkip de-MIC done in s/w */
name|uint32_t
name|is_crypto_tkipcm
decl_stmt|;
comment|/* tkip counter measures */
name|uint32_t
name|is_crypto_ccmp
decl_stmt|;
comment|/* ccmp crypto done in s/w */
name|uint32_t
name|is_crypto_wep
decl_stmt|;
comment|/* wep crypto done in s/w */
name|uint32_t
name|is_crypto_setkey_cipher
decl_stmt|;
comment|/* cipher rejected key */
name|uint32_t
name|is_crypto_setkey_nokey
decl_stmt|;
comment|/* no key index for setkey */
name|uint32_t
name|is_crypto_delkey
decl_stmt|;
comment|/* driver key delete failed */
name|uint32_t
name|is_crypto_badcipher
decl_stmt|;
comment|/* unknown cipher */
name|uint32_t
name|is_crypto_nocipher
decl_stmt|;
comment|/* cipher not available */
name|uint32_t
name|is_crypto_attachfail
decl_stmt|;
comment|/* cipher attach failed */
name|uint32_t
name|is_crypto_swfallback
decl_stmt|;
comment|/* cipher fallback to s/w */
name|uint32_t
name|is_crypto_keyfail
decl_stmt|;
comment|/* driver key alloc failed */
name|uint32_t
name|is_crypto_enmicfail
decl_stmt|;
comment|/* en-MIC failed */
name|uint32_t
name|is_ibss_capmismatch
decl_stmt|;
comment|/* merge failed-cap mismatch */
name|uint32_t
name|is_ibss_norate
decl_stmt|;
comment|/* merge failed-rate mismatch */
name|uint32_t
name|is_ps_unassoc
decl_stmt|;
comment|/* ps-poll for unassoc. sta */
name|uint32_t
name|is_ps_badaid
decl_stmt|;
comment|/* ps-poll w/ incorrect aid */
name|uint32_t
name|is_ps_qempty
decl_stmt|;
comment|/* ps-poll w/ nothing to send */
name|uint32_t
name|is_ff_badhdr
decl_stmt|;
comment|/* fast frame rx'd w/ bad hdr */
name|uint32_t
name|is_ff_tooshort
decl_stmt|;
comment|/* fast frame rx decap error */
name|uint32_t
name|is_ff_split
decl_stmt|;
comment|/* fast frame rx split error */
name|uint32_t
name|is_ff_decap
decl_stmt|;
comment|/* fast frames decap'd */
name|uint32_t
name|is_ff_encap
decl_stmt|;
comment|/* fast frames encap'd for tx */
name|uint32_t
name|is_rx_badbintval
decl_stmt|;
comment|/* rx frame w/ bogus bintval */
name|uint32_t
name|is_rx_demicfail
decl_stmt|;
comment|/* rx demic failed */
name|uint32_t
name|is_rx_defrag
decl_stmt|;
comment|/* rx defragmentation failed */
name|uint32_t
name|is_rx_mgmt
decl_stmt|;
comment|/* rx management frames */
name|uint32_t
name|is_rx_action
decl_stmt|;
comment|/* rx action mgt frames */
name|uint32_t
name|is_amsdu_tooshort
decl_stmt|;
comment|/* A-MSDU rx decap error */
name|uint32_t
name|is_amsdu_split
decl_stmt|;
comment|/* A-MSDU rx split error */
name|uint32_t
name|is_amsdu_decap
decl_stmt|;
comment|/* A-MSDU decap'd */
name|uint32_t
name|is_amsdu_encap
decl_stmt|;
comment|/* A-MSDU encap'd for tx */
name|uint32_t
name|is_ampdu_bar_bad
decl_stmt|;
comment|/* A-MPDU BAR out of window */
name|uint32_t
name|is_ampdu_bar_oow
decl_stmt|;
comment|/* A-MPDU BAR before ADDBA */
name|uint32_t
name|is_ampdu_bar_move
decl_stmt|;
comment|/* A-MPDU BAR moved window */
name|uint32_t
name|is_ampdu_bar_rx
decl_stmt|;
comment|/* A-MPDU BAR frames handled */
name|uint32_t
name|is_ampdu_rx_flush
decl_stmt|;
comment|/* A-MPDU frames flushed */
name|uint32_t
name|is_ampdu_rx_oor
decl_stmt|;
comment|/* A-MPDU frames out-of-order */
name|uint32_t
name|is_ampdu_rx_copy
decl_stmt|;
comment|/* A-MPDU frames copied down */
name|uint32_t
name|is_ampdu_rx_drop
decl_stmt|;
comment|/* A-MPDU frames dropped */
name|uint32_t
name|is_tx_badstate
decl_stmt|;
comment|/* tx discard state != RUN */
name|uint32_t
name|is_tx_notassoc
decl_stmt|;
comment|/* tx failed, sta not assoc */
name|uint32_t
name|is_tx_classify
decl_stmt|;
comment|/* tx classification failed */
name|uint32_t
name|is_dwds_mcast
decl_stmt|;
comment|/* discard mcast over dwds */
name|uint32_t
name|is_dwds_qdrop
decl_stmt|;
comment|/* dwds pending frame q full */
name|uint32_t
name|is_ht_assoc_nohtcap
decl_stmt|;
comment|/* non-HT sta rejected */
name|uint32_t
name|is_ht_assoc_downgrade
decl_stmt|;
comment|/* HT sta forced to legacy */
name|uint32_t
name|is_ht_assoc_norate
decl_stmt|;
comment|/* HT assoc w/ rate mismatch */
name|uint32_t
name|is_ampdu_rx_age
decl_stmt|;
comment|/* A-MPDU sent up 'cuz of age */
name|uint32_t
name|is_ampdu_rx_move
decl_stmt|;
comment|/* A-MPDU MSDU moved window */
name|uint32_t
name|is_addba_reject
decl_stmt|;
comment|/* ADDBA reject 'cuz disabled */
name|uint32_t
name|is_addba_norequest
decl_stmt|;
comment|/* ADDBA response w/o ADDBA */
name|uint32_t
name|is_addba_badtoken
decl_stmt|;
comment|/* ADDBA response w/ wrong 						   dialogtoken */
name|uint32_t
name|is_addba_badpolicy
decl_stmt|;
comment|/* ADDBA resp w/ wrong policy */
name|uint32_t
name|is_ampdu_stop
decl_stmt|;
comment|/* A-MPDU stream stopped */
name|uint32_t
name|is_ampdu_stop_failed
decl_stmt|;
comment|/* A-MPDU stream not running */
name|uint32_t
name|is_ampdu_rx_reorder
decl_stmt|;
comment|/* A-MPDU held for rx reorder */
name|uint32_t
name|is_scan_bg
decl_stmt|;
comment|/* background scans started */
name|uint8_t
name|is_rx_deauth_code
decl_stmt|;
comment|/* last rx'd deauth reason */
name|uint8_t
name|is_rx_disassoc_code
decl_stmt|;
comment|/* last rx'd disassoc reason */
name|uint8_t
name|is_rx_authfail_code
decl_stmt|;
comment|/* last rx'd auth fail reason */
name|uint32_t
name|is_beacon_miss
decl_stmt|;
comment|/* beacon miss notification */
name|uint32_t
name|is_rx_badstate
decl_stmt|;
comment|/* rx discard state != RUN */
name|uint32_t
name|is_ff_flush
decl_stmt|;
comment|/* ff's flush'd from stageq */
name|uint32_t
name|is_tx_ctl
decl_stmt|;
comment|/* tx ctrl frames */
name|uint32_t
name|is_ampdu_rexmt
decl_stmt|;
comment|/* A-MPDU frames rexmt ok */
name|uint32_t
name|is_ampdu_rexmt_fail
decl_stmt|;
comment|/* A-MPDU frames rexmt fail */
name|uint32_t
name|is_mesh_wrongmesh
decl_stmt|;
comment|/* dropped 'cuz not mesh sta*/
name|uint32_t
name|is_mesh_nolink
decl_stmt|;
comment|/* dropped 'cuz link not estab*/
name|uint32_t
name|is_mesh_fwd_ttl
decl_stmt|;
comment|/* mesh not fwd'd 'cuz ttl 0 */
name|uint32_t
name|is_mesh_fwd_nobuf
decl_stmt|;
comment|/* mesh not fwd'd 'cuz no mbuf*/
name|uint32_t
name|is_mesh_fwd_tooshort
decl_stmt|;
comment|/* mesh not fwd'd 'cuz no hdr */
name|uint32_t
name|is_mesh_fwd_disabled
decl_stmt|;
comment|/* mesh not fwd'd 'cuz disabled */
name|uint32_t
name|is_mesh_fwd_nopath
decl_stmt|;
comment|/* mesh not fwd'd 'cuz path unknown */
name|uint32_t
name|is_hwmp_wrongseq
decl_stmt|;
comment|/* wrong hwmp seq no. */
name|uint32_t
name|is_hwmp_rootreqs
decl_stmt|;
comment|/* root PREQs sent */
name|uint32_t
name|is_hwmp_rootrann
decl_stmt|;
comment|/* root RANNs sent */
name|uint32_t
name|is_mesh_badae
decl_stmt|;
comment|/* dropped 'cuz invalid AE */
name|uint32_t
name|is_mesh_rtaddfailed
decl_stmt|;
comment|/* route add failed */
name|uint32_t
name|is_mesh_notproxy
decl_stmt|;
comment|/* dropped 'cuz not proxying */
name|uint32_t
name|is_rx_badalign
decl_stmt|;
comment|/* dropped 'cuz misaligned */
name|uint32_t
name|is_hwmp_proxy
decl_stmt|;
comment|/* PREP for proxy route */
name|uint32_t
name|is_spare
index|[
literal|11
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
comment|/*  * WPA/RSN get/set key request.  Specify the key/cipher  * type and whether the key is to be used for sending and/or  * receiving.  The key index should be set only when working  * with global keys (use IEEE80211_KEYIX_NONE for ``no index'').  * Otherwise a unicast/pairwise key is specified by the bssid  * (on a station) or mac address (on an ap).  They key length  * must include any MIC key data; otherwise it should be no  * more than IEEE80211_KEYBUF_SIZE.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_key
block|{
name|uint8_t
name|ik_type
decl_stmt|;
comment|/* key/cipher type */
name|uint8_t
name|ik_pad
decl_stmt|;
name|uint16_t
name|ik_keyix
decl_stmt|;
comment|/* key index */
name|uint8_t
name|ik_keylen
decl_stmt|;
comment|/* key length in bytes */
name|uint8_t
name|ik_flags
decl_stmt|;
comment|/* NB: IEEE80211_KEY_XMIT and IEEE80211_KEY_RECV defined elsewhere */
define|#
directive|define
name|IEEE80211_KEY_DEFAULT
value|0x80
comment|/* default xmit key */
name|uint8_t
name|ik_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint64_t
name|ik_keyrsc
decl_stmt|;
comment|/* key receive sequence counter */
name|uint64_t
name|ik_keytsc
decl_stmt|;
comment|/* key transmit sequence counter */
name|uint8_t
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
name|uint8_t
name|idk_keyix
decl_stmt|;
comment|/* key index */
name|uint8_t
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
name|uint8_t
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
define|#
directive|define
name|IEEE80211_MLME_AUTH
value|6
comment|/* authenticate station */
name|uint8_t
name|im_ssid_len
decl_stmt|;
comment|/* length of optional ssid */
name|uint16_t
name|im_reason
decl_stmt|;
comment|/* 802.11 reason code */
name|uint8_t
name|im_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
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
name|IEEE80211_MACCMD_POLICY_RADIUS
init|=
literal|7
block|,
comment|/* set policy: RADIUS managed */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ieee80211req_maclist
block|{
name|uint8_t
name|ml_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Mesh Routing Table Operations.  */
end_comment

begin_enum
enum|enum
block|{
name|IEEE80211_MESH_RTCMD_LIST
init|=
literal|0
block|,
comment|/* list HWMP routing table */
name|IEEE80211_MESH_RTCMD_FLUSH
init|=
literal|1
block|,
comment|/* flush HWMP routing table */
name|IEEE80211_MESH_RTCMD_ADD
init|=
literal|2
block|,
comment|/* add entry to the table */
name|IEEE80211_MESH_RTCMD_DELETE
init|=
literal|3
block|,
comment|/* delete an entry from the table */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ieee80211req_mesh_route
block|{
name|uint8_t
name|imr_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_MESHRT_FLAGS_VALID
value|0x01
define|#
directive|define
name|IEEE80211_MESHRT_FLAGS_PROXY
value|0x02
name|uint8_t
name|imr_dest
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|imr_nexthop
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|imr_nhops
decl_stmt|;
name|uint8_t
name|imr_pad
decl_stmt|;
name|uint32_t
name|imr_metric
decl_stmt|;
name|uint32_t
name|imr_lifetime
decl_stmt|;
name|uint32_t
name|imr_lastmseq
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * HWMP root modes  */
end_comment

begin_enum
enum|enum
block|{
name|IEEE80211_HWMP_ROOTMODE_DISABLED
init|=
literal|0
block|,
comment|/* disabled */
name|IEEE80211_HWMP_ROOTMODE_NORMAL
init|=
literal|1
block|,
comment|/* normal PREPs */
name|IEEE80211_HWMP_ROOTMODE_PROACTIVE
init|=
literal|2
block|,
comment|/* proactive PREPS */
name|IEEE80211_HWMP_ROOTMODE_RANN
init|=
literal|3
block|,
comment|/* use RANN elemid */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Set the active channel list by IEEE channel #: each channel  * to be marked active is set in a bit vector.  Note this list is  * intersected with the available channel list in calculating  * the set of channels actually used in scanning.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_chanlist
block|{
name|uint8_t
name|ic_channels
index|[
literal|32
index|]
decl_stmt|;
comment|/* NB: can be variable length */
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
literal|1
index|]
decl_stmt|;
comment|/* NB: variable length */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_CHANINFO_SIZE
parameter_list|(
name|_nchan
parameter_list|)
define|\
value|(sizeof(struct ieee80211req_chaninfo) + \ 	 (((_nchan)-1) * sizeof(struct ieee80211_channel)))
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHANINFO_SPACE
parameter_list|(
name|_ci
parameter_list|)
define|\
value|IEEE80211_CHANINFO_SIZE((_ci)->ic_nchans)
end_define

begin_comment
comment|/*  * Retrieve the WPA/RSN information element for an associated station.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_wpaie
block|{
comment|/* old version w/ only one ie */
name|uint8_t
name|wpa_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|wpa_ie
index|[
name|IEEE80211_MAX_OPT_IE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211req_wpaie2
block|{
name|uint8_t
name|wpa_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|wpa_ie
index|[
name|IEEE80211_MAX_OPT_IE
index|]
decl_stmt|;
name|uint8_t
name|rsn_ie
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
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint64_t
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
name|uint16_t
name|isi_len
decl_stmt|;
comment|/* total length (mult of 4) */
name|uint16_t
name|isi_ie_off
decl_stmt|;
comment|/* offset to IE data */
name|uint16_t
name|isi_ie_len
decl_stmt|;
comment|/* IE length */
name|uint16_t
name|isi_freq
decl_stmt|;
comment|/* MHz */
name|uint32_t
name|isi_flags
decl_stmt|;
comment|/* channel flags */
name|uint32_t
name|isi_state
decl_stmt|;
comment|/* state flags */
name|uint8_t
name|isi_authmode
decl_stmt|;
comment|/* authentication algorithm */
name|int8_t
name|isi_rssi
decl_stmt|;
comment|/* receive signal strength */
name|int8_t
name|isi_noise
decl_stmt|;
comment|/* noise floor */
name|uint8_t
name|isi_capinfo
decl_stmt|;
comment|/* capabilities */
name|uint8_t
name|isi_erp
decl_stmt|;
comment|/* ERP element */
name|uint8_t
name|isi_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|isi_nrates
decl_stmt|;
comment|/* negotiated rates */
name|uint8_t
name|isi_rates
index|[
name|IEEE80211_RATE_MAXSIZE
index|]
decl_stmt|;
name|uint8_t
name|isi_txrate
decl_stmt|;
comment|/* legacy/IEEE rate or MCS */
name|uint16_t
name|isi_associd
decl_stmt|;
comment|/* assoc response */
name|uint16_t
name|isi_txpower
decl_stmt|;
comment|/* current tx power */
name|uint16_t
name|isi_vlan
decl_stmt|;
comment|/* vlan tag */
comment|/* NB: [IEEE80211_NONQOS_TID] holds seq#'s for non-QoS stations */
name|uint16_t
name|isi_txseqs
index|[
name|IEEE80211_TID_SIZE
index|]
decl_stmt|;
comment|/* tx seq #/TID */
name|uint16_t
name|isi_rxseqs
index|[
name|IEEE80211_TID_SIZE
index|]
decl_stmt|;
comment|/* rx seq#/TID */
name|uint16_t
name|isi_inact
decl_stmt|;
comment|/* inactivity timer */
name|uint16_t
name|isi_txmbps
decl_stmt|;
comment|/* current tx rate in .5 Mb/s */
name|uint16_t
name|isi_pad
decl_stmt|;
name|uint32_t
name|isi_jointime
decl_stmt|;
comment|/* time of assoc/join */
name|struct
name|ieee80211_mimo_info
name|isi_mimo
decl_stmt|;
comment|/* MIMO info for 11n sta's */
comment|/* 11s info */
name|uint16_t
name|isi_peerid
decl_stmt|;
name|uint16_t
name|isi_localid
decl_stmt|;
name|uint8_t
name|isi_peerstate
decl_stmt|;
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
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint64_t
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
name|uint8_t
name|it_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|it_txpow
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * WME parameters manipulated with IEEE80211_IOC_WME_CWMIN  * through IEEE80211_IOC_WME_ACKPOLICY are set and return  * using i_val and i_len.  i_val holds the value itself.  * i_len specifies the AC and, as appropriate, then high bit  * specifies whether the operation is to be applied to the  * BSS or ourself.  */
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

begin_comment
comment|/*  * Application Information Elements can be appended to a variety  * of frames with the IEE80211_IOC_APPIE request.  This request  * piggybacks on a normal ieee80211req; the frame type is passed  * in i_val as the 802.11 FC0 bytes and the length of the IE data  * is passed in i_len.  The data is referenced in i_data.  If i_len  * is zero then any previously configured IE data is removed.  At  * most IEEE80211_MAX_APPIE data be appened.  Note that multiple  * IE's can be supplied; the data is treated opaquely.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MAX_APPIE
value|1024
end_define

begin_comment
comment|/* max app IE data */
end_comment

begin_comment
comment|/*  * Hack: the WPA authenticator uses this mechanism to specify WPA  * ie's that are used instead of the ones normally constructed using  * the cipher state setup with separate ioctls.  This avoids issues  * like the authenticator ordering ie data differently than the  * net80211 layer and needing to keep separate state for WPA and RSN.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_APPIE_WPA
define|\
value|(IEEE80211_FC0_TYPE_MGT | IEEE80211_FC0_SUBTYPE_BEACON | \ 	 IEEE80211_FC0_SUBTYPE_PROBE_RESP)
end_define

begin_comment
comment|/*  * Station mode roaming parameters.  These are maintained  * per band/mode and control the roaming algorithm.  */
end_comment

begin_struct
struct|struct
name|ieee80211_roamparams_req
block|{
name|struct
name|ieee80211_roamparam
name|params
index|[
name|IEEE80211_MODE_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Transmit parameters.  These can be used to set fixed transmit  * rate for each operating mode when operating as client or on a  * per-client basis according to the capabilities of the client  * (e.g. an 11b client associated to an 11g ap) when operating as  * an ap.  *  * MCS are distinguished from legacy rates by or'ing in 0x80.  */
end_comment

begin_struct
struct|struct
name|ieee80211_txparams_req
block|{
name|struct
name|ieee80211_txparam
name|params
index|[
name|IEEE80211_MODE_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Set regulatory domain state with IEEE80211_IOC_REGDOMAIN.  * Note this is both the regulatory description and the channel  * list.  The get request for IEEE80211_IOC_REGDOMAIN returns  * only the regdomain info; the channel list is obtained  * separately with IEEE80211_IOC_CHANINFO.  */
end_comment

begin_struct
struct|struct
name|ieee80211_regdomain_req
block|{
name|struct
name|ieee80211_regdomain
name|rd
decl_stmt|;
name|struct
name|ieee80211req_chaninfo
name|chaninfo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_REGDOMAIN_SIZE
parameter_list|(
name|_nchan
parameter_list|)
define|\
value|(sizeof(struct ieee80211_regdomain_req) + \ 	 (((_nchan)-1) * sizeof(struct ieee80211_channel)))
end_define

begin_define
define|#
directive|define
name|IEEE80211_REGDOMAIN_SPACE
parameter_list|(
name|_req
parameter_list|)
define|\
value|IEEE80211_REGDOMAIN_SIZE((_req)->chaninfo.ic_nchans)
end_define

begin_comment
comment|/*  * Get driver capabilities.  Driver, hardware crypto, and  * HT/802.11n capabilities, and a table that describes what  * the radio can do.  */
end_comment

begin_struct
struct|struct
name|ieee80211_devcaps_req
block|{
name|uint32_t
name|dc_drivercaps
decl_stmt|;
comment|/* general driver caps */
name|uint32_t
name|dc_cryptocaps
decl_stmt|;
comment|/* hardware crypto support */
name|uint32_t
name|dc_htcaps
decl_stmt|;
comment|/* HT/802.11n support */
name|struct
name|ieee80211req_chaninfo
name|dc_chaninfo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_DEVCAPS_SIZE
parameter_list|(
name|_nchan
parameter_list|)
define|\
value|(sizeof(struct ieee80211_devcaps_req) + \ 	 (((_nchan)-1) * sizeof(struct ieee80211_channel)))
end_define

begin_define
define|#
directive|define
name|IEEE80211_DEVCAPS_SPACE
parameter_list|(
name|_dc
parameter_list|)
define|\
value|IEEE80211_DEVCAPS_SIZE((_dc)->dc_chaninfo.ic_nchans)
end_define

begin_struct
struct|struct
name|ieee80211_chanswitch_req
block|{
name|struct
name|ieee80211_channel
name|csa_chan
decl_stmt|;
comment|/* new channel */
name|int
name|csa_mode
decl_stmt|;
comment|/* CSA mode */
name|int
name|csa_count
decl_stmt|;
comment|/* beacon count to switch */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Get/set per-station vlan tag.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_sta_vlan
block|{
name|uint8_t
name|sv_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|sv_vlan
decl_stmt|;
block|}
struct|;
end_struct

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
name|uint16_t
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
name|SIOCG80211STATS
value|_IOWR('i', 236, struct ifreq)
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

begin_comment
comment|/* 22 was IEEE80211_IOC_OPTIE, replaced by IEEE80211_IOC_APPIE */
end_comment

begin_comment
comment|/* 23 was IEEE80211_IOC_SCAN_REQ */
end_comment

begin_comment
comment|/* 24 was IEEE80211_IOC_SCAN_RESULTS */
end_comment

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

begin_comment
comment|/* 31-35,37-38 were for WPA authenticator settings */
end_comment

begin_comment
comment|/* 36 was IEEE80211_IOC_DRIVER_CAPS */
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

begin_comment
comment|/* 45 was IEEE80211_IOC_STA_INFO */
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
name|IEEE80211_IOC_FF
value|57
end_define

begin_comment
comment|/* ATH fast frames (on, off) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_TURBOP
value|58
end_define

begin_comment
comment|/* ATH turbo' (on, off) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_BGSCAN
value|59
end_define

begin_comment
comment|/* bg scanning (on, off) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_BGSCAN_IDLE
value|60
end_define

begin_comment
comment|/* bg scan idle threshold */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_BGSCAN_INTERVAL
value|61
end_define

begin_comment
comment|/* bg scan interval */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_SCANVALID
value|65
end_define

begin_comment
comment|/* scan cache valid threshold */
end_comment

begin_comment
comment|/* 66-72 were IEEE80211_IOC_ROAM_* and IEEE80211_IOC_MCAST_RATE */
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

begin_define
define|#
directive|define
name|IEEE80211_IOC_SCAN_RESULTS
value|76
end_define

begin_comment
comment|/* get scan results */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_BMISSTHRESHOLD
value|77
end_define

begin_comment
comment|/* beacon miss threshold */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_STA_INFO
value|78
end_define

begin_comment
comment|/* station/neighbor info */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_WPAIE2
value|79
end_define

begin_comment
comment|/* WPA+RSN info elements */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_CURCHAN
value|80
end_define

begin_comment
comment|/* current channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_SHORTGI
value|81
end_define

begin_comment
comment|/* 802.11n half GI */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_AMPDU
value|82
end_define

begin_comment
comment|/* 802.11n A-MPDU (on, off) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_AMPDU_LIMIT
value|83
end_define

begin_comment
comment|/* A-MPDU length limit */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_AMPDU_DENSITY
value|84
end_define

begin_comment
comment|/* A-MPDU density */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_AMSDU
value|85
end_define

begin_comment
comment|/* 802.11n A-MSDU (on, off) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_AMSDU_LIMIT
value|86
end_define

begin_comment
comment|/* A-MSDU length limit */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_PUREN
value|87
end_define

begin_comment
comment|/* pure 11n (no legacy sta's) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_DOTH
value|88
end_define

begin_comment
comment|/* 802.11h (on, off) */
end_comment

begin_comment
comment|/* 89-91 were regulatory items */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_HTCOMPAT
value|92
end_define

begin_comment
comment|/* support pre-D1.10 HT ie's */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_DWDS
value|93
end_define

begin_comment
comment|/* DWDS/4-address handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_INACTIVITY
value|94
end_define

begin_comment
comment|/* sta inactivity handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_APPIE
value|95
end_define

begin_comment
comment|/* application IE's */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_WPS
value|96
end_define

begin_comment
comment|/* WPS operation */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_TSN
value|97
end_define

begin_comment
comment|/* TSN operation */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_DEVCAPS
value|98
end_define

begin_comment
comment|/* driver+device capabilities */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_CHANSWITCH
value|99
end_define

begin_comment
comment|/* start 11h channel switch */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_DFS
value|100
end_define

begin_comment
comment|/* DFS (on, off) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_DOTD
value|101
end_define

begin_comment
comment|/* 802.11d (on, off) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_HTPROTMODE
value|102
end_define

begin_comment
comment|/* HT protection (off, rts) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_SCAN_REQ
value|103
end_define

begin_comment
comment|/* scan w/ specified params */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_SCAN_CANCEL
value|104
end_define

begin_comment
comment|/* cancel ongoing scan */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_HTCONF
value|105
end_define

begin_comment
comment|/* HT config (off, HT20, HT40)*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_REGDOMAIN
value|106
end_define

begin_comment
comment|/* regulatory domain info */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_ROAM
value|107
end_define

begin_comment
comment|/* roaming params en masse */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_TXPARAMS
value|108
end_define

begin_comment
comment|/* tx parameters */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_STA_VLAN
value|109
end_define

begin_comment
comment|/* per-station vlan tag */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_SMPS
value|110
end_define

begin_comment
comment|/* MIMO power save */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_RIFS
value|111
end_define

begin_comment
comment|/* RIFS config (on, off) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_GREENFIELD
value|112
end_define

begin_comment
comment|/* Greenfield (on, off) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_STBC
value|113
end_define

begin_comment
comment|/* STBC Tx/RX (on, off) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MESH_ID
value|170
end_define

begin_comment
comment|/* mesh identifier */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MESH_AP
value|171
end_define

begin_comment
comment|/* accepting peerings */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MESH_FWRD
value|172
end_define

begin_comment
comment|/* forward frames */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MESH_PROTO
value|173
end_define

begin_comment
comment|/* mesh protocols */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MESH_TTL
value|174
end_define

begin_comment
comment|/* mesh TTL */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MESH_RTCMD
value|175
end_define

begin_comment
comment|/* mesh routing table commands*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MESH_PR_METRIC
value|176
end_define

begin_comment
comment|/* mesh metric protocol */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MESH_PR_PATH
value|177
end_define

begin_comment
comment|/* mesh path protocol */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MESH_PR_SIG
value|178
end_define

begin_comment
comment|/* mesh sig protocol */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MESH_PR_CC
value|179
end_define

begin_comment
comment|/* mesh congestion protocol */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_MESH_PR_AUTH
value|180
end_define

begin_comment
comment|/* mesh auth protocol */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_HWMP_ROOTMODE
value|190
end_define

begin_comment
comment|/* HWMP root mode */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_HWMP_MAXHOPS
value|191
end_define

begin_comment
comment|/* number of hops before drop */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_HWMP_TTL
value|192
end_define

begin_comment
comment|/* HWMP TTL */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_TDMA_SLOT
value|201
end_define

begin_comment
comment|/* TDMA: assigned slot */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_TDMA_SLOTCNT
value|202
end_define

begin_comment
comment|/* TDMA: slots in bss */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_TDMA_SLOTLEN
value|203
end_define

begin_comment
comment|/* TDMA: slot length (usecs) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IOC_TDMA_BINTERVAL
value|204
end_define

begin_comment
comment|/* TDMA: beacon intvl (slots) */
end_comment

begin_comment
comment|/*  * Parameters for controlling a scan requested with  * IEEE80211_IOC_SCAN_REQ.  *  * Active scans cause ProbeRequest frames to be issued for each  * specified ssid and, by default, a broadcast ProbeRequest frame.  * The set of ssid's is specified in the request.  *  * By default the scan will cause a BSS to be joined (in station/adhoc  * mode) or a channel to be selected for operation (hostap mode).  * To disable that specify IEEE80211_IOC_SCAN_NOPICK and if the  *  * If the station is currently associated to an AP then a scan request  * will cause the station to leave the current channel and potentially  * miss frames from the AP.  Alternatively the station may notify the  * AP that it is going into power save mode before it leaves the channel.  * This ensures frames for the station are buffered by the AP.  This is  * termed a ``bg scan'' and is requested with the IEEE80211_IOC_SCAN_BGSCAN  * flag.  Background scans may take longer than foreground scans and may  * be preempted by traffic.  If a station is not associated to an AP  * then a request for a background scan is automatically done in the  * foreground.  *  * The results of the scan request are cached by the system.  This  * information is aged out and/or invalidated based on events like not  * being able to associated to an AP.  To flush the current cache  * contents before doing a scan the IEEE80211_IOC_SCAN_FLUSH flag may  * be specified.  *  * By default the scan will be done until a suitable AP is located  * or a channel is found for use.  A scan can also be constrained  * to be done once (IEEE80211_IOC_SCAN_ONCE) or to last for no more  * than a specified duration.  */
end_comment

begin_struct
struct|struct
name|ieee80211_scan_req
block|{
name|int
name|sr_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_IOC_SCAN_NOPICK
value|0x00001
comment|/* scan only, no selection */
define|#
directive|define
name|IEEE80211_IOC_SCAN_ACTIVE
value|0x00002
comment|/* active scan (probe req) */
define|#
directive|define
name|IEEE80211_IOC_SCAN_PICK1ST
value|0x00004
comment|/* ``hey sailor'' mode */
define|#
directive|define
name|IEEE80211_IOC_SCAN_BGSCAN
value|0x00008
comment|/* bg scan, exit ps at end */
define|#
directive|define
name|IEEE80211_IOC_SCAN_ONCE
value|0x00010
comment|/* do one complete pass */
define|#
directive|define
name|IEEE80211_IOC_SCAN_NOBCAST
value|0x00020
comment|/* don't send bcast probe req */
define|#
directive|define
name|IEEE80211_IOC_SCAN_NOJOIN
value|0x00040
comment|/* no auto-sequencing */
define|#
directive|define
name|IEEE80211_IOC_SCAN_FLUSH
value|0x10000
comment|/* flush scan cache first */
define|#
directive|define
name|IEEE80211_IOC_SCAN_CHECK
value|0x20000
comment|/* check scan cache first */
name|u_int
name|sr_duration
decl_stmt|;
comment|/* duration (ms) */
define|#
directive|define
name|IEEE80211_IOC_SCAN_DURATION_MIN
value|1
define|#
directive|define
name|IEEE80211_IOC_SCAN_DURATION_MAX
value|0x7fffffff
define|#
directive|define
name|IEEE80211_IOC_SCAN_FOREVER
value|IEEE80211_IOC_SCAN_DURATION_MAX
name|u_int
name|sr_mindwell
decl_stmt|;
comment|/* min channel dwelltime (ms) */
name|u_int
name|sr_maxdwell
decl_stmt|;
comment|/* max channel dwelltime (ms) */
name|int
name|sr_nssid
decl_stmt|;
define|#
directive|define
name|IEEE80211_IOC_SCAN_MAX_SSID
value|3
struct|struct
block|{
name|int
name|len
decl_stmt|;
comment|/* length in bytes */
name|uint8_t
name|ssid
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
comment|/* ssid contents */
block|}
name|sr_ssid
index|[
name|IEEE80211_IOC_SCAN_MAX_SSID
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Scan result data returned for IEEE80211_IOC_SCAN_RESULTS.  * Each result is a fixed size structure followed by a variable  * length SSID and one or more variable length information elements.  * The size of each variable length item is found in the fixed  * size structure and the entire length of the record is specified  * in isr_len.  Result records are rounded to a multiple of 4 bytes.  */
end_comment

begin_struct
struct|struct
name|ieee80211req_scan_result
block|{
name|uint16_t
name|isr_len
decl_stmt|;
comment|/* total length (mult of 4) */
name|uint16_t
name|isr_ie_off
decl_stmt|;
comment|/* offset to SSID+IE data */
name|uint16_t
name|isr_ie_len
decl_stmt|;
comment|/* IE length */
name|uint16_t
name|isr_freq
decl_stmt|;
comment|/* MHz */
name|uint16_t
name|isr_flags
decl_stmt|;
comment|/* channel flags */
name|int8_t
name|isr_noise
decl_stmt|;
name|int8_t
name|isr_rssi
decl_stmt|;
name|uint16_t
name|isr_intval
decl_stmt|;
comment|/* beacon interval */
name|uint8_t
name|isr_capinfo
decl_stmt|;
comment|/* capabilities */
name|uint8_t
name|isr_erp
decl_stmt|;
comment|/* ERP element */
name|uint8_t
name|isr_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|isr_nrates
decl_stmt|;
name|uint8_t
name|isr_rates
index|[
name|IEEE80211_RATE_MAXSIZE
index|]
decl_stmt|;
name|uint8_t
name|isr_ssid_len
decl_stmt|;
comment|/* SSID length */
name|uint8_t
name|isr_meshid_len
decl_stmt|;
comment|/* MESH ID length */
comment|/* variable length SSID, followed by variable length MESH ID, 	  followed by IE data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Virtual AP cloning parameters.  The parent device must  * be a vap-capable device.  All parameters specified with  * the clone request are fixed for the lifetime of the vap.  *  * There are two flavors of WDS vaps: legacy and dynamic.  * Legacy WDS operation implements a static binding between  * two stations encapsulating traffic in 4-address frames.  * Dynamic WDS vaps are created when a station associates to  * an AP and sends a 4-address frame.  If the AP vap is  * configured to support WDS then this will generate an  * event to user programs listening on the routing socket  * and a Dynamic WDS vap will be created to handle traffic  * to/from that station.  In both cases the bssid of the  * peer must be specified when creating the vap.  *  * By default a vap will inherit the mac address/bssid of  * the underlying device.  To request a unique address the  * IEEE80211_CLONE_BSSID flag should be supplied.  This is  * meaningless for WDS vaps as they share the bssid of an  * AP vap that must otherwise exist.  Note that some devices  * may not be able to support multiple addresses.  *  * Station mode vap's normally depend on the device to notice  * when the AP stops sending beacon frames.  If IEEE80211_CLONE_NOBEACONS  * is specified the net80211 layer will do this in s/w.  This  * is mostly useful when setting up a WDS repeater/extender where  * an AP vap is combined with a sta vap and the device isn't able  * to track beacon frames in hardware.  */
end_comment

begin_struct
struct|struct
name|ieee80211_clone_params
block|{
name|char
name|icp_parent
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* parent device */
name|uint16_t
name|icp_opmode
decl_stmt|;
comment|/* operating mode */
name|uint16_t
name|icp_flags
decl_stmt|;
comment|/* see below */
name|uint8_t
name|icp_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
comment|/* for WDS links */
name|uint8_t
name|icp_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
comment|/* local address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_CLONE_BSSID
value|0x0001
end_define

begin_comment
comment|/* allocate unique mac/bssid */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CLONE_NOBEACONS
value|0x0002
end_define

begin_comment
comment|/* don't setup beacon timers */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CLONE_WDSLEGACY
value|0x0004
end_define

begin_comment
comment|/* legacy WDS processing */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CLONE_MACADDR
value|0x0008
end_define

begin_comment
comment|/* use specified mac addr */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CLONE_TDMA
value|0x0010
end_define

begin_comment
comment|/* operate in TDMA mode */
end_comment

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

