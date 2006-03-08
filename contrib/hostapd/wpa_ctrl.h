begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant/hostapd control interface library  * Copyright (c) 2004-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
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
comment|/** EAP method selected */
define|#
directive|define
name|WPA_EVENT_EAP_METHOD
value|"CTRL-EVENT-EAP-METHOD "
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
comment|/**  * wpa_ctrl_pending - Check whether there are pending event messages  * @ctrl: Control interface data from wpa_ctrl_open()  * Returns: Non-zero if there are pending messages  *  * This function will check whether there are any pending control interface  * message available to be received with wpa_ctrl_recv(). wpa_ctrl_pending() is  * only used for event messages, i.e., wpa_ctrl_attach() must have been used to  * register the control interface as an event monitor.  */
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
ifdef|#
directive|ifdef
name|CONFIG_CTRL_IFACE_UDP
define|#
directive|define
name|WPA_CTRL_IFACE_PORT
value|9877
define|#
directive|define
name|WPA_GLOBAL_CTRL_IFACE_PORT
value|9878
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

