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

begin_ifdef
ifdef|#
directive|ifdef
name|WICACHE
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|WICACHE
end_ifdef

begin_define
define|#
directive|define
name|MAXWICACHE
value|10
end_define

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

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * These are all the LTV record types that we can read or write  * from the WaveLAN. Not all of them are temendously useful, but I  * list as many as I know about here for completeness.  */
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

begin_define
define|#
directive|define
name|WI_RID_DOMAINS
value|0xFD11
end_define

begin_define
define|#
directive|define
name|WI_RID_CIS
value|0xFD13
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
comment|/* data rate for message xmit */
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
name|WI_RID_FIRM_ID
value|0xFD02
end_define

begin_comment
comment|/* Primary func firmware ID. */
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
name|WI_RID_CFI_ACT_RANGE
value|0xFD33
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

