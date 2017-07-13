begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  * Copyright (c) 2017 Marius Strobl<marius@FreeBSD.org>  * Copyright (c) 2015-2016 Ilya Bakulin<kibab@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Portions of this software may have been developed with reference to  * the SD Simplified Specification.  The following disclaimer may apply:  *  * The following conditions apply to the release of the simplified  * specification ("Simplified Specification") by the SD Card Association and  * the SD Group. The Simplified Specification is a subset of the complete SD  * Specification which is owned by the SD Card Association and the SD  * Group. This Simplified Specification is provided on a non-confidential  * basis subject to the disclaimers below. Any implementation of the  * Simplified Specification may require a license from the SD Card  * Association, SD Group, SD-3C LLC or other third parties.  *  * Disclaimers:  *  * The information contained in the Simplified Specification is presented only  * as a standard specification for SD Cards and SD Host/Ancillary products and  * is provided "AS-IS" without any representations or warranties of any  * kind. No responsibility is assumed by the SD Group, SD-3C LLC or the SD  * Card Association for any damages, any infringements of patents or other  * right of the SD Group, SD-3C LLC, the SD Card Association or any third  * parties, which may result from its use. No license is granted by  * implication, estoppel or otherwise under any patent or other rights of the  * SD Group, SD-3C LLC, the SD Card Association or any third party. Nothing  * herein shall be construed as an obligation by the SD Group, the SD-3C LLC  * or the SD Card Association to disclose or distribute any technical  * information, know-how or other confidential information to any third party.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_MMC_MMCREG_H
end_ifndef

begin_define
define|#
directive|define
name|DEV_MMC_MMCREG_H
end_define

begin_comment
comment|/*  * This file contains the register definitions for the mmc and sd buses.  * They are taken from publicly available sources.  */
end_comment

begin_struct_decl
struct_decl|struct
name|mmc_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mmc_request
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|mmc_command
block|{
name|uint32_t
name|opcode
decl_stmt|;
name|uint32_t
name|arg
decl_stmt|;
name|uint32_t
name|resp
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* Expected responses */
define|#
directive|define
name|MMC_RSP_PRESENT
value|(1ul<< 0)
comment|/* Response */
define|#
directive|define
name|MMC_RSP_136
value|(1ul<< 1)
comment|/* 136 bit response */
define|#
directive|define
name|MMC_RSP_CRC
value|(1ul<< 2)
comment|/* Expect valid crc */
define|#
directive|define
name|MMC_RSP_BUSY
value|(1ul<< 3)
comment|/* Card may send busy */
define|#
directive|define
name|MMC_RSP_OPCODE
value|(1ul<< 4)
comment|/* Response include opcode */
define|#
directive|define
name|MMC_RSP_MASK
value|0x1ful
define|#
directive|define
name|MMC_CMD_AC
value|(0ul<< 5)
comment|/* Addressed Command, no data */
define|#
directive|define
name|MMC_CMD_ADTC
value|(1ul<< 5)
comment|/* Addressed Data transfer cmd */
define|#
directive|define
name|MMC_CMD_BC
value|(2ul<< 5)
comment|/* Broadcast command, no response */
define|#
directive|define
name|MMC_CMD_BCR
value|(3ul<< 5)
comment|/* Broadcast command with response */
define|#
directive|define
name|MMC_CMD_MASK
value|(3ul<< 5)
comment|/* Possible response types defined in the standard: */
define|#
directive|define
name|MMC_RSP_NONE
value|(0)
define|#
directive|define
name|MMC_RSP_R1
value|(MMC_RSP_PRESENT | MMC_RSP_CRC | MMC_RSP_OPCODE)
define|#
directive|define
name|MMC_RSP_R1B
value|(MMC_RSP_PRESENT | MMC_RSP_CRC | MMC_RSP_OPCODE | MMC_RSP_BUSY)
define|#
directive|define
name|MMC_RSP_R2
value|(MMC_RSP_PRESENT | MMC_RSP_136 | MMC_RSP_CRC)
define|#
directive|define
name|MMC_RSP_R3
value|(MMC_RSP_PRESENT)
define|#
directive|define
name|MMC_RSP_R4
value|(MMC_RSP_PRESENT)
define|#
directive|define
name|MMC_RSP_R5
value|(MMC_RSP_PRESENT | MMC_RSP_CRC | MMC_RSP_OPCODE)
define|#
directive|define
name|MMC_RSP_R5B
value|(MMC_RSP_PRESENT | MMC_RSP_CRC | MMC_RSP_OPCODE | MMC_RSP_BUSY)
define|#
directive|define
name|MMC_RSP_R6
value|(MMC_RSP_PRESENT | MMC_RSP_CRC | MMC_RSP_OPCODE)
define|#
directive|define
name|MMC_RSP_R7
value|(MMC_RSP_PRESENT | MMC_RSP_CRC | MMC_RSP_OPCODE)
define|#
directive|define
name|MMC_RSP
parameter_list|(
name|x
parameter_list|)
value|((x)& MMC_RSP_MASK)
name|uint32_t
name|retries
decl_stmt|;
name|uint32_t
name|error
decl_stmt|;
define|#
directive|define
name|MMC_ERR_NONE
value|0
define|#
directive|define
name|MMC_ERR_TIMEOUT
value|1
define|#
directive|define
name|MMC_ERR_BADCRC
value|2
define|#
directive|define
name|MMC_ERR_FIFO
value|3
define|#
directive|define
name|MMC_ERR_FAILED
value|4
define|#
directive|define
name|MMC_ERR_INVALID
value|5
define|#
directive|define
name|MMC_ERR_NO_MEMORY
value|6
define|#
directive|define
name|MMC_ERR_MAX
value|6
name|struct
name|mmc_data
modifier|*
name|data
decl_stmt|;
comment|/* Data segment with cmd */
name|struct
name|mmc_request
modifier|*
name|mrq
decl_stmt|;
comment|/* backpointer to request */
block|}
struct|;
end_struct

begin_comment
comment|/*  * R1 responses  *  * Types (per SD 2.0 standard)  *	e : error bit  *	s : status bit  *	r : detected and set for the actual command response  *	x : Detected and set during command execution.  The host can get  *	    the status by issuing a command with R1 response.  *  * Clear Condition (per SD 2.0 standard)  *	a : according to the card current state.  *	b : always related to the previous command.  reception of a valid  *	    command will clear it (with a delay of one command).  *	c : clear by read  */
end_comment

begin_define
define|#
directive|define
name|R1_OUT_OF_RANGE
value|(1u<< 31)
end_define

begin_comment
comment|/* erx, c */
end_comment

begin_define
define|#
directive|define
name|R1_ADDRESS_ERROR
value|(1u<< 30)
end_define

begin_comment
comment|/* erx, c */
end_comment

begin_define
define|#
directive|define
name|R1_BLOCK_LEN_ERROR
value|(1u<< 29)
end_define

begin_comment
comment|/* erx, c */
end_comment

begin_define
define|#
directive|define
name|R1_ERASE_SEQ_ERROR
value|(1u<< 28)
end_define

begin_comment
comment|/* er, c */
end_comment

begin_define
define|#
directive|define
name|R1_ERASE_PARAM
value|(1u<< 27)
end_define

begin_comment
comment|/* erx, c */
end_comment

begin_define
define|#
directive|define
name|R1_WP_VIOLATION
value|(1u<< 26)
end_define

begin_comment
comment|/* erx, c */
end_comment

begin_define
define|#
directive|define
name|R1_CARD_IS_LOCKED
value|(1u<< 25)
end_define

begin_comment
comment|/* sx, a */
end_comment

begin_define
define|#
directive|define
name|R1_LOCK_UNLOCK_FAILED
value|(1u<< 24)
end_define

begin_comment
comment|/* erx, c */
end_comment

begin_define
define|#
directive|define
name|R1_COM_CRC_ERROR
value|(1u<< 23)
end_define

begin_comment
comment|/* er, b */
end_comment

begin_define
define|#
directive|define
name|R1_ILLEGAL_COMMAND
value|(1u<< 22)
end_define

begin_comment
comment|/* er, b */
end_comment

begin_define
define|#
directive|define
name|R1_CARD_ECC_FAILED
value|(1u<< 21)
end_define

begin_comment
comment|/* erx, c */
end_comment

begin_define
define|#
directive|define
name|R1_CC_ERROR
value|(1u<< 20)
end_define

begin_comment
comment|/* erx, c */
end_comment

begin_define
define|#
directive|define
name|R1_ERROR
value|(1u<< 19)
end_define

begin_comment
comment|/* erx, c */
end_comment

begin_define
define|#
directive|define
name|R1_CSD_OVERWRITE
value|(1u<< 16)
end_define

begin_comment
comment|/* erx, c */
end_comment

begin_define
define|#
directive|define
name|R1_WP_ERASE_SKIP
value|(1u<< 15)
end_define

begin_comment
comment|/* erx, c */
end_comment

begin_define
define|#
directive|define
name|R1_CARD_ECC_DISABLED
value|(1u<< 14)
end_define

begin_comment
comment|/* sx, a */
end_comment

begin_define
define|#
directive|define
name|R1_ERASE_RESET
value|(1u<< 13)
end_define

begin_comment
comment|/* sr, c */
end_comment

begin_define
define|#
directive|define
name|R1_CURRENT_STATE_MASK
value|(0xfu<< 9)
end_define

begin_comment
comment|/* sx, b */
end_comment

begin_define
define|#
directive|define
name|R1_READY_FOR_DATA
value|(1u<< 8)
end_define

begin_comment
comment|/* sx, a */
end_comment

begin_define
define|#
directive|define
name|R1_SWITCH_ERROR
value|(1u<< 7)
end_define

begin_comment
comment|/* sx, c */
end_comment

begin_define
define|#
directive|define
name|R1_APP_CMD
value|(1u<< 5)
end_define

begin_comment
comment|/* sr, c */
end_comment

begin_define
define|#
directive|define
name|R1_AKE_SEQ_ERROR
value|(1u<< 3)
end_define

begin_comment
comment|/* er, c */
end_comment

begin_define
define|#
directive|define
name|R1_STATUS
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFFE000)
end_define

begin_define
define|#
directive|define
name|R1_CURRENT_STATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& R1_CURRENT_STATE_MASK)>> 9)
end_define

begin_define
define|#
directive|define
name|R1_STATE_IDLE
value|0
end_define

begin_define
define|#
directive|define
name|R1_STATE_READY
value|1
end_define

begin_define
define|#
directive|define
name|R1_STATE_IDENT
value|2
end_define

begin_define
define|#
directive|define
name|R1_STATE_STBY
value|3
end_define

begin_define
define|#
directive|define
name|R1_STATE_TRAN
value|4
end_define

begin_define
define|#
directive|define
name|R1_STATE_DATA
value|5
end_define

begin_define
define|#
directive|define
name|R1_STATE_RCV
value|6
end_define

begin_define
define|#
directive|define
name|R1_STATE_PRG
value|7
end_define

begin_define
define|#
directive|define
name|R1_STATE_DIS
value|8
end_define

begin_comment
comment|/* R4 response (SDIO) */
end_comment

begin_define
define|#
directive|define
name|R4_IO_NUM_FUNCTIONS
parameter_list|(
name|ocr
parameter_list|)
value|(((ocr)>> 28)& 0x3)
end_define

begin_define
define|#
directive|define
name|R4_IO_MEM_PRESENT
value|(0x1<<27)
end_define

begin_define
define|#
directive|define
name|R4_IO_OCR_MASK
value|0x00fffff0
end_define

begin_comment
comment|/*  * R5 responses  *  * Types (per SD 2.0 standard)  *e : error bit  *s : status bit  *r : detected and set for the actual command response  *x : Detected and set during command execution.  The host can get  *    the status by issuing a command with R1 response.  *  * Clear Condition (per SD 2.0 standard)  *a : according to the card current state.  *b : always related to the previous command.  reception of a valid  *    command will clear it (with a delay of one command).  *c : clear by read  */
end_comment

begin_define
define|#
directive|define
name|R5_COM_CRC_ERROR
value|(1u<< 15)
end_define

begin_comment
comment|/* er, b */
end_comment

begin_define
define|#
directive|define
name|R5_ILLEGAL_COMMAND
value|(1u<< 14)
end_define

begin_comment
comment|/* er, b */
end_comment

begin_define
define|#
directive|define
name|R5_IO_CURRENT_STATE_MASK
value|(3u<< 12)
end_define

begin_comment
comment|/* s, b */
end_comment

begin_define
define|#
directive|define
name|R5_IO_CURRENT_STATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& R5_IO_CURRENT_STATE_MASK)>> 12)
end_define

begin_define
define|#
directive|define
name|R5_ERROR
value|(1u<< 11)
end_define

begin_comment
comment|/* erx, c */
end_comment

begin_define
define|#
directive|define
name|R5_FUNCTION_NUMBER
value|(1u<< 9)
end_define

begin_comment
comment|/* er, c */
end_comment

begin_define
define|#
directive|define
name|R5_OUT_OF_RANGE
value|(1u<< 8)
end_define

begin_comment
comment|/* er, c */
end_comment

begin_struct
struct|struct
name|mmc_data
block|{
name|size_t
name|len
decl_stmt|;
comment|/* size of the data */
name|size_t
name|xfer_len
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
comment|/* data buffer */
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|MMC_DATA_WRITE
value|(1UL<< 0)
define|#
directive|define
name|MMC_DATA_READ
value|(1UL<< 1)
define|#
directive|define
name|MMC_DATA_STREAM
value|(1UL<< 2)
define|#
directive|define
name|MMC_DATA_MULTI
value|(1UL<< 3)
name|struct
name|mmc_request
modifier|*
name|mrq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mmc_request
block|{
name|struct
name|mmc_command
modifier|*
name|cmd
decl_stmt|;
name|struct
name|mmc_command
modifier|*
name|stop
decl_stmt|;
name|void
function_decl|(
modifier|*
name|done
function_decl|)
parameter_list|(
name|struct
name|mmc_request
modifier|*
parameter_list|)
function_decl|;
comment|/* Completion function */
name|void
modifier|*
name|done_data
decl_stmt|;
comment|/* requestor set data */
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|MMC_REQ_DONE
value|1
block|}
struct|;
end_struct

begin_comment
comment|/* Command definitions */
end_comment

begin_comment
comment|/* Class 0 and 1: Basic commands& read stream commands */
end_comment

begin_define
define|#
directive|define
name|MMC_GO_IDLE_STATE
value|0
end_define

begin_define
define|#
directive|define
name|MMC_SEND_OP_COND
value|1
end_define

begin_define
define|#
directive|define
name|MMC_ALL_SEND_CID
value|2
end_define

begin_define
define|#
directive|define
name|MMC_SET_RELATIVE_ADDR
value|3
end_define

begin_define
define|#
directive|define
name|SD_SEND_RELATIVE_ADDR
value|3
end_define

begin_define
define|#
directive|define
name|MMC_SET_DSR
value|4
end_define

begin_define
define|#
directive|define
name|MMC_SLEEP_AWAKE
value|5
end_define

begin_define
define|#
directive|define
name|IO_SEND_OP_COND
value|5
end_define

begin_define
define|#
directive|define
name|MMC_SWITCH_FUNC
value|6
end_define

begin_define
define|#
directive|define
name|MMC_SWITCH_FUNC_CMDS
value|0
end_define

begin_define
define|#
directive|define
name|MMC_SWITCH_FUNC_SET
value|1
end_define

begin_define
define|#
directive|define
name|MMC_SWITCH_FUNC_CLR
value|2
end_define

begin_define
define|#
directive|define
name|MMC_SWITCH_FUNC_WR
value|3
end_define

begin_define
define|#
directive|define
name|MMC_SELECT_CARD
value|7
end_define

begin_define
define|#
directive|define
name|MMC_DESELECT_CARD
value|7
end_define

begin_define
define|#
directive|define
name|MMC_SEND_EXT_CSD
value|8
end_define

begin_define
define|#
directive|define
name|SD_SEND_IF_COND
value|8
end_define

begin_define
define|#
directive|define
name|MMC_SEND_CSD
value|9
end_define

begin_define
define|#
directive|define
name|MMC_SEND_CID
value|10
end_define

begin_define
define|#
directive|define
name|MMC_READ_DAT_UNTIL_STOP
value|11
end_define

begin_define
define|#
directive|define
name|MMC_STOP_TRANSMISSION
value|12
end_define

begin_define
define|#
directive|define
name|MMC_SEND_STATUS
value|13
end_define

begin_define
define|#
directive|define
name|MMC_BUSTEST_R
value|14
end_define

begin_define
define|#
directive|define
name|MMC_GO_INACTIVE_STATE
value|15
end_define

begin_define
define|#
directive|define
name|MMC_BUSTEST_W
value|19
end_define

begin_comment
comment|/* Class 2: Block oriented read commands */
end_comment

begin_define
define|#
directive|define
name|MMC_SET_BLOCKLEN
value|16
end_define

begin_define
define|#
directive|define
name|MMC_READ_SINGLE_BLOCK
value|17
end_define

begin_define
define|#
directive|define
name|MMC_READ_MULTIPLE_BLOCK
value|18
end_define

begin_define
define|#
directive|define
name|MMC_SEND_TUNING_BLOCK
value|19
end_define

begin_define
define|#
directive|define
name|MMC_SEND_TUNING_BLOCK_HS200
value|21
end_define

begin_comment
comment|/* Class 3: Stream write commands */
end_comment

begin_define
define|#
directive|define
name|MMC_WRITE_DAT_UNTIL_STOP
value|20
end_define

begin_comment
comment|/* reserved: 22 */
end_comment

begin_comment
comment|/* Class 4: Block oriented write commands */
end_comment

begin_define
define|#
directive|define
name|MMC_SET_BLOCK_COUNT
value|23
end_define

begin_define
define|#
directive|define
name|MMC_WRITE_BLOCK
value|24
end_define

begin_define
define|#
directive|define
name|MMC_WRITE_MULTIPLE_BLOCK
value|25
end_define

begin_define
define|#
directive|define
name|MMC_PROGARM_CID
value|26
end_define

begin_define
define|#
directive|define
name|MMC_PROGRAM_CSD
value|27
end_define

begin_comment
comment|/* Class 6: Block oriented write protection commands */
end_comment

begin_define
define|#
directive|define
name|MMC_SET_WRITE_PROT
value|28
end_define

begin_define
define|#
directive|define
name|MMC_CLR_WRITE_PROT
value|29
end_define

begin_define
define|#
directive|define
name|MMC_SEND_WRITE_PROT
value|30
end_define

begin_comment
comment|/* reserved: 31 */
end_comment

begin_comment
comment|/* Class 5: Erase commands */
end_comment

begin_define
define|#
directive|define
name|SD_ERASE_WR_BLK_START
value|32
end_define

begin_define
define|#
directive|define
name|SD_ERASE_WR_BLK_END
value|33
end_define

begin_comment
comment|/* 34 -- reserved old command */
end_comment

begin_define
define|#
directive|define
name|MMC_ERASE_GROUP_START
value|35
end_define

begin_define
define|#
directive|define
name|MMC_ERASE_GROUP_END
value|36
end_define

begin_comment
comment|/* 37 -- reserved old command */
end_comment

begin_define
define|#
directive|define
name|MMC_ERASE
value|38
end_define

begin_comment
comment|/* Class 9: I/O mode commands */
end_comment

begin_define
define|#
directive|define
name|MMC_FAST_IO
value|39
end_define

begin_define
define|#
directive|define
name|MMC_GO_IRQ_STATE
value|40
end_define

begin_comment
comment|/* reserved: 41 */
end_comment

begin_comment
comment|/* Class 7: Lock card */
end_comment

begin_define
define|#
directive|define
name|MMC_LOCK_UNLOCK
value|42
end_define

begin_comment
comment|/* reserved: 43 */
end_comment

begin_comment
comment|/* reserved: 44 */
end_comment

begin_comment
comment|/* reserved: 45 */
end_comment

begin_comment
comment|/* reserved: 46 */
end_comment

begin_comment
comment|/* reserved: 47 */
end_comment

begin_comment
comment|/* reserved: 48 */
end_comment

begin_comment
comment|/* reserved: 49 */
end_comment

begin_comment
comment|/* reserved: 50 */
end_comment

begin_comment
comment|/* reserved: 51 */
end_comment

begin_comment
comment|/* reserved: 54 */
end_comment

begin_comment
comment|/* Class 8: Application specific commands */
end_comment

begin_define
define|#
directive|define
name|MMC_APP_CMD
value|55
end_define

begin_define
define|#
directive|define
name|MMC_GEN_CMD
value|56
end_define

begin_comment
comment|/* reserved: 57 */
end_comment

begin_comment
comment|/* reserved: 58 */
end_comment

begin_comment
comment|/* reserved: 59 */
end_comment

begin_comment
comment|/* reserved for mfg: 60 */
end_comment

begin_comment
comment|/* reserved for mfg: 61 */
end_comment

begin_comment
comment|/* reserved for mfg: 62 */
end_comment

begin_comment
comment|/* reserved for mfg: 63 */
end_comment

begin_comment
comment|/* Class 9: I/O cards (sd) */
end_comment

begin_define
define|#
directive|define
name|SD_IO_RW_DIRECT
value|52
end_define

begin_comment
comment|/* CMD52 arguments */
end_comment

begin_define
define|#
directive|define
name|SD_ARG_CMD52_READ
value|(0<<31)
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD52_WRITE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD52_FUNC_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD52_FUNC_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD52_EXCHANGE
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD52_REG_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD52_REG_MASK
value|0x1ffff
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD52_DATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD52_DATA_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|SD_R5_DATA
parameter_list|(
name|resp
parameter_list|)
value|((resp)[0]& 0xff)
end_define

begin_define
define|#
directive|define
name|SD_IO_RW_EXTENDED
value|53
end_define

begin_comment
comment|/* CMD53 arguments */
end_comment

begin_define
define|#
directive|define
name|SD_ARG_CMD53_READ
value|(0<<31)
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD53_WRITE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD53_FUNC_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD53_FUNC_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD53_BLOCK_MODE
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD53_INCREMENT
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD53_REG_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD53_REG_MASK
value|0x1ffff
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD53_LENGTH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD53_LENGTH_MASK
value|0x1ff
end_define

begin_define
define|#
directive|define
name|SD_ARG_CMD53_LENGTH_MAX
value|64
end_define

begin_comment
comment|/* XXX should be 511? */
end_comment

begin_comment
comment|/* Class 10: Switch function commands */
end_comment

begin_define
define|#
directive|define
name|SD_SWITCH_FUNC
value|6
end_define

begin_comment
comment|/* reserved: 34 */
end_comment

begin_comment
comment|/* reserved: 35 */
end_comment

begin_comment
comment|/* reserved: 36 */
end_comment

begin_comment
comment|/* reserved: 37 */
end_comment

begin_comment
comment|/* reserved: 50 */
end_comment

begin_comment
comment|/* reserved: 57 */
end_comment

begin_comment
comment|/* Application specific commands for SD */
end_comment

begin_define
define|#
directive|define
name|ACMD_SET_BUS_WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|ACMD_SD_STATUS
value|13
end_define

begin_define
define|#
directive|define
name|ACMD_SEND_NUM_WR_BLOCKS
value|22
end_define

begin_define
define|#
directive|define
name|ACMD_SET_WR_BLK_ERASE_COUNT
value|23
end_define

begin_define
define|#
directive|define
name|ACMD_SD_SEND_OP_COND
value|41
end_define

begin_define
define|#
directive|define
name|ACMD_SET_CLR_CARD_DETECT
value|42
end_define

begin_define
define|#
directive|define
name|ACMD_SEND_SCR
value|51
end_define

begin_comment
comment|/*  * EXT_CSD fields  */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_EXT_PART_ATTR
value|52
end_define

begin_comment
comment|/* R/W, 2 bytes */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_ENH_START_ADDR
value|136
end_define

begin_comment
comment|/* R/W, 4 bytes */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_ENH_SIZE_MULT
value|140
end_define

begin_comment
comment|/* R/W, 3 bytes */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_GP_SIZE_MULT
value|143
end_define

begin_comment
comment|/* R/W, 12 bytes */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PART_SET
value|155
end_define

begin_comment
comment|/* R/W */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PART_ATTR
value|156
end_define

begin_comment
comment|/* R/W */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PART_SUPPORT
value|160
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_RPMB_MULT
value|168
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_BOOT_WP_STATUS
value|174
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_ERASE_GRP_DEF
value|175
end_define

begin_comment
comment|/* R/W */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG
value|179
end_define

begin_comment
comment|/* R/W */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_BUS_WIDTH
value|183
end_define

begin_comment
comment|/* R/W */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_STROBE_SUPPORT
value|184
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_HS_TIMING
value|185
end_define

begin_comment
comment|/* R/W */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_POWER_CLASS
value|187
end_define

begin_comment
comment|/* R/W */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_CARD_TYPE
value|196
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_DRIVER_STRENGTH
value|197
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_REV
value|192
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PART_SWITCH_TO
value|199
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PWR_CL_52_195
value|200
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PWR_CL_26_195
value|201
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PWR_CL_52_360
value|202
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PWR_CL_26_360
value|203
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_SEC_CNT
value|212
end_define

begin_comment
comment|/* RO, 4 bytes */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_HC_WP_GRP_SIZE
value|221
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_ERASE_TO_MULT
value|223
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_ERASE_GRP_SIZE
value|224
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_BOOT_SIZE_MULT
value|226
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PWR_CL_200_195
value|236
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PWR_CL_200_360
value|237
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PWR_CL_52_195_DDR
value|238
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PWR_CL_52_360_DDR
value|239
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_GEN_CMD6_TIME
value|248
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_PWR_CL_200_360_DDR
value|253
end_define

begin_comment
comment|/* RO */
end_comment

begin_comment
comment|/*  * EXT_CSD field definitions  */
end_comment

begin_define
define|#
directive|define
name|EXT_CSD_EXT_PART_ATTR_DEFAULT
value|0x0
end_define

begin_define
define|#
directive|define
name|EXT_CSD_EXT_PART_ATTR_SYSTEMCODE
value|0x1
end_define

begin_define
define|#
directive|define
name|EXT_CSD_EXT_PART_ATTR_NPERSISTENT
value|0x2
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_SET_COMPLETED
value|0x01
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_ATTR_ENH_USR
value|0x01
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_ATTR_ENH_GP0
value|0x02
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_ATTR_ENH_GP1
value|0x04
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_ATTR_ENH_GP2
value|0x08
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_ATTR_ENH_GP3
value|0x10
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_ATTR_ENH_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_SUPPORT_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_SUPPORT_ENH_ATTR_EN
value|0x02
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_SUPPORT_EXT_ATTR_EN
value|0x04
end_define

begin_define
define|#
directive|define
name|EXT_CSD_BOOT_WP_STATUS_BOOT0_PWR
value|0x01
end_define

begin_define
define|#
directive|define
name|EXT_CSD_BOOT_WP_STATUS_BOOT0_PERM
value|0x02
end_define

begin_define
define|#
directive|define
name|EXT_CSD_BOOT_WP_STATUS_BOOT0_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|EXT_CSD_BOOT_WP_STATUS_BOOT1_PWR
value|0x04
end_define

begin_define
define|#
directive|define
name|EXT_CSD_BOOT_WP_STATUS_BOOT1_PERM
value|0x08
end_define

begin_define
define|#
directive|define
name|EXT_CSD_BOOT_WP_STATUS_BOOT1_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|EXT_CSD_ERASE_GRP_DEF_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_ACC_DEFAULT
value|0x00
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_ACC_BOOT0
value|0x01
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_ACC_BOOT1
value|0x02
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_ACC_RPMB
value|0x03
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_ACC_GP0
value|0x04
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_ACC_GP1
value|0x05
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_ACC_GP2
value|0x06
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_ACC_GP3
value|0x07
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_ACC_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_BOOT0
value|0x08
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_BOOT1
value|0x10
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_BOOT_USR
value|0x38
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_BOOT_MASK
value|0x38
end_define

begin_define
define|#
directive|define
name|EXT_CSD_PART_CONFIG_BOOT_ACK
value|0x40
end_define

begin_define
define|#
directive|define
name|EXT_CSD_CMD_SET_NORMAL
value|1
end_define

begin_define
define|#
directive|define
name|EXT_CSD_CMD_SET_SECURE
value|2
end_define

begin_define
define|#
directive|define
name|EXT_CSD_CMD_SET_CPSECURE
value|4
end_define

begin_define
define|#
directive|define
name|EXT_CSD_HS_TIMING_BC
value|0
end_define

begin_define
define|#
directive|define
name|EXT_CSD_HS_TIMING_HS
value|1
end_define

begin_define
define|#
directive|define
name|EXT_CSD_HS_TIMING_DDR200
value|2
end_define

begin_define
define|#
directive|define
name|EXT_CSD_HS_TIMING_DDR400
value|3
end_define

begin_define
define|#
directive|define
name|EXT_CSD_HS_TIMING_DRV_STR_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|EXT_CSD_POWER_CLASS_8BIT_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|EXT_CSD_POWER_CLASS_8BIT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|EXT_CSD_POWER_CLASS_4BIT_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|EXT_CSD_POWER_CLASS_4BIT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|EXT_CSD_CARD_TYPE_HS_26
value|0x0001
end_define

begin_define
define|#
directive|define
name|EXT_CSD_CARD_TYPE_HS_52
value|0x0002
end_define

begin_define
define|#
directive|define
name|EXT_CSD_CARD_TYPE_DDR_52_1_8V
value|0x0004
end_define

begin_define
define|#
directive|define
name|EXT_CSD_CARD_TYPE_DDR_52_1_2V
value|0x0008
end_define

begin_define
define|#
directive|define
name|EXT_CSD_CARD_TYPE_HS200_1_8V
value|0x0010
end_define

begin_define
define|#
directive|define
name|EXT_CSD_CARD_TYPE_HS200_1_2V
value|0x0020
end_define

begin_define
define|#
directive|define
name|EXT_CSD_CARD_TYPE_HS400_1_8V
value|0x0040
end_define

begin_define
define|#
directive|define
name|EXT_CSD_CARD_TYPE_HS400_1_2V
value|0x0080
end_define

begin_define
define|#
directive|define
name|EXT_CSD_CARD_TYPE_HS400ES
value|0x0100
end_define

begin_define
define|#
directive|define
name|EXT_CSD_BUS_WIDTH_1
value|0
end_define

begin_define
define|#
directive|define
name|EXT_CSD_BUS_WIDTH_4
value|1
end_define

begin_define
define|#
directive|define
name|EXT_CSD_BUS_WIDTH_8
value|2
end_define

begin_define
define|#
directive|define
name|EXT_CSD_BUS_WIDTH_4_DDR
value|5
end_define

begin_define
define|#
directive|define
name|EXT_CSD_BUS_WIDTH_8_DDR
value|6
end_define

begin_define
define|#
directive|define
name|EXT_CSD_BUS_WIDTH_ES
value|0x80
end_define

begin_define
define|#
directive|define
name|MMC_TYPE_HS_26_MAX
value|26000000
end_define

begin_define
define|#
directive|define
name|MMC_TYPE_HS_52_MAX
value|52000000
end_define

begin_define
define|#
directive|define
name|MMC_TYPE_DDR52_MAX
value|52000000
end_define

begin_define
define|#
directive|define
name|MMC_TYPE_HS200_HS400ES_MAX
value|200000000
end_define

begin_comment
comment|/*  * SD bus widths  */
end_comment

begin_define
define|#
directive|define
name|SD_BUS_WIDTH_1
value|0
end_define

begin_define
define|#
directive|define
name|SD_BUS_WIDTH_4
value|2
end_define

begin_comment
comment|/*  * SD Switch  */
end_comment

begin_define
define|#
directive|define
name|SD_SWITCH_MODE_CHECK
value|0
end_define

begin_define
define|#
directive|define
name|SD_SWITCH_MODE_SET
value|1
end_define

begin_define
define|#
directive|define
name|SD_SWITCH_GROUP1
value|0
end_define

begin_define
define|#
directive|define
name|SD_SWITCH_NORMAL_MODE
value|0
end_define

begin_define
define|#
directive|define
name|SD_SWITCH_HS_MODE
value|1
end_define

begin_define
define|#
directive|define
name|SD_SWITCH_SDR50_MODE
value|2
end_define

begin_define
define|#
directive|define
name|SD_SWITCH_SDR104_MODE
value|3
end_define

begin_define
define|#
directive|define
name|SD_SWITCH_DDR50
value|4
end_define

begin_define
define|#
directive|define
name|SD_SWITCH_NOCHANGE
value|0xF
end_define

begin_define
define|#
directive|define
name|SD_CLR_CARD_DETECT
value|0
end_define

begin_define
define|#
directive|define
name|SD_SET_CARD_DETECT
value|1
end_define

begin_define
define|#
directive|define
name|SD_HS_MAX
value|50000000
end_define

begin_define
define|#
directive|define
name|SD_DDR50_MAX
value|50000000
end_define

begin_define
define|#
directive|define
name|SD_SDR12_MAX
value|25000000
end_define

begin_define
define|#
directive|define
name|SD_SDR25_MAX
value|50000000
end_define

begin_define
define|#
directive|define
name|SD_SDR50_MAX
value|100000000
end_define

begin_define
define|#
directive|define
name|SD_SDR104_MAX
value|208000000
end_define

begin_comment
comment|/* Specifications require 400 kHz max. during ID phase. */
end_comment

begin_define
define|#
directive|define
name|SD_MMC_CARD_ID_FREQUENCY
value|400000
end_define

begin_comment
comment|/*  * SDIO Direct& Extended I/O  */
end_comment

begin_define
define|#
directive|define
name|SD_IO_RW_WR
value|(1u<< 31)
end_define

begin_define
define|#
directive|define
name|SD_IO_RW_FUNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 28)
end_define

begin_define
define|#
directive|define
name|SD_IO_RW_RAW
value|(1u<< 27)
end_define

begin_define
define|#
directive|define
name|SD_IO_RW_INCR
value|(1u<< 26)
end_define

begin_define
define|#
directive|define
name|SD_IO_RW_ADR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FFFF)<< 9)
end_define

begin_define
define|#
directive|define
name|SD_IO_RW_DAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 0)
end_define

begin_define
define|#
directive|define
name|SD_IO_RW_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 0)
end_define

begin_define
define|#
directive|define
name|SD_IOE_RW_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FF)<< 0)
end_define

begin_define
define|#
directive|define
name|SD_IOE_RW_BLK
value|(1u<< 27)
end_define

begin_comment
comment|/* Card Common Control Registers (CCCR) */
end_comment

begin_define
define|#
directive|define
name|SD_IO_CCCR_START
value|0x00000
end_define

begin_define
define|#
directive|define
name|SD_IO_CCCR_SIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|SD_IO_CCCR_FN_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|SD_IO_CCCR_FN_READY
value|0x03
end_define

begin_define
define|#
directive|define
name|SD_IO_CCCR_INT_ENABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|SD_IO_CCCR_INT_PENDING
value|0x05
end_define

begin_define
define|#
directive|define
name|SD_IO_CCCR_CTL
value|0x06
end_define

begin_define
define|#
directive|define
name|CCCR_CTL_RES
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|SD_IO_CCCR_BUS_WIDTH
value|0x07
end_define

begin_define
define|#
directive|define
name|CCCR_BUS_WIDTH_4
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CCCR_BUS_WIDTH_1
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|SD_IO_CCCR_CARDCAP
value|0x08
end_define

begin_define
define|#
directive|define
name|SD_IO_CCCR_CISPTR
value|0x09
end_define

begin_comment
comment|/* XXX 9-10, 10-11, or 9-12 */
end_comment

begin_comment
comment|/* Function Basic Registers (FBR) */
end_comment

begin_define
define|#
directive|define
name|SD_IO_FBR_START
value|0x00100
end_define

begin_define
define|#
directive|define
name|SD_IO_FBR_SIZE
value|0x00700
end_define

begin_comment
comment|/* Card Information Structure (CIS) */
end_comment

begin_define
define|#
directive|define
name|SD_IO_CIS_START
value|0x01000
end_define

begin_define
define|#
directive|define
name|SD_IO_CIS_SIZE
value|0x17000
end_define

begin_comment
comment|/* CIS tuple codes (based on PC Card 16) */
end_comment

begin_define
define|#
directive|define
name|SD_IO_CISTPL_VERS_1
value|0x15
end_define

begin_define
define|#
directive|define
name|SD_IO_CISTPL_MANFID
value|0x20
end_define

begin_define
define|#
directive|define
name|SD_IO_CISTPL_FUNCID
value|0x21
end_define

begin_define
define|#
directive|define
name|SD_IO_CISTPL_FUNCE
value|0x22
end_define

begin_define
define|#
directive|define
name|SD_IO_CISTPL_END
value|0xff
end_define

begin_comment
comment|/* CISTPL_FUNCID codes */
end_comment

begin_comment
comment|/* OpenBSD incorrectly defines 0x0c as FUNCTION_WLAN */
end_comment

begin_comment
comment|/* #define SDMMC_FUNCTION_WLAN		0x0c */
end_comment

begin_comment
comment|/* OCR bits */
end_comment

begin_comment
comment|/*  * in SD 2.0 spec, bits 8-14 are now marked reserved  * Low voltage in SD2.0 spec is bit 7, TBD voltage  * Low voltage in MC 3.31 spec is bit 7, 1.65-1.95V  * Specs prior to  MMC 3.31 defined bits 0-7 as voltages down to 1.5V.  * 3.31 redefined them to be reserved and also said that cards had to  * support the 2.7-3.6V and fixed the OCR to be 0xfff8000 for high voltage  * cards.  MMC 4.0 says that a dual voltage card responds with 0xfff8080.  * Looks like the fine-grained control of the voltage tolerance ranges  * was abandoned.  *  * The MMC_OCR_CCS appears to be valid for only SD cards.  */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_VOLTAGE
value|0x3fffffffU
end_define

begin_comment
comment|/* Vdd Voltage mask */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_LOW_VOLTAGE
value|(1u<< 7)
end_define

begin_comment
comment|/* Low Voltage Range -- tbd */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_MIN_VOLTAGE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|MMC_OCR_200_210
value|(1U<< 8)
end_define

begin_comment
comment|/* Vdd voltage 2.00 ~ 2.10 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_210_220
value|(1U<< 9)
end_define

begin_comment
comment|/* Vdd voltage 2.10 ~ 2.20 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_220_230
value|(1U<< 10)
end_define

begin_comment
comment|/* Vdd voltage 2.20 ~ 2.30 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_230_240
value|(1U<< 11)
end_define

begin_comment
comment|/* Vdd voltage 2.30 ~ 2.40 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_240_250
value|(1U<< 12)
end_define

begin_comment
comment|/* Vdd voltage 2.40 ~ 2.50 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_250_260
value|(1U<< 13)
end_define

begin_comment
comment|/* Vdd voltage 2.50 ~ 2.60 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_260_270
value|(1U<< 14)
end_define

begin_comment
comment|/* Vdd voltage 2.60 ~ 2.70 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_270_280
value|(1U<< 15)
end_define

begin_comment
comment|/* Vdd voltage 2.70 ~ 2.80 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_280_290
value|(1U<< 16)
end_define

begin_comment
comment|/* Vdd voltage 2.80 ~ 2.90 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_290_300
value|(1U<< 17)
end_define

begin_comment
comment|/* Vdd voltage 2.90 ~ 3.00 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_300_310
value|(1U<< 18)
end_define

begin_comment
comment|/* Vdd voltage 3.00 ~ 3.10 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_310_320
value|(1U<< 19)
end_define

begin_comment
comment|/* Vdd voltage 3.10 ~ 3.20 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_320_330
value|(1U<< 20)
end_define

begin_comment
comment|/* Vdd voltage 3.20 ~ 3.30 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_330_340
value|(1U<< 21)
end_define

begin_comment
comment|/* Vdd voltage 3.30 ~ 3.40 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_340_350
value|(1U<< 22)
end_define

begin_comment
comment|/* Vdd voltage 3.40 ~ 3.50 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_350_360
value|(1U<< 23)
end_define

begin_comment
comment|/* Vdd voltage 3.50 ~ 3.60 */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_MAX_VOLTAGE_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|MMC_OCR_S18R
value|(1U<< 24)
end_define

begin_comment
comment|/* Switching to 1.8 V requested (SD) */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_S18A
value|MMC_OCR_S18R
end_define

begin_comment
comment|/* Switching to 1.8 V accepted (SD) */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_XPC
value|(1U<< 28)
end_define

begin_comment
comment|/* SDXC Power Control */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_ACCESS_MODE_BYTE
value|(0U<< 29)
end_define

begin_comment
comment|/* Access Mode Byte (MMC) */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_ACCESS_MODE_SECT
value|(1U<< 29)
end_define

begin_comment
comment|/* Access Mode Sector (MMC) */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_ACCESS_MODE_MASK
value|(3U<< 29)
end_define

begin_define
define|#
directive|define
name|MMC_OCR_CCS
value|(1u<< 30)
end_define

begin_comment
comment|/* Card Capacity status (SD vs SDHC) */
end_comment

begin_define
define|#
directive|define
name|MMC_OCR_CARD_BUSY
value|(1U<< 31)
end_define

begin_comment
comment|/* Card Power up status */
end_comment

begin_comment
comment|/* CSD -- decoded structure */
end_comment

begin_struct
struct|struct
name|mmc_cid
block|{
name|uint32_t
name|mid
decl_stmt|;
name|char
name|pnm
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|psn
decl_stmt|;
name|uint16_t
name|oid
decl_stmt|;
name|uint16_t
name|mdt_year
decl_stmt|;
name|uint8_t
name|mdt_month
decl_stmt|;
name|uint8_t
name|prv
decl_stmt|;
name|uint8_t
name|fwrev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mmc_csd
block|{
name|uint8_t
name|csd_structure
decl_stmt|;
name|uint8_t
name|spec_vers
decl_stmt|;
name|uint16_t
name|ccc
decl_stmt|;
name|uint16_t
name|tacc
decl_stmt|;
name|uint32_t
name|nsac
decl_stmt|;
name|uint32_t
name|r2w_factor
decl_stmt|;
name|uint32_t
name|tran_speed
decl_stmt|;
name|uint32_t
name|read_bl_len
decl_stmt|;
name|uint32_t
name|write_bl_len
decl_stmt|;
name|uint32_t
name|vdd_r_curr_min
decl_stmt|;
name|uint32_t
name|vdd_r_curr_max
decl_stmt|;
name|uint32_t
name|vdd_w_curr_min
decl_stmt|;
name|uint32_t
name|vdd_w_curr_max
decl_stmt|;
name|uint32_t
name|wp_grp_size
decl_stmt|;
name|uint32_t
name|erase_sector
decl_stmt|;
name|uint64_t
name|capacity
decl_stmt|;
name|unsigned
name|int
name|read_bl_partial
range|:
literal|1
decl_stmt|,
name|read_blk_misalign
range|:
literal|1
decl_stmt|,
name|write_bl_partial
range|:
literal|1
decl_stmt|,
name|write_blk_misalign
range|:
literal|1
decl_stmt|,
name|dsr_imp
range|:
literal|1
decl_stmt|,
name|erase_blk_en
range|:
literal|1
decl_stmt|,
name|wp_grp_enable
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mmc_scr
block|{
name|unsigned
name|char
name|sda_vsn
decl_stmt|;
name|unsigned
name|char
name|bus_widths
decl_stmt|;
define|#
directive|define
name|SD_SCR_BUS_WIDTH_1
value|(1<< 0)
define|#
directive|define
name|SD_SCR_BUS_WIDTH_4
value|(1<< 2)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mmc_sd_status
block|{
name|uint8_t
name|bus_width
decl_stmt|;
name|uint8_t
name|secured_mode
decl_stmt|;
name|uint16_t
name|card_type
decl_stmt|;
name|uint16_t
name|prot_area
decl_stmt|;
name|uint8_t
name|speed_class
decl_stmt|;
name|uint8_t
name|perf_move
decl_stmt|;
name|uint8_t
name|au_size
decl_stmt|;
name|uint16_t
name|erase_size
decl_stmt|;
name|uint8_t
name|erase_timeout
decl_stmt|;
name|uint8_t
name|erase_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Various MMC/SD constants  */
end_comment

begin_define
define|#
directive|define
name|MMC_BOOT_RPMB_BLOCK_SIZE
value|(128 * 1024)
end_define

begin_define
define|#
directive|define
name|MMC_EXTCSD_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|MMC_PART_GP_MAX
value|4
end_define

begin_define
define|#
directive|define
name|MMC_PART_MAX
value|8
end_define

begin_comment
comment|/*  * Older versions of the MMC standard had a variable sector size.  However,  * I've been able to find no old MMC or SD cards that have a non 512  * byte sector size anywhere, so we assume that such cards are very rare  * and only note their existence in passing here...  */
end_comment

begin_define
define|#
directive|define
name|MMC_SECTOR_SIZE
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_MMCREG_H */
end_comment

end_unit

