begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Defines for Cronyx-Sigma adapter driver.  *  * Copyright (C) 1994 Cronyx Ltd.  * Author: Serge Vakulenko,<vak@zebub.msk.su>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organizations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Version 1.9, Wed Oct  4 18:58:15 MSK 1995  */
end_comment

begin_comment
comment|/*  * Asynchronous channel mode -------------------------------------------------  */
end_comment

begin_comment
comment|/* Parity */
end_comment

begin_define
define|#
directive|define
name|PAR_EVEN
value|0
end_define

begin_comment
comment|/* even parity */
end_comment

begin_define
define|#
directive|define
name|PAR_ODD
value|1
end_define

begin_comment
comment|/* odd parity */
end_comment

begin_comment
comment|/* Parity mode */
end_comment

begin_define
define|#
directive|define
name|PARM_NOPAR
value|0
end_define

begin_comment
comment|/* no parity */
end_comment

begin_define
define|#
directive|define
name|PARM_FORCE
value|1
end_define

begin_comment
comment|/* force parity (odd = force 1, even = 0) */
end_comment

begin_define
define|#
directive|define
name|PARM_NORMAL
value|2
end_define

begin_comment
comment|/* normal parity */
end_comment

begin_comment
comment|/* Flow control transparency mode */
end_comment

begin_define
define|#
directive|define
name|FLOWCC_PASS
value|0
end_define

begin_comment
comment|/* pass flow ctl chars as exceptions */
end_comment

begin_define
define|#
directive|define
name|FLOWCC_NOTPASS
value|1
end_define

begin_comment
comment|/* don't pass flow ctl chars to the host */
end_comment

begin_comment
comment|/* Stop bit length */
end_comment

begin_define
define|#
directive|define
name|STOPB_1
value|2
end_define

begin_comment
comment|/* 1 stop bit */
end_comment

begin_define
define|#
directive|define
name|STOPB_15
value|3
end_define

begin_comment
comment|/* 1.5 stop bits */
end_comment

begin_define
define|#
directive|define
name|STOPB_2
value|4
end_define

begin_comment
comment|/* 2 stop bits */
end_comment

begin_comment
comment|/* Action on break condition */
end_comment

begin_define
define|#
directive|define
name|BRK_INTR
value|0
end_define

begin_comment
comment|/* generate an exception interrupt */
end_comment

begin_define
define|#
directive|define
name|BRK_NULL
value|1
end_define

begin_comment
comment|/* translate to a NULL character */
end_comment

begin_define
define|#
directive|define
name|BRK_RESERVED
value|2
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|BRK_DISCARD
value|3
end_define

begin_comment
comment|/* discard character */
end_comment

begin_comment
comment|/* Parity/framing error actions */
end_comment

begin_define
define|#
directive|define
name|PERR_INTR
value|0
end_define

begin_comment
comment|/* generate an exception interrupt */
end_comment

begin_define
define|#
directive|define
name|PERR_NULL
value|1
end_define

begin_comment
comment|/* translate to a NULL character */
end_comment

begin_define
define|#
directive|define
name|PERR_IGNORE
value|2
end_define

begin_comment
comment|/* ignore error; char passed as good data */
end_comment

begin_define
define|#
directive|define
name|PERR_DISCARD
value|3
end_define

begin_comment
comment|/* discard error character */
end_comment

begin_define
define|#
directive|define
name|PERR_FFNULL
value|5
end_define

begin_comment
comment|/* translate to FF NULL char */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* async channel option register 1 */
name|unsigned
name|charlen
range|:
literal|4
decl_stmt|;
comment|/* character length, 5..8 */
name|unsigned
name|ignpar
range|:
literal|1
decl_stmt|;
comment|/* ignore parity */
name|unsigned
name|parmode
range|:
literal|2
decl_stmt|;
comment|/* parity mode */
name|unsigned
name|parity
range|:
literal|1
decl_stmt|;
comment|/* parity */
block|}
name|cx_cor1_async_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* async channel option register 2 */
name|unsigned
name|dsrae
range|:
literal|1
decl_stmt|;
comment|/* DSR automatic enable */
name|unsigned
name|ctsae
range|:
literal|1
decl_stmt|;
comment|/* CTS automatic enable */
name|unsigned
name|rtsao
range|:
literal|1
decl_stmt|;
comment|/* RTS automatic output enable */
name|unsigned
name|rlm
range|:
literal|1
decl_stmt|;
comment|/* remote loopback mode enable */
name|unsigned
name|zero
range|:
literal|1
decl_stmt|;
name|unsigned
name|etc
range|:
literal|1
decl_stmt|;
comment|/* embedded transmitter cmd enable */
name|unsigned
name|ixon
range|:
literal|1
decl_stmt|;
comment|/* in-band XON/XOFF enable */
name|unsigned
name|ixany
range|:
literal|1
decl_stmt|;
comment|/* XON on any character */
block|}
name|cx_cor2_async_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* async channel option register 3 */
name|unsigned
name|stopb
range|:
literal|3
decl_stmt|;
comment|/* stop bit length */
name|unsigned
name|zero
range|:
literal|1
decl_stmt|;
name|unsigned
name|scde
range|:
literal|1
decl_stmt|;
comment|/* special char detection enable */
name|unsigned
name|flowct
range|:
literal|1
decl_stmt|;
comment|/* flow control transparency mode */
name|unsigned
name|rngde
range|:
literal|1
decl_stmt|;
comment|/* range detect enable */
name|unsigned
name|escde
range|:
literal|1
decl_stmt|;
comment|/* extended spec. char detect enable */
block|}
name|cx_cor3_async_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* async channel option register 6 */
name|unsigned
name|parerr
range|:
literal|3
decl_stmt|;
comment|/* parity/framing error actions */
name|unsigned
name|brk
range|:
literal|2
decl_stmt|;
comment|/* action on break condition */
name|unsigned
name|inlcr
range|:
literal|1
decl_stmt|;
comment|/* translate NL to CR on input */
name|unsigned
name|icrnl
range|:
literal|1
decl_stmt|;
comment|/* translate CR to NL on input */
name|unsigned
name|igncr
range|:
literal|1
decl_stmt|;
comment|/* discard CR on input */
block|}
name|cx_cor6_async_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* async channel option register 7 */
name|unsigned
name|ocrnl
range|:
literal|1
decl_stmt|;
comment|/* translate CR to NL on output */
name|unsigned
name|onlcr
range|:
literal|1
decl_stmt|;
comment|/* translate NL to CR on output */
name|unsigned
name|zero
range|:
literal|3
decl_stmt|;
name|unsigned
name|fcerr
range|:
literal|1
decl_stmt|;
comment|/* process flow ctl err chars enable */
name|unsigned
name|lnext
range|:
literal|1
decl_stmt|;
comment|/* LNext option enable */
name|unsigned
name|istrip
range|:
literal|1
decl_stmt|;
comment|/* strip 8-bit on input */
block|}
name|cx_cor7_async_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* async channel options */
name|cx_cor1_async_t
name|cor1
decl_stmt|;
comment|/* channel option register 1 */
name|cx_cor2_async_t
name|cor2
decl_stmt|;
comment|/* channel option register 2 */
name|cx_cor3_async_t
name|cor3
decl_stmt|;
comment|/* option register 3 */
name|cx_cor6_async_t
name|cor6
decl_stmt|;
comment|/* channel option register 6 */
name|cx_cor7_async_t
name|cor7
decl_stmt|;
comment|/* channel option register 7 */
name|unsigned
name|char
name|schr1
decl_stmt|;
comment|/* special character register 1 (XON) */
name|unsigned
name|char
name|schr2
decl_stmt|;
comment|/* special character register 2 (XOFF) */
name|unsigned
name|char
name|schr3
decl_stmt|;
comment|/* special character register 3 */
name|unsigned
name|char
name|schr4
decl_stmt|;
comment|/* special character register 4 */
name|unsigned
name|char
name|scrl
decl_stmt|;
comment|/* special character range low */
name|unsigned
name|char
name|scrh
decl_stmt|;
comment|/* special character range high */
name|unsigned
name|char
name|lnxt
decl_stmt|;
comment|/* LNext character */
block|}
name|cx_opt_async_t
typedef|;
end_typedef

begin_comment
comment|/*  * HDLC channel mode ---------------------------------------------------------  */
end_comment

begin_comment
comment|/* Address field length option */
end_comment

begin_define
define|#
directive|define
name|AFLO_1OCT
value|0
end_define

begin_comment
comment|/* address field is 1 octet in length */
end_comment

begin_define
define|#
directive|define
name|AFLO_2OCT
value|1
end_define

begin_comment
comment|/* address field is 2 octet in length */
end_comment

begin_comment
comment|/* Clear detect for X.21 data transfer phase */
end_comment

begin_define
define|#
directive|define
name|CLRDET_DISABLE
value|0
end_define

begin_comment
comment|/* clear detect disabled */
end_comment

begin_define
define|#
directive|define
name|CLRDET_ENABLE
value|1
end_define

begin_comment
comment|/* clear detect enabled */
end_comment

begin_comment
comment|/* Addressing mode */
end_comment

begin_define
define|#
directive|define
name|ADMODE_NOADDR
value|0
end_define

begin_comment
comment|/* no address */
end_comment

begin_define
define|#
directive|define
name|ADMODE_4_1
value|1
end_define

begin_comment
comment|/* 4 * 1 byte */
end_comment

begin_define
define|#
directive|define
name|ADMODE_2_2
value|2
end_define

begin_comment
comment|/* 2 * 2 byte */
end_comment

begin_comment
comment|/* FCS append */
end_comment

begin_define
define|#
directive|define
name|FCS_NOTPASS
value|0
end_define

begin_comment
comment|/* receive CRC is not passed to the host */
end_comment

begin_define
define|#
directive|define
name|FCS_PASS
value|1
end_define

begin_comment
comment|/* receive CRC is passed to the host */
end_comment

begin_comment
comment|/* CRC modes */
end_comment

begin_define
define|#
directive|define
name|CRC_INVERT
value|0
end_define

begin_comment
comment|/* CRC is transmitted inverted (CRC V.41) */
end_comment

begin_define
define|#
directive|define
name|CRC_DONT_INVERT
value|1
end_define

begin_comment
comment|/* CRC is not transmitted inverted (CRC-16) */
end_comment

begin_comment
comment|/* Send sync pattern */
end_comment

begin_define
define|#
directive|define
name|SYNC_00
value|0
end_define

begin_comment
comment|/* send 00h as pad char (NRZI encoding) */
end_comment

begin_define
define|#
directive|define
name|SYNC_AA
value|1
end_define

begin_comment
comment|/* send AAh (Manchester/NRZ encoding) */
end_comment

begin_comment
comment|/* FCS preset */
end_comment

begin_define
define|#
directive|define
name|FCSP_ONES
value|0
end_define

begin_comment
comment|/* FCS is preset to all ones (CRC V.41) */
end_comment

begin_define
define|#
directive|define
name|FCSP_ZEROS
value|1
end_define

begin_comment
comment|/* FCS is preset to all zeros (CRC-16) */
end_comment

begin_comment
comment|/* idle mode */
end_comment

begin_define
define|#
directive|define
name|IDLE_FLAG
value|0
end_define

begin_comment
comment|/* idle in flag */
end_comment

begin_define
define|#
directive|define
name|IDLE_MARK
value|1
end_define

begin_comment
comment|/* idle in mark */
end_comment

begin_comment
comment|/* CRC polynomial select */
end_comment

begin_define
define|#
directive|define
name|POLY_V41
value|0
end_define

begin_comment
comment|/* x^16+x^12+x^5+1 (HDLC, preset to 1) */
end_comment

begin_define
define|#
directive|define
name|POLY_16
value|1
end_define

begin_comment
comment|/* x^16+x^15+x^2+1 (bisync, preset to 0) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* hdlc channel option register 1 */
name|unsigned
name|ifflags
range|:
literal|4
decl_stmt|;
comment|/* number of inter-frame flags sent */
name|unsigned
name|admode
range|:
literal|2
decl_stmt|;
comment|/* addressing mode */
name|unsigned
name|clrdet
range|:
literal|1
decl_stmt|;
comment|/* clear detect for X.21 data transfer phase */
name|unsigned
name|aflo
range|:
literal|1
decl_stmt|;
comment|/* address field length option */
block|}
name|cx_cor1_hdlc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* hdlc channel option register 2 */
name|unsigned
name|dsrae
range|:
literal|1
decl_stmt|;
comment|/* DSR automatic enable */
name|unsigned
name|ctsae
range|:
literal|1
decl_stmt|;
comment|/* CTS automatic enable */
name|unsigned
name|rtsao
range|:
literal|1
decl_stmt|;
comment|/* RTS automatic output enable */
name|unsigned
name|zero1
range|:
literal|1
decl_stmt|;
name|unsigned
name|crcninv
range|:
literal|1
decl_stmt|;
comment|/* CRC inversion option */
name|unsigned
name|zero2
range|:
literal|1
decl_stmt|;
name|unsigned
name|fcsapd
range|:
literal|1
decl_stmt|;
comment|/* FCS append */
name|unsigned
name|zero3
range|:
literal|1
decl_stmt|;
block|}
name|cx_cor2_hdlc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* hdlc channel option register 3 */
name|unsigned
name|padcnt
range|:
literal|3
decl_stmt|;
comment|/* pad character count */
name|unsigned
name|idle
range|:
literal|1
decl_stmt|;
comment|/* idle mode */
name|unsigned
name|nofcs
range|:
literal|1
decl_stmt|;
comment|/* FCS disable */
name|unsigned
name|fcspre
range|:
literal|1
decl_stmt|;
comment|/* FCS preset */
name|unsigned
name|syncpat
range|:
literal|1
decl_stmt|;
comment|/* send sync pattern */
name|unsigned
name|sndpad
range|:
literal|1
decl_stmt|;
comment|/* send pad characters before flag enable */
block|}
name|cx_cor3_hdlc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* hdlc channel options */
name|cx_cor1_hdlc_t
name|cor1
decl_stmt|;
comment|/* hdlc channel option register 1 */
name|cx_cor2_hdlc_t
name|cor2
decl_stmt|;
comment|/* hdlc channel option register 2 */
name|cx_cor3_hdlc_t
name|cor3
decl_stmt|;
comment|/* hdlc channel option register 3 */
name|unsigned
name|char
name|rfar1
decl_stmt|;
comment|/* receive frame address register 1 */
name|unsigned
name|char
name|rfar2
decl_stmt|;
comment|/* receive frame address register 2 */
name|unsigned
name|char
name|rfar3
decl_stmt|;
comment|/* receive frame address register 3 */
name|unsigned
name|char
name|rfar4
decl_stmt|;
comment|/* receive frame address register 4 */
name|unsigned
name|char
name|cpsr
decl_stmt|;
comment|/* CRC polynomial select */
block|}
name|cx_opt_hdlc_t
typedef|;
end_typedef

begin_comment
comment|/*  * BISYNC channel mode -------------------------------------------------------  */
end_comment

begin_comment
comment|/* Longitudinal redundancy check */
end_comment

begin_define
define|#
directive|define
name|BCC_CRC16
value|0
end_define

begin_comment
comment|/* CRC16 is used for BCC */
end_comment

begin_define
define|#
directive|define
name|BCC_LRC
value|1
end_define

begin_comment
comment|/* LRC is used for BCC */
end_comment

begin_comment
comment|/* Send pad pattern */
end_comment

begin_define
define|#
directive|define
name|PAD_AA
value|0
end_define

begin_comment
comment|/* send AAh as pad character */
end_comment

begin_define
define|#
directive|define
name|PAD_55
value|1
end_define

begin_comment
comment|/* send 55h as pad character */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* channel option register 1 */
name|unsigned
name|charlen
range|:
literal|4
decl_stmt|;
comment|/* character length, 5..8 */
name|unsigned
name|ignpar
range|:
literal|1
decl_stmt|;
comment|/* ignore parity */
name|unsigned
name|parmode
range|:
literal|2
decl_stmt|;
comment|/* parity mode */
name|unsigned
name|parity
range|:
literal|1
decl_stmt|;
comment|/* parity */
block|}
name|cx_cor1_bisync_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* channel option register 2 */
name|unsigned
name|syns
range|:
literal|4
decl_stmt|;
comment|/* number of extra SYN chars before a frame */
name|unsigned
name|crcninv
range|:
literal|1
decl_stmt|;
comment|/* CRC inversion option */
name|unsigned
name|ebcdic
range|:
literal|1
decl_stmt|;
comment|/* use EBCDIC as char set (instead of ASCII) */
name|unsigned
name|bcc
range|:
literal|1
decl_stmt|;
comment|/* BCC append enable */
name|unsigned
name|lrc
range|:
literal|1
decl_stmt|;
comment|/* longitudinal redundancy check */
block|}
name|cx_cor2_bisync_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* channel option register 3 */
name|unsigned
name|padcnt
range|:
literal|3
decl_stmt|;
comment|/* pad character count */
name|unsigned
name|idle
range|:
literal|1
decl_stmt|;
comment|/* idle mode */
name|unsigned
name|nofcs
range|:
literal|1
decl_stmt|;
comment|/* FCS disable */
name|unsigned
name|fcspre
range|:
literal|1
decl_stmt|;
comment|/* FCS preset */
name|unsigned
name|padpat
range|:
literal|1
decl_stmt|;
comment|/* send pad pattern */
name|unsigned
name|sndpad
range|:
literal|1
decl_stmt|;
comment|/* send pad characters before SYN enable */
block|}
name|cx_cor3_bisync_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* channel option register 6 */
name|unsigned
name|char
name|specterm
decl_stmt|;
comment|/* special termination character */
block|}
name|cx_cor6_bisync_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* bisync channel options */
name|cx_cor1_bisync_t
name|cor1
decl_stmt|;
comment|/* channel option register 1 */
name|cx_cor2_bisync_t
name|cor2
decl_stmt|;
comment|/* channel option register 2 */
name|cx_cor3_bisync_t
name|cor3
decl_stmt|;
comment|/* channel option register 3 */
name|cx_cor6_bisync_t
name|cor6
decl_stmt|;
comment|/* channel option register 6 */
name|unsigned
name|char
name|cpsr
decl_stmt|;
comment|/* CRC polynomial select */
block|}
name|cx_opt_bisync_t
typedef|;
end_typedef

begin_comment
comment|/*  * X.21 channel mode ---------------------------------------------------------  */
end_comment

begin_comment
comment|/* The number of SYN chars on receive */
end_comment

begin_define
define|#
directive|define
name|X21SYN_2
value|0
end_define

begin_comment
comment|/* two SYN characters are required */
end_comment

begin_define
define|#
directive|define
name|X21SYN_1
value|1
end_define

begin_comment
comment|/* one SYN character is required */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* channel option register 1 */
name|unsigned
name|charlen
range|:
literal|4
decl_stmt|;
comment|/* character length, 5..8 */
name|unsigned
name|ignpar
range|:
literal|1
decl_stmt|;
comment|/* ignore parity */
name|unsigned
name|parmode
range|:
literal|2
decl_stmt|;
comment|/* parity mode */
name|unsigned
name|parity
range|:
literal|1
decl_stmt|;
comment|/* parity */
block|}
name|cx_cor1_x21_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* channel option register 2 */
name|unsigned
name|zero1
range|:
literal|5
decl_stmt|;
name|unsigned
name|etc
range|:
literal|1
decl_stmt|;
comment|/* embedded transmitter command enable */
name|unsigned
name|zero2
range|:
literal|2
decl_stmt|;
block|}
name|cx_cor2_x21_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* channel option register 3 */
name|unsigned
name|zero
range|:
literal|4
decl_stmt|;
name|unsigned
name|scde
range|:
literal|1
decl_stmt|;
comment|/* special character detect enable */
name|unsigned
name|stripsyn
range|:
literal|1
decl_stmt|;
comment|/* treat SYN chars as special condition */
name|unsigned
name|ssde
range|:
literal|1
decl_stmt|;
comment|/* steady state detect enable */
name|unsigned
name|syn
range|:
literal|1
decl_stmt|;
comment|/* the number of SYN chars on receive */
block|}
name|cx_cor3_x21_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* channel option register 6 */
name|unsigned
name|char
name|synchar
decl_stmt|;
comment|/* syn character */
block|}
name|cx_cor6_x21_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* x21 channel options */
name|cx_cor1_x21_t
name|cor1
decl_stmt|;
comment|/* channel option register 1 */
name|cx_cor2_x21_t
name|cor2
decl_stmt|;
comment|/* channel option register 2 */
name|cx_cor3_x21_t
name|cor3
decl_stmt|;
comment|/* channel option register 3 */
name|cx_cor6_x21_t
name|cor6
decl_stmt|;
comment|/* channel option register 6 */
name|unsigned
name|char
name|schr1
decl_stmt|;
comment|/* special character register 1 */
name|unsigned
name|char
name|schr2
decl_stmt|;
comment|/* special character register 2 */
name|unsigned
name|char
name|schr3
decl_stmt|;
comment|/* special character register 3 */
block|}
name|cx_opt_x21_t
typedef|;
end_typedef

begin_comment
comment|/*  * CD2400 channel state structure --------------------------------------------  */
end_comment

begin_comment
comment|/* Signal encoding */
end_comment

begin_define
define|#
directive|define
name|ENCOD_NRZ
value|0
end_define

begin_comment
comment|/* NRZ mode */
end_comment

begin_define
define|#
directive|define
name|ENCOD_NRZI
value|1
end_define

begin_comment
comment|/* NRZI mode */
end_comment

begin_define
define|#
directive|define
name|ENCOD_MANCHESTER
value|2
end_define

begin_comment
comment|/* Manchester mode */
end_comment

begin_comment
comment|/* Clock source */
end_comment

begin_define
define|#
directive|define
name|CLK_0
value|0
end_define

begin_comment
comment|/* clock 0 */
end_comment

begin_define
define|#
directive|define
name|CLK_1
value|1
end_define

begin_comment
comment|/* clock 1 */
end_comment

begin_define
define|#
directive|define
name|CLK_2
value|2
end_define

begin_comment
comment|/* clock 2 */
end_comment

begin_define
define|#
directive|define
name|CLK_3
value|3
end_define

begin_comment
comment|/* clock 3 */
end_comment

begin_define
define|#
directive|define
name|CLK_4
value|4
end_define

begin_comment
comment|/* clock 4 */
end_comment

begin_define
define|#
directive|define
name|CLK_EXT
value|6
end_define

begin_comment
comment|/* external clock */
end_comment

begin_define
define|#
directive|define
name|CLK_RCV
value|7
end_define

begin_comment
comment|/* receive clock */
end_comment

begin_comment
comment|/* Channel type */
end_comment

begin_define
define|#
directive|define
name|T_NONE
value|0
end_define

begin_comment
comment|/* no channel */
end_comment

begin_define
define|#
directive|define
name|T_ASYNC
value|1
end_define

begin_comment
comment|/* pure asynchronous RS-232 channel */
end_comment

begin_define
define|#
directive|define
name|T_SYNC_RS232
value|2
end_define

begin_comment
comment|/* pure synchronous RS-232 channel */
end_comment

begin_define
define|#
directive|define
name|T_SYNC_V35
value|3
end_define

begin_comment
comment|/* pure synchronous V.35 channel */
end_comment

begin_define
define|#
directive|define
name|T_SYNC_RS449
value|4
end_define

begin_comment
comment|/* pure synchronous RS-449 channel */
end_comment

begin_define
define|#
directive|define
name|T_UNIV_RS232
value|5
end_define

begin_comment
comment|/* sync/async RS-232 channel */
end_comment

begin_define
define|#
directive|define
name|T_UNIV_RS449
value|6
end_define

begin_comment
comment|/* sync/async RS-232/RS-449 channel */
end_comment

begin_define
define|#
directive|define
name|T_UNIV_V35
value|7
end_define

begin_comment
comment|/* sync/async RS-232/V.35 channel */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* channel mode */
name|M_ASYNC
block|,
comment|/* asynchronous mode */
name|M_HDLC
block|,
comment|/* HDLC mode */
name|M_BISYNC
block|,
comment|/* BISYNC mode */
name|M_X21
comment|/* X.21 mode */
block|}
name|cx_chan_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* channel option register 4 */
name|unsigned
name|thr
range|:
literal|4
decl_stmt|;
comment|/* FIFO threshold */
name|unsigned
name|zero
range|:
literal|1
decl_stmt|;
name|unsigned
name|cts_zd
range|:
literal|1
decl_stmt|;
comment|/* detect 1 to 0 transition on the CTS */
name|unsigned
name|cd_zd
range|:
literal|1
decl_stmt|;
comment|/* detect 1 to 0 transition on the CD */
name|unsigned
name|dsr_zd
range|:
literal|1
decl_stmt|;
comment|/* detect 1 to 0 transition on the DSR */
block|}
name|cx_cor4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* channel option register 5 */
name|unsigned
name|rx_thr
range|:
literal|4
decl_stmt|;
comment|/* receive flow control FIFO threshold */
name|unsigned
name|zero
range|:
literal|1
decl_stmt|;
name|unsigned
name|cts_od
range|:
literal|1
decl_stmt|;
comment|/* detect 0 to 1 transition on the CTS */
name|unsigned
name|cd_od
range|:
literal|1
decl_stmt|;
comment|/* detect 0 to 1 transition on the CD */
name|unsigned
name|dsr_od
range|:
literal|1
decl_stmt|;
comment|/* detect 0 to 1 transition on the DSR */
block|}
name|cx_cor5_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* receive clock option register */
name|unsigned
name|clk
range|:
literal|3
decl_stmt|;
comment|/* receive clock source */
name|unsigned
name|encod
range|:
literal|2
decl_stmt|;
comment|/* signal encoding NRZ/NRZI/Manchester */
name|unsigned
name|dpll
range|:
literal|1
decl_stmt|;
comment|/* DPLL enable */
name|unsigned
name|zero
range|:
literal|1
decl_stmt|;
name|unsigned
name|tlval
range|:
literal|1
decl_stmt|;
comment|/* transmit line value */
block|}
name|cx_rcor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* transmit clock option register */
name|unsigned
name|zero1
range|:
literal|1
decl_stmt|;
name|unsigned
name|llm
range|:
literal|1
decl_stmt|;
comment|/* local loopback mode */
name|unsigned
name|zero2
range|:
literal|1
decl_stmt|;
name|unsigned
name|ext1x
range|:
literal|1
decl_stmt|;
comment|/* external 1x clock mode */
name|unsigned
name|zero3
range|:
literal|1
decl_stmt|;
name|unsigned
name|clk
range|:
literal|3
decl_stmt|;
comment|/* transmit clock source */
block|}
name|cx_tcor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|cx_cor4_t
name|cor4
decl_stmt|;
comment|/* channel option register 4 */
name|cx_cor5_t
name|cor5
decl_stmt|;
comment|/* channel option register 5 */
name|cx_rcor_t
name|rcor
decl_stmt|;
comment|/* receive clock option register */
name|cx_tcor_t
name|tcor
decl_stmt|;
comment|/* transmit clock option register */
block|}
name|cx_chan_opt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* line break mode */
name|BRK_IDLE
block|,
comment|/* normal line mode */
name|BRK_SEND
block|,
comment|/* start sending break */
name|BRK_STOP
comment|/* stop sending break */
block|}
name|cx_break_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|cisco
range|:
literal|1
decl_stmt|;
comment|/* cisco mode */
name|unsigned
name|keepalive
range|:
literal|1
decl_stmt|;
comment|/* keepalive enable */
name|unsigned
name|ext
range|:
literal|1
decl_stmt|;
comment|/* use external ppp implementation */
name|unsigned
name|lock
range|:
literal|1
decl_stmt|;
comment|/* channel locked for use by driver */
name|unsigned
name|norts
range|:
literal|1
decl_stmt|;
comment|/* disable automatic RTS control */
block|}
name|cx_soft_opt_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NCHIP
value|4
end_define

begin_comment
comment|/* the number of controllers per board */
end_comment

begin_define
define|#
directive|define
name|NCHAN
value|16
end_define

begin_comment
comment|/* the number of channels on the board */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|board
decl_stmt|;
comment|/* adapter number, 0..2 */
name|unsigned
name|char
name|channel
decl_stmt|;
comment|/* channel number, 0..15 */
name|unsigned
name|char
name|type
decl_stmt|;
comment|/* channel type (read only) */
name|unsigned
name|char
name|iftype
decl_stmt|;
comment|/* chan0 interface RS-232/RS-449/V.35 */
name|unsigned
name|long
name|rxbaud
decl_stmt|;
comment|/* receiver speed */
name|unsigned
name|long
name|txbaud
decl_stmt|;
comment|/* transmitter speed */
name|cx_chan_mode_t
name|mode
decl_stmt|;
comment|/* channel mode */
name|cx_chan_opt_t
name|opt
decl_stmt|;
comment|/* common channel options */
name|cx_opt_async_t
name|aopt
decl_stmt|;
comment|/* async mode options */
name|cx_opt_hdlc_t
name|hopt
decl_stmt|;
comment|/* hdlc mode options */
name|cx_opt_bisync_t
name|bopt
decl_stmt|;
comment|/* bisync mode options */
name|cx_opt_x21_t
name|xopt
decl_stmt|;
comment|/* x.21 mode options */
name|cx_soft_opt_t
name|sopt
decl_stmt|;
comment|/* software options and state flags */
name|char
name|master
index|[
literal|16
index|]
decl_stmt|;
comment|/* master interface name or \0 */
block|}
name|cx_options_t
typedef|;
end_typedef

begin_comment
comment|/* user settable options */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_chan_t
block|{
name|unsigned
name|char
name|type
decl_stmt|;
comment|/* channel type */
name|unsigned
name|char
name|num
decl_stmt|;
comment|/* channel number, 0..15 */
name|struct
name|_board_t
modifier|*
name|board
decl_stmt|;
comment|/* board pointer */
name|struct
name|_chip_t
modifier|*
name|chip
decl_stmt|;
comment|/* controller pointer */
name|struct
name|_stat_t
modifier|*
name|stat
decl_stmt|;
comment|/* statistics */
name|unsigned
name|long
name|rxbaud
decl_stmt|;
comment|/* receiver speed */
name|unsigned
name|long
name|txbaud
decl_stmt|;
comment|/* transmitter speed */
name|cx_chan_mode_t
name|mode
decl_stmt|;
comment|/* channel mode */
name|cx_chan_opt_t
name|opt
decl_stmt|;
comment|/* common channel options */
name|cx_opt_async_t
name|aopt
decl_stmt|;
comment|/* async mode options */
name|cx_opt_hdlc_t
name|hopt
decl_stmt|;
comment|/* hdlc mode options */
name|cx_opt_bisync_t
name|bopt
decl_stmt|;
comment|/* bisync mode options */
name|cx_opt_x21_t
name|xopt
decl_stmt|;
comment|/* x.21 mode options */
name|unsigned
name|char
modifier|*
name|arbuf
decl_stmt|;
comment|/* receiver A dma buffer */
name|unsigned
name|char
modifier|*
name|brbuf
decl_stmt|;
comment|/* receiver B dma buffer */
name|unsigned
name|char
modifier|*
name|atbuf
decl_stmt|;
comment|/* transmitter A dma buffer */
name|unsigned
name|char
modifier|*
name|btbuf
decl_stmt|;
comment|/* transmitter B dma buffer */
name|unsigned
name|long
name|arphys
decl_stmt|;
comment|/* receiver A phys address */
name|unsigned
name|long
name|brphys
decl_stmt|;
comment|/* receiver B phys address */
name|unsigned
name|long
name|atphys
decl_stmt|;
comment|/* transmitter A phys address */
name|unsigned
name|long
name|btphys
decl_stmt|;
comment|/* transmitter B phys address */
name|unsigned
name|char
name|dtr
decl_stmt|;
comment|/* DTR signal value */
name|unsigned
name|char
name|rts
decl_stmt|;
comment|/* RTS signal value */
ifdef|#
directive|ifdef
name|KERNEL
name|struct
name|tty
modifier|*
name|ttyp
decl_stmt|;
comment|/* tty structure pointer */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* network interface data */
name|struct
name|ifnet
modifier|*
name|master
decl_stmt|;
comment|/* master interface, or ==ifp */
name|struct
name|_chan_t
modifier|*
name|slaveq
decl_stmt|;
comment|/* slave queue pointer, or NULL */
name|cx_soft_opt_t
name|sopt
decl_stmt|;
comment|/* software options and state flags */
name|cx_break_t
name|brk
decl_stmt|;
comment|/* line break mode */
ifdef|#
directive|ifdef
name|__bsdi__
name|struct
name|ttydevice_tmp
modifier|*
name|ttydev
decl_stmt|;
comment|/* tty statistics structure */
endif|#
directive|endif
endif|#
directive|endif
block|}
name|cx_chan_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_chip_t
block|{
name|unsigned
name|short
name|port
decl_stmt|;
comment|/* base port address, or 0 if no chip */
name|unsigned
name|char
name|num
decl_stmt|;
comment|/* controller number, 0..3 */
name|struct
name|_board_t
modifier|*
name|board
decl_stmt|;
comment|/* board pointer */
name|unsigned
name|long
name|oscfreq
decl_stmt|;
comment|/* oscillator frequency in Hz */
block|}
name|cx_chip_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_stat_t
block|{
name|unsigned
name|char
name|board
decl_stmt|;
comment|/* adapter number, 0..2 */
name|unsigned
name|char
name|channel
decl_stmt|;
comment|/* channel number, 0..15 */
name|unsigned
name|long
name|rintr
decl_stmt|;
comment|/* receive interrupts */
name|unsigned
name|long
name|tintr
decl_stmt|;
comment|/* transmit interrupts */
name|unsigned
name|long
name|mintr
decl_stmt|;
comment|/* modem interrupts */
name|unsigned
name|long
name|ibytes
decl_stmt|;
comment|/* input bytes */
name|unsigned
name|long
name|ipkts
decl_stmt|;
comment|/* input packets */
name|unsigned
name|long
name|ierrs
decl_stmt|;
comment|/* input errors */
name|unsigned
name|long
name|obytes
decl_stmt|;
comment|/* output bytes */
name|unsigned
name|long
name|opkts
decl_stmt|;
comment|/* output packets */
name|unsigned
name|long
name|oerrs
decl_stmt|;
comment|/* output errors */
block|}
name|cx_stat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_board_t
block|{
name|unsigned
name|short
name|port
decl_stmt|;
comment|/* base board port, 0..3f0 */
name|unsigned
name|short
name|num
decl_stmt|;
comment|/* board number, 0..2 */
name|unsigned
name|char
name|irq
decl_stmt|;
comment|/* interrupt request {3 5 7 10 11 12 15} */
name|unsigned
name|char
name|dma
decl_stmt|;
comment|/* DMA request {5 6 7} */
name|unsigned
name|char
name|if0type
decl_stmt|;
comment|/* chan0 interface RS-232/RS-449/V.35 */
name|unsigned
name|char
name|if8type
decl_stmt|;
comment|/* chan8 interface RS-232/RS-449/V.35 */
name|unsigned
name|short
name|bcr0
decl_stmt|;
comment|/* BCR0 image */
name|unsigned
name|short
name|bcr0b
decl_stmt|;
comment|/* BCR0b image */
name|unsigned
name|short
name|bcr1
decl_stmt|;
comment|/* BCR1 image */
name|unsigned
name|short
name|bcr1b
decl_stmt|;
comment|/* BCR1b image */
name|cx_chip_t
name|chip
index|[
name|NCHIP
index|]
decl_stmt|;
comment|/* controller structures */
name|cx_chan_t
name|chan
index|[
name|NCHAN
index|]
decl_stmt|;
comment|/* channel structures */
name|cx_stat_t
name|stat
index|[
name|NCHAN
index|]
decl_stmt|;
comment|/* channel statistics */
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
comment|/* board version name */
name|unsigned
name|char
name|nuniv
decl_stmt|;
comment|/* number of universal channels */
name|unsigned
name|char
name|nsync
decl_stmt|;
comment|/* number of sync. channels */
name|unsigned
name|char
name|nasync
decl_stmt|;
comment|/* number of async. channels */
block|}
name|cx_board_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CX_SPEED_DFLT
value|9600
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|int
name|cx_probe_board
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_init
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|,
name|int
name|num
parameter_list|,
name|int
name|port
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|dma
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_setup_board
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_setup_chan
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_chan_dtr
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_chan_rts
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_cmd
parameter_list|(
name|int
name|base
parameter_list|,
name|int
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_chan_cd
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_clock
parameter_list|(
name|long
name|hz
parameter_list|,
name|long
name|ba
parameter_list|,
name|int
modifier|*
name|clk
parameter_list|,
name|int
modifier|*
name|div
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CXIOCGETMODE
value|_IOWR('x', 1, cx_options_t)
end_define

begin_comment
comment|/* get channel options */
end_comment

begin_define
define|#
directive|define
name|CXIOCSETMODE
value|_IOW('x', 2, cx_options_t)
end_define

begin_comment
comment|/* set channel options */
end_comment

begin_define
define|#
directive|define
name|CXIOCGETSTAT
value|_IOWR('x', 3, cx_stat_t)
end_define

begin_comment
comment|/* get channel stats */
end_comment

end_unit

