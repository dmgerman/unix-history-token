begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions for low level routines and data structures  * for the Advanced Systems Inc. SCSI controllers chips.  *  * Copyright (c) 1996-1997, 1999-2000 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Ported from:  * advansys.c - Linux Host Driver for AdvanSys SCSI Adapters  *       * Copyright (c) 1995-1996 Advanced System Products, Inc.  * All Rights Reserved.  *     * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that redistributions of source  * code retain the above copyright notice and this comment without  * modification.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ADVLIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_ADVLIB_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct_decl
struct_decl|struct
name|cam_path
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|ccb
union_decl|;
end_union_decl

begin_typedef
typedef|typedef
name|u_int8_t
name|target_bit_vector
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TARGET_BIT_VECTOR_SET
value|-1
end_define

begin_define
define|#
directive|define
name|ADV_SCSI_ID_BITS
value|3
end_define

begin_define
define|#
directive|define
name|ADV_MAX_TID
value|7
end_define

begin_define
define|#
directive|define
name|ADV_MAX_LUN
value|7
end_define

begin_comment
comment|/* Enumeration of board types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ADV_NONE
init|=
literal|0x000
block|,
name|ADV_ISA
init|=
literal|0x001
block|,
name|ADV_ISAPNP
init|=
literal|0x003
block|,
name|ADV_VL
init|=
literal|0x004
block|,
name|ADV_EISA
init|=
literal|0x008
block|,
name|ADV_PCI
init|=
literal|0x010
block|,
name|ADV_MCA
init|=
literal|0x020
block|,
name|ADV_PCMCIA
init|=
literal|0x040
block|,
name|ADV_ULTRA
init|=
literal|0x100
block|,
name|ADV_WIDE
init|=
literal|0x200
block|,
name|ADV_WIDE32
init|=
literal|0x400
block|}
name|adv_btype
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|ADV_STATE_NONE
init|=
literal|0x00
block|,
name|ADV_RESOURCE_SHORTAGE
init|=
literal|0x01
block|,
name|ADV_IN_TIMEOUT
init|=
literal|0x02
block|,
name|ADV_BUSDMA_BLOCK
init|=
literal|0x04
block|,
name|ADV_BUSDMA_BLOCK_CLEARED
init|=
literal|0x08
block|}
name|adv_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|ACCB_FREE
init|=
literal|0x00
block|,
name|ACCB_ACTIVE
init|=
literal|0x01
block|,
name|ACCB_ABORT_QUEUED
init|=
literal|0x02
block|,
name|ACCB_RECOVERY_CCB
init|=
literal|0x04
block|}
name|adv_ccb_state
typedef|;
end_typedef

begin_struct
struct|struct
name|adv_ccb_info
block|{
name|adv_ccb_state
name|state
decl_stmt|;
name|bus_dmamap_t
name|dmamap
decl_stmt|;
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|adv_ccb_info
argument_list|)
name|links
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ccb_cinfo_ptr
value|spriv_ptr0
end_define

begin_define
define|#
directive|define
name|ADV_SYN_XFER_NO
value|8
end_define

begin_define
define|#
directive|define
name|ADV_SYN_MAX_OFFSET
value|0x0F
end_define

begin_define
define|#
directive|define
name|ADV_DEF_SDTR_OFFSET
value|0x0F
end_define

begin_define
define|#
directive|define
name|ADV_DEF_SDTR_INDEX
value|0x00
end_define

begin_define
define|#
directive|define
name|ADV_OVERRUN_BSIZE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ADV_MAX_CDB_LEN
value|12
end_define

begin_define
define|#
directive|define
name|ADV_MAX_SENSE_LEN
value|32
end_define

begin_define
define|#
directive|define
name|ADV_MIN_SENSE_LEN
value|14
end_define

begin_define
define|#
directive|define
name|ADV_TIDLUN_TO_IX
parameter_list|(
name|tid
parameter_list|,
name|lun
parameter_list|)
value|((tid) | ((lun)<< ADV_SCSI_ID_BITS) )
end_define

begin_define
define|#
directive|define
name|ADV_TID_TO_TARGET_MASK
parameter_list|(
name|tid
parameter_list|)
value|(0x01<< (tid))
end_define

begin_define
define|#
directive|define
name|ADV_TIX_TO_TARGET_MASK
parameter_list|(
name|tix
parameter_list|)
value|(0x01<< ((tix)& ADV_MAX_TID))
end_define

begin_define
define|#
directive|define
name|ADV_TIX_TO_TID
parameter_list|(
name|tix
parameter_list|)
value|((tix)& ADV_MAX_TID)
end_define

begin_define
define|#
directive|define
name|ADV_TID_TO_TIX
parameter_list|(
name|tid
parameter_list|)
value|((tid)& ADV_MAX_TID)
end_define

begin_define
define|#
directive|define
name|ADV_TIX_TO_LUN
parameter_list|(
name|tix
parameter_list|)
value|(((tix)>> ADV_SCSI_ID_BITS)& ADV_MAX_LUN )
end_define

begin_comment
comment|/*  * XXX  * PnP port addresses  * I believe that these are standard PnP address and should be replaced  * by the values in a central ISA PnP header file when we get one.  */
end_comment

begin_define
define|#
directive|define
name|ADV_ISA_PNP_PORT_ADDR
value|(0x279)
end_define

begin_define
define|#
directive|define
name|ADV_ISA_PNP_PORT_WRITE
value|(ADV_ISA_PNP_PORT_ADDR+0x800)
end_define

begin_comment
comment|/*  * Board Signatures  */
end_comment

begin_define
define|#
directive|define
name|ADV_SIGNATURE_WORD
value|0x0000
end_define

begin_define
define|#
directive|define
name|ADV_1000_ID0W
value|0x04C1
end_define

begin_define
define|#
directive|define
name|ADV_1000_ID0W_FIX
value|0x00C1
end_define

begin_define
define|#
directive|define
name|ADV_SIGNATURE_BYTE
value|0x0001
end_define

begin_define
define|#
directive|define
name|ADV_1000_ID1B
value|0x25
end_define

begin_define
define|#
directive|define
name|ADV_REG_IH
value|0x0002
end_define

begin_define
define|#
directive|define
name|ADV_INS_HALTINT
value|0x6281
end_define

begin_define
define|#
directive|define
name|ADV_INS_HALT
value|0x6280
end_define

begin_define
define|#
directive|define
name|ADV_INS_SINT
value|0x6200
end_define

begin_define
define|#
directive|define
name|ADV_INS_RFLAG_WTM
value|0x7380
end_define

begin_define
define|#
directive|define
name|ADV_CONFIG_LSW
value|0x0002
end_define

begin_define
define|#
directive|define
name|ADV_CFG_LSW_ISA_DMA_CHANNEL
value|0x0003
end_define

begin_define
define|#
directive|define
name|ADV_CFG_LSW_HOST_INT_ON
value|0x0020
end_define

begin_define
define|#
directive|define
name|ADV_CFG_LSW_BIOS_ON
value|0x0040
end_define

begin_define
define|#
directive|define
name|ADV_CFG_LSW_VERA_BURST_ON
value|0x0080
end_define

begin_define
define|#
directive|define
name|ADV_CFG_LSW_SCSI_PARITY_ON
value|0x0800
end_define

begin_define
define|#
directive|define
name|ADV_CFG_LSW_SCSIID
value|0x0700
end_define

begin_define
define|#
directive|define
name|ADV_CFG_LSW_SCSIID_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ADV_CONFIG_SCSIID
parameter_list|(
name|cfg
parameter_list|)
value|((cfg>> ADV_CFG_LSW_SCSIID_SHIFT)& ADV_MAX_TID)
end_define

begin_comment
comment|/*  * Chip Revision Number  */
end_comment

begin_define
define|#
directive|define
name|ADV_NONEISA_CHIP_REVISION
value|0x0003
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_MIN_VER_VL
value|0x01
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_MAX_VER_VL
value|0x07
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_MIN_VER_PCI
value|0x09
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_MAX_VER_PCI
value|0x0F
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_VER_PCI_BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_VER_PCI_ULTRA_3150
value|(ADV_CHIP_VER_PCI_BIT | 0x02)
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_VER_PCI_ULTRA_3050
value|(ADV_CHIP_VER_PCI_BIT | 0x03)
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_MIN_VER_ISA
value|0x11
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_MIN_VER_ISA_PNP
value|0x21
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_MAX_VER_ISA
value|0x27
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_VER_ISA_BIT
value|0x30
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_VER_ISAPNP_BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_VER_ASYN_BUG
value|0x21
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_MIN_VER_EISA
value|0x41
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_MAX_VER_EISA
value|0x47
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_VER_EISA_BIT
value|0x40
end_define

begin_define
define|#
directive|define
name|ADV_CONFIG_MSW
value|0x0004
end_define

begin_define
define|#
directive|define
name|ADV_CFG_MSW_SCSI_TARGET_ON
value|0x0080
end_define

begin_define
define|#
directive|define
name|ADV_CFG_MSW_LRAM_8BITS_ON
value|0x0800
end_define

begin_define
define|#
directive|define
name|ADV_CFG_MSW_CLR_MASK
value|0x30C0
end_define

begin_define
define|#
directive|define
name|ADV_EEPROM_DATA
value|0x0006
end_define

begin_define
define|#
directive|define
name|ADV_EEPROM_CMD
value|0x0007
end_define

begin_define
define|#
directive|define
name|ADV_EEPROM_CMD_READ
value|0x80
end_define

begin_define
define|#
directive|define
name|ADV_EEPROM_CMD_WRITE
value|0x40
end_define

begin_define
define|#
directive|define
name|ADV_EEPROM_CMD_WRITE_ENABLE
value|0x30
end_define

begin_define
define|#
directive|define
name|ADV_EEPROM_CMD_WRITE_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|ADV_DMA_SPEED
value|0x0007
end_define

begin_define
define|#
directive|define
name|ADV_DEF_ISA_DMA_SPEED
value|4
end_define

begin_define
define|#
directive|define
name|ADV_REG_FLAG
value|0x0007
end_define

begin_define
define|#
directive|define
name|ADV_LRAM_DATA
value|0x0008
end_define

begin_define
define|#
directive|define
name|ADV_LRAM_ADDR
value|0x000A
end_define

begin_define
define|#
directive|define
name|ADV_SYN_OFFSET
value|0x000B
end_define

begin_define
define|#
directive|define
name|ADV_REG_PROG_COUNTER
value|0x000C
end_define

begin_define
define|#
directive|define
name|ADV_MCODE_START_ADDR
value|0x0080
end_define

begin_define
define|#
directive|define
name|ADV_REG_IFC
value|0x000D
end_define

begin_define
define|#
directive|define
name|ADV_IFC_REG_LOCK
value|0x00
end_define

begin_define
define|#
directive|define
name|ADV_IFC_REG_UNLOCK
value|0x09
end_define

begin_define
define|#
directive|define
name|ADV_IFC_WR_EN_FILTER
value|0x10
end_define

begin_define
define|#
directive|define
name|ADV_IFC_RD_NO_EEPROM
value|0x10
end_define

begin_define
define|#
directive|define
name|ADV_IFC_SLEW_RATE
value|0x20
end_define

begin_define
define|#
directive|define
name|ADV_IFC_ACT_NEG
value|0x40
end_define

begin_define
define|#
directive|define
name|ADV_IFC_INP_FILTER
value|0x80
end_define

begin_define
define|#
directive|define
name|ADV_IFC_INIT_DEFAULT
value|(ADV_IFC_ACT_NEG | ADV_IFC_REG_UNLOCK)
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_STATUS
value|0x000E
end_define

begin_define
define|#
directive|define
name|ADV_CSW_TEST1
value|0x8000
end_define

begin_define
define|#
directive|define
name|ADV_CSW_AUTO_CONFIG
value|0x4000
end_define

begin_define
define|#
directive|define
name|ADV_CSW_RESERVED1
value|0x2000
end_define

begin_define
define|#
directive|define
name|ADV_CSW_IRQ_WRITTEN
value|0x1000
end_define

begin_define
define|#
directive|define
name|ADV_CSW_33MHZ_SELECTED
value|0x0800
end_define

begin_define
define|#
directive|define
name|ADV_CSW_TEST2
value|0x0400
end_define

begin_define
define|#
directive|define
name|ADV_CSW_TEST3
value|0x0200
end_define

begin_define
define|#
directive|define
name|ADV_CSW_RESERVED2
value|0x0100
end_define

begin_define
define|#
directive|define
name|ADV_CSW_DMA_DONE
value|0x0080
end_define

begin_define
define|#
directive|define
name|ADV_CSW_FIFO_RDY
value|0x0040
end_define

begin_define
define|#
directive|define
name|ADV_CSW_EEP_READ_DONE
value|0x0020
end_define

begin_define
define|#
directive|define
name|ADV_CSW_HALTED
value|0x0010
end_define

begin_define
define|#
directive|define
name|ADV_CSW_SCSI_RESET_ACTIVE
value|0x0008
end_define

begin_define
define|#
directive|define
name|ADV_CSW_PARITY_ERR
value|0x0004
end_define

begin_define
define|#
directive|define
name|ADV_CSW_SCSI_RESET_LATCH
value|0x0002
end_define

begin_define
define|#
directive|define
name|ADV_CSW_INT_PENDING
value|0x0001
end_define

begin_comment
comment|/*  * XXX I don't understand the relevence of the naming  * convention change here.  What does CIW stand for?  * Perhaps this is to differentiate read and write  * values?  */
end_comment

begin_define
define|#
directive|define
name|ADV_CIW_INT_ACK
value|0x0100
end_define

begin_define
define|#
directive|define
name|ADV_CIW_TEST1
value|0x0200
end_define

begin_define
define|#
directive|define
name|ADV_CIW_TEST2
value|0x0400
end_define

begin_define
define|#
directive|define
name|ADV_CIW_SEL_33MHZ
value|0x0800
end_define

begin_define
define|#
directive|define
name|ADV_CIW_IRQ_ACT
value|0x1000
end_define

begin_define
define|#
directive|define
name|ADV_CIW_CLR_SCSI_RESET_INT
value|0x1000
end_define

begin_define
define|#
directive|define
name|ADV_CHIP_CTRL
value|0x000F
end_define

begin_define
define|#
directive|define
name|ADV_CC_CHIP_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|ADV_CC_SCSI_RESET
value|0x40
end_define

begin_define
define|#
directive|define
name|ADV_CC_HALT
value|0x20
end_define

begin_define
define|#
directive|define
name|ADV_CC_SINGLE_STEP
value|0x10
end_define

begin_define
define|#
directive|define
name|ADV_CC_DMA_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|ADV_CC_TEST
value|0x04
end_define

begin_define
define|#
directive|define
name|ADV_CC_BANK_ONE
value|0x02
end_define

begin_define
define|#
directive|define
name|ADV_CC_DIAG
value|0x01
end_define

begin_define
define|#
directive|define
name|ADV_HALTCODE_W
value|0x0040
end_define

begin_define
define|#
directive|define
name|ADV_STOP_CODE_B
value|0x0034
end_define

begin_define
define|#
directive|define
name|ADV_STOP_REQ_RISC_STOP
value|0x01
end_define

begin_define
define|#
directive|define
name|ADV_STOP_ACK_RISC_STOP
value|0x03
end_define

begin_define
define|#
directive|define
name|ADV_STOP_CLEAN_UP_BUSY_Q
value|0x10
end_define

begin_define
define|#
directive|define
name|ADV_STOP_CLEAN_UP_DISC_Q
value|0x20
end_define

begin_define
define|#
directive|define
name|ADV_STOP_HOST_REQ_RISC_HALT
value|0x40
end_define

begin_comment
comment|/*  * EEPROM routine constants  * XXX What about wide controllers?  * Surely they have space for 8 more targets.  */
end_comment

begin_define
define|#
directive|define
name|ADV_EEPROM_CFG_BEG_VL
value|2
end_define

begin_define
define|#
directive|define
name|ADV_EEPROM_MAX_ADDR_VL
value|15
end_define

begin_define
define|#
directive|define
name|ADV_EEPROM_CFG_BEG
value|32
end_define

begin_define
define|#
directive|define
name|ADV_EEPROM_MAX_ADDR
value|45
end_define

begin_define
define|#
directive|define
name|ADV_EEPROM_MAX_RETRY
value|20
end_define

begin_struct
struct|struct
name|adv_eeprom_config
block|{
name|u_int16_t
name|cfg_lsw
decl_stmt|;
name|u_int16_t
name|cfg_msw
decl_stmt|;
name|u_int8_t
name|init_sdtr
decl_stmt|;
name|u_int8_t
name|disc_enable
decl_stmt|;
name|u_int8_t
name|use_cmd_qng
decl_stmt|;
name|u_int8_t
name|start_motor
decl_stmt|;
name|u_int8_t
name|max_total_qng
decl_stmt|;
name|u_int8_t
name|max_tag_qng
decl_stmt|;
name|u_int8_t
name|bios_scan
decl_stmt|;
name|u_int8_t
name|power_up_wait
decl_stmt|;
name|u_int8_t
name|no_scam
decl_stmt|;
name|u_int8_t
name|scsi_id_dma_speed
decl_stmt|;
define|#
directive|define
name|EEPROM_SCSI_ID_MASK
value|0x0F
define|#
directive|define
name|EEPROM_DMA_SPEED_MASK
value|0xF0
define|#
directive|define
name|EEPROM_DMA_SPEED
parameter_list|(
name|ep
parameter_list|)
define|\
value|(((ep).scsi_id_dma_speed& EEPROM_DMA_SPEED_MASK)>> 4)
define|#
directive|define
name|EEPROM_SET_DMA_SPEED
parameter_list|(
name|ep
parameter_list|,
name|speed
parameter_list|)
define|\
value|(ep).scsi_id_dma_speed&= ~EEPROM_DMA_SPEED_MASK;	\ 		(ep).scsi_id_dma_speed |=				\ 		    (((speed)<< 4)& EEPROM_DMA_SPEED_MASK)
define|#
directive|define
name|EEPROM_SCSIID
parameter_list|(
name|ep
parameter_list|)
value|((ep).scsi_id_dma_speed& EEPROM_SCSI_ID_MASK)
define|#
directive|define
name|EEPROM_SET_SCSIID
parameter_list|(
name|ep
parameter_list|,
name|id
parameter_list|)
define|\
value|(ep).scsi_id_dma_speed&= ~EEPROM_SCSI_ID_MASK; \ 		(ep).scsi_id_dma_speed |= ((id)& EEPROM_SCSI_ID_MASK)
name|u_int8_t
name|sdtr_data
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|adapter_info
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|cntl
decl_stmt|;
name|u_int16_t
name|chksum
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Bank 1 */
end_comment

begin_define
define|#
directive|define
name|ADV_SEQ_ACCUM
value|0x0000
end_define

begin_define
define|#
directive|define
name|ADV_QUEUE_ELEMENT_INDEX
value|0x0001
end_define

begin_define
define|#
directive|define
name|ADV_SEQ_INSTRUCTION_HOLD
value|0x0002
end_define

begin_define
define|#
directive|define
name|ADV_QUEUE_ELEMENT_POINTER
value|0x0003
end_define

begin_define
define|#
directive|define
name|ADV_HOST_DATA_FIFO_L
value|0x0004
end_define

begin_define
define|#
directive|define
name|ADV_HOST_SCSIID
value|0x0005
end_define

begin_define
define|#
directive|define
name|ADV_HOST_DATA_FIFO_H
value|0x0006
end_define

begin_define
define|#
directive|define
name|ADV_SCSI_CONTROL
value|0x0009
end_define

begin_define
define|#
directive|define
name|SC_SEL
value|0x80
end_define

begin_define
define|#
directive|define
name|SC_BSY
value|0x40
end_define

begin_define
define|#
directive|define
name|SC_ACK
value|0x20
end_define

begin_define
define|#
directive|define
name|SC_REQ
value|0x10
end_define

begin_define
define|#
directive|define
name|SC_ATN
value|0x08
end_define

begin_define
define|#
directive|define
name|SC_IO
value|0x04
end_define

begin_define
define|#
directive|define
name|SC_CD
value|0x02
end_define

begin_define
define|#
directive|define
name|SC_MSG
value|0x01
end_define

begin_define
define|#
directive|define
name|ADV_SCSIDATL
value|0x000B
end_define

begin_define
define|#
directive|define
name|ADV_DMA_TRANSFER_CNT
value|0x000C
end_define

begin_define
define|#
directive|define
name|ADV_DMA_TRANSFER_CNT1
value|0x000E
end_define

begin_comment
comment|/*  * Instruction data and code segment addresses,  * and transaction address translation (queues).  * All addresses refer to on board LRAM.  */
end_comment

begin_define
define|#
directive|define
name|ADV_DATA_SEC_BEG
value|0x0080
end_define

begin_define
define|#
directive|define
name|ADV_DATA_SEC_END
value|0x0080
end_define

begin_define
define|#
directive|define
name|ADV_CODE_SEC_BEG
value|0x0080
end_define

begin_define
define|#
directive|define
name|ADV_CODE_SEC_END
value|0x0080
end_define

begin_define
define|#
directive|define
name|ADV_QADR_BEG
value|0x4000
end_define

begin_define
define|#
directive|define
name|ADV_QADR_END
value|0x7FFF
end_define

begin_define
define|#
directive|define
name|ADV_QLAST_ADR
value|0x7FC0
end_define

begin_define
define|#
directive|define
name|ADV_QBLK_SIZE
value|0x40
end_define

begin_define
define|#
directive|define
name|ADV_BIOS_DATA_QBEG
value|0xF8
end_define

begin_define
define|#
directive|define
name|ADV_MAX_QNO
value|0xF8
end_define

begin_define
define|#
directive|define
name|ADV_QADR_USED
value|(ADV_MAX_QNO * 64)
end_define

begin_define
define|#
directive|define
name|ADV_QNO_TO_QADDR
parameter_list|(
name|q_no
parameter_list|)
value|((ADV_QADR_BEG) + ((u_int16_t)(q_no)<< 6))
end_define

begin_define
define|#
directive|define
name|ADV_MIN_ACTIVE_QNO
value|0x01
end_define

begin_define
define|#
directive|define
name|ADV_QLINK_END
value|0xFF
end_define

begin_define
define|#
directive|define
name|ADV_MAX_SG_QUEUE
value|5
end_define

begin_define
define|#
directive|define
name|ADV_SG_LIST_PER_Q
value|7
end_define

begin_define
define|#
directive|define
name|ADV_MAX_SG_LIST
value|(1 + ((ADV_SG_LIST_PER_Q) * (ADV_MAX_SG_QUEUE)))
end_define

begin_define
define|#
directive|define
name|ADV_MIN_REMAIN_Q
value|0x02
end_define

begin_define
define|#
directive|define
name|ADV_DEF_MAX_TOTAL_QNG
value|0xF0
end_define

begin_define
define|#
directive|define
name|ADV_MIN_TAG_Q_PER_DVC
value|0x04
end_define

begin_define
define|#
directive|define
name|ADV_DEF_TAG_Q_PER_DVC
value|0x04
end_define

begin_define
define|#
directive|define
name|ADV_MIN_FREE_Q
value|ADV_MIN_REMAIN_Q
end_define

begin_define
define|#
directive|define
name|ADV_MIN_TOTAL_QNG
value|((ADV_MAX_SG_QUEUE)+(ADV_MIN_FREE_Q))
end_define

begin_define
define|#
directive|define
name|ADV_MAX_TOTAL_QNG
value|240
end_define

begin_define
define|#
directive|define
name|ADV_MAX_INRAM_TAG_QNG
value|16
end_define

begin_define
define|#
directive|define
name|ADV_MAX_PCI_INRAM_TOTAL_QNG
value|20
end_define

begin_define
define|#
directive|define
name|ADV_MAX_PCI_ULTRA_INRAM_TOTAL_QNG
value|16
end_define

begin_define
define|#
directive|define
name|ADV_MAX_PCI_ULTRA_INRAM_TAG_QNG
value|8
end_define

begin_define
define|#
directive|define
name|ADV_DEF_IRQ_NO
value|10
end_define

begin_define
define|#
directive|define
name|ADV_MAX_IRQ_NO
value|15
end_define

begin_define
define|#
directive|define
name|ADV_MIN_IRQ_NO
value|10
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_CPY_BEG
value|4
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_SGHD_CPY_BEG
value|2
end_define

begin_comment
comment|/* SCSIQ Microcode representation offsets */
end_comment

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_FWD
value|0
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_BWD
value|1
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_STATUS
value|2
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_QNO
value|3
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_CNTL
value|4
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_SG_QUEUE_CNT
value|5
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_LIST_CNT
value|6
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_CUR_LIST_CNT
value|7
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_D_DATA_ADDR
value|8
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_D_DATA_CNT
value|12
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_SENSE_LEN
value|20
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_DONE_INFO_BEG
value|22
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_D_CINFO_IDX
value|22
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_TARGET_IX
value|26
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_CDB_LEN
value|28
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_TAG_CODE
value|29
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_W_VM_ID
value|30
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_DONE_STATUS
value|32
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_HOST_STATUS
value|33
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_SCSI_STATUS
value|34
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_CDB_BEG
value|36
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_FIRST_SG_QK_QP
value|48
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_SG_WK_QP
value|49
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_B_SG_WK_IX
value|50
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_W_ALT_DC1
value|52
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_DW_REMAIN_XFER_ADDR
value|56
end_define

begin_define
define|#
directive|define
name|ADV_SCSIQ_DW_REMAIN_XFER_CNT
value|60
end_define

begin_comment
comment|/* LRAM Offsets */
end_comment

begin_define
define|#
directive|define
name|ADVV_MSGOUT_BEG
value|0x0000
end_define

begin_define
define|#
directive|define
name|ADVV_MSGOUT_SDTR_PERIOD
value|(ADVV_MSGOUT_BEG+3)
end_define

begin_define
define|#
directive|define
name|ADVV_MSGOUT_SDTR_OFFSET
value|(ADVV_MSGOUT_BEG+4)
end_define

begin_define
define|#
directive|define
name|ADVV_BREAK_SAVED_CODE
value|0x0006
end_define

begin_define
define|#
directive|define
name|ADVV_MSGIN_BEG
value|(ADVV_MSGOUT_BEG+8)
end_define

begin_define
define|#
directive|define
name|ADVV_MSGIN_SDTR_PERIOD
value|(ADVV_MSGIN_BEG+3)
end_define

begin_define
define|#
directive|define
name|ADVV_MSGIN_SDTR_OFFSET
value|(ADVV_MSGIN_BEG+4)
end_define

begin_define
define|#
directive|define
name|ADVV_SDTR_DATA_BEG
value|(ADVV_MSGIN_BEG+8)
end_define

begin_define
define|#
directive|define
name|ADVV_SDTR_DONE_BEG
value|(ADVV_SDTR_DATA_BEG+8)
end_define

begin_define
define|#
directive|define
name|ADVV_MAX_DVC_QNG_BEG
value|0x0020
end_define

begin_define
define|#
directive|define
name|ADVV_BREAK_ADDR
value|0x0028
end_define

begin_define
define|#
directive|define
name|ADVV_BREAK_NOTIFY_COUNT
value|0x002A
end_define

begin_define
define|#
directive|define
name|ADVV_BREAK_CONTROL
value|0x002C
end_define

begin_define
define|#
directive|define
name|ADVV_BREAK_HIT_COUNT
value|0x002E
end_define

begin_define
define|#
directive|define
name|ADVV_ASCDVC_ERR_CODE_W
value|0x0030
end_define

begin_define
define|#
directive|define
name|ADVV_MCODE_CHKSUM_W
value|0x0032
end_define

begin_define
define|#
directive|define
name|ADVV_MCODE_SIZE_W
value|0x0034
end_define

begin_define
define|#
directive|define
name|ADVV_STOP_CODE_B
value|0x0036
end_define

begin_define
define|#
directive|define
name|ADVV_DVC_ERR_CODE_B
value|0x0037
end_define

begin_define
define|#
directive|define
name|ADVV_OVERRUN_PADDR_D
value|0x0038
end_define

begin_define
define|#
directive|define
name|ADVV_OVERRUN_BSIZE_D
value|0x003C
end_define

begin_define
define|#
directive|define
name|ADVV_HALTCODE_W
value|0x0040
end_define

begin_define
define|#
directive|define
name|ADV_HALT_EXTMSG_IN
value|0x8000
end_define

begin_define
define|#
directive|define
name|ADV_HALT_CHK_CONDITION
value|0x8100
end_define

begin_define
define|#
directive|define
name|ADV_HALT_SS_QUEUE_FULL
value|0x8200
end_define

begin_define
define|#
directive|define
name|ADV_HALT_DISABLE_ASYN_USE_SYN_FIX
value|0x8300
end_define

begin_define
define|#
directive|define
name|ADV_HALT_ENABLE_ASYN_USE_SYN_FIX
value|0x8400
end_define

begin_define
define|#
directive|define
name|ADV_HALT_SDTR_REJECTED
value|0x4000
end_define

begin_define
define|#
directive|define
name|ADV_HALT_HOST_COPY_SG_LIST_TO_RISC
value|0x2000
end_define

begin_define
define|#
directive|define
name|ADVV_CHKSUM_W
value|0x0042
end_define

begin_define
define|#
directive|define
name|ADVV_MC_DATE_W
value|0x0044
end_define

begin_define
define|#
directive|define
name|ADVV_MC_VER_W
value|0x0046
end_define

begin_define
define|#
directive|define
name|ADVV_NEXTRDY_B
value|0x0048
end_define

begin_define
define|#
directive|define
name|ADVV_DONENEXT_B
value|0x0049
end_define

begin_define
define|#
directive|define
name|ADVV_USE_TAGGED_QNG_B
value|0x004A
end_define

begin_define
define|#
directive|define
name|ADVV_SCSIBUSY_B
value|0x004B
end_define

begin_define
define|#
directive|define
name|ADVV_Q_DONE_IN_PROGRESS_B
value|0x004C
end_define

begin_define
define|#
directive|define
name|ADVV_CURCDB_B
value|0x004D
end_define

begin_define
define|#
directive|define
name|ADVV_RCLUN_B
value|0x004E
end_define

begin_define
define|#
directive|define
name|ADVV_BUSY_QHEAD_B
value|0x004F
end_define

begin_define
define|#
directive|define
name|ADVV_DISC1_QHEAD_B
value|0x0050
end_define

begin_define
define|#
directive|define
name|ADVV_DISC_ENABLE_B
value|0x0052
end_define

begin_define
define|#
directive|define
name|ADVV_CAN_TAGGED_QNG_B
value|0x0053
end_define

begin_define
define|#
directive|define
name|ADVV_HOSTSCSI_ID_B
value|0x0055
end_define

begin_define
define|#
directive|define
name|ADVV_MCODE_CNTL_B
value|0x0056
end_define

begin_define
define|#
directive|define
name|ADVV_NULL_TARGET_B
value|0x0057
end_define

begin_define
define|#
directive|define
name|ADVV_FREE_Q_HEAD_W
value|0x0058
end_define

begin_define
define|#
directive|define
name|ADVV_DONE_Q_TAIL_W
value|0x005A
end_define

begin_define
define|#
directive|define
name|ADVV_FREE_Q_HEAD_B
value|(ADVV_FREE_Q_HEAD_W+1)
end_define

begin_define
define|#
directive|define
name|ADVV_DONE_Q_TAIL_B
value|(ADVV_DONE_Q_TAIL_W+1)
end_define

begin_define
define|#
directive|define
name|ADVV_HOST_FLAG_B
value|0x005D
end_define

begin_define
define|#
directive|define
name|ADV_HOST_FLAG_IN_ISR
value|0x01
end_define

begin_define
define|#
directive|define
name|ADV_HOST_FLAG_ACK_INT
value|0x02
end_define

begin_define
define|#
directive|define
name|ADVV_TOTAL_READY_Q_B
value|0x0064
end_define

begin_define
define|#
directive|define
name|ADVV_VER_SERIAL_B
value|0x0065
end_define

begin_define
define|#
directive|define
name|ADVV_HALTCODE_SAVED_W
value|0x0066
end_define

begin_define
define|#
directive|define
name|ADVV_WTM_FLAG_B
value|0x0068
end_define

begin_define
define|#
directive|define
name|ADVV_RISC_FLAG_B
value|0x006A
end_define

begin_define
define|#
directive|define
name|ADV_RISC_FLAG_GEN_INT
value|0x01
end_define

begin_define
define|#
directive|define
name|ADV_RISC_FLAG_REQ_SG_LIST
value|0x02
end_define

begin_define
define|#
directive|define
name|ADVV_REQ_SG_LIST_QP
value|0x006B
end_define

begin_define
define|#
directive|define
name|ADV_TRANS_CUR
value|0x01
end_define

begin_comment
comment|/* Modify current neogtiation status */
end_comment

begin_define
define|#
directive|define
name|ADV_TRANS_ACTIVE
value|0x03
end_define

begin_comment
comment|/* Assume this is the active target */
end_comment

begin_define
define|#
directive|define
name|ADV_TRANS_GOAL
value|0x04
end_define

begin_comment
comment|/* Modify negotiation goal */
end_comment

begin_define
define|#
directive|define
name|ADV_TRANS_USER
value|0x08
end_define

begin_comment
comment|/* Modify user negotiation settings */
end_comment

begin_struct
struct|struct
name|adv_transinfo
block|{
name|u_int8_t
name|period
decl_stmt|;
name|u_int8_t
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adv_target_transinfo
block|{
name|struct
name|adv_transinfo
name|current
decl_stmt|;
name|struct
name|adv_transinfo
name|goal
decl_stmt|;
name|struct
name|adv_transinfo
name|user
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adv_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|bus_space_tag_t
name|tag
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ccb_hdr
argument_list|)
name|pending_ccbs
expr_stmt|;
name|struct
name|adv_ccb_info
modifier|*
name|ccb_infos
decl_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|adv_ccb_info
argument_list|)
name|free_ccb_infos
expr_stmt|;
name|bus_dma_tag_t
name|parent_dmat
decl_stmt|;
name|bus_dma_tag_t
name|buffer_dmat
decl_stmt|;
name|bus_dma_tag_t
name|sense_dmat
decl_stmt|;
name|bus_dmamap_t
name|sense_dmamap
decl_stmt|;
name|struct
name|scsi_sense_data
modifier|*
name|sense_buffers
decl_stmt|;
name|bus_addr_t
name|sense_physbase
decl_stmt|;
name|bus_addr_t
name|overrun_physbase
decl_stmt|;
name|adv_btype
name|type
decl_stmt|;
name|struct
name|adv_target_transinfo
name|tinfo
index|[
literal|8
index|]
decl_stmt|;
name|target_bit_vector
name|fix_asyn_xfer
decl_stmt|;
name|target_bit_vector
name|fix_asyn_xfer_always
decl_stmt|;
name|target_bit_vector
name|disc_enable
decl_stmt|;
name|target_bit_vector
name|user_disc_enable
decl_stmt|;
name|target_bit_vector
name|cmd_qng_enabled
decl_stmt|;
name|target_bit_vector
name|user_cmd_qng_enabled
decl_stmt|;
name|u_int16_t
name|control
decl_stmt|;
define|#
directive|define
name|ADV_CNTL_INITIATOR
value|0x0001
define|#
directive|define
name|ADV_CNTL_BIOS_GT_1GB
value|0x0002
define|#
directive|define
name|ADV_CNTL_BIOS_GT_2_DISK
value|0x0004
define|#
directive|define
name|ADV_CNTL_BIOS_REMOVABLE
value|0x0008
define|#
directive|define
name|ADV_CNTL_NO_SCAM
value|0x0010
define|#
directive|define
name|ADV_CNTL_INT_MULTI_Q
value|0x0080
define|#
directive|define
name|ADV_CNTL_NO_LUN_SUPPORT
value|0x0040
define|#
directive|define
name|ADV_CNTL_NO_VERIFY_COPY
value|0x0100
define|#
directive|define
name|ADV_CNTL_RESET_SCSI
value|0x0200
define|#
directive|define
name|ADV_CNTL_INIT_INQUIRY
value|0x0400
define|#
directive|define
name|ADV_CNTL_INIT_VERBOSE
value|0x0800
define|#
directive|define
name|ADV_CNTL_SCSI_PARITY
value|0x1000
define|#
directive|define
name|ADV_CNTL_BURST_MODE
value|0x2000
define|#
directive|define
name|ADV_CNTL_SDTR_ENABLE_ULTRA
value|0x4000
name|u_int16_t
name|bug_fix_control
decl_stmt|;
define|#
directive|define
name|ADV_BUG_FIX_IF_NOT_DWB
value|0x0001
define|#
directive|define
name|ADV_BUG_FIX_ASYN_USE_SYN
value|0x0002
name|adv_state
name|state
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|int
name|init_level
decl_stmt|;
name|u_int32_t
name|max_dma_addr
decl_stmt|;
name|u_int32_t
name|max_dma_count
decl_stmt|;
name|u_int8_t
name|isa_dma_speed
decl_stmt|;
name|u_int8_t
name|isa_dma_channel
decl_stmt|;
name|u_int8_t
name|scsi_id
decl_stmt|;
name|u_int8_t
name|chip_version
decl_stmt|;
name|u_int8_t
name|max_tags_per_target
decl_stmt|;
name|u_int8_t
name|max_openings
decl_stmt|;
name|u_int8_t
name|cur_active
decl_stmt|;
name|u_int8_t
name|openings_needed
decl_stmt|;
name|u_int8_t
name|ccb_infos_allocated
decl_stmt|;
name|u_int8_t
modifier|*
name|sdtr_period_tbl
decl_stmt|;
name|u_int8_t
name|sdtr_period_tbl_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structures for talking to the RISC engine.  */
end_comment

begin_struct
struct|struct
name|adv_scsiq_1
block|{
name|u_int8_t
name|status
decl_stmt|;
define|#
directive|define
name|QS_FREE
value|0x00
define|#
directive|define
name|QS_READY
value|0x01
define|#
directive|define
name|QS_DISC1
value|0x02
define|#
directive|define
name|QS_DISC2
value|0x04
define|#
directive|define
name|QS_BUSY
value|0x08
define|#
directive|define
name|QS_ABORTED
value|0x40
define|#
directive|define
name|QS_DONE
value|0x80
name|u_int8_t
name|q_no
decl_stmt|;
comment|/* 						 * Queue ID of the first queue 						 * used in this transaction. 						 */
name|u_int8_t
name|cntl
decl_stmt|;
define|#
directive|define
name|QC_NO_CALLBACK
value|0x01
define|#
directive|define
name|QC_SG_SWAP_QUEUE
value|0x02
define|#
directive|define
name|QC_SG_HEAD
value|0x04
define|#
directive|define
name|QC_DATA_IN
value|0x08
define|#
directive|define
name|QC_DATA_OUT
value|0x10
define|#
directive|define
name|QC_URGENT
value|0x20
define|#
directive|define
name|QC_MSG_OUT
value|0x40
define|#
directive|define
name|QC_REQ_SENSE
value|0x80
name|u_int8_t
name|sg_queue_cnt
decl_stmt|;
comment|/* Number of SG entries */
name|u_int8_t
name|target_id
decl_stmt|;
comment|/* target id as a bit vector */
name|u_int8_t
name|target_lun
decl_stmt|;
comment|/* LUN - taken from our xs */
name|u_int32_t
name|data_addr
decl_stmt|;
comment|/* 						 * physical addres of first 						 * (possibly only) segment 						 * to transfer. 						 */
name|u_int32_t
name|data_cnt
decl_stmt|;
comment|/* 						 * byte count of the first 						 * (possibly only) segment 						 * to transfer. 						 */
name|u_int32_t
name|sense_addr
decl_stmt|;
comment|/* 						 * physical address of the sense 						 * buffer. 						 */
name|u_int8_t
name|sense_len
decl_stmt|;
comment|/* length of sense buffer */
name|u_int8_t
name|extra_bytes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adv_scsiq_2
block|{
name|u_int32_t
name|ccb_index
decl_stmt|;
comment|/* Index to our CCB Info */
name|u_int8_t
name|target_ix
decl_stmt|;
comment|/* Combined TID and LUN */
name|u_int8_t
name|flag
decl_stmt|;
name|u_int8_t
name|cdb_len
decl_stmt|;
comment|/* 						 * Number of bytes in the SCSI 						 * command to execute. 						 */
name|u_int8_t
name|tag_code
decl_stmt|;
comment|/* 						 * Tag type for this transaction 						 * (SIMPLE, ORDERED, HEAD ) 						 */
define|#
directive|define
name|ADV_TAG_FLAG_EXTRA_BYTES
value|0x10
define|#
directive|define
name|ADV_TAG_FLAG_DISABLE_DISCONNECT
value|0x04
define|#
directive|define
name|ADV_TAG_FLAG_DISABLE_ASYN_USE_SYN_FIX
value|0x08
define|#
directive|define
name|ADV_TAG_FLAG_DISABLE_CHK_COND_INT_HOST
value|0x40
name|u_int16_t
name|vm_id
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adv_scsiq_3
block|{
name|u_int8_t
name|done_stat
decl_stmt|;
define|#
directive|define
name|QD_IN_PROGRESS
value|0x00
define|#
directive|define
name|QD_NO_ERROR
value|0x01
define|#
directive|define
name|QD_ABORTED_BY_HOST
value|0x02
define|#
directive|define
name|QD_WITH_ERROR
value|0x04
define|#
directive|define
name|QD_INVALID_REQUEST
value|0x80
define|#
directive|define
name|QD_INVALID_HOST_NUM
value|0x81
define|#
directive|define
name|QD_INVALID_DEVICE
value|0x82
define|#
directive|define
name|QD_ERR_INTERNAL
value|0xFF
name|u_int8_t
name|host_stat
decl_stmt|;
define|#
directive|define
name|QHSTA_NO_ERROR
value|0x00
define|#
directive|define
name|QHSTA_M_SEL_TIMEOUT
value|0x11
define|#
directive|define
name|QHSTA_M_DATA_OVER_RUN
value|0x12
define|#
directive|define
name|QHSTA_M_DATA_UNDER_RUN
value|0x12
define|#
directive|define
name|QHSTA_M_UNEXPECTED_BUS_FREE
value|0x13
define|#
directive|define
name|QHSTA_M_BAD_BUS_PHASE_SEQ
value|0x14
define|#
directive|define
name|QHSTA_D_QDONE_SG_LIST_CORRUPTED
value|0x21
define|#
directive|define
name|QHSTA_D_ASC_DVC_ERROR_CODE_SET
value|0x22
define|#
directive|define
name|QHSTA_D_HOST_ABORT_FAILED
value|0x23
define|#
directive|define
name|QHSTA_D_EXE_SCSI_Q_FAILED
value|0x24
define|#
directive|define
name|QHSTA_D_EXE_SCSI_Q_BUSY_TIMEOUT
value|0x25
define|#
directive|define
name|QHSTA_D_ASPI_NO_BUF_POOL
value|0x26
define|#
directive|define
name|QHSTA_M_WTM_TIMEOUT
value|0x41
define|#
directive|define
name|QHSTA_M_BAD_CMPL_STATUS_IN
value|0x42
define|#
directive|define
name|QHSTA_M_NO_AUTO_REQ_SENSE
value|0x43
define|#
directive|define
name|QHSTA_M_AUTO_REQ_SENSE_FAIL
value|0x44
define|#
directive|define
name|QHSTA_M_TARGET_STATUS_BUSY
value|0x45
define|#
directive|define
name|QHSTA_M_BAD_TAG_CODE
value|0x46
define|#
directive|define
name|QHSTA_M_BAD_QUEUE_FULL_OR_BUSY
value|0x47
define|#
directive|define
name|QHSTA_M_HUNG_REQ_SCSI_BUS_RESET
value|0x48
define|#
directive|define
name|QHSTA_D_LRAM_CMP_ERROR
value|0x81
define|#
directive|define
name|QHSTA_M_MICRO_CODE_ERROR_HALT
value|0xA1
name|u_int8_t
name|scsi_stat
decl_stmt|;
name|u_int8_t
name|scsi_msg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adv_scsiq_4
block|{
name|u_int8_t
name|cdb
index|[
name|ADV_MAX_CDB_LEN
index|]
decl_stmt|;
name|u_int8_t
name|y_first_sg_list_qp
decl_stmt|;
name|u_int8_t
name|y_working_sg_qp
decl_stmt|;
name|u_int8_t
name|y_working_sg_ix
decl_stmt|;
name|u_int8_t
name|y_res
decl_stmt|;
name|u_int16_t
name|x_req_count
decl_stmt|;
name|u_int16_t
name|x_reconnect_rtn
decl_stmt|;
name|u_int32_t
name|x_saved_data_addr
decl_stmt|;
name|u_int32_t
name|x_saved_data_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adv_q_done_info
block|{
name|struct
name|adv_scsiq_2
name|d2
decl_stmt|;
name|struct
name|adv_scsiq_3
name|d3
decl_stmt|;
name|u_int8_t
name|q_status
decl_stmt|;
name|u_int8_t
name|q_no
decl_stmt|;
name|u_int8_t
name|cntl
decl_stmt|;
name|u_int8_t
name|sense_len
decl_stmt|;
name|u_int8_t
name|extra_bytes
decl_stmt|;
name|u_int8_t
name|res
decl_stmt|;
name|u_int32_t
name|remain_bytes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adv_sg_entry
block|{
name|u_int32_t
name|addr
decl_stmt|;
name|u_int32_t
name|bytes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adv_sg_head
block|{
name|u_int16_t
name|entry_cnt
decl_stmt|;
comment|/* 						 * Number of SG entries 						 * in this list 						 */
name|u_int16_t
name|queue_cnt
decl_stmt|;
comment|/* 						 * Number of queues required 						 * to store entry_cnt 						 * SG entries. 						 */
name|u_int16_t
name|entry_to_copy
decl_stmt|;
comment|/* 						 * Number of SG entries to 						 * copy to the board. 						 */
name|u_int16_t
name|res
decl_stmt|;
name|struct
name|adv_sg_entry
modifier|*
name|sg_list
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|QCX_SORT
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|QCX_COALEASE
value|(0x0002)
end_define

begin_struct
struct|struct
name|adv_scsi_q
block|{
name|struct
name|adv_scsiq_1
name|q1
decl_stmt|;
name|struct
name|adv_scsiq_2
name|q2
decl_stmt|;
name|u_int8_t
modifier|*
name|cdbptr
decl_stmt|;
comment|/* 						 * Pointer to the SCSI command 						 * to execute. 						 */
name|struct
name|adv_sg_head
modifier|*
name|sg_head
decl_stmt|;
comment|/* 						 * Pointer to possible SG list 						 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adv_scsi_req_q
block|{
name|struct
name|adv_scsiq_1
name|r1
decl_stmt|;
name|struct
name|adv_scsiq_2
name|r2
decl_stmt|;
name|u_int8_t
modifier|*
name|cdbptr
decl_stmt|;
name|struct
name|adv_sg_head
modifier|*
name|sg_head
decl_stmt|;
name|u_int8_t
modifier|*
name|sense_ptr
decl_stmt|;
name|struct
name|adv_scsiq_3
name|r3
decl_stmt|;
name|u_int8_t
name|cdb
index|[
name|ADV_MAX_CDB_LEN
index|]
decl_stmt|;
name|u_int8_t
name|sense
index|[
name|ADV_MIN_SENSE_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adv_risc_q
block|{
name|u_int8_t
name|fwd
decl_stmt|;
name|u_int8_t
name|bwd
decl_stmt|;
name|struct
name|adv_scsiq_1
name|i1
decl_stmt|;
name|struct
name|adv_scsiq_2
name|i2
decl_stmt|;
name|struct
name|adv_scsiq_3
name|i3
decl_stmt|;
name|struct
name|adv_scsiq_4
name|i4
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adv_sg_list_q
block|{
name|u_int8_t
name|seq_no
decl_stmt|;
name|u_int8_t
name|q_no
decl_stmt|;
name|u_int8_t
name|cntl
decl_stmt|;
define|#
directive|define
name|QCSG_SG_XFER_LIST
value|0x02
define|#
directive|define
name|QCSG_SG_XFER_MORE
value|0x04
define|#
directive|define
name|QCSG_SG_XFER_END
value|0x08
name|u_int8_t
name|sg_head_qp
decl_stmt|;
name|u_int8_t
name|sg_list_cnt
decl_stmt|;
name|u_int8_t
name|sg_cur_list_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ADV_SGQ_B_SG_CNTL
value|4
end_define

begin_define
define|#
directive|define
name|ADV_SGQ_B_SG_HEAD_QP
value|5
end_define

begin_define
define|#
directive|define
name|ADV_SGQ_B_SG_LIST_CNT
value|6
end_define

begin_define
define|#
directive|define
name|ADV_SGQ_B_SG_CUR_LIST_CNT
value|7
end_define

begin_define
define|#
directive|define
name|ADV_SGQ_LIST_BEG
value|8
end_define

begin_struct
struct|struct
name|asc_risc_sg_list_q
block|{
name|u_int8_t
name|fwd
decl_stmt|;
name|u_int8_t
name|bwd
decl_stmt|;
name|struct
name|adv_sg_list_q
name|sg
decl_stmt|;
name|struct
name|adv_sg_entry
name|sg_list
index|[
name|ADV_SG_LIST_PER_Q
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Chip Register functions */
end_comment

begin_function_decl
name|void
name|adv_set_bank
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|u_int8_t
name|bank
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* LRAM routines */
end_comment

begin_function_decl
name|u_int8_t
name|adv_read_lram_8
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|u_int16_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adv_write_lram_8
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|u_int16_t
name|addr
parameter_list|,
name|u_int8_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|adv_read_lram_16
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|u_int16_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adv_write_lram_16
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|u_int16_t
name|addr
parameter_list|,
name|u_int16_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Intialization */
end_comment

begin_function_decl
name|int
name|adv_find_signature
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
name|adv_lib_init
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|adv_get_eeprom_config
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|struct
name|adv_eeprom_config
modifier|*
name|eeprom_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adv_set_eeprom_config
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|struct
name|adv_eeprom_config
modifier|*
name|eeprom_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adv_reset_chip
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|int
name|reset_bus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adv_test_external_lram
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adv_init_lram_and_mcode
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int8_t
name|adv_get_chip_irq
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int8_t
name|adv_set_chip_irq
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|u_int8_t
name|irq_no
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adv_set_chip_scsiid
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|int
name|new_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Queue handling and execution */
end_comment

begin_function_decl
name|int
name|adv_execute_scsi_queue
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|struct
name|adv_scsi_q
modifier|*
name|scsiq
parameter_list|,
name|u_int32_t
name|datalen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int8_t
name|adv_copy_lram_doneq
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|u_int16_t
name|q_addr
parameter_list|,
name|struct
name|adv_q_done_info
modifier|*
name|scsiq
parameter_list|,
name|u_int32_t
name|max_dma_count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Chip Control */
end_comment

begin_function_decl
name|int
name|adv_start_chip
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adv_start_execution
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adv_stop_execution
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adv_stop_chip
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adv_is_chip_halted
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Interrupt processing */
end_comment

begin_function_decl
name|void
name|adv_ack_interrupt
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adv_isr_chip_halted
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* SDTR Conversion */
end_comment

begin_function_decl
name|void
name|adv_set_syncrate
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|struct
name|cam_path
modifier|*
name|path
parameter_list|,
name|u_int
name|target_id
parameter_list|,
name|u_int
name|period
parameter_list|,
name|u_int
name|offset
parameter_list|,
name|u_int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adv_sdtr_to_period_offset
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|u_int8_t
name|sync_data
parameter_list|,
name|u_int8_t
modifier|*
name|period
parameter_list|,
name|u_int8_t
modifier|*
name|offset
parameter_list|,
name|int
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int8_t
name|adv_period_offset_to_sdtr
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|u_int
modifier|*
name|period
parameter_list|,
name|u_int
modifier|*
name|offset
parameter_list|,
name|int
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Error recovery */
end_comment

begin_union_decl
union_decl|union
name|ccb
union_decl|;
end_union_decl

begin_function_decl
name|int
name|adv_abort_ccb
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|int
name|target
parameter_list|,
name|int
name|lun
parameter_list|,
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|u_int32_t
name|status
parameter_list|,
name|int
name|queued_only
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adv_reset_bus
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|int
name|initiate_reset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Async event callback */
end_comment

begin_function_decl
name|void
name|advasync
parameter_list|(
name|void
modifier|*
name|callback_arg
parameter_list|,
name|u_int32_t
name|code
parameter_list|,
name|struct
name|cam_path
modifier|*
name|path
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ADV_INB
parameter_list|(
name|adv
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_1((adv)->tag, (adv)->bsh, offset)
end_define

begin_define
define|#
directive|define
name|ADV_INW
parameter_list|(
name|adv
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_2((adv)->tag, (adv)->bsh, offset)
end_define

begin_define
define|#
directive|define
name|ADV_INSB
parameter_list|(
name|adv
parameter_list|,
name|offset
parameter_list|,
name|valp
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_1((adv)->tag, (adv)->bsh, offset, valp, count)
end_define

begin_comment
comment|/* These controllers seem to have problems with PIO on some fast processors */
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|ADV_INSW
parameter_list|(
name|struct
name|adv_softc
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ADV_INSW
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|u_int
name|offset
parameter_list|,
name|u_int16_t
modifier|*
name|valp
parameter_list|,
name|u_int
name|count
parameter_list|)
block|{
while|while
condition|(
name|count
operator|--
condition|)
operator|*
name|valp
operator|++
operator|=
name|bus_space_read_2
argument_list|(
name|adv
operator|->
name|tag
argument_list|,
name|adv
operator|->
name|bsh
argument_list|,
name|offset
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|ADV_OUTB
parameter_list|(
name|adv
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1((adv)->tag, (adv)->bsh, offset, val)
end_define

begin_define
define|#
directive|define
name|ADV_OUTW
parameter_list|(
name|adv
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2((adv)->tag, (adv)->bsh, offset, val)
end_define

begin_comment
comment|/* These controllers seem to have problems with PIO on some fast processors */
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|ADV_OUTSW
parameter_list|(
name|struct
name|adv_softc
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ADV_OUTSW
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|u_int
name|offset
parameter_list|,
name|u_int16_t
modifier|*
name|valp
parameter_list|,
name|u_int
name|count
parameter_list|)
block|{
while|while
condition|(
name|count
operator|--
condition|)
name|bus_space_write_2
argument_list|(
name|adv
operator|->
name|tag
argument_list|,
name|adv
operator|->
name|bsh
argument_list|,
name|offset
argument_list|,
operator|*
name|valp
operator|++
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ADVLIB_H_ */
end_comment

end_unit

