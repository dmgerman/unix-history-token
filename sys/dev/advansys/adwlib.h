begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions for low level routines and data structures  * for the Advanced Systems Inc. SCSI controllers chips.  *  * Copyright (c) 1998, 1999, 2000 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Ported from:  * advansys.c - Linux Host Driver for AdvanSys SCSI Adapters  *       * Copyright (c) 1995-1998 Advanced System Products, Inc.  * All Rights Reserved.  *     * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that redistributions of source  * code retain the above copyright notice and this comment without  * modification.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ADWLIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_ADWLIB_H_
end_define

begin_include
include|#
directive|include
file|"opt_adw.h"
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* for offsetof */
end_comment

begin_include
include|#
directive|include
file|<dev/advansys/adwmcode.h>
end_include

begin_define
define|#
directive|define
name|ADW_DEF_MAX_HOST_QNG
value|253
end_define

begin_define
define|#
directive|define
name|ADW_DEF_MIN_HOST_QNG
value|16
end_define

begin_define
define|#
directive|define
name|ADW_DEF_MAX_DVC_QNG
value|63
end_define

begin_define
define|#
directive|define
name|ADW_DEF_MIN_DVC_QNG
value|4
end_define

begin_define
define|#
directive|define
name|ADW_MAX_TID
value|15
end_define

begin_define
define|#
directive|define
name|ADW_MAX_LUN
value|7
end_define

begin_define
define|#
directive|define
name|ADW_ALL_TARGETS
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|ADW_TARGET_GROUP
parameter_list|(
name|tid
parameter_list|)
value|((tid)& ~0x3)
end_define

begin_define
define|#
directive|define
name|ADW_TARGET_GROUP_SHIFT
parameter_list|(
name|tid
parameter_list|)
value|(((tid)& 0x3) * 4)
end_define

begin_define
define|#
directive|define
name|ADW_TARGET_GROUP_MASK
parameter_list|(
name|tid
parameter_list|)
value|(0xF<< ADW_TARGET_GROUP_SHIFT(tid))
end_define

begin_comment
comment|/*  * Board Register offsets.  */
end_comment

begin_define
define|#
directive|define
name|ADW_INTR_STATUS_REG
value|0x0000
end_define

begin_define
define|#
directive|define
name|ADW_INTR_STATUS_INTRA
value|0x01
end_define

begin_define
define|#
directive|define
name|ADW_INTR_STATUS_INTRB
value|0x02
end_define

begin_define
define|#
directive|define
name|ADW_INTR_STATUS_INTRC
value|0x04
end_define

begin_define
define|#
directive|define
name|ADW_INTR_STATUS_INTRALL
value|0x07
end_define

begin_define
define|#
directive|define
name|ADW_SIGNATURE_WORD
value|0x0000
end_define

begin_define
define|#
directive|define
name|ADW_CHIP_ID_WORD
value|0x04C1
end_define

begin_define
define|#
directive|define
name|ADW_SIGNATURE_BYTE
value|0x0001
end_define

begin_define
define|#
directive|define
name|ADW_CHIP_ID_BYTE
value|0x25
end_define

begin_define
define|#
directive|define
name|ADW_INTR_ENABLES
value|0x0002
end_define

begin_comment
comment|/*8 bit */
end_comment

begin_define
define|#
directive|define
name|ADW_INTR_ENABLE_HOST_INTR
value|0x01
end_define

begin_define
define|#
directive|define
name|ADW_INTR_ENABLE_SEL_INTR
value|0x02
end_define

begin_define
define|#
directive|define
name|ADW_INTR_ENABLE_DPR_INTR
value|0x04
end_define

begin_define
define|#
directive|define
name|ADW_INTR_ENABLE_RTA_INTR
value|0x08
end_define

begin_define
define|#
directive|define
name|ADW_INTR_ENABLE_RMA_INTR
value|0x10
end_define

begin_define
define|#
directive|define
name|ADW_INTR_ENABLE_RST_INTR
value|0x20
end_define

begin_define
define|#
directive|define
name|ADW_INTR_ENABLE_DPE_INTR
value|0x40
end_define

begin_define
define|#
directive|define
name|ADW_INTR_ENABLE_GLOBAL_INTR
value|0x80
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG
value|0x0002
end_define

begin_comment
comment|/*16 bit*/
end_comment

begin_define
define|#
directive|define
name|ADW_CTRL_REG_HOST_INTR
value|0x0100
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG_SEL_INTR
value|0x0200
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG_DPR_INTR
value|0x0400
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG_RTA_INTR
value|0x0800
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG_RMA_INTR
value|0x1000
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG_RES_BIT14
value|0x2000
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG_DPE_INTR
value|0x4000
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG_POWER_DONE
value|0x8000
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG_ANY_INTR
value|0xFF00
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG_CMD_RESET
value|0x00C6
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG_CMD_WR_IO_REG
value|0x00C5
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG_CMD_RD_IO_REG
value|0x00C4
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG_CMD_WR_PCI_CFG
value|0x00C3
end_define

begin_define
define|#
directive|define
name|ADW_CTRL_REG_CMD_RD_PCI_CFG
value|0x00C2
end_define

begin_define
define|#
directive|define
name|ADW_RAM_ADDR
value|0x0004
end_define

begin_define
define|#
directive|define
name|ADW_RAM_DATA
value|0x0006
end_define

begin_define
define|#
directive|define
name|ADW_RISC_CSR
value|0x000A
end_define

begin_define
define|#
directive|define
name|ADW_RISC_CSR_STOP
value|0x0000
end_define

begin_define
define|#
directive|define
name|ADW_RISC_TEST_COND
value|0x2000
end_define

begin_define
define|#
directive|define
name|ADW_RISC_CSR_RUN
value|0x4000
end_define

begin_define
define|#
directive|define
name|ADW_RISC_CSR_SINGLE_STEP
value|0x8000
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG0
value|0x000C
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG0_TIMER_MODEAB
value|0xC000
end_define

begin_comment
comment|/* 							 * Watchdog, Second, 							 * and Selto timer CFG 							 */
end_comment

begin_define
define|#
directive|define
name|ADW_SCSI_CFG0_PARITY_EN
value|0x2000
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG0_EVEN_PARITY
value|0x1000
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG0_WD_LONG
value|0x0800
end_define

begin_comment
comment|/* 							 * Watchdog Interval, 							 * 1: 57 min, 0: 13 sec 							 */
end_comment

begin_define
define|#
directive|define
name|ADW_SCSI_CFG0_QUEUE_128
value|0x0400
end_define

begin_comment
comment|/* 							 * Queue Size, 							 * 1: 128 byte, 							 * 0: 64 byte 							 */
end_comment

begin_define
define|#
directive|define
name|ADW_SCSI_CFG0_PRIM_MODE
value|0x0100
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG0_SCAM_EN
value|0x0080
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG0_SEL_TMO_LONG
value|0x0040
end_define

begin_comment
comment|/* 							 * Sel/Resel Timeout, 							 * 1: 400 ms, 							 * 0: 1.6 ms 							 */
end_comment

begin_define
define|#
directive|define
name|ADW_SCSI_CFG0_CFRM_ID
value|0x0020
end_define

begin_comment
comment|/* SCAM id sel. */
end_comment

begin_define
define|#
directive|define
name|ADW_SCSI_CFG0_OUR_ID_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG0_OUR_ID
value|0x000F
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1
value|0x000E
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_BIG_ENDIAN
value|0x8000
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_TERM_POL
value|0x2000
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_SLEW_RATE
value|0x1000
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_FILTER_MASK
value|0x0C00
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_FLTR_DISABLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_FLTR_11_TO_20NS
value|0x0800
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_FLTR_21_TO_39NS
value|0x0C00
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_DIS_ACTIVE_NEG
value|0x0200
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_DIFF_MODE
value|0x0100
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_DIFF_SENSE
value|0x0080
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_TERM_CTL_MANUAL
value|0x0040
end_define

begin_comment
comment|/* Global Term Switch */
end_comment

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_TERM_CTL_MASK
value|0x0030
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_TERM_CTL_H
value|0x0020
end_define

begin_comment
comment|/* Enable SCSI-H */
end_comment

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_TERM_CTL_L
value|0x0010
end_define

begin_comment
comment|/* Enable SCSI-L */
end_comment

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_CABLE_DETECT
value|0x000F
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_EXT16_MASK
value|0x0008
end_define

begin_comment
comment|/* Ext16 cable pres */
end_comment

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_EXT8_MASK
value|0x0004
end_define

begin_comment
comment|/* Ext8 cable pres */
end_comment

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_INT8_MASK
value|0x0002
end_define

begin_comment
comment|/* Int8 cable pres */
end_comment

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_INT16_MASK
value|0x0001
end_define

begin_comment
comment|/* Int16 cable pres */
end_comment

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_ILLEGAL_CABLE_CONF_A_MASK
define|\
value|(ADW_SCSI_CFG1_EXT16_MASK|ADW_SCSI_CFG1_INT8_MASK|ADW_SCSI_CFG1_INT16_MASK)
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CFG1_ILLEGAL_CABLE_CONF_B_MASK
define|\
value|(ADW_SCSI_CFG1_EXT8_MASK|ADW_SCSI_CFG1_INT8_MASK|ADW_SCSI_CFG1_INT16_MASK)
end_define

begin_comment
comment|/*  * Addendum for ASC-38C0800 Chip  */
end_comment

begin_define
define|#
directive|define
name|ADW2_SCSI_CFG1_DIS_TERM_DRV
value|0x4000
end_define

begin_comment
comment|/* 							 * The Terminators 							 * must be disabled 							 * in order to detect 							 * cable presence 							 */
end_comment

begin_define
define|#
directive|define
name|ADW2_SCSI_CFG1_DEV_DETECT
value|0x1C00
end_define

begin_define
define|#
directive|define
name|ADW2_SCSI_CFG1_DEV_DETECT_HVD
value|0x1000
end_define

begin_define
define|#
directive|define
name|ADW2_SCSI_CFG1_DEV_DETECT_LVD
value|0x0800
end_define

begin_define
define|#
directive|define
name|ADW2_SCSI_CFG1_DEV_DETECT_SE
value|0x0400
end_define

begin_define
define|#
directive|define
name|ADW2_SCSI_CFG1_TERM_CTL_LVD
value|0x00C0
end_define

begin_comment
comment|/* Ultra2 Only */
end_comment

begin_define
define|#
directive|define
name|ADW2_SCSI_CFG1_TERM_LVD_HI
value|0x0080
end_define

begin_define
define|#
directive|define
name|ADW2_SCSI_CFG1_TERM_LVD_LO
value|0x0040
end_define

begin_define
define|#
directive|define
name|ADW2_SCSI_CFG1_EXTLVD_MASK
value|0x0008
end_define

begin_comment
comment|/* ExtLVD cable pres */
end_comment

begin_define
define|#
directive|define
name|ADW2_SCSI_CFG1_INTLVD_MASK
value|0x0004
end_define

begin_comment
comment|/* IntLVD cable pres */
end_comment

begin_define
define|#
directive|define
name|ADW_MEM_CFG
value|0x0010
end_define

begin_define
define|#
directive|define
name|ADW_MEM_CFG_BIOS_EN
value|0x40
end_define

begin_define
define|#
directive|define
name|ADW_MEM_CFG_FAST_EE_CLK
value|0x20
end_define

begin_comment
comment|/* Diagnostic Bit */
end_comment

begin_define
define|#
directive|define
name|ADW_MEM_CFG_RAM_SZ_MASK
value|0x1C
end_define

begin_comment
comment|/* RISC RAM Size */
end_comment

begin_define
define|#
directive|define
name|ADW_MEM_CFG_RAM_SZ_2KB
value|0x00
end_define

begin_define
define|#
directive|define
name|ADW_MEM_CFG_RAM_SZ_4KB
value|0x04
end_define

begin_define
define|#
directive|define
name|ADW_MEM_CFG_RAM_SZ_8KB
value|0x08
end_define

begin_define
define|#
directive|define
name|ADW_MEM_CFG_RAM_SZ_16KB
value|0x0C
end_define

begin_define
define|#
directive|define
name|ADW_MEM_CFG_RAM_SZ_32KB
value|0x10
end_define

begin_define
define|#
directive|define
name|ADW_MEM_CFG_RAM_SZ_64KB
value|0x14
end_define

begin_define
define|#
directive|define
name|ADW_GPIO_CNTL
value|0x0011
end_define

begin_define
define|#
directive|define
name|ADW_GPIO_DATA
value|0x0012
end_define

begin_define
define|#
directive|define
name|ADW_COMMA
value|0x0014
end_define

begin_define
define|#
directive|define
name|ADW_COMMB
value|0x0018
end_define

begin_define
define|#
directive|define
name|ADW_EEP_CMD
value|0x001A
end_define

begin_define
define|#
directive|define
name|ADW_EEP_CMD_READ
value|0x0080
end_define

begin_comment
comment|/* or in address */
end_comment

begin_define
define|#
directive|define
name|ADW_EEP_CMD_WRITE
value|0x0040
end_define

begin_comment
comment|/* or in address */
end_comment

begin_define
define|#
directive|define
name|ADW_EEP_CMD_WRITE_ABLE
value|0x0030
end_define

begin_define
define|#
directive|define
name|ADW_EEP_CMD_WRITE_DISABLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|ADW_EEP_CMD_DONE
value|0x0200
end_define

begin_define
define|#
directive|define
name|ADW_EEP_CMD_DONE_ERR
value|0x0001
end_define

begin_define
define|#
directive|define
name|ADW_EEP_DELAY_MS
value|100
end_define

begin_define
define|#
directive|define
name|ADW_EEP_DATA
value|0x001C
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0
value|0x0020
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_BC_THRESH_ENB
value|0x80
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_FIFO_THRESH
value|0x70
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_FIFO_THRESH_16B
value|0x00
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_FIFO_THRESH_32B
value|0x20
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_FIFO_THRESH_48B
value|0x30
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_FIFO_THRESH_64B
value|0x40
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_FIFO_THRESH_80B
value|0x50
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_FIFO_THRESH_96B
value|0x60
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_FIFO_THRESH_112B
value|0x70
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_START_CTL_MASK
value|0x0C
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_START_CTL_TH
value|0x00
end_define

begin_comment
comment|/* Start on thresh */
end_comment

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_START_CTL_IDLE
value|0x04
end_define

begin_comment
comment|/* Start when idle */
end_comment

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_START_CTL_TH_IDLE
value|0x08
end_define

begin_comment
comment|/* Either */
end_comment

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_START_CTL_EM_FU
value|0x0C
end_define

begin_comment
comment|/* Start on full/empty */
end_comment

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_READ_CMD_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_READ_CMD_MR
value|0x00
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_READ_CMD_MRL
value|0x02
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_READ_CMD_MRM
value|0x03
end_define

begin_define
define|#
directive|define
name|ADW_TICKLE
value|0x0022
end_define

begin_define
define|#
directive|define
name|ADW_TICKLE_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|ADW_TICKLE_A
value|0x01
end_define

begin_define
define|#
directive|define
name|ADW_TICKLE_B
value|0x02
end_define

begin_define
define|#
directive|define
name|ADW_TICKLE_C
value|0x03
end_define

begin_comment
comment|/* Program Counter */
end_comment

begin_define
define|#
directive|define
name|ADW_PC
value|0x2A
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CTRL
value|0x0034
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_CTRL_RSTOUT
value|0x2000
end_define

begin_comment
comment|/*  * ASC-38C0800 RAM BIST Register bit definitions  */
end_comment

begin_define
define|#
directive|define
name|ADW_RAM_BIST
value|0x0038
end_define

begin_define
define|#
directive|define
name|ADW_RAM_BIST_RAM_TEST_MODE
value|0x80
end_define

begin_define
define|#
directive|define
name|ADW_RAM_BIST_PRE_TEST_MODE
value|0x40
end_define

begin_define
define|#
directive|define
name|ADW_RAM_BIST_NORMAL_MODE
value|0x00
end_define

begin_define
define|#
directive|define
name|ADW_RAM_BIST_RAM_TEST_DONE
value|0x10
end_define

begin_define
define|#
directive|define
name|ADW_RAM_BIST_RAM_TEST_STATUS
value|0x0F
end_define

begin_define
define|#
directive|define
name|ADW_RAM_BIST_RAM_TEST_HOST_ERR
value|0x08
end_define

begin_define
define|#
directive|define
name|ADW_RAM_BIST_RAM_TEST_RAM_ERR
value|0x04
end_define

begin_define
define|#
directive|define
name|ADW_RAM_BIST_RAM_TEST_RISC_ERR
value|0x02
end_define

begin_define
define|#
directive|define
name|ADW_RAM_BIST_RAM_TEST_SCSI_ERR
value|0x01
end_define

begin_define
define|#
directive|define
name|ADW_RAM_BIST_RAM_TEST_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|ADW_RAM_BIST_PRE_TEST_VALUE
value|0x05
end_define

begin_define
define|#
directive|define
name|ADW_RAM_BIST_NORMAL_VALUE
value|0x00
end_define

begin_define
define|#
directive|define
name|ADW_PLL_TEST
value|0x0039
end_define

begin_define
define|#
directive|define
name|ADW_SCSI_RESET_HOLD_TIME_US
value|60
end_define

begin_comment
comment|/* LRAM Constants */
end_comment

begin_define
define|#
directive|define
name|ADW_3550_MEMSIZE
value|0x2000
end_define

begin_comment
comment|/* 8 KB Internal Memory */
end_comment

begin_define
define|#
directive|define
name|ADW_3550_IOLEN
value|0x40
end_define

begin_comment
comment|/* I/O Port Range in bytes */
end_comment

begin_define
define|#
directive|define
name|ADW_38C0800_MEMSIZE
value|0x4000
end_define

begin_comment
comment|/* 16 KB Internal Memory */
end_comment

begin_define
define|#
directive|define
name|ADW_38C0800_IOLEN
value|0x100
end_define

begin_comment
comment|/* I/O Port Range in bytes */
end_comment

begin_define
define|#
directive|define
name|ADW_38C1600_MEMSIZE
value|0x4000
end_define

begin_comment
comment|/* 16 KB Internal Memory */
end_comment

begin_define
define|#
directive|define
name|ADW_38C1600_IOLEN
value|0x100
end_define

begin_comment
comment|/* I/O Port Range in bytes */
end_comment

begin_define
define|#
directive|define
name|ADW_38C1600_MEMLEN
value|0x1000
end_define

begin_comment
comment|/* Memory Range 4KB */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_BIOSMEM
value|0x0040
end_define

begin_comment
comment|/* BIOS RISC Memory Start */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_BIOSLEN
value|0x0050
end_define

begin_comment
comment|/* BIOS RISC Memory Length */
end_comment

begin_define
define|#
directive|define
name|PCI_ID_ADVANSYS_3550
value|0x230010CD00000000ull
end_define

begin_define
define|#
directive|define
name|PCI_ID_ADVANSYS_38C0800_REV1
value|0x250010CD00000000ull
end_define

begin_define
define|#
directive|define
name|PCI_ID_ADVANSYS_38C1600_REV1
value|0x270010CD00000000ull
end_define

begin_define
define|#
directive|define
name|PCI_ID_ALL_MASK
value|0xFFFFFFFFFFFFFFFFull
end_define

begin_define
define|#
directive|define
name|PCI_ID_DEV_VENDOR_MASK
value|0xFFFFFFFF00000000ull
end_define

begin_comment
comment|/* ====================== SCSI Request Structures =========================== */
end_comment

begin_define
define|#
directive|define
name|ADW_NO_OF_SG_PER_BLOCK
value|15
end_define

begin_comment
comment|/*  * Although the adapter can deal with S/G lists of indefinite size,  * we limit the list to 30 to conserve space as the kernel can only send  * us buffers of at most 64KB currently.  */
end_comment

begin_define
define|#
directive|define
name|ADW_SG_BLOCKCNT
value|2
end_define

begin_define
define|#
directive|define
name|ADW_SGSIZE
value|(ADW_NO_OF_SG_PER_BLOCK * ADW_SG_BLOCKCNT)
end_define

begin_struct
struct|struct
name|adw_sg_elm
block|{
name|u_int32_t
name|sg_addr
decl_stmt|;
name|u_int32_t
name|sg_count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* sg block structure used by the microcode */
end_comment

begin_struct
struct|struct
name|adw_sg_block
block|{
name|u_int8_t
name|reserved1
decl_stmt|;
name|u_int8_t
name|reserved2
decl_stmt|;
name|u_int8_t
name|reserved3
decl_stmt|;
name|u_int8_t
name|sg_cnt
decl_stmt|;
comment|/* Valid entries in this block */
name|u_int32_t
name|sg_busaddr_next
decl_stmt|;
comment|/* link to the next sg block */
name|struct
name|adw_sg_elm
name|sg_list
index|[
name|ADW_NO_OF_SG_PER_BLOCK
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure representing a single allocation block of adw sg blocks */
end_comment

begin_struct
struct|struct
name|sg_map_node
block|{
name|bus_dmamap_t
name|sg_dmamap
decl_stmt|;
name|bus_addr_t
name|sg_physaddr
decl_stmt|;
name|struct
name|adw_sg_block
modifier|*
name|sg_vaddr
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|sg_map_node
argument_list|)
name|links
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|QHSTA_NO_ERROR
init|=
literal|0x00
block|,
name|QHSTA_M_SEL_TIMEOUT
init|=
literal|0x11
block|,
name|QHSTA_M_DATA_OVER_RUN
init|=
literal|0x12
block|,
name|QHSTA_M_UNEXPECTED_BUS_FREE
init|=
literal|0x13
block|,
name|QHSTA_M_QUEUE_ABORTED
init|=
literal|0x15
block|,
name|QHSTA_M_SXFR_SDMA_ERR
init|=
literal|0x16
block|,
comment|/* SCSI DMA Error */
name|QHSTA_M_SXFR_SXFR_PERR
init|=
literal|0x17
block|,
comment|/* SCSI Bus Parity Error */
name|QHSTA_M_RDMA_PERR
init|=
literal|0x18
block|,
comment|/* RISC PCI DMA parity error */
name|QHSTA_M_SXFR_OFF_UFLW
init|=
literal|0x19
block|,
comment|/* Offset Underflow */
name|QHSTA_M_SXFR_OFF_OFLW
init|=
literal|0x20
block|,
comment|/* Offset Overflow */
name|QHSTA_M_SXFR_WD_TMO
init|=
literal|0x21
block|,
comment|/* Watchdog Timeout */
name|QHSTA_M_SXFR_DESELECTED
init|=
literal|0x22
block|,
comment|/* Deselected */
name|QHSTA_M_SXFR_XFR_PH_ERR
init|=
literal|0x24
block|,
comment|/* Transfer Phase Error */
name|QHSTA_M_SXFR_UNKNOWN_ERROR
init|=
literal|0x25
block|,
comment|/* SXFR_STATUS Unknown Error */
name|QHSTA_M_SCSI_BUS_RESET
init|=
literal|0x30
block|,
comment|/* Request aborted from SBR */
name|QHSTA_M_SCSI_BUS_RESET_UNSOL
init|=
literal|0x31
block|,
comment|/* Request aborted from unsol. SBR*/
name|QHSTA_M_BUS_DEVICE_RESET
init|=
literal|0x32
block|,
comment|/* Request aborted from BDR */
name|QHSTA_M_DIRECTION_ERR
init|=
literal|0x35
block|,
comment|/* Data Phase mismatch */
name|QHSTA_M_DIRECTION_ERR_HUNG
init|=
literal|0x36
block|,
comment|/* Data Phase mismatch - bus hang */
name|QHSTA_M_WTM_TIMEOUT
init|=
literal|0x41
block|,
name|QHSTA_M_BAD_CMPL_STATUS_IN
init|=
literal|0x42
block|,
name|QHSTA_M_NO_AUTO_REQ_SENSE
init|=
literal|0x43
block|,
name|QHSTA_M_AUTO_REQ_SENSE_FAIL
init|=
literal|0x44
block|,
name|QHSTA_M_INVALID_DEVICE
init|=
literal|0x45
block|,
comment|/* Bad target ID */
name|QHSTA_M_FROZEN_TIDQ
init|=
literal|0x46
block|,
comment|/* TID Queue frozen. */
name|QHSTA_M_SGBACKUP_ERROR
init|=
literal|0x47
comment|/* Scatter-Gather backup error */
block|}
name|host_status_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|QD_NO_STATUS
init|=
literal|0x00
block|,
comment|/* Request not completed yet. */
name|QD_NO_ERROR
init|=
literal|0x01
block|,
name|QD_ABORTED_BY_HOST
init|=
literal|0x02
block|,
name|QD_WITH_ERROR
init|=
literal|0x04
block|}
name|done_status_t
typedef|;
end_typedef

begin_comment
comment|/*  * Microcode request structure  *  * All fields in this structure are used by the microcode so their  * size and ordering cannot be changed.  */
end_comment

begin_struct
struct|struct
name|adw_scsi_req_q
block|{
name|u_int8_t
name|cntl
decl_stmt|;
comment|/* Ucode flags and state. */
name|u_int8_t
name|target_cmd
decl_stmt|;
name|u_int8_t
name|target_id
decl_stmt|;
comment|/* Device target identifier. */
name|u_int8_t
name|target_lun
decl_stmt|;
comment|/* Device target logical unit number. */
name|u_int32_t
name|data_addr
decl_stmt|;
comment|/* Data buffer physical address. */
name|u_int32_t
name|data_cnt
decl_stmt|;
comment|/* Data count. Ucode sets to residual. */
name|u_int32_t
name|sense_baddr
decl_stmt|;
comment|/* Sense buffer bus address. */
name|u_int32_t
name|carrier_baddr
decl_stmt|;
comment|/* Carrier bus address. */
name|u_int8_t
name|mflag
decl_stmt|;
comment|/* microcode flag field. */
name|u_int8_t
name|sense_len
decl_stmt|;
comment|/* Auto-sense length. Residual on complete. */
name|u_int8_t
name|cdb_len
decl_stmt|;
comment|/* SCSI CDB length. */
name|u_int8_t
name|scsi_cntl
decl_stmt|;
comment|/* SCSI command control flags (tags, nego) */
define|#
directive|define
name|ADW_QSC_NO_DISC
value|0x01
define|#
directive|define
name|ADW_QSC_NO_TAGMSG
value|0x02
define|#
directive|define
name|ADW_QSC_NO_SYNC
value|0x04
define|#
directive|define
name|ADW_QSC_NO_WIDE
value|0x08
define|#
directive|define
name|ADW_QSC_REDO_DTR
value|0x10
comment|/* Renegotiate WDTR/SDTR */
define|#
directive|define
name|ADW_QSC_SIMPLE_Q_TAG
value|0x00
define|#
directive|define
name|ADW_QSC_HEAD_OF_Q_TAG
value|0x40
define|#
directive|define
name|ADW_QSC_ORDERED_Q_TAG
value|0x80
name|u_int8_t
name|done_status
decl_stmt|;
comment|/* Completion status. */
name|u_int8_t
name|scsi_status
decl_stmt|;
comment|/* SCSI status byte. */
name|u_int8_t
name|host_status
decl_stmt|;
comment|/* Ucode host status. */
name|u_int8_t
name|sg_wk_ix
decl_stmt|;
comment|/* Microcode working SG index. */
name|u_int8_t
name|cdb
index|[
literal|12
index|]
decl_stmt|;
comment|/* SCSI command block. */
name|u_int32_t
name|sg_real_addr
decl_stmt|;
comment|/* SG list physical address. */
name|u_int32_t
name|scsi_req_baddr
decl_stmt|;
comment|/* Bus address of this structure. */
name|u_int32_t
name|sg_wk_data_cnt
decl_stmt|;
comment|/* Saved data count at disconnection. */
comment|/* 	 * The 'tokens' placed in these two fields are 	 * used to identify the scsi request and the next 	 * carrier in the response queue, *not* physical 	 * addresses.  This driver uses byte offsets for 	 * portability and speed of mapping back to either 	 * a virtual or physical address. 	 */
name|u_int32_t
name|scsi_req_bo
decl_stmt|;
comment|/* byte offset of this structure */
name|u_int32_t
name|carrier_bo
decl_stmt|;
comment|/* byte offst of our carrier. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|ACB_FREE
init|=
literal|0x00
block|,
name|ACB_ACTIVE
init|=
literal|0x01
block|,
name|ACB_RELEASE_SIMQ
init|=
literal|0x02
block|,
name|ACB_RECOVERY_ACB
init|=
literal|0x04
block|}
name|acb_state
typedef|;
end_typedef

begin_struct
struct|struct
name|acb
block|{
name|struct
name|adw_scsi_req_q
name|queue
decl_stmt|;
name|bus_dmamap_t
name|dmamap
decl_stmt|;
name|acb_state
name|state
decl_stmt|;
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
name|struct
name|adw_sg_block
modifier|*
name|sg_blocks
decl_stmt|;
name|bus_addr_t
name|sg_busaddr
decl_stmt|;
name|struct
name|scsi_sense_data
name|sense_data
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|acb
argument_list|)
name|links
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * EEPROM configuration format  *  * Field naming convention:   *  *  *_enable indicates the field enables or disables the feature. The  *  value is never reset.  *  *  *_able indicates both whether a feature should be enabled or disabled  *  and whether a device is capable of the feature. At initialization  *  this field may be set, but later if a device is found to be incapable  *  of the feature, the field is cleared.  *  * Default values are maintained in a_init.c in the structure  * Default_EEPROM_Config.  */
end_comment

begin_struct
struct|struct
name|adw_eeprom
block|{
name|u_int16_t
name|cfg_lsw
decl_stmt|;
comment|/* 00 power up initialization */
define|#
directive|define
name|ADW_EEPROM_BIG_ENDIAN
value|0x8000
define|#
directive|define
name|ADW_EEPROM_BIOS_ENABLE
value|0x4000
define|#
directive|define
name|ADW_EEPROM_TERM_POL
value|0x2000
define|#
directive|define
name|ADW_EEPROM_CIS_LD
value|0x1000
comment|/* bit 13 set - Term Polarity Control */
comment|/* bit 14 set - BIOS Enable */
comment|/* bit 15 set - Big Endian Mode */
name|u_int16_t
name|cfg_msw
decl_stmt|;
comment|/* unused */
name|u_int16_t
name|disc_enable
decl_stmt|;
name|u_int16_t
name|wdtr_able
decl_stmt|;
union|union
block|{
comment|/* 		 * sync enable bits for UW cards, 		 * actual sync rate for TID 0-3 		 * on U2W and U160 cards. 		 */
name|u_int16_t
name|sync_enable
decl_stmt|;
name|u_int16_t
name|sdtr1
decl_stmt|;
block|}
name|sync1
union|;
name|u_int16_t
name|start_motor
decl_stmt|;
name|u_int16_t
name|tagqng_able
decl_stmt|;
name|u_int16_t
name|bios_scan
decl_stmt|;
name|u_int16_t
name|scam_tolerant
decl_stmt|;
name|u_int8_t
name|adapter_scsi_id
decl_stmt|;
name|u_int8_t
name|bios_boot_delay
decl_stmt|;
name|u_int8_t
name|scsi_reset_delay
decl_stmt|;
name|u_int8_t
name|bios_id_lun
decl_stmt|;
comment|/*    high nibble is lun */
comment|/*    low nibble is scsi id */
name|u_int8_t
name|termination_se
decl_stmt|;
comment|/* 0 - automatic */
define|#
directive|define
name|ADW_EEPROM_TERM_AUTO
value|0
define|#
directive|define
name|ADW_EEPROM_TERM_OFF
value|1
define|#
directive|define
name|ADW_EEPROM_TERM_HIGH_ON
value|2
define|#
directive|define
name|ADW_EEPROM_TERM_BOTH_ON
value|3
name|u_int8_t
name|termination_lvd
decl_stmt|;
name|u_int16_t
name|bios_ctrl
decl_stmt|;
define|#
directive|define
name|ADW_BIOS_INIT_DIS
value|0x0001
comment|/* Don't act as initiator */
define|#
directive|define
name|ADW_BIOS_EXT_TRANS
value|0x0002
comment|/*> 1 GB support */
define|#
directive|define
name|ADW_BIOS_MORE_2DISK
value|0x0004
comment|/*> 1 GB support */
define|#
directive|define
name|ADW_BIOS_NO_REMOVABLE
value|0x0008
comment|/* don't support removable media */
define|#
directive|define
name|ADW_BIOS_CD_BOOT
value|0x0010
comment|/* support bootable CD */
define|#
directive|define
name|ADW_BIOS_SCAN_EN
value|0x0020
comment|/* BIOS SCAN enabled */
define|#
directive|define
name|ADW_BIOS_MULTI_LUN
value|0x0040
comment|/* probe luns */
define|#
directive|define
name|ADW_BIOS_MESSAGE
value|0x0080
comment|/* display BIOS message */
define|#
directive|define
name|ADW_BIOS_RESET_BUS
value|0x0200
comment|/* reset SCSI bus durint init */
define|#
directive|define
name|ADW_BIOS_QUIET
value|0x0800
comment|/* No verbose initialization */
define|#
directive|define
name|ADW_BIOS_SCSI_PAR_EN
value|0x1000
comment|/* SCSI parity enabled */
union|union
block|{
comment|/* 13 		 * ultra enable bits for UW cards, 		 * actual sync rate for TID 4-7 		 * on U2W and U160 cards. 		 */
name|u_int16_t
name|ultra_enable
decl_stmt|;
name|u_int16_t
name|sdtr2
decl_stmt|;
block|}
name|sync2
union|;
union|union
block|{
comment|/* 14 		 * reserved for UW cards, 		 * actual sync rate for TID 8-11 		 * on U2W and U160 cards. 		 */
name|u_int16_t
name|reserved
decl_stmt|;
name|u_int16_t
name|sdtr3
decl_stmt|;
block|}
name|sync3
union|;
name|u_int8_t
name|max_host_qng
decl_stmt|;
comment|/* 15 maximum host queuing */
name|u_int8_t
name|max_dvc_qng
decl_stmt|;
comment|/*    maximum per device queuing */
name|u_int16_t
name|dvc_cntl
decl_stmt|;
comment|/* 16 control bit for driver */
union|union
block|{
comment|/* 17 		 * reserved for UW cards, 		 * actual sync rate for TID 12-15 		 * on U2W and U160 cards. 		 */
name|u_int16_t
name|reserved
decl_stmt|;
name|u_int16_t
name|sdtr4
decl_stmt|;
block|}
name|sync4
union|;
name|u_int16_t
name|serial_number
index|[
literal|3
index|]
decl_stmt|;
comment|/* 18-20 */
name|u_int16_t
name|checksum
decl_stmt|;
comment|/* 21 */
name|u_int8_t
name|oem_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* 22 - 29 */
name|u_int16_t
name|dvc_err_code
decl_stmt|;
comment|/* 30 */
name|u_int16_t
name|adv_err_code
decl_stmt|;
comment|/* 31 */
name|u_int16_t
name|adv_err_addr
decl_stmt|;
comment|/* 32 */
name|u_int16_t
name|saved_dvc_err_code
decl_stmt|;
comment|/* 33 */
name|u_int16_t
name|saved_adv_err_code
decl_stmt|;
comment|/* 34 */
name|u_int16_t
name|saved_adv_err_addr
decl_stmt|;
comment|/* 35 */
name|u_int16_t
name|reserved
index|[
literal|20
index|]
decl_stmt|;
comment|/* 36 - 55 */
name|u_int16_t
name|cisptr_lsw
decl_stmt|;
comment|/* 56 CIS data */
name|u_int16_t
name|cisptr_msw
decl_stmt|;
comment|/* 57 CIS data */
name|u_int32_t
name|subid
decl_stmt|;
comment|/* 58-59 SubSystem Vendor/Dev ID */
name|u_int16_t
name|reserved2
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* EEProm Addresses */
end_comment

begin_define
define|#
directive|define
name|ADW_EEP_DVC_CFG_BEGIN
value|0x00
end_define

begin_define
define|#
directive|define
name|ADW_EEP_DVC_CFG_END
value|(offsetof(struct adw_eeprom, checksum)/2)
end_define

begin_define
define|#
directive|define
name|ADW_EEP_DVC_CTL_BEGIN
value|(offsetof(struct adw_eeprom, oem_name)/2)
end_define

begin_define
define|#
directive|define
name|ADW_EEP_MAX_WORD_ADDR
value|(sizeof(struct adw_eeprom)/2)
end_define

begin_define
define|#
directive|define
name|ADW_BUS_RESET_HOLD_DELAY_US
value|100
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|ADW_CHIP_NONE
block|,
name|ADW_CHIP_ASC3550
block|,
comment|/* Ultra-Wide IC */
name|ADW_CHIP_ASC38C0800
block|,
comment|/* Ultra2-Wide/LVD IC */
name|ADW_CHIP_ASC38C1600
comment|/* Ultra3-Wide/LVD2 IC */
block|}
name|adw_chip
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|ADW_FENONE
init|=
literal|0x0000
block|,
name|ADW_ULTRA
init|=
literal|0x0001
block|,
comment|/* Supports 20MHz Transfers */
name|ADW_ULTRA2
init|=
literal|0x0002
block|,
comment|/* Supports 40MHz Transfers */
name|ADW_DT
init|=
literal|0x0004
block|,
comment|/* Supports Double Transistion REQ/ACK*/
name|ADW_WIDE
init|=
literal|0x0008
block|,
comment|/* Wide Channel */
name|ADW_ASC3550_FE
init|=
name|ADW_ULTRA
block|,
name|ADW_ASC38C0800_FE
init|=
name|ADW_ULTRA2
block|,
name|ADW_ASC38C1600_FE
init|=
name|ADW_ULTRA2
operator||
name|ADW_DT
block|}
name|adw_feature
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|ADW_FNONE
init|=
literal|0x0000
block|,
name|ADW_EEPROM_FAILED
init|=
literal|0x0001
block|}
name|adw_flag
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|ADW_STATE_NORMAL
init|=
literal|0x00
block|,
name|ADW_RESOURCE_SHORTAGE
init|=
literal|0x01
block|}
name|adw_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|ADW_MC_SDTR_ASYNC
block|,
name|ADW_MC_SDTR_5
block|,
name|ADW_MC_SDTR_10
block|,
name|ADW_MC_SDTR_20
block|,
name|ADW_MC_SDTR_40
block|,
name|ADW_MC_SDTR_80
block|}
name|adw_mc_sdtr
typedef|;
end_typedef

begin_struct
struct|struct
name|adw_syncrate
block|{
name|adw_mc_sdtr
name|mc_sdtr
decl_stmt|;
name|u_int8_t
name|period
decl_stmt|;
name|char
modifier|*
name|rate
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* We have an input and output queue for our carrier structures */
end_comment

begin_define
define|#
directive|define
name|ADW_OUTPUT_QUEUE
value|0
end_define

begin_comment
comment|/* Offset into carriers member */
end_comment

begin_define
define|#
directive|define
name|ADW_INPUT_QUEUE
value|1
end_define

begin_comment
comment|/* Offset into carriers member */
end_comment

begin_define
define|#
directive|define
name|ADW_NUM_CARRIER_QUEUES
value|2
end_define

begin_struct
struct|struct
name|adw_softc
block|{
name|bus_space_tag_t
name|tag
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|adw_state
name|state
decl_stmt|;
name|bus_dma_tag_t
name|buffer_dmat
decl_stmt|;
name|struct
name|acb
modifier|*
name|acbs
decl_stmt|;
name|struct
name|adw_carrier
modifier|*
name|carriers
decl_stmt|;
name|struct
name|adw_carrier
modifier|*
name|free_carriers
decl_stmt|;
name|struct
name|adw_carrier
modifier|*
name|commandq
decl_stmt|;
name|struct
name|adw_carrier
modifier|*
name|responseq
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ccb_hdr
argument_list|)
name|pending_ccbs
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|acb
argument_list|)
name|free_acb_list
expr_stmt|;
name|bus_dma_tag_t
name|parent_dmat
decl_stmt|;
name|bus_dma_tag_t
name|carrier_dmat
decl_stmt|;
comment|/* dmat for our acb carriers*/
name|bus_dmamap_t
name|carrier_dmamap
decl_stmt|;
name|bus_dma_tag_t
name|acb_dmat
decl_stmt|;
comment|/* dmat for our ccb array */
name|bus_dmamap_t
name|acb_dmamap
decl_stmt|;
name|bus_dma_tag_t
name|sg_dmat
decl_stmt|;
comment|/* dmat for our sg maps */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|sg_map_node
argument_list|)
name|sg_maps
expr_stmt|;
name|bus_addr_t
name|acb_busbase
decl_stmt|;
name|bus_addr_t
name|carrier_busbase
decl_stmt|;
name|adw_chip
name|chip
decl_stmt|;
name|adw_feature
name|features
decl_stmt|;
name|adw_flag
name|flags
decl_stmt|;
name|u_int
name|memsize
decl_stmt|;
name|char
name|channel
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|resource
modifier|*
name|regs
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|void
modifier|*
name|ih
decl_stmt|;
specifier|const
name|struct
name|adw_mcode
modifier|*
name|mcode_data
decl_stmt|;
specifier|const
name|struct
name|adw_eeprom
modifier|*
name|default_eeprom
decl_stmt|;
name|device_t
name|device
decl_stmt|;
name|int
name|regs_res_type
decl_stmt|;
name|int
name|regs_res_id
decl_stmt|;
name|int
name|irq_res_type
decl_stmt|;
name|u_int
name|max_acbs
decl_stmt|;
name|u_int
name|num_acbs
decl_stmt|;
name|u_int
name|initiator_id
decl_stmt|;
name|u_int
name|init_level
decl_stmt|;
name|u_int
name|unit
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|cam_status
name|last_reset
decl_stmt|;
comment|/* Last reset type */
name|u_int16_t
name|bios_ctrl
decl_stmt|;
name|u_int16_t
name|user_wdtr
decl_stmt|;
name|u_int16_t
name|user_sdtr
index|[
literal|4
index|]
decl_stmt|;
comment|/* A nibble per-device */
name|u_int16_t
name|user_tagenb
decl_stmt|;
name|u_int16_t
name|tagenb
decl_stmt|;
name|u_int16_t
name|user_discenb
decl_stmt|;
name|u_int16_t
name|serial_number
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|adw_eeprom
name|adw_asc3550_default_eeprom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|adw_eeprom
name|adw_asc38C0800_default_eeprom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|adw_syncrate
name|adw_syncrates
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|adw_num_syncrates
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|adw_inb
parameter_list|(
name|adw
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_1((adw)->tag, (adw)->bsh, port)
end_define

begin_define
define|#
directive|define
name|adw_inw
parameter_list|(
name|adw
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_2((adw)->tag, (adw)->bsh, port)
end_define

begin_define
define|#
directive|define
name|adw_inl
parameter_list|(
name|adw
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_4((adw)->tag, (adw)->bsh, port)
end_define

begin_define
define|#
directive|define
name|adw_outb
parameter_list|(
name|adw
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1((adw)->tag, (adw)->bsh, port, value)
end_define

begin_define
define|#
directive|define
name|adw_outw
parameter_list|(
name|adw
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_2((adw)->tag, (adw)->bsh, port, value)
end_define

begin_define
define|#
directive|define
name|adw_outl
parameter_list|(
name|adw
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_4((adw)->tag, (adw)->bsh, port, value)
end_define

begin_define
define|#
directive|define
name|adw_set_multi_2
parameter_list|(
name|adw
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_set_multi_2((adw)->tag, (adw)->bsh, port, value, count)
end_define

begin_function_decl
specifier|static
name|__inline
specifier|const
name|char
modifier|*
name|adw_name
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|u_int
name|adw_lram_read_8
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|u_int
name|adw_lram_read_16
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|u_int
name|adw_lram_read_32
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|adw_lram_write_8
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|addr
parameter_list|,
name|u_int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|adw_lram_write_16
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|addr
parameter_list|,
name|u_int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|adw_lram_write_32
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|addr
parameter_list|,
name|u_int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|u_int32_t
name|acbvtobo
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|struct
name|acb
modifier|*
name|acb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|u_int32_t
name|acbvtob
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|struct
name|acb
modifier|*
name|acb
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|acb
operator|*
name|acbbotov
argument_list|(
argument|struct adw_softc *adw
argument_list|,
argument|u_int32_t busaddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|acb
operator|*
name|acbbtov
argument_list|(
argument|struct adw_softc *adw
argument_list|,
argument|u_int32_t busaddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|__inline
name|u_int32_t
name|carriervtobo
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|struct
name|adw_carrier
modifier|*
name|carrier
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|u_int32_t
name|carriervtob
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|struct
name|adw_carrier
modifier|*
name|carrier
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|adw_carrier
operator|*
name|carrierbotov
argument_list|(
argument|struct adw_softc *adw
argument_list|,
argument|u_int32_t byte_offset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|adw_carrier
operator|*
name|carrierbtov
argument_list|(
argument|struct adw_softc *adw
argument_list|,
argument|u_int32_t baddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|__inline
specifier|const
name|char
modifier|*
name|adw_name
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|)
block|{
return|return
operator|(
name|adw
operator|->
name|name
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|adw_lram_read_8
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|addr
parameter_list|)
block|{
name|adw_outw
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_ADDR
argument_list|,
name|addr
argument_list|)
expr_stmt|;
return|return
operator|(
name|adw_inb
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_DATA
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|adw_lram_read_16
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|addr
parameter_list|)
block|{
name|adw_outw
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_ADDR
argument_list|,
name|addr
argument_list|)
expr_stmt|;
return|return
operator|(
name|adw_inw
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_DATA
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|adw_lram_read_32
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|addr
parameter_list|)
block|{
name|u_int
name|retval
decl_stmt|;
name|adw_outw
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_ADDR
argument_list|,
name|addr
argument_list|)
expr_stmt|;
name|retval
operator|=
name|adw_inw
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_DATA
argument_list|)
expr_stmt|;
name|retval
operator||=
operator|(
name|adw_inw
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_DATA
argument_list|)
operator|<<
literal|16
operator|)
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|adw_lram_write_8
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|addr
parameter_list|,
name|u_int
name|value
parameter_list|)
block|{
name|adw_outw
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_ADDR
argument_list|,
name|addr
argument_list|)
expr_stmt|;
name|adw_outb
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_DATA
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|adw_lram_write_16
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|addr
parameter_list|,
name|u_int
name|value
parameter_list|)
block|{
name|adw_outw
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_ADDR
argument_list|,
name|addr
argument_list|)
expr_stmt|;
name|adw_outw
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_DATA
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|adw_lram_write_32
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|addr
parameter_list|,
name|u_int
name|value
parameter_list|)
block|{
name|adw_outw
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_ADDR
argument_list|,
name|addr
argument_list|)
expr_stmt|;
name|adw_outw
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_DATA
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|adw_outw
argument_list|(
name|adw
argument_list|,
name|ADW_RAM_DATA
argument_list|,
name|value
operator|>>
literal|16
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|acbvtobo
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|struct
name|acb
modifier|*
name|acb
parameter_list|)
block|{
return|return
operator|(
call|(
name|u_int32_t
call|)
argument_list|(
operator|(
name|caddr_t
operator|)
name|acb
operator|-
operator|(
name|caddr_t
operator|)
name|adw
operator|->
name|acbs
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|acbvtob
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|struct
name|acb
modifier|*
name|acb
parameter_list|)
block|{
return|return
operator|(
name|adw
operator|->
name|acb_busbase
operator|+
name|acbvtobo
argument_list|(
name|adw
argument_list|,
name|acb
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|acb
operator|*
name|acbbotov
argument_list|(
argument|struct adw_softc *adw
argument_list|,
argument|u_int32_t byteoffset
argument_list|)
block|{
return|return
operator|(
operator|(
expr|struct
name|acb
operator|*
operator|)
operator|(
operator|(
name|caddr_t
operator|)
name|adw
operator|->
name|acbs
operator|+
name|byteoffset
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|acb
operator|*
name|acbbtov
argument_list|(
argument|struct adw_softc *adw
argument_list|,
argument|u_int32_t busaddr
argument_list|)
block|{
return|return
operator|(
name|acbbotov
argument_list|(
name|adw
argument_list|,
name|busaddr
operator|-
name|adw
operator|->
name|acb_busbase
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/*  * Return the byte offset for a carrier relative to our array of carriers.  */
end_comment

begin_function
specifier|static
name|__inline
name|u_int32_t
name|carriervtobo
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|struct
name|adw_carrier
modifier|*
name|carrier
parameter_list|)
block|{
return|return
operator|(
call|(
name|u_int32_t
call|)
argument_list|(
operator|(
name|caddr_t
operator|)
name|carrier
operator|-
operator|(
name|caddr_t
operator|)
name|adw
operator|->
name|carriers
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|carriervtob
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|struct
name|adw_carrier
modifier|*
name|carrier
parameter_list|)
block|{
return|return
operator|(
name|adw
operator|->
name|carrier_busbase
operator|+
name|carriervtobo
argument_list|(
name|adw
argument_list|,
name|carrier
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|adw_carrier
operator|*
name|carrierbotov
argument_list|(
argument|struct adw_softc *adw
argument_list|,
argument|u_int32_t byte_offset
argument_list|)
block|{
return|return
operator|(
operator|(
expr|struct
name|adw_carrier
operator|*
operator|)
operator|(
operator|(
name|caddr_t
operator|)
name|adw
operator|->
name|carriers
operator|+
name|byte_offset
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|adw_carrier
operator|*
name|carrierbtov
argument_list|(
argument|struct adw_softc *adw
argument_list|,
argument|u_int32_t baddr
argument_list|)
block|{
return|return
operator|(
name|carrierbotov
argument_list|(
name|adw
argument_list|,
name|baddr
operator|-
name|adw
operator|->
name|carrier_busbase
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/* Intialization */
end_comment

begin_function_decl
name|int
name|adw_find_signature
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adw_reset_chip
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adw_reset_bus
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|adw_eeprom_read
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|struct
name|adw_eeprom
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adw_eeprom_write
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|struct
name|adw_eeprom
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adw_init_chip
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|term_scsicfg1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adw_set_user_sdtr
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|tid
parameter_list|,
name|u_int
name|mc_sdtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|adw_get_user_sdtr
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adw_set_chip_sdtr
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|tid
parameter_list|,
name|u_int
name|sdtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|adw_get_chip_sdtr
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|adw_find_sdtr
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|period
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|adw_find_period
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|mc_sdtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|adw_hshk_cfg_period_factor
parameter_list|(
name|u_int
name|tinfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Idle Commands */
end_comment

begin_function_decl
name|adw_idle_cmd_status_t
name|adw_idle_cmd_send
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|cmd
parameter_list|,
name|u_int
name|parameter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* SCSI Transaction Processing */
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|adw_send_acb
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|struct
name|acb
modifier|*
name|acb
parameter_list|,
name|u_int32_t
name|acb_baddr
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|adw_tickle_risc
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|u_int
name|value
parameter_list|)
block|{
comment|/* 	 * Tickle the RISC to tell it to read its Command Queue Head pointer. 	 */
name|adw_outb
argument_list|(
name|adw
argument_list|,
name|ADW_TICKLE
argument_list|,
name|value
argument_list|)
expr_stmt|;
if|if
condition|(
name|adw
operator|->
name|chip
operator|==
name|ADW_CHIP_ASC3550
condition|)
block|{
comment|/* 		 * Clear the tickle value. In the ASC-3550 the RISC flag 		 * command 'clr_tickle_a' does not work unless the host 		 * value is cleared. 		 */
name|adw_outb
argument_list|(
name|adw
argument_list|,
name|ADW_TICKLE
argument_list|,
name|ADW_TICKLE_NOP
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|adw_send_acb
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
parameter_list|,
name|struct
name|acb
modifier|*
name|acb
parameter_list|,
name|u_int32_t
name|acb_baddr
parameter_list|)
block|{
name|struct
name|adw_carrier
modifier|*
name|new_cq
decl_stmt|;
name|new_cq
operator|=
name|adw
operator|->
name|free_carriers
expr_stmt|;
name|adw
operator|->
name|free_carriers
operator|=
name|carrierbotov
argument_list|(
name|adw
argument_list|,
name|new_cq
operator|->
name|next_ba
argument_list|)
expr_stmt|;
name|new_cq
operator|->
name|next_ba
operator|=
name|ADW_CQ_STOPPER
expr_stmt|;
name|acb
operator|->
name|queue
operator|.
name|carrier_baddr
operator|=
name|adw
operator|->
name|commandq
operator|->
name|carr_ba
expr_stmt|;
name|acb
operator|->
name|queue
operator|.
name|carrier_bo
operator|=
name|adw
operator|->
name|commandq
operator|->
name|carr_offset
expr_stmt|;
name|adw
operator|->
name|commandq
operator|->
name|areq_ba
operator|=
name|acbvtob
argument_list|(
name|adw
argument_list|,
name|acb
argument_list|)
expr_stmt|;
name|adw
operator|->
name|commandq
operator|->
name|next_ba
operator|=
name|new_cq
operator|->
name|carr_ba
expr_stmt|;
if|#
directive|if
literal|0
block|printf("EnQ 0x%x 0x%x 0x%x 0x%x\n", 	       adw->commandq->carr_offset, 	       adw->commandq->carr_ba, 	       adw->commandq->areq_ba, 	       adw->commandq->next_ba);
endif|#
directive|endif
name|adw
operator|->
name|commandq
operator|=
name|new_cq
expr_stmt|;
name|adw_tickle_risc
argument_list|(
name|adw
argument_list|,
name|ADW_TICKLE_A
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ADWLIB_H_ */
end_comment

end_unit

