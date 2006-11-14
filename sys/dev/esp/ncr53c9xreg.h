begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ncr53c9xreg.h,v 1.14 2005/02/27 00:27:02 perry Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994 Peter Galbavy.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Peter Galbavy.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Register addresses, relative to some base address  */
end_comment

begin_define
define|#
directive|define
name|NCR_TCL
value|0x00
end_define

begin_comment
comment|/* RW - Transfer Count Low	*/
end_comment

begin_define
define|#
directive|define
name|NCR_TCM
value|0x01
end_define

begin_comment
comment|/* RW - Transfer Count Mid	*/
end_comment

begin_define
define|#
directive|define
name|NCR_TCH
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
name|NCR_FIFO
value|0x02
end_define

begin_comment
comment|/* RW - FIFO data		*/
end_comment

begin_define
define|#
directive|define
name|NCR_CMD
value|0x03
end_define

begin_comment
comment|/* RW - Command (2 deep)	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_DMA
value|0x80
end_define

begin_comment
comment|/*	DMA Bit			*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_NOP
value|0x00
end_define

begin_comment
comment|/*	No Operation		*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_FLUSH
value|0x01
end_define

begin_comment
comment|/*	Flush FIFO		*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_RSTCHIP
value|0x02
end_define

begin_comment
comment|/*	Reset Chip		*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_RSTSCSI
value|0x03
end_define

begin_comment
comment|/*	Reset SCSI Bus		*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_RESEL
value|0x40
end_define

begin_comment
comment|/*	Reselect Sequence	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_SELNATN
value|0x41
end_define

begin_comment
comment|/*	Select without ATN	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_SELATN
value|0x42
end_define

begin_comment
comment|/*	Select with ATN		*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_SELATNS
value|0x43
end_define

begin_comment
comment|/*	Select with ATN& Stop	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_ENSEL
value|0x44
end_define

begin_comment
comment|/*	Enable (Re)Selection	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_DISSEL
value|0x45
end_define

begin_comment
comment|/*	Disable (Re)Selection	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_SELATN3
value|0x46
end_define

begin_comment
comment|/*	Select with ATN3	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_RESEL3
value|0x47
end_define

begin_comment
comment|/*	Reselect3 Sequence	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_SNDMSG
value|0x20
end_define

begin_comment
comment|/*	Send Message		*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_SNDSTAT
value|0x21
end_define

begin_comment
comment|/*	Send Status		*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_SNDDATA
value|0x22
end_define

begin_comment
comment|/*	Send Data		*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_DISCSEQ
value|0x23
end_define

begin_comment
comment|/*	Disconnect Sequence	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_TERMSEQ
value|0x24
end_define

begin_comment
comment|/*	Terminate Sequence	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_TCCS
value|0x25
end_define

begin_comment
comment|/*	Target Command Comp Seq	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_DISC
value|0x27
end_define

begin_comment
comment|/*	Disconnect		*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_RECMSG
value|0x28
end_define

begin_comment
comment|/*	Receive Message		*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_RECCMD
value|0x29
end_define

begin_comment
comment|/*	Receive Command 	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_RECDATA
value|0x2a
end_define

begin_comment
comment|/*	Receive Data		*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_RECCSEQ
value|0x2b
end_define

begin_comment
comment|/*	Receive Command Sequence*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_ABORT
value|0x04
end_define

begin_comment
comment|/*	Target Abort DMA	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_TRANS
value|0x10
end_define

begin_comment
comment|/*	Transfer Information	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_ICCS
value|0x11
end_define

begin_comment
comment|/*	Initiator Cmd Comp Seq 	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_MSGOK
value|0x12
end_define

begin_comment
comment|/*	Message Accepted	*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_TRPAD
value|0x18
end_define

begin_comment
comment|/*	Transfer Pad		*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_SETATN
value|0x1a
end_define

begin_comment
comment|/*	Set ATN			*/
end_comment

begin_define
define|#
directive|define
name|NCRCMD_RSTATN
value|0x1b
end_define

begin_comment
comment|/*	Reset ATN		*/
end_comment

begin_define
define|#
directive|define
name|NCR_STAT
value|0x04
end_define

begin_comment
comment|/* RO - Status			*/
end_comment

begin_define
define|#
directive|define
name|NCRSTAT_INT
value|0x80
end_define

begin_comment
comment|/*	Interrupt		*/
end_comment

begin_define
define|#
directive|define
name|NCRSTAT_GE
value|0x40
end_define

begin_comment
comment|/*	Gross Error		*/
end_comment

begin_define
define|#
directive|define
name|NCRSTAT_PE
value|0x20
end_define

begin_comment
comment|/*	Parity Error		*/
end_comment

begin_define
define|#
directive|define
name|NCRSTAT_TC
value|0x10
end_define

begin_comment
comment|/*	Terminal Count		*/
end_comment

begin_define
define|#
directive|define
name|NCRSTAT_VGC
value|0x08
end_define

begin_comment
comment|/*	Valid Group Code	*/
end_comment

begin_define
define|#
directive|define
name|NCRSTAT_PHASE
value|0x07
end_define

begin_comment
comment|/*	Phase bits		*/
end_comment

begin_define
define|#
directive|define
name|NCR_SELID
value|0x04
end_define

begin_comment
comment|/* WO - Select/Reselect Bus ID	*/
end_comment

begin_define
define|#
directive|define
name|NCR_BUSID_HME
value|0x10
end_define

begin_comment
comment|/* XXX HME reselect ID 		*/
end_comment

begin_define
define|#
directive|define
name|NCR_BUSID_HME32
value|0x40
end_define

begin_comment
comment|/* XXX HME to select more than 16 */
end_comment

begin_define
define|#
directive|define
name|NCR_INTR
value|0x05
end_define

begin_comment
comment|/* RO - Interrupt		*/
end_comment

begin_define
define|#
directive|define
name|NCRINTR_SBR
value|0x80
end_define

begin_comment
comment|/*	SCSI Bus Reset		*/
end_comment

begin_define
define|#
directive|define
name|NCRINTR_ILL
value|0x40
end_define

begin_comment
comment|/*	Illegal Command		*/
end_comment

begin_define
define|#
directive|define
name|NCRINTR_DIS
value|0x20
end_define

begin_comment
comment|/*	Disconnect		*/
end_comment

begin_define
define|#
directive|define
name|NCRINTR_BS
value|0x10
end_define

begin_comment
comment|/*	Bus Service		*/
end_comment

begin_define
define|#
directive|define
name|NCRINTR_FC
value|0x08
end_define

begin_comment
comment|/*	Function Complete	*/
end_comment

begin_define
define|#
directive|define
name|NCRINTR_RESEL
value|0x04
end_define

begin_comment
comment|/*	Reselected		*/
end_comment

begin_define
define|#
directive|define
name|NCRINTR_SELATN
value|0x02
end_define

begin_comment
comment|/*	Select with ATN		*/
end_comment

begin_define
define|#
directive|define
name|NCRINTR_SEL
value|0x01
end_define

begin_comment
comment|/*	Selected		*/
end_comment

begin_define
define|#
directive|define
name|NCR_TIMEOUT
value|0x05
end_define

begin_comment
comment|/* WO - Select/Reselect Timeout */
end_comment

begin_define
define|#
directive|define
name|NCR_STEP
value|0x06
end_define

begin_comment
comment|/* RO - Sequence Step		*/
end_comment

begin_define
define|#
directive|define
name|NCRSTEP_MASK
value|0x07
end_define

begin_comment
comment|/*	the last 3 bits		*/
end_comment

begin_define
define|#
directive|define
name|NCRSTEP_DONE
value|0x04
end_define

begin_comment
comment|/*	command went out	*/
end_comment

begin_define
define|#
directive|define
name|NCR_SYNCTP
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
name|NCR_FFLAG
value|0x07
end_define

begin_comment
comment|/* RO - FIFO Flags		*/
end_comment

begin_define
define|#
directive|define
name|NCRFIFO_SS
value|0xe0
end_define

begin_comment
comment|/*	Sequence Step (Dup)	*/
end_comment

begin_define
define|#
directive|define
name|NCRFIFO_FF
value|0x1f
end_define

begin_comment
comment|/*	Bytes in FIFO		*/
end_comment

begin_define
define|#
directive|define
name|NCR_SYNCOFF
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
name|NCR_CFG1
value|0x08
end_define

begin_comment
comment|/* RW - Configuration #1	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG1_SLOW
value|0x80
end_define

begin_comment
comment|/*	Slow Cable Mode		*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG1_SRR
value|0x40
end_define

begin_comment
comment|/*	SCSI Reset Rep Int Dis	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG1_PTEST
value|0x20
end_define

begin_comment
comment|/*	Parity Test Mod		*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG1_PARENB
value|0x10
end_define

begin_comment
comment|/*	Enable Parity Check	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG1_CTEST
value|0x08
end_define

begin_comment
comment|/*	Enable Chip Test	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG1_BUSID
value|0x07
end_define

begin_comment
comment|/*	Bus ID			*/
end_comment

begin_define
define|#
directive|define
name|NCR_CCF
value|0x09
end_define

begin_comment
comment|/* WO -	Clock Conversion Factor	*/
end_comment

begin_comment
comment|/*	0 = 35.01 - 40MHz	*/
end_comment

begin_comment
comment|/*	NEVER SET TO 1		*/
end_comment

begin_comment
comment|/*	2 = 10MHz		*/
end_comment

begin_comment
comment|/*	3 = 10.01 - 15MHz	*/
end_comment

begin_comment
comment|/*	4 = 15.01 - 20MHz	*/
end_comment

begin_comment
comment|/*	5 = 20.01 - 25MHz	*/
end_comment

begin_comment
comment|/*	6 = 25.01 - 30MHz	*/
end_comment

begin_comment
comment|/*	7 = 30.01 - 35MHz	*/
end_comment

begin_define
define|#
directive|define
name|NCR_TEST
value|0x0a
end_define

begin_comment
comment|/* WO - Test (Chip Test Only)	*/
end_comment

begin_define
define|#
directive|define
name|NCR_CFG2
value|0x0b
end_define

begin_comment
comment|/* RW - Configuration #2	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG2_RSVD
value|0xa0
end_define

begin_comment
comment|/*	reserved		*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG2_FE
value|0x40
end_define

begin_comment
comment|/* 	Features Enable		*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG2_DREQ
value|0x10
end_define

begin_comment
comment|/* 	DREQ High Impedance	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG2_SCSI2
value|0x08
end_define

begin_comment
comment|/* 	SCSI-2 Enable		*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG2_BPA
value|0x04
end_define

begin_comment
comment|/* 	Target Bad Parity Abort	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG2_RPE
value|0x02
end_define

begin_comment
comment|/* 	Register Parity Error	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG2_DPE
value|0x01
end_define

begin_comment
comment|/* 	DMA Parity Error	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG2_HMEFE
value|0x10
end_define

begin_comment
comment|/*	HME feature enable	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG2_HME32
value|0x80
end_define

begin_comment
comment|/*	HME 32 extended		*/
end_comment

begin_comment
comment|/* Config #3 only on 53C9X */
end_comment

begin_define
define|#
directive|define
name|NCR_CFG3
value|0x0c
end_define

begin_comment
comment|/* RW - Configuration #3	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG3_RSVD
value|0xe0
end_define

begin_comment
comment|/*	reserved		*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG3_IDM
value|0x10
end_define

begin_comment
comment|/*	ID Message Res Check	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG3_QTE
value|0x08
end_define

begin_comment
comment|/*	Queue Tag Enable	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG3_CDB
value|0x04
end_define

begin_comment
comment|/*	CDB 10-bytes OK		*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG3_FSCSI
value|0x02
end_define

begin_comment
comment|/*	Fast SCSI		*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG3_FCLK
value|0x01
end_define

begin_comment
comment|/*	Fast Clock (>25MHz)	*/
end_comment

begin_comment
comment|/*  * For some unknown reason, the ESP406/FAS408 looks like every  * other ncr53c9x, except for configuration #3 register.  At any  * rate, if you're dealing with these chips, you need to use these  * defines instead.  */
end_comment

begin_comment
comment|/* Config #3 different on ESP406/FAS408 */
end_comment

begin_define
define|#
directive|define
name|NCR_ESPCFG3
value|0x0c
end_define

begin_comment
comment|/* RW - Configuration #3	*/
end_comment

begin_define
define|#
directive|define
name|NCRESPCFG3_IDM
value|0x80
end_define

begin_comment
comment|/*	ID Message Res Check	*/
end_comment

begin_define
define|#
directive|define
name|NCRESPCFG3_QTE
value|0x40
end_define

begin_comment
comment|/*	Queue Tag Enable	*/
end_comment

begin_define
define|#
directive|define
name|NCRESPCFG3_CDB
value|0x20
end_define

begin_comment
comment|/*	CDB 10-bytes OK		*/
end_comment

begin_define
define|#
directive|define
name|NCRESPCFG3_FSCSI
value|0x10
end_define

begin_comment
comment|/*	Fast SCSI		*/
end_comment

begin_define
define|#
directive|define
name|NCRESPCFG3_SRESB
value|0x08
end_define

begin_comment
comment|/*	Save Residual Byte	*/
end_comment

begin_define
define|#
directive|define
name|NCRESPCFG3_FCLK
value|0x04
end_define

begin_comment
comment|/*	Fast Clock (>25MHz)	*/
end_comment

begin_define
define|#
directive|define
name|NCRESPCFG3_ADMA
value|0x02
end_define

begin_comment
comment|/*	Alternate DMA Mode	*/
end_comment

begin_define
define|#
directive|define
name|NCRESPCFG3_T8M
value|0x01
end_define

begin_comment
comment|/*	Threshold 8 Mode	*/
end_comment

begin_comment
comment|/* Config #3 also different on NCR53CF9x/FAS100A/FAS216/FAS236 */
end_comment

begin_define
define|#
directive|define
name|NCR_F9XCFG3
value|0x0c
end_define

begin_comment
comment|/* RW - Configuration #3	*/
end_comment

begin_define
define|#
directive|define
name|NCRF9XCFG3_IDM
value|0x80
end_define

begin_comment
comment|/*	ID Message Res Check	*/
end_comment

begin_define
define|#
directive|define
name|NCRF9XCFG3_QTE
value|0x40
end_define

begin_comment
comment|/*	Queue Tag Enable	*/
end_comment

begin_define
define|#
directive|define
name|NCRF9XCFG3_CDB
value|0x20
end_define

begin_comment
comment|/*	CDB 10-bytes OK		*/
end_comment

begin_define
define|#
directive|define
name|NCRF9XCFG3_FSCSI
value|0x10
end_define

begin_comment
comment|/*	Fast SCSI		*/
end_comment

begin_define
define|#
directive|define
name|NCRF9XCFG3_FCLK
value|0x08
end_define

begin_comment
comment|/*	Fast Clock (>25MHz)	*/
end_comment

begin_define
define|#
directive|define
name|NCRF9XCFG3_SRESB
value|0x04
end_define

begin_comment
comment|/*	Save Residual Byte	*/
end_comment

begin_define
define|#
directive|define
name|NCRF9XCFG3_ADMA
value|0x02
end_define

begin_comment
comment|/*	Alternate DMA Mode	*/
end_comment

begin_define
define|#
directive|define
name|NCRF9XCFG3_T8M
value|0x01
end_define

begin_comment
comment|/*	Threshold 8 Mode	*/
end_comment

begin_comment
comment|/* Config #3 on FAS366 */
end_comment

begin_define
define|#
directive|define
name|NCRFASCFG3_OBAUTO
value|0x80
end_define

begin_comment
comment|/*	auto push odd-byte to DMA */
end_comment

begin_define
define|#
directive|define
name|NCRFASCFG3_EWIDE
value|0x40
end_define

begin_comment
comment|/* 	Enable Wide-SCSI     */
end_comment

begin_define
define|#
directive|define
name|NCRFASCFG3_IDBIT3
value|0x20
end_define

begin_comment
comment|/* 	Bit 3 of HME SCSI-ID */
end_comment

begin_define
define|#
directive|define
name|NCRFASCFG3_IDRESCHK
value|0x10
end_define

begin_comment
comment|/* 	ID message checking */
end_comment

begin_define
define|#
directive|define
name|NCRFASCFG3_QUENB
value|0x08
end_define

begin_comment
comment|/* 	3-byte msg support */
end_comment

begin_define
define|#
directive|define
name|NCRFASCFG3_CDB10
value|0x04
end_define

begin_comment
comment|/* 	group 2 scsi-2 support */
end_comment

begin_define
define|#
directive|define
name|NCRFASCFG3_FASTSCSI
value|0x02
end_define

begin_comment
comment|/* 	10 MB/S fast scsi mode */
end_comment

begin_define
define|#
directive|define
name|NCRFASCFG3_FASTCLK
value|0x01
end_define

begin_comment
comment|/* 	fast clock mode */
end_comment

begin_comment
comment|/* Config #4 only on ESP406/FAS408 */
end_comment

begin_define
define|#
directive|define
name|NCR_CFG4
value|0x0d
end_define

begin_comment
comment|/* RW - Configuration #4	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG4_CRS1
value|0x80
end_define

begin_comment
comment|/*	Select register set #1	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG4_RSVD
value|0x7b
end_define

begin_comment
comment|/*	reserved		*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG4_ACTNEG
value|0x04
end_define

begin_comment
comment|/*	Active negation		*/
end_comment

begin_comment
comment|/*    The following registers are only on the ESP406/FAS408.  The    documentation refers to them as "Control Register Set #1".    These are the registers that are visible when bit 7 of    register 0x0d is set.  This bit is common to both register sets. */
end_comment

begin_define
define|#
directive|define
name|NCR_JMP
value|0x00
end_define

begin_comment
comment|/* RO - Jumper Sense Register	*/
end_comment

begin_define
define|#
directive|define
name|NCRJMP_RSVD
value|0xc0
end_define

begin_comment
comment|/*	reserved		*/
end_comment

begin_define
define|#
directive|define
name|NCRJMP_ROMSZ
value|0x20
end_define

begin_comment
comment|/*	ROM Size 1=16K, 0=32K	*/
end_comment

begin_define
define|#
directive|define
name|NCRJMP_J4
value|0x10
end_define

begin_comment
comment|/*	Jumper #4		*/
end_comment

begin_define
define|#
directive|define
name|NCRJMP_J3
value|0x08
end_define

begin_comment
comment|/*	Jumper #3		*/
end_comment

begin_define
define|#
directive|define
name|NCRJMP_J2
value|0x04
end_define

begin_comment
comment|/*	Jumper #2		*/
end_comment

begin_define
define|#
directive|define
name|NCRJMP_J1
value|0x02
end_define

begin_comment
comment|/*	Jumper #1		*/
end_comment

begin_define
define|#
directive|define
name|NCRJMP_J0
value|0x01
end_define

begin_comment
comment|/*	Jumper #0		*/
end_comment

begin_define
define|#
directive|define
name|NCR_PIOFIFO
value|0x04
end_define

begin_comment
comment|/* WO - PIO FIFO, 4 bytes deep	*/
end_comment

begin_define
define|#
directive|define
name|NCR_PSTAT
value|0x08
end_define

begin_comment
comment|/* RW - PIO Status Register	*/
end_comment

begin_define
define|#
directive|define
name|NCRPSTAT_PERR
value|0x80
end_define

begin_comment
comment|/*	PIO Error		*/
end_comment

begin_define
define|#
directive|define
name|NCRPSTAT_SIRQ
value|0x40
end_define

begin_comment
comment|/*	Active High of SCSI IRQ */
end_comment

begin_define
define|#
directive|define
name|NCRPSTAT_ATAI
value|0x20
end_define

begin_comment
comment|/*	ATA IRQ			*/
end_comment

begin_define
define|#
directive|define
name|NCRPSTAT_FEMPT
value|0x10
end_define

begin_comment
comment|/*	PIO FIFO Empty		*/
end_comment

begin_define
define|#
directive|define
name|NCRPSTAT_F13
value|0x08
end_define

begin_comment
comment|/*	PIO FIFO 1/3		*/
end_comment

begin_define
define|#
directive|define
name|NCRPSTAT_F23
value|0x04
end_define

begin_comment
comment|/*	PIO FIFO 2/3		*/
end_comment

begin_define
define|#
directive|define
name|NCRPSTAT_FFULL
value|0x02
end_define

begin_comment
comment|/*	PIO FIFO Full		*/
end_comment

begin_define
define|#
directive|define
name|NCRPSTAT_PIOM
value|0x01
end_define

begin_comment
comment|/*	PIO/DMA Mode		*/
end_comment

begin_define
define|#
directive|define
name|NCR_PIOI
value|0x0b
end_define

begin_comment
comment|/* RW - PIO Interrupt Enable	*/
end_comment

begin_define
define|#
directive|define
name|NCRPIOI_RSVD
value|0xe0
end_define

begin_comment
comment|/*	reserved		*/
end_comment

begin_define
define|#
directive|define
name|NCRPIOI_EMPTY
value|0x10
end_define

begin_comment
comment|/*	IRQ When Empty		*/
end_comment

begin_define
define|#
directive|define
name|NCRPIOI_13
value|0x08
end_define

begin_comment
comment|/*	IRQ When 1/3		*/
end_comment

begin_define
define|#
directive|define
name|NCRPIOI_23
value|0x04
end_define

begin_comment
comment|/*	IRQ When 2/3		*/
end_comment

begin_define
define|#
directive|define
name|NCRPIOI_FULL
value|0x02
end_define

begin_comment
comment|/*	IRQ When Full		*/
end_comment

begin_define
define|#
directive|define
name|NCRPIOI_FINV
value|0x01
end_define

begin_comment
comment|/*	Flag Invert		*/
end_comment

begin_define
define|#
directive|define
name|NCR_CFG5
value|0x0d
end_define

begin_comment
comment|/* RW - Configuration #5	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG5_CRS1
value|0x80
end_define

begin_comment
comment|/*	Select Register Set #1	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG5_SRAM
value|0x40
end_define

begin_comment
comment|/*	SRAM Memory Map		*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG5_AADDR
value|0x20
end_define

begin_comment
comment|/*	Auto Address		*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG5_PTRINC
value|0x10
end_define

begin_comment
comment|/*	Pointer Increment	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG5_LOWPWR
value|0x08
end_define

begin_comment
comment|/*	Low Power Mode		*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG5_SINT
value|0x04
end_define

begin_comment
comment|/*	SCSI Interrupt Enable	*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG5_INTP
value|0x02
end_define

begin_comment
comment|/*	INT Polarity		*/
end_comment

begin_define
define|#
directive|define
name|NCRCFG5_AINT
value|0x01
end_define

begin_comment
comment|/*	ATA Interrupt Enable	*/
end_comment

begin_define
define|#
directive|define
name|NCR_SIGNTR
value|0x0e
end_define

begin_comment
comment|/* RO - Signature		*/
end_comment

begin_comment
comment|/* Am53c974 Config #3 */
end_comment

begin_define
define|#
directive|define
name|NCR_AMDCFG3
value|0x0c
end_define

begin_comment
comment|/* RW - Configuration #3	*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG3_IDM
value|0x80
end_define

begin_comment
comment|/*	ID Message Res Check	*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG3_QTE
value|0x40
end_define

begin_comment
comment|/*	Queue Tag Enable	*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG3_CDB
value|0x20
end_define

begin_comment
comment|/*	CDB 10-bytes OK		*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG3_FSCSI
value|0x10
end_define

begin_comment
comment|/*	Fast SCSI		*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG3_FCLK
value|0x08
end_define

begin_comment
comment|/*	Fast Clock (40MHz)	*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG3_RSVD
value|0x07
end_define

begin_comment
comment|/*	Reserved		*/
end_comment

begin_comment
comment|/* Am53c974 Config #4 */
end_comment

begin_define
define|#
directive|define
name|NCR_AMDCFG4
value|0x0d
end_define

begin_comment
comment|/* RW - Configuration #4	*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG4_GE
value|0xc0
end_define

begin_comment
comment|/*	Glitch Eater		*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG4_GE12NS
value|0x00
end_define

begin_comment
comment|/*	Signal window 12ns	*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG4_GE25NS
value|0x80
end_define

begin_comment
comment|/*	Signal window 25ns	*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG4_GE35NS
value|0x40
end_define

begin_comment
comment|/*	Signal window 35ns	*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG4_GE0NS
value|0xc0
end_define

begin_comment
comment|/*	Signal window 0ns	*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG4_PWD
value|0x20
end_define

begin_comment
comment|/*	Reduced power feature	*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG4_RSVD
value|0x13
end_define

begin_comment
comment|/*	Reserved		*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG4_RAE
value|0x08
end_define

begin_comment
comment|/*	Active neg. REQ/ACK	*/
end_comment

begin_define
define|#
directive|define
name|NCRAMDCFG4_RADE
value|0x04
end_define

begin_comment
comment|/*	Active neg. REQ/ACK/DAT	*/
end_comment

begin_comment
comment|/*  * FAS366  */
end_comment

begin_define
define|#
directive|define
name|NCR_RCL
value|NCR_TCH
end_define

begin_comment
comment|/* Recommand counter low */
end_comment

begin_define
define|#
directive|define
name|NCR_RCH
value|0xf
end_define

begin_comment
comment|/* Recommand counter high */
end_comment

begin_define
define|#
directive|define
name|NCR_UID
value|NCR_RCL
end_define

begin_comment
comment|/* fas366 part-uniq id */
end_comment

begin_comment
comment|/* status register #2 definitions (read	only) */
end_comment

begin_define
define|#
directive|define
name|NCR_STAT2
value|NCR_CCF
end_define

begin_define
define|#
directive|define
name|NCRFAS_STAT2_SEQCNT
value|0x01
end_define

begin_comment
comment|/* Sequence counter bit 7-3 enabled */
end_comment

begin_define
define|#
directive|define
name|NCRFAS_STAT2_FLATCHED
value|0x02
end_define

begin_comment
comment|/* FIFO flags register latched */
end_comment

begin_define
define|#
directive|define
name|NCRFAS_STAT2_CLATCHED
value|0x04
end_define

begin_comment
comment|/* Xfer cntr& recommand ctr	latched */
end_comment

begin_define
define|#
directive|define
name|NCRFAS_STAT2_CACTIVE
value|0x08
end_define

begin_comment
comment|/* Command register is active */
end_comment

begin_define
define|#
directive|define
name|NCRFAS_STAT2_SCSI16
value|0x10
end_define

begin_comment
comment|/* SCSI interface is	wide */
end_comment

begin_define
define|#
directive|define
name|NCRFAS_STAT2_ISHUTTLE
value|0x20
end_define

begin_comment
comment|/* FIFO Top register	contains 1 byte */
end_comment

begin_define
define|#
directive|define
name|NCRFAS_STAT2_OSHUTTLE
value|0x40
end_define

begin_comment
comment|/* next byte	from FIFO is MSB */
end_comment

begin_define
define|#
directive|define
name|NCRFAS_STAT2_EMPTY
value|0x80
end_define

begin_comment
comment|/* FIFO is empty */
end_comment

end_unit

