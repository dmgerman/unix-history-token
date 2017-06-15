begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Voltaire Inc.  All rights reserved.  * Copyright (c) 2005 Intel Corporation.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|RDMA_CM_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|RDMA_CM_H
end_define

begin_include
include|#
directive|include
file|<linux/socket.h>
end_include

begin_include
include|#
directive|include
file|<linux/in6.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_addr.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_sa.h>
end_include

begin_comment
comment|/*  * Upon receiving a device removal event, users must destroy the associated  * RDMA identifier and release all resources allocated with the device.  */
end_comment

begin_enum
enum|enum
name|rdma_cm_event_type
block|{
name|RDMA_CM_EVENT_ADDR_RESOLVED
block|,
name|RDMA_CM_EVENT_ADDR_ERROR
block|,
name|RDMA_CM_EVENT_ROUTE_RESOLVED
block|,
name|RDMA_CM_EVENT_ROUTE_ERROR
block|,
name|RDMA_CM_EVENT_CONNECT_REQUEST
block|,
name|RDMA_CM_EVENT_CONNECT_RESPONSE
block|,
name|RDMA_CM_EVENT_CONNECT_ERROR
block|,
name|RDMA_CM_EVENT_UNREACHABLE
block|,
name|RDMA_CM_EVENT_REJECTED
block|,
name|RDMA_CM_EVENT_ESTABLISHED
block|,
name|RDMA_CM_EVENT_DISCONNECTED
block|,
name|RDMA_CM_EVENT_DEVICE_REMOVAL
block|,
name|RDMA_CM_EVENT_MULTICAST_JOIN
block|,
name|RDMA_CM_EVENT_MULTICAST_ERROR
block|,
name|RDMA_CM_EVENT_ADDR_CHANGE
block|,
name|RDMA_CM_EVENT_TIMEWAIT_EXIT
block|}
enum|;
end_enum

begin_function_decl
specifier|const
name|char
modifier|*
name|__attribute_const__
name|rdma_event_msg
parameter_list|(
name|enum
name|rdma_cm_event_type
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|rdma_port_space
block|{
name|RDMA_PS_SDP
init|=
literal|0x0001
block|,
name|RDMA_PS_IPOIB
init|=
literal|0x0002
block|,
name|RDMA_PS_IB
init|=
literal|0x013F
block|,
name|RDMA_PS_TCP
init|=
literal|0x0106
block|,
name|RDMA_PS_UDP
init|=
literal|0x0111
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|RDMA_IB_IP_PS_MASK
value|0xFFFFFFFFFFFF0000ULL
end_define

begin_define
define|#
directive|define
name|RDMA_IB_IP_PS_TCP
value|0x0000000001060000ULL
end_define

begin_define
define|#
directive|define
name|RDMA_IB_IP_PS_UDP
value|0x0000000001110000ULL
end_define

begin_define
define|#
directive|define
name|RDMA_IB_IP_PS_IB
value|0x00000000013F0000ULL
end_define

begin_struct
struct|struct
name|rdma_addr
block|{
name|struct
name|sockaddr_storage
name|src_addr
decl_stmt|;
name|struct
name|sockaddr_storage
name|dst_addr
decl_stmt|;
name|struct
name|rdma_dev_addr
name|dev_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rdma_route
block|{
name|struct
name|rdma_addr
name|addr
decl_stmt|;
name|struct
name|ib_sa_path_rec
modifier|*
name|path_rec
decl_stmt|;
name|int
name|num_paths
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rdma_conn_param
block|{
specifier|const
name|void
modifier|*
name|private_data
decl_stmt|;
name|u8
name|private_data_len
decl_stmt|;
name|u8
name|responder_resources
decl_stmt|;
name|u8
name|initiator_depth
decl_stmt|;
name|u8
name|flow_control
decl_stmt|;
name|u8
name|retry_count
decl_stmt|;
comment|/* ignored when accepting */
name|u8
name|rnr_retry_count
decl_stmt|;
comment|/* Fields below ignored if a QP is created on the rdma_cm_id. */
name|u8
name|srq
decl_stmt|;
name|u32
name|qp_num
decl_stmt|;
name|u32
name|qkey
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rdma_ud_param
block|{
specifier|const
name|void
modifier|*
name|private_data
decl_stmt|;
name|u8
name|private_data_len
decl_stmt|;
name|struct
name|ib_ah_attr
name|ah_attr
decl_stmt|;
name|u32
name|qp_num
decl_stmt|;
name|u32
name|qkey
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rdma_cm_event
block|{
name|enum
name|rdma_cm_event_type
name|event
decl_stmt|;
name|int
name|status
decl_stmt|;
union|union
block|{
name|struct
name|rdma_conn_param
name|conn
decl_stmt|;
name|struct
name|rdma_ud_param
name|ud
decl_stmt|;
block|}
name|param
union|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|rdma_cm_state
block|{
name|RDMA_CM_IDLE
block|,
name|RDMA_CM_ADDR_QUERY
block|,
name|RDMA_CM_ADDR_RESOLVED
block|,
name|RDMA_CM_ROUTE_QUERY
block|,
name|RDMA_CM_ROUTE_RESOLVED
block|,
name|RDMA_CM_CONNECT
block|,
name|RDMA_CM_DISCONNECT
block|,
name|RDMA_CM_ADDR_BOUND
block|,
name|RDMA_CM_LISTEN
block|,
name|RDMA_CM_DEVICE_REMOVAL
block|,
name|RDMA_CM_DESTROYING
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|rdma_cm_id
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * rdma_cm_event_handler - Callback used to report user events.  *  * Notes: Users may not call rdma_destroy_id from this callback to destroy  *   the passed in id, or a corresponding listen id.  Returning a  *   non-zero value from the callback will destroy the passed in id.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|rdma_cm_event_handler
function_decl|)
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|struct
name|rdma_cm_event
modifier|*
name|event
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|rdma_cm_id
block|{
name|struct
name|ib_device
modifier|*
name|device
decl_stmt|;
name|void
modifier|*
name|context
decl_stmt|;
name|struct
name|ib_qp
modifier|*
name|qp
decl_stmt|;
name|rdma_cm_event_handler
name|event_handler
decl_stmt|;
name|struct
name|rdma_route
name|route
decl_stmt|;
name|enum
name|rdma_port_space
name|ps
decl_stmt|;
name|enum
name|ib_qp_type
name|qp_type
decl_stmt|;
name|u8
name|port_num
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * rdma_create_id - Create an RDMA identifier.  *  * @net: The network namespace in which to create the new id.  * @event_handler: User callback invoked to report events associated with the  *   returned rdma_id.  * @context: User specified context associated with the id.  * @ps: RDMA port space.  * @qp_type: type of queue pair associated with the id.  *  * The id holds a reference on the network namespace until it is destroyed.  */
end_comment

begin_function_decl
name|struct
name|rdma_cm_id
modifier|*
name|rdma_create_id
parameter_list|(
name|struct
name|vnet
modifier|*
name|net
parameter_list|,
name|rdma_cm_event_handler
name|event_handler
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|enum
name|rdma_port_space
name|ps
parameter_list|,
name|enum
name|ib_qp_type
name|qp_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * rdma_destroy_id - Destroys an RDMA identifier.   *   * @id: RDMA identifier.   *   * Note: calling this function has the effect of canceling in-flight   * asynchronous operations associated with the id.   */
end_comment

begin_function_decl
name|void
name|rdma_destroy_id
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_bind_addr - Bind an RDMA identifier to a source address and  *   associated RDMA device, if needed.  *  * @id: RDMA identifier.  * @addr: Local address information.  Wildcard values are permitted.  *  * This associates a source address with the RDMA identifier before calling  * rdma_listen.  If a specific local address is given, the RDMA identifier will  * be bound to a local RDMA device.  */
end_comment

begin_function_decl
name|int
name|rdma_bind_addr
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_resolve_addr - Resolve destination and optional source addresses  *   from IP addresses to an RDMA address.  If successful, the specified  *   rdma_cm_id will be bound to a local device.  *  * @id: RDMA identifier.  * @src_addr: Source address information.  This parameter may be NULL.  * @dst_addr: Destination address information.  * @timeout_ms: Time to wait for resolution to complete.  */
end_comment

begin_function_decl
name|int
name|rdma_resolve_addr
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|src_addr
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|dst_addr
parameter_list|,
name|int
name|timeout_ms
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_resolve_route - Resolve the RDMA address bound to the RDMA identifier  *   into route information needed to establish a connection.  *  * This is called on the client side of a connection.  * Users must have first called rdma_resolve_addr to resolve a dst_addr  * into an RDMA address before calling this routine.  */
end_comment

begin_function_decl
name|int
name|rdma_resolve_route
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|int
name|timeout_ms
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_create_qp - Allocate a QP and associate it with the specified RDMA  * identifier.  *  * QPs allocated to an rdma_cm_id will automatically be transitioned by the CMA  * through their states.  */
end_comment

begin_function_decl
name|int
name|rdma_create_qp
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|struct
name|ib_pd
modifier|*
name|pd
parameter_list|,
name|struct
name|ib_qp_init_attr
modifier|*
name|qp_init_attr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_destroy_qp - Deallocate the QP associated with the specified RDMA  * identifier.  *  * Users must destroy any QP associated with an RDMA identifier before  * destroying the RDMA ID.  */
end_comment

begin_function_decl
name|void
name|rdma_destroy_qp
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_init_qp_attr - Initializes the QP attributes for use in transitioning  *   to a specified QP state.  * @id: Communication identifier associated with the QP attributes to  *   initialize.  * @qp_attr: On input, specifies the desired QP state.  On output, the  *   mandatory and desired optional attributes will be set in order to  *   modify the QP to the specified state.  * @qp_attr_mask: The QP attribute mask that may be used to transition the  *   QP to the specified state.  *  * Users must set the @qp_attr->qp_state to the desired QP state.  This call  * will set all required attributes for the given transition, along with  * known optional attributes.  Users may override the attributes returned from  * this call before calling ib_modify_qp.  *  * Users that wish to have their QP automatically transitioned through its  * states can associate a QP with the rdma_cm_id by calling rdma_create_qp().  */
end_comment

begin_function_decl
name|int
name|rdma_init_qp_attr
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
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

begin_comment
comment|/**  * rdma_connect - Initiate an active connection request.  * @id: Connection identifier to connect.  * @conn_param: Connection information used for connected QPs.  *  * Users must have resolved a route for the rdma_cm_id to connect with  * by having called rdma_resolve_route before calling this routine.  *  * This call will either connect to a remote QP or obtain remote QP  * information for unconnected rdma_cm_id's.  The actual operation is  * based on the rdma_cm_id's port space.  */
end_comment

begin_function_decl
name|int
name|rdma_connect
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|struct
name|rdma_conn_param
modifier|*
name|conn_param
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_listen - This function is called by the passive side to  *   listen for incoming connection requests.  *  * Users must have bound the rdma_cm_id to a local address by calling  * rdma_bind_addr before calling this routine.  */
end_comment

begin_function_decl
name|int
name|rdma_listen
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|int
name|backlog
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_accept - Called to accept a connection request or response.  * @id: Connection identifier associated with the request.  * @conn_param: Information needed to establish the connection.  This must be  *   provided if accepting a connection request.  If accepting a connection  *   response, this parameter must be NULL.  *  * Typically, this routine is only called by the listener to accept a connection  * request.  It must also be called on the active side of a connection if the  * user is performing their own QP transitions.  *  * In the case of error, a reject message is sent to the remote side and the  * state of the qp associated with the id is modified to error, such that any  * previously posted receive buffers would be flushed.  */
end_comment

begin_function_decl
name|int
name|rdma_accept
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|struct
name|rdma_conn_param
modifier|*
name|conn_param
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_notify - Notifies the RDMA CM of an asynchronous event that has  * occurred on the connection.  * @id: Connection identifier to transition to established.  * @event: Asynchronous event.  *  * This routine should be invoked by users to notify the CM of relevant  * communication events.  Events that should be reported to the CM and  * when to report them are:  *  * IB_EVENT_COMM_EST - Used when a message is received on a connected  *    QP before an RTU has been received.  */
end_comment

begin_function_decl
name|int
name|rdma_notify
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|enum
name|ib_event_type
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_reject - Called to reject a connection request or response.  */
end_comment

begin_function_decl
name|int
name|rdma_reject
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
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
comment|/**  * rdma_disconnect - This function disconnects the associated QP and  *   transitions it into the error state.  */
end_comment

begin_function_decl
name|int
name|rdma_disconnect
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_join_multicast - Join the multicast group specified by the given  *   address.  * @id: Communication identifier associated with the request.  * @addr: Multicast address identifying the group to join.  * @join_state: Multicast JoinState bitmap requested by port.  *		Bitmap is based on IB_SA_MCMEMBER_REC_JOIN_STATE bits.  * @context: User-defined context associated with the join request, returned  * to the user through the private_data pointer in multicast events.  */
end_comment

begin_function_decl
name|int
name|rdma_join_multicast
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|u8
name|join_state
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_leave_multicast - Leave the multicast group specified by the given  *   address.  */
end_comment

begin_function_decl
name|void
name|rdma_leave_multicast
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_set_service_type - Set the type of service associated with a  *   connection identifier.  * @id: Communication identifier to associated with service type.  * @tos: Type of service.  *  * The type of service is interpretted as a differentiated service  * field (RFC 2474).  The service type should be specified before  * performing route resolution, as existing communication on the  * connection identifier may be unaffected.  The type of service  * requested may not be supported by the network to all destinations.  */
end_comment

begin_function_decl
name|void
name|rdma_set_service_type
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|int
name|tos
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_set_reuseaddr - Allow the reuse of local addresses when binding  *    the rdma_cm_id.  * @id: Communication identifier to configure.  * @reuse: Value indicating if the bound address is reusable.  *  * Reuse must be set before an address is bound to the id.  */
end_comment

begin_function_decl
name|int
name|rdma_set_reuseaddr
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|int
name|reuse
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_set_afonly - Specify that listens are restricted to the  *    bound address family only.  * @id: Communication identifer to configure.  * @afonly: Value indicating if listens are restricted.  *  * Must be set before identifier is in the listening state.  */
end_comment

begin_function_decl
name|int
name|rdma_set_afonly
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|int
name|afonly
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rdma_get_service_id - Return the IB service ID for a specified address.  * @id: Communication identifier associated with the address.  * @addr: Address for the service ID.  */
end_comment

begin_function_decl
name|__be64
name|rdma_get_service_id
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RDMA_CM_H */
end_comment

end_unit

