begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dmxreg.h	7.1 (Berkeley) %G%  *  * Common structures and definitions  * for merged DMF and DMZ drivers.  */
end_comment

begin_comment
comment|/*  * Hardware registers per octet of asynchronous lines  */
end_comment

begin_struct
struct|struct
name|dmx_octet
block|{
name|short
name|csr
decl_stmt|;
comment|/* control-status register */
name|short
name|lpr
decl_stmt|;
comment|/* line parameter register */
name|short
name|rbuf
decl_stmt|;
comment|/* receiver buffer (ro) */
union|union
block|{
name|u_short
name|irw
decl_stmt|;
comment|/* indirect register word */
name|u_char
name|irc
index|[
literal|2
index|]
decl_stmt|;
comment|/*    "         "    bytes */
block|}
name|octun
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rsp
value|rbuf
end_define

begin_comment
comment|/* receive silo parameter register (wo) */
end_comment

begin_define
define|#
directive|define
name|tbuf
value|octun.irc[0]
end_define

begin_comment
comment|/* transmit buffer */
end_comment

begin_define
define|#
directive|define
name|tsc
value|octun.irc[0]
end_define

begin_comment
comment|/* transmit silo count */
end_comment

begin_define
define|#
directive|define
name|rmstsc
value|octun.irw
end_define

begin_comment
comment|/* rcv modem status, xmit silo count */
end_comment

begin_define
define|#
directive|define
name|rms
value|octun.irc[1]
end_define

begin_comment
comment|/* receive modem status */
end_comment

begin_define
define|#
directive|define
name|lctms
value|octun.irw
end_define

begin_comment
comment|/* line control, transmit modem status */
end_comment

begin_define
define|#
directive|define
name|tba
value|octun.irw
end_define

begin_comment
comment|/* transmit buffer address */
end_comment

begin_define
define|#
directive|define
name|tcc
value|octun.irw
end_define

begin_comment
comment|/* transmit character count */
end_comment

begin_comment
comment|/* bits in dmfcsr */
end_comment

begin_define
define|#
directive|define
name|DMF_TI
value|0100000
end_define

begin_comment
comment|/* transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|DMF_TIE
value|0040000
end_define

begin_comment
comment|/* transmit interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DMF_NXM
value|0030000
end_define

begin_comment
comment|/* non-existent memory (which bit?) */
end_comment

begin_define
define|#
directive|define
name|DMF_LIN
value|0003400
end_define

begin_comment
comment|/* transmit line number */
end_comment

begin_define
define|#
directive|define
name|DMF_RI
value|0000200
end_define

begin_comment
comment|/* receiver interrupt */
end_comment

begin_define
define|#
directive|define
name|DMF_RIE
value|0000100
end_define

begin_comment
comment|/* receiver interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DMF_CLR
value|0000040
end_define

begin_comment
comment|/* master reset */
end_comment

begin_define
define|#
directive|define
name|DMF_IAD
value|0000037
end_define

begin_comment
comment|/* indirect address register */
end_comment

begin_define
define|#
directive|define
name|DMF_IE
value|(DMF_TIE|DMF_RIE)
end_define

begin_define
define|#
directive|define
name|DMFIR_RMSTSC
value|000
end_define

begin_comment
comment|/* select rmstsc indirect register */
end_comment

begin_define
define|#
directive|define
name|DMFIR_TBUF
value|000
end_define

begin_comment
comment|/* select tbuf indirect register */
end_comment

begin_define
define|#
directive|define
name|DMFIR_LCR
value|010
end_define

begin_comment
comment|/* select lcr indirect register */
end_comment

begin_define
define|#
directive|define
name|DMFIR_TBA
value|020
end_define

begin_comment
comment|/* select tba indirect register */
end_comment

begin_define
define|#
directive|define
name|DMFIR_TCC
value|030
end_define

begin_comment
comment|/* select tcc indirect register */
end_comment

begin_comment
comment|/* bits in dmflpr */
end_comment

begin_define
define|#
directive|define
name|BITS6
value|0010
end_define

begin_comment
comment|/* 6 bits per character */
end_comment

begin_define
define|#
directive|define
name|BITS7
value|0020
end_define

begin_comment
comment|/* 7 bits per character */
end_comment

begin_define
define|#
directive|define
name|BITS8
value|0030
end_define

begin_comment
comment|/* 8 bits per character */
end_comment

begin_define
define|#
directive|define
name|PENABLE
value|0040
end_define

begin_comment
comment|/* parity enable */
end_comment

begin_define
define|#
directive|define
name|EPAR
value|0100
end_define

begin_comment
comment|/* even parity */
end_comment

begin_define
define|#
directive|define
name|TWOSB
value|0200
end_define

begin_comment
comment|/* two stop bits */
end_comment

begin_define
define|#
directive|define
name|DMF_SILOCNT
value|32
end_define

begin_comment
comment|/* size of DMF output silo (per line) */
end_comment

begin_comment
comment|/* bits in dmfrbuf */
end_comment

begin_define
define|#
directive|define
name|DMF_DSC
value|0004000
end_define

begin_comment
comment|/* data set change */
end_comment

begin_define
define|#
directive|define
name|DMF_PE
value|0010000
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|DMF_FE
value|0020000
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|DMF_DO
value|0040000
end_define

begin_comment
comment|/* data overrun */
end_comment

begin_comment
comment|/* bits in dmfrmstsc */
end_comment

begin_define
define|#
directive|define
name|DMF_TSC
value|0x00ff
end_define

begin_comment
comment|/* transmit silo count */
end_comment

begin_define
define|#
directive|define
name|DMF_USRR
value|0x0400
end_define

begin_comment
comment|/* user modem signal (pin 25) */
end_comment

begin_define
define|#
directive|define
name|DMF_SR
value|0x0800
end_define

begin_comment
comment|/* secondary receive */
end_comment

begin_define
define|#
directive|define
name|DMF_CTS
value|0x1000
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|DMF_CAR
value|0x2000
end_define

begin_comment
comment|/* carrier detect */
end_comment

begin_define
define|#
directive|define
name|DMF_RNG
value|0x4000
end_define

begin_comment
comment|/* ring */
end_comment

begin_define
define|#
directive|define
name|DMF_DSR
value|0x8000
end_define

begin_comment
comment|/* data set ready */
end_comment

begin_comment
comment|/* bits in dmflctms (tms half) */
end_comment

begin_define
define|#
directive|define
name|DMF_USRW
value|0x0100
end_define

begin_comment
comment|/* user modem signal (pin 18) */
end_comment

begin_define
define|#
directive|define
name|DMF_DTR
value|0x0200
end_define

begin_comment
comment|/* data terminal ready */
end_comment

begin_define
define|#
directive|define
name|DMF_RATE
value|0x0400
end_define

begin_comment
comment|/* data signal rate select */
end_comment

begin_define
define|#
directive|define
name|DMF_SRTS
value|0x0800
end_define

begin_comment
comment|/* secondary request to send (dmf) */
end_comment

begin_define
define|#
directive|define
name|DMF_RTS
value|0x1000
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|DMF_PREEMPT
value|0x8000
end_define

begin_comment
comment|/* preempt output */
end_comment

begin_comment
comment|/* bits in dmflctms (lc half) */
end_comment

begin_define
define|#
directive|define
name|DMF_MIE
value|0040
end_define

begin_comment
comment|/* modem interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DMF_FLUSH
value|0020
end_define

begin_comment
comment|/* flush transmit silo */
end_comment

begin_define
define|#
directive|define
name|DMF_BRK
value|0010
end_define

begin_comment
comment|/* send break bit */
end_comment

begin_define
define|#
directive|define
name|DMF_RE
value|0004
end_define

begin_comment
comment|/* receive enable */
end_comment

begin_define
define|#
directive|define
name|DMF_AUTOX
value|0002
end_define

begin_comment
comment|/* auto XON/XOFF */
end_comment

begin_define
define|#
directive|define
name|DMF_TE
value|0001
end_define

begin_comment
comment|/* transmit enable */
end_comment

begin_define
define|#
directive|define
name|DMF_ENA
value|(DMF_MIE|DMF_RE|DMF_TE)
end_define

begin_comment
comment|/* flags for modem control */
end_comment

begin_define
define|#
directive|define
name|DMF_ON
value|(DMF_DTR|DMF_RTS|DMF_ENA)
end_define

begin_define
define|#
directive|define
name|DMF_OFF
value|0
end_define

begin_comment
comment|/* bits added to dm lsr for DMGET/DMSET */
end_comment

begin_define
define|#
directive|define
name|DML_USR
value|0001000
end_define

begin_comment
comment|/* usr modem sig, not a real DM bit */
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

end_unit

