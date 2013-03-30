begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Adrian Chadd<adrian@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<machine/bus.h>
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
file|<mips/atheros/ar933x_uart.h>
end_include

begin_include
include|#
directive|include
file|"uart_if.h"
end_include

begin_comment
comment|/*  * Default system clock is 25MHz; see ar933x_chip.c for how  * the startup process determines whether it's 25MHz or 40MHz.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_RCLK
value|(25 * 1000 * 1000)
end_define

begin_define
define|#
directive|define
name|ar933x_getreg
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
name|ar933x_setreg
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * Clear pending interrupts. THRE is cleared by reading IIR. Data  * that may have been received gets lost here.  */
end_comment

begin_endif
unit|static void ar933x_clrint(struct uart_bas *bas) { 	uint8_t iir, lsr;  	iir = uart_getreg(bas, REG_IIR); 	while ((iir& IIR_NOPEND) == 0) { 		iir&= IIR_IMASK; 		if (iir == IIR_RLS) { 			lsr = uart_getreg(bas, REG_LSR); 			if (lsr& (LSR_BI|LSR_FE|LSR_PE)) 				(void)uart_getreg(bas, REG_DATA); 		} else if (iir == IIR_RXRDY || iir == IIR_RXTOUT) 			(void)uart_getreg(bas, REG_DATA); 		else if (iir == IIR_MLSC) 			(void)uart_getreg(bas, REG_MSR); 		uart_barrier(bas); 		iir = uart_getreg(bas, REG_IIR); 	} }
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|static int ar933x_drain(struct uart_bas *bas, int what) { 	int delay, limit;  	delay = ar933x_delay(bas);  	if (what& UART_DRAIN_TRANSMITTER) {
comment|/* 		 * Pick an arbitrary high limit to avoid getting stuck in 		 * an infinite loop when the hardware is broken. Make the 		 * limit high enough to handle large FIFOs. 		 */
end_comment

begin_comment
unit|limit = 10*1024; 		while ((uart_getreg(bas, REG_LSR)& LSR_TEMT) == 0&& --limit) 			DELAY(delay); 		if (limit == 0) {
comment|/* printf("ns8250: transmitter appears stuck... "); */
end_comment

begin_comment
unit|return (EIO); 		} 	}  	if (what& UART_DRAIN_RECEIVER) {
comment|/* 		 * Pick an arbitrary high limit to avoid getting stuck in 		 * an infinite loop when the hardware is broken. Make the 		 * limit high enough to handle large FIFOs and integrated 		 * UARTs. The HP rx2600 for example has 3 UARTs on the 		 * management board that tend to get a lot of data send 		 * to it when the UART is first activated. 		 */
end_comment

begin_comment
unit|limit=10*4096; 		while ((uart_getreg(bas, REG_LSR)& LSR_RXRDY)&& --limit) { 			(void)uart_getreg(bas, REG_DATA); 			uart_barrier(bas); 			DELAY(delay<< 2); 		} 		if (limit == 0) {
comment|/* printf("ns8250: receiver appears broken... "); */
end_comment

begin_endif
unit|return (EIO); 		} 	} 	return (0); }
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * We can only flush UARTs with FIFOs. UARTs without FIFOs should be  * drained. WARNING: this function clobbers the FIFO setting!  */
end_comment

begin_endif
unit|static void ar933x_flush(struct uart_bas *bas, int what) { 	uint8_t fcr;  	fcr = FCR_ENABLE; 	if (what& UART_FLUSH_TRANSMITTER) 		fcr |= FCR_XMT_RST; 	if (what& UART_FLUSH_RECEIVER) 		fcr |= FCR_RCV_RST; 	uart_setreg(bas, REG_FCR, fcr); 	uart_barrier(bas); }
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|static int ar933x_param(struct uart_bas *bas, int baudrate, int databits, int stopbits,     int parity) { 	int divisor; 	uint8_t lcr;  	lcr = 0; 	if (databits>= 8) 		lcr |= LCR_8BITS; 	else if (databits == 7) 		lcr |= LCR_7BITS; 	else if (databits == 6) 		lcr |= LCR_6BITS; 	else 		lcr |= LCR_5BITS; 	if (stopbits> 1) 		lcr |= LCR_STOPB; 	lcr |= parity<< 3;
comment|/* Set baudrate. */
end_comment

begin_comment
unit|if (baudrate> 0) { 		divisor = ar933x_divisor(bas->rclk, baudrate); 		if (divisor == 0) 			return (EINVAL); 		uart_setreg(bas, REG_LCR, lcr | LCR_DLAB); 		uart_barrier(bas); 		uart_setreg(bas, REG_DLL, divisor& 0xff); 		uart_setreg(bas, REG_DLH, (divisor>> 8)& 0xff); 		uart_barrier(bas); 	}
comment|/* Set LCR and clear DLAB. */
end_comment

begin_endif
unit|uart_setreg(bas, REG_LCR, lcr); 	uart_barrier(bas); 	return (0); }
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Low-level UART interface.  */
end_comment

begin_function_decl
specifier|static
name|int
name|ar933x_probe
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
name|ar933x_init
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
name|ar933x_term
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
name|ar933x_putc
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
name|ar933x_rxready
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
name|ar933x_getc
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

begin_decl_stmt
specifier|static
name|struct
name|uart_ops
name|uart_ar933x_ops
init|=
block|{
operator|.
name|probe
operator|=
name|ar933x_probe
block|,
operator|.
name|init
operator|=
name|ar933x_init
block|,
operator|.
name|term
operator|=
name|ar933x_term
block|,
operator|.
name|putc
operator|=
name|ar933x_putc
block|,
operator|.
name|rxready
operator|=
name|ar933x_rxready
block|,
operator|.
name|getc
operator|=
name|ar933x_getc
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|ar933x_probe
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|)
block|{
if|#
directive|if
literal|0
block|u_char val;
comment|/* Check known 0 bits that don't depend on DLAB. */
block|val = uart_getreg(bas, REG_IIR); 	if (val& 0x30) 		return (ENXIO);
comment|/* 	 * Bit 6 of the MCR (= 0x40) appears to be 1 for the Sun1699 	 * chip, but otherwise doesn't seem to have a function. In 	 * other words, uart(4) works regardless. Ignore that bit so 	 * the probe succeeds. 	 */
block|val = uart_getreg(bas, REG_MCR); 	if (val& 0xa0) 		return (ENXIO);
endif|#
directive|endif
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
name|ar933x_init
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
block|{
if|#
directive|if
literal|0
block|u_char	ier;  	if (bas->rclk == 0) 		bas->rclk = DEFAULT_RCLK; 	ar933x_param(bas, baudrate, databits, stopbits, parity);
comment|/* Disable all interrupt sources. */
comment|/* 	 * We use 0xe0 instead of 0xf0 as the mask because the XScale PXA 	 * UARTs split the receive time-out interrupt bit out separately as 	 * 0x10.  This gets handled by ier_mask and ier_rxbits below. 	 */
block|ier = uart_getreg(bas, REG_IER)& 0xe0; 	uart_setreg(bas, REG_IER, ier); 	uart_barrier(bas);
comment|/* Disable the FIFO (if present). */
block|uart_setreg(bas, REG_FCR, 0); 	uart_barrier(bas);
comment|/* Set RTS& DTR. */
block|uart_setreg(bas, REG_MCR, MCR_IE | MCR_RTS | MCR_DTR); 	uart_barrier(bas);  	ar933x_clrint(bas);
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|void
name|ar933x_term
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|)
block|{
if|#
directive|if
literal|0
comment|/* Clear RTS& DTR. */
block|uart_setreg(bas, REG_MCR, MCR_IE); 	uart_barrier(bas);
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|void
name|ar933x_putc
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
name|int
name|limit
decl_stmt|;
name|limit
operator|=
literal|250000
expr_stmt|;
comment|/* Wait for space in the TX FIFO */
while|while
condition|(
operator|(
operator|(
name|ar933x_getreg
argument_list|(
name|bas
argument_list|,
name|AR933X_UART_DATA_REG
argument_list|)
operator|&
name|AR933X_UART_DATA_TX_CSR
operator|)
operator|==
literal|0
operator|)
operator|&&
operator|--
name|limit
condition|)
name|DELAY
argument_list|(
literal|4
argument_list|)
expr_stmt|;
comment|/* Write the actual byte */
name|ar933x_setreg
argument_list|(
name|bas
argument_list|,
name|AR933X_UART_DATA_REG
argument_list|,
operator|(
name|c
operator|&
literal|0xff
operator|)
operator||
name|AR933X_UART_DATA_TX_CSR
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|ar933x_rxready
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|bas
parameter_list|)
block|{
comment|/* Wait for a character to come ready */
return|return
operator|(
operator|!
operator|!
operator|(
name|ar933x_getreg
argument_list|(
name|bas
argument_list|,
name|AR933X_UART_DATA_REG
argument_list|)
operator|&
name|AR933X_UART_DATA_RX_CSR
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ar933x_getc
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
comment|/* Wait for a character to come ready */
while|while
condition|(
operator|(
name|ar933x_getreg
argument_list|(
name|bas
argument_list|,
name|AR933X_UART_DATA_REG
argument_list|)
operator|&
name|AR933X_UART_DATA_RX_CSR
operator|)
operator|==
literal|0
condition|)
block|{
name|uart_unlock
argument_list|(
name|hwmtx
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|uart_lock
argument_list|(
name|hwmtx
argument_list|)
expr_stmt|;
block|}
comment|/* Read the top of the RX FIFO */
name|c
operator|=
name|ar933x_getreg
argument_list|(
name|bas
argument_list|,
name|AR933X_UART_DATA_REG
argument_list|)
operator|&
literal|0xff
expr_stmt|;
comment|/* Remove that entry from said RX FIFO */
name|ar933x_setreg
argument_list|(
name|bas
argument_list|,
name|AR933X_UART_DATA_REG
argument_list|,
name|AR933X_UART_DATA_RX_CSR
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
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * High-level UART interface.  */
end_comment

begin_struct
struct|struct
name|ar933x_softc
block|{
name|struct
name|uart_softc
name|base
decl_stmt|;
name|uint32_t
name|u_ier
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|static
name|int
name|ar933x_bus_attach
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
name|ar933x_bus_detach
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
name|ar933x_bus_flush
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
name|ar933x_bus_getsig
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
name|ar933x_bus_ioctl
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
name|ar933x_bus_ipend
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
name|ar933x_bus_param
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
name|ar933x_bus_probe
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
name|ar933x_bus_receive
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
name|ar933x_bus_setsig
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
name|ar933x_bus_transmit
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
name|ar933x_methods
index|[]
init|=
block|{
name|KOBJMETHOD
argument_list|(
name|uart_attach
argument_list|,
name|ar933x_bus_attach
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_detach
argument_list|,
name|ar933x_bus_detach
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_flush
argument_list|,
name|ar933x_bus_flush
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_getsig
argument_list|,
name|ar933x_bus_getsig
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_ioctl
argument_list|,
name|ar933x_bus_ioctl
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_ipend
argument_list|,
name|ar933x_bus_ipend
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_param
argument_list|,
name|ar933x_bus_param
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_probe
argument_list|,
name|ar933x_bus_probe
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_receive
argument_list|,
name|ar933x_bus_receive
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_setsig
argument_list|,
name|ar933x_bus_setsig
argument_list|)
block|,
name|KOBJMETHOD
argument_list|(
name|uart_transmit
argument_list|,
name|ar933x_bus_transmit
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
name|uart_ar933x_class
init|=
block|{
literal|"ar933x"
block|,
name|ar933x_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|ar933x_softc
argument_list|)
block|,
operator|.
name|uc_ops
operator|=
operator|&
name|uart_ar933x_ops
block|,
operator|.
name|uc_range
operator|=
literal|8
block|,
operator|.
name|uc_rclk
operator|=
name|DEFAULT_RCLK
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SIGCHG
parameter_list|(
name|c
parameter_list|,
name|i
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
define|\
value|if (c) {					\ 		i |= (i& s) ? s : s | d;		\ 	} else {					\ 		i = (i& s) ? (i& ~s) | d : i;		\ 	}
end_define

begin_function
specifier|static
name|int
name|ar933x_bus_attach
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
if|#
directive|if
literal|0
block|struct ar933x_softc *ns8250 = (struct ar933x_softc*)sc; 	struct uart_bas *bas; 	unsigned int ivar;  	bas =&sc->sc_bas;  	ns8250->mcr = uart_getreg(bas, REG_MCR); 	ns8250->fcr = FCR_ENABLE; 	if (!resource_int_value("uart", device_get_unit(sc->sc_dev), "flags",&ivar)) { 		if (UART_FLAGS_FCR_RX_LOW(ivar))  			ns8250->fcr |= FCR_RX_LOW; 		else if (UART_FLAGS_FCR_RX_MEDL(ivar))  			ns8250->fcr |= FCR_RX_MEDL; 		else if (UART_FLAGS_FCR_RX_HIGH(ivar))  			ns8250->fcr |= FCR_RX_HIGH; 		else 			ns8250->fcr |= FCR_RX_MEDH; 	} else  		ns8250->fcr |= FCR_RX_MEDH;
comment|/* Get IER mask */
block|ivar = 0xf0; 	resource_int_value("uart", device_get_unit(sc->sc_dev), "ier_mask",&ivar); 	ns8250->ier_mask = (uint8_t)(ivar& 0xff);
comment|/* Get IER RX interrupt bits */
block|ivar = IER_EMSC | IER_ERLS | IER_ERXRDY; 	resource_int_value("uart", device_get_unit(sc->sc_dev), "ier_rxbits",&ivar); 	ns8250->ier_rxbits = (uint8_t)(ivar& 0xff); 	 	uart_setreg(bas, REG_FCR, ns8250->fcr); 	uart_barrier(bas); 	ar933x_bus_flush(sc, UART_FLUSH_RECEIVER|UART_FLUSH_TRANSMITTER);  	if (ns8250->mcr& MCR_DTR) 		sc->sc_hwsig |= SER_DTR; 	if (ns8250->mcr& MCR_RTS) 		sc->sc_hwsig |= SER_RTS; 	ar933x_bus_getsig(sc);  	ar933x_clrint(bas); 	ns8250->ier = uart_getreg(bas, REG_IER)& ns8250->ier_mask; 	ns8250->ier |= ns8250->ier_rxbits; 	uart_setreg(bas, REG_IER, ns8250->ier); 	uart_barrier(bas);
endif|#
directive|endif
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
name|ar933x_bus_detach
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
if|#
directive|if
literal|0
block|struct ar933x_softc *ns8250; 	struct uart_bas *bas; 	u_char ier;  	ns8250 = (struct ar933x_softc *)sc; 	bas =&sc->sc_bas; 	ier = uart_getreg(bas, REG_IER)& ns8250->ier_mask; 	uart_setreg(bas, REG_IER, ier); 	uart_barrier(bas); 	ar933x_clrint(bas);
endif|#
directive|endif
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
name|ar933x_bus_flush
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
if|#
directive|if
literal|0
block|struct ar933x_softc *ns8250 = (struct ar933x_softc*)sc; 	struct uart_bas *bas; 	int error;  	bas =&sc->sc_bas; 	uart_lock(sc->sc_hwmtx); 	if (sc->sc_rxfifosz> 1) { 		ar933x_flush(bas, what); 		uart_setreg(bas, REG_FCR, ns8250->fcr); 		uart_barrier(bas); 		error = 0; 	} else 		error = ar933x_drain(bas, what); 	uart_unlock(sc->sc_hwmtx); 	return (error);
endif|#
directive|endif
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ar933x_bus_getsig
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
if|#
directive|if
literal|0
block|uint32_t new, old, sig; 	uint8_t msr;  	do { 		old = sc->sc_hwsig; 		sig = old; 		uart_lock(sc->sc_hwmtx); 		msr = uart_getreg(&sc->sc_bas, REG_MSR); 		uart_unlock(sc->sc_hwmtx); 		SIGCHG(msr& MSR_DSR, sig, SER_DSR, SER_DDSR); 		SIGCHG(msr& MSR_CTS, sig, SER_CTS, SER_DCTS); 		SIGCHG(msr& MSR_DCD, sig, SER_DCD, SER_DDCD); 		SIGCHG(msr& MSR_RI,  sig, SER_RI,  SER_DRI); 		new = sig& ~SER_MASK_DELTA; 	} while (!atomic_cmpset_32(&sc->sc_hwsig, old, new)); 	return (sig);
endif|#
directive|endif
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
name|ar933x_bus_ioctl
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
if|#
directive|if
literal|0
block|struct uart_bas *bas; 	int baudrate, divisor, error; 	uint8_t efr, lcr;  	bas =&sc->sc_bas; 	error = 0; 	uart_lock(sc->sc_hwmtx); 	switch (request) { 	case UART_IOCTL_BREAK: 		lcr = uart_getreg(bas, REG_LCR); 		if (data) 			lcr |= LCR_SBREAK; 		else 			lcr&= ~LCR_SBREAK; 		uart_setreg(bas, REG_LCR, lcr); 		uart_barrier(bas); 		break; 	case UART_IOCTL_IFLOW: 		lcr = uart_getreg(bas, REG_LCR); 		uart_barrier(bas); 		uart_setreg(bas, REG_LCR, 0xbf); 		uart_barrier(bas); 		efr = uart_getreg(bas, REG_EFR); 		if (data) 			efr |= EFR_RTS; 		else 			efr&= ~EFR_RTS; 		uart_setreg(bas, REG_EFR, efr); 		uart_barrier(bas); 		uart_setreg(bas, REG_LCR, lcr); 		uart_barrier(bas); 		break; 	case UART_IOCTL_OFLOW: 		lcr = uart_getreg(bas, REG_LCR); 		uart_barrier(bas); 		uart_setreg(bas, REG_LCR, 0xbf); 		uart_barrier(bas); 		efr = uart_getreg(bas, REG_EFR); 		if (data) 			efr |= EFR_CTS; 		else 			efr&= ~EFR_CTS; 		uart_setreg(bas, REG_EFR, efr); 		uart_barrier(bas); 		uart_setreg(bas, REG_LCR, lcr); 		uart_barrier(bas); 		break; 	case UART_IOCTL_BAUD: 		lcr = uart_getreg(bas, REG_LCR); 		uart_setreg(bas, REG_LCR, lcr | LCR_DLAB); 		uart_barrier(bas); 		divisor = uart_getreg(bas, REG_DLL) | 		    (uart_getreg(bas, REG_DLH)<< 8); 		uart_barrier(bas); 		uart_setreg(bas, REG_LCR, lcr); 		uart_barrier(bas); 		baudrate = (divisor> 0) ? bas->rclk / divisor / 16 : 0; 		if (baudrate> 0) 			*(int*)data = baudrate; 		else 			error = ENXIO; 		break; 	default: 		error = EINVAL; 		break; 	} 	uart_unlock(sc->sc_hwmtx); 	return (error);
endif|#
directive|endif
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ar933x_bus_ipend
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
if|#
directive|if
literal|0
block|struct uart_bas *bas; 	struct ar933x_softc *ns8250; 	int ipend; 	uint8_t iir, lsr;  	ns8250 = (struct ar933x_softc *)sc; 	bas =&sc->sc_bas; 	uart_lock(sc->sc_hwmtx); 	iir = uart_getreg(bas, REG_IIR); 	if (iir& IIR_NOPEND) { 		uart_unlock(sc->sc_hwmtx); 		return (0); 	} 	ipend = 0; 	if (iir& IIR_RXRDY) { 		lsr = uart_getreg(bas, REG_LSR); 		if (lsr& LSR_OE) 			ipend |= SER_INT_OVERRUN; 		if (lsr& LSR_BI) 			ipend |= SER_INT_BREAK; 		if (lsr& LSR_RXRDY) 			ipend |= SER_INT_RXREADY; 	} else { 		if (iir& IIR_TXRDY) { 			ipend |= SER_INT_TXIDLE; 			uart_setreg(bas, REG_IER, ns8250->ier); 		} else 			ipend |= SER_INT_SIGCHG; 	} 	if (ipend == 0) 		ar933x_clrint(bas); 	uart_unlock(sc->sc_hwmtx); 	return (ipend);
endif|#
directive|endif
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
name|ar933x_bus_param
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
if|#
directive|if
literal|0
block|struct uart_bas *bas; 	int error;  	bas =&sc->sc_bas; 	uart_lock(sc->sc_hwmtx); 	error = ar933x_param(bas, baudrate, databits, stopbits, parity); 	uart_unlock(sc->sc_hwmtx); 	return (error);
endif|#
directive|endif
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ar933x_bus_probe
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
if|#
directive|if
literal|0
block|struct ar933x_softc *ns8250; 	struct uart_bas *bas; 	int count, delay, error, limit; 	uint8_t lsr, mcr, ier;  	ns8250 = (struct ar933x_softc *)sc; 	bas =&sc->sc_bas;  	error = ar933x_probe(bas); 	if (error) 		return (error);  	mcr = MCR_IE; 	if (sc->sc_sysdev == NULL) {
comment|/* By using ar933x_init() we also set DTR and RTS. */
block|ar933x_init(bas, 115200, 8, 1, UART_PARITY_NONE); 	} else 		mcr |= MCR_DTR | MCR_RTS;  	error = ar933x_drain(bas, UART_DRAIN_TRANSMITTER); 	if (error) 		return (error);
comment|/* 	 * Set loopback mode. This avoids having garbage on the wire and 	 * also allows us send and receive data. We set DTR and RTS to 	 * avoid the possibility that automatic flow-control prevents 	 * any data from being sent. 	 */
block|uart_setreg(bas, REG_MCR, MCR_LOOPBACK | MCR_IE | MCR_DTR | MCR_RTS); 	uart_barrier(bas);
comment|/* 	 * Enable FIFOs. And check that the UART has them. If not, we're 	 * done. Since this is the first time we enable the FIFOs, we reset 	 * them. 	 */
block|uart_setreg(bas, REG_FCR, FCR_ENABLE); 	uart_barrier(bas); 	if (!(uart_getreg(bas, REG_IIR)& IIR_FIFO_MASK)) {
comment|/* 		 * NS16450 or INS8250. We don't bother to differentiate 		 * between them. They're too old to be interesting. 		 */
block|uart_setreg(bas, REG_MCR, mcr); 		uart_barrier(bas); 		sc->sc_rxfifosz = sc->sc_txfifosz = 1; 		device_set_desc(sc->sc_dev, "8250 or 16450 or compatible"); 		return (0); 	}  	uart_setreg(bas, REG_FCR, FCR_ENABLE | FCR_XMT_RST | FCR_RCV_RST); 	uart_barrier(bas);  	count = 0; 	delay = ar933x_delay(bas);
comment|/* We have FIFOs. Drain the transmitter and receiver. */
block|error = ar933x_drain(bas, UART_DRAIN_RECEIVER|UART_DRAIN_TRANSMITTER); 	if (error) { 		uart_setreg(bas, REG_MCR, mcr); 		uart_setreg(bas, REG_FCR, 0); 		uart_barrier(bas); 		goto describe; 	}
comment|/* 	 * We should have a sufficiently clean "pipe" to determine the 	 * size of the FIFOs. We send as much characters as is reasonable 	 * and wait for the overflow bit in the LSR register to be 	 * asserted, counting the characters as we send them. Based on 	 * that count we know the FIFO size. 	 */
block|do { 		uart_setreg(bas, REG_DATA, 0); 		uart_barrier(bas); 		count++;  		limit = 30; 		lsr = 0;
comment|/* 		 * LSR bits are cleared upon read, so we must accumulate 		 * them to be able to test LSR_OE below. 		 */
block|while (((lsr |= uart_getreg(bas, REG_LSR))& LSR_TEMT) == 0&& 		    --limit) 			DELAY(delay); 		if (limit == 0) { 			ier = uart_getreg(bas, REG_IER)& ns8250->ier_mask; 			uart_setreg(bas, REG_IER, ier); 			uart_setreg(bas, REG_MCR, mcr); 			uart_setreg(bas, REG_FCR, 0); 			uart_barrier(bas); 			count = 0; 			goto describe; 		} 	} while ((lsr& LSR_OE) == 0&& count< 130); 	count--;  	uart_setreg(bas, REG_MCR, mcr);
comment|/* Reset FIFOs. */
block|ar933x_flush(bas, UART_FLUSH_RECEIVER|UART_FLUSH_TRANSMITTER);   describe: 	if (count>= 14&& count<= 16) { 		sc->sc_rxfifosz = 16; 		device_set_desc(sc->sc_dev, "16550 or compatible"); 	} else if (count>= 28&& count<= 32) { 		sc->sc_rxfifosz = 32; 		device_set_desc(sc->sc_dev, "16650 or compatible"); 	} else if (count>= 56&& count<= 64) { 		sc->sc_rxfifosz = 64; 		device_set_desc(sc->sc_dev, "16750 or compatible"); 	} else if (count>= 112&& count<= 128) { 		sc->sc_rxfifosz = 128; 		device_set_desc(sc->sc_dev, "16950 or compatible"); 	} else { 		sc->sc_rxfifosz = 16; 		device_set_desc(sc->sc_dev, 		    "Non-standard ns8250 class UART with FIFOs"); 	}
comment|/* 	 * Force the Tx FIFO size to 16 bytes for now. We don't program the 	 * Tx trigger. Also, we assume that all data has been sent when the 	 * interrupt happens. 	 */
block|sc->sc_txfifosz = 16;
if|#
directive|if
literal|0
comment|/* 	 * XXX there are some issues related to hardware flow control and 	 * it's likely that uart(4) is the cause. This basicly needs more 	 * investigation, but we avoid using for hardware flow control 	 * until then. 	 */
comment|/* 16650s or higher have automatic flow control. */
block|if (sc->sc_rxfifosz> 16) { 		sc->sc_hwiflow = 1; 		sc->sc_hwoflow = 1; 	}
endif|#
directive|endif
endif|#
directive|endif
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
name|ar933x_bus_receive
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
if|#
directive|if
literal|0
block|struct uart_bas *bas; 	int xc; 	uint8_t lsr;  	bas =&sc->sc_bas; 	uart_lock(sc->sc_hwmtx); 	lsr = uart_getreg(bas, REG_LSR); 	while (lsr& LSR_RXRDY) { 		if (uart_rx_full(sc)) { 			sc->sc_rxbuf[sc->sc_rxput] = UART_STAT_OVERRUN; 			break; 		} 		xc = uart_getreg(bas, REG_DATA); 		if (lsr& LSR_FE) 			xc |= UART_STAT_FRAMERR; 		if (lsr& LSR_PE) 			xc |= UART_STAT_PARERR; 		uart_rx_put(sc, xc); 		lsr = uart_getreg(bas, REG_LSR); 	}
comment|/* Discard everything left in the Rx FIFO. */
block|while (lsr& LSR_RXRDY) { 		(void)uart_getreg(bas, REG_DATA); 		uart_barrier(bas); 		lsr = uart_getreg(bas, REG_LSR); 	} 	uart_unlock(sc->sc_hwmtx);
endif|#
directive|endif
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
name|ar933x_bus_setsig
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
if|#
directive|if
literal|0
block|struct ar933x_softc *ns8250 = (struct ar933x_softc*)sc; 	struct uart_bas *bas; 	uint32_t new, old;  	bas =&sc->sc_bas; 	do { 		old = sc->sc_hwsig; 		new = old; 		if (sig& SER_DDTR) { 			SIGCHG(sig& SER_DTR, new, SER_DTR, 			    SER_DDTR); 		} 		if (sig& SER_DRTS) { 			SIGCHG(sig& SER_RTS, new, SER_RTS, 			    SER_DRTS); 		} 	} while (!atomic_cmpset_32(&sc->sc_hwsig, old, new)); 	uart_lock(sc->sc_hwmtx); 	ns8250->mcr&= ~(MCR_DTR|MCR_RTS); 	if (new& SER_DTR) 		ns8250->mcr |= MCR_DTR; 	if (new& SER_RTS) 		ns8250->mcr |= MCR_RTS; 	uart_setreg(bas, REG_MCR, ns8250->mcr); 	uart_barrier(bas); 	uart_unlock(sc->sc_hwmtx);
endif|#
directive|endif
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
name|ar933x_bus_transmit
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
if|#
directive|if
literal|0
block|struct ar933x_softc *ns8250 = (struct ar933x_softc*)sc; 	struct uart_bas *bas; 	int i;  	bas =&sc->sc_bas; 	uart_lock(sc->sc_hwmtx); 	while ((uart_getreg(bas, REG_LSR)& LSR_THRE) == 0) 		; 	uart_setreg(bas, REG_IER, ns8250->ier | IER_ETXRDY); 	uart_barrier(bas); 	for (i = 0; i< sc->sc_txdatasz; i++) { 		uart_setreg(bas, REG_DATA, sc->sc_txbuf[i]); 		uart_barrier(bas); 	} 	sc->sc_txbusy = 1; 	uart_unlock(sc->sc_hwmtx);
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

