begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant/hostapd control interface library  * Copyright (c) 2004-2006, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPA_CTRL_H
end_ifndef

begin_define
define|#
directive|define
name|WPA_CTRL_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* wpa_supplicant control interface - fixed message prefixes */
comment|/** Interactive request for identity/password/pin */
define|#
directive|define
name|WPA_CTRL_REQ
value|"CTRL-REQ-"
comment|/** Response to identity/password/pin request */
define|#
directive|define
name|WPA_CTRL_RSP
value|"CTRL-RSP-"
comment|/* Event messages with fixed prefix */
comment|/** Authentication completed successfully and data connection enabled */
define|#
directive|define
name|WPA_EVENT_CONNECTED
value|"CTRL-EVENT-CONNECTED "
comment|/** Disconnected, data connection is not available */
define|#
directive|define
name|WPA_EVENT_DISCONNECTED
value|"CTRL-EVENT-DISCONNECTED "
comment|/** Association rejected during connection attempt */
define|#
directive|define
name|WPA_EVENT_ASSOC_REJECT
value|"CTRL-EVENT-ASSOC-REJECT "
comment|/** wpa_supplicant is exiting */
define|#
directive|define
name|WPA_EVENT_TERMINATING
value|"CTRL-EVENT-TERMINATING "
comment|/** Password change was completed successfully */
define|#
directive|define
name|WPA_EVENT_PASSWORD_CHANGED
value|"CTRL-EVENT-PASSWORD-CHANGED "
comment|/** EAP-Request/Notification received */
define|#
directive|define
name|WPA_EVENT_EAP_NOTIFICATION
value|"CTRL-EVENT-EAP-NOTIFICATION "
comment|/** EAP authentication started (EAP-Request/Identity received) */
define|#
directive|define
name|WPA_EVENT_EAP_STARTED
value|"CTRL-EVENT-EAP-STARTED "
comment|/** EAP method proposed by the server */
define|#
directive|define
name|WPA_EVENT_EAP_PROPOSED_METHOD
value|"CTRL-EVENT-EAP-PROPOSED-METHOD "
comment|/** EAP method selected */
define|#
directive|define
name|WPA_EVENT_EAP_METHOD
value|"CTRL-EVENT-EAP-METHOD "
comment|/** EAP peer certificate from TLS */
define|#
directive|define
name|WPA_EVENT_EAP_PEER_CERT
value|"CTRL-EVENT-EAP-PEER-CERT "
comment|/** EAP TLS certificate chain validation error */
define|#
directive|define
name|WPA_EVENT_EAP_TLS_CERT_ERROR
value|"CTRL-EVENT-EAP-TLS-CERT-ERROR "
comment|/** EAP authentication completed successfully */
define|#
directive|define
name|WPA_EVENT_EAP_SUCCESS
value|"CTRL-EVENT-EAP-SUCCESS "
comment|/** EAP authentication failed (EAP-Failure received) */
define|#
directive|define
name|WPA_EVENT_EAP_FAILURE
value|"CTRL-EVENT-EAP-FAILURE "
comment|/** Network block temporarily disabled (e.g., due to authentication failure) */
define|#
directive|define
name|WPA_EVENT_TEMP_DISABLED
value|"CTRL-EVENT-SSID-TEMP-DISABLED "
comment|/** Temporarily disabled network block re-enabled */
define|#
directive|define
name|WPA_EVENT_REENABLED
value|"CTRL-EVENT-SSID-REENABLED "
comment|/** New scan results available */
define|#
directive|define
name|WPA_EVENT_SCAN_RESULTS
value|"CTRL-EVENT-SCAN-RESULTS "
comment|/** wpa_supplicant state change */
define|#
directive|define
name|WPA_EVENT_STATE_CHANGE
value|"CTRL-EVENT-STATE-CHANGE "
comment|/** A new BSS entry was added (followed by BSS entry id and BSSID) */
define|#
directive|define
name|WPA_EVENT_BSS_ADDED
value|"CTRL-EVENT-BSS-ADDED "
comment|/** A BSS entry was removed (followed by BSS entry id and BSSID) */
define|#
directive|define
name|WPA_EVENT_BSS_REMOVED
value|"CTRL-EVENT-BSS-REMOVED "
comment|/** WPS overlap detected in PBC mode */
define|#
directive|define
name|WPS_EVENT_OVERLAP
value|"WPS-OVERLAP-DETECTED "
comment|/** Available WPS AP with active PBC found in scan results */
define|#
directive|define
name|WPS_EVENT_AP_AVAILABLE_PBC
value|"WPS-AP-AVAILABLE-PBC "
comment|/** Available WPS AP with our address as authorized in scan results */
define|#
directive|define
name|WPS_EVENT_AP_AVAILABLE_AUTH
value|"WPS-AP-AVAILABLE-AUTH "
comment|/** Available WPS AP with recently selected PIN registrar found in scan results  */
define|#
directive|define
name|WPS_EVENT_AP_AVAILABLE_PIN
value|"WPS-AP-AVAILABLE-PIN "
comment|/** Available WPS AP found in scan results */
define|#
directive|define
name|WPS_EVENT_AP_AVAILABLE
value|"WPS-AP-AVAILABLE "
comment|/** A new credential received */
define|#
directive|define
name|WPS_EVENT_CRED_RECEIVED
value|"WPS-CRED-RECEIVED "
comment|/** M2D received */
define|#
directive|define
name|WPS_EVENT_M2D
value|"WPS-M2D "
comment|/** WPS registration failed after M2/M2D */
define|#
directive|define
name|WPS_EVENT_FAIL
value|"WPS-FAIL "
comment|/** WPS registration completed successfully */
define|#
directive|define
name|WPS_EVENT_SUCCESS
value|"WPS-SUCCESS "
comment|/** WPS enrollment attempt timed out and was terminated */
define|#
directive|define
name|WPS_EVENT_TIMEOUT
value|"WPS-TIMEOUT "
define|#
directive|define
name|WPS_EVENT_ENROLLEE_SEEN
value|"WPS-ENROLLEE-SEEN "
define|#
directive|define
name|WPS_EVENT_OPEN_NETWORK
value|"WPS-OPEN-NETWORK "
comment|/* WPS ER events */
define|#
directive|define
name|WPS_EVENT_ER_AP_ADD
value|"WPS-ER-AP-ADD "
define|#
directive|define
name|WPS_EVENT_ER_AP_REMOVE
value|"WPS-ER-AP-REMOVE "
define|#
directive|define
name|WPS_EVENT_ER_ENROLLEE_ADD
value|"WPS-ER-ENROLLEE-ADD "
define|#
directive|define
name|WPS_EVENT_ER_ENROLLEE_REMOVE
value|"WPS-ER-ENROLLEE-REMOVE "
define|#
directive|define
name|WPS_EVENT_ER_AP_SETTINGS
value|"WPS-ER-AP-SETTINGS "
define|#
directive|define
name|WPS_EVENT_ER_SET_SEL_REG
value|"WPS-ER-AP-SET-SEL-REG "
comment|/** P2P device found */
define|#
directive|define
name|P2P_EVENT_DEVICE_FOUND
value|"P2P-DEVICE-FOUND "
comment|/** P2P device lost */
define|#
directive|define
name|P2P_EVENT_DEVICE_LOST
value|"P2P-DEVICE-LOST "
comment|/** A P2P device requested GO negotiation, but we were not ready to start the  * negotiation */
define|#
directive|define
name|P2P_EVENT_GO_NEG_REQUEST
value|"P2P-GO-NEG-REQUEST "
define|#
directive|define
name|P2P_EVENT_GO_NEG_SUCCESS
value|"P2P-GO-NEG-SUCCESS "
define|#
directive|define
name|P2P_EVENT_GO_NEG_FAILURE
value|"P2P-GO-NEG-FAILURE "
define|#
directive|define
name|P2P_EVENT_GROUP_FORMATION_SUCCESS
value|"P2P-GROUP-FORMATION-SUCCESS "
define|#
directive|define
name|P2P_EVENT_GROUP_FORMATION_FAILURE
value|"P2P-GROUP-FORMATION-FAILURE "
define|#
directive|define
name|P2P_EVENT_GROUP_STARTED
value|"P2P-GROUP-STARTED "
define|#
directive|define
name|P2P_EVENT_GROUP_REMOVED
value|"P2P-GROUP-REMOVED "
define|#
directive|define
name|P2P_EVENT_CROSS_CONNECT_ENABLE
value|"P2P-CROSS-CONNECT-ENABLE "
define|#
directive|define
name|P2P_EVENT_CROSS_CONNECT_DISABLE
value|"P2P-CROSS-CONNECT-DISABLE "
comment|/* parameters:<peer address><PIN> */
define|#
directive|define
name|P2P_EVENT_PROV_DISC_SHOW_PIN
value|"P2P-PROV-DISC-SHOW-PIN "
comment|/* parameters:<peer address> */
define|#
directive|define
name|P2P_EVENT_PROV_DISC_ENTER_PIN
value|"P2P-PROV-DISC-ENTER-PIN "
comment|/* parameters:<peer address> */
define|#
directive|define
name|P2P_EVENT_PROV_DISC_PBC_REQ
value|"P2P-PROV-DISC-PBC-REQ "
comment|/* parameters:<peer address> */
define|#
directive|define
name|P2P_EVENT_PROV_DISC_PBC_RESP
value|"P2P-PROV-DISC-PBC-RESP "
comment|/* parameters:<peer address><status> */
define|#
directive|define
name|P2P_EVENT_PROV_DISC_FAILURE
value|"P2P-PROV-DISC-FAILURE"
comment|/* parameters:<freq><src addr><dialog token><update indicator><TLVs> */
define|#
directive|define
name|P2P_EVENT_SERV_DISC_REQ
value|"P2P-SERV-DISC-REQ "
comment|/* parameters:<src addr><update indicator><TLVs> */
define|#
directive|define
name|P2P_EVENT_SERV_DISC_RESP
value|"P2P-SERV-DISC-RESP "
define|#
directive|define
name|P2P_EVENT_INVITATION_RECEIVED
value|"P2P-INVITATION-RECEIVED "
define|#
directive|define
name|P2P_EVENT_INVITATION_RESULT
value|"P2P-INVITATION-RESULT "
define|#
directive|define
name|P2P_EVENT_FIND_STOPPED
value|"P2P-FIND-STOPPED "
define|#
directive|define
name|INTERWORKING_AP
value|"INTERWORKING-AP "
define|#
directive|define
name|INTERWORKING_NO_MATCH
value|"INTERWORKING-NO-MATCH "
define|#
directive|define
name|GAS_RESPONSE_INFO
value|"GAS-RESPONSE-INFO "
comment|/* hostapd control interface - fixed message prefixes */
define|#
directive|define
name|WPS_EVENT_PIN_NEEDED
value|"WPS-PIN-NEEDED "
define|#
directive|define
name|WPS_EVENT_NEW_AP_SETTINGS
value|"WPS-NEW-AP-SETTINGS "
define|#
directive|define
name|WPS_EVENT_REG_SUCCESS
value|"WPS-REG-SUCCESS "
define|#
directive|define
name|WPS_EVENT_AP_SETUP_LOCKED
value|"WPS-AP-SETUP-LOCKED "
define|#
directive|define
name|WPS_EVENT_AP_SETUP_UNLOCKED
value|"WPS-AP-SETUP-UNLOCKED "
define|#
directive|define
name|WPS_EVENT_AP_PIN_ENABLED
value|"WPS-AP-PIN-ENABLED "
define|#
directive|define
name|WPS_EVENT_AP_PIN_DISABLED
value|"WPS-AP-PIN-DISABLED "
define|#
directive|define
name|AP_STA_CONNECTED
value|"AP-STA-CONNECTED "
define|#
directive|define
name|AP_STA_DISCONNECTED
value|"AP-STA-DISCONNECTED "
comment|/* BSS command information masks */
define|#
directive|define
name|WPA_BSS_MASK_ALL
value|0xFFFFFFFF
define|#
directive|define
name|WPA_BSS_MASK_ID
value|BIT(0)
define|#
directive|define
name|WPA_BSS_MASK_BSSID
value|BIT(1)
define|#
directive|define
name|WPA_BSS_MASK_FREQ
value|BIT(2)
define|#
directive|define
name|WPA_BSS_MASK_BEACON_INT
value|BIT(3)
define|#
directive|define
name|WPA_BSS_MASK_CAPABILITIES
value|BIT(4)
define|#
directive|define
name|WPA_BSS_MASK_QUAL
value|BIT(5)
define|#
directive|define
name|WPA_BSS_MASK_NOISE
value|BIT(6)
define|#
directive|define
name|WPA_BSS_MASK_LEVEL
value|BIT(7)
define|#
directive|define
name|WPA_BSS_MASK_TSF
value|BIT(8)
define|#
directive|define
name|WPA_BSS_MASK_AGE
value|BIT(9)
define|#
directive|define
name|WPA_BSS_MASK_IE
value|BIT(10)
define|#
directive|define
name|WPA_BSS_MASK_FLAGS
value|BIT(11)
define|#
directive|define
name|WPA_BSS_MASK_SSID
value|BIT(12)
define|#
directive|define
name|WPA_BSS_MASK_WPS_SCAN
value|BIT(13)
define|#
directive|define
name|WPA_BSS_MASK_P2P_SCAN
value|BIT(14)
define|#
directive|define
name|WPA_BSS_MASK_INTERNETW
value|BIT(15)
define|#
directive|define
name|WPA_BSS_MASK_WIFI_DISPLAY
value|BIT(16)
comment|/* wpa_supplicant/hostapd control interface access */
comment|/**  * wpa_ctrl_open - Open a control interface to wpa_supplicant/hostapd  * @ctrl_path: Path for UNIX domain sockets; ignored if UDP sockets are used.  * Returns: Pointer to abstract control interface data or %NULL on failure  *  * This function is used to open a control interface to wpa_supplicant/hostapd.  * ctrl_path is usually /var/run/wpa_supplicant or /var/run/hostapd. This path  * is configured in wpa_supplicant/hostapd and other programs using the control  * interface need to use matching path configuration.  */
name|struct
name|wpa_ctrl
modifier|*
name|wpa_ctrl_open
parameter_list|(
specifier|const
name|char
modifier|*
name|ctrl_path
parameter_list|)
function_decl|;
comment|/**  * wpa_ctrl_close - Close a control interface to wpa_supplicant/hostapd  * @ctrl: Control interface data from wpa_ctrl_open()  *  * This function is used to close a control interface.  */
name|void
name|wpa_ctrl_close
parameter_list|(
name|struct
name|wpa_ctrl
modifier|*
name|ctrl
parameter_list|)
function_decl|;
comment|/**  * wpa_ctrl_request - Send a command to wpa_supplicant/hostapd  * @ctrl: Control interface data from wpa_ctrl_open()  * @cmd: Command; usually, ASCII text, e.g., "PING"  * @cmd_len: Length of the cmd in bytes  * @reply: Buffer for the response  * @reply_len: Reply buffer length  * @msg_cb: Callback function for unsolicited messages or %NULL if not used  * Returns: 0 on success, -1 on error (send or receive failed), -2 on timeout  *  * This function is used to send commands to wpa_supplicant/hostapd. Received  * response will be written to reply and reply_len is set to the actual length  * of the reply. This function will block for up to two seconds while waiting  * for the reply. If unsolicited messages are received, the blocking time may  * be longer.  *  * msg_cb can be used to register a callback function that will be called for  * unsolicited messages received while waiting for the command response. These  * messages may be received if wpa_ctrl_request() is called at the same time as  * wpa_supplicant/hostapd is sending such a message. This can happen only if  * the program has used wpa_ctrl_attach() to register itself as a monitor for  * event messages. Alternatively to msg_cb, programs can register two control  * interface connections and use one of them for commands and the other one for  * receiving event messages, in other words, call wpa_ctrl_attach() only for  * the control interface connection that will be used for event messages.  */
name|int
name|wpa_ctrl_request
parameter_list|(
name|struct
name|wpa_ctrl
modifier|*
name|ctrl
parameter_list|,
specifier|const
name|char
modifier|*
name|cmd
parameter_list|,
name|size_t
name|cmd_len
parameter_list|,
name|char
modifier|*
name|reply
parameter_list|,
name|size_t
modifier|*
name|reply_len
parameter_list|,
name|void
function_decl|(
modifier|*
name|msg_cb
function_decl|)
parameter_list|(
name|char
modifier|*
name|msg
parameter_list|,
name|size_t
name|len
parameter_list|)
parameter_list|)
function_decl|;
comment|/**  * wpa_ctrl_attach - Register as an event monitor for the control interface  * @ctrl: Control interface data from wpa_ctrl_open()  * Returns: 0 on success, -1 on failure, -2 on timeout  *  * This function registers the control interface connection as a monitor for  * wpa_supplicant/hostapd events. After a success wpa_ctrl_attach() call, the  * control interface connection starts receiving event messages that can be  * read with wpa_ctrl_recv().  */
name|int
name|wpa_ctrl_attach
parameter_list|(
name|struct
name|wpa_ctrl
modifier|*
name|ctrl
parameter_list|)
function_decl|;
comment|/**  * wpa_ctrl_detach - Unregister event monitor from the control interface  * @ctrl: Control interface data from wpa_ctrl_open()  * Returns: 0 on success, -1 on failure, -2 on timeout  *  * This function unregisters the control interface connection as a monitor for  * wpa_supplicant/hostapd events, i.e., cancels the registration done with  * wpa_ctrl_attach().  */
name|int
name|wpa_ctrl_detach
parameter_list|(
name|struct
name|wpa_ctrl
modifier|*
name|ctrl
parameter_list|)
function_decl|;
comment|/**  * wpa_ctrl_recv - Receive a pending control interface message  * @ctrl: Control interface data from wpa_ctrl_open()  * @reply: Buffer for the message data  * @reply_len: Length of the reply buffer  * Returns: 0 on success, -1 on failure  *  * This function will receive a pending control interface message. This  * function will block if no messages are available. The received response will  * be written to reply and reply_len is set to the actual length of the reply.  * wpa_ctrl_recv() is only used for event messages, i.e., wpa_ctrl_attach()  * must have been used to register the control interface as an event monitor.  */
name|int
name|wpa_ctrl_recv
parameter_list|(
name|struct
name|wpa_ctrl
modifier|*
name|ctrl
parameter_list|,
name|char
modifier|*
name|reply
parameter_list|,
name|size_t
modifier|*
name|reply_len
parameter_list|)
function_decl|;
comment|/**  * wpa_ctrl_pending - Check whether there are pending event messages  * @ctrl: Control interface data from wpa_ctrl_open()  * Returns: 1 if there are pending messages, 0 if no, or -1 on error  *  * This function will check whether there are any pending control interface  * message available to be received with wpa_ctrl_recv(). wpa_ctrl_pending() is  * only used for event messages, i.e., wpa_ctrl_attach() must have been used to  * register the control interface as an event monitor.  */
name|int
name|wpa_ctrl_pending
parameter_list|(
name|struct
name|wpa_ctrl
modifier|*
name|ctrl
parameter_list|)
function_decl|;
comment|/**  * wpa_ctrl_get_fd - Get file descriptor used by the control interface  * @ctrl: Control interface data from wpa_ctrl_open()  * Returns: File descriptor used for the connection  *  * This function can be used to get the file descriptor that is used for the  * control interface connection. The returned value can be used, e.g., with  * select() while waiting for multiple events.  *  * The returned file descriptor must not be used directly for sending or  * receiving packets; instead, the library functions wpa_ctrl_request() and  * wpa_ctrl_recv() must be used for this.  */
name|int
name|wpa_ctrl_get_fd
parameter_list|(
name|struct
name|wpa_ctrl
modifier|*
name|ctrl
parameter_list|)
function_decl|;
name|char
modifier|*
name|wpa_ctrl_get_remote_ifname
parameter_list|(
name|struct
name|wpa_ctrl
modifier|*
name|ctrl
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|ANDROID
comment|/**  * wpa_ctrl_cleanup() - Delete any local UNIX domain socket files that  * may be left over from clients that were previously connected to  * wpa_supplicant. This keeps these files from being orphaned in the  * event of crashes that prevented them from being removed as part  * of the normal orderly shutdown.  */
name|void
name|wpa_ctrl_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* ANDROID */
ifdef|#
directive|ifdef
name|CONFIG_CTRL_IFACE_UDP
comment|/* Port range for multiple wpa_supplicant instances and multiple VIFs */
define|#
directive|define
name|WPA_CTRL_IFACE_PORT
value|9877
define|#
directive|define
name|WPA_CTRL_IFACE_PORT_LIMIT
value|50
comment|/* decremented from start */
define|#
directive|define
name|WPA_GLOBAL_CTRL_IFACE_PORT
value|9878
define|#
directive|define
name|WPA_GLOBAL_CTRL_IFACE_PORT_LIMIT
value|20
comment|/* incremented from start */
endif|#
directive|endif
comment|/* CONFIG_CTRL_IFACE_UDP */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPA_CTRL_H */
end_comment

end_unit

