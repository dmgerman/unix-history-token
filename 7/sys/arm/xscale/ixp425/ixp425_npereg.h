begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2005, Intel Corporation.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Intel Corporation nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXP425_NPEREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXP425_NPEREG_H_
end_define

begin_comment
comment|/* signature found as 1st word in a microcode image library */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_IMAGEMGR_SIGNATURE
value|0xDEADBEEF
end_define

begin_comment
comment|/* marks end of header in a microcode image library */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_IMAGEMGR_END_OF_HEADER
value|0xFFFFFFFF
end_define

begin_comment
comment|/*  * Intel (R) IXP400 Software NPE Image ID Definition  *  * Definition of NPE Image ID to be passed to ixNpeDlNpeInitAndStart()  * as input of type uint32_t which has the following fields format:  *  * Field		[Bit Location]  * -----------------------------------  * Device ID		[31 - 28]  * NPE ID		[27 - 24]  * NPE Functionality ID	[23 - 16]  * Major Release Number	[15 -  8]  * Minor Release Number	[7 - 0]  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_NPEID_FROM_IMAGEID_GET
parameter_list|(
name|imageId
parameter_list|)
define|\
value|(((imageId)>> 24)& 0xf)
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_DEVICEID_FROM_IMAGEID_GET
parameter_list|(
name|imageId
parameter_list|)
define|\
value|(((imageId)>> 28)& 0xf)
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_FUNCTIONID_FROM_IMAGEID_GET
parameter_list|(
name|imageId
parameter_list|)
define|\
value|(((imageId)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_MAJOR_FROM_IMAGEID_GET
parameter_list|(
name|imageId
parameter_list|)
define|\
value|(((imageId)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_MINOR_FROM_IMAGEID_GET
parameter_list|(
name|imageId
parameter_list|)
define|\
value|(((imageId)>> 0)& 0xff)
end_define

begin_comment
comment|/*  * Instruction and Data Memory Size (in words) for each NPE   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ixp46X
end_ifndef

begin_define
define|#
directive|define
name|IX_NPEDL_INS_MEMSIZE_WORDS_NPEA
value|4096
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_INS_MEMSIZE_WORDS_NPEB
value|2048
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_INS_MEMSIZE_WORDS_NPEC
value|2048
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_DATA_MEMSIZE_WORDS_NPEA
value|2048
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_DATA_MEMSIZE_WORDS_NPEB
value|2048
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_DATA_MEMSIZE_WORDS_NPEC
value|2048
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IX_NPEDL_INS_MEMSIZE_WORDS_NPEA
value|4096
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_INS_MEMSIZE_WORDS_NPEB
value|4096
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_INS_MEMSIZE_WORDS_NPEC
value|4096
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_DATA_MEMSIZE_WORDS_NPEA
value|4096
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_DATA_MEMSIZE_WORDS_NPEB
value|4096
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_DATA_MEMSIZE_WORDS_NPEC
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BAR offsets */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_EXAD
value|0x00000000
end_define

begin_comment
comment|/* Execution Address */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_EXDATA
value|0x00000004
end_define

begin_comment
comment|/* Execution Data */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_EXCTL
value|0x00000008
end_define

begin_comment
comment|/* Execution Control */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_EXCT
value|0x0000000C
end_define

begin_comment
comment|/* Execution Count */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_AP0
value|0x00000010
end_define

begin_comment
comment|/* Action Point 0 */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_AP1
value|0x00000014
end_define

begin_comment
comment|/* Action Point 1 */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_AP2
value|0x00000018
end_define

begin_comment
comment|/* Action Point 2 */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_AP3
value|0x0000001C
end_define

begin_comment
comment|/* Action Point 3 */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_WFIFO
value|0x00000020
end_define

begin_comment
comment|/* Watchpoint FIFO */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_WC
value|0x00000024
end_define

begin_comment
comment|/* Watch Count */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_PROFCT
value|0x00000028
end_define

begin_comment
comment|/* Profile Count */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_STAT
value|0x0000002C
end_define

begin_comment
comment|/* Messaging Status */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_CTL
value|0x00000030
end_define

begin_comment
comment|/* Messaging Control */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_MBST
value|0x00000034
end_define

begin_comment
comment|/* Mailbox Status */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_OFFSET_FIFO
value|0x00000038
end_define

begin_comment
comment|/* Message FIFO */
end_comment

begin_comment
comment|/*  * Reset value for Mailbox (MBST) register  * NOTE that if used, it should be complemented with an NPE intruction  * to clear the Mailbox at the NPE side as well  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_REG_RESET_MBST
value|0x0000F0F0
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_MASK_WFIFO_VALID
value|0x80000000
end_define

begin_comment
comment|/* VALID bit */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_MASK_STAT_OFNE
value|0x00010000
end_define

begin_comment
comment|/* OFNE bit */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_MASK_STAT_IFNE
value|0x00080000
end_define

begin_comment
comment|/* IFNE bit */
end_comment

begin_comment
comment|/*  * EXCTL (Execution Control) Register commands  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_CMD_NPE_STEP
value|0x01
end_define

begin_comment
comment|/* Step 1 instruction */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_CMD_NPE_START
value|0x02
end_define

begin_comment
comment|/* Start execution */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_CMD_NPE_STOP
value|0x03
end_define

begin_comment
comment|/* Stop execution */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_CMD_NPE_CLR_PIPE
value|0x04
end_define

begin_comment
comment|/* Clear ins pipeline */
end_comment

begin_comment
comment|/*  * Read/write operations use address in EXAD and data in EXDATA.  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_CMD_RD_INS_MEM
value|0x10
end_define

begin_comment
comment|/* Read ins memory */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_CMD_WR_INS_MEM
value|0x11
end_define

begin_comment
comment|/* Write ins memory */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_CMD_RD_DATA_MEM
value|0x12
end_define

begin_comment
comment|/* Read data memory */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_CMD_WR_DATA_MEM
value|0x13
end_define

begin_comment
comment|/* Write data memory */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_CMD_RD_ECS_REG
value|0x14
end_define

begin_comment
comment|/* Read ECS register */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_CMD_WR_ECS_REG
value|0x15
end_define

begin_comment
comment|/* Write ECS register */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_CMD_CLR_PROFILE_CNT
value|0x0C
end_define

begin_comment
comment|/* Clear Profile Count register */
end_comment

begin_comment
comment|/*  * EXCTL (Execution Control) Register status bit masks  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_STATUS_RUN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_STATUS_STOP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_STATUS_CLEAR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_EXCTL_STATUS_ECS_K
value|0x00800000
end_define

begin_comment
comment|/* pipeline Klean */
end_comment

begin_comment
comment|/*  * Executing Context Stack (ECS) level registers   */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_BG_CTXT_REG_0
value|0x00
end_define

begin_comment
comment|/* reg 0 @ bg ctx */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_BG_CTXT_REG_1
value|0x01
end_define

begin_comment
comment|/* reg 1 @ bg ctx */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_BG_CTXT_REG_2
value|0x02
end_define

begin_comment
comment|/* reg 2 @ bg ctx */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_PRI_1_CTXT_REG_0
value|0x04
end_define

begin_comment
comment|/* reg 0 @ pri 1 ctx */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_PRI_1_CTXT_REG_1
value|0x05
end_define

begin_comment
comment|/* reg 1 @ pri 1 ctx */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_PRI_1_CTXT_REG_2
value|0x06
end_define

begin_comment
comment|/* reg 2 @ pri 1 ctx */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_PRI_2_CTXT_REG_0
value|0x08
end_define

begin_comment
comment|/* reg 0 @ pri 2 ctx */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_PRI_2_CTXT_REG_1
value|0x09
end_define

begin_comment
comment|/* reg 1 @ pri 2 ctx */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_PRI_2_CTXT_REG_2
value|0x0A
end_define

begin_comment
comment|/* reg 2 @ pri 2 ctx */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_DBG_CTXT_REG_0
value|0x0C
end_define

begin_comment
comment|/* reg 0 @ debug ctx */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_DBG_CTXT_REG_1
value|0x0D
end_define

begin_comment
comment|/* reg 1 @ debug ctx */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_DBG_CTXT_REG_2
value|0x0E
end_define

begin_comment
comment|/* reg 2 @ debug ctx */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_INSTRUCT_REG
value|0x11
end_define

begin_comment
comment|/* Instruction reg */
end_comment

begin_comment
comment|/*  * Execution Access register reset values  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_BG_CTXT_REG_0_RESET
value|0xA0000000
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_BG_CTXT_REG_1_RESET
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_BG_CTXT_REG_2_RESET
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_PRI_1_CTXT_REG_0_RESET
value|0x20000080
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_PRI_1_CTXT_REG_1_RESET
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_PRI_1_CTXT_REG_2_RESET
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_PRI_2_CTXT_REG_0_RESET
value|0x20000080
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_PRI_2_CTXT_REG_1_RESET
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_PRI_2_CTXT_REG_2_RESET
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_DBG_CTXT_REG_0_RESET
value|0x20000000
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_DBG_CTXT_REG_1_RESET
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_DBG_CTXT_REG_2_RESET
value|0x001E0000
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_ECS_INSTRUCT_REG_RESET
value|0x1003C00F
end_define

begin_comment
comment|/*  * Masks used to read/write particular bits in Execution Access registers  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_MASK_ECS_REG_0_ACTIVE
value|0x80000000
end_define

begin_comment
comment|/* Active bit */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_MASK_ECS_REG_0_NEXTPC
value|0x1FFF0000
end_define

begin_comment
comment|/* NextPC bits */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_MASK_ECS_REG_0_LDUR
value|0x00000700
end_define

begin_comment
comment|/* LDUR bits */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_MASK_ECS_REG_1_CCTXT
value|0x000F0000
end_define

begin_comment
comment|/* NextPC bits */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_MASK_ECS_REG_1_SELCTXT
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_MASK_ECS_DBG_REG_2_IF
value|0x00100000
end_define

begin_comment
comment|/* IF bit */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_MASK_ECS_DBG_REG_2_IE
value|0x00080000
end_define

begin_comment
comment|/* IE bit */
end_comment

begin_comment
comment|/*  * Bit-Offsets from LSB of particular bit-fields in Execution Access registers.  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_OFFSET_ECS_REG_0_NEXTPC
value|16
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_OFFSET_ECS_REG_0_LDUR
value|8
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_OFFSET_ECS_REG_1_CCTXT
value|16
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_OFFSET_ECS_REG_1_SELCTXT
value|0
end_define

begin_comment
comment|/*  * NPE core& co-processor instruction templates to load into NPE Instruction   * Register, for read/write of NPE register file registers.  */
end_comment

begin_comment
comment|/*  * Read an 8-bit NPE internal logical register  * and return the value in the EXDATA register (aligned to MSB).  * NPE Assembler instruction:  "mov8 d0, d0&&& DBG_WrExec"  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_INSTR_RD_REG_BYTE
value|0x0FC00000
end_define

begin_comment
comment|/*  * Read a 16-bit NPE internal logical register  * and return the value in the EXDATA register (aligned to MSB).  * NPE Assembler instruction:  "mov16 d0, d0&&& DBG_WrExec"  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_INSTR_RD_REG_SHORT
value|0x0FC08010
end_define

begin_comment
comment|/*  * Read a 16-bit NPE internal logical register  * and return the value in the EXDATA register.  * NPE Assembler instruction:  "mov32 d0, d0&&& DBG_WrExec"  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_INSTR_RD_REG_WORD
value|0x0FC08210
end_define

begin_comment
comment|/*  * Write an 8-bit NPE internal logical register.  * NPE Assembler instruction:  "mov8 d0, #0"  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_INSTR_WR_REG_BYTE
value|0x00004000
end_define

begin_comment
comment|/*  * Write a 16-bit NPE internal logical register.  * NPE Assembler instruction:  "mov16 d0, #0"  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_INSTR_WR_REG_SHORT
value|0x0000C000
end_define

begin_comment
comment|/*  * Write a 16-bit NPE internal logical register.  * NPE Assembler instruction:  "cprd32 d0&&& DBG_RdInFIFO"  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_INSTR_RD_FIFO
value|0x0F888220
end_define

begin_comment
comment|/*  * Reset Mailbox (MBST) register  * NPE Assembler instruction:  "mov32 d0, d0&&& DBG_ClearM"  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_INSTR_RESET_MBOX
value|0x0FAC8210
end_define

begin_comment
comment|/*  * Bit-offsets from LSB, of particular bit-fields in an NPE instruction  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_OFFSET_INSTR_SRC
value|4
end_define

begin_comment
comment|/* src operand */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_OFFSET_INSTR_DEST
value|9
end_define

begin_comment
comment|/* dest operand */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_OFFSET_INSTR_COPROC
value|18
end_define

begin_comment
comment|/* coprocessor ins */
end_comment

begin_comment
comment|/*  * Masks used to read/write particular bits of an NPE Instruction  */
end_comment

begin_comment
comment|/**  * Mask the bits of 16-bit data value (least-sig 5 bits) to be used in  * SRC field of immediate-mode NPE instruction  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_MASK_IMMED_INSTR_SRC_DATA
value|0x1F
end_define

begin_comment
comment|/**  * Mask the bits of 16-bit data value (most-sig 11 bits) to be used in  * COPROC field of immediate-mode NPE instruction  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_MASK_IMMED_INSTR_COPROC_DATA
value|0xFFE0
end_define

begin_comment
comment|/**  * LSB offset of the bit-field of 16-bit data value (most-sig 11 bits)  * to be used in COPROC field of immediate-mode NPE instruction  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_OFFSET_IMMED_INSTR_COPROC_DATA
value|5
end_define

begin_comment
comment|/**  * Number of left-shifts required to align most-sig 11 bits of 16-bit  * data value into COPROC field of immediate-mode NPE instruction  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_DISPLACE_IMMED_INSTR_COPROC_DATA
define|\
value|(IX_NPEDL_OFFSET_INSTR_COPROC - IX_NPEDL_OFFSET_IMMED_INSTR_COPROC_DATA)
end_define

begin_comment
comment|/**  * LDUR value used with immediate-mode NPE Instructions by the NpeDl  * for writing to NPE internal logical registers  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_WR_INSTR_LDUR
value|1
end_define

begin_comment
comment|/**  * LDUR value used with NON-immediate-mode NPE Instructions by the NpeDl  * for reading from NPE internal logical registers  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_RD_INSTR_LDUR
value|0
end_define

begin_comment
comment|/**  * NPE internal Context Store registers.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IX_NPEDL_CTXT_REG_STEVT
init|=
literal|0
block|,
comment|/**< identifies STEVT   */
name|IX_NPEDL_CTXT_REG_STARTPC
block|,
comment|/**< identifies STARTPC */
name|IX_NPEDL_CTXT_REG_REGMAP
block|,
comment|/**< identifies REGMAP  */
name|IX_NPEDL_CTXT_REG_CINDEX
block|,
comment|/**< identifies CINDEX  */
name|IX_NPEDL_CTXT_REG_MAX
comment|/**< Total number of Context Store registers */
block|}
name|IxNpeDlCtxtRegNum
typedef|;
end_typedef

begin_comment
comment|/*  * NPE Context Store register logical addresses  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_CTXT_REG_ADDR_STEVT
value|0x0000001B
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_CTXT_REG_ADDR_STARTPC
value|0x0000001C
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_CTXT_REG_ADDR_REGMAP
value|0x0000001E
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_CTXT_REG_ADDR_CINDEX
value|0x0000001F
end_define

begin_comment
comment|/*  * NPE Context Store register reset values  */
end_comment

begin_comment
comment|/**  * Reset value of STEVT NPE internal Context Store register  *        (STEVT = off, 0x80)  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_CTXT_REG_RESET_STEVT
value|0x80
end_define

begin_comment
comment|/**  * Reset value of STARTPC NPE internal Context Store register  *        (STARTPC = 0x0000)  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_CTXT_REG_RESET_STARTPC
value|0x0000
end_define

begin_comment
comment|/**  * Reset value of REGMAP NPE internal Context Store register  *        (REGMAP = d0->p0, d8->p2, d16->p4)  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_CTXT_REG_RESET_REGMAP
value|0x0820
end_define

begin_comment
comment|/**  * Reset value of CINDEX NPE internal Context Store register  *        (CINDEX = 0)  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_CTXT_REG_RESET_CINDEX
value|0x00
end_define

begin_comment
comment|/*  * Numeric range of context levels available on an NPE  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_CTXT_NUM_MIN
value|0
end_define

begin_define
define|#
directive|define
name|IX_NPEDL_CTXT_NUM_MAX
value|15
end_define

begin_comment
comment|/**  * Number of Physical registers currently supported  *        Initial NPE implementations will have a 32-word register file.  *        Later implementations may have a 64-word register file.  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_TOTAL_NUM_PHYS_REG
value|32
end_define

begin_comment
comment|/**  * LSB-offset of Regmap number in Physical NPE register address, used  *        for Physical To Logical register address mapping in the NPE  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_OFFSET_PHYS_REG_ADDR_REGMAP
value|1
end_define

begin_comment
comment|/**  * Mask to extract a logical NPE register address from a physical  *        register address, used for Physical To Logical address mapping  */
end_comment

begin_define
define|#
directive|define
name|IX_NPEDL_MASK_PHYS_REG_ADDR_LOGICAL_ADDR
value|0x1
end_define

begin_comment
comment|/*  * NPE Message/Mailbox interface.  */
end_comment

begin_define
define|#
directive|define
name|IX_NPESTAT
value|IX_NPEDL_REG_OFFSET_STAT
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|IX_NPECTL
value|IX_NPEDL_REG_OFFSET_CTL
end_define

begin_comment
comment|/* control register */
end_comment

begin_define
define|#
directive|define
name|IX_NPEFIFO
value|IX_NPEDL_REG_OFFSET_FIFO
end_define

begin_comment
comment|/* FIFO register */
end_comment

begin_comment
comment|/* control register */
end_comment

begin_define
define|#
directive|define
name|IX_NPECTL_OFE
value|0x00010000
end_define

begin_comment
comment|/* output fifo enable */
end_comment

begin_define
define|#
directive|define
name|IX_NPECTL_IFE
value|0x00020000
end_define

begin_comment
comment|/* input fifo enable */
end_comment

begin_define
define|#
directive|define
name|IX_NPECTL_OFWE
value|0x01000000
end_define

begin_comment
comment|/* output fifo write enable */
end_comment

begin_define
define|#
directive|define
name|IX_NPECTL_IFWE
value|0x02000000
end_define

begin_comment
comment|/* input fifo write enable */
end_comment

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|IX_NPESTAT_OFNE
value|0x00010000
end_define

begin_comment
comment|/* output fifo not empty */
end_comment

begin_define
define|#
directive|define
name|IX_NPESTAT_IFNF
value|0x00020000
end_define

begin_comment
comment|/* input fifo not full */
end_comment

begin_define
define|#
directive|define
name|IX_NPESTAT_OFNF
value|0x00040000
end_define

begin_comment
comment|/* output fifo not full */
end_comment

begin_define
define|#
directive|define
name|IX_NPESTAT_IFNE
value|0x00080000
end_define

begin_comment
comment|/* input fifo not empty */
end_comment

begin_define
define|#
directive|define
name|IX_NPESTAT_MBINT
value|0x00100000
end_define

begin_comment
comment|/* Mailbox interrupt */
end_comment

begin_define
define|#
directive|define
name|IX_NPESTAT_IFINT
value|0x00200000
end_define

begin_comment
comment|/* input fifo interrupt */
end_comment

begin_define
define|#
directive|define
name|IX_NPESTAT_OFINT
value|0x00400000
end_define

begin_comment
comment|/* output fifo interrupt */
end_comment

begin_define
define|#
directive|define
name|IX_NPESTAT_WFINT
value|0x00800000
end_define

begin_comment
comment|/* watch fifo interrupt */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXP425_NPEREG_H_ */
end_comment

end_unit

