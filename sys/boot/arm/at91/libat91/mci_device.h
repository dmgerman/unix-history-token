begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This software is derived from software provide by Kwikbyte who specifically  * disclaimed copyright on the code.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|//*---------------------------------------------------------------------------
end_comment

begin_comment
comment|//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
end_comment

begin_comment
comment|//*---------------------------------------------------------------------------
end_comment

begin_comment
comment|//* The software is delivered "AS IS" without warranty or condition of any
end_comment

begin_comment
comment|//* kind, either express, implied or statutory. This includes without
end_comment

begin_comment
comment|//* limitation any warranty or condition with respect to merchantability or
end_comment

begin_comment
comment|//* fitness for any particular purpose, or against the infringements of
end_comment

begin_comment
comment|//* intellectual property rights of others.
end_comment

begin_comment
comment|//*---------------------------------------------------------------------------
end_comment

begin_comment
comment|//* File Name           : AT91C_MCI_Device.h
end_comment

begin_comment
comment|//* Object              : Data Flash Atmel Description File
end_comment

begin_comment
comment|//* Translator          :
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//* 1.0 26/11/02 FB		: Creation
end_comment

begin_comment
comment|//*---------------------------------------------------------------------------
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MCI_Device_h
end_ifndef

begin_define
define|#
directive|define
name|__MCI_Device_h
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_typedef
typedef|typedef
name|unsigned
name|int
name|AT91S_MCIDeviceStatus
typedef|;
end_typedef

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_define
define|#
directive|define
name|AT91C_CARD_REMOVED
value|0
end_define

begin_define
define|#
directive|define
name|AT91C_MMC_CARD_INSERTED
value|1
end_define

begin_define
define|#
directive|define
name|AT91C_SD_CARD_INSERTED
value|2
end_define

begin_define
define|#
directive|define
name|AT91C_NO_ARGUMENT
value|0x0
end_define

begin_define
define|#
directive|define
name|AT91C_FIRST_RCA
value|0xCAFE
end_define

begin_define
define|#
directive|define
name|AT91C_MAX_MCI_CARDS
value|10
end_define

begin_define
define|#
directive|define
name|AT91C_BUS_WIDTH_1BIT
value|0x00
end_define

begin_define
define|#
directive|define
name|AT91C_BUS_WIDTH_4BITS
value|0x02
end_define

begin_comment
comment|/* Driver State */
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_IDLE
value|0x0
end_define

begin_define
define|#
directive|define
name|AT91C_MCI_TIMEOUT_ERROR
value|0x1
end_define

begin_define
define|#
directive|define
name|AT91C_MCI_RX_SINGLE_BLOCK
value|0x2
end_define

begin_define
define|#
directive|define
name|AT91C_MCI_RX_MULTIPLE_BLOCK
value|0x3
end_define

begin_define
define|#
directive|define
name|AT91C_MCI_RX_STREAM
value|0x4
end_define

begin_define
define|#
directive|define
name|AT91C_MCI_TX_SINGLE_BLOCK
value|0x5
end_define

begin_define
define|#
directive|define
name|AT91C_MCI_TX_MULTIPLE_BLOCK
value|0x6
end_define

begin_define
define|#
directive|define
name|AT91C_MCI_TX_STREAM
value|0x7
end_define

begin_comment
comment|/* TimeOut */
end_comment

begin_define
define|#
directive|define
name|AT91C_TIMEOUT_CMDRDY
value|30
end_define

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// MMC& SDCard Structures
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|/*---------------------------------------------*/
end_comment

begin_comment
comment|/* MCI Device Structure Definition 			   */
end_comment

begin_comment
comment|/*---------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_MciDevice
block|{
specifier|volatile
name|unsigned
name|char
name|state
decl_stmt|;
name|unsigned
name|char
name|SDCard_bus_width
decl_stmt|;
name|unsigned
name|char
name|IsSDv2
decl_stmt|;
name|unsigned
name|char
name|IsSDHC
decl_stmt|;
name|unsigned
name|int
name|RCA
decl_stmt|;
comment|// RCA
name|unsigned
name|int
name|READ_BL_LEN
decl_stmt|;
ifdef|#
directive|ifdef
name|REPORT_SIZE
name|unsigned
name|int
name|Memory_Capacity
decl_stmt|;
endif|#
directive|endif
block|}
name|AT91S_MciDevice
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<dev/mmc/mmcreg.h>
end_include

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// Functions returnals
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_define
define|#
directive|define
name|AT91C_CMD_SEND_OK
value|0
end_define

begin_comment
comment|// Command ok
end_comment

begin_define
define|#
directive|define
name|AT91C_CMD_SEND_ERROR
value|-1
end_define

begin_comment
comment|// Command failed
end_comment

begin_define
define|#
directive|define
name|AT91C_INIT_OK
value|2
end_define

begin_comment
comment|// Init Successfull
end_comment

begin_define
define|#
directive|define
name|AT91C_INIT_ERROR
value|3
end_define

begin_comment
comment|// Init Failed
end_comment

begin_define
define|#
directive|define
name|AT91C_READ_OK
value|4
end_define

begin_comment
comment|// Read Successfull
end_comment

begin_define
define|#
directive|define
name|AT91C_READ_ERROR
value|5
end_define

begin_comment
comment|// Read Failed
end_comment

begin_define
define|#
directive|define
name|AT91C_WRITE_OK
value|6
end_define

begin_comment
comment|// Write Successfull
end_comment

begin_define
define|#
directive|define
name|AT91C_WRITE_ERROR
value|7
end_define

begin_comment
comment|// Write Failed
end_comment

begin_define
define|#
directive|define
name|AT91C_ERASE_OK
value|8
end_define

begin_comment
comment|// Erase Successfull
end_comment

begin_define
define|#
directive|define
name|AT91C_ERASE_ERROR
value|9
end_define

begin_comment
comment|// Erase Failed
end_comment

begin_define
define|#
directive|define
name|AT91C_CARD_SELECTED_OK
value|10
end_define

begin_comment
comment|// Card Selection Successfull
end_comment

begin_define
define|#
directive|define
name|AT91C_CARD_SELECTED_ERROR
value|11
end_define

begin_comment
comment|// Card Selection Failed
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SR_ERROR
value|(AT91C_MCI_UNRE | AT91C_MCI_OVRE | AT91C_MCI_DTOE | \ 	AT91C_MCI_DCRCE | AT91C_MCI_RTOE | AT91C_MCI_RENDE | AT91C_MCI_RCRCE | \ 	AT91C_MCI_RDIRE | AT91C_MCI_RINDE)
end_define

begin_define
define|#
directive|define
name|MMC_CMDNB
value|(0x1Fu<<  0)
end_define

begin_comment
comment|// Command Number
end_comment

begin_define
define|#
directive|define
name|MMC_RSPTYP
value|(0x3u<<  6)
end_define

begin_comment
comment|// Response Type
end_comment

begin_define
define|#
directive|define
name|MMC_RSPTYP_NO
value|(0x0u<<  6)
end_define

begin_comment
comment|// No response
end_comment

begin_define
define|#
directive|define
name|MMC_RSPTYP_48
value|(0x1u<<  6)
end_define

begin_comment
comment|// 48-bit response
end_comment

begin_define
define|#
directive|define
name|MMC_RSPTYP_136
value|(0x2u<<  6)
end_define

begin_comment
comment|// 136-bit response
end_comment

begin_define
define|#
directive|define
name|MMC_SPCMD
value|(0x7u<<  8)
end_define

begin_comment
comment|// Special CMD
end_comment

begin_define
define|#
directive|define
name|MMC_SPCMD_NONE
value|(0x0u<<  8)
end_define

begin_comment
comment|// Not a special CMD
end_comment

begin_define
define|#
directive|define
name|MMC_SPCMD_INIT
value|(0x1u<<  8)
end_define

begin_comment
comment|// Initialization CMD
end_comment

begin_define
define|#
directive|define
name|MMC_SPCMD_SYNC
value|(0x2u<<  8)
end_define

begin_comment
comment|// Synchronized CMD
end_comment

begin_define
define|#
directive|define
name|MMC_SPCMD_IT_CMD
value|(0x4u<<  8)
end_define

begin_comment
comment|// Interrupt command
end_comment

begin_define
define|#
directive|define
name|MMC_SPCMD_IT_REP
value|(0x5u<<  8)
end_define

begin_comment
comment|// Interrupt response
end_comment

begin_define
define|#
directive|define
name|MMC_OPDCMD
value|(0x1u<< 11)
end_define

begin_comment
comment|// Open Drain Command
end_comment

begin_define
define|#
directive|define
name|MMC_MAXLAT
value|(0x1u<< 12)
end_define

begin_comment
comment|// Maximum Latency for Command to respond
end_comment

begin_define
define|#
directive|define
name|MMC_TRCMD
value|(0x3u<< 16)
end_define

begin_comment
comment|// Transfer CMD
end_comment

begin_define
define|#
directive|define
name|MMC_TRCMD_NO
value|(0x0u<< 16)
end_define

begin_comment
comment|// No transfer
end_comment

begin_define
define|#
directive|define
name|MMC_TRCMD_START
value|(0x1u<< 16)
end_define

begin_comment
comment|// Start transfer
end_comment

begin_define
define|#
directive|define
name|MMC_TRCMD_STOP
value|(0x2u<< 16)
end_define

begin_comment
comment|// Stop transfer
end_comment

begin_define
define|#
directive|define
name|MMC_TRDIR
value|(0x1u<< 18)
end_define

begin_comment
comment|// Transfer Direction
end_comment

begin_define
define|#
directive|define
name|MMC_TRTYP
value|(0x3u<< 19)
end_define

begin_comment
comment|// Transfer Type
end_comment

begin_define
define|#
directive|define
name|MMC_TRTYP_BLOCK
value|(0x0u<< 19)
end_define

begin_comment
comment|// Block Transfer type
end_comment

begin_define
define|#
directive|define
name|MMC_TRTYP_MULTIPLE
value|(0x1u<< 19)
end_define

begin_comment
comment|// Multiple Block transfer type
end_comment

begin_define
define|#
directive|define
name|MMC_TRTYP_STREAM
value|(0x2u<< 19)
end_define

begin_comment
comment|// Stream transfer type
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// MCI_CMD Register Value
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_define
define|#
directive|define
name|POWER_ON_INIT
define|\
value|(0 | MMC_TRCMD_NO | MMC_SPCMD_INIT | MMC_OPDCMD)
end_define

begin_comment
comment|/////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// Class 0& 1 commands: Basic commands and Read Stream commands
end_comment

begin_comment
comment|/////////////////////////////////////////////////////////////////
end_comment

begin_define
define|#
directive|define
name|GO_IDLE_STATE_CMD
define|\
value|(0 | MMC_TRCMD_NO | MMC_SPCMD_NONE )
end_define

begin_define
define|#
directive|define
name|MMC_GO_IDLE_STATE_CMD
define|\
value|(0 | MMC_TRCMD_NO | MMC_SPCMD_NONE | MMC_OPDCMD)
end_define

begin_define
define|#
directive|define
name|MMC_SEND_OP_COND_CMD
define|\
value|(1 | MMC_TRCMD_NO | MMC_SPCMD_NONE | MMC_RSPTYP_48 | \      MMC_OPDCMD)
end_define

begin_define
define|#
directive|define
name|ALL_SEND_CID_CMD
define|\
value|(2 | MMC_TRCMD_NO | MMC_SPCMD_NONE | MMC_RSPTYP_136)
end_define

begin_define
define|#
directive|define
name|MMC_ALL_SEND_CID_CMD
define|\
value|(2 | MMC_TRCMD_NO | MMC_SPCMD_NONE | MMC_RSPTYP_136 | \     MMC_OPDCMD)
end_define

begin_define
define|#
directive|define
name|SET_RELATIVE_ADDR_CMD
define|\
value|(3 | MMC_TRCMD_NO | MMC_SPCMD_NONE | MMC_RSPTYP_48 | \      MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|MMC_SET_RELATIVE_ADDR_CMD
define|\
value|(3 | MMC_TRCMD_NO | MMC_SPCMD_NONE | MMC_RSPTYP_48 | \      MMC_MAXLAT | MMC_OPDCMD)
end_define

begin_define
define|#
directive|define
name|SET_DSR_CMD
define|\
value|(4 | MMC_TRCMD_NO | MMC_SPCMD_NONE | MMC_RSPTYP_NO | \      MMC_MAXLAT)
end_define

begin_comment
comment|// no tested
end_comment

begin_define
define|#
directive|define
name|SEL_DESEL_CARD_CMD
define|\
value|(7 | MMC_TRCMD_NO | MMC_SPCMD_NONE | MMC_RSPTYP_48 | \      MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|SEND_CSD_CMD
define|\
value|(9 | MMC_TRCMD_NO | MMC_SPCMD_NONE | MMC_RSPTYP_136 | \      MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|SEND_CID_CMD
define|\
value|(10 | MMC_TRCMD_NO | MMC_SPCMD_NONE | MMC_RSPTYP_136 | \      MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|MMC_READ_DAT_UNTIL_STOP_CMD
define|\
value|(11 | MMC_TRTYP_STREAM | MMC_SPCMD_NONE | \      MMC_RSPTYP_48 | MMC_TRDIR | MMC_TRCMD_START | \      MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|STOP_TRANSMISSION_CMD
define|\
value|(12 | MMC_TRCMD_STOP | MMC_SPCMD_NONE | MMC_RSPTYP_48 | \      MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|STOP_TRANSMISSION_SYNC_CMD
define|\
value|(12 | MMC_TRCMD_STOP | MMC_SPCMD_SYNC | MMC_RSPTYP_48 | \      MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|SEND_STATUS_CMD
define|\
value|(13 | MMC_TRCMD_NO | MMC_SPCMD_NONE | MMC_RSPTYP_48 | \      MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|GO_INACTIVE_STATE_CMD
define|\
value|(15 | MMC_RSPTYP_NO)
end_define

begin_define
define|#
directive|define
name|SD_SEND_IF_COND_CMD
define|\
value|(8 | MMC_TRCMD_NO | MMC_SPCMD_NONE | MMC_RSPTYP_48 | \      MMC_MAXLAT)
end_define

begin_comment
comment|//*------------------------------------------------
end_comment

begin_comment
comment|//* Class 2 commands: Block oriented Read commands
end_comment

begin_comment
comment|//*------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|SET_BLOCKLEN_CMD
value|(16 | MMC_TRCMD_NO 	| MMC_SPCMD_NONE	| MMC_RSPTYP_48		| MMC_MAXLAT )
end_define

begin_define
define|#
directive|define
name|READ_SINGLE_BLOCK_CMD
value|(17 | MMC_SPCMD_NONE	| MMC_RSPTYP_48 	| MMC_TRCMD_START	| MMC_TRTYP_BLOCK	| MMC_TRDIR	| MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|READ_MULTIPLE_BLOCK_CMD
value|(18 | MMC_SPCMD_NONE	| MMC_RSPTYP_48 	| MMC_TRCMD_START	| MMC_TRTYP_MULTIPLE	| MMC_TRDIR	| MMC_MAXLAT)
end_define

begin_comment
comment|//*--------------------------------------------
end_comment

begin_comment
comment|//* Class 3 commands: Sequential write commands
end_comment

begin_comment
comment|//*--------------------------------------------
end_comment

begin_define
define|#
directive|define
name|MMC_WRITE_DAT_UNTIL_STOP_CMD
value|(20 | MMC_TRTYP_STREAM| MMC_SPCMD_NONE	| MMC_RSPTYP_48& ~(MMC_TRDIR) | MMC_TRCMD_START | MMC_MAXLAT )
end_define

begin_comment
comment|// MMC
end_comment

begin_comment
comment|//*------------------------------------------------
end_comment

begin_comment
comment|//* Class 4 commands: Block oriented write commands
end_comment

begin_comment
comment|//*------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|WRITE_BLOCK_CMD
value|(24 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_START	| (MMC_TRTYP_BLOCK&  ~(MMC_TRDIR))	| MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|WRITE_MULTIPLE_BLOCK_CMD
value|(25 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_START	| (MMC_TRTYP_MULTIPLE&  ~(MMC_TRDIR)) 	| MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|PROGRAM_CSD_CMD
value|(27 | MMC_RSPTYP_48 )
end_define

begin_comment
comment|//*----------------------------------------
end_comment

begin_comment
comment|//* Class 6 commands: Group Write protect
end_comment

begin_comment
comment|//*----------------------------------------
end_comment

begin_define
define|#
directive|define
name|SET_WRITE_PROT_CMD
value|(28	| MMC_RSPTYP_48 )
end_define

begin_define
define|#
directive|define
name|CLR_WRITE_PROT_CMD
value|(29	| MMC_RSPTYP_48 )
end_define

begin_define
define|#
directive|define
name|SEND_WRITE_PROT_CMD
value|(30	| MMC_RSPTYP_48 )
end_define

begin_comment
comment|//*----------------------------------------
end_comment

begin_comment
comment|//* Class 5 commands: Erase commands
end_comment

begin_comment
comment|//*----------------------------------------
end_comment

begin_define
define|#
directive|define
name|TAG_SECTOR_START_CMD
value|(32 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_NO	| MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|TAG_SECTOR_END_CMD
value|(33 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_NO	| MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|MMC_UNTAG_SECTOR_CMD
value|(34 | MMC_RSPTYP_48 )
end_define

begin_define
define|#
directive|define
name|MMC_TAG_ERASE_GROUP_START_CMD
value|(35 | MMC_RSPTYP_48 )
end_define

begin_define
define|#
directive|define
name|MMC_TAG_ERASE_GROUP_END_CMD
value|(36 | MMC_RSPTYP_48 )
end_define

begin_define
define|#
directive|define
name|MMC_UNTAG_ERASE_GROUP_CMD
value|(37 | MMC_RSPTYP_48 )
end_define

begin_define
define|#
directive|define
name|ERASE_CMD
value|(38 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_NO	| MMC_MAXLAT )
end_define

begin_comment
comment|//*----------------------------------------
end_comment

begin_comment
comment|//* Class 7 commands: Lock commands
end_comment

begin_comment
comment|//*----------------------------------------
end_comment

begin_define
define|#
directive|define
name|LOCK_UNLOCK
value|(42 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_NO	| MMC_MAXLAT)
end_define

begin_comment
comment|// no tested
end_comment

begin_comment
comment|//*-----------------------------------------------
end_comment

begin_comment
comment|// Class 8 commands: Application specific commands
end_comment

begin_comment
comment|//*-----------------------------------------------
end_comment

begin_define
define|#
directive|define
name|APP_CMD
value|(55 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_NO | MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|GEN_CMD
value|(56 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_NO | MMC_MAXLAT)
end_define

begin_comment
comment|// no tested
end_comment

begin_define
define|#
directive|define
name|SDCARD_SET_BUS_WIDTH_CMD
value|(6 	| MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_NO	| MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|SDCARD_STATUS_CMD
value|(13 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_NO	| MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|SDCARD_SEND_NUM_WR_BLOCKS_CMD
value|(22 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_NO	| MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|SDCARD_SET_WR_BLK_ERASE_COUNT_CMD
value|(23 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_NO	| MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|SDCARD_APP_OP_COND_CMD
value|(41 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_NO | MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|SDCARD_SET_CLR_CARD_DETECT_CMD
value|(42 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_NO	| MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|SDCARD_SEND_SCR_CMD
value|(51 | MMC_SPCMD_NONE	| MMC_RSPTYP_48	| MMC_TRCMD_NO	| MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|SDCARD_APP_ALL_CMD
value|(SDCARD_SET_BUS_WIDTH_CMD +\ 												SDCARD_STATUS_CMD +\ 												SDCARD_SEND_NUM_WR_BLOCKS_CMD +\ 												SDCARD_SET_WR_BLK_ERASE_COUNT_CMD +\ 												SDCARD_APP_OP_COND_CMD +\ 												SDCARD_SET_CLR_CARD_DETECT_CMD +\ 												SDCARD_SEND_SCR_CMD)
end_define

begin_comment
comment|//*----------------------------------------
end_comment

begin_comment
comment|//* Class 9 commands: IO Mode commands
end_comment

begin_comment
comment|//*----------------------------------------
end_comment

begin_define
define|#
directive|define
name|MMC_FAST_IO_CMD
value|(39 | MMC_SPCMD_NONE | MMC_RSPTYP_48 | MMC_MAXLAT)
end_define

begin_define
define|#
directive|define
name|MMC_GO_IRQ_STATE_CMD
value|(40 | MMC_SPCMD_NONE | MMC_RSPTYP_48 | MMC_TRCMD_NO	| MMC_MAXLAT)
end_define

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// OCR Register
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_define
define|#
directive|define
name|AT91C_VDD_16_17
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_17_18
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_18_19
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_19_20
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_20_21
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_21_22
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_22_23
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_23_24
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_24_25
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_25_26
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_26_27
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_27_28
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_28_29
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_29_30
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_30_31
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_31_32
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_32_33
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_33_34
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_34_35
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AT91C_VDD_35_36
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AT91C_CCS
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|AT91C_CARD_POWER_UP_DONE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|AT91C_MMC_HOST_VOLTAGE_RANGE
value|(AT91C_VDD_27_28 | AT91C_VDD_28_29  | \     AT91C_VDD_29_30 | AT91C_VDD_30_31 | AT91C_VDD_31_32 | AT91C_VDD_32_33)
end_define

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// CURRENT_STATE& READY_FOR_DATA in SDCard Status Register definition (response type R1)
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_define
define|#
directive|define
name|AT91C_SR_READY_FOR_DATA
value|(1<< 8)
end_define

begin_comment
comment|// corresponds to buffer empty signalling on the bus
end_comment

begin_define
define|#
directive|define
name|AT91C_SR_IDLE
value|(0<< 9)
end_define

begin_define
define|#
directive|define
name|AT91C_SR_READY
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AT91C_SR_IDENT
value|(2<< 9)
end_define

begin_define
define|#
directive|define
name|AT91C_SR_STBY
value|(3<< 9)
end_define

begin_define
define|#
directive|define
name|AT91C_SR_TRAN
value|(4<< 9)
end_define

begin_define
define|#
directive|define
name|AT91C_SR_DATA
value|(5<< 9)
end_define

begin_define
define|#
directive|define
name|AT91C_SR_RCV
value|(6<< 9)
end_define

begin_define
define|#
directive|define
name|AT91C_SR_PRG
value|(7<< 9)
end_define

begin_define
define|#
directive|define
name|AT91C_SR_DIS
value|(8<< 9)
end_define

begin_define
define|#
directive|define
name|AT91C_SR_CARD_SELECTED
value|(AT91C_SR_READY_FOR_DATA + AT91C_SR_TRAN)
end_define

begin_define
define|#
directive|define
name|MMC_FIRST_RCA
value|0xCAFE
end_define

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// MMC CSD register header File
end_comment

begin_comment
comment|// CSD_x_xxx_S	for shift value for word x
end_comment

begin_comment
comment|// CSD_x_xxx_M	for mask  value for word x
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// First Response INT<=> CSD[3] : bits 0 to 31
end_comment

begin_define
define|#
directive|define
name|CSD_3_BIT0_S
value|0
end_define

begin_comment
comment|// [0:0]
end_comment

begin_define
define|#
directive|define
name|CSD_3_BIT0_M
value|0x01
end_define

begin_define
define|#
directive|define
name|CSD_3_CRC_S
value|1
end_define

begin_comment
comment|// [7:1]
end_comment

begin_define
define|#
directive|define
name|CSD_3_CRC_M
value|0x7F
end_define

begin_define
define|#
directive|define
name|CSD_3_MMC_ECC_S
value|8
end_define

begin_comment
comment|// [9:8] reserved for MMC compatibility
end_comment

begin_define
define|#
directive|define
name|CSD_3_MMC_ECC_M
value|0x03
end_define

begin_define
define|#
directive|define
name|CSD_3_FILE_FMT_S
value|10
end_define

begin_comment
comment|// [11:10]
end_comment

begin_define
define|#
directive|define
name|CSD_3_FILE_FMT_M
value|0x03
end_define

begin_define
define|#
directive|define
name|CSD_3_TMP_WP_S
value|12
end_define

begin_comment
comment|// [12:12]
end_comment

begin_define
define|#
directive|define
name|CSD_3_TMP_WP_M
value|0x01
end_define

begin_define
define|#
directive|define
name|CSD_3_PERM_WP_S
value|13
end_define

begin_comment
comment|// [13:13]
end_comment

begin_define
define|#
directive|define
name|CSD_3_PERM_WP_M
value|0x01
end_define

begin_define
define|#
directive|define
name|CSD_3_COPY_S
value|14
end_define

begin_comment
comment|// [14:14]
end_comment

begin_define
define|#
directive|define
name|CSD_3_COPY_M
value|0x01
end_define

begin_define
define|#
directive|define
name|CSD_3_FILE_FMT_GRP_S
value|15
end_define

begin_comment
comment|// [15:15]
end_comment

begin_define
define|#
directive|define
name|CSD_3_FILE_FMT_GRP_M
value|0x01
end_define

begin_comment
comment|//	reserved		16		// [20:16]
end_comment

begin_comment
comment|//	reserved		0x1F
end_comment

begin_define
define|#
directive|define
name|CSD_3_WBLOCK_P_S
value|21
end_define

begin_comment
comment|// [21:21]
end_comment

begin_define
define|#
directive|define
name|CSD_3_WBLOCK_P_M
value|0x01
end_define

begin_define
define|#
directive|define
name|CSD_3_WBLEN_S
value|22
end_define

begin_comment
comment|// [25:22]
end_comment

begin_define
define|#
directive|define
name|CSD_3_WBLEN_M
value|0x0F
end_define

begin_define
define|#
directive|define
name|CSD_3_R2W_F_S
value|26
end_define

begin_comment
comment|// [28:26]
end_comment

begin_define
define|#
directive|define
name|CSD_3_R2W_F_M
value|0x07
end_define

begin_define
define|#
directive|define
name|CSD_3_MMC_DEF_ECC_S
value|29
end_define

begin_comment
comment|// [30:29] reserved for MMC compatibility
end_comment

begin_define
define|#
directive|define
name|CSD_3_MMC_DEF_ECC_M
value|0x03
end_define

begin_define
define|#
directive|define
name|CSD_3_WP_GRP_EN_S
value|31
end_define

begin_comment
comment|// [31:31]
end_comment

begin_define
define|#
directive|define
name|CSD_3_WP_GRP_EN_M
value|0x01
end_define

begin_comment
comment|// Seconde Response INT<=> CSD[2] : bits 32 to 63
end_comment

begin_define
define|#
directive|define
name|CSD_2_v21_WP_GRP_SIZE_S
value|0
end_define

begin_comment
comment|// [38:32]
end_comment

begin_define
define|#
directive|define
name|CSD_2_v21_WP_GRP_SIZE_M
value|0x7F
end_define

begin_define
define|#
directive|define
name|CSD_2_v21_SECT_SIZE_S
value|7
end_define

begin_comment
comment|// [45:39]
end_comment

begin_define
define|#
directive|define
name|CSD_2_v21_SECT_SIZE_M
value|0x7F
end_define

begin_define
define|#
directive|define
name|CSD_2_v21_ER_BLEN_EN_S
value|14
end_define

begin_comment
comment|// [46:46]
end_comment

begin_define
define|#
directive|define
name|CSD_2_v21_ER_BLEN_EN_M
value|0x01
end_define

begin_define
define|#
directive|define
name|CSD_2_v22_WP_GRP_SIZE_S
value|0
end_define

begin_comment
comment|// [36:32]
end_comment

begin_define
define|#
directive|define
name|CSD_2_v22_WP_GRP_SIZE_M
value|0x1F
end_define

begin_define
define|#
directive|define
name|CSD_2_v22_ER_GRP_SIZE_S
value|5
end_define

begin_comment
comment|// [41:37]
end_comment

begin_define
define|#
directive|define
name|CSD_2_v22_ER_GRP_SIZE_M
value|0x1F
end_define

begin_define
define|#
directive|define
name|CSD_2_v22_SECT_SIZE_S
value|10
end_define

begin_comment
comment|// [46:42]
end_comment

begin_define
define|#
directive|define
name|CSD_2_v22_SECT_SIZE_M
value|0x1F
end_define

begin_define
define|#
directive|define
name|CSD_2_C_SIZE_M_S
value|15
end_define

begin_comment
comment|// [49:47]
end_comment

begin_define
define|#
directive|define
name|CSD_2_C_SIZE_M_M
value|0x07
end_define

begin_define
define|#
directive|define
name|CSD_2_VDD_WMAX_S
value|18
end_define

begin_comment
comment|// [52:50]
end_comment

begin_define
define|#
directive|define
name|CSD_2_VDD_WMAX_M
value|0x07
end_define

begin_define
define|#
directive|define
name|CSD_2_VDD_WMIN_S
value|21
end_define

begin_comment
comment|// [55:53]
end_comment

begin_define
define|#
directive|define
name|CSD_2_VDD_WMIN_M
value|0x07
end_define

begin_define
define|#
directive|define
name|CSD_2_RCUR_MAX_S
value|24
end_define

begin_comment
comment|// [58:56]
end_comment

begin_define
define|#
directive|define
name|CSD_2_RCUR_MAX_M
value|0x07
end_define

begin_define
define|#
directive|define
name|CSD_2_RCUR_MIN_S
value|27
end_define

begin_comment
comment|// [61:59]
end_comment

begin_define
define|#
directive|define
name|CSD_2_RCUR_MIN_M
value|0x07
end_define

begin_define
define|#
directive|define
name|CSD_2_CSIZE_L_S
value|30
end_define

begin_comment
comment|// [63:62]<=> 2 LSB of CSIZE
end_comment

begin_define
define|#
directive|define
name|CSD_2_CSIZE_L_M
value|0x03
end_define

begin_comment
comment|// Third Response INT<=> CSD[1] : bits 64 to 95
end_comment

begin_define
define|#
directive|define
name|CSD_1_CSIZE_H_S
value|0
end_define

begin_comment
comment|// [73:64]<=> 10 MSB of CSIZE
end_comment

begin_define
define|#
directive|define
name|CSD_1_CSIZE_H_M
value|0x03FF
end_define

begin_comment
comment|// reserved			10		// [75:74]
end_comment

begin_comment
comment|// reserved			0x03
end_comment

begin_define
define|#
directive|define
name|CSD_1_DSR_I_S
value|12
end_define

begin_comment
comment|// [76:76]
end_comment

begin_define
define|#
directive|define
name|CSD_1_DSR_I_M
value|0x01
end_define

begin_define
define|#
directive|define
name|CSD_1_RD_B_MIS_S
value|13
end_define

begin_comment
comment|// [77:77]
end_comment

begin_define
define|#
directive|define
name|CSD_1_RD_B_MIS_M
value|0x01
end_define

begin_define
define|#
directive|define
name|CSD_1_WR_B_MIS_S
value|14
end_define

begin_comment
comment|// [78:78]
end_comment

begin_define
define|#
directive|define
name|CSD_1_WR_B_MIS_M
value|0x01
end_define

begin_define
define|#
directive|define
name|CSD_1_RD_B_PAR_S
value|15
end_define

begin_comment
comment|// [79:79]
end_comment

begin_define
define|#
directive|define
name|CSD_1_RD_B_PAR_M
value|0x01
end_define

begin_define
define|#
directive|define
name|CSD_1_RD_B_LEN_S
value|16
end_define

begin_comment
comment|// [83:80]
end_comment

begin_define
define|#
directive|define
name|CSD_1_RD_B_LEN_M
value|0x0F
end_define

begin_define
define|#
directive|define
name|CSD_1_CCC_S
value|20
end_define

begin_comment
comment|// [95:84]
end_comment

begin_define
define|#
directive|define
name|CSD_1_CCC_M
value|0x0FFF
end_define

begin_comment
comment|// Fourth Response INT<=> CSD[0] : bits 96 to 127
end_comment

begin_define
define|#
directive|define
name|CSD_0_TRANS_SPEED_S
value|0
end_define

begin_comment
comment|// [103:96]
end_comment

begin_define
define|#
directive|define
name|CSD_0_TRANS_SPEED_M
value|0xFF
end_define

begin_define
define|#
directive|define
name|CSD_0_NSAC_S
value|8
end_define

begin_comment
comment|// [111:104]
end_comment

begin_define
define|#
directive|define
name|CSD_0_NSAC_M
value|0xFF
end_define

begin_define
define|#
directive|define
name|CSD_0_TAAC_S
value|16
end_define

begin_comment
comment|// [119:112]
end_comment

begin_define
define|#
directive|define
name|CSD_0_TAAC_M
value|0xFF
end_define

begin_comment
comment|//	reserved		24		// [121:120]
end_comment

begin_comment
comment|//	reserved		0x03
end_comment

begin_define
define|#
directive|define
name|CSD_0_MMC_SPEC_VERS_S
value|26
end_define

begin_comment
comment|// [125:122]	reserved for MMC compatibility
end_comment

begin_define
define|#
directive|define
name|CSD_0_MMC_SPEC_VERS_M
value|0x0F
end_define

begin_define
define|#
directive|define
name|CSD_0_STRUCT_S
value|30
end_define

begin_comment
comment|// [127:126]
end_comment

begin_define
define|#
directive|define
name|CSD_0_STRUCT_M
value|0x03
end_define

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

