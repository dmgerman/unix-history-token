begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: tmc18c30reg.h,v 1.4 1998/03/14 07:05:23 kmatsuda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1996, 1997, 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *  Copyright (c) 1996, 1997, 1998  *	Kouichi Matsuda. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TMC18C30REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_TMC18C30REG_H_
end_define

begin_define
define|#
directive|define
name|tmc_wdata
value|0x00
end_define

begin_define
define|#
directive|define
name|tmc_rdata
value|0x00
end_define

begin_define
define|#
directive|define
name|tmc_bctl
value|0x01
end_define

begin_define
define|#
directive|define
name|BCTL_BUSFREE
value|0x00
end_define

begin_define
define|#
directive|define
name|BCTL_RST
value|0x01
end_define

begin_define
define|#
directive|define
name|BCTL_SEL
value|0x02
end_define

begin_define
define|#
directive|define
name|BCTL_BSY
value|0x04
end_define

begin_define
define|#
directive|define
name|BCTL_ATN
value|0x08
end_define

begin_define
define|#
directive|define
name|BCTL_IO
value|0x10
end_define

begin_define
define|#
directive|define
name|BCTL_CD
value|0x20
end_define

begin_define
define|#
directive|define
name|BCTL_MSG
value|0x40
end_define

begin_define
define|#
directive|define
name|BCTL_BUSEN
value|0x80
end_define

begin_define
define|#
directive|define
name|tmc_bstat
value|0x01
end_define

begin_define
define|#
directive|define
name|BSTAT_BSY
value|0x01
end_define

begin_define
define|#
directive|define
name|BSTAT_MSG
value|0x02
end_define

begin_define
define|#
directive|define
name|BSTAT_IO
value|0x04
end_define

begin_define
define|#
directive|define
name|BSTAT_CMD
value|0x08
end_define

begin_define
define|#
directive|define
name|BSTAT_REQ
value|0x10
end_define

begin_define
define|#
directive|define
name|BSTAT_SEL
value|0x20
end_define

begin_define
define|#
directive|define
name|BSTAT_ACK
value|0x40
end_define

begin_define
define|#
directive|define
name|tmc_ictl
value|0x02
end_define

begin_define
define|#
directive|define
name|ICTL_FIFO
value|0x10
end_define

begin_define
define|#
directive|define
name|ICTL_ARBIT
value|0x20
end_define

begin_define
define|#
directive|define
name|ICTL_SEL
value|0x40
end_define

begin_define
define|#
directive|define
name|ICTL_CD
value|0x80
end_define

begin_define
define|#
directive|define
name|ICTL_ALLINT
value|(ICTL_ARBIT | ICTL_CD | ICTL_SEL | ICTL_FIFO)
end_define

begin_define
define|#
directive|define
name|tmc_astat
value|0x02
end_define

begin_define
define|#
directive|define
name|ASTAT_INT
value|0x01
end_define

begin_define
define|#
directive|define
name|ASTAT_ARBIT
value|0x02
end_define

begin_define
define|#
directive|define
name|ASTAT_PARERR
value|0x04
end_define

begin_define
define|#
directive|define
name|ASTAT_SCSIRST
value|0x08
end_define

begin_define
define|#
directive|define
name|ASTAT_STATMASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|ASTAT_FIFODIR
value|0x10
end_define

begin_define
define|#
directive|define
name|ASTAT_FIFOEN
value|0x20
end_define

begin_define
define|#
directive|define
name|ASTAT_PARENB
value|0x40
end_define

begin_define
define|#
directive|define
name|ASTAT_BUSEN
value|0x80
end_define

begin_define
define|#
directive|define
name|tmc_ssctl
value|0x03
end_define

begin_define
define|#
directive|define
name|SSCTL_FSYNCHEN
value|0x40
end_define

begin_define
define|#
directive|define
name|SSCTL_SYNCHEN
value|0x80
end_define

begin_define
define|#
directive|define
name|tmc_fstat
value|0x03
end_define

begin_define
define|#
directive|define
name|tmc_fctl
value|0x04
end_define

begin_define
define|#
directive|define
name|FCTL_CLRFIFO
value|0x01
end_define

begin_define
define|#
directive|define
name|FCTL_ARBIT
value|0x04
end_define

begin_define
define|#
directive|define
name|FCTL_PARENB
value|0x08
end_define

begin_define
define|#
directive|define
name|FCTL_INTEN
value|0x10
end_define

begin_define
define|#
directive|define
name|FCTL_CLRINT
value|0x20
end_define

begin_define
define|#
directive|define
name|FCTL_FIFOW
value|0x40
end_define

begin_define
define|#
directive|define
name|FCTL_FIFOEN
value|0x80
end_define

begin_define
define|#
directive|define
name|tmc_icnd
value|0x04
end_define

begin_define
define|#
directive|define
name|tmc_mctl
value|0x05
end_define

begin_define
define|#
directive|define
name|tmc_idlsb
value|0x05
end_define

begin_define
define|#
directive|define
name|tmc_idmsb
value|0x06
end_define

begin_define
define|#
directive|define
name|tmc_wlb
value|0x07
end_define

begin_define
define|#
directive|define
name|tmc_rlb
value|0x07
end_define

begin_define
define|#
directive|define
name|tmc_scsiid
value|0x08
end_define

begin_define
define|#
directive|define
name|tmc_sdna
value|0x08
end_define

begin_define
define|#
directive|define
name|tmc_istat
value|0x09
end_define

begin_define
define|#
directive|define
name|ISTAT_INTEN
value|0x08
end_define

begin_define
define|#
directive|define
name|ISTAT_FIFO
value|0x10
end_define

begin_define
define|#
directive|define
name|ISTAT_ARBIT
value|0x20
end_define

begin_define
define|#
directive|define
name|ISTAT_SEL
value|0x40
end_define

begin_define
define|#
directive|define
name|ISTAT_CD
value|0x80
end_define

begin_define
define|#
directive|define
name|tmc_cfg1
value|0x0a
end_define

begin_define
define|#
directive|define
name|tmc_ioctl
value|0x0b
end_define

begin_define
define|#
directive|define
name|IOCTL_IO32
value|0x80
end_define

begin_define
define|#
directive|define
name|tmc_cfg2
value|0x0b
end_define

begin_define
define|#
directive|define
name|tmc_wfifo
value|0x0c
end_define

begin_define
define|#
directive|define
name|tmc_rfifo
value|0x0c
end_define

begin_define
define|#
directive|define
name|tmc_fdcnt
value|0x0e
end_define

begin_comment
comment|/* Information transfer phases */
end_comment

begin_define
define|#
directive|define
name|BUSFREE_PHASE
value|0x00
end_define

begin_define
define|#
directive|define
name|DATA_OUT_PHASE
value|(BSTAT_BSY)
end_define

begin_define
define|#
directive|define
name|DATA_IN_PHASE
value|(BSTAT_BSY|BSTAT_IO)
end_define

begin_define
define|#
directive|define
name|COMMAND_PHASE
value|(BSTAT_CMD|BSTAT_BSY)
end_define

begin_define
define|#
directive|define
name|STATUS_PHASE
value|(BSTAT_CMD|BSTAT_BSY|BSTAT_IO)
end_define

begin_define
define|#
directive|define
name|MESSAGE_OUT_PHASE
value|(BSTAT_CMD|BSTAT_MSG|BSTAT_BSY)
end_define

begin_define
define|#
directive|define
name|MESSAGE_IN_PHASE
value|(BSTAT_CMD|BSTAT_MSG|BSTAT_BSY|BSTAT_IO)
end_define

begin_define
define|#
directive|define
name|PHASE_RESELECTED
value|(BSTAT_SEL|BSTAT_IO)
end_define

begin_define
define|#
directive|define
name|BSTAT_PHMASK
value|(BSTAT_MSG | BSTAT_IO | BSTAT_CMD)
end_define

begin_define
define|#
directive|define
name|PHASE_MASK
value|(BSTAT_SEL | BSTAT_BSY | BSTAT_PHMASK)
end_define

begin_define
define|#
directive|define
name|RESEL_PHASE_MASK
value|(BSTAT_SEL | BSTAT_PHMASK)
end_define

begin_define
define|#
directive|define
name|STG_IS_PHASE_DATA
parameter_list|(
name|st
parameter_list|)
define|\
value|((((st)& PHASE_MASK)& ~BSTAT_IO) == BSTAT_BSY)
end_define

begin_comment
comment|/* chip type */
end_comment

begin_define
define|#
directive|define
name|TMCCHIP_UNK
value|0x00
end_define

begin_define
define|#
directive|define
name|TMCCHIP_1800
value|0x01
end_define

begin_define
define|#
directive|define
name|TMCCHIP_18C50
value|0x02
end_define

begin_define
define|#
directive|define
name|TMCCHIP_18C30
value|0x03
end_define

begin_define
define|#
directive|define
name|STGIOSZ
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TMC18C30REG_H_ */
end_comment

end_unit

