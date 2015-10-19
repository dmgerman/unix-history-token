begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Wi-Fi Direct - P2P module  * Copyright (c) 2009-2010, Atheros Communications  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|P2P_H
end_ifndef

begin_define
define|#
directive|define
name|P2P_H
end_define

begin_include
include|#
directive|include
file|"common/ieee802_11_defs.h"
end_include

begin_include
include|#
directive|include
file|"wps/wps.h"
end_include

begin_comment
comment|/* P2P ASP Setup Capability */
end_comment

begin_define
define|#
directive|define
name|P2PS_SETUP_NONE
value|0
end_define

begin_define
define|#
directive|define
name|P2PS_SETUP_NEW
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|P2PS_SETUP_CLIENT
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|P2PS_SETUP_GROUP_OWNER
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|P2PS_WILD_HASH_STR
value|"org.wi-fi.wfds"
end_define

begin_define
define|#
directive|define
name|P2PS_HASH_LEN
value|6
end_define

begin_define
define|#
directive|define
name|P2P_MAX_QUERY_HASH
value|6
end_define

begin_define
define|#
directive|define
name|P2PS_FEATURE_CAPAB_CPT_MAX
value|2
end_define

begin_comment
comment|/**  * P2P_MAX_PREF_CHANNELS - Maximum number of preferred channels  */
end_comment

begin_define
define|#
directive|define
name|P2P_MAX_PREF_CHANNELS
value|100
end_define

begin_comment
comment|/**  * P2P_MAX_REG_CLASSES - Maximum number of regulatory classes  */
end_comment

begin_define
define|#
directive|define
name|P2P_MAX_REG_CLASSES
value|10
end_define

begin_comment
comment|/**  * P2P_MAX_REG_CLASS_CHANNELS - Maximum number of channels per regulatory class  */
end_comment

begin_define
define|#
directive|define
name|P2P_MAX_REG_CLASS_CHANNELS
value|20
end_define

begin_comment
comment|/**  * struct p2p_channels - List of supported channels  */
end_comment

begin_struct
struct|struct
name|p2p_channels
block|{
comment|/** 	 * struct p2p_reg_class - Supported regulatory class 	 */
struct|struct
name|p2p_reg_class
block|{
comment|/** 		 * reg_class - Regulatory class (IEEE 802.11-2007, Annex J) 		 */
name|u8
name|reg_class
decl_stmt|;
comment|/** 		 * channel - Supported channels 		 */
name|u8
name|channel
index|[
name|P2P_MAX_REG_CLASS_CHANNELS
index|]
decl_stmt|;
comment|/** 		 * channels - Number of channel entries in use 		 */
name|size_t
name|channels
decl_stmt|;
block|}
name|reg_class
index|[
name|P2P_MAX_REG_CLASSES
index|]
struct|;
comment|/** 	 * reg_classes - Number of reg_class entries in use 	 */
name|size_t
name|reg_classes
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|p2p_wps_method
block|{
name|WPS_NOT_READY
block|,
name|WPS_PIN_DISPLAY
block|,
name|WPS_PIN_KEYPAD
block|,
name|WPS_PBC
block|,
name|WPS_NFC
block|,
name|WPS_P2PS
block|}
enum|;
end_enum

begin_comment
comment|/**  * struct p2p_go_neg_results - P2P Group Owner Negotiation results  */
end_comment

begin_struct
struct|struct
name|p2p_go_neg_results
block|{
comment|/** 	 * status - Negotiation result (Status Code) 	 * 	 * 0 (P2P_SC_SUCCESS) indicates success. Non-zero values indicate 	 * failed negotiation. 	 */
name|int
name|status
decl_stmt|;
comment|/** 	 * role_go - Whether local end is Group Owner 	 */
name|int
name|role_go
decl_stmt|;
comment|/** 	 * freq - Frequency of the group operational channel in MHz 	 */
name|int
name|freq
decl_stmt|;
name|int
name|ht40
decl_stmt|;
name|int
name|vht
decl_stmt|;
comment|/** 	 * ssid - SSID of the group 	 */
name|u8
name|ssid
index|[
name|SSID_MAX_LEN
index|]
decl_stmt|;
comment|/** 	 * ssid_len - Length of SSID in octets 	 */
name|size_t
name|ssid_len
decl_stmt|;
comment|/** 	 * psk - WPA pre-shared key (256 bits) (GO only) 	 */
name|u8
name|psk
index|[
literal|32
index|]
decl_stmt|;
comment|/** 	 * psk_set - Whether PSK field is configured (GO only) 	 */
name|int
name|psk_set
decl_stmt|;
comment|/** 	 * passphrase - WPA2-Personal passphrase for the group (GO only) 	 */
name|char
name|passphrase
index|[
literal|64
index|]
decl_stmt|;
comment|/** 	 * peer_device_addr - P2P Device Address of the peer 	 */
name|u8
name|peer_device_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** 	 * peer_interface_addr - P2P Interface Address of the peer 	 */
name|u8
name|peer_interface_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** 	 * wps_method - WPS method to be used during provisioning 	 */
name|enum
name|p2p_wps_method
name|wps_method
decl_stmt|;
define|#
directive|define
name|P2P_MAX_CHANNELS
value|50
comment|/** 	 * freq_list - Zero-terminated list of possible operational channels 	 */
name|int
name|freq_list
index|[
name|P2P_MAX_CHANNELS
index|]
decl_stmt|;
comment|/** 	 * persistent_group - Whether the group should be made persistent 	 * 0 = not persistent 	 * 1 = persistent group without persistent reconnect 	 * 2 = persistent group with persistent reconnect 	 */
name|int
name|persistent_group
decl_stmt|;
comment|/** 	 * peer_config_timeout - Peer configuration timeout (in 10 msec units) 	 */
name|unsigned
name|int
name|peer_config_timeout
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|p2ps_provision
block|{
comment|/** 	 * pd_seeker - P2PS provision discovery seeker role 	 */
name|unsigned
name|int
name|pd_seeker
range|:
literal|1
decl_stmt|;
comment|/** 	 * status - Remote returned provisioning status code 	 */
name|int
name|status
decl_stmt|;
comment|/** 	 * adv_id - P2PS Advertisement ID 	 */
name|u32
name|adv_id
decl_stmt|;
comment|/** 	 * session_id - P2PS Session ID 	 */
name|u32
name|session_id
decl_stmt|;
comment|/** 	 * method - WPS Method (to be) used to establish session 	 */
name|u16
name|method
decl_stmt|;
comment|/** 	 * conncap - Connection Capabilities negotiated between P2P peers 	 */
name|u8
name|conncap
decl_stmt|;
comment|/** 	 * role - Info about the roles to be used for this connection 	 */
name|u8
name|role
decl_stmt|;
comment|/** 	 * session_mac - MAC address of the peer that started the session 	 */
name|u8
name|session_mac
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** 	 * adv_mac - MAC address of the peer advertised the service 	 */
name|u8
name|adv_mac
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** 	 * cpt_mask - Supported Coordination Protocol Transport mask 	 * 	 * A bitwise mask of supported ASP Coordination Protocol Transports. 	 * This property is set together and corresponds with cpt_priority. 	 */
name|u8
name|cpt_mask
decl_stmt|;
comment|/** 	 * cpt_priority - Coordination Protocol Transport priority list 	 * 	 * Priorities of supported ASP Coordination Protocol Transports. 	 * This property is set together and corresponds with cpt_mask. 	 * The CPT priority list is 0 terminated. 	 */
name|u8
name|cpt_priority
index|[
name|P2PS_FEATURE_CAPAB_CPT_MAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/** 	 * info - Vendor defined extra Provisioning information 	 */
name|char
name|info
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|p2ps_advertisement
block|{
name|struct
name|p2ps_advertisement
modifier|*
name|next
decl_stmt|;
comment|/** 	 * svc_info - Pointer to (internal) Service defined information 	 */
name|char
modifier|*
name|svc_info
decl_stmt|;
comment|/** 	 * id - P2PS Advertisement ID 	 */
name|u32
name|id
decl_stmt|;
comment|/** 	 * config_methods - WPS Methods which are allowed for this service 	 */
name|u16
name|config_methods
decl_stmt|;
comment|/** 	 * state - Current state of the service: 0 - Out Of Service, 1-255 Vendor defined 	 */
name|u8
name|state
decl_stmt|;
comment|/** 	 * auto_accept - Automatically Accept provisioning request if possible. 	 */
name|u8
name|auto_accept
decl_stmt|;
comment|/** 	 * hash - 6 octet Service Name has to match against incoming Probe Requests 	 */
name|u8
name|hash
index|[
name|P2PS_HASH_LEN
index|]
decl_stmt|;
comment|/** 	 * cpt_mask - supported Coordination Protocol Transport mask 	 * 	 * A bitwise mask of supported ASP Coordination Protocol Transports. 	 * This property is set together and corresponds with cpt_priority. 	 */
name|u8
name|cpt_mask
decl_stmt|;
comment|/** 	 * cpt_priority - Coordination Protocol Transport priority list 	 * 	 * Priorities of supported ASP Coordinatin Protocol Transports. 	 * This property is set together and corresponds with cpt_mask. 	 * The CPT priority list is 0 terminated. 	 */
name|u8
name|cpt_priority
index|[
name|P2PS_FEATURE_CAPAB_CPT_MAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/** 	 * svc_name - NULL Terminated UTF-8 Service Name, and svc_info storage 	 */
name|char
name|svc_name
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|p2p_data
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|p2p_scan_type
block|{
name|P2P_SCAN_SOCIAL
block|,
name|P2P_SCAN_FULL
block|,
name|P2P_SCAN_SPECIFIC
block|,
name|P2P_SCAN_SOCIAL_PLUS_ONE
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|P2P_MAX_WPS_VENDOR_EXT
value|10
end_define

begin_comment
comment|/**  * struct p2p_peer_info - P2P peer information  */
end_comment

begin_struct
struct|struct
name|p2p_peer_info
block|{
comment|/** 	 * p2p_device_addr - P2P Device Address of the peer 	 */
name|u8
name|p2p_device_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** 	 * pri_dev_type - Primary Device Type 	 */
name|u8
name|pri_dev_type
index|[
literal|8
index|]
decl_stmt|;
comment|/** 	 * device_name - Device Name (0..32 octets encoded in UTF-8) 	 */
name|char
name|device_name
index|[
name|WPS_DEV_NAME_MAX_LEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/** 	 * manufacturer - Manufacturer (0..64 octets encoded in UTF-8) 	 */
name|char
name|manufacturer
index|[
name|WPS_MANUFACTURER_MAX_LEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/** 	 * model_name - Model Name (0..32 octets encoded in UTF-8) 	 */
name|char
name|model_name
index|[
name|WPS_MODEL_NAME_MAX_LEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/** 	 * model_number - Model Number (0..32 octets encoded in UTF-8) 	 */
name|char
name|model_number
index|[
name|WPS_MODEL_NUMBER_MAX_LEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/** 	 * serial_number - Serial Number (0..32 octets encoded in UTF-8) 	 */
name|char
name|serial_number
index|[
name|WPS_SERIAL_NUMBER_MAX_LEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/** 	 * level - Signal level 	 */
name|int
name|level
decl_stmt|;
comment|/** 	 * config_methods - WPS Configuration Methods 	 */
name|u16
name|config_methods
decl_stmt|;
comment|/** 	 * dev_capab - Device Capabilities 	 */
name|u8
name|dev_capab
decl_stmt|;
comment|/** 	 * group_capab - Group Capabilities 	 */
name|u8
name|group_capab
decl_stmt|;
comment|/** 	 * wps_sec_dev_type_list - WPS secondary device type list 	 * 	 * This list includes from 0 to 16 Secondary Device Types as indicated 	 * by wps_sec_dev_type_list_len (8 * number of types). 	 */
name|u8
name|wps_sec_dev_type_list
index|[
name|WPS_SEC_DEV_TYPE_MAX_LEN
index|]
decl_stmt|;
comment|/** 	 * wps_sec_dev_type_list_len - Length of secondary device type list 	 */
name|size_t
name|wps_sec_dev_type_list_len
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|wps_vendor_ext
index|[
name|P2P_MAX_WPS_VENDOR_EXT
index|]
decl_stmt|;
comment|/** 	 * wfd_subelems - Wi-Fi Display subelements from WFD IE(s) 	 */
name|struct
name|wpabuf
modifier|*
name|wfd_subelems
decl_stmt|;
comment|/** 	 * vendor_elems - Unrecognized vendor elements 	 * 	 * This buffer includes any other vendor element than P2P, WPS, and WFD 	 * IE(s) from the frame that was used to discover the peer. 	 */
name|struct
name|wpabuf
modifier|*
name|vendor_elems
decl_stmt|;
comment|/** 	 * p2ps_instance - P2PS Application Service Info 	 */
name|struct
name|wpabuf
modifier|*
name|p2ps_instance
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|p2p_prov_disc_status
block|{
name|P2P_PROV_DISC_SUCCESS
block|,
name|P2P_PROV_DISC_TIMEOUT
block|,
name|P2P_PROV_DISC_REJECTED
block|,
name|P2P_PROV_DISC_TIMEOUT_JOIN
block|,
name|P2P_PROV_DISC_INFO_UNAVAILABLE
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|p2p_channel
block|{
name|u8
name|op_class
decl_stmt|;
name|u8
name|chan
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct p2p_config - P2P configuration  *  * This configuration is provided to the P2P module during initialization with  * p2p_init().  */
end_comment

begin_struct
struct|struct
name|p2p_config
block|{
comment|/** 	 * country - Country code to use in P2P operations 	 */
name|char
name|country
index|[
literal|3
index|]
decl_stmt|;
comment|/** 	 * reg_class - Regulatory class for own listen channel 	 */
name|u8
name|reg_class
decl_stmt|;
comment|/** 	 * channel - Own listen channel 	 */
name|u8
name|channel
decl_stmt|;
comment|/** 	 * channel_forced - the listen channel was forced by configuration 	 *                  or by control interface and cannot be overridden 	 */
name|u8
name|channel_forced
decl_stmt|;
comment|/** 	 * Regulatory class for own operational channel 	 */
name|u8
name|op_reg_class
decl_stmt|;
comment|/** 	 * op_channel - Own operational channel 	 */
name|u8
name|op_channel
decl_stmt|;
comment|/** 	 * cfg_op_channel - Whether op_channel is hardcoded in configuration 	 */
name|u8
name|cfg_op_channel
decl_stmt|;
comment|/** 	 * channels - Own supported regulatory classes and channels 	 * 	 * List of supposerted channels per regulatory class. The regulatory 	 * classes are defined in IEEE Std 802.11-2007 Annex J and the 	 * numbering of the clases depends on the configured country code. 	 */
name|struct
name|p2p_channels
name|channels
decl_stmt|;
comment|/** 	 * cli_channels - Additional client channels 	 * 	 * This list of channels (if any) will be used when advertising local 	 * channels during GO Negotiation or Invitation for the cases where the 	 * local end may become the client. This may allow the peer to become a 	 * GO on additional channels if it supports these options. The main use 	 * case for this is to include passive-scan channels on devices that may 	 * not know their current location and have configured most channels to 	 * not allow initiation of radition (i.e., another device needs to take 	 * master responsibilities). 	 */
name|struct
name|p2p_channels
name|cli_channels
decl_stmt|;
comment|/** 	 * num_pref_chan - Number of pref_chan entries 	 */
name|unsigned
name|int
name|num_pref_chan
decl_stmt|;
comment|/** 	 * pref_chan - Preferred channels for GO Negotiation 	 */
name|struct
name|p2p_channel
modifier|*
name|pref_chan
decl_stmt|;
comment|/** 	 * pri_dev_type - Primary Device Type (see WPS) 	 */
name|u8
name|pri_dev_type
index|[
literal|8
index|]
decl_stmt|;
comment|/** 	 * P2P_SEC_DEVICE_TYPES - Maximum number of secondary device types 	 */
define|#
directive|define
name|P2P_SEC_DEVICE_TYPES
value|5
comment|/** 	 * sec_dev_type - Optional secondary device types 	 */
name|u8
name|sec_dev_type
index|[
name|P2P_SEC_DEVICE_TYPES
index|]
index|[
literal|8
index|]
decl_stmt|;
comment|/** 	 * num_sec_dev_types - Number of sec_dev_type entries 	 */
name|size_t
name|num_sec_dev_types
decl_stmt|;
comment|/** 	 * dev_addr - P2P Device Address 	 */
name|u8
name|dev_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** 	 * dev_name - Device Name 	 */
name|char
modifier|*
name|dev_name
decl_stmt|;
name|char
modifier|*
name|manufacturer
decl_stmt|;
name|char
modifier|*
name|model_name
decl_stmt|;
name|char
modifier|*
name|model_number
decl_stmt|;
name|char
modifier|*
name|serial_number
decl_stmt|;
name|u8
name|uuid
index|[
literal|16
index|]
decl_stmt|;
name|u16
name|config_methods
decl_stmt|;
comment|/** 	 * concurrent_operations - Whether concurrent operations are supported 	 */
name|int
name|concurrent_operations
decl_stmt|;
comment|/** 	 * max_peers - Maximum number of discovered peers to remember 	 * 	 * If more peers are discovered, older entries will be removed to make 	 * room for the new ones. 	 */
name|size_t
name|max_peers
decl_stmt|;
comment|/** 	 * p2p_intra_bss - Intra BSS communication is supported 	 */
name|int
name|p2p_intra_bss
decl_stmt|;
comment|/** 	 * ssid_postfix - Postfix data to add to the SSID 	 * 	 * This data will be added to the end of the SSID after the 	 * DIRECT-<random two octets> prefix. 	 */
name|u8
name|ssid_postfix
index|[
name|SSID_MAX_LEN
operator|-
literal|9
index|]
decl_stmt|;
comment|/** 	 * ssid_postfix_len - Length of the ssid_postfix data 	 */
name|size_t
name|ssid_postfix_len
decl_stmt|;
comment|/** 	 * max_listen - Maximum listen duration in ms 	 */
name|unsigned
name|int
name|max_listen
decl_stmt|;
comment|/** 	 * passphrase_len - Passphrase length (8..63) 	 * 	 * This parameter controls the length of the random passphrase that is 	 * generated at the GO. 	 */
name|unsigned
name|int
name|passphrase_len
decl_stmt|;
comment|/** 	 * cb_ctx - Context to use with callback functions 	 */
name|void
modifier|*
name|cb_ctx
decl_stmt|;
comment|/** 	 * debug_print - Debug print 	 * @ctx: Callback context from cb_ctx 	 * @level: Debug verbosity level (MSG_*) 	 * @msg: Debug message 	 */
name|void
function_decl|(
modifier|*
name|debug_print
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
comment|/* Callbacks to request lower layer driver operations */
comment|/** 	 * p2p_scan - Request a P2P scan/search 	 * @ctx: Callback context from cb_ctx 	 * @type: Scan type 	 * @freq: Specific frequency (MHz) to scan or 0 for no restriction 	 * @num_req_dev_types: Number of requested device types 	 * @req_dev_types: Array containing requested device types 	 * @dev_id: Device ID to search for or %NULL to find all devices 	 * @pw_id: Device Password ID 	 * Returns: 0 on success, -1 on failure 	 * 	 * This callback function is used to request a P2P scan or search 	 * operation to be completed. Type type argument specifies which type 	 * of scan is to be done. @P2P_SCAN_SOCIAL indicates that only the 	 * social channels (1, 6, 11) should be scanned. @P2P_SCAN_FULL 	 * indicates that all channels are to be scanned. @P2P_SCAN_SPECIFIC 	 * request a scan of a single channel specified by freq. 	 * @P2P_SCAN_SOCIAL_PLUS_ONE request scan of all the social channels 	 * plus one extra channel specified by freq. 	 * 	 * The full scan is used for the initial scan to find group owners from 	 * all. The other types are used during search phase scan of the social 	 * channels (with potential variation if the Listen channel of the 	 * target peer is known or if other channels are scanned in steps). 	 * 	 * The scan results are returned after this call by calling 	 * p2p_scan_res_handler() for each scan result that has a P2P IE and 	 * then calling p2p_scan_res_handled() to indicate that all scan 	 * results have been indicated. 	 */
name|int
function_decl|(
modifier|*
name|p2p_scan
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|enum
name|p2p_scan_type
name|type
parameter_list|,
name|int
name|freq
parameter_list|,
name|unsigned
name|int
name|num_req_dev_types
parameter_list|,
specifier|const
name|u8
modifier|*
name|req_dev_types
parameter_list|,
specifier|const
name|u8
modifier|*
name|dev_id
parameter_list|,
name|u16
name|pw_id
parameter_list|)
function_decl|;
comment|/** 	 * send_probe_resp - Transmit a Probe Response frame 	 * @ctx: Callback context from cb_ctx 	 * @buf: Probe Response frame (including the header and body) 	 * @freq: Forced frequency (in MHz) to use or 0. 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function is used to reply to Probe Request frames that were 	 * indicated with a call to p2p_probe_req_rx(). The response is to be 	 * sent on the same channel, unless otherwise specified, or to be 	 * dropped if the driver is not listening to Probe Request frames 	 * anymore. 	 * 	 * Alternatively, the responsibility for building the Probe Response 	 * frames in Listen state may be in another system component in which 	 * case this function need to be implemented (i.e., the function 	 * pointer can be %NULL). The WPS and P2P IEs to be added for Probe 	 * Response frames in such a case are available from the 	 * start_listen() callback. It should be noted that the received Probe 	 * Request frames must be indicated by calling p2p_probe_req_rx() even 	 * if this send_probe_resp() is not used. 	 */
name|int
function_decl|(
modifier|*
name|send_probe_resp
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|)
function_decl|;
comment|/** 	 * send_action - Transmit an Action frame 	 * @ctx: Callback context from cb_ctx 	 * @freq: Frequency in MHz for the channel on which to transmit 	 * @dst: Destination MAC address (Address 1) 	 * @src: Source MAC address (Address 2) 	 * @bssid: BSSID (Address 3) 	 * @buf: Frame body (starting from Category field) 	 * @len: Length of buf in octets 	 * @wait_time: How many msec to wait for a response frame 	 * Returns: 0 on success, -1 on failure 	 * 	 * The Action frame may not be transmitted immediately and the status 	 * of the transmission must be reported by calling 	 * p2p_send_action_cb() once the frame has either been transmitted or 	 * it has been dropped due to excessive retries or other failure to 	 * transmit. 	 */
name|int
function_decl|(
modifier|*
name|send_action
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
specifier|const
name|u8
modifier|*
name|src
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|unsigned
name|int
name|wait_time
parameter_list|)
function_decl|;
comment|/** 	 * send_action_done - Notify that Action frame sequence was completed 	 * @ctx: Callback context from cb_ctx 	 * 	 * This function is called when the Action frame sequence that was 	 * started with send_action() has been completed, i.e., when there is 	 * no need to wait for a response from the destination peer anymore. 	 */
name|void
function_decl|(
modifier|*
name|send_action_done
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/** 	 * start_listen - Start Listen state 	 * @ctx: Callback context from cb_ctx 	 * @freq: Frequency of the listen channel in MHz 	 * @duration: Duration for the Listen state in milliseconds 	 * @probe_resp_ie: IE(s) to be added to Probe Response frames 	 * Returns: 0 on success, -1 on failure 	 * 	 * This Listen state may not start immediately since the driver may 	 * have other pending operations to complete first. Once the Listen 	 * state has started, p2p_listen_cb() must be called to notify the P2P 	 * module. Once the Listen state is stopped, p2p_listen_end() must be 	 * called to notify the P2P module that the driver is not in the Listen 	 * state anymore. 	 * 	 * If the send_probe_resp() is not used for generating the response, 	 * the IEs from probe_resp_ie need to be added to the end of the Probe 	 * Response frame body. If send_probe_resp() is used, the probe_resp_ie 	 * information can be ignored. 	 */
name|int
function_decl|(
modifier|*
name|start_listen
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|,
name|unsigned
name|int
name|duration
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|probe_resp_ie
parameter_list|)
function_decl|;
comment|/** 	 * stop_listen - Stop Listen state 	 * @ctx: Callback context from cb_ctx 	 * 	 * This callback can be used to stop a Listen state operation that was 	 * previously requested with start_listen(). 	 */
name|void
function_decl|(
modifier|*
name|stop_listen
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/** 	 * get_noa - Get current Notice of Absence attribute payload 	 * @ctx: Callback context from cb_ctx 	 * @interface_addr: P2P Interface Address of the GO 	 * @buf: Buffer for returning NoA 	 * @buf_len: Buffer length in octets 	 * Returns: Number of octets used in buf, 0 to indicate no NoA is being 	 * advertized, or -1 on failure 	 * 	 * This function is used to fetch the current Notice of Absence 	 * attribute value from GO. 	 */
name|int
function_decl|(
modifier|*
name|get_noa
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|interface_addr
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_len
parameter_list|)
function_decl|;
comment|/* Callbacks to notify events to upper layer management entity */
comment|/** 	 * dev_found - Notification of a found P2P Device 	 * @ctx: Callback context from cb_ctx 	 * @addr: Source address of the message triggering this notification 	 * @info: P2P peer information 	 * @new_device: Inform if the peer is newly found 	 * 	 * This callback is used to notify that a new P2P Device has been 	 * found. This may happen, e.g., during Search state based on scan 	 * results or during Listen state based on receive Probe Request and 	 * Group Owner Negotiation Request. 	 */
name|void
function_decl|(
modifier|*
name|dev_found
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|struct
name|p2p_peer_info
modifier|*
name|info
parameter_list|,
name|int
name|new_device
parameter_list|)
function_decl|;
comment|/** 	 * dev_lost - Notification of a lost P2P Device 	 * @ctx: Callback context from cb_ctx 	 * @dev_addr: P2P Device Address of the lost P2P Device 	 * 	 * This callback is used to notify that a P2P Device has been deleted. 	 */
name|void
function_decl|(
modifier|*
name|dev_lost
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|dev_addr
parameter_list|)
function_decl|;
comment|/** 	 * find_stopped - Notification of a p2p_find operation stopping 	 * @ctx: Callback context from cb_ctx 	 */
name|void
function_decl|(
modifier|*
name|find_stopped
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/** 	 * go_neg_req_rx - Notification of a receive GO Negotiation Request 	 * @ctx: Callback context from cb_ctx 	 * @src: Source address of the message triggering this notification 	 * @dev_passwd_id: WPS Device Password ID 	 * @go_intent: Peer's GO Intent 	 * 	 * This callback is used to notify that a P2P Device is requesting 	 * group owner negotiation with us, but we do not have all the 	 * necessary information to start GO Negotiation. This indicates that 	 * the local user has not authorized the connection yet by providing a 	 * PIN or PBC button press. This information can be provided with a 	 * call to p2p_connect(). 	 */
name|void
function_decl|(
modifier|*
name|go_neg_req_rx
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|src
parameter_list|,
name|u16
name|dev_passwd_id
parameter_list|,
name|u8
name|go_intent
parameter_list|)
function_decl|;
comment|/** 	 * go_neg_completed - Notification of GO Negotiation results 	 * @ctx: Callback context from cb_ctx 	 * @res: GO Negotiation results 	 * 	 * This callback is used to notify that Group Owner Negotiation has 	 * been completed. Non-zero struct p2p_go_neg_results::status indicates 	 * failed negotiation. In case of success, this function is responsible 	 * for creating a new group interface (or using the existing interface 	 * depending on driver features), setting up the group interface in 	 * proper mode based on struct p2p_go_neg_results::role_go and 	 * initializing WPS provisioning either as a Registrar (if GO) or as an 	 * Enrollee. Successful WPS provisioning must be indicated by calling 	 * p2p_wps_success_cb(). The callee is responsible for timing out group 	 * formation if WPS provisioning cannot be completed successfully 	 * within 15 seconds. 	 */
name|void
function_decl|(
modifier|*
name|go_neg_completed
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|struct
name|p2p_go_neg_results
modifier|*
name|res
parameter_list|)
function_decl|;
comment|/** 	 * sd_request - Callback on Service Discovery Request 	 * @ctx: Callback context from cb_ctx 	 * @freq: Frequency (in MHz) of the channel 	 * @sa: Source address of the request 	 * @dialog_token: Dialog token 	 * @update_indic: Service Update Indicator from the source of request 	 * @tlvs: P2P Service Request TLV(s) 	 * @tlvs_len: Length of tlvs buffer in octets 	 * 	 * This callback is used to indicate reception of a service discovery 	 * request. Response to the query must be indicated by calling 	 * p2p_sd_response() with the context information from the arguments to 	 * this callback function. 	 * 	 * This callback handler can be set to %NULL to indicate that service 	 * discovery is not supported. 	 */
name|void
function_decl|(
modifier|*
name|sd_request
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|int
name|freq
parameter_list|,
specifier|const
name|u8
modifier|*
name|sa
parameter_list|,
name|u8
name|dialog_token
parameter_list|,
name|u16
name|update_indic
parameter_list|,
specifier|const
name|u8
modifier|*
name|tlvs
parameter_list|,
name|size_t
name|tlvs_len
parameter_list|)
function_decl|;
comment|/** 	 * sd_response - Callback on Service Discovery Response 	 * @ctx: Callback context from cb_ctx 	 * @sa: Source address of the request 	 * @update_indic: Service Update Indicator from the source of response 	 * @tlvs: P2P Service Response TLV(s) 	 * @tlvs_len: Length of tlvs buffer in octets 	 * 	 * This callback is used to indicate reception of a service discovery 	 * response. This callback handler can be set to %NULL if no service 	 * discovery requests are used. The information provided with this call 	 * is replies to the queries scheduled with p2p_sd_request(). 	 */
name|void
function_decl|(
modifier|*
name|sd_response
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|sa
parameter_list|,
name|u16
name|update_indic
parameter_list|,
specifier|const
name|u8
modifier|*
name|tlvs
parameter_list|,
name|size_t
name|tlvs_len
parameter_list|)
function_decl|;
comment|/** 	 * prov_disc_req - Callback on Provisiong Discovery Request 	 * @ctx: Callback context from cb_ctx 	 * @peer: Source address of the request 	 * @config_methods: Requested WPS Config Method 	 * @dev_addr: P2P Device Address of the found P2P Device 	 * @pri_dev_type: Primary Device Type 	 * @dev_name: Device Name 	 * @supp_config_methods: Supported configuration Methods 	 * @dev_capab: Device Capabilities 	 * @group_capab: Group Capabilities 	 * @group_id: P2P Group ID (or %NULL if not included) 	 * @group_id_len: Length of P2P Group ID 	 * 	 * This callback is used to indicate reception of a Provision Discovery 	 * Request frame that the P2P module accepted. 	 */
name|void
function_decl|(
modifier|*
name|prov_disc_req
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer
parameter_list|,
name|u16
name|config_methods
parameter_list|,
specifier|const
name|u8
modifier|*
name|dev_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|pri_dev_type
parameter_list|,
specifier|const
name|char
modifier|*
name|dev_name
parameter_list|,
name|u16
name|supp_config_methods
parameter_list|,
name|u8
name|dev_capab
parameter_list|,
name|u8
name|group_capab
parameter_list|,
specifier|const
name|u8
modifier|*
name|group_id
parameter_list|,
name|size_t
name|group_id_len
parameter_list|)
function_decl|;
comment|/** 	 * prov_disc_resp - Callback on Provisiong Discovery Response 	 * @ctx: Callback context from cb_ctx 	 * @peer: Source address of the response 	 * @config_methods: Value from p2p_prov_disc_req() or 0 on failure 	 * 	 * This callback is used to indicate reception of a Provision Discovery 	 * Response frame for a pending request scheduled with 	 * p2p_prov_disc_req(). This callback handler can be set to %NULL if 	 * provision discovery is not used. 	 */
name|void
function_decl|(
modifier|*
name|prov_disc_resp
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer
parameter_list|,
name|u16
name|config_methods
parameter_list|)
function_decl|;
comment|/** 	 * prov_disc_fail - Callback on Provision Discovery failure 	 * @ctx: Callback context from cb_ctx 	 * @peer: Source address of the response 	 * @status: Cause of failure, will not be %P2P_PROV_DISC_SUCCESS 	 * @adv_id: If non-zero, then the adv_id of the PD Request 	 * @adv_mac: P2P Device Address of the advertizer 	 * @deferred_session_resp: Deferred session response sent by advertizer 	 * 	 * This callback is used to indicate either a failure or no response 	 * to an earlier provision discovery request. 	 * 	 * This callback handler can be set to %NULL if provision discovery 	 * is not used or failures do not need to be indicated. 	 */
name|void
function_decl|(
modifier|*
name|prov_disc_fail
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer
parameter_list|,
name|enum
name|p2p_prov_disc_status
name|status
parameter_list|,
name|u32
name|adv_id
parameter_list|,
specifier|const
name|u8
modifier|*
name|adv_mac
parameter_list|,
specifier|const
name|char
modifier|*
name|deferred_session_resp
parameter_list|)
function_decl|;
comment|/** 	 * invitation_process - Optional callback for processing Invitations 	 * @ctx: Callback context from cb_ctx 	 * @sa: Source address of the Invitation Request 	 * @bssid: P2P Group BSSID from the request or %NULL if not included 	 * @go_dev_addr: GO Device Address from P2P Group ID 	 * @ssid: SSID from P2P Group ID 	 * @ssid_len: Length of ssid buffer in octets 	 * @go: Variable for returning whether the local end is GO in the group 	 * @group_bssid: Buffer for returning P2P Group BSSID (if local end GO) 	 * @force_freq: Variable for returning forced frequency for the group 	 * @persistent_group: Whether this is an invitation to reinvoke a 	 *	persistent group (instead of invitation to join an active 	 *	group) 	 * @channels: Available operating channels for the group 	 * @dev_pw_id: Device Password ID for NFC static handover or -1 if not 	 *	used 	 * Returns: Status code (P2P_SC_*) 	 * 	 * This optional callback can be used to implement persistent reconnect 	 * by allowing automatic restarting of persistent groups without user 	 * interaction. If this callback is not implemented (i.e., is %NULL), 	 * the received Invitation Request frames are replied with 	 * %P2P_SC_REQ_RECEIVED status and indicated to upper layer with the 	 * invitation_result() callback. 	 * 	 * If the requested parameters are acceptable and the group is known, 	 * %P2P_SC_SUCCESS may be returned. If the requested group is unknown, 	 * %P2P_SC_FAIL_UNKNOWN_GROUP should be returned. %P2P_SC_REQ_RECEIVED 	 * can be returned if there is not enough data to provide immediate 	 * response, i.e., if some sort of user interaction is needed. The 	 * invitation_received() callback will be called in that case 	 * immediately after this call. 	 */
name|u8
function_decl|(
modifier|*
name|invitation_process
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|sa
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
specifier|const
name|u8
modifier|*
name|go_dev_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|ssid
parameter_list|,
name|size_t
name|ssid_len
parameter_list|,
name|int
modifier|*
name|go
parameter_list|,
name|u8
modifier|*
name|group_bssid
parameter_list|,
name|int
modifier|*
name|force_freq
parameter_list|,
name|int
name|persistent_group
parameter_list|,
specifier|const
name|struct
name|p2p_channels
modifier|*
name|channels
parameter_list|,
name|int
name|dev_pw_id
parameter_list|)
function_decl|;
comment|/** 	 * invitation_received - Callback on Invitation Request RX 	 * @ctx: Callback context from cb_ctx 	 * @sa: Source address of the Invitation Request 	 * @bssid: P2P Group BSSID or %NULL if not received 	 * @ssid: SSID of the group 	 * @ssid_len: Length of ssid in octets 	 * @go_dev_addr: GO Device Address 	 * @status: Response Status 	 * @op_freq: Operational frequency for the group 	 * 	 * This callback is used to indicate sending of an Invitation Response 	 * for a received Invitation Request. If status == 0 (success), the 	 * upper layer code is responsible for starting the group. status == 1 	 * indicates need to get user authorization for the group. Other status 	 * values indicate that the invitation request was rejected. 	 */
name|void
function_decl|(
modifier|*
name|invitation_received
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|sa
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
specifier|const
name|u8
modifier|*
name|ssid
parameter_list|,
name|size_t
name|ssid_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|go_dev_addr
parameter_list|,
name|u8
name|status
parameter_list|,
name|int
name|op_freq
parameter_list|)
function_decl|;
comment|/** 	 * invitation_result - Callback on Invitation result 	 * @ctx: Callback context from cb_ctx 	 * @status: Negotiation result (Status Code) 	 * @bssid: P2P Group BSSID or %NULL if not received 	 * @channels: Available operating channels for the group 	 * @addr: Peer address 	 * @freq: Frequency (in MHz) indicated during invitation or 0 	 * @peer_oper_freq: Operating frequency (in MHz) advertized by the peer 	 * during invitation or 0 	 * 	 * This callback is used to indicate result of an Invitation procedure 	 * started with a call to p2p_invite(). The indicated status code is 	 * the value received from the peer in Invitation Response with 0 	 * (P2P_SC_SUCCESS) indicating success or -1 to indicate a timeout or a 	 * local failure in transmitting the Invitation Request. 	 */
name|void
function_decl|(
modifier|*
name|invitation_result
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|int
name|status
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
specifier|const
name|struct
name|p2p_channels
modifier|*
name|channels
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|freq
parameter_list|,
name|int
name|peer_oper_freq
parameter_list|)
function_decl|;
comment|/** 	 * go_connected - Check whether we are connected to a GO 	 * @ctx: Callback context from cb_ctx 	 * @dev_addr: P2P Device Address of a GO 	 * Returns: 1 if we are connected as a P2P client to the specified GO 	 * or 0 if not. 	 */
name|int
function_decl|(
modifier|*
name|go_connected
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|dev_addr
parameter_list|)
function_decl|;
comment|/** 	 * presence_resp - Callback on Presence Response 	 * @ctx: Callback context from cb_ctx 	 * @src: Source address (GO's P2P Interface Address) 	 * @status: Result of the request (P2P_SC_*) 	 * @noa: Returned NoA value 	 * @noa_len: Length of the NoA buffer in octets 	 */
name|void
function_decl|(
modifier|*
name|presence_resp
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|src
parameter_list|,
name|u8
name|status
parameter_list|,
specifier|const
name|u8
modifier|*
name|noa
parameter_list|,
name|size_t
name|noa_len
parameter_list|)
function_decl|;
comment|/** 	 * is_concurrent_session_active - Check whether concurrent session is 	 * active on other virtual interfaces 	 * @ctx: Callback context from cb_ctx 	 * Returns: 1 if concurrent session is active on other virtual interface 	 * or 0 if not. 	 */
name|int
function_decl|(
modifier|*
name|is_concurrent_session_active
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/** 	 * is_p2p_in_progress - Check whether P2P operation is in progress 	 * @ctx: Callback context from cb_ctx 	 * Returns: 1 if P2P operation (e.g., group formation) is in progress 	 * or 0 if not. 	 */
name|int
function_decl|(
modifier|*
name|is_p2p_in_progress
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/** 	 * Determine if we have a persistent group we share with remote peer 	 * and allocate interface for this group if needed 	 * @ctx: Callback context from cb_ctx 	 * @addr: Peer device address to search for 	 * @ssid: Persistent group SSID or %NULL if any 	 * @ssid_len: Length of @ssid 	 * @go_dev_addr: Buffer for returning GO P2P Device Address 	 * @ret_ssid: Buffer for returning group SSID 	 * @ret_ssid_len: Buffer for returning length of @ssid 	 * @intended_iface_addr: Buffer for returning intended iface address 	 * Returns: 1 if a matching persistent group was found, 0 otherwise 	 */
name|int
function_decl|(
modifier|*
name|get_persistent_group
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|ssid
parameter_list|,
name|size_t
name|ssid_len
parameter_list|,
name|u8
modifier|*
name|go_dev_addr
parameter_list|,
name|u8
modifier|*
name|ret_ssid
parameter_list|,
name|size_t
modifier|*
name|ret_ssid_len
parameter_list|,
name|u8
modifier|*
name|intended_iface_addr
parameter_list|)
function_decl|;
comment|/** 	 * Get information about a possible local GO role 	 * @ctx: Callback context from cb_ctx 	 * @intended_addr: Buffer for returning intended GO interface address 	 * @ssid: Buffer for returning group SSID 	 * @ssid_len: Buffer for returning length of @ssid 	 * @group_iface: Buffer for returning whether a separate group interface 	 *	would be used 	 * Returns: 1 if GO info found, 0 otherwise 	 * 	 * This is used to compose New Group settings (SSID, and intended 	 * address) during P2PS provisioning if results of provisioning *might* 	 * result in our being an autonomous GO. 	 */
name|int
function_decl|(
modifier|*
name|get_go_info
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|u8
modifier|*
name|intended_addr
parameter_list|,
name|u8
modifier|*
name|ssid
parameter_list|,
name|size_t
modifier|*
name|ssid_len
parameter_list|,
name|int
modifier|*
name|group_iface
parameter_list|)
function_decl|;
comment|/** 	 * remove_stale_groups - Remove stale P2PS groups 	 * 	 * Because P2PS stages *potential* GOs, and remote devices can remove 	 * credentials unilaterally, we need to make sure we don't let stale 	 * unusable groups build up. 	 */
name|int
function_decl|(
modifier|*
name|remove_stale_groups
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer
parameter_list|,
specifier|const
name|u8
modifier|*
name|go
parameter_list|,
specifier|const
name|u8
modifier|*
name|ssid
parameter_list|,
name|size_t
name|ssid_len
parameter_list|)
function_decl|;
comment|/** 	 * p2ps_prov_complete - P2PS provisioning complete 	 * 	 * When P2PS provisioning completes (successfully or not) we must 	 * transmit all of the results to the upper layers. 	 */
name|void
function_decl|(
modifier|*
name|p2ps_prov_complete
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|u8
name|status
parameter_list|,
specifier|const
name|u8
modifier|*
name|dev
parameter_list|,
specifier|const
name|u8
modifier|*
name|adv_mac
parameter_list|,
specifier|const
name|u8
modifier|*
name|ses_mac
parameter_list|,
specifier|const
name|u8
modifier|*
name|grp_mac
parameter_list|,
name|u32
name|adv_id
parameter_list|,
name|u32
name|ses_id
parameter_list|,
name|u8
name|conncap
parameter_list|,
name|int
name|passwd_id
parameter_list|,
specifier|const
name|u8
modifier|*
name|persist_ssid
parameter_list|,
name|size_t
name|persist_ssid_size
parameter_list|,
name|int
name|response_done
parameter_list|,
name|int
name|prov_start
parameter_list|,
specifier|const
name|char
modifier|*
name|session_info
parameter_list|,
specifier|const
name|u8
modifier|*
name|feat_cap
parameter_list|,
name|size_t
name|feat_cap_len
parameter_list|)
function_decl|;
comment|/** 	 * prov_disc_resp_cb - Callback for indicating completion of PD Response 	 * @ctx: Callback context from cb_ctx 	 * Returns: 1 if operation was started, 0 otherwise 	 * 	 * This callback can be used to perform any pending actions after 	 * provisioning. It is mainly used for P2PS pending group creation. 	 */
name|int
function_decl|(
modifier|*
name|prov_disc_resp_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/** 	 * p2ps_group_capability - Determine group capability 	 * 	 * This function can be used to determine group capability based on 	 * information from P2PS PD exchange and the current state of ongoing 	 * groups and driver capabilities. 	 * 	 * P2PS_SETUP_* bitmap is used as the parameters and return value. 	 */
name|u8
function_decl|(
modifier|*
name|p2ps_group_capability
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|u8
name|incoming
parameter_list|,
name|u8
name|role
parameter_list|)
function_decl|;
comment|/** 	 * get_pref_freq_list - Get preferred frequency list for an interface 	 * @ctx: Callback context from cb_ctx 	 * @go: Whether the use if for GO role 	 * @len: Length of freq_list in entries (both IN and OUT) 	 * @freq_list: Buffer for returning the preferred frequencies (MHz) 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function can be used to query the preferred frequency list from 	 * the driver specific to a particular interface type. 	 */
name|int
function_decl|(
modifier|*
name|get_pref_freq_list
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|int
name|go
parameter_list|,
name|unsigned
name|int
modifier|*
name|len
parameter_list|,
name|unsigned
name|int
modifier|*
name|freq_list
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* P2P module initialization/deinitialization */
end_comment

begin_comment
comment|/**  * p2p_init - Initialize P2P module  * @cfg: P2P module configuration  * Returns: Pointer to private data or %NULL on failure  *  * This function is used to initialize global P2P module context (one per  * device). The P2P module will keep a copy of the configuration data, so the  * caller does not need to maintain this structure. However, the callback  * functions and the context parameters to them must be kept available until  * the P2P module is deinitialized with p2p_deinit().  */
end_comment

begin_function_decl
name|struct
name|p2p_data
modifier|*
name|p2p_init
parameter_list|(
specifier|const
name|struct
name|p2p_config
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_deinit - Deinitialize P2P module  * @p2p: P2P module context from p2p_init()  */
end_comment

begin_function_decl
name|void
name|p2p_deinit
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_flush - Flush P2P module state  * @p2p: P2P module context from p2p_init()  *  * This command removes the P2P module state like peer device entries.  */
end_comment

begin_function_decl
name|void
name|p2p_flush
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_unauthorize - Unauthorize the specified peer device  * @p2p: P2P module context from p2p_init()  * @addr: P2P peer entry to be unauthorized  * Returns: 0 on success, -1 on failure  *  * This command removes any connection authorization from the specified P2P  * peer device address. This can be used, e.g., to cancel effect of a previous  * p2p_authorize() or p2p_connect() call that has not yet resulted in completed  * GO Negotiation.  */
end_comment

begin_function_decl
name|int
name|p2p_unauthorize
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_dev_name - Set device name  * @p2p: P2P module context from p2p_init()  * Returns: 0 on success, -1 on failure  *  * This function can be used to update the P2P module configuration with  * information that was not available at the time of the p2p_init() call.  */
end_comment

begin_function_decl
name|int
name|p2p_set_dev_name
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|char
modifier|*
name|dev_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_manufacturer
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|char
modifier|*
name|manufacturer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_model_name
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|char
modifier|*
name|model_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_model_number
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|char
modifier|*
name|model_number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_serial_number
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|char
modifier|*
name|serial_number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p2p_set_config_methods
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|u16
name|config_methods
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p2p_set_uuid
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_pri_dev_type - Set primary device type  * @p2p: P2P module context from p2p_init()  * Returns: 0 on success, -1 on failure  *  * This function can be used to update the P2P module configuration with  * information that was not available at the time of the p2p_init() call.  */
end_comment

begin_function_decl
name|int
name|p2p_set_pri_dev_type
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|pri_dev_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_sec_dev_types - Set secondary device types  * @p2p: P2P module context from p2p_init()  * Returns: 0 on success, -1 on failure  *  * This function can be used to update the P2P module configuration with  * information that was not available at the time of the p2p_init() call.  */
end_comment

begin_function_decl
name|int
name|p2p_set_sec_dev_types
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
name|dev_types
index|[]
index|[
literal|8
index|]
parameter_list|,
name|size_t
name|num_dev_types
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_country
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|char
modifier|*
name|country
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Commands from upper layer management entity */
end_comment

begin_enum
enum|enum
name|p2p_discovery_type
block|{
name|P2P_FIND_START_WITH_FULL
block|,
name|P2P_FIND_ONLY_SOCIAL
block|,
name|P2P_FIND_PROGRESSIVE
block|}
enum|;
end_enum

begin_comment
comment|/**  * p2p_find - Start P2P Find (Device Discovery)  * @p2p: P2P module context from p2p_init()  * @timeout: Timeout for find operation in seconds or 0 for no timeout  * @type: Device Discovery type  * @num_req_dev_types: Number of requested device types  * @req_dev_types: Requested device types array, must be an array  *	containing num_req_dev_types * WPS_DEV_TYPE_LEN bytes; %NULL if no  *	requested device types.  * @dev_id: Device ID to search for or %NULL to find all devices  * @search_delay: Extra delay in milliseconds between search iterations  * @seek_count: Number of ASP Service Strings in the seek_string array  * @seek_string: ASP Service Strings to query for in Probe Requests  * @freq: Requested first scan frequency (in MHz) to modify type ==  *	P2P_FIND_START_WITH_FULL behavior. 0 = Use normal full scan.  *	If p2p_find is already in progress, this parameter is ignored and full  *	scan will be executed.  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|p2p_find
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|unsigned
name|int
name|timeout
parameter_list|,
name|enum
name|p2p_discovery_type
name|type
parameter_list|,
name|unsigned
name|int
name|num_req_dev_types
parameter_list|,
specifier|const
name|u8
modifier|*
name|req_dev_types
parameter_list|,
specifier|const
name|u8
modifier|*
name|dev_id
parameter_list|,
name|unsigned
name|int
name|search_delay
parameter_list|,
name|u8
name|seek_count
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|seek_string
parameter_list|,
name|int
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_notify_scan_trigger_status - Indicate scan trigger status  * @p2p: P2P module context from p2p_init()  * @status: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|void
name|p2p_notify_scan_trigger_status
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_stop_find - Stop P2P Find (Device Discovery)  * @p2p: P2P module context from p2p_init()  */
end_comment

begin_function_decl
name|void
name|p2p_stop_find
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_stop_find_for_freq - Stop P2P Find for next oper on specific freq  * @p2p: P2P module context from p2p_init()  * @freq: Frequency in MHz for next operation  *  * This is like p2p_stop_find(), but Listen state is not stopped if we are  * already on the same frequency.  */
end_comment

begin_function_decl
name|void
name|p2p_stop_find_for_freq
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_listen - Start P2P Listen state for specified duration  * @p2p: P2P module context from p2p_init()  * @timeout: Listen state duration in milliseconds  * Returns: 0 on success, -1 on failure  *  * This function can be used to request the P2P module to keep the device  * discoverable on the listen channel for an extended set of time. At least in  * its current form, this is mainly used for testing purposes and may not be of  * much use for normal P2P operations.  */
end_comment

begin_function_decl
name|int
name|p2p_listen
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|unsigned
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_stop_listen - Stop P2P Listen  * @p2p: P2P module context from p2p_init()  */
end_comment

begin_function_decl
name|void
name|p2p_stop_listen
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_connect - Start P2P group formation (GO negotiation)  * @p2p: P2P module context from p2p_init()  * @peer_addr: MAC address of the peer P2P client  * @wps_method: WPS method to be used in provisioning  * @go_intent: Local GO intent value (1..15)  * @own_interface_addr: Intended interface address to use with the group  * @force_freq: The only allowed channel frequency in MHz or 0  * @persistent_group: Whether to create a persistent group (0 = no, 1 =  * persistent group without persistent reconnect, 2 = persistent group with  * persistent reconnect)  * @force_ssid: Forced SSID for the group if we become GO or %NULL to generate  *	a new SSID  * @force_ssid_len: Length of $force_ssid buffer  * @pd_before_go_neg: Whether to send Provision Discovery prior to GO  *	Negotiation as an interoperability workaround when initiating group  *	formation  * @pref_freq: Preferred operating frequency in MHz or 0 (this is only used if  *	force_freq == 0)  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|p2p_connect
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer_addr
parameter_list|,
name|enum
name|p2p_wps_method
name|wps_method
parameter_list|,
name|int
name|go_intent
parameter_list|,
specifier|const
name|u8
modifier|*
name|own_interface_addr
parameter_list|,
name|unsigned
name|int
name|force_freq
parameter_list|,
name|int
name|persistent_group
parameter_list|,
specifier|const
name|u8
modifier|*
name|force_ssid
parameter_list|,
name|size_t
name|force_ssid_len
parameter_list|,
name|int
name|pd_before_go_neg
parameter_list|,
name|unsigned
name|int
name|pref_freq
parameter_list|,
name|u16
name|oob_pw_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_authorize - Authorize P2P group formation (GO negotiation)  * @p2p: P2P module context from p2p_init()  * @peer_addr: MAC address of the peer P2P client  * @wps_method: WPS method to be used in provisioning  * @go_intent: Local GO intent value (1..15)  * @own_interface_addr: Intended interface address to use with the group  * @force_freq: The only allowed channel frequency in MHz or 0  * @persistent_group: Whether to create a persistent group (0 = no, 1 =  * persistent group without persistent reconnect, 2 = persistent group with  * persistent reconnect)  * @force_ssid: Forced SSID for the group if we become GO or %NULL to generate  *	a new SSID  * @force_ssid_len: Length of $force_ssid buffer  * @pref_freq: Preferred operating frequency in MHz or 0 (this is only used if  *	force_freq == 0)  * Returns: 0 on success, -1 on failure  *  * This is like p2p_connect(), but the actual group negotiation is not  * initiated automatically, i.e., the other end is expected to do that.  */
end_comment

begin_function_decl
name|int
name|p2p_authorize
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer_addr
parameter_list|,
name|enum
name|p2p_wps_method
name|wps_method
parameter_list|,
name|int
name|go_intent
parameter_list|,
specifier|const
name|u8
modifier|*
name|own_interface_addr
parameter_list|,
name|unsigned
name|int
name|force_freq
parameter_list|,
name|int
name|persistent_group
parameter_list|,
specifier|const
name|u8
modifier|*
name|force_ssid
parameter_list|,
name|size_t
name|force_ssid_len
parameter_list|,
name|unsigned
name|int
name|pref_freq
parameter_list|,
name|u16
name|oob_pw_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_reject - Reject peer device (explicitly block connection attempts)  * @p2p: P2P module context from p2p_init()  * @peer_addr: MAC address of the peer P2P client  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|p2p_reject
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_prov_disc_req - Send Provision Discovery Request  * @p2p: P2P module context from p2p_init()  * @peer_addr: MAC address of the peer P2P client  * @p2ps_prov: Provisioning info for P2PS  * @config_methods: WPS Config Methods value (only one bit set)  * @join: Whether this is used by a client joining an active group  * @force_freq: Forced TX frequency for the frame (mainly for the join case)  * @user_initiated_pd: Flag to indicate if initiated by user or not  * Returns: 0 on success, -1 on failure  *  * This function can be used to request a discovered P2P peer to display a PIN  * (config_methods = WPS_CONFIG_DISPLAY) or be prepared to enter a PIN from us  * (config_methods = WPS_CONFIG_KEYPAD). The Provision Discovery Request frame  * is transmitted once immediately and if no response is received, the frame  * will be sent again whenever the target device is discovered during device  * dsicovery (start with a p2p_find() call). Response from the peer is  * indicated with the p2p_config::prov_disc_resp() callback.  */
end_comment

begin_function_decl
name|int
name|p2p_prov_disc_req
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer_addr
parameter_list|,
name|struct
name|p2ps_provision
modifier|*
name|p2ps_prov
parameter_list|,
name|u16
name|config_methods
parameter_list|,
name|int
name|join
parameter_list|,
name|int
name|force_freq
parameter_list|,
name|int
name|user_initiated_pd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_sd_request - Schedule a service discovery query  * @p2p: P2P module context from p2p_init()  * @dst: Destination peer or %NULL to apply for all peers  * @tlvs: P2P Service Query TLV(s)  * Returns: Reference to the query or %NULL on failure  *  * Response to the query is indicated with the p2p_config::sd_response()  * callback.  */
end_comment

begin_function_decl
name|void
modifier|*
name|p2p_sd_request
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|tlvs
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_WIFI_DISPLAY
end_ifdef

begin_function_decl
name|void
modifier|*
name|p2p_sd_request_wfd
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|tlvs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_WIFI_DISPLAY */
end_comment

begin_comment
comment|/**  * p2p_sd_cancel_request - Cancel a pending service discovery query  * @p2p: P2P module context from p2p_init()  * @req: Query reference from p2p_sd_request()  * Returns: 0 if request for cancelled; -1 if not found  */
end_comment

begin_function_decl
name|int
name|p2p_sd_cancel_request
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|void
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_sd_response - Send response to a service discovery query  * @p2p: P2P module context from p2p_init()  * @freq: Frequency from p2p_config::sd_request() callback  * @dst: Destination address from p2p_config::sd_request() callback  * @dialog_token: Dialog token from p2p_config::sd_request() callback  * @resp_tlvs: P2P Service Response TLV(s)  *  * This function is called as a response to the request indicated with  * p2p_config::sd_request() callback.  */
end_comment

begin_function_decl
name|void
name|p2p_sd_response
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
name|freq
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
name|u8
name|dialog_token
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|resp_tlvs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_sd_service_update - Indicate a change in local services  * @p2p: P2P module context from p2p_init()  *  * This function needs to be called whenever there is a change in availability  * of the local services. This will increment the Service Update Indicator  * value which will be used in SD Request and Response frames.  */
end_comment

begin_function_decl
name|void
name|p2p_sd_service_update
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|p2p_invite_role
block|{
name|P2P_INVITE_ROLE_GO
block|,
name|P2P_INVITE_ROLE_ACTIVE_GO
block|,
name|P2P_INVITE_ROLE_CLIENT
block|}
enum|;
end_enum

begin_comment
comment|/**  * p2p_invite - Invite a P2P Device into a group  * @p2p: P2P module context from p2p_init()  * @peer: Device Address of the peer P2P Device  * @role: Local role in the group  * @bssid: Group BSSID or %NULL if not known  * @ssid: Group SSID  * @ssid_len: Length of ssid in octets  * @force_freq: The only allowed channel frequency in MHz or 0  * @go_dev_addr: Forced GO Device Address or %NULL if none  * @persistent_group: Whether this is to reinvoke a persistent group  * @pref_freq: Preferred operating frequency in MHz or 0 (this is only used if  *	force_freq == 0)  * @dev_pw_id: Device Password ID from OOB Device Password (NFC) static handover  *	case or -1 if not used  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|p2p_invite
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer
parameter_list|,
name|enum
name|p2p_invite_role
name|role
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
specifier|const
name|u8
modifier|*
name|ssid
parameter_list|,
name|size_t
name|ssid_len
parameter_list|,
name|unsigned
name|int
name|force_freq
parameter_list|,
specifier|const
name|u8
modifier|*
name|go_dev_addr
parameter_list|,
name|int
name|persistent_group
parameter_list|,
name|unsigned
name|int
name|pref_freq
parameter_list|,
name|int
name|dev_pw_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_presence_req - Request GO presence  * @p2p: P2P module context from p2p_init()  * @go_interface_addr: GO P2P Interface Address  * @own_interface_addr: Own P2P Interface Address for this group  * @freq: Group operating frequence (in MHz)  * @duration1: Preferred presence duration in microseconds  * @interval1: Preferred presence interval in microseconds  * @duration2: Acceptable presence duration in microseconds  * @interval2: Acceptable presence interval in microseconds  * Returns: 0 on success, -1 on failure  *  * If both duration and interval values are zero, the parameter pair is not  * specified (i.e., to remove Presence Request, use duration1 = interval1 = 0).  */
end_comment

begin_function_decl
name|int
name|p2p_presence_req
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|go_interface_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|own_interface_addr
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|,
name|u32
name|duration1
parameter_list|,
name|u32
name|interval1
parameter_list|,
name|u32
name|duration2
parameter_list|,
name|u32
name|interval2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_ext_listen - Set Extended Listen Timing  * @p2p: P2P module context from p2p_init()  * @freq: Group operating frequence (in MHz)  * @period: Availability period in milliseconds (1-65535; 0 to disable)  * @interval: Availability interval in milliseconds (1-65535; 0 to disable)  * Returns: 0 on success, -1 on failure  *  * This function can be used to enable or disable (period = interval = 0)  * Extended Listen Timing. When enabled, the P2P Device will become  * discoverable (go into Listen State) every @interval milliseconds for at  * least @period milliseconds.  */
end_comment

begin_function_decl
name|int
name|p2p_ext_listen
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|unsigned
name|int
name|period
parameter_list|,
name|unsigned
name|int
name|interval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Event notifications from upper layer management operations */
end_comment

begin_comment
comment|/**  * p2p_wps_success_cb - Report successfully completed WPS provisioning  * @p2p: P2P module context from p2p_init()  * @mac_addr: Peer address  *  * This function is used to report successfully completed WPS provisioning  * during group formation in both GO/Registrar and client/Enrollee roles.  */
end_comment

begin_function_decl
name|void
name|p2p_wps_success_cb
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|mac_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_formation_failed - Report failed WPS provisioning  * @p2p: P2P module context from p2p_init()  *  * This function is used to report failed group formation. This can happen  * either due to failed WPS provisioning or due to 15 second timeout during  * the provisioning phase.  */
end_comment

begin_function_decl
name|void
name|p2p_group_formation_failed
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_get_provisioning_info - Get any stored provisioning info  * @p2p: P2P module context from p2p_init()  * @addr: Peer P2P Device Address  * Returns: WPS provisioning information (WPS config method) or 0 if no  * information is available  *  * This function is used to retrieve stored WPS provisioning info for the given  * peer.  */
end_comment

begin_function_decl
name|u16
name|p2p_get_provisioning_info
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_clear_provisioning_info - Clear any stored provisioning info  * @p2p: P2P module context from p2p_init()  * @iface_addr: Peer P2P Device Address  *  * This function is used to clear stored WPS provisioning info for the given  * peer.  */
end_comment

begin_function_decl
name|void
name|p2p_clear_provisioning_info
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Event notifications from lower layer driver operations */
end_comment

begin_comment
comment|/**  * enum p2p_probe_req_status  *  * @P2P_PREQ_MALFORMED: frame was not well-formed  * @P2P_PREQ_NOT_LISTEN: device isn't in listen state, frame ignored  * @P2P_PREQ_NOT_P2P: frame was not a P2P probe request  * @P2P_PREQ_P2P_NOT_PROCESSED: frame was P2P but wasn't processed  * @P2P_PREQ_P2P_PROCESSED: frame has been processed by P2P  */
end_comment

begin_enum
enum|enum
name|p2p_probe_req_status
block|{
name|P2P_PREQ_MALFORMED
block|,
name|P2P_PREQ_NOT_LISTEN
block|,
name|P2P_PREQ_NOT_P2P
block|,
name|P2P_PREQ_NOT_PROCESSED
block|,
name|P2P_PREQ_PROCESSED
block|}
enum|;
end_enum

begin_comment
comment|/**  * p2p_probe_req_rx - Report reception of a Probe Request frame  * @p2p: P2P module context from p2p_init()  * @addr: Source MAC address  * @dst: Destination MAC address if available or %NULL  * @bssid: BSSID if available or %NULL  * @ie: Information elements from the Probe Request frame body  * @ie_len: Length of ie buffer in octets  * @rx_freq: Probe Request frame RX frequency  * Returns: value indicating the type and status of the probe request  */
end_comment

begin_function_decl
name|enum
name|p2p_probe_req_status
name|p2p_probe_req_rx
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
specifier|const
name|u8
modifier|*
name|ie
parameter_list|,
name|size_t
name|ie_len
parameter_list|,
name|unsigned
name|int
name|rx_freq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_rx_action - Report received Action frame  * @p2p: P2P module context from p2p_init()  * @da: Destination address of the received Action frame  * @sa: Source address of the received Action frame  * @bssid: Address 3 of the received Action frame  * @category: Category of the received Action frame  * @data: Action frame body after the Category field  * @len: Length of the data buffer in octets  * @freq: Frequency (in MHz) on which the frame was received  */
end_comment

begin_function_decl
name|void
name|p2p_rx_action
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|da
parameter_list|,
specifier|const
name|u8
modifier|*
name|sa
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
name|u8
name|category
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_scan_res_handler - Indicate a P2P scan results  * @p2p: P2P module context from p2p_init()  * @bssid: BSSID of the scan result  * @freq: Frequency of the channel on which the device was found in MHz  * @rx_time: Time when the result was received  * @level: Signal level (signal strength of the received Beacon/Probe Response  *	frame)  * @ies: Pointer to IEs from the scan result  * @ies_len: Length of the ies buffer  * Returns: 0 to continue or 1 to stop scan result indication  *  * This function is called to indicate a scan result entry with P2P IE from a  * scan requested with struct p2p_config::p2p_scan(). This can be called during  * the actual scan process (i.e., whenever a new device is found) or as a  * sequence of calls after the full scan has been completed. The former option  * can result in optimized operations, but may not be supported by all  * driver/firmware designs. The ies buffer need to include at least the P2P IE,  * but it is recommended to include all IEs received from the device. The  * caller does not need to check that the IEs contain a P2P IE before calling  * this function since frames will be filtered internally if needed.  *  * This function will return 1 if it wants to stop scan result iteration (and  * scan in general if it is still in progress). This is used to allow faster  * start of a pending operation, e.g., to start a pending GO negotiation.  */
end_comment

begin_function_decl
name|int
name|p2p_scan_res_handler
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
name|int
name|freq
parameter_list|,
name|struct
name|os_reltime
modifier|*
name|rx_time
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|u8
modifier|*
name|ies
parameter_list|,
name|size_t
name|ies_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_scan_res_handled - Indicate end of scan results  * @p2p: P2P module context from p2p_init()  *  * This function is called to indicate that all P2P scan results from a scan  * have been reported with zero or more calls to p2p_scan_res_handler(). This  * function must be called as a response to successful  * struct p2p_config::p2p_scan() call if none of the p2p_scan_res_handler()  * calls stopped iteration.  */
end_comment

begin_function_decl
name|void
name|p2p_scan_res_handled
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|p2p_send_action_result
block|{
name|P2P_SEND_ACTION_SUCCESS
comment|/* Frame was send and acknowledged */
block|,
name|P2P_SEND_ACTION_NO_ACK
comment|/* Frame was sent, but not acknowledged */
block|,
name|P2P_SEND_ACTION_FAILED
comment|/* Frame was not sent due to a failure */
block|}
enum|;
end_enum

begin_comment
comment|/**  * p2p_send_action_cb - Notify TX status of an Action frame  * @p2p: P2P module context from p2p_init()  * @freq: Channel frequency in MHz  * @dst: Destination MAC address (Address 1)  * @src: Source MAC address (Address 2)  * @bssid: BSSID (Address 3)  * @result: Result of the transmission attempt  *  * This function is used to indicate the result of an Action frame transmission  * that was requested with struct p2p_config::send_action() callback.  */
end_comment

begin_function_decl
name|void
name|p2p_send_action_cb
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
specifier|const
name|u8
modifier|*
name|src
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
name|enum
name|p2p_send_action_result
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_listen_cb - Indicate the start of a requested Listen state  * @p2p: P2P module context from p2p_init()  * @freq: Listen channel frequency in MHz  * @duration: Duration for the Listen state in milliseconds  *  * This function is used to indicate that a Listen state requested with  * struct p2p_config::start_listen() callback has started.  */
end_comment

begin_function_decl
name|void
name|p2p_listen_cb
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|,
name|unsigned
name|int
name|duration
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_listen_end - Indicate the end of a requested Listen state  * @p2p: P2P module context from p2p_init()  * @freq: Listen channel frequency in MHz  * Returns: 0 if no operations were started, 1 if an operation was started  *  * This function is used to indicate that a Listen state requested with  * struct p2p_config::start_listen() callback has ended.  */
end_comment

begin_function_decl
name|int
name|p2p_listen_end
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p2p_deauth_notif
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
name|u16
name|reason_code
parameter_list|,
specifier|const
name|u8
modifier|*
name|ie
parameter_list|,
name|size_t
name|ie_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p2p_disassoc_notif
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
name|u16
name|reason_code
parameter_list|,
specifier|const
name|u8
modifier|*
name|ie
parameter_list|,
name|size_t
name|ie_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Per-group P2P state for GO */
end_comment

begin_struct_decl
struct_decl|struct
name|p2p_group
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * struct p2p_group_config - P2P group configuration  *  * This configuration is provided to the P2P module during initialization of  * the per-group information with p2p_group_init().  */
end_comment

begin_struct
struct|struct
name|p2p_group_config
block|{
comment|/** 	 * persistent_group - Whether the group is persistent 	 * 0 = not a persistent group 	 * 1 = persistent group without persistent reconnect 	 * 2 = persistent group with persistent reconnect 	 */
name|int
name|persistent_group
decl_stmt|;
comment|/** 	 * interface_addr - P2P Interface Address of the group 	 */
name|u8
name|interface_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** 	 * max_clients - Maximum number of clients in the group 	 */
name|unsigned
name|int
name|max_clients
decl_stmt|;
comment|/** 	 * ssid - Group SSID 	 */
name|u8
name|ssid
index|[
name|SSID_MAX_LEN
index|]
decl_stmt|;
comment|/** 	 * ssid_len - Length of SSID 	 */
name|size_t
name|ssid_len
decl_stmt|;
comment|/** 	 * freq - Operating channel of the group 	 */
name|int
name|freq
decl_stmt|;
comment|/** 	 * cb_ctx - Context to use with callback functions 	 */
name|void
modifier|*
name|cb_ctx
decl_stmt|;
comment|/** 	 * ie_update - Notification of IE update 	 * @ctx: Callback context from cb_ctx 	 * @beacon_ies: P2P IE for Beacon frames or %NULL if no change 	 * @proberesp_ies: P2P Ie for Probe Response frames 	 * 	 * P2P module uses this callback function to notify whenever the P2P IE 	 * in Beacon or Probe Response frames should be updated based on group 	 * events. 	 * 	 * The callee is responsible for freeing the returned buffer(s) with 	 * wpabuf_free(). 	 */
name|void
function_decl|(
modifier|*
name|ie_update
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|beacon_ies
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|proberesp_ies
parameter_list|)
function_decl|;
comment|/** 	 * idle_update - Notification of changes in group idle state 	 * @ctx: Callback context from cb_ctx 	 * @idle: Whether the group is idle (no associated stations) 	 */
name|void
function_decl|(
modifier|*
name|idle_update
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|int
name|idle
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * p2p_group_init - Initialize P2P group  * @p2p: P2P module context from p2p_init()  * @config: P2P group configuration (will be freed by p2p_group_deinit())  * Returns: Pointer to private data or %NULL on failure  *  * This function is used to initialize per-group P2P module context. Currently,  * this is only used to manage GO functionality and P2P clients do not need to  * create an instance of this per-group information.  */
end_comment

begin_function_decl
name|struct
name|p2p_group
modifier|*
name|p2p_group_init
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|struct
name|p2p_group_config
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_deinit - Deinitialize P2P group  * @group: P2P group context from p2p_group_init()  */
end_comment

begin_function_decl
name|void
name|p2p_group_deinit
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_notif_assoc - Notification of P2P client association with GO  * @group: P2P group context from p2p_group_init()  * @addr: Interface address of the P2P client  * @ie: IEs from the (Re)association Request frame  * @len: Length of the ie buffer in octets  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|p2p_group_notif_assoc
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|ie
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_assoc_resp_ie - Build P2P IE for (re)association response  * @group: P2P group context from p2p_group_init()  * @status: Status value (P2P_SC_SUCCESS if association succeeded)  * Returns: P2P IE for (Re)association Response or %NULL on failure  *  * The caller is responsible for freeing the returned buffer with  * wpabuf_free().  */
end_comment

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|p2p_group_assoc_resp_ie
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|,
name|u8
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_notif_disassoc - Notification of P2P client disassociation from GO  * @group: P2P group context from p2p_group_init()  * @addr: Interface address of the P2P client  */
end_comment

begin_function_decl
name|void
name|p2p_group_notif_disassoc
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_notif_formation_done - Notification of completed group formation  * @group: P2P group context from p2p_group_init()  */
end_comment

begin_function_decl
name|void
name|p2p_group_notif_formation_done
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_notif_noa - Notification of NoA change  * @group: P2P group context from p2p_group_init()  * @noa: Notice of Absence attribute payload, %NULL if none  * @noa_len: Length of noa buffer in octets  * Returns: 0 on success, -1 on failure  *  * Notify the P2P group management about a new NoA contents. This will be  * inserted into the P2P IEs in Beacon and Probe Response frames with rest of  * the group information.  */
end_comment

begin_function_decl
name|int
name|p2p_group_notif_noa
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|,
specifier|const
name|u8
modifier|*
name|noa
parameter_list|,
name|size_t
name|noa_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_match_dev_type - Match device types in group with requested type  * @group: P2P group context from p2p_group_init()  * @wps: WPS TLVs from Probe Request frame (concatenated WPS IEs)  * Returns: 1 on match, 0 on mismatch  *  * This function can be used to match the Requested Device Type attribute in  * WPS IE with the device types of a group member for deciding whether a GO  * should reply to a Probe Request frame. Match will be reported if the WPS IE  * is not requested any specific device type.  */
end_comment

begin_function_decl
name|int
name|p2p_group_match_dev_type
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|wps
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_match_dev_id - Match P2P Device Address in group with requested device id  */
end_comment

begin_function_decl
name|int
name|p2p_group_match_dev_id
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_go_discover - Send GO Discoverability Request to a group client  * @group: P2P group context from p2p_group_init()  * Returns: 0 on success (frame scheduled); -1 if client was not found  */
end_comment

begin_function_decl
name|int
name|p2p_group_go_discover
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|,
specifier|const
name|u8
modifier|*
name|dev_id
parameter_list|,
specifier|const
name|u8
modifier|*
name|searching_dev
parameter_list|,
name|int
name|rx_freq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generic helper functions */
end_comment

begin_comment
comment|/**  * p2p_ie_text - Build text format description of P2P IE  * @p2p_ie: P2P IE  * @buf: Buffer for returning text  * @end: Pointer to the end of the buf area  * Returns: Number of octets written to the buffer or -1 on failure  *  * This function can be used to parse P2P IE contents into text format  * field=value lines.  */
end_comment

begin_function_decl
name|int
name|p2p_ie_text
parameter_list|(
name|struct
name|wpabuf
modifier|*
name|p2p_ie
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|char
modifier|*
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_scan_result_text - Build text format description of P2P IE  * @ies: Information elements from scan results  * @ies_len: ies buffer length in octets  * @buf: Buffer for returning text  * @end: Pointer to the end of the buf area  * Returns: Number of octets written to the buffer or -1 on failure  *  * This function can be used to parse P2P IE contents into text format  * field=value lines.  */
end_comment

begin_function_decl
name|int
name|p2p_scan_result_text
parameter_list|(
specifier|const
name|u8
modifier|*
name|ies
parameter_list|,
name|size_t
name|ies_len
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|char
modifier|*
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_parse_dev_addr_in_p2p_ie - Parse P2P Device Address from a concatenated  * P2P IE  * @p2p_ie: P2P IE  * @dev_addr: Buffer for returning P2P Device Address  * Returns: 0 on success or -1 if P2P Device Address could not be parsed  */
end_comment

begin_function_decl
name|int
name|p2p_parse_dev_addr_in_p2p_ie
parameter_list|(
name|struct
name|wpabuf
modifier|*
name|p2p_ie
parameter_list|,
name|u8
modifier|*
name|dev_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_parse_dev_addr - Parse P2P Device Address from P2P IE(s)  * @ies: Information elements from scan results  * @ies_len: ies buffer length in octets  * @dev_addr: Buffer for returning P2P Device Address  * Returns: 0 on success or -1 if P2P Device Address could not be parsed  */
end_comment

begin_function_decl
name|int
name|p2p_parse_dev_addr
parameter_list|(
specifier|const
name|u8
modifier|*
name|ies
parameter_list|,
name|size_t
name|ies_len
parameter_list|,
name|u8
modifier|*
name|dev_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_assoc_req_ie - Build P2P IE for (Re)Association Request frame  * @p2p: P2P module context from p2p_init()  * @bssid: BSSID  * @buf: Buffer for writing the P2P IE  * @len: Maximum buf length in octets  * @p2p_group: Whether this is for association with a P2P GO  * @p2p_ie: Reassembled P2P IE data from scan results or %NULL if none  * Returns: Number of octets written into buf or -1 on failure  */
end_comment

begin_function_decl
name|int
name|p2p_assoc_req_ie
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|p2p_group
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|p2p_ie
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_scan_ie - Build P2P IE for Probe Request  * @p2p: P2P module context from p2p_init()  * @ies: Buffer for writing P2P IE  * @dev_id: Device ID to search for or %NULL for any  */
end_comment

begin_function_decl
name|void
name|p2p_scan_ie
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|ies
parameter_list|,
specifier|const
name|u8
modifier|*
name|dev_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_scan_ie_buf_len - Get maximum buffer length needed for p2p_scan_ie  * @p2p: P2P module context from p2p_init()  * Returns: Number of octets that p2p_scan_ie() may add to the buffer  */
end_comment

begin_function_decl
name|size_t
name|p2p_scan_ie_buf_len
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_go_params - Generate random P2P group parameters  * @p2p: P2P module context from p2p_init()  * @params: Buffer for parameters  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|p2p_go_params
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|struct
name|p2p_go_neg_results
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_get_group_capab - Get Group Capability from P2P IE data  * @p2p_ie: P2P IE(s) contents  * Returns: Group Capability  */
end_comment

begin_function_decl
name|u8
name|p2p_get_group_capab
parameter_list|(
specifier|const
name|struct
name|wpabuf
modifier|*
name|p2p_ie
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_get_cross_connect_disallowed - Does WLAN AP disallows cross connection  * @p2p_ie: P2P IE(s) contents  * Returns: 0 if cross connection is allow, 1 if not  */
end_comment

begin_function_decl
name|int
name|p2p_get_cross_connect_disallowed
parameter_list|(
specifier|const
name|struct
name|wpabuf
modifier|*
name|p2p_ie
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_get_go_dev_addr - Get P2P Device Address from P2P IE data  * @p2p_ie: P2P IE(s) contents  * Returns: Pointer to P2P Device Address or %NULL if not included  */
end_comment

begin_function_decl
specifier|const
name|u8
modifier|*
name|p2p_get_go_dev_addr
parameter_list|(
specifier|const
name|struct
name|wpabuf
modifier|*
name|p2p_ie
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_get_peer_info - Get P2P peer information  * @p2p: P2P module context from p2p_init()  * @addr: P2P Device Address of the peer or %NULL to indicate the first peer  * @next: Whether to select the peer entry following the one indicated by addr  * Returns: Pointer to peer info or %NULL if not found  */
end_comment

begin_function_decl
specifier|const
name|struct
name|p2p_peer_info
modifier|*
name|p2p_get_peer_info
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|next
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_get_peer_info_txt - Get internal P2P peer information in text format  * @info: Pointer to P2P peer info from p2p_get_peer_info()  * @buf: Buffer for returning text  * @buflen: Maximum buffer length  * Returns: Number of octets written to the buffer or -1 on failure  *  * Note: This information is internal to the P2P module and subject to change.  * As such, this should not really be used by external programs for purposes  * other than debugging.  */
end_comment

begin_function_decl
name|int
name|p2p_get_peer_info_txt
parameter_list|(
specifier|const
name|struct
name|p2p_peer_info
modifier|*
name|info
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

begin_comment
comment|/**  * p2p_peer_known - Check whether P2P peer is known  * @p2p: P2P module context from p2p_init()  * @addr: P2P Device Address of the peer  * Returns: 1 if the specified device is in the P2P peer table or 0 if not  */
end_comment

begin_function_decl
name|int
name|p2p_peer_known
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_client_discoverability - Set client discoverability capability  * @p2p: P2P module context from p2p_init()  * @enabled: Whether client discoverability will be enabled  *  * This function can be used to disable (and re-enable) client discoverability.  * This capability is enabled by default and should not be disabled in normal  * use cases, i.e., this is mainly for testing purposes.  */
end_comment

begin_function_decl
name|void
name|p2p_set_client_discoverability
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
name|enabled
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_managed_oper - Set managed P2P Device operations capability  * @p2p: P2P module context from p2p_init()  * @enabled: Whether managed P2P Device operations will be enabled  */
end_comment

begin_function_decl
name|void
name|p2p_set_managed_oper
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
name|enabled
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_config_get_random_social - Return a random social channel  * @p2p: P2P config  * @op_class: Selected operating class  * @op_channel: Selected social channel  * Returns: 0 on success, -1 on failure  *  * This function is used before p2p_init is called. A random social channel  * from supports bands 2.4 GHz (channels 1,6,11) and 60 GHz (channel 2) is  * returned on success.  */
end_comment

begin_function_decl
name|int
name|p2p_config_get_random_social
parameter_list|(
name|struct
name|p2p_config
modifier|*
name|p2p
parameter_list|,
name|u8
modifier|*
name|op_class
parameter_list|,
name|u8
modifier|*
name|op_channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_listen_channel
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|u8
name|reg_class
parameter_list|,
name|u8
name|channel
parameter_list|,
name|u8
name|forced
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
name|p2p_get_listen_channel
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_ssid_postfix
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|postfix
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_get_interface_addr
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|dev_addr
parameter_list|,
name|u8
modifier|*
name|iface_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_get_dev_addr
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|iface_addr
parameter_list|,
name|u8
modifier|*
name|dev_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p2p_set_peer_filter
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_cross_connect - Set cross connection capability  * @p2p: P2P module context from p2p_init()  * @enabled: Whether cross connection will be enabled  */
end_comment

begin_function_decl
name|void
name|p2p_set_cross_connect
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
name|enabled
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_get_oper_freq
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|iface_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_intra_bss_dist - Set intra BSS distribution  * @p2p: P2P module context from p2p_init()  * @enabled: Whether intra BSS distribution will be enabled  */
end_comment

begin_function_decl
name|void
name|p2p_set_intra_bss_dist
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
name|enabled
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_channels_includes_freq
parameter_list|(
specifier|const
name|struct
name|p2p_channels
modifier|*
name|channels
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_channels_to_freqs
parameter_list|(
specifier|const
name|struct
name|p2p_channels
modifier|*
name|channels
parameter_list|,
name|int
modifier|*
name|freq_list
parameter_list|,
name|unsigned
name|int
name|max_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_supported_freq - Check whether channel is supported for P2P  * @p2p: P2P module context from p2p_init()  * @freq: Channel frequency in MHz  * Returns: 0 if channel not usable for P2P, 1 if usable for P2P  */
end_comment

begin_function_decl
name|int
name|p2p_supported_freq
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_supported_freq_go - Check whether channel is supported for P2P GO operation  * @p2p: P2P module context from p2p_init()  * @freq: Channel frequency in MHz  * Returns: 0 if channel not usable for P2P, 1 if usable for P2P  */
end_comment

begin_function_decl
name|int
name|p2p_supported_freq_go
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_supported_freq_cli - Check whether channel is supported for P2P client operation  * @p2p: P2P module context from p2p_init()  * @freq: Channel frequency in MHz  * Returns: 0 if channel not usable for P2P, 1 if usable for P2P  */
end_comment

begin_function_decl
name|int
name|p2p_supported_freq_cli
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_get_pref_freq - Get channel from preferred channel list  * @p2p: P2P module context from p2p_init()  * @channels: List of channels  * Returns: Preferred channel  */
end_comment

begin_function_decl
name|unsigned
name|int
name|p2p_get_pref_freq
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|struct
name|p2p_channels
modifier|*
name|channels
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p2p_update_channel_list
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|struct
name|p2p_channels
modifier|*
name|chan
parameter_list|,
specifier|const
name|struct
name|p2p_channels
modifier|*
name|cli_chan
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_best_channels - Update best channel information  * @p2p: P2P module context from p2p_init()  * @freq_24: Frequency (MHz) of best channel in 2.4 GHz band  * @freq_5: Frequency (MHz) of best channel in 5 GHz band  * @freq_overall: Frequency (MHz) of best channel overall  */
end_comment

begin_function_decl
name|void
name|p2p_set_best_channels
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
name|freq_24
parameter_list|,
name|int
name|freq_5
parameter_list|,
name|int
name|freq_overall
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_own_freq_preference - Set own preference for channel  * @p2p: P2P module context from p2p_init()  * @freq: Frequency (MHz) of the preferred channel or 0 if no preference  *  * This function can be used to set a preference on the operating channel based  * on frequencies used on the other virtual interfaces that share the same  * radio. If non-zero, this is used to try to avoid multi-channel concurrency.  */
end_comment

begin_function_decl
name|void
name|p2p_set_own_freq_preference
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|u8
modifier|*
name|p2p_get_go_neg_peer
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_get_group_num_members - Get number of members in group  * @group: P2P group context from p2p_group_init()  * Returns: Number of members in the group  */
end_comment

begin_function_decl
name|unsigned
name|int
name|p2p_get_group_num_members
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_client_limit_reached - Check if client limit is reached  * @group: P2P group context from p2p_group_init()  * Returns: 1 if no of clients limit reached  */
end_comment

begin_function_decl
name|int
name|p2p_client_limit_reached
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_iterate_group_members - Iterate group members  * @group: P2P group context from p2p_group_init()  * @next: iteration pointer, must be a pointer to a void * that is set to %NULL  *	on the first call and not modified later  * Returns: A P2P Device Address for each call and %NULL for no more members  */
end_comment

begin_function_decl
specifier|const
name|u8
modifier|*
name|p2p_iterate_group_members
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|,
name|void
modifier|*
modifier|*
name|next
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_get_dev_addr - Get a P2P Device Address of a client in a group  * @group: P2P group context from p2p_group_init()  * @addr: P2P Interface Address of the client  * Returns: P2P Device Address of the client if found or %NULL if no match  * found  */
end_comment

begin_function_decl
specifier|const
name|u8
modifier|*
name|p2p_group_get_dev_addr
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_is_client_connected - Check whether a specific client is connected  * @group: P2P group context from p2p_group_init()  * @addr: P2P Device Address of the client  * Returns: 1 if client is connected or 0 if not  */
end_comment

begin_function_decl
name|int
name|p2p_group_is_client_connected
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|,
specifier|const
name|u8
modifier|*
name|dev_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_get_config - Get the group configuration  * @group: P2P group context from p2p_group_init()  * Returns: The group configuration pointer  */
end_comment

begin_function_decl
specifier|const
name|struct
name|p2p_group_config
modifier|*
name|p2p_group_get_config
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_loop_on_all_groups - Run the given callback on all groups  * @p2p: P2P module context from p2p_init()  * @group_callback: The callback function pointer  * @user_data: Some user data pointer which can be %NULL  *  * The group_callback function can stop the iteration by returning 0.  */
end_comment

begin_function_decl
name|void
name|p2p_loop_on_all_groups
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
function_decl|(
modifier|*
name|group_callback
function_decl|)
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_get_peer_found - Get P2P peer info structure of a found peer  * @p2p: P2P module context from p2p_init()  * @addr: P2P Device Address of the peer or %NULL to indicate the first peer  * @next: Whether to select the peer entry following the one indicated by addr  * Returns: The first P2P peer info available or %NULL if no such peer exists  */
end_comment

begin_function_decl
specifier|const
name|struct
name|p2p_peer_info
modifier|*
name|p2p_get_peer_found
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|next
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_remove_wps_vendor_extensions - Remove WPS vendor extensions  * @p2p: P2P module context from p2p_init()  */
end_comment

begin_function_decl
name|void
name|p2p_remove_wps_vendor_extensions
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_add_wps_vendor_extension - Add a WPS vendor extension  * @p2p: P2P module context from p2p_init()  * @vendor_ext: The vendor extensions to add  * Returns: 0 on success, -1 on failure  *  * The wpabuf structures in the array are owned by the P2P  * module after this call.  */
end_comment

begin_function_decl
name|int
name|p2p_add_wps_vendor_extension
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|vendor_ext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_oper_channel - Set the P2P operating channel  * @p2p: P2P module context from p2p_init()  * @op_reg_class: Operating regulatory class to set  * @op_channel: operating channel to set  * @cfg_op_channel : Whether op_channel is hardcoded in configuration  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|p2p_set_oper_channel
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|u8
name|op_reg_class
parameter_list|,
name|u8
name|op_channel
parameter_list|,
name|int
name|cfg_op_channel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_pref_chan - Set P2P preferred channel list  * @p2p: P2P module context from p2p_init()  * @num_pref_chan: Number of entries in pref_chan list  * @pref_chan: Preferred channels or %NULL to remove preferences  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|p2p_set_pref_chan
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|unsigned
name|int
name|num_pref_chan
parameter_list|,
specifier|const
name|struct
name|p2p_channel
modifier|*
name|pref_chan
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_no_go_freq - Set no GO channel ranges  * @p2p: P2P module context from p2p_init()  * @list: Channel ranges or %NULL to remove restriction  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|p2p_set_no_go_freq
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|struct
name|wpa_freq_range_list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_in_progress - Check whether a P2P operation is progress  * @p2p: P2P module context from p2p_init()  * Returns: 0 if P2P module is idle, 1 if an operation is in progress but not  * in search state, or 2 if search state operation is in progress  */
end_comment

begin_function_decl
name|int
name|p2p_in_progress
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|p2p_wps_method_text
parameter_list|(
name|enum
name|p2p_wps_method
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_config_timeout - Set local config timeouts  * @p2p: P2P module context from p2p_init()  * @go_timeout: Time in 10 ms units it takes to start the GO mode  * @client_timeout: Time in 10 ms units it takes to start the client mode  */
end_comment

begin_function_decl
name|void
name|p2p_set_config_timeout
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|u8
name|go_timeout
parameter_list|,
name|u8
name|client_timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_wfd_ie_beacon
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|ie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_wfd_ie_probe_req
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|ie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_wfd_ie_probe_resp
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|ie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_wfd_ie_assoc_req
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|ie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_wfd_ie_invitation
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|ie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_wfd_ie_prov_disc_req
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|ie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_wfd_ie_prov_disc_resp
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|ie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_wfd_ie_go_neg
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|ie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_wfd_dev_info
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|elem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_wfd_assoc_bssid
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|elem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_wfd_coupled_sink_info
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|elem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|wifi_display_encaps
parameter_list|(
name|struct
name|wpabuf
modifier|*
name|subelems
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_set_disc_int - Set min/max discoverable interval for p2p_find  * @p2p: P2P module context from p2p_init()  * @min_disc_int: minDiscoverableInterval (in units of 100 TU); default 1  * @max_disc_int: maxDiscoverableInterval (in units of 100 TU); default 3  * @max_disc_tu: Maximum number of TUs (1.024 ms) for discoverable interval; or  *	-1 not to limit  * Returns: 0 on success, or -1 on failure  *  * This function can be used to configure minDiscoverableInterval and  * maxDiscoverableInterval parameters for the Listen state during device  * discovery (p2p_find). A random number of 100 TU units is picked for each  * Listen state iteration from [min_disc_int,max_disc_int] range.  *  * max_disc_tu can be used to futher limit the discoverable duration. However,  * it should be noted that use of this parameter is not recommended since it  * would not be compliant with the P2P specification.  */
end_comment

begin_function_decl
name|int
name|p2p_set_disc_int
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
name|min_disc_int
parameter_list|,
name|int
name|max_disc_int
parameter_list|,
name|int
name|max_disc_tu
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_get_state_txt - Get current P2P state for debug purposes  * @p2p: P2P module context from p2p_init()  * Returns: Name of the current P2P module state  *  * It should be noted that the P2P module state names are internal information  * and subject to change at any point, i.e., this information should be used  * mainly for debugging purposes.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|p2p_get_state_txt
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|p2p_build_nfc_handover_req
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
name|client_freq
parameter_list|,
specifier|const
name|u8
modifier|*
name|go_dev_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|ssid
parameter_list|,
name|size_t
name|ssid_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|p2p_build_nfc_handover_sel
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
name|client_freq
parameter_list|,
specifier|const
name|u8
modifier|*
name|go_dev_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|ssid
parameter_list|,
name|size_t
name|ssid_len
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|p2p_nfc_params
block|{
name|int
name|sel
decl_stmt|;
specifier|const
name|u8
modifier|*
name|wsc_attr
decl_stmt|;
name|size_t
name|wsc_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|p2p_attr
decl_stmt|;
name|size_t
name|p2p_len
decl_stmt|;
enum|enum
block|{
name|NO_ACTION
block|,
name|JOIN_GROUP
block|,
name|AUTH_JOIN
block|,
name|INIT_GO_NEG
block|,
name|RESP_GO_NEG
block|,
name|BOTH_GO
block|,
name|PEER_CLIENT
block|}
name|next_step
enum|;
name|struct
name|p2p_peer_info
modifier|*
name|peer
decl_stmt|;
name|u8
name|oob_dev_pw
index|[
name|WPS_OOB_PUBKEY_HASH_LEN
operator|+
literal|2
operator|+
name|WPS_OOB_DEVICE_PASSWORD_LEN
index|]
decl_stmt|;
name|size_t
name|oob_dev_pw_len
decl_stmt|;
name|int
name|go_freq
decl_stmt|;
name|u8
name|go_dev_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u8
name|go_ssid
index|[
name|SSID_MAX_LEN
index|]
decl_stmt|;
name|size_t
name|go_ssid_len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|p2p_process_nfc_connection_handover
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|struct
name|p2p_nfc_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p2p_set_authorized_oob_dev_pw_id
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|u16
name|dev_pw_id
parameter_list|,
name|int
name|go_intent
parameter_list|,
specifier|const
name|u8
modifier|*
name|own_interface_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_set_passphrase_len
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p2p_loop_on_known_peers
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|void
function_decl|(
modifier|*
name|peer_callback
function_decl|)
parameter_list|(
name|struct
name|p2p_peer_info
modifier|*
name|peer
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p2p_set_vendor_elems
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|struct
name|wpabuf
modifier|*
modifier|*
name|vendor_elem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p2p_set_intended_addr
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|u8
modifier|*
name|intended_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|p2ps_advertisement
modifier|*
name|p2p_service_p2ps_id
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|u32
name|adv_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_service_add_asp
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|int
name|auto_accept
parameter_list|,
name|u32
name|adv_id
parameter_list|,
specifier|const
name|char
modifier|*
name|adv_str
parameter_list|,
name|u8
name|svc_state
parameter_list|,
name|u16
name|config_methods
parameter_list|,
specifier|const
name|char
modifier|*
name|svc_info
parameter_list|,
specifier|const
name|u8
modifier|*
name|cpt_priority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p2p_service_del_asp
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
name|u32
name|adv_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p2p_service_flush_asp
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|p2ps_advertisement
modifier|*
name|p2p_get_p2ps_adv_list
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_expire_peers - Periodic cleanup function to expire peers  * @p2p: P2P module context from p2p_init()  *  * This is a cleanup function that the entity calling p2p_init() is  * expected to call periodically to clean up expired peer entries.  */
end_comment

begin_function_decl
name|void
name|p2p_expire_peers
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p2p_set_own_pref_freq_list
parameter_list|(
name|struct
name|p2p_data
modifier|*
name|p2p
parameter_list|,
specifier|const
name|unsigned
name|int
modifier|*
name|pref_freq_list
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * p2p_group_get_common_freqs - Get the group common frequencies  * @group: P2P group context from p2p_group_init()  * @common_freqs: On return will hold the group common frequencies  * @num: On return will hold the number of group common frequencies  * Returns: 0 on success, -1 otherwise  */
end_comment

begin_function_decl
name|int
name|p2p_group_get_common_freqs
parameter_list|(
name|struct
name|p2p_group
modifier|*
name|group
parameter_list|,
name|int
modifier|*
name|common_freqs
parameter_list|,
name|unsigned
name|int
modifier|*
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* P2P_H */
end_comment

end_unit

