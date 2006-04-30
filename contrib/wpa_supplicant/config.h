begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / Configuration file structures  * Copyright (c) 2003-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_CTRL_IFACE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_CTRL_IFACE_UDP
end_ifndef

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_CTRL_IFACE_UDP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_CTRL_IFACE */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_EAPOL_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_AP_SCAN
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_FAST_REAUTH
value|1
end_define

begin_include
include|#
directive|include
file|"config_ssid.h"
end_include

begin_comment
comment|/**  * struct wpa_config_blob - Named configuration blob  *  * This data structure is used to provide storage for binary objects to store  * abstract information like certificates and private keys inlined with the  * configuration data.  */
end_comment

begin_struct
struct|struct
name|wpa_config_blob
block|{
comment|/** 	 * name - Blob name 	 */
name|char
modifier|*
name|name
decl_stmt|;
comment|/** 	 * data - Pointer to binary data 	 */
name|u8
modifier|*
name|data
decl_stmt|;
comment|/** 	 * len - Length of binary data 	 */
name|size_t
name|len
decl_stmt|;
comment|/** 	 * next - Pointer to next blob in the configuration 	 */
name|struct
name|wpa_config_blob
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/** 	 * ctrl_interface - Directory for UNIX domain sockets 	 * 	 * This variable is used to configure where the UNIX domain sockets 	 * for the control interface are created. If UDP-based ctrl_iface is 	 * used, this variable can be set to any string (i.e., %NULL is not 	 * allowed). 	 */
name|char
modifier|*
name|ctrl_interface
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_CTRL_IFACE
ifndef|#
directive|ifndef
name|CONFIG_CTRL_IFACE_UDP
comment|/** 	 * ctrl_interface_gid - Group identity for the UNIX domain sockets 	 * 	 * Access control for the control interface can be configured 	 * by setting the directory to allow only members of a group 	 * to use sockets. This way, it is possible to run 	 * wpa_supplicant as root (since it needs to change network 	 * configuration and open raw sockets) and still allow GUI/CLI 	 * components to be run as non-root users. However, since the 	 * control interface can be used to change the network 	 * configuration, this access needs to be protected in many 	 * cases. By default, wpa_supplicant is configured to use gid 	 * 0 (root). If you want to allow non-root users to use the 	 * control interface, add a new group and change this value to 	 * match with that group. Add users that should have control 	 * interface access to this group. 	 */
name|gid_t
name|ctrl_interface_gid
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_CTRL_IFACE_UDP */
comment|/** 	 * ctrl_interface_gid_set - Whether ctrl_interface_gid is used 	 * 	 * If this variable is zero, ctrl_interface_gid value is not used and 	 * group will not be changed from the value it got by default 	 * when the directory or socket was created. 	 */
name|int
name|ctrl_interface_gid_set
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_CTRL_IFACE */
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
block|}
struct|;
end_struct

begin_comment
comment|/* Protypes for common functions from config.c */
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

