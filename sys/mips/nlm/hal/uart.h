begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XLP_HAL_UART_H__
end_ifndef

begin_define
define|#
directive|define
name|__XLP_HAL_UART_H__
end_define

begin_comment
comment|/* UART Specific registers */
end_comment

begin_define
define|#
directive|define
name|UART_RX_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|UART_TX_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|UART_INT_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|UART_INT_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|UART_FIFO_CTL
value|0x02
end_define

begin_define
define|#
directive|define
name|UART_LINE_CTL
value|0x03
end_define

begin_define
define|#
directive|define
name|UART_MODEM_CTL
value|0x04
end_define

begin_define
define|#
directive|define
name|UART_LINE_STS
value|0x05
end_define

begin_define
define|#
directive|define
name|UART_MODEM_STS
value|0x06
end_define

begin_define
define|#
directive|define
name|UART_DIVISOR0
value|0x00
end_define

begin_define
define|#
directive|define
name|UART_DIVISOR1
value|0x01
end_define

begin_define
define|#
directive|define
name|BASE_BAUD
value|(XLP_IO_CLK/16)
end_define

begin_define
define|#
directive|define
name|BAUD_DIVISOR
parameter_list|(
name|baud
parameter_list|)
value|(BASE_BAUD / baud)
end_define

begin_comment
comment|/* LCR mask values */
end_comment

begin_define
define|#
directive|define
name|LCR_5BITS
value|0x00
end_define

begin_define
define|#
directive|define
name|LCR_6BITS
value|0x01
end_define

begin_define
define|#
directive|define
name|LCR_7BITS
value|0x02
end_define

begin_define
define|#
directive|define
name|LCR_8BITS
value|0x03
end_define

begin_define
define|#
directive|define
name|LCR_STOPB
value|0x04
end_define

begin_define
define|#
directive|define
name|LCR_PENAB
value|0x08
end_define

begin_define
define|#
directive|define
name|LCR_PODD
value|0x00
end_define

begin_define
define|#
directive|define
name|LCR_PEVEN
value|0x10
end_define

begin_define
define|#
directive|define
name|LCR_PONE
value|0x20
end_define

begin_define
define|#
directive|define
name|LCR_PZERO
value|0x30
end_define

begin_define
define|#
directive|define
name|LCR_SBREAK
value|0x40
end_define

begin_define
define|#
directive|define
name|LCR_EFR_ENABLE
value|0xbf
end_define

begin_define
define|#
directive|define
name|LCR_DLAB
value|0x80
end_define

begin_comment
comment|/* MCR mask values */
end_comment

begin_define
define|#
directive|define
name|MCR_DTR
value|0x01
end_define

begin_define
define|#
directive|define
name|MCR_RTS
value|0x02
end_define

begin_define
define|#
directive|define
name|MCR_DRS
value|0x04
end_define

begin_define
define|#
directive|define
name|MCR_IE
value|0x08
end_define

begin_define
define|#
directive|define
name|MCR_LOOPBACK
value|0x10
end_define

begin_comment
comment|/* FCR mask values */
end_comment

begin_define
define|#
directive|define
name|FCR_RCV_RST
value|0x02
end_define

begin_define
define|#
directive|define
name|FCR_XMT_RST
value|0x04
end_define

begin_define
define|#
directive|define
name|FCR_RX_LOW
value|0x00
end_define

begin_define
define|#
directive|define
name|FCR_RX_MEDL
value|0x40
end_define

begin_define
define|#
directive|define
name|FCR_RX_MEDH
value|0x80
end_define

begin_define
define|#
directive|define
name|FCR_RX_HIGH
value|0xc0
end_define

begin_comment
comment|/* IER mask values */
end_comment

begin_define
define|#
directive|define
name|IER_ERXRDY
value|0x1
end_define

begin_define
define|#
directive|define
name|IER_ETXRDY
value|0x2
end_define

begin_define
define|#
directive|define
name|IER_ERLS
value|0x4
end_define

begin_define
define|#
directive|define
name|IER_EMSC
value|0x8
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ASSEMBLY__
argument_list|)
end_if

begin_define
define|#
directive|define
name|nlm_read_uart_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|nlm_read_reg(b, r)
end_define

begin_define
define|#
directive|define
name|nlm_write_uart_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg(b, r, v)
end_define

begin_define
define|#
directive|define
name|nlm_get_uart_pcibase
parameter_list|(
name|node
parameter_list|,
name|inst
parameter_list|)
define|\
value|nlm_pcicfg_base(XLP_IO_UART_OFFSET(node, inst))
end_define

begin_define
define|#
directive|define
name|nlm_get_uart_regbase
parameter_list|(
name|node
parameter_list|,
name|inst
parameter_list|)
define|\
value|(nlm_get_uart_pcibase(node, inst) + XLP_IO_PCI_HDRSZ)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|nlm_uart_set_baudrate
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|baud
parameter_list|)
block|{
name|uint32_t
name|lcr
decl_stmt|;
name|lcr
operator|=
name|nlm_read_uart_reg
argument_list|(
name|base
argument_list|,
name|UART_LINE_CTL
argument_list|)
expr_stmt|;
comment|/* enable divisor register, and write baud values */
name|nlm_write_uart_reg
argument_list|(
name|base
argument_list|,
name|UART_LINE_CTL
argument_list|,
name|lcr
operator||
operator|(
literal|1
operator|<<
literal|7
operator|)
argument_list|)
expr_stmt|;
name|nlm_write_uart_reg
argument_list|(
name|base
argument_list|,
name|UART_DIVISOR0
argument_list|,
operator|(
name|BAUD_DIVISOR
argument_list|(
name|baud
argument_list|)
operator|&
literal|0xff
operator|)
argument_list|)
expr_stmt|;
name|nlm_write_uart_reg
argument_list|(
name|base
argument_list|,
name|UART_DIVISOR1
argument_list|,
operator|(
operator|(
name|BAUD_DIVISOR
argument_list|(
name|baud
argument_list|)
operator|>>
literal|8
operator|)
operator|&
literal|0xff
operator|)
argument_list|)
expr_stmt|;
comment|/* restore default lcr */
name|nlm_write_uart_reg
argument_list|(
name|base
argument_list|,
name|UART_LINE_CTL
argument_list|,
name|lcr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nlm_uart_outbyte
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|char
name|c
parameter_list|)
block|{
name|uint32_t
name|lsr
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|lsr
operator|=
name|nlm_read_uart_reg
argument_list|(
name|base
argument_list|,
name|UART_LINE_STS
argument_list|)
expr_stmt|;
if|if
condition|(
name|lsr
operator|&
literal|0x20
condition|)
break|break;
block|}
name|nlm_write_uart_reg
argument_list|(
name|base
argument_list|,
name|UART_TX_DATA
argument_list|,
operator|(
name|int
operator|)
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|char
name|nlm_uart_inbyte
parameter_list|(
name|uint64_t
name|base
parameter_list|)
block|{
name|int
name|data
decl_stmt|,
name|lsr
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|lsr
operator|=
name|nlm_read_uart_reg
argument_list|(
name|base
argument_list|,
name|UART_LINE_STS
argument_list|)
expr_stmt|;
if|if
condition|(
name|lsr
operator|&
literal|0x80
condition|)
block|{
comment|/* parity/frame/break-error - push a zero */
name|data
operator|=
literal|0
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|lsr
operator|&
literal|0x01
condition|)
block|{
comment|/* Rx data */
name|data
operator|=
name|nlm_read_uart_reg
argument_list|(
name|base
argument_list|,
name|UART_RX_DATA
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
return|return
operator|(
name|char
operator|)
name|data
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|nlm_uart_init
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|baud
parameter_list|,
name|int
name|databits
parameter_list|,
name|int
name|stopbits
parameter_list|,
name|int
name|parity
parameter_list|,
name|int
name|int_en
parameter_list|,
name|int
name|loopback
parameter_list|)
block|{
name|uint32_t
name|lcr
decl_stmt|;
name|lcr
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|databits
operator|>=
literal|8
condition|)
name|lcr
operator||=
name|LCR_8BITS
expr_stmt|;
elseif|else
if|if
condition|(
name|databits
operator|==
literal|7
condition|)
name|lcr
operator||=
name|LCR_7BITS
expr_stmt|;
elseif|else
if|if
condition|(
name|databits
operator|==
literal|6
condition|)
name|lcr
operator||=
name|LCR_6BITS
expr_stmt|;
else|else
name|lcr
operator||=
name|LCR_5BITS
expr_stmt|;
if|if
condition|(
name|stopbits
operator|>
literal|1
condition|)
name|lcr
operator||=
name|LCR_STOPB
expr_stmt|;
name|lcr
operator||=
name|parity
operator|<<
literal|3
expr_stmt|;
comment|/* setup default lcr */
name|nlm_write_uart_reg
argument_list|(
name|base
argument_list|,
name|UART_LINE_CTL
argument_list|,
name|lcr
argument_list|)
expr_stmt|;
comment|/* Reset the FIFOs */
name|nlm_write_uart_reg
argument_list|(
name|base
argument_list|,
name|UART_LINE_CTL
argument_list|,
name|FCR_RCV_RST
operator||
name|FCR_XMT_RST
argument_list|)
expr_stmt|;
name|nlm_uart_set_baudrate
argument_list|(
name|base
argument_list|,
name|baud
argument_list|)
expr_stmt|;
if|if
condition|(
name|loopback
condition|)
name|nlm_write_uart_reg
argument_list|(
name|base
argument_list|,
name|UART_MODEM_CTL
argument_list|,
literal|0x1f
argument_list|)
expr_stmt|;
if|if
condition|(
name|int_en
condition|)
name|nlm_write_uart_reg
argument_list|(
name|base
argument_list|,
name|UART_INT_EN
argument_list|,
name|IER_ERXRDY
operator||
name|IER_ETXRDY
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE&& !__ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XLP_HAL_UART_H__ */
end_comment

end_unit

