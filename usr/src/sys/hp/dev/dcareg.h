begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1990 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)dcareg.h	7.3 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|dcadevice
block|{
name|u_char
name|dca_pad0
decl_stmt|;
specifier|volatile
name|u_char
name|dca_irid
decl_stmt|;
specifier|volatile
name|short
name|dca_ic
decl_stmt|;
specifier|volatile
name|short
name|dca_ocbrc
decl_stmt|;
specifier|volatile
name|short
name|dca_lcsm
decl_stmt|;
name|short
name|dca_pad1
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|dca_pad2
decl_stmt|;
specifier|volatile
name|u_char
name|dca_data
decl_stmt|;
specifier|volatile
name|short
name|dca_ier
decl_stmt|;
name|u_char
name|dca_pad4
decl_stmt|;
specifier|volatile
name|u_char
name|dca_iir
decl_stmt|;
comment|/* read-only */
define|#
directive|define
name|dca_fifo
value|dca_iir
comment|/* write-only */
specifier|volatile
name|short
name|dca_cfcr
decl_stmt|;
specifier|volatile
name|short
name|dca_mcr
decl_stmt|;
specifier|volatile
name|short
name|dca_lsr
decl_stmt|;
name|u_char
name|dca_pad3
decl_stmt|;
specifier|volatile
name|u_char
name|dca_msr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* interface reset/id */
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
comment|/* interrupt control */
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
comment|/* 16 bit baud rate divisor (lower byte in dca_data, upper in dca_ier) */
end_comment

begin_define
define|#
directive|define
name|DCABRD
parameter_list|(
name|x
parameter_list|)
value|(153600 / (x))
end_define

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
name|MCR_SRTS
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

begin_comment
comment|/*  * WARNING: Serial console is assumed to be at SC9  * and CONUNIT must be 0.  */
end_comment

begin_define
define|#
directive|define
name|CONSCODE
value|(9)
end_define

begin_define
define|#
directive|define
name|CONUNIT
value|(0)
end_define

end_unit

