begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 Silicon Graphics International Corp.  * Copyright (c) 2011 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl_ha.h#1 $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTL_HA_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTL_HA_H_
end_define

begin_comment
comment|/*  * CTL High Availability Modes:  *  * CTL_HA_MODE_ACT_STBY:  One side is in Active state and processing commands,  *			  the other side is in Standby state, returning errors.  * CTL_HA_MODE_SER_ONLY:  Commands are serialized to the other side.  Write  *			  mirroring and read re-direction are assumed to  * 			  happen in the back end.  * CTL_HA_MODE_XFER:	  Commands are serialized and data is transferred  *			  for write mirroring and read re-direction.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_HA_MODE_ACT_STBY
block|,
name|CTL_HA_MODE_SER_ONLY
block|,
name|CTL_HA_MODE_XFER
block|}
name|ctl_ha_mode
typedef|;
end_typedef

begin_comment
comment|/*  * This is a stubbed out High Availability interface.  It assumes two nodes  * staying in sync.  *  * The reason this interface is here, and stubbed out, is that CTL was  * originally written with support for Copan's (now SGI) high availability  * framework.  That framework was not released by SGI, and would not have  * been generally applicable to FreeBSD anyway.  *  * The idea here is to show the kind of API that would need to be in place  * in a HA framework to work with CTL's HA hooks.  This API is very close  * to the Copan/SGI API, so that the code using it could stay in place  * as-is.  *  * So, in summary, this is a shell without real substance, and much more  * work would be needed to actually make HA work.  The implementation  * inside CTL will also need to change to fit the eventual implementation.  * The additional pieces we would need are:  *  *  - HA "Supervisor" framework that can startup the components of the  *    system, and initiate failover (i.e. active/active to single mode)  *    and failback (single to active/active mode) state transitions.  *    This framework would be able to recognize when an event happens  *    that requires it to initiate state transitions in the components it  *    manages.  *  *  - HA communication framework.  This framework should have the following  *    features:  *	- Separate channels for separate system components.  The CTL  *	  instance on one node should communicate with the CTL instance  *	  on another node.  *	- Short message passing.  These messages would be fixed length, so  *	  they could be preallocated and easily passed between the nodes.  *	  i.e. conceptually like an ethernet packet.  *	- DMA/large buffer capability.  This would require some negotiation  *	  with the other node to define the destination.  It could  *	  allow for "push" (i.e. initiated by the requesting node) DMA or  * 	  "pull" (i.e. initiated by the target controller) DMA or both.  *	- Communication channel status change notification.  *  - HA capability in other portions of the storage stack.  Having two CTL  *    instances communicate is just one part of an overall HA solution.  *    State needs to be synchronized at multiple levels of the system in  *    order for failover to actually work.  For instance, if CTL is using a  *    file on a ZFS filesystem as its backing store, the ZFS array state  *    should be synchronized with the other node, so that the other node  *    can immediately take over if the node that is primary for a particular  *    array fails.  */
end_comment

begin_comment
comment|/*  * Communication channel IDs for various system components.  This is to  * make sure one CTL instance talks with another, one ZFS instance talks  * with another, etc.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_HA_CHAN_NONE
block|,
name|CTL_HA_CHAN_CTL
block|,
name|CTL_HA_CHAN_ZFS
block|,
name|CTL_HA_CHAN_MAX
block|}
name|ctl_ha_channel
typedef|;
end_typedef

begin_comment
comment|/*  * HA communication event notification.  These are events generated by the  * HA communication subsystem.  *  * CTL_HA_EVT_MSG_RECV:		Message received by the other node.  * CTL_HA_EVT_MSG_SENT:		Message sent to the other node.  * CTL_HA_EVT_DISCONNECT:	Communication channel disconnected.  * CTL_HA_EVT_DMA_SENT:		DMA successfully sent to other node (push).  * CTL_HA_EVT_DMA_RECEIVED:	DMA successfully received by other node (pull).  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_HA_EVT_NONE
block|,
name|CTL_HA_EVT_MSG_RECV
block|,
name|CTL_HA_EVT_MSG_SENT
block|,
name|CTL_HA_EVT_DISCONNECT
block|,
name|CTL_HA_EVT_DMA_SENT
block|,
name|CTL_HA_EVT_DMA_RECEIVED
block|,
name|CTL_HA_EVT_MAX
block|}
name|ctl_ha_event
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_HA_STATUS_WAIT
block|,
name|CTL_HA_STATUS_SUCCESS
block|,
name|CTL_HA_STATUS_ERROR
block|,
name|CTL_HA_STATUS_INVALID
block|,
name|CTL_HA_STATUS_DISCONNECT
block|,
name|CTL_HA_STATUS_BUSY
block|,
name|CTL_HA_STATUS_MAX
block|}
name|ctl_ha_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_HA_DATA_CTL
block|,
name|CTL_HA_DATA_ZFS
block|,
name|CTL_HA_DATA_MAX
block|}
name|ctl_ha_dtid
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_HA_DT_CMD_READ
block|,
name|CTL_HA_DT_CMD_WRITE
block|, }
name|ctl_ha_dt_cmd
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|ctl_ha_dt_req
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ctl_ha_dt_cb
function_decl|)
parameter_list|(
name|struct
name|ctl_ha_dt_req
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ctl_ha_dt_req
block|{
name|ctl_ha_dt_cmd
name|command
decl_stmt|;
name|void
modifier|*
name|context
decl_stmt|;
name|ctl_ha_dt_cb
name|callback
decl_stmt|;
name|ctl_ha_dtid
name|id
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
name|uint8_t
modifier|*
name|local
decl_stmt|;
name|uint8_t
modifier|*
name|remote
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ctl_evt_handler
function_decl|)
parameter_list|(
name|ctl_ha_channel
name|channel
parameter_list|,
name|ctl_ha_event
name|event
parameter_list|,
name|int
name|param
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|ctl_ha_register_evthandler
parameter_list|(
name|ctl_ha_channel
name|channel
parameter_list|,
name|ctl_evt_handler
name|handler
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|ctl_ha_status
name|ctl_ha_msg_create
parameter_list|(
name|ctl_ha_channel
name|channel
parameter_list|,
name|ctl_evt_handler
name|handler
parameter_list|)
block|{
return|return
operator|(
name|CTL_HA_STATUS_SUCCESS
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Receive a message of the specified size.  */
end_comment

begin_function
specifier|static
specifier|inline
name|ctl_ha_status
name|ctl_ha_msg_recv
parameter_list|(
name|ctl_ha_channel
name|channel
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|,
name|int
name|wait
parameter_list|)
block|{
return|return
operator|(
name|CTL_HA_STATUS_SUCCESS
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Send a message of the specified size.  */
end_comment

begin_function
specifier|static
specifier|inline
name|ctl_ha_status
name|ctl_ha_msg_send
parameter_list|(
name|ctl_ha_channel
name|channel
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|,
name|int
name|wait
parameter_list|)
block|{
return|return
operator|(
name|CTL_HA_STATUS_SUCCESS
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Allocate a data transfer request structure.  */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|ctl_ha_dt_req
modifier|*
name|ctl_dt_req_alloc
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Free a data transfer request structure.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ctl_dt_req_free
parameter_list|(
name|struct
name|ctl_ha_dt_req
modifier|*
name|req
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/*  * Issue a DMA request for a single buffer.  */
end_comment

begin_function
specifier|static
specifier|inline
name|ctl_ha_status
name|ctl_dt_single
parameter_list|(
name|struct
name|ctl_ha_dt_req
modifier|*
name|req
parameter_list|)
block|{
return|return
operator|(
name|CTL_HA_STATUS_WAIT
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * SINGLE:	   One node  * HA:		   Two nodes (Active/Active implied)  * SLAVE/MASTER:   The component can set these flags to indicate which side  *		   is in control.  It has no effect on the HA framework.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_HA_STATE_UNKNOWN
init|=
literal|0x00
block|,
name|CTL_HA_STATE_SINGLE
init|=
literal|0x01
block|,
name|CTL_HA_STATE_HA
init|=
literal|0x02
block|,
name|CTL_HA_STATE_MASK
init|=
literal|0x0F
block|,
name|CTL_HA_STATE_SLAVE
init|=
literal|0x10
block|,
name|CTL_HA_STATE_MASTER
init|=
literal|0x20
block|}
name|ctl_ha_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_HA_COMP_STATUS_OK
block|,
name|CTL_HA_COMP_STATUS_FAILED
block|,
name|CTL_HA_COMP_STATUS_ERROR
block|}
name|ctl_ha_comp_status
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|ctl_ha_component
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|ctl_ha_comp_status
function_decl|(
modifier|*
name|ctl_hacmp_init_t
function_decl|)
parameter_list|(
name|struct
name|ctl_ha_component
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|ctl_ha_comp_status
function_decl|(
modifier|*
name|ctl_hacmp_start_t
function_decl|)
parameter_list|(
name|struct
name|ctl_ha_component
modifier|*
parameter_list|,
name|ctl_ha_state
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ctl_ha_component
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|ctl_ha_state
name|state
decl_stmt|;
name|ctl_ha_comp_status
name|status
decl_stmt|;
name|ctl_hacmp_init_t
name|init
decl_stmt|;
name|ctl_hacmp_start_t
name|start
decl_stmt|;
name|ctl_hacmp_init_t
name|quiesce
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTL_HA_STATE_IS_SINGLE
parameter_list|(
name|state
parameter_list|)
value|((state& CTL_HA_STATE_MASK) == \ 					  CTL_HA_STATE_SINGLE)
end_define

begin_define
define|#
directive|define
name|CTL_HA_STATE_IS_HA
parameter_list|(
name|state
parameter_list|)
value|((state& CTL_HA_STATE_MASK) == \ 					  CTL_HA_STATE_HA)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CTL_HA_H_ */
end_comment

end_unit

