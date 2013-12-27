begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SCU_REMOTE_NODE_CONTEXT_HEADER__
end_ifndef

begin_define
define|#
directive|define
name|__SCU_REMOTE_NODE_CONTEXT_HEADER__
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the structures and constatns used by the SCU  * hardware to describe a remote node context.  */
end_comment

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
comment|// __cplusplus
include|#
directive|include
file|<dev/isci/scil/sci_types.h>
comment|/**  * @struct SSP_REMOTE_NODE_CONTEXT  *  * @brief This structure contains the SCU hardware definition for an SSP  *       remote node.  */
typedef|typedef
struct|struct
name|SSP_REMOTE_NODE_CONTEXT
block|{
comment|// WORD 0
comment|/**     * This field is the remote node index assigned for this remote node. All     * remote nodes must have a unique remote node index. The value of the remote     * node index can not exceed the maximum number of remote nodes reported in     * the SCU device context capacity register.     */
name|U32
name|remote_node_index
range|:
literal|12
decl_stmt|;
name|U32
name|reserved0_1
range|:
literal|4
decl_stmt|;
comment|/**     * This field tells the SCU hardware how many simultaneous connections that     * this remote node will support.     */
name|U32
name|remote_node_port_width
range|:
literal|4
decl_stmt|;
comment|/**     * This field tells the SCU hardware which logical port to associate with this     * remote node.     */
name|U32
name|logical_port_index
range|:
literal|3
decl_stmt|;
name|U32
name|reserved0_2
range|:
literal|5
decl_stmt|;
comment|/**     * This field will enable the I_T nexus loss timer for this remote node.     */
name|U32
name|nexus_loss_timer_enable
range|:
literal|1
decl_stmt|;
comment|/**     * This field is the for driver debug only and is not used.     */
name|U32
name|check_bit
range|:
literal|1
decl_stmt|;
comment|/**     * This field must be set to TRUE when the hardware DMAs the remote node     * context to the hardware SRAM.  When the remote node is being invalidated     * this field must be set to FALSE.     */
name|U32
name|is_valid
range|:
literal|1
decl_stmt|;
comment|/**     * This field must be set to TRUE.     */
name|U32
name|is_remote_node_context
range|:
literal|1
decl_stmt|;
comment|// WORD 1 - 2
comment|/**     * This is the low word of the remote device SAS Address     */
name|U32
name|remote_sas_address_lo
decl_stmt|;
comment|/**     * This field is the high word of the remote device SAS Address     */
name|U32
name|remote_sas_address_hi
decl_stmt|;
comment|// WORD 3
comment|/**     * This field reprensets the function number assigned to this remote device.     * This value must match the virtual function number that is being used to     * communicate to the device.     */
name|U32
name|function_number
range|:
literal|8
decl_stmt|;
name|U32
name|reserved3_1
range|:
literal|8
decl_stmt|;
comment|/**     * This field provides the driver a way to cheat on the arbitration wait time     * for this remote node.     */
name|U32
name|arbitration_wait_time
range|:
literal|16
decl_stmt|;
comment|// WORD 4
comment|/**     * This field tells the SCU hardware how long this device may occupy the     * connection before it must be closed.     */
name|U32
name|connection_occupancy_timeout
range|:
literal|16
decl_stmt|;
comment|/**     * This field tells the SCU hardware how long to maintain a connection when     * there are no frames being transmitted on the link.     */
name|U32
name|connection_inactivity_timeout
range|:
literal|16
decl_stmt|;
comment|// WORD  5
comment|/**     * This field allows the driver to cheat on the arbitration wait time for this     * remote node.     */
name|U32
name|initial_arbitration_wait_time
range|:
literal|16
decl_stmt|;
comment|/**     * This field is tells the hardware what to program for the connection rate in     * the open address frame.  See the SAS spec for valid values.     */
name|U32
name|oaf_connection_rate
range|:
literal|4
decl_stmt|;
comment|/**     * This field tells the SCU hardware what to program for the features in the     * open address frame.  See the SAS spec for valid values.     */
name|U32
name|oaf_features
range|:
literal|4
decl_stmt|;
comment|/**     * This field tells the SCU hardware what to use for the source zone group in     * the open address frame.  See the SAS spec for more details on zoning.     */
name|U32
name|oaf_source_zone_group
range|:
literal|8
decl_stmt|;
comment|// WORD 6
comment|/**     * This field tells the SCU hardware what to use as the more capibilities in     * the open address frame. See the SAS Spec for details.     */
name|U32
name|oaf_more_compatibility_features
decl_stmt|;
comment|// WORD 7
name|U32
name|reserved7
decl_stmt|;
block|}
name|SSP_REMOTE_NODE_CONTEXT_T
typedef|;
comment|/**  * @struct STP_REMOTE_NODE_CONTEXT  *  * @brief This structure contains the SCU hardware definition for a STP remote  *        node.  *  * @todo STP Targets are not yet supported so this definition is a placeholder  *       until we do support them.  */
typedef|typedef
struct|struct
name|STP_REMOTE_NODE_CONTEXT
block|{
comment|/**     * Placeholder data for the STP remote node.     */
name|U32
name|data
index|[
literal|8
index|]
decl_stmt|;
block|}
name|STP_REMOTE_NODE_CONTEXT_T
typedef|;
comment|/**  * @union SCU_REMOTE_NODE_CONTEXT  *  * @brief This union combines the SAS and SATA remote node definitions.  */
typedef|typedef
union|union
name|SCU_REMOTE_NODE_CONTEXT
block|{
comment|/**     * SSP Remote Node     */
name|SSP_REMOTE_NODE_CONTEXT_T
name|ssp
decl_stmt|;
comment|/**     * STP Remote Node     */
name|STP_REMOTE_NODE_CONTEXT_T
name|stp
decl_stmt|;
block|}
name|SCU_REMOTE_NODE_CONTEXT_T
typedef|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __SCU_REMOTE_NODE_CONTEXT_HEADER__
end_comment

end_unit

