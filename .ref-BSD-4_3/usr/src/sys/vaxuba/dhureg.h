begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dhureg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*   * DHU-11 device register definitions.  */
end_comment

begin_struct
struct|struct
name|dhudevice
block|{
union|union
block|{
name|short
name|csr
decl_stmt|;
comment|/* control-status register */
struct|struct
block|{
name|char
name|csrl
decl_stmt|;
comment|/* low byte for line select */
name|char
name|csrh
decl_stmt|;
comment|/* high byte for tx line */
block|}
name|cb
struct|;
block|}
name|un1
union|;
define|#
directive|define
name|dhucsr
value|un1.csr
define|#
directive|define
name|dhucsrl
value|un1.cb.csrl
define|#
directive|define
name|dhucsrh
value|un1.cb.csrh
union|union
block|{
name|short
name|rbuf
decl_stmt|;
comment|/* recv.char/ds.change register (R) */
name|short
name|timo
decl_stmt|;
comment|/* delay between recv -> intr (W) */
block|}
name|un2
union|;
define|#
directive|define
name|dhurbuf
value|un2.rbuf
define|#
directive|define
name|dhutimo
value|un2.timo
name|short
name|dhulpr
decl_stmt|;
comment|/* line parameter register */
union|union
block|{
name|char
name|fbyte
index|[
literal|1
index|]
decl_stmt|;
comment|/* fifo data byte (low byte only) (W) */
name|short
name|fdata
decl_stmt|;
comment|/* fifo data word (W) */
name|char
name|sbyte
index|[
literal|2
index|]
decl_stmt|;
comment|/* line status/fifo size (R) */
block|}
name|un3
union|;
define|#
directive|define
name|dhubyte
value|un3.fbyte[0]
define|#
directive|define
name|dhufifo
value|un3.fdata
define|#
directive|define
name|dhusize
value|un3.sbyte[0]
define|#
directive|define
name|dhustat
value|un3.sbyte[1]
name|short
name|dhulcr
decl_stmt|;
comment|/* line control register */
name|short
name|dhubar1
decl_stmt|;
comment|/* buffer address register 1 */
name|char
name|dhubar2
decl_stmt|;
comment|/* buffer address register 2 */
name|char
name|dhulcr2
decl_stmt|;
comment|/* xmit enable bit */
name|short
name|dhubcr
decl_stmt|;
comment|/* buffer count register */
block|}
struct|;
end_struct

begin_comment
comment|/* Bits in dhucsr */
end_comment

begin_define
define|#
directive|define
name|DHU_CS_TIE
value|0x4000
end_define

begin_comment
comment|/* transmit interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DHU_CS_DFAIL
value|0x2000
end_define

begin_comment
comment|/* diagnostic fail */
end_comment

begin_define
define|#
directive|define
name|DHU_CS_RI
value|0x0080
end_define

begin_comment
comment|/* receiver interrupt */
end_comment

begin_define
define|#
directive|define
name|DHU_CS_RIE
value|0x0040
end_define

begin_comment
comment|/* receiver interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DHU_CS_MCLR
value|0x0020
end_define

begin_comment
comment|/* master clear */
end_comment

begin_define
define|#
directive|define
name|DHU_CS_SST
value|0x0010
end_define

begin_comment
comment|/* skip self test (with DHU_CS_MCLR) */
end_comment

begin_define
define|#
directive|define
name|DHU_CS_IAP
value|0x000f
end_define

begin_comment
comment|/* indirect address pointer */
end_comment

begin_define
define|#
directive|define
name|DHU_IE
value|(DHU_CS_TIE|DHU_CS_RIE)
end_define

begin_comment
comment|/* map unit into iap register select */
end_comment

begin_define
define|#
directive|define
name|DHU_SELECT
parameter_list|(
name|unit
parameter_list|)
value|((unit)& DHU_CS_IAP)
end_define

begin_comment
comment|/* Transmitter bits in high byte of dhucsr */
end_comment

begin_define
define|#
directive|define
name|DHU_CSH_TI
value|0x80
end_define

begin_comment
comment|/* transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|DHU_CSH_NXM
value|0x10
end_define

begin_comment
comment|/* transmit dma err: non-exist-mem */
end_comment

begin_define
define|#
directive|define
name|DHU_CSH_TLN
value|0x0f
end_define

begin_comment
comment|/* transmit line number */
end_comment

begin_comment
comment|/* map csrh line bits into line */
end_comment

begin_define
define|#
directive|define
name|DHU_TX_LINE
parameter_list|(
name|csrh
parameter_list|)
value|((csrh)& DHU_CSH_TLN)
end_define

begin_comment
comment|/* Bits in dhurbuf */
end_comment

begin_define
define|#
directive|define
name|DHU_RB_VALID
value|0x8000
end_define

begin_comment
comment|/* data valid */
end_comment

begin_define
define|#
directive|define
name|DHU_RB_STAT
value|0x7000
end_define

begin_comment
comment|/* status bits */
end_comment

begin_define
define|#
directive|define
name|DHU_RB_DO
value|0x4000
end_define

begin_comment
comment|/* data overrun */
end_comment

begin_define
define|#
directive|define
name|DHU_RB_FE
value|0x2000
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|DHU_RB_PE
value|0x1000
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|DHU_RB_RLN
value|0x0f00
end_define

begin_comment
comment|/* receive line number */
end_comment

begin_define
define|#
directive|define
name|DHU_RB_RDS
value|0x00ff
end_define

begin_comment
comment|/* receive data/status */
end_comment

begin_define
define|#
directive|define
name|DHU_RB_DIAG
value|0x0001
end_define

begin_comment
comment|/* if DHU_RB_STAT -> diag vs modem */
end_comment

begin_comment
comment|/* map rbuf line bits into line */
end_comment

begin_define
define|#
directive|define
name|DHU_RX_LINE
parameter_list|(
name|rbuf
parameter_list|)
value|(((rbuf)& DHU_RB_RLN)>> 8)
end_define

begin_comment
comment|/* Bits in dhulpr */
end_comment

begin_define
define|#
directive|define
name|DHU_LP_TSPEED
value|0xf000
end_define

begin_define
define|#
directive|define
name|DHU_LP_RSPEED
value|0x0f00
end_define

begin_define
define|#
directive|define
name|DHU_LP_TWOSB
value|0x0080
end_define

begin_define
define|#
directive|define
name|DHU_LP_EPAR
value|0x0040
end_define

begin_define
define|#
directive|define
name|DHU_LP_PENABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|DHU_LP_BITS8
value|0x0018
end_define

begin_define
define|#
directive|define
name|DHU_LP_BITS7
value|0x0010
end_define

begin_define
define|#
directive|define
name|DHU_LP_BITS6
value|0x0008
end_define

begin_comment
comment|/* Bits in dhustat */
end_comment

begin_define
define|#
directive|define
name|DHU_ST_DSR
value|0x80
end_define

begin_comment
comment|/* data set ready */
end_comment

begin_define
define|#
directive|define
name|DHU_ST_RI
value|0x20
end_define

begin_comment
comment|/* ring indicator */
end_comment

begin_define
define|#
directive|define
name|DHU_ST_DCD
value|0x10
end_define

begin_comment
comment|/* carrier detect */
end_comment

begin_define
define|#
directive|define
name|DHU_ST_CTS
value|0x04
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|DHU_ST_DHU
value|0x01
end_define

begin_comment
comment|/* always one on a dhu, zero on dhv */
end_comment

begin_comment
comment|/* Bits in dhulcr */
end_comment

begin_define
define|#
directive|define
name|DHU_LC_RTS
value|0x1000
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|DHU_LC_DTR
value|0x0200
end_define

begin_comment
comment|/* data terminal ready */
end_comment

begin_define
define|#
directive|define
name|DHU_LC_MODEM
value|0x0100
end_define

begin_comment
comment|/* modem control enable */
end_comment

begin_define
define|#
directive|define
name|DHU_LC_MAINT
value|0x00c0
end_define

begin_comment
comment|/* maintenance mode */
end_comment

begin_define
define|#
directive|define
name|DHU_LC_FXOFF
value|0x0020
end_define

begin_comment
comment|/* force xoff */
end_comment

begin_define
define|#
directive|define
name|DHU_LC_OAUTOF
value|0x0010
end_define

begin_comment
comment|/* output auto flow */
end_comment

begin_define
define|#
directive|define
name|DHU_LC_BREAK
value|0x0008
end_define

begin_comment
comment|/* break control */
end_comment

begin_define
define|#
directive|define
name|DHU_LC_RXEN
value|0x0004
end_define

begin_comment
comment|/* receiver enable */
end_comment

begin_define
define|#
directive|define
name|DHU_LC_IAUTOF
value|0x0002
end_define

begin_comment
comment|/* input auto flow */
end_comment

begin_define
define|#
directive|define
name|DHU_LC_TXABORT
value|0x0001
end_define

begin_comment
comment|/* transmitter abort */
end_comment

begin_comment
comment|/* Bits in dhulcr2 */
end_comment

begin_define
define|#
directive|define
name|DHU_LC2_TXEN
value|0x80
end_define

begin_comment
comment|/* transmitter enable */
end_comment

begin_comment
comment|/* Bits in dhubar2 */
end_comment

begin_define
define|#
directive|define
name|DHU_BA2_DMAGO
value|0x80
end_define

begin_comment
comment|/* transmit dma start */
end_comment

begin_define
define|#
directive|define
name|DHU_BA2_XBA
value|0x03
end_define

begin_comment
comment|/* top two bits of dma address */
end_comment

begin_define
define|#
directive|define
name|DHU_XBA_SHIFT
value|16
end_define

begin_comment
comment|/* amount to shift xba bits */
end_comment

begin_comment
comment|/* Bits for dhumctl only:  stat bits are shifted up 16 */
end_comment

begin_define
define|#
directive|define
name|DHU_ON
value|(DHU_LC_DTR|DHU_LC_RTS|DHU_LC_MODEM)
end_define

begin_define
define|#
directive|define
name|DHU_OFF
value|DHU_LC_MODEM
end_define

begin_define
define|#
directive|define
name|DHU_DSR
value|(DHU_ST_DSR<< 16)
end_define

begin_define
define|#
directive|define
name|DHU_RNG
value|(DHU_ST_RI<< 16)
end_define

begin_define
define|#
directive|define
name|DHU_CAR
value|(DHU_ST_DCD<< 16)
end_define

begin_define
define|#
directive|define
name|DHU_CTS
value|(DHU_ST_CTS<< 16)
end_define

begin_define
define|#
directive|define
name|DHU_RTS
value|DHU_LC_RTS
end_define

begin_define
define|#
directive|define
name|DHU_DTR
value|DHU_LC_DTR
end_define

begin_define
define|#
directive|define
name|DHU_BRK
value|DHU_LC_BREAK
end_define

begin_define
define|#
directive|define
name|DHU_LE
value|DHU_LC_MODEM
end_define

begin_comment
comment|/* bits in dm lsr, copied from dmreg.h */
end_comment

begin_define
define|#
directive|define
name|DML_DSR
value|0000400
end_define

begin_comment
comment|/* data set ready, not a real DM bit */
end_comment

begin_define
define|#
directive|define
name|DML_RNG
value|0000200
end_define

begin_comment
comment|/* ring */
end_comment

begin_define
define|#
directive|define
name|DML_CAR
value|0000100
end_define

begin_comment
comment|/* carrier detect */
end_comment

begin_define
define|#
directive|define
name|DML_CTS
value|0000040
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|DML_SR
value|0000020
end_define

begin_comment
comment|/* secondary receive */
end_comment

begin_define
define|#
directive|define
name|DML_ST
value|0000010
end_define

begin_comment
comment|/* secondary transmit */
end_comment

begin_define
define|#
directive|define
name|DML_RTS
value|0000004
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|DML_DTR
value|0000002
end_define

begin_comment
comment|/* data terminal ready */
end_comment

begin_define
define|#
directive|define
name|DML_LE
value|0000001
end_define

begin_comment
comment|/* line enable */
end_comment

end_unit

