begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * UPnP for WPS / internal definitions  * Copyright (c) 2000-2003 Intel Corporation  * Copyright (c) 2006-2007 Sony Corporation  * Copyright (c) 2008-2009 Atheros Communications  * Copyright (c) 2009, Jouni Malinen<j@w1.fi>  *  * See wps_upnp.c for more details on licensing and code history.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPS_UPNP_I_H
end_ifndef

begin_define
define|#
directive|define
name|WPS_UPNP_I_H
end_define

begin_define
define|#
directive|define
name|UPNP_MULTICAST_ADDRESS
value|"239.255.255.250"
end_define

begin_comment
comment|/* for UPnP multicasting */
end_comment

begin_define
define|#
directive|define
name|UPNP_MULTICAST_PORT
value|1900
end_define

begin_comment
comment|/* UDP port to monitor for UPnP */
end_comment

begin_comment
comment|/* min subscribe time per UPnP standard */
end_comment

begin_define
define|#
directive|define
name|UPNP_SUBSCRIBE_SEC_MIN
value|1800
end_define

begin_comment
comment|/* subscribe time we use */
end_comment

begin_define
define|#
directive|define
name|UPNP_SUBSCRIBE_SEC
value|(UPNP_SUBSCRIBE_SEC_MIN + 1)
end_define

begin_comment
comment|/* "filenames" used in URLs that we service via our "web server": */
end_comment

begin_define
define|#
directive|define
name|UPNP_WPS_DEVICE_XML_FILE
value|"wps_device.xml"
end_define

begin_define
define|#
directive|define
name|UPNP_WPS_SCPD_XML_FILE
value|"wps_scpd.xml"
end_define

begin_define
define|#
directive|define
name|UPNP_WPS_DEVICE_CONTROL_FILE
value|"wps_control"
end_define

begin_define
define|#
directive|define
name|UPNP_WPS_DEVICE_EVENT_FILE
value|"wps_event"
end_define

begin_struct_decl
struct_decl|struct
name|web_connection
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|subscription
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|upnp_wps_device_sm
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|http_reply_code
block|{
name|HTTP_OK
init|=
literal|200
block|,
name|HTTP_BAD_REQUEST
init|=
literal|400
block|,
name|UPNP_INVALID_ACTION
init|=
literal|401
block|,
name|UPNP_INVALID_ARGS
init|=
literal|402
block|,
name|HTTP_PRECONDITION_FAILED
init|=
literal|412
block|,
name|HTTP_INTERNAL_SERVER_ERROR
init|=
literal|500
block|,
name|HTTP_UNIMPLEMENTED
init|=
literal|501
block|,
name|UPNP_ACTION_FAILED
init|=
literal|501
block|,
name|UPNP_ARG_VALUE_INVALID
init|=
literal|600
block|,
name|UPNP_ARG_VALUE_OUT_OF_RANGE
init|=
literal|601
block|,
name|UPNP_OUT_OF_MEMORY
init|=
literal|603
block|}
enum|;
end_enum

begin_enum
enum|enum
name|advertisement_type_enum
block|{
name|ADVERTISE_UP
init|=
literal|0
block|,
name|ADVERTISE_DOWN
init|=
literal|1
block|,
name|MSEARCH_REPLY
init|=
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/*  * Advertisements are broadcast via UDP NOTIFYs, and are also the essence of  * the reply to UDP M-SEARCH requests. This struct handles both cases.  *  * A state machine is needed because a number of variant forms must be sent in  * separate packets and spread out in time to avoid congestion.  */
end_comment

begin_struct
struct|struct
name|advertisement_state_machine
block|{
comment|/* double-linked list */
name|struct
name|advertisement_state_machine
modifier|*
name|next
decl_stmt|;
name|struct
name|advertisement_state_machine
modifier|*
name|prev
decl_stmt|;
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
decl_stmt|;
comment|/* parent */
name|enum
name|advertisement_type_enum
name|type
decl_stmt|;
name|int
name|state
decl_stmt|;
name|int
name|nerrors
decl_stmt|;
name|struct
name|sockaddr_in
name|client
decl_stmt|;
comment|/* for M-SEARCH replies */
block|}
struct|;
end_struct

begin_comment
comment|/*  * An address of a subscriber (who may have multiple addresses). We are  * supposed to send (via TCP) updates to each subscriber, trying each address  * for a subscriber until we find one that seems to work.  */
end_comment

begin_struct
struct|struct
name|subscr_addr
block|{
comment|/* double linked list */
name|struct
name|subscr_addr
modifier|*
name|next
decl_stmt|;
name|struct
name|subscr_addr
modifier|*
name|prev
decl_stmt|;
name|struct
name|subscription
modifier|*
name|s
decl_stmt|;
comment|/* parent */
name|char
modifier|*
name|domain_and_port
decl_stmt|;
comment|/* domain and port part of url */
name|char
modifier|*
name|path
decl_stmt|;
comment|/* "filepath" part of url (from "mem") */
name|struct
name|sockaddr_in
name|saddr
decl_stmt|;
comment|/* address for doing connect */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Subscribers to our events are recorded in this struct. This includes a max  * of one outgoing connection (sending an "event message") per subscriber. We  * also have to age out subscribers unless they renew.  */
end_comment

begin_struct
struct|struct
name|subscription
block|{
comment|/* double linked list */
name|struct
name|subscription
modifier|*
name|next
decl_stmt|;
name|struct
name|subscription
modifier|*
name|prev
decl_stmt|;
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
decl_stmt|;
comment|/* parent */
name|time_t
name|timeout_time
decl_stmt|;
comment|/* when to age out the subscription */
name|unsigned
name|next_subscriber_sequence
decl_stmt|;
comment|/* number our messages */
comment|/* 	 * This uuid identifies the subscription and is randomly generated by 	 * us and given to the subscriber when the subscription is accepted; 	 * and is then included with each event sent to the subscriber. 	 */
name|u8
name|uuid
index|[
name|UUID_LEN
index|]
decl_stmt|;
comment|/* Linked list of address alternatives (rotate through on failure) */
name|struct
name|subscr_addr
modifier|*
name|addr_list
decl_stmt|;
name|int
name|n_addr
decl_stmt|;
comment|/* Number of addresses in list */
name|struct
name|wps_event_
modifier|*
name|event_queue
decl_stmt|;
comment|/* Queued event messages. */
name|int
name|n_queue
decl_stmt|;
comment|/* How many events are queued */
name|struct
name|wps_event_
modifier|*
name|current_event
decl_stmt|;
comment|/* non-NULL if being sent (not in q) 					   */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Our instance data corresponding to one WiFi network interface  * (multiple might share the same wired network interface!).  *  * This is known as an opaque struct declaration to users of the WPS UPnP code.  */
end_comment

begin_struct
struct|struct
name|upnp_wps_device_sm
block|{
name|struct
name|upnp_wps_device_ctx
modifier|*
name|ctx
decl_stmt|;
comment|/* callback table */
name|struct
name|wps_context
modifier|*
name|wps
decl_stmt|;
name|void
modifier|*
name|priv
decl_stmt|;
name|char
modifier|*
name|root_dir
decl_stmt|;
name|char
modifier|*
name|desc_url
decl_stmt|;
name|int
name|started
decl_stmt|;
comment|/* nonzero if we are active */
name|char
modifier|*
name|net_if
decl_stmt|;
comment|/* network interface we use */
name|char
modifier|*
name|mac_addr_text
decl_stmt|;
comment|/* mac addr of network i.f. we use */
name|u8
name|mac_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/* mac addr of network i.f. we use */
name|char
modifier|*
name|ip_addr_text
decl_stmt|;
comment|/* IP address of network i.f. we use */
name|unsigned
name|ip_addr
decl_stmt|;
comment|/* IP address of network i.f. we use (host order) */
name|int
name|multicast_sd
decl_stmt|;
comment|/* send multicast messages over this socket */
name|int
name|ssdp_sd
decl_stmt|;
comment|/* receive discovery UPD packets on socket */
name|int
name|ssdp_sd_registered
decl_stmt|;
comment|/* nonzero if we must unregister */
name|unsigned
name|advertise_count
decl_stmt|;
comment|/* how many advertisements done */
name|struct
name|advertisement_state_machine
name|advertisement
decl_stmt|;
name|struct
name|advertisement_state_machine
modifier|*
name|msearch_replies
decl_stmt|;
name|int
name|n_msearch_replies
decl_stmt|;
comment|/* no. of pending M-SEARCH replies */
name|int
name|web_port
decl_stmt|;
comment|/* our port that others get xml files from */
name|int
name|web_sd
decl_stmt|;
comment|/* socket to listen for web requests */
name|int
name|web_sd_registered
decl_stmt|;
comment|/* nonzero if we must cancel registration */
name|struct
name|web_connection
modifier|*
name|web_connections
decl_stmt|;
comment|/* linked list */
name|int
name|n_web_connections
decl_stmt|;
comment|/* no. of pending web connections */
comment|/* Note: subscriptions are kept in expiry order */
name|struct
name|subscription
modifier|*
name|subscriptions
decl_stmt|;
comment|/* linked list */
name|int
name|n_subscriptions
decl_stmt|;
comment|/* no of current subscriptions */
name|int
name|event_send_all_queued
decl_stmt|;
comment|/* if we are scheduled to send events soon 				    */
name|char
modifier|*
name|wlanevent
decl_stmt|;
comment|/* the last WLANEvent data */
comment|/* FIX: maintain separate structures for each UPnP peer */
name|struct
name|upnp_wps_peer
name|peer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* wps_upnp.c */
end_comment

begin_function_decl
name|void
name|format_date
parameter_list|(
name|struct
name|wpabuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|subscription
modifier|*
name|subscription_start
parameter_list|(
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
parameter_list|,
name|char
modifier|*
name|callback_urls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|subscription
modifier|*
name|subscription_renew
parameter_list|(
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
parameter_list|,
specifier|const
name|u8
name|uuid
index|[
name|UUID_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|subscription_unlink
parameter_list|(
name|struct
name|subscription
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|subscription_destroy
parameter_list|(
name|struct
name|subscription
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|subscription
modifier|*
name|subscription_find
parameter_list|(
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
parameter_list|,
specifier|const
name|u8
name|uuid
index|[
name|UUID_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|send_wpabuf
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* wps_upnp_ssdp.c */
end_comment

begin_function_decl
name|void
name|msearchreply_state_machine_stop
parameter_list|(
name|struct
name|advertisement_state_machine
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|advertisement_state_machine_start
parameter_list|(
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|advertisement_state_machine_stop
parameter_list|(
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssdp_listener_stop
parameter_list|(
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssdp_listener_start
parameter_list|(
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|add_ssdp_network
parameter_list|(
name|char
modifier|*
name|net_if
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssdp_open_multicast
parameter_list|(
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* wps_upnp_web.c */
end_comment

begin_function_decl
name|void
name|web_connection_stop
parameter_list|(
name|struct
name|web_connection
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|web_listener_start
parameter_list|(
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|web_listener_stop
parameter_list|(
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* wps_upnp_event.c */
end_comment

begin_function_decl
name|int
name|event_add
parameter_list|(
name|struct
name|subscription
modifier|*
name|s
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|event_delete
parameter_list|(
name|struct
name|wps_event_
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|event_delete_all
parameter_list|(
name|struct
name|subscription
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|event_send_all_later
parameter_list|(
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|event_send_stop_all
parameter_list|(
name|struct
name|upnp_wps_device_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPS_UPNP_I_H */
end_comment

end_unit

