begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*matcddrv.h------------------------------------------------------------------  	Matsushita(Panasonic) / Creative CD-ROM Driver	(matcd) 	Authored by Frank Durda IV  Copyright 1994, 1995, 2002, 2003  Frank Durda IV.  All rights reserved. "FDIV" is a trademark of Frank Durda IV.  ------------------------------------------------------------------------------  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met: 1. Redistributions of source code must retain the above copyright    notice, this list of conditions and the following disclaimer. 2. Redistributions in binary form must reproduce the above copyright    notice, this list of conditions and the following disclaimer in the    documentation and/or other materials provided with the distribution. 3. Neither the name of the author nor the names of their contributors    may be used to endorse or promote products derived from this software    without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  ------------------------------------------------------------------------------  See matcd.c for Edit History information. */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------- 	Matsushita CR562/CR563 Commands  	These equates are for commands accepted by the Matsushita drive. 	This is not a complete list - just the ones that this driver uses. ----------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|NOP
value|0x05
end_define

begin_comment
comment|/*No action - just return status*/
end_comment

begin_define
define|#
directive|define
name|DOOROPEN
value|0x06
end_define

begin_comment
comment|/*Open tray*/
end_comment

begin_define
define|#
directive|define
name|DOORCLOSE
value|0x07
end_define

begin_comment
comment|/*Close tray*/
end_comment

begin_define
define|#
directive|define
name|ABORT
value|0x08
end_define

begin_comment
comment|/*Abort command*/
end_comment

begin_define
define|#
directive|define
name|MODESELECT
value|0x09
end_define

begin_comment
comment|/*Set drive parameters*/
end_comment

begin_define
define|#
directive|define
name|LOCK
value|0x0c
end_define

begin_comment
comment|/*Prevent/Allow medium removal*/
end_comment

begin_define
define|#
directive|define
name|PAUSE
value|0x0d
end_define

begin_comment
comment|/*Pause/Resume playback*/
end_comment

begin_define
define|#
directive|define
name|PLAYBLOCKS
value|0x0e
end_define

begin_comment
comment|/*Play audio - block to block range*/
end_comment

begin_define
define|#
directive|define
name|PLAYTRKS
value|0x0f
end_define

begin_comment
comment|/*Play audio - tracks& index*/
end_comment

begin_define
define|#
directive|define
name|READ
value|0x10
end_define

begin_comment
comment|/*Read data*/
end_comment

begin_define
define|#
directive|define
name|READERROR
value|0x82
end_define

begin_comment
comment|/*Read Error*/
end_comment

begin_define
define|#
directive|define
name|READID
value|0x83
end_define

begin_comment
comment|/*Read Drive Type& Firmware Info*/
end_comment

begin_define
define|#
directive|define
name|MODESENSE
value|0x84
end_define

begin_comment
comment|/*Report drive settings*/
end_comment

begin_define
define|#
directive|define
name|READSUBQ
value|0x87
end_define

begin_comment
comment|/*Read Q channel information*/
end_comment

begin_define
define|#
directive|define
name|READDINFO
value|0x8b
end_define

begin_comment
comment|/*Read TOC tracks& drive size*/
end_comment

begin_define
define|#
directive|define
name|READTOC
value|0x8c
end_define

begin_comment
comment|/*Read entry from TOC*/
end_comment

begin_define
define|#
directive|define
name|BLOCKPARAM
value|0x00
end_define

begin_comment
comment|/*Used with MODESELECT command*/
end_comment

begin_define
define|#
directive|define
name|SPEEDPARM
value|0x03
end_define

begin_comment
comment|/*Adjust audio playback speed*/
end_comment

begin_define
define|#
directive|define
name|AUDIOPARM
value|0x05
end_define

begin_comment
comment|/*Set/read audio levels& routing*/
end_comment

begin_define
define|#
directive|define
name|RESUME
value|0x80
end_define

begin_comment
comment|/*Used with PAUSE command*/
end_comment

begin_define
define|#
directive|define
name|MAXCMDSIZ
value|12
end_define

begin_comment
comment|/*Max command size with NULL*/
end_comment

begin_comment
comment|/*	Possible data transfers for MODESELECT + BLOCKPARAM */
end_comment

begin_define
define|#
directive|define
name|MODE_DATA
value|0x00
end_define

begin_comment
comment|/*2048, 2340*/
end_comment

begin_define
define|#
directive|define
name|MODE_DA
value|0x82
end_define

begin_comment
comment|/*2352*/
end_comment

begin_define
define|#
directive|define
name|MODE_USER
value|0x01
end_define

begin_comment
comment|/*2048, 2052, 2336, 2340, 2352*/
end_comment

begin_define
define|#
directive|define
name|MODE_UNKNOWN
value|0xff
end_define

begin_comment
comment|/*Uninitialized state*/
end_comment

begin_define
define|#
directive|define
name|MODE_XA
value|0x81
end_define

begin_comment
comment|/*2048, 2060, 2324, 2336, 2340, 2352*/
end_comment

begin_comment
comment|/*The driver does not implement XA.*/
end_comment

begin_define
define|#
directive|define
name|DEFVOL
value|0xff
end_define

begin_comment
comment|/*Default drive volume level, 100% 					  volume.  Based on drive action.*/
end_comment

begin_define
define|#
directive|define
name|OUTLEFT
value|0x01
end_define

begin_comment
comment|/*Output on Left*/
end_comment

begin_define
define|#
directive|define
name|OUTRIGHT
value|0x02
end_define

begin_comment
comment|/*Output on Right*/
end_comment

begin_comment
comment|/*	 Matsushita CR562/CR563 Status bits*/
end_comment

begin_define
define|#
directive|define
name|MATCD_ST_DOOROPEN
value|0x80
end_define

begin_comment
comment|/*Door is open right now*/
end_comment

begin_define
define|#
directive|define
name|MATCD_ST_DSKIN
value|0x40
end_define

begin_comment
comment|/*Disc in drive*/
end_comment

begin_define
define|#
directive|define
name|MATCD_ST_SPIN
value|0x20
end_define

begin_comment
comment|/*Disc is spinning*/
end_comment

begin_define
define|#
directive|define
name|MATCD_ST_ERROR
value|0x10
end_define

begin_comment
comment|/*Error on command*/
end_comment

begin_define
define|#
directive|define
name|MATCD_ST_AUDIOBSY
value|0x08
end_define

begin_comment
comment|/*Drive is playing audio*/
end_comment

begin_define
define|#
directive|define
name|MATCD_ST_LOCK
value|0x04
end_define

begin_comment
comment|/*Drive is locked*/
end_comment

begin_define
define|#
directive|define
name|MATCD_ST_X2
value|0x02
end_define

begin_comment
comment|/*Media is at double-speed*/
end_comment

begin_define
define|#
directive|define
name|MATCD_ST_READY
value|0x01
end_define

begin_comment
comment|/*Drive is ready*/
end_comment

begin_comment
comment|/*	Error codes returned from READERROR command. 	(The hardware vendor did not provide any additional information 	 on what conditions generate these errors.) */
end_comment

begin_define
define|#
directive|define
name|NO_ERROR
value|0x00
end_define

begin_define
define|#
directive|define
name|RECV_RETRY
value|0x01
end_define

begin_define
define|#
directive|define
name|RECV_ECC
value|0x02
end_define

begin_define
define|#
directive|define
name|NOT_READY
value|0x03
end_define

begin_define
define|#
directive|define
name|TOC_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|UNRECV_ERROR
value|0x05
end_define

begin_define
define|#
directive|define
name|SEEK_ERROR
value|0x06
end_define

begin_define
define|#
directive|define
name|TRACK_ERROR
value|0x07
end_define

begin_define
define|#
directive|define
name|RAM_ERROR
value|0x08
end_define

begin_define
define|#
directive|define
name|DIAG_ERROR
value|0x09
end_define

begin_define
define|#
directive|define
name|FOCUS_ERROR
value|0x0a
end_define

begin_define
define|#
directive|define
name|CLV_ERROR
value|0x0b
end_define

begin_define
define|#
directive|define
name|DATA_ERROR
value|0x0c
end_define

begin_define
define|#
directive|define
name|ADDRESS_ERROR
value|0x0d
end_define

begin_define
define|#
directive|define
name|CDB_ERROR
value|0x0e
end_define

begin_define
define|#
directive|define
name|END_ADDRESS
value|0x0f
end_define

begin_define
define|#
directive|define
name|MODE_ERROR
value|0x10
end_define

begin_define
define|#
directive|define
name|MEDIA_CHANGED
value|0x11
end_define

begin_define
define|#
directive|define
name|HARD_RESET
value|0x12
end_define

begin_define
define|#
directive|define
name|ROM_ERROR
value|0x13
end_define

begin_define
define|#
directive|define
name|CMD_ERROR
value|0x14
end_define

begin_define
define|#
directive|define
name|DISC_OUT
value|0x15
end_define

begin_define
define|#
directive|define
name|HARD_ERROR
value|0x16
end_define

begin_define
define|#
directive|define
name|ILLEGAL_REQ
value|0x17
end_define

begin_comment
comment|/*	Human-readable error messages - what a concept!*/
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
modifier|*
name|matcderrors
index|[]
init|=
block|{
literal|"No error"
block|,
comment|/* 00 */
literal|"Soft read error after retry"
block|,
comment|/* 01 */
literal|"Soft read error after error-correction"
block|,
comment|/* 02 */
literal|"Not ready"
block|,
comment|/* 03 */
literal|"Unable to read TOC"
block|,
comment|/* 04 */
literal|"Hard read error of data track"
block|,
comment|/* 05 */
literal|"Seek did not complete"
block|,
comment|/* 06 */
literal|"Tracking servo failure"
block|,
comment|/* 07 */
literal|"Drive RAM failure"
block|,
comment|/* 08 */
literal|"Drive self-test failed"
block|,
comment|/* 09 */
literal|"Focusing servo failure"
block|,
comment|/* 0a */
literal|"Spindle servo failure"
block|,
comment|/* 0b */
literal|"Data path failure"
block|,
comment|/* 0c */
literal|"Illegal logical block address"
block|,
comment|/* 0d */
literal|"Illegal field in CDB"
block|,
comment|/* 0e */
literal|"End of user encountered on this track"
block|,
comment|/* 0f */
literal|"Illegal data mode for this track"
block|,
comment|/* 10 */
literal|"Media changed"
block|,
comment|/* 11 */
literal|"Power-on or drive reset occurred"
block|,
comment|/* 12 */
literal|"Drive ROM failure"
block|,
comment|/* 13 */
literal|"Illegal drive command received from host"
block|,
comment|/* 14 */
literal|"Disc removed during operation"
block|,
comment|/* 15 */
literal|"Drive Hardware error"
block|,
comment|/* 16 */
literal|"Illegal request from host"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 17 */
end_comment

begin_comment
comment|/*End of matcddrv.h*/
end_comment

end_unit

