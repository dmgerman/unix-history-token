begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002, 2003 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|is_rx_nowep
decl_stmt|;
comment|/* rx w/ wep but wep !config */
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
name|is_rx_nombuf
decl_stmt|;
comment|/* rx failed for lack of mbuf */
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
name|is_tx_nombuf
decl_stmt|;
comment|/* tx failed for lack of mbuf */
name|u_int32_t
name|is_tx_nonode
decl_stmt|;
comment|/* tx failed for no node */
name|u_int32_t
name|is_tx_unknownmgt
decl_stmt|;
comment|/* tx of unknown mgt frame */
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

begin_ifndef
ifndef|#
directive|ifndef
name|IEEE80211_CHAN_ANY
end_ifndef

begin_define
define|#
directive|define
name|IEEE80211_CHAN_ANY
value|0xffff
end_define

begin_comment
comment|/* token for ``any channel'' */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

