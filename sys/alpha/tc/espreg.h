begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: espreg.h,v 1.2.4.1 1996/09/10 17:28:17 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 Peter Galbavy.  All rights reserved.  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Peter Galbavy.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Register addresses, relative to some base address  */
end_comment

begin_define
define|#
directive|define
name|ESP_TCL
value|0x00
end_define

begin_comment
comment|/* RW - Transfer Count Low	*/
end_comment

begin_define
define|#
directive|define
name|ESP_TCM
value|0x01
end_define

begin_comment
comment|/* RW - Transfer Count Mid	*/
end_comment

begin_define
define|#
directive|define
name|ESP_TCH
value|0x0e
end_define

begin_comment
comment|/* RW - Transfer Count High	*/
end_comment

begin_comment
comment|/*	NOT on 53C90		*/
end_comment

begin_define
define|#
directive|define
name|ESP_FIFO
value|0x02
end_define

begin_comment
comment|/* RW - FIFO data		*/
end_comment

begin_define
define|#
directive|define
name|ESP_CMD
value|0x03
end_define

begin_comment
comment|/* RW - Command (2 deep)	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_DMA
value|0x80
end_define

begin_comment
comment|/*	DMA Bit			*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_NOP
value|0x00
end_define

begin_comment
comment|/*	No Operation		*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_FLUSH
value|0x01
end_define

begin_comment
comment|/*	Flush FIFO		*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RSTCHIP
value|0x02
end_define

begin_comment
comment|/*	Reset Chip		*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RSTSCSI
value|0x03
end_define

begin_comment
comment|/*	Reset SCSI Bus		*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RESEL
value|0x40
end_define

begin_comment
comment|/*	Reselect Sequence	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SELNATN
value|0x41
end_define

begin_comment
comment|/*	Select without ATN	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SELATN
value|0x42
end_define

begin_comment
comment|/*	Select with ATN		*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SELATNS
value|0x43
end_define

begin_comment
comment|/*	Select with ATN& Stop	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_ENSEL
value|0x44
end_define

begin_comment
comment|/*	Enable (Re)Selection	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_DISSEL
value|0x45
end_define

begin_comment
comment|/*	Disable (Re)Selection	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SELATN3
value|0x46
end_define

begin_comment
comment|/*	Select with ATN3	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RESEL3
value|0x47
end_define

begin_comment
comment|/*	Reselect3 Sequence	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SNDMSG
value|0x20
end_define

begin_comment
comment|/*	Send Message		*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SNDSTAT
value|0x21
end_define

begin_comment
comment|/*	Send Status		*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SNDDATA
value|0x22
end_define

begin_comment
comment|/*	Send Data		*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_DISCSEQ
value|0x23
end_define

begin_comment
comment|/*	Disconnect Sequence	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_TERMSEQ
value|0x24
end_define

begin_comment
comment|/*	Terminate Sequence	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_TCCS
value|0x25
end_define

begin_comment
comment|/*	Target Command Comp Seq	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_DISC
value|0x27
end_define

begin_comment
comment|/*	Disconnect		*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RECMSG
value|0x28
end_define

begin_comment
comment|/*	Receive Message		*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RECCMD
value|0x29
end_define

begin_comment
comment|/*	Receive Command 	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RECDATA
value|0x2a
end_define

begin_comment
comment|/*	Receive Data		*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RECCSEQ
value|0x2b
end_define

begin_comment
comment|/*	Receive Command Sequence*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_ABORT
value|0x04
end_define

begin_comment
comment|/*	Target Abort DMA	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_TRANS
value|0x10
end_define

begin_comment
comment|/*	Transfer Information	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_ICCS
value|0x11
end_define

begin_comment
comment|/*	Initiator Cmd Comp Seq 	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_MSGOK
value|0x12
end_define

begin_comment
comment|/*	Message Accepted	*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_TRPAD
value|0x18
end_define

begin_comment
comment|/*	Transfer Pad		*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SETATN
value|0x1a
end_define

begin_comment
comment|/*	Set ATN			*/
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RSTATN
value|0x1b
end_define

begin_comment
comment|/*	Reset ATN		*/
end_comment

begin_define
define|#
directive|define
name|ESP_STAT
value|0x04
end_define

begin_comment
comment|/* RO - Status			*/
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_INT
value|0x80
end_define

begin_comment
comment|/*	Interrupt		*/
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_GE
value|0x40
end_define

begin_comment
comment|/*	Gross Error		*/
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_PE
value|0x20
end_define

begin_comment
comment|/*	Parity Error		*/
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_TC
value|0x10
end_define

begin_comment
comment|/*	Terminal Count		*/
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_VGC
value|0x08
end_define

begin_comment
comment|/*	Valid Group Code	*/
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_PHASE
value|0x07
end_define

begin_comment
comment|/*	Phase bits		*/
end_comment

begin_define
define|#
directive|define
name|ESP_SELID
value|0x04
end_define

begin_comment
comment|/* WO - Select/Reselect Bus ID	*/
end_comment

begin_define
define|#
directive|define
name|ESP_INTR
value|0x05
end_define

begin_comment
comment|/* RO - Interrupt		*/
end_comment

begin_define
define|#
directive|define
name|ESPINTR_SBR
value|0x80
end_define

begin_comment
comment|/*	SCSI Bus Reset		*/
end_comment

begin_define
define|#
directive|define
name|ESPINTR_ILL
value|0x40
end_define

begin_comment
comment|/*	Illegal Command		*/
end_comment

begin_define
define|#
directive|define
name|ESPINTR_DIS
value|0x20
end_define

begin_comment
comment|/*	Disconnect		*/
end_comment

begin_define
define|#
directive|define
name|ESPINTR_BS
value|0x10
end_define

begin_comment
comment|/*	Bus Service		*/
end_comment

begin_define
define|#
directive|define
name|ESPINTR_FC
value|0x08
end_define

begin_comment
comment|/*	Function Complete	*/
end_comment

begin_define
define|#
directive|define
name|ESPINTR_RESEL
value|0x04
end_define

begin_comment
comment|/*	Reselected		*/
end_comment

begin_define
define|#
directive|define
name|ESPINTR_SELATN
value|0x02
end_define

begin_comment
comment|/*	Select with ATN		*/
end_comment

begin_define
define|#
directive|define
name|ESPINTR_SEL
value|0x01
end_define

begin_comment
comment|/*	Selected		*/
end_comment

begin_define
define|#
directive|define
name|ESP_TIMEOUT
value|0x05
end_define

begin_comment
comment|/* WO - Select/Reselect Timeout */
end_comment

begin_define
define|#
directive|define
name|ESP_STEP
value|0x06
end_define

begin_comment
comment|/* RO - Sequence Step		*/
end_comment

begin_define
define|#
directive|define
name|ESPSTEP_MASK
value|0x07
end_define

begin_comment
comment|/*	the last 3 bits		*/
end_comment

begin_define
define|#
directive|define
name|ESPSTEP_DONE
value|0x04
end_define

begin_comment
comment|/*	command went out	*/
end_comment

begin_define
define|#
directive|define
name|ESP_SYNCTP
value|0x06
end_define

begin_comment
comment|/* WO - Synch Transfer Period	*/
end_comment

begin_comment
comment|/*	Default 5 (53C9X)	*/
end_comment

begin_define
define|#
directive|define
name|ESP_FFLAG
value|0x07
end_define

begin_comment
comment|/* RO - FIFO Flags		*/
end_comment

begin_define
define|#
directive|define
name|ESPFIFO_SS
value|0xe0
end_define

begin_comment
comment|/*	Sequence Step (Dup)	*/
end_comment

begin_define
define|#
directive|define
name|ESPFIFO_FF
value|0x1f
end_define

begin_comment
comment|/*	Bytes in FIFO		*/
end_comment

begin_define
define|#
directive|define
name|ESP_SYNCOFF
value|0x07
end_define

begin_comment
comment|/* WO - Synch Offset		*/
end_comment

begin_comment
comment|/*	0 = ASYNC		*/
end_comment

begin_comment
comment|/*	1 - 15 = SYNC bytes	*/
end_comment

begin_define
define|#
directive|define
name|ESP_CFG1
value|0x08
end_define

begin_comment
comment|/* RW - Configuration #1	*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG1_SLOW
value|0x80
end_define

begin_comment
comment|/*	Slow Cable Mode		*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG1_SRR
value|0x40
end_define

begin_comment
comment|/*	SCSI Reset Rep Int Dis	*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG1_PTEST
value|0x20
end_define

begin_comment
comment|/*	Parity Test Mod		*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG1_PARENB
value|0x10
end_define

begin_comment
comment|/*	Enable Parity Check	*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG1_CTEST
value|0x08
end_define

begin_comment
comment|/*	Enable Chip Test	*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG1_BUSID
value|0x07
end_define

begin_comment
comment|/*	Bus ID			*/
end_comment

begin_define
define|#
directive|define
name|ESP_CCF
value|0x09
end_define

begin_comment
comment|/* WO -	Clock Conversion Factor	*/
end_comment

begin_comment
comment|/*	0 = 35.01 - 40Mhz	*/
end_comment

begin_comment
comment|/*	NEVER SET TO 1		*/
end_comment

begin_comment
comment|/*	2 = 10Mhz		*/
end_comment

begin_comment
comment|/*	3 = 10.01 - 15Mhz	*/
end_comment

begin_comment
comment|/*	4 = 15.01 - 20Mhz	*/
end_comment

begin_comment
comment|/*	5 = 20.01 - 25Mhz	*/
end_comment

begin_comment
comment|/*	6 = 25.01 - 30Mhz	*/
end_comment

begin_comment
comment|/*	7 = 30.01 - 35Mhz	*/
end_comment

begin_define
define|#
directive|define
name|ESP_TEST
value|0x0a
end_define

begin_comment
comment|/* WO - Test (Chip Test Only)	*/
end_comment

begin_define
define|#
directive|define
name|ESP_CFG2
value|0x0b
end_define

begin_comment
comment|/* RW - Configuration #2	*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG2_RSVD
value|0xa0
end_define

begin_comment
comment|/*	reserved		*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG2_FE
value|0x40
end_define

begin_comment
comment|/* 	Features Enable		*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG2_DREQ
value|0x10
end_define

begin_comment
comment|/* 	DREQ High Impedance	*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG2_SCSI2
value|0x08
end_define

begin_comment
comment|/* 	SCSI-2 Enable		*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG2_BPA
value|0x04
end_define

begin_comment
comment|/* 	Target Bad Parity Abort	*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG2_RPE
value|0x02
end_define

begin_comment
comment|/* 	Register Parity Error	*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG2_DPE
value|0x01
end_define

begin_comment
comment|/* 	DMA Parity Error	*/
end_comment

begin_comment
comment|/* Config #3 only on 53C9X */
end_comment

begin_define
define|#
directive|define
name|ESP_CFG3
value|0x0c
end_define

begin_comment
comment|/* RW - Configuration #3	*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG3_RSVD
value|0xe0
end_define

begin_comment
comment|/*	reserved		*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG3_IDM
value|0x10
end_define

begin_comment
comment|/*	ID Message Res Check	*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG3_QTE
value|0x08
end_define

begin_comment
comment|/*	Queue Tag Enable	*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG3_CDB
value|0x04
end_define

begin_comment
comment|/*	CDB 10-bytes OK		*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG3_FSCSI
value|0x02
end_define

begin_comment
comment|/*	Fast SCSI		*/
end_comment

begin_define
define|#
directive|define
name|ESPCFG3_FCLK
value|0x01
end_define

begin_comment
comment|/*	Fast Clock (>25Mhz)	*/
end_comment

end_unit

