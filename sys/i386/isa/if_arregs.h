begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1999 John Hay.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY [your name] AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_ARREGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_ARREGS_H_
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
name|NPORT
value|4
end_define

begin_comment
comment|/* A ArNet board can have 4 ports or */
end_comment

begin_comment
comment|/* channels */
end_comment

begin_define
define|#
directive|define
name|AR_BUF_SIZ
value|512
end_define

begin_define
define|#
directive|define
name|AR_TX_BLOCKS
value|2
end_define

begin_define
define|#
directive|define
name|ARC_IO_SIZ
value|0x10
end_define

begin_define
define|#
directive|define
name|ARC_WIN_SIZ
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ARC_WIN_MSK
value|(ARC_WIN_SIZ - 1)
end_define

begin_define
define|#
directive|define
name|ARC_WIN_SHFT
value|14
end_define

begin_comment
comment|/* Some PCI specific offsets. */
end_comment

begin_define
define|#
directive|define
name|AR_PCI_SCA_1_OFFSET
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_PCI_SCA_2_OFFSET
value|0x00040400
end_define

begin_define
define|#
directive|define
name|AR_PCI_ORBASE_OFFSET
value|0x00041000
end_define

begin_define
define|#
directive|define
name|AR_PCI_SCA_PCR
value|0x0208
end_define

begin_define
define|#
directive|define
name|AR_PCI_SCA_DMER
value|0x0309
end_define

begin_comment
comment|/* PCI Legacy (below 1M) offsets. */
end_comment

begin_define
define|#
directive|define
name|AR_PCI_L_SCA_1_OFFSET
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AR_PCI_L_SCA_2_OFFSET
value|0x00004400
end_define

begin_define
define|#
directive|define
name|AR_PCI_L_ORBASE_OFFSET
value|0x00005000
end_define

begin_define
define|#
directive|define
name|AR_ID_5
value|0x00
end_define

begin_comment
comment|/* RO, Card probe '5' */
end_comment

begin_define
define|#
directive|define
name|AR_ID_7
value|0x01
end_define

begin_comment
comment|/* RO, Card probe '7' */
end_comment

begin_define
define|#
directive|define
name|AR_ID_0
value|0x02
end_define

begin_comment
comment|/* RO, Card probe '0' */
end_comment

begin_define
define|#
directive|define
name|AR_BMI
value|0x03
end_define

begin_comment
comment|/* RO, Bus, mem and interface type */
end_comment

begin_define
define|#
directive|define
name|AR_REV
value|0x04
end_define

begin_comment
comment|/* RO, Adapter revision */
end_comment

begin_define
define|#
directive|define
name|AR_PNUM
value|0x05
end_define

begin_comment
comment|/* RO, Port number */
end_comment

begin_define
define|#
directive|define
name|AR_HNDSH
value|0x06
end_define

begin_comment
comment|/* RO, Supported handshake */
end_comment

begin_define
define|#
directive|define
name|AR_ISTAT
value|0x07
end_define

begin_comment
comment|/* RO, DCD and Interrupt status */
end_comment

begin_define
define|#
directive|define
name|AR_MSCA_EN
value|0x08
end_define

begin_comment
comment|/* WO, Memory and SCA enable */
end_comment

begin_define
define|#
directive|define
name|AR_TXC_DTR0
value|0x09
end_define

begin_comment
comment|/* WO, Tx Clock and DTR control 0 + 1 */
end_comment

begin_define
define|#
directive|define
name|AR_SEC_PAL
value|0x0A
end_define

begin_comment
comment|/* RW, Security PAL */
end_comment

begin_define
define|#
directive|define
name|AR_INT_ACK0
value|0x0B
end_define

begin_comment
comment|/* RO, Interrupt Acknowledge 0 + 1 */
end_comment

begin_define
define|#
directive|define
name|AR_INT_SEL
value|0x0C
end_define

begin_comment
comment|/* RW, Interrupt Select */
end_comment

begin_define
define|#
directive|define
name|AR_MEM_SEL
value|0x0D
end_define

begin_comment
comment|/* RW, Memory Select */
end_comment

begin_define
define|#
directive|define
name|AR_INT_ACK2
value|0x0E
end_define

begin_comment
comment|/* RO, Interrupt Acknowledge 2 + 3 */
end_comment

begin_define
define|#
directive|define
name|AR_TXC_DTR2
value|0x0E
end_define

begin_comment
comment|/* WO, Tx Clock and DTR control 2 + 3 */
end_comment

begin_comment
comment|/* PCI only */
end_comment

begin_define
define|#
directive|define
name|AR_PIMCTRL
value|0x4C
end_define

begin_comment
comment|/* RW, PIM and LEDs */
end_comment

begin_define
define|#
directive|define
name|AR_INT_SCB
value|0x50
end_define

begin_comment
comment|/* RO, Interrupt Scoreboard */
end_comment

begin_define
define|#
directive|define
name|AR_REV_MSK
value|0x0F
end_define

begin_define
define|#
directive|define
name|AR_WSIZ_MSK
value|0xE0
end_define

begin_define
define|#
directive|define
name|AR_WSIZ_SHFT
value|5
end_define

begin_comment
comment|/* Bus memory and interface type */
end_comment

begin_define
define|#
directive|define
name|AR_BUS_MSK
value|0x03
end_define

begin_define
define|#
directive|define
name|AR_BUS_ISA
value|0x00
end_define

begin_define
define|#
directive|define
name|AR_BUS_MCA
value|0x01
end_define

begin_define
define|#
directive|define
name|AR_BUS_EISA
value|0x02
end_define

begin_define
define|#
directive|define
name|AR_BUS_PCI
value|0x03
end_define

begin_define
define|#
directive|define
name|AR_MEM_MSK
value|0x1C
end_define

begin_define
define|#
directive|define
name|AR_MEM_SHFT
value|0x02
end_define

begin_define
define|#
directive|define
name|AR_MEM_64K
value|0x00
end_define

begin_define
define|#
directive|define
name|AR_MEM_128K
value|0x04
end_define

begin_define
define|#
directive|define
name|AR_MEM_256K
value|0x08
end_define

begin_define
define|#
directive|define
name|AR_MEM_512K
value|0x0C
end_define

begin_comment
comment|/*  * EIA-232  * V.35/EIA-232  * EIA-530  * X.21  * EIA-530/X.21 Combo  */
end_comment

begin_define
define|#
directive|define
name|AR_IFACE_MSK
value|0xE0
end_define

begin_define
define|#
directive|define
name|AR_IFACE_SHFT
value|0x05
end_define

begin_define
define|#
directive|define
name|AR_IFACE_EIA_232
value|0x00
end_define

begin_comment
comment|/* Only on the 570 card, not 570i */
end_comment

begin_define
define|#
directive|define
name|AR_IFACE_V_35
value|0x20
end_define

begin_comment
comment|/* Selectable between V.35 and EIA-232 */
end_comment

begin_define
define|#
directive|define
name|AR_IFACE_EIA_530
value|0x40
end_define

begin_define
define|#
directive|define
name|AR_IFACE_X_21
value|0x60
end_define

begin_define
define|#
directive|define
name|AR_IFACE_COMBO
value|0xC0
end_define

begin_comment
comment|/* X.21 / EIA-530 */
end_comment

begin_define
define|#
directive|define
name|AR_IFACE_PIM
value|0xE0
end_define

begin_comment
comment|/* PIM module */
end_comment

begin_define
define|#
directive|define
name|AR_IFACE_LOOPBACK
value|0xFE
end_define

begin_define
define|#
directive|define
name|AR_IFACE_UNKNOWN
value|0xFF
end_define

begin_comment
comment|/* Supported Handshake signals */
end_comment

begin_define
define|#
directive|define
name|AR_SHSK_DTR
value|0x01
end_define

begin_define
define|#
directive|define
name|AR_SHSK_RTS
value|0x02
end_define

begin_define
define|#
directive|define
name|AR_SHSK_CTS
value|0x10
end_define

begin_define
define|#
directive|define
name|AR_SHSK_DSR
value|0x20
end_define

begin_define
define|#
directive|define
name|AR_SHSK_RI
value|0x40
end_define

begin_define
define|#
directive|define
name|AR_SHSK_DCD
value|0x80
end_define

begin_comment
comment|/* DCD and Interrupt status */
end_comment

begin_define
define|#
directive|define
name|AR_BD_INT
value|0x01
end_define

begin_define
define|#
directive|define
name|AR_INT_0
value|0x20
end_define

begin_define
define|#
directive|define
name|AR_INT_1
value|0x40
end_define

begin_define
define|#
directive|define
name|AR_DCD_MSK
value|0x1E
end_define

begin_define
define|#
directive|define
name|AR_DCD_SHFT
value|0x01
end_define

begin_define
define|#
directive|define
name|AR_DCD_0
value|0x02
end_define

begin_define
define|#
directive|define
name|AR_DCD_1
value|0x04
end_define

begin_define
define|#
directive|define
name|AR_DCD_2
value|0x08
end_define

begin_define
define|#
directive|define
name|AR_DCD_3
value|0x10
end_define

begin_comment
comment|/* Memory and SCA enable */
end_comment

begin_define
define|#
directive|define
name|AR_WIN_MSK
value|0x1F
end_define

begin_define
define|#
directive|define
name|AR_SEL_SCA_0
value|0x00
end_define

begin_define
define|#
directive|define
name|AR_SEL_SCA_1
value|0x20
end_define

begin_define
define|#
directive|define
name|AR_ENA_SCA
value|0x40
end_define

begin_define
define|#
directive|define
name|AR_ENA_MEM
value|0x80
end_define

begin_comment
comment|/* Transmit Clock and DTR and RESET */
end_comment

begin_define
define|#
directive|define
name|AR_TXC_DTR_TX0
value|0x01
end_define

begin_define
define|#
directive|define
name|AR_TXC_DTR_TX1
value|0x02
end_define

begin_define
define|#
directive|define
name|AR_TXC_DTR_DTR0
value|0x04
end_define

begin_define
define|#
directive|define
name|AR_TXC_DTR_DTR1
value|0x08
end_define

begin_define
define|#
directive|define
name|AR_TXC_DTR_TXCS0
value|0x10
end_define

begin_define
define|#
directive|define
name|AR_TXC_DTR_TXCS1
value|0x20
end_define

begin_define
define|#
directive|define
name|AR_TXC_DTR_NOTRESET
value|0x40
end_define

begin_define
define|#
directive|define
name|AR_TXC_DTR_RESET
value|0x00
end_define

begin_comment
comment|/* Interrupt select register */
end_comment

begin_define
define|#
directive|define
name|AR_INTS_CEN
value|0x01
end_define

begin_define
define|#
directive|define
name|AR_INTS_ISEL0
value|0x02
end_define

begin_define
define|#
directive|define
name|AR_INTS_ISEL1
value|0x04
end_define

begin_define
define|#
directive|define
name|AR_INTS_ISEL2
value|0x08
end_define

begin_define
define|#
directive|define
name|AR_INTS_CMA14
value|0x10
end_define

begin_define
define|#
directive|define
name|AR_INTS_CMA15
value|0x20
end_define

begin_comment
comment|/* Advanced PIM Control */
end_comment

begin_define
define|#
directive|define
name|AR_PIM_STROBE
value|0x01
end_define

begin_define
define|#
directive|define
name|AR_PIM_DATA
value|0x02
end_define

begin_define
define|#
directive|define
name|AR_PIM_MODEG
value|0x04
end_define

begin_define
define|#
directive|define
name|AR_PIM_A2D_STROBE
value|0x04
end_define

begin_define
define|#
directive|define
name|AR_PIM_MODEY
value|0x08
end_define

begin_define
define|#
directive|define
name|AR_PIM_A2D_DOUT
value|0x08
end_define

begin_define
define|#
directive|define
name|AR_PIM_AUTO_LED
value|0x10
end_define

begin_define
define|#
directive|define
name|AR_PIM_INT
value|0x20
end_define

begin_define
define|#
directive|define
name|AR_PIM_RESET
value|0x00
end_define

begin_comment
comment|/* MODEG and MODEY 0 */
end_comment

begin_define
define|#
directive|define
name|AR_PIM_READ
value|AR_PIM_MODEG
end_define

begin_define
define|#
directive|define
name|AR_PIM_WRITE
value|AR_PIM_MODEY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_ARREGS_H_ */
end_comment

end_unit

