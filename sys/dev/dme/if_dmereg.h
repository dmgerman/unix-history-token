begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2010 Andrew Turner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_DMEREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_DMEREG_H__
end_define

begin_comment
comment|/*  * DM9000 register definitions  */
end_comment

begin_define
define|#
directive|define
name|DME_NCR
value|0x00
end_define

begin_define
define|#
directive|define
name|NCR_EXT_PHY
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|NCR_WAKEEN
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|NCR_FCOL
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|NCR_FDX
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|NCR_LBK_NORMAL
value|(0<<1)
end_define

begin_define
define|#
directive|define
name|NCR_LBK_MAC
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|NCR_LBK_PHY
value|(2<<1)
end_define

begin_define
define|#
directive|define
name|NCR_RST
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DME_NSR
value|0x01
end_define

begin_define
define|#
directive|define
name|NSR_SPEED
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|NSR_LINKST
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|NSR_WAKEST
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|NSR_TX2END
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|NSR_TX1END
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|NSR_RXOV
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|DME_TCR
value|0x02
end_define

begin_define
define|#
directive|define
name|TCR_TJDIS
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|TCR_EXCECM
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|TCR_PAD_DIS2
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|TCR_PAD_CRC2
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|TCR_PAD_DIS1
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|TCR_PAD_CRC1
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|TCR_TXREQ
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DME_TSR1
value|0x03
end_define

begin_define
define|#
directive|define
name|DME_TSR2
value|0x04
end_define

begin_define
define|#
directive|define
name|DME_RCR
value|0x05
end_define

begin_define
define|#
directive|define
name|RCR_WTDIS
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|RCR_DIS_LONG
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|RCR_DIS_CRC
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|RCR_ALL
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|RCR_RUNT
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|RCR_PRMSC
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|RCR_RXEN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DME_RSR
value|0x06
end_define

begin_define
define|#
directive|define
name|DME_ROCR
value|0x07
end_define

begin_define
define|#
directive|define
name|DME_BPTR
value|0x08
end_define

begin_define
define|#
directive|define
name|BPTR_BPHW
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0x0f)<< 4)
end_define

begin_define
define|#
directive|define
name|BPTR_JPT
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0x0f)<< 0)
end_define

begin_define
define|#
directive|define
name|DME_FCTR
value|0x09
end_define

begin_define
define|#
directive|define
name|FCTR_HWOT
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0x0f)<< 4)
end_define

begin_define
define|#
directive|define
name|FCTR_LWOT
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0x0f)<< 0)
end_define

begin_define
define|#
directive|define
name|DME_FCR
value|0x0A
end_define

begin_define
define|#
directive|define
name|DME_EPCR
value|0x0B
end_define

begin_define
define|#
directive|define
name|EPCR_REEP
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|EPCR_WEP
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|EPCR_EPOS
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|EPCR_ERPRR
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|EPCR_ERPRW
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|EPCR_ERRE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DME_EPAR
value|0x0C
end_define

begin_define
define|#
directive|define
name|DME_EPDRL
value|0x0D
end_define

begin_define
define|#
directive|define
name|DME_EPDRH
value|0x0E
end_define

begin_define
define|#
directive|define
name|DME_WCR
value|0x0F
end_define

begin_define
define|#
directive|define
name|DME_PAR_BASE
value|0x10
end_define

begin_define
define|#
directive|define
name|DME_PAR
parameter_list|(
name|n
parameter_list|)
value|(DME_PAR_BASE + n)
end_define

begin_define
define|#
directive|define
name|DME_MAR_BASE
value|0x16
end_define

begin_define
define|#
directive|define
name|DME_MAR
parameter_list|(
name|n
parameter_list|)
value|(DME_MAR_BASE + n)
end_define

begin_define
define|#
directive|define
name|DME_GPCR
value|0x1E
end_define

begin_define
define|#
directive|define
name|DME_GPR
value|0x1F
end_define

begin_define
define|#
directive|define
name|DME_TRPAL
value|0x22
end_define

begin_define
define|#
directive|define
name|DME_TRPAH
value|0x23
end_define

begin_define
define|#
directive|define
name|DME_RWPAL
value|0x24
end_define

begin_define
define|#
directive|define
name|DME_RWPAH
value|0x25
end_define

begin_define
define|#
directive|define
name|DME_VIDL
value|0x28
end_define

begin_define
define|#
directive|define
name|DME_VIDH
value|0x29
end_define

begin_define
define|#
directive|define
name|DME_PIDL
value|0x2A
end_define

begin_define
define|#
directive|define
name|DME_PIDH
value|0x2B
end_define

begin_define
define|#
directive|define
name|DME_CHIPR
value|0x2C
end_define

begin_define
define|#
directive|define
name|DME_SMCR
value|0x2F
end_define

begin_define
define|#
directive|define
name|DME_MRCMDX
value|0xF0
end_define

begin_define
define|#
directive|define
name|DME_MRCMD
value|0xF2
end_define

begin_define
define|#
directive|define
name|DME_MRRL
value|0xF4
end_define

begin_define
define|#
directive|define
name|DME_MRRH
value|0xF5
end_define

begin_define
define|#
directive|define
name|DME_MWCMDX
value|0xF6
end_define

begin_define
define|#
directive|define
name|DME_MWCMD
value|0xF8
end_define

begin_define
define|#
directive|define
name|DME_MWRL
value|0xFA
end_define

begin_define
define|#
directive|define
name|DME_MWRH
value|0xFB
end_define

begin_define
define|#
directive|define
name|DME_TXPLL
value|0xFC
end_define

begin_define
define|#
directive|define
name|DME_TXPLH
value|0xFD
end_define

begin_define
define|#
directive|define
name|DME_ISR
value|0xFE
end_define

begin_define
define|#
directive|define
name|ISR_LNKCHG
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|ISR_UDRUN
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|ISR_ROO
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ISR_ROS
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ISR_PT
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ISR_PR
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DME_IMR
value|0xFF
end_define

begin_define
define|#
directive|define
name|IMR_PAR
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|IMR_LNKCHGI
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|IMR_UDRUNI
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|IMR_ROOI
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|IMR_ROI
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|IMR_PTI
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|IMR_PRI
value|(1<<0)
end_define

begin_comment
comment|/* Extra PHY register from DM9000B */
end_comment

begin_define
define|#
directive|define
name|MII_DME_DSPCR
value|0x1B
end_define

begin_define
define|#
directive|define
name|DSPCR_INIT
value|0xE100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DMEREGS_H__ */
end_comment

end_unit

