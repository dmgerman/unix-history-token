begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions for low level routines and data structures  * for the Advanced Systems Inc. SCSI controllers chips.  *  * Copyright (c) 1998 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|ADW_DMA_CFG0_IFO_THRESH_48B
value|0x30
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_IFO_THRESH_64B
value|0x40
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_IFO_THRESH_80B
value|0x50
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_IFO_THRESH_96B
value|0x60
end_define

begin_define
define|#
directive|define
name|ADW_DMA_CFG0_IFO_THRESH_112B
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
name|ADW_CONDOR_MEMSIZE
value|0x2000
end_define

begin_comment
comment|/* 8 KB Internal Memory */
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
name|first_entry_no
decl_stmt|;
comment|/* starting entry number */
name|u_int8_t
name|last_entry_no
decl_stmt|;
comment|/* last entry number */
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
comment|/* Bad target ID */
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
name|sg_entry_cnt
decl_stmt|;
comment|/* SG element count. Zero for no SG. */
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
name|sense_addr
decl_stmt|;
comment|/* Sense buffer physical address. */
name|u_int32_t
name|srb_ptr
decl_stmt|;
comment|/* Driver request pointer. */
name|u_int8_t
name|a_flag
decl_stmt|;
comment|/* Adv Library flag field. */
name|u_int8_t
name|sense_len
decl_stmt|;
comment|/* Auto-sense length. Residual on complete. */
name|u_int8_t
name|cdb_len
decl_stmt|;
comment|/* SCSI CDB length. */
name|u_int8_t
name|tag_code
decl_stmt|;
comment|/* SCSI-2 Tag Queue Code: 00, 20-22. */
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
name|ux_sg_ix
decl_stmt|;
comment|/* Ucode working SG variable. */
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
name|free_scsiq_link
decl_stmt|;
comment|/* Unused */
name|u_int32_t
name|ux_wk_data_cnt
decl_stmt|;
comment|/* Saved data count at disconnection. */
name|u_int32_t
name|scsi_req_baddr
decl_stmt|;
comment|/* Bus address of this request. */
name|u_int32_t
name|sg_block_index
decl_stmt|;
comment|/* sg_block tag (Unused) */
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|bios_init_dis
range|:
literal|1
decl_stmt|,
comment|/* don't act as initiator. */
name|bios_ext_trans
range|:
literal|1
decl_stmt|,
comment|/*> 1 GB support */
name|bios_more_2disk
range|:
literal|1
decl_stmt|,
comment|/*> 2 Disk Support */
name|bios_no_removable
range|:
literal|1
decl_stmt|,
comment|/* don't support removables */
name|bios_cd_boot
range|:
literal|1
decl_stmt|,
comment|/* support bootable CD */
range|:
literal|1
decl_stmt|,
name|bios_multi_lun
range|:
literal|1
decl_stmt|,
comment|/* support multiple LUNs */
name|bios_message
range|:
literal|1
decl_stmt|,
comment|/* display BIOS message */
range|:
literal|1
decl_stmt|,
name|bios_reset_sb
range|:
literal|1
decl_stmt|,
comment|/* Reset SCSI bus during init. */
range|:
literal|1
decl_stmt|,
name|bios_quiet
range|:
literal|1
decl_stmt|,
comment|/* No verbose initialization. */
name|bios_scsi_par_en
range|:
literal|1
decl_stmt|,
comment|/* SCSI parity enabled */
range|:
literal|3
decl_stmt|;
block|}
name|adw_bios_ctrl
typedef|;
end_typedef

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
name|u_int16_t
name|sdtr_able
decl_stmt|;
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
name|termination
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
name|reserved1
decl_stmt|;
comment|/*    reserved byte (not used) */
name|adw_bios_ctrl
name|bios_ctrl
decl_stmt|;
name|u_int16_t
name|ultra_able
decl_stmt|;
comment|/* 13 ULTRA speed able */
name|u_int16_t
name|reserved2
decl_stmt|;
comment|/* 14 reserved */
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
name|u_int16_t
name|bug_fix
decl_stmt|;
comment|/* 17 control bit for bug fix */
name|u_int16_t
name|serial_number
index|[
literal|3
index|]
decl_stmt|;
name|u_int16_t
name|checksum
decl_stmt|;
name|u_int8_t
name|oem_name
index|[
literal|16
index|]
decl_stmt|;
name|u_int16_t
name|dvc_err_code
decl_stmt|;
name|u_int16_t
name|adv_err_code
decl_stmt|;
name|u_int16_t
name|adv_err_addr
decl_stmt|;
name|u_int16_t
name|saved_dvc_err_code
decl_stmt|;
name|u_int16_t
name|saved_adv_err_code
decl_stmt|;
name|u_int16_t
name|saved_adv_err_addr
decl_stmt|;
name|u_int16_t
name|num_of_err
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
name|adw_bios_ctrl
name|bios_ctrl
decl_stmt|;
name|adw_idle_cmd_t
name|idle_cmd
decl_stmt|;
name|u_int
name|idle_cmd_param
decl_stmt|;
specifier|volatile
name|int
name|idle_command_cmp
decl_stmt|;
name|u_int16_t
name|user_wdtr
decl_stmt|;
name|u_int16_t
name|user_sdtr
decl_stmt|;
name|u_int16_t
name|user_ultra
decl_stmt|;
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
name|struct
name|adw_eeprom
name|adw_default_eeprom
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

begin_comment
comment|/* Intialization */
end_comment

begin_function_decl
name|int
name|adw_find_signature
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
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

begin_comment
comment|/* Idle Commands */
end_comment

begin_function_decl
name|void
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

begin_function_decl
name|adw_idle_cmd_status_t
name|adw_idle_cmd_wait
parameter_list|(
name|struct
name|adw_softc
modifier|*
name|adw
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
name|u_int
name|next_queue
decl_stmt|;
comment|/* Determine the next free queue. */
name|next_queue
operator|=
name|adw_lram_read_8
argument_list|(
name|adw
argument_list|,
name|ADW_MC_HOST_NEXT_READY
argument_list|)
expr_stmt|;
name|next_queue
operator|=
name|ADW_MC_RISC_Q_LIST_BASE
operator|+
operator|(
name|next_queue
operator|*
name|ADW_MC_RISC_Q_LIST_SIZE
operator|)
expr_stmt|;
comment|/* 	 * Write the physical address of the host Q to the free Q. 	 */
name|adw_lram_write_32
argument_list|(
name|adw
argument_list|,
name|next_queue
operator|+
name|RQL_PHYADDR
argument_list|,
name|acb_baddr
argument_list|)
expr_stmt|;
name|adw_lram_write_8
argument_list|(
name|adw
argument_list|,
name|next_queue
operator|+
name|RQL_TID
argument_list|,
name|acb
operator|->
name|queue
operator|.
name|target_id
argument_list|)
expr_stmt|;
comment|/* 	 * Set the ADW_MC_HOST_NEXT_READY (0x128) microcode variable to 	 * the 'next_queue' request forward pointer. 	 * 	 * Do this *before* changing the 'next_queue' queue to QS_READY. 	 * After the state is changed to QS_READY 'RQL_FWD' will be changed 	 * by the microcode. 	 * 	 */
name|adw_lram_write_8
argument_list|(
name|adw
argument_list|,
name|ADW_MC_HOST_NEXT_READY
argument_list|,
name|adw_lram_read_8
argument_list|(
name|adw
argument_list|,
name|next_queue
operator|+
name|RQL_FWD
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * Change the state of 'next_queue' request from QS_FREE to 	 * QS_READY which will cause the microcode to pick it up and 	 * execute it. 	 *   	 * Can't reference 'next_queue' after changing the request 	 * state to QS_READY. The microcode now owns the request. 	 */
name|adw_lram_write_8
argument_list|(
name|adw
argument_list|,
name|next_queue
operator|+
name|RQL_STATE
argument_list|,
name|ADW_MC_QS_READY
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

