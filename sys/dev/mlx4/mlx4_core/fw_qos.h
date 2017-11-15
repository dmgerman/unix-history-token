begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Topspin Communications.  All rights reserved.  * Copyright (c) 2005, 2006, 2007, 2008 Mellanox Technologies.  * All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MLX4_FW_QOS_H
end_ifndef

begin_define
define|#
directive|define
name|MLX4_FW_QOS_H
end_define

begin_include
include|#
directive|include
file|<dev/mlx4/cmd.h>
end_include

begin_include
include|#
directive|include
file|<dev/mlx4/device.h>
end_include

begin_define
define|#
directive|define
name|MLX4_NUM_UP
value|8
end_define

begin_define
define|#
directive|define
name|MLX4_NUM_TC
value|8
end_define

begin_comment
comment|/* Default supported priorities for VPP allocation */
end_comment

begin_define
define|#
directive|define
name|MLX4_DEFAULT_QOS_PRIO
value|(0)
end_define

begin_comment
comment|/* Derived from FW feature definition, 0 is the default vport fo all QPs */
end_comment

begin_define
define|#
directive|define
name|MLX4_VPP_DEFAULT_VPORT
value|(0)
end_define

begin_struct
struct|struct
name|mlx4_vport_qos_param
block|{
name|u32
name|bw_share
decl_stmt|;
name|u32
name|max_avg_bw
decl_stmt|;
name|u8
name|enable
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * mlx4_SET_PORT_PRIO2TC - This routine maps user priorities to traffic  * classes of a given port and device.  *  * @dev: mlx4_dev.  * @port: Physical port number.  * @prio2tc: Array of TC associated with each priorities.  *  * Returns 0 on success or a negative mlx4_core errno code.  **/
end_comment

begin_function_decl
name|int
name|mlx4_SET_PORT_PRIO2TC
parameter_list|(
name|struct
name|mlx4_dev
modifier|*
name|dev
parameter_list|,
name|u8
name|port
parameter_list|,
name|u8
modifier|*
name|prio2tc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * mlx4_SET_PORT_SCHEDULER - This routine configures the arbitration between  * traffic classes (ETS) and configured rate limit for traffic classes.  * tc_tx_bw, pg and ratelimit are arrays where each index represents a TC.  * The description for those parameters below refers to a single TC.  *  * @dev: mlx4_dev.  * @port: Physical port number.  * @tc_tx_bw: The percentage of the bandwidth allocated for traffic class  *  within a TC group. The sum of the bw_percentage of all the traffic  *  classes within a TC group must equal 100% for correct operation.  * @pg: The TC group the traffic class is associated with.  * @ratelimit: The maximal bandwidth allowed for the use by this traffic class.  *  * Returns 0 on success or a negative mlx4_core errno code.  **/
end_comment

begin_function_decl
name|int
name|mlx4_SET_PORT_SCHEDULER
parameter_list|(
name|struct
name|mlx4_dev
modifier|*
name|dev
parameter_list|,
name|u8
name|port
parameter_list|,
name|u8
modifier|*
name|tc_tx_bw
parameter_list|,
name|u8
modifier|*
name|pg
parameter_list|,
name|u16
modifier|*
name|ratelimit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * mlx4_ALLOCATE_VPP_get - Query port VPP availible resources and allocation.  * Before distribution of VPPs to priorities, only availible_vpp is returned.  * After initialization it returns the distribution of VPPs among priorities.  *  * @dev: mlx4_dev.  * @port: Physical port number.  * @availible_vpp: Pointer to variable where number of availible VPPs is stored  * @vpp_p_up: Distribution of VPPs to priorities is stored in this array  *  * Returns 0 on success or a negative mlx4_core errno code.  **/
end_comment

begin_function_decl
name|int
name|mlx4_ALLOCATE_VPP_get
parameter_list|(
name|struct
name|mlx4_dev
modifier|*
name|dev
parameter_list|,
name|u8
name|port
parameter_list|,
name|u16
modifier|*
name|availible_vpp
parameter_list|,
name|u8
modifier|*
name|vpp_p_up
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * mlx4_ALLOCATE_VPP_set - Distribution of VPPs among differnt priorities.  * The total number of VPPs assigned to all for a port must not exceed  * the value reported by availible_vpp in mlx4_ALLOCATE_VPP_get.  * VPP allocation is allowed only after the port type has been set,  * and while no QPs are open for this port.  *  * @dev: mlx4_dev.  * @port: Physical port number.  * @vpp_p_up: Allocation of VPPs to different priorities.  *  * Returns 0 on success or a negative mlx4_core errno code.  **/
end_comment

begin_function_decl
name|int
name|mlx4_ALLOCATE_VPP_set
parameter_list|(
name|struct
name|mlx4_dev
modifier|*
name|dev
parameter_list|,
name|u8
name|port
parameter_list|,
name|u8
modifier|*
name|vpp_p_up
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * mlx4_SET_VPORT_QOS_get - Query QoS proporties of a Vport.  * Each priority allowed for the Vport is assigned with a share of the BW,  * and a BW limitation. This commands query the current QoS values.  *  * @dev: mlx4_dev.  * @port: Physical port number.  * @vport: Vport id.  * @out_param: Array of mlx4_vport_qos_param that will contain the values.  *  * Returns 0 on success or a negative mlx4_core errno code.  **/
end_comment

begin_function_decl
name|int
name|mlx4_SET_VPORT_QOS_get
parameter_list|(
name|struct
name|mlx4_dev
modifier|*
name|dev
parameter_list|,
name|u8
name|port
parameter_list|,
name|u8
name|vport
parameter_list|,
name|struct
name|mlx4_vport_qos_param
modifier|*
name|out_param
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * mlx4_SET_VPORT_QOS_set - Set QoS proporties of a Vport.  * QoS parameters can be modified at any time, but must be initialized  * before any QP is associated with the VPort.  *  * @dev: mlx4_dev.  * @port: Physical port number.  * @vport: Vport id.  * @out_param: Array of mlx4_vport_qos_param which holds the requested values.  *  * Returns 0 on success or a negative mlx4_core errno code.  **/
end_comment

begin_function_decl
name|int
name|mlx4_SET_VPORT_QOS_set
parameter_list|(
name|struct
name|mlx4_dev
modifier|*
name|dev
parameter_list|,
name|u8
name|port
parameter_list|,
name|u8
name|vport
parameter_list|,
name|struct
name|mlx4_vport_qos_param
modifier|*
name|in_param
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MLX4_FW_QOS_H */
end_comment

end_unit

