begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: sbicreg.h,v 1.2 1994/10/26 02:04:40 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Van Jacobson of Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)scsireg.h	7.3 (Berkeley) 2/5/91  */
end_comment

begin_comment
comment|/*  * Ported to PC-9801 by Yoshio Kimura, 1994  *	last update 09/24/1994  */
end_comment

begin_comment
comment|/*  * AMD AM33C93A SCSI interface hardware description.  *  * Using parts of the Mach scsi driver for the 33C93  */
end_comment

begin_define
define|#
directive|define
name|SBIC_myid
value|0
end_define

begin_define
define|#
directive|define
name|SBIC_cdbsize
value|0
end_define

begin_define
define|#
directive|define
name|SBIC_control
value|1
end_define

begin_define
define|#
directive|define
name|SBIC_timeo
value|2
end_define

begin_define
define|#
directive|define
name|SBIC_cdb1
value|3
end_define

begin_define
define|#
directive|define
name|SBIC_tsecs
value|3
end_define

begin_define
define|#
directive|define
name|SBIC_cdb2
value|4
end_define

begin_define
define|#
directive|define
name|SBIC_theads
value|4
end_define

begin_define
define|#
directive|define
name|SBIC_cdb3
value|5
end_define

begin_define
define|#
directive|define
name|SBIC_tcyl_hi
value|5
end_define

begin_define
define|#
directive|define
name|SBIC_cdb4
value|6
end_define

begin_define
define|#
directive|define
name|SBIC_tcyl_lo
value|6
end_define

begin_define
define|#
directive|define
name|SBIC_cdb5
value|7
end_define

begin_define
define|#
directive|define
name|SBIC_addr_hi
value|7
end_define

begin_define
define|#
directive|define
name|SBIC_cdb6
value|8
end_define

begin_define
define|#
directive|define
name|SBIC_addr_2
value|8
end_define

begin_define
define|#
directive|define
name|SBIC_cdb7
value|9
end_define

begin_define
define|#
directive|define
name|SBIC_addr_3
value|9
end_define

begin_define
define|#
directive|define
name|SBIC_cdb8
value|10
end_define

begin_define
define|#
directive|define
name|SBIC_addr_lo
value|10
end_define

begin_define
define|#
directive|define
name|SBIC_cdb9
value|11
end_define

begin_define
define|#
directive|define
name|SBIC_secno
value|11
end_define

begin_define
define|#
directive|define
name|SBIC_cdb10
value|12
end_define

begin_define
define|#
directive|define
name|SBIC_headno
value|12
end_define

begin_define
define|#
directive|define
name|SBIC_cdb11
value|13
end_define

begin_define
define|#
directive|define
name|SBIC_cylno_hi
value|13
end_define

begin_define
define|#
directive|define
name|SBIC_cdb12
value|14
end_define

begin_define
define|#
directive|define
name|SBIC_cylno_lo
value|14
end_define

begin_define
define|#
directive|define
name|SBIC_tlun
value|15
end_define

begin_define
define|#
directive|define
name|SBIC_cmd_phase
value|16
end_define

begin_define
define|#
directive|define
name|SBIC_syn
value|17
end_define

begin_define
define|#
directive|define
name|SBIC_count_hi
value|18
end_define

begin_define
define|#
directive|define
name|SBIC_count_med
value|19
end_define

begin_define
define|#
directive|define
name|SBIC_count_lo
value|20
end_define

begin_define
define|#
directive|define
name|SBIC_selid
value|21
end_define

begin_define
define|#
directive|define
name|SBIC_rselid
value|22
end_define

begin_define
define|#
directive|define
name|SBIC_csr
value|23
end_define

begin_define
define|#
directive|define
name|SBIC_cmd
value|24
end_define

begin_define
define|#
directive|define
name|SBIC_data
value|25
end_define

begin_define
define|#
directive|define
name|SBIC_mem_bank
value|48
end_define

begin_define
define|#
directive|define
name|SBIC_mem_win
value|49
end_define

begin_define
define|#
directive|define
name|SBIC_reserved1
value|50
end_define

begin_define
define|#
directive|define
name|SBIC_reset_int
value|51
end_define

begin_define
define|#
directive|define
name|SBIC_reserved2
value|52
end_define

begin_define
define|#
directive|define
name|SBIC_reserved3
value|53
end_define

begin_comment
comment|/* sbic_asr is addressed directly */
end_comment

begin_comment
comment|/*  *	Register defines  */
end_comment

begin_comment
comment|/*  * Auxiliary Status Register  */
end_comment

begin_define
define|#
directive|define
name|SBIC_ASR_INT
value|0x80
end_define

begin_comment
comment|/* Interrupt pending */
end_comment

begin_define
define|#
directive|define
name|SBIC_ASR_LCI
value|0x40
end_define

begin_comment
comment|/* Last command ignored */
end_comment

begin_define
define|#
directive|define
name|SBIC_ASR_BSY
value|0x20
end_define

begin_comment
comment|/* Busy, only cmd/data/asr readable */
end_comment

begin_define
define|#
directive|define
name|SBIC_ASR_CIP
value|0x10
end_define

begin_comment
comment|/* Busy, cmd unavail also */
end_comment

begin_define
define|#
directive|define
name|SBIC_ASR_xxx
value|0x0c
end_define

begin_define
define|#
directive|define
name|SBIC_ASR_PE
value|0x02
end_define

begin_comment
comment|/* Parity error (even) */
end_comment

begin_define
define|#
directive|define
name|SBIC_ASR_DBR
value|0x01
end_define

begin_comment
comment|/* Data Buffer Ready */
end_comment

begin_comment
comment|/*  * My ID register, and/or CDB Size  */
end_comment

begin_define
define|#
directive|define
name|SBIC_ID_FS_8_10
value|0x00
end_define

begin_comment
comment|/* Input clock is  8-10 Mhz */
end_comment

begin_comment
comment|/* 11 Mhz is invalid */
end_comment

begin_define
define|#
directive|define
name|SBIC_ID_FS_12_15
value|0x40
end_define

begin_comment
comment|/* Input clock is 12-15 Mhz */
end_comment

begin_define
define|#
directive|define
name|SBIC_ID_FS_16_20
value|0x80
end_define

begin_comment
comment|/* Input clock is 16-20 Mhz */
end_comment

begin_define
define|#
directive|define
name|SBIC_ID_EHP
value|0x10
end_define

begin_comment
comment|/* Enable host parity */
end_comment

begin_define
define|#
directive|define
name|SBIC_ID_EAF
value|0x08
end_define

begin_comment
comment|/* Enable Advanced Features */
end_comment

begin_define
define|#
directive|define
name|SBIC_ID_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|SBIC_ID_CBDSIZE_MASK
value|0x0f
end_define

begin_comment
comment|/* if unk SCSI cmd group */
end_comment

begin_comment
comment|/*  * Control register  */
end_comment

begin_define
define|#
directive|define
name|SBIC_CTL_DMA
value|0x80
end_define

begin_comment
comment|/* Single byte dma */
end_comment

begin_define
define|#
directive|define
name|SBIC_CTL_DBA_DMA
value|0x40
end_define

begin_comment
comment|/* direct buffer acces (bus master)*/
end_comment

begin_define
define|#
directive|define
name|SBIC_CTL_BURST_DMA
value|0x20
end_define

begin_comment
comment|/* continuous mode (8237) */
end_comment

begin_define
define|#
directive|define
name|SBIC_CTL_NO_DMA
value|0x00
end_define

begin_comment
comment|/* Programmed I/O */
end_comment

begin_define
define|#
directive|define
name|SBIC_CTL_HHP
value|0x10
end_define

begin_comment
comment|/* Halt on host parity error */
end_comment

begin_define
define|#
directive|define
name|SBIC_CTL_EDI
value|0x08
end_define

begin_comment
comment|/* Ending disconnect interrupt */
end_comment

begin_define
define|#
directive|define
name|SBIC_CTL_IDI
value|0x04
end_define

begin_comment
comment|/* Intermediate disconnect interrupt*/
end_comment

begin_define
define|#
directive|define
name|SBIC_CTL_HA
value|0x02
end_define

begin_comment
comment|/* Halt on ATN */
end_comment

begin_define
define|#
directive|define
name|SBIC_CTL_HSP
value|0x01
end_define

begin_comment
comment|/* Halt on SCSI parity error */
end_comment

begin_comment
comment|/*  * Timeout period register  * [val in msecs, input clk in 0.1 Mhz]  */
end_comment

begin_define
define|#
directive|define
name|SBIC_TIMEOUT
parameter_list|(
name|val
parameter_list|,
name|clk
parameter_list|)
value|((((val) * (clk)) / 800) + 1)
end_define

begin_comment
comment|/*  * CDBn registers, note that  *	cdb11 is used for status byte in target mode (send-status-and-cc)  *	cdb12 sez if linked command complete, and w/flag if so  */
end_comment

begin_comment
comment|/*  * Target LUN register  * [holds target status when select-and-xfer]  */
end_comment

begin_define
define|#
directive|define
name|SBIC_TLUN_VALID
value|0x80
end_define

begin_comment
comment|/* did we receive an Identify msg */
end_comment

begin_define
define|#
directive|define
name|SBIC_TLUN_DOK
value|0x40
end_define

begin_comment
comment|/* Disconnect OK */
end_comment

begin_define
define|#
directive|define
name|SBIC_TLUN_xxx
value|0x38
end_define

begin_define
define|#
directive|define
name|SBIC_TLUN_MASK
value|0x07
end_define

begin_comment
comment|/*  * Command Phase register  */
end_comment

begin_define
define|#
directive|define
name|SBIC_CPH_MASK
value|0x7f
end_define

begin_comment
comment|/* values/restarts are cmd specific */
end_comment

begin_define
define|#
directive|define
name|SBIC_CPH
parameter_list|(
name|p
parameter_list|)
value|((p)& SBIC_CPH_MASK)
end_define

begin_comment
comment|/*  * FIFO register  */
end_comment

begin_define
define|#
directive|define
name|SBIC_FIFO_DEEP
value|12
end_define

begin_comment
comment|/*  * maximum possible size in TC registers. Since this is 24 bit, it's easy  */
end_comment

begin_define
define|#
directive|define
name|SBIC_TC_MAX
value|((1<< 24) - 1)
end_define

begin_comment
comment|/*  * Synchronous xfer register  */
end_comment

begin_define
define|#
directive|define
name|SBIC_SYN_OFF_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|SBIC_SYN_MAX_OFFSET
value|SBIC_FIFO_DEEP
end_define

begin_define
define|#
directive|define
name|SBIC_SYN_PER_MASK
value|0x70
end_define

begin_define
define|#
directive|define
name|SBIC_SYN_MIN_PERIOD
value|2
end_define

begin_comment
comment|/* upto 8, encoded as 0 */
end_comment

begin_define
define|#
directive|define
name|SBIC_SYN
parameter_list|(
name|o
parameter_list|,
name|p
parameter_list|)
define|\
value|(((o)& SBIC_SYN_OFF_MASK) | (((p)<< 4)& SBIC_SYN_PER_MASK))
end_define

begin_comment
comment|/*  * Transfer count register  * optimal access macros depend on addressing  */
end_comment

begin_comment
comment|/*  * Destination ID (selid) register  */
end_comment

begin_define
define|#
directive|define
name|SBIC_SID_SCC
value|0x80
end_define

begin_comment
comment|/* Select command chaining (tgt) */
end_comment

begin_define
define|#
directive|define
name|SBIC_SID_DPD
value|0x40
end_define

begin_comment
comment|/* Data phase direction (inittor) */
end_comment

begin_define
define|#
directive|define
name|SBIC_SID_FROM_SCSI
value|0x40
end_define

begin_define
define|#
directive|define
name|SBIC_SID_TO_SCSI
value|0x00
end_define

begin_define
define|#
directive|define
name|SBIC_SID_xxx
value|0x38
end_define

begin_define
define|#
directive|define
name|SBIC_SID_IDMASK
value|0x07
end_define

begin_comment
comment|/*  * Source ID (rselid) register  */
end_comment

begin_define
define|#
directive|define
name|SBIC_RID_ER
value|0x80
end_define

begin_comment
comment|/* Enable reselection */
end_comment

begin_define
define|#
directive|define
name|SBIC_RID_ES
value|0x40
end_define

begin_comment
comment|/* Enable selection */
end_comment

begin_define
define|#
directive|define
name|SBIC_RID_DSP
value|0x20
end_define

begin_comment
comment|/* Disable select parity */
end_comment

begin_define
define|#
directive|define
name|SBIC_RID_SIV
value|0x08
end_define

begin_comment
comment|/* Source ID valid */
end_comment

begin_define
define|#
directive|define
name|SBIC_RID_MASK
value|0x07
end_define

begin_comment
comment|/*  * Status register  */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_CAUSE
value|0xf0
end_define

begin_define
define|#
directive|define
name|SBIC_CSR_RESET
value|0x00
end_define

begin_comment
comment|/* chip was reset */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_CMD_DONE
value|0x10
end_define

begin_comment
comment|/* cmd completed */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_CMD_STOPPED
value|0x20
end_define

begin_comment
comment|/* interrupted or abrted*/
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_CMD_ERR
value|0x40
end_define

begin_comment
comment|/* end with error */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_BUS_SERVICE
value|0x80
end_define

begin_comment
comment|/* REQ pending on the bus */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_QUALIFIER
value|0x0f
end_define

begin_comment
comment|/* Reset State Interrupts */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_RESET
value|0x00
end_define

begin_comment
comment|/* reset w/advanced features*/
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_RESET_AM
value|0x01
end_define

begin_comment
comment|/* reset w/advanced features*/
end_comment

begin_comment
comment|/* Successful Completion Interrupts */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_TARGET
value|0x10
end_define

begin_comment
comment|/* reselect complete */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_INITIATOR
value|0x11
end_define

begin_comment
comment|/* select complete */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_WO_ATN
value|0x13
end_define

begin_comment
comment|/* tgt mode completion */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_W_ATN
value|0x14
end_define

begin_comment
comment|/* ditto */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_XLATED
value|0x15
end_define

begin_comment
comment|/* translate address cmd */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_S_XFERRED
value|0x16
end_define

begin_comment
comment|/* initiator mode completion*/
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_XFERRED
value|0x18
end_define

begin_comment
comment|/* phase in low bits */
end_comment

begin_comment
comment|/* Paused or Aborted Interrupts */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_MSGIN_W_ACK
value|0x20
end_define

begin_comment
comment|/* (I) msgin, ACK asserted*/
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_SDP
value|0x21
end_define

begin_comment
comment|/* (I) SDP msg received */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_SEL_ABRT
value|0x22
end_define

begin_comment
comment|/* sel/resel aborted */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_XFR_PAUSED
value|0x23
end_define

begin_comment
comment|/* (T) no ATN */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_XFR_PAUSED_ATN
value|0x24
end_define

begin_comment
comment|/* (T) ATN is asserted */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_RSLT_AM
value|0x27
end_define

begin_comment
comment|/* (I) lost selection (AM) */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_MIS
value|0x28
end_define

begin_comment
comment|/* (I) xfer aborted, ph mis */
end_comment

begin_comment
comment|/* Terminated Interrupts */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_CMD_INVALID
value|0x40
end_define

begin_define
define|#
directive|define
name|SBIC_CSR_DISC
value|0x41
end_define

begin_comment
comment|/* (I) tgt disconnected */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_SEL_TIMEO
value|0x42
end_define

begin_define
define|#
directive|define
name|SBIC_CSR_PE
value|0x43
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_PE_ATN
value|0x44
end_define

begin_comment
comment|/* ditto, ATN is asserted */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_XLATE_TOOBIG
value|0x45
end_define

begin_define
define|#
directive|define
name|SBIC_CSR_RSLT_NOAM
value|0x46
end_define

begin_comment
comment|/* (I) lost sel, no AM mode */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_BAD_STATUS
value|0x47
end_define

begin_comment
comment|/* status byte was nok */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_MIS_1
value|0x48
end_define

begin_comment
comment|/* ph mis, see low bits */
end_comment

begin_comment
comment|/* Service Required Interrupts */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_RSLT_NI
value|0x80
end_define

begin_comment
comment|/* reselected, no ify msg */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_RSLT_IFY
value|0x81
end_define

begin_comment
comment|/* ditto, AM mode, got ify */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_SLT
value|0x82
end_define

begin_comment
comment|/* selected, no ATN */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_SLT_ATN
value|0x83
end_define

begin_comment
comment|/* selected with ATN */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_ATN
value|0x84
end_define

begin_comment
comment|/* (T) ATN asserted */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_DISC_1
value|0x85
end_define

begin_comment
comment|/* (I) bus is free */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_UNK_GROUP
value|0x87
end_define

begin_comment
comment|/* strange CDB1 */
end_comment

begin_define
define|#
directive|define
name|SBIC_CSR_MIS_2
value|0x88
end_define

begin_comment
comment|/* (I) ph mis, see low bits */
end_comment

begin_define
define|#
directive|define
name|SBIC_PHASE
parameter_list|(
name|csr
parameter_list|)
value|SCSI_PHASE(csr)
end_define

begin_comment
comment|/*  * Command register (command codes)  */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_SBT
value|0x80
end_define

begin_comment
comment|/* Single byte xfer qualifier */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_MASK
value|0x7f
end_define

begin_comment
comment|/* Miscellaneous */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_RESET
value|0x00
end_define

begin_comment
comment|/* (DTI) lev I */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_ABORT
value|0x01
end_define

begin_comment
comment|/* (DTI) lev I */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_DISC
value|0x04
end_define

begin_comment
comment|/* ( TI) lev I */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_SSCC
value|0x0d
end_define

begin_comment
comment|/* ( TI) lev I */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_SET_IDI
value|0x0f
end_define

begin_comment
comment|/* (DTI) lev I */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_XLATE
value|0x18
end_define

begin_comment
comment|/* (DT ) lev II */
end_comment

begin_comment
comment|/* Initiator state */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_SET_ATN
value|0x02
end_define

begin_comment
comment|/* (  I) lev I */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_CLR_ACK
value|0x03
end_define

begin_comment
comment|/* (  I) lev I */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_XFER_PAD
value|0x19
end_define

begin_comment
comment|/* (  I) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_XFER_INFO
value|0x20
end_define

begin_comment
comment|/* (  I) lev II */
end_comment

begin_comment
comment|/* Target state */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_SND_DISC
value|0x0e
end_define

begin_comment
comment|/* ( T ) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_RCV_CMD
value|0x10
end_define

begin_comment
comment|/* ( T ) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_RCV_DATA
value|0x11
end_define

begin_comment
comment|/* ( T ) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_RCV_MSG_OUT
value|0x12
end_define

begin_comment
comment|/* ( T ) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_RCV
value|0x13
end_define

begin_comment
comment|/* ( T ) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_SND_STATUS
value|0x14
end_define

begin_comment
comment|/* ( T ) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_SND_DATA
value|0x15
end_define

begin_comment
comment|/* ( T ) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_SND_MSG_IN
value|0x16
end_define

begin_comment
comment|/* ( T ) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_SND
value|0x17
end_define

begin_comment
comment|/* ( T ) lev II */
end_comment

begin_comment
comment|/* Disconnected state */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_RESELECT
value|0x05
end_define

begin_comment
comment|/* (D  ) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_SEL_ATN
value|0x06
end_define

begin_comment
comment|/* (D  ) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_SEL
value|0x07
end_define

begin_comment
comment|/* (D  ) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_SEL_ATN_XFER
value|0x08
end_define

begin_comment
comment|/* (D I) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_SEL_XFER
value|0x09
end_define

begin_comment
comment|/* (D I) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_RESELECT_RECV
value|0x0a
end_define

begin_comment
comment|/* (DT ) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_RESELECT_SEND
value|0x0b
end_define

begin_comment
comment|/* (DT ) lev II */
end_comment

begin_define
define|#
directive|define
name|SBIC_CMD_WAIT_SEL_RECV
value|0x0c
end_define

begin_comment
comment|/* (DT ) lev II */
end_comment

begin_comment
comment|/* approximate, but we won't do SBT on selects */
end_comment

begin_define
define|#
directive|define
name|sbic_isa_select
parameter_list|(
name|cmd
parameter_list|)
value|(((cmd)> 0x5)&& ((cmd)< 0xa))
end_define

begin_define
define|#
directive|define
name|SBIC_MACHINE_DMA_MODE
value|SBIC_CTL_DMA
end_define

begin_define
define|#
directive|define
name|sbic_read_reg
parameter_list|(
name|iobase
parameter_list|,
name|regno
parameter_list|,
name|val
parameter_list|)
value|do { \ 		outb(iobase, (regno));	\ 		(val) = inb((iobase) + 2); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|sbic_write_reg
parameter_list|(
name|iobase
parameter_list|,
name|regno
parameter_list|,
name|val
parameter_list|)
value|do { \ 		outb(iobase, (regno));	\ 		outb((iobase) + 2, (val)); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_myid
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_myid,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_myid
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_myid,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cdbsize
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cdbsize,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cdbsize
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cdbsize,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_control
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_control,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_control
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_control,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_timeo
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_timeo,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_timeo
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_timeo,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cdb1
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cdb1,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cdb1
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cdb1,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cdb2
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cdb2,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cdb2
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cdb2,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cdb3
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cdb3,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cdb3
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cdb3,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cdb4
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cdb4,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cdb4
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cdb4,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cdb5
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cdb5,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cdb5
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cdb5,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cdb6
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cdb6,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cdb6
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cdb6,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cdb7
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cdb7,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cdb7
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cdb7,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cdb8
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cdb8,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cdb8
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cdb8,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cdb9
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cdb9,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cdb9
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cdb9,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cdb10
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cdb10,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cdb10
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cdb10,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cdb11
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cdb11,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cdb11
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cdb11,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cdb12
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cdb12,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cdb12
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cdb12,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_tlun
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_tlun,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_tlun
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_tlun,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cmd_phase
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cmd_phase,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cmd_phase
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cmd_phase,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_syn
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_syn,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_syn
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_syn,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_count_hi
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_count_hi,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_count_hi
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_count_hi,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_count_med
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_count_med,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_count_med
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_count_med,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_count_lo
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_count_lo,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_count_lo
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_count_lo,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_selid
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_selid,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_selid
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_selid,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_rselid
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_rselid,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_rselid
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_rselid,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_csr
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_csr,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_csr
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_csr,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_cmd
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_cmd,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_cmd
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_cmd,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_data
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_data,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_data
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_data,val)
end_define

begin_define
define|#
directive|define
name|SET_SBIC_mem_bank
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_write_reg(iobase,SBIC_mem_bank,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_mem_bank
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_mem_bank,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_mem_win
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_mem_win,val)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_reset_int
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|sbic_read_reg(iobase,SBIC_reset_int,val)
end_define

begin_define
define|#
directive|define
name|SBIC_TC_PUT
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|do { \ 	sbic_write_reg(iobase,SBIC_count_hi,((val)>>16)); \ 	outb((iobase) + 2, ((val)>>8)); \ 	outb((iobase) + 2, (val)); \ } while (0)
end_define

begin_define
define|#
directive|define
name|SBIC_TC_GET
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|do { \ 	sbic_read_reg(iobase,SBIC_count_hi,(val)); \ 	(val) = ((val)<<8) | inb((iobase) + 2); \ 	(val) = ((val)<<8) | inb((iobase) + 2); \ } while (0)
end_define

begin_define
define|#
directive|define
name|SBIC_LOAD_COMMAND
parameter_list|(
name|iobase
parameter_list|,
name|cmd
parameter_list|,
name|cmdsize
parameter_list|)
value|do { \ 	int n=(cmdsize)-1; \ 	char *ptr = (char*)(cmd); \ 	sbic_write_reg(iobase,SBIC_cdb1,*ptr++); \ 	while (n--> 0) outb((iobase) + 2, *ptr++); \ } while (0)
end_define

begin_define
define|#
directive|define
name|GET_SBIC_asr
parameter_list|(
name|iobase
parameter_list|,
name|val
parameter_list|)
value|(val) = inb(iobase)
end_define

begin_define
define|#
directive|define
name|WAIT_CIP
parameter_list|(
name|iobase
parameter_list|)
value|do { \ 	while (inb(iobase)& SBIC_ASR_CIP) \ 		; \ } while (0)
end_define

begin_comment
comment|/* transmit a byte in programmed I/O mode */
end_comment

begin_define
define|#
directive|define
name|SEND_BYTE
parameter_list|(
name|iobase
parameter_list|,
name|ch
parameter_list|)
value|do { \   WAIT_CIP((iobase)->sc_base); \   SET_SBIC_cmd((iobase)->sc_base, SBIC_CMD_SBT | SBIC_CMD_XFER_INFO); \   SBIC_WAIT(iobase, SBIC_ASR_DBR, 0); \   SET_SBIC_data((iobase)->sc_base, ch); \   } while (0)
end_define

begin_comment
comment|/* receive a byte in programmed I/O mode */
end_comment

begin_define
define|#
directive|define
name|RECV_BYTE
parameter_list|(
name|iobase
parameter_list|,
name|ch
parameter_list|)
value|do { \   WAIT_CIP((iobase)->sc_base); \   SET_SBIC_cmd((iobase)->sc_base, SBIC_CMD_SBT | SBIC_CMD_XFER_INFO); \   SBIC_WAIT(iobase, SBIC_ASR_DBR, 0); \   GET_SBIC_data((iobase)->sc_base, ch); \   } while (0)
end_define

end_unit

