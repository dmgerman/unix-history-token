begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Vybrid Family Universal Asynchronous Receiver/Transmitter  * Chapter 49, Vybrid Reference Manual, Rev. 5, 07/2013  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/fdt.h>
end_include

begin_include
include|#
directive|include
file|<dev/uart/uart.h>
end_include

begin_include
include|#
directive|include
file|<dev/uart/uart_cpu.h>
end_include

begin_include
include|#
directive|include
file|<dev/uart/uart_bus.h>
end_include

begin_include
include|#
directive|include
file|"uart_if.h"
end_include

begin_define
define|#
directive|define
name|UART_BDH
value|0x00
end_define

begin_comment
comment|/* Baud Rate Registers: High */
end_comment

begin_define
define|#
directive|define
name|UART_BDL
value|0x01
end_define

begin_comment
comment|/* Baud Rate Registers: Low */
end_comment

begin_define
define|#
directive|define
name|UART_C1
value|0x02
end_define

begin_comment
comment|/* Control Register 1 */
end_comment

begin_define
define|#
directive|define
name|UART_C2
value|0x03
end_define

begin_comment
comment|/* Control Register 2 */
end_comment

begin_define
define|#
directive|define
name|UART_S1
value|0x04
end_define

begin_comment
comment|/* Status Register 1 */
end_comment

begin_define
define|#
directive|define
name|UART_S2
value|0x05
end_define

begin_comment
comment|/* Status Register 2 */
end_comment

begin_define
define|#
directive|define
name|UART_C3
value|0x06
end_define

begin_comment
comment|/* Control Register 3 */
end_comment

begin_define
define|#
directive|define
name|UART_D
value|0x07
end_define

begin_comment
comment|/* Data Register */
end_comment

begin_define
define|#
directive|define
name|UART_MA1
value|0x08
end_define

begin_comment
comment|/* Match Address Registers 1 */
end_comment

begin_define
define|#
directive|define
name|UART_MA2
value|0x09
end_define

begin_comment
comment|/* Match Address Registers 2 */
end_comment

begin_define
define|#
directive|define
name|UART_C4
value|0x0A
end_define

begin_comment
comment|/* Control Register 4 */
end_comment

begin_define
define|#
directive|define
name|UART_C5
value|0x0B
end_define

begin_comment
comment|/* Control Register 5 */
end_comment

begin_define
define|#
directive|define
name|UART_ED
value|0x0C
end_define

begin_comment
comment|/* Extended Data Register */
end_comment

begin_define
define|#
directive|define
name|UART_MODEM
value|0x0D
end_define

begin_comment
comment|/* Modem Register */
end_comment

begin_define
define|#
directive|define
name|UART_IR
value|0x0E
end_define

begin_comment
comment|/* Infrared Register */
end_comment

begin_define
define|#
directive|define
name|UART_PFIFO
value|0x10
end_define

begin_comment
comment|/* FIFO Parameters */
end_comment

begin_define
define|#
directive|define
name|UART_CFIFO
value|0x11
end_define

begin_comment
comment|/* FIFO Control Register */
end_comment

begin_define
define|#
directive|define
name|UART_SFIFO
value|0x12
end_define

begin_comment
comment|/* FIFO Status Register */
end_comment

begin_define
define|#
directive|define
name|UART_TWFIFO
value|0x13
end_define

begin_comment
comment|/* FIFO Transmit Watermark */
end_comment

begin_define
define|#
directive|define
name|UART_TCFIFO
value|0x14
end_define

begin_comment
comment|/* FIFO Transmit Count */
end_comment

begin_define
define|#
directive|define
name|UART_RWFIFO
value|0x15
end_define

begin_comment
comment|/* FIFO Receive Watermark */
end_comment

begin_define
define|#
directive|define
name|UART_RCFIFO
value|0x16
end_define

begin_comment
comment|/* FIFO Receive Count */
end_comment

begin_define
define|#
directive|define
name|UART_C7816
value|0x18
end_define

begin_comment
comment|/* 7816 Control Register */
end_comment

begin_define
define|#
directive|define
name|UART_IE7816
value|0x19
end_define

begin_comment
comment|/* 7816 Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|UART_IS7816
value|0x1A
end_define

begin_comment
comment|/* 7816 Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|UART_WP7816T0
value|0x1B
end_define

begin_comment
comment|/* 7816 Wait Parameter Register */
end_comment

begin_define
define|#
directive|define
name|UART_WP7816T1
value|0x1B
end_define

begin_comment
comment|/* 7816 Wait Parameter Register */
end_comment

begin_define
define|#
directive|define
name|UART_WN7816
value|0x1C
end_define

begin_comment
comment|/* 7816 Wait N Register */
end_comment

begin_define
define|#
directive|define
name|UART_WF7816
value|0x1D
end_define

begin_comment
comment|/* 7816 Wait FD Register */
end_comment

begin_define
define|#
directive|define
name|UART_ET7816
value|0x1E
end_define

begin_comment
comment|/* 7816 Error Threshold Register */
end_comment

begin_define
define|#
directive|define
name|UART_TL7816
value|0x1F
end_define

begin_comment
comment|/* 7816 Transmit Length Register */
end_comment

begin_define
define|#
directive|define
name|UART_C6
value|0x21
end_define

begin_comment
comment|/* CEA709.1-B Control Register 6 */
end_comment

begin_define
define|#
directive|define
name|UART_PCTH
value|0x22
end_define

begin_comment
comment|/* CEA709.1-B Packet Cycle Time Counter High */
end_comment

begin_define
define|#
directive|define
name|UART_PCTL
value|0x23
end_define

begin_comment
comment|/* CEA709.1-B Packet Cycle Time Counter Low */
end_comment

begin_define
define|#
directive|define
name|UART_B1T
value|0x24
end_define

begin_comment
comment|/* CEA709.1-B Beta1 Timer */
end_comment

begin_define
define|#
directive|define
name|UART_SDTH
value|0x25
end_define

begin_comment
comment|/* CEA709.1-B Secondary Delay Timer High */
end_comment

begin_define
define|#
directive|define
name|UART_SDTL
value|0x26
end_define

begin_comment
comment|/* CEA709.1-B Secondary Delay Timer Low */
end_comment

begin_define
define|#
directive|define
name|UART_PRE
value|0x27
end_define

begin_comment
comment|/* CEA709.1-B Preamble */
end_comment

begin_define
define|#
directive|define
name|UART_TPL
value|0x28
end_define

begin_comment
comment|/* CEA709.1-B Transmit Packet Length */
end_comment

begin_define
define|#
directive|define
name|UART_IE
value|0x29
end_define

begin_comment
comment|/* CEA709.1-B Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|UART_WB
value|0x2A
end_define

begin_comment
comment|/* CEA709.1-B WBASE */
end_comment

begin_define
define|#
directive|define
name|UART_S3
value|0x2B
end_define

begin_comment
comment|/* CEA709.1-B Status Register */
end_comment

begin_define
define|#
directive|define
name|UART_S4
value|0x2C
end_define

begin_comment
comment|/* CEA709.1-B Status Register */
end_comment

begin_define
define|#
directive|define
name|UART_RPL
value|0x2D
end_define

begin_comment
comment|/* CEA709.1-B Received Packet Length */
end_comment

begin_define
define|#
directive|define
name|UART_RPREL
value|0x2E
end_define

begin_comment
comment|/* CEA709.1-B Received Preamble Length */
end_comment

begin_define
define|#
directive|define
name|UART_CPW
value|0x2F
end_define

begin_comment
comment|/* CEA709.1-B Collision Pulse Width */
end_comment

begin_define
define|#
directive|define
name|UART_RIDT
value|0x30
end_define

begin_comment
comment|/* CEA709.1-B Receive Indeterminate Time */
end_comment

begin_define
define|#
directive|define
name|UART_TIDT
value|0x31
end_define

begin_comment
comment|/* CEA709.1-B Transmit Indeterminate Time */
end_comment

begin_define
define|#
directive|define
name|UART_C2_TE
value|(1<< 3)
end_define

begin_comment
comment|/* Transmitter Enable */
end_comment

begin_define
define|#
directive|define
name|UART_C2_TIE
value|(1<< 7)
end_define

begin_comment
comment|/* Transmitter Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|UART_C2_RE
value|(1<< 2)
end_define

begin_comment
comment|/* Receiver Enable */
end_comment

begin_define
define|#
directive|define
name|UART_C2_RIE
value|(1<< 5)
end_define

begin_comment
comment|/* Receiver Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|UART_S1_TDRE
value|(1<< 7)
end_define

begin_comment
comment|/* Transmit Data Register Empty Flag */
end_comment

begin_define
define|#
directive|define
name|UART_S1_RDRF
value|(1<< 5)
end_define

begin_comment
comment|/* Receive Data Register Full Flag */
end_comment

begin_define
define|#
directive|define
name|UART_S2_LBKDIF
value|(1<< 7)
end_define

begin_comment
comment|/* LIN Break Detect Interrupt Flag */
end_comment

begin_define
define|#
directive|define
name|UART_C4_BRFA
value|0x1f
end_define

begin_comment
comment|/* Baud Rate Fine Adjust */
end_comment

begin_define
define|#
directive|define
name|UART_BDH_SBR
value|0x1f
end_define

begin_comment
comment|/* UART Baud Rate Bits */
end_comment

begin_comment
comment|/*  * Low-level UART interface.  */
end_comment

begin_function_decl
specifier|static
name|int
name|vf_uart_probe
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|vf_uart_init
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|vf_uart_term
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|vf_uart_putc
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vf_uart_rxready
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vf_uart_getc
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|,
name|struct
name|mtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uart_reinit
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|struct
name|uart_ops
name|uart_vybrid_ops
init|=
block|{
operator|.
name|probe
operator|=
name|vf_uart_probe
block|,
operator|.
name|init
operator|=
name|vf_uart_init
block|,
operator|.
name|term
operator|=
name|vf_uart_term
block|,
operator|.
name|putc
operator|=
name|vf_uart_putc
block|,
operator|.
name|rxready
operator|=
name|vf_uart_rxready
block|,
operator|.
name|getc
operator|=
name|vf_uart_getc
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|vf_uart_probe
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|vf_uart_init
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|,
name|int
name|baudrate
parameter_list|,
name|int
name|databits
parameter_list|,
name|int
name|stopbits
parameter_list|,
name|int
name|parity
parameter_list|)
block|{  }
end_function

begin_function
specifier|static
name|void
name|vf_uart_term
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|)
block|{  }
end_function

begin_function
specifier|static
name|void
name|vf_uart_putc
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|,
name|int
name|c
parameter_list|)
block|{
while|while
condition|(
operator|!
operator|(
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_S1
argument_list|)
operator|&
name|UART_S1_TDRE
operator|)
condition|)
empty_stmt|;
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_D
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|vf_uart_rxready
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|)
block|{
name|int
name|usr1
decl_stmt|;
name|usr1
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_S1
argument_list|)
expr_stmt|;
if|if
condition|(
name|usr1
operator|&
name|UART_S1_RDRF
condition|)
block|{
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|vf_uart_getc
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|,
name|struct
name|mtx
modifier|*
name|hwmtx
parameter_list|)
block|{
name|int
name|c
decl_stmt|;
name|uart_lock
argument_list|(
name|hwmtx
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
operator|(
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_S1
argument_list|)
operator|&
name|UART_S1_RDRF
operator|)
condition|)
empty_stmt|;
name|c
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_D
argument_list|)
expr_stmt|;
name|uart_unlock
argument_list|(
name|hwmtx
argument_list|)
expr_stmt|;
return|return
operator|(
name|c
operator|&
literal|0xff
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * High-level UART interface.  */
end_comment

begin_struct
struct|struct
name|vf_uart_softc
block|{
name|struct
name|uart_softc
name|base
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|uart_reinit
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|,
name|int
name|clkspeed
parameter_list|,
name|int
name|baud
parameter_list|)
block|{
name|struct
name|uart_bas
modifier|*
name|bas
decl_stmt|;
name|int
name|sbr
decl_stmt|;
name|int
name|brfa
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|bas
operator|=
operator|&
name|sc
operator|->
name|sc_bas
expr_stmt|;
if|if
condition|(
operator|!
name|bas
condition|)
block|{
name|printf
argument_list|(
literal|"Error: cant reconfigure bas\n"
argument_list|)
expr_stmt|;
return|return;
block|}
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_MODEM
argument_list|,
literal|0x00
argument_list|)
expr_stmt|;
comment|/* 	 * Disable transmitter and receiver 	 * for a while. 	 */
name|reg
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|UART_C2_RE
operator||
name|UART_C2_TE
operator|)
expr_stmt|;
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|,
literal|0x00
argument_list|)
expr_stmt|;
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_C1
argument_list|,
literal|0x00
argument_list|)
expr_stmt|;
name|sbr
operator|=
call|(
name|uint16_t
call|)
argument_list|(
name|clkspeed
operator|/
operator|(
name|baud
operator|*
literal|16
operator|)
argument_list|)
expr_stmt|;
name|brfa
operator|=
operator|(
name|clkspeed
operator|/
name|baud
operator|)
operator|-
operator|(
name|sbr
operator|*
literal|16
operator|)
expr_stmt|;
name|reg
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_BDH
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
name|UART_BDH_SBR
expr_stmt|;
name|reg
operator||=
operator|(
operator|(
name|sbr
operator|&
literal|0x1f00
operator|)
operator|>>
literal|8
operator|)
expr_stmt|;
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_BDH
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|reg
operator|=
name|sbr
operator|&
literal|0x00ff
expr_stmt|;
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_BDL
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|reg
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_C4
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
name|UART_C4_BRFA
expr_stmt|;
name|reg
operator||=
operator|(
name|brfa
operator|&
name|UART_C4_BRFA
operator|)
expr_stmt|;
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_C4
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|reg
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|UART_C2_RE
operator||
name|UART_C2_TE
operator|)
expr_stmt|;
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|,
name|reg
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|static
name|int
name|vf_uart_bus_attach
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vf_uart_bus_detach
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vf_uart_bus_flush
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vf_uart_bus_getsig
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vf_uart_bus_ioctl
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|intptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vf_uart_bus_ipend
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vf_uart_bus_param
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vf_uart_bus_probe
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vf_uart_bus_receive
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vf_uart_bus_setsig
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vf_uart_bus_transmit
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|kobj_method_t
name|vf_uart_methods
index|[]
init|=
block|{
name|KOBJMETHOD
argument_list|(
name|uart_attach
argument_list|,
name|vf_uart_bus_attach
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_detach
argument_list|,
name|vf_uart_bus_detach
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_flush
argument_list|,
name|vf_uart_bus_flush
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_getsig
argument_list|,
name|vf_uart_bus_getsig
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_ioctl
argument_list|,
name|vf_uart_bus_ioctl
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_ipend
argument_list|,
name|vf_uart_bus_ipend
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_param
argument_list|,
name|vf_uart_bus_param
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_probe
argument_list|,
name|vf_uart_bus_probe
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_receive
argument_list|,
name|vf_uart_bus_receive
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_setsig
argument_list|,
name|vf_uart_bus_setsig
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_transmit
argument_list|,
name|vf_uart_bus_transmit
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uart_class
name|uart_vybrid_class
init|=
block|{
literal|"vybrid"
block|,
name|vf_uart_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|vf_uart_softc
argument_list|)
block|,
operator|.
name|uc_ops
operator|=
operator|&
name|uart_vybrid_ops
block|,
operator|.
name|uc_range
operator|=
literal|0x100
block|,
operator|.
name|uc_rclk
operator|=
literal|24000000
comment|/* TODO: get value from CCM */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|vf_uart_bus_attach
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
name|struct
name|uart_bas
modifier|*
name|bas
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|bas
operator|=
operator|&
name|sc
operator|->
name|sc_bas
expr_stmt|;
name|sc
operator|->
name|sc_hwiflow
operator|=
literal|0
expr_stmt|;
name|sc
operator|->
name|sc_hwoflow
operator|=
literal|0
expr_stmt|;
name|uart_reinit
argument_list|(
name|sc
argument_list|,
literal|66000000
argument_list|,
literal|115200
argument_list|)
expr_stmt|;
name|reg
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_sysdev
operator|!=
name|NULL
operator|&&
name|sc
operator|->
name|sc_sysdev
operator|->
name|type
operator|==
name|UART_DEV_CONSOLE
condition|)
block|{
name|reg
operator|&=
operator|~
name|UART_C2_RIE
expr_stmt|;
block|}
else|else
block|{
name|reg
operator||=
name|UART_C2_RIE
expr_stmt|;
block|}
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|,
name|reg
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|vf_uart_bus_detach
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
comment|/* TODO */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|vf_uart_bus_flush
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|,
name|int
name|what
parameter_list|)
block|{
comment|/* TODO */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|vf_uart_bus_getsig
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
comment|/* TODO */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|vf_uart_bus_ioctl
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|,
name|int
name|request
parameter_list|,
name|intptr_t
name|data
parameter_list|)
block|{
name|struct
name|uart_bas
modifier|*
name|bas
decl_stmt|;
name|int
name|error
decl_stmt|;
name|bas
operator|=
operator|&
name|sc
operator|->
name|sc_bas
expr_stmt|;
name|error
operator|=
literal|0
expr_stmt|;
name|uart_lock
argument_list|(
name|sc
operator|->
name|sc_hwmtx
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|request
condition|)
block|{
case|case
name|UART_IOCTL_BREAK
case|:
comment|/* TODO */
break|break;
case|case
name|UART_IOCTL_BAUD
case|:
comment|/* TODO */
operator|*
operator|(
name|int
operator|*
operator|)
name|data
operator|=
literal|115200
expr_stmt|;
break|break;
default|default:
name|error
operator|=
name|EINVAL
expr_stmt|;
break|break;
block|}
name|uart_unlock
argument_list|(
name|sc
operator|->
name|sc_hwmtx
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|vf_uart_bus_ipend
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
name|struct
name|uart_bas
modifier|*
name|bas
decl_stmt|;
name|int
name|ipend
decl_stmt|;
name|uint32_t
name|usr1
decl_stmt|,
name|usr2
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|int
name|sfifo
decl_stmt|;
name|bas
operator|=
operator|&
name|sc
operator|->
name|sc_bas
expr_stmt|;
name|ipend
operator|=
literal|0
expr_stmt|;
name|uart_lock
argument_list|(
name|sc
operator|->
name|sc_hwmtx
argument_list|)
expr_stmt|;
name|usr1
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_S1
argument_list|)
expr_stmt|;
name|usr2
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_S2
argument_list|)
expr_stmt|;
name|sfifo
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_SFIFO
argument_list|)
expr_stmt|;
comment|/* ack usr2 */
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_S2
argument_list|,
name|usr2
argument_list|)
expr_stmt|;
if|if
condition|(
name|usr1
operator|&
name|UART_S1_TDRE
condition|)
block|{
name|reg
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|UART_C2_TIE
operator|)
expr_stmt|;
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|,
name|reg
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_txbusy
operator|!=
literal|0
condition|)
block|{
name|ipend
operator||=
name|SER_INT_TXIDLE
expr_stmt|;
block|}
block|}
if|if
condition|(
name|usr1
operator|&
name|UART_S1_RDRF
condition|)
block|{
name|reg
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|UART_C2_RIE
operator|)
expr_stmt|;
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|ipend
operator||=
name|SER_INT_RXREADY
expr_stmt|;
block|}
if|if
condition|(
name|usr2
operator|&
name|UART_S2_LBKDIF
condition|)
block|{
name|ipend
operator||=
name|SER_INT_BREAK
expr_stmt|;
block|}
name|uart_unlock
argument_list|(
name|sc
operator|->
name|sc_hwmtx
argument_list|)
expr_stmt|;
return|return
operator|(
name|ipend
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|vf_uart_bus_param
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|,
name|int
name|baudrate
parameter_list|,
name|int
name|databits
parameter_list|,
name|int
name|stopbits
parameter_list|,
name|int
name|parity
parameter_list|)
block|{
name|uart_lock
argument_list|(
name|sc
operator|->
name|sc_hwmtx
argument_list|)
expr_stmt|;
name|vf_uart_init
argument_list|(
operator|&
name|sc
operator|->
name|sc_bas
argument_list|,
name|baudrate
argument_list|,
name|databits
argument_list|,
name|stopbits
argument_list|,
name|parity
argument_list|)
expr_stmt|;
name|uart_unlock
argument_list|(
name|sc
operator|->
name|sc_hwmtx
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|vf_uart_bus_probe
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|error
operator|=
name|vf_uart_probe
argument_list|(
operator|&
name|sc
operator|->
name|sc_bas
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|sc
operator|->
name|sc_rxfifosz
operator|=
literal|1
expr_stmt|;
name|sc
operator|->
name|sc_txfifosz
operator|=
literal|1
expr_stmt|;
name|device_set_desc
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"Vybrid Family UART"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|vf_uart_bus_receive
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
name|struct
name|uart_bas
modifier|*
name|bas
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|int
name|c
decl_stmt|;
name|bas
operator|=
operator|&
name|sc
operator|->
name|sc_bas
expr_stmt|;
name|uart_lock
argument_list|(
name|sc
operator|->
name|sc_hwmtx
argument_list|)
expr_stmt|;
comment|/* Read FIFO */
while|while
condition|(
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_S1
argument_list|)
operator|&
name|UART_S1_RDRF
condition|)
block|{
if|if
condition|(
name|uart_rx_full
argument_list|(
name|sc
argument_list|)
condition|)
block|{
comment|/* No space left in input buffer */
name|sc
operator|->
name|sc_rxbuf
index|[
name|sc
operator|->
name|sc_rxput
index|]
operator|=
name|UART_STAT_OVERRUN
expr_stmt|;
break|break;
block|}
name|c
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_D
argument_list|)
expr_stmt|;
name|uart_rx_put
argument_list|(
name|sc
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
comment|/* Reenable Data Ready interrupt */
name|reg
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|UART_C2_RIE
operator|)
expr_stmt|;
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|uart_unlock
argument_list|(
name|sc
operator|->
name|sc_hwmtx
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|vf_uart_bus_setsig
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|,
name|int
name|sig
parameter_list|)
block|{
name|struct
name|uart_bas
modifier|*
name|bas
decl_stmt|;
name|int
name|reg
decl_stmt|;
comment|/* TODO: implement (?) */
comment|/* XXX workaround to have working console on mount prompt */
comment|/* Enable RX interrupt */
name|bas
operator|=
operator|&
name|sc
operator|->
name|sc_bas
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_sysdev
operator|!=
name|NULL
operator|&&
name|sc
operator|->
name|sc_sysdev
operator|->
name|type
operator|==
name|UART_DEV_CONSOLE
condition|)
block|{
name|reg
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|UART_C2_RIE
operator|)
expr_stmt|;
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|,
name|reg
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|vf_uart_bus_transmit
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
name|struct
name|uart_bas
modifier|*
name|bas
init|=
operator|&
name|sc
operator|->
name|sc_bas
decl_stmt|;
name|int
name|i
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|bas
operator|=
operator|&
name|sc
operator|->
name|sc_bas
expr_stmt|;
name|uart_lock
argument_list|(
name|sc
operator|->
name|sc_hwmtx
argument_list|)
expr_stmt|;
comment|/* Fill TX FIFO */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|sc
operator|->
name|sc_txdatasz
condition|;
name|i
operator|++
control|)
block|{
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_D
argument_list|,
name|sc
operator|->
name|sc_txbuf
index|[
name|i
index|]
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|uart_barrier
argument_list|(
operator|&
name|sc
operator|->
name|sc_bas
argument_list|)
expr_stmt|;
block|}
name|sc
operator|->
name|sc_txbusy
operator|=
literal|1
expr_stmt|;
comment|/* Call me when ready */
name|reg
operator|=
name|uart_getreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|UART_C2_TIE
operator|)
expr_stmt|;
name|uart_setreg
argument_list|(
name|bas
argument_list|,
name|UART_C2
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|uart_unlock
argument_list|(
name|sc
operator|->
name|sc_hwmtx
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

