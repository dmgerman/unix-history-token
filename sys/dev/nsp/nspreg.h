begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: nspreg.h,v 1.4.3 2001/06/29 06:27:53 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NSPREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_NSPREG_H_
end_define

begin_comment
comment|/* base registers */
end_comment

begin_define
define|#
directive|define
name|nsp_irqcr
value|0
end_define

begin_define
define|#
directive|define
name|IRQCR_RESCL
value|0x01
end_define

begin_define
define|#
directive|define
name|IRQCR_PHCL
value|0x02
end_define

begin_define
define|#
directive|define
name|IRQCR_TIMERCL
value|0x04
end_define

begin_define
define|#
directive|define
name|IRQCR_FIFOCL
value|0x08
end_define

begin_define
define|#
directive|define
name|IRQCR_SCSIIDIS
value|0x10
end_define

begin_define
define|#
directive|define
name|IRQCR_EXTIDIS
value|0x20
end_define

begin_define
define|#
directive|define
name|IRQCR_TIMERIDIS
value|0x40
end_define

begin_define
define|#
directive|define
name|IRQCR_FIFOIDIS
value|0x80
end_define

begin_define
define|#
directive|define
name|IRQCR_ALLMASK
value|0xff
end_define

begin_define
define|#
directive|define
name|IRQCR_IRQDIS
value|0xf0
end_define

begin_define
define|#
directive|define
name|nsp_irqsr
value|0
end_define

begin_define
define|#
directive|define
name|IRQSR_SCSI
value|0x01
end_define

begin_define
define|#
directive|define
name|IRQSR_EXT
value|0x02
end_define

begin_define
define|#
directive|define
name|IRQSR_TIMER
value|0x04
end_define

begin_define
define|#
directive|define
name|IRQSR_FIFO
value|0x08
end_define

begin_define
define|#
directive|define
name|IRQSR_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|nsp_ifselr
value|1
end_define

begin_define
define|#
directive|define
name|IFSELR_IFSEL
value|0x01
end_define

begin_define
define|#
directive|define
name|IFSELR_REGSEL
value|0x04
end_define

begin_define
define|#
directive|define
name|nsp_fifosr
value|1
end_define

begin_define
define|#
directive|define
name|FIFOSR_CHIPREVM
value|0x0f
end_define

begin_define
define|#
directive|define
name|FIFOSR_CHIPIDM
value|0x70
end_define

begin_define
define|#
directive|define
name|FIFOSR_FULLEMP
value|0x80
end_define

begin_define
define|#
directive|define
name|nsp_idxr
value|2
end_define

begin_define
define|#
directive|define
name|nsp_datar
value|3
end_define

begin_define
define|#
directive|define
name|nsp_fifodr
value|4
end_define

begin_comment
comment|/* indexed registers */
end_comment

begin_define
define|#
directive|define
name|NSPR_EXTBUSC
value|0x10
end_define

begin_define
define|#
directive|define
name|NSPR_CLKDIVR
value|0x11
end_define

begin_define
define|#
directive|define
name|CLKDIVR_40M
value|0x02
end_define

begin_define
define|#
directive|define
name|CLKDIVR_20M
value|0x01
end_define

begin_define
define|#
directive|define
name|NSPR_TERMPWRC
value|0x13
end_define

begin_define
define|#
directive|define
name|TERMPWRC_POWON
value|0x01
end_define

begin_define
define|#
directive|define
name|NSPR_SCIENR
value|0x15
end_define

begin_define
define|#
directive|define
name|SCIENR_SCCHG
value|0x01
end_define

begin_define
define|#
directive|define
name|SCIENR_RESEL
value|0x10
end_define

begin_define
define|#
directive|define
name|SCIENR_FIFO
value|0x20
end_define

begin_define
define|#
directive|define
name|SCIENR_RST
value|0x40
end_define

begin_define
define|#
directive|define
name|NSPR_IRQPHS
value|0x16
end_define

begin_define
define|#
directive|define
name|IRQPHS_LMSG
value|0x01
end_define

begin_define
define|#
directive|define
name|IRQPHS_LIO
value|0x02
end_define

begin_define
define|#
directive|define
name|IRQPHS_LCD
value|0x04
end_define

begin_define
define|#
directive|define
name|IRQPHS_LBF
value|0x08
end_define

begin_define
define|#
directive|define
name|IRQPHS_PCHG
value|0x10
end_define

begin_define
define|#
directive|define
name|IRQPHS_RSEL
value|0x20
end_define

begin_define
define|#
directive|define
name|IRQPHS_FIFO
value|0x40
end_define

begin_define
define|#
directive|define
name|IRQPHS_RST
value|0x80
end_define

begin_define
define|#
directive|define
name|IRQPHS_PHMASK
value|(IRQPHS_LCD | IRQPHS_LMSG | IRQPHS_LIO)
end_define

begin_define
define|#
directive|define
name|NSPR_TIMERCNT
value|0x17
end_define

begin_define
define|#
directive|define
name|NSPR_SCBUSCR
value|0x18
end_define

begin_define
define|#
directive|define
name|SCBUSCR_SEL
value|0x01
end_define

begin_define
define|#
directive|define
name|SCBUSCR_RST
value|0x02
end_define

begin_define
define|#
directive|define
name|SCBUSCR_DOUT
value|0x04
end_define

begin_define
define|#
directive|define
name|SCBUSCR_ATN
value|0x08
end_define

begin_define
define|#
directive|define
name|SCBUSCR_ACK
value|0x10
end_define

begin_define
define|#
directive|define
name|SCBUSCR_BSY
value|0x20
end_define

begin_define
define|#
directive|define
name|SCBUSCR_ADIR
value|0x40
end_define

begin_define
define|#
directive|define
name|SCBUSCR_ACKEN
value|0x80
end_define

begin_define
define|#
directive|define
name|NSPR_SCBUSMON
value|0x19
end_define

begin_define
define|#
directive|define
name|SCBUSMON_MSG
value|0x01
end_define

begin_define
define|#
directive|define
name|SCBUSMON_IO
value|0x02
end_define

begin_define
define|#
directive|define
name|SCBUSMON_CD
value|0x04
end_define

begin_define
define|#
directive|define
name|SCBUSMON_BSY
value|0x08
end_define

begin_define
define|#
directive|define
name|SCBUSMON_ACK
value|0x10
end_define

begin_define
define|#
directive|define
name|SCBUSMON_REQ
value|0x20
end_define

begin_define
define|#
directive|define
name|SCBUSMON_SEL
value|0x40
end_define

begin_define
define|#
directive|define
name|SCBUSMON_ATN
value|0x80
end_define

begin_define
define|#
directive|define
name|NSPR_SETARBIT
value|0x1A
end_define

begin_define
define|#
directive|define
name|NSPR_ARBITS
value|0x1A
end_define

begin_define
define|#
directive|define
name|ARBITS_EXEC
value|0x01
end_define

begin_define
define|#
directive|define
name|ARBITS_CLR
value|0x02
end_define

begin_define
define|#
directive|define
name|ARBITS_WIN
value|0x02
end_define

begin_define
define|#
directive|define
name|ARBITS_FAIL
value|0x04
end_define

begin_define
define|#
directive|define
name|ARBITS_RESEL
value|0x08
end_define

begin_define
define|#
directive|define
name|NSPR_PARITYR
value|0x1B
end_define

begin_comment
comment|/* (W/R) */
end_comment

begin_define
define|#
directive|define
name|PARITYR_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|PARITYR_CLEAR
value|0x02
end_define

begin_define
define|#
directive|define
name|PARITYR_PE
value|0x02
end_define

begin_define
define|#
directive|define
name|NSPR_CMDCR
value|0x1C
end_define

begin_comment
comment|/* (W) */
end_comment

begin_define
define|#
directive|define
name|CMDCR_PTCLR
value|0x01
end_define

begin_define
define|#
directive|define
name|CMDCR_EXEC
value|0x02
end_define

begin_define
define|#
directive|define
name|NSPR_RESELR
value|0x1C
end_define

begin_comment
comment|/* (R) */
end_comment

begin_define
define|#
directive|define
name|NSPR_CMDDR
value|0x1D
end_define

begin_comment
comment|/* (W/R) */
end_comment

begin_define
define|#
directive|define
name|NSPR_PTCLRR
value|0x1E
end_define

begin_comment
comment|/* (W) */
end_comment

begin_define
define|#
directive|define
name|PTCLRR_PT
value|0x01
end_define

begin_define
define|#
directive|define
name|PTCLRR_ACK
value|0x02
end_define

begin_define
define|#
directive|define
name|PTCLRR_REQ
value|0x04
end_define

begin_define
define|#
directive|define
name|PTCLRR_HOST
value|0x08
end_define

begin_define
define|#
directive|define
name|PTCLRR_RSS
value|0x30
end_define

begin_define
define|#
directive|define
name|PTCLRR_RSS_ACK
value|0x00
end_define

begin_define
define|#
directive|define
name|PTCLRR_RSS_REQ
value|0x10
end_define

begin_define
define|#
directive|define
name|PTCLRR_RSS_HOST
value|0x20
end_define

begin_define
define|#
directive|define
name|NSPR_XFERCR
value|0x1E
end_define

begin_comment
comment|/* (R) */
end_comment

begin_define
define|#
directive|define
name|NSPR_XFERMR
value|0x20
end_define

begin_define
define|#
directive|define
name|XFERMR_MEM8
value|0x01
end_define

begin_define
define|#
directive|define
name|XFERMR_MEM32
value|0x02
end_define

begin_define
define|#
directive|define
name|XFERMR_ADR24
value|0x04
end_define

begin_define
define|#
directive|define
name|XFERMR_ADR32
value|0x08
end_define

begin_define
define|#
directive|define
name|XFERMR_IO8
value|0x10
end_define

begin_define
define|#
directive|define
name|XFERMR_IO32
value|0x20
end_define

begin_define
define|#
directive|define
name|XFERMR_XEN
value|0x40
end_define

begin_define
define|#
directive|define
name|XFERMR_FIFOEN
value|0x80
end_define

begin_define
define|#
directive|define
name|NSPR_SYNCR
value|0x21
end_define

begin_define
define|#
directive|define
name|SYNCR_OFFM
value|0x0f
end_define

begin_define
define|#
directive|define
name|SYNCR_PERM
value|0xf0
end_define

begin_define
define|#
directive|define
name|SYNCR_PERS
value|4
end_define

begin_define
define|#
directive|define
name|NSPR_DATA
value|0x22
end_define

begin_define
define|#
directive|define
name|NSPR_DATAACK
value|0x23
end_define

begin_define
define|#
directive|define
name|NSPR_OCR
value|0x26
end_define

begin_define
define|#
directive|define
name|OCR_ROMEN
value|0x01
end_define

begin_define
define|#
directive|define
name|OCR_TERMPWROUT
value|0x02
end_define

begin_define
define|#
directive|define
name|OCR_TERMPWRS
value|0x04
end_define

begin_define
define|#
directive|define
name|NSPR_ACKWIDTH
value|0x27
end_define

begin_comment
comment|/* SCBUSMON phase defs */
end_comment

begin_define
define|#
directive|define
name|SCBUSMON_FREE
value|0
end_define

begin_define
define|#
directive|define
name|SCBUSMON_CMD
define|\
value|(SCBUSMON_BSY | SCBUSMON_CD | SCBUSMON_REQ)
end_define

begin_define
define|#
directive|define
name|SCBUSMON_MSGIN
define|\
value|(SCBUSMON_BSY | SCBUSMON_MSG | SCBUSMON_IO | SCBUSMON_CD | SCBUSMON_REQ)
end_define

begin_define
define|#
directive|define
name|SCBUSMON_MSGOUT
define|\
value|(SCBUSMON_BSY | SCBUSMON_MSG | SCBUSMON_CD | SCBUSMON_REQ)
end_define

begin_define
define|#
directive|define
name|SCBUSMON_DATAIN
define|\
value|(SCBUSMON_BSY | SCBUSMON_IO | SCBUSMON_REQ)
end_define

begin_define
define|#
directive|define
name|SCBUSMON_DATAOUT
define|\
value|(SCBUSMON_BSY | SCBUSMON_REQ)
end_define

begin_define
define|#
directive|define
name|SCBUSMON_STATUS
define|\
value|(SCBUSMON_BSY | SCBUSMON_IO | SCBUSMON_CD | SCBUSMON_REQ)
end_define

begin_define
define|#
directive|define
name|SCBUSMON_RESELECT
define|\
value|(SCBUSMON_SEL | SCBUSMON_IO)
end_define

begin_define
define|#
directive|define
name|SCBUSMON_PHMASK
define|\
value|(SCBUSMON_SEL | SCBUSMON_CD | SCBUSMON_MSG | SCBUSMON_IO)
end_define

begin_comment
comment|/* Data phase */
end_comment

begin_define
define|#
directive|define
name|NSP_IS_PHASE_DATA
parameter_list|(
name|ph
parameter_list|)
define|\
value|((((ph)& SCBUSMON_PHMASK)& ~SCBUSMON_IO) == 0)
end_define

begin_define
define|#
directive|define
name|NSP_IS_IRQPHS_DATA
parameter_list|(
name|ph
parameter_list|)
define|\
value|((((ph)& IRQPHS_PHMASK)& ~SCBUSMON_IO) == 0)
end_define

begin_comment
comment|/* SCSI phase */
end_comment

begin_define
define|#
directive|define
name|PHASE_CMD
value|(SCBUSMON_CMD& SCBUSMON_PHMASK)
end_define

begin_define
define|#
directive|define
name|PHASE_DATAIN
value|(SCBUSMON_DATAIN& SCBUSMON_PHMASK)
end_define

begin_define
define|#
directive|define
name|PHASE_DATAOUT
value|(SCBUSMON_DATAOUT& SCBUSMON_PHMASK)
end_define

begin_define
define|#
directive|define
name|PHASE_STATUS
value|(SCBUSMON_STATUS& SCBUSMON_PHMASK)
end_define

begin_define
define|#
directive|define
name|PHASE_MSGIN
value|(SCBUSMON_MSGIN& SCBUSMON_PHMASK)
end_define

begin_define
define|#
directive|define
name|PHASE_MSGOUT
value|(SCBUSMON_MSGOUT& SCBUSMON_PHMASK)
end_define

begin_define
define|#
directive|define
name|PHASE_SEL
value|(SCBUSMON_SEL | SCBUSMON_IO)
end_define

begin_define
define|#
directive|define
name|IRQPHS_CMD
value|(IRQPHS_LCD)
end_define

begin_define
define|#
directive|define
name|IRQPHS_DATAIN
value|(IRQPHS_LIO)
end_define

begin_define
define|#
directive|define
name|IRQPHS_DATAOUT
value|(0)
end_define

begin_define
define|#
directive|define
name|IRQPHS_STATUS
value|(IRQPHS_LCD | IRQPHS_LIO)
end_define

begin_define
define|#
directive|define
name|IRQPHS_MSGIN
value|(IRQPHS_LCD | IRQPHS_LMSG | IRQPHS_LIO)
end_define

begin_define
define|#
directive|define
name|IRQPHS_MSGOUT
value|(IRQPHS_LCD | IRQPHS_LMSG)
end_define

begin_comment
comment|/* Size */
end_comment

begin_define
define|#
directive|define
name|NSP_MEMSIZE
value|NBPG
end_define

begin_define
define|#
directive|define
name|NSP_IOSIZE
value|16
end_define

begin_define
define|#
directive|define
name|NSP_BUFFER_SIZE
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NSPREG_H_ */
end_comment

end_unit

