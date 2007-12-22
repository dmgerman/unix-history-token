begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / Station table data structures  * Copyright (c) 2002-2004, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AP_H
end_ifndef

begin_define
define|#
directive|define
name|AP_H
end_define

begin_comment
comment|/* STA flags */
end_comment

begin_define
define|#
directive|define
name|WLAN_STA_AUTH
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_ASSOC
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_PS
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_TIM
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_PERM
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_AUTHORIZED
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_PENDING_POLL
value|BIT(6)
end_define

begin_comment
comment|/* pending activity poll not ACKed */
end_comment

begin_define
define|#
directive|define
name|WLAN_STA_SHORT_PREAMBLE
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_PREAUTH
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_WME
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_NONERP
value|BIT(31)
end_define

begin_comment
comment|/* Maximum number of supported rates (from both Supported Rates and Extended  * Supported Rates IEs). */
end_comment

begin_define
define|#
directive|define
name|WLAN_SUPP_RATES_MAX
value|32
end_define

begin_struct
struct|struct
name|sta_info
block|{
name|struct
name|sta_info
modifier|*
name|next
decl_stmt|;
comment|/* next entry in sta list */
name|struct
name|sta_info
modifier|*
name|hnext
decl_stmt|;
comment|/* next entry in hash table list */
name|u8
name|addr
index|[
literal|6
index|]
decl_stmt|;
name|u16
name|aid
decl_stmt|;
comment|/* STA's unique AID (1 .. 2007) or 0 if not yet assigned */
name|u32
name|flags
decl_stmt|;
name|u16
name|capability
decl_stmt|;
name|u16
name|listen_interval
decl_stmt|;
comment|/* or beacon_int for APs */
name|u8
name|supported_rates
index|[
name|WLAN_SUPP_RATES_MAX
index|]
decl_stmt|;
name|int
name|supported_rates_len
decl_stmt|;
name|unsigned
name|int
name|nonerp_set
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|no_short_slot_time_set
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|no_short_preamble_set
range|:
literal|1
decl_stmt|;
name|u16
name|auth_alg
decl_stmt|;
name|u8
name|previous_ap
index|[
literal|6
index|]
decl_stmt|;
enum|enum
block|{
name|STA_NULLFUNC
init|=
literal|0
block|,
name|STA_DISASSOC
block|,
name|STA_DEAUTH
block|,
name|STA_REMOVE
block|}
name|timeout_next
enum|;
comment|/* IEEE 802.1X related data */
name|struct
name|eapol_state_machine
modifier|*
name|eapol_sm
decl_stmt|;
comment|/* IEEE 802.11f (IAPP) related data */
name|struct
name|ieee80211_mgmt
modifier|*
name|last_assoc_req
decl_stmt|;
name|u32
name|acct_session_id_hi
decl_stmt|;
name|u32
name|acct_session_id_lo
decl_stmt|;
name|time_t
name|acct_session_start
decl_stmt|;
name|int
name|acct_session_started
decl_stmt|;
name|int
name|acct_terminate_cause
decl_stmt|;
comment|/* Acct-Terminate-Cause */
name|int
name|acct_interim_interval
decl_stmt|;
comment|/* Acct-Interim-Interval */
name|unsigned
name|long
name|last_rx_bytes
decl_stmt|;
name|unsigned
name|long
name|last_tx_bytes
decl_stmt|;
name|u32
name|acct_input_gigawords
decl_stmt|;
comment|/* Acct-Input-Gigawords */
name|u32
name|acct_output_gigawords
decl_stmt|;
comment|/* Acct-Output-Gigawords */
name|u8
modifier|*
name|challenge
decl_stmt|;
comment|/* IEEE 802.11 Shared Key Authentication Challenge */
name|struct
name|wpa_state_machine
modifier|*
name|wpa_sm
decl_stmt|;
name|struct
name|rsn_preauth_interface
modifier|*
name|preauth_iface
decl_stmt|;
name|struct
name|hostapd_ssid
modifier|*
name|ssid
decl_stmt|;
comment|/* SSID selection based on (Re)AssocReq */
name|struct
name|hostapd_ssid
modifier|*
name|ssid_probe
decl_stmt|;
comment|/* SSID selection based on ProbeReq */
name|int
name|vlan_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Maximum number of AIDs to use for STAs; must be 2007 or lower  * (8802.11 limitation) */
end_comment

begin_define
define|#
directive|define
name|MAX_AID_TABLE_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|STA_HASH_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|STA_HASH
parameter_list|(
name|sta
parameter_list|)
value|(sta[5])
end_define

begin_comment
comment|/* Default value for maximum station inactivity. After AP_MAX_INACTIVITY has  * passed since last received frame from the station, a nullfunc data frame is  * sent to the station. If this frame is not acknowledged and no other frames  * have been received, the station will be disassociated after  * AP_DISASSOC_DELAY seconds. Similarily, the station will be deauthenticated  * after AP_DEAUTH_DELAY seconds has passed after disassociation. */
end_comment

begin_define
define|#
directive|define
name|AP_MAX_INACTIVITY
value|(5 * 60)
end_define

begin_define
define|#
directive|define
name|AP_DISASSOC_DELAY
value|(1)
end_define

begin_define
define|#
directive|define
name|AP_DEAUTH_DELAY
value|(1)
end_define

begin_comment
comment|/* Number of seconds to keep STA entry with Authenticated flag after it has  * been disassociated. */
end_comment

begin_define
define|#
directive|define
name|AP_MAX_INACTIVITY_AFTER_DISASSOC
value|(1 * 30)
end_define

begin_comment
comment|/* Number of seconds to keep STA entry after it has been deauthenticated. */
end_comment

begin_define
define|#
directive|define
name|AP_MAX_INACTIVITY_AFTER_DEAUTH
value|(1 * 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AP_H */
end_comment

end_unit

