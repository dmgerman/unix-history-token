begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / Configuration file structures  * Copyright (c) 2003-2005, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_H
end_define

begin_define
define|#
directive|define
name|DEFAULT_EAPOL_VERSION
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NO_SCAN_PROCESSING
end_ifdef

begin_define
define|#
directive|define
name|DEFAULT_AP_SCAN
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NO_SCAN_PROCESSING */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_AP_SCAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NO_SCAN_PROCESSING */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_FAST_REAUTH
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_BSS_MAX_COUNT
value|200
end_define

begin_include
include|#
directive|include
file|"config_ssid.h"
end_include

begin_comment
comment|/**  * struct wpa_config - wpa_supplicant configuration data  *  * This data structure is presents the per-interface (radio) configuration  * data. In many cases, there is only one struct wpa_config instance, but if  * more than one network interface is being controlled, one instance is used  * for each.  */
end_comment

begin_struct
struct|struct
name|wpa_config
block|{
comment|/** 	 * ssid - Head of the global network list 	 * 	 * This is the head for the list of all the configured networks. 	 */
name|struct
name|wpa_ssid
modifier|*
name|ssid
decl_stmt|;
comment|/** 	 * pssid - Per-priority network lists (in priority order) 	 */
name|struct
name|wpa_ssid
modifier|*
modifier|*
name|pssid
decl_stmt|;
comment|/** 	 * num_prio - Number of different priorities used in the pssid lists 	 * 	 * This indicates how many per-priority network lists are included in 	 * pssid. 	 */
name|int
name|num_prio
decl_stmt|;
comment|/** 	 * eapol_version - IEEE 802.1X/EAPOL version number 	 * 	 * wpa_supplicant is implemented based on IEEE Std 802.1X-2004 which 	 * defines EAPOL version 2. However, there are many APs that do not 	 * handle the new version number correctly (they seem to drop the 	 * frames completely). In order to make wpa_supplicant interoperate 	 * with these APs, the version number is set to 1 by default. This 	 * configuration value can be used to set it to the new version (2). 	 */
name|int
name|eapol_version
decl_stmt|;
comment|/** 	 * ap_scan - AP scanning/selection 	 * 	 * By default, wpa_supplicant requests driver to perform AP 	 * scanning and then uses the scan results to select a 	 * suitable AP. Another alternative is to allow the driver to 	 * take care of AP scanning and selection and use 	 * wpa_supplicant just to process EAPOL frames based on IEEE 	 * 802.11 association information from the driver. 	 * 	 * 1: wpa_supplicant initiates scanning and AP selection (default). 	 * 	 * 0: Driver takes care of scanning, AP selection, and IEEE 802.11 	 * association parameters (e.g., WPA IE generation); this mode can 	 * also be used with non-WPA drivers when using IEEE 802.1X mode; 	 * do not try to associate with APs (i.e., external program needs 	 * to control association). This mode must also be used when using 	 * wired Ethernet drivers. 	 * 	 * 2: like 0, but associate with APs using security policy and SSID 	 * (but not BSSID); this can be used, e.g., with ndiswrapper and NDIS 	 * drivers to enable operation with hidden SSIDs and optimized roaming; 	 * in this mode, the network blocks in the configuration are tried 	 * one by one until the driver reports successful association; each 	 * network block should have explicit security policy (i.e., only one 	 * option in the lists) for key_mgmt, pairwise, group, proto variables. 	 */
name|int
name|ap_scan
decl_stmt|;
comment|/** 	 * ctrl_interface - Parameters for the control interface 	 * 	 * If this is specified, %wpa_supplicant will open a control interface 	 * that is available for external programs to manage %wpa_supplicant. 	 * The meaning of this string depends on which control interface 	 * mechanism is used. For all cases, the existance of this parameter 	 * in configuration is used to determine whether the control interface 	 * is enabled. 	 * 	 * For UNIX domain sockets (default on Linux and BSD): This is a 	 * directory that will be created for UNIX domain sockets for listening 	 * to requests from external programs (CLI/GUI, etc.) for status 	 * information and configuration. The socket file will be named based 	 * on the interface name, so multiple %wpa_supplicant processes can be 	 * run at the same time if more than one interface is used. 	 * /var/run/wpa_supplicant is the recommended directory for sockets and 	 * by default, wpa_cli will use it when trying to connect with 	 * %wpa_supplicant. 	 * 	 * Access control for the control interface can be configured 	 * by setting the directory to allow only members of a group 	 * to use sockets. This way, it is possible to run 	 * %wpa_supplicant as root (since it needs to change network 	 * configuration and open raw sockets) and still allow GUI/CLI 	 * components to be run as non-root users. However, since the 	 * control interface can be used to change the network 	 * configuration, this access needs to be protected in many 	 * cases. By default, %wpa_supplicant is configured to use gid 	 * 0 (root). If you want to allow non-root users to use the 	 * control interface, add a new group and change this value to 	 * match with that group. Add users that should have control 	 * interface access to this group. 	 * 	 * When configuring both the directory and group, use following format: 	 * DIR=/var/run/wpa_supplicant GROUP=wheel 	 * DIR=/var/run/wpa_supplicant GROUP=0 	 * (group can be either group name or gid) 	 * 	 * For UDP connections (default on Windows): The value will be ignored. 	 * This variable is just used to select that the control interface is 	 * to be created. The value can be set to, e.g., udp 	 * (ctrl_interface=udp). 	 * 	 * For Windows Named Pipe: This value can be used to set the security 	 * descriptor for controlling access to the control interface. Security 	 * descriptor can be set using Security Descriptor String Format (see 	 * http://msdn.microsoft.com/library/default.asp?url=/library/en-us/secauthz/security/security_descriptor_string_format.asp). 	 * The descriptor string needs to be prefixed with SDDL=. For example, 	 * ctrl_interface=SDDL=D: would set an empty DACL (which will reject 	 * all connections). 	 */
name|char
modifier|*
name|ctrl_interface
decl_stmt|;
comment|/** 	 * ctrl_interface_group - Control interface group (DEPRECATED) 	 * 	 * This variable is only used for backwards compatibility. Group for 	 * UNIX domain sockets should now be specified using GROUP=group in 	 * ctrl_interface variable. 	 */
name|char
modifier|*
name|ctrl_interface_group
decl_stmt|;
comment|/** 	 * fast_reauth - EAP fast re-authentication (session resumption) 	 * 	 * By default, fast re-authentication is enabled for all EAP methods 	 * that support it. This variable can be used to disable fast 	 * re-authentication (by setting fast_reauth=0). Normally, there is no 	 * need to disable fast re-authentication. 	 */
name|int
name|fast_reauth
decl_stmt|;
comment|/** 	 * opensc_engine_path - Path to the OpenSSL engine for opensc 	 * 	 * This is an OpenSSL specific configuration option for loading OpenSC 	 * engine (engine_opensc.so); if %NULL, this engine is not loaded. 	 */
name|char
modifier|*
name|opensc_engine_path
decl_stmt|;
comment|/** 	 * pkcs11_engine_path - Path to the OpenSSL engine for PKCS#11 	 * 	 * This is an OpenSSL specific configuration option for loading PKCS#11 	 * engine (engine_pkcs11.so); if %NULL, this engine is not loaded. 	 */
name|char
modifier|*
name|pkcs11_engine_path
decl_stmt|;
comment|/** 	 * pkcs11_module_path - Path to the OpenSSL OpenSC/PKCS#11 module 	 * 	 * This is an OpenSSL specific configuration option for configuring 	 * path to OpenSC/PKCS#11 engine (opensc-pkcs11.so); if %NULL, this 	 * module is not loaded. 	 */
name|char
modifier|*
name|pkcs11_module_path
decl_stmt|;
comment|/** 	 * driver_param - Driver interface parameters 	 * 	 * This text string is passed to the selected driver interface with the 	 * optional struct wpa_driver_ops::set_param() handler. This can be 	 * used to configure driver specific options without having to add new 	 * driver interface functionality. 	 */
name|char
modifier|*
name|driver_param
decl_stmt|;
comment|/** 	 * dot11RSNAConfigPMKLifetime - Maximum lifetime of a PMK 	 * 	 * dot11 MIB variable for the maximum lifetime of a PMK in the PMK 	 * cache (unit: seconds). 	 */
name|unsigned
name|int
name|dot11RSNAConfigPMKLifetime
decl_stmt|;
comment|/** 	 * dot11RSNAConfigPMKReauthThreshold - PMK re-authentication threshold 	 * 	 * dot11 MIB variable for the percentage of the PMK lifetime 	 * that should expire before an IEEE 802.1X reauthentication occurs. 	 */
name|unsigned
name|int
name|dot11RSNAConfigPMKReauthThreshold
decl_stmt|;
comment|/** 	 * dot11RSNAConfigSATimeout - Security association timeout 	 * 	 * dot11 MIB variable for the maximum time a security association 	 * shall take to set up (unit: seconds). 	 */
name|unsigned
name|int
name|dot11RSNAConfigSATimeout
decl_stmt|;
comment|/** 	 * update_config - Is wpa_supplicant allowed to update configuration 	 * 	 * This variable control whether wpa_supplicant is allow to re-write 	 * its configuration with wpa_config_write(). If this is zero, 	 * configuration data is only changed in memory and the external data 	 * is not overriden. If this is non-zero, wpa_supplicant will update 	 * the configuration data (e.g., a file) whenever configuration is 	 * changed. This update may replace the old configuration which can 	 * remove comments from it in case of a text file configuration. 	 */
name|int
name|update_config
decl_stmt|;
comment|/** 	 * blobs - Configuration blobs 	 */
name|struct
name|wpa_config_blob
modifier|*
name|blobs
decl_stmt|;
comment|/** 	 * uuid - Universally Unique IDentifier (UUID; see RFC 4122) for WPS 	 */
name|u8
name|uuid
index|[
literal|16
index|]
decl_stmt|;
comment|/** 	 * device_name - Device Name (WPS) 	 * User-friendly description of device; up to 32 octets encoded in 	 * UTF-8 	 */
name|char
modifier|*
name|device_name
decl_stmt|;
comment|/** 	 * manufacturer - Manufacturer (WPS) 	 * The manufacturer of the device (up to 64 ASCII characters) 	 */
name|char
modifier|*
name|manufacturer
decl_stmt|;
comment|/** 	 * model_name - Model Name (WPS) 	 * Model of the device (up to 32 ASCII characters) 	 */
name|char
modifier|*
name|model_name
decl_stmt|;
comment|/** 	 * model_number - Model Number (WPS) 	 * Additional device description (up to 32 ASCII characters) 	 */
name|char
modifier|*
name|model_number
decl_stmt|;
comment|/** 	 * serial_number - Serial Number (WPS) 	 * Serial number of the device (up to 32 characters) 	 */
name|char
modifier|*
name|serial_number
decl_stmt|;
comment|/** 	 * device_type - Primary Device Type (WPS) 	 * Used format: categ-OUI-subcateg 	 * categ = Category as an integer value 	 * OUI = OUI and type octet as a 4-octet hex-encoded value; 	 *	0050F204 for default WPS OUI 	 * subcateg = OUI-specific Sub Category as an integer value 	 * Examples: 	 *   1-0050F204-1 (Computer / PC) 	 *   1-0050F204-2 (Computer / Server) 	 *   5-0050F204-1 (Storage / NAS) 	 *   6-0050F204-1 (Network Infrastructure / AP) 	 */
name|char
modifier|*
name|device_type
decl_stmt|;
comment|/** 	 * config_methods - Config Methods 	 * 	 * This is a space-separated list of supported WPS configuration 	 * methods. For example, "label display push_button keypad". 	 * Available methods: usba ethernet label display ext_nfc_token 	 * int_nfc_token nfc_interface push_button keypad. 	 */
name|char
modifier|*
name|config_methods
decl_stmt|;
comment|/** 	 * os_version - OS Version (WPS) 	 * 4-octet operating system version number 	 */
name|u8
name|os_version
index|[
literal|4
index|]
decl_stmt|;
comment|/** 	 * country - Country code 	 * 	 * This is the ISO/IEC alpha2 country code for which we are operating 	 * in 	 */
name|char
name|country
index|[
literal|2
index|]
decl_stmt|;
comment|/** 	 * wps_cred_processing - Credential processing 	 * 	 *   0 = process received credentials internally 	 *   1 = do not process received credentials; just pass them over 	 *	ctrl_iface to external program(s) 	 *   2 = process received credentials internally and pass them over 	 *	ctrl_iface to external program(s) 	 */
name|int
name|wps_cred_processing
decl_stmt|;
comment|/** 	 * bss_max_count - Maximum number of BSS entries to keep in memory 	 */
name|unsigned
name|int
name|bss_max_count
decl_stmt|;
comment|/** 	 * filter_ssids - SSID-based scan result filtering 	 * 	 *   0 = do not filter scan results 	 *   1 = only include configured SSIDs in scan results/BSS table 	 */
name|int
name|filter_ssids
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Prototypes for common functions from config.c */
end_comment

begin_function_decl
name|void
name|wpa_config_free
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|ssid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_config_free_ssid
parameter_list|(
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpa_ssid
modifier|*
name|wpa_config_get_network
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|config
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpa_ssid
modifier|*
name|wpa_config_add_network
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_config_remove_network
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|config
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_config_set_network_defaults
parameter_list|(
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_config_set
parameter_list|(
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|,
specifier|const
name|char
modifier|*
name|var
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|wpa_config_get_all
parameter_list|(
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|,
name|int
name|get_keys
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|wpa_config_get
parameter_list|(
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|,
specifier|const
name|char
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|wpa_config_get_no_key
parameter_list|(
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|,
specifier|const
name|char
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_config_update_psk
parameter_list|(
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_config_add_prio_network
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|config
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
name|wpa_config_update_prio_list
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|wpa_config_blob
modifier|*
name|wpa_config_get_blob
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|config
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
name|wpa_config_set_blob
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|config
parameter_list|,
name|struct
name|wpa_config_blob
modifier|*
name|blob
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_config_free_blob
parameter_list|(
name|struct
name|wpa_config_blob
modifier|*
name|blob
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_config_remove_blob
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|config
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpa_config
modifier|*
name|wpa_config_alloc_empty
parameter_list|(
specifier|const
name|char
modifier|*
name|ctrl_interface
parameter_list|,
specifier|const
name|char
modifier|*
name|driver_param
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_NO_STDOUT_DEBUG
end_ifndef

begin_function_decl
name|void
name|wpa_config_debug_dump_networks
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NO_STDOUT_DEBUG */
end_comment

begin_define
define|#
directive|define
name|wpa_config_debug_dump_networks
parameter_list|(
name|c
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NO_STDOUT_DEBUG */
end_comment

begin_comment
comment|/* Prototypes for backend specific functions from the selected config_*.c */
end_comment

begin_comment
comment|/**  * wpa_config_read - Read and parse configuration database  * @name: Name of the configuration (e.g., path and file name for the  * configuration file)  * Returns: Pointer to allocated configuration data or %NULL on failure  *  * This function reads configuration data, parses its contents, and allocates  * data structures needed for storing configuration information. The allocated  * data can be freed with wpa_config_free().  *  * Each configuration backend needs to implement this function.  */
end_comment

begin_function_decl
name|struct
name|wpa_config
modifier|*
name|wpa_config_read
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * wpa_config_write - Write or update configuration data  * @name: Name of the configuration (e.g., path and file name for the  * configuration file)  * @config: Configuration data from wpa_config_read()  * Returns: 0 on success, -1 on failure  *  * This function write all configuration data into an external database (e.g.,  * a text file) in a format that can be read with wpa_config_read(). This can  * be used to allow wpa_supplicant to update its configuration, e.g., when a  * new network is added or a password is changed.  *  * Each configuration backend needs to implement this function.  */
end_comment

begin_function_decl
name|int
name|wpa_config_write
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|wpa_config
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_H */
end_comment

end_unit

