begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / dbus-based control interface  * Copyright (c) 2006, Dan Williams<dcbw@redhat.com> and Red Hat, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CTRL_IFACE_DBUS_H
end_ifndef

begin_define
define|#
directive|define
name|CTRL_IFACE_DBUS_H
end_define

begin_struct_decl
struct_decl|struct
name|wps_credential
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_CTRL_IFACE_DBUS
end_ifdef

begin_define
define|#
directive|define
name|WPAS_DBUS_OBJECT_PATH_MAX
value|150
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_SERVICE
value|"fi.epitest.hostap.WPASupplicant"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_PATH
value|"/fi/epitest/hostap/WPASupplicant"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_INTERFACE
value|"fi.epitest.hostap.WPASupplicant"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_PATH_INTERFACES
value|WPAS_DBUS_PATH "/Interfaces"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_IFACE_INTERFACE
value|WPAS_DBUS_INTERFACE ".Interface"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_NETWORKS_PART
value|"Networks"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_IFACE_NETWORK
value|WPAS_DBUS_INTERFACE ".Network"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_BSSIDS_PART
value|"BSSIDs"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_IFACE_BSSID
value|WPAS_DBUS_INTERFACE ".BSSID"
end_define

begin_comment
comment|/* Errors */
end_comment

begin_define
define|#
directive|define
name|WPAS_ERROR_INVALID_NETWORK
define|\
value|WPAS_DBUS_IFACE_INTERFACE ".InvalidNetwork"
end_define

begin_define
define|#
directive|define
name|WPAS_ERROR_INVALID_BSSID
define|\
value|WPAS_DBUS_IFACE_INTERFACE ".InvalidBSSID"
end_define

begin_define
define|#
directive|define
name|WPAS_ERROR_INVALID_OPTS
define|\
value|WPAS_DBUS_INTERFACE ".InvalidOptions"
end_define

begin_define
define|#
directive|define
name|WPAS_ERROR_INVALID_IFACE
define|\
value|WPAS_DBUS_INTERFACE ".InvalidInterface"
end_define

begin_define
define|#
directive|define
name|WPAS_ERROR_ADD_ERROR
define|\
value|WPAS_DBUS_INTERFACE ".AddError"
end_define

begin_define
define|#
directive|define
name|WPAS_ERROR_EXISTS_ERROR
define|\
value|WPAS_DBUS_INTERFACE ".ExistsError"
end_define

begin_define
define|#
directive|define
name|WPAS_ERROR_REMOVE_ERROR
define|\
value|WPAS_DBUS_INTERFACE ".RemoveError"
end_define

begin_define
define|#
directive|define
name|WPAS_ERROR_SCAN_ERROR
define|\
value|WPAS_DBUS_IFACE_INTERFACE ".ScanError"
end_define

begin_define
define|#
directive|define
name|WPAS_ERROR_ADD_NETWORK_ERROR
define|\
value|WPAS_DBUS_IFACE_INTERFACE ".AddNetworkError"
end_define

begin_define
define|#
directive|define
name|WPAS_ERROR_INTERNAL_ERROR
define|\
value|WPAS_DBUS_IFACE_INTERFACE ".InternalError"
end_define

begin_define
define|#
directive|define
name|WPAS_ERROR_REMOVE_NETWORK_ERROR
define|\
value|WPAS_DBUS_IFACE_INTERFACE ".RemoveNetworkError"
end_define

begin_define
define|#
directive|define
name|WPAS_ERROR_WPS_PBC_ERROR
define|\
value|WPAS_DBUS_IFACE_INTERFACE ".WpsPbcError"
end_define

begin_define
define|#
directive|define
name|WPAS_ERROR_WPS_PIN_ERROR
define|\
value|WPAS_DBUS_IFACE_INTERFACE ".WpsPinError"
end_define

begin_define
define|#
directive|define
name|WPAS_ERROR_WPS_REG_ERROR
define|\
value|WPAS_DBUS_IFACE_INTERFACE ".WpsRegError"
end_define

begin_define
define|#
directive|define
name|WPAS_DBUS_BSSID_FORMAT
value|"%02x%02x%02x%02x%02x%02x"
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

begin_function_decl
name|int
name|wpa_supplicant_dbus_ctrl_iface_init
parameter_list|(
name|struct
name|wpas_dbus_priv
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_supplicant_dbus_notify_scan_results
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
name|wpa_supplicant_dbus_notify_scanning
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
name|wpa_supplicant_dbus_notify_state_change
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|enum
name|wpa_states
name|new_state
parameter_list|,
name|enum
name|wpa_states
name|old_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_supplicant_dbus_notify_wps_cred
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
name|wpa_supplicant_dbus_notify_certification
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|depth
parameter_list|,
specifier|const
name|char
modifier|*
name|subject
parameter_list|,
specifier|const
name|char
modifier|*
name|cert_hash
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|cert
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|wpas_dbus_decompose_object_path
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
modifier|*
name|network
parameter_list|,
name|char
modifier|*
modifier|*
name|bssid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpas_dbus_register_iface
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
name|wpas_dbus_unregister_iface
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Methods internal to the dbus control interface */
end_comment

begin_function_decl
name|struct
name|wpa_supplicant
modifier|*
name|wpa_supplicant_get_iface_by_dbus_path
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_CTRL_IFACE_DBUS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|wpa_supplicant_dbus_notify_scan_results
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
name|void
name|wpa_supplicant_dbus_notify_scanning
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
block|{ }
end_function

begin_define
define|#
directive|define
name|wpa_supplicant_dbus_notify_state_change
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
name|wpa_supplicant_dbus_notify_wps_cred
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
name|wpa_supplicant_dbus_notify_certification
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|depth
parameter_list|,
specifier|const
name|char
modifier|*
name|subject
parameter_list|,
specifier|const
name|char
modifier|*
name|cert_hash
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|cert
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|wpas_dbus_register_iface
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
name|wpas_dbus_unregister_iface
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_CTRL_IFACE_DBUS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CTRL_IFACE_DBUS_H */
end_comment

end_unit

