begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 John Hay.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by [your name]  *	and [any other names deserving credit ]  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY [your name] AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HD64570_H_
end_ifndef

begin_define
define|#
directive|define
name|_HD64570_H_
end_define

begin_typedef
typedef|typedef
struct|struct
name|msci_channel
block|{
union|union
block|{
name|unsigned
name|short
name|us_trb
decl_stmt|;
comment|/* rw */
struct|struct
block|{
name|unsigned
name|char
name|uc_trbl
decl_stmt|;
name|unsigned
name|char
name|uc_trbh
decl_stmt|;
block|}
name|uc_trb
struct|;
block|}
name|u_trb
union|;
name|unsigned
name|char
name|st0
decl_stmt|;
comment|/* ro */
name|unsigned
name|char
name|st1
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|st2
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|st3
decl_stmt|;
comment|/* ro */
name|unsigned
name|char
name|fst
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused0
decl_stmt|;
name|unsigned
name|char
name|ie0
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|ie1
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|ie2
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|fie
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|cmd
decl_stmt|;
comment|/* wo */
name|unsigned
name|char
name|unused1
decl_stmt|;
name|unsigned
name|char
name|md0
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|md1
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|md2
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|ctl
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|sa0
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|sa1
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|idl
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|tmc
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|rxs
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|txs
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|trc0
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|trc1
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|rrc
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused2
decl_stmt|;
name|unsigned
name|char
name|cst0
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|cst1
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused3
index|[
literal|2
index|]
decl_stmt|;
block|}
name|msci_channel
typedef|;
end_typedef

begin_define
define|#
directive|define
name|trb
value|u_trb.us_trb
end_define

begin_define
define|#
directive|define
name|trbl
value|u_trb.uc_trb.uc_trbl
end_define

begin_define
define|#
directive|define
name|trbh
value|u_trb.uc_trb.uc_trbh
end_define

begin_typedef
typedef|typedef
struct|struct
name|timer_channel
block|{
name|unsigned
name|short
name|tcnt
decl_stmt|;
comment|/* rw */
name|unsigned
name|short
name|tconr
decl_stmt|;
comment|/* wo */
name|unsigned
name|char
name|tcsr
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|tepr
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused
index|[
literal|2
index|]
decl_stmt|;
block|}
name|timer_channel
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dmac_channel
block|{
name|unsigned
name|short
name|dar
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|darb
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused0
decl_stmt|;
name|unsigned
name|short
name|sar
decl_stmt|;
comment|/* rw On odd numbered dmacs (tx) only */
name|unsigned
name|char
name|sarb
decl_stmt|;
comment|/* rw */
define|#
directive|define
name|cpb
value|sarb
name|unsigned
name|char
name|unused1
decl_stmt|;
name|unsigned
name|short
name|cda
decl_stmt|;
comment|/* rw */
name|unsigned
name|short
name|eda
decl_stmt|;
comment|/* rw */
name|unsigned
name|short
name|bfl
decl_stmt|;
comment|/* rw On even numbered dmacs (rx) only */
name|unsigned
name|short
name|bcr
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|dsr
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|dmr
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused2
decl_stmt|;
name|unsigned
name|char
name|fct
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|dir
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|dcr
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused3
index|[
literal|10
index|]
decl_stmt|;
block|}
name|dmac_channel
typedef|;
end_typedef

begin_comment
comment|/* x is the channel number. rx channels are even numbered and tx, odd. */
end_comment

begin_define
define|#
directive|define
name|DMAC_RXCH
parameter_list|(
name|x
parameter_list|)
value|((x*2) + 0)
end_define

begin_define
define|#
directive|define
name|DMAC_TXCH
parameter_list|(
name|x
parameter_list|)
value|((x*2) + 1)
end_define

begin_typedef
typedef|typedef
struct|struct
name|sca_regs
block|{
name|unsigned
name|char
name|lpr
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused0
decl_stmt|;
comment|/* -- */
comment|/* Wait system */
name|unsigned
name|char
name|pabr0
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|pabr1
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|wcrl
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|wcrm
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|wcrh
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused1
decl_stmt|;
comment|/* DMAC */
name|unsigned
name|char
name|pcr
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|dmer
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused2
index|[
literal|6
index|]
decl_stmt|;
comment|/* Interrupt */
name|unsigned
name|char
name|isr0
decl_stmt|;
comment|/* ro */
name|unsigned
name|char
name|isr1
decl_stmt|;
comment|/* ro */
name|unsigned
name|char
name|isr2
decl_stmt|;
comment|/* ro */
name|unsigned
name|char
name|unused3
decl_stmt|;
name|unsigned
name|char
name|ier0
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|ier1
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|ier2
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused4
decl_stmt|;
name|unsigned
name|char
name|itcr
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused5
decl_stmt|;
name|unsigned
name|char
name|ivr
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused6
decl_stmt|;
name|unsigned
name|char
name|imvr
decl_stmt|;
comment|/* rw */
name|unsigned
name|char
name|unused7
index|[
literal|3
index|]
decl_stmt|;
comment|/* MSCI Channel 0 */
name|msci_channel
name|msci
index|[
literal|2
index|]
decl_stmt|;
name|timer_channel
name|timer
index|[
literal|4
index|]
decl_stmt|;
name|dmac_channel
name|dmac
index|[
literal|4
index|]
decl_stmt|;
block|}
name|sca_regs
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SCA_CMD_TXRESET
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_CMD_TXENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|SCA_CMD_TXDISABLE
value|0x03
end_define

begin_define
define|#
directive|define
name|SCA_CMD_TXCRCINIT
value|0x04
end_define

begin_define
define|#
directive|define
name|SCA_CMD_TXCRCEXCL
value|0x05
end_define

begin_define
define|#
directive|define
name|SCA_CMS_TXEOM
value|0x06
end_define

begin_define
define|#
directive|define
name|SCA_CMD_TXABORT
value|0x07
end_define

begin_define
define|#
directive|define
name|SCA_CMD_MPON
value|0x08
end_define

begin_define
define|#
directive|define
name|SCA_CMD_TXBCLEAR
value|0x09
end_define

begin_define
define|#
directive|define
name|SCA_CMD_RXRESET
value|0x11
end_define

begin_define
define|#
directive|define
name|SCA_CMD_RXENABLE
value|0x12
end_define

begin_define
define|#
directive|define
name|SCA_CMD_RXDISABLE
value|0x13
end_define

begin_define
define|#
directive|define
name|SCA_CMD_RXCRCINIT
value|0x14
end_define

begin_define
define|#
directive|define
name|SCA_CMD_RXMSGREJ
value|0x15
end_define

begin_define
define|#
directive|define
name|SCA_CMD_MPSEARCH
value|0x16
end_define

begin_define
define|#
directive|define
name|SCA_CMD_RXCRCEXCL
value|0x17
end_define

begin_define
define|#
directive|define
name|SCA_CMD_RXCRCCALC
value|0x18
end_define

begin_define
define|#
directive|define
name|SCA_CMD_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|SCA_CMD_RESET
value|0x21
end_define

begin_define
define|#
directive|define
name|SCA_CMD_SEARCH
value|0x31
end_define

begin_define
define|#
directive|define
name|SCA_MD0_CRC_1
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_MD0_CRC_CCITT
value|0x02
end_define

begin_define
define|#
directive|define
name|SCA_MD0_CRC_ENABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|SCA_MD0_AUTO_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|SCA_MD0_MODE_ASYNC
value|0x00
end_define

begin_define
define|#
directive|define
name|SCA_MD0_MODE_BYTESYNC1
value|0x20
end_define

begin_define
define|#
directive|define
name|SCA_MD0_MODE_BISYNC
value|0x40
end_define

begin_define
define|#
directive|define
name|SCA_MD0_MODE_BYTESYNC2
value|0x60
end_define

begin_define
define|#
directive|define
name|SCA_MD0_MODE_HDLC
value|0x80
end_define

begin_define
define|#
directive|define
name|SCA_MD1_NOADDRCHK
value|0x00
end_define

begin_define
define|#
directive|define
name|SCA_MD1_SNGLADDR1
value|0x40
end_define

begin_define
define|#
directive|define
name|SCA_MD1_SNGLADDR2
value|0x80
end_define

begin_define
define|#
directive|define
name|SCA_MD1_DUALADDR
value|0xC0
end_define

begin_define
define|#
directive|define
name|SCA_MD2_DUPLEX
value|0x00
end_define

begin_define
define|#
directive|define
name|SCA_MD2_ECHO
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_MD2_LOOPBACK
value|0x03
end_define

begin_define
define|#
directive|define
name|SCA_MD2_ADPLLx8
value|0x00
end_define

begin_define
define|#
directive|define
name|SCA_MD2_ADPLLx16
value|0x08
end_define

begin_define
define|#
directive|define
name|SCA_MD2_ADPLLx32
value|0x10
end_define

begin_define
define|#
directive|define
name|SCA_MD2_NRZ
value|0x00
end_define

begin_define
define|#
directive|define
name|SCA_MD2_NRZI
value|0x20
end_define

begin_define
define|#
directive|define
name|SCA_MD2_MANCHESTER
value|0x80
end_define

begin_define
define|#
directive|define
name|SCA_MD2_FM0
value|0xC0
end_define

begin_define
define|#
directive|define
name|SCA_MD2_FM1
value|0xA0
end_define

begin_define
define|#
directive|define
name|SCA_CTL_RTS
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_CTL_IDLPAT
value|0x10
end_define

begin_define
define|#
directive|define
name|SCA_CTL_UDRNC
value|0x20
end_define

begin_define
define|#
directive|define
name|SCA_RXS_DIV_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|SCA_RXS_DIV1
value|0x00
end_define

begin_define
define|#
directive|define
name|SCA_RXS_DIV2
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_RXS_DIV4
value|0x02
end_define

begin_define
define|#
directive|define
name|SCA_RXS_DIV8
value|0x03
end_define

begin_define
define|#
directive|define
name|SCA_RXS_DIV16
value|0x04
end_define

begin_define
define|#
directive|define
name|SCA_RXS_DIV32
value|0x05
end_define

begin_define
define|#
directive|define
name|SCA_RXS_DIV64
value|0x06
end_define

begin_define
define|#
directive|define
name|SCA_RXS_DIV128
value|0x07
end_define

begin_define
define|#
directive|define
name|SCA_RXS_DIV256
value|0x08
end_define

begin_define
define|#
directive|define
name|SCA_RXS_DIV512
value|0x09
end_define

begin_define
define|#
directive|define
name|SCA_RXS_CLK_RXC0
value|0x00
end_define

begin_define
define|#
directive|define
name|SCA_RXS_CLK_RXC1
value|0x20
end_define

begin_define
define|#
directive|define
name|SCA_RXS_CLK_INT
value|0x40
end_define

begin_define
define|#
directive|define
name|SCA_RXS_CLK_ADPLL_OUT
value|0x60
end_define

begin_define
define|#
directive|define
name|SCA_RXS_CLK_ADPLL_IN
value|0x70
end_define

begin_define
define|#
directive|define
name|SCA_TXS_DIV_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|SCA_TXS_DIV1
value|0x00
end_define

begin_define
define|#
directive|define
name|SCA_TXS_DIV2
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_TXS_DIV4
value|0x02
end_define

begin_define
define|#
directive|define
name|SCA_TXS_DIV8
value|0x03
end_define

begin_define
define|#
directive|define
name|SCA_TXS_DIV16
value|0x04
end_define

begin_define
define|#
directive|define
name|SCA_TXS_DIV32
value|0x05
end_define

begin_define
define|#
directive|define
name|SCA_TXS_DIV64
value|0x06
end_define

begin_define
define|#
directive|define
name|SCA_TXS_DIV128
value|0x07
end_define

begin_define
define|#
directive|define
name|SCA_TXS_DIV256
value|0x08
end_define

begin_define
define|#
directive|define
name|SCA_TXS_DIV512
value|0x09
end_define

begin_define
define|#
directive|define
name|SCA_TXS_CLK_TXC
value|0x00
end_define

begin_define
define|#
directive|define
name|SCA_TXS_CLK_INT
value|0x40
end_define

begin_define
define|#
directive|define
name|SCA_TXS_CLK_RX
value|0x60
end_define

begin_define
define|#
directive|define
name|SCA_ST0_RXRDY
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_ST0_TXRDY
value|0x02
end_define

begin_define
define|#
directive|define
name|SCA_ST0_RXINT
value|0x40
end_define

begin_define
define|#
directive|define
name|SCA_ST0_TXINT
value|0x80
end_define

begin_define
define|#
directive|define
name|SCA_ST1_IDLST
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_ST1_ABTST
value|0x02
end_define

begin_define
define|#
directive|define
name|SCA_ST1_DCDCHG
value|0x04
end_define

begin_define
define|#
directive|define
name|SCA_ST1_CTSCHG
value|0x08
end_define

begin_define
define|#
directive|define
name|SCA_ST1_FLAG
value|0x10
end_define

begin_define
define|#
directive|define
name|SCA_ST1_TXIDL
value|0x40
end_define

begin_define
define|#
directive|define
name|SCA_ST1_UDRN
value|0x80
end_define

begin_comment
comment|/* ST2 and FST look the same */
end_comment

begin_define
define|#
directive|define
name|SCA_FST_CRCERR
value|0x04
end_define

begin_define
define|#
directive|define
name|SCA_FST_OVRN
value|0x08
end_define

begin_define
define|#
directive|define
name|SCA_FST_RESFRM
value|0x10
end_define

begin_define
define|#
directive|define
name|SCA_FST_ABRT
value|0x20
end_define

begin_define
define|#
directive|define
name|SCA_FST_SHRT
value|0x40
end_define

begin_define
define|#
directive|define
name|SCA_FST_EOM
value|0x80
end_define

begin_define
define|#
directive|define
name|SCA_ST3_RXENA
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_ST3_TXENA
value|0x02
end_define

begin_define
define|#
directive|define
name|SCA_ST3_DCD
value|0x04
end_define

begin_define
define|#
directive|define
name|SCA_ST3_CTS
value|0x08
end_define

begin_define
define|#
directive|define
name|SCA_ST3_ADPLLSRCH
value|0x10
end_define

begin_define
define|#
directive|define
name|SCA_ST3_TXDATA
value|0x20
end_define

begin_define
define|#
directive|define
name|SCA_FIE_EOMFE
value|0x80
end_define

begin_define
define|#
directive|define
name|SCA_IE0_RXRDY
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_IE0_TXRDY
value|0x02
end_define

begin_define
define|#
directive|define
name|SCA_IE0_RXINT
value|0x40
end_define

begin_define
define|#
directive|define
name|SCA_IE0_TXINT
value|0x80
end_define

begin_define
define|#
directive|define
name|SCA_IE1_IDLDE
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_IE1_ABTDE
value|0x02
end_define

begin_define
define|#
directive|define
name|SCA_IE1_DCD
value|0x04
end_define

begin_define
define|#
directive|define
name|SCA_IE1_CTS
value|0x08
end_define

begin_define
define|#
directive|define
name|SCA_IE1_FLAG
value|0x10
end_define

begin_define
define|#
directive|define
name|SCA_IE1_IDL
value|0x40
end_define

begin_define
define|#
directive|define
name|SCA_IE1_UDRN
value|0x80
end_define

begin_define
define|#
directive|define
name|SCA_IE2_CRCERR
value|0x04
end_define

begin_define
define|#
directive|define
name|SCA_IE2_OVRN
value|0x08
end_define

begin_define
define|#
directive|define
name|SCA_IE2_RESFRM
value|0x10
end_define

begin_define
define|#
directive|define
name|SCA_IE2_ABRT
value|0x20
end_define

begin_define
define|#
directive|define
name|SCA_IE2_SHRT
value|0x40
end_define

begin_define
define|#
directive|define
name|SCA_IE2_EOM
value|0x80
end_define

begin_comment
comment|/* This is for RRC, TRC0 and TRC1. */
end_comment

begin_define
define|#
directive|define
name|SCA_RCR_MASK
value|0x1F
end_define

begin_define
define|#
directive|define
name|SCA_IE1_
end_define

begin_define
define|#
directive|define
name|SCA_IV_CHAN0
value|0x00
end_define

begin_define
define|#
directive|define
name|SCA_IV_CHAN1
value|0x20
end_define

begin_define
define|#
directive|define
name|SCA_IV_RXRDY
value|0x04
end_define

begin_define
define|#
directive|define
name|SCA_IV_TXRDY
value|0x06
end_define

begin_define
define|#
directive|define
name|SCA_IV_RXINT
value|0x08
end_define

begin_define
define|#
directive|define
name|SCA_IV_TXINT
value|0x0A
end_define

begin_define
define|#
directive|define
name|SCA_IV_DMACH0
value|0x00
end_define

begin_define
define|#
directive|define
name|SCA_IV_DMACH1
value|0x08
end_define

begin_define
define|#
directive|define
name|SCA_IV_DMACH2
value|0x20
end_define

begin_define
define|#
directive|define
name|SCA_IV_DMACH3
value|0x28
end_define

begin_define
define|#
directive|define
name|SCA_IV_DMIA
value|0x14
end_define

begin_define
define|#
directive|define
name|SCA_IV_DMIB
value|0x16
end_define

begin_define
define|#
directive|define
name|SCA_IV_TIMER0
value|0x1C
end_define

begin_define
define|#
directive|define
name|SCA_IV_TIMER1
value|0x1E
end_define

begin_define
define|#
directive|define
name|SCA_IV_TIMER2
value|0x3C
end_define

begin_define
define|#
directive|define
name|SCA_IV_TIMER3
value|0x3E
end_define

begin_comment
comment|/*  * DMA registers  */
end_comment

begin_define
define|#
directive|define
name|SCA_DSR_EOT
value|0x80
end_define

begin_define
define|#
directive|define
name|SCA_DSR_EOM
value|0x40
end_define

begin_define
define|#
directive|define
name|SCA_DSR_BOF
value|0x20
end_define

begin_define
define|#
directive|define
name|SCA_DSR_COF
value|0x10
end_define

begin_define
define|#
directive|define
name|SCA_DSR_DE
value|0x02
end_define

begin_define
define|#
directive|define
name|SCA_DSR_DWE
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_DMR_TMOD
value|0x10
end_define

begin_define
define|#
directive|define
name|SCA_DMR_NF
value|0x04
end_define

begin_define
define|#
directive|define
name|SCA_DMR_CNTE
value|0x02
end_define

begin_define
define|#
directive|define
name|SCA_DMER_EN
value|0x80
end_define

begin_define
define|#
directive|define
name|SCA_DCR_ABRT
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_DCR_FCCLR
value|0x02
end_define

begin_comment
comment|/* Clear frame end intr counter */
end_comment

begin_define
define|#
directive|define
name|SCA_DIR_EOT
value|0x80
end_define

begin_define
define|#
directive|define
name|SCA_DIR_EOM
value|0x40
end_define

begin_define
define|#
directive|define
name|SCA_DIR_BOF
value|0x20
end_define

begin_define
define|#
directive|define
name|SCA_DIR_COF
value|0x10
end_define

begin_define
define|#
directive|define
name|SCA_PCR_BRC
value|0x10
end_define

begin_define
define|#
directive|define
name|SCA_PCR_CCC
value|0x08
end_define

begin_define
define|#
directive|define
name|SCA_PCR_PR2
value|0x04
end_define

begin_define
define|#
directive|define
name|SCA_PCR_PR1
value|0x02
end_define

begin_define
define|#
directive|define
name|SCA_PCR_PR0
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|sca_descriptor
block|{
name|unsigned
name|short
name|cp
decl_stmt|;
name|unsigned
name|short
name|bp
decl_stmt|;
name|unsigned
name|char
name|bpb
decl_stmt|;
name|unsigned
name|char
name|unused0
decl_stmt|;
name|unsigned
name|short
name|len
decl_stmt|;
name|unsigned
name|char
name|stat
decl_stmt|;
name|unsigned
name|char
name|unused1
decl_stmt|;
block|}
name|sca_descriptor
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SCA_DESC_EOT
value|0x01
end_define

begin_define
define|#
directive|define
name|SCA_DESC_CRC
value|0x04
end_define

begin_define
define|#
directive|define
name|SCA_DESC_OVRN
value|0x08
end_define

begin_define
define|#
directive|define
name|SCA_DESC_RESD
value|0x10
end_define

begin_define
define|#
directive|define
name|SCA_DESC_ABORT
value|0x20
end_define

begin_define
define|#
directive|define
name|SCA_DESC_SHRTFRM
value|0x40
end_define

begin_define
define|#
directive|define
name|SCA_DESC_EOM
value|0x80
end_define

begin_define
define|#
directive|define
name|SCA_DESC_ERRORS
value|0x7C
end_define

begin_comment
comment|/* *************************************************************************** **                                 END *************************************************************************** **/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HD64570_H_ */
end_comment

end_unit

