begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_WAVELAN_IEEE_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_WAVELAN_IEEE_H
end_define

begin_comment
comment|/*  * This header defines a simple command interface to the FreeBSD  * WaveLAN/IEEE driver (wi) driver, which is used to set certain  * device-specific parameters which can't be easily managed through  * ifconfig(8). No, sysctl(2) is not the answer. I said a _simple_  * interface, didn't I.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIOCSWAVELAN
end_ifndef

begin_define
define|#
directive|define
name|SIOCSWAVELAN
value|SIOCSIFGENERIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIOCGWAVELAN
end_ifndef

begin_define
define|#
directive|define
name|SIOCGWAVELAN
value|SIOCGIFGENERIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WI_RID_MONITOR_MODE
value|0x0500
end_define

begin_comment
comment|/*  * Technically I don't think there's a limit to a record  * length. The largest record is the one that contains the CIS  * data, which is 240 words long, so 256 should be a safe  * value.  */
end_comment

begin_define
define|#
directive|define
name|WI_MAX_DATALEN
value|512
end_define

begin_struct
struct|struct
name|wi_req
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
name|u_int16_t
name|wi_val
index|[
name|WI_MAX_DATALEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Private LTV records (interpreted only by the driver). This is  * a minor kludge to allow reading the interface statistics from  * the driver.  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_IFACE_STATS
value|0x0100
end_define

begin_define
define|#
directive|define
name|WI_RID_MGMT_XMIT
value|0x0200
end_define

begin_define
define|#
directive|define
name|WI_RID_ZERO_CACHE
value|0x0300
end_define

begin_define
define|#
directive|define
name|WI_RID_READ_CACHE
value|0x0400
end_define

begin_struct
struct|struct
name|wi_80211_hdr
block|{
name|u_int16_t
name|frame_ctl
decl_stmt|;
name|u_int16_t
name|dur_id
decl_stmt|;
name|u_int8_t
name|addr1
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|addr2
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|addr3
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|seq_ctl
decl_stmt|;
name|u_int8_t
name|addr4
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WI_FCTL_VERS
value|0x0002
end_define

begin_define
define|#
directive|define
name|WI_FCTL_FTYPE
value|0x000C
end_define

begin_define
define|#
directive|define
name|WI_FCTL_STYPE
value|0x00F0
end_define

begin_define
define|#
directive|define
name|WI_FCTL_TODS
value|0x0100
end_define

begin_define
define|#
directive|define
name|WI_FCTL_FROMDS
value|0x0200
end_define

begin_define
define|#
directive|define
name|WI_FCTL_MOREFRAGS
value|0x0400
end_define

begin_define
define|#
directive|define
name|WI_FCTL_RETRY
value|0x0800
end_define

begin_define
define|#
directive|define
name|WI_FCTL_PM
value|0x1000
end_define

begin_define
define|#
directive|define
name|WI_FCTL_MOREDATA
value|0x2000
end_define

begin_define
define|#
directive|define
name|WI_FCTL_WEP
value|0x4000
end_define

begin_define
define|#
directive|define
name|WI_FCTL_ORDER
value|0x8000
end_define

begin_define
define|#
directive|define
name|WI_FTYPE_MGMT
value|0x0000
end_define

begin_define
define|#
directive|define
name|WI_FTYPE_CTL
value|0x0004
end_define

begin_define
define|#
directive|define
name|WI_FTYPE_DATA
value|0x0008
end_define

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_ASREQ
value|0x0000
end_define

begin_comment
comment|/* association request */
end_comment

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_ASRESP
value|0x0010
end_define

begin_comment
comment|/* association response */
end_comment

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_REASREQ
value|0x0020
end_define

begin_comment
comment|/* reassociation request */
end_comment

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_REASRESP
value|0x0030
end_define

begin_comment
comment|/* reassociation response */
end_comment

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_PROBEREQ
value|0x0040
end_define

begin_comment
comment|/* probe request */
end_comment

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_PROBERESP
value|0x0050
end_define

begin_comment
comment|/* probe response */
end_comment

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_BEACON
value|0x0080
end_define

begin_comment
comment|/* beacon */
end_comment

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_ATIM
value|0x0090
end_define

begin_comment
comment|/* announcement traffic ind msg */
end_comment

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_DISAS
value|0x00A0
end_define

begin_comment
comment|/* disassociation */
end_comment

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_AUTH
value|0x00B0
end_define

begin_comment
comment|/* authentication */
end_comment

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_DEAUTH
value|0x00C0
end_define

begin_comment
comment|/* deauthentication */
end_comment

begin_define
define|#
directive|define
name|WI_STYPE_CTL_PSPOLL
value|0x00A0
end_define

begin_define
define|#
directive|define
name|WI_STYPE_CTL_RTS
value|0x00B0
end_define

begin_define
define|#
directive|define
name|WI_STYPE_CTL_CTS
value|0x00C0
end_define

begin_define
define|#
directive|define
name|WI_STYPE_CTL_ACK
value|0x00D0
end_define

begin_define
define|#
directive|define
name|WI_STYPE_CTL_CFEND
value|0x00E0
end_define

begin_define
define|#
directive|define
name|WI_STYPE_CTL_CFENDACK
value|0x00F0
end_define

begin_struct
struct|struct
name|wi_mgmt_hdr
block|{
name|u_int16_t
name|frame_ctl
decl_stmt|;
name|u_int16_t
name|duration
decl_stmt|;
name|u_int8_t
name|dst_addr
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|src_addr
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|bssid
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|seq_ctl
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*   * Lucent/wavelan IEEE signal strength cache  *  * driver keeps cache of last  * MAXWICACHE packets to arrive including signal strength info.  * daemons may read this via ioctl  *  * Each entry in the wi_sigcache has a unique macsrc.  */
end_comment

begin_struct
struct|struct
name|wi_sigcache
block|{
name|char
name|macsrc
index|[
literal|6
index|]
decl_stmt|;
comment|/* unique MAC address for entry */
name|int
name|ipsrc
decl_stmt|;
comment|/* ip address associated with packet */
name|int
name|signal
decl_stmt|;
comment|/* signal strength of the packet */
name|int
name|noise
decl_stmt|;
comment|/* noise value */
name|int
name|quality
decl_stmt|;
comment|/* quality of the packet */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_struct
struct|struct
name|wi_counters
block|{
name|u_int32_t
name|wi_tx_unicast_frames
decl_stmt|;
name|u_int32_t
name|wi_tx_multicast_frames
decl_stmt|;
name|u_int32_t
name|wi_tx_fragments
decl_stmt|;
name|u_int32_t
name|wi_tx_unicast_octets
decl_stmt|;
name|u_int32_t
name|wi_tx_multicast_octets
decl_stmt|;
name|u_int32_t
name|wi_tx_deferred_xmits
decl_stmt|;
name|u_int32_t
name|wi_tx_single_retries
decl_stmt|;
name|u_int32_t
name|wi_tx_multi_retries
decl_stmt|;
name|u_int32_t
name|wi_tx_retry_limit
decl_stmt|;
name|u_int32_t
name|wi_tx_discards
decl_stmt|;
name|u_int32_t
name|wi_rx_unicast_frames
decl_stmt|;
name|u_int32_t
name|wi_rx_multicast_frames
decl_stmt|;
name|u_int32_t
name|wi_rx_fragments
decl_stmt|;
name|u_int32_t
name|wi_rx_unicast_octets
decl_stmt|;
name|u_int32_t
name|wi_rx_multicast_octets
decl_stmt|;
name|u_int32_t
name|wi_rx_fcs_errors
decl_stmt|;
name|u_int32_t
name|wi_rx_discards_nobuf
decl_stmt|;
name|u_int32_t
name|wi_tx_discards_wrong_sa
decl_stmt|;
name|u_int32_t
name|wi_rx_WEP_cant_decrypt
decl_stmt|;
name|u_int32_t
name|wi_rx_msg_in_msg_frags
decl_stmt|;
name|u_int32_t
name|wi_rx_msg_in_bad_msg_frags
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Network parameters, static configuration entities.  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PORTTYPE
value|0xFC00
end_define

begin_comment
comment|/* Connection control characteristics */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MAC_NODE
value|0xFC01
end_define

begin_comment
comment|/* MAC address of this station */
end_comment

begin_define
define|#
directive|define
name|WI_RID_DESIRED_SSID
value|0xFC02
end_define

begin_comment
comment|/* Service Set ID for connection */
end_comment

begin_define
define|#
directive|define
name|WI_RID_OWN_CHNL
value|0xFC03
end_define

begin_comment
comment|/* Comm channel for BSS creation */
end_comment

begin_define
define|#
directive|define
name|WI_RID_OWN_SSID
value|0xFC04
end_define

begin_comment
comment|/* IBSS creation ID */
end_comment

begin_define
define|#
directive|define
name|WI_RID_OWN_ATIM_WIN
value|0xFC05
end_define

begin_comment
comment|/* ATIM window time for IBSS creation */
end_comment

begin_define
define|#
directive|define
name|WI_RID_SYSTEM_SCALE
value|0xFC06
end_define

begin_comment
comment|/* scale that specifies AP density */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MAX_DATALEN
value|0xFC07
end_define

begin_comment
comment|/* Max len of MAC frame body data */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MAC_WDS
value|0xFC08
end_define

begin_comment
comment|/* MAC addr of corresponding WDS node */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PM_ENABLED
value|0xFC09
end_define

begin_comment
comment|/* ESS power management enable */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PM_EPS
value|0xFC0A
end_define

begin_comment
comment|/* PM EPS/PS mode */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MCAST_RX
value|0xFC0B
end_define

begin_comment
comment|/* ESS PM mcast reception */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MAX_SLEEP
value|0xFC0C
end_define

begin_comment
comment|/* max sleep time for ESS PM */
end_comment

begin_define
define|#
directive|define
name|WI_RID_HOLDOVER
value|0xFC0D
end_define

begin_comment
comment|/* holdover time for ESS PM */
end_comment

begin_define
define|#
directive|define
name|WI_RID_NODENAME
value|0xFC0E
end_define

begin_comment
comment|/* ID name of this node for diag */
end_comment

begin_define
define|#
directive|define
name|WI_RID_DTIM_PERIOD
value|0xFC10
end_define

begin_comment
comment|/* beacon interval between DTIMs */
end_comment

begin_define
define|#
directive|define
name|WI_RID_WDS_ADDR1
value|0xFC11
end_define

begin_comment
comment|/* port 1 MAC of WDS link node */
end_comment

begin_define
define|#
directive|define
name|WI_RID_WDS_ADDR2
value|0xFC12
end_define

begin_comment
comment|/* port 1 MAC of WDS link node */
end_comment

begin_define
define|#
directive|define
name|WI_RID_WDS_ADDR3
value|0xFC13
end_define

begin_comment
comment|/* port 1 MAC of WDS link node */
end_comment

begin_define
define|#
directive|define
name|WI_RID_WDS_ADDR4
value|0xFC14
end_define

begin_comment
comment|/* port 1 MAC of WDS link node */
end_comment

begin_define
define|#
directive|define
name|WI_RID_WDS_ADDR5
value|0xFC15
end_define

begin_comment
comment|/* port 1 MAC of WDS link node */
end_comment

begin_define
define|#
directive|define
name|WI_RID_WDS_ADDR6
value|0xFC16
end_define

begin_comment
comment|/* port 1 MAC of WDS link node */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MCAST_PM_BUF
value|0xFC17
end_define

begin_comment
comment|/* PM buffering of mcast */
end_comment

begin_define
define|#
directive|define
name|WI_RID_ENCRYPTION
value|0xFC20
end_define

begin_comment
comment|/* enable/disable WEP */
end_comment

begin_define
define|#
directive|define
name|WI_RID_AUTHTYPE
value|0xFC21
end_define

begin_comment
comment|/* specify authentication type */
end_comment

begin_define
define|#
directive|define
name|WI_RID_P2_TX_CRYPT_KEY
value|0xFC23
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_CRYPT_KEY0
value|0xFC24
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_CRYPT_KEY1
value|0xFC25
end_define

begin_define
define|#
directive|define
name|WI_RID_MICROWAVE_OVEN
value|0xFC25
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_CRYPT_KEY2
value|0xFC26
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_CRYPT_KEY3
value|0xFC27
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_ENCRYPTION
value|0xFC28
end_define

begin_define
define|#
directive|define
name|PRIVACY_INVOKED
value|0x01
end_define

begin_define
define|#
directive|define
name|EXCLUDE_UNENCRYPTED
value|0x02
end_define

begin_define
define|#
directive|define
name|HOST_ENCRYPT
value|0x10
end_define

begin_define
define|#
directive|define
name|IV_EVERY_FRAME
value|0x00
end_define

begin_comment
comment|/* IV = Initialization Vector */
end_comment

begin_define
define|#
directive|define
name|IV_EVERY10_FRAME
value|0x20
end_define

begin_comment
comment|/* every 10 frame IV reuse */
end_comment

begin_define
define|#
directive|define
name|IV_EVERY50_FRAME
value|0x40
end_define

begin_comment
comment|/* every 50 frame IV reuse */
end_comment

begin_define
define|#
directive|define
name|IV_EVERY100_FRAME
value|0x60
end_define

begin_comment
comment|/* every 100 frame IV reuse */
end_comment

begin_define
define|#
directive|define
name|HOST_DECRYPT
value|0x80
end_define

begin_define
define|#
directive|define
name|WI_RID_WEP_MAPTABLE
value|0xFC29
end_define

begin_define
define|#
directive|define
name|WI_RID_CNFAUTHMODE
value|0xFC2A
end_define

begin_define
define|#
directive|define
name|WI_RID_ROAMING_MODE
value|0xFC2D
end_define

begin_define
define|#
directive|define
name|WI_RID_BASIC_RATE
value|0xFCB3
end_define

begin_define
define|#
directive|define
name|WI_RID_SUPPORT_RATE
value|0xFCB4
end_define

begin_comment
comment|/*  * Network parameters, dynamic configuration entities  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MCAST_LIST
value|0xFC80
end_define

begin_comment
comment|/* list of multicast addrs */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CREATE_IBSS
value|0xFC81
end_define

begin_comment
comment|/* create IBSS */
end_comment

begin_define
define|#
directive|define
name|WI_RID_FRAG_THRESH
value|0xFC82
end_define

begin_comment
comment|/* frag len, unicast msg xmit */
end_comment

begin_define
define|#
directive|define
name|WI_RID_RTS_THRESH
value|0xFC83
end_define

begin_comment
comment|/* frame len for RTS/CTS handshake */
end_comment

begin_define
define|#
directive|define
name|WI_RID_TX_RATE
value|0xFC84
end_define

begin_comment
comment|/* data rate for message xmit  					* 0 == Fixed 1mbps  					* 1 == Fixed 2mbps  					* 2 == auto fallback 					*/
end_comment

begin_define
define|#
directive|define
name|WI_RID_PROMISC
value|0xFC85
end_define

begin_comment
comment|/* enable promisc mode */
end_comment

begin_define
define|#
directive|define
name|WI_RID_FRAG_THRESH0
value|0xFC90
end_define

begin_define
define|#
directive|define
name|WI_RID_FRAG_THRESH1
value|0xFC91
end_define

begin_define
define|#
directive|define
name|WI_RID_FRAG_THRESH2
value|0xFC92
end_define

begin_define
define|#
directive|define
name|WI_RID_FRAG_THRESH3
value|0xFC93
end_define

begin_define
define|#
directive|define
name|WI_RID_FRAG_THRESH4
value|0xFC94
end_define

begin_define
define|#
directive|define
name|WI_RID_FRAG_THRESH5
value|0xFC95
end_define

begin_define
define|#
directive|define
name|WI_RID_FRAG_THRESH6
value|0xFC96
end_define

begin_define
define|#
directive|define
name|WI_RID_RTS_THRESH0
value|0xFC97
end_define

begin_define
define|#
directive|define
name|WI_RID_RTS_THRESH1
value|0xFC98
end_define

begin_define
define|#
directive|define
name|WI_RID_RTS_THRESH2
value|0xFC99
end_define

begin_define
define|#
directive|define
name|WI_RID_RTS_THRESH3
value|0xFC9A
end_define

begin_define
define|#
directive|define
name|WI_RID_RTS_THRESH4
value|0xFC9B
end_define

begin_define
define|#
directive|define
name|WI_RID_RTS_THRESH5
value|0xFC9C
end_define

begin_define
define|#
directive|define
name|WI_RID_RTS_THRESH6
value|0xFC9D
end_define

begin_define
define|#
directive|define
name|WI_RID_TX_RATE0
value|0xFC9E
end_define

begin_define
define|#
directive|define
name|WI_RID_TX_RATE1
value|0xFC9F
end_define

begin_define
define|#
directive|define
name|WI_RID_TX_RATE2
value|0xFCA0
end_define

begin_define
define|#
directive|define
name|WI_RID_TX_RATE3
value|0xFCA1
end_define

begin_define
define|#
directive|define
name|WI_RID_TX_RATE4
value|0xFCA2
end_define

begin_define
define|#
directive|define
name|WI_RID_TX_RATE5
value|0xFCA3
end_define

begin_define
define|#
directive|define
name|WI_RID_TX_RATE6
value|0xFCA4
end_define

begin_define
define|#
directive|define
name|WI_RID_DEFLT_CRYPT_KEYS
value|0xFCB0
end_define

begin_define
define|#
directive|define
name|WI_RID_TX_CRYPT_KEY
value|0xFCB1
end_define

begin_define
define|#
directive|define
name|WI_RID_TICK_TIME
value|0xFCE0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_struct
struct|struct
name|wi_key
block|{
name|u_int16_t
name|wi_keylen
decl_stmt|;
name|u_int8_t
name|wi_keydat
index|[
literal|14
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wi_ltv_keys
block|{
name|u_int16_t
name|wi_len
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
name|struct
name|wi_key
name|wi_keys
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * NIC information  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_DNLD_BUF
value|0xFD01
end_define

begin_define
define|#
directive|define
name|WI_RID_MEMSZ
value|0xFD02
end_define

begin_comment
comment|/* memory size info (XXX Lucent) */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PRI_IDENTITY
value|0xFD02
end_define

begin_comment
comment|/* primary funcs firmware ident (PRISM2) */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PRI_SUP_RANGE
value|0xFD03
end_define

begin_comment
comment|/* primary supplier compatibility */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CIF_ACT_RANGE
value|0xFD04
end_define

begin_comment
comment|/* controller sup. compatibility */
end_comment

begin_define
define|#
directive|define
name|WI_RID_SERIALNO
value|0xFD0A
end_define

begin_comment
comment|/* card serial number */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CARD_ID
value|0xFD0B
end_define

begin_comment
comment|/* card identification */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MFI_SUP_RANGE
value|0xFD0C
end_define

begin_comment
comment|/* modem supplier compatibility */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CFI_SUP_RANGE
value|0xFD0D
end_define

begin_comment
comment|/* controller sup. compatibility */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CHANNEL_LIST
value|0xFD10
end_define

begin_comment
comment|/* allowd comm. frequencies. */
end_comment

begin_define
define|#
directive|define
name|WI_RID_REG_DOMAINS
value|0xFD11
end_define

begin_comment
comment|/* list of intendted regulatory doms */
end_comment

begin_define
define|#
directive|define
name|WI_RID_TEMP_TYPE
value|0xFD12
end_define

begin_comment
comment|/* hw temp range code */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CIS
value|0xFD13
end_define

begin_comment
comment|/* PC card info struct */
end_comment

begin_define
define|#
directive|define
name|WI_RID_STA_IDENTITY
value|0xFD20
end_define

begin_comment
comment|/* station funcs firmware ident */
end_comment

begin_define
define|#
directive|define
name|WI_RID_STA_SUP_RANGE
value|0xFD21
end_define

begin_comment
comment|/* station supplier compat */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MFI_ACT_RANGE
value|0xFD22
end_define

begin_define
define|#
directive|define
name|WI_RID_SYMBOL_IDENTITY
value|0xFD24
end_define

begin_define
define|#
directive|define
name|WI_RID_CFI_ACT_RANGE
value|0xFD33
end_define

begin_define
define|#
directive|define
name|WI_RID_COMMQUAL
value|0xFD43
end_define

begin_define
define|#
directive|define
name|WI_RID_SCALETHRESH
value|0xFD46
end_define

begin_define
define|#
directive|define
name|WI_RID_PCF
value|0xFD87
end_define

begin_comment
comment|/*  * MAC information  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PORT_STAT
value|0xFD40
end_define

begin_comment
comment|/* actual MAC port con control stat */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CURRENT_SSID
value|0xFD41
end_define

begin_comment
comment|/* ID of actually connected SS */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CURRENT_BSSID
value|0xFD42
end_define

begin_comment
comment|/* ID of actually connected BSS */
end_comment

begin_define
define|#
directive|define
name|WI_RID_COMMS_QUALITY
value|0xFD43
end_define

begin_comment
comment|/* quality of BSS connection */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CUR_TX_RATE
value|0xFD44
end_define

begin_comment
comment|/* current TX rate */
end_comment

begin_define
define|#
directive|define
name|WI_RID_OWN_BEACON_INT
value|0xFD45
end_define

begin_comment
comment|/* beacon xmit time for BSS creation */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CUR_SCALE_THRESH
value|0xFD46
end_define

begin_comment
comment|/* actual system scane thresh setting */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PROT_RESP_TIME
value|0xFD47
end_define

begin_comment
comment|/* time to wait for resp to req msg */
end_comment

begin_define
define|#
directive|define
name|WI_RID_SHORT_RTR_LIM
value|0xFD48
end_define

begin_comment
comment|/* max tx attempts for short frames */
end_comment

begin_define
define|#
directive|define
name|WI_RID_LONG_RTS_LIM
value|0xFD49
end_define

begin_comment
comment|/* max tx attempts for long frames */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MAX_TX_LIFE
value|0xFD4A
end_define

begin_comment
comment|/* max tx frame handling duration */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MAX_RX_LIFE
value|0xFD4B
end_define

begin_comment
comment|/* max rx frame handling duration */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CF_POLL
value|0xFD4C
end_define

begin_comment
comment|/* contention free pollable ind */
end_comment

begin_define
define|#
directive|define
name|WI_RID_AUTH_ALGS
value|0xFD4D
end_define

begin_comment
comment|/* auth algorithms available */
end_comment

begin_define
define|#
directive|define
name|WI_RID_AUTH_TYPE
value|0xFD4E
end_define

begin_comment
comment|/* availanle auth types */
end_comment

begin_define
define|#
directive|define
name|WI_RID_WEP_AVAIL
value|0xFD4F
end_define

begin_comment
comment|/* WEP privacy option available */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CUR_TX_RATE1
value|0xFD80
end_define

begin_define
define|#
directive|define
name|WI_RID_CUR_TX_RATE2
value|0xFD81
end_define

begin_define
define|#
directive|define
name|WI_RID_CUR_TX_RATE3
value|0xFD82
end_define

begin_define
define|#
directive|define
name|WI_RID_CUR_TX_RATE4
value|0xFD83
end_define

begin_define
define|#
directive|define
name|WI_RID_CUR_TX_RATE5
value|0xFD84
end_define

begin_define
define|#
directive|define
name|WI_RID_CUR_TX_RATE6
value|0xFD85
end_define

begin_define
define|#
directive|define
name|WI_RID_OWN_MAC
value|0xFD86
end_define

begin_comment
comment|/* unique local MAC addr */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PCI_INFO
value|0xFD87
end_define

begin_comment
comment|/* point coordination func cap */
end_comment

begin_comment
comment|/*  * Modem information  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PHY_TYPE
value|0xFDC0
end_define

begin_comment
comment|/* phys layer type indication */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CURRENT_CHAN
value|0xFDC1
end_define

begin_comment
comment|/* current frequency */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PWR_STATE
value|0xFDC2
end_define

begin_comment
comment|/* pwr consumption status */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CCA_MODE
value|0xFDC3
end_define

begin_comment
comment|/* clear chan assess mode indication */
end_comment

begin_define
define|#
directive|define
name|WI_RID_CCA_TIME
value|0xFDC4
end_define

begin_comment
comment|/* clear chan assess time */
end_comment

begin_define
define|#
directive|define
name|WI_RID_MAC_PROC_DELAY
value|0xFDC5
end_define

begin_comment
comment|/* MAC processing delay time */
end_comment

begin_define
define|#
directive|define
name|WI_RID_DATA_RATES
value|0xFDC6
end_define

begin_comment
comment|/* supported data rates */
end_comment

begin_comment
comment|/*  * bsd-airtools v0.2 - source-mods v0.2 [common.h]  * by h1kari - (c) Dachb0den Labs 2001  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Dachb0den Labs.  *      David Hulton<h1kari@dachb0den.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by David Hulton.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY David Hulton AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL David Hulton OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * standard hermes recieve frame used by wavelan/prism2 cards  */
end_comment

begin_struct
struct|struct
name|wi_rx_frame
block|{
comment|/* 	 * hermes prefix header. supplies information on the current status of 	 * the network and various other statistics gathered from the 	 * management/control frames as used internally. 	 */
name|u_int16_t
name|wi_status
decl_stmt|;
name|u_int16_t
name|wi_ts0
decl_stmt|;
name|u_int16_t
name|wi_ts1
decl_stmt|;
name|u_int8_t
name|wi_silence
decl_stmt|;
name|u_int8_t
name|wi_signal
decl_stmt|;
name|u_int8_t
name|wi_rate
decl_stmt|;
name|u_int8_t
name|wi_rx_flow
decl_stmt|;
name|u_int16_t
name|wi_rsvd0
decl_stmt|;
name|u_int16_t
name|wi_rsvd1
decl_stmt|;
comment|/* 	 * standard 80211 frame header. all packets have to use this header as 	 * per the AN9900 from intersil, even management/control. for 	 * management packets, they just threw the header into the data field, 	 * but for control packets the headers are lost in translation and 	 * therefore not all control packet info can be displayed. 	 */
name|u_int16_t
name|wi_frame_ctl
decl_stmt|;
name|u_int16_t
name|wi_id
decl_stmt|;
name|u_int8_t
name|wi_addr1
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|wi_addr2
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|wi_addr3
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|wi_seq_ctl
decl_stmt|;
name|u_int8_t
name|wi_addr4
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|wi_dat_len
decl_stmt|;
comment|/* 	 * another wierdity with the drivers. they append a 802.3 header which 	 * is somewhat redundant, since all the same data is provided in the 	 * 802.11 header. 	 */
name|u_int8_t
name|wi_dst_addr
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|wi_src_addr
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|wi_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WI_DATA_HDRLEN
value|WI_802_11_OFFSET
end_define

begin_define
define|#
directive|define
name|WI_MGMT_HDRLEN
value|WI_802_11_OFFSET_RAW
end_define

begin_define
define|#
directive|define
name|WI_CTL_HDRLEN
value|WI_802_11_OFFSET_RAW
end_define

begin_comment
comment|/*  * all data packets have a snap (sub-network access protocol) header that  * isn't entirely definied, but added for ethernet compatibility.  */
end_comment

begin_struct
struct|struct
name|wi_snap_frame
block|{
name|u_int16_t
name|wi_dat
index|[
literal|3
index|]
decl_stmt|;
name|u_int16_t
name|wi_type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * management frame headers  * note: all management frames consist of a static header and variable length  * fields.  */
end_comment

begin_comment
comment|/*  * variable length field structure  */
end_comment

begin_struct
struct|struct
name|wi_mgmt_var_hdr
block|{
name|u_int8_t
name|wi_code
decl_stmt|;
name|u_int8_t
name|wi_len
decl_stmt|;
name|u_int8_t
name|wi_data
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * management beacon frame prefix  */
end_comment

begin_struct
struct|struct
name|wi_mgmt_beacon_hdr
block|{
name|u_int32_t
name|wi_ts0
decl_stmt|;
name|u_int32_t
name|wi_ts1
decl_stmt|;
name|u_int16_t
name|wi_interval
decl_stmt|;
name|u_int16_t
name|wi_capinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ibss announcement traffic indication message (atim) frame  * note: no parameters  */
end_comment

begin_comment
comment|/*  * management disassociation frame  */
end_comment

begin_struct
struct|struct
name|wi_mgmt_disas_hdr
block|{
name|u_int16_t
name|wi_reason
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * management association request frame prefix  */
end_comment

begin_struct
struct|struct
name|wi_mgmt_asreq_hdr
block|{
name|u_int16_t
name|wi_capinfo
decl_stmt|;
name|u_int16_t
name|wi_interval
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * management association response frame prefix  */
end_comment

begin_struct
struct|struct
name|wi_mgmt_asresp_hdr
block|{
name|u_int16_t
name|wi_capinfo
decl_stmt|;
name|u_int16_t
name|wi_status
decl_stmt|;
name|u_int16_t
name|wi_aid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * management reassociation request frame prefix  */
end_comment

begin_struct
struct|struct
name|wi_mgmt_reasreq_hdr
block|{
name|u_int16_t
name|wi_capinfo
decl_stmt|;
name|u_int16_t
name|wi_interval
decl_stmt|;
name|u_int8_t
name|wi_currap
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * management reassociation response frame prefix  */
end_comment

begin_struct
struct|struct
name|wi_mgmt_reasresp_hdr
block|{
name|u_int16_t
name|wi_capinfo
decl_stmt|;
name|u_int16_t
name|wi_status
decl_stmt|;
name|u_int16_t
name|wi_aid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * management probe request frame prefix  * note: no static parameters, only variable length  */
end_comment

begin_comment
comment|/*  * management probe response frame prefix  */
end_comment

begin_struct
struct|struct
name|wi_mgmt_proberesp_hdr
block|{
name|u_int32_t
name|wi_ts0
decl_stmt|;
name|u_int32_t
name|wi_ts1
decl_stmt|;
name|u_int16_t
name|wi_interval
decl_stmt|;
name|u_int16_t
name|wi_capinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * management authentication frame prefix  */
end_comment

begin_struct
struct|struct
name|wi_mgmt_auth_hdr
block|{
name|u_int16_t
name|wi_algo
decl_stmt|;
name|u_int16_t
name|wi_seq
decl_stmt|;
name|u_int16_t
name|wi_status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * management deauthentication frame  */
end_comment

begin_struct
struct|struct
name|wi_mgmt_deauth_hdr
block|{
name|u_int16_t
name|wi_reason
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * rid configuration register definitions  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_SCAN_REQ
value|0xFCE1
end_define

begin_comment
comment|/* scan request information */
end_comment

begin_define
define|#
directive|define
name|WI_RID_SCAN_RES
value|0xFD88
end_define

begin_comment
comment|/* scan result information */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PROCFRAME
value|0x3137
end_define

begin_comment
comment|/* Return full frame information */
end_comment

begin_define
define|#
directive|define
name|WI_RID_PRISM2
value|0x3138
end_define

begin_comment
comment|/* tell if we're a prism2 card or not */
end_comment

begin_comment
comment|/*  * 802.11 definitions  */
end_comment

begin_define
define|#
directive|define
name|WI_STAT_BADCRC
value|0x0001
end_define

begin_define
define|#
directive|define
name|WI_STAT_UNDECRYPTABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|WI_STAT_ERRSTAT
value|0x0003
end_define

begin_define
define|#
directive|define
name|WI_STAT_MAC_PORT
value|0x0700
end_define

begin_define
define|#
directive|define
name|WI_STAT_1042
value|0x2000
end_define

begin_define
define|#
directive|define
name|WI_STAT_TUNNEL
value|0x4000
end_define

begin_define
define|#
directive|define
name|WI_STAT_WMP_MSG
value|0x6000
end_define

begin_define
define|#
directive|define
name|WI_RXSTAT_MSG_TYPE
value|0xE000
end_define

begin_define
define|#
directive|define
name|WI_FCTL_OPT_MASK
value|0xFF00
end_define

begin_define
define|#
directive|define
name|WI_AID_SET
value|0xC000
end_define

begin_define
define|#
directive|define
name|WI_AID_MASK
value|0x3FFF
end_define

begin_define
define|#
directive|define
name|WI_SCTL_FRAGNUM_MASK
value|0x000F
end_define

begin_define
define|#
directive|define
name|WI_SCTL_SEQNUM_MASK
value|0xFFF0
end_define

begin_define
define|#
directive|define
name|WI_STAT_UNSPEC_FAIL
value|1
end_define

begin_define
define|#
directive|define
name|WI_STAT_CAPINFO_FAIL
value|10
end_define

begin_define
define|#
directive|define
name|WI_STAT_REAS_DENY
value|11
end_define

begin_define
define|#
directive|define
name|WI_STAT_ASSOC_DENY
value|12
end_define

begin_define
define|#
directive|define
name|WI_STAT_ALGO_FAIL
value|13
end_define

begin_define
define|#
directive|define
name|WI_STAT_SEQ_FAIL
value|14
end_define

begin_define
define|#
directive|define
name|WI_STAT_CHAL_FAIL
value|15
end_define

begin_define
define|#
directive|define
name|WI_STAT_TOUT_FAIL
value|16
end_define

begin_define
define|#
directive|define
name|WI_STAT_OVERL_DENY
value|17
end_define

begin_define
define|#
directive|define
name|WI_STAT_RATE_DENY
value|18
end_define

begin_define
define|#
directive|define
name|WI_FTYPE_MGMT
value|0x0000
end_define

begin_define
define|#
directive|define
name|WI_FTYPE_CTL
value|0x0004
end_define

begin_define
define|#
directive|define
name|WI_FTYPE_DATA
value|0x0008
end_define

begin_define
define|#
directive|define
name|WI_FCTL_VERS
value|0x0002
end_define

begin_define
define|#
directive|define
name|WI_FCTL_FTYPE
value|0x000C
end_define

begin_define
define|#
directive|define
name|WI_FCTL_STYPE
value|0x00F0
end_define

begin_define
define|#
directive|define
name|WI_FCTL_TODS
value|0x0100
end_define

begin_define
define|#
directive|define
name|WI_FCTL_FROMDS
value|0x0200
end_define

begin_define
define|#
directive|define
name|WI_FCTL_MOREFRAGS
value|0x0400
end_define

begin_define
define|#
directive|define
name|WI_FCTL_RETRY
value|0x0800
end_define

begin_define
define|#
directive|define
name|WI_FCTL_PM
value|0x1000
end_define

begin_define
define|#
directive|define
name|WI_FCTL_MOREDATA
value|0x2000
end_define

begin_define
define|#
directive|define
name|WI_FCTL_WEP
value|0x4000
end_define

begin_define
define|#
directive|define
name|WI_FCTL_ORDER
value|0x8000
end_define

begin_define
define|#
directive|define
name|WI_FCS_LEN
value|0x4
end_define

begin_comment
comment|/* checksum length */
end_comment

begin_comment
comment|/*  * management definitions  */
end_comment

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_ASREQ
value|0x0000
end_define

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_ASRESP
value|0x0010
end_define

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_REASREQ
value|0x0020
end_define

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_REASRESP
value|0x0030
end_define

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_PROBEREQ
value|0x0040
end_define

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_PROBERESP
value|0x0050
end_define

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_BEACON
value|0x0080
end_define

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_ATIM
value|0x0090
end_define

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_DISAS
value|0x00A0
end_define

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_AUTH
value|0x00B0
end_define

begin_define
define|#
directive|define
name|WI_STYPE_MGMT_DEAUTH
value|0x00C0
end_define

begin_define
define|#
directive|define
name|WI_CAPINFO_ESS
value|0x01
end_define

begin_define
define|#
directive|define
name|WI_CAPINFO_IBSS
value|0x02
end_define

begin_define
define|#
directive|define
name|WI_CAPINFO_CFPOLL
value|0x04
end_define

begin_define
define|#
directive|define
name|WI_CAPINFO_CFPOLLREQ
value|0x08
end_define

begin_define
define|#
directive|define
name|WI_CAPINFO_PRIV
value|0x10
end_define

begin_define
define|#
directive|define
name|WI_REASON_UNSPEC
value|1
end_define

begin_define
define|#
directive|define
name|WI_REASON_AUTH_INVALID
value|2
end_define

begin_define
define|#
directive|define
name|WI_REASON_DEAUTH_LEAVE
value|3
end_define

begin_define
define|#
directive|define
name|WI_REASON_DISAS_INACT
value|4
end_define

begin_define
define|#
directive|define
name|WI_REASON_DISAS_OVERL
value|5
end_define

begin_define
define|#
directive|define
name|WI_REASON_CLASS2
value|6
end_define

begin_define
define|#
directive|define
name|WI_REASON_CLASS3
value|7
end_define

begin_define
define|#
directive|define
name|WI_REASON_DISAS_LEAVE
value|8
end_define

begin_define
define|#
directive|define
name|WI_REASON_NOAUTH
value|9
end_define

begin_define
define|#
directive|define
name|WI_VAR_SSID
value|0
end_define

begin_define
define|#
directive|define
name|WI_VAR_SRATES
value|1
end_define

begin_define
define|#
directive|define
name|WI_VAR_FH
value|2
end_define

begin_define
define|#
directive|define
name|WI_VAR_DS
value|3
end_define

begin_define
define|#
directive|define
name|WI_VAR_CF
value|4
end_define

begin_define
define|#
directive|define
name|WI_VAR_TIM
value|5
end_define

begin_define
define|#
directive|define
name|WI_VAR_IBSS
value|6
end_define

begin_define
define|#
directive|define
name|WI_VAR_CHAL
value|16
end_define

begin_define
define|#
directive|define
name|WI_VAR_SRATES_MASK
value|0x7F
end_define

begin_comment
comment|/*  * control definitions  */
end_comment

begin_define
define|#
directive|define
name|WI_STYPE_CTL_PSPOLL
value|0x00A0
end_define

begin_define
define|#
directive|define
name|WI_STYPE_CTL_RTS
value|0x00B0
end_define

begin_define
define|#
directive|define
name|WI_STYPE_CTL_CTS
value|0x00C0
end_define

begin_define
define|#
directive|define
name|WI_STYPE_CTL_ACK
value|0x00D0
end_define

begin_define
define|#
directive|define
name|WI_STYPE_CTL_CFEND
value|0x00E0
end_define

begin_define
define|#
directive|define
name|WI_STYPE_CTL_CFENDCFACK
value|0x00F0
end_define

begin_comment
comment|/*  * ap scanning structures  */
end_comment

begin_struct
struct|struct
name|wi_scan_res
block|{
name|u_int16_t
name|wi_chan
decl_stmt|;
name|u_int16_t
name|wi_noise
decl_stmt|;
name|u_int16_t
name|wi_signal
decl_stmt|;
name|u_int8_t
name|wi_bssid
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|wi_interval
decl_stmt|;
name|u_int16_t
name|wi_capinfo
decl_stmt|;
name|u_int16_t
name|wi_ssid_len
decl_stmt|;
name|u_int8_t
name|wi_ssid
index|[
literal|32
index|]
decl_stmt|;
name|u_int8_t
name|wi_srates
index|[
literal|10
index|]
decl_stmt|;
name|u_int8_t
name|wi_rate
decl_stmt|;
name|u_int8_t
name|wi_rsvd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WI_WAVELAN_RES_SIZE
value|50
end_define

begin_struct
struct|struct
name|wi_scan_p2_hdr
block|{
name|u_int16_t
name|wi_rsvd
decl_stmt|;
name|u_int16_t
name|wi_reason
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WI_PRISM2_RES_SIZE
value|62
end_define

begin_comment
comment|/*  * prism2 debug mode definitions  */
end_comment

begin_define
define|#
directive|define
name|SIOCSPRISM2DEBUG
value|_IOW('i', 137, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGPRISM2DEBUG
value|_IOWR('i', 138, struct ifreq)
end_define

begin_define
define|#
directive|define
name|WI_CMD_DEBUG
value|0x0038
end_define

begin_comment
comment|/* prism2 debug */
end_comment

begin_define
define|#
directive|define
name|WI_DEBUG_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_INIT
value|0x01
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_SLEEP
value|0x02
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_WAKE
value|0x03
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_CHAN
value|0x08
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_DELAYSUPP
value|0x09
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_TXSUPP
value|0x0A
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_MONITOR
value|0x0B
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_LEDTEST
value|0x0C
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_CONTTX
value|0x0E
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_STOPTEST
value|0x0F
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_CONTRX
value|0x10
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_SIGSTATE
value|0x11
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_CALENABLE
value|0x13
end_define

begin_define
define|#
directive|define
name|WI_DEBUG_CONFBITS
value|0x15
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

