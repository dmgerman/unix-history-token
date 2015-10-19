begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / Configuration file structures  * Copyright (c) 2003-2012, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
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
name|DEFAULT_USER_MPM
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_MAX_PEER_LINKS
value|99
end_define

begin_define
define|#
directive|define
name|DEFAULT_MESH_MAX_INACTIVITY
value|300
end_define

begin_comment
comment|/*  * The default dot11RSNASAERetransPeriod is defined as 40 ms in the standard,  * but use 1000 ms in practice to avoid issues on low power CPUs.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_DOT11_RSNA_SAE_RETRANS_PERIOD
value|1000
end_define

begin_define
define|#
directive|define
name|DEFAULT_FAST_REAUTH
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_P2P_GO_INTENT
value|7
end_define

begin_define
define|#
directive|define
name|DEFAULT_P2P_INTRA_BSS
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_P2P_GO_MAX_INACTIVITY
value|(5 * 60)
end_define

begin_define
define|#
directive|define
name|DEFAULT_P2P_OPTIMIZE_LISTEN_CHAN
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_BSS_MAX_COUNT
value|200
end_define

begin_define
define|#
directive|define
name|DEFAULT_BSS_EXPIRATION_AGE
value|180
end_define

begin_define
define|#
directive|define
name|DEFAULT_BSS_EXPIRATION_SCAN_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|DEFAULT_MAX_NUM_STA
value|128
end_define

begin_define
define|#
directive|define
name|DEFAULT_ACCESS_NETWORK_TYPE
value|15
end_define

begin_define
define|#
directive|define
name|DEFAULT_SCAN_CUR_FREQ
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_P2P_SEARCH_DELAY
value|500
end_define

begin_define
define|#
directive|define
name|DEFAULT_RAND_ADDR_LIFETIME
value|60
end_define

begin_define
define|#
directive|define
name|DEFAULT_KEY_MGMT_OFFLOAD
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_CERT_IN_CB
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_P2P_GO_CTWINDOW
value|0
end_define

begin_include
include|#
directive|include
file|"config_ssid.h"
end_include

begin_include
include|#
directive|include
file|"wps/wps.h"
end_include

begin_include
include|#
directive|include
file|"common/ieee802_11_defs.h"
end_include

begin_include
include|#
directive|include
file|"common/ieee802_11_common.h"
end_include

begin_struct
struct|struct
name|wpa_cred
block|{
comment|/** 	 * next - Next credential in the list 	 * 	 * This pointer can be used to iterate over all credentials. The head 	 * of this list is stored in the cred field of struct wpa_config. 	 */
name|struct
name|wpa_cred
modifier|*
name|next
decl_stmt|;
comment|/** 	 * id - Unique id for the credential 	 * 	 * This identifier is used as a unique identifier for each credential 	 * block when using the control interface. Each credential is allocated 	 * an id when it is being created, either when reading the 	 * configuration file or when a new credential is added through the 	 * control interface. 	 */
name|int
name|id
decl_stmt|;
comment|/** 	 * temporary - Whether this credential is temporary and not to be saved 	 */
name|int
name|temporary
decl_stmt|;
comment|/** 	 * priority - Priority group 	 * 	 * By default, all networks and credentials get the same priority group 	 * (0). This field can be used to give higher priority for credentials 	 * (and similarly in struct wpa_ssid for network blocks) to change the 	 * Interworking automatic networking selection behavior. The matching 	 * network (based on either an enabled network block or a credential) 	 * with the highest priority value will be selected. 	 */
name|int
name|priority
decl_stmt|;
comment|/** 	 * pcsc - Use PC/SC and SIM/USIM card 	 */
name|int
name|pcsc
decl_stmt|;
comment|/** 	 * realm - Home Realm for Interworking 	 */
name|char
modifier|*
name|realm
decl_stmt|;
comment|/** 	 * username - Username for Interworking network selection 	 */
name|char
modifier|*
name|username
decl_stmt|;
comment|/** 	 * password - Password for Interworking network selection 	 */
name|char
modifier|*
name|password
decl_stmt|;
comment|/** 	 * ext_password - Whether password is a name for external storage 	 */
name|int
name|ext_password
decl_stmt|;
comment|/** 	 * ca_cert - CA certificate for Interworking network selection 	 */
name|char
modifier|*
name|ca_cert
decl_stmt|;
comment|/** 	 * client_cert - File path to client certificate file (PEM/DER) 	 * 	 * This field is used with Interworking networking selection for a case 	 * where client certificate/private key is used for authentication 	 * (EAP-TLS). Full path to the file should be used since working 	 * directory may change when wpa_supplicant is run in the background. 	 * 	 * Alternatively, a named configuration blob can be used by setting 	 * this to blob://blob_name. 	 */
name|char
modifier|*
name|client_cert
decl_stmt|;
comment|/** 	 * private_key - File path to client private key file (PEM/DER/PFX) 	 * 	 * When PKCS#12/PFX file (.p12/.pfx) is used, client_cert should be 	 * commented out. Both the private key and certificate will be read 	 * from the PKCS#12 file in this case. Full path to the file should be 	 * used since working directory may change when wpa_supplicant is run 	 * in the background. 	 * 	 * Windows certificate store can be used by leaving client_cert out and 	 * configuring private_key in one of the following formats: 	 * 	 * cert://substring_to_match 	 * 	 * hash://certificate_thumbprint_in_hex 	 * 	 * For example: private_key="hash://63093aa9c47f56ae88334c7b65a4" 	 * 	 * Note that when running wpa_supplicant as an application, the user 	 * certificate store (My user account) is used, whereas computer store 	 * (Computer account) is used when running wpasvc as a service. 	 * 	 * Alternatively, a named configuration blob can be used by setting 	 * this to blob://blob_name. 	 */
name|char
modifier|*
name|private_key
decl_stmt|;
comment|/** 	 * private_key_passwd - Password for private key file 	 */
name|char
modifier|*
name|private_key_passwd
decl_stmt|;
comment|/** 	 * imsi - IMSI in<MCC> |<MNC> | '-' |<MSIN> format 	 */
name|char
modifier|*
name|imsi
decl_stmt|;
comment|/** 	 * milenage - Milenage parameters for SIM/USIM simulator in 	 *<Ki>:<OPc>:<SQN> format 	 */
name|char
modifier|*
name|milenage
decl_stmt|;
comment|/** 	 * domain_suffix_match - Constraint for server domain name 	 * 	 * If set, this FQDN is used as a suffix match requirement for the AAA 	 * server certificate in SubjectAltName dNSName element(s). If a 	 * matching dNSName is found, this constraint is met. If no dNSName 	 * values are present, this constraint is matched against SubjectName CN 	 * using same suffix match comparison. Suffix match here means that the 	 * host/domain name is compared one label at a time starting from the 	 * top-level domain and all the labels in @domain_suffix_match shall be 	 * included in the certificate. The certificate may include additional 	 * sub-level labels in addition to the required labels. 	 * 	 * For example, domain_suffix_match=example.com would match 	 * test.example.com but would not match test-example.com. 	 */
name|char
modifier|*
name|domain_suffix_match
decl_stmt|;
comment|/** 	 * domain - Home service provider FQDN(s) 	 * 	 * This is used to compare against the Domain Name List to figure out 	 * whether the AP is operated by the Home SP. Multiple domain entries 	 * can be used to configure alternative FQDNs that will be considered 	 * home networks. 	 */
name|char
modifier|*
modifier|*
name|domain
decl_stmt|;
comment|/** 	 * num_domain - Number of FQDNs in the domain array 	 */
name|size_t
name|num_domain
decl_stmt|;
comment|/** 	 * roaming_consortium - Roaming Consortium OI 	 * 	 * If roaming_consortium_len is non-zero, this field contains the 	 * Roaming Consortium OI that can be used to determine which access 	 * points support authentication with this credential. This is an 	 * alternative to the use of the realm parameter. When using Roaming 	 * Consortium to match the network, the EAP parameters need to be 	 * pre-configured with the credential since the NAI Realm information 	 * may not be available or fetched. 	 */
name|u8
name|roaming_consortium
index|[
literal|15
index|]
decl_stmt|;
comment|/** 	 * roaming_consortium_len - Length of roaming_consortium 	 */
name|size_t
name|roaming_consortium_len
decl_stmt|;
name|u8
name|required_roaming_consortium
index|[
literal|15
index|]
decl_stmt|;
name|size_t
name|required_roaming_consortium_len
decl_stmt|;
comment|/** 	 * eap_method - EAP method to use 	 * 	 * Pre-configured EAP method to use with this credential or %NULL to 	 * indicate no EAP method is selected, i.e., the method will be 	 * selected automatically based on ANQP information. 	 */
name|struct
name|eap_method_type
modifier|*
name|eap_method
decl_stmt|;
comment|/** 	 * phase1 - Phase 1 (outer authentication) parameters 	 * 	 * Pre-configured EAP parameters or %NULL. 	 */
name|char
modifier|*
name|phase1
decl_stmt|;
comment|/** 	 * phase2 - Phase 2 (inner authentication) parameters 	 * 	 * Pre-configured EAP parameters or %NULL. 	 */
name|char
modifier|*
name|phase2
decl_stmt|;
struct|struct
name|excluded_ssid
block|{
name|u8
name|ssid
index|[
name|SSID_MAX_LEN
index|]
decl_stmt|;
name|size_t
name|ssid_len
decl_stmt|;
block|}
modifier|*
name|excluded_ssid
struct|;
name|size_t
name|num_excluded_ssid
decl_stmt|;
struct|struct
name|roaming_partner
block|{
name|char
name|fqdn
index|[
literal|128
index|]
decl_stmt|;
name|int
name|exact_match
decl_stmt|;
name|u8
name|priority
decl_stmt|;
name|char
name|country
index|[
literal|3
index|]
decl_stmt|;
block|}
modifier|*
name|roaming_partner
struct|;
name|size_t
name|num_roaming_partner
decl_stmt|;
name|int
name|update_identifier
decl_stmt|;
comment|/** 	 * provisioning_sp - FQDN of the SP that provisioned the credential 	 */
name|char
modifier|*
name|provisioning_sp
decl_stmt|;
comment|/** 	 * sp_priority - Credential priority within a provisioning SP 	 * 	 * This is the priority of the credential among all credentials 	 * provisionined by the same SP (i.e., for entries that have identical 	 * provisioning_sp value). The range of this priority is 0-255 with 0 	 * being the highest and 255 the lower priority. 	 */
name|int
name|sp_priority
decl_stmt|;
name|unsigned
name|int
name|min_dl_bandwidth_home
decl_stmt|;
name|unsigned
name|int
name|min_ul_bandwidth_home
decl_stmt|;
name|unsigned
name|int
name|min_dl_bandwidth_roaming
decl_stmt|;
name|unsigned
name|int
name|min_ul_bandwidth_roaming
decl_stmt|;
comment|/** 	 * max_bss_load - Maximum BSS Load Channel Utilization (1..255) 	 * This value is used as the maximum channel utilization for network 	 * selection purposes for home networks. If the AP does not advertise 	 * BSS Load or if the limit would prevent any connection, this 	 * constraint will be ignored. 	 */
name|unsigned
name|int
name|max_bss_load
decl_stmt|;
name|unsigned
name|int
name|num_req_conn_capab
decl_stmt|;
name|u8
modifier|*
name|req_conn_capab_proto
decl_stmt|;
name|int
modifier|*
modifier|*
name|req_conn_capab_port
decl_stmt|;
comment|/** 	 * ocsp - Whether to use/require OCSP to check server certificate 	 * 	 * 0 = do not use OCSP stapling (TLS certificate status extension) 	 * 1 = try to use OCSP stapling, but not require response 	 * 2 = require valid OCSP stapling response 	 */
name|int
name|ocsp
decl_stmt|;
comment|/** 	 * sim_num - User selected SIM identifier 	 * 	 * This variable is used for identifying which SIM is used if the system 	 * has more than one. 	 */
name|int
name|sim_num
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CFG_CHANGED_DEVICE_NAME
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_CONFIG_METHODS
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_DEVICE_TYPE
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_OS_VERSION
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_UUID
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_COUNTRY
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_SEC_DEVICE_TYPE
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_P2P_SSID_POSTFIX
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_WPS_STRING
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_P2P_INTRA_BSS
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_VENDOR_EXTENSION
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_P2P_LISTEN_CHANNEL
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_P2P_OPER_CHANNEL
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_P2P_PREF_CHAN
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_EXT_PW_BACKEND
value|BIT(14)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_NFC_PASSWORD_TOKEN
value|BIT(15)
end_define

begin_define
define|#
directive|define
name|CFG_CHANGED_P2P_PASSPHRASE_LEN
value|BIT(16)
end_define

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
comment|/** 	 * cred - Head of the credential list 	 * 	 * This is the head for the list of all the configured credentials. 	 */
name|struct
name|wpa_cred
modifier|*
name|cred
decl_stmt|;
comment|/** 	 * eapol_version - IEEE 802.1X/EAPOL version number 	 * 	 * wpa_supplicant is implemented based on IEEE Std 802.1X-2004 which 	 * defines EAPOL version 2. However, there are many APs that do not 	 * handle the new version number correctly (they seem to drop the 	 * frames completely). In order to make wpa_supplicant interoperate 	 * with these APs, the version number is set to 1 by default. This 	 * configuration value can be used to set it to the new version (2). 	 */
name|int
name|eapol_version
decl_stmt|;
comment|/** 	 * ap_scan - AP scanning/selection 	 * 	 * By default, wpa_supplicant requests driver to perform AP 	 * scanning and then uses the scan results to select a 	 * suitable AP. Another alternative is to allow the driver to 	 * take care of AP scanning and selection and use 	 * wpa_supplicant just to process EAPOL frames based on IEEE 	 * 802.11 association information from the driver. 	 * 	 * 1: wpa_supplicant initiates scanning and AP selection (default). 	 * 	 * 0: Driver takes care of scanning, AP selection, and IEEE 802.11 	 * association parameters (e.g., WPA IE generation); this mode can 	 * also be used with non-WPA drivers when using IEEE 802.1X mode; 	 * do not try to associate with APs (i.e., external program needs 	 * to control association). This mode must also be used when using 	 * wired Ethernet drivers. 	 * 	 * 2: like 0, but associate with APs using security policy and SSID 	 * (but not BSSID); this can be used, e.g., with ndiswrapper and NDIS 	 * drivers to enable operation with hidden SSIDs and optimized roaming; 	 * in this mode, the network blocks in the configuration are tried 	 * one by one until the driver reports successful association; each 	 * network block should have explicit security policy (i.e., only one 	 * option in the lists) for key_mgmt, pairwise, group, proto variables. 	 * 	 * Note: ap_scan=2 should not be used with the nl80211 driver interface 	 * (the current Linux interface). ap_scan=1 is optimized work working 	 * with nl80211. For finding networks using hidden SSID, scan_ssid=1 in 	 * the network block can be used with nl80211. 	 */
name|int
name|ap_scan
decl_stmt|;
comment|/** 	 * bgscan - Background scan and roaming parameters or %NULL if none 	 * 	 * This is an optional set of parameters for background scanning and 	 * roaming within a network (ESS). For more detailed information see 	 * ssid block documentation. 	 * 	 * The variable defines default bgscan behavior for all BSS station 	 * networks except for those which have their own bgscan configuration. 	 */
name|char
modifier|*
name|bgscan
decl_stmt|;
comment|/** 	 * disable_scan_offload - Disable automatic offloading of scan requests 	 * 	 * By default, %wpa_supplicant tries to offload scanning if the driver 	 * indicates support for this (sched_scan). This configuration 	 * parameter can be used to disable this offloading mechanism. 	 */
name|int
name|disable_scan_offload
decl_stmt|;
comment|/** 	 * ctrl_interface - Parameters for the control interface 	 * 	 * If this is specified, %wpa_supplicant will open a control interface 	 * that is available for external programs to manage %wpa_supplicant. 	 * The meaning of this string depends on which control interface 	 * mechanism is used. For all cases, the existence of this parameter 	 * in configuration is used to determine whether the control interface 	 * is enabled. 	 * 	 * For UNIX domain sockets (default on Linux and BSD): This is a 	 * directory that will be created for UNIX domain sockets for listening 	 * to requests from external programs (CLI/GUI, etc.) for status 	 * information and configuration. The socket file will be named based 	 * on the interface name, so multiple %wpa_supplicant processes can be 	 * run at the same time if more than one interface is used. 	 * /var/run/wpa_supplicant is the recommended directory for sockets and 	 * by default, wpa_cli will use it when trying to connect with 	 * %wpa_supplicant. 	 * 	 * Access control for the control interface can be configured 	 * by setting the directory to allow only members of a group 	 * to use sockets. This way, it is possible to run 	 * %wpa_supplicant as root (since it needs to change network 	 * configuration and open raw sockets) and still allow GUI/CLI 	 * components to be run as non-root users. However, since the 	 * control interface can be used to change the network 	 * configuration, this access needs to be protected in many 	 * cases. By default, %wpa_supplicant is configured to use gid 	 * 0 (root). If you want to allow non-root users to use the 	 * control interface, add a new group and change this value to 	 * match with that group. Add users that should have control 	 * interface access to this group. 	 * 	 * When configuring both the directory and group, use following format: 	 * DIR=/var/run/wpa_supplicant GROUP=wheel 	 * DIR=/var/run/wpa_supplicant GROUP=0 	 * (group can be either group name or gid) 	 * 	 * For UDP connections (default on Windows): The value will be ignored. 	 * This variable is just used to select that the control interface is 	 * to be created. The value can be set to, e.g., udp 	 * (ctrl_interface=udp). 	 * 	 * For Windows Named Pipe: This value can be used to set the security 	 * descriptor for controlling access to the control interface. Security 	 * descriptor can be set using Security Descriptor String Format (see 	 * http://msdn.microsoft.com/library/default.asp?url=/library/en-us/secauthz/security/security_descriptor_string_format.asp). 	 * The descriptor string needs to be prefixed with SDDL=. For example, 	 * ctrl_interface=SDDL=D: would set an empty DACL (which will reject 	 * all connections). 	 */
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
comment|/** 	 * openssl_ciphers - OpenSSL cipher string 	 * 	 * This is an OpenSSL specific configuration option for configuring the 	 * default ciphers. If not set, "DEFAULT:!EXP:!LOW" is used as the 	 * default. 	 */
name|char
modifier|*
name|openssl_ciphers
decl_stmt|;
comment|/** 	 * pcsc_reader - PC/SC reader name prefix 	 * 	 * If not %NULL, PC/SC reader with a name that matches this prefix is 	 * initialized for SIM/USIM access. Empty string can be used to match 	 * the first available reader. 	 */
name|char
modifier|*
name|pcsc_reader
decl_stmt|;
comment|/** 	 * pcsc_pin - PIN for USIM, GSM SIM, and smartcards 	 * 	 * This field is used to configure PIN for SIM/USIM for EAP-SIM and 	 * EAP-AKA. If left out, this will be asked through control interface. 	 */
name|char
modifier|*
name|pcsc_pin
decl_stmt|;
comment|/** 	 * external_sim - Use external processing for SIM/USIM operations 	 */
name|int
name|external_sim
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
comment|/** 	 * device_type - Primary Device Type (WPS) 	 */
name|u8
name|device_type
index|[
name|WPS_DEV_TYPE_LEN
index|]
decl_stmt|;
comment|/** 	 * config_methods - Config Methods 	 * 	 * This is a space-separated list of supported WPS configuration 	 * methods. For example, "label virtual_display virtual_push_button 	 * keypad". 	 * Available methods: usba ethernet label display ext_nfc_token 	 * int_nfc_token nfc_interface push_button keypad 	 * virtual_display physical_display 	 * virtual_push_button physical_push_button. 	 */
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
define|#
directive|define
name|MAX_SEC_DEVICE_TYPES
value|5
comment|/** 	 * sec_device_types - Secondary Device Types (P2P) 	 */
name|u8
name|sec_device_type
index|[
name|MAX_SEC_DEVICE_TYPES
index|]
index|[
name|WPS_DEV_TYPE_LEN
index|]
decl_stmt|;
name|int
name|num_sec_device_types
decl_stmt|;
name|int
name|p2p_listen_reg_class
decl_stmt|;
name|int
name|p2p_listen_channel
decl_stmt|;
name|int
name|p2p_oper_reg_class
decl_stmt|;
name|int
name|p2p_oper_channel
decl_stmt|;
name|int
name|p2p_go_intent
decl_stmt|;
name|char
modifier|*
name|p2p_ssid_postfix
decl_stmt|;
name|int
name|persistent_reconnect
decl_stmt|;
name|int
name|p2p_intra_bss
decl_stmt|;
name|unsigned
name|int
name|num_p2p_pref_chan
decl_stmt|;
name|struct
name|p2p_channel
modifier|*
name|p2p_pref_chan
decl_stmt|;
name|struct
name|wpa_freq_range_list
name|p2p_no_go_freq
decl_stmt|;
name|int
name|p2p_add_cli_chan
decl_stmt|;
name|int
name|p2p_ignore_shared_freq
decl_stmt|;
name|int
name|p2p_optimize_listen_chan
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|wps_vendor_ext_m1
decl_stmt|;
define|#
directive|define
name|MAX_WPS_VENDOR_EXT
value|10
comment|/** 	 * wps_vendor_ext - Vendor extension attributes in WPS 	 */
name|struct
name|wpabuf
modifier|*
name|wps_vendor_ext
index|[
name|MAX_WPS_VENDOR_EXT
index|]
decl_stmt|;
comment|/** 	 * p2p_group_idle - Maximum idle time in seconds for P2P group 	 * 	 * This value controls how long a P2P group is maintained after there 	 * is no other members in the group. As a GO, this means no associated 	 * stations in the group. As a P2P client, this means no GO seen in 	 * scan results. The maximum idle time is specified in seconds with 0 	 * indicating no time limit, i.e., the P2P group remains in active 	 * state indefinitely until explicitly removed. As a P2P client, the 	 * maximum idle time of P2P_MAX_CLIENT_IDLE seconds is enforced, i.e., 	 * this parameter is mainly meant for GO use and for P2P client, it can 	 * only be used to reduce the default timeout to smaller value. A 	 * special value -1 can be used to configure immediate removal of the 	 * group for P2P client role on any disconnection after the data 	 * connection has been established. 	 */
name|int
name|p2p_group_idle
decl_stmt|;
comment|/** 	 * p2p_go_freq_change_policy - The GO frequency change policy 	 * 	 * This controls the behavior of the GO when there is a change in the 	 * map of the currently used frequencies in case more than one channel 	 * is supported. 	 * 	 * @P2P_GO_FREQ_MOVE_SCM: Prefer working in a single channel mode if 	 * possible. In case the GO is the only interface using its frequency 	 * and there are other station interfaces on other frequencies, the GO 	 * will migrate to one of these frequencies. 	 * 	 * @P2P_GO_FREQ_MOVE_SCM_PEER_SUPPORTS: Same as P2P_GO_FREQ_MOVE_SCM, 	 * but a transition is possible only in case one of the other used 	 * frequencies is one of the frequencies in the intersection of the 	 * frequency list of the local device and the peer device. 	 * 	 * @P2P_GO_FREQ_MOVE_STAY: Prefer to stay on the current frequency. 	 */
enum|enum
block|{
name|P2P_GO_FREQ_MOVE_SCM
init|=
literal|0
block|,
name|P2P_GO_FREQ_MOVE_SCM_PEER_SUPPORTS
init|=
literal|1
block|,
name|P2P_GO_FREQ_MOVE_STAY
init|=
literal|2
block|,
name|P2P_GO_FREQ_MOVE_MAX
init|=
name|P2P_GO_FREQ_MOVE_STAY
block|, 	}
name|p2p_go_freq_change_policy
enum|;
define|#
directive|define
name|DEFAULT_P2P_GO_FREQ_MOVE
value|P2P_GO_FREQ_MOVE_STAY
comment|/** 	 * p2p_passphrase_len - Passphrase length (8..63) for P2P GO 	 * 	 * This parameter controls the length of the random passphrase that is 	 * generated at the GO. 	 */
name|unsigned
name|int
name|p2p_passphrase_len
decl_stmt|;
comment|/** 	 * bss_max_count - Maximum number of BSS entries to keep in memory 	 */
name|unsigned
name|int
name|bss_max_count
decl_stmt|;
comment|/** 	 * bss_expiration_age - BSS entry age after which it can be expired 	 * 	 * This value controls the time in seconds after which a BSS entry 	 * gets removed if it has not been updated or is not in use. 	 */
name|unsigned
name|int
name|bss_expiration_age
decl_stmt|;
comment|/** 	 * bss_expiration_scan_count - Expire BSS after number of scans 	 * 	 * If the BSS entry has not been seen in this many scans, it will be 	 * removed. A value of 1 means that entry is removed after the first 	 * scan in which the BSSID is not seen. Larger values can be used 	 * to avoid BSS entries disappearing if they are not visible in 	 * every scan (e.g., low signal quality or interference). 	 */
name|unsigned
name|int
name|bss_expiration_scan_count
decl_stmt|;
comment|/** 	 * filter_ssids - SSID-based scan result filtering 	 * 	 *   0 = do not filter scan results 	 *   1 = only include configured SSIDs in scan results/BSS table 	 */
name|int
name|filter_ssids
decl_stmt|;
comment|/** 	 * filter_rssi - RSSI-based scan result filtering 	 * 	 * 0 = do not filter scan results 	 * -n = filter scan results below -n dBm 	 */
name|int
name|filter_rssi
decl_stmt|;
comment|/** 	 * max_num_sta - Maximum number of STAs in an AP/P2P GO 	 */
name|unsigned
name|int
name|max_num_sta
decl_stmt|;
comment|/** 	 * freq_list - Array of allowed scan frequencies or %NULL for all 	 * 	 * This is an optional zero-terminated array of frequencies in 	 * megahertz (MHz) to allow for narrowing scanning range. 	 */
name|int
modifier|*
name|freq_list
decl_stmt|;
comment|/** 	 * scan_cur_freq - Whether to scan only the current channel 	 * 	 * If true, attempt to scan only the current channel if any other 	 * VIFs on this radio are already associated on a particular channel. 	 */
name|int
name|scan_cur_freq
decl_stmt|;
comment|/** 	 * changed_parameters - Bitmap of changed parameters since last update 	 */
name|unsigned
name|int
name|changed_parameters
decl_stmt|;
comment|/** 	 * disassoc_low_ack - Disassocicate stations with massive packet loss 	 */
name|int
name|disassoc_low_ack
decl_stmt|;
comment|/** 	 * interworking - Whether Interworking (IEEE 802.11u) is enabled 	 */
name|int
name|interworking
decl_stmt|;
comment|/** 	 * access_network_type - Access Network Type 	 * 	 * When Interworking is enabled, scans will be limited to APs that 	 * advertise the specified Access Network Type (0..15; with 15 	 * indicating wildcard match). 	 */
name|int
name|access_network_type
decl_stmt|;
comment|/** 	 * hessid - Homogenous ESS identifier 	 * 	 * If this is set (any octet is non-zero), scans will be used to 	 * request response only from BSSes belonging to the specified 	 * Homogeneous ESS. This is used only if interworking is enabled. 	 */
name|u8
name|hessid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** 	 * hs20 - Hotspot 2.0 	 */
name|int
name|hs20
decl_stmt|;
comment|/** 	 * pbc_in_m1 - AP mode WPS probing workaround for PBC with Windows 7 	 * 	 * Windows 7 uses incorrect way of figuring out AP's WPS capabilities 	 * by acting as a Registrar and using M1 from the AP. The config 	 * methods attribute in that message is supposed to indicate only the 	 * configuration method supported by the AP in Enrollee role, i.e., to 	 * add an external Registrar. For that case, PBC shall not be used and 	 * as such, the PushButton config method is removed from M1 by default. 	 * If pbc_in_m1=1 is included in the configuration file, the PushButton 	 * config method is left in M1 (if included in config_methods 	 * parameter) to allow Windows 7 to use PBC instead of PIN (e.g., from 	 * a label in the AP). 	 */
name|int
name|pbc_in_m1
decl_stmt|;
comment|/** 	 * autoscan - Automatic scan parameters or %NULL if none 	 * 	 * This is an optional set of parameters for automatic scanning 	 * within an interface in following format: 	 *<autoscan module name>:<module parameters> 	 */
name|char
modifier|*
name|autoscan
decl_stmt|;
comment|/** 	 * wps_nfc_pw_from_config - NFC Device Password was read from config 	 * 	 * This parameter can be determined whether the NFC Device Password was 	 * included in the configuration (1) or generated dynamically (0). Only 	 * the former case is re-written back to the configuration file. 	 */
name|int
name|wps_nfc_pw_from_config
decl_stmt|;
comment|/** 	 * wps_nfc_dev_pw_id - NFC Device Password ID for password token 	 */
name|int
name|wps_nfc_dev_pw_id
decl_stmt|;
comment|/** 	 * wps_nfc_dh_pubkey - NFC DH Public Key for password token 	 */
name|struct
name|wpabuf
modifier|*
name|wps_nfc_dh_pubkey
decl_stmt|;
comment|/** 	 * wps_nfc_dh_privkey - NFC DH Private Key for password token 	 */
name|struct
name|wpabuf
modifier|*
name|wps_nfc_dh_privkey
decl_stmt|;
comment|/** 	 * wps_nfc_dev_pw - NFC Device Password for password token 	 */
name|struct
name|wpabuf
modifier|*
name|wps_nfc_dev_pw
decl_stmt|;
comment|/** 	 * ext_password_backend - External password backend or %NULL if none 	 * 	 * format:<backend name>[:<optional backend parameters>] 	 */
name|char
modifier|*
name|ext_password_backend
decl_stmt|;
comment|/* 	 * p2p_go_max_inactivity - Timeout in seconds to detect STA inactivity 	 * 	 * This timeout value is used in P2P GO mode to clean up 	 * inactive stations. 	 * By default: 300 seconds. 	 */
name|int
name|p2p_go_max_inactivity
decl_stmt|;
name|struct
name|hostapd_wmm_ac_params
name|wmm_ac_params
index|[
literal|4
index|]
decl_stmt|;
comment|/** 	 * auto_interworking - Whether to use network selection automatically 	 * 	 * 0 = do not automatically go through Interworking network selection 	 *     (i.e., require explicit interworking_select command for this) 	 * 1 = perform Interworking network selection if one or more 	 *     credentials have been configured and scan did not find a 	 *     matching network block 	 */
name|int
name|auto_interworking
decl_stmt|;
comment|/** 	 * p2p_go_ht40 - Default mode for HT40 enable when operating as GO. 	 * 	 * This will take effect for p2p_group_add, p2p_connect, and p2p_invite. 	 * Note that regulatory constraints and driver capabilities are 	 * consulted anyway, so setting it to 1 can't do real harm. 	 * By default: 0 (disabled) 	 */
name|int
name|p2p_go_ht40
decl_stmt|;
comment|/** 	 * p2p_go_vht - Default mode for VHT enable when operating as GO 	 * 	 * This will take effect for p2p_group_add, p2p_connect, and p2p_invite. 	 * Note that regulatory constraints and driver capabilities are 	 * consulted anyway, so setting it to 1 can't do real harm. 	 * By default: 0 (disabled) 	 */
name|int
name|p2p_go_vht
decl_stmt|;
comment|/** 	 * p2p_go_ctwindow - CTWindow to use when operating as GO 	 * 	 * By default: 0 (no CTWindow). Values 0-127 can be used to indicate 	 * the length of the CTWindow in TUs. 	 */
name|int
name|p2p_go_ctwindow
decl_stmt|;
comment|/** 	 * p2p_disabled - Whether P2P operations are disabled for this interface 	 */
name|int
name|p2p_disabled
decl_stmt|;
comment|/** 	 * p2p_no_group_iface - Whether group interfaces can be used 	 * 	 * By default, wpa_supplicant will create a separate interface for P2P 	 * group operations if the driver supports this. This functionality can 	 * be disabled by setting this parameter to 1. In that case, the same 	 * interface that was used for the P2P management operations is used 	 * also for the group operation. 	 */
name|int
name|p2p_no_group_iface
decl_stmt|;
comment|/** 	 * p2p_cli_probe - Enable/disable P2P CLI probe request handling 	 * 	 * If this parameter is set to 1, a connected P2P Client will receive 	 * and handle Probe Request frames. Setting this parameter to 0 	 * disables this option. Default value: 0. 	 * 	 * Note: Setting this property at run time takes effect on the following 	 * interface state transition to/from the WPA_COMPLETED state. 	 */
name|int
name|p2p_cli_probe
decl_stmt|;
comment|/** 	 * okc - Whether to enable opportunistic key caching by default 	 * 	 * By default, OKC is disabled unless enabled by the per-network 	 * proactive_key_caching=1 parameter. okc=1 can be used to change this 	 * default behavior. 	 */
name|int
name|okc
decl_stmt|;
comment|/** 	 * pmf - Whether to enable/require PMF by default 	 * 	 * By default, PMF is disabled unless enabled by the per-network 	 * ieee80211w=1 or ieee80211w=2 parameter. pmf=1/2 can be used to change 	 * this default behavior. 	 */
name|enum
name|mfp_options
name|pmf
decl_stmt|;
comment|/** 	 * sae_groups - Preference list of enabled groups for SAE 	 * 	 * By default (if this parameter is not set), the mandatory group 19 	 * (ECC group defined over a 256-bit prime order field) is preferred, 	 * but other groups are also enabled. If this parameter is set, the 	 * groups will be tried in the indicated order. 	 */
name|int
modifier|*
name|sae_groups
decl_stmt|;
comment|/** 	 * dtim_period - Default DTIM period in Beacon intervals 	 * 	 * This parameter can be used to set the default value for network 	 * blocks that do not specify dtim_period. 	 */
name|int
name|dtim_period
decl_stmt|;
comment|/** 	 * beacon_int - Default Beacon interval in TU 	 * 	 * This parameter can be used to set the default value for network 	 * blocks that do not specify beacon_int. 	 */
name|int
name|beacon_int
decl_stmt|;
comment|/** 	 * ap_vendor_elements: Vendor specific elements for Beacon/ProbeResp 	 * 	 * This parameter can be used to define additional vendor specific 	 * elements for Beacon and Probe Response frames in AP/P2P GO mode. The 	 * format for these element(s) is a hexdump of the raw information 	 * elements (id+len+payload for one or more elements). 	 */
name|struct
name|wpabuf
modifier|*
name|ap_vendor_elements
decl_stmt|;
comment|/** 	 * ignore_old_scan_res - Ignore scan results older than request 	 * 	 * The driver may have a cache of scan results that makes it return 	 * information that is older than our scan trigger. This parameter can 	 * be used to configure such old information to be ignored instead of 	 * allowing it to update the internal BSS table. 	 */
name|int
name|ignore_old_scan_res
decl_stmt|;
comment|/** 	 * sched_scan_interval -  schedule scan interval 	 */
name|unsigned
name|int
name|sched_scan_interval
decl_stmt|;
comment|/** 	 * tdls_external_control - External control for TDLS setup requests 	 * 	 * Enable TDLS mode where external programs are given the control 	 * to specify the TDLS link to get established to the driver. The 	 * driver requests the TDLS setup to the supplicant only for the 	 * specified TDLS peers. 	 */
name|int
name|tdls_external_control
decl_stmt|;
name|u8
name|ip_addr_go
index|[
literal|4
index|]
decl_stmt|;
name|u8
name|ip_addr_mask
index|[
literal|4
index|]
decl_stmt|;
name|u8
name|ip_addr_start
index|[
literal|4
index|]
decl_stmt|;
name|u8
name|ip_addr_end
index|[
literal|4
index|]
decl_stmt|;
comment|/** 	 * osu_dir - OSU provider information directory 	 * 	 * If set, allow FETCH_OSU control interface command to be used to fetch 	 * OSU provider information into all APs and store the results in this 	 * directory. 	 */
name|char
modifier|*
name|osu_dir
decl_stmt|;
comment|/** 	 * wowlan_triggers - Wake-on-WLAN triggers 	 * 	 * If set, these wowlan triggers will be configured. 	 */
name|char
modifier|*
name|wowlan_triggers
decl_stmt|;
comment|/** 	 * p2p_search_delay - Extra delay between concurrent search iterations 	 * 	 * Add extra delay (in milliseconds) between search iterations when 	 * there is a concurrent operation to make p2p_find friendlier to 	 * concurrent operations by avoiding it from taking 100% of radio 	 * resources. 	 */
name|unsigned
name|int
name|p2p_search_delay
decl_stmt|;
comment|/** 	 * mac_addr - MAC address policy default 	 * 	 * 0 = use permanent MAC address 	 * 1 = use random MAC address for each ESS connection 	 * 2 = like 1, but maintain OUI (with local admin bit set) 	 * 	 * By default, permanent MAC address is used unless policy is changed by 	 * the per-network mac_addr parameter. Global mac_addr=1 can be used to 	 * change this default behavior. 	 */
name|int
name|mac_addr
decl_stmt|;
comment|/** 	 * rand_addr_lifetime - Lifetime of random MAC address in seconds 	 */
name|unsigned
name|int
name|rand_addr_lifetime
decl_stmt|;
comment|/** 	 * preassoc_mac_addr - Pre-association MAC address policy 	 * 	 * 0 = use permanent MAC address 	 * 1 = use random MAC address 	 * 2 = like 1, but maintain OUI (with local admin bit set) 	 */
name|int
name|preassoc_mac_addr
decl_stmt|;
comment|/** 	 * key_mgmt_offload - Use key management offload 	 * 	 * Key management offload should be used if the device supports it. 	 * Key management offload is the capability of a device operating as 	 * a station to do the exchange necessary to establish temporal keys 	 * during initial RSN connection, after roaming, or during a PTK 	 * rekeying operation. 	 */
name|int
name|key_mgmt_offload
decl_stmt|;
comment|/** 	 * user_mpm - MPM residency 	 * 	 * 0: MPM lives in driver. 	 * 1: wpa_supplicant handles peering and station allocation. 	 * 	 * If AMPE or SAE is enabled, the MPM is always in userspace. 	 */
name|int
name|user_mpm
decl_stmt|;
comment|/** 	 * max_peer_links - Maximum number of peer links 	 * 	 * Maximum number of mesh peering currently maintained by the STA. 	 */
name|int
name|max_peer_links
decl_stmt|;
comment|/** 	 * cert_in_cb - Whether to include a peer certificate dump in events 	 * 	 * This controls whether peer certificates for authentication server and 	 * its certificate chain are included in EAP peer certificate events. 	 */
name|int
name|cert_in_cb
decl_stmt|;
comment|/** 	 * mesh_max_inactivity - Timeout in seconds to detect STA inactivity 	 * 	 * This timeout value is used in mesh STA to clean up inactive stations. 	 * By default: 300 seconds. 	 */
name|int
name|mesh_max_inactivity
decl_stmt|;
comment|/** 	 * dot11RSNASAERetransPeriod - Timeout to retransmit SAE Auth frame 	 * 	 * This timeout value is used in mesh STA to retransmit 	 * SAE Authentication frame. 	 * By default: 1000 milliseconds. 	 */
name|int
name|dot11RSNASAERetransPeriod
decl_stmt|;
comment|/** 	 * passive_scan - Whether to force passive scan for network connection 	 * 	 * This parameter can be used to force only passive scanning to be used 	 * for network connection cases. It should be noted that this will slow 	 * down scan operations and reduce likelihood of finding the AP. In 	 * addition, some use cases will override this due to functional 	 * requirements, e.g., for finding an AP that uses hidden SSID 	 * (scan_ssid=1) or P2P device discovery. 	 */
name|int
name|passive_scan
decl_stmt|;
comment|/** 	 * reassoc_same_bss_optim - Whether to optimize reassoc-to-same-BSS 	 */
name|int
name|reassoc_same_bss_optim
decl_stmt|;
comment|/** 	 * wps_priority - Priority for the networks added through WPS 	 * 	 * This priority value will be set to each network profile that is added 	 * by executing the WPS protocol. 	 */
name|int
name|wps_priority
decl_stmt|;
comment|/** 	 * fst_group_id - FST group ID 	 */
name|char
modifier|*
name|fst_group_id
decl_stmt|;
comment|/** 	 * fst_priority - priority of the interface within the FST group 	 */
name|int
name|fst_priority
decl_stmt|;
comment|/** 	 * fst_llt - default FST LLT (Link-Lost Timeout) to be used for the 	 * interface. 	 */
name|int
name|fst_llt
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
name|void
name|wpa_config_foreach_network
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|config
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
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
name|int
name|wpa_config_set_quoted
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_config_dump_values
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|config
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
name|wpa_config_get_value
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
name|void
name|wpa_config_flush_blobs
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpa_cred
modifier|*
name|wpa_config_get_cred
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
name|wpa_cred
modifier|*
name|wpa_config_add_cred
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
name|wpa_config_remove_cred
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
name|wpa_config_free_cred
parameter_list|(
name|struct
name|wpa_cred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_config_set_cred
parameter_list|(
name|struct
name|wpa_cred
modifier|*
name|cred
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
name|wpa_config_get_cred_no_key
parameter_list|(
name|struct
name|wpa_cred
modifier|*
name|cred
parameter_list|,
specifier|const
name|char
modifier|*
name|var
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
comment|/* Prototypes for common functions from config.c */
end_comment

begin_function_decl
name|int
name|wpa_config_process_global
parameter_list|(
name|struct
name|wpa_config
modifier|*
name|config
parameter_list|,
name|char
modifier|*
name|pos
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Prototypes for backend specific functions from the selected config_*.c */
end_comment

begin_comment
comment|/**  * wpa_config_read - Read and parse configuration database  * @name: Name of the configuration (e.g., path and file name for the  * configuration file)  * @cfgp: Pointer to previously allocated configuration data or %NULL if none  * Returns: Pointer to allocated configuration data or %NULL on failure  *  * This function reads configuration data, parses its contents, and allocates  * data structures needed for storing configuration information. The allocated  * data can be freed with wpa_config_free().  *  * Each configuration backend needs to implement this function.  */
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
parameter_list|,
name|struct
name|wpa_config
modifier|*
name|cfgp
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

