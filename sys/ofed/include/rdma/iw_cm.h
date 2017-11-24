begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Network Appliance, Inc. All rights reserved.  * Copyright (c) 2005 Open Grid Computing, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IW_CM_H
end_ifndef

begin_define
define|#
directive|define
name|IW_CM_H
end_define

begin_include
include|#
directive|include
file|<linux/in.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_cm.h>
end_include

begin_struct_decl
struct_decl|struct
name|iw_cm_id
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|iw_cm_event_type
block|{
name|IW_CM_EVENT_CONNECT_REQUEST
init|=
literal|1
block|,
comment|/* connect request received */
name|IW_CM_EVENT_CONNECT_REPLY
block|,
comment|/* reply from active connect request */
name|IW_CM_EVENT_ESTABLISHED
block|,
comment|/* passive side accept successful */
name|IW_CM_EVENT_DISCONNECT
block|,
comment|/* orderly shutdown */
name|IW_CM_EVENT_CLOSE
comment|/* close complete */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|iw_cm_event
block|{
name|enum
name|iw_cm_event_type
name|event
decl_stmt|;
name|int
name|status
decl_stmt|;
name|struct
name|sockaddr_storage
name|local_addr
decl_stmt|;
name|struct
name|sockaddr_storage
name|remote_addr
decl_stmt|;
name|void
modifier|*
name|private_data
decl_stmt|;
name|void
modifier|*
name|provider_data
decl_stmt|;
name|u8
name|private_data_len
decl_stmt|;
name|u8
name|ord
decl_stmt|;
name|u8
name|ird
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * iw_cm_handler - Function to be called by the IW CM when delivering events  * to the client.  *  * @cm_id: The IW CM identifier associated with the event.  * @event: Pointer to the event structure.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|iw_cm_handler
function_decl|)
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|,
name|struct
name|iw_cm_event
modifier|*
name|event
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * iw_event_handler - Function called by the provider when delivering provider  * events to the IW CM.  Returns either 0 indicating the event was processed  * or -errno if the event could not be processed.  *  * @cm_id: The IW CM identifier associated with the event.  * @event: Pointer to the event structure.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|iw_event_handler
function_decl|)
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|,
name|struct
name|iw_cm_event
modifier|*
name|event
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|iw_cm_id
block|{
name|iw_cm_handler
name|cm_handler
decl_stmt|;
comment|/* client callback function */
name|void
modifier|*
name|context
decl_stmt|;
comment|/* client cb context */
name|struct
name|ib_device
modifier|*
name|device
decl_stmt|;
name|struct
name|sockaddr_storage
name|local_addr
decl_stmt|;
comment|/* local addr */
name|struct
name|sockaddr_storage
name|remote_addr
decl_stmt|;
name|struct
name|sockaddr_storage
name|m_local_addr
decl_stmt|;
comment|/* nmapped local addr */
name|struct
name|sockaddr_storage
name|m_remote_addr
decl_stmt|;
comment|/* nmapped rem addr */
name|void
modifier|*
name|provider_data
decl_stmt|;
comment|/* provider private data */
name|iw_event_handler
name|event_handler
decl_stmt|;
comment|/* cb for provider 						    events */
comment|/* Used by provider to add and remove refs on IW cm_id */
name|void
function_decl|(
modifier|*
name|add_ref
function_decl|)
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rem_ref
function_decl|)
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
parameter_list|)
function_decl|;
name|u8
name|tos
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iw_cm_conn_param
block|{
specifier|const
name|void
modifier|*
name|private_data
decl_stmt|;
name|u16
name|private_data_len
decl_stmt|;
name|u32
name|ord
decl_stmt|;
name|u32
name|ird
decl_stmt|;
name|u32
name|qpn
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iw_cm_verbs
block|{
name|void
function_decl|(
modifier|*
name|add_ref
function_decl|)
parameter_list|(
name|struct
name|ib_qp
modifier|*
name|qp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rem_ref
function_decl|)
parameter_list|(
name|struct
name|ib_qp
modifier|*
name|qp
parameter_list|)
function_decl|;
name|struct
name|ib_qp
modifier|*
function_decl|(
modifier|*
name|get_qp
function_decl|)
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|int
name|qpn
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|connect
function_decl|)
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|,
name|struct
name|iw_cm_conn_param
modifier|*
name|conn_param
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|accept
function_decl|)
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|,
name|struct
name|iw_cm_conn_param
modifier|*
name|conn_param
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|reject
function_decl|)
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|,
specifier|const
name|void
modifier|*
name|pdata
parameter_list|,
name|u8
name|pdata_len
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|create_listen
function_decl|)
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|,
name|int
name|backlog
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|destroy_listen
function_decl|)
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|)
function_decl|;
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * iw_create_cm_id - Create an IW CM identifier.  *  * @device: The IB device on which to create the IW CM identier.  * @event_handler: User callback invoked to report events associated with the  *   returned IW CM identifier.  * @context: User specified context associated with the id.  */
end_comment

begin_function_decl
name|struct
name|iw_cm_id
modifier|*
name|iw_create_cm_id
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|iw_cm_handler
name|cm_handler
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * iw_destroy_cm_id - Destroy an IW CM identifier.  *  * @cm_id: The previously created IW CM identifier to destroy.  *  * The client can assume that no events will be delivered for the CM ID after  * this function returns.  */
end_comment

begin_function_decl
name|void
name|iw_destroy_cm_id
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * iw_cm_bind_qp - Unbind the specified IW CM identifier and QP  *  * @cm_id: The IW CM idenfier to unbind from the QP.  * @qp: The QP  *  * This is called by the provider when destroying the QP to ensure  * that any references held by the IWCM are released. It may also  * be called by the IWCM when destroying a CM_ID to that any  * references held by the provider are released.  */
end_comment

begin_function_decl
name|void
name|iw_cm_unbind_qp
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|,
name|struct
name|ib_qp
modifier|*
name|qp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * iw_cm_get_qp - Return the ib_qp associated with a QPN  *  * @ib_device: The IB device  * @qpn: The queue pair number  */
end_comment

begin_function_decl
name|struct
name|ib_qp
modifier|*
name|iw_cm_get_qp
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|int
name|qpn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * iw_cm_listen - Listen for incoming connection requests on the  * specified IW CM id.  *  * @cm_id: The IW CM identifier.  * @backlog: The maximum number of outstanding un-accepted inbound listen  *   requests to queue.  *  * The source address and port number are specified in the IW CM identifier  * structure.  */
end_comment

begin_function_decl
name|int
name|iw_cm_listen
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|,
name|int
name|backlog
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * iw_cm_accept - Called to accept an incoming connect request.  *  * @cm_id: The IW CM identifier associated with the connection request.  * @iw_param: Pointer to a structure containing connection establishment  *   parameters.  *  * The specified cm_id will have been provided in the event data for a  * CONNECT_REQUEST event. Subsequent events related to this connection will be  * delivered to the specified IW CM identifier prior and may occur prior to  * the return of this function. If this function returns a non-zero value, the  * client can assume that no events will be delivered to the specified IW CM  * identifier.  */
end_comment

begin_function_decl
name|int
name|iw_cm_accept
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|,
name|struct
name|iw_cm_conn_param
modifier|*
name|iw_param
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * iw_cm_reject - Reject an incoming connection request.  *  * @cm_id: Connection identifier associated with the request.  * @private_daa: Pointer to data to deliver to the remote peer as part of the  *   reject message.  * @private_data_len: The number of bytes in the private_data parameter.  *  * The client can assume that no events will be delivered to the specified IW  * CM identifier following the return of this function. The private_data  * buffer is available for reuse when this function returns.  */
end_comment

begin_function_decl
name|int
name|iw_cm_reject
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|,
specifier|const
name|void
modifier|*
name|private_data
parameter_list|,
name|u8
name|private_data_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * iw_cm_connect - Called to request a connection to a remote peer.  *  * @cm_id: The IW CM identifier for the connection.  * @iw_param: Pointer to a structure containing connection  establishment  *   parameters.  *  * Events may be delivered to the specified IW CM identifier prior to the  * return of this function. If this function returns a non-zero value, the  * client can assume that no events will be delivered to the specified IW CM  * identifier.  */
end_comment

begin_function_decl
name|int
name|iw_cm_connect
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|,
name|struct
name|iw_cm_conn_param
modifier|*
name|iw_param
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * iw_cm_disconnect - Close the specified connection.  *  * @cm_id: The IW CM identifier to close.  * @abrupt: If 0, the connection will be closed gracefully, otherwise, the  *   connection will be reset.  *  * The IW CM identifier is still active until the IW_CM_EVENT_CLOSE event is  * delivered.  */
end_comment

begin_function_decl
name|int
name|iw_cm_disconnect
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|,
name|int
name|abrupt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * iw_cm_init_qp_attr - Called to initialize the attributes of the QP  * associated with a IW CM identifier.  *  * @cm_id: The IW CM identifier associated with the QP  * @qp_attr: Pointer to the QP attributes structure.  * @qp_attr_mask: Pointer to a bit vector specifying which QP attributes are  *   valid.  */
end_comment

begin_function_decl
name|int
name|iw_cm_init_qp_attr
parameter_list|(
name|struct
name|iw_cm_id
modifier|*
name|cm_id
parameter_list|,
name|struct
name|ib_qp_attr
modifier|*
name|qp_attr
parameter_list|,
name|int
modifier|*
name|qp_attr_mask
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IW_CM_H */
end_comment

end_unit

