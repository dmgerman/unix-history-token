begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIC_SDS_PHY_REGISTERS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIC_SDS_PHY_REGISTERS_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the macros used by the phy object to read/write  *        to the SCU link layer registers.  */
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
file|<dev/isci/scil/scic_sds_controller.h>
comment|//*****************************************************************************
comment|//* SCU LINK LAYER REGISTER OPERATIONS
comment|//*****************************************************************************
comment|/**  * Macro to read the transport layer register associated with this phy  * object.  */
define|#
directive|define
name|scu_transport_layer_read
parameter_list|(
name|phy
parameter_list|,
name|reg
parameter_list|)
define|\
value|scu_register_read( \       scic_sds_phy_get_controller(phy), \       (phy)->transport_layer_registers->reg \    )
comment|/**  * Macro to write the transport layer register associated with this phy  * object.  */
define|#
directive|define
name|scu_transport_layer_write
parameter_list|(
name|phy
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_register_write( \       scic_sds_phy_get_controller(phy), \       (phy)->transport_layer_registers->reg, \       (value) \    )
comment|//****************************************************************************
comment|//* Transport Layer registers controlled by the phy object
comment|//****************************************************************************
comment|/**  * This macro reads the Transport layer control register  */
define|#
directive|define
name|SCU_TLCR_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_transport_layer_read(phy, control)
comment|/**  * This macro writes the Transport layer control register  */
define|#
directive|define
name|SCU_TLCR_WRITE
parameter_list|(
name|phy
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_transport_layer_write(phy, control, value)
comment|/**  * This macro reads the Transport layer address translation register  */
define|#
directive|define
name|SCU_TLADTR_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_transport_layer_read(phy, address_translation)
comment|/**  * This macro writes the Transport layer address translation register  */
define|#
directive|define
name|SCU_TLADTR_WRITE
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_transport_layer_write(phy, address_translation, value)
comment|/**  * This macro writes the STP Transport Layer Direct Attached RNi register.  */
define|#
directive|define
name|SCU_STPTLDARNI_WRITE
parameter_list|(
name|phy
parameter_list|,
name|index
parameter_list|)
define|\
value|scu_transport_layer_write(phy, stp_rni, index)
comment|/**  * This macro reads the STP Transport Layer Direct Attached RNi register.  */
define|#
directive|define
name|SCU_STPTLDARNI_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_transport_layer_read(phy, stp_rni)
comment|//*****************************************************************************
comment|//* SCU LINK LAYER REGISTER OPERATIONS
comment|//*****************************************************************************
comment|/**  * THis macro requests the SCU register write for the specified link layer  * register.  */
define|#
directive|define
name|scu_link_layer_register_read
parameter_list|(
name|phy
parameter_list|,
name|reg
parameter_list|)
define|\
value|scu_register_read( \       scic_sds_phy_get_controller(phy), \       (phy)->link_layer_registers->reg \    )
comment|/**  * This macro requests the SCU register read for the specified link layer  * register.  */
define|#
directive|define
name|scu_link_layer_register_write
parameter_list|(
name|phy
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_register_write( \       scic_sds_phy_get_controller(phy), \       (phy)->link_layer_registers->reg, \       (value) \    )
comment|//*****************************************************************************
comment|//* SCU LINK LAYER REGISTERS
comment|//*****************************************************************************
comment|/// This macro reads from the SAS Identify Frame PHY Identifier register
define|#
directive|define
name|SCU_SAS_TIPID_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, identify_frame_phy_id)
comment|/// This macro writes to the SAS Identify Frame PHY Identifier register
define|#
directive|define
name|SCU_SAS_TIPID_WRITE
parameter_list|(
name|phy
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_link_layer_register_write(phy, identify_frame_phy_id, value)
comment|/// This macro reads from the SAS Identification register
define|#
directive|define
name|SCU_SAS_TIID_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, transmit_identification)
comment|/// This macro writes to the SAS Identification register
define|#
directive|define
name|SCU_SAS_TIID_WRITE
parameter_list|(
name|phy
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_link_layer_register_write(phy, transmit_identification, value)
comment|/// This macro reads the SAS Device Name High register
define|#
directive|define
name|SCU_SAS_TIDNH_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, sas_device_name_high)
comment|/// This macro writes the SAS Device Name High register
define|#
directive|define
name|SCU_SAS_TIDNH_WRITE
parameter_list|(
name|phy
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_link_layer_register_write(phy, sas_device_name_high, value)
comment|/// This macro reads the SAS Device Name Low register
define|#
directive|define
name|SCU_SAS_TIDNL_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, sas_device_name_low)
comment|/// This macro writes the SAS Device Name Low register
define|#
directive|define
name|SCU_SAS_TIDNL_WRITE
parameter_list|(
name|phy
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_link_layer_register_write(phy, sas_device_name_low, value)
comment|/// This macro reads the Source SAS Address High register
define|#
directive|define
name|SCU_SAS_TISSAH_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, source_sas_address_high)
comment|/// This macro writes the Source SAS Address High register
define|#
directive|define
name|SCU_SAS_TISSAH_WRITE
parameter_list|(
name|phy
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_link_layer_register_write(phy, source_sas_address_high, value)
comment|/// This macro reads the Source SAS Address Low register
define|#
directive|define
name|SCU_SAS_TISSAL_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, source_sas_address_low)
comment|/// This macro writes the Source SAS Address Low register
define|#
directive|define
name|SCU_SAS_TISSAL_WRITE
parameter_list|(
name|phy
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_link_layer_register_write(phy, source_sas_address_low, value)
comment|/// This macro reads the PHY Configuration register
define|#
directive|define
name|SCU_SAS_PCFG_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, phy_configuration);
comment|/// This macro writes the PHY Configuration register
define|#
directive|define
name|SCU_SAS_PCFG_WRITE
parameter_list|(
name|phy
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_link_layer_register_write(phy, phy_configuration, value)
comment|/// This macro reads the PHY Enable Spinup register
define|#
directive|define
name|SCU_SAS_ENSPINUP_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, notify_enable_spinup_control)
comment|/// This macro writes the PHY Enable Spinup register
define|#
directive|define
name|SCU_SAS_ENSPINUP_WRITE
parameter_list|(
name|phy
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_link_layer_register_write(phy, notify_enable_spinup_control, value)
comment|/// This macro reads the CLKSM register
define|#
directive|define
name|SCU_SAS_CLKSM_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, clock_skew_management)
comment|/// This macro writes the CLKSM register
define|#
directive|define
name|SCU_SAS_CLKSM_WRITE
parameter_list|(
name|phy
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_link_layer_register_write(phy, clock_skew_management, value)
comment|/// This macro reads the PHY Capacity register
define|#
directive|define
name|SCU_SAS_PHYCAP_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, phy_capabilities)
comment|/// This macro writes the PHY Capacity register
define|#
directive|define
name|SCU_SAS_PHYCAP_WRITE
parameter_list|(
name|phy
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_link_layer_register_write(phy, phy_capabilities, value)
comment|/// This macro reads the Recieved PHY Capacity register
define|#
directive|define
name|SCU_SAS_RECPHYCAP_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, receive_phycap)
comment|/// This macro reads the link layer control register
define|#
directive|define
name|SCU_SAS_LLCTL_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, link_layer_control);
comment|/// This macro writes the link layer control register
define|#
directive|define
name|SCU_SAS_LLCTL_WRITE
parameter_list|(
name|phy
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_link_layer_register_write(phy, link_layer_control, value);
comment|/// This macro reads the link layer status register
define|#
directive|define
name|SCU_SAS_LLSTA_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, link_layer_status);
define|#
directive|define
name|SCU_SAS_ECENCR_READ
parameter_list|(
name|phy
parameter_list|)
define|\
value|scu_link_layer_register_read(phy, error_counter_event_notification_control)
define|#
directive|define
name|SCU_SAS_ECENCR_WRITE
parameter_list|(
name|phy
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_link_layer_register_write(phy, error_counter_event_notification_control, value)
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
comment|// _SCIC_SDS_PHY_REGISTERS_H_
end_comment

end_unit

