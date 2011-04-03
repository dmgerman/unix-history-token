begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Aleksandr Rybalko.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or  * without modification, are permitted provided that the following  * conditions are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above  *    copyright notice, this list of conditions and the following  *    disclaimer in the documentation and/or other materials provided  *    with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RT305XUART_H
end_ifndef

begin_define
define|#
directive|define
name|_RT305XUART_H
end_define

begin_undef
undef|#
directive|undef
name|uart_getreg
end_undef

begin_undef
undef|#
directive|undef
name|uart_setreg
end_undef

begin_define
define|#
directive|define
name|uart_getreg
parameter_list|(
name|bas
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((bas)->bst, (bas)->bsh, reg)
end_define

begin_define
define|#
directive|define
name|uart_setreg
parameter_list|(
name|bas
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_4((bas)->bst, (bas)->bsh, reg, value)
end_define

begin_comment
comment|/* UART registers */
end_comment

begin_define
define|#
directive|define
name|UART_RX_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|UART_TX_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|UART_IER_REG
value|0x08
end_define

begin_define
define|#
directive|define
name|UART_IER_EDSSI
value|(1<<3)
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_IER_ELSI
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|UART_IER_ETBEI
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|UART_IER_ERBFI
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|UART_IIR_REG
value|0x0c
end_define

begin_define
define|#
directive|define
name|UART_IIR_RXFIFO
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|UART_IIR_TXFIFO
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|UART_IIR_ID_MST
value|0
end_define

begin_define
define|#
directive|define
name|UART_IIR_ID_THRE
value|1
end_define

begin_define
define|#
directive|define
name|UART_IIR_ID_DR
value|2
end_define

begin_define
define|#
directive|define
name|UART_IIR_ID_LINESTATUS
value|3
end_define

begin_define
define|#
directive|define
name|UART_IIR_ID_DR2
value|6
end_define

begin_define
define|#
directive|define
name|UART_IIR_ID_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|UART_IIR_ID_MASK
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|UART_IIR_INTP
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|UART_FCR_REG
value|0x10
end_define

begin_define
define|#
directive|define
name|UART_FCR_RXTGR_1
value|(0<<6)
end_define

begin_define
define|#
directive|define
name|UART_FCR_RXTGR_4
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|UART_FCR_RXTGR_8
value|(2<<6)
end_define

begin_define
define|#
directive|define
name|UART_FCR_RXTGR_12
value|(3<<6)
end_define

begin_define
define|#
directive|define
name|UART_FCR_TXTGR_1
value|(0<<4)
end_define

begin_define
define|#
directive|define
name|UART_FCR_TXTGR_4
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|UART_FCR_TXTGR_8
value|(2<<4)
end_define

begin_define
define|#
directive|define
name|UART_FCR_TXTGR_12
value|(3<<4)
end_define

begin_define
define|#
directive|define
name|UART_FCR_DMA
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|UART_FCR_TXRST
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|UART_FCR_RXRST
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|UART_FCR_FIFOEN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|UART_LCR_REG
value|0x14
end_define

begin_define
define|#
directive|define
name|UART_LCR_DLAB
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|UART_LCR_BRK
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|UART_LCR_FPAR
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|UART_LCR_EVEN
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|UART_LCR_PEN
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|UART_LCR_STB_15
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|UART_LCR_5B
value|0
end_define

begin_define
define|#
directive|define
name|UART_LCR_6B
value|1
end_define

begin_define
define|#
directive|define
name|UART_LCR_7B
value|2
end_define

begin_define
define|#
directive|define
name|UART_LCR_8B
value|3
end_define

begin_define
define|#
directive|define
name|UART_MCR_REG
value|0x18
end_define

begin_define
define|#
directive|define
name|UART_MCR_LOOP
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|UART_MCR_OUT2_L
value|(1<<3)
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_MCR_OUT1_L
value|(1<<2)
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_MCR_RTS_L
value|(1<<1)
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_MCR_DTR_L
value|(1<<0)
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_LSR_REG
value|0x1c
end_define

begin_define
define|#
directive|define
name|UART_LSR_ERINF
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|UART_LSR_TEMT
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|UART_LSR_THRE
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|UART_LSR_BI
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|UART_LSR_FE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|UART_LSR_PE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|UART_LSR_OE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|UART_LSR_DR
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|UART_MSR_REG
value|0x20
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_MSR_DCD
value|(1<<7)
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_MSR_RI
value|(1<<6)
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_MSR_DSR
value|(1<<5)
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_MSR_CTS
value|(1<<4)
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_MSR_DDCD
value|(1<<3)
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_MSR_TERI
value|(1<<2)
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_MSR_DDSR
value|(1<<1)
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_MSR_DCTS
value|(1<<0)
end_define

begin_comment
comment|/* Only full UART */
end_comment

begin_define
define|#
directive|define
name|UART_CDDL_REG
value|0x28
end_define

begin_define
define|#
directive|define
name|UART_CDDLL_REG
value|0x2c
end_define

begin_define
define|#
directive|define
name|UART_CDDLH_REG
value|0x30
end_define

begin_define
define|#
directive|define
name|UART_IFCTL_REG
value|0x34
end_define

begin_define
define|#
directive|define
name|UART_IFCTL_IFCTL
value|(1<<0)
end_define

begin_function_decl
name|int
name|uart_cnattach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RT305XUART_H */
end_comment

end_unit

