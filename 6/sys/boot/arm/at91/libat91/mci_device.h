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

begin_typedef
typedef|typedef
name|unsigned
name|int
name|AT91S_MCIDeviceStatus
typedef|;
end_typedef

begin_comment
comment|/////////////////////////////////////////////////////////////////////////////////////////////////////
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
comment|/////////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// MMC& SDCard Structures
end_comment

begin_comment
comment|/////////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|/*-----------------------------------------------*/
end_comment

begin_comment
comment|/* SDCard Device Descriptor Structure Definition */
end_comment

begin_comment
comment|/*-----------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_MciDeviceDesc
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
block|}
name|AT91S_MciDeviceDesc
operator|,
typedef|*
name|AT91PS_MciDeviceDesc
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------*/
end_comment

begin_comment
comment|/* MMC& SDCard Structure Device Features	   */
end_comment

begin_comment
comment|/*---------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AT91S_MciDeviceFeatures
block|{
name|unsigned
name|char
name|Card_Inserted
decl_stmt|;
comment|// (0=AT91C_CARD_REMOVED) (1=AT91C_MMC_CARD_INSERTED) (2=AT91C_SD_CARD_INSERTED)
name|unsigned
name|int
name|Relative_Card_Address
decl_stmt|;
comment|// RCA
name|unsigned
name|int
name|READ_BL_LEN
decl_stmt|;
name|unsigned
name|int
name|WRITE_BL_LEN
decl_stmt|;
name|unsigned
name|int
name|Max_Read_DataBlock_Length
decl_stmt|;
comment|// 2^(READ_BL_LEN) in CSD
name|unsigned
name|int
name|Max_Write_DataBlock_Length
decl_stmt|;
comment|// 2^(WRITE_BL_LEN) in CSD
name|unsigned
name|char
name|Read_Partial
decl_stmt|;
comment|// READ_BL_PARTIAL
name|unsigned
name|char
name|Write_Partial
decl_stmt|;
comment|// WRITE_BL_PARTIAL
name|unsigned
name|char
name|Erase_Block_Enable
decl_stmt|;
comment|// ERASE_BLK_EN
name|unsigned
name|char
name|Read_Block_Misalignment
decl_stmt|;
comment|// READ_BLK_MISALIGN
name|unsigned
name|char
name|Write_Block_Misalignment
decl_stmt|;
comment|// WRITE_BLK_MISALIGN
name|unsigned
name|char
name|Sector_Size
decl_stmt|;
comment|// SECTOR_SIZE
name|unsigned
name|int
name|Memory_Capacity
decl_stmt|;
comment|// Size in bits of the device
block|}
name|AT91S_MciDeviceFeatures
operator|,
typedef|*
name|AT91PS_MciDeviceFeatures
typedef|;
end_typedef

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
name|AT91PS_MciDeviceDesc
name|pMCI_DeviceDesc
decl_stmt|;
comment|// MCI device descriptor
name|AT91PS_MciDeviceFeatures
name|pMCI_DeviceFeatures
decl_stmt|;
comment|// Pointer on a MCI device features array
block|}
name|AT91S_MciDevice
operator|,
typedef|*
name|AT91PS_MciDevice
typedef|;
end_typedef

begin_comment
comment|/////////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// MCI_CMD Register Value
end_comment

begin_comment
comment|/////////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_define
define|#
directive|define
name|AT91C_POWER_ON_INIT
value|(0	| AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_INIT | AT91C_MCI_OPDCMD)
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
name|AT91C_GO_IDLE_STATE_CMD
value|(0 	| AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_NONE )
end_define

begin_define
define|#
directive|define
name|AT91C_MMC_GO_IDLE_STATE_CMD
value|(0 	| AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_NONE  | AT91C_MCI_OPDCMD)
end_define

begin_define
define|#
directive|define
name|AT91C_MMC_SEND_OP_COND_CMD
value|(1	| AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48 | AT91C_MCI_OPDCMD)
end_define

begin_define
define|#
directive|define
name|AT91C_ALL_SEND_CID_CMD
value|(2	| AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_136 )
end_define

begin_define
define|#
directive|define
name|AT91C_MMC_ALL_SEND_CID_CMD
value|(2	| AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_136 | AT91C_MCI_OPDCMD)
end_define

begin_define
define|#
directive|define
name|AT91C_SET_RELATIVE_ADDR_CMD
value|(3	| AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48		| AT91C_MCI_MAXLAT )
end_define

begin_define
define|#
directive|define
name|AT91C_MMC_SET_RELATIVE_ADDR_CMD
value|(3	| AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48		| AT91C_MCI_MAXLAT | AT91C_MCI_OPDCMD)
end_define

begin_define
define|#
directive|define
name|AT91C_SET_DSR_CMD
value|(4	| AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_NO		| AT91C_MCI_MAXLAT )
end_define

begin_comment
comment|// no tested
end_comment

begin_define
define|#
directive|define
name|AT91C_SEL_DESEL_CARD_CMD
value|(7	| AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48  		| AT91C_MCI_MAXLAT )
end_define

begin_define
define|#
directive|define
name|AT91C_SEND_CSD_CMD
value|(9	| AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_136 		| AT91C_MCI_MAXLAT )
end_define

begin_define
define|#
directive|define
name|AT91C_SEND_CID_CMD
value|(10	| AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_136 		| AT91C_MCI_MAXLAT )
end_define

begin_define
define|#
directive|define
name|AT91C_MMC_READ_DAT_UNTIL_STOP_CMD
value|(11	| AT91C_MCI_TRTYP_STREAM| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRDIR	| AT91C_MCI_TRCMD_START | AT91C_MCI_MAXLAT )
end_define

begin_define
define|#
directive|define
name|AT91C_STOP_TRANSMISSION_CMD
value|(12	| AT91C_MCI_TRCMD_STOP 	| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48 		| AT91C_MCI_MAXLAT )
end_define

begin_define
define|#
directive|define
name|AT91C_STOP_TRANSMISSION_SYNC_CMD
value|(12	| AT91C_MCI_TRCMD_STOP 	| AT91C_MCI_SPCMD_SYNC	| AT91C_MCI_RSPTYP_48 		| AT91C_MCI_MAXLAT )
end_define

begin_define
define|#
directive|define
name|AT91C_SEND_STATUS_CMD
value|(13	| AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48 		| AT91C_MCI_MAXLAT )
end_define

begin_define
define|#
directive|define
name|AT91C_GO_INACTIVE_STATE_CMD
value|(15	| AT91C_MCI_RSPTYP_NO )
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
name|AT91C_SET_BLOCKLEN_CMD
value|(16 | AT91C_MCI_TRCMD_NO 	| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48		| AT91C_MCI_MAXLAT )
end_define

begin_define
define|#
directive|define
name|AT91C_READ_SINGLE_BLOCK_CMD
value|(17 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48 	| AT91C_MCI_TRCMD_START	| AT91C_MCI_TRTYP_BLOCK	| AT91C_MCI_TRDIR	| AT91C_MCI_MAXLAT)
end_define

begin_define
define|#
directive|define
name|AT91C_READ_MULTIPLE_BLOCK_CMD
value|(18 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48 	| AT91C_MCI_TRCMD_START	| AT91C_MCI_TRTYP_MULTIPLE	| AT91C_MCI_TRDIR	| AT91C_MCI_MAXLAT)
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
name|AT91C_MMC_WRITE_DAT_UNTIL_STOP_CMD
value|(20 | AT91C_MCI_TRTYP_STREAM| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48& ~(AT91C_MCI_TRDIR) | AT91C_MCI_TRCMD_START | AT91C_MCI_MAXLAT )
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
name|AT91C_WRITE_BLOCK_CMD
value|(24 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_START	| (AT91C_MCI_TRTYP_BLOCK&  ~(AT91C_MCI_TRDIR))	| AT91C_MCI_MAXLAT)
end_define

begin_define
define|#
directive|define
name|AT91C_WRITE_MULTIPLE_BLOCK_CMD
value|(25 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_START	| (AT91C_MCI_TRTYP_MULTIPLE&  ~(AT91C_MCI_TRDIR)) 	| AT91C_MCI_MAXLAT)
end_define

begin_define
define|#
directive|define
name|AT91C_PROGRAM_CSD_CMD
value|(27 | AT91C_MCI_RSPTYP_48 )
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
name|AT91C_SET_WRITE_PROT_CMD
value|(28	| AT91C_MCI_RSPTYP_48 )
end_define

begin_define
define|#
directive|define
name|AT91C_CLR_WRITE_PROT_CMD
value|(29	| AT91C_MCI_RSPTYP_48 )
end_define

begin_define
define|#
directive|define
name|AT91C_SEND_WRITE_PROT_CMD
value|(30	| AT91C_MCI_RSPTYP_48 )
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
name|AT91C_TAG_SECTOR_START_CMD
value|(32 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_NO	| AT91C_MCI_MAXLAT)
end_define

begin_define
define|#
directive|define
name|AT91C_TAG_SECTOR_END_CMD
value|(33 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_NO	| AT91C_MCI_MAXLAT)
end_define

begin_define
define|#
directive|define
name|AT91C_MMC_UNTAG_SECTOR_CMD
value|(34 | AT91C_MCI_RSPTYP_48 )
end_define

begin_define
define|#
directive|define
name|AT91C_MMC_TAG_ERASE_GROUP_START_CMD
value|(35 | AT91C_MCI_RSPTYP_48 )
end_define

begin_define
define|#
directive|define
name|AT91C_MMC_TAG_ERASE_GROUP_END_CMD
value|(36 | AT91C_MCI_RSPTYP_48 )
end_define

begin_define
define|#
directive|define
name|AT91C_MMC_UNTAG_ERASE_GROUP_CMD
value|(37 | AT91C_MCI_RSPTYP_48 )
end_define

begin_define
define|#
directive|define
name|AT91C_ERASE_CMD
value|(38 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_NO	| AT91C_MCI_MAXLAT )
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
name|AT91C_LOCK_UNLOCK
value|(42 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_NO	| AT91C_MCI_MAXLAT)
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
name|AT91C_APP_CMD
value|(55 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_NO | AT91C_MCI_MAXLAT)
end_define

begin_define
define|#
directive|define
name|AT91C_GEN_CMD
value|(56 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_NO | AT91C_MCI_MAXLAT)
end_define

begin_comment
comment|// no tested
end_comment

begin_define
define|#
directive|define
name|AT91C_SDCARD_SET_BUS_WIDTH_CMD
value|(6 	| AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_NO	| AT91C_MCI_MAXLAT)
end_define

begin_define
define|#
directive|define
name|AT91C_SDCARD_STATUS_CMD
value|(13 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_NO	| AT91C_MCI_MAXLAT)
end_define

begin_define
define|#
directive|define
name|AT91C_SDCARD_SEND_NUM_WR_BLOCKS_CMD
value|(22 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_NO	| AT91C_MCI_MAXLAT)
end_define

begin_define
define|#
directive|define
name|AT91C_SDCARD_SET_WR_BLK_ERASE_COUNT_CMD
value|(23 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_NO	| AT91C_MCI_MAXLAT)
end_define

begin_define
define|#
directive|define
name|AT91C_SDCARD_APP_OP_COND_CMD
value|(41 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_NO )
end_define

begin_define
define|#
directive|define
name|AT91C_SDCARD_SET_CLR_CARD_DETECT_CMD
value|(42 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_NO	| AT91C_MCI_MAXLAT)
end_define

begin_define
define|#
directive|define
name|AT91C_SDCARD_SEND_SCR_CMD
value|(51 | AT91C_MCI_SPCMD_NONE	| AT91C_MCI_RSPTYP_48	| AT91C_MCI_TRCMD_NO	| AT91C_MCI_MAXLAT)
end_define

begin_define
define|#
directive|define
name|AT91C_SDCARD_APP_ALL_CMD
value|(AT91C_SDCARD_SET_BUS_WIDTH_CMD +\ 												AT91C_SDCARD_STATUS_CMD +\ 												AT91C_SDCARD_SEND_NUM_WR_BLOCKS_CMD +\ 												AT91C_SDCARD_SET_WR_BLK_ERASE_COUNT_CMD +\ 												AT91C_SDCARD_APP_OP_COND_CMD +\ 												AT91C_SDCARD_SET_CLR_CARD_DETECT_CMD +\ 												AT91C_SDCARD_SEND_SCR_CMD)
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
name|AT91C_MMC_FAST_IO_CMD
value|(39 | AT91C_MCI_SPCMD_NONE | AT91C_MCI_RSPTYP_48 | AT91C_MCI_MAXLAT)
end_define

begin_define
define|#
directive|define
name|AT91C_MMC_GO_IRQ_STATE_CMD
value|(40 | AT91C_MCI_SPCMD_NONE | AT91C_MCI_RSPTYP_48 | AT91C_MCI_TRCMD_NO	| AT91C_MCI_MAXLAT)
end_define

begin_comment
comment|/////////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// Functions returnals
end_comment

begin_comment
comment|/////////////////////////////////////////////////////////////////////////////////////////////////////
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

begin_comment
comment|/////////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// MCI_SR Errors
end_comment

begin_comment
comment|/////////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_define
define|#
directive|define
name|AT91C_MCI_SR_ERROR
value|(AT91C_MCI_UNRE |\ 									 AT91C_MCI_OVRE |\ 									 AT91C_MCI_DTOE |\ 									 AT91C_MCI_DCRCE |\ 									 AT91C_MCI_RTOE |\ 									 AT91C_MCI_RENDE |\ 									 AT91C_MCI_RCRCE |\ 									 AT91C_MCI_RDIRE |\ 									 AT91C_MCI_RINDE)
end_define

begin_comment
comment|////////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// OCR Register
end_comment

begin_comment
comment|////////////////////////////////////////////////////////////////////////////////////////////////////
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
name|AT91C_CARD_POWER_UP_BUSY
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|AT91C_MMC_HOST_VOLTAGE_RANGE
value|(AT91C_VDD_27_28 +\ 										AT91C_VDD_28_29 +\ 										AT91C_VDD_29_30 +\ 										AT91C_VDD_30_31 +\ 										AT91C_VDD_31_32 +\ 										AT91C_VDD_32_33)
end_define

begin_comment
comment|////////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// CURRENT_STATE& READY_FOR_DATA in SDCard Status Register definition (response type R1)
end_comment

begin_comment
comment|////////////////////////////////////////////////////////////////////////////////////////////////////
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

begin_comment
comment|/////////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// MMC CSD register header File
end_comment

begin_comment
comment|// AT91C_CSD_xxx_S	for shift value
end_comment

begin_comment
comment|// AT91C_CSD_xxx_M	for mask  value
end_comment

begin_comment
comment|/////////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// First Response INT<=> CSD[3] : bits 0 to 31
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_BIT0_S
value|0
end_define

begin_comment
comment|// [0:0]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_BIT0_M
value|0x01
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_CRC_S
value|1
end_define

begin_comment
comment|// [7:1]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_CRC_M
value|0x7F
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_MMC_ECC_S
value|8
end_define

begin_comment
comment|// [9:8]		reserved for MMC compatibility
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_MMC_ECC_M
value|0x03
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_FILE_FMT_S
value|10
end_define

begin_comment
comment|// [11:10]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_FILE_FMT_M
value|0x03
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_TMP_WP_S
value|12
end_define

begin_comment
comment|// [12:12]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_TMP_WP_M
value|0x01
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_PERM_WP_S
value|13
end_define

begin_comment
comment|// [13:13]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_PERM_WP_M
value|0x01
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_COPY_S
value|14
end_define

begin_comment
comment|// [14:14]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_COPY_M
value|0x01
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_FILE_FMT_GRP_S
value|15
end_define

begin_comment
comment|// [15:15]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_FILE_FMT_GRP_M
value|0x01
end_define

begin_comment
comment|//	reserved						16		// [20:16]
end_comment

begin_comment
comment|//	reserved						0x1F
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_WBLOCK_P_S
value|21
end_define

begin_comment
comment|// [21:21]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_WBLOCK_P_M
value|0x01
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_WBLEN_S
value|22
end_define

begin_comment
comment|// [25:22]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_WBLEN_M
value|0x0F
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_R2W_F_S
value|26
end_define

begin_comment
comment|// [28:26]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_R2W_F_M
value|0x07
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_MMC_DEF_ECC_S
value|29
end_define

begin_comment
comment|// [30:29]		reserved for MMC compatibility
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_MMC_DEF_ECC_M
value|0x03
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_WP_GRP_EN_S
value|31
end_define

begin_comment
comment|// [31:31]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_WP_GRP_EN_M
value|0x01
end_define

begin_comment
comment|// Seconde Response INT<=> CSD[2] : bits 32 to 63
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_v21_WP_GRP_SIZE_S
value|0
end_define

begin_comment
comment|// [38:32]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_v21_WP_GRP_SIZE_M
value|0x7F
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_v21_SECT_SIZE_S
value|7
end_define

begin_comment
comment|// [45:39]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_v21_SECT_SIZE_M
value|0x7F
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_v21_ER_BLEN_EN_S
value|14
end_define

begin_comment
comment|// [46:46]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_v21_ER_BLEN_EN_M
value|0x01
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_v22_WP_GRP_SIZE_S
value|0
end_define

begin_comment
comment|// [36:32]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_v22_WP_GRP_SIZE_M
value|0x1F
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_v22_ER_GRP_SIZE_S
value|5
end_define

begin_comment
comment|// [41:37]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_v22_ER_GRP_SIZE_M
value|0x1F
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_v22_SECT_SIZE_S
value|10
end_define

begin_comment
comment|// [46:42]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_v22_SECT_SIZE_M
value|0x1F
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_C_SIZE_M_S
value|15
end_define

begin_comment
comment|// [49:47]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_C_SIZE_M_M
value|0x07
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_VDD_WMAX_S
value|18
end_define

begin_comment
comment|// [52:50]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_VDD_WMAX_M
value|0x07
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_VDD_WMIN_S
value|21
end_define

begin_comment
comment|// [55:53]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_VDD_WMIN_M
value|0x07
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_RCUR_MAX_S
value|24
end_define

begin_comment
comment|// [58:56]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_RCUR_MAX_M
value|0x07
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_RCUR_MIN_S
value|27
end_define

begin_comment
comment|// [61:59]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_RCUR_MIN_M
value|0x07
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_CSIZE_L_S
value|30
end_define

begin_comment
comment|// [63:62]<=> 2 LSB of CSIZE
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_CSIZE_L_M
value|0x03
end_define

begin_comment
comment|// Third Response INT<=> CSD[1] : bits 64 to 95
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_CSIZE_H_S
value|0
end_define

begin_comment
comment|// [73:64]<=> 10 MSB of CSIZE
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_CSIZE_H_M
value|0x03FF
end_define

begin_comment
comment|// reserved							10		// [75:74]
end_comment

begin_comment
comment|// reserved							0x03
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_DSR_I_S
value|12
end_define

begin_comment
comment|// [76:76]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_DSR_I_M
value|0x01
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_RD_B_MIS_S
value|13
end_define

begin_comment
comment|// [77:77]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_RD_B_MIS_M
value|0x01
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_WR_B_MIS_S
value|14
end_define

begin_comment
comment|// [78:78]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_WR_B_MIS_M
value|0x01
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_RD_B_PAR_S
value|15
end_define

begin_comment
comment|// [79:79]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_RD_B_PAR_M
value|0x01
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_RD_B_LEN_S
value|16
end_define

begin_comment
comment|// [83:80]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_RD_B_LEN_M
value|0x0F
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_CCC_S
value|20
end_define

begin_comment
comment|// [95:84]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_CCC_M
value|0x0FFF
end_define

begin_comment
comment|// Fourth Response INT<=> CSD[0] : bits 96 to 127
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_TRANS_SPEED_S
value|0
end_define

begin_comment
comment|// [103:96]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_TRANS_SPEED_M
value|0xFF
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_NSAC_S
value|8
end_define

begin_comment
comment|// [111:104]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_NSAC_M
value|0xFF
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_TAAC_S
value|16
end_define

begin_comment
comment|// [119:112]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_TAAC_M
value|0xFF
end_define

begin_comment
comment|//	reserved						24		// [121:120]
end_comment

begin_comment
comment|//	reserved						0x03
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_MMC_SPEC_VERS_S
value|26
end_define

begin_comment
comment|// [125:122]	reserved for MMC compatibility
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_MMC_SPEC_VERS_M
value|0x0F
end_define

begin_define
define|#
directive|define
name|AT91C_CSD_STRUCT_S
value|30
end_define

begin_comment
comment|// [127:126]
end_comment

begin_define
define|#
directive|define
name|AT91C_CSD_STRUCT_M
value|0x03
end_define

begin_comment
comment|/////////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_function_decl
name|void
name|AT91F_MCI_Device_Handler
parameter_list|(
name|AT91PS_MciDevice
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_SDCard_Init
parameter_list|(
name|AT91PS_MciDevice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_SetBlocklength
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_ReadBlock
parameter_list|(
name|AT91PS_MciDevice
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AT91S_MCIDeviceStatus
name|AT91F_MCI_WriteBlock
parameter_list|(
name|AT91PS_MciDevice
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|AT91S_MCIDeviceStatus AT91F_MCI_MMC_Init (AT91PS_MciDevice pMCI_Device); AT91S_MCIDeviceStatus AT91F_MCI_MMC_SelectCard(AT91PS_MciDevice pMCI_Device, unsigned int relative_card_address);
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

