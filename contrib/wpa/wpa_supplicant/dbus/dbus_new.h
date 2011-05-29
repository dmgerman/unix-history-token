begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / dbus-based control interface  * Copyright (c) 2006, Dan Williams<dcbw@redhat.com> and Red Hat, Inc.  * Copyright (c) 2009-2010, Witold Sowa<witold.sowa@gmail.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CTRL_IFACE_DBUS_NEW_H
end_ifndef

begin_define
define|#
directive|define
name|CTRL_IFACE_DBUS_NEW_H
end_define

begin_struct_decl
struct_decl|struct
name|wpa_global
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wpa_supplicant
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wpa_ssid
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wps_event_m2d
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wps_event_fail
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wps_credential
struct_decl|;
end_struct_decl

begin_enum_decl
enum_decl|enum
name|wpa_states
enum_decl|;
end_enum_decl

begin_enum
enum|enum
name|wpas_dbus_prop
block|{
name|WPAS_DBUS_PROP_AP_SCAN
block|,
name|WPAS_DBUS_PROP_SCANNING
block|,
name|WPAS_DBUS_PROP_STATE
block|,
name|WPAS_DBUS_PROP_CURRENT_BSS
block|,
name|WPAS_DBUS_PROP_CURRENT_NETWORK
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|wpas_dbus_bss_prop
block|{
name|WPAS_DBUS_BSS_PROP_SIGNAL
block|,
name|WPAS_DBUS_BSS_PROP_FREQ
block|,
name|WPAS_DBUS_BSS_PROP_MODE
block|,
name|WPAS_DBUS_BSS_PROP_PRIVACY
block|,
name|WPAS_DBUS_BSS_PROP_RATES
block|,
name|WPAS_DBUS_BSS_PROP_WPA
block|,
name|WPAS_DBUS_BSS_PROP_RSN
block|,
name|WPAS_DBUS_BSS_PROP_IES
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|WPAS_DBUS_OBJECT_PATH_MAX
value|150
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_NEW_SERVICE
value|"fi.w1.wpa_supplicant1"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_NEW_PATH
value|"/fi/w1/wpa_supplicant1"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_NEW_INTERFACE
value|"fi.w1.wpa_supplicant1"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_NEW_PATH_INTERFACES
value|WPAS_DBUS_NEW_PATH "/Interfaces"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_NEW_IFACE_INTERFACE
value|WPAS_DBUS_NEW_INTERFACE ".Interface"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_NEW_IFACE_WPS
value|WPAS_DBUS_NEW_IFACE_INTERFACE ".WPS"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_NEW_NETWORKS_PART
value|"Networks"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_NEW_IFACE_NETWORK
value|WPAS_DBUS_NEW_INTERFACE ".Network"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_NEW_BSSIDS_PART
value|"BSSs"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_NEW_IFACE_BSS
value|WPAS_DBUS_NEW_INTERFACE ".BSS"
end_define

begin_comment
comment|/* Errors */
end_comment

begin_define
define|#
directive|define
name|WPAS_DBUS_ERROR_UNKNOWN_ERROR
define|\
value|WPAS_DBUS_NEW_INTERFACE ".UnknownError"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_ERROR_INVALID_ARGS
define|\
value|WPAS_DBUS_NEW_INTERFACE ".InvalidArgs"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_ERROR_IFACE_EXISTS
define|\
value|WPAS_DBUS_NEW_INTERFACE ".InterfaceExists"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_ERROR_IFACE_UNKNOWN
define|\
value|WPAS_DBUS_NEW_INTERFACE ".InterfaceUnknown"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_ERROR_NOT_CONNECTED
define|\
value|WPAS_DBUS_NEW_INTERFACE ".NotConnected"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_ERROR_NETWORK_UNKNOWN
define|\
value|WPAS_DBUS_NEW_INTERFACE ".NetworkUnknown"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_ERROR_BLOB_EXISTS
define|\
value|WPAS_DBUS_NEW_INTERFACE ".BlobExists"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_ERROR_BLOB_UNKNOWN
define|\
value|WPAS_DBUS_NEW_INTERFACE ".BlobUnknown"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_CTRL_IFACE_DBUS_NEW
end_ifdef

begin_function_decl
name|int
name|wpas_dbus_ctrl_iface_init
parameter_list|(
name|struct
name|wpas_dbus_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_ctrl_iface_deinit
parameter_list|(
name|struct
name|wpas_dbus_priv
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpas_dbus_register_interface
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpas_dbus_unregister_interface
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_signal_prop_changed
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|enum
name|wpas_dbus_prop
name|property
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_bss_signal_prop_changed
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|enum
name|wpas_dbus_bss_prop
name|property
parameter_list|,
name|unsigned
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_signal_network_enabled_changed
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_signal_network_selected
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_signal_scan_done
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|success
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_signal_wps_cred
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|struct
name|wps_credential
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_signal_wps_event_m2d
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wps_event_m2d
modifier|*
name|m2d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_signal_wps_event_fail
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wps_event_fail
modifier|*
name|fail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_signal_wps_event_success
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpas_dbus_register_network
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpas_dbus_unregister_network
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|nid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpas_dbus_unregister_bss
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
parameter_list|,
name|unsigned
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpas_dbus_register_bss
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
parameter_list|,
name|unsigned
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_signal_blob_added
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_signal_blob_removed
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_signal_debug_level_changed
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_signal_debug_timestamp_changed
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpas_dbus_signal_debug_show_keys_changed
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_CTRL_IFACE_DBUS_NEW */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|wpas_dbus_register_interface
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|wpas_dbus_unregister_interface
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_define
define|#
directive|define
name|wpas_dbus_signal_state_changed
parameter_list|(
name|w
parameter_list|,
name|n
parameter_list|,
name|o
parameter_list|)
value|do { } while (0)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_signal_prop_changed
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|enum
name|wpas_dbus_prop
name|property
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_bss_signal_prop_changed
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|enum
name|wpas_dbus_bss_prop
name|property
parameter_list|,
name|unsigned
name|int
name|id
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_signal_network_enabled_changed
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_signal_network_selected
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|id
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_signal_scan_done
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|success
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_signal_wps_cred
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|struct
name|wps_credential
modifier|*
name|cred
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_signal_wps_event_m2d
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wps_event_m2d
modifier|*
name|m2d
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_signal_wps_event_fail
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wps_event_fail
modifier|*
name|fail
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_signal_wps_event_success
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|wpas_dbus_register_network
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|wpas_dbus_unregister_network
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|nid
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|wpas_dbus_unregister_bss
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
parameter_list|,
name|unsigned
name|int
name|id
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|wpas_dbus_register_bss
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
parameter_list|,
name|unsigned
name|int
name|id
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_signal_blob_added
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_signal_blob_removed
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_signal_debug_level_changed
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_signal_debug_timestamp_changed
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpas_dbus_signal_debug_show_keys_changed
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_CTRL_IFACE_DBUS_NEW */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CTRL_IFACE_DBUS_H_NEW */
end_comment

end_unit

