begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / AP table  * Copyright 2002-2003, Jouni Malinen<j@w1.fi>  * Copyright 2003-2004, Instant802 Networks, Inc.  * Copyright 2006, Devicescape Software, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AP_LIST_H
end_ifndef

begin_define
define|#
directive|define
name|AP_LIST_H
end_define

begin_struct
struct|struct
name|ap_info
block|{
comment|/* Note: next/prev pointers are updated whenever a new beacon is 	 * received because these are used to find the least recently used 	 * entries. iter_next/iter_prev are updated only when adding new BSSes 	 * and when removing old ones. These should be used when iterating 	 * through the table in a manner that allows beacons to be received 	 * during the iteration. */
name|struct
name|ap_info
modifier|*
name|next
decl_stmt|;
comment|/* next entry in AP list */
name|struct
name|ap_info
modifier|*
name|prev
decl_stmt|;
comment|/* previous entry in AP list */
name|struct
name|ap_info
modifier|*
name|hnext
decl_stmt|;
comment|/* next entry in hash table list */
name|struct
name|ap_info
modifier|*
name|iter_next
decl_stmt|;
comment|/* next entry in AP iteration list */
name|struct
name|ap_info
modifier|*
name|iter_prev
decl_stmt|;
comment|/* previous entry in AP iteration list */
name|u8
name|addr
index|[
literal|6
index|]
decl_stmt|;
name|u16
name|beacon_int
decl_stmt|;
name|u16
name|capability
decl_stmt|;
name|u8
name|supported_rates
index|[
name|WLAN_SUPP_RATES_MAX
index|]
decl_stmt|;
name|u8
name|ssid
index|[
literal|33
index|]
decl_stmt|;
name|size_t
name|ssid_len
decl_stmt|;
name|int
name|wpa
decl_stmt|;
name|int
name|erp
decl_stmt|;
comment|/* ERP Info or -1 if ERP info element not present */
name|int
name|phytype
decl_stmt|;
comment|/* .11a / .11b / .11g / Atheros Turbo */
name|int
name|channel
decl_stmt|;
name|int
name|datarate
decl_stmt|;
comment|/* in 100 kbps */
name|int
name|ssi_signal
decl_stmt|;
name|unsigned
name|int
name|num_beacons
decl_stmt|;
comment|/* number of beacon frames received */
name|time_t
name|last_beacon
decl_stmt|;
name|int
name|already_seen
decl_stmt|;
comment|/* whether API call AP-NEW has already fetched 			   * information about this AP */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ieee802_11_elems
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hostapd_frame_info
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|ap_info
modifier|*
name|ap_get_ap
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|,
name|u8
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ap_ap_for_each
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|,
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|ap_info
modifier|*
name|s
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_list_process_beacon
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|,
name|struct
name|ieee80211_mgmt
modifier|*
name|mgmt
parameter_list|,
name|struct
name|ieee802_11_elems
modifier|*
name|elems
parameter_list|,
name|struct
name|hostapd_frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ap_list_init
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_list_deinit
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ap_list_reconfig
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|,
name|struct
name|hostapd_config
modifier|*
name|oldconf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AP_LIST_H */
end_comment

end_unit

