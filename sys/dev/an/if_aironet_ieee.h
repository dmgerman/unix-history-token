begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_AIRONET_IEEE_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_AIRONET_IEEE_H
end_define

begin_comment
comment|/*  * This header defines a simple command interface to the FreeBSD  * Aironet driver (an) driver, which is used to set certain  * device-specific parameters which can't be easily managed through  * ifconfig(8). No, sysctl(2) is not the answer. I said a _simple_  * interface, didn't I.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIOCSAIRONET
end_ifndef

begin_define
define|#
directive|define
name|SIOCSAIRONET
value|SIOCSIFGENERIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIOCGAIRONET
end_ifndef

begin_define
define|#
directive|define
name|SIOCGAIRONET
value|SIOCGIFGENERIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is a make-predend RID value used only by the driver  * to allow the user to set the speed.  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_TX_SPEED
value|0x1234
end_define

begin_comment
comment|/*  * Technically I don't think there's a limit to a record  * length. The largest record is the one that contains the CIS  * data, which is 240 words long, so 256 should be a safe  * value.  */
end_comment

begin_define
define|#
directive|define
name|AN_MAX_DATALEN
value|512
end_define

begin_struct
struct|struct
name|an_req
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int16_t
name|an_val
index|[
name|AN_MAX_DATALEN
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
name|AN_RID_IFACE_STATS
value|0x0100
end_define

begin_define
define|#
directive|define
name|AN_RID_MGMT_XMIT
value|0x0200
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ANCACHE
end_ifdef

begin_define
define|#
directive|define
name|AN_RID_ZERO_CACHE
value|0x0300
end_define

begin_define
define|#
directive|define
name|AN_RID_READ_CACHE
value|0x0400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AN_FCTL_VERS
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_FCTL_FTYPE
value|0x000C
end_define

begin_define
define|#
directive|define
name|AN_FCTL_STYPE
value|0x00F0
end_define

begin_define
define|#
directive|define
name|AN_FCTL_TODS
value|0x0100
end_define

begin_define
define|#
directive|define
name|AN_FCTL_FROMDS
value|0x0200
end_define

begin_define
define|#
directive|define
name|AN_FCTL_MOREFRAGS
value|0x0400
end_define

begin_define
define|#
directive|define
name|AN_FCTL_RETRY
value|0x0800
end_define

begin_define
define|#
directive|define
name|AN_FCTL_PM
value|0x1000
end_define

begin_define
define|#
directive|define
name|AN_FCTL_MOREDATA
value|0x2000
end_define

begin_define
define|#
directive|define
name|AN_FCTL_WEP
value|0x4000
end_define

begin_define
define|#
directive|define
name|AN_FCTL_ORDER
value|0x8000
end_define

begin_define
define|#
directive|define
name|AN_FTYPE_MGMT
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_FTYPE_CTL
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_FTYPE_DATA
value|0x0008
end_define

begin_define
define|#
directive|define
name|AN_STYPE_MGMT_ASREQ
value|0x0000
end_define

begin_comment
comment|/* association request */
end_comment

begin_define
define|#
directive|define
name|AN_STYPE_MGMT_ASRESP
value|0x0010
end_define

begin_comment
comment|/* association response */
end_comment

begin_define
define|#
directive|define
name|AN_STYPE_MGMT_REASREQ
value|0x0020
end_define

begin_comment
comment|/* reassociation request */
end_comment

begin_define
define|#
directive|define
name|AN_STYPE_MGMT_REASRESP
value|0x0030
end_define

begin_comment
comment|/* reassociation response */
end_comment

begin_define
define|#
directive|define
name|AN_STYPE_MGMT_PROBEREQ
value|0x0040
end_define

begin_comment
comment|/* probe request */
end_comment

begin_define
define|#
directive|define
name|AN_STYPE_MGMT_PROBERESP
value|0x0050
end_define

begin_comment
comment|/* probe response */
end_comment

begin_define
define|#
directive|define
name|AN_STYPE_MGMT_BEACON
value|0x0080
end_define

begin_comment
comment|/* beacon */
end_comment

begin_define
define|#
directive|define
name|AN_STYPE_MGMT_ATIM
value|0x0090
end_define

begin_comment
comment|/* announcement traffic ind msg */
end_comment

begin_define
define|#
directive|define
name|AN_STYPE_MGMT_DISAS
value|0x00A0
end_define

begin_comment
comment|/* disassociation */
end_comment

begin_define
define|#
directive|define
name|AN_STYPE_MGMT_AUTH
value|0x00B0
end_define

begin_comment
comment|/* authentication */
end_comment

begin_define
define|#
directive|define
name|AN_STYPE_MGMT_DEAUTH
value|0x00C0
end_define

begin_comment
comment|/* deauthentication */
end_comment

begin_comment
comment|/*  * Aironet IEEE signal strength cache  *  * driver keeps cache of last  * MAXANCACHE packets to arrive including signal strength info.  * daemons may read this via ioctl  *  * Each entry in the wi_sigcache has a unique macsrc.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ANCACHE
end_ifdef

begin_define
define|#
directive|define
name|MAXANCACHE
value|10
end_define

begin_struct
struct|struct
name|an_sigcache
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

begin_struct
struct|struct
name|an_ltv_key
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int16_t
name|kindex
decl_stmt|;
name|u_int8_t
name|mac
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|klen
decl_stmt|;
name|u_int8_t
name|key
index|[
literal|16
index|]
decl_stmt|;
comment|/* 128-bit keys */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|an_ltv_stats
block|{
name|u_int16_t
name|an_fudge
decl_stmt|;
name|u_int16_t
name|an_len
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_type
decl_stmt|;
comment|/* 0xXX */
name|u_int16_t
name|an_spacer
decl_stmt|;
comment|/* 0x02 */
name|u_int32_t
name|an_rx_overruns
decl_stmt|;
comment|/* 0x04 */
name|u_int32_t
name|an_rx_plcp_csum_errs
decl_stmt|;
comment|/* 0x08 */
name|u_int32_t
name|an_rx_plcp_format_errs
decl_stmt|;
comment|/* 0x0C */
name|u_int32_t
name|an_rx_plcp_len_errs
decl_stmt|;
comment|/* 0x10 */
name|u_int32_t
name|an_rx_mac_crc_errs
decl_stmt|;
comment|/* 0x14 */
name|u_int32_t
name|an_rx_mac_crc_ok
decl_stmt|;
comment|/* 0x18 */
name|u_int32_t
name|an_rx_wep_errs
decl_stmt|;
comment|/* 0x1C */
name|u_int32_t
name|an_rx_wep_ok
decl_stmt|;
comment|/* 0x20 */
name|u_int32_t
name|an_retry_long
decl_stmt|;
comment|/* 0x24 */
name|u_int32_t
name|an_retry_short
decl_stmt|;
comment|/* 0x28 */
name|u_int32_t
name|an_retry_max
decl_stmt|;
comment|/* 0x2C */
name|u_int32_t
name|an_no_ack
decl_stmt|;
comment|/* 0x30 */
name|u_int32_t
name|an_no_cts
decl_stmt|;
comment|/* 0x34 */
name|u_int32_t
name|an_rx_ack_ok
decl_stmt|;
comment|/* 0x38 */
name|u_int32_t
name|an_rx_cts_ok
decl_stmt|;
comment|/* 0x3C */
name|u_int32_t
name|an_tx_ack_ok
decl_stmt|;
comment|/* 0x40 */
name|u_int32_t
name|an_tx_rts_ok
decl_stmt|;
comment|/* 0x44 */
name|u_int32_t
name|an_tx_cts_ok
decl_stmt|;
comment|/* 0x48 */
name|u_int32_t
name|an_tx_lmac_mcasts
decl_stmt|;
comment|/* 0x4C */
name|u_int32_t
name|an_tx_lmac_bcasts
decl_stmt|;
comment|/* 0x50 */
name|u_int32_t
name|an_tx_lmac_ucast_frags
decl_stmt|;
comment|/* 0x54 */
name|u_int32_t
name|an_tx_lmac_ucasts
decl_stmt|;
comment|/* 0x58 */
name|u_int32_t
name|an_tx_beacons
decl_stmt|;
comment|/* 0x5C */
name|u_int32_t
name|an_rx_beacons
decl_stmt|;
comment|/* 0x60 */
name|u_int32_t
name|an_tx_single_cols
decl_stmt|;
comment|/* 0x64 */
name|u_int32_t
name|an_tx_multi_cols
decl_stmt|;
comment|/* 0x68 */
name|u_int32_t
name|an_tx_defers_no
decl_stmt|;
comment|/* 0x6C */
name|u_int32_t
name|an_tx_defers_prot
decl_stmt|;
comment|/* 0x70 */
name|u_int32_t
name|an_tx_defers_energy
decl_stmt|;
comment|/* 0x74 */
name|u_int32_t
name|an_rx_dups
decl_stmt|;
comment|/* 0x78 */
name|u_int32_t
name|an_rx_partial
decl_stmt|;
comment|/* 0x7C */
name|u_int32_t
name|an_tx_too_old
decl_stmt|;
comment|/* 0x80 */
name|u_int32_t
name|an_rx_too_old
decl_stmt|;
comment|/* 0x84 */
name|u_int32_t
name|an_lostsync_max_retries
decl_stmt|;
comment|/* 0x88 */
name|u_int32_t
name|an_lostsync_missed_beacons
decl_stmt|;
comment|/* 0x8C */
name|u_int32_t
name|an_lostsync_arl_exceeded
decl_stmt|;
comment|/*0x90 */
name|u_int32_t
name|an_lostsync_deauthed
decl_stmt|;
comment|/* 0x94 */
name|u_int32_t
name|an_lostsync_disassociated
decl_stmt|;
comment|/*0x98 */
name|u_int32_t
name|an_lostsync_tsf_timing
decl_stmt|;
comment|/* 0x9C */
name|u_int32_t
name|an_tx_host_mcasts
decl_stmt|;
comment|/* 0xA0 */
name|u_int32_t
name|an_tx_host_bcasts
decl_stmt|;
comment|/* 0xA4 */
name|u_int32_t
name|an_tx_host_ucasts
decl_stmt|;
comment|/* 0xA8 */
name|u_int32_t
name|an_tx_host_failed
decl_stmt|;
comment|/* 0xAC */
name|u_int32_t
name|an_rx_host_mcasts
decl_stmt|;
comment|/* 0xB0 */
name|u_int32_t
name|an_rx_host_bcasts
decl_stmt|;
comment|/* 0xB4 */
name|u_int32_t
name|an_rx_host_ucasts
decl_stmt|;
comment|/* 0xB8 */
name|u_int32_t
name|an_rx_host_discarded
decl_stmt|;
comment|/* 0xBC */
name|u_int32_t
name|an_tx_hmac_mcasts
decl_stmt|;
comment|/* 0xC0 */
name|u_int32_t
name|an_tx_hmac_bcasts
decl_stmt|;
comment|/* 0xC4 */
name|u_int32_t
name|an_tx_hmac_ucasts
decl_stmt|;
comment|/* 0xC8 */
name|u_int32_t
name|an_tx_hmac_failed
decl_stmt|;
comment|/* 0xCC */
name|u_int32_t
name|an_rx_hmac_mcasts
decl_stmt|;
comment|/* 0xD0 */
name|u_int32_t
name|an_rx_hmac_bcasts
decl_stmt|;
comment|/* 0xD4 */
name|u_int32_t
name|an_rx_hmac_ucasts
decl_stmt|;
comment|/* 0xD8 */
name|u_int32_t
name|an_rx_hmac_discarded
decl_stmt|;
comment|/* 0xDC */
name|u_int32_t
name|an_tx_hmac_accepted
decl_stmt|;
comment|/* 0xE0 */
name|u_int32_t
name|an_ssid_mismatches
decl_stmt|;
comment|/* 0xE4 */
name|u_int32_t
name|an_ap_mismatches
decl_stmt|;
comment|/* 0xE8 */
name|u_int32_t
name|an_rates_mismatches
decl_stmt|;
comment|/* 0xEC */
name|u_int32_t
name|an_auth_rejects
decl_stmt|;
comment|/* 0xF0 */
name|u_int32_t
name|an_auth_timeouts
decl_stmt|;
comment|/* 0xF4 */
name|u_int32_t
name|an_assoc_rejects
decl_stmt|;
comment|/* 0xF8 */
name|u_int32_t
name|an_assoc_timeouts
decl_stmt|;
comment|/* 0xFC */
name|u_int32_t
name|an_reason_outside_table
decl_stmt|;
comment|/* 0x100 */
name|u_int32_t
name|an_reason1
decl_stmt|;
comment|/* 0x104 */
name|u_int32_t
name|an_reason2
decl_stmt|;
comment|/* 0x108 */
name|u_int32_t
name|an_reason3
decl_stmt|;
comment|/* 0x10C */
name|u_int32_t
name|an_reason4
decl_stmt|;
comment|/* 0x110 */
name|u_int32_t
name|an_reason5
decl_stmt|;
comment|/* 0x114 */
name|u_int32_t
name|an_reason6
decl_stmt|;
comment|/* 0x118 */
name|u_int32_t
name|an_reason7
decl_stmt|;
comment|/* 0x11C */
name|u_int32_t
name|an_reason8
decl_stmt|;
comment|/* 0x120 */
name|u_int32_t
name|an_reason9
decl_stmt|;
comment|/* 0x124 */
name|u_int32_t
name|an_reason10
decl_stmt|;
comment|/* 0x128 */
name|u_int32_t
name|an_reason11
decl_stmt|;
comment|/* 0x12C */
name|u_int32_t
name|an_reason12
decl_stmt|;
comment|/* 0x130 */
name|u_int32_t
name|an_reason13
decl_stmt|;
comment|/* 0x134 */
name|u_int32_t
name|an_reason14
decl_stmt|;
comment|/* 0x138 */
name|u_int32_t
name|an_reason15
decl_stmt|;
comment|/* 0x13C */
name|u_int32_t
name|an_reason16
decl_stmt|;
comment|/* 0x140 */
name|u_int32_t
name|an_reason17
decl_stmt|;
comment|/* 0x144 */
name|u_int32_t
name|an_reason18
decl_stmt|;
comment|/* 0x148 */
name|u_int32_t
name|an_reason19
decl_stmt|;
comment|/* 0x14C */
name|u_int32_t
name|an_rx_mgmt_pkts
decl_stmt|;
comment|/* 0x150 */
name|u_int32_t
name|an_tx_mgmt_pkts
decl_stmt|;
comment|/* 0x154 */
name|u_int32_t
name|an_rx_refresh_pkts
decl_stmt|;
comment|/* 0x158 */
name|u_int32_t
name|an_tx_refresh_pkts
decl_stmt|;
comment|/* 0x15C */
name|u_int32_t
name|an_rx_poll_pkts
decl_stmt|;
comment|/* 0x160 */
name|u_int32_t
name|an_tx_poll_pkts
decl_stmt|;
comment|/* 0x164 */
name|u_int32_t
name|an_host_retries
decl_stmt|;
comment|/* 0x168 */
name|u_int32_t
name|an_lostsync_hostreq
decl_stmt|;
comment|/* 0x16C */
name|u_int32_t
name|an_host_tx_bytes
decl_stmt|;
comment|/* 0x170 */
name|u_int32_t
name|an_host_rx_bytes
decl_stmt|;
comment|/* 0x174 */
name|u_int32_t
name|an_uptime_usecs
decl_stmt|;
comment|/* 0x178 */
name|u_int32_t
name|an_uptime_secs
decl_stmt|;
comment|/* 0x17C */
name|u_int32_t
name|an_lostsync_better_ap
decl_stmt|;
comment|/* 0x180 */
name|u_int32_t
name|an_rsvd
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * General configuration information.  */
end_comment

begin_struct
struct|struct
name|an_ltv_genconfig
block|{
comment|/* General configuration. */
name|u_int16_t
name|an_len
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_type
decl_stmt|;
comment|/* XXXX */
name|u_int16_t
name|an_opmode
decl_stmt|;
comment|/* 0x02 */
name|u_int16_t
name|an_rxmode
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|an_fragthresh
decl_stmt|;
comment|/* 0x06 */
name|u_int16_t
name|an_rtsthresh
decl_stmt|;
comment|/* 0x08 */
name|u_int8_t
name|an_macaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x0A */
name|u_int8_t
name|an_rates
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x10 */
name|u_int16_t
name|an_shortretry_limit
decl_stmt|;
comment|/* 0x18 */
name|u_int16_t
name|an_longretry_limit
decl_stmt|;
comment|/* 0x1A */
name|u_int16_t
name|an_tx_msdu_lifetime
decl_stmt|;
comment|/* 0x1C */
name|u_int16_t
name|an_rx_msdu_lifetime
decl_stmt|;
comment|/* 0x1E */
name|u_int16_t
name|an_stationary
decl_stmt|;
comment|/* 0x20 */
name|u_int16_t
name|an_ordering
decl_stmt|;
comment|/* 0x22 */
name|u_int16_t
name|an_devtype
decl_stmt|;
comment|/* 0x24 */
name|u_int16_t
name|an_rsvd0
index|[
literal|5
index|]
decl_stmt|;
comment|/* 0x26 */
comment|/* Scanning associating. */
name|u_int16_t
name|an_scanmode
decl_stmt|;
comment|/* 0x30 */
name|u_int16_t
name|an_probedelay
decl_stmt|;
comment|/* 0x32 */
name|u_int16_t
name|an_probe_energy_timeout
decl_stmt|;
comment|/* 0x34 */
name|u_int16_t
name|an_probe_response_timeout
decl_stmt|;
comment|/*0x36 */
name|u_int16_t
name|an_beacon_listen_timeout
decl_stmt|;
comment|/*0x38 */
name|u_int16_t
name|an_ibss_join_net_timeout
decl_stmt|;
comment|/*0x3A */
name|u_int16_t
name|an_auth_timeout
decl_stmt|;
comment|/* 0x3C */
name|u_int16_t
name|an_authtype
decl_stmt|;
comment|/* 0x3E */
name|u_int16_t
name|an_assoc_timeout
decl_stmt|;
comment|/* 0x40 */
name|u_int16_t
name|an_specified_ap_timeout
decl_stmt|;
comment|/* 0x42 */
name|u_int16_t
name|an_offline_scan_interval
decl_stmt|;
comment|/*0x44 */
name|u_int16_t
name|an_offline_scan_duration
decl_stmt|;
comment|/*0x46 */
name|u_int16_t
name|an_link_loss_delay
decl_stmt|;
comment|/* 0x48 */
name|u_int16_t
name|an_max_beacon_lost_time
decl_stmt|;
comment|/* 0x4A */
name|u_int16_t
name|an_refresh_interval
decl_stmt|;
comment|/* 0x4C */
name|u_int16_t
name|an_rsvd1
decl_stmt|;
comment|/* 0x4E */
comment|/* Power save operation */
name|u_int16_t
name|an_psave_mode
decl_stmt|;
comment|/* 0x50 */
name|u_int16_t
name|an_sleep_for_dtims
decl_stmt|;
comment|/* 0x52 */
name|u_int16_t
name|an_listen_interval
decl_stmt|;
comment|/* 0x54 */
name|u_int16_t
name|an_fast_listen_interval
decl_stmt|;
comment|/* 0x56 */
name|u_int16_t
name|an_listen_decay
decl_stmt|;
comment|/* 0x58 */
name|u_int16_t
name|an_fast_listen_decay
decl_stmt|;
comment|/* 0x5A */
name|u_int16_t
name|an_rsvd2
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x5C */
comment|/* Ad-hoc (or AP) operation. */
name|u_int16_t
name|an_beacon_period
decl_stmt|;
comment|/* 0x60 */
name|u_int16_t
name|an_atim_duration
decl_stmt|;
comment|/* 0x62 */
name|u_int16_t
name|an_rsvd3
decl_stmt|;
comment|/* 0x64 */
name|u_int16_t
name|an_ds_channel
decl_stmt|;
comment|/* 0x66 */
name|u_int16_t
name|an_rsvd4
decl_stmt|;
comment|/* 0x68 */
name|u_int16_t
name|an_dtim_period
decl_stmt|;
comment|/* 0x6A */
name|u_int16_t
name|an_rsvd5
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x6C */
comment|/* Radio operation. */
name|u_int16_t
name|an_radiotype
decl_stmt|;
comment|/* 0x70 */
name|u_int16_t
name|an_diversity
decl_stmt|;
comment|/* 0x72 */
name|u_int16_t
name|an_tx_power
decl_stmt|;
comment|/* 0x74 */
name|u_int16_t
name|an_rss_thresh
decl_stmt|;
comment|/* 0x76 */
name|u_int16_t
name|an_modulation_type
decl_stmt|;
comment|/* 0x78 */
name|u_int16_t
name|an_short_preamble
decl_stmt|;
comment|/* 0x7A */
name|u_int16_t
name|an_home_product
decl_stmt|;
comment|/* 0x7C */
name|u_int16_t
name|an_rsvd6
decl_stmt|;
comment|/* 0x7E */
comment|/* Aironet extensions. */
name|u_int8_t
name|an_nodename
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x80 */
name|u_int16_t
name|an_arl_thresh
decl_stmt|;
comment|/* 0x90 */
name|u_int16_t
name|an_arl_decay
decl_stmt|;
comment|/* 0x92 */
name|u_int16_t
name|an_arl_delay
decl_stmt|;
comment|/* 0x94 */
name|u_int8_t
name|an_rsvd7
decl_stmt|;
comment|/* 0x96 */
name|u_int8_t
name|an_rsvd8
decl_stmt|;
comment|/* 0x97 */
name|u_int8_t
name|an_magic_packet_action
decl_stmt|;
comment|/* 0x98 */
name|u_int8_t
name|an_magic_packet_ctl
decl_stmt|;
comment|/* 0x99 */
name|u_int16_t
name|an_rsvd9
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_OPMODE_IBSS_ADHOC
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_OPMODE_INFRASTRUCTURE_STATION
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_OPMODE_AP
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_OPMODE_AP_REPEATER
value|0x0003
end_define

begin_define
define|#
directive|define
name|AN_OPMODE_UNMODIFIED_PAYLOAD
value|0x0100
end_define

begin_define
define|#
directive|define
name|AN_OPMODE_AIRONET_EXTENSIONS
value|0x0200
end_define

begin_define
define|#
directive|define
name|AN_OPMODE_AP_EXTENSIONS
value|0x0400
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_BC_MC_ADDR
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_BC_ADDR
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_ADDR
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_80211_MONITOR_CURBSS
value|0x0003
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_80211_MONITOR_ANYBSS
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_LAN_MONITOR_CURBSS
value|0x0005
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_NO_8023_HEADER
value|0x0100
end_define

begin_define
define|#
directive|define
name|AN_RATE_1MBPS
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_RATE_2MBPS
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_RATE_5_5MBPS
value|0x000B
end_define

begin_define
define|#
directive|define
name|AN_RATE_11MBPS
value|0x0016
end_define

begin_define
define|#
directive|define
name|AN_DEVTYPE_PC4500
value|0x0065
end_define

begin_define
define|#
directive|define
name|AN_DEVTYPE_PC4800
value|0x006D
end_define

begin_define
define|#
directive|define
name|AN_SCANMODE_ACTIVE
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_SCANMODE_PASSIVE
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_SCANMODE_AIRONET_ACTIVE
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_AUTHTYPE_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_AUTHTYPE_OPEN
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_AUTHTYPE_SHAREDKEY
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_AUTHTYPE_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|AN_AUTHTYPE_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|AN_AUTHTYPE_PRIVACY_IN_USE
value|0x0100
end_define

begin_define
define|#
directive|define
name|AN_AUTHTYPE_ALLOW_UNENCRYPTED
value|0x0200
end_define

begin_define
define|#
directive|define
name|AN_AUTHTYPE_LEAP
value|0x1000
end_define

begin_define
define|#
directive|define
name|AN_PSAVE_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_PSAVE_CAM
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_PSAVE_PSP
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_PSAVE_PSP_CAM
value|0x0003
end_define

begin_define
define|#
directive|define
name|AN_RADIOTYPE_80211_FH
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_RADIOTYPE_80211_DS
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_RADIOTYPE_LM2000_DS
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_DIVERSITY_FACTORY_DEFAULT
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_DIVERSITY_ANTENNA_1_ONLY
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_DIVERSITY_ANTENNA_2_ONLY
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_DIVERSITY_ANTENNA_1_AND_2
value|0x0003
end_define

begin_define
define|#
directive|define
name|AN_TXPOWER_FACTORY_DEFAULT
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_TXPOWER_50MW
value|50
end_define

begin_define
define|#
directive|define
name|AN_TXPOWER_100MW
value|100
end_define

begin_define
define|#
directive|define
name|AN_TXPOWER_250MW
value|250
end_define

begin_define
define|#
directive|define
name|AN_HOME_NETWORK
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_HOME_INSTALL_AP
value|0x0002
end_define

begin_comment
comment|/*  * Valid SSID list. You can specify up to three SSIDs denoting  * the service sets that you want to join. The first SSID always  * defaults to "tsunami" which is a handy way to detect the  * card.  */
end_comment

begin_struct
struct|struct
name|an_ltv_ssidlist
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int16_t
name|an_ssid1_len
decl_stmt|;
name|char
name|an_ssid1
index|[
literal|32
index|]
decl_stmt|;
name|u_int16_t
name|an_ssid2_len
decl_stmt|;
name|char
name|an_ssid2
index|[
literal|32
index|]
decl_stmt|;
name|u_int16_t
name|an_ssid3_len
decl_stmt|;
name|char
name|an_ssid3
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Valid AP list.  */
end_comment

begin_struct
struct|struct
name|an_ltv_aplist
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int8_t
name|an_ap1
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|an_ap2
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|an_ap3
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|an_ap4
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Driver name.  */
end_comment

begin_struct
struct|struct
name|an_ltv_drvname
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int8_t
name|an_drvname
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Frame encapsulation.  */
end_comment

begin_struct
struct|struct
name|an_rid_encap
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int16_t
name|an_ethertype_default
decl_stmt|;
name|u_int16_t
name|an_action_default
decl_stmt|;
name|u_int16_t
name|an_ethertype0
decl_stmt|;
name|u_int16_t
name|an_action0
decl_stmt|;
name|u_int16_t
name|an_ethertype1
decl_stmt|;
name|u_int16_t
name|an_action1
decl_stmt|;
name|u_int16_t
name|an_ethertype2
decl_stmt|;
name|u_int16_t
name|an_action2
decl_stmt|;
name|u_int16_t
name|an_ethertype3
decl_stmt|;
name|u_int16_t
name|an_action3
decl_stmt|;
name|u_int16_t
name|an_ethertype4
decl_stmt|;
name|u_int16_t
name|an_action4
decl_stmt|;
name|u_int16_t
name|an_ethertype5
decl_stmt|;
name|u_int16_t
name|an_action5
decl_stmt|;
name|u_int16_t
name|an_ethertype6
decl_stmt|;
name|u_int16_t
name|an_action6
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_ENCAP_ACTION_RX
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_ENCAP_ACTION_TX
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_RXENCAP_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_RXENCAP_RFC1024
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_TXENCAP_RFC1024
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_TXENCAP_80211
value|0x0002
end_define

begin_comment
comment|/*  * Card capabilities (read only).  */
end_comment

begin_struct
struct|struct
name|an_ltv_caps
block|{
name|u_int16_t
name|an_len
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_type
decl_stmt|;
comment|/* XXXX */
name|u_int8_t
name|an_oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x02 */
name|u_int8_t
name|an_rsvd0
decl_stmt|;
comment|/* 0x05 */
name|u_int16_t
name|an_prodnum
decl_stmt|;
comment|/* 0x06 */
name|u_int8_t
name|an_manufname
index|[
literal|32
index|]
decl_stmt|;
comment|/* 0x08 */
name|u_int8_t
name|an_prodname
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x28 */
name|u_int8_t
name|an_prodvers
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x38 */
name|u_int8_t
name|an_oemaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x40 */
name|u_int8_t
name|an_aironetaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x46 */
name|u_int16_t
name|an_radiotype
decl_stmt|;
comment|/* 0x4C */
name|u_int16_t
name|an_regdomain
decl_stmt|;
comment|/* 0x4E */
name|u_int8_t
name|an_callid
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x50 */
name|u_int8_t
name|an_rates
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x56 */
name|u_int8_t
name|an_rx_diversity
decl_stmt|;
comment|/* 0x5E */
name|u_int8_t
name|an_tx_diversity
decl_stmt|;
comment|/* 0x5F */
name|u_int16_t
name|an_tx_powerlevels
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x60 */
name|u_int16_t
name|an_hwrev
decl_stmt|;
comment|/* 0x70 */
name|u_int16_t
name|an_hwcaps
decl_stmt|;
comment|/* 0x72 */
name|u_int16_t
name|an_temprange
decl_stmt|;
comment|/* 0x74 */
name|u_int16_t
name|an_fwrev
decl_stmt|;
comment|/* 0x76 */
name|u_int16_t
name|an_fwsubrev
decl_stmt|;
comment|/* 0x78 */
name|u_int16_t
name|an_ifacerev
decl_stmt|;
comment|/* 0x7A */
name|u_int16_t
name|an_softcaps
decl_stmt|;
comment|/* 0x7C */
name|u_int16_t
name|an_bootblockrev
decl_stmt|;
comment|/* 0x7E */
name|u_int16_t
name|an_req_hw_support
decl_stmt|;
comment|/* 0x80 */
name|u_int16_t
name|an_unknown
decl_stmt|;
comment|/* 0x82 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Access point (read only)  */
end_comment

begin_struct
struct|struct
name|an_ltv_apinfo
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int16_t
name|an_tim_addr
decl_stmt|;
name|u_int16_t
name|an_airo_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Radio info (read only).  */
end_comment

begin_struct
struct|struct
name|an_ltv_radioinfo
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
comment|/* ??? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Status (read only). Note: the manual claims this RID is 108 bytes  * long (0x6A is the last datum, which is 2 bytes long) however when  * this RID is read from the NIC, it returns a length of 110. To be  * on the safe side, this structure is padded with an extra 16-bit  * word. (There is a misprint in the manual which says the macaddr  * field is 8 bytes long.)  *  * Also, the channel_set and current_channel fields appear to be  * reversed. Either that, or the hop_period field is unused.  */
end_comment

begin_struct
struct|struct
name|an_ltv_status
block|{
name|u_int16_t
name|an_len
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_type
decl_stmt|;
comment|/* 0xXX */
name|u_int8_t
name|an_macaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x02 */
name|u_int16_t
name|an_opmode
decl_stmt|;
comment|/* 0x08 */
name|u_int16_t
name|an_errcode
decl_stmt|;
comment|/* 0x0A */
name|u_int16_t
name|an_cur_signal_strength
decl_stmt|;
comment|/* 0x0C */
name|u_int16_t
name|an_ssidlen
decl_stmt|;
comment|/* 0x0E */
name|u_int8_t
name|an_ssid
index|[
literal|32
index|]
decl_stmt|;
comment|/* 0x10 */
name|u_int8_t
name|an_ap_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x30 */
name|u_int8_t
name|an_cur_bssid
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x40 */
name|u_int8_t
name|an_prev_bssid1
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x46 */
name|u_int8_t
name|an_prev_bssid2
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x4C */
name|u_int8_t
name|an_prev_bssid3
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x52 */
name|u_int16_t
name|an_beacon_period
decl_stmt|;
comment|/* 0x58 */
name|u_int16_t
name|an_dtim_period
decl_stmt|;
comment|/* 0x5A */
name|u_int16_t
name|an_atim_duration
decl_stmt|;
comment|/* 0x5C */
name|u_int16_t
name|an_hop_period
decl_stmt|;
comment|/* 0x5E */
name|u_int16_t
name|an_cur_channel
decl_stmt|;
comment|/* 0x62 */
name|u_int16_t
name|an_channel_set
decl_stmt|;
comment|/* 0x60 */
name|u_int16_t
name|an_hops_to_backbone
decl_stmt|;
comment|/* 0x64 */
name|u_int16_t
name|an_ap_total_load
decl_stmt|;
comment|/* 0x66 */
name|u_int16_t
name|an_our_generated_load
decl_stmt|;
comment|/* 0x68 */
name|u_int16_t
name|an_accumulated_arl
decl_stmt|;
comment|/* 0x6A */
name|u_int16_t
name|an_cur_signal_quality
decl_stmt|;
comment|/* 0x6C */
name|u_int16_t
name|an_current_tx_rate
decl_stmt|;
comment|/* 0x6E */
name|u_int16_t
name|an_ap_device
decl_stmt|;
comment|/* 0x70 */
name|u_int16_t
name|an_normalized_rssi
decl_stmt|;
comment|/* 0x72 */
name|u_int16_t
name|an_short_pre_in_use
decl_stmt|;
comment|/* 0x74 */
name|u_int8_t
name|an_ap_ip_addr
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x76 */
name|u_int16_t
name|an_max_noise_prev_sec
decl_stmt|;
comment|/* 0x7A */
name|u_int16_t
name|an_avg_noise_prev_min
decl_stmt|;
comment|/* 0x7C */
name|u_int16_t
name|an_max_noise_prev_min
decl_stmt|;
comment|/* 0x7E */
name|u_int16_t
name|an_spare
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_STATUS_OPMODE_CONFIGURED
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_STATUS_OPMODE_MAC_ENABLED
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_STATUS_OPMODE_RX_ENABLED
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_STATUS_OPMODE_IN_SYNC
value|0x0010
end_define

begin_define
define|#
directive|define
name|AN_STATUS_OPMODE_ASSOCIATED
value|0x0020
end_define

begin_define
define|#
directive|define
name|AN_STATUS_OPMODE_LEAP
value|0x0040
end_define

begin_define
define|#
directive|define
name|AN_STATUS_OPMODE_ERROR
value|0x8000
end_define

begin_comment
comment|/*  * WEP Key  */
end_comment

begin_struct
struct|struct
name|an_ltv_wepkey
block|{
name|u_int16_t
name|an_len
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_type
decl_stmt|;
comment|/* 0xXX */
name|u_int16_t
name|an_key_index
decl_stmt|;
comment|/* 0x02 */
name|u_int8_t
name|an_mac_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|an_key_len
decl_stmt|;
comment|/* 0x0A */
name|u_int8_t
name|an_key
index|[
literal|13
index|]
decl_stmt|;
comment|/* 0x0C */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Receive frame structure.  */
end_comment

begin_struct
struct|struct
name|an_rxframe
block|{
name|u_int32_t
name|an_rx_time
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_rx_status
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|an_rx_payload_len
decl_stmt|;
comment|/* 0x06 */
name|u_int8_t
name|an_rsvd0
decl_stmt|;
comment|/* 0x08 */
name|u_int8_t
name|an_rx_signal_strength
decl_stmt|;
comment|/* 0x09 */
name|u_int8_t
name|an_rx_rate
decl_stmt|;
comment|/* 0x0A */
name|u_int8_t
name|an_rx_chan
decl_stmt|;
comment|/* 0x0B */
name|u_int8_t
name|an_rx_assoc_cnt
decl_stmt|;
comment|/* 0x0C */
name|u_int8_t
name|an_rsvd1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x0D */
name|u_int8_t
name|an_plcp_hdr
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x10 */
name|u_int16_t
name|an_frame_ctl
decl_stmt|;
comment|/* 0x14 */
name|u_int16_t
name|an_duration
decl_stmt|;
comment|/* 0x16 */
name|u_int8_t
name|an_addr1
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x18 */
name|u_int8_t
name|an_addr2
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x1E */
name|u_int8_t
name|an_addr3
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x24 */
name|u_int16_t
name|an_seq_ctl
decl_stmt|;
comment|/* 0x2A */
name|u_int8_t
name|an_addr4
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x2C */
name|u_int8_t
name|an_gaplen
decl_stmt|;
comment|/* 0x32 */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Do not modify this unless you are modifying LEAP itself */
end_comment

begin_define
define|#
directive|define
name|LEAP_USERNAME_MAX
value|32
end_define

begin_define
define|#
directive|define
name|LEAP_PASSWORD_MAX
value|32
end_define

begin_comment
comment|/*  * LEAP Username  */
end_comment

begin_struct
struct|struct
name|an_ltv_leap_username
block|{
name|u_int16_t
name|an_len
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_type
decl_stmt|;
comment|/* 0xXX */
name|u_int16_t
name|an_username_len
decl_stmt|;
comment|/* 0x02 */
name|u_int8_t
name|an_username
index|[
name|LEAP_USERNAME_MAX
index|]
decl_stmt|;
comment|/* 0x04 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * LEAP Password  */
end_comment

begin_struct
struct|struct
name|an_ltv_leap_password
block|{
name|u_int16_t
name|an_len
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_type
decl_stmt|;
comment|/* 0xXX */
name|u_int16_t
name|an_password_len
decl_stmt|;
comment|/* 0x02 */
name|u_int8_t
name|an_password
index|[
name|LEAP_PASSWORD_MAX
index|]
decl_stmt|;
comment|/* 0x04 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * These are all the LTV record types that we can read or write  * from the Aironet. Not all of them are temendously useful, but I  * list as many as I know about here for completeness.  */
end_comment

begin_comment
comment|/*  * Configuration (read/write)  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_GENCONFIG
value|0xFF10
end_define

begin_comment
comment|/* General configuration info */
end_comment

begin_define
define|#
directive|define
name|AN_RID_SSIDLIST
value|0xFF11
end_define

begin_comment
comment|/* Valid SSID list */
end_comment

begin_define
define|#
directive|define
name|AN_RID_APLIST
value|0xFF12
end_define

begin_comment
comment|/* Valid AP list */
end_comment

begin_define
define|#
directive|define
name|AN_RID_DRVNAME
value|0xFF13
end_define

begin_comment
comment|/* ID name of this node for diag */
end_comment

begin_define
define|#
directive|define
name|AN_RID_ENCAPPROTO
value|0xFF14
end_define

begin_comment
comment|/* Payload encapsulation type */
end_comment

begin_define
define|#
directive|define
name|AN_RID_WEP_TEMP
value|0xFF15
end_define

begin_comment
comment|/* Temporary Key */
end_comment

begin_define
define|#
directive|define
name|AN_RID_WEP_PERM
value|0xFF16
end_define

begin_comment
comment|/* Perminant Key */
end_comment

begin_define
define|#
directive|define
name|AN_RID_ACTUALCFG
value|0xFF20
end_define

begin_comment
comment|/* Current configuration settings */
end_comment

begin_comment
comment|/*  * Reporting (read only)  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_CAPABILITIES
value|0xFF00
end_define

begin_comment
comment|/* PC 4500/4800 capabilities */
end_comment

begin_define
define|#
directive|define
name|AN_RID_AP_INFO
value|0xFF01
end_define

begin_comment
comment|/* Access point info */
end_comment

begin_define
define|#
directive|define
name|AN_RID_RADIO_INFO
value|0xFF02
end_define

begin_comment
comment|/* Radio info */
end_comment

begin_define
define|#
directive|define
name|AN_RID_STATUS
value|0xFF50
end_define

begin_comment
comment|/* Current status info */
end_comment

begin_define
define|#
directive|define
name|AN_RID_BEACONS_HST
value|0xFF51
end_define

begin_define
define|#
directive|define
name|AN_RID_BUSY_HST
value|0xFF52
end_define

begin_define
define|#
directive|define
name|AN_RID_RETRIES_HST
value|0xFF53
end_define

begin_comment
comment|/*  * Statistics  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_16BITS_CUM
value|0xFF60
end_define

begin_comment
comment|/* Cumulative 16-bit stats counters */
end_comment

begin_define
define|#
directive|define
name|AN_RID_16BITS_DELTA
value|0xFF61
end_define

begin_comment
comment|/* 16-bit stats (since last clear) */
end_comment

begin_define
define|#
directive|define
name|AN_RID_16BITS_DELTACLR
value|0xFF62
end_define

begin_comment
comment|/* 16-bit stats, clear on read */
end_comment

begin_define
define|#
directive|define
name|AN_RID_32BITS_CUM
value|0xFF68
end_define

begin_comment
comment|/* Cumulative 32-bit stats counters */
end_comment

begin_define
define|#
directive|define
name|AN_RID_32BITS_DELTA
value|0xFF69
end_define

begin_comment
comment|/* 32-bit stats (since last clear) */
end_comment

begin_define
define|#
directive|define
name|AN_RID_32BITS_DELTACLR
value|0xFF6A
end_define

begin_comment
comment|/* 32-bit stats, clear on read */
end_comment

begin_comment
comment|/*  * LEAP  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_LEAPUSERNAME
value|0xFF23
end_define

begin_comment
comment|/* Username */
end_comment

begin_define
define|#
directive|define
name|AN_RID_LEAPPASSWORD
value|0xFF24
end_define

begin_comment
comment|/* Password */
end_comment

begin_comment
comment|/*  * OTHER Unknonwn for now  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_MOD
value|0xFF17
end_define

begin_define
define|#
directive|define
name|AN_RID_OPTIONS
value|0xFF18
end_define

begin_define
define|#
directive|define
name|AN_RID_FACTORY_CONFIG
value|0xFF18
end_define

begin_comment
comment|/*  *   FreeBSD fake RID  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_MONITOR_MODE
value|0x0001
end_define

begin_comment
comment|/* Set monitor mode for driver */
end_comment

begin_define
define|#
directive|define
name|AN_MONITOR
value|1
end_define

begin_define
define|#
directive|define
name|AN_MONITOR_ANY_BSS
value|2
end_define

begin_define
define|#
directive|define
name|AN_MONITOR_INCLUDE_BEACON
value|4
end_define

begin_define
define|#
directive|define
name|AN_MONITOR_AIRONET_HEADER
value|8
end_define

begin_define
define|#
directive|define
name|DLT_AIRONET_HEADER
value|120
end_define

begin_comment
comment|/* Has been allocated at tcpdump.org */
end_comment

begin_comment
comment|/*  * from the Linux driver from Cisco ... no copyright header.  * Removed duplicated information that already existed in the FreeBSD driver  * provides emulation of the Cisco extensions to the Linux Aironet driver.  */
end_comment

begin_comment
comment|/*  * Ioctl constants to be used in airo_ioctl.command  */
end_comment

begin_define
define|#
directive|define
name|AIROGCAP
value|0
end_define

begin_comment
comment|/* Capability rid */
end_comment

begin_define
define|#
directive|define
name|AIROGCFG
value|1
end_define

begin_comment
comment|/* USED A LOT  */
end_comment

begin_define
define|#
directive|define
name|AIROGSLIST
value|2
end_define

begin_comment
comment|/* System ID list  */
end_comment

begin_define
define|#
directive|define
name|AIROGVLIST
value|3
end_define

begin_comment
comment|/* List of specified AP's */
end_comment

begin_define
define|#
directive|define
name|AIROGDRVNAM
value|4
end_define

begin_comment
comment|/* NOTUSED */
end_comment

begin_define
define|#
directive|define
name|AIROGEHTENC
value|5
end_define

begin_comment
comment|/* NOTUSED */
end_comment

begin_define
define|#
directive|define
name|AIROGWEPKTMP
value|6
end_define

begin_define
define|#
directive|define
name|AIROGWEPKNV
value|7
end_define

begin_define
define|#
directive|define
name|AIROGSTAT
value|8
end_define

begin_define
define|#
directive|define
name|AIROGSTATSC32
value|9
end_define

begin_define
define|#
directive|define
name|AIROGSTATSD32
value|10
end_define

begin_comment
comment|/*  * Leave gap of 40 commands after AIROGSTATSD32  */
end_comment

begin_define
define|#
directive|define
name|AIROPCAP
value|AIROGSTATSD32	+ 40
end_define

begin_define
define|#
directive|define
name|AIROPVLIST
value|AIROPCAP	+ 1
end_define

begin_define
define|#
directive|define
name|AIROPSLIST
value|AIROPVLIST	+ 1
end_define

begin_define
define|#
directive|define
name|AIROPCFG
value|AIROPSLIST	+ 1
end_define

begin_define
define|#
directive|define
name|AIROPSIDS
value|AIROPCFG	+ 1
end_define

begin_define
define|#
directive|define
name|AIROPAPLIST
value|AIROPSIDS	+ 1
end_define

begin_define
define|#
directive|define
name|AIROPMACON
value|AIROPAPLIST	+ 1
end_define

begin_comment
comment|/* Enable mac  */
end_comment

begin_define
define|#
directive|define
name|AIROPMACOFF
value|AIROPMACON	+ 1
end_define

begin_comment
comment|/* Disable mac */
end_comment

begin_define
define|#
directive|define
name|AIROPSTCLR
value|AIROPMACOFF	+ 1
end_define

begin_define
define|#
directive|define
name|AIROPWEPKEY
value|AIROPSTCLR	+ 1
end_define

begin_define
define|#
directive|define
name|AIROPWEPKEYNV
value|AIROPWEPKEY	+ 1
end_define

begin_define
define|#
directive|define
name|AIROPLEAPPWD
value|AIROPWEPKEYNV	+ 1
end_define

begin_define
define|#
directive|define
name|AIROPLEAPUSR
value|AIROPLEAPPWD	+ 1
end_define

begin_comment
comment|/*  * Another gap of 40 commands before flash codes  */
end_comment

begin_define
define|#
directive|define
name|AIROFLSHRST
value|AIROPWEPKEYNV	+ 40
end_define

begin_define
define|#
directive|define
name|AIROFLSHGCHR
value|AIROFLSHRST	+ 1
end_define

begin_define
define|#
directive|define
name|AIROFLSHSTFL
value|AIROFLSHGCHR	+ 1
end_define

begin_define
define|#
directive|define
name|AIROFLSHPCHR
value|AIROFLSHSTFL	+ 1
end_define

begin_define
define|#
directive|define
name|AIROFLPUTBUF
value|AIROFLSHPCHR	+ 1
end_define

begin_define
define|#
directive|define
name|AIRORESTART
value|AIROFLPUTBUF	+ 1
end_define

begin_comment
comment|/*  * Struct to enable up to 65535 ioctl's  */
end_comment

begin_define
define|#
directive|define
name|AIROMAGIC
value|0xa55a
end_define

begin_typedef
typedef|typedef
struct|struct
name|aironet_ioctl
block|{
name|unsigned
name|short
name|command
decl_stmt|;
comment|/* What to do */
name|unsigned
name|short
name|len
decl_stmt|;
comment|/* Len of data */
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
comment|/* d-data */
block|}
name|airo_ioctl
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

