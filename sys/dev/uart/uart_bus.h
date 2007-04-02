begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_UART_BUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_UART_BUS_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KLD_MODULE
end_ifndef

begin_include
include|#
directive|include
file|"opt_uart.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/serial.h>
end_include

begin_include
include|#
directive|include
file|<sys/timepps.h>
end_include

begin_comment
comment|/* Drain and flush targets. */
end_comment

begin_define
define|#
directive|define
name|UART_DRAIN_RECEIVER
value|0x0001
end_define

begin_define
define|#
directive|define
name|UART_DRAIN_TRANSMITTER
value|0x0002
end_define

begin_define
define|#
directive|define
name|UART_FLUSH_RECEIVER
value|UART_DRAIN_RECEIVER
end_define

begin_define
define|#
directive|define
name|UART_FLUSH_TRANSMITTER
value|UART_DRAIN_TRANSMITTER
end_define

begin_comment
comment|/* Received character status bits. */
end_comment

begin_define
define|#
directive|define
name|UART_STAT_BREAK
value|0x0100
end_define

begin_define
define|#
directive|define
name|UART_STAT_FRAMERR
value|0x0200
end_define

begin_define
define|#
directive|define
name|UART_STAT_OVERRUN
value|0x0400
end_define

begin_define
define|#
directive|define
name|UART_STAT_PARERR
value|0x0800
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|UART_PPS_ON_CTS
end_ifdef

begin_define
define|#
directive|define
name|UART_SIG_DPPS
value|SER_DCTS
end_define

begin_define
define|#
directive|define
name|UART_SIG_PPS
value|SER_CTS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UART_SIG_DPPS
value|SER_DDCD
end_define

begin_define
define|#
directive|define
name|UART_SIG_PPS
value|SER_DCD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UART_IOCTL() requests */
end_comment

begin_define
define|#
directive|define
name|UART_IOCTL_BREAK
value|1
end_define

begin_define
define|#
directive|define
name|UART_IOCTL_IFLOW
value|2
end_define

begin_define
define|#
directive|define
name|UART_IOCTL_OFLOW
value|3
end_define

begin_define
define|#
directive|define
name|UART_IOCTL_BAUD
value|4
end_define

begin_comment
comment|/*  * UART class& instance (=softc)  */
end_comment

begin_struct
struct|struct
name|uart_class
block|{
name|KOBJ_CLASS_FIELDS
expr_stmt|;
name|struct
name|uart_ops
modifier|*
name|uc_ops
decl_stmt|;
comment|/* Low-level console operations. */
name|u_int
name|uc_range
decl_stmt|;
comment|/* Bus space address range. */
name|u_int
name|uc_rclk
decl_stmt|;
comment|/* Default rclk for this device. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uart_softc
block|{
name|KOBJ_FIELDS
expr_stmt|;
name|struct
name|uart_class
modifier|*
name|sc_class
decl_stmt|;
name|struct
name|uart_bas
name|sc_bas
decl_stmt|;
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|mtx
name|sc_hwmtx_s
decl_stmt|;
comment|/* Spinlock protecting hardware. */
name|struct
name|mtx
modifier|*
name|sc_hwmtx
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_rres
decl_stmt|;
comment|/* Register resource. */
name|int
name|sc_rrid
decl_stmt|;
name|int
name|sc_rtype
decl_stmt|;
comment|/* SYS_RES_{IOPORT|MEMORY}. */
name|struct
name|resource
modifier|*
name|sc_ires
decl_stmt|;
comment|/* Interrupt resource. */
name|void
modifier|*
name|sc_icookie
decl_stmt|;
name|int
name|sc_irid
decl_stmt|;
name|int
name|sc_callout
range|:
literal|1
decl_stmt|;
comment|/* This UART is opened for callout. */
name|int
name|sc_fastintr
range|:
literal|1
decl_stmt|;
comment|/* This UART uses fast interrupts. */
name|int
name|sc_hwiflow
range|:
literal|1
decl_stmt|;
comment|/* This UART has HW input flow ctl. */
name|int
name|sc_hwoflow
range|:
literal|1
decl_stmt|;
comment|/* This UART has HW output flow ctl. */
name|int
name|sc_leaving
range|:
literal|1
decl_stmt|;
comment|/* This UART is going away. */
name|int
name|sc_opened
range|:
literal|1
decl_stmt|;
comment|/* This UART is open for business. */
name|int
name|sc_polled
range|:
literal|1
decl_stmt|;
comment|/* This UART has no interrupts. */
name|int
name|sc_txbusy
range|:
literal|1
decl_stmt|;
comment|/* This UART is transmitting. */
name|struct
name|uart_devinfo
modifier|*
name|sc_sysdev
decl_stmt|;
comment|/* System device (or NULL). */
name|int
name|sc_altbrk
decl_stmt|;
comment|/* State for alt break sequence. */
name|uint32_t
name|sc_hwsig
decl_stmt|;
comment|/* Signal state. Used by HW driver. */
comment|/* Receiver data. */
name|uint16_t
modifier|*
name|sc_rxbuf
decl_stmt|;
name|int
name|sc_rxbufsz
decl_stmt|;
name|int
name|sc_rxput
decl_stmt|;
name|int
name|sc_rxget
decl_stmt|;
name|int
name|sc_rxfifosz
decl_stmt|;
comment|/* Size of RX FIFO. */
comment|/* Transmitter data. */
name|uint8_t
modifier|*
name|sc_txbuf
decl_stmt|;
name|int
name|sc_txdatasz
decl_stmt|;
name|int
name|sc_txfifosz
decl_stmt|;
comment|/* Size of TX FIFO and buffer. */
comment|/* Pulse capturing support (PPS). */
name|struct
name|pps_state
name|sc_pps
decl_stmt|;
comment|/* Upper layer data. */
name|void
modifier|*
name|sc_softih
decl_stmt|;
name|uint32_t
name|sc_ttypend
decl_stmt|;
union|union
block|{
comment|/* TTY specific data. */
struct|struct
block|{
name|struct
name|tty
modifier|*
name|tp
decl_stmt|;
block|}
name|u_tty
struct|;
comment|/* Keyboard specific data. */
struct|struct
block|{ 		}
name|u_kbd
struct|;
block|}
name|sc_u
union|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|uart_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|uart_driver_name
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|uart_bus_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uart_bus_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|serdev_intr_t
modifier|*
name|uart_bus_ihand
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|ipend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uart_bus_ipend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uart_bus_probe
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|regshft
parameter_list|,
name|int
name|rclk
parameter_list|,
name|int
name|rid
parameter_list|,
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uart_bus_sysdev
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uart_tty_attach
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uart_tty_detach
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uart_tty_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Receive buffer operations.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|uart_rx_empty
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
return|return
operator|(
operator|(
name|sc
operator|->
name|sc_rxget
operator|==
name|sc
operator|->
name|sc_rxput
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|uart_rx_full
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
return|return
operator|(
operator|(
name|sc
operator|->
name|sc_rxput
operator|+
literal|1
operator|<
name|sc
operator|->
name|sc_rxbufsz
operator|)
condition|?
operator|(
name|sc
operator|->
name|sc_rxput
operator|+
literal|1
operator|==
name|sc
operator|->
name|sc_rxget
operator|)
else|:
operator|(
name|sc
operator|->
name|sc_rxget
operator|==
literal|0
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|uart_rx_get
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|)
block|{
name|int
name|ptr
decl_stmt|,
name|xc
decl_stmt|;
name|ptr
operator|=
name|sc
operator|->
name|sc_rxget
expr_stmt|;
if|if
condition|(
name|ptr
operator|==
name|sc
operator|->
name|sc_rxput
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|xc
operator|=
name|sc
operator|->
name|sc_rxbuf
index|[
name|ptr
operator|++
index|]
expr_stmt|;
name|sc
operator|->
name|sc_rxget
operator|=
operator|(
name|ptr
operator|<
name|sc
operator|->
name|sc_rxbufsz
operator|)
condition|?
name|ptr
else|:
literal|0
expr_stmt|;
return|return
operator|(
name|xc
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|uart_rx_put
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|,
name|int
name|xc
parameter_list|)
block|{
name|int
name|ptr
decl_stmt|;
name|ptr
operator|=
operator|(
name|sc
operator|->
name|sc_rxput
operator|+
literal|1
operator|<
name|sc
operator|->
name|sc_rxbufsz
operator|)
condition|?
name|sc
operator|->
name|sc_rxput
operator|+
literal|1
else|:
literal|0
expr_stmt|;
if|if
condition|(
name|ptr
operator|==
name|sc
operator|->
name|sc_rxget
condition|)
return|return
operator|(
name|ENOSPC
operator|)
return|;
name|sc
operator|->
name|sc_rxbuf
index|[
name|sc
operator|->
name|sc_rxput
index|]
operator|=
name|xc
expr_stmt|;
name|sc
operator|->
name|sc_rxput
operator|=
name|ptr
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_UART_BUS_H_ */
end_comment

end_unit

