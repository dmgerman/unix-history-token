begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*creative.h-------------------------------------------------------------------  	Matsushita(Panasonic) / Creative CD-ROM Driver	(matcd) 	Authored by Frank Durda IV  Copyright 1994, 1995, 2002, 2003  Frank Durda IV.  All rights reserved. "FDIV" is a trademark of Frank Durda IV.  ------------------------------------------------------------------------------  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met: 1. Redistributions of source code must retain the above copyright    notice, this list of conditions and the following disclaimer. 2. Redistributions in binary form must reproduce the above copyright    notice, this list of conditions and the following disclaimer in the    documentation and/or other materials provided with the distribution. 3. Neither the name of the author nor the names of their contributors    may be used to endorse or promote products derived from this software    without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  ------------------------------------------------------------------------------  See matcd.c for Edit History */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------- These are the I/O port mapping offsets and bit assignments used by Creative Labs in their implementation of the host interface adapter for the Matsushita CD-ROM drive.  These may be different in the adapter cards (including sound cards) made by other vendors.  It is unknown if the Creative interface is based on a reference design provided by Matsushita.  (If Matsushita did provide a reference design, you would expect adapters made by other vendors to be more compatible.)  Note that the Matsushita drives are actually capable of using DMA and generating interrupts, but none of the host adapters provide the circuitry needed to do DMA or generate interrupts.  See matcd.h for defines related to the drive command set.  ------------------------------------------------------------------------------ 	Creative Labs (and compatible) host adapter I/O port mapping offsets ----------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|NUMPORTS
value|4
end_define

begin_comment
comment|/*Four ports are decoded by the i/f*/
end_comment

begin_define
define|#
directive|define
name|CMD
value|0
end_define

begin_comment
comment|/*Write - commands*/
end_comment

begin_define
define|#
directive|define
name|DATA
value|0
end_define

begin_comment
comment|/*Read - status from drive.  Also for*/
end_comment

begin_comment
comment|/*reading data on Creative adapters.*/
end_comment

begin_define
define|#
directive|define
name|PHASE
value|1
end_define

begin_comment
comment|/*Write - switch between data/status*/
end_comment

begin_define
define|#
directive|define
name|STATUS
value|1
end_define

begin_comment
comment|/*Read - bus status*/
end_comment

begin_define
define|#
directive|define
name|RESET
value|2
end_define

begin_comment
comment|/*Write - reset all attached drives*/
end_comment

begin_comment
comment|/*Any value written will reset*/
end_comment

begin_define
define|#
directive|define
name|ALTDATA
value|2
end_define

begin_comment
comment|/*Read - data on non-Creative adaptrs.*/
end_comment

begin_define
define|#
directive|define
name|SELECT
value|3
end_define

begin_comment
comment|/*Write - drive select*/
end_comment

begin_comment
comment|/*	Creative PHASE port bit assignments */
end_comment

begin_define
define|#
directive|define
name|PHASENA
value|1
end_define

begin_comment
comment|/*Access data bytes instead of status*/
end_comment

begin_comment
comment|/*on shared data/status port*/
end_comment

begin_comment
comment|/*	Creative STATUS port register bits */
end_comment

begin_define
define|#
directive|define
name|DTEN
value|2
end_define

begin_comment
comment|/*When low, in data xfer phase*/
end_comment

begin_define
define|#
directive|define
name|STEN
value|4
end_define

begin_comment
comment|/*When low, in status phase*/
end_comment

begin_define
define|#
directive|define
name|TEST
value|1
end_define

begin_comment
comment|/*Function is unknown*/
end_comment

begin_comment
comment|/*	Creative drive SELECT port bit assignments 	Note that on the Creative host adapters, DS0==Bit 1 and 	DS1==Bit 0   (DS is Drive Select). */
end_comment

begin_define
define|#
directive|define
name|CRDRIVE0
value|0x00
end_define

begin_define
define|#
directive|define
name|CRDRIVE1
value|0x02
end_define

begin_define
define|#
directive|define
name|CRDRIVE2
value|0x01
end_define

begin_define
define|#
directive|define
name|CRDRIVE3
value|0x03
end_define

begin_comment
comment|/*End of creative.h*/
end_comment

end_unit

