begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: ncr53c500reg.h,v 1.5 1998/12/26 11:50:01 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1995, 1996, 1997, 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *  Copyright (c) 1995, 1996, 1997, 1998  *	Naofumi HONDA. All rights reserved.  *  Copyright (c) 1995, 1996, 1997, 1998  *	Kouichi Matsuda. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NCR53C500REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_NCR53C500REG_H_
end_define

begin_comment
comment|/* Control Register Set 0 */
end_comment

begin_define
define|#
directive|define
name|NCVIOSZ
value|0x10
end_define

begin_define
define|#
directive|define
name|cr0_tclsb
value|0x00
end_define

begin_comment
comment|/* RW - Transfer Count Low	*/
end_comment

begin_define
define|#
directive|define
name|cr0_tcmsb
value|0x01
end_define

begin_comment
comment|/* RW - Transfer Count Mid	*/
end_comment

begin_define
define|#
directive|define
name|cr0_sfifo
value|0x02
end_define

begin_comment
comment|/* RW - FIFO data		*/
end_comment

begin_define
define|#
directive|define
name|cr0_cmd
value|0x03
end_define

begin_comment
comment|/* RW - Command (2 deep)	*/
end_comment

begin_define
define|#
directive|define
name|cr0_stat
value|0x04
end_define

begin_comment
comment|/* RO - Status			*/
end_comment

begin_define
define|#
directive|define
name|cr0_dstid
value|0x04
end_define

begin_comment
comment|/* WO - Select/Reselect Bus ID	*/
end_comment

begin_define
define|#
directive|define
name|cr0_istat
value|0x05
end_define

begin_comment
comment|/* RO - Interrupt		*/
end_comment

begin_define
define|#
directive|define
name|cr0_srtout
value|0x05
end_define

begin_comment
comment|/* WO - Select/Reselect Timeout	*/
end_comment

begin_define
define|#
directive|define
name|cr0_seq
value|0x06
end_define

begin_comment
comment|/* RO - Sequence Step		*/
end_comment

begin_define
define|#
directive|define
name|cr0_period
value|0x06
end_define

begin_comment
comment|/* WO - Synch Transfer Period	*/
end_comment

begin_define
define|#
directive|define
name|cr0_sffl
value|0x07
end_define

begin_comment
comment|/* RO - FIFO FLags		*/
end_comment

begin_define
define|#
directive|define
name|cr0_offs
value|0x07
end_define

begin_comment
comment|/* WO - Synch Ofset		*/
end_comment

begin_define
define|#
directive|define
name|cr0_cfg1
value|0x08
end_define

begin_comment
comment|/* RW - Configuration #1	*/
end_comment

begin_define
define|#
directive|define
name|cr0_clk
value|0x09
end_define

begin_comment
comment|/* WO - Clock Conversion Factor	*/
end_comment

begin_define
define|#
directive|define
name|cr0_tst
value|0x0a
end_define

begin_comment
comment|/* WO - Test (Chip Test Only)	*/
end_comment

begin_define
define|#
directive|define
name|cr0_cfg2
value|0x0b
end_define

begin_comment
comment|/* RW - Configuration #2	*/
end_comment

begin_define
define|#
directive|define
name|cr0_cfg3
value|0x0c
end_define

begin_comment
comment|/* RW - Configuration #3	*/
end_comment

begin_define
define|#
directive|define
name|cr0_cfg4
value|0x0d
end_define

begin_comment
comment|/* RW - Configuration #4	*/
end_comment

begin_define
define|#
directive|define
name|cr0_tchsb
value|0x0e
end_define

begin_comment
comment|/* RW - Transfer Count High	*/
end_comment

begin_define
define|#
directive|define
name|cr0_fifo_bottom
value|0x0f
end_define

begin_comment
comment|/* WO - FIFO bottom		*/
end_comment

begin_comment
comment|/* Control Register Set 1 */
end_comment

begin_define
define|#
directive|define
name|cr1_jumper
value|0x00
end_define

begin_comment
comment|/* RW - Jumper Sense Port	*/
end_comment

begin_define
define|#
directive|define
name|cr1_sram_ptr
value|0x01
end_define

begin_comment
comment|/* RW - SRAM Address Pointer	*/
end_comment

begin_define
define|#
directive|define
name|cr1_sram_data
value|0x02
end_define

begin_comment
comment|/* RW - SRAM Data		*/
end_comment

begin_define
define|#
directive|define
name|cr1_fdata
value|0x04
end_define

begin_comment
comment|/* RW - PIO FIFO		*/
end_comment

begin_define
define|#
directive|define
name|cr1_fstat
value|0x08
end_define

begin_comment
comment|/* RW - PIO Status		*/
end_comment

begin_define
define|#
directive|define
name|cr1_atacmd
value|0x09
end_define

begin_comment
comment|/* RW - ATA Command/Status	*/
end_comment

begin_define
define|#
directive|define
name|cr1_ataerr
value|0x0a
end_define

begin_comment
comment|/* RW - ATA Features/Error	*/
end_comment

begin_define
define|#
directive|define
name|cr1_pflag
value|0x0b
end_define

begin_comment
comment|/* RW - PIO Flag Interrupt Enable	*/
end_comment

begin_define
define|#
directive|define
name|cr1_cfg5
value|0x0d
end_define

begin_comment
comment|/* RW - Configuration #5	*/
end_comment

begin_define
define|#
directive|define
name|cr1_sig
value|0x0e
end_define

begin_comment
comment|/* RO - Signature		*/
end_comment

begin_define
define|#
directive|define
name|cr1_cfg6
value|0x0f
end_define

begin_comment
comment|/* RW - Configuration #6	*/
end_comment

begin_comment
comment|/* atacmd (MPS110 ONLY) */
end_comment

begin_define
define|#
directive|define
name|ATACMD_POWDOWN
value|0x2d
end_define

begin_define
define|#
directive|define
name|ATACMD_ENGAGE
value|0x24
end_define

begin_comment
comment|/* cr0_sffl regster */
end_comment

begin_define
define|#
directive|define
name|CR0_SFFLR_BMASK
value|0x1f
end_define

begin_comment
comment|/* scsi fifo byte mask */
end_comment

begin_comment
comment|/* cfg4 */
end_comment

begin_define
define|#
directive|define
name|C4_ANE
value|0x04
end_define

begin_comment
comment|/* cfg2 */
end_comment

begin_define
define|#
directive|define
name|C2_SCSI2
value|0x08
end_define

begin_comment
comment|/* SCSI-2 Enable	*/
end_comment

begin_define
define|#
directive|define
name|C2_FE
value|0x40
end_define

begin_comment
comment|/* Features Enable	*/
end_comment

begin_comment
comment|/* cfg1 */
end_comment

begin_define
define|#
directive|define
name|C1_SLOW
value|0x80
end_define

begin_comment
comment|/* Slow Cable Mode	*/
end_comment

begin_define
define|#
directive|define
name|C1_SRR
value|0x40
end_define

begin_comment
comment|/* SCSI Reset Rep Int Dis	*/
end_comment

begin_define
define|#
directive|define
name|C1_PARENB
value|0x10
end_define

begin_comment
comment|/* Enable Parity Check	*/
end_comment

begin_comment
comment|/* clk factor */
end_comment

begin_define
define|#
directive|define
name|CLK_40M_F
value|0x00
end_define

begin_define
define|#
directive|define
name|CLK_25M_F
value|0x05
end_define

begin_define
define|#
directive|define
name|CLK_30M_F
value|0x06
end_define

begin_define
define|#
directive|define
name|CLK_35M_F
value|0x07
end_define

begin_comment
comment|/* interrupt status register */
end_comment

begin_define
define|#
directive|define
name|INTR_SBR
value|0x80
end_define

begin_comment
comment|/* SCSI Bus Reset	*/
end_comment

begin_define
define|#
directive|define
name|INTR_ILL
value|0x40
end_define

begin_comment
comment|/* Illegal Command	*/
end_comment

begin_define
define|#
directive|define
name|INTR_DIS
value|0x20
end_define

begin_comment
comment|/* Disconnect		*/
end_comment

begin_define
define|#
directive|define
name|INTR_BS
value|0x10
end_define

begin_comment
comment|/* Bus Service		*/
end_comment

begin_define
define|#
directive|define
name|INTR_FC
value|0x08
end_define

begin_comment
comment|/* Function Complete	*/
end_comment

begin_define
define|#
directive|define
name|INTR_RESEL
value|0x04
end_define

begin_comment
comment|/* Reselected		*/
end_comment

begin_define
define|#
directive|define
name|INTR_SELATN
value|0x02
end_define

begin_comment
comment|/* Select with ATN	*/
end_comment

begin_define
define|#
directive|define
name|INTR_SEL
value|0x01
end_define

begin_comment
comment|/* Selected		*/
end_comment

begin_define
define|#
directive|define
name|INTR_RESELECT
value|(INTR_RESEL | INTR_FC)
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|STAT_INT
value|0x80
end_define

begin_comment
comment|/* Interrupt		*/
end_comment

begin_define
define|#
directive|define
name|STAT_GE
value|0x40
end_define

begin_comment
comment|/* Gross Error		*/
end_comment

begin_define
define|#
directive|define
name|STAT_PE
value|0x20
end_define

begin_comment
comment|/* Parity Error		*/
end_comment

begin_define
define|#
directive|define
name|STAT_TC
value|0x10
end_define

begin_comment
comment|/* Terminal Count	*/
end_comment

begin_comment
comment|/* phase bits */
end_comment

begin_define
define|#
directive|define
name|IOI
value|0x01
end_define

begin_define
define|#
directive|define
name|CDI
value|0x02
end_define

begin_define
define|#
directive|define
name|MSGI
value|0x04
end_define

begin_comment
comment|/* Information transfer phases */
end_comment

begin_define
define|#
directive|define
name|DATA_OUT_PHASE
value|(0)
end_define

begin_define
define|#
directive|define
name|DATA_IN_PHASE
value|(IOI)
end_define

begin_define
define|#
directive|define
name|COMMAND_PHASE
value|(CDI)
end_define

begin_define
define|#
directive|define
name|STATUS_PHASE
value|(CDI|IOI)
end_define

begin_define
define|#
directive|define
name|MESSAGE_OUT_PHASE
value|(MSGI|CDI)
end_define

begin_define
define|#
directive|define
name|MESSAGE_IN_PHASE
value|(MSGI|CDI|IOI)
end_define

begin_define
define|#
directive|define
name|PHASE_MASK
value|(MSGI|CDI|IOI)
end_define

begin_comment
comment|/* fifo status register */
end_comment

begin_define
define|#
directive|define
name|FIFO_SMASK
value|0x1e
end_define

begin_define
define|#
directive|define
name|FIFO_E
value|0x10
end_define

begin_comment
comment|/* fifo empty */
end_comment

begin_define
define|#
directive|define
name|FIFO_B
value|0x00
end_define

begin_comment
comment|/* there exists any */
end_comment

begin_define
define|#
directive|define
name|FIFO_1
value|0x08
end_define

begin_comment
comment|/* 1/3<= bytes< 2/3 */
end_comment

begin_define
define|#
directive|define
name|FIFO_2
value|0x04
end_define

begin_comment
comment|/* 2/3<= bytes< full */
end_comment

begin_define
define|#
directive|define
name|FIFO_F
value|0x02
end_define

begin_comment
comment|/* full */
end_comment

begin_define
define|#
directive|define
name|FIFO_EN
value|0x01
end_define

begin_comment
comment|/* fifo direction */
end_comment

begin_define
define|#
directive|define
name|FIFO_BRK
value|0x40
end_define

begin_comment
comment|/* phase miss */
end_comment

begin_define
define|#
directive|define
name|FIFO_F_SZ
value|128
end_define

begin_define
define|#
directive|define
name|FIFO_1_SZ
value|44
end_define

begin_define
define|#
directive|define
name|FIFO_2_SZ
value|84
end_define

begin_comment
comment|/* pflags */
end_comment

begin_define
define|#
directive|define
name|PFR_WRITE
value|0x01
end_define

begin_comment
comment|/* Commands */
end_comment

begin_define
define|#
directive|define
name|CMD_DMA
value|0x80
end_define

begin_comment
comment|/* DMA Bit			*/
end_comment

begin_define
define|#
directive|define
name|CMD_NOP
value|0x00
end_define

begin_comment
comment|/* No Operation			*/
end_comment

begin_define
define|#
directive|define
name|CMD_FLUSH
value|0x01
end_define

begin_comment
comment|/* Flush FIFO			*/
end_comment

begin_define
define|#
directive|define
name|CMD_RSTCHIP
value|0x02
end_define

begin_comment
comment|/* Reset Chip			*/
end_comment

begin_define
define|#
directive|define
name|CMD_RSTSCSI
value|0x03
end_define

begin_comment
comment|/* Reset SCSI Bus		*/
end_comment

begin_define
define|#
directive|define
name|CMD_RESEL
value|0x40
end_define

begin_comment
comment|/* Reselect Sequence		*/
end_comment

begin_define
define|#
directive|define
name|CMD_SELNATN
value|0x41
end_define

begin_comment
comment|/* Select without ATN		*/
end_comment

begin_define
define|#
directive|define
name|CMD_SELATN
value|0x42
end_define

begin_comment
comment|/* Select with ATN		*/
end_comment

begin_define
define|#
directive|define
name|CMD_SELATNS
value|0x43
end_define

begin_comment
comment|/* Select with ATN& Stop	*/
end_comment

begin_define
define|#
directive|define
name|CMD_ENSEL
value|0x44
end_define

begin_comment
comment|/* Enable (Re)Selection		*/
end_comment

begin_define
define|#
directive|define
name|CMD_DISSEL
value|0x45
end_define

begin_comment
comment|/* Disable (Re)Selection	*/
end_comment

begin_define
define|#
directive|define
name|CMD_SELATN3
value|0x46
end_define

begin_comment
comment|/* Select with ATN3		*/
end_comment

begin_define
define|#
directive|define
name|CMD_RESEL3
value|0x47
end_define

begin_comment
comment|/* Reselect3 Sequence		*/
end_comment

begin_define
define|#
directive|define
name|CMD_SNDMSG
value|0x20
end_define

begin_comment
comment|/* Send Message			*/
end_comment

begin_define
define|#
directive|define
name|CMD_SNDSTAT
value|0x21
end_define

begin_comment
comment|/* Send Status			*/
end_comment

begin_define
define|#
directive|define
name|CMD_SNDDATA
value|0x22
end_define

begin_comment
comment|/* Send Data			*/
end_comment

begin_define
define|#
directive|define
name|CMD_DISCSEQ
value|0x23
end_define

begin_comment
comment|/* Disconnect Sequence		*/
end_comment

begin_define
define|#
directive|define
name|CMD_TERMSEQ
value|0x24
end_define

begin_comment
comment|/* Terminate Sequence		*/
end_comment

begin_define
define|#
directive|define
name|CMD_TCCS
value|0x25
end_define

begin_comment
comment|/* Target Command Comp Seq	*/
end_comment

begin_define
define|#
directive|define
name|CMD_DISC
value|0x27
end_define

begin_comment
comment|/* Disconnect			*/
end_comment

begin_define
define|#
directive|define
name|CMD_RECMSG
value|0x28
end_define

begin_comment
comment|/* Receive Message		*/
end_comment

begin_define
define|#
directive|define
name|CMD_RECCMD
value|0x29
end_define

begin_comment
comment|/* Receive Command		*/
end_comment

begin_define
define|#
directive|define
name|CMD_RECDATA
value|0x2a
end_define

begin_comment
comment|/* Receive Data			*/
end_comment

begin_define
define|#
directive|define
name|CMD_RECCSEQ
value|0x2b
end_define

begin_comment
comment|/* Receive Command Sequence	*/
end_comment

begin_define
define|#
directive|define
name|CMD_ABORT
value|0x04
end_define

begin_comment
comment|/* Target Abort DMA		*/
end_comment

begin_define
define|#
directive|define
name|CMD_TRANS
value|0x10
end_define

begin_comment
comment|/* Transfer Information		*/
end_comment

begin_define
define|#
directive|define
name|CMD_ICCS
value|0x11
end_define

begin_comment
comment|/* Initiator Cmd Comp Seq	*/
end_comment

begin_define
define|#
directive|define
name|CMD_MSGOK
value|0x12
end_define

begin_comment
comment|/* Message Accepted		*/
end_comment

begin_define
define|#
directive|define
name|CMD_TRPAD
value|0x18
end_define

begin_comment
comment|/* Transfer Pad			*/
end_comment

begin_define
define|#
directive|define
name|CMD_SETATN
value|0x1a
end_define

begin_comment
comment|/* Set ATN			*/
end_comment

begin_define
define|#
directive|define
name|CMD_RSTATN
value|0x1b
end_define

begin_comment
comment|/* Reset ATN			*/
end_comment

begin_comment
comment|/* Default timeout */
end_comment

begin_define
define|#
directive|define
name|SEL_TOUT
value|0xa3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NCR53C500REG_H_ */
end_comment

end_unit

