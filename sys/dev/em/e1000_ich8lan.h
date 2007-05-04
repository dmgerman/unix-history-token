begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2007, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_E1000_ICH8LAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_ICH8LAN_H_
end_define

begin_include
include|#
directive|include
file|"e1000_api.h"
end_include

begin_define
define|#
directive|define
name|ICH_FLASH_GFPREG
value|0x0000
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_HSFSTS
value|0x0004
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_HSFCTL
value|0x0006
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_FADDR
value|0x0008
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_FDATA0
value|0x0010
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_READ_COMMAND_TIMEOUT
value|500
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_WRITE_COMMAND_TIMEOUT
value|500
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_ERASE_COMMAND_TIMEOUT
value|3000000
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_LINEAR_ADDR_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_CYCLE_REPEAT_COUNT
value|10
end_define

begin_define
define|#
directive|define
name|ICH_CYCLE_READ
value|0
end_define

begin_define
define|#
directive|define
name|ICH_CYCLE_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|ICH_CYCLE_ERASE
value|3
end_define

begin_define
define|#
directive|define
name|FLASH_GFPREG_BASE_MASK
value|0x1FFF
end_define

begin_define
define|#
directive|define
name|FLASH_SECTOR_ADDR_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|E1000_SHADOW_RAM_WORDS
value|2048
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SEG_SIZE_256
value|256
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SEG_SIZE_4K
value|4096
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SEG_SIZE_8K
value|8192
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SEG_SIZE_64K
value|65536
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SECTOR_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_REG_MAPSIZE
value|0x00A0
end_define

begin_define
define|#
directive|define
name|E1000_ICH_FWSM_RSPCIPHY
value|0x00000040
end_define

begin_comment
comment|/* Reset PHY on PCI Reset */
end_comment

begin_define
define|#
directive|define
name|E1000_ICH_FWSM_DISSW
value|0x10000000
end_define

begin_comment
comment|/* FW Disables SW Writes */
end_comment

begin_define
define|#
directive|define
name|E1000_ICH_FWSM_FW_VALID
value|0x00008000
end_define

begin_comment
comment|/* FW established a valid                                                      * mode.                                                      */
end_comment

begin_define
define|#
directive|define
name|E1000_ICH_MNG_IAMT_MODE
value|0x2
end_define

begin_define
define|#
directive|define
name|ID_LED_DEFAULT_ICH8LAN
value|((ID_LED_DEF1_DEF2<< 12) | \                                  (ID_LED_DEF1_OFF2<<  8) | \                                  (ID_LED_DEF1_ON2<<  4) | \                                  (ID_LED_DEF1_DEF2))
end_define

begin_define
define|#
directive|define
name|E1000_ICH_NVM_SIG_WORD
value|0x13
end_define

begin_define
define|#
directive|define
name|E1000_ICH_NVM_SIG_MASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|E1000_ICH8_LAN_INIT_TIMEOUT
value|1500
end_define

begin_define
define|#
directive|define
name|E1000_FEXTNVM_SW_CONFIG
value|1
end_define

begin_define
define|#
directive|define
name|E1000_FEXTNVM_SW_CONFIG_ICH8M
value|(1<< 27)
end_define

begin_comment
comment|/* Bit redefined for ICH8M :/ */
end_comment

begin_define
define|#
directive|define
name|PCIE_ICH8_SNOOP_ALL
value|PCIE_NO_SNOOP_ALL
end_define

begin_define
define|#
directive|define
name|E1000_ICH_RAR_ENTRIES
value|7
end_define

begin_define
define|#
directive|define
name|PHY_PAGE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|PHY_REG
parameter_list|(
name|page
parameter_list|,
name|reg
parameter_list|)
value|(((page)<< PHY_PAGE_SHIFT) | \                            ((reg)& MAX_PHY_REG_ADDRESS))
end_define

begin_define
define|#
directive|define
name|IGP3_KMRN_DIAG
value|PHY_REG(770, 19)
end_define

begin_comment
comment|/* KMRN Diagnostic */
end_comment

begin_define
define|#
directive|define
name|IGP3_VR_CTRL
value|PHY_REG(776, 18)
end_define

begin_comment
comment|/* Voltage Regulator Control */
end_comment

begin_define
define|#
directive|define
name|IGP3_CAPABILITY
value|PHY_REG(776, 19)
end_define

begin_comment
comment|/* Capability */
end_comment

begin_define
define|#
directive|define
name|IGP3_PM_CTRL
value|PHY_REG(769, 20)
end_define

begin_comment
comment|/* Power Management Control */
end_comment

begin_define
define|#
directive|define
name|IGP3_KMRN_DIAG_PCS_LOCK_LOSS
value|0x0002
end_define

begin_define
define|#
directive|define
name|IGP3_VR_CTRL_DEV_POWERDOWN_MODE_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|IGP3_VR_CTRL_MODE_SHUTDOWN
value|0x0200
end_define

begin_define
define|#
directive|define
name|IGP3_PM_CTRL_FORCE_PWR_DOWN
value|0x0020
end_define

begin_comment
comment|/* Additional interrupts need to be handled for ICH family:     DSW = The FW changed the status of the DISSW bit in FWSM     PHYINT = The LAN connected device generates an interrupt     EPRST = Manageability reset event */
end_comment

begin_define
define|#
directive|define
name|IMS_ICH_ENABLE_MASK
value|(\     E1000_IMS_DSW   | \     E1000_IMS_PHYINT | \     E1000_IMS_EPRST)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

