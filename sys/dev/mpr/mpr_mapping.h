begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2015 LSI Corp.  * Copyright (c) 2013-2016 Avago Technologies  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Avago Technologies (LSI) MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
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
comment|/**  * struct _map_phy_change - PHY entries received in Topology change list  * @physical_id: SAS address of the device attached with the associate PHY  * @device_info: bitfield provides detailed info about the device  * @dev_handle: device handle for the device pointed by this entry  * @slot: slot ID  * @is_processed: Flag to indicate whether this entry is processed or not  * @is_SATA_SSD: 1 if this is a SATA device AND an SSD, 0 otherwise  */
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
name|uint8_t
name|is_SATA_SSD
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct _map_port_change - PCIe Port entries received in PCIe Topology change  * list event  * @physical_id: WWID of the device attached to the associated port  * @device_info: bitfield provides detailed info about the device  * @MDTS: Maximum Data Transfer Size for the device  * @dev_handle: device handle for the device pointed by this entry  * @slot: slot ID  * @is_processed: Flag to indicate whether this entry is processed or not  */
end_comment

begin_struct
struct|struct
name|_map_port_change
block|{
name|uint64_t
name|physical_id
decl_stmt|;
name|uint32_t
name|device_info
decl_stmt|;
name|uint32_t
name|MDTS
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
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct _map_topology_change - SAS/SATA entries to be removed from mapping  * table  * @enc_handle: enclosure handle where this device is located  * @exp_handle: expander handle where this device is located  * @num_entries: number of entries in the SAS Topology Change List event  * @start_phy_num: PHY number of the first PHY in the event data  * @num_phys: number of PHYs in the expander where this device is located  * @exp_status: status for the expander where this device is located  * @phy_details: more details about each PHY in the event data  */
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

begin_comment
comment|/**  * struct _map_pcie_topology_change - PCIe entries to be removed from mapping  * table  * @enc_handle: enclosure handle where this device is located  * @switch_dev_handle:  PCIe switch device handle where this device is located  * @num_entries: number of entries in the PCIe Topology Change List event  * @start_port_num: port number of the first port in the event data  * @num_ports: number of ports in the PCIe switch device  * @switch_status: status for the PCIe switch where this device is located  * @port_details: more details about each Port in the event data  */
end_comment

begin_struct
struct|struct
name|_map_pcie_topology_change
block|{
name|uint16_t
name|enc_handle
decl_stmt|;
name|uint16_t
name|switch_dev_handle
decl_stmt|;
name|uint8_t
name|num_entries
decl_stmt|;
name|uint8_t
name|start_port_num
decl_stmt|;
name|uint8_t
name|num_ports
decl_stmt|;
name|uint8_t
name|switch_status
decl_stmt|;
name|struct
name|_map_port_change
modifier|*
name|port_details
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
parameter_list|,
name|u8
modifier|*
name|is_SATA_SSD
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

