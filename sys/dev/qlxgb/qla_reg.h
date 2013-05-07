begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2011-2013 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * File: qla_reg.h  * Author : David C Somayajulu, Qlogic Corporation, Aliso Viejo, CA 92656.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QLA_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_QLA_REG_H_
end_define

begin_comment
comment|/*  * Begin Definitions for QLA82xx Registers  */
end_comment

begin_comment
comment|/*  * Register offsets for QLA8022  */
end_comment

begin_comment
comment|/******************************  * PCIe Registers  ******************************/
end_comment

begin_define
define|#
directive|define
name|Q8_CRB_WINDOW_2M
value|0x130060
end_define

begin_define
define|#
directive|define
name|Q8_INT_VECTOR
value|0x130100
end_define

begin_define
define|#
directive|define
name|Q8_INT_MASK
value|0x130104
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_STATUS_F0
value|0x130118
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_MASK_F0
value|0x130128
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_STATUS_F1
value|0x130160
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_MASK_F1
value|0x130170
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_STATUS_F2
value|0x130164
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_MASK_F2
value|0x130174
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_STATUS_F3
value|0x130168
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_MASK_F3
value|0x130178
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_STATUS_F4
value|0x130360
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_MASK_F4
value|0x130370
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_STATUS_F5
value|0x130364
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_MASK_F5
value|0x130374
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_STATUS_F6
value|0x130368
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_MASK_F6
value|0x130378
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_STATUS_F7
value|0x13036C
end_define

begin_define
define|#
directive|define
name|Q8_INT_TARGET_MASK_F7
value|0x13037C
end_define

begin_define
define|#
directive|define
name|Q8_SEM2_LOCK
value|0x13C010
end_define

begin_define
define|#
directive|define
name|Q8_SEM2_UNLOCK
value|0x13C014
end_define

begin_define
define|#
directive|define
name|Q8_SEM3_LOCK
value|0x13C018
end_define

begin_define
define|#
directive|define
name|Q8_SEM3_UNLOCK
value|0x13C01C
end_define

begin_define
define|#
directive|define
name|Q8_SEM5_LOCK
value|0x13C028
end_define

begin_define
define|#
directive|define
name|Q8_SEM5_UNLOCK
value|0x13C02C
end_define

begin_define
define|#
directive|define
name|Q8_SEM7_LOCK
value|0x13C038
end_define

begin_define
define|#
directive|define
name|Q8_SEM7_UNLOCK
value|0x13C03C
end_define

begin_comment
comment|/* Valid bit for a SEM<N>_LOCK registers */
end_comment

begin_define
define|#
directive|define
name|SEM_LOCK_BIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|Q8_ROM_LOCKID
value|0x1B2100
end_define

begin_comment
comment|/*******************************  * Firmware Interface Registers  *******************************/
end_comment

begin_define
define|#
directive|define
name|Q8_FW_VER_MAJOR
value|0x1B2150
end_define

begin_define
define|#
directive|define
name|Q8_FW_VER_MINOR
value|0x1B2154
end_define

begin_define
define|#
directive|define
name|Q8_FW_VER_SUB
value|0x1B2158
end_define

begin_define
define|#
directive|define
name|Q8_FW_VER_BUILD
value|0x1B2168
end_define

begin_define
define|#
directive|define
name|Q8_CMDPEG_STATE
value|0x1B2250
end_define

begin_define
define|#
directive|define
name|Q8_RCVPEG_STATE
value|0x1B233C
end_define

begin_comment
comment|/*  * definitions for Q8_CMDPEG_STATE  */
end_comment

begin_define
define|#
directive|define
name|CMDPEG_PHAN_INIT_COMPLETE
value|0xFF01
end_define

begin_define
define|#
directive|define
name|Q8_ROM_STATUS
value|0x1A0004
end_define

begin_comment
comment|/*  * definitions for Q8_ROM_STATUS  * bit definitions for Q8_UNM_ROMUSB_GLB_STATUS   * 31:3 Reserved; Rest as below  */
end_comment

begin_define
define|#
directive|define
name|ROM_STATUS_RDY
value|0x0004
end_define

begin_define
define|#
directive|define
name|ROM_STATUS_DONE
value|0x0002
end_define

begin_define
define|#
directive|define
name|ROM_STATUS_AUTO_ROM_SHDW
value|0x0001
end_define

begin_define
define|#
directive|define
name|Q8_ASIC_RESET
value|0x1A0008
end_define

begin_comment
comment|/*  * definitions for Q8_ASIC_RESET  */
end_comment

begin_define
define|#
directive|define
name|ASIC_RESET_RST_XDMA
value|0x00800000
end_define

begin_comment
comment|/* Reset XDMA */
end_comment

begin_define
define|#
directive|define
name|ASIC_RESET_PEG_ICACHE
value|0x00000020
end_define

begin_comment
comment|/* Reset PEG_ICACHE */
end_comment

begin_define
define|#
directive|define
name|ASIC_RESET_PEG_DCACHE
value|0x00000010
end_define

begin_comment
comment|/* Reset PEG_DCACHE */
end_comment

begin_define
define|#
directive|define
name|ASIC_RESET_PEG_3
value|0x00000008
end_define

begin_comment
comment|/* Reset PEG_3 */
end_comment

begin_define
define|#
directive|define
name|ASIC_RESET_PEG_2
value|0x00000004
end_define

begin_comment
comment|/* Reset PEG_2 */
end_comment

begin_define
define|#
directive|define
name|ASIC_RESET_PEG_1
value|0x00000002
end_define

begin_comment
comment|/* Reset PEG_1 */
end_comment

begin_define
define|#
directive|define
name|ASIC_RESET_PEG_0
value|0x00000001
end_define

begin_comment
comment|/* Reset PEG_0 */
end_comment

begin_define
define|#
directive|define
name|Q8_COLD_BOOT
value|0x1B21FC
end_define

begin_comment
comment|/*  * definitions for Q8_COLD_BOOT  */
end_comment

begin_define
define|#
directive|define
name|COLD_BOOT_VALUE
value|0x12345678
end_define

begin_define
define|#
directive|define
name|Q8_MIU_TEST_AGT_CTRL
value|0x180090
end_define

begin_define
define|#
directive|define
name|Q8_MIU_TEST_AGT_ADDR_LO
value|0x180094
end_define

begin_define
define|#
directive|define
name|Q8_MIU_TEST_AGT_ADDR_HI
value|0x180098
end_define

begin_define
define|#
directive|define
name|Q8_MIU_TEST_AGT_WRDATA_LO
value|0x1800A0
end_define

begin_define
define|#
directive|define
name|Q8_MIU_TEST_AGT_WRDATA_HI
value|0x1800A4
end_define

begin_define
define|#
directive|define
name|Q8_MIU_TEST_AGT_RDDATA_LO
value|0x1800A8
end_define

begin_define
define|#
directive|define
name|Q8_MIU_TEST_AGT_RDDATA_HI
value|0x1800AC
end_define

begin_define
define|#
directive|define
name|Q8_MIU_TEST_AGT_WRDATA_ULO
value|0x1800B0
end_define

begin_define
define|#
directive|define
name|Q8_MIU_TEST_AGT_WRDATA_UHI
value|0x1800B4
end_define

begin_define
define|#
directive|define
name|Q8_MIU_TEST_AGT_RDDATA_ULO
value|0x1800B8
end_define

begin_define
define|#
directive|define
name|Q8_MIU_TEST_AGT_RDDATA_UHI
value|0x1800BC
end_define

begin_define
define|#
directive|define
name|Q8_PEG_0_RESET
value|0x160018
end_define

begin_define
define|#
directive|define
name|Q8_PEG_0_CLR1
value|0x160008
end_define

begin_define
define|#
directive|define
name|Q8_PEG_0_CLR2
value|0x16000C
end_define

begin_define
define|#
directive|define
name|Q8_PEG_1_CLR1
value|0x161008
end_define

begin_define
define|#
directive|define
name|Q8_PEG_1_CLR2
value|0x16100C
end_define

begin_define
define|#
directive|define
name|Q8_PEG_2_CLR1
value|0x162008
end_define

begin_define
define|#
directive|define
name|Q8_PEG_2_CLR2
value|0x16200C
end_define

begin_define
define|#
directive|define
name|Q8_PEG_3_CLR1
value|0x163008
end_define

begin_define
define|#
directive|define
name|Q8_PEG_3_CLR2
value|0x16300C
end_define

begin_define
define|#
directive|define
name|Q8_PEG_4_CLR1
value|0x164008
end_define

begin_define
define|#
directive|define
name|Q8_PEG_4_CLR2
value|0x16400C
end_define

begin_define
define|#
directive|define
name|Q8_PEG_D_RESET1
value|0x1650EC
end_define

begin_define
define|#
directive|define
name|Q8_PEG_D_RESET2
value|0x16504C
end_define

begin_define
define|#
directive|define
name|Q8_PEG_HALT_STATUS1
value|0x1B20A8
end_define

begin_define
define|#
directive|define
name|Q8_PEG_HALT_STATUS2
value|0x1B20AC
end_define

begin_define
define|#
directive|define
name|Q8_FIRMWARE_HEARTBEAT
value|0x1B20B0
end_define

begin_define
define|#
directive|define
name|Q8_PEG_I_RESET
value|0x16604C
end_define

begin_define
define|#
directive|define
name|Q8_CRB_MAC_BLOCK_START
value|0x1B21C0
end_define

begin_comment
comment|/***************************************************  * Flash ROM Access Registers ( Indirect Registers )  ***************************************************/
end_comment

begin_define
define|#
directive|define
name|Q8_ROM_INSTR_OPCODE
value|0x03310004
end_define

begin_comment
comment|/*  * bit definitions for Q8_ROM_INSTR_OPCODE   * 31:8 Reserved; Rest Below  */
end_comment

begin_define
define|#
directive|define
name|ROM_OPCODE_WR_STATUS_REG
value|0x01
end_define

begin_define
define|#
directive|define
name|ROM_OPCODE_PROG_PAGE
value|0x02
end_define

begin_define
define|#
directive|define
name|ROM_OPCODE_RD_BYTE
value|0x03
end_define

begin_define
define|#
directive|define
name|ROM_OPCODE_WR_DISABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|ROM_OPCODE_RD_STATUS_REG
value|0x05
end_define

begin_define
define|#
directive|define
name|ROM_OPCODE_WR_ENABLE
value|0x06
end_define

begin_define
define|#
directive|define
name|ROM_OPCODE_FAST_RD
value|0x0B
end_define

begin_define
define|#
directive|define
name|ROM_OPCODE_REL_DEEP_PWR_DWN
value|0xAB
end_define

begin_define
define|#
directive|define
name|ROM_OPCODE_BULK_ERASE
value|0xC7
end_define

begin_define
define|#
directive|define
name|ROM_OPCODE_DEEP_PWR_DWN
value|0xC9
end_define

begin_define
define|#
directive|define
name|ROM_OPCODE_SECTOR_ERASE
value|0xD8
end_define

begin_define
define|#
directive|define
name|Q8_ROM_ADDRESS
value|0x03310008
end_define

begin_comment
comment|/*  * bit definitions for Q8_ROM_ADDRESS   * 31:24 Reserved;  * 23:0  Physical ROM Address in bytes  */
end_comment

begin_define
define|#
directive|define
name|Q8_ROM_ADDR_BYTE_COUNT
value|0x03310010
end_define

begin_comment
comment|/*  * bit definitions for Q8_ROM_ADDR_BYTE_COUNT   * 31:2 Reserved;  * 1:0  max address bytes for ROM Interface  */
end_comment

begin_define
define|#
directive|define
name|Q8_ROM_DUMMY_BYTE_COUNT
value|0x03310014
end_define

begin_comment
comment|/*  * bit definitions for Q8_ROM_DUMMY_BYTE_COUNT   * 31:2 Reserved;  * 1:0 dummy bytes for ROM Instructions  */
end_comment

begin_define
define|#
directive|define
name|Q8_ROM_RD_DATA
value|0x03310018
end_define

begin_define
define|#
directive|define
name|Q8_ROM_WR_DATA
value|0x0331000C
end_define

begin_define
define|#
directive|define
name|Q8_ROM_DIRECT_WINDOW
value|0x03310030
end_define

begin_define
define|#
directive|define
name|Q8_ROM_DIRECT_DATA_OFFSET
value|0x03310000
end_define

begin_define
define|#
directive|define
name|Q8_NX_CDRP_CMD_RSP
value|0x1B2218
end_define

begin_define
define|#
directive|define
name|Q8_NX_CDRP_ARG1
value|0x1B221C
end_define

begin_define
define|#
directive|define
name|Q8_NX_CDRP_ARG2
value|0x1B2220
end_define

begin_define
define|#
directive|define
name|Q8_NX_CDRP_ARG3
value|0x1B2224
end_define

begin_define
define|#
directive|define
name|Q8_NX_CDRP_SIGNATURE
value|0x1B2228
end_define

begin_define
define|#
directive|define
name|Q8_LINK_STATE
value|0x1B2298
end_define

begin_define
define|#
directive|define
name|Q8_LINK_SPEED_0
value|0x1B22E8
end_define

begin_comment
comment|/*  * Macros for reading and writing registers  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|Q8_MB
parameter_list|()
value|__asm volatile("mfence" ::: "memory")
end_define

begin_define
define|#
directive|define
name|Q8_WMB
parameter_list|()
value|__asm volatile("sfence" ::: "memory")
end_define

begin_define
define|#
directive|define
name|Q8_RMB
parameter_list|()
value|__asm volatile("lfence" ::: "memory")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Q8_MB
parameter_list|()
end_define

begin_define
define|#
directive|define
name|Q8_WMB
parameter_list|()
end_define

begin_define
define|#
directive|define
name|Q8_RMB
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|READ_REG32
parameter_list|(
name|ha
parameter_list|,
name|reg
parameter_list|)
value|bus_read_4((ha->pci_reg), reg)
end_define

begin_define
define|#
directive|define
name|READ_OFFSET32
parameter_list|(
name|ha
parameter_list|,
name|off
parameter_list|)
value|READ_REG32(ha, off)
end_define

begin_define
define|#
directive|define
name|WRITE_REG32
parameter_list|(
name|ha
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|{\ 		bus_write_4((ha->pci_reg), reg, val);\ 		bus_read_4((ha->pci_reg), reg);\ 	}
end_define

begin_define
define|#
directive|define
name|WRITE_REG32_MB
parameter_list|(
name|ha
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|{\ 		Q8_WMB();\ 		bus_write_4((ha->pci_reg), reg, val);\ 	}
end_define

begin_define
define|#
directive|define
name|WRITE_OFFSET32
parameter_list|(
name|ha
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|{\ 			bus_write_4((ha->pci_reg), off, val);\ 			bus_read_4((ha->pci_reg), off);\ 		}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QLA_REG_H_ */
end_comment

end_unit

