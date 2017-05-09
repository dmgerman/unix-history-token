begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Based on BSD-licensed source modules in the Linux iwlwifi driver,  * which were used as the reference documentation for this implementation.  *  ******************************************************************************  *  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2013 - 2014 Intel Corporation. All rights reserved.  * Copyright(c) 2013 - 2015 Intel Mobile Communications GmbH  * Copyright(c) 2015        Intel Deutschland GmbH  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110,  * USA  *  * The full GNU General Public License is included in this distribution  * in the file called COPYING.  *  * Contact Information:  *  Intel Linux Wireless<linuxwifi@intel.com>  * Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497  *  * BSD LICENSE  *  * Copyright(c) 2013 - 2014 Intel Corporation. All rights reserved.  * Copyright(c) 2013 - 2015 Intel Mobile Communications GmbH  * Copyright(c) 2015        Intel Deutschland GmbH  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *  * Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * Neither the name Intel Corporation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *****************************************************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_IWM_CONSTANTS_H
end_ifndef

begin_define
define|#
directive|define
name|__IF_IWM_CONSTANTS_H
end_define

begin_comment
comment|/*<netproto/802_11/ieee80211_var.h> */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_DEFAULT_PS_TX_DATA_TIMEOUT
value|(100 * 1000)
end_define

begin_define
define|#
directive|define
name|IWM_MVM_DEFAULT_PS_RX_DATA_TIMEOUT
value|(100 * 1000)
end_define

begin_define
define|#
directive|define
name|IWM_MVM_WOWLAN_PS_TX_DATA_TIMEOUT
value|(10 * 1000)
end_define

begin_define
define|#
directive|define
name|IWM_MVM_WOWLAN_PS_RX_DATA_TIMEOUT
value|(10 * 1000)
end_define

begin_define
define|#
directive|define
name|IWM_MVM_SHORT_PS_TX_DATA_TIMEOUT
value|(2 * 1024)
end_define

begin_comment
comment|/* defined in TU */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_SHORT_PS_RX_DATA_TIMEOUT
value|(40 * 1024)
end_define

begin_comment
comment|/* defined in TU */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_P2P_LOWLATENCY_PS_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|IWM_MVM_UAPSD_RX_DATA_TIMEOUT
value|(50 * 1000)
end_define

begin_define
define|#
directive|define
name|IWM_MVM_UAPSD_TX_DATA_TIMEOUT
value|(50 * 1000)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_comment
comment|/* XXX Find corresponding values from net80211 */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_UAPSD_QUEUES
value|(IEEE80211_WMM_IE_STA_QOSINFO_AC_VO |\ 					 IEEE80211_WMM_IE_STA_QOSINFO_AC_VI |\ 					 IEEE80211_WMM_IE_STA_QOSINFO_AC_BK |\ 					 IEEE80211_WMM_IE_STA_QOSINFO_AC_BE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IWM_MVM_PS_HEAVY_TX_THLD_PACKETS
value|20
end_define

begin_define
define|#
directive|define
name|IWM_MVM_PS_HEAVY_RX_THLD_PACKETS
value|8
end_define

begin_define
define|#
directive|define
name|IWM_MVM_PS_SNOOZE_HEAVY_TX_THLD_PACKETS
value|30
end_define

begin_define
define|#
directive|define
name|IWM_MVM_PS_SNOOZE_HEAVY_RX_THLD_PACKETS
value|20
end_define

begin_define
define|#
directive|define
name|IWM_MVM_PS_HEAVY_TX_THLD_PERCENT
value|50
end_define

begin_define
define|#
directive|define
name|IWM_MVM_PS_HEAVY_RX_THLD_PERCENT
value|50
end_define

begin_define
define|#
directive|define
name|IWM_MVM_PS_SNOOZE_INTERVAL
value|25
end_define

begin_define
define|#
directive|define
name|IWM_MVM_PS_SNOOZE_WINDOW
value|50
end_define

begin_define
define|#
directive|define
name|IWM_MVM_WOWLAN_PS_SNOOZE_WINDOW
value|25
end_define

begin_define
define|#
directive|define
name|IWM_MVM_LOWLAT_QUOTA_MIN_PERCENT
value|64
end_define

begin_define
define|#
directive|define
name|IWM_MVM_BT_COEX_EN_RED_TXP_THRESH
value|62
end_define

begin_define
define|#
directive|define
name|IWM_MVM_BT_COEX_DIS_RED_TXP_THRESH
value|65
end_define

begin_define
define|#
directive|define
name|IWM_MVM_BT_COEX_SYNC2SCO
value|1
end_define

begin_define
define|#
directive|define
name|IWM_MVM_BT_COEX_CORUNNING
value|0
end_define

begin_define
define|#
directive|define
name|IWM_MVM_BT_COEX_MPLUT
value|1
end_define

begin_define
define|#
directive|define
name|IWM_MVM_BT_COEX_RRC
value|1
end_define

begin_define
define|#
directive|define
name|IWM_MVM_BT_COEX_TTC
value|1
end_define

begin_define
define|#
directive|define
name|IWM_MVM_BT_COEX_MPLUT_REG0
value|0x22002200
end_define

begin_define
define|#
directive|define
name|IWM_MVM_BT_COEX_MPLUT_REG1
value|0x11118451
end_define

begin_define
define|#
directive|define
name|IWM_MVM_BT_COEX_ANTENNA_COUPLING_THRS
value|30
end_define

begin_define
define|#
directive|define
name|IWM_MVM_FW_MCAST_FILTER_PASS_ALL
value|0
end_define

begin_define
define|#
directive|define
name|IWM_MVM_FW_BCAST_FILTER_PASS_ALL
value|0
end_define

begin_define
define|#
directive|define
name|IWM_MVM_QUOTA_THRESHOLD
value|4
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_RSSI_BASED_INIT_RATE
value|0
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_80_20_FAR_RANGE_TWEAK
value|1
end_define

begin_define
define|#
directive|define
name|IWM_MVM_TOF_IS_RESPONDER
value|0
end_define

begin_define
define|#
directive|define
name|IWM_MVM_SW_TX_CSUM_OFFLOAD
value|0
end_define

begin_define
define|#
directive|define
name|IWM_MVM_HW_CSUM_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|IWM_MVM_COLLECT_FW_ERR_DUMP
value|1
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_NUM_TRY_BEFORE_ANT_TOGGLE
value|1
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_HT_VHT_RETRIES_PER_RATE
value|2
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_HT_VHT_RETRIES_PER_RATE_TW
value|1
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_INITIAL_MIMO_NUM_RATES
value|3
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_INITIAL_SISO_NUM_RATES
value|3
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_INITIAL_LEGACY_NUM_RATES
value|2
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_INITIAL_LEGACY_RETRIES
value|2
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_SECONDARY_LEGACY_RETRIES
value|1
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_SECONDARY_LEGACY_NUM_RATES
value|16
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_SECONDARY_SISO_NUM_RATES
value|3
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_SECONDARY_SISO_RETRIES
value|1
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_RATE_MIN_FAILURE_TH
value|3
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_RATE_MIN_SUCCESS_TH
value|8
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_STAY_IN_COLUMN_TIMEOUT
value|5
end_define

begin_comment
comment|/* Seconds */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_RS_IDLE_TIMEOUT
value|5
end_define

begin_comment
comment|/* Seconds */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_RS_MISSED_RATE_MAX
value|15
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_LEGACY_FAILURE_LIMIT
value|160
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_LEGACY_SUCCESS_LIMIT
value|480
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_LEGACY_TABLE_COUNT
value|160
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_NON_LEGACY_FAILURE_LIMIT
value|400
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_NON_LEGACY_SUCCESS_LIMIT
value|4500
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_NON_LEGACY_TABLE_COUNT
value|1500
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_SR_FORCE_DECREASE
value|15
end_define

begin_comment
comment|/* percent */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_RS_SR_NO_DECREASE
value|85
end_define

begin_comment
comment|/* percent */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_RS_AGG_TIME_LIMIT
value|4000
end_define

begin_comment
comment|/* 4 msecs. valid 100-8000 */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_RS_AGG_DISABLE_START
value|3
end_define

begin_define
define|#
directive|define
name|IWM_MVM_RS_TPC_SR_FORCE_INCREASE
value|75
end_define

begin_comment
comment|/* percent */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_RS_TPC_SR_NO_INCREASE
value|85
end_define

begin_comment
comment|/* percent */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_RS_TPC_TX_POWER_STEP
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_IWM_CONSTANTS_H */
end_comment

end_unit

