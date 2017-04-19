begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCICS_REG_DRIVER_H
end_ifndef

begin_define
define|#
directive|define
name|_PCICS_REG_DRIVER_H
end_define

begin_comment
comment|/* offset of configuration space in the pci core register */
end_comment

begin_define
define|#
directive|define
name|PCICFG_OFFSET
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCICFG_VENDOR_ID_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_ID_OFFSET
value|0x02
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_IO_SPACE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_MEM_SPACE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_BUS_MASTER
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_SPECIAL_CYCLES
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_MWI_CYCLES
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_VGA_SNOOP
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_PERR_ENA
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_STEPPING
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_SERR_ENA
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_FAST_B2B
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_INT_DISABLE
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_RESERVED
value|(0x1f<<11)
end_define

begin_define
define|#
directive|define
name|PCICFG_STATUS_OFFSET
value|0x06
end_define

begin_define
define|#
directive|define
name|PCICFG_REVISION_ID_OFFSET
value|0x08
end_define

begin_define
define|#
directive|define
name|PCICFG_REVESION_ID_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|PCICFG_REVESION_ID_ERROR_VAL
value|0xff
end_define

begin_define
define|#
directive|define
name|PCICFG_CACHE_LINE_SIZE
value|0x0c
end_define

begin_define
define|#
directive|define
name|PCICFG_LATENCY_TIMER
value|0x0d
end_define

begin_define
define|#
directive|define
name|PCICFG_HEADER_TYPE
value|0x0e
end_define

begin_define
define|#
directive|define
name|PCICFG_HEADER_TYPE_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|PCICFG_HEADER_TYPE_BRIDGE
value|1
end_define

begin_define
define|#
directive|define
name|PCICFG_HEADER_TYPE_CARDBUS
value|2
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_1_LOW
value|0x10
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_1_HIGH
value|0x14
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_2_LOW
value|0x18
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_2_HIGH
value|0x1c
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_3_LOW
value|0x20
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_3_HIGH
value|0x24
end_define

begin_define
define|#
directive|define
name|PCICFG_SUBSYSTEM_VENDOR_ID_OFFSET
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCICFG_SUBSYSTEM_ID_OFFSET
value|0x2e
end_define

begin_define
define|#
directive|define
name|PCICFG_INT_LINE
value|0x3c
end_define

begin_define
define|#
directive|define
name|PCICFG_INT_PIN
value|0x3d
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY
value|0x48
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_VERSION
value|(0x3<<16)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_CLOCK
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_RESERVED
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_DSI
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_AUX_CURRENT
value|(0x7<<22)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_D1_SUPPORT
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_D2_SUPPORT
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D0
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D1
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D2
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D3_HOT
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D3_COLD
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CSR_OFFSET
value|0x4c
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CSR_STATE
value|(0x3<<0)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CSR_PME_ENABLE
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CSR_PME_STATUS
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CAP_ID_OFFSET
value|0x58
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_ENABLE
value|(0x1<<16)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_MCAP
value|(0x7<<17)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_MENA
value|(0x7<<20)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_64_BIT_ADDR_CAP
value|(0x1<<23)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_MSI_PVMASK_CAPABLE
value|(0x1<<24)
end_define

begin_define
define|#
directive|define
name|PCICFG_GRC_ADDRESS
value|0x78
end_define

begin_define
define|#
directive|define
name|PCICFG_GRC_DATA
value|0x80
end_define

begin_define
define|#
directive|define
name|PCICFG_ME_REGISTER
value|0x98
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CAP_ID_OFFSET
value|0xa0
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CONTROL_TABLE_SIZE
value|(0x7ff<<16)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CONTROL_RESERVED
value|(0x7<<27)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CONTROL_FUNC_MASK
value|(0x1<<30)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CONTROL_MSIX_ENABLE
value|(0x1<<31)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_CONTROL
value|0xb4
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_CONTROL_NP_TRANSACTION_PEND
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS
value|0xb6
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_CORR_ERR_DET
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_NON_FATAL_ERR_DET
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_FATAL_ERR_DET
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_UNSUP_REQ_DET
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_AUX_PWR_DET
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_NO_PEND
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PCICFG_LINK_CONTROL
value|0xbc
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_CONTROL_2
value|(0xd4)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_CONTROL_2_ATOMIC_REQ_ENABLE
value|(1<<6)
end_define

begin_comment
comment|/* config_2 offset */
end_comment

begin_define
define|#
directive|define
name|GRC_CONFIG_2_SIZE_REG
value|0x408
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_DISABLED
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_64K
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_128K
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_256K
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_512K
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_1M
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_2M
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_4M
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_8M
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_16M
value|(9L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_32M
value|(10L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_64M
value|(11L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_128M
value|(12L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_256M
value|(13L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_512M
value|(14L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_1G
value|(15L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_64ENA
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_RETRY
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_CFG_CYCLE_RETRY
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_FIRST_CFG_DONE
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE
value|(0xffL<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_DISABLED
value|(0L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_2K
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_4K
value|(2L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_8K
value|(3L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_16K
value|(4L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_32K
value|(5L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_64K
value|(6L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_128K
value|(7L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_256K
value|(8L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_512K
value|(9L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_1M
value|(10L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_2M
value|(11L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_4M
value|(12L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_8M
value|(13L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_16M
value|(14L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_32M
value|(15L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR_PREFETCH
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_RESERVED0
value|(0x7fffL<<17)
end_define

begin_comment
comment|/* config_3 offset */
end_comment

begin_define
define|#
directive|define
name|GRC_CONFIG_3_SIZE_REG
value|0x40c
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_STICKY_BYTE
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_FORCE_PME
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_PME_STATUS
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_PME_ENABLE
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_PM_STATE
value|(0x3L<<27)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_VAUX_PRESET
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_PCI_POWER
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|GRC_REG_DEVICE_CONTROL
value|0x4d8
end_define

begin_comment
comment|/* When VF Enable is cleared(after it was previously set),  * this register will read a value of 1, indicating that all the  * VFs that belong to this PF should be flushed.  * Software should clear this bit within 1 second of VF Enable  * being set by writing a 1 to it, so that VFs are visible to the system  * again.WC  */
end_comment

begin_define
define|#
directive|define
name|PCIE_SRIOV_DISABLE_IN_PROGRESS
value|(1<< 29)
end_define

begin_comment
comment|/* When FLR is initiated, this register will read a value of 1 indicating  * that the Function is in FLR state. Func can be brought out of FLR state  * either bywriting 1 to this register (at least 50 ms after FLR was  * initiated),or it can also be cleared automatically after 55 ms if  * auto_clear bit in private reg space is set. This bit also exists in  * VF register space WC  */
end_comment

begin_define
define|#
directive|define
name|PCIE_FLR_IN_PROGRESS
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|GRC_BAR2_CONFIG
value|0x4e0
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_DISABLED
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_64K
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_128K
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_256K
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_512K
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_1M
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_2M
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_4M
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_8M
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_16M
value|(9L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_32M
value|(10L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_64M
value|(11L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_128M
value|(12L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_256M
value|(13L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_512M
value|(14L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_1G
value|(15L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_64ENA
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|GRC_BAR3_CONFIG
value|0x4f4
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_DISABLED
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_64K
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_128K
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_256K
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_512K
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_1M
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_2M
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_4M
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_8M
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_16M
value|(9L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_32M
value|(10L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_64M
value|(11L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_128M
value|(12L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_256M
value|(13L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_512M
value|(14L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_1G
value|(15L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_64ENA
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PCI_PM_DATA_A
value|0x410
end_define

begin_define
define|#
directive|define
name|PCI_PM_DATA_B
value|0x414
end_define

begin_define
define|#
directive|define
name|PCI_ID_VAL1
value|0x434
end_define

begin_define
define|#
directive|define
name|PCI_ID_VAL2
value|0x438
end_define

begin_define
define|#
directive|define
name|PCI_ID_VAL3
value|0x43c
end_define

begin_define
define|#
directive|define
name|PCI_ID_VAL3_REVISION_ID_ERROR
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|GRC_CONFIG_REG_VF_BAR_REG_1
value|0x608
end_define

begin_define
define|#
directive|define
name|GRC_CONFIG_REG_VF_BAR_REG_BAR0_SIZE
value|0xf
end_define

begin_define
define|#
directive|define
name|GRC_CONFIG_REG_VF_MSIX_CONTROL
value|0x61C
end_define

begin_comment
comment|/* This field resides in VF only and does not exist in PF.  * This register controls the read value of the MSIX_CONTROL[10:0] register  * in the VF configuration space. A value of "00000000011" indicates  * a table size of 4. The value is controlled by IOV_MSIX_TBL_SIZ  * define in version.v  */
end_comment

begin_define
define|#
directive|define
name|GRC_CR_VF_MSIX_CTRL_VF_MSIX_TBL_SIZE_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|GRC_CONFIG_REG_PF_INIT_VF
value|0x624
end_define

begin_comment
comment|/* First VF_NUM for PF is encoded in this register.  * The number of VFs assigned to a PF is assumed to be a multiple of 8.  * Software should program these bits based on Total Number of VFs programmed  * for each PF.  * Since registers from 0x000-0x7ff are spilt across functions, each PF will  * have the same location for the same 4 bits  */
end_comment

begin_define
define|#
directive|define
name|GRC_CR_PF_INIT_VF_PF_FIRST_VF_NUM_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5
value|0x814
end_define

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_UNKNOWNTYPE_ERR_ATTN
value|(1<< 29)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_BOUNDARY4K_ERR_ATTN
value|(1<< 28)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_MRRS_ERR_ATTN
value|(1<< 27)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_MPS_ERR_ATTN
value|(1<< 26)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_TTX_BRIDGE_FORWARD_ERR
value|(1<< 25)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_TTX_TXINTF_OVERFLOW
value|(1<< 24)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_PHY_ERR_ATTN
value|(1<< 23)
end_define

begin_comment
comment|/*RO*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_DL_ERR_ATTN
value|(1<< 22)
end_define

begin_comment
comment|/*RO*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_TTX_ERR_NP_TAG_IN_USE
value|(1<< 21)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_TRX_ERR_UNEXP_RTAG
value|(1<< 20)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_PRI_SIG_TARGET_ABORT1
value|(1<< 19)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_UNSPPORT1
value|(1<< 18)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_ECRC1
value|(1<< 17)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_MALF_TLP1
value|(1<< 16)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_RX_OFLOW1
value|(1<< 15)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_UNEXP_CPL1
value|(1<< 14)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_MASTER_ABRT1
value|(1<< 13)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_CPL_TIMEOUT1
value|(1<< 12)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_FC_PRTL1
value|(1<< 11)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_PSND_TLP1
value|(1<< 10)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_PRI_SIG_TARGET_ABORT
value|(1<< 9)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_UNSPPORT
value|(1<< 8)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_ECRC
value|(1<< 7)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_MALF_TLP
value|(1<< 6)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_RX_OFLOW
value|(1<< 5)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_UNEXP_CPL
value|(1<< 4)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_MASTER_ABRT
value|(1<< 3)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_CPL_TIMEOUT
value|(1<< 2)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_FC_PRTL
value|(1<< 1)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_PSND_TLP
value|(1<< 0)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT
value|0x854
end_define

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_PRI_SIG_TARGET_ABORT4
value|(1<< 29)
end_define

begin_comment
comment|/* WC */
end_comment

begin_comment
comment|/*Unsupported Request Error Status in function4, if set, generate  *pcie_err_attn output when this error is seen.  WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_UNSPPORT4
value|(1<< 28)
end_define

begin_comment
comment|/*ECRC Error TLP Status Status in function 4, if set,  *generate pcie_err_attn output when this error is seen..WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_ECRC4
value|(1<< 27)
end_define

begin_comment
comment|/*Malformed TLP Status Status in function 4, if set,  *generate pcie_err_attn output when this error is seen..WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_MALF_TLP4
value|(1<< 26)
end_define

begin_comment
comment|/*Receiver Overflow Status Status in function 4, if set,  *generate pcie_err_attn output when this error is seen..WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_RX_OFLOW4
value|(1<< 25)
end_define

begin_comment
comment|/*Unexpected Completion Status Status in function 4, if set,  *generate pcie_err_attn output when this error is seen..WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_UNEXP_CPL4
value|(1<< 24)
end_define

begin_comment
comment|/* Receive UR Statusin function 4. If set, generate pcie_err_attn output  * when this error is seen.  WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_MASTER_ABRT4
value|(1<< 23)
end_define

begin_comment
comment|/* Completer Timeout Status Status in function 4, if set,  * generate pcie_err_attn output when this error is seen..WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_CPL_TIMEOUT4
value|(1<< 22)
end_define

begin_comment
comment|/* Flow Control Protocol Error Status Status in function 4, * if set, generate pcie_err_attn output when this error is seen.  * WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_FC_PRTL4
value|(1<< 21)
end_define

begin_comment
comment|/* Poisoned Error Status Status in function 4, if set, generate  * pcie_err_attn output when this error is seen..WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_PSND_TLP4
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_PRI_SIG_TARGET_ABORT3
value|(1<< 19)
end_define

begin_comment
comment|/* WC */
end_comment

begin_comment
comment|/* Unsupported Request Error Status in function3, if set, generate  * pcie_err_attn output when this error is seen..WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_UNSPPORT3
value|(1<< 18)
end_define

begin_comment
comment|/* ECRC Error TLP Status Status in function 3, if set, generate  * pcie_err_attn output when this error is seen..  WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_ECRC3
value|(1<< 17)
end_define

begin_comment
comment|/* Malformed TLP Status Status in function 3, if set, generate  * pcie_err_attn output when this error is seen..WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_MALF_TLP3
value|(1<< 16)
end_define

begin_comment
comment|/* Receiver Overflow Status Status in function 3, if set, generate  * pcie_err_attn output when this error is seen..WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_RX_OFLOW3
value|(1<< 15)
end_define

begin_comment
comment|/* Unexpected Completion Status Status in function 3, if set, generate  * pcie_err_attn output when this error is seen.  WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_UNEXP_CPL3
value|(1<< 14)
end_define

begin_comment
comment|/* Receive UR Statusin function 3. If set, generate pcie_err_attn output  * when this error is seen.  WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_MASTER_ABRT3
value|(1<< 13)
end_define

begin_comment
comment|/* Completer Timeout Status Status in function 3, if set, generate  * pcie_err_attn output when this error is seen..WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_CPL_TIMEOUT3
value|(1<< 12)
end_define

begin_comment
comment|/* Flow Control Protocol Error Status Status in function 3, if set,  * generate pcie_err_attn output when this error is seen..WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_FC_PRTL3
value|(1<< 11)
end_define

begin_comment
comment|/* Poisoned Error Status Status in function 3, if set, generate  * pcie_err_attn output when this error is seen..WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_PSND_TLP3
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_PRI_SIG_TARGET_ABORT2
value|(1<< 9)
end_define

begin_comment
comment|/* WC */
end_comment

begin_comment
comment|/* Unsupported Request Error Status for Function 2, if set,  * generate pcie_err_attn output when this error is seen.  WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_UNSPPORT2
value|(1<< 8)
end_define

begin_comment
comment|/* ECRC Error TLP Status Status for Function 2, if set, generate  * pcie_err_attn output when this error is seen..WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_ECRC2
value|(1<< 7)
end_define

begin_comment
comment|/* Malformed TLP Status Status for Function 2, if set, generate  * pcie_err_attn output when this error is seen..  WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_MALF_TLP2
value|(1<< 6)
end_define

begin_comment
comment|/* Receiver Overflow Status Status for Function 2, if set, generate  * pcie_err_attn output when this error is seen..  WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_RX_OFLOW2
value|(1<< 5)
end_define

begin_comment
comment|/* Unexpected Completion Status Status for Function 2, if set, generate  * pcie_err_attn output when this error is seen.  WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_UNEXP_CPL2
value|(1<< 4)
end_define

begin_comment
comment|/* Receive UR Statusfor Function 2. If set, generate pcie_err_attn output  * when this error is seen.  WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_MASTER_ABRT2
value|(1<< 3)
end_define

begin_comment
comment|/* Completer Timeout Status Status for Function 2, if set, generate  * pcie_err_attn output when this error is seen.  WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_CPL_TIMEOUT2
value|(1<< 2)
end_define

begin_comment
comment|/* Flow Control Protocol Error Status Status for Function 2, if set,  * generate pcie_err_attn output when this error is seen.  WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_FC_PRTL2
value|(1<< 1)
end_define

begin_comment
comment|/* Poisoned Error Status Status for Function 2, if set, generate  * pcie_err_attn output when this error is seen..  WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_PSND_TLP2
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT
value|0x85C
end_define

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_PRI_SIG_TARGET_ABORT7
value|(1<< 29)
end_define

begin_comment
comment|/* WC */
end_comment

begin_comment
comment|/* Unsupported Request Error Status in function7, if set, generate  * pcie_err_attn output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_UNSPPORT7
value|(1<< 28)
end_define

begin_comment
comment|/* ECRC Error TLP Status Status in function 7, if set, generate  * pcie_err_attn output when this error is seen.. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_ECRC7
value|(1<< 27)
end_define

begin_comment
comment|/* Malformed TLP Status Status in function 7, if set, generate  * pcie_err_attn output when this error is seen.. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_MALF_TLP7
value|(1<< 26)
end_define

begin_comment
comment|/* Receiver Overflow Status Status in function 7, if set, generate  * pcie_err_attn output when this error is seen.. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_RX_OFLOW7
value|(1<< 25)
end_define

begin_comment
comment|/* Unexpected Completion Status Status in function 7, if set, generate  * pcie_err_attn output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_UNEXP_CPL7
value|(1<< 24)
end_define

begin_comment
comment|/* Receive UR Statusin function 7. If set, generate pcie_err_attn  * output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_MASTER_ABRT7
value|(1<< 23)
end_define

begin_comment
comment|/* Completer Timeout Status Status in function 7, if set, generate  * pcie_err_attn output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_CPL_TIMEOUT7
value|(1<< 22)
end_define

begin_comment
comment|/* Flow Control Protocol Error Status Status in function 7, if set,  * generate pcie_err_attn output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_FC_PRTL7
value|(1<< 21)
end_define

begin_comment
comment|/* Poisoned Error Status Status in function 7, if set,  * generate pcie_err_attn output when this error is seen.. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_PSND_TLP7
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_PRI_SIG_TARGET_ABORT6
value|(1<< 19)
end_define

begin_comment
comment|/* WC */
end_comment

begin_comment
comment|/* Unsupported Request Error Status in function6, if set, generate  * pcie_err_attn output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_UNSPPORT6
value|(1<< 18)
end_define

begin_comment
comment|/* ECRC Error TLP Status Status in function 6, if set, generate  * pcie_err_attn output when this error is seen.. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_ECRC6
value|(1<< 17)
end_define

begin_comment
comment|/* Malformed TLP Status Status in function 6, if set, generate  * pcie_err_attn output when this error is seen.. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_MALF_TLP6
value|(1<< 16)
end_define

begin_comment
comment|/* Receiver Overflow Status Status in function 6, if set, generate  * pcie_err_attn output when this error is seen.. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_RX_OFLOW6
value|(1<< 15)
end_define

begin_comment
comment|/* Unexpected Completion Status Status in function 6, if set,  * generate pcie_err_attn output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_UNEXP_CPL6
value|(1<< 14)
end_define

begin_comment
comment|/* Receive UR Statusin function 6. If set, generate pcie_err_attn  * output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_MASTER_ABRT6
value|(1<< 13)
end_define

begin_comment
comment|/* Completer Timeout Status Status in function 6, if set, generate  * pcie_err_attn output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_CPL_TIMEOUT6
value|(1<< 12)
end_define

begin_comment
comment|/* Flow Control Protocol Error Status Status in function 6, if set,  * generate pcie_err_attn output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_FC_PRTL6
value|(1<< 11)
end_define

begin_comment
comment|/* Poisoned Error Status Status in function 6, if set, generate  * pcie_err_attn output when this error is seen.. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_PSND_TLP6
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_PRI_SIG_TARGET_ABORT5
value|(1<< 9)
end_define

begin_comment
comment|/*    WC */
end_comment

begin_comment
comment|/* Unsupported Request Error Status for Function 5, if set,  * generate pcie_err_attn output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_UNSPPORT5
value|(1<< 8)
end_define

begin_comment
comment|/* ECRC Error TLP Status Status for Function 5, if set, generate  * pcie_err_attn output when this error is seen.. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_ECRC5
value|(1<< 7)
end_define

begin_comment
comment|/* Malformed TLP Status Status for Function 5, if set, generate  * pcie_err_attn output when this error is seen.. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_MALF_TLP5
value|(1<< 6)
end_define

begin_comment
comment|/* Receiver Overflow Status Status for Function 5, if set, generate  * pcie_err_attn output when this error is seen.. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_RX_OFLOW5
value|(1<< 5)
end_define

begin_comment
comment|/* Unexpected Completion Status Status for Function 5, if set, generate  * pcie_err_attn output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_UNEXP_CPL5
value|(1<< 4)
end_define

begin_comment
comment|/* Receive UR Statusfor Function 5. If set, generate pcie_err_attn output  * when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_MASTER_ABRT5
value|(1<< 3)
end_define

begin_comment
comment|/* Completer Timeout Status Status for Function 5, if set, generate  * pcie_err_attn output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_CPL_TIMEOUT5
value|(1<< 2)
end_define

begin_comment
comment|/* Flow Control Protocol Error Status Status for Function 5, if set,  * generate pcie_err_attn output when this error is seen. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_FC_PRTL5
value|(1<< 1)
end_define

begin_comment
comment|/* Poisoned Error Status Status for Function 5, if set,  * generate pcie_err_attn output when this error is seen.. WC  */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_PSND_TLP5
value|(1<< 0)
end_define

begin_comment
comment|/* PCI CAPABILITIES  */
end_comment

begin_define
define|#
directive|define
name|PCI_CAP_PCIE
value|0x10
end_define

begin_comment
comment|/*PCIe capability ID*/
end_comment

begin_define
define|#
directive|define
name|PCIE_DEV_CAPS
value|0x04
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PCIE_DEV_CAPS_FLR_CAPABILITY
end_ifndef

begin_define
define|#
directive|define
name|PCIE_DEV_CAPS_FLR_CAPABILITY
value|(1<< 28)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PCIE_DEV_CTRL
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIE_DEV_CTRL_FLR
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCIE_DEV_STATUS
value|0x0A
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PCIE_DEV_STATUS_PENDING_TRANSACTION
end_ifndef

begin_define
define|#
directive|define
name|PCIE_DEV_STATUS_PENDING_TRANSACTION
value|(1<< 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_CAPABILITY_LIST
end_ifndef

begin_comment
comment|/* Ofset of first capability list entry */
end_comment

begin_define
define|#
directive|define
name|PCI_CAPABILITY_LIST
value|0x34
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PCI_CAPABILITY_LIST_MASK
value|0xff
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_CB_CAPABILITY_LIST
end_ifndef

begin_define
define|#
directive|define
name|PCI_CB_CAPABILITY_LIST
value|0x14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__LINUX
argument_list|)
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|PCI_CAP_LIST_ID
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|PCI_CAP_LIST_ID_DEF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__LINUX
argument_list|)
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|PCI_CAP_LIST_NEXT
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|PCI_CAP_LIST_NEXT_DEF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__LINUX
argument_list|)
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|PCI_STATUS
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|PCI_STATUS_DEF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__LINUX
argument_list|)
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|PCI_STATUS_CAP_LIST
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|PCI_STATUS_CAP_LIST_DEF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_CAP_LIST_ID_DEF
end_ifndef

begin_define
define|#
directive|define
name|PCI_CAP_LIST_ID
value|0x0
end_define

begin_comment
comment|/* Capability ID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PCI_CAP_LIST_ID_MASK
value|0xff
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_CAP_LIST_NEXT_DEF
end_ifndef

begin_comment
comment|/* Next capability in the list  */
end_comment

begin_define
define|#
directive|define
name|PCI_CAP_LIST_NEXT
value|0x1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PCI_CAP_LIST_NEXT_MASK
value|0xff
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_STATUS_DEF
end_ifndef

begin_define
define|#
directive|define
name|PCI_STATUS
value|0x6
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_STATUS_CAP_LIST_DEF
end_ifndef

begin_comment
comment|/* Support Capability List  */
end_comment

begin_define
define|#
directive|define
name|PCI_STATUS_CAP_LIST
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_SRIOV_CAP
end_ifndef

begin_comment
comment|/* Some PCI Config defines... need to put this in a better location... */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_CAP
value|0x04
end_define

begin_comment
comment|/* SR-IOV Capabilities */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_CAP_VFM
value|0x01
end_define

begin_comment
comment|/* VF Migration Capable */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_CAP_INTR
parameter_list|(
name|x
parameter_list|)
value|((x)>> 21)
end_define

begin_comment
comment|/* Interrupt Message Number */
end_comment

begin_define
define|#
directive|define
name|PCI_EXT_CAP_ID_SRIOV
value|0x10
end_define

begin_comment
comment|/* Single Root I/O Virtualization */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_CTRL
value|0x08
end_define

begin_comment
comment|/* SR-IOV Control */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_CTRL_VFE
value|0x01
end_define

begin_comment
comment|/* VF Enable */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_CTRL_VFM
value|0x02
end_define

begin_comment
comment|/* VF Migration Enable */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_CTRL_INTR
value|0x04
end_define

begin_comment
comment|/* VF Migration Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_CTRL_MSE
value|0x08
end_define

begin_comment
comment|/* VF Memory Space Enable */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_CTRL_ARI
value|0x10
end_define

begin_comment
comment|/* ARI Capable Hierarchy */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_STATUS
value|0x0a
end_define

begin_comment
comment|/* SR-IOV Status */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_STATUS_VFM
value|0x01
end_define

begin_comment
comment|/* VF Migration Status */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_INITIAL_VF
value|0x0c
end_define

begin_comment
comment|/* Initial VFs */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_TOTAL_VF
value|0x0e
end_define

begin_comment
comment|/* Total VFs */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_NUM_VF
value|0x10
end_define

begin_comment
comment|/* Number of VFs */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_FUNC_LINK
value|0x12
end_define

begin_comment
comment|/* Function Dependency Link */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_VF_OFFSET
value|0x14
end_define

begin_comment
comment|/* First VF Offset */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_VF_STRIDE
value|0x16
end_define

begin_comment
comment|/* Following VF Stride */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_VF_DID
value|0x1a
end_define

begin_comment
comment|/* VF Device ID */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_SUP_PGSIZE
value|0x1c
end_define

begin_comment
comment|/* Supported Page Sizes */
end_comment

begin_define
define|#
directive|define
name|PCI_SRIOV_SYS_PGSIZE
value|0x20
end_define

begin_comment
comment|/* System Page Size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_CAP_ID_EXP
end_ifndef

begin_define
define|#
directive|define
name|PCI_CAP_ID_EXP
value|0x10
end_define

begin_comment
comment|/* PCI Express */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_EXP_DEVCTL
end_ifndef

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL
value|8
end_define

begin_comment
comment|/* Device Control */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_EXP_DEVCTL_RELAX_EN
end_ifndef

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_RELAX_EN
value|0x0010
end_define

begin_comment
comment|/* Enable relaxed ordering */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

