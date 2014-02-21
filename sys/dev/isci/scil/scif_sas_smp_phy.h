begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIF_SAS_SMP_PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIF_SAS_SMP_PHY_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the protected interface structures, constants,  *        and methods for the SCIF_SAS_SMP_PHY object.  */
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
file|<dev/isci/scil/scif_sas_remote_device.h>
include|#
directive|include
file|<dev/isci/scil/sci_fast_list.h>
struct_decl|struct
name|SCIF_SAS_CONTROLLER
struct_decl|;
struct_decl|struct
name|SCIF_SAS_SMP_PHY
struct_decl|;
struct_decl|struct
name|SCIF_SAS_REMOTE_DEVICE
struct_decl|;
comment|/**  * @struct SCIF_SAS_SMP_PHY  *  * @brief This structure stores data for a smp phy of a smp device (expander).  */
typedef|typedef
struct|struct
name|SCIF_SAS_SMP_PHY
block|{
comment|/**     * A smp phy can either connect to a end device or another smp phy,     * This two conditions are mutual exclusive.     */
union|union
block|{
comment|/**        * The attached smp phy. This field has valid meaning when        * attached_device_type is expander.        */
name|struct
name|SCIF_SAS_SMP_PHY
modifier|*
name|attached_phy
decl_stmt|;
comment|/**        * The attached end device. This field has valid meaning when        * attached_device_type is end_device.        */
name|struct
name|SCIF_SAS_REMOTE_DEVICE
modifier|*
name|end_device
decl_stmt|;
block|}
name|u
union|;
comment|/**     * This field records the owning expander device this smp phy belongs to.     */
name|struct
name|SCIF_SAS_REMOTE_DEVICE
modifier|*
name|owning_device
decl_stmt|;
comment|/**     * The list element of this smp phy for the smp phy list of the ownig expander.     */
name|SCI_FAST_LIST_ELEMENT_T
name|list_element
decl_stmt|;
comment|/**     * This field records the attached sas address, retrieved from a DISCOVER     * response. Zero value is valid.     */
name|SCI_SAS_ADDRESS_T
name|attached_sas_address
decl_stmt|;
comment|/**     * This field records the attached device type, retrieved from a DISCOVER     * response.     */
name|U8
name|attached_device_type
decl_stmt|;
comment|/**     * This field records the routing attribute, retrieved from a DISCOVER     * response.     */
name|U8
name|routing_attribute
decl_stmt|;
comment|/**     * This field records the phy identifier of this smp phy, retrieved from a     * DISCOVER response.     */
name|U8
name|phy_identifier
decl_stmt|;
comment|/**     * this field stores the last route index for previous round of config     * route table activity on a smp phy within one DISCOVER process.     */
name|U16
name|config_route_table_index_anchor
decl_stmt|;
block|}
name|SCIF_SAS_SMP_PHY_T
typedef|;
name|void
name|scif_sas_smp_phy_construct
parameter_list|(
name|SCIF_SAS_SMP_PHY_T
modifier|*
name|this_smp_phy
parameter_list|,
name|struct
name|SCIF_SAS_REMOTE_DEVICE
modifier|*
name|owning_device
parameter_list|,
name|U8
name|expander_phy_id
parameter_list|)
function_decl|;
name|void
name|scif_sas_smp_phy_destruct
parameter_list|(
name|SCIF_SAS_SMP_PHY_T
modifier|*
name|this_smp_phy
parameter_list|)
function_decl|;
name|void
name|scif_sas_smp_phy_save_information
parameter_list|(
name|SCIF_SAS_SMP_PHY_T
modifier|*
name|this_smp_phy
parameter_list|,
name|struct
name|SCIF_SAS_REMOTE_DEVICE
modifier|*
name|attached_device
parameter_list|,
name|SMP_RESPONSE_DISCOVER_T
modifier|*
name|discover_response
parameter_list|)
function_decl|;
name|SCI_STATUS
name|scif_sas_smp_phy_set_attached_phy
parameter_list|(
name|SCIF_SAS_SMP_PHY_T
modifier|*
name|this_smp_phy
parameter_list|,
name|U8
name|attached_phy_identifier
parameter_list|,
name|struct
name|SCIF_SAS_REMOTE_DEVICE
modifier|*
name|attached_remote_device
parameter_list|)
function_decl|;
name|SCI_STATUS
name|scif_sas_smp_phy_verify_routing_attribute
parameter_list|(
name|SCIF_SAS_SMP_PHY_T
modifier|*
name|this_smp_phy
parameter_list|,
name|SCIF_SAS_SMP_PHY_T
modifier|*
name|attached_smp_phy
parameter_list|)
function_decl|;
name|SCIF_SAS_SMP_PHY_T
modifier|*
name|scif_sas_smp_phy_find_next_phy_in_wide_port
parameter_list|(
name|SCIF_SAS_SMP_PHY_T
modifier|*
name|this_smp_phy
parameter_list|)
function_decl|;
name|SCIF_SAS_SMP_PHY_T
modifier|*
name|scif_sas_smp_phy_find_middle_phy_in_wide_port
parameter_list|(
name|SCIF_SAS_SMP_PHY_T
modifier|*
name|this_smp_phy
parameter_list|)
function_decl|;
name|SCIF_SAS_SMP_PHY_T
modifier|*
name|scif_sas_smp_phy_find_highest_phy_in_wide_port
parameter_list|(
name|SCIF_SAS_SMP_PHY_T
modifier|*
name|this_smp_phy
parameter_list|)
function_decl|;
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
comment|// _SCIF_SAS_SMP_PHY_H_
end_comment

end_unit

