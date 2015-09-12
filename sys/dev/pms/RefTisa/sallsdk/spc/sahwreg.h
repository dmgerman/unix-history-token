begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file sahwreg.h  *  \brief The file defines the register offset of hardware  */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SAHWREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__SAHWREG_H__
end_define

begin_comment
comment|/* #define MSGU_ACCESS_VIA_XCBI  */
end_comment

begin_comment
comment|/* Defined in build script now */
end_comment

begin_comment
comment|/* Message Unit Registers - BAR0(0x10), BAR0(win) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SPC_I2O_ENABLE
end_ifdef

begin_comment
comment|/* i2o=1 space register offsets - MU_I2O_ENABLE */
end_comment

begin_comment
comment|/* Currently FPGA use these offset */
end_comment

begin_define
define|#
directive|define
name|MSGU_IBDB_SET
value|0x20
end_define

begin_define
define|#
directive|define
name|MSGU_HOST_INT_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|MSGU_HOST_INT_MASK
value|0x34
end_define

begin_define
define|#
directive|define
name|MSGU_IOPIB_INT_STATUS
value|0x40
end_define

begin_define
define|#
directive|define
name|MSGU_IOPIB_INT_MASK
value|0x44
end_define

begin_define
define|#
directive|define
name|MSGU_IBDB_CLEAR
value|0x70
end_define

begin_define
define|#
directive|define
name|MSGU_MSGU_CONTROL
value|0x74
end_define

begin_define
define|#
directive|define
name|MSGU_ODR
value|0x9C
end_define

begin_define
define|#
directive|define
name|MSGU_ODCR
value|0xA0
end_define

begin_define
define|#
directive|define
name|MSGU_SCRATCH_PAD_0
value|0xB0
end_define

begin_define
define|#
directive|define
name|MSGU_SCRATCH_PAD_1
value|0xB4
end_define

begin_define
define|#
directive|define
name|MSGU_SCRATCH_PAD_2
value|0xB8
end_define

begin_define
define|#
directive|define
name|MSGU_SCRATCH_PAD_3
value|0xBC
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* i2o=0 space register offsets - ~MU_I2O_ENABLE */
end_comment

begin_define
define|#
directive|define
name|MSGU_IBDB_SET
value|0x04
end_define

begin_comment
comment|/* RevA - Write only, RevB - Read/Write */
end_comment

begin_define
define|#
directive|define
name|MSGU_HOST_INT_STATUS
value|0x08
end_define

begin_define
define|#
directive|define
name|MSGU_HOST_INT_MASK
value|0x0C
end_define

begin_define
define|#
directive|define
name|MSGU_IOPIB_INT_STATUS
value|0x18
end_define

begin_define
define|#
directive|define
name|MSGU_IOPIB_INT_MASK
value|0x1C
end_define

begin_define
define|#
directive|define
name|MSGU_IBDB_CLEAR
value|0x20
end_define

begin_comment
comment|/* RevB - Host not use */
end_comment

begin_define
define|#
directive|define
name|MSGU_MSGU_CONTROL
value|0x24
end_define

begin_define
define|#
directive|define
name|MSGU_ODR
value|0x3C
end_define

begin_comment
comment|/* RevB */
end_comment

begin_define
define|#
directive|define
name|MSGU_ODCR
value|0x40
end_define

begin_comment
comment|/* RevB */
end_comment

begin_define
define|#
directive|define
name|MSGU_SCRATCH_PAD_0
value|0x44
end_define

begin_define
define|#
directive|define
name|MSGU_SCRATCH_PAD_1
value|0x48
end_define

begin_define
define|#
directive|define
name|MSGU_SCRATCH_PAD_2
value|0x4C
end_define

begin_define
define|#
directive|define
name|MSGU_SCRATCH_PAD_3
value|0x50
end_define

begin_define
define|#
directive|define
name|MSGU_HOST_SCRATCH_PAD_0
value|0x54
end_define

begin_define
define|#
directive|define
name|MSGU_HOST_SCRATCH_PAD_1
value|0x58
end_define

begin_define
define|#
directive|define
name|MSGU_HOST_SCRATCH_PAD_2
value|0x5C
end_define

begin_define
define|#
directive|define
name|MSGU_HOST_SCRATCH_PAD_3
value|0x60
end_define

begin_define
define|#
directive|define
name|MSGU_HOST_SCRATCH_PAD_4
value|0x64
end_define

begin_define
define|#
directive|define
name|MSGU_HOST_SCRATCH_PAD_5
value|0x68
end_define

begin_define
define|#
directive|define
name|MSGU_HOST_SCRATCH_PAD_6
value|0x6C
end_define

begin_define
define|#
directive|define
name|MSGU_HOST_SCRATCH_PAD_7
value|0x70
end_define

begin_define
define|#
directive|define
name|MSGU_ODMR
value|0x74
end_define

begin_comment
comment|/* RevB */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Table 215   Messaging Unit Address Map Offset (Hex) Name Access Internal Offset Internal Name Comment */
end_comment

begin_define
define|#
directive|define
name|V_Inbound_Doorbell_Set_Register
value|0x00
end_define

begin_comment
comment|/* Host R/W Local INT 0x0 MSGU - Inbound Doorbell Set */
end_comment

begin_define
define|#
directive|define
name|V_Inbound_Doorbell_Set_RegisterU
value|0x04
end_define

begin_comment
comment|/* Host R/W Local INT 0x4 MSGU - Inbound Doorbell Set */
end_comment

begin_define
define|#
directive|define
name|V_Inbound_Doorbell_Clear_Register
value|0x08
end_define

begin_comment
comment|/* Host No access Local  W, R all 0s 0x8 MSGU - Inbound Doorbell Clear */
end_comment

begin_define
define|#
directive|define
name|V_Inbound_Doorbell_Clear_RegisterU
value|0x0C
end_define

begin_comment
comment|/* Host No access Local  W, R all 0s 0xC MSGU - Inbound Doorbell Clear */
end_comment

begin_define
define|#
directive|define
name|V_Inbound_Doorbell_Mask_Set_Register
value|0x10
end_define

begin_comment
comment|/* Host RO Local R/W 0x10 MSGU - Inbound Doorbell Mask Set New in SPCv */
end_comment

begin_define
define|#
directive|define
name|V_Inbound_Doorbell_Mask_Set_RegisterU
value|0x14
end_define

begin_comment
comment|/* Host RO Local R/W 0x14 MSGU - Inbound Doorbell Mask Set New in SPCv */
end_comment

begin_define
define|#
directive|define
name|V_Inbound_Doorbell_Mask_Clear_Register
value|0x18
end_define

begin_comment
comment|/* Host RO Local W, R all 0s 0x18 MSGU - Inbound Doorbell Mask Clear New in SPCv */
end_comment

begin_define
define|#
directive|define
name|V_Inbound_Doorbell_Mask_Clear_RegisterU
value|0x1C
end_define

begin_comment
comment|/* Host RO Local W, R all 0s 0x1C MSGU - Inbound Doorbell Mask Clear New in SPCv */
end_comment

begin_define
define|#
directive|define
name|V_Outbound_Doorbell_Set_Register
value|0x20
end_define

begin_comment
comment|/* Host RO Local R/W 0x20 MSGU - Outbound Doorbell Set */
end_comment

begin_define
define|#
directive|define
name|V_Outbound_Doorbell_Set_RegisterU
value|0x24
end_define

begin_comment
comment|/* Host RO Local R/W 0x24 MSGU - Outbound Doorbell Set */
end_comment

begin_define
define|#
directive|define
name|V_Outbound_Doorbell_Clear_Register
value|0x28
end_define

begin_comment
comment|/* Host W, R all 0s Local  RO 0x28 MSGU - Outbound Doorbell Clear */
end_comment

begin_define
define|#
directive|define
name|V_Outbound_Doorbell_Clear_RegisterU
value|0x2C
end_define

begin_comment
comment|/* Host W, R all 0s Local  RO 0x2C MSGU - Outbound Doorbell Clear */
end_comment

begin_define
define|#
directive|define
name|V_Outbound_Doorbell_Mask_Set_Register
value|0x30
end_define

begin_comment
comment|/* Host RW  Local RO 0x30 MSGU - Outbound Doorbell Mask Set 1's set */
end_comment

begin_define
define|#
directive|define
name|V_Outbound_Doorbell_Mask_Set_RegisterU
value|0x34
end_define

begin_comment
comment|/* Host RW  Local RO 0x30 MSGU - Outbound Doorbell Mask Set 1's set */
end_comment

begin_define
define|#
directive|define
name|V_Outbound_Doorbell_Mask_Clear_Register
value|0x38
end_define

begin_comment
comment|/* Host W, R all 0s Local RO 0x38 MSGU - Outbound Doorbell Mask Clear New in SPCv 1's clear */
end_comment

begin_define
define|#
directive|define
name|V_Outbound_Doorbell_Mask_Clear_RegisterU
value|0x3C
end_define

begin_comment
comment|/* Host W, R all 0s Local RO 0x38 MSGU - Outbound Doorbell Mask Clear New in SPCv 1's clear */
end_comment

begin_comment
comment|/* 0x40 Reserved  R all 0s */
end_comment

begin_define
define|#
directive|define
name|V_Scratchpad_0_Register
value|0x44
end_define

begin_comment
comment|/* Host RO Local R/W 0x120 MSGU - Scratchpad 0 */
end_comment

begin_define
define|#
directive|define
name|V_Scratchpad_1_Register
value|0x48
end_define

begin_comment
comment|/* Host RO Local R/W 0x128 MSGU - Scratchpad 1 */
end_comment

begin_define
define|#
directive|define
name|V_Scratchpad_2_Register
value|0x4C
end_define

begin_comment
comment|/* Host RO Local R/W 0x130 MSGU - Scratchpad 2 */
end_comment

begin_define
define|#
directive|define
name|V_Scratchpad_3_Register
value|0x50
end_define

begin_comment
comment|/* Host RO Local R/W 0x138 MSGU - Scratchpad 3 */
end_comment

begin_define
define|#
directive|define
name|V_Host_Scratchpad_0_Register
value|0x54
end_define

begin_comment
comment|/* Host RW Local RO 0x140 MSGU - Scratchpad 4 */
end_comment

begin_define
define|#
directive|define
name|V_Host_Scratchpad_1_Register
value|0x58
end_define

begin_comment
comment|/* Host RW Local RO 0x148 MSGU - Scratchpad 5 */
end_comment

begin_define
define|#
directive|define
name|V_Host_Scratchpad_2_Register
value|0x5C
end_define

begin_comment
comment|/* Host RW Local RO 0x150 MSGU - Scratchpad 6 */
end_comment

begin_define
define|#
directive|define
name|V_Host_Scratchpad_3_Register
value|0x60
end_define

begin_comment
comment|/* Host RW Local RO 0x158 MSGU - Scratchpad 7 */
end_comment

begin_define
define|#
directive|define
name|V_Host_Scratchpad_4_Register
value|0x64
end_define

begin_comment
comment|/* Host RW Local R/W 0x160 MSGU - Scratchpad 8 */
end_comment

begin_define
define|#
directive|define
name|V_Host_Scratchpad_5_Register
value|0x68
end_define

begin_comment
comment|/* Host RW Local R/W 0x168 MSGU - Scratchpad 9 */
end_comment

begin_define
define|#
directive|define
name|V_Scratchpad_Rsvd_0_Register
value|0x6C
end_define

begin_comment
comment|/* Host RW Local R/W 0x170 MSGU - Scratchpad 10 */
end_comment

begin_define
define|#
directive|define
name|V_Scratchpad_Rsvd_1_Register
value|0x70
end_define

begin_comment
comment|/* Host RW Local R/W 0x178 MSGU - Scratchpad 11 */
end_comment

begin_comment
comment|/* 0x74 - 0xFF Reserved R all 0s */
end_comment

begin_define
define|#
directive|define
name|V_Outbound_Queue_Consumer_Indices_Base
value|0x100
end_define

begin_comment
comment|/*  typical value real offset is read from table to 0x1FF Host RW Local RO 0x1F100  0x1F1FF In DQ storage area*/
end_comment

begin_define
define|#
directive|define
name|V_Inbound_Queue_Producer_Indices
value|0x200
end_define

begin_comment
comment|/*  typical value real offset is read from table to 0x3FF Host RW Local RO 0x1F200  0x1F3FF In DQ storage area, also mapped as WSM*/
end_comment

begin_comment
comment|/*                SPC_V                                                 SPC      Bar     Name                                 Offset     Bar     Name                    Offset   PCIBAR0, V_Inbound_Doorbell_Set_Register,         0x00   PCIBAR0, MSGU_IBDB_SET,            0x04   PCIBAR0, V_Inbound_Doorbell_Clear_Register,       0x08       NA   PCIBAR0, V_Inbound_Doorbell_Mask_Set_Register,    0x10       NA   PCIBAR0, V_Inbound_Doorbell_Mask_Clear_Register,  0x18       NA   PCIBAR0, V_Outbound_Doorbell_Set_Register,        0x20   PCIBAR0, MSGU_ODR,                 0x3C   PCIBAR0, V_Outbound_Doorbell_Clear_Register,      0x28   PCIBAR0, MSGU_ODCR,                0x40   PCIBAR0, V_Outbound_Doorbell_Mask_Set_Register,   0x30   PCIBAR0, MSGU_ODMR,                0x74   PCIBAR0, V_Outbound_Doorbell_Mask_Clear_Register, 0x38       NA   PCIBAR0, V_Scratchpad_0_Register,                 0x44   PCIBAR0, MSGU_SCRATCH_PAD_0,       0x44   PCIBAR0, V_Scratchpad_1_Register,                 0x48   PCIBAR0, MSGU_SCRATCH_PAD_1,       0x48   PCIBAR0, V_Scratchpad_2_Register,                 0x4C   PCIBAR0, MSGU_SCRATCH_PAD_2,       0x4C   PCIBAR0, V_Scratchpad_3_Register,                 0x50   PCIBAR0, MSGU_SCRATCH_PAD_3,       0x50   PCIBAR0, V_Host_Scratchpad_0_Register,            0x54   PCIBAR0, MSGU_HOST_SCRATCH_PAD_0,  0x54   PCIBAR0, V_Host_Scratchpad_1_Register,            0x58   PCIBAR0, MSGU_HOST_SCRATCH_PAD_1,  0x58   PCIBAR0, V_Host_Scratchpad_2_Register,            0x5C   PCIBAR0, MSGU_HOST_SCRATCH_PAD_2,  0x5C   PCIBAR0, V_Host_Scratchpad_3_Register,            0x60   PCIBAR0, MSGU_HOST_SCRATCH_PAD_3,  0x60  */
end_comment

begin_define
define|#
directive|define
name|V_RamEccDbErr
value|0x00000018
end_define

begin_define
define|#
directive|define
name|V_SoftResetRegister
value|0x1000
end_define

begin_define
define|#
directive|define
name|V_MEMBASE_II_ShiftRegister
value|0x1010
end_define

begin_define
define|#
directive|define
name|V_GsmConfigReset
value|0
end_define

begin_define
define|#
directive|define
name|V_GsmReadAddrParityCheck
value|0x38
end_define

begin_define
define|#
directive|define
name|V_GsmWriteAddrParityCheck
value|0x40
end_define

begin_define
define|#
directive|define
name|V_GsmWriteDataParityCheck
value|0x48
end_define

begin_define
define|#
directive|define
name|V_GsmReadAddrParityIndic
value|0x58
end_define

begin_define
define|#
directive|define
name|V_GsmWriteAddrParityIndic
value|0x60
end_define

begin_define
define|#
directive|define
name|V_GsmWriteDataParityIndic
value|0x68
end_define

begin_define
define|#
directive|define
name|SPCv_Reset_Reserved
value|0xFFFFFF3C
end_define

begin_define
define|#
directive|define
name|SPCv_Reset_Read_Mask
value|0xC0
end_define

begin_define
define|#
directive|define
name|SPCv_Reset_Read_NoReset
value|0x0
end_define

begin_define
define|#
directive|define
name|SPCv_Reset_Read_NormalResetOccurred
value|0x40
end_define

begin_define
define|#
directive|define
name|SPCv_Reset_Read_SoftResetHDAOccurred
value|0x80
end_define

begin_define
define|#
directive|define
name|SPCv_Reset_Read_ChipResetOccurred
value|0xC0
end_define

begin_define
define|#
directive|define
name|SPCv_Reset_Write_NormalReset
value|0x1
end_define

begin_define
define|#
directive|define
name|SPCv_Reset_Write_SoftResetHDA
value|0x2
end_define

begin_define
define|#
directive|define
name|SPCv_Reset_Write_ChipReset
value|0x3
end_define

begin_comment
comment|/* [31:8] Reserved -- Reserved Host R / Local R/W */
end_comment

begin_comment
comment|/* Indicator that a controller soft reset has occurred. The bootloader sets this field when a soft reset occurs. Host is read only. [7:6] b00: No soft reset occurred. Device reset value. b01: Normal soft reset occurred. b10: Soft reset HDA mode occurred. b11: Chip reset occurred. Soft Reset Occurred SFT_RST_OCR [5:2] Reserved -- Reserved b0000 Reserved Host R/W / Local R The controller soft reset type that is required by the host side. The host sets this field and the bootloader clears it. b00: Ready for soft reset / normal status. b01: Normal soft reset. b10: Soft reset HDA mode. b11: Chip reset. Soft Reset Requested SFT_RST_RQST [1:0]  */
end_comment

begin_comment
comment|/***** RevB - ODAR - Outbound DoorBell Auto-Clearing Register               ICT  - Interrupt Coalescing Timer Register               ICC  - Interrupt Coalescing Control Register             - BAR2(0x18), BAR1(win) *****/
end_comment

begin_comment
comment|/****************** 64 KB BAR *****************/
end_comment

begin_define
define|#
directive|define
name|SPC_ODAR
value|0x00335C
end_define

begin_define
define|#
directive|define
name|SPC_ICTIMER
value|0x0033C0
end_define

begin_define
define|#
directive|define
name|SPC_ICCONTROL
value|0x0033C4
end_define

begin_comment
comment|/* BAR2(0x18), BAR1(win) */
end_comment

begin_define
define|#
directive|define
name|MSGU_XCBI_IBDB_REG
value|0x003034
end_define

begin_comment
comment|/* PCIE - Message Unit Inbound Doorbell register */
end_comment

begin_define
define|#
directive|define
name|MSGU_XCBI_OBDB_REG
value|0x003354
end_define

begin_comment
comment|/* PCIE - Message Unit Outbound Doorbell Interrupt Register */
end_comment

begin_define
define|#
directive|define
name|MSGU_XCBI_OBDB_MASK
value|0x003358
end_define

begin_comment
comment|/* PCIE - Message Unit Outbound Doorbell Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|MSGU_XCBI_OBDB_CLEAR
value|0x00303C
end_define

begin_comment
comment|/* PCIE - Message Unit Outbound Doorbell Interrupt Clear Register */
end_comment

begin_comment
comment|/* RB6 offset */
end_comment

begin_define
define|#
directive|define
name|SPC_RB6_OFFSET
value|0x80C0
end_define

begin_define
define|#
directive|define
name|RB6_MAGIC_NUMBER_RST
value|0x1234
end_define

begin_comment
comment|/* Magic number of soft reset for RB6 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MSGU_ACCESS_VIA_XCBI
end_ifdef

begin_define
define|#
directive|define
name|MSGU_READ_IDR
value|ossaHwRegReadExt(agRoot, PCIBAR1, MSGU_XCBI_IBDB_REG)
end_define

begin_define
define|#
directive|define
name|MSGU_READ_ODMR
value|ossaHwRegReadExt(agRoot, PCIBAR1, MSGU_XCBI_OBDB_MASK)
end_define

begin_define
define|#
directive|define
name|MSGU_READ_ODR
value|ossaHwRegReadExt(agRoot, PCIBAR1, MSGU_XCBI_OBDB_REG)
end_define

begin_define
define|#
directive|define
name|MSGU_READ_ODCR
value|ossaHwRegReadExt(agRoot, PCIBAR1, MSGU_XCBI_OBDB_CLEAR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MSGU_READ_IDR
value|siHalRegReadExt(agRoot, GEN_MSGU_IBDB_SET, MSGU_IBDB_SET)
end_define

begin_define
define|#
directive|define
name|MSGU_READ_ODMR
value|siHalRegReadExt(agRoot, GEN_MSGU_ODMR,     MSGU_ODMR)
end_define

begin_define
define|#
directive|define
name|MSGU_READ_ODR
value|siHalRegReadExt(agRoot, GEN_MSGU_ODR,      MSGU_ODR)
end_define

begin_define
define|#
directive|define
name|MSGU_READ_ODCR
value|siHalRegReadExt(agRoot, GEN_MSGU_ODCR,     MSGU_ODCR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bit definition for ODMR register */
end_comment

begin_define
define|#
directive|define
name|ODMR_MASK_ALL
value|0xFFFFFFFF
end_define

begin_comment
comment|/* mask all interrupt vector */
end_comment

begin_define
define|#
directive|define
name|ODMR_CLEAR_ALL
value|0
end_define

begin_comment
comment|/* clear all interrupt vector */
end_comment

begin_comment
comment|/* bit definition for ODMR register */
end_comment

begin_define
define|#
directive|define
name|ODCR_CLEAR_ALL
value|0xFFFFFFFF
end_define

begin_comment
comment|/* mask all interrupt vector */
end_comment

begin_comment
comment|/* bit definition for Inbound Doorbell register */
end_comment

begin_define
define|#
directive|define
name|IBDB_IBQ_UNFREEZE
value|0x08
end_define

begin_comment
comment|/* Inbound doorbell bit3 */
end_comment

begin_define
define|#
directive|define
name|IBDB_IBQ_FREEZE
value|0x04
end_define

begin_comment
comment|/* Inbound doorbell bit2 */
end_comment

begin_define
define|#
directive|define
name|IBDB_CFG_TABLE_RESET
value|0x02
end_define

begin_comment
comment|/* Inbound doorbell bit1 */
end_comment

begin_define
define|#
directive|define
name|IBDB_CFG_TABLE_UPDATE
value|0x01
end_define

begin_comment
comment|/* Inbound doorbell bit0 */
end_comment

begin_define
define|#
directive|define
name|IBDB_MPIIU
value|0x08
end_define

begin_comment
comment|/* Inbound doorbell bit3 - Unfreeze */
end_comment

begin_define
define|#
directive|define
name|IBDB_MPIIF
value|0x04
end_define

begin_comment
comment|/* Inbound doorbell bit2 - Freeze */
end_comment

begin_define
define|#
directive|define
name|IBDB_MPICT
value|0x02
end_define

begin_comment
comment|/* Inbound doorbell bit1 - Termination */
end_comment

begin_define
define|#
directive|define
name|IBDB_MPIINI
value|0x01
end_define

begin_comment
comment|/* Inbound doorbell bit0 - Initialization */
end_comment

begin_comment
comment|/* bit mask definition for Scratch Pad0 register */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD0_BAR_MASK
value|0xFC000000
end_define

begin_comment
comment|/* bit31-26 - mask bar */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD0_OFFSET_MASK
value|0x03FFFFFF
end_define

begin_comment
comment|/* bit25-0  - offset mask */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD0_AAPERR_MASK
value|0xFFFFFFFF
end_define

begin_comment
comment|/* if AAP error state */
end_comment

begin_comment
comment|/* state definition for Scratch Pad1 register */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_POR
value|0x00
end_define

begin_comment
comment|/* power on reset state */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_SFR
value|0x01
end_define

begin_comment
comment|/* soft reset state */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_ERR
value|0x02
end_define

begin_comment
comment|/* error state */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_RDY
value|0x03
end_define

begin_comment
comment|/* ready state */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_RST
value|0x04
end_define

begin_comment
comment|/* soft reset toggle flag */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_AAP1RDY_RST
value|0x08
end_define

begin_comment
comment|/* AAP1 ready for soft reset */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_STATE_MASK
value|0xFFFFFFF0
end_define

begin_comment
comment|/* ScratchPad1 Mask other bits 31:4, bit1-0 State */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_RESERVED
value|0x000000F0
end_define

begin_comment
comment|/* Scratch Pad1 Reserved bit 4 to 7 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_RAAE_MASK
value|0x00000003
end_define

begin_comment
comment|/* 0 1 also  ready */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_RAAE_ERR
value|0x00000002
end_define

begin_comment
comment|/* 1 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_ILA_MASK
value|0x0000000C
end_define

begin_comment
comment|/* 2 3 also  ready */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_ILA_ERR
value|0x00000008
end_define

begin_comment
comment|/* 3  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_BOOTSTATE_MASK
value|0x00000070
end_define

begin_comment
comment|/* 456 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_BOOTSTATE_SUCESS
value|0x00000000
end_define

begin_comment
comment|/* Load successful */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_BOOTSTATE_HDA_SEEPROM
value|0x00000010
end_define

begin_comment
comment|/* HDA Mode SEEPROM Setting */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_BOOTSTATE_HDA_BOOTSTRAP
value|0x00000020
end_define

begin_comment
comment|/* HDA Mode BootStrap Setting */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_BOOTSTATE_HDA_SOFTRESET
value|0x00000030
end_define

begin_comment
comment|/* HDA Mode Soft Reset */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_BOOTSTATE_CRIT_ERROR
value|0x00000040
end_define

begin_comment
comment|/* HDA Mode due to critical error */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_BOOTSTATE_R1
value|0x00000050
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_BOOTSTATE_R2
value|0x00000060
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_BOOTSTATE_FATAL
value|0x00000070
end_define

begin_comment
comment|/* Fatal Error  Boot process halted */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_ILA_IMAGE
value|0x00000080
end_define

begin_comment
comment|/* 7 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_FW_IMAGE
value|0x00000100
end_define

begin_comment
comment|/* 8 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_BIT9_RESERVED
value|0x00000200
end_define

begin_comment
comment|/* 9 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_IOP0_MASK
value|0x00000C00
end_define

begin_comment
comment|/* 10 11 also ready  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_IOP0_ERR
value|0x00000800
end_define

begin_comment
comment|/* 11   */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_IOP1_MASK
value|0x00003000
end_define

begin_comment
comment|/* 12 13 also ready */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_IOP1_ERR
value|0x00002000
end_define

begin_comment
comment|/* 13  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_RESERVED
value|0xFFFFC000
end_define

begin_comment
comment|/* 14-31  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_READY
value|( SCRATCH_PAD1_V_RAAE_MASK | SCRATCH_PAD1_V_ILA_MASK | SCRATCH_PAD1_V_IOP0_MASK )
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_ERROR
value|( SCRATCH_PAD1_V_RAAE_ERR  | SCRATCH_PAD1_V_ILA_ERR  | SCRATCH_PAD1_V_IOP0_ERR  | SCRATCH_PAD1_V_IOP1_ERR  )
end_define

begin_comment
comment|/* Scratch Pad1 13 11 3 1 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_ILA_ERROR_STATE
parameter_list|(
name|ScratchPad1
parameter_list|)
value|((((ScratchPad1)& SCRATCH_PAD1_V_ILA_MASK ) == SCRATCH_PAD1_V_ILA_MASK) ?  0: \                                                       (((ScratchPad1)& SCRATCH_PAD1_V_ILA_MASK ) == SCRATCH_PAD1_V_ILA_ERR ) ?  SCRATCH_PAD1_V_ILA_ERR : 0 )
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_RAAE_ERROR_STATE
parameter_list|(
name|ScratchPad1
parameter_list|)
value|((((ScratchPad1)& SCRATCH_PAD1_V_RAAE_MASK ) == SCRATCH_PAD1_V_RAAE_MASK) ?  0: \                                                       (((ScratchPad1)& SCRATCH_PAD1_V_RAAE_MASK ) == SCRATCH_PAD1_V_RAAE_ERR)  ?  SCRATCH_PAD1_V_RAAE_ERR : 0 )
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_IOP0_ERROR_STATE
parameter_list|(
name|ScratchPad1
parameter_list|)
value|((((ScratchPad1)& SCRATCH_PAD1_V_IOP0_MASK ) == SCRATCH_PAD1_V_IOP0_MASK) ?  0: \                                                       (((ScratchPad1)& SCRATCH_PAD1_V_IOP0_MASK ) == SCRATCH_PAD1_V_IOP0_ERR)  ?  SCRATCH_PAD1_V_IOP0_ERR : 0 )
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_IOP1_ERROR_STATE
parameter_list|(
name|ScratchPad1
parameter_list|)
value|((((ScratchPad1)& SCRATCH_PAD1_V_IOP1_MASK ) == SCRATCH_PAD1_V_IOP1_MASK) ?  0: \                                                       (((ScratchPad1)& SCRATCH_PAD1_V_IOP1_MASK ) == SCRATCH_PAD1_V_IOP1_ERR)  ?  SCRATCH_PAD1_V_IOP1_ERR : 0 )
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_ERROR_STATE
parameter_list|(
name|ScratchPad1
parameter_list|)
value|( SCRATCH_PAD1_V_ILA_ERROR_STATE(ScratchPad1)  | \                                                   SCRATCH_PAD1_V_RAAE_ERROR_STATE(ScratchPad1) | \                                                   SCRATCH_PAD1_V_IOP0_ERROR_STATE(ScratchPad1) | \                                                   SCRATCH_PAD1_V_IOP1_ERROR_STATE(ScratchPad1) )
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD1_V_BOOTLDR_ERROR
value|0x00000070
end_define

begin_comment
comment|/* Scratch Pad1 (6 5 4) */
end_comment

begin_comment
comment|/* error bit definition */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_BDMA_ERR
value|0x80000000
end_define

begin_comment
comment|/* bit31 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_GSM_ERR
value|0x40000000
end_define

begin_comment
comment|/* bit30 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_MBIC1_ERR
value|0x20000000
end_define

begin_comment
comment|/* bit29 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_MBIC1_SET0_ERR
value|0x10000000
end_define

begin_comment
comment|/* bit28 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_MBIC1_SET1_ERR
value|0x08000000
end_define

begin_comment
comment|/* bit27 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_PMIC1_ERR
value|0x04000000
end_define

begin_comment
comment|/* bit26 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_PMIC2_ERR
value|0x02000000
end_define

begin_comment
comment|/* bit25 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_PMIC_EVENT_ERR
value|0x01000000
end_define

begin_comment
comment|/* bit24 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_OSSP_ERR
value|0x00800000
end_define

begin_comment
comment|/* bit23 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_SSPA_ERR
value|0x00400000
end_define

begin_comment
comment|/* bit22 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_SSPL_ERR
value|0x00200000
end_define

begin_comment
comment|/* bit21 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_HSST_ERR
value|0x00100000
end_define

begin_comment
comment|/* bit20 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_PCS_ERR
value|0x00080000
end_define

begin_comment
comment|/* bit19 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_FW_INIT_ERR
value|0x00008000
end_define

begin_comment
comment|/* bit15 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_FW_ASRT_ERR
value|0x00004000
end_define

begin_comment
comment|/* bit14 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_FW_WDG_ERR
value|0x00002000
end_define

begin_comment
comment|/* bit13 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_AAP_ERROR_STATE
value|0x00000002
end_define

begin_comment
comment|/* bit1 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD1_AAP_READY
value|0x00000003
end_define

begin_comment
comment|/* bit1& bit0 */
end_comment

begin_comment
comment|/* state definition for Scratch Pad2 register */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_POR
value|0x00
end_define

begin_comment
comment|/* power on state */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_SFR
value|0x01
end_define

begin_comment
comment|/* soft reset state */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_ERR
value|0x02
end_define

begin_comment
comment|/* error state */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_RDY
value|0x03
end_define

begin_comment
comment|/* ready state */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_FWRDY_RST
value|0x04
end_define

begin_comment
comment|/* FW ready for soft reset rdy flag */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_IOPRDY_RST
value|0x08
end_define

begin_comment
comment|/* IOP ready for soft reset */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_STATE_MASK
value|0xFFFFFFF0
end_define

begin_comment
comment|/* ScratchPad 2 Mask for other bits 31:4, bit1-0 State*/
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_RESERVED
value|0x000000F0
end_define

begin_comment
comment|/* Scratch Pad1 Reserved bit 4 to 7 */
end_comment

begin_comment
comment|/* error bit definition */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_BDMA_ERR
value|0x80000000
end_define

begin_comment
comment|/* bit31 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_GSM_ERR
value|0x40000000
end_define

begin_comment
comment|/* bit30 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_MBIC3_ERR
value|0x20000000
end_define

begin_comment
comment|/* bit29 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_MBIC3_SET0_ERR
value|0x10000000
end_define

begin_comment
comment|/* bit28 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_MBIC3_SET1_ERR
value|0x08000000
end_define

begin_comment
comment|/* bit27 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_PMIC1_ERR
value|0x04000000
end_define

begin_comment
comment|/* bit26 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_PMIC2_ERR
value|0x02000000
end_define

begin_comment
comment|/* bit25 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_PMIC_EVENT_ERR
value|0x01000000
end_define

begin_comment
comment|/* bit24 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_OSSP_ERR
value|0x00800000
end_define

begin_comment
comment|/* bit23 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_SSPA_ERR
value|0x00400000
end_define

begin_comment
comment|/* bit22 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_SSPL_ERR
value|0x00200000
end_define

begin_comment
comment|/* bit21 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HSST_ERR
value|0x00100000
end_define

begin_comment
comment|/* bit20 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_PCS_ERR
value|0x00080000
end_define

begin_comment
comment|/* bit19 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_FW_BOOT_ROM_ERROR
value|0x00010000
end_define

begin_comment
comment|/* bit16 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_FW_ILA_ERR
value|0x00008000
end_define

begin_comment
comment|/* bit15 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_FW_FLM_ERR
value|0x00004000
end_define

begin_comment
comment|/* bit14 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_FW_FW_ASRT_ERR
value|0x00002000
end_define

begin_comment
comment|/* bit13 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_FW_HW_WDG_ERR
value|0x00001000
end_define

begin_comment
comment|/* bit12 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_FW_GEN_EXCEPTION_ERR
value|0x00000800
end_define

begin_comment
comment|/* bit11 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_FW_UNDTMN_ERR
value|0x00000400
end_define

begin_comment
comment|/* bit10 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_FW_HW_FATAL_ERR
value|0x00000200
end_define

begin_comment
comment|/* bit9 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_FW_HW_NON_FATAL_ERR
value|0x00000100
end_define

begin_comment
comment|/* bit8 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD2_FW_HW_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_PCS_ERR
value|0x00
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_GSM_ERR
value|0x01
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_OSSP0_ERR
value|0x02
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_OSSP1_ERR
value|0x03
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_OSSP2_ERR
value|0x04
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_ERAAE_ERR
value|0x05
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_SDS_ERR
value|0x06
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_PCIE_CORE_ERR
value|0x08
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_PCIE_AL_ERR
value|0x0C
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_MSGU_ERR
value|0x0E
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_SPBC_ERR
value|0x0F
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_BDMA_ERR
value|0x10
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_MCPSL2B_ERR
value|0x13
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_MCPSDC_ERR
value|0x14
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD2_HW_ERROR_INT_INDX_UNDETERMINED_ERROR_OCCURRED
value|0xFF
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD_ERROR_MASK
value|0xFFFFFF00
end_define

begin_comment
comment|/* Error mask bits 31:8 */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD_STATE_MASK
value|0x00000003
end_define

begin_comment
comment|/* State Mask bits 1:0 */
end_comment

begin_define
define|#
directive|define
name|SPCV_RAAE_STATE_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|SPCV_IOP0_STATE_MASK
value|((1<< 10) | (1<< 11))
end_define

begin_define
define|#
directive|define
name|SPCV_IOP1_STATE_MASK
value|((1<< 12) | (1<< 13))
end_define

begin_define
define|#
directive|define
name|SPCV_ERROR_VALUE
value|0x2
end_define

begin_define
define|#
directive|define
name|SCRATCH_PAD3_FW_IMAGE_MASK
value|0x0000000F
end_define

begin_comment
comment|/* SPC 8x6G boots from Image */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_FW_IMAGE_FLAG_VALID
value|0x00000008
end_define

begin_comment
comment|/* Image flag is valid */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_FW_IMAGE_B_VALID
value|0x00000004
end_define

begin_comment
comment|/* Image B is valid */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_FW_IMAGE_A_VALID
value|0x00000002
end_define

begin_comment
comment|/* Image A is valid */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_FW_IMAGE_B_ACTIVE
value|0x00000001
end_define

begin_comment
comment|/* Image B is active */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_
value|0x00000001
end_define

begin_comment
comment|/* Image B is valid */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_ENC_DISABLED
value|0x00000000
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_ENC_DIS_ERR
value|0x00000001
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_ENC_ENA_ERR
value|0x00000002
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_ENC_READY
value|0x00000003
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_ENC_MASK
value|SCRATCH_PAD3_V_ENC_READY
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_AUT
value|0x00000008
end_define

begin_comment
comment|/* AUT Operator authentication*/
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_ARF
value|0x00000004
end_define

begin_comment
comment|/* ARF factory mode. */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_XTS_ENABLED
value|(1<< SHIFT14)
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_SMA_ENABLED
value|(1<< SHIFT4 )
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_SMB_ENABLED
value|(1<< SHIFT5 )
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_SMF_ENABLED
value|0
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_SM_MASK
value|0x000000F0
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|SCRATCH_PAD3_V_ERR_CODE
value|0x00FF0000
end_define

begin_comment
comment|/*  */
end_comment

begin_comment
comment|/* Dynamic map through Bar4 - 0x00700000 */
end_comment

begin_define
define|#
directive|define
name|GSM_CONFIG_RESET
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RAM_ECC_DB_ERR
value|0x00000018
end_define

begin_define
define|#
directive|define
name|GSM_READ_ADDR_PARITY_INDIC
value|0x00000058
end_define

begin_define
define|#
directive|define
name|GSM_WRITE_ADDR_PARITY_INDIC
value|0x00000060
end_define

begin_define
define|#
directive|define
name|GSM_WRITE_DATA_PARITY_INDIC
value|0x00000068
end_define

begin_define
define|#
directive|define
name|GSM_READ_ADDR_PARITY_CHECK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|GSM_WRITE_ADDR_PARITY_CHECK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|GSM_WRITE_DATA_PARITY_CHECK
value|0x00000048
end_define

begin_comment
comment|/* signature defintion for host scratch pad0 register */
end_comment

begin_define
define|#
directive|define
name|SPC_SOFT_RESET_SIGNATURE
value|0x252acbcd
end_define

begin_comment
comment|/* Signature for Soft Reset */
end_comment

begin_define
define|#
directive|define
name|SPC_HDASOFT_RESET_SIGNATURE
value|0xa5aa27d7
end_define

begin_comment
comment|/* Signature for HDA Soft Reset without PCIe resetting */
end_comment

begin_comment
comment|/**** SPC Top-level Registers definition for Soft Reset/HDA mode ****/
end_comment

begin_comment
comment|/****************** 64 KB BAR *****************/
end_comment

begin_comment
comment|/* SPC Reset register - BAR4(0x20), BAR2(win) (need dynamic mapping) */
end_comment

begin_define
define|#
directive|define
name|SPC_REG_RESET
value|0x000000
end_define

begin_comment
comment|/* reset register */
end_comment

begin_define
define|#
directive|define
name|SPC_REG_DEVICE_LCLK
value|0x000058
end_define

begin_comment
comment|/* Device LCLK generation register */
end_comment

begin_define
define|#
directive|define
name|SPC_READ_RESET_REG
value|siHalRegReadExt(agRoot, GEN_SPC_REG_RESET, SPC_REG_RESET)
end_define

begin_define
define|#
directive|define
name|SPC_WRITE_RESET_REG
parameter_list|(
name|value
parameter_list|)
value|ossaHwRegWriteExt(agRoot, PCIBAR2, SPC_REG_RESET, value);
end_define

begin_comment
comment|/* NMI register - BAR4(0x20), BAR2(win) 0x060000/0x070000 */
end_comment

begin_comment
comment|//#define MBIC_RAW_NMI_STAT_VPE0_IOP               0x0004C8 not used anymore
end_comment

begin_comment
comment|//#define MBIC_RAW_NMI_STAT_VPE0_AAP1              0x0104C8 not used anymore
end_comment

begin_define
define|#
directive|define
name|MBIC_NMI_ENABLE_VPE0_IOP
value|0x000418
end_define

begin_define
define|#
directive|define
name|MBIC_NMI_ENABLE_VPE0_AAP1
value|0x000418
end_define

begin_comment
comment|/* PCIE registers - BAR2(0x18), BAR1(win) 0x010000 */
end_comment

begin_define
define|#
directive|define
name|PCIE_EVENT_INTERRUPT_ENABLE
value|0x003040
end_define

begin_define
define|#
directive|define
name|PCIE_EVENT_INTERRUPT
value|0x003044
end_define

begin_define
define|#
directive|define
name|PCIE_ERROR_INTERRUPT_ENABLE
value|0x003048
end_define

begin_define
define|#
directive|define
name|PCIE_ERROR_INTERRUPT
value|0x00304C
end_define

begin_comment
comment|/* PCIe Message Unit Configuration Registers offset - BAR2(0x18), BAR1(win) 0x010000 */
end_comment

begin_define
define|#
directive|define
name|SPC_REG_MSGU_CONFIG
value|0x003018
end_define

begin_define
define|#
directive|define
name|PMIC_MU_CFG_1_BITMSK_MU_MEM_ENABLE
value|0x00000010
end_define

begin_comment
comment|/* bit difination for SPC_RESET register */
end_comment

begin_define
define|#
directive|define
name|SPC_REG_RESET_OSSP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_RAAE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_PCS_SPBC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_PCS_IOP_SS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_PCS_AAP1_SS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_PCS_AAP2_SS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_PCS_LM
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_PCS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_GSM
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_DDR2
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_BDMA_CORE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_BDMA_SXCBI
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_PCIE_AL_SXCBI
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_PCIE_PWR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_PCIE_SFT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_PCS_SXCBI
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_LMS_SXCBI
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_PMIC_SXCBI
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_PMIC_CORE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_PCIE_PC_SXCBI
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SPC_REG_RESET_DEVICE
value|0x80000000
end_define

begin_comment
comment|/* bit definition for SPC Device Revision register - BAR1 */
end_comment

begin_define
define|#
directive|define
name|SPC_REG_DEVICE_REV
value|0x000024
end_define

begin_define
define|#
directive|define
name|SPC_REG_DEVICE_REV_MASK
value|0x0000000F
end_define

begin_comment
comment|/* bit definition for SPC_REG_TOP_DEVICE_ID  - BAR2 */
end_comment

begin_define
define|#
directive|define
name|SPC_REG_TOP_DEVICE_ID
value|0x20
end_define

begin_define
define|#
directive|define
name|SPC_TOP_DEVICE_ID
value|0x8001
end_define

begin_define
define|#
directive|define
name|SPC_REG_TOP_BOOT_STRAP
value|0x8
end_define

begin_define
define|#
directive|define
name|SPC_TOP_BOOT_STRAP
value|0x02C0A682
end_define

begin_comment
comment|/* For PHY Error */
end_comment

begin_define
define|#
directive|define
name|COUNT_OFFSET
value|0x4000
end_define

begin_define
define|#
directive|define
name|LCLK_CLEAR
value|0x2
end_define

begin_define
define|#
directive|define
name|LCLK
value|0x1
end_define

begin_define
define|#
directive|define
name|CNTL_OFFSET
value|0x100
end_define

begin_define
define|#
directive|define
name|L0_LCLK_CLEAR
value|0x2
end_define

begin_define
define|#
directive|define
name|L0_LCLK
value|0x1
end_define

begin_define
define|#
directive|define
name|DEVICE_LCLK_CLEAR
value|0x40
end_define

begin_comment
comment|/****************** 64 KB BAR *****************/
end_comment

begin_comment
comment|/* PHY Error Count Registers - BAR4(0x20), BAR2(win) (need dynamic mapping) */
end_comment

begin_define
define|#
directive|define
name|SPC_SSPL_COUNTER_CNTL
value|0x001030
end_define

begin_define
define|#
directive|define
name|SPC_INVALID_DW_COUNT
value|0x001034
end_define

begin_define
define|#
directive|define
name|SPC_RUN_DISP_ERROR_COUNT
value|0x001038
end_define

begin_define
define|#
directive|define
name|SPC_CODE_VIOLATION_COUNT
value|0x00103C
end_define

begin_define
define|#
directive|define
name|SPC_LOSS_DW_SYNC_COUNT
value|0x001040
end_define

begin_define
define|#
directive|define
name|SPC_PHY_RESET_PROBLEM_COUNT
value|0x001044
end_define

begin_define
define|#
directive|define
name|SPC_READ_DEV_REV
value|ossaHwRegReadExt(agRoot, PCIBAR2, SPC_REG_DEVICE_REV);
end_define

begin_define
define|#
directive|define
name|SPC_READ_COUNTER_CNTL
parameter_list|(
name|phyId
parameter_list|)
value|ossaHwRegReadExt(agRoot, PCIBAR2, SPC_SSPL_COUNTER_CNTL + (COUNT_OFFSET * phyId))
end_define

begin_define
define|#
directive|define
name|SPC_WRITE_COUNTER_CNTL
parameter_list|(
name|phyId
parameter_list|,
name|value
parameter_list|)
value|ossaHwRegWriteExt(agRoot, PCIBAR2, SPC_SSPL_COUNTER_CNTL + (COUNT_OFFSET * phyId), value)
end_define

begin_define
define|#
directive|define
name|SPC_READ_INV_DW_COUNT
parameter_list|(
name|phyId
parameter_list|)
value|ossaHwRegReadExt(agRoot, PCIBAR2, SPC_INVALID_DW_COUNT + (COUNT_OFFSET * phyId))
end_define

begin_define
define|#
directive|define
name|SPC_READ_DISP_ERR_COUNT
parameter_list|(
name|phyId
parameter_list|)
value|ossaHwRegReadExt(agRoot, PCIBAR2, SPC_RUN_DISP_ERROR_COUNT + (COUNT_OFFSET * phyId))
end_define

begin_define
define|#
directive|define
name|SPC_READ_CODE_VIO_COUNT
parameter_list|(
name|phyId
parameter_list|)
value|ossaHwRegReadExt(agRoot, PCIBAR2, SPC_CODE_VIOLATION_COUNT + (COUNT_OFFSET * phyId))
end_define

begin_define
define|#
directive|define
name|SPC_READ_LOSS_DW_COUNT
parameter_list|(
name|phyId
parameter_list|)
value|ossaHwRegReadExt(agRoot, PCIBAR2, SPC_LOSS_DW_SYNC_COUNT + (COUNT_OFFSET * phyId))
end_define

begin_define
define|#
directive|define
name|SPC_READ_PHY_RESET_COUNT
parameter_list|(
name|phyId
parameter_list|)
value|ossaHwRegReadExt(agRoot, PCIBAR2, SPC_PHY_RESET_PROBLEM_COUNT + (COUNT_OFFSET * phyId))
end_define

begin_comment
comment|/* PHY Error Count Control Registers - BAR2(0x18), BAR1(win) */
end_comment

begin_define
define|#
directive|define
name|SPC_L0_ERR_CNT_CNTL
value|0x0041B0
end_define

begin_define
define|#
directive|define
name|SPC_READ_L0ERR_CNT_CNTL
parameter_list|(
name|phyId
parameter_list|)
value|ossaHwRegReadExt(agRoot, PCIBAR1, SPC_L0_ERR_CNT_CNTL + (CNTL_OFFSET * phyId))
end_define

begin_define
define|#
directive|define
name|SPC_WRITE_L0ERR_CNT_CNTL
parameter_list|(
name|phyId
parameter_list|,
name|value
parameter_list|)
value|ossaHwRegWriteExt(agRoot, PCIBAR1, SPC_L0_ERR_CNT_CNTL + (CNTL_OFFSET * phyId), value)
end_define

begin_comment
comment|/* registers for BAR Shifting - BAR2(0x18), BAR1(win) */
end_comment

begin_define
define|#
directive|define
name|SPC_IBW_AXI_TRANSLATION_LOW
value|0x003258
end_define

begin_comment
comment|/* HDA mode definitions */
end_comment

begin_comment
comment|/* 256KB */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_OFFSET256K
value|0x0003FFC0
end_define

begin_define
define|#
directive|define
name|HDA_RSP_OFFSET256K
value|0x0003FFE0
end_define

begin_comment
comment|/* 512KB */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_OFFSET512K
value|0x0007FFC0
end_define

begin_define
define|#
directive|define
name|HDA_RSP_OFFSET512K
value|0x0007FFE0
end_define

begin_comment
comment|/* 768KB */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_OFFSET768K
value|0x000BFFC0
end_define

begin_define
define|#
directive|define
name|HDA_RSP_OFFSET768K
value|0x000BFFE0
end_define

begin_comment
comment|/* 1024KB - by default */
end_comment

begin_define
define|#
directive|define
name|HDA_CMD_OFFSET1MB
value|0x0000FEC0
end_define

begin_define
define|#
directive|define
name|HDA_RSP_OFFSET1MB
value|0x0000FEE0
end_define

begin_comment
comment|/*  Table 27 Boot ROM HDA Protocol Command Format */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|spcv_hda_cmd_s
block|{
comment|/*  Offset Byte 3 Byte 2 Byte 1 Byte 0 */
name|bit32
name|cmdparm_0
decl_stmt|;
comment|/*  0 Command Parameter 0 */
name|bit32
name|cmdparm_1
decl_stmt|;
comment|/*  4 Command Parameter 1 */
name|bit32
name|cmdparm_2
decl_stmt|;
comment|/*  8 Command Parameter 2 */
name|bit32
name|cmdparm_3
decl_stmt|;
comment|/*  12 Command Parameter 3 */
name|bit32
name|cmdparm_4
decl_stmt|;
comment|/*  16 Command Parameter 4 */
name|bit32
name|cmdparm_5
decl_stmt|;
comment|/*  20 Command Parameter 5 */
name|bit32
name|cmdparm_6
decl_stmt|;
comment|/*  24 Command Parameter 6 */
name|bit32
name|C_PA_SEQ_ID_CMD_CODE
decl_stmt|;
comment|/*  28 C_PA SEQ_ID CMD_CODE */
block|}
name|spcv_hda_cmd_t
typedef|;
end_typedef

begin_comment
comment|/* Table 28 Boot ROM HDA Protocol Response Format  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|spcv_hda_rsp_s
block|{
comment|/*  Offset Byte 3 Byte 2 Byte 1 Byte 0 */
name|bit32
name|cmdparm_0
decl_stmt|;
comment|/*  0 Command Parameter 0 */
name|bit32
name|cmdparm_1
decl_stmt|;
comment|/*  4 Command Parameter 1 */
name|bit32
name|cmdparm_2
decl_stmt|;
comment|/*  8 Command Parameter 2 */
name|bit32
name|cmdparm_3
decl_stmt|;
comment|/*  12 Command Parameter 3 */
name|bit32
name|cmdparm_4
decl_stmt|;
comment|/*  16 Command Parameter 4 */
name|bit32
name|cmdparm_5
decl_stmt|;
comment|/*  20 Command Parameter 5 */
name|bit32
name|cmdparm_6
decl_stmt|;
comment|/*  24 Command Parameter 6 */
name|bit32
name|R_PA_SEQ_ID_RSP_CODE
decl_stmt|;
comment|/*  28 C_PA SEQ_ID CMD_CODE */
block|}
name|spcv_hda_rsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SPC_V_HDA_COMMAND_OFFSET
value|0x000042c0
end_define

begin_define
define|#
directive|define
name|SPC_V_HDA_RESPONSE_OFFSET
value|0x000042e0
end_define

begin_define
define|#
directive|define
name|HDA_C_PA_OFFSET
value|0x1F
end_define

begin_define
define|#
directive|define
name|HDA_SEQ_ID_OFFSET
value|0x1E
end_define

begin_define
define|#
directive|define
name|HDA_PAR_LEN_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|HDA_CMD_CODE_OFFSET
value|0x1C
end_define

begin_define
define|#
directive|define
name|HDA_RSP_CODE_OFFSET
value|0x1C
end_define

begin_define
define|#
directive|define
name|SM_HDA_RSP_OFFSET1MB_PLUS_HDA_RSP_CODE_OFFSET
value|(HDA_RSP_OFFSET1MB + HDA_RSP_CODE_OFFSET)
end_define

begin_comment
comment|/* commands */
end_comment

begin_define
define|#
directive|define
name|SPC_V_HDAC_PA
value|0xCB
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAC_BUF_INFO
value|0x0001
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAC_EXEC
value|0x0002
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAC_RESET
value|0x0003
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAC_DMA
value|0x0004
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAC_PA_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAC_SEQID_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAC_CMDCODE_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/* responses */
end_comment

begin_define
define|#
directive|define
name|SPC_V_HDAR_PA
value|0xDB
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAR_BUF_INFO
value|0x8001
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAR_IDLE
value|0x8002
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAR_BAD_IMG
value|0x8003
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAR_BAD_CMD
value|0x8004
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAR_INTL_ERR
value|0x8005
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAR_EXEC
value|0x8006
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAR_PA_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAR_SEQID_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|SPC_V_HDAR_RSPCODE_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|ILAHDA_RAAE_IMG_GET
value|0x11
end_define

begin_define
define|#
directive|define
name|ILAHDA_IOP_IMG_GET
value|0x10
end_define

begin_define
define|#
directive|define
name|ILAHDAC_RAAE_IMG_DONE
value|0x81
end_define

begin_define
define|#
directive|define
name|HDA_AES_DIF_FUNC
value|0xFEDFAE1F
end_define

begin_comment
comment|/* Set MSGU Mapping Registers in BAR0 */
end_comment

begin_define
define|#
directive|define
name|PMIC_MU_CFG_1_BITMSK_MU_IO_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PMIC_MU_CFG_1_BITMSK_MU_IO_WIR
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|PMIC_MU_CFG_1_BITMSK_MU_MEM_ENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PMIC_MU_CFG_1_BITMSK_MU_MEM_OFFSET
value|0xFFFFFC00
end_define

begin_comment
comment|/* PMIC Init */
end_comment

begin_define
define|#
directive|define
name|MU_MEM_OFFSET
value|0x0
end_define

begin_define
define|#
directive|define
name|MSGU_MU_IO_WIR
value|0x8
end_define

begin_comment
comment|/* Window 0 */
end_comment

begin_define
define|#
directive|define
name|BOOTTLOADERHDA_IDLE
value|0x8002
end_define

begin_define
define|#
directive|define
name|HDAR_BAD_IMG
value|0x8003
end_define

begin_define
define|#
directive|define
name|HDAR_BAD_CMD
value|0x8004
end_define

begin_define
define|#
directive|define
name|HDAR_EXEC
value|0x8006
end_define

begin_define
define|#
directive|define
name|CEILING
parameter_list|(
name|X
parameter_list|,
name|rem
parameter_list|)
value|((((bit32)X % rem)> 0) ? (bit32)(X/rem+1) : (bit32)(X/rem))
end_define

begin_define
define|#
directive|define
name|GSMSM_AXI_LOWERADDR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SHIFT_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|OFFSET_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|SIZE_64KB
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ILA_ISTR_ADDROFFSETHDA
value|0x0007E000
end_define

begin_define
define|#
directive|define
name|HDA_STATUS_BITS
value|0x0000FFFF
end_define

begin_comment
comment|/* Scratchpad Reg: bit[31]: 1-CMDFlag 0-RSPFlag; bit[30,24]:CMD/RSP; bit[23,0]:Offset/Size - Shared with the host driver */
end_comment

begin_comment
comment|/* ILA: Mandatory response / state codes in MSGU Scratchpad 0 */
end_comment

begin_define
define|#
directive|define
name|ILAHDA_IOP_IMG_GET
value|0x10
end_define

begin_define
define|#
directive|define
name|ILAHDA_AAP1_IMG_GET
value|0x11
end_define

begin_define
define|#
directive|define
name|ILAHDA_AAP2_IMG_GET
value|0x12
end_define

begin_define
define|#
directive|define
name|ILAHDA_EXITGOOD
value|0x1F
end_define

begin_comment
comment|/* HOST: Mandatory command codes in Host Scratchpad 3 */
end_comment

begin_define
define|#
directive|define
name|ILAHDAC_IOP_IMG_DONE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ILAHDAC_AAP1_IMG_DONE
value|0x00000081
end_define

begin_define
define|#
directive|define
name|ILAHDAC_AAP2_IMG_DONE
value|0x00000082
end_define

begin_define
define|#
directive|define
name|ILAHDAC_ISTR_IMG_DONE
value|0x00000083
end_define

begin_define
define|#
directive|define
name|ILAHDAC_GOTOHDA
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HDA_ISTR_DONE
value|(bit32)(ILAHDAC_ISTR_IMG_DONE<< 24)
end_define

begin_define
define|#
directive|define
name|HDA_AAP1_DONE
value|(bit32)(ILAHDAC_AAP1_IMG_DONE<< 24)
end_define

begin_define
define|#
directive|define
name|HDA_IOP_DONE
value|(bit32)(ILAHDAC_IOP_IMG_DONE<< 24)
end_define

begin_define
define|#
directive|define
name|RB6_ACCESS_REG
value|0x6A0000
end_define

begin_define
define|#
directive|define
name|HDAC_EXEC_CMD
value|0x0002
end_define

begin_define
define|#
directive|define
name|HDA_C_PA
value|0xcb
end_define

begin_define
define|#
directive|define
name|HDA_SEQ_ID_BITS
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HDA_GSM_OFFSET_BITS
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|MBIC_AAP1_ADDR_BASE
value|0x060000
end_define

begin_define
define|#
directive|define
name|MBIC_GSM_SM_BASE
value|0x04F0000
end_define

begin_define
define|#
directive|define
name|MBIC_IOP_ADDR_BASE
value|0x070000
end_define

begin_define
define|#
directive|define
name|GSM_ADDR_BASE
value|0x0700000
end_define

begin_define
define|#
directive|define
name|SPC_TOP_LEVEL_ADDR_BASE
value|0x000000
end_define

begin_define
define|#
directive|define
name|GSM_CONFIG_RESET_VALUE
value|0x00003b00
end_define

begin_define
define|#
directive|define
name|GPIO_ADDR_BASE
value|0x00090000
end_define

begin_define
define|#
directive|define
name|GPIO_GPIO_0_0UTPUT_CTL_OFFSET
value|0x0000010c
end_define

begin_comment
comment|/* Scratchpad registers for fatal errors */
end_comment

begin_define
define|#
directive|define
name|SA_FATAL_ERROR_SP1_AAP1_ERR_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|SA_FATAL_ERROR_SP2_IOP_ERR_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|SA_FATAL_ERROR_FATAL_ERROR
value|0x2
end_define

begin_comment
comment|/* PCIe Analyzer trigger */
end_comment

begin_define
define|#
directive|define
name|PCIE_TRIGGER_ON_REGISTER_READ
value|V_Host_Scratchpad_2_Register
end_define

begin_comment
comment|/* PCI trigger on this offset */
end_comment

begin_define
define|#
directive|define
name|PCI_TRIGGER_INIT_TEST
value|1
end_define

begin_comment
comment|/* Setting adjustable paramater PciTrigger to match this value */
end_comment

begin_define
define|#
directive|define
name|PCI_TRIGGER_OFFSET_MISMATCH
value|2
end_define

begin_comment
comment|/* Setting adjustable paramater PciTrigger to match this value */
end_comment

begin_define
define|#
directive|define
name|PCI_TRIGGER_COAL_IOMB_ERROR
value|4
end_define

begin_comment
comment|/* Setting adjustable paramater PciTrigger to match this value */
end_comment

begin_define
define|#
directive|define
name|PCI_TRIGGER_COAL_INVALID
value|8
end_define

begin_comment
comment|/* Setting adjustable paramater PciTrigger to match this value */
end_comment

begin_comment
comment|/*                                                                   */
end_comment

begin_enum
enum|enum
name|spc_spcv_offsetmap_e
block|{
name|GEN_MSGU_IBDB_SET
init|=
literal|0
block|,
name|GEN_MSGU_ODR
block|,
name|GEN_MSGU_ODCR
block|,
name|GEN_MSGU_SCRATCH_PAD_0
block|,
name|GEN_MSGU_SCRATCH_PAD_1
block|,
name|GEN_MSGU_SCRATCH_PAD_2
block|,
name|GEN_MSGU_SCRATCH_PAD_3
block|,
name|GEN_MSGU_HOST_SCRATCH_PAD_0
block|,
name|GEN_MSGU_HOST_SCRATCH_PAD_1
block|,
name|GEN_MSGU_HOST_SCRATCH_PAD_2
block|,
name|GEN_MSGU_HOST_SCRATCH_PAD_3
block|,
name|GEN_MSGU_ODMR
block|,
name|GEN_PCIE_TRIGGER
block|,
name|GEN_SPC_REG_RESET
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__SAHWREG_H__ */
end_comment

end_unit

