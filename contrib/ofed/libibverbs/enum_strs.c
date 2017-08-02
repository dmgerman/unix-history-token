begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 Lawrence Livermore National Laboratory  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<infiniband/verbs.h>
end_include

begin_function
specifier|const
name|char
modifier|*
name|ibv_node_type_str
parameter_list|(
name|enum
name|ibv_node_type
name|node_type
parameter_list|)
block|{
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|node_type_str
index|[]
init|=
block|{
index|[
name|IBV_NODE_CA
index|]
operator|=
literal|"InfiniBand channel adapter"
block|,
index|[
name|IBV_NODE_SWITCH
index|]
operator|=
literal|"InfiniBand switch"
block|,
index|[
name|IBV_NODE_ROUTER
index|]
operator|=
literal|"InfiniBand router"
block|,
index|[
name|IBV_NODE_RNIC
index|]
operator|=
literal|"iWARP NIC"
block|,
index|[
name|IBV_NODE_USNIC
index|]
operator|=
literal|"usNIC"
block|,
index|[
name|IBV_NODE_USNIC_UDP
index|]
operator|=
literal|"usNIC UDP"
block|, 	}
decl_stmt|;
if|if
condition|(
name|node_type
operator|<
name|IBV_NODE_CA
operator|||
name|node_type
operator|>
name|IBV_NODE_USNIC_UDP
condition|)
return|return
literal|"unknown"
return|;
return|return
name|node_type_str
index|[
name|node_type
index|]
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|ibv_port_state_str
parameter_list|(
name|enum
name|ibv_port_state
name|port_state
parameter_list|)
block|{
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|port_state_str
index|[]
init|=
block|{
index|[
name|IBV_PORT_NOP
index|]
operator|=
literal|"no state change (NOP)"
block|,
index|[
name|IBV_PORT_DOWN
index|]
operator|=
literal|"down"
block|,
index|[
name|IBV_PORT_INIT
index|]
operator|=
literal|"init"
block|,
index|[
name|IBV_PORT_ARMED
index|]
operator|=
literal|"armed"
block|,
index|[
name|IBV_PORT_ACTIVE
index|]
operator|=
literal|"active"
block|,
index|[
name|IBV_PORT_ACTIVE_DEFER
index|]
operator|=
literal|"active defer"
block|}
decl_stmt|;
if|if
condition|(
name|port_state
operator|<
name|IBV_PORT_NOP
operator|||
name|port_state
operator|>
name|IBV_PORT_ACTIVE_DEFER
condition|)
return|return
literal|"unknown"
return|;
return|return
name|port_state_str
index|[
name|port_state
index|]
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|ibv_event_type_str
parameter_list|(
name|enum
name|ibv_event_type
name|event
parameter_list|)
block|{
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|event_type_str
index|[]
init|=
block|{
index|[
name|IBV_EVENT_CQ_ERR
index|]
operator|=
literal|"CQ error"
block|,
index|[
name|IBV_EVENT_QP_FATAL
index|]
operator|=
literal|"local work queue catastrophic error"
block|,
index|[
name|IBV_EVENT_QP_REQ_ERR
index|]
operator|=
literal|"invalid request local work queue error"
block|,
index|[
name|IBV_EVENT_QP_ACCESS_ERR
index|]
operator|=
literal|"local access violation work queue error"
block|,
index|[
name|IBV_EVENT_COMM_EST
index|]
operator|=
literal|"communication established"
block|,
index|[
name|IBV_EVENT_SQ_DRAINED
index|]
operator|=
literal|"send queue drained"
block|,
index|[
name|IBV_EVENT_PATH_MIG
index|]
operator|=
literal|"path migrated"
block|,
index|[
name|IBV_EVENT_PATH_MIG_ERR
index|]
operator|=
literal|"path migration request error"
block|,
index|[
name|IBV_EVENT_DEVICE_FATAL
index|]
operator|=
literal|"local catastrophic error"
block|,
index|[
name|IBV_EVENT_PORT_ACTIVE
index|]
operator|=
literal|"port active"
block|,
index|[
name|IBV_EVENT_PORT_ERR
index|]
operator|=
literal|"port error"
block|,
index|[
name|IBV_EVENT_LID_CHANGE
index|]
operator|=
literal|"LID change"
block|,
index|[
name|IBV_EVENT_PKEY_CHANGE
index|]
operator|=
literal|"P_Key change"
block|,
index|[
name|IBV_EVENT_SM_CHANGE
index|]
operator|=
literal|"SM change"
block|,
index|[
name|IBV_EVENT_SRQ_ERR
index|]
operator|=
literal|"SRQ catastrophic error"
block|,
index|[
name|IBV_EVENT_SRQ_LIMIT_REACHED
index|]
operator|=
literal|"SRQ limit reached"
block|,
index|[
name|IBV_EVENT_QP_LAST_WQE_REACHED
index|]
operator|=
literal|"last WQE reached"
block|,
index|[
name|IBV_EVENT_CLIENT_REREGISTER
index|]
operator|=
literal|"client reregistration"
block|,
index|[
name|IBV_EVENT_GID_CHANGE
index|]
operator|=
literal|"GID table change"
block|}
decl_stmt|;
if|if
condition|(
name|event
operator|<
name|IBV_EVENT_CQ_ERR
operator|||
name|event
operator|>
name|IBV_EVENT_GID_CHANGE
condition|)
return|return
literal|"unknown"
return|;
return|return
name|event_type_str
index|[
name|event
index|]
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|ibv_wc_status_str
parameter_list|(
name|enum
name|ibv_wc_status
name|status
parameter_list|)
block|{
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|wc_status_str
index|[]
init|=
block|{
index|[
name|IBV_WC_SUCCESS
index|]
operator|=
literal|"success"
block|,
index|[
name|IBV_WC_LOC_LEN_ERR
index|]
operator|=
literal|"local length error"
block|,
index|[
name|IBV_WC_LOC_QP_OP_ERR
index|]
operator|=
literal|"local QP operation error"
block|,
index|[
name|IBV_WC_LOC_EEC_OP_ERR
index|]
operator|=
literal|"local EE context operation error"
block|,
index|[
name|IBV_WC_LOC_PROT_ERR
index|]
operator|=
literal|"local protection error"
block|,
index|[
name|IBV_WC_WR_FLUSH_ERR
index|]
operator|=
literal|"Work Request Flushed Error"
block|,
index|[
name|IBV_WC_MW_BIND_ERR
index|]
operator|=
literal|"memory management operation error"
block|,
index|[
name|IBV_WC_BAD_RESP_ERR
index|]
operator|=
literal|"bad response error"
block|,
index|[
name|IBV_WC_LOC_ACCESS_ERR
index|]
operator|=
literal|"local access error"
block|,
index|[
name|IBV_WC_REM_INV_REQ_ERR
index|]
operator|=
literal|"remote invalid request error"
block|,
index|[
name|IBV_WC_REM_ACCESS_ERR
index|]
operator|=
literal|"remote access error"
block|,
index|[
name|IBV_WC_REM_OP_ERR
index|]
operator|=
literal|"remote operation error"
block|,
index|[
name|IBV_WC_RETRY_EXC_ERR
index|]
operator|=
literal|"transport retry counter exceeded"
block|,
index|[
name|IBV_WC_RNR_RETRY_EXC_ERR
index|]
operator|=
literal|"RNR retry counter exceeded"
block|,
index|[
name|IBV_WC_LOC_RDD_VIOL_ERR
index|]
operator|=
literal|"local RDD violation error"
block|,
index|[
name|IBV_WC_REM_INV_RD_REQ_ERR
index|]
operator|=
literal|"remote invalid RD request"
block|,
index|[
name|IBV_WC_REM_ABORT_ERR
index|]
operator|=
literal|"aborted error"
block|,
index|[
name|IBV_WC_INV_EECN_ERR
index|]
operator|=
literal|"invalid EE context number"
block|,
index|[
name|IBV_WC_INV_EEC_STATE_ERR
index|]
operator|=
literal|"invalid EE context state"
block|,
index|[
name|IBV_WC_FATAL_ERR
index|]
operator|=
literal|"fatal error"
block|,
index|[
name|IBV_WC_RESP_TIMEOUT_ERR
index|]
operator|=
literal|"response timeout error"
block|,
index|[
name|IBV_WC_GENERAL_ERR
index|]
operator|=
literal|"general error"
block|}
decl_stmt|;
if|if
condition|(
name|status
operator|<
name|IBV_WC_SUCCESS
operator|||
name|status
operator|>
name|IBV_WC_GENERAL_ERR
condition|)
return|return
literal|"unknown"
return|;
return|return
name|wc_status_str
index|[
name|status
index|]
return|;
block|}
end_function

end_unit

