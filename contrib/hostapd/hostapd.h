begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / Initialization and configuration  * Host AP kernel driver  * Copyright (c) 2002-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOSTAPD_H
end_ifndef

begin_define
define|#
directive|define
name|HOSTAPD_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"ap.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_ALEN
end_ifndef

begin_define
define|#
directive|define
name|ETH_ALEN
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFNAMSIZ
end_ifndef

begin_define
define|#
directive|define
name|IFNAMSIZ
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_P_ALL
end_ifndef

begin_define
define|#
directive|define
name|ETH_P_ALL
value|0x0003
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_P_PAE
end_ifndef

begin_define
define|#
directive|define
name|ETH_P_PAE
value|0x888E
end_define

begin_comment
comment|/* Port Access Entity (IEEE 802.1X) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ETH_P_PAE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT
end_ifndef

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAC2STR
end_ifndef

begin_define
define|#
directive|define
name|MAC2STR
parameter_list|(
name|a
parameter_list|)
value|(a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
end_define

begin_define
define|#
directive|define
name|MACSTR
value|"%02x:%02x:%02x:%02x:%02x:%02x"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_define
define|#
directive|define
name|MAX_VLAN_ID
value|4094
end_define

begin_struct
struct|struct
name|ieee8023_hdr
block|{
name|u8
name|dest
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|src
index|[
literal|6
index|]
decl_stmt|;
name|u16
name|ethertype
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_hdr
block|{
name|u16
name|frame_control
decl_stmt|;
name|u16
name|duration_id
decl_stmt|;
name|u8
name|addr1
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|addr2
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|addr3
index|[
literal|6
index|]
decl_stmt|;
name|u16
name|seq_ctrl
decl_stmt|;
comment|/* followed by 'u8 addr4[6];' if ToDS and FromDS is set in data frame 	 */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DA_FROMDS
value|addr1
end_define

begin_define
define|#
directive|define
name|IEEE80211_BSSID_FROMDS
value|addr2
end_define

begin_define
define|#
directive|define
name|IEEE80211_SA_FROMDS
value|addr3
end_define

begin_define
define|#
directive|define
name|IEEE80211_HDRLEN
value|(sizeof(struct ieee80211_hdr))
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC
parameter_list|(
name|type
parameter_list|,
name|stype
parameter_list|)
value|host_to_le16((type<< 2) | (stype<< 4))
end_define

begin_comment
comment|/* MTU to be set for the wlan#ap device; this is mainly needed for IEEE 802.1X  * frames that might be longer than normal default MTU and they are not  * fragmented */
end_comment

begin_define
define|#
directive|define
name|HOSTAPD_MTU
value|2290
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|rfc1042_header
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|hostap_sta_driver_data
block|{
name|unsigned
name|long
name|rx_packets
decl_stmt|,
name|tx_packets
decl_stmt|,
name|rx_bytes
decl_stmt|,
name|tx_bytes
decl_stmt|;
name|unsigned
name|long
name|current_tx_rate
decl_stmt|;
name|unsigned
name|long
name|inactive_msec
decl_stmt|;
name|unsigned
name|long
name|flags
decl_stmt|;
name|unsigned
name|long
name|num_ps_buf_frames
decl_stmt|;
name|unsigned
name|long
name|tx_retry_failed
decl_stmt|;
name|unsigned
name|long
name|tx_retry_count
decl_stmt|;
name|int
name|last_rssi
decl_stmt|;
name|int
name|last_ack_rssi
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|driver_ops
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wpa_ctrl_dst
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|radius_server_data
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_FULL_DYNAMIC_VLAN
end_ifdef

begin_struct_decl
struct_decl|struct
name|full_dynamic_vlan
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_FULL_DYNAMIC_VLAN */
end_comment

begin_comment
comment|/**  * struct hostapd_data - hostapd per-BSS data structure  */
end_comment

begin_struct
struct|struct
name|hostapd_data
block|{
name|struct
name|hostapd_iface
modifier|*
name|iface
decl_stmt|;
name|struct
name|hostapd_config
modifier|*
name|iconf
decl_stmt|;
name|struct
name|hostapd_bss_config
modifier|*
name|conf
decl_stmt|;
name|int
name|interface_added
decl_stmt|;
comment|/* virtual interface added for this BSS */
name|u8
name|own_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|int
name|num_sta
decl_stmt|;
comment|/* number of entries in sta_list */
name|struct
name|sta_info
modifier|*
name|sta_list
decl_stmt|;
comment|/* STA info list head */
name|struct
name|sta_info
modifier|*
name|sta_hash
index|[
name|STA_HASH_SIZE
index|]
decl_stmt|;
comment|/* pointers to STA info; based on allocated AID or NULL if AID free 	 * AID is in the range 1-2007, so sta_aid[0] corresponders to AID 1 	 * and so on 	 */
name|struct
name|sta_info
modifier|*
name|sta_aid
index|[
name|MAX_AID_TABLE_SIZE
index|]
decl_stmt|;
name|struct
name|driver_ops
modifier|*
name|driver
decl_stmt|;
name|u8
modifier|*
name|default_wep_key
decl_stmt|;
name|u8
name|default_wep_key_idx
decl_stmt|;
name|struct
name|radius_client_data
modifier|*
name|radius
decl_stmt|;
name|int
name|radius_client_reconfigured
decl_stmt|;
name|u32
name|acct_session_id_hi
decl_stmt|,
name|acct_session_id_lo
decl_stmt|;
name|struct
name|iapp_data
modifier|*
name|iapp
decl_stmt|;
enum|enum
block|{
name|DO_NOT_ASSOC
init|=
literal|0
block|,
name|WAIT_BEACON
block|,
name|AUTHENTICATE
block|,
name|ASSOCIATE
block|,
name|ASSOCIATED
block|}
name|assoc_ap_state
enum|;
name|char
name|assoc_ap_ssid
index|[
literal|33
index|]
decl_stmt|;
name|int
name|assoc_ap_ssid_len
decl_stmt|;
name|u16
name|assoc_ap_aid
decl_stmt|;
name|struct
name|hostapd_cached_radius_acl
modifier|*
name|acl_cache
decl_stmt|;
name|struct
name|hostapd_acl_query_data
modifier|*
name|acl_queries
decl_stmt|;
name|struct
name|wpa_authenticator
modifier|*
name|wpa_auth
decl_stmt|;
name|struct
name|rsn_preauth_interface
modifier|*
name|preauth_iface
decl_stmt|;
name|time_t
name|michael_mic_failure
decl_stmt|;
name|int
name|michael_mic_failures
decl_stmt|;
name|int
name|tkip_countermeasures
decl_stmt|;
name|int
name|ctrl_sock
decl_stmt|;
name|struct
name|wpa_ctrl_dst
modifier|*
name|ctrl_dst
decl_stmt|;
name|void
modifier|*
name|ssl_ctx
decl_stmt|;
name|void
modifier|*
name|eap_sim_db_priv
decl_stmt|;
name|struct
name|radius_server_data
modifier|*
name|radius_srv
decl_stmt|;
name|int
name|parameter_set_count
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_FULL_DYNAMIC_VLAN
name|struct
name|full_dynamic_vlan
modifier|*
name|full_dynamic_vlan
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_FULL_DYNAMIC_VLAN */
block|}
struct|;
end_struct

begin_comment
comment|/**  * hostapd_iface_cb - Generic callback type for per-iface asynchronous requests  * @iface: the interface the event occured on.  * @status: 0 if the request succeeded; -1 if the request failed.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|hostapd_iface_cb
function_decl|)
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|,
name|int
name|status
parameter_list|)
function_decl|;
end_typedef

begin_struct_decl
struct_decl|struct
name|hostapd_config_change
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * struct hostapd_iface - hostapd per-interface data structure  */
end_comment

begin_struct
struct|struct
name|hostapd_iface
block|{
name|char
modifier|*
name|config_fname
decl_stmt|;
name|struct
name|hostapd_config
modifier|*
name|conf
decl_stmt|;
name|hostapd_iface_cb
name|setup_cb
decl_stmt|;
name|size_t
name|num_bss
decl_stmt|;
name|struct
name|hostapd_data
modifier|*
modifier|*
name|bss
decl_stmt|;
name|int
name|num_ap
decl_stmt|;
comment|/* number of entries in ap_list */
name|struct
name|ap_info
modifier|*
name|ap_list
decl_stmt|;
comment|/* AP info list head */
name|struct
name|ap_info
modifier|*
name|ap_hash
index|[
name|STA_HASH_SIZE
index|]
decl_stmt|;
name|struct
name|ap_info
modifier|*
name|ap_iter_list
decl_stmt|;
name|struct
name|hostapd_hw_modes
modifier|*
name|hw_features
decl_stmt|;
name|int
name|num_hw_features
decl_stmt|;
name|struct
name|hostapd_hw_modes
modifier|*
name|current_mode
decl_stmt|;
comment|/* Rates that are currently used (i.e., filtered copy of 	 * current_mode->channels */
name|int
name|num_rates
decl_stmt|;
name|struct
name|hostapd_rate_data
modifier|*
name|current_rates
decl_stmt|;
name|hostapd_iface_cb
name|hw_mode_sel_cb
decl_stmt|;
name|u16
name|hw_flags
decl_stmt|;
comment|/* Number of associated Non-ERP stations (i.e., stations using 802.11b 	 * in 802.11g BSS) */
name|int
name|num_sta_non_erp
decl_stmt|;
comment|/* Number of associated stations that do not support Short Slot Time */
name|int
name|num_sta_no_short_slot_time
decl_stmt|;
comment|/* Number of associated stations that do not support Short Preamble */
name|int
name|num_sta_no_short_preamble
decl_stmt|;
name|int
name|olbc
decl_stmt|;
comment|/* Overlapping Legacy BSS Condition */
name|int
name|dfs_enable
decl_stmt|;
name|u8
name|pwr_const
decl_stmt|;
name|unsigned
name|int
name|tx_power
decl_stmt|;
name|unsigned
name|int
name|sta_max_power
decl_stmt|;
name|unsigned
name|int
name|channel_switch
decl_stmt|;
name|struct
name|hostapd_config_change
modifier|*
name|change
decl_stmt|;
name|hostapd_iface_cb
name|reload_iface_cb
decl_stmt|;
name|hostapd_iface_cb
name|config_reload_cb
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|hostapd_new_assoc_sta
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
name|int
name|reassoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hostapd_logger
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|unsigned
name|int
name|module
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|PRINTF_FORMAT
parameter_list|(
function_decl|5
operator|,
function_decl|6
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_MSC_VER
end_ifndef

begin_define
define|#
directive|define
name|HOSTAPD_DEBUG
parameter_list|(
name|level
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do { \ 	if (hapd->conf == NULL || hapd->conf->debug>= (level)) \ 		printf(args); \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_define
define|#
directive|define
name|HOSTAPD_DEBUG_COND
parameter_list|(
name|level
parameter_list|)
value|(hapd->conf->debug>= (level))
end_define

begin_function_decl
specifier|const
name|char
modifier|*
name|hostapd_ip_txt
parameter_list|(
specifier|const
name|struct
name|hostapd_ip_addr
modifier|*
name|addr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_ip_diff
parameter_list|(
name|struct
name|hostapd_ip_addr
modifier|*
name|a
parameter_list|,
name|struct
name|hostapd_ip_addr
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HOSTAPD_H */
end_comment

end_unit

