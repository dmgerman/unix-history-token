begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2000  * Dr. Duncan McLennan Barclay, dmlb@ragnet.demon.co.uk.  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY DUNCAN BARCLAY AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL DUNCAN BARCLAY OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: if_raymib.h,v 1.3 2000/03/21 14:27:46 dmlb Exp $  *  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|RAY_FAILCAUSE_WAITING
value|257
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|RAY_MIB_LASTUSER
value|45
end_define

begin_define
define|#
directive|define
name|RAY_MIB_MAX
value|62
end_define

begin_comment
comment|/*  * Strings for the MIB  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_STRINGS
value|{		\ 	"Network type",			\ 	"AP status",			\ 	"SSID",				\ 	"Scan mode",			\ 	"APM mode",			\ 	"MAC address",			\ 	"FRAG_THRESH",			\ 	"DWELL_TIME",			\ 	"BEACON_PERIOD",		\ 	"DTIM_INTERVAL",		\ 	"MAX_RETRY",			\ 	"ACK_TIMO",			\ 	"SIFS",				\ 	"DIFS",				\ 	"PIFS",				\ 	"RTS_THRESH",			\ 	"SCAN_DWELL",			\ 	"SCAN_MAX_DWELL",		\ 	"ASSOC_TIMO",			\ 	"ADHOC_SCAN_CYCLE",		\ 	"INFRA_SCAN_CYCLE",		\ 	"INFRA_SUPER_SCAN_CYCLE",	\ 	"PROMISC",			\ 	"UNIQ_WORD",			\ 	"SLOT_TIME",			\ 	"ROAM_LOW_SNR_THRESH",		\ 	"LOW_SNR_COUNT",		\ 	"INFRA_MISSED_BEACON_COUNT",	\ 	"ADHOC_MISSED_BEACON_COUNT",	\ 	"COUNTRY_CODE",			\ 	"HOP_SEQ",			\ 	"HOP_SEQ_LEN",			\ 	"CW_MAX",			\ 	"CW_MIN",			\ 	"NOISE_FILTER_GAIN",		\ 	"NOISE_LIMIT_OFFSET",		\ 	"RSSI_THRESH_OFFSET",		\ 	"BUSY_THRESH_OFFSET",		\ 	"SYNC_THRESH",			\ 	"TEST_MODE",			\ 	"TEST_MIN_CHAN",		\ 	"TEST_MAX_CHAN",		\ 	"ALLOW_PROBE_RESP",		\ 	"PRIVACY_MUST_START",		\ 	"PRIVACY_CAN_JOIN",		\ 	"BASIC_RATE_SET",		\ 	"Firmware version",		\ 	"Current BSS Id",		\ 	"Current INITED",		\ 	"Current DEF_TXRATE",		\ 	"Current ENCRYPT",		\ 	"Current NET_TYPE",		\ 	"Current SSID",			\ 	"Current PRIV_START",		\ 	"Current PRIV_JOIN",		\ 	"Desired BSSID",		\ 	"Desired INITED",		\ 	"Desired DEF_TXRATE",		\ 	"Desired ENCRYPT",		\ 	"Desired NET_TYPE",		\ 	"Desired SSID",			\ 	"Desired PRIV_START",		\ 	"Desired PRIV_JOIN"		\ }
end_define

begin_define
define|#
directive|define
name|RAY_MIB_HELP_STRINGS
value|{			\ 	"0 Ad hoc, 1 Infrastructure",		\ 	"0 Station, 1 Access Point",		\ 	"",					\ 	"0 Passive, 1 Active",			\ 	"0 Off, 1 On",				\ 	"",					\ 	"FRAG_THRESH",				\ 	"DWELL_TIME",				\ 	"BEACON_PERIOD",			\ 	"DTIM_INTERVAL",			\ 	"MAX_RETRY",				\ 	"ACK_TIMO",				\ 	"SIFS",					\ 	"DIFS",					\ 	"PIFS",					\ 	"RTS_THRESH",				\ 	"SCAN_DWELL",				\ 	"SCAN_MAX_DWELL",			\ 	"ASSOC_TIMO",				\ 	"ADHOC_SCAN_CYCLE",			\ 	"INFRA_SCAN_CYCLE",			\ 	"INFRA_SUPER_SCAN_CYCLE",		\ 	"PROMISC",				\ 	"UNIQ_WORD",				\ 	"SLOT_TIME",				\ 	"ROAM_LOW_SNR_THRESH",			\ 	"LOW_SNR_COUNT",			\ 	"INFRA_MISSED_BEACON_COUNT",		\ 	"ADHOC_MISSED_BEACON_COUNT",		\ 	"COUNTRY_CODE",				\ 	"HOP_SEQ",				\ 	"HOP_SEQ_LEN",				\ 	"CW_MAX",				\ 	"CW_MIN",				\ 	"NOISE_FILTER_GAIN",			\ 	"NOISE_LIMIT_OFFSET",			\ 	"RSSI_THRESH_OFFSET",			\ 	"BUSY_THRESH_OFFSET",			\ 	"SYNC_THRESH",				\ 	"TEST_MODE",				\ 	"TEST_MIN_CHAN",			\ 	"TEST_MAX_CHAN",			\ 	"ALLOW_PROBE_RESP",			\ 	"PRIVACY_MUST_START",			\ 	"PRIVACY_CAN_JOIN",			\ 	"BASIC_RATE_SET",			\ 	"",					\ 	"",					\ 	"0 Joined a net, 1 Created a net",	\ 	"Current DEF_TXRATE",			\ 	"Current ENCRYPT",			\ 	"Current NET_TYPE",			\ 	"",					\ 	"Current PRIV_START",			\ 	"Current PRIV_JOIN",			\ 	"N/A",					\ 	"N/A",					\ 	"Desired DEF_TXRATE",			\ 	"Desired ENCRYPT",			\ 	"Desired NET_TYPE",			\ 	"",					\ 	"Desired PRIV_START",			\ 	"Desired PRIV_JOIN"			\ }
end_define

begin_comment
comment|/*  * Sizes for each MIB element  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_SIZES
value|{					\ 	1,
comment|/* RAY_MIB_NET_TYPE */
value|\ 	1,
comment|/* RAY_MIB_AP_STATUS */
value|\ 	IEEE80211_NWID_LEN,
comment|/* RAY_MIB_SSID */
value|\ 	1,
comment|/* RAY_MIB_SCAN_MODE */
value|\ 	1,
comment|/* RAY_MIB_APM_MODE */
value|\ 	ETHER_ADDR_LEN,
comment|/* RAY_MIB_MAC_ADDR */
value|\ 	2,
comment|/* RAY_MIB_FRAG_THRESH */
value|\ 	2,
comment|/* RAY_MIB_DWELL_TIME */
value|\ 	2,
comment|/* RAY_MIB_BEACON_PERIOD */
value|\ 	1,
comment|/* RAY_MIB_DTIM_INTERVAL */
value|\ 	1,
comment|/* RAY_MIB_MAX_RETRY */
value|\ 	1,
comment|/* RAY_MIB_ACK_TIMO */
value|\ 	1,
comment|/* RAY_MIB_SIFS */
value|\ 	1,
comment|/* RAY_MIB_DIFS */
value|\ 	1,
comment|/* RAY_MIB_PIFS */
value|\ 	2,
comment|/* RAY_MIB_RTS_THRESH */
value|\ 	2,
comment|/* RAY_MIB_SCAN_DWELL */
value|\ 	2,
comment|/* RAY_MIB_SCAN_MAX_DWELL */
value|\ 	1,
comment|/* RAY_MIB_ASSOC_TIMO */
value|\ 	1,
comment|/* RAY_MIB_ADHOC_SCAN_CYCLE */
value|\ 	1,
comment|/* RAY_MIB_INFRA_SCAN_CYCLE */
value|\ 	1,
comment|/* RAY_MIB_INFRA_SUPER_SCAN_CYCLE */
value|\ 	1,
comment|/* RAY_MIB_PROMISC */
value|\ 	2,
comment|/* RAY_MIB_UNIQ_WORD */
value|\ 	1,
comment|/* RAY_MIB_SLOT_TIME */
value|\ 	1,
comment|/* RAY_MIB_ROAM_LOW_SNR_THRESH */
value|\ 	1,
comment|/* RAY_MIB_LOW_SNR_COUNT */
value|\ 	1,
comment|/* RAY_MIB_INFRA_MISSED_BEACON_COUNT */
value|\ 	1,
comment|/* RAY_MIB_ADHOC_MISSED_BEACON_COUNT */
value|\ 	1,
comment|/* RAY_MIB_COUNTRY_CODE */
value|\ 	1,
comment|/* RAY_MIB_HOP_SEQ */
value|\ 	1,
comment|/* RAY_MIB_HOP_SEQ_LEN */
value|\ 	2,
comment|/* RAY_MIB_CW_MAX */
value|\ 	2,
comment|/* RAY_MIB_CW_MIN */
value|\ 	1,
comment|/* RAY_MIB_NOISE_FILTER_GAIN */
value|\ 	1,
comment|/* RAY_MIB_NOISE_LIMIT_OFFSET */
value|\ 	1,
comment|/* RAY_MIB_RSSI_THRESH_OFFSET */
value|\ 	1,
comment|/* RAY_MIB_BUSY_THRESH_OFFSET */
value|\ 	1,
comment|/* RAY_MIB_SYNC_THRESH */
value|\ 	1,
comment|/* RAY_MIB_TEST_MODE */
value|\ 	1,
comment|/* RAY_MIB_TEST_MIN_CHAN */
value|\ 	1,
comment|/* RAY_MIB_TEST_MAX_CHAN */
value|\ 	1,
comment|/* RAY_MIB_ALLOW_PROBE_RESP */
value|\ 	1,
comment|/* RAY_MIB_PRIVACY_MUST_START */
value|\ 	1,
comment|/* RAY_MIB_PRIVACY_CAN_JOIN */
value|\ 	8,
comment|/* RAY_MIB_BASIC_RATE_SET */
value|\ 	1,
comment|/* RAY_MIB_VERSION */
value|\ 	ETHER_ADDR_LEN,
comment|/* RAY_MIB_CUR_BSSID */
value|\ 	1,
comment|/* RAY_MIB_CUR_INITED */
value|\ 	1,
comment|/* RAY_MIB_CUR_DEF_TXRATE */
value|\ 	1,
comment|/* RAY_MIB_CUR_ENCRYPT */
value|\ 	1,
comment|/* RAY_MIB_CUR_NET_TYPE */
value|\ 	IEEE80211_NWID_LEN,
comment|/* RAY_MIB_CUR_SSID */
value|\ 	1,
comment|/* RAY_MIB_CUR_PRIV_START */
value|\ 	1,
comment|/* RAY_MIB_CUR_PRIV_JOIN */
value|\ 	ETHER_ADDR_LEN,
comment|/* RAY_MIB_DES_BSSID */
value|\ 	1,
comment|/* RAY_MIB_DES_INITED */
value|\ 	1,
comment|/* RAY_MIB_DES_DEF_TXRATE */
value|\ 	1,
comment|/* RAY_MIB_DES_ENCRYPT */
value|\ 	1,
comment|/* RAY_MIB_DES_NET_TYPE */
value|\ 	IEEE80211_NWID_LEN,
comment|/* RAY_MIB_DES_SSID */
value|\ 	1,
comment|/* RAY_MIB_DES_PRIV_START */
value|\ 	1
comment|/* RAY_MIB_DES_PRIV_JOIN */
value|\ }
end_define

begin_comment
comment|/*  * MIB values  *  * I've included comments as to where the numbers have originated  * from.  *  * Linux refers to ray_cs.c and rayctl.h from version 167 of the  * Linux Raylink driver.  *  * NetBSD refers to if_ray.c from version 1.12 of the NetBSD Raylink  * driver.  *  * Symb refers to numbers cleaned from the 802.11 specification,  * discussion with 802.11 knowledgable people at Symbionics (i.e. me,  * aps, ifo, hjl).  *  * V4 and V5 refer to settings for version 4 and version 5 of  * the firmware.  *  */
end_comment

begin_comment
comment|/*  * ADHOC		- I've not got an access point  */
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
name|RAY_MIB_NET_TYPE_DEFAULT
value|RAY_MIB_NET_TYPE_ADHOC
end_define

begin_comment
comment|/*  * TERMINAL		- but we might play with using the card as an AP  */
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
name|RAY_MIB_AP_STATUS_DEFAULT
value|RAY_MIB_AP_STATUS_TERMINAL
end_define

begin_comment
comment|/*  * 			- windows setting comes from the Aviator software v1.1  */
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
name|RAY_MIB_SSID_NOT_WINDOWS
value|"WIRELESS_NETWORK"
end_define

begin_define
define|#
directive|define
name|RAY_MIB_SSID_DEFAULT
value|RAY_MIB_SSID_WINDOWS
end_define

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
name|RAY_MIB_SCAN_MODE_DEFAULT
value|RAY_MIB_SCAN_MODE_ACTIVE
end_define

begin_comment
comment|/*  * NONE			- power saving only works with access points  */
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
name|RAY_MIB_APM_MODE_DEFAULT
value|RAY_MIB_APM_MODE_NONE
end_define

begin_comment
comment|/*  * Linux.h	0x0200  * Linux.c-V4	0x7fff  * Linux.c-V5	0x7fff  * NetBSD.c	0x7fff	- disabled  * Symb		0xXXXX	- you really should fragment but getting it wrong  *			  crucifies the performance  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_FRAG_THRESH_DISABLE
value|0x7fff
end_define

begin_define
define|#
directive|define
name|RAY_MIB_FRAG_THRESH_DEFAULT
value|RAY_MIB_FRAG_THRESH_DISABLE
end_define

begin_comment
comment|/*  * Linux.h		- 16k * 2**n, n=0-4 in Kus  * Linux.c-V4	0x0200  * Linux.c-V5	0x0080	- 128 Kus  * NetBSD-V4	0x0200	- from Linux  * NetBSD-V4	0x0400	- "divined"  * NetBSD-V5	0x0080  * Symb-V4	0xXXXX	- 802.11 dwell time is XXX Kus  * Symb-V5	0xXXXX	- 802.11 dwell time is XXX Kus  * XXX			- see init_startup_params in Linux.c  */
end_comment

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
comment|/*  * Linux.h		- n * a_hop_time  in Kus  * Linux.c-V4	0x0001  * Linux.c-V5	0x0100	- 256 Kus  * NetBSD-V4	0x0001	- from Linux  * NetBSD-V4	0x0000	- "divined"  * NetBSD-V5	0x0100  * Symb-V4	0x0001	- best performance is one beacon each dwell XXX  * Symb-V5	0x0080	- best performance is one beacon each dwell XXX  * XXX			- see init_startup_params in Linux.c  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_BEACON_PERIOD_V4
value|0x01
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BEACON_PERIOD_V5
value|RAY_MIB_DWELL_TIME_V5
end_define

begin_comment
comment|/*  * Linux.h		- in beacons  * Linux.c	0x01  * NetBSD	0x01  * Symb		0xXX	- need to find out what DTIM is  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_DTIM_INTERVAL_DEFAULT
value|0x01
end_define

begin_comment
comment|/*  * Linux.c	0x07  * NetBSD	0x01	- documented default for 5/6  * NetBSD	0x07	- from Linux  * NetBSD	0x03	- "divined"  * Symb		0xXX	- 7 retries seems okay but check with APS  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_MAX_RETRY_DEFAULT
value|0x07
end_define

begin_comment
comment|/*  * Linux.c	0xa3  * NetBSD	0x86	- documented default for 5/6  * NetBSD	0xa3	- from Linux  * NetBSD	0xa3	- "divined"  * Symb		0xXX	- this must be a 802.11 defined setting?  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_ACK_TIMO_DEFAULT
value|0xa3
end_define

begin_comment
comment|/*  * Linux.c	0x1d  * NetBSD	0x1c	- documented default for 5/6  * NetBSD	0x1d	- from Linux  * NetBSD	0x1d	- "divined"  * Symb		0xXX	- default SIFS for 802.11  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_SIFS_DEFAULT
value|0x1d
end_define

begin_comment
comment|/*  * Linux.c	0x82  * NetBSD	0x82	- documented default for 5/6  * NetBSD	0x82	- from Linux  * Symb		0xXX	- default DIFS for 802.11  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_DIFS_DEFAULT
value|0x82
end_define

begin_comment
comment|/*  * Linux.c-V4	0xce  * Linux.c-V5	0x4e  * NetBSD	0x00	- documented default for 5/6  * NetBSD-V4	0xce	- from Linux  * NetBSD-V5	0x4e	- from Linux  * Symb		0xXX	- default PIFS for 802.11  */
end_comment

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
comment|/*  * Linux.c	0x7fff  * NetBSD	0x7fff	- disabled  * Symb		0xXXXX	- need to set this realistically to get CTS/RTS mode  *			  working right  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_RTS_THRESH_DISABLE
value|0x7fff
end_define

begin_define
define|#
directive|define
name|RAY_MIB_RTS_THRESH_DEFAULT
value|RAY_MIB_RTS_THRESH_DISABLE
end_define

begin_comment
comment|/*  * Linux.c-V4	0xfb1e  * Linix.c-V5	0x04e2  * NetBSD-V4	0xfb1e  * NetBSD-V5	0x04e2  * Symb		0xXXXX	- this might be the time to dwell on a channel  *			  whilst scanning for the n/w. In that case it should  *			  be tied to the dwell time above.  *			  V5 numbers could be Kus,  *			    0x04e2Kus = 1250*1024us = 1.28 seconds  */
end_comment

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
comment|/*  * Linux.c-V4	0xc75c  * Linix.c-V5	0x38a4  * NetBSD-V4	0xc75c  * NetBSD-V5	0x38a4  * Symb		0xXXXX	- see above - this may be total time before giving up  *			  but 0x38a4 Kus is about 14 seconds  *			  i.e. not 79*SCAN_DWELL  */
end_comment

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
comment|/*  * Linix.c	0x05  * NetBSD	0x05  * Symb		0xXX	- can't be in Kus too short  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_ASSOC_TIMO_DEFAULT
value|0x05
end_define

begin_comment
comment|/*  * Linix.c-V4	0x04  * Linux.c-V5	0x08  * NetBSD-V4	0x04	- Linux  * NetBSD-V4	0x08	- "divined"  * NetBSD-V5	0x08  * Symb		0xXX	- hmm maybe this ties in with the DWELL_SCAN above?  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_SCAN_CYCLE_DEFAULT
value|0x08
end_define

begin_comment
comment|/*  * Linix.c	0x02  * NetBSD-V4	0x02	- Linux  * NetBSD-V4	0x01	- "divined"  * NetBSD-V5	0x02  * Symb		0xXX	- hmm maybe this ties in with the DWELL_SCAN above?  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_SCAN_CYCLE_DEFAULT
value|0x02
end_define

begin_comment
comment|/*  * Linix.c-V4	0x04  * Linux.c-V5	0x08  * NetBSD-V4	0x04	- Linux  * NetBSD-V4	0x18	- "divined"  * NetBSD-V5	0x08  * Symb		0xXX	- hmm maybe this ties in with the DWELL_SCAN above?  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_SUPER_SCAN_CYCLE_DEFAULT
value|0x08
end_define

begin_define
define|#
directive|define
name|RAY_MIB_PROMISC_DEFAULT
value|0x00
end_define

begin_define
define|#
directive|define
name|RAY_MIB_UNIQ_WORD_DEFAULT
value|0x0cbd
end_define

begin_comment
comment|/*  * Linux.c-V4	0x4e  * Linix.c-V5	0x32  * NetBSD-V4	0x4e	- Linux  * NetBSD-V4	0x18	- "divined"  * NetBSD-V5	0x32	- mentions spec. is 50us i.e. 0x32  * Symb		0xXX	- wtf 0x4e = 78  */
end_comment

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
comment|/*  * Linux.c	0xff  * NetBSD-V4	0xff	- Linux  * NetBSD-V4	0x30	- "divined"  * NetBSD-V5	0xff	- disabled  * NetBSD.h		- if below this inc count  * Symb		0xXX	- hmm is 0xff really disabled? need this to work  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_ROAM_LOW_SNR_THRESH_DISABLED
value|0xff
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ROAM_LOW_SNR_THRESH_DEFAULT
value|RAY_MIB_ROAM_LOW_SNR_THRESH_DISABLED
end_define

begin_comment
comment|/*  * Linux.c	0xff  * NetBSD	0x07	- "divined - check" and marked as disabled  * NetBSD	0xff	- disabled  * NetBSD.h		- roam after cnt below thrsh  * Symb		0xXX	- hmm is 0xff really disabled? need this to work  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_LOW_SNR_COUNT_DISABLED
value|0xff
end_define

begin_define
define|#
directive|define
name|RAY_MIB_LOW_SNR_COUNT_DEFAULT
value|RAY_MIB_LOW_SNR_COUNT_DISABLED
end_define

begin_comment
comment|/*  * Linux.c	0x05  * NetBSD	0x02	- documented default for 5/6  * NetBSD	0x05	- Linux  * NetBSD	0x07	- "divined - check, looks fishy"  * Symb		0xXX	- 5 missed beacons is probably okay  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_INFRA_MISSED_BEACON_COUNT_DEFAULT
value|0x05
end_define

begin_comment
comment|/*  * Linux.c	0xff  * NetBSD	0xff  * Symb		0xXX	- so what happens in adhoc if the beacon is missed?  *			  do we create our own beacon  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_MISSED_BEACON_COUNT_DISABLED
value|0xff
end_define

begin_define
define|#
directive|define
name|RAY_MIB_ADHOC_MISSED_BEACON_COUNT_DEFAULT
value|RAY_MIB_ADHOC_MISSED_BEACON_COUNT_DISABLED
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_USA
value|0x1
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_EUROPE
value|0x2
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_JAPAN
value|0x3
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_KOREA
value|0x4
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_SPAIN
value|0x5
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_FRANCE
value|0x6
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_ISRAEL
value|0x7
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_AUSTRALIA
value|0x8
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_JAPAN_TEST
value|0x9
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_MAX
value|0xa
end_define

begin_define
define|#
directive|define
name|RAY_MIB_COUNTRY_CODE_DEFAULT
value|RAY_MIB_COUNTRY_CODE_USA
end_define

begin_comment
comment|/*  * NetBSD.h		- no longer supported  */
end_comment

begin_define
define|#
directive|define
name|RAY_MIB_HOP_SEQ_DEFAULT
value|0x0b
end_define

begin_comment
comment|/*  * Linux.c-V4	0x4e  * Linix.c-V5	0x4f  * NetBSD-V4	0x4e  * NetBSD-V5	0x4f  * Symb		0xXX	- 0x4e = 78 so is it a cock up?  */
end_comment

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
name|RAY_MIB_BASIC_RATE_SET_MAX
value|5
end_define

begin_define
define|#
directive|define
name|RAY_MIB_BASIC_RATE_SET_DEFAULT
value|RAY_MIB_BASIC_RATE_SET_2000K
end_define

end_unit

