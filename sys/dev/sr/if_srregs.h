begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 John Hay.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by [your name]  *	and [any other names deserving credit ]  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY [your name] AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_SRREGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_SRREGS_H_
end_define

begin_define
define|#
directive|define
name|NCHAN
value|2
end_define

begin_comment
comment|/* A HD64570 chip have 2 channels */
end_comment

begin_define
define|#
directive|define
name|SR_BUF_SIZ
value|512
end_define

begin_define
define|#
directive|define
name|SR_TX_BLOCKS
value|2
end_define

begin_comment
comment|/* Sepperate sets of tx buffers */
end_comment

begin_define
define|#
directive|define
name|SRC_IO_SIZ
value|0x10
end_define

begin_comment
comment|/* Actually a lie. It uses a lot more. */
end_comment

begin_define
define|#
directive|define
name|SRC_WIN_SIZ
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SRC_WIN_MSK
value|(SRC_WIN_SIZ - 1)
end_define

begin_define
define|#
directive|define
name|SRC_WIN_SHFT
value|14
end_define

begin_define
define|#
directive|define
name|SR_FLAGS_NCHAN_MSK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|SR_FLAGS_0_CLK_MSK
value|0x00000030
end_define

begin_define
define|#
directive|define
name|SR_FLAGS_0_EXT_CLK
value|0x00000000
end_define

begin_comment
comment|/* External RX clock shared by TX */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_0_EXT_SEP_CLK
value|0x00000010
end_define

begin_comment
comment|/* Sepperate external clocks */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_0_INT_CLK
value|0x00000020
end_define

begin_comment
comment|/* Internal clock */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_1_CLK_MSK
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|SR_FLAGS_1_EXT_CLK
value|0x00000000
end_define

begin_comment
comment|/* External RX clock shared by TX */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_1_EXT_SEP_CLK
value|0x00000040
end_define

begin_comment
comment|/* Sepperate external clocks */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_1_INT_CLK
value|0x00000080
end_define

begin_comment
comment|/* Internal clock */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_CLK_SHFT
value|4
end_define

begin_define
define|#
directive|define
name|SR_FLAGS_CLK_CHAN_SHFT
value|2
end_define

begin_define
define|#
directive|define
name|SR_FLAGS_EXT_CLK
value|0x00000000
end_define

begin_comment
comment|/* External RX clock shared by TX */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_EXT_SEP_CLK
value|0x00000001
end_define

begin_comment
comment|/* Sepperate external clocks */
end_comment

begin_define
define|#
directive|define
name|SR_FLAGS_INT_CLK
value|0x00000002
end_define

begin_comment
comment|/* Internal clock */
end_comment

begin_define
define|#
directive|define
name|SR_PCR
value|0x00
end_define

begin_comment
comment|/* RW, PC Control Register */
end_comment

begin_define
define|#
directive|define
name|SR_BAR
value|0x02
end_define

begin_comment
comment|/* RW, Base Address Register */
end_comment

begin_define
define|#
directive|define
name|SR_PSR
value|0x04
end_define

begin_comment
comment|/* RW, Page Scan Register */
end_comment

begin_define
define|#
directive|define
name|SR_MCR
value|0x06
end_define

begin_comment
comment|/* RW, Modem Control Register */
end_comment

begin_define
define|#
directive|define
name|SR_PCR_SCARUN
value|0x01
end_define

begin_comment
comment|/* !Reset */
end_comment

begin_define
define|#
directive|define
name|SR_PCR_EN_VPM
value|0x02
end_define

begin_comment
comment|/* Running above 1M */
end_comment

begin_define
define|#
directive|define
name|SR_PCR_MEM_WIN
value|0x04
end_define

begin_comment
comment|/* Open memory window */
end_comment

begin_define
define|#
directive|define
name|SR_PCR_ISA16
value|0x08
end_define

begin_comment
comment|/* 16 bit ISA mode */
end_comment

begin_define
define|#
directive|define
name|SR_PCR_16M_SEL
value|0xF0
end_define

begin_comment
comment|/* A20-A23 Addresses */
end_comment

begin_define
define|#
directive|define
name|SR_PSR_PG_SEL
value|0x1F
end_define

begin_comment
comment|/* Page 0 - 31 select */
end_comment

begin_define
define|#
directive|define
name|SR_PG_MSK
value|0x1F
end_define

begin_define
define|#
directive|define
name|SR_PSR_WIN_SIZ
value|0x60
end_define

begin_comment
comment|/* Window size select */
end_comment

begin_define
define|#
directive|define
name|SR_PSR_WIN_16K
value|0x00
end_define

begin_define
define|#
directive|define
name|SR_PSR_WIN_32K
value|0x20
end_define

begin_define
define|#
directive|define
name|SR_PSR_WIN_64K
value|0x40
end_define

begin_define
define|#
directive|define
name|SR_PSR_WIN_128K
value|0x60
end_define

begin_define
define|#
directive|define
name|SR_PSR_EN_SCA_DMA
value|0x80
end_define

begin_comment
comment|/* Enable the SCA DMA */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_DTR0
value|0x01
end_define

begin_comment
comment|/* Deactivate DTR0 */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_DTR1
value|0x02
end_define

begin_comment
comment|/* Deactivate DTR1 */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_DSR0
value|0x04
end_define

begin_comment
comment|/* DSR0 Status */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_DSR1
value|0x08
end_define

begin_comment
comment|/* DSR1 Status */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_TE0
value|0x10
end_define

begin_comment
comment|/* Enable RS422 TXD */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_TE1
value|0x20
end_define

begin_comment
comment|/* Enable RS422 TXD */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_ETC0
value|0x40
end_define

begin_comment
comment|/* Enable Ext Clock out */
end_comment

begin_define
define|#
directive|define
name|SR_MCR_ETC1
value|0x80
end_define

begin_comment
comment|/* Enable Ext Clock out */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_SRREGS_H_ */
end_comment

end_unit

