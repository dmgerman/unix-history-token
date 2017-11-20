begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright(c) 2002-2011 Exar Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification are permitted provided the following conditions are met:  *  *    1. Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *  *    3. Neither the name of the Exar Corporation nor the names of its  *       contributors may be used to endorse or promote products derived from  *       this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VXGE_HAL_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_REGS_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|/* Using this strcture to calculate offsets */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_pci_config_le_t
block|{
name|u16
name|vendor_id
decl_stmt|;
comment|/* 0x00 */
name|u16
name|device_id
decl_stmt|;
comment|/* 0x02 */
name|u16
name|command
decl_stmt|;
comment|/* 0x04 */
name|u16
name|status
decl_stmt|;
comment|/* 0x06 */
name|u8
name|revision
decl_stmt|;
comment|/* 0x08 */
name|u8
name|pciClass
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x09 */
name|u8
name|cache_line_size
decl_stmt|;
comment|/* 0x0c */
name|u8
name|latency_timer
decl_stmt|;
comment|/* 0x0d */
name|u8
name|header_type
decl_stmt|;
comment|/* 0x0e */
name|u8
name|bist
decl_stmt|;
comment|/* 0x0f */
name|u32
name|base_addr0_lo
decl_stmt|;
comment|/* 0x10 */
name|u32
name|base_addr0_hi
decl_stmt|;
comment|/* 0x14 */
name|u32
name|base_addr1_lo
decl_stmt|;
comment|/* 0x18 */
name|u32
name|base_addr1_hi
decl_stmt|;
comment|/* 0x1C */
name|u32
name|base_addr2_lo
decl_stmt|;
comment|/* 0x20 */
name|u32
name|base_addr2_hi
decl_stmt|;
comment|/* 0x24 */
name|u32
name|cardbus_cis_pointer
decl_stmt|;
comment|/* 0x28 */
name|u16
name|subsystem_vendor_id
decl_stmt|;
comment|/* 0x2c */
name|u16
name|subsystem_id
decl_stmt|;
comment|/* 0x2e */
name|u32
name|rom_base
decl_stmt|;
comment|/* 0x30 */
name|u8
name|capabilities_pointer
decl_stmt|;
comment|/* 0x34 */
name|u8
name|rsvd_35
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x35 */
name|u32
name|rsvd_38
decl_stmt|;
comment|/* 0x38 */
name|u8
name|interrupt_line
decl_stmt|;
comment|/* 0x3c */
name|u8
name|interrupt_pin
decl_stmt|;
comment|/* 0x3d */
name|u8
name|min_grant
decl_stmt|;
comment|/* 0x3e */
name|u8
name|max_latency
decl_stmt|;
comment|/* 0x3f */
name|u8
name|rsvd_b1
index|[
name|VXGE_HAL_PCI_CONFIG_SPACE_SIZE
operator|-
literal|0x40
index|]
decl_stmt|;
block|}
name|vxge_hal_pci_config_le_t
typedef|;
end_typedef

begin_comment
comment|/* 0x100 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_pci_config_t
block|{
if|#
directive|if
name|defined
argument_list|(
name|VXGE_OS_HOST_BIG_ENDIAN
argument_list|)
name|u16
name|device_id
decl_stmt|;
comment|/* 0x02 */
name|u16
name|vendor_id
decl_stmt|;
comment|/* 0x00 */
name|u16
name|status
decl_stmt|;
comment|/* 0x06 */
name|u16
name|command
decl_stmt|;
comment|/* 0x04 */
name|u8
name|pciClass
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x09 */
name|u8
name|revision
decl_stmt|;
comment|/* 0x08 */
name|u8
name|bist
decl_stmt|;
comment|/* 0x0f */
name|u8
name|header_type
decl_stmt|;
comment|/* 0x0e */
name|u8
name|latency_timer
decl_stmt|;
comment|/* 0x0d */
name|u8
name|cache_line_size
decl_stmt|;
comment|/* 0x0c */
name|u32
name|base_addr0_lo
decl_stmt|;
comment|/* 0x10 */
name|u32
name|base_addr0_hi
decl_stmt|;
comment|/* 0x14 */
name|u32
name|base_addr1_lo
decl_stmt|;
comment|/* 0x18 */
name|u32
name|base_addr1_hi
decl_stmt|;
comment|/* 0x1C */
name|u32
name|not_Implemented1
decl_stmt|;
comment|/* 0x20 */
name|u32
name|not_Implemented2
decl_stmt|;
comment|/* 0x24 */
name|u32
name|cardbus_cis_pointer
decl_stmt|;
comment|/* 0x28 */
name|u16
name|subsystem_id
decl_stmt|;
comment|/* 0x2e */
name|u16
name|subsystem_vendor_id
decl_stmt|;
comment|/* 0x2c */
name|u32
name|rom_base
decl_stmt|;
comment|/* 0x30 */
name|u8
name|rsvd_35
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x35 */
name|u8
name|capabilities_pointer
decl_stmt|;
comment|/* 0x34 */
name|u32
name|rsvd_38
decl_stmt|;
comment|/* 0x38 */
name|u8
name|max_latency
decl_stmt|;
comment|/* 0x3f */
name|u8
name|min_grant
decl_stmt|;
comment|/* 0x3e */
name|u8
name|interrupt_pin
decl_stmt|;
comment|/* 0x3d */
name|u8
name|interrupt_line
decl_stmt|;
comment|/* 0x3c */
else|#
directive|else
name|u16
name|vendor_id
decl_stmt|;
comment|/* 0x00 */
name|u16
name|device_id
decl_stmt|;
comment|/* 0x02 */
name|u16
name|command
decl_stmt|;
comment|/* 0x04 */
name|u16
name|status
decl_stmt|;
comment|/* 0x06 */
name|u8
name|revision
decl_stmt|;
comment|/* 0x08 */
name|u8
name|pciClass
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x09 */
name|u8
name|cache_line_size
decl_stmt|;
comment|/* 0x0c */
name|u8
name|latency_timer
decl_stmt|;
comment|/* 0x0d */
name|u8
name|header_type
decl_stmt|;
comment|/* 0x0e */
name|u8
name|bist
decl_stmt|;
comment|/* 0x0f */
name|u32
name|base_addr0_lo
decl_stmt|;
comment|/* 0x10 */
name|u32
name|base_addr0_hi
decl_stmt|;
comment|/* 0x14 */
name|u32
name|base_addr1_lo
decl_stmt|;
comment|/* 0x18 */
name|u32
name|base_addr1_hi
decl_stmt|;
comment|/* 0x1C */
name|u32
name|not_Implemented1
decl_stmt|;
comment|/* 0x20 */
name|u32
name|not_Implemented2
decl_stmt|;
comment|/* 0x24 */
name|u32
name|cardbus_cis_pointer
decl_stmt|;
comment|/* 0x28 */
name|u16
name|subsystem_vendor_id
decl_stmt|;
comment|/* 0x2c */
name|u16
name|subsystem_id
decl_stmt|;
comment|/* 0x2e */
name|u32
name|rom_base
decl_stmt|;
comment|/* 0x30 */
name|u8
name|capabilities_pointer
decl_stmt|;
comment|/* 0x34 */
name|u8
name|rsvd_35
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x35 */
name|u32
name|rsvd_38
decl_stmt|;
comment|/* 0x38 */
name|u8
name|interrupt_line
decl_stmt|;
comment|/* 0x3c */
name|u8
name|interrupt_pin
decl_stmt|;
comment|/* 0x3d */
name|u8
name|min_grant
decl_stmt|;
comment|/* 0x3e */
name|u8
name|max_latency
decl_stmt|;
comment|/* 0x3f */
endif|#
directive|endif
name|u8
name|rsvd_b1
index|[
name|VXGE_HAL_PCI_CONFIG_SPACE_SIZE
operator|-
literal|0x40
index|]
decl_stmt|;
block|}
name|vxge_hal_pci_config_t
typedef|;
end_typedef

begin_comment
comment|/* 0x100 */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_EEPROM_SIZE
value|(0x01<< 11)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VXGE_OS_HOST_BIG_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID
parameter_list|(
name|ptr
parameter_list|)
value|*((ptr) + 3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_NEXT
parameter_list|(
name|ptr
parameter_list|)
value|*((ptr) + 2)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID
parameter_list|(
name|ptr
parameter_list|)
value|*(ptr)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_NEXT
parameter_list|(
name|ptr
parameter_list|)
value|*((ptr) + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Capability lists */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_LIST_ID
value|0
end_define

begin_comment
comment|/* Capability ID */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_PM
value|0x01
end_define

begin_comment
comment|/* Power Management */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_AGP
value|0x02
end_define

begin_comment
comment|/* Accelerated Graphics Port */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_VPD
value|0x03
end_define

begin_comment
comment|/* Vital Product Data */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_SLOTID
value|0x04
end_define

begin_comment
comment|/* Slot Identification */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_MSI
value|0x05
end_define

begin_comment
comment|/* Message Signalled Intr */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_CHSWP
value|0x06
end_define

begin_comment
comment|/* CompactPCI HotSwap */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_PCIX
value|0x07
end_define

begin_comment
comment|/* PCIX */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_HT
value|0x08
end_define

begin_comment
comment|/* Hypertransport */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_VS
value|0x09
end_define

begin_comment
comment|/* Vendor Specific */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_DBGPORT
value|0x0A
end_define

begin_comment
comment|/* Debug Port */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_CPCICSR
value|0x0B
end_define

begin_comment
comment|/* CompPCI central res ctrl */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_SHPC
value|0x0C
end_define

begin_comment
comment|/* PCI Standard Hot-Plug Ctrl */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_PCIBSVID
value|0x0D
end_define

begin_comment
comment|/* PCI Bridge Subsys Vendr Id */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_AGP8X
value|0x0E
end_define

begin_comment
comment|/* AGP 8x */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_SECDEV
value|0x0F
end_define

begin_comment
comment|/* Secure Device */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_PCIE
value|0x10
end_define

begin_comment
comment|/* PCI Express */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_ID_MSIX
value|0x11
end_define

begin_comment
comment|/* MSI-X */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_LIST_NEXT
value|1
end_define

begin_comment
comment|/* Next cap in the list */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_CAP_FLAGS
value|2
end_define

begin_comment
comment|/* Cap defined flags(16 bits) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_pm_capability_le_t
block|{
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u16
name|capabilities_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_VER_MASK
value|0x0007
comment|/* Version */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_CLOCK
value|0x0008
comment|/* PME clock required */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_AUX_POWER
value|0x0010
comment|/* Auxiliary power support */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_DSI
value|0x0020
comment|/* Device specific init */
define|#
directive|define
name|VXGE_HAL_PCI_PM_AUX_CURRENT
value|0x01C0
comment|/* Auxiliary current reqs */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_D1
value|0x0200
comment|/* D1 power state support */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_D2
value|0x0400
comment|/* D2 power state support */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D0
value|0x0800
comment|/* PME# assertable from D0 */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D1
value|0x1000
comment|/* PME# assertable from D1 */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D2
value|0x2000
comment|/* PME# assertable from D2 */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D3_HOT
value|0x4000
comment|/* PME# assertable from D3hot */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D3_COLD
value|0x8000
comment|/* PME# assertable from D3cold */
name|u16
name|pm_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_STATE_MASK
value|0x0003
comment|/* Curr power state(D0 to D3) */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_NO_SOFT_RESET
value|0x0008
comment|/* trans from D3hot to D0 */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_PME_ENABLE
value|0x0100
comment|/* PME pin enable */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_DATA_SEL_MASK
value|0x1e00
comment|/* Data select (??) */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_DATA_SCALE_MASK
value|0x6000
comment|/* Data scale (??) */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_PME_STATUS
value|0x8000
comment|/* PME pin status */
name|u8
name|pm_ppb_ext
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_PM_PPB_B2_B3
value|0x40
comment|/* Stop clk when in D3hot(??) */
define|#
directive|define
name|VXGE_HAL_PCI_PM_BPCC_ENABLE
value|0x80
comment|/* Bus pwr/clk ctrl enable(??) */
name|u8
name|pm_data_reg
decl_stmt|;
block|}
name|vxge_hal_pm_capability_le_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_pm_capability_t
block|{
if|#
directive|if
name|defined
argument_list|(
name|VXGE_OS_HOST_BIG_ENDIAN
argument_list|)
name|u16
name|capabilities_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_VER_MASK
value|0x0007
comment|/* Version */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_CLOCK
value|0x0008
comment|/* PME clock required */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_AUX_POWER
value|0x0010
comment|/* Auxiliary power support */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_DSI
value|0x0020
comment|/* Dev specific init */
define|#
directive|define
name|VXGE_HAL_PCI_PM_AUX_CURRENT
value|0x01C0
comment|/* Auxiliary current reqs */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_D1
value|0x0200
comment|/* D1 power state support */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_D2
value|0x0400
comment|/* D2 power state support */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D0
value|0x0800
comment|/* PME# assertable from D0 */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D1
value|0x1000
comment|/* PME# assertable from D1 */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D2
value|0x2000
comment|/* PME# assertable from D2 */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D3_HOT
value|0x4000
comment|/* PME# assertable from D3hot */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D3_COLD
value|0x8000
comment|/* PME# assertable from D3cold */
name|u8
name|next_capability_ptr
decl_stmt|;
name|u8
name|capability_id
decl_stmt|;
name|u8
name|pm_data_reg
decl_stmt|;
name|u8
name|pm_ppb_ext
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_PM_PPB_B2_B3
value|0x40
comment|/* Stop clk when in D3hot(??) */
define|#
directive|define
name|VXGE_HAL_PCI_PM_BPCC_ENABLE
value|0x80
comment|/* Bus pwr/clk ctrl enable(??) */
name|u16
name|pm_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_STATE_MASK
value|0x0003
comment|/* Curr pwr state (D0 to D3) */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_NO_SOFT_RESET
value|0x0008
comment|/* dev trans D3hot to D0 */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_PME_ENABLE
value|0x0100
comment|/* PME pin enable */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_DATA_SEL_MASK
value|0x1e00
comment|/* Data select (??) */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_DATA_SCALE_MASK
value|0x6000
comment|/* Data scale (??) */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_PME_STATUS
value|0x8000
comment|/* PME pin status */
else|#
directive|else
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u16
name|capabilities_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_VER_MASK
value|0x0007
comment|/* Version */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_CLOCK
value|0x0008
comment|/* PME clock required */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_AUX_POWER
value|0x0010
comment|/* Auxiliary power support */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_DSI
value|0x0020
comment|/* Dev specific init */
define|#
directive|define
name|VXGE_HAL_PCI_PM_AUX_CURRENT
value|0x01C0
comment|/* Auxiliary curr reqs */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_D1
value|0x0200
comment|/* D1 power state support */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_D2
value|0x0400
comment|/* D2 power state support */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D0
value|0x0800
comment|/* PME# assertable from D0 */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D1
value|0x1000
comment|/* PME# assertable from D1 */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D2
value|0x2000
comment|/* PME# assertable from D2 */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D3_HOT
value|0x4000
comment|/* PME# assertable from D3hot */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CAP_PME_D3_COLD
value|0x8000
comment|/* PME# assertable from D3cold */
name|u16
name|pm_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_STATE_MASK
value|0x0003
comment|/* Curr pwr state (D0 to D3) */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_NO_SOFT_RESET
value|0x0008
comment|/* dev trans D3hot to D0 */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_PME_ENABLE
value|0x0100
comment|/* PME pin enable */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_DATA_SEL_MASK
value|0x1e00
comment|/* Data select (??) */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_DATA_SCALE_MASK
value|0x6000
comment|/* Data scale (??) */
define|#
directive|define
name|VXGE_HAL_PCI_PM_CTRL_PME_STATUS
value|0x8000
comment|/* PME pin status */
name|u8
name|pm_ppb_ext
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_PM_PPB_B2_B3
value|0x40
comment|/* Stop clk when in D3hot(??) */
define|#
directive|define
name|VXGE_HAL_PCI_PM_BPCC_ENABLE
value|0x80
comment|/* Bus pwr/clk ctrl enable(??) */
name|u8
name|pm_data_reg
decl_stmt|;
endif|#
directive|endif
block|}
name|vxge_hal_pm_capability_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpid_capability_le_t
block|{
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u16
name|vpd_address
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_VPID_COMPL_FALG
value|0x8000
comment|/* Read Completion Flag */
name|u32
name|vpd_data
decl_stmt|;
block|}
name|vxge_hal_vpid_capability_le_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpid_capability_t
block|{
if|#
directive|if
name|defined
argument_list|(
name|VXGE_OS_HOST_BIG_ENDIAN
argument_list|)
name|u16
name|vpd_address
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_VPID_COMPL_FALG
value|0x8000
comment|/* Read Completion Flag */
name|u8
name|next_capability_ptr
decl_stmt|;
name|u8
name|capability_id
decl_stmt|;
name|u32
name|vpd_data
decl_stmt|;
else|#
directive|else
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u16
name|vpd_address
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_VPID_COMPL_FALG
value|0x8000
comment|/* Read Completion Flag */
name|u32
name|vpd_data
decl_stmt|;
endif|#
directive|endif
block|}
name|vxge_hal_vpid_capability_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_sid_capability_le_t
block|{
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u8
name|sid_esr
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_SID_ESR_NSLOTS
value|0x1f
comment|/* Num of exp slots avail */
define|#
directive|define
name|VXGE_HAL_PCI_SID_ESR_FIC
value|0x20
comment|/* First In Chassis Flag */
name|u8
name|sid_chasis_nr
decl_stmt|;
block|}
name|vxge_hal_sid_capability_le_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_sid_capability_t
block|{
if|#
directive|if
name|defined
argument_list|(
name|VXGE_OS_HOST_BIG_ENDIAN
argument_list|)
name|u8
name|sid_chasis_nr
decl_stmt|;
name|u8
name|sid_esr
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_SID_ESR_NSLOTS
value|0x1f
comment|/* Num of exp slots avail */
define|#
directive|define
name|VXGE_HAL_PCI_SID_ESR_FIC
value|0x20
comment|/* First In Chassis Flag */
name|u8
name|next_capability_ptr
decl_stmt|;
name|u8
name|capability_id
decl_stmt|;
else|#
directive|else
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u8
name|sid_esr
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_SID_ESR_NSLOTS
value|0x1f
comment|/* Num of exp slots avail */
define|#
directive|define
name|VXGE_HAL_PCI_SID_ESR_FIC
value|0x20
comment|/* First In Chassis Flag */
name|u8
name|sid_chasis_nr
decl_stmt|;
endif|#
directive|endif
block|}
name|vxge_hal_sid_capability_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_msi_capability_le_t
block|{
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u16
name|msi_control
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_PVMASK
value|0x0100
comment|/* Per Vector Masking Capable */
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_64BIT
value|0x0080
comment|/* 64-bit addresses allowed */
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_QSIZE
value|0x0070
comment|/* Msg queue size configured */
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_QMASK
value|0x000e
comment|/* Max queue size available */
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_ENABLE
value|0x0001
comment|/* MSI feature enabled */
union|union
block|{
struct|struct
block|{
name|u32
name|msi_addr
decl_stmt|;
name|u16
name|msi_data
decl_stmt|;
name|u16
name|msi_unused
decl_stmt|;
block|}
name|ma32_no_pvm
struct|;
struct|struct
block|{
name|u32
name|msi_addr
decl_stmt|;
name|u16
name|msi_data
decl_stmt|;
name|u16
name|msi_unused
decl_stmt|;
name|u32
name|msi_mask
decl_stmt|;
name|u32
name|msi_pending
decl_stmt|;
block|}
name|ma32_pvm
struct|;
struct|struct
block|{
name|u32
name|msi_addr_lo
decl_stmt|;
name|u32
name|msi_addr_hi
decl_stmt|;
name|u16
name|msi_data
decl_stmt|;
name|u16
name|msi_unused
decl_stmt|;
block|}
name|ma64_no_pvm
struct|;
struct|struct
block|{
name|u32
name|msi_addr_lo
decl_stmt|;
name|u32
name|msi_addr_hi
decl_stmt|;
name|u16
name|msi_data
decl_stmt|;
name|u16
name|msi_unused
decl_stmt|;
name|u32
name|msi_mask
decl_stmt|;
name|u32
name|msi_pending
decl_stmt|;
block|}
name|ma64_pvm
struct|;
block|}
name|au
union|;
block|}
name|vxge_hal_msi_capability_le_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_msi_capability_t
block|{
if|#
directive|if
name|defined
argument_list|(
name|VXGE_OS_HOST_BIG_ENDIAN
argument_list|)
name|u16
name|msi_control
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_PVMASK
value|0x0100
comment|/* Per Vector Masking Capable */
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_64BIT
value|0x0080
comment|/* 64-bit addresses allowed */
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_QSIZE
value|0x0070
comment|/* Msg queue size configured */
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_QMASK
value|0x000e
comment|/* Max queue size available */
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_ENABLE
value|0x0001
comment|/* MSI feature enabled */
name|u8
name|next_capability_ptr
decl_stmt|;
name|u8
name|capability_id
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u32
name|msi_addr
decl_stmt|;
name|u16
name|msi_unused
decl_stmt|;
name|u16
name|msi_data
decl_stmt|;
block|}
name|ma32_no_pvm
struct|;
struct|struct
block|{
name|u32
name|msi_addr
decl_stmt|;
name|u16
name|msi_unused
decl_stmt|;
name|u16
name|msi_data
decl_stmt|;
name|u32
name|msi_mask
decl_stmt|;
name|u32
name|msi_pending
decl_stmt|;
block|}
name|ma32_pvm
struct|;
struct|struct
block|{
name|u32
name|msi_addr_lo
decl_stmt|;
name|u32
name|msi_addr_hi
decl_stmt|;
name|u16
name|msi_unused
decl_stmt|;
name|u16
name|msi_data
decl_stmt|;
block|}
name|ma64_no_pvm
struct|;
struct|struct
block|{
name|u32
name|msi_addr_lo
decl_stmt|;
name|u32
name|msi_addr_hi
decl_stmt|;
name|u16
name|msi_unused
decl_stmt|;
name|u16
name|msi_data
decl_stmt|;
name|u32
name|msi_mask
decl_stmt|;
name|u32
name|msi_pending
decl_stmt|;
block|}
name|ma64_pvm
struct|;
block|}
name|au
union|;
else|#
directive|else
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u16
name|msi_control
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_PVMASK
value|0x0100
comment|/* Per Vector Masking Capable */
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_64BIT
value|0x0080
comment|/* 64-bit addresses allowed */
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_QSIZE
value|0x0070
comment|/* Msg queue size configured */
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_QMASK
value|0x000e
comment|/* Max queue size available */
define|#
directive|define
name|VXGE_HAL_PCI_MSI_FLAGS_ENABLE
value|0x0001
comment|/* MSI feature enabled */
union|union
block|{
struct|struct
block|{
name|u32
name|msi_addr
decl_stmt|;
name|u16
name|msi_data
decl_stmt|;
name|u16
name|msi_unused
decl_stmt|;
block|}
name|ma32_no_pvm
struct|;
struct|struct
block|{
name|u32
name|msi_addr
decl_stmt|;
name|u16
name|msi_data
decl_stmt|;
name|u16
name|msi_unused
decl_stmt|;
name|u32
name|msi_mask
decl_stmt|;
name|u32
name|msi_pending
decl_stmt|;
block|}
name|ma32_pvm
struct|;
struct|struct
block|{
name|u32
name|msi_addr_lo
decl_stmt|;
name|u32
name|msi_addr_hi
decl_stmt|;
name|u16
name|msi_data
decl_stmt|;
name|u16
name|msi_unused
decl_stmt|;
block|}
name|ma64_no_pvm
struct|;
struct|struct
block|{
name|u32
name|msi_addr_lo
decl_stmt|;
name|u32
name|msi_addr_hi
decl_stmt|;
name|u16
name|msi_data
decl_stmt|;
name|u16
name|msi_unused
decl_stmt|;
name|u32
name|msi_mask
decl_stmt|;
name|u32
name|msi_pending
decl_stmt|;
block|}
name|ma64_pvm
struct|;
block|}
name|au
union|;
endif|#
directive|endif
block|}
name|vxge_hal_msi_capability_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_chswp_capability_le_t
block|{
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u8
name|chswp_csr
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_DHA
value|0x01
comment|/* Device Hiding Arm */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_EIM
value|0x02
comment|/* ENUM# Signal Mask */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_PIE
value|0x04
comment|/* Pending Insert or Extract */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_LOO
value|0x08
comment|/* LED On / Off */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_PI
value|0x30
comment|/* Programming Interface */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_EXT
value|0x40
comment|/* ENUM# status - extraction */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_INS
value|0x80
comment|/* ENUM# status - insertion */
block|}
name|vxge_hal_chswp_capability_le_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_chswp_capability_t
block|{
if|#
directive|if
name|defined
argument_list|(
name|VXGE_OS_HOST_BIG_ENDIAN
argument_list|)
name|u8
name|chswp_csr
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_DHA
value|0x01
comment|/* Device Hiding Arm */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_EIM
value|0x02
comment|/* ENUM# Signal Mask */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_PIE
value|0x04
comment|/* Pending Insert or Extract */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_LOO
value|0x08
comment|/* LED On / Off */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_PI
value|0x30
comment|/* Programming Interface */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_EXT
value|0x40
comment|/* ENUM# status - extraction */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_INS
value|0x80
comment|/* ENUM# status - insertion */
name|u8
name|next_capability_ptr
decl_stmt|;
name|u8
name|capability_id
decl_stmt|;
else|#
directive|else
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u8
name|chswp_csr
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_DHA
value|0x01
comment|/* Device Hiding Arm */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_EIM
value|0x02
comment|/* ENUM# Signal Mask */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_PIE
value|0x04
comment|/* Pending Insert or Extract */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_LOO
value|0x08
comment|/* LED On / Off */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_PI
value|0x30
comment|/* Programming Interface */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_EXT
value|0x40
comment|/* ENUM# status - extraction */
define|#
directive|define
name|VXGE_HAL_PCI_CHSWP_INS
value|0x80
comment|/* ENUM# status - insertion */
endif|#
directive|endif
block|}
name|vxge_hal_chswp_capability_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_shpc_capability_le_t
block|{
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
block|}
name|vxge_hal_shpc_capability_le_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_shpc_capability_t
block|{
if|#
directive|if
name|defined
argument_list|(
name|VXGE_OS_HOST_BIG_ENDIAN
argument_list|)
name|u8
name|next_capability_ptr
decl_stmt|;
name|u8
name|capability_id
decl_stmt|;
else|#
directive|else
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
endif|#
directive|endif
block|}
name|vxge_hal_shpc_capability_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_msix_capability_le_t
block|{
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u16
name|msix_control
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_FLAGS_ENABLE
value|0x8000
comment|/* MSIX Enable */
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_FLAGS_MASK
value|0x4000
comment|/* Mask all vectors */
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_FLAGS_TSIZE
value|0x001f
comment|/* Table Size */
name|u32
name|table_offset
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_TABLE_OFFSET
value|0xFFFFFFF8
comment|/* Table offset mask */
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_TABLE_BIR
value|0x00000007
comment|/* Table BIR mask */
name|u32
name|pba_offset
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_PBA_OFFSET
value|0xFFFFFFF8
comment|/* Table offset mask */
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_PBA_BIR
value|0x00000007
comment|/* Table BIR mask */
block|}
name|vxge_hal_msix_capability_le_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_msix_capability_t
block|{
if|#
directive|if
name|defined
argument_list|(
name|VXGE_OS_HOST_BIG_ENDIAN
argument_list|)
name|u16
name|msix_control
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_FLAGS_ENABLE
value|0x8000
comment|/* MSIX Enable */
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_FLAGS_MASK
value|0x4000
comment|/* Mask all vectors */
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_FLAGS_TSIZE
value|0x001f
comment|/* Table Size */
name|u8
name|next_capability_ptr
decl_stmt|;
name|u8
name|capability_id
decl_stmt|;
name|u32
name|table_offset
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_TABLE_OFFSET
value|0xFFFFFFF8
comment|/* Table offset mask */
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_TABLE_BIR
value|0x00000007
comment|/* Table BIR mask */
name|u32
name|pba_offset
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_PBA_OFFSET
value|0xFFFFFFF8
comment|/* Table offset mask */
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_PBA_BIR
value|0x00000007
comment|/* Table BIR mask */
else|#
directive|else
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u16
name|msix_control
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_FLAGS_ENABLE
value|0x8000
comment|/* MSIX Enable */
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_FLAGS_MASK
value|0x4000
comment|/* Mask all vectors */
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_FLAGS_TSIZE
value|0x001f
comment|/* Table Size */
name|u32
name|table_offset
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_TABLE_OFFSET
value|0xFFFFFFF8
comment|/* Table offset mask */
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_TABLE_BIR
value|0x00000007
comment|/* Table BIR mask */
name|u32
name|pba_offset
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_PBA_OFFSET
value|0xFFFFFFF8
comment|/* Table offset mask */
define|#
directive|define
name|VXGE_HAL_PCI_MSIX_PBA_BIR
value|0x00000007
comment|/* Table BIR mask */
endif|#
directive|endif
block|}
name|vxge_hal_msix_capability_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_pci_caps_offset_t
block|{
name|u32
name|pm_cap_offset
decl_stmt|;
name|u32
name|vpd_cap_offset
decl_stmt|;
name|u32
name|sid_cap_offset
decl_stmt|;
name|u32
name|msi_cap_offset
decl_stmt|;
name|u32
name|vs_cap_offset
decl_stmt|;
name|u32
name|shpc_cap_offset
decl_stmt|;
name|u32
name|msix_cap_offset
decl_stmt|;
block|}
name|vxge_hal_pci_caps_offset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_pci_e_capability_le_t
block|{
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u16
name|pci_e_flags
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_FLAGS_VERS
value|0x000f
comment|/* Capability version */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_FLAGS_TYPE
value|0x00f0
comment|/* Device/Port type */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_ENDPOINT
value|0x0
comment|/* Express Endpoint */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_LEG_END
value|0x1
comment|/* Legacy Endpoint */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_ROOT_PORT
value|0x4
comment|/* Root Port */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_UPSTREAM
value|0x5
comment|/* Upstream Port */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_DOWNSTREAM
value|0x6
comment|/* Downstream Port */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_PCI_BRIDGE
value|0x7
comment|/* PCI/PCI-X Bridge */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_FLAGS_SLOT
value|0x0100
comment|/* Slot implemented */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_FLAGS_IRQ
value|0x3e00
comment|/* Interrupt msg number */
name|u32
name|pci_e_devcap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PAYLOAD
value|0x07
comment|/* Max_Payload_Size */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PHANTOM
value|0x18
comment|/* Phantom functions */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_EXT_TAG
value|0x20
comment|/* Extended tags */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_L0S
value|0x1c0
comment|/* L0s Acceptable Latency */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_L1
value|0xe00
comment|/* L1 Acceptable Latency */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_ATN_BUT
value|0x1000
comment|/* Attention Button Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_ATN_IND
value|0x2000
comment|/* Attention Ind Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PWR_IND
value|0x4000
comment|/* Power Indicator Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PWR_VAL
value|0x3fc0000
comment|/* Slot Power Limit Value */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PWR_SCL
value|0xc000000
comment|/* Slot Power Limit Scale */
name|u16
name|pci_e_devctl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_CERE
value|0x0001
comment|/* Correctable Err Report En. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_NFERE
value|0x0002
comment|/* Non-Fatal Err Report En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_FERE
value|0x0004
comment|/* Fatal Error Report En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_URRE
value|0x0008
comment|/* Unsupported Req Report En. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_RELAX_EN
value|0x0010
comment|/* Enable relaxed ordering */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_PAYLOAD
value|0x00e0
comment|/* Max_Payload_Size */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_EXT_TAG
value|0x0100
comment|/* Extended Tag Field Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_PHANTOM
value|0x0200
comment|/* Phantom Functions Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_AUX_PME
value|0x0400
comment|/* Auxiliary Power PM Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_NOSNOOP_EN
value|0x0800
comment|/* Enable No Snoop */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_READRQ
value|0x7000
comment|/* Max_Read_Request_Size */
name|u16
name|pci_e_devsta
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_CED
value|0x01
comment|/* Correctable Error Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_NFED
value|0x02
comment|/* Non-Fatal Error Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_FED
value|0x04
comment|/* Fatal Error Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_URD
value|0x08
comment|/* Unsupported Req Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_AUXPD
value|0x10
comment|/* AUX Power Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_TRPND
value|0x20
comment|/* Transactions Pending */
name|u32
name|pci_e_lnkcap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_SPEED
value|0xf
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LS_2_5
value|0x1
comment|/* 2.5 Gb/s supported. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LS_5
value|0x2
comment|/* 5 and 2.5 Gb/s supported. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_WIDTH
value|0x3f0
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_RES
value|0x0
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X1
value|0x1
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X2
value|0x2
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X4
value|0x4
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X8
value|0x8
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X12
value|0xa
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X16
value|0x10
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X32
value|0x20
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_ASPM
value|0xc00
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LASPM_RES1
value|0x0
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LASPM_LO
value|0x1
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LASPM_RES2
value|0x2
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LASPM_L0_L1
value|0x3
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_LAT
value|0x7000
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_LT_64
value|0x0
comment|/* Less than 64ns. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_64_128
value|0x1
comment|/* 64ns to less than 128ns. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_128_256
value|0x2
comment|/* 128ns to less than 256ns. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_256_512
value|0x3
comment|/* 256ns to less than 512ns. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_512_1us
value|0x4
comment|/* 512ns to less than 1s. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_1us_2us
value|0x5
comment|/* 1s to less than 2s. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_2us_4us
value|0x6
comment|/* 2s-4s. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_GT_4us
value|0x7
comment|/* More than 4s. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_LAT
value|0x38000
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_LT_1us
value|0x0
comment|/* Less than 1us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_1us_2us
value|0x1
comment|/* 1us to less than 2us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_2us_4us
value|0x2
comment|/* 2us to less than 4us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_4us_8us
value|0x3
comment|/* 4us to less than 8us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_8us_16us
value|0x4
comment|/* 8us to less than 16us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_16us_32us
value|0x5
comment|/* 16us to less than 32us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_32us_64us
value|0x6
comment|/* 32us-64us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_GT_64us
value|0x7
comment|/* More than 64us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_CLK_PWR_MGMT
value|0x40000
comment|/* Clk power management. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_DOWN_ERR_CAP
value|0x80000
comment|/* Down error capable. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_ACT_CAP
value|0x100000
comment|/* DL active rep cap. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_BW_CAP
value|0x200000
comment|/* DL bw reporting cap. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_PORT_NUM
value|0xff000000
comment|/* Port number. */
name|u16
name|pci_e_lnkctl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM
value|0x3
comment|/* ASPM Control. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM_DISABLED
value|0x0
comment|/* Disabled. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM_L0_EN
value|0x1
comment|/* L0 entry enabled. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM_L1_EN
value|0x2
comment|/* L1 entry enabled. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM_L0_L1_EN
value|0x3
comment|/* L0& L1 entry enabled. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_RCB
value|0x8
comment|/* Read Completion Boundary. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_RCB_64
value|0x0
comment|/* RCB 64 bytes. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_RCB_128
value|0x1
comment|/* RCB 128 bytes. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_DISABLED
value|0x10
comment|/* Disables the link. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_RETRAIN
value|0x20
comment|/* Retrain the link. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_CCCFG
value|0x40
comment|/* Common clock config. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_EXT_SYNC
value|0x80
comment|/* Extended Sync. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_CLK_PWRMGMT
value|0x100
comment|/* Enable clk pwr mgmt. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_HW_AUTO_DIS
value|0x200
comment|/* Hw autonomous with dis */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_BWM_INTR_EN
value|0x400
comment|/* Bw mgt interrupt enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ABW_INTR_EN
value|0x800
comment|/* Autonomous BW intr en */
name|u16
name|pci_e_lnksta
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LNK_SPEED
value|0xf
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LS_2_5
value|0x1
comment|/* 2.5 Gb/s supported. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LS_5
value|0x2
comment|/* 5 2.5 Gb/s supported. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LNK_WIDTH
value|0x3f0
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_RES
value|0x0
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X1
value|0x1
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X2
value|0x2
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X4
value|0x4
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X8
value|0x8
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X12
value|0xa
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X16
value|0x10
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X32
value|0x20
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LNK_TRAIN
value|0x800
comment|/* Link training. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_SCLK_CFG
value|0x1000
comment|/* Slot Clock Config. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_DLL_ACTIVE
value|0x2000
comment|/* Data LL Active. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_BWM_STA
value|0x4000
comment|/* Bw mgmt intr enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_ABW_STA
value|0x8000
comment|/* Autonomous BW intr en */
name|u32
name|pci_e_stlcap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_ATTN_BTTN
value|0x1
comment|/* Attention Button Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_PWR_CTRL
value|0x2
comment|/* Power Control Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_MRL_SENS
value|0x4
comment|/* MRL Sesor Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_ATTN_IND
value|0x8
comment|/* Attention Ind Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_PWR_IND
value|0x10
comment|/* Power Indicator Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_HP_SURP
value|0x20
comment|/* Hot-Plug Surprise */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_HP_CAP
value|0x40
comment|/* Hot-Plug Surprise */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_VAL
value|0x7F80
comment|/* Hot-Plug Surprise */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_250
value|0xF0
comment|/* 250 W Slot Power Limit */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_275
value|0xF1
comment|/* 275 W Slot Power Limit */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_300
value|0xF2
comment|/* 300 W Slot Power Limit */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_LIM
value|0x18000
comment|/* Hot-Plug Surprise */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_1X
value|0x0
comment|/* 1.0x */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_XBY10
value|0x1
comment|/* 0.1x */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_XBY100
value|0x2
comment|/* 0.01x */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_XBY1000
value|0x3
comment|/* 0.001x */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_EM_INTR_LOCK
value|0x20000
comment|/* Ele-mec Intrlock Pres */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_NO_CMD_CMPL
value|0x40000
comment|/* No Cmd Compl Support */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_PHY_SL_NO
value|0xFFF80000
comment|/* Phys Slot Number */
name|u16
name|pci_e_stlctl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATTN_BTN_EN
value|0x1
comment|/* Atten Btn pressed enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PF_DET_EN
value|0x2
comment|/* Power Fault Detected En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_MRL_SENS_EN
value|0x4
comment|/* MRL Sensor Changed Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PDET_CH_EN
value|0x8
comment|/* Presence Detect Change En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_CC_INTR_EN
value|0x10
comment|/* Cmd Compl Intr Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_HP_INTR_EN
value|0x20
comment|/* Hot-Plug Intr Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_CTRL
value|0xC0
comment|/* Attention Ind Control */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_RES
value|0x0
comment|/* Reserved */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_ON
value|0x1
comment|/* On */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_BLNK
value|0x2
comment|/* Blink */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_OFF
value|0x3
comment|/* Off */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_CTRL
value|0x300
comment|/* POwer Indicator Control */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_RES
value|0x0
comment|/* Reserved */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_ON
value|0x1
comment|/* On */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_BLNK
value|0x2
comment|/* Blink */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_OFF
value|0x3
comment|/* Off */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWRCTRL_CTRL
value|0x400
comment|/* Power Controller Ctrl */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWRCTRL_on
value|0x0
comment|/* Power on */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWRCTRL_off
value|0x1
comment|/* Power off */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_EM_IL_CTRL
value|0x800
comment|/* Ele-mec Interlock Crl */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_DLL_ST_CH_EN
value|0x1000
comment|/* DL Layer State Ch En */
name|u16
name|pci_e_stlsta
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_ATTN_BTN
value|0x1
comment|/* Attention Button Pressed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PF_DET
value|0x2
comment|/* Power Fault Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_MRL_SENS_CH
value|0x4
comment|/* MRL Sensor Changed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PDET_CH
value|0x8
comment|/* Presence Detect Changed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_CMD_COMPL
value|0x10
comment|/* Command Completed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_MRL_SENS_STA
value|0x20
comment|/* MRL Sensor State */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_MRL_SENS_CL
value|0x0
comment|/* MRL Sensor State - closed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_MRL_SENS_OP
value|0x1
comment|/* MRL Sensor State - open */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PDET_STA
value|0x400
comment|/* Presence Detect State */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PDET_EMPTY
value|0x0
comment|/* Clost Empty */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PDET_PRESENT
value|0x1
comment|/* Card Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_EM_IL_STA
value|0x80
comment|/* Ele-mec Intrlock Control */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_EM_IL_DIS
value|0x0
comment|/* Disengaged */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_EM_IL_EN
value|0x1
comment|/* Engaged */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_DLL_ST_CH
value|0x100
comment|/* DL Layer State Changed */
name|u16
name|pci_e_rtctl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_SECEE
value|0x01
comment|/* Sys Err on Correctable Error */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_SENFEE
value|0x02
comment|/* Sys Err on Non-Fatal Error */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_SEFEE
value|0x04
comment|/* Sys Err on Fatal Error */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_PMEIE
value|0x08
comment|/* PME Interrupt Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_CRSSVE
value|0x10
comment|/* CRS SW Visibility Enable */
name|u16
name|pci_e_rtcap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCAP_CRS_SW_VIS
value|0x01
comment|/* CRS SW Visibility */
name|u32
name|pci_e_rtsta
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTSTA_PME_REQ_ID
value|0xFFFF
comment|/* PME Requestor ID */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTSTA_PME_STATUS
value|0x10000
comment|/* PME status */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTSTA_PME_PENDING
value|0x20000
comment|/* PME Pending */
block|}
name|vxge_hal_pci_e_capability_le_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_pci_e_capability_t
block|{
if|#
directive|if
name|defined
argument_list|(
name|VXGE_OS_HOST_BIG_ENDIAN
argument_list|)
name|u16
name|pci_e_flags
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_FLAGS_VERS
value|0x000f
comment|/* Capability version */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_FLAGS_TYPE
value|0x00f0
comment|/* Device/Port type */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_ENDPOINT
value|0x0
comment|/* Express Endpoint */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_LEG_END
value|0x1
comment|/* Legacy Endpoint */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_ROOT_PORT
value|0x4
comment|/* Root Port */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_UPSTREAM
value|0x5
comment|/* Upstream Port */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_DOWNSTREAM
value|0x6
comment|/* Downstream Port */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_PCI_BRIDGE
value|0x7
comment|/* PCI/PCI-X Bridge */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_FLAGS_SLOT
value|0x0100
comment|/* Slot implemented */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_FLAGS_IRQ
value|0x3e00
comment|/* Interrupt message number */
name|u8
name|next_capability_ptr
decl_stmt|;
name|u8
name|capability_id
decl_stmt|;
name|u32
name|pci_e_devcap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PAYLOAD
value|0x07
comment|/* Max_Payload_Size */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PHANTOM
value|0x18
comment|/* Phantom functions */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_EXT_TAG
value|0x20
comment|/* Extended tags */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_L0S
value|0x1c0
comment|/* L0s Acceptable Latency */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_L1
value|0xe00
comment|/* L1 Acceptable Latency */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_ATN_BUT
value|0x1000
comment|/* Attention Button Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_ATN_IND
value|0x2000
comment|/* Attention Ind Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PWR_IND
value|0x4000
comment|/* Power Indicator Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PWR_VAL
value|0x3fc0000
comment|/* Slot Power Limit Value */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PWR_SCL
value|0xc000000
comment|/* Slot Power Limit Scale */
name|u16
name|pci_e_devsta
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_CED
value|0x01
comment|/* Correctable Err Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_NFED
value|0x02
comment|/* Non-Fatal Error Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_FED
value|0x04
comment|/* Fatal Error Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_URD
value|0x08
comment|/* Unsupported Req Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_AUXPD
value|0x10
comment|/* AUX Power Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_TRPND
value|0x20
comment|/* Transactions Pending */
name|u16
name|pci_e_devctl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_CERE
value|0x0001
comment|/* Corr'ble Err Reporting En. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_NFERE
value|0x0002
comment|/* Non-Fatal Err Reporting En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_FERE
value|0x0004
comment|/* Fatal Error Reporting En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_URRE
value|0x0008
comment|/* Unsupp Req Reporting En. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_RELAX_EN
value|0x0010
comment|/* Enable relaxed ordering */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_PAYLOAD
value|0x00e0
comment|/* Max_Payload_Size */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_EXT_TAG
value|0x0100
comment|/* Extended Tag Field Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_PHANTOM
value|0x0200
comment|/* Phantom Functions Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_AUX_PME
value|0x0400
comment|/* Auxiliary Power PM Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_NOSNOOP_EN
value|0x0800
comment|/* Enable No Snoop */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_READRQ
value|0x7000
comment|/* Max_Read_Request_Size */
name|u32
name|pci_e_lnkcap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_SPEED
value|0xf
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LS_2_5
value|0x1
comment|/* 2.5 Gb/s supported. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LS_5
value|0x2
comment|/* 5 2.5 Gb/s supported. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_WIDTH
value|0x3f0
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_RES
value|0x0
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X1
value|0x1
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X2
value|0x2
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X4
value|0x4
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X8
value|0x8
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X12
value|0xa
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X16
value|0x10
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X32
value|0x20
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_ASPM
value|0xc00
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LASPM_RES1
value|0x0
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LASPM_LO
value|0x1
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LASPM_RES2
value|0x2
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LASPM_L0_L1
value|0x3
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_LAT
value|0x7000
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_LT_64
value|0x0
comment|/* Less than 64 ns. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_64_128
value|0x1
comment|/* 64 ns to less than 128 ns. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_128_256
value|0x2
comment|/* 128 ns to less than 256 ns. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_256_512
value|0x3
comment|/* 256 ns to less than 512 ns. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_512_1us
value|0x4
comment|/* 512 ns to less than 1us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_1us_2us
value|0x5
comment|/* 1us to less than 2us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_2us_4us
value|0x6
comment|/* 2us-4us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_GT_4us
value|0x7
comment|/* More than 4us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_LAT
value|0x38000
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_LT_1us
value|0x0
comment|/* Less than 1us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_1us_2us
value|0x1
comment|/* 1us to less than 2us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_2us_4us
value|0x2
comment|/* 2us to less than 4us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_4us_8us
value|0x3
comment|/* 4us to less than 8us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_8us_16us
value|0x4
comment|/* 8us to less than 16us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_16us_32us
value|0x5
comment|/* 16us to less than 32us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_32us_64us
value|0x6
comment|/* 32us-64s. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_GT_64us
value|0x7
comment|/* More than 64us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_CLK_PWR_MGMT
value|0x40000
comment|/* Clk power management. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_DOWN_ERR_CAP
value|0x80000
comment|/* Down error capable. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_ACT_CAP
value|0x100000
comment|/* DL active rep cap. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_BW_CAP
value|0x200000
comment|/* DL bw rep cap. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_PORT_NUM
value|0xff000000
comment|/* Port number. */
name|u16
name|pci_e_lnksta
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LNK_SPEED
value|0xf
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LS_2_5
value|0x1
comment|/* 2.5 Gb/s supported. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LS_5
value|0x2
comment|/* 5 2.5 Gb/s supported. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LNK_WIDTH
value|0x3f0
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_RES
value|0x0
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X1
value|0x1
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X2
value|0x2
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X4
value|0x4
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X8
value|0x8
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X12
value|0xa
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X16
value|0x10
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X32
value|0x20
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LNK_TRAIN
value|0x800
comment|/* Link training. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_SCLK_CFG
value|0x1000
comment|/* Slot Clock Config. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_DLL_ACTIVE
value|0x2000
comment|/* Data LL Active. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_BWM_STA
value|0x4000
comment|/* Bw mgmt interrupt enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_ABW_STA
value|0x8000
comment|/* Autonomous BW intr en */
name|u16
name|pci_e_lnkctl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM
value|0x3
comment|/* ASPM Control. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM_DISABLED
value|0x0
comment|/* Disabled. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM_L0_EN
value|0x1
comment|/* L0 entry enabled. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM_L1_EN
value|0x2
comment|/* L1 entry enabled. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM_L0_L1_EN
value|0x3
comment|/* L0& L1 entry enabled. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_RCB
value|0x8
comment|/* Read Compl Boundary. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_RCB_64
value|0x0
comment|/* RCB 64 bytes. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_RCB_128
value|0x1
comment|/* RCB 128 bytes. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_DISABLED
value|0x10
comment|/* Disables the link. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_RETRAIN
value|0x20
comment|/* Retrain the link. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_CCCFG
value|0x40
comment|/* Common clock config. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_EXT_SYNC
value|0x80
comment|/* Extended Sync. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_CLK_PWRMGMT
value|0x100
comment|/* Enable clk pwr mgmt. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_HW_AUTO_DIS
value|0x200
comment|/* Hw autonomous w/dis */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_BWM_INTR_EN
value|0x400
comment|/* Bw mgmt intr enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ABW_INTR_EN
value|0x800
comment|/* Autonomous BW int en */
name|u32
name|pci_e_stlcap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_ATTN_BTTN
value|0x1
comment|/* Attention Button Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_PWR_CTRL
value|0x2
comment|/* Power Control Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_MRL_SENS
value|0x4
comment|/* MRL Sesor Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_ATTN_IND
value|0x8
comment|/* Attention Ind Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_PWR_IND
value|0x10
comment|/* Power Indicator Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_HP_SURP
value|0x20
comment|/* Hot-Plug Surprise */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_HP_CAP
value|0x40
comment|/* Hot-Plug Surprise */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_VAL
value|0x7F80
comment|/* Hot-Plug Surprise */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_250
value|0xF0
comment|/* 250 W Slot Power Limit */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_275
value|0xF1
comment|/* 275 W Slot Power Limit */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_300
value|0xF2
comment|/* 300 W Slot Power Limit */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_LIM
value|0x18000
comment|/* Hot-Plug Surprise */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_1X
value|0x0
comment|/* 1.0x */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_XBY10
value|0x1
comment|/* 0.1x */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_XBY100
value|0x2
comment|/* 0.01x */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_XBY1000
value|0x3
comment|/* 0.001x */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_EM_INTR_LOCK
value|0x20000
comment|/* Ele-mec Intrlock Pres */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_NO_CMD_CMPL
value|0x40000
comment|/* No Command Compl Supp */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_PHY_SL_NO
value|0xFFF80000
comment|/* Phy Slot Number */
name|u16
name|pci_e_stlsta
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_ATTN_BTN
value|0x1
comment|/* Attention Button Pressed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PF_DET
value|0x2
comment|/* Power Fault Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_MRL_SENS_CH
value|0x4
comment|/* MRL Sensor Changed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PDET_CH
value|0x8
comment|/* Presence Detect Changed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_CMD_COMPL
value|0x10
comment|/* Command Completed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_MRL_SENS_STA
value|0x20
comment|/* MRL Sensor State */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_MRL_SENS_CL
value|0x0
comment|/* MRL Sensor State - closed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_MRL_SENS_OP
value|0x1
comment|/* MRL Sensor State - open */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PDET_STA
value|0x400
comment|/* Presence Detect State */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PDET_EMPTY
value|0x0
comment|/* Clost Empty */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PDET_PRESENT
value|0x1
comment|/* Card Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_EM_IL_STA
value|0x80
comment|/* Ele-mec Intrlock Ctrl */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_EM_IL_DIS
value|0x0
comment|/* Disengaged */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_EM_IL_EN
value|0x1
comment|/* Engaged */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_DLL_ST_CH
value|0x100
comment|/* DL State Changed */
name|u16
name|pci_e_stlctl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATTN_BTN_EN
value|0x1
comment|/* Atten Btn pressed en */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PF_DET_EN
value|0x2
comment|/* Pwr Fault Detected En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_MRL_SENS_EN
value|0x4
comment|/* MRL Sensor Changed En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PDET_CH_EN
value|0x8
comment|/* Presence Detect Changed En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_CC_INTR_EN
value|0x10
comment|/* Cmmd Completed Intr En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_HP_INTR_EN
value|0x20
comment|/* Hot-Plug Intr Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_CTRL
value|0xC0
comment|/* Attention Ind Ctrl */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_RES
value|0x0
comment|/* Reserved */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_ON
value|0x1
comment|/* On */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_BLNK
value|0x2
comment|/* Blink */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_OFF
value|0x3
comment|/* Off */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_CTRL
value|0x300
comment|/* POwer Ind Control */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_RES
value|0x0
comment|/* Reserved */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_ON
value|0x1
comment|/* On */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_BLNK
value|0x2
comment|/* Blink */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_OFF
value|0x3
comment|/* Off */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWRCTRL_CTRL
value|0x400
comment|/* Power Controller Ctrl */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWRCTRL_on
value|0x0
comment|/* Power on */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWRCTRL_off
value|0x1
comment|/* Power off */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_EM_IL_CTRL
value|0x800
comment|/* Ele-mec Intrlock Ctrl */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_DLL_ST_CH_EN
value|0x1000
comment|/* DL State Changed En */
name|u16
name|pci_e_rtcap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCAP_CRS_SW_VIS
value|0x01
comment|/* CRS Software Visibility */
name|u16
name|pci_e_rtctl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_SECEE
value|0x01
comment|/* Sys Err on Correctable Error */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_SENFEE
value|0x02
comment|/* Sys Err on Non-Fatal Error */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_SEFEE
value|0x04
comment|/* Sys Err on Fatal Error */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_PMEIE
value|0x08
comment|/* PME Intr Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_CRSSVE
value|0x10
comment|/* CRS SW Visibility Enable */
name|u32
name|pci_e_rtsta
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTSTA_PME_REQ_ID
value|0xFFFF
comment|/* PME Requestor ID */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTSTA_PME_STATUS
value|0x10000
comment|/* PME status */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTSTA_PME_PENDING
value|0x20000
comment|/* PME Pending */
else|#
directive|else
name|u8
name|capability_id
decl_stmt|;
name|u8
name|next_capability_ptr
decl_stmt|;
name|u16
name|pci_e_flags
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_FLAGS_VERS
value|0x000f
comment|/* Capability version */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_FLAGS_TYPE
value|0x00f0
comment|/* Device/Port type */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_ENDPOINT
value|0x0
comment|/* Express Endpoint */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_LEG_END
value|0x1
comment|/* Legacy Endpoint */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_ROOT_PORT
value|0x4
comment|/* Root Port */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_UPSTREAM
value|0x5
comment|/* Upstream Port */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_DOWNSTREAM
value|0x6
comment|/* Downstream Port */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_TYPE_PCI_BRIDGE
value|0x7
comment|/* PCI/PCI-X Bridge */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_FLAGS_SLOT
value|0x0100
comment|/* Slot implemented */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_FLAGS_IRQ
value|0x3e00
comment|/* Interrupt message number */
name|u32
name|pci_e_devcap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PAYLOAD
value|0x07
comment|/* Max_Payload_Size */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PHANTOM
value|0x18
comment|/* Phantom functions */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_EXT_TAG
value|0x20
comment|/* Extended tags */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_L0S
value|0x1c0
comment|/* L0s Acceptable Latency */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_L1
value|0xe00
comment|/* L1 Acceptable Latency */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_ATN_BUT
value|0x1000
comment|/* Attention Button Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_ATN_IND
value|0x2000
comment|/* Attention Ind Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PWR_IND
value|0x4000
comment|/* Power Indicator Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PWR_VAL
value|0x3fc0000
comment|/* Slot Power Limit Value */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCAP_PWR_SCL
value|0xc000000
comment|/* Slot Power Limit Scale */
name|u16
name|pci_e_devctl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_CERE
value|0x0001
comment|/* Corr'ble Err Reporting En. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_NFERE
value|0x0002
comment|/* Non-Fatal Err Reporting En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_FERE
value|0x0004
comment|/* Fatal Err Reporting En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_URRE
value|0x0008
comment|/* Unsupp Req Reporting En. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_RELAX_EN
value|0x0010
comment|/* Enable relaxed ordering */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_PAYLOAD
value|0x00e0
comment|/* Max_Payload_Size */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_EXT_TAG
value|0x0100
comment|/* Extended Tag Field Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_PHANTOM
value|0x0200
comment|/* Phantom Functions Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_AUX_PME
value|0x0400
comment|/* Auxiliary Power PM Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_NOSNOOP_EN
value|0x0800
comment|/* Enable No Snoop */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVCTL_READRQ
value|0x7000
comment|/* Max_Read_Request_Size */
name|u16
name|pci_e_devsta
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_CED
value|0x01
comment|/* Correctable Error Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_NFED
value|0x02
comment|/* Non-Fatal Error Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_FED
value|0x04
comment|/* Fatal Error Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_URD
value|0x08
comment|/* Unsupp Request Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_AUXPD
value|0x10
comment|/* AUX Power Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_DEVSTA_TRPND
value|0x20
comment|/* Transactions Pending */
name|u32
name|pci_e_lnkcap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_SPEED
value|0xf
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LS_2_5
value|0x1
comment|/* 2.5 Gb/s supported. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LS_5
value|0x2
comment|/* 5 and 2.5 Gb/s supported. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_WIDTH
value|0x3f0
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_RES
value|0x0
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X1
value|0x1
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X2
value|0x2
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X4
value|0x4
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X8
value|0x8
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X12
value|0xa
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X16
value|0x10
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LW_X32
value|0x20
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_ASPM
value|0xc00
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LASPM_RES1
value|0x0
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LASPM_LO
value|0x1
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LASPM_RES2
value|0x2
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LASPM_L0_L1
value|0x3
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_LAT
value|0x7000
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_LT_64
value|0x0
comment|/* Less than 64 ns. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_64_128
value|0x1
comment|/* 64ns to less than 128ns. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_128_256
value|0x2
comment|/* 128ns to less than 256ns. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_256_512
value|0x3
comment|/* 256ns to less than 512ns. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_512_1us
value|0x4
comment|/* 512ns to less than 1us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_1us_2us
value|0x5
comment|/* 1us to less than 2us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_2us_4us
value|0x6
comment|/* 2us-4us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L0_GT_4us
value|0x7
comment|/* More than 4us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_LAT
value|0x38000
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_LT_1us
value|0x0
comment|/* Less than 1us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_1us_2us
value|0x1
comment|/* 1us to less than 2us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_2us_4us
value|0x2
comment|/* 2us to less than 4us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_4us_8us
value|0x3
comment|/* 4us to less than 8us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_8us_16us
value|0x4
comment|/* 8us to less than 16us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_16us_32us
value|0x5
comment|/* 16us to less than 32us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_32us_64us
value|0x6
comment|/* 32us-64us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_L1_GT_64us
value|0x7
comment|/* More than 64us. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_CLK_PWR_MGMT
value|0x40000
comment|/* Clock power mgmt */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_DOWN_ERR_CAP
value|0x80000
comment|/* Down error capable. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_ACT_CAP
value|0x100000
comment|/* DL active rep cap. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_BW_CAP
value|0x200000
comment|/* DL bw rep cap. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCAP_LNK_PORT_NUM
value|0xff000000
comment|/* Port number. */
name|u16
name|pci_e_lnkctl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM
value|0x3
comment|/* ASPM Control. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM_DISABLED
value|0x0
comment|/* Disabled. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM_L0_EN
value|0x1
comment|/* L0 entry enabled. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM_L1_EN
value|0x2
comment|/* L1 entry enabled. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ASPM_L0_L1_EN
value|0x3
comment|/* L0& L1 entry enabled. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_RCB
value|0x8
comment|/* Read Completion Boundary. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_RCB_64
value|0x0
comment|/* RCB 64 bytes. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_RCB_128
value|0x1
comment|/* RCB 128 bytes. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_DISABLED
value|0x10
comment|/* Disables the link. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_RETRAIN
value|0x20
comment|/* Retrain the link. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_CCCFG
value|0x40
comment|/* Common clock config. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_EXT_SYNC
value|0x80
comment|/* Extended Sync. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_CLK_PWRMGMT
value|0x100
comment|/* Enable clock power mgmt */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_HW_AUTO_DIS
value|0x200
comment|/* HW autonomous with dis */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_BWM_INTR_EN
value|0x400
comment|/* Bw mgmt interrupt enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKCTL_ABW_INTR_EN
value|0x800
comment|/* Autonomous BW int enable */
name|u16
name|pci_e_lnksta
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LNK_SPEED
value|0xf
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LS_2_5
value|0x1
comment|/* 2.5 Gb/s supported. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LS_5
value|0x2
comment|/* 5 and 2.5 Gb/s supported */
comment|/* Supported Link speeds. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LNK_WIDTH
value|0x3f0
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_RES
value|0x0
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X1
value|0x1
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X2
value|0x2
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X4
value|0x4
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X8
value|0x8
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X12
value|0xa
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X16
value|0x10
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LW_X32
value|0x20
comment|/* Reserved. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_LNK_TRAIN
value|0x800
comment|/* Link training. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_SCLK_CFG
value|0x1000
comment|/* Slot Clock Config. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_DLL_ACTIVE
value|0x2000
comment|/* Data LL Active. */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_BWM_STA
value|0x4000
comment|/* Bw mgmt intr enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_LNKSTA_ABW_STA
value|0x8000
comment|/* Autonomous BW intr en */
name|u32
name|pci_e_stlcap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_ATTN_BTTN
value|0x1
comment|/* Attention Button Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_PWR_CTRL
value|0x2
comment|/* Power Control Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_MRL_SENS
value|0x4
comment|/* MRL Sesor Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_ATTN_IND
value|0x8
comment|/* Attention Ind Present */
comment|/* Power Indicator Present */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_PWR_IND
value|0x10
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_HP_SURP
value|0x20
comment|/* Hot-Plug Surprise */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_HP_CAP
value|0x40
comment|/* Hot-Plug Surprise */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_VAL
value|0x7F80
comment|/* Hot-Plug Surprise */
comment|/* 250 W Slot Power Limit */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_250
value|0xF0
comment|/* 275 W Slot Power Limit */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_275
value|0xF1
comment|/* 300 W Slot Power Limit */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_300
value|0xF2
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_LIM
value|0x18000
comment|/* Hot-Plug Surprise */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_1X
value|0x0
comment|/* 1.0x */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_XBY10
value|0x1
comment|/* 0.1x */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_XBY100
value|0x2
comment|/* 0.01x */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_SL_PWR_XBY1000
value|0x3
comment|/* 0.001x */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_EM_INTR_LOCK
value|0x20000
comment|/* Ele-mec Intrlock Pres */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_NO_CMD_CMPL
value|0x40000
comment|/* No Cmd Completed Supp */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCAP_PHY_SL_NO
value|0xFFF80000
comment|/* Phys Slot Number */
name|u16
name|pci_e_stlctl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATTN_BTN_EN
value|0x1
comment|/* Atten Bttn pressed en */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PF_DET_EN
value|0x2
comment|/* Power Fault Detected En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_MRL_SENS_EN
value|0x4
comment|/* MRL Sensor Changed Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PDET_CH_EN
value|0x8
comment|/* Presence Detect Changed En */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_CC_INTR_EN
value|0x10
comment|/* Cmd Compl Intr Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_HP_INTR_EN
value|0x20
comment|/* Hot-Plug Intr Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_CTRL
value|0xC0
comment|/* Atten Ind Control */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_RES
value|0x0
comment|/* Reserved */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_ON
value|0x1
comment|/* On */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_BLNK
value|0x2
comment|/* Blink */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_ATN_IND_OFF
value|0x3
comment|/* Off */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_CTRL
value|0x300
comment|/* Power Ind Control */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_RES
value|0x0
comment|/* Reserved */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_ON
value|0x1
comment|/* On */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_BLNK
value|0x2
comment|/* Blink */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWR_IND_OFF
value|0x3
comment|/* Off */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWRCTRL_CTRL
value|0x400
comment|/* Power Controller Ctrl */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWRCTRL_on
value|0x0
comment|/* Power on */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_PWRCTRL_off
value|0x1
comment|/* Power off */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_EM_IL_CTRL
value|0x800
comment|/* Ele-mec Intrlock Ctrl */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLCTL_DLL_ST_CH_EN
value|0x1000
comment|/* DL State Changed En */
name|u16
name|pci_e_stlsta
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_ATTN_BTN
value|0x1
comment|/* Attention Button Pressed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PF_DET
value|0x2
comment|/* Power Fault Detected */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_MRL_SENS_CH
value|0x4
comment|/* MRL Sensor Changed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PDET_CH
value|0x8
comment|/* Presence Detect Changed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_CMD_COMPL
value|0x10
comment|/* Command Completed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_MRL_SENS_STA
value|0x20
comment|/* MRL Sensor State */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_MRL_SENS_CL
value|0x0
comment|/* MRL Sensor State - closed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_MRL_SENS_OP
value|0x1
comment|/* MRL Sensor State - open */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PDET_STA
value|0x400
comment|/* Presence Detect State */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PDET_EMPTY
value|0x0
comment|/* Clost Empty */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_PDET_PRESENT
value|0x1
comment|/* Card Present */
comment|/* Ele-mec Interlock Control */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_EM_IL_STA
value|0x80
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_EM_IL_DIS
value|0x0
comment|/* Disengaged */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_EM_IL_EN
value|0x1
comment|/* Engaged */
comment|/* DL Layer State Changed */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_STLSTA_DLL_ST_CH
value|0x100
name|u16
name|pci_e_rtctl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_SECEE
value|0x01
comment|/* Sys Err on Correctable Error */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_SENFEE
value|0x02
comment|/* Sys Err on Non-Fatal Error */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_SEFEE
value|0x04
comment|/* Sys Err on Fatal Error */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_PMEIE
value|0x08
comment|/* PME Interrupt Enable */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCTL_CRSSVE
value|0x10
comment|/* CRS SW Visibility Enable */
name|u16
name|pci_e_rtcap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTCAP_CRS_SW_VIS
value|0x01
comment|/* CRS SW Visibility */
name|u32
name|pci_e_rtsta
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTSTA_PME_REQ_ID
value|0xFFFF
comment|/* PME Requestor ID */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTSTA_PME_STATUS
value|0x10000
comment|/* PME status */
define|#
directive|define
name|VXGE_HAL_PCI_EXP_RTSTA_PME_PENDING
value|0x20000
comment|/* PME Pending */
endif|#
directive|endif
block|}
name|vxge_hal_pci_e_capability_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u32
name|vxge_hal_pci_e_caps_offset_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_EXT_CAP_ID
parameter_list|(
name|header
parameter_list|)
value|(header& 0x0000ffff)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_EXT_CAP_VER
parameter_list|(
name|header
parameter_list|)
value|((header>> 16)& 0xf)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_EXT_CAP_NEXT
parameter_list|(
name|header
parameter_list|)
value|((header>> 20)& 0xffc)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_EXT_CAP_ID_ERR
value|1
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_EXT_CAP_ID_VC
value|2
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_EXT_CAP_ID_DSN
value|3
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_PCI_EXT_CAP_ID_PWR
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_err_capability_t
block|{
name|u32
name|pci_err_header
decl_stmt|;
name|u32
name|pci_err_uncor_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_ERR_UNC_TRAIN
value|0x00000001
comment|/* Training */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_UNC_DLP
value|0x00000010
comment|/* Data Link Protocol */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_UNC_POISON_TLP
value|0x00001000
comment|/* Poisoned TLP */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_UNC_FCP
value|0x00002000
comment|/* Flow Control Protocol */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_UNC_COMP_TIME
value|0x00004000
comment|/* Completion Timeout */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_UNC_COMP_ABORT
value|0x00008000
comment|/* Completer Abort */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_UNC_UNX_COMP
value|0x00010000
comment|/* Unexpected Completion */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_UNC_RX_OVER
value|0x00020000
comment|/* Receiver Overflow */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_UNC_MALF_TLP
value|0x00040000
comment|/* Malformed TLP */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_UNC_ECRC
value|0x00080000
comment|/* ECRC Error Status */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_UNC_UNSUP
value|0x00100000
comment|/* Unsupported Request */
name|u32
name|pci_err_uncor_mask
decl_stmt|;
name|u32
name|pci_err_uncor_server
decl_stmt|;
name|u32
name|pci_err_cor_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_ERR_COR_RCVR
value|0x00000001
comment|/* Receiver Error Status */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_COR_BAD_TLP
value|0x00000040
comment|/* Bad TLP Status */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_COR_BAD_DLLP
value|0x00000080
comment|/* Bad DLLP Status */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_COR_REP_ROLL
value|0x00000100
comment|/* REPLAY_NUM Rollover */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_COR_REP_TIMER
value|0x00001000
comment|/* Replay Timer Timeout */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_COR_MASK
value|20
comment|/* Correctable Error Mask */
name|u32
name|pci_err_cap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_FEP
parameter_list|(
name|x
parameter_list|)
value|((x)& 31)
comment|/* First Error Pointer */
comment|/* ECRC Generation Capable */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_ECRC_GENC
value|0x00000020
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_ECRC_GENE
value|0x00000040
comment|/* ECRC Generation Enable */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_ECRC_CHKC
value|0x00000080
comment|/* ECRC Check Capable */
define|#
directive|define
name|VXGE_HAL_PCI_ERR_CAP_ECRC_CHKE
value|0x00000100
comment|/* ECRC Check Enable */
name|u32
name|err_header_log
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_ERR_HEADER_LOG
parameter_list|(
name|x
parameter_list|)
value|((x)>> 31)
comment|/* Error Header Log */
name|u32
name|unused2
index|[
literal|3
index|]
decl_stmt|;
name|u32
name|pci_err_root_command
decl_stmt|;
name|u32
name|pci_err_root_status
decl_stmt|;
name|u32
name|pci_err_root_cor_src
decl_stmt|;
name|u32
name|pci_err_root_src
decl_stmt|;
block|}
name|vxge_hal_err_capability_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vc_capability_t
block|{
name|u32
name|pci_vc_header
decl_stmt|;
name|u32
name|pci_vc_port_reg1
decl_stmt|;
name|u32
name|pci_vc_port_reg2
decl_stmt|;
name|u32
name|pci_vc_port_ctrl
decl_stmt|;
name|u32
name|pci_vc_port_status
decl_stmt|;
name|u32
name|pci_vc_res_cap
decl_stmt|;
name|u32
name|pci_vc_res_ctrl
decl_stmt|;
name|u32
name|pci_vc_res_status
decl_stmt|;
block|}
name|vxge_hal_vc_capability_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_pwr_budget_capability_t
block|{
name|u32
name|pci_pwr_header
decl_stmt|;
name|u32
name|pci_pwr_dsr
decl_stmt|;
name|u32
name|pci_pwr_data
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_PWR_DATA_BASE
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
comment|/* Base Power */
define|#
directive|define
name|VXGE_HAL_PCI_PWR_DATA_SCALE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 3)
comment|/* Data Scale */
define|#
directive|define
name|VXGE_HAL_PCI_PWR_DATA_PM_SUB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 7)
comment|/* PM Sub State */
define|#
directive|define
name|VXGE_HAL_PCI_PWR_DATA_PM_STATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 3)
comment|/* PM State */
define|#
directive|define
name|VXGE_HAL_PCI_PWR_DATA_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 7)
comment|/* Type */
define|#
directive|define
name|VXGE_HAL_PCI_PWR_DATA_RAIL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 7)
comment|/* Power Rail */
name|u32
name|pci_pwr_cap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_PWR_CAP_BUDGET
parameter_list|(
name|x
parameter_list|)
value|((x)& 1)
comment|/* Include in sys budget */
block|}
name|vxge_hal_pwr_budget_capability_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_pci_e_ext_caps_offset_t
block|{
name|u32
name|err_cap_offset
decl_stmt|;
name|u32
name|vc_cap_offset
decl_stmt|;
name|u32
name|dsn_cap_offset
decl_stmt|;
name|u32
name|pwr_budget_cap_offset
decl_stmt|;
block|}
name|vxge_hal_pci_e_ext_caps_offset_t
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_HAL_REGS_H */
end_comment

end_unit

