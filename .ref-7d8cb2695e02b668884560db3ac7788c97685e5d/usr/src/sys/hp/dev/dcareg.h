begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1990 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)dcareg.h	7.5 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<hp/dev/iotypes.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|hp700
end_ifdef

begin_struct
struct|struct
name|dcadevice
block|{
name|vu_char
name|dca_reset
decl_stmt|;
name|vu_char
name|dca_pad
index|[
literal|0x800
operator|-
literal|1
index|]
decl_stmt|;
name|vu_char
name|dca_data
decl_stmt|;
comment|/* receive buf or xmit hold */
name|vu_char
name|dca_ier
decl_stmt|;
comment|/* interrupt enable */
name|vu_char
name|dca_iir
decl_stmt|;
comment|/* (RO) interrupt identify */
define|#
directive|define
name|dca_fifo
value|dca_iir
comment|/* (WO) FIFO control */
name|vu_char
name|dca_cfcr
decl_stmt|;
comment|/* line control */
name|vu_char
name|dca_mcr
decl_stmt|;
comment|/* modem control */
name|vu_char
name|dca_lsr
decl_stmt|;
comment|/* line status */
name|vu_char
name|dca_msr
decl_stmt|;
comment|/* modem status */
name|vu_char
name|dca_scr
decl_stmt|;
comment|/* scratch pad */
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|dcadevice
block|{
comment|/* card registers */
name|u_char
name|dca_pad0
decl_stmt|;
name|vu_char
name|dca_id
decl_stmt|;
comment|/* 0x01 (read) */
define|#
directive|define
name|dca_reset
value|dca_id
comment|/* 0x01 (write) */
name|u_char
name|dca_pad1
decl_stmt|;
name|vu_char
name|dca_ic
decl_stmt|;
comment|/* 0x03 */
name|u_char
name|dca_pad2
decl_stmt|;
name|vu_char
name|dca_ocbrc
decl_stmt|;
comment|/* 0x05 */
name|u_char
name|dca_pad3
decl_stmt|;
name|vu_char
name|dca_lcsm
decl_stmt|;
comment|/* 0x07 */
name|u_char
name|dca_pad4
index|[
literal|8
index|]
decl_stmt|;
comment|/* chip registers */
name|u_char
name|dca_pad5
decl_stmt|;
name|vu_char
name|dca_data
decl_stmt|;
comment|/* 0x11 */
name|u_char
name|dca_pad6
decl_stmt|;
name|vu_char
name|dca_ier
decl_stmt|;
comment|/* 0x13 */
name|u_char
name|dca_pad7
decl_stmt|;
name|vu_char
name|dca_iir
decl_stmt|;
comment|/* 0x15 (read) */
define|#
directive|define
name|dca_fifo
value|dca_iir
comment|/* 0x15 (write) */
name|u_char
name|dca_pad8
decl_stmt|;
name|vu_char
name|dca_cfcr
decl_stmt|;
comment|/* 0x17 */
name|u_char
name|dca_pad9
decl_stmt|;
name|vu_char
name|dca_mcr
decl_stmt|;
comment|/* 0x19 */
name|u_char
name|dca_padA
decl_stmt|;
name|vu_char
name|dca_lsr
decl_stmt|;
comment|/* 0x1B */
name|u_char
name|dca_padB
decl_stmt|;
name|vu_char
name|dca_msr
decl_stmt|;
comment|/* 0x1D */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* interface reset/id (300 only) */
end_comment

begin_define
define|#
directive|define
name|DCAID0
value|0x02
end_define

begin_define
define|#
directive|define
name|DCAREMID0
value|0x82
end_define

begin_define
define|#
directive|define
name|DCAID1
value|0x42
end_define

begin_define
define|#
directive|define
name|DCAREMID1
value|0xC2
end_define

begin_comment
comment|/* interrupt control (300 only) */
end_comment

begin_define
define|#
directive|define
name|DCAIPL
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 4)& 3) + 3)
end_define

begin_define
define|#
directive|define
name|IC_IR
value|0x40
end_define

begin_define
define|#
directive|define
name|IC_IE
value|0x80
end_define

begin_comment
comment|/*  * 16 bit baud rate divisor (lower byte in dca_data, upper in dca_ier)  * NB: This constant is for a 7.3728 clock frequency. The 300 clock  *     frequency is 2.4576, giving a constant of 153600.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|hp300
end_ifdef

begin_define
define|#
directive|define
name|DCABRD
parameter_list|(
name|x
parameter_list|)
value|(153600 / (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|hp700
end_ifdef

begin_define
define|#
directive|define
name|DCABRD
parameter_list|(
name|x
parameter_list|)
value|(460800 / (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* interrupt enable register */
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

begin_comment
comment|/* interrupt identification register */
end_comment

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

begin_comment
comment|/* fifo control register */
end_comment

begin_define
define|#
directive|define
name|FIFO_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|FIFO_RCV_RST
value|0x02
end_define

begin_define
define|#
directive|define
name|FIFO_XMT_RST
value|0x04
end_define

begin_define
define|#
directive|define
name|FIFO_DMA_MODE
value|0x08
end_define

begin_define
define|#
directive|define
name|FIFO_TRIGGER_1
value|0x00
end_define

begin_define
define|#
directive|define
name|FIFO_TRIGGER_4
value|0x40
end_define

begin_define
define|#
directive|define
name|FIFO_TRIGGER_8
value|0x80
end_define

begin_define
define|#
directive|define
name|FIFO_TRIGGER_14
value|0xc0
end_define

begin_comment
comment|/* character format control register */
end_comment

begin_define
define|#
directive|define
name|CFCR_DLAB
value|0x80
end_define

begin_define
define|#
directive|define
name|CFCR_SBREAK
value|0x40
end_define

begin_define
define|#
directive|define
name|CFCR_PZERO
value|0x30
end_define

begin_define
define|#
directive|define
name|CFCR_PONE
value|0x20
end_define

begin_define
define|#
directive|define
name|CFCR_PEVEN
value|0x10
end_define

begin_define
define|#
directive|define
name|CFCR_PODD
value|0x00
end_define

begin_define
define|#
directive|define
name|CFCR_PENAB
value|0x08
end_define

begin_define
define|#
directive|define
name|CFCR_STOPB
value|0x04
end_define

begin_define
define|#
directive|define
name|CFCR_8BITS
value|0x03
end_define

begin_define
define|#
directive|define
name|CFCR_7BITS
value|0x02
end_define

begin_define
define|#
directive|define
name|CFCR_6BITS
value|0x01
end_define

begin_define
define|#
directive|define
name|CFCR_5BITS
value|0x00
end_define

begin_comment
comment|/* modem control register */
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
name|MCR_IEN
value|0x08
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

begin_comment
comment|/* line status register */
end_comment

begin_define
define|#
directive|define
name|LSR_RCV_FIFO
value|0x80
end_define

begin_define
define|#
directive|define
name|LSR_TSRE
value|0x40
end_define

begin_define
define|#
directive|define
name|LSR_TXRDY
value|0x20
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

begin_comment
comment|/* modem status register */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|hp300
end_ifdef

begin_comment
comment|/* WARNING: Serial console is assumed to be at SC9 */
end_comment

begin_define
define|#
directive|define
name|CONSCODE
value|(9)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|hp700
end_ifdef

begin_comment
comment|/* hardwired port addresses */
end_comment

begin_define
define|#
directive|define
name|PORT1
value|((struct dcadevice *)CORE_RS232_1)
end_define

begin_define
define|#
directive|define
name|PORT2
value|((struct dcadevice *)CORE_RS232_2)
end_define

begin_define
define|#
directive|define
name|CONPORT
value|PORT1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CONUNIT
value|(0)
end_define

end_unit

