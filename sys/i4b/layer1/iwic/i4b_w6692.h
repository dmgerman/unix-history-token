begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, 2000 Dave Boyce. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *      i4b_iwic - isdn4bsd Winbond W6692 driver  *      ----------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Sun Jan 21 11:09:46 2001]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_W6692_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_W6692_H_
end_define

begin_define
define|#
directive|define
name|IWIC_BCH_A
value|0
end_define

begin_comment
comment|/* channel A */
end_comment

begin_define
define|#
directive|define
name|IWIC_BCH_B
value|1
end_define

begin_comment
comment|/* channel B */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	FIFO depths  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|IWIC_DCHAN_FIFO_LEN
value|64
end_define

begin_define
define|#
directive|define
name|IWIC_BCHAN_FIFO_LEN
value|64
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	D-Channel register offsets  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|D_RFIFO
value|0x00
end_define

begin_comment
comment|/* D channel receive FIFO */
end_comment

begin_define
define|#
directive|define
name|D_XFIFO
value|0x04
end_define

begin_comment
comment|/* D channel transmit FIFO */
end_comment

begin_define
define|#
directive|define
name|D_CMDR
value|0x08
end_define

begin_comment
comment|/* D channel command register */
end_comment

begin_define
define|#
directive|define
name|D_MODE
value|0x0c
end_define

begin_comment
comment|/* D channel mode control */
end_comment

begin_define
define|#
directive|define
name|D_TIMR
value|0x10
end_define

begin_comment
comment|/* D channel timer control */
end_comment

begin_define
define|#
directive|define
name|D_EXIR
value|0x1c
end_define

begin_comment
comment|/* D channel extended interrupt */
end_comment

begin_define
define|#
directive|define
name|D_EXIM
value|0x20
end_define

begin_comment
comment|/* D channel extended interrupt mask */
end_comment

begin_define
define|#
directive|define
name|D_STAR
value|0x24
end_define

begin_comment
comment|/* D channel status register */
end_comment

begin_define
define|#
directive|define
name|D_RSTA
value|0x28
end_define

begin_comment
comment|/* D channel receive status */
end_comment

begin_define
define|#
directive|define
name|D_SAM
value|0x2c
end_define

begin_comment
comment|/* D channel address mask 1 */
end_comment

begin_define
define|#
directive|define
name|D_SAP1
value|0x30
end_define

begin_comment
comment|/* D channel individual SAPI 1 */
end_comment

begin_define
define|#
directive|define
name|D_SAP2
value|0x34
end_define

begin_comment
comment|/* D channel individual SAPI 2 */
end_comment

begin_define
define|#
directive|define
name|D_TAM
value|0x38
end_define

begin_comment
comment|/* D channel address mask 2 */
end_comment

begin_define
define|#
directive|define
name|D_TEI1
value|0x3c
end_define

begin_comment
comment|/* D channel individual TEI 1 */
end_comment

begin_define
define|#
directive|define
name|D_TEI2
value|0x40
end_define

begin_comment
comment|/* D channel individual TEI 2 */
end_comment

begin_define
define|#
directive|define
name|D_RBCH
value|0x44
end_define

begin_comment
comment|/* D channel receive frame byte count high */
end_comment

begin_define
define|#
directive|define
name|D_RBCL
value|0x48
end_define

begin_comment
comment|/* D channel receive frame byte count low */
end_comment

begin_define
define|#
directive|define
name|D_CTL
value|0x54
end_define

begin_comment
comment|/* D channel control register */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	B-channel base offsets  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|B1_CHAN_OFFSET
value|0x80
end_define

begin_comment
comment|/* B1 channel offset */
end_comment

begin_define
define|#
directive|define
name|B2_CHAN_OFFSET
value|0xc0
end_define

begin_comment
comment|/* B2 channel offset */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	B-channel register offsets, from base  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|B_RFIFO
value|0x00
end_define

begin_comment
comment|/* B channel receive FIFO */
end_comment

begin_define
define|#
directive|define
name|B_XFIFO
value|0x04
end_define

begin_comment
comment|/* B channel transmit FIFO */
end_comment

begin_define
define|#
directive|define
name|B_CMDR
value|0x08
end_define

begin_comment
comment|/* B channel command register */
end_comment

begin_define
define|#
directive|define
name|B_MODE
value|0x0c
end_define

begin_comment
comment|/* B channel mode control */
end_comment

begin_define
define|#
directive|define
name|B_EXIR
value|0x10
end_define

begin_comment
comment|/* B channel extended interrupt */
end_comment

begin_define
define|#
directive|define
name|B_EXIM
value|0x14
end_define

begin_comment
comment|/* B channel extended interrupt mask */
end_comment

begin_define
define|#
directive|define
name|B_STAR
value|0x18
end_define

begin_comment
comment|/* B channel status register */
end_comment

begin_define
define|#
directive|define
name|B_ADM1
value|0x1c
end_define

begin_comment
comment|/* B channel address mask 1 */
end_comment

begin_define
define|#
directive|define
name|B_ADM2
value|0x20
end_define

begin_comment
comment|/* B channel address mask 2 */
end_comment

begin_define
define|#
directive|define
name|B_ADR1
value|0x24
end_define

begin_comment
comment|/* B channel address 1 */
end_comment

begin_define
define|#
directive|define
name|B_ADR2
value|0x28
end_define

begin_comment
comment|/* B channel address 2 */
end_comment

begin_define
define|#
directive|define
name|B_RBCL
value|0x2c
end_define

begin_comment
comment|/* B channel receive frame byte count high */
end_comment

begin_define
define|#
directive|define
name|B_RBCH
value|0x30
end_define

begin_comment
comment|/* B channel receive frame byte count low */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  * 	Remaining control register offsets.  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|ISTA
value|0x14
end_define

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|IMASK
value|0x18
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|TIMR2
value|0x4c
end_define

begin_comment
comment|/* Timer 2 */
end_comment

begin_define
define|#
directive|define
name|L1_RC
value|0x50
end_define

begin_comment
comment|/* GCI layer 1 ready code */
end_comment

begin_define
define|#
directive|define
name|CIR
value|0x58
end_define

begin_comment
comment|/* Command/Indication receive */
end_comment

begin_define
define|#
directive|define
name|CIX
value|0x5c
end_define

begin_comment
comment|/* Command/Indication transmit */
end_comment

begin_define
define|#
directive|define
name|SQR
value|0x60
end_define

begin_comment
comment|/* S/Q channel receive register */
end_comment

begin_define
define|#
directive|define
name|SQX
value|0x64
end_define

begin_comment
comment|/* S/Q channel transmit register */
end_comment

begin_define
define|#
directive|define
name|PCTL
value|0x68
end_define

begin_comment
comment|/* Peripheral control register */
end_comment

begin_define
define|#
directive|define
name|MOR
value|0x6c
end_define

begin_comment
comment|/* Monitor receive channel */
end_comment

begin_define
define|#
directive|define
name|MOX
value|0x70
end_define

begin_comment
comment|/* Monitor transmit channel */
end_comment

begin_define
define|#
directive|define
name|MOSR
value|0x74
end_define

begin_comment
comment|/* Monitor channel status register */
end_comment

begin_define
define|#
directive|define
name|MOCR
value|0x78
end_define

begin_comment
comment|/* Monitor channel control register */
end_comment

begin_define
define|#
directive|define
name|GCR
value|0x7c
end_define

begin_comment
comment|/* GCI mode control register */
end_comment

begin_define
define|#
directive|define
name|XADDR
value|0xf4
end_define

begin_comment
comment|/* Peripheral address register */
end_comment

begin_define
define|#
directive|define
name|XDATA
value|0xf8
end_define

begin_comment
comment|/* Peripheral data register */
end_comment

begin_define
define|#
directive|define
name|EPCTL
value|0xfc
end_define

begin_comment
comment|/* Serial EEPROM control */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	register bits  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|D_CMDR_RACK
value|0x80
end_define

begin_define
define|#
directive|define
name|D_CMDR_RRST
value|0x40
end_define

begin_define
define|#
directive|define
name|D_CMDR_STT
value|0x10
end_define

begin_define
define|#
directive|define
name|D_CMDR_XMS
value|0x08
end_define

begin_define
define|#
directive|define
name|D_CMDR_XME
value|0x02
end_define

begin_define
define|#
directive|define
name|D_CMDR_XRST
value|0x01
end_define

begin_define
define|#
directive|define
name|D_MODE_MMS
value|0x80
end_define

begin_define
define|#
directive|define
name|D_MODE_RACT
value|0x40
end_define

begin_define
define|#
directive|define
name|D_MODE_TMS
value|0x10
end_define

begin_define
define|#
directive|define
name|D_MODE_TEE
value|0x08
end_define

begin_define
define|#
directive|define
name|D_MODE_MFD
value|0x04
end_define

begin_define
define|#
directive|define
name|D_MODE_DLP
value|0x02
end_define

begin_define
define|#
directive|define
name|D_MODE_RLP
value|0x01
end_define

begin_define
define|#
directive|define
name|D_TIMR_CNT
parameter_list|(
name|i
parameter_list|)
value|(((i)>> 5)& 0x07)
end_define

begin_define
define|#
directive|define
name|D_TIMR_VAL
parameter_list|(
name|i
parameter_list|)
value|((i)& 0x1f)
end_define

begin_define
define|#
directive|define
name|ISTA_D_RMR
value|0x80
end_define

begin_define
define|#
directive|define
name|ISTA_D_RME
value|0x40
end_define

begin_define
define|#
directive|define
name|ISTA_D_XFR
value|0x20
end_define

begin_define
define|#
directive|define
name|ISTA_XINT1
value|0x10
end_define

begin_define
define|#
directive|define
name|ISTA_XINT0
value|0x08
end_define

begin_define
define|#
directive|define
name|ISTA_D_EXI
value|0x04
end_define

begin_define
define|#
directive|define
name|ISTA_B1_EXI
value|0x02
end_define

begin_define
define|#
directive|define
name|ISTA_B2_EXI
value|0x01
end_define

begin_define
define|#
directive|define
name|IMASK_D_RMR
value|0x80
end_define

begin_define
define|#
directive|define
name|IMASK_D_RME
value|0x40
end_define

begin_define
define|#
directive|define
name|IMASK_D_XFR
value|0x20
end_define

begin_define
define|#
directive|define
name|IMASK_XINT1
value|0x10
end_define

begin_define
define|#
directive|define
name|IMASK_XINT0
value|0x08
end_define

begin_define
define|#
directive|define
name|IMASK_D_EXI
value|0x04
end_define

begin_define
define|#
directive|define
name|IMASK_B1_EXI
value|0x02
end_define

begin_define
define|#
directive|define
name|IMASK_B2_EXI
value|0x01
end_define

begin_define
define|#
directive|define
name|D_EXIR_RDOV
value|0x80
end_define

begin_define
define|#
directive|define
name|D_EXIR_XDUN
value|0x40
end_define

begin_define
define|#
directive|define
name|D_EXIR_XCOL
value|0x20
end_define

begin_define
define|#
directive|define
name|D_EXIR_TIN2
value|0x10
end_define

begin_define
define|#
directive|define
name|D_EXIR_MOC
value|0x08
end_define

begin_define
define|#
directive|define
name|D_EXIR_ISC
value|0x04
end_define

begin_define
define|#
directive|define
name|D_EXIR_TEXP
value|0x02
end_define

begin_define
define|#
directive|define
name|D_EXIR_WEXP
value|0x01
end_define

begin_define
define|#
directive|define
name|D_EXIM_RDOV
value|0x80
end_define

begin_define
define|#
directive|define
name|D_EXIM_XDUN
value|0x40
end_define

begin_define
define|#
directive|define
name|D_EXIM_XCOL
value|0x20
end_define

begin_define
define|#
directive|define
name|D_EXIM_TIM2
value|0x10
end_define

begin_define
define|#
directive|define
name|D_EXIM_MOC
value|0x08
end_define

begin_define
define|#
directive|define
name|D_EXIM_ISC
value|0x04
end_define

begin_define
define|#
directive|define
name|D_EXIM_TEXP
value|0x02
end_define

begin_define
define|#
directive|define
name|D_EXIM_WEXP
value|0x01
end_define

begin_define
define|#
directive|define
name|D_STAR_XDOW
value|0x80
end_define

begin_define
define|#
directive|define
name|D_STAR_XBZ
value|0x20
end_define

begin_define
define|#
directive|define
name|D_STAR_DRDY
value|0x10
end_define

begin_define
define|#
directive|define
name|D_RSTA_RDOV
value|0x40
end_define

begin_define
define|#
directive|define
name|D_RSTA_CRCE
value|0x20
end_define

begin_define
define|#
directive|define
name|D_RSTA_RMB
value|0x10
end_define

begin_define
define|#
directive|define
name|D_RBCH_VN
parameter_list|(
name|i
parameter_list|)
value|(((i)>> 6)& 0x03)
end_define

begin_define
define|#
directive|define
name|D_RBCH_LOV
value|0x20
end_define

begin_define
define|#
directive|define
name|D_RBC
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|(((((h)& 0x1f))<< 8) + (l))
end_define

begin_define
define|#
directive|define
name|D_TIMR2_TMD
value|0x80
end_define

begin_define
define|#
directive|define
name|D_TIMR2_TBCN
parameter_list|(
name|i
parameter_list|)
value|((i)& 0x3f)
end_define

begin_define
define|#
directive|define
name|L1_RC_RC
parameter_list|(
name|i
parameter_list|)
value|((i)& 0x0f)
end_define

begin_define
define|#
directive|define
name|D_CTL_WTT
parameter_list|(
name|i
parameter_list|)
value|(((i)> 6)& 0x03)
end_define

begin_define
define|#
directive|define
name|D_CTL_SRST
value|0x20
end_define

begin_define
define|#
directive|define
name|D_CTL_TPS
value|0x04
end_define

begin_define
define|#
directive|define
name|D_CTL_OPS
parameter_list|(
name|i
parameter_list|)
value|((i)& 0x03)
end_define

begin_define
define|#
directive|define
name|CIR_SCC
value|0x80
end_define

begin_define
define|#
directive|define
name|CIR_ICC
value|0x40
end_define

begin_define
define|#
directive|define
name|CIR_CODR
parameter_list|(
name|i
parameter_list|)
value|((i)& 0x0f)
end_define

begin_define
define|#
directive|define
name|CIX_ECK
value|0x00
end_define

begin_define
define|#
directive|define
name|CIX_RST
value|0x01
end_define

begin_define
define|#
directive|define
name|CIX_SCP
value|0x04
end_define

begin_define
define|#
directive|define
name|CIX_SSP
value|0x02
end_define

begin_define
define|#
directive|define
name|CIX_AR8
value|0x08
end_define

begin_define
define|#
directive|define
name|CIX_AR10
value|0x09
end_define

begin_define
define|#
directive|define
name|CIX_EAL
value|0x0a
end_define

begin_define
define|#
directive|define
name|CIX_DRC
value|0x0f
end_define

begin_define
define|#
directive|define
name|CIR_CE
value|0x07
end_define

begin_define
define|#
directive|define
name|CIR_DRD
value|0x00
end_define

begin_define
define|#
directive|define
name|CIR_LD
value|0x04
end_define

begin_define
define|#
directive|define
name|CIR_ARD
value|0x08
end_define

begin_define
define|#
directive|define
name|CIR_TI
value|0x0a
end_define

begin_define
define|#
directive|define
name|CIR_ATI
value|0x0b
end_define

begin_define
define|#
directive|define
name|CIR_AI8
value|0x0c
end_define

begin_define
define|#
directive|define
name|CIR_AI10
value|0x0d
end_define

begin_define
define|#
directive|define
name|CIR_CD
value|0x0f
end_define

begin_define
define|#
directive|define
name|SQR_XIND1
value|0x80
end_define

begin_define
define|#
directive|define
name|SQR_XIND0
value|0x40
end_define

begin_define
define|#
directive|define
name|SQR_MSYN
value|0x20
end_define

begin_define
define|#
directive|define
name|SQR_SCIE
value|0x10
end_define

begin_define
define|#
directive|define
name|SQR_S
parameter_list|(
name|i
parameter_list|)
value|((i)& 0x0f)
end_define

begin_define
define|#
directive|define
name|SQX_SCIE
value|0x10
end_define

begin_define
define|#
directive|define
name|SQX_Q
parameter_list|(
name|i
parameter_list|)
value|((i)& 0x0f)
end_define

begin_define
define|#
directive|define
name|B_CMDR_RACK
value|0x80
end_define

begin_define
define|#
directive|define
name|B_CMDR_RRST
value|0x40
end_define

begin_define
define|#
directive|define
name|B_CMDR_RACT
value|0x20
end_define

begin_define
define|#
directive|define
name|B_CMDR_XMS
value|0x04
end_define

begin_define
define|#
directive|define
name|B_CMDR_XME
value|0x02
end_define

begin_define
define|#
directive|define
name|B_CMDR_XRST
value|0x01
end_define

begin_define
define|#
directive|define
name|B_MODE_MMS
value|0x80
end_define

begin_define
define|#
directive|define
name|B_MODE_ITF
value|0x40
end_define

begin_define
define|#
directive|define
name|B_MODE_EPCM
value|0x20
end_define

begin_define
define|#
directive|define
name|B_MODE_BSW1
value|0x10
end_define

begin_define
define|#
directive|define
name|B_MODE_BSW0
value|0x08
end_define

begin_define
define|#
directive|define
name|B_MODE_SW56
value|0x04
end_define

begin_define
define|#
directive|define
name|B_MODE_FTS1
value|0x02
end_define

begin_define
define|#
directive|define
name|B_MODE_FTS0
value|0x01
end_define

begin_define
define|#
directive|define
name|B_EXIR_RMR
value|0x40
end_define

begin_define
define|#
directive|define
name|B_EXIR_RME
value|0x20
end_define

begin_define
define|#
directive|define
name|B_EXIR_RDOV
value|0x10
end_define

begin_define
define|#
directive|define
name|B_EXIR_XFR
value|0x02
end_define

begin_define
define|#
directive|define
name|B_EXIR_XDUN
value|0x01
end_define

begin_define
define|#
directive|define
name|B_EXIM_RMR
value|0x40
end_define

begin_define
define|#
directive|define
name|B_EXIM_RME
value|0x20
end_define

begin_define
define|#
directive|define
name|B_EXIM_RDOV
value|0x10
end_define

begin_define
define|#
directive|define
name|B_EXIM_XFR
value|0x02
end_define

begin_define
define|#
directive|define
name|B_EXIM_XDUN
value|0x01
end_define

begin_define
define|#
directive|define
name|B_STAR_RDOV
value|0x40
end_define

begin_define
define|#
directive|define
name|B_STAR_CRCE
value|0x20
end_define

begin_define
define|#
directive|define
name|B_STAR_RMB
value|0x10
end_define

begin_define
define|#
directive|define
name|B_STAR_XDOW
value|0x04
end_define

begin_define
define|#
directive|define
name|B_STAR_XBZ
value|0x01
end_define

begin_define
define|#
directive|define
name|B_RBC
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|(((((h)& 0x1f))<< 8) + (l))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_W6692_H_ */
end_comment

end_unit

