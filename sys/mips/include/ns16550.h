begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997-2001, 2005, Juniper Networks, Inc.  * All rights reserved.  *  * ns16550.h -- NS16550 DUART Device Driver, used on Atlas, SCB and NIC  *  * Michael Beesley, April 1997  * Highly leveraged from the Atlas device driver written by Jim Hayes  *  *	JNPR: ns16550.h,v 1.2.4.1 2007/09/10 07:51:14 girish  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NS16550_H__
end_ifndef

begin_define
define|#
directive|define
name|__NS16550_H__
end_define

begin_comment
comment|/* speed to initialize to during chip tests */
end_comment

begin_define
define|#
directive|define
name|SIO_TEST_SPEED
value|9600
end_define

begin_comment
comment|/* default serial console speed if not set with sysctl or probed from boot */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONSPEED
end_ifndef

begin_define
define|#
directive|define
name|CONSPEED
value|9600
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default serial gdb speed if not set with sysctl or probed from boot */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDBSPEED
end_ifndef

begin_define
define|#
directive|define
name|GDBSPEED
value|CONSPEED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IO_COMSIZE
value|8
end_define

begin_comment
comment|/* 8250, 16x50 com controllers */
end_comment

begin_comment
comment|/*  * NS16550 UART registers  */
end_comment

begin_comment
comment|/* 8250 registers #[0-6]. */
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

begin_define
define|#
directive|define
name|IIR_IMASK
value|0xf
end_define

begin_define
define|#
directive|define
name|IIR_RXTOUT
value|0xc
end_define

begin_define
define|#
directive|define
name|IIR_RLS
value|0x6
end_define

begin_define
define|#
directive|define
name|IIR_RXRDY
value|0x4
end_define

begin_define
define|#
directive|define
name|IIR_TXRDY
value|0x2
end_define

begin_define
define|#
directive|define
name|IIR_NOPEND
value|0x1
end_define

begin_define
define|#
directive|define
name|IIR_MLSC
value|0x0
end_define

begin_define
define|#
directive|define
name|IIR_FIFO_MASK
value|0xc0
end_define

begin_comment
comment|/* set if FIFOs are enabled */
end_comment

begin_define
define|#
directive|define
name|LCR_DLAB
value|0x80
end_define

begin_define
define|#
directive|define
name|CFCR_DLAB
value|LCR_DLAB
end_define

begin_define
define|#
directive|define
name|LCR_EFR_ENABLE
value|0xbf
end_define

begin_comment
comment|/* magic to enable EFR on 16650 up */
end_comment

begin_define
define|#
directive|define
name|CFCR_EFR_ENABLE
value|LCR_EFR_ENABLE
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
name|CFCR_SBREAK
value|LCR_SBREAK
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
name|CFCR_PZERO
value|LCR_PZERO
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
name|CFCR_PONE
value|LCR_PONE
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
name|CFCR_PEVEN
value|LCR_PEVEN
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
name|CFCR_PODD
value|LCR_PODD
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
name|CFCR_PENAB
value|LCR_PENAB
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
name|CFCR_STOPB
value|LCR_STOPB
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
name|CFCR_8BITS
value|LCR_8BITS
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
name|CFCR_7BITS
value|LCR_7BITS
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
name|CFCR_6BITS
value|LCR_6BITS
end_define

begin_define
define|#
directive|define
name|LCR_5BITS
value|0x00
end_define

begin_define
define|#
directive|define
name|CFCR_5BITS
value|LCR_5BITS
end_define

begin_define
define|#
directive|define
name|MCR_PRESCALE
value|0x80
end_define

begin_comment
comment|/* only available on 16650 up */
end_comment

begin_define
define|#
directive|define
name|MCR_LOOPBACK
value|0x10
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
name|MCR_IENABLE
value|MCR_IE
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
name|MCR_RTS
value|0x02
end_define

begin_define
define|#
directive|define
name|MCR_DTR
value|0x01
end_define

begin_define
define|#
directive|define
name|LSR_RCV_FIFO
value|0x80
end_define

begin_define
define|#
directive|define
name|LSR_TEMT
value|0x40
end_define

begin_define
define|#
directive|define
name|LSR_TSRE
value|LSR_TEMT
end_define

begin_define
define|#
directive|define
name|LSR_THRE
value|0x20
end_define

begin_define
define|#
directive|define
name|LSR_TXRDY
value|LSR_THRE
end_define

begin_define
define|#
directive|define
name|LSR_BI
value|0x10
end_define

begin_define
define|#
directive|define
name|LSR_FE
value|0x08
end_define

begin_define
define|#
directive|define
name|LSR_PE
value|0x04
end_define

begin_define
define|#
directive|define
name|LSR_OE
value|0x02
end_define

begin_define
define|#
directive|define
name|LSR_RXRDY
value|0x01
end_define

begin_define
define|#
directive|define
name|LSR_RCV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|MSR_DCD
value|0x80
end_define

begin_define
define|#
directive|define
name|MSR_RI
value|0x40
end_define

begin_define
define|#
directive|define
name|MSR_DSR
value|0x20
end_define

begin_define
define|#
directive|define
name|MSR_CTS
value|0x10
end_define

begin_define
define|#
directive|define
name|MSR_DDCD
value|0x08
end_define

begin_define
define|#
directive|define
name|MSR_TERI
value|0x04
end_define

begin_define
define|#
directive|define
name|MSR_DDSR
value|0x02
end_define

begin_define
define|#
directive|define
name|MSR_DCTS
value|0x01
end_define

begin_define
define|#
directive|define
name|FCR_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|FIFO_ENABLE
value|FCR_ENABLE
end_define

begin_define
define|#
directive|define
name|FCR_RCV_RST
value|0x02
end_define

begin_define
define|#
directive|define
name|FIFO_RCV_RST
value|FCR_RCV_RST
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
name|FIFO_XMT_RST
value|FCR_XMT_RST
end_define

begin_define
define|#
directive|define
name|FCR_DMA
value|0x08
end_define

begin_define
define|#
directive|define
name|FIFO_DMA_MODE
value|FCR_DMA
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
name|FIFO_RX_LOW
value|FCR_RX_LOW
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
name|FIFO_RX_MEDL
value|FCR_RX_MEDL
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
name|FIFO_RX_MEDH
value|FCR_RX_MEDH
end_define

begin_define
define|#
directive|define
name|FCR_RX_HIGH
value|0xc0
end_define

begin_define
define|#
directive|define
name|FIFO_RX_HIGH
value|FCR_RX_HIGH
end_define

begin_comment
comment|/* 16650 registers #2,[4-7].  Access enabled by LCR_EFR_ENABLE. */
end_comment

begin_define
define|#
directive|define
name|EFR_CTS
value|0x80
end_define

begin_define
define|#
directive|define
name|EFR_AUTOCTS
value|EFR_CTS
end_define

begin_define
define|#
directive|define
name|EFR_RTS
value|0x40
end_define

begin_define
define|#
directive|define
name|EFR_AUTORTS
value|EFR_RTS
end_define

begin_define
define|#
directive|define
name|EFR_EFE
value|0x10
end_define

begin_comment
comment|/* enhanced functions enable */
end_comment

begin_define
define|#
directive|define
name|com_data
value|0
end_define

begin_comment
comment|/* data register (R) */
end_comment

begin_define
define|#
directive|define
name|com_rdata
value|0
end_define

begin_comment
comment|/* data register (R) */
end_comment

begin_define
define|#
directive|define
name|com_tdata
value|0
end_define

begin_comment
comment|/* data register (W) */
end_comment

begin_define
define|#
directive|define
name|com_dlbl
value|0
end_define

begin_comment
comment|/* divisor latch low (W) */
end_comment

begin_define
define|#
directive|define
name|com_dlbh
value|0x4
end_define

begin_comment
comment|/* divisor latch high (W) */
end_comment

begin_define
define|#
directive|define
name|com_ier
value|0x4
end_define

begin_comment
comment|/* interrupt enable (W) */
end_comment

begin_define
define|#
directive|define
name|com_iir
value|0x8
end_define

begin_comment
comment|/* interrupt identification (R) */
end_comment

begin_define
define|#
directive|define
name|com_fifo
value|0x8
end_define

begin_comment
comment|/* FIFO control (W) */
end_comment

begin_define
define|#
directive|define
name|com_lctl
value|0xc
end_define

begin_comment
comment|/* line control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_cfcr
value|0xc
end_define

begin_comment
comment|/* line control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_mcr
value|0x10
end_define

begin_comment
comment|/* modem control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_lsr
value|0x14
end_define

begin_comment
comment|/* line status register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_msr
value|0x18
end_define

begin_comment
comment|/* modem status register (R/W) */
end_comment

begin_define
define|#
directive|define
name|NS16550_HZ
value|(33300000)
end_define

begin_comment
comment|/* 33.3 Mhz */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_RCLK
value|(33300000)
end_define

begin_define
define|#
directive|define
name|NS16550_PAD
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/*  * ns16550_device: Structure to lay down over the device registers  * Note: all accesses are 8-bit reads and writes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|data
decl_stmt|;
comment|/* data register (R/W) */
specifier|volatile
name|u_int32_t
name|ier
decl_stmt|;
comment|/* interrupt enable (W) */
specifier|volatile
name|u_int32_t
name|iir
decl_stmt|;
comment|/* interrupt identification (R) */
specifier|volatile
name|u_int32_t
name|cfcr
decl_stmt|;
comment|/* line control register (R/W) */
specifier|volatile
name|u_int32_t
name|mcr
decl_stmt|;
comment|/* modem control register (R/W) */
specifier|volatile
name|u_int32_t
name|lsr
decl_stmt|;
comment|/* line status register (R/W) */
specifier|volatile
name|u_int32_t
name|msr
decl_stmt|;
comment|/* modem status register (R/W) */
specifier|volatile
name|u_int32_t
name|scr
decl_stmt|;
comment|/* scratch register (R/W) */
block|}
name|ns16550_device
typedef|;
end_typedef

begin_define
define|#
directive|define
name|com_lcr
value|com_cfcr
end_define

begin_define
define|#
directive|define
name|com_efr
value|com_fifo
end_define

begin_define
define|#
directive|define
name|NS16550_SYNC
value|__asm __volatile ("sync")
end_define

begin_define
define|#
directive|define
name|NS16550_DEVICE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|TI16C752B_DEVICE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|fifo
value|iir
end_define

begin_comment
comment|/* 16550 fifo control (W) */
end_comment

begin_comment
comment|/* 16 bit baud rate divisor (lower byte in dca_data, upper in dca_ier) */
end_comment

begin_define
define|#
directive|define
name|BRTC
parameter_list|(
name|x
parameter_list|)
value|(NS16550_HZ / (16*(x)))
end_define

begin_define
define|#
directive|define
name|PA_2_K1VA
parameter_list|(
name|a
parameter_list|)
value|(MIPS_UNCACHED_MEMORY_ADDR | (a))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|COMBRD
end_ifdef

begin_undef
undef|#
directive|undef
name|COMBRD
end_undef

begin_define
define|#
directive|define
name|COMBRD
parameter_list|(
name|x
parameter_list|)
value|(NS16550_HZ / (16*(x)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|uart_post_init
parameter_list|(
name|u_int32_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|puts_post
parameter_list|(
name|u_int32_t
name|addr
parameter_list|,
specifier|const
name|char
modifier|*
name|char_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hexout_post
parameter_list|(
name|u_int32_t
name|addr
parameter_list|,
name|u_int32_t
name|value
parameter_list|,
name|int
name|num_chars
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NS16550_H__ */
end_comment

begin_comment
comment|/* end of file */
end_comment

end_unit

