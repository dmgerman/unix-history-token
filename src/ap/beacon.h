begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / IEEE 802.11 Management: Beacon and Probe Request/Response  * Copyright (c) 2002-2004, Instant802 Networks, Inc.  * Copyright (c) 2005-2006, Devicescape Software, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BEACON_H
end_ifndef

begin_define
define|#
directive|define
name|BEACON_H
end_define

begin_struct_decl
struct_decl|struct
name|ieee80211_mgmt
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|handle_probe_req
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|struct
name|ieee80211_mgmt
modifier|*
name|mgmt
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|ssi_signal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee802_11_set_beacon
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee802_11_set_beacons
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
name|ieee802_11_update_beacons
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
name|ieee802_11_build_ap_params
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|wpa_driver_ap_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_11_free_ap_params
parameter_list|(
name|struct
name|wpa_driver_ap_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sta_track_add
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sta_track_expire
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|,
name|int
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostapd_data
modifier|*
name|sta_track_seen_on
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|char
modifier|*
name|ifname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BEACON_H */
end_comment

end_unit

