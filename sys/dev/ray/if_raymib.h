begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2000  * Dr. Duncan McLennan Barclay, dmlb@ragnet.demon.co.uk.  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY DUNCAN BARCLAY AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL DUNCAN BARCLAY OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Bit mask definitions for firmware versioning  */
end_comment

begin_define
define|#
directive|define
name|RAY_V4
value|0x1
end_define

begin_define
define|#
directive|define
name|RAY_V5
value|0x2
end_define

begin_comment
comment|/*  * MIB stuctures  */
end_comment

begin_struct
struct|struct
name|ray_mib_common_head
block|{
comment|/*Offset*/
comment|/*Size*/
name|u_int8_t
name|mib_net_type
decl_stmt|;
comment|/*00*/
name|u_int8_t
name|mib_ap_status
decl_stmt|;
comment|/*01*/
name|u_int8_t
name|mib_ssid
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
comment|/*02*/
comment|/*20*/
name|u_int8_t
name|mib_scan_mode
decl_stmt|;
comment|/*22*/
name|u_int8_t
name|mib_apm_mode
decl_stmt|;
comment|/*23*/
name|u_int8_t
name|mib_mac_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/*24*/
comment|/*06*/
name|u_int8_t
name|mib_frag_thresh
index|[
literal|2
index|]
decl_stmt|;
comment|/*2a*/
comment|/*02*/
name|u_int8_t
name|mib_dwell_time
index|[
literal|2
index|]
decl_stmt|;
comment|/*2c*/
comment|/*02*/
name|u_int8_t
name|mib_beacon_period
index|[
literal|2
index|]
decl_stmt|;
comment|/*2e*/
comment|/*02*/
name|u_int8_t
name|mib_dtim_interval
decl_stmt|;
comment|/*30*/
name|u_int8_t
name|mib_max_retry
decl_stmt|;
comment|/*31*/
name|u_int8_t
name|mib_ack_timo
decl_stmt|;
comment|/*32*/
name|u_int8_t
name|mib_sifs
decl_stmt|;
comment|/*33*/
name|u_int8_t
name|mib_difs
decl_stmt|;
comment|/*34*/
name|u_int8_t
name|mib_pifs
decl_stmt|;
comment|/*35*/
name|u_int8_t
name|mib_rts_thresh
index|[
literal|2
index|]
decl_stmt|;
comment|/*36*/
comment|/*02*/
name|u_int8_t
name|mib_scan_dwell
index|[
literal|2
index|]
decl_stmt|;
comment|/*38*/
comment|/*02*/
name|u_int8_t
name|mib_scan_max_dwell
index|[
literal|2
index|]
decl_stmt|;
comment|/*3a*/
comment|/*02*/
name|u_int8_t
name|mib_assoc_timo
decl_stmt|;
comment|/*3c*/
name|u_int8_t
name|mib_adhoc_scan_cycle
decl_stmt|;
comment|/*3d*/
name|u_int8_t
name|mib_infra_scan_cycle
decl_stmt|;
comment|/*3e*/
name|u_int8_t
name|mib_infra_super_scan_cycle
decl_stmt|;
comment|/*3f*/
name|u_int8_t
name|mib_promisc
decl_stmt|;
comment|/*40*/
name|u_int8_t
name|mib_uniq_word
index|[
literal|2
index|]
decl_stmt|;
comment|/*41*/
comment|/*02*/
name|u_int8_t
name|mib_slot_time
decl_stmt|;
comment|/*43*/
name|u_int8_t
name|mib_roam_low_snr_thresh
decl_stmt|;
comment|/*44*/
name|u_int8_t
name|mib_low_snr_count
decl_stmt|;
comment|/*45*/
name|u_int8_t
name|mib_infra_missed_beacon_count
decl_stmt|;
comment|/*46*/
name|u_int8_t
name|mib_adhoc_missed_beacon_count
decl_stmt|;
comment|/*47*/
name|u_int8_t
name|mib_country_code
decl_stmt|;
comment|/*48*/
name|u_int8_t
name|mib_hop_seq
decl_stmt|;
comment|/*49*/
name|u_int8_t
name|mib_hop_seq_len
decl_stmt|;
comment|/*4a*/
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|ray_mib_common_tail
block|{
name|u_int8_t
name|mib_noise_filter_gain
decl_stmt|;
comment|/*00*/
name|u_int8_t
name|mib_noise_limit_offset
decl_stmt|;
comment|/*01*/
name|u_int8_t
name|mib_rssi_thresh_offset
decl_stmt|;
comment|/*02*/
name|u_int8_t
name|mib_busy_thresh_offset
decl_stmt|;
comment|/*03*/
name|u_int8_t
name|mib_sync_thresh
decl_stmt|;
comment|/*04*/
name|u_int8_t
name|mib_test_mode
decl_stmt|;
comment|/*05*/
name|u_int8_t
name|mib_test_min_chan
decl_stmt|;
comment|/*06*/
name|u_int8_t
name|mib_test_max_chan
decl_stmt|;
comment|/*07*/
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|ray_mib_4
block|{
name|struct
name|ray_mib_common_head
name|mib_head
decl_stmt|;
comment|/*00*/
name|u_int8_t
name|mib_cw_max
decl_stmt|;
comment|/*4b*/
name|u_int8_t
name|mib_cw_min
decl_stmt|;
comment|/*4c*/
name|struct
name|ray_mib_common_tail
name|mib_tail
decl_stmt|;
comment|/*4d*/
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|ray_mib_5
block|{
name|struct
name|ray_mib_common_head
name|mib_head
decl_stmt|;
comment|/*00*/
name|u_int8_t
name|mib_cw_max
index|[
literal|2
index|]
decl_stmt|;
comment|/*4b*/
comment|/*02*/
name|u_int8_t
name|mib_cw_min
index|[
literal|2
index|]
decl_stmt|;
comment|/*4d*/
comment|/*02*/
name|struct
name|ray_mib_common_tail
name|mib_tail
decl_stmt|;
comment|/*4f*/
name|u_int8_t
name|mib_allow_probe_resp
decl_stmt|;
comment|/*57*/
name|u_int8_t
name|mib_privacy_must_start
decl_stmt|;
comment|/*58*/
name|u_int8_t
name|mib_privacy_can_join
decl_stmt|;
comment|/*59*/
name|u_int8_t
name|mib_basic_rate_set
index|[
literal|8
index|]
decl_stmt|;
comment|/*5a*/
comment|/*08*/
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|mib_net_type
value|mib_head.mib_net_type
end_define

begin_define
define|#
directive|define
name|mib_ap_status
value|mib_head.mib_ap_status
end_define

begin_define
define|#
directive|define
name|mib_ssid
value|mib_head.mib_ssid
end_define

begin_define
define|#
directive|define
name|mib_scan_mode
value|mib_head.mib_scan_mode
end_define

begin_define
define|#
directive|define
name|mib_apm_mode
value|mib_head.mib_apm_mode
end_define

begin_define
define|#
directive|define
name|mib_mac_addr
value|mib_head.mib_mac_addr
end_define

begin_define
define|#
directive|define
name|mib_frag_thresh
value|mib_head.mib_frag_thresh
end_define

begin_define
define|#
directive|define
name|mib_dwell_time
value|mib_head.mib_dwell_time
end_define

begin_define
define|#
directive|define
name|mib_beacon_period
value|mib_head.mib_beacon_period
end_define

begin_define
define|#
directive|define
name|mib_dtim_interval
value|mib_head.mib_dtim_interval
end_define

begin_define
define|#
directive|define
name|mib_max_retry
value|mib_head.mib_max_retry
end_define

begin_define
define|#
directive|define
name|mib_ack_timo
value|mib_head.mib_ack_timo
end_define

begin_define
define|#
directive|define
name|mib_sifs
value|mib_head.mib_sifs
end_define

begin_define
define|#
directive|define
name|mib_difs
value|mib_head.mib_difs
end_define

begin_define
define|#
directive|define
name|mib_pifs
value|mib_head.mib_pifs
end_define

begin_define
define|#
directive|define
name|mib_rts_thresh
value|mib_head.mib_rts_thresh
end_define

begin_define
define|#
directive|define
name|mib_scan_dwell
value|mib_head.mib_scan_dwell
end_define

begin_define
define|#
directive|define
name|mib_scan_max_dwell
value|mib_head.mib_scan_max_dwell
end_define

begin_define
define|#
directive|define
name|mib_assoc_timo
value|mib_head.mib_assoc_timo
end_define

begin_define
define|#
directive|define
name|mib_adhoc_scan_cycle
value|mib_head.mib_adhoc_scan_cycle
end_define

begin_define
define|#
directive|define
name|mib_infra_scan_cycle
value|mib_head.mib_infra_scan_cycle
end_define

begin_define
define|#
directive|define
name|mib_infra_super_scan_cycle
define|\
value|mib_head.mib_infra_super_scan_cycle
end_define

begin_define
define|#
directive|define
name|mib_promisc
value|mib_head.mib_promisc
end_define

begin_define
define|#
directive|define
name|mib_uniq_word
value|mib_head.mib_uniq_word
end_define

begin_define
define|#
directive|define
name|mib_slot_time
value|mib_head.mib_slot_time
end_define

begin_define
define|#
directive|define
name|mib_roam_low_snr_thresh
value|mib_head.mib_roam_low_snr_thresh
end_define

begin_define
define|#
directive|define
name|mib_low_snr_count
value|mib_head.mib_low_snr_count
end_define

begin_define
define|#
directive|define
name|mib_infra_missed_beacon_count
define|\
value|mib_head.mib_infra_missed_beacon_count
end_define

begin_define
define|#
directive|define
name|mib_adhoc_missed_beacon_count
define|\
value|mib_head.mib_adhoc_missed_beacon_count
end_define

begin_define
define|#
directive|define
name|mib_country_code
value|mib_head.mib_country_code
end_define

begin_define
define|#
directive|define
name|mib_hop_seq
value|mib_head.mib_hop_seq
end_define

begin_define
define|#
directive|define
name|mib_hop_seq_len
value|mib_head.mib_hop_seq_len
end_define

begin_define
define|#
directive|define
name|mib_noise_filter_gain
value|mib_tail.mib_noise_filter_gain
end_define

begin_define
define|#
directive|define
name|mib_noise_limit_offset
value|mib_tail.mib_noise_limit_offset
end_define

begin_define
define|#
directive|define
name|mib_rssi_thresh_offset
value|mib_tail.mib_rssi_thresh_offset
end_define

begin_define
define|#
directive|define
name|mib_busy_thresh_offset
value|mib_tail.mib_busy_thresh_offset
end_define

begin_define
define|#
directive|define
name|mib_sync_thresh
value|mib_tail.mib_sync_thresh
end_define

begin_define
define|#
directive|define
name|mib_test_mode
value|mib_tail.mib_test_mode
end_define

begin_define
define|#
directive|define
name|mib_test_min_chan
value|mib_tail.mib_test_min_chan
end_define

begin_define
define|#
directive|define
name|mib_test_max_chan
value|mib_tail.mib_test_max_chan
end_define

begin_comment
comment|/*  * MIB IDs for the update/report param commands  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_NET_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_AP_STATUS
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SSID
value|2
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_MODE
value|3
end_define

begin_define
define|#
directive|define
name|RAY_MIB_APM_MODE
value|4
end_define

begin_define
define|#
directive|define
name|RAY_MIB_MAC_ADDR
value|5
end_define

begin_define
define|#
directive|define
name|RAY_MIB_FRAG_THRESH
value|6
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DWELL_TIME
value|7
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BEACON_PERIOD
value|8
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DTIM_INTERVAL
value|9
end_define

begin_define
define|#
directive|define
name|RAY_MIB_MAX_RETRY
value|10
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ACK_TIMO
value|11
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SIFS
value|12
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DIFS
value|13
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PIFS
value|14
end_define

begin_define
define|#
directive|define
name|RAY_MIB_RTS_THRESH
value|15
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_DWELL
value|16
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_MAX_DWELL
value|17
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ASSOC_TIMO
value|18
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_SCAN_CYCLE
value|19
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_SCAN_CYCLE
value|20
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_SUPER_SCAN_CYCLE
value|21
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PROMISC
value|22
end_define

begin_define
define|#
directive|define
name|RAY_MIB_UNIQ_WORD
value|23
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SLOT_TIME
value|24
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ROAM_LOW_SNR_THRESH
value|25
end_define

begin_define
define|#
directive|define
name|RAY_MIB_LOW_SNR_COUNT
value|26
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_MISSED_BEACON_COUNT
value|27
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_MISSED_BEACON_COUNT
value|28
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE
value|29
end_define

begin_define
define|#
directive|define
name|RAY_MIB_HOP_SEQ
value|30
end_define

begin_define
define|#
directive|define
name|RAY_MIB_HOP_SEQ_LEN
value|31
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CW_MAX
value|32
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CW_MIN
value|33
end_define

begin_define
define|#
directive|define
name|RAY_MIB_NOISE_FILTER_GAIN
value|34
end_define

begin_define
define|#
directive|define
name|RAY_MIB_NOISE_LIMIT_OFFSET
value|35
end_define

begin_define
define|#
directive|define
name|RAY_MIB_RSSI_THRESH_OFFSET
value|36
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BUSY_THRESH_OFFSET
value|37
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SYNC_THRESH
value|38
end_define

begin_define
define|#
directive|define
name|RAY_MIB_TEST_MODE
value|39
end_define

begin_define
define|#
directive|define
name|RAY_MIB_TEST_MIN_CHAN
value|40
end_define

begin_define
define|#
directive|define
name|RAY_MIB_TEST_MAX_CHAN
value|41
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ALLOW_PROBE_RESP
value|42
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PRIVACY_MUST_START
value|43
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PRIVACY_CAN_JOIN
value|44
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BASIC_RATE_SET
value|45
end_define

begin_define
define|#
directive|define
name|RAY_MIB_VERSION
value|46
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CUR_BSSID
value|47
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CUR_INITED
value|48
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CUR_DEF_TXRATE
value|49
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CUR_ENCRYPT
value|50
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CUR_NET_TYPE
value|51
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CUR_SSID
value|52
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CUR_PRIV_START
value|53
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CUR_PRIV_JOIN
value|54
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DES_BSSID
value|55
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DES_INITED
value|56
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DES_DEF_TXRATE
value|57
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DES_ENCRYPT
value|58
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DES_NET_TYPE
value|59
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DES_SSID
value|60
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DES_PRIV_START
value|61
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DES_PRIV_JOIN
value|62
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CUR_AP_STATUS
value|63
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CUR_PROMISC
value|64
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DES_AP_STATUS
value|65
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DES_PROMISC
value|66
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CUR_FRAMING
value|67
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DES_FRAMING
value|68
end_define

begin_define
define|#
directive|define
name|RAY_MIB_LASTUSER
value|45
end_define

begin_define
define|#
directive|define
name|RAY_MIB_MAX
value|68
end_define

begin_comment
comment|/*  * Strings for the MIB  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_STRINGS
value|{		\ 	"Network type",			\ 	"AP status",			\ 	"SSID",				\ 	"Scan mode",			\ 	"APM mode",			\ 	"MAC address",			\ 	"Fragmentation threshold",	\ 	"Dwell time",			\ 	"Beacon period",		\ 	"DTIM_INTERVAL",		\ 	"MAX_RETRY",			\ 	"ACK_TIMO",			\ 	"SIFS",				\ 	"DIFS",				\ 	"PIFS",				\ 	"RTS_THRESH",			\ 	"SCAN_DWELL",			\ 	"SCAN_MAX_DWELL",		\ 	"ASSOC_TIMO",			\ 	"ADHOC_SCAN_CYCLE",		\ 	"INFRA_SCAN_CYCLE",		\ 	"INFRA_SUPER_SCAN_CYCLE",	\ 	"PROMISC",			\ 	"UNIQ_WORD",			\ 	"SLOT_TIME",			\ 	"ROAM_LOW_SNR_THRESH",		\ 	"LOW_SNR_COUNT",		\ 	"INFRA_MISSED_BEACON_COUNT",	\ 	"ADHOC_MISSED_BEACON_COUNT",	\ 	"COUNTRY_CODE",			\ 	"HOP_SEQ",			\ 	"HOP_SEQ_LEN",			\ 	"CW_MAX",			\ 	"CW_MIN",			\ 	"NOISE_FILTER_GAIN",		\ 	"NOISE_LIMIT_OFFSET",		\ 	"RSSI_THRESH_OFFSET",		\ 	"BUSY_THRESH_OFFSET",		\ 	"SYNC_THRESH",			\ 	"TEST_MODE",			\ 	"TEST_MIN_CHAN",		\ 	"TEST_MAX_CHAN",		\ 	"ALLOW_PROBE_RESP",		\ 	"PRIVACY_MUST_START",		\ 	"PRIVACY_CAN_JOIN",		\ 	"BASIC_RATE_SET",		\ 	"Firmware version",		\ 	"Current BSS Id",		\ 	"Current INITED",		\ 	"Current DEF_TXRATE",		\ 	"Current ENCRYPT",		\ 	"Current NET_TYPE",		\ 	"Current SSID",			\ 	"Current PRIV_START",		\ 	"Current PRIV_JOIN",		\ 	"Desired BSSID",		\ 	"Desired INITED",		\ 	"Desired DEF_TXRATE",		\ 	"Desired ENCRYPT",		\ 	"Desired NET_TYPE",		\ 	"Desired SSID",			\ 	"Desired PRIV_START",		\ 	"Desired PRIV_JOIN",		\ 	"Current AP_STATUS",		\ 	"Current PROMISC",		\ 	"Desired AP_STATUS",		\ 	"Desired PROMISC",		\ 	"Current FRAMING",		\ 	"Desired FRAMING"		\ }
end_define

begin_define
define|#
directive|define
name|RAY_MIB_HELP_STRINGS
value|{			\ 	"0 Ad hoc, 1 Infrastructure",		\ 	"0 Station, 1 Access Point",		\ 	"",					\ 	"0 Passive, 1 Active",			\ 	"0 Off, 1 On",				\ 	"",					\ 	"Bytes",				\ 	"DWELL_TIME",				\ 	"BEACON_PERIOD",			\ 	"DTIM_INTERVAL",			\ 	"MAX_RETRY",				\ 	"ACK_TIMO",				\ 	"SIFS",					\ 	"DIFS",					\ 	"PIFS",					\ 	"RTS_THRESH",				\ 	"SCAN_DWELL",				\ 	"SCAN_MAX_DWELL",			\ 	"ASSOC_TIMO",				\ 	"ADHOC_SCAN_CYCLE",			\ 	"INFRA_SCAN_CYCLE",			\ 	"INFRA_SUPER_SCAN_CYCLE",		\ 	"PROMISC",				\ 	"UNIQ_WORD",				\ 	"SLOT_TIME",				\ 	"ROAM_LOW_SNR_THRESH",			\ 	"LOW_SNR_COUNT",			\ 	"INFRA_MISSED_BEACON_COUNT",		\ 	"ADHOC_MISSED_BEACON_COUNT",		\ 	"COUNTRY_CODE",				\ 	"HOP_SEQ",				\ 	"HOP_SEQ_LEN",				\ 	"CW_MAX",				\ 	"CW_MIN",				\ 	"NOISE_FILTER_GAIN",			\ 	"NOISE_LIMIT_OFFSET",			\ 	"RSSI_THRESH_OFFSET",			\ 	"BUSY_THRESH_OFFSET",			\ 	"SYNC_THRESH",				\ 	"TEST_MODE",				\ 	"TEST_MIN_CHAN",			\ 	"TEST_MAX_CHAN",			\ 	"ALLOW_PROBE_RESP",			\ 	"PRIVACY_MUST_START",			\ 	"PRIVACY_CAN_JOIN",			\ 	"BASIC_RATE_SET",			\ 	"",					\ 	"",					\ 	"0 Joined a net, 1 Created a net",	\ 	"Current DEF_TXRATE",			\ 	"Current ENCRYPT",			\ 	"Current NET_TYPE",			\ 	"",					\ 	"Current PRIV_START",			\ 	"Current PRIV_JOIN",			\ 	"",					\ 	"N/A",					\ 	"Desired DEF_TXRATE",			\ 	"Desired ENCRYPT",			\ 	"Desired NET_TYPE",			\ 	"",					\ 	"Desired PRIV_START",			\ 	"Desired PRIV_JOIN",			\ 	"Current AP_STATUS",			\ 	"Current PROMISC",			\ 	"Desired AP_STATUS",			\ 	"Desired PROMISC",			\ 	"Current FRAMING",			\ 	"Desired FRAMING"			\ }
end_define

begin_comment
comment|/*  * Applicable versions and work size for each MIB element  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_INFO_SIZ4
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFO_SIZ5
value|2
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SIZE
parameter_list|(
name|info
parameter_list|,
name|mib
parameter_list|,
name|version
parameter_list|)
define|\
value|info[(mib)][(version& RAY_V4)?RAY_MIB_INFO_SIZ4:RAY_MIB_INFO_SIZ5]
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFO
value|{							\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_NET_TYPE */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_AP_STATUS */
value|\ {RAY_V4|RAY_V5,	IEEE80211_NWID_LEN, 					\ 			IEEE80211_NWID_LEN},
comment|/* RAY_MIB_SSID */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_SCAN_MODE */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_APM_MODE */
value|\ {RAY_V4|RAY_V5,	ETHER_ADDR_LEN,						\ 			ETHER_ADDR_LEN},
comment|/* RAY_MIB_MAC_ADDR */
value|\ {RAY_V4|RAY_V5,	2,	2},
comment|/* RAY_MIB_FRAG_THRESH */
value|\ {RAY_V4|RAY_V5,	2,	2},
comment|/* RAY_MIB_DWELL_TIME */
value|\ {RAY_V4|RAY_V5,	2,	2},
comment|/* RAY_MIB_BEACON_PERIOD */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_DTIM_INTERVAL */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_MAX_RETRY */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_ACK_TIMO */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_SIFS */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_DIFS */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_PIFS */
value|\ {RAY_V4|RAY_V5,	2,	2},
comment|/* RAY_MIB_RTS_THRESH */
value|\ {RAY_V4|RAY_V5,	2,	2},
comment|/* RAY_MIB_SCAN_DWELL */
value|\ {RAY_V4|RAY_V5,	2,	2},
comment|/* RAY_MIB_SCAN_MAX_DWELL */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_ASSOC_TIMO */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_ADHOC_SCAN_CYCLE */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_INFRA_SCAN_CYCLE */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_INFRA_SUPER_SCAN_CYCLE */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_PROMISC */
value|\ {RAY_V4|RAY_V5,	2,	2},
comment|/* RAY_MIB_UNIQ_WORD */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_SLOT_TIME */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_ROAM_LOW_SNR_THRESH */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_LOW_SNR_COUNT */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_INFRA_MISSED_BEACON_COUNT */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_ADHOC_MISSED_BEACON_COUNT */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_COUNTRY_CODE */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_HOP_SEQ */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_HOP_SEQ_LEN */
value|\ {RAY_V4|RAY_V5,	1,	2},
comment|/* RAY_MIB_CW_MAX */
value|\ {RAY_V4|RAY_V5,	1,	2},
comment|/* RAY_MIB_CW_MIN */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_NOISE_FILTER_GAIN */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_NOISE_LIMIT_OFFSET */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_RSSI_THRESH_OFFSET */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_BUSY_THRESH_OFFSET */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_SYNC_THRESH */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_TEST_MODE */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_TEST_MIN_CHAN */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_TEST_MAX_CHAN */
value|\ {       RAY_V5,	0,	1},
comment|/* RAY_MIB_ALLOW_PROBE_RESP */
value|\ {       RAY_V5,	0,	1},
comment|/* RAY_MIB_PRIVACY_MUST_START */
value|\ {       RAY_V5,	0,	1},
comment|/* RAY_MIB_PRIVACY_CAN_JOIN */
value|\ {       RAY_V5,	0,	8},
comment|/* RAY_MIB_BASIC_RATE_SET */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_VERSION */
value|\ {RAY_V4|RAY_V5,	ETHER_ADDR_LEN,						\ 			ETHER_ADDR_LEN},
comment|/* RAY_MIB_CUR_BSSID */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_CUR_INITED */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_CUR_DEF_TXRATE */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_CUR_ENCRYPT */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_CUR_NET_TYPE */
value|\ {RAY_V4|RAY_V5,	IEEE80211_NWID_LEN,					\ 			IEEE80211_NWID_LEN},
comment|/* RAY_MIB_CUR_SSID */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_CUR_PRIV_START */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_CUR_PRIV_JOIN */
value|\ {RAY_V4|RAY_V5,	ETHER_ADDR_LEN,						\ 			ETHER_ADDR_LEN},
comment|/* RAY_MIB_DES_BSSID */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_DES_INITED */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_DES_DEF_TXRATE */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_DES_ENCRYPT */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_DES_NET_TYPE */
value|\ {RAY_V4|RAY_V5,	IEEE80211_NWID_LEN, 					\ 			IEEE80211_NWID_LEN},
comment|/* RAY_MIB_DES_SSID */
value|\ {RAY_V4|RAY_V5,	1,	1},
comment|/* RAY_MIB_DES_PRIV_START */
value|\ {RAY_V4|RAY_V5,	1, 	1},
comment|/* RAY_MIB_DES_PRIV_JOIN */
value|\ {RAY_V4|RAY_V5,	1, 	1},
comment|/* RAY_MIB_CUR_AP_STATUS */
value|\ {RAY_V4|RAY_V5,	1, 	1},
comment|/* RAY_MIB_CUR_PROMISC */
value|\ {RAY_V4|RAY_V5,	1, 	1},
comment|/* RAY_MIB_DES_AP_STATUS */
value|\ {RAY_V4|RAY_V5,	1, 	1},
comment|/* RAY_MIB_DES_PROMISC */
value|\ {RAY_V4|RAY_V5,	1, 	1},
comment|/* RAY_MIB_CUR_FRAMING */
value|\ {RAY_V4|RAY_V5,	1, 	1}
comment|/* RAY_MIB_DES_FRAMING */
value|\ }
end_define

begin_comment
comment|/*  * MIB values  *  * I've included comments as to where the numbers have originated  * from.  *  * Linux refers to ray_cs.c and rayctl.h from version 167 of the  * Linux Raylink driver.  *  * NetBSD refers to if_ray.c from version 1.12 of the NetBSD Raylink  * driver.  *  * Symb refers to numbers cleaned from the 802.11 specification,  * discussion with 802.11 knowledgable people at Symbionics or  * stuff needed by me (i.e. me, * aps, ifo, hjl).  *  * V4 and V5 refer to settings for version 4 and version 5 of  * the firmware.  *  * DOC refers to the  *	Combined Interface Requirements Specification  *	and Interface Design Document (IRS/IDD)  *	for the  *	WLAN System Interfaces Between the  *	HOST COMPUTER and the  *	PCMCIA WLAN INTERFACE CARD  *	Revision ECF 5.00  *	17 June, 1998  */
end_comment

begin_comment
comment|/* Obtained by raycontrol _before_ downloading  *  * WebGear Aviator  *  * # raycontrol -i ray0  * Firmware version                4  * Network type                    0x01    0 Ad hoc, 1 Infrastructure  * AP status                       0x00    0 Station, 1 Access Point  * SSID                                                              * Scan mode                       0x01    0 Passive, 1 Active  * APM mode                        0x00    0 Off, 1 On  * MAC address                     00:00:8f:48:e4:44  * Fragmentation threshold         0x0200  FRAG_THRESH  * Dwell tIME                      0x01    DWELL_TIME  * Beacon period                   0x01    BEACON_PERIOD  * DTIM_INTERVAL                   0x05    DTIM_INTERVAL  * MAX_RETRY                       0x03    MAX_RETRY  * ACK_TIMO                        0x8c    ACK_TIMO  * SIFS                            0x1e    SIFS  * DIFS                            0x82    DIFS  * PIFS                            0xce    PIFS  * RTS_THRESH                      0x0100  RTS_THRESH  * SCAN_DWELL                      0xfc18  SCAN_DWELL  * SCAN_MAX_DWELL                  0xc180  SCAN_MAX_DWELL  * ASSOC_TIMO                      0x05    ASSOC_TIMO  * ADHOC_SCAN_CYCLE                0x04    ADHOC_SCAN_CYCLE  * INFRA_SCAN_CYCLE                0x02    INFRA_SCAN_CYCLE  * INFRA_SUPER_SCAN_CYCLE          0x04    INFRA_SUPER_SCAN_CYCLE  * PROMISC                         0x00    PROMISC  * UNIQ_WORD                       0x0cbd  UNIQ_WORD  * SLOT_TIME                       0x4e    SLOT_TIME  * ROAM_LOW_SNR_THRESH             0x20    ROAM_LOW_SNR_THRESH  * LOW_SNR_COUNT                   0x04    LOW_SNR_COUNT  * INFRA_MISSED_BEACON_COUNT       0x04    INFRA_MISSED_BEACON_COUNT  * ADHOC_MISSED_BEACON_COUNT       0x04    ADHOC_MISSED_BEACON_COUNT  * COUNTRY_CODE                    0x01    COUNTRY_CODE  * HOP_SEQ                         0x07    HOP_SEQ  * HOP_SEQ_LEN                     0x4e    HOP_SEQ_LEN  * CW_MAX                          0x3f    CW_MAX  * CW_MIN                          0x0f    CW_MIN  * NOISE_FILTER_GAIN               0x00    NOISE_FILTER_GAIN  * NOISE_LIMIT_OFFSET              0x00    NOISE_LIMIT_OFFSET  * RSSI_THRESH_OFFSET              0x70    RSSI_THRESH_OFFSET  * BUSY_THRESH_OFFSET              0x70    BUSY_THRESH_OFFSET  * SYNC_THRESH                     0x07    SYNC_THRESH  * TEST_MODE                       0x00    TEST_MODE  * TEST_MIN_CHAN                   0x02    TEST_MIN_CHAN  * TEST_MAX_CHAN                   0x02    TEST_MAX_CHAN  *  * Raylink  * Firmware version          	5  * Network type              	0x01	0 Ad hoc, 1 Infrastructure  * AP status                 	0x00	0 Station, 1 Access Point  * SSID                      	ESSID1                          	  * Scan mode                 	0x01	0 Passive, 1 Active  * APM mode                  	0x00	0 Off, 1 On  * MAC address               	00:00:8f:a8:17:06	  * Fragmentation threshold   	0x7fff	Bytes  * Dwell time                	0x0080	DWELL_TIME  * Beacon period             	0x0100	BEACON_PERIOD  * DTIM_INTERVAL             	0x01	DTIM_INTERVAL  * MAX_RETRY                 	0x1f	MAX_RETRY  * ACK_TIMO                  	0x86	ACK_TIMO  * SIFS                      	0x1c	SIFS  * DIFS                      	0x82	DIFS  * PIFS                      	0x4e	PIFS  * RTS_THRESH                	0x7fff	RTS_THRESH  * SCAN_DWELL                	0x04e2	SCAN_DWELL  * SCAN_MAX_DWELL            	0x38a4	SCAN_MAX_DWELL  * ASSOC_TIMO                	0x05	ASSOC_TIMO  * ADHOC_SCAN_CYCLE          	0x08	ADHOC_SCAN_CYCLE  * INFRA_SCAN_CYCLE          	0x02	INFRA_SCAN_CYCLE  * INFRA_SUPER_SCAN_CYCLE    	0x08	INFRA_SUPER_SCAN_CYCLE  * PROMISC                   	0x00	PROMISC  * UNIQ_WORD                 	0x0cbd	UNIQ_WORD  * SLOT_TIME                 	0x32	SLOT_TIME  * ROAM_LOW_SNR_THRESH       	0xff	ROAM_LOW_SNR_THRESH  * LOW_SNR_COUNT             	0xff	LOW_SNR_COUNT  * INFRA_MISSED_BEACON_COUNT 	0x02	INFRA_MISSED_BEACON_COUNT  * ADHOC_MISSED_BEACON_COUNT 	0xff	ADHOC_MISSED_BEACON_COUNT  * COUNTRY_CODE              	0x01	COUNTRY_CODE  * HOP_SEQ                   	0x0b	HOP_SEQ  * HOP_SEQ_LEN               	0x55	HOP_SEQ_LEN  * CW_MAX                    	0x003f	CW_MAX  * CW_MIN                    	0x000f	CW_MIN  * NOISE_FILTER_GAIN         	0x04	NOISE_FILTER_GAIN  * NOISE_LIMIT_OFFSET        	0x08	NOISE_LIMIT_OFFSET  * RSSI_THRESH_OFFSET        	0x28	RSSI_THRESH_OFFSET  * BUSY_THRESH_OFFSET        	0x28	BUSY_THRESH_OFFSET  * SYNC_THRESH               	0x07	SYNC_THRESH  * TEST_MODE                 	0x00	TEST_MODE  * TEST_MIN_CHAN             	0x02	TEST_MIN_CHAN  * TEST_MAX_CHAN             	0x02	TEST_MAX_CHAN  * ALLOW_PROBE_RESP          	0x00	ALLOW_PROBE_RESP  * PRIVACY_MUST_START        	0x00	PRIVACY_MUST_START  * PRIVACY_CAN_JOIN          	0x00	PRIVACY_CAN_JOIN  * BASIC_RATE_SET            	0x02	BASIC_RATE_SET  */
end_comment

begin_comment
comment|/*  * mib_net_type  *  * DOC		0x01	- Defines network type for Start and Join  *			- Network commands.  *  * As the V4 cards don't do infra we have to use adhoc. For V5 cards  * we follow standard FreeBSD practise and use infrastructure mode.  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_NET_TYPE_ADHOC
value|0x00
end_define

begin_define
define|#
directive|define
name|RAY_MIB_NET_TYPE_INFRA
value|0x01
end_define

begin_define
define|#
directive|define
name|RAY_MIB_NET_TYPE_V4
value|RAY_MIB_NET_TYPE_ADHOC
end_define

begin_define
define|#
directive|define
name|RAY_MIB_NET_TYPE_V5
value|RAY_MIB_NET_TYPE_INFRA
end_define

begin_comment
comment|/*  * mib_ap_status  *  * DOC		0x00	- Applicable only when Network Type is  *			- Infrastructure.  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_AP_STATUS_TERMINAL
value|0x00
end_define

begin_define
define|#
directive|define
name|RAY_MIB_AP_STATUS_AP
value|0x01
end_define

begin_define
define|#
directive|define
name|RAY_MIB_AP_STATUS_V4
value|RAY_MIB_AP_STATUS_TERMINAL
end_define

begin_define
define|#
directive|define
name|RAY_MIB_AP_STATUS_V5
value|RAY_MIB_AP_STATUS_TERMINAL
end_define

begin_comment
comment|/*  * mib_ssid  *  * DOC		ESSID1	- Service Set ID. Can be any ASCII string  *			- up to 32 bytes in length. If the string is  *			- less than 32 bytes long, it must be  *			- followed by a byte of 00h.  *  * Symb			- windows setting comes from the Aviator software v1.1  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_SSID_WINDOWS
value|"NETWORK_NAME"
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SSID_RAYLINK
value|"ESSID1"
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SSID_V4
value|RAY_MIB_SSID_WINDOWS
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SSID_V5
value|RAY_MIB_SSID_RAYLINK
end_define

begin_comment
comment|/*  * mib_scan_mode  *  * DOC		0x01	- Defines acquisition approach for  *			- terminals operating in either Ad Hoc or  *			- Infrastructure Networks. N/A for APs.   */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_MODE_PASSIVE
value|0x00
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_MODE_ACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_MODE_V4
value|RAY_MIB_SCAN_MODE_ACTIVE
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_MODE_V5
value|RAY_MIB_SCAN_MODE_ACTIVE
end_define

begin_comment
comment|/*  * mib_apm_mode  *  * DOC		0x00	- Defines power management mode for  *			- stations operating in either Ad Hoc or  *			- Infrastructure Networks. Must always  *			- be 0 for APs.  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_APM_MODE_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|RAY_MIB_APM_MODE_POWERSAVE
value|0x01
end_define

begin_define
define|#
directive|define
name|RAY_MIB_APM_MODE_V4
value|RAY_MIB_APM_MODE_NONE
end_define

begin_define
define|#
directive|define
name|RAY_MIB_APM_MODE_V5
value|RAY_MIB_APM_MODE_NONE
end_define

begin_comment
comment|/*  * mib_mac_addr  *  * DOC			- MAC Address to be used by WIC (For  *			- format see Figure 3.2.4.1.2-1, MAC  *			- Address Format). Host may echo card  *			- supplied address or use locally  *			- administered address.  */
end_comment

begin_comment
comment|/*  * mib_frag_thresh  *  * DOC		0x7fff	- Maximum over-the-air packet size (in  *			- bytes)  *  * Symb		0xXXXX	- you really should fragment when in low signal  *			- conditions but getting it wrong  *			  crucifies the performance  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_FRAG_THRESH_MINIMUM
value|0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_FRAG_THRESH_MAXIMUM
value|2346
end_define

begin_define
define|#
directive|define
name|RAY_MIB_FRAG_THRESH_DISABLE
value|0x7fff
end_define

begin_define
define|#
directive|define
name|RAY_MIB_FRAG_THRESH_V4
value|RAY_MIB_FRAG_THRESH_DISABLE
end_define

begin_define
define|#
directive|define
name|RAY_MIB_FRAG_THRESH_V5
value|RAY_MIB_FRAG_THRESH_DISABLE
end_define

begin_comment
comment|/*  * mib_dwell_time  *  * DOC		0x0080	- Defines hop dwell time in Kusec.  *			- Required only of stations which intend  *			- to issue a Start Network command.  *			- Forward Compatible Firmware (Build  *			- 5) requires that the dwell time be one of  *			- the set 16, 32, 64, 128, and 256.  *  * Linux.h		- 16k * 2**n, n=0-4 in Kus  * Linux.c-V4	0x0200  * Linux.c-V5	0x0080	- 128 Kus  * NetBSD-V4	0x0200	- from Linux  * NetBSD-V4	0x0400	- "divined"  * NetBSD-V5	0x0080  * Symb-V4	0xXXXX	- 802.11 dwell time is XXX Kus  * Symb-V5	0xXXXX	- 802.11 dwell time is XXX Kus  *  * XXX confirm that 1024Kus is okay for windows driver - how? and see  * XXX how it is over the maximum  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_DWELL_TIME_MINIMUM
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DWELL_TIME_MAXIMUM
value|390
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DWELL_TIME_V4
value|0x0400
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DWELL_TIME_V5
value|0x0080
end_define

begin_comment
comment|/*  * mib_beacon_period  *  * DOC		0x0100	- Defines time between target beacon  *			- transmit times (TBTT) in Kusec.  *			- Forward Compatible Firmware (Build  *			- 5) requires that the Beacon Period be an  *			- integral multiple of the Dwell Time (not  *			- exceeding 255 hops).  *			- Required only of stations which intend  *			- to issue a Start Network command.  *  * Linux.h		- n * a_hop_time  in Kus  * Linux.c-V4	0x0001  * Linux.c-V5	0x0100	- 256 Kus  * NetBSD-V4	0x0001	- from Linux  * NetBSD-V4	0x0000	- "divined"  * NetBSD-V5	0x0100  * Symb-V4	0x0001	- best performance is one beacon each dwell XXX  * Symb-V5	0x0080	- best performance is one beacon each dwell XXX  *  * XXX V4 should probably set this to dwell_time  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_BEACON_PERIOD_MINIMUM
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BEACON_PERIOD_MAXIMUM
value|0xffff
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BEACON_PERIOD_V4
value|0x0001
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BEACON_PERIOD_V5
value|(2*RAY_MIB_DWELL_TIME_V5)
end_define

begin_comment
comment|/*  * mib_dtim_interval  *  * DOC		0x01	- Number of beacons per DTIM period.  *			- Only APs will use this parameter, to set  *			- the DTIM period.  *  * Linux.h		- in beacons  * Linux.c	0x01  * NetBSD	0x01  * Symb		0xXX	- need to find out what DTIM is  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_DTIM_INTERVAL_MINIMUM
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DTIM_INTERVAL_MAXIMUM
value|255
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DTIM_INTERVAL_V4
value|0x01
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DTIM_INTERVAL_V5
value|0x01
end_define

begin_comment
comment|/*  * mib_max_retry  *  * DOC		31	- Number of times WIC will attempt to  *			- retransmit a failed packet.  *  * Linux.c	0x07  * NetBSD	0x01	- "documented default for 5/6"  * NetBSD	0x07	- from Linux  * NetBSD	0x03	- "divined"  * Symb		0xXX	- 7 retries seems okay but check with APS  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_MAX_RETRY_MINIMUM
value|0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_MAX_RETRY_MAXIMUM
value|255
end_define

begin_define
define|#
directive|define
name|RAY_MIB_MAX_RETRY_V4
value|0x07
end_define

begin_define
define|#
directive|define
name|RAY_MIB_MAX_RETRY_V5
value|0x1f
end_define

begin_comment
comment|/*  * mib_ack_timo  *  * DOC		0x86	- Time WIC will wait after completion of  *			- a transmit before timing out anticipated  *			- ACK (2 usec steps). Should equal  *			- SIFS + constant.  *  * Linux.c	0xa3  * NetBSD	0x86	- documented default for 5/6  * NetBSD	0xa3	- from Linux  * NetBSD	0xa3	- "divined"  * Symb		0xXX	- this must be a 802.11 defined setting?  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_ACK_TIMO_MINIMUM
value|0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ACK_TIMO_MAXIMUM
value|255
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ACK_TIMO_V4
value|0xa3
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ACK_TIMO_V5
value|0x86
end_define

begin_comment
comment|/*  * mib_sifs  *  * DOC		0x1c	- SIFS time in usec.  *  * Linux.c	0x1d  * NetBSD	0x1c	- documented default for 5/6  * NetBSD	0x1d	- from Linux  * NetBSD	0x1d	- "divined"  * Symb		0xXX	- default SIFS for 802.11  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_SIFS_MINIMUM
value|28
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SIFS_MAXIMUM
value|62
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SIFS_V4
value|0x1d
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SIFS_V5
value|0x1c
end_define

begin_comment
comment|/*  * mib_difs  *  * DOC		0x82	- DIFS time in usec.  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_DIFS_MINIMUM
value|130
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DIFS_MAXIMUM
value|255
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DIFS_V4
value|0x82
end_define

begin_define
define|#
directive|define
name|RAY_MIB_DIFS_V5
value|0x82
end_define

begin_comment
comment|/*  * mib_pifs  *  * DOC		78	- PIFS time in usec. (Not currently  *			- implemented.  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_PIFS_MINIMUM
value|78
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PIFS_MAXIMUM
value|255
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PIFS_V4
value|0xce
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PIFS_V5
value|0x4e
end_define

begin_comment
comment|/*  * mib_rts_thresh  *  * DOC		0x7ffff	- Threshold size in bytes below which  *			- messages will not require use of RTS  *			- Protocol.  *  * Linux.c	0x7fff  * NetBSD	0x7fff	- disabled  * Symb		0xXXXX	- need to set this realistically to get CTS/RTS mode  *			  working right  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_RTS_THRESH_MINIMUM
value|0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_RTS_THRESH_MAXIMUM
value|2346
end_define

begin_define
define|#
directive|define
name|RAY_MIB_RTS_THRESH_DISABLE
value|0x7fff
end_define

begin_define
define|#
directive|define
name|RAY_MIB_RTS_THRESH_V4
value|RAY_MIB_RTS_THRESH_DISABLE
end_define

begin_define
define|#
directive|define
name|RAY_MIB_RTS_THRESH_V5
value|RAY_MIB_RTS_THRESH_DISABLE
end_define

begin_comment
comment|/*  * mib_scan_dwell  *  * DOC		0x04e2	- Time channel remains clear after probe  *			- transmission prior to hopping to next  *			- channel. (in 2 msec steps).  *  * Linux.c-V4	0xfb1e	- 128572us  * Linix.c-V5	0x04e2	-   2500us  * NetBSD-V4	0xfb1e  * NetBSD-V5	0x04e2  * Symb		0xXXXX	- Check that v4 h/w can do 2.5ms and default it  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_DWELL_MINIMUM
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_DWELL_MAXIMUM
value|65535
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_DWELL_V4
value|0xfb1e
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_DWELL_V5
value|0x04e2
end_define

begin_comment
comment|/*  * mib_scan_max_dwell  *  * DOC		0x38a4	- Time to remain on a frequency channel  *			- if CCA is detected after probe  *			- transmission. (in 2 usec steps).  *  * Linux.c-V4	0xc75c	- 102072us  * Linix.c-V5	0x38a4	-  29000us  * NetBSD-V4	0xc75c  * NetBSD-V5	0x38a4  * Symb		0xXXXX	- see above - this may be total time before giving up  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_MAX_DWELL_MINIMUM
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_MAX_DWELL_MAXIMUM
value|65535
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_MAX_DWELL_V4
value|0xc75c
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SCAN_MAX_DWELL_V5
value|0x38a4
end_define

begin_comment
comment|/*  * mib_assoc_timo  *  * DOC		0x05	- Time (in hops) a station waits after  *			- transmitting an Association Request  *			- Message before association attempt is  *			- considered failed. N/A for Ad Hoc  *			- Networks and for APs in Infrastructure  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_ASSOC_TIMO_MINIMUM
value|0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ASSOC_TIMO_MAXIMUM
value|255
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ASSOC_TIMO_V4
value|0x05
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ASSOC_TIMO_V5
value|0x05
end_define

begin_comment
comment|/*  * mib_adhoc_scan_cycle  *  * DOC		0x08	- Maximum number of times to cycle  *			- through frequency hopping pattern as  *			- part of scanning during Ad Hoc  *			- Acquisition.  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_SCAN_CYCLE_MINIMUM
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_SCAN_CYCLE_MAXIMUM
value|255
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_SCAN_CYCLE_V4
value|0x08
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_SCAN_CYCLE_V5
value|0x08
end_define

begin_comment
comment|/*  * mib_infra_scan_cycle  *  * DOC		0x02	- Number of times to cycle through  *			- frequency hopping pattern as part of  *			- scanning during Infrastructure Network  *			- Acquisition.  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_SCAN_CYCLE_MINIMUM
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_SCAN_CYCLE_MAXIMUM
value|255
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_SCAN_CYCLE_V4
value|0x02
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_SCAN_CYCLE_V5
value|0x02
end_define

begin_comment
comment|/*  * mib_infra_super_scan_cycle  *  * DOC		0x08	- Number of times to repeat an  *			- Infrastructure scan cycle if no APs are  *			- found before indicating a failure.  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_SUPER_SCAN_CYCLE_MINIMUM
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_SUPER_SCAN_CYCLE_MAXIMUM
value|255
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_SUPER_SCAN_CYCLE_V4
value|0x08
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_SUPER_SCAN_CYCLE_V5
value|0x08
end_define

begin_comment
comment|/*  * mib_promisc  *  * DOC		0x00	- Controls operation of WIC in  *			- promiscuous mode.  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_PROMISC_DISABLED
value|0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PROMISC_ENABLED
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PROMISC_V4
value|0x00
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PROMISC_V5
value|0x00
end_define

begin_comment
comment|/*  * mib_uniq_word  *  * DOC		0x0cdb	- Unique word pattern (Transmitted as  *			- 0CBDh per 802.11)  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_UNIQ_WORD_MINIMUM
value|0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_UNIQ_WORD_MAXIMUM
value|0xffff
end_define

begin_define
define|#
directive|define
name|RAY_MIB_UNIQ_WORD_V4
value|0x0cbd
end_define

begin_define
define|#
directive|define
name|RAY_MIB_UNIQ_WORD_V5
value|0x0cbd
end_define

begin_comment
comment|/*  * mib_slot_time  *  * DOC		0x32	- Slot time in usec  *  * Linux.c-V4	0x4e  * Linix.c-V5	0x32  * NetBSD-V4	0x4e	- Linux  * NetBSD-V4	0x18	- "divined"  * NetBSD-V5	0x32	- mentions spec. is 50us i.e. 0x32  * Symb		0xXX	- wtf 0x4e = 78  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_SLOT_TIME_MINIMUM
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SLOT_TIME_MAXIMUM
value|128
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SLOT_TIME_V4
value|0x4e
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SLOT_TIME_V5
value|0x32
end_define

begin_comment
comment|/*  * mib_roam_low_snr_thresh  *  * DOC		0xff	- SNR Threshold for use by roaming  *			- algorithm. [Low power count is  *			- incremented when Beacon is received at  *			- SNR lower than Roaming Low SNR  *			- Threshold.] To disable, set to FFh.  *  * Linux.c	0xff  * NetBSD-V4	0xff	- Linux  * NetBSD-V4	0x30	- "divined"  * NetBSD-V5	0xff	- disabled  * NetBSD.h		- if below this inc count  * Symb		0xXX	- hmm is 0xff really disabled? need this to work  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_ROAM_LOW_SNR_THRESH_MINIMUM
value|0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ROAM_LOW_SNR_THRESH_MAXIMUM
value|255
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ROAM_LOW_SNR_THRESH_DISABLED
value|0xff
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ROAM_LOW_SNR_THRESH_V4
value|RAY_MIB_ROAM_LOW_SNR_THRESH_DISABLED
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ROAM_LOW_SNR_THRESH_V5
value|RAY_MIB_ROAM_LOW_SNR_THRESH_DISABLED
end_define

begin_comment
comment|/*  * mib_low_snr_count  *  * DOC		0xff	- Threshold that number of consecutive  *			- beacons received at SNR< Roaming  *			- Low SNR Threshold must exceed  *			- before roaming processing begins. To  *			- disable, set to FFh.  *  * Linux.c	0xff  * NetBSD	0x07	- "divined - check" and marked as disabled  * NetBSD	0xff	- disabled  * NetBSD.h		- roam after cnt below thrsh  * Symb		0xXX	- hmm is 0xff really disabled? need  *			- this to work in infrastructure mode with mutliple APs  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_LOW_SNR_COUNT_MINIMUM
value|0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_LOW_SNR_COUNT_MAXIMUM
value|255
end_define

begin_define
define|#
directive|define
name|RAY_MIB_LOW_SNR_COUNT_DISABLED
value|0xff
end_define

begin_define
define|#
directive|define
name|RAY_MIB_LOW_SNR_COUNT_V4
value|RAY_MIB_LOW_SNR_COUNT_DISABLED
end_define

begin_define
define|#
directive|define
name|RAY_MIB_LOW_SNR_COUNT_V5
value|RAY_MIB_LOW_SNR_COUNT_DISABLED
end_define

begin_comment
comment|/*  * mib_infra_missed_beacon_count  *  * DOC		0x02	- Threshold that number of consecutive  *			- beacons not received must exceed  *			- before roaming processing begins in an  *			- infrastructure network. To disable, set  *			- to FFh.  * Linux.c	0x05  * NetBSD	0x02	- documented default for 5/6  * NetBSD	0x05	- Linux  * NetBSD	0x07	- "divined - check, looks fishy"  * Symb		0xXX	- 5 missed beacons is probably okay  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_MISSED_BEACON_COUNT_MINIMUM
value|0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_MISSED_BEACON_COUNT_MAXIMUM
value|255
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_MISSED_BEACON_COUNT_V4
value|0x05
end_define

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_MISSED_BEACON_COUNT_V5
value|0x02
end_define

begin_comment
comment|/*  * mib_adhoc_missed_beacon_count  *  * DOC		0xff	- Threshold that number of consecutive  *			- beacons transmitted by a terminal must  *			- exceed before reacquisition processing  *			- begins in Ad Hoc Network.  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_MISSED_BEACON_COUNT_MINIMUM
value|0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_MISSED_BEACON_COUNT_MAXIMUM
value|255
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_MISSED_BEACON_COUNT_DISABLED
value|0xff
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_MISSED_BEACON_COUNT_V4
value|RAY_MIB_ADHOC_MISSED_BEACON_COUNT_DISABLED
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_MISSED_BEACON_COUNT_V5
value|RAY_MIB_ADHOC_MISSED_BEACON_COUNT_DISABLED
end_define

begin_comment
comment|/*  * mib_country_code  *  * DOC		0x01	- Country set of hopping patterns  *			- (element value in beacon)  *			- Note: Japan Test is for a special test  *			- mode required by the Japanese  *			- regulatory authorities.  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_MIMIMUM
value|0x01
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_MAXIMUM
value|0x09
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_USA
value|0x01
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_EUROPE
value|0x02
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_JAPAN
value|0x03
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_KOREA
value|0x04
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_SPAIN
value|0x05
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_FRANCE
value|0x06
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_ISRAEL
value|0x07
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_AUSTRALIA
value|0x08
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_JAPAN_TEST
value|0x09
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_V4
value|RAY_MIB_COUNTRY_CODE_USA
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_V5
value|RAY_MIB_COUNTRY_CODE_USA
end_define

begin_comment
comment|/*  * mib_hop_seq  *  * DOC		0x0b	- Hop Pattern to use. (Currently 66  *			- US/Europe plus 12 Japanese).  *  * NetBSD.h		- no longer supported  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_HOP_SEQ_MINIMUM
value|6
end_define

begin_define
define|#
directive|define
name|RAY_MIB_HOP_SEQ_MAXIMUM
value|72
end_define

begin_define
define|#
directive|define
name|RAY_MIB_HOP_SEQ_V4
value|0x0b
end_define

begin_define
define|#
directive|define
name|RAY_MIB_HOP_SEQ_V5
value|0x04
end_define

begin_comment
comment|/*  * mib_hop_seq_len  *  * DOC		0x4f	- Number of frequency channels in  *			- hopping pattern is now set to the value  *			- defined in IEEE802.11 for the selected  *			- Current Country Code.  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_HOP_SEQ_LEN_MINIMUM
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_HOP_SEQ_LEN_MAXIMUM
value|79
end_define

begin_define
define|#
directive|define
name|RAY_MIB_HOP_SEQ_LEN_V4
value|0x4e
end_define

begin_define
define|#
directive|define
name|RAY_MIB_HOP_SEQ_LEN_V5
value|0x4f
end_define

begin_comment
comment|/*  * All from here down are the same in Linux/NetBSD and seem to be sane.  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_CW_MAX_V4
value|0x3f
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CW_MAX_V5
value|0x003f
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CW_MIN_V4
value|0x0f
end_define

begin_define
define|#
directive|define
name|RAY_MIB_CW_MIN_V5
value|0x000f
end_define

begin_comment
comment|/*  * Symb		0xXX	- these parameters will affect the clear channel  *			  assesment false triggering  *  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_NOISE_FILTER_GAIN_DEFAULT
value|0x04
end_define

begin_define
define|#
directive|define
name|RAY_MIB_NOISE_LIMIT_OFFSET_DEFAULT
value|0x08
end_define

begin_define
define|#
directive|define
name|RAY_MIB_RSSI_THRESH_OFFSET_DEFAULT
value|0x28
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BUSY_THRESH_OFFSET_DEFAULT
value|0x28
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SYNC_THRESH_DEFAULT
value|0x07
end_define

begin_define
define|#
directive|define
name|RAY_MIB_TEST_MODE_NORMAL
value|0x0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_TEST_MODE_ANT_1
value|0x1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_TEST_MODE_ATN_2
value|0x2
end_define

begin_define
define|#
directive|define
name|RAY_MIB_TEST_MODE_ATN_BOTH
value|0x3
end_define

begin_define
define|#
directive|define
name|RAY_MIB_TEST_MODE_DEFAULT
value|RAY_MIB_TEST_MODE_NORMAL
end_define

begin_define
define|#
directive|define
name|RAY_MIB_TEST_MIN_CHAN_DEFAULT
value|0x02
end_define

begin_define
define|#
directive|define
name|RAY_MIB_TEST_MAX_CHAN_DEFAULT
value|0x02
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ALLOW_PROBE_RESP_DISALLOW
value|0x0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ALLOW_PROBE_RESP_ALLOW
value|0x1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ALLOW_PROBE_RESP_DEFAULT
value|RAY_MIB_ALLOW_PROBE_RESP_DISALLOW
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PRIVACY_MUST_START_NOWEP
value|0x0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PRIVACY_MUST_START_WEP
value|0x1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PRIVACY_MUST_START_DEFAULT
value|RAY_MIB_PRIVACY_MUST_START_NOWEP
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PRIVACY_CAN_JOIN_NOWEP
value|0x0
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PRIVACY_CAN_JOIN_WEP
value|0x1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PRIVACY_CAN_JOIN_DONT_CARE
value|0x2
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PRIVACY_CAN_JOIN_DEFAULT
value|RAY_MIB_PRIVACY_CAN_JOIN_NOWEP
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BASIC_RATE_SET_MINIMUM
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BASIC_RATE_SET_MAXIMUM
value|4
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BASIC_RATE_SET_500K
value|1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BASIC_RATE_SET_1000K
value|2
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BASIC_RATE_SET_1500K
value|3
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BASIC_RATE_SET_2000K
value|4
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BASIC_RATE_SET_DEFAULT
value|RAY_MIB_BASIC_RATE_SET_2000K
end_define

begin_comment
comment|/*  * IOCTL support  */
end_comment

begin_struct
struct|struct
name|ray_param_req
block|{
name|int
name|r_failcause
decl_stmt|;
name|u_int8_t
name|r_paramid
decl_stmt|;
name|u_int8_t
name|r_len
decl_stmt|;
name|u_int8_t
name|r_data
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ray_stats_req
block|{
name|u_int64_t
name|rxoverflow
decl_stmt|;
comment|/* Number of rx overflows	*/
name|u_int64_t
name|rxcksum
decl_stmt|;
comment|/* Number of checksum errors	*/
name|u_int64_t
name|rxhcksum
decl_stmt|;
comment|/* Number of header checksum errors */
name|u_int8_t
name|rxnoise
decl_stmt|;
comment|/* Average receiver level	*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RAY_FAILCAUSE_EIDRANGE
value|1
end_define

begin_define
define|#
directive|define
name|RAY_FAILCAUSE_ELENGTH
value|2
end_define

begin_comment
comment|/* device can possibly return up to 255 */
end_comment

begin_define
define|#
directive|define
name|RAY_FAILCAUSE_EDEVSTOP
value|256
end_define

begin_comment
comment|/* Get a param the data is a ray_param_req structure */
end_comment

begin_define
define|#
directive|define
name|SIOCSRAYPARAM
value|SIOCSIFGENERIC
end_define

begin_define
define|#
directive|define
name|SIOCGRAYPARAM
value|SIOCGIFGENERIC
end_define

begin_comment
comment|/* Get the error counters the data is a ray_stats_req structure */
end_comment

begin_define
define|#
directive|define
name|SIOCGRAYSTATS
value|_IOWR('i', 201, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGRAYSIGLEV
value|_IOWR('i', 202, struct ifreq)
end_define

begin_define
define|#
directive|define
name|RAY_NSIGLEVRECS
value|8
end_define

begin_define
define|#
directive|define
name|RAY_NSIGLEV
value|8
end_define

begin_define
define|#
directive|define
name|RAY_NANTENNA
value|8
end_define

begin_struct
struct|struct
name|ray_siglev
block|{
name|u_int8_t
name|rsl_host
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* MAC address */
name|u_int8_t
name|rsl_siglevs
index|[
name|RAY_NSIGLEV
index|]
decl_stmt|;
comment|/* levels, newest in [0] */
name|u_int8_t
name|rsl_antennas
index|[
name|RAY_NANTENNA
index|]
decl_stmt|;
comment|/* best antenna */
name|struct
name|timeval
name|rsl_time
decl_stmt|;
comment|/* time of last packet */
block|}
struct|;
end_struct

end_unit

