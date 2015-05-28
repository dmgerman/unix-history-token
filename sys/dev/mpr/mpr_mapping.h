begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2014 LSI Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * LSI MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MPR_MAPPING_H
end_ifndef

begin_define
define|#
directive|define
name|_MPR_MAPPING_H
end_define

begin_comment
comment|/**  * struct _map_phy_change - PHY entries recieved in Topology change list  * @physical_id: SAS address of the device attached with the associate PHY  * @device_info: bitfield provides detailed info about the device  * @dev_handle: device handle for the device pointed by this entry  * @slot: slot ID  * @is_processed: Flag to indicate whether this entry is processed or not  */
end_comment

begin_struct
struct|struct
name|_map_phy_change
block|{
name|uint64_t
name|physical_id
decl_stmt|;
name|uint32_t
name|device_info
decl_stmt|;
name|uint16_t
name|dev_handle
decl_stmt|;
name|uint16_t
name|slot
decl_stmt|;
name|uint8_t
name|reason
decl_stmt|;
name|uint8_t
name|is_processed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct _map_topology_change - entries to be removed from mapping table  * @dpm_entry_num: index of this device in device persistent map table  * @dev_handle: device handle for the device pointed by this entry  */
end_comment

begin_struct
struct|struct
name|_map_topology_change
block|{
name|uint16_t
name|enc_handle
decl_stmt|;
name|uint16_t
name|exp_handle
decl_stmt|;
name|uint8_t
name|num_entries
decl_stmt|;
name|uint8_t
name|start_phy_num
decl_stmt|;
name|uint8_t
name|num_phys
decl_stmt|;
name|uint8_t
name|exp_status
decl_stmt|;
name|struct
name|_map_phy_change
modifier|*
name|phy_details
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|mprsas_get_sas_address_for_sata_disk
parameter_list|(
name|struct
name|mpr_softc
modifier|*
name|ioc
parameter_list|,
name|u64
modifier|*
name|sas_address
parameter_list|,
name|u16
name|handle
parameter_list|,
name|u32
name|device_info
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

