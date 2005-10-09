begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Defines for Cronyx-Sigma adapter driver.  *  * Copyright (C) 1994-2001 Cronyx Engineering.  * Author: Serge Vakulenko,<vak@cronyx.ru>  *  * Copyright (C) 1998-2003 Cronyx Engineering.  * Author: Roman Kurakin,<rik@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Cronyx Id: cxddk.h,v 1.1.2.1 2003/11/12 17:13:41 rik Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|port_t
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_M_ALPHA
end_ifdef

begin_comment
comment|/* port address on Alpha under */
end_comment

begin_define
define|#
directive|define
name|port_t
value|unsigned long
end_define

begin_comment
comment|/* Windows NT is 32 bit long */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|port_t
value|unsigned short
end_define

begin_comment
comment|/* all other architectures */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* have 16-bit port addresses */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NBRD
value|3
end_define

begin_comment
comment|/* the max number of installed boards */
end_comment

begin_define
define|#
directive|define
name|NPORT
value|32
end_define

begin_comment
comment|/* the number of i/o ports per board */
end_comment

begin_define
define|#
directive|define
name|DMABUFSZ
value|1600
end_define

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
comment|/* CRC invertion option */
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
comment|/* Board type */
end_comment

begin_define
define|#
directive|define
name|B_SIGMA_XXX
value|0
end_define

begin_comment
comment|/* old Sigmas */
end_comment

begin_define
define|#
directive|define
name|B_SIGMA_2X
value|1
end_define

begin_comment
comment|/* Sigma-22 */
end_comment

begin_define
define|#
directive|define
name|B_SIGMA_800
value|2
end_define

begin_comment
comment|/* Sigma-800 */
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

begin_define
define|#
directive|define
name|T_UNIV
value|8
end_define

begin_comment
comment|/* sync/async, unknown interface */
end_comment

begin_define
define|#
directive|define
name|M_ASYNC
value|0
end_define

begin_comment
comment|/* asynchronous mode */
end_comment

begin_define
define|#
directive|define
name|M_HDLC
value|1
end_define

begin_comment
comment|/* bit-sync mode (HDLC) */
end_comment

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
block|,
comment|/* stop sending break */
block|}
name|cx_break_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BUS_NORMAL
value|0
end_define

begin_comment
comment|/* normal bus timing */
end_comment

begin_define
define|#
directive|define
name|BUS_FAST
value|1
end_define

begin_comment
comment|/* fast bus timing (Sigma-22 and -800) */
end_comment

begin_define
define|#
directive|define
name|BUS_FAST2
value|2
end_define

begin_comment
comment|/* fast bus timing (Sigma-800) */
end_comment

begin_define
define|#
directive|define
name|BUS_FAST3
value|3
end_define

begin_comment
comment|/* fast bus timing (Sigma-800) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* board options */
name|unsigned
name|char
name|fast
decl_stmt|;
comment|/* bus master timing (Sigma-22 and -800) */
block|}
name|cx_board_opt_t
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
name|tbuffer
index|[
literal|2
index|]
index|[
name|DMABUFSZ
index|]
decl_stmt|;
name|unsigned
name|char
name|rbuffer
index|[
literal|2
index|]
index|[
name|DMABUFSZ
index|]
decl_stmt|;
block|}
name|cx_buf_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_cx_chan_t
block|{
name|struct
name|_cx_board_t
modifier|*
name|board
decl_stmt|;
comment|/* board pointer */
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
name|port_t
name|port
decl_stmt|;
comment|/* base port address */
name|unsigned
name|long
name|oscfreq
decl_stmt|;
comment|/* oscillator frequency in Hz */
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
name|unsigned
name|char
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
name|void
modifier|*
name|sys
decl_stmt|;
name|int
name|debug
decl_stmt|;
name|void
modifier|*
name|attach
index|[
literal|2
index|]
decl_stmt|;
name|char
modifier|*
name|received_data
decl_stmt|;
name|int
name|received_len
decl_stmt|;
name|int
name|overflow
decl_stmt|;
name|void
function_decl|(
modifier|*
name|call_on_rx
function_decl|)
parameter_list|(
name|struct
name|_cx_chan_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|call_on_tx
function_decl|)
parameter_list|(
name|struct
name|_cx_chan_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|call_on_msig
function_decl|)
parameter_list|(
name|struct
name|_cx_chan_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|call_on_err
function_decl|)
parameter_list|(
name|struct
name|_cx_chan_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
name|cx_chan_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_cx_board_t
block|{
name|unsigned
name|char
name|type
decl_stmt|;
comment|/* board type */
name|unsigned
name|char
name|num
decl_stmt|;
comment|/* board number, 0..2 */
name|port_t
name|port
decl_stmt|;
comment|/* base board port, 0..3f0 */
name|unsigned
name|char
name|irq
decl_stmt|;
comment|/* irq {3 5 7 10 11 12 15} */
name|unsigned
name|char
name|dma
decl_stmt|;
comment|/* DMA request {5 6 7} */
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
name|cx_board_opt_t
name|opt
decl_stmt|;
comment|/* board options */
name|cx_chan_t
name|chan
index|[
name|NCHAN
index|]
decl_stmt|;
comment|/* channel structures */
name|void
modifier|*
name|sys
decl_stmt|;
block|}
name|cx_board_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|long
name|cx_rxbaud
decl_stmt|,
name|cx_txbaud
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cx_univ_mode
decl_stmt|,
name|cx_sync_mode
decl_stmt|,
name|cx_iftype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cx_chan_opt_t
name|chan_opt_dflt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default mode-independent options */
end_comment

begin_decl_stmt
specifier|extern
name|cx_opt_async_t
name|opt_async_dflt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default async options */
end_comment

begin_decl_stmt
specifier|extern
name|cx_opt_hdlc_t
name|opt_hdlc_dflt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default hdlc options */
end_comment

begin_decl_stmt
specifier|extern
name|cx_board_opt_t
name|board_opt_dflt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default board options */
end_comment

begin_struct_decl
struct_decl|struct
name|_cr_dat_tst
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|cx_probe_board
parameter_list|(
name|port_t
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
name|cx_init
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|,
name|int
name|num
parameter_list|,
name|port_t
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
name|cx_init_board
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|,
name|int
name|num
parameter_list|,
name|port_t
name|port
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|dma
parameter_list|,
name|int
name|chain
parameter_list|,
name|int
name|rev
parameter_list|,
name|int
name|osc
parameter_list|,
name|int
name|mod
parameter_list|,
name|int
name|rev2
parameter_list|,
name|int
name|osc2
parameter_list|,
name|int
name|mod2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_init_2x
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|,
name|int
name|num
parameter_list|,
name|port_t
name|port
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|dma
parameter_list|,
name|int
name|rev
parameter_list|,
name|int
name|osc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_init_800
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|,
name|int
name|num
parameter_list|,
name|port_t
name|port
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|dma
parameter_list|,
name|int
name|chain
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_download
parameter_list|(
name|port_t
name|port
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|firmware
parameter_list|,
name|long
name|bits
parameter_list|,
specifier|const
name|struct
name|_cr_dat_tst
modifier|*
name|tst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_setup_board
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|firmware
parameter_list|,
name|long
name|bits
parameter_list|,
specifier|const
name|struct
name|_cr_dat_tst
modifier|*
name|tst
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
name|cx_update_chan
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_set_dtr
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
name|cx_set_rts
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
name|cx_led
parameter_list|(
name|cx_board_t
modifier|*
name|b
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
name|port_t
name|base
parameter_list|,
name|int
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_disable_dma
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_reinit_board
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_get_dsr
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_get_cts
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_get_cd
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

begin_comment
comment|/* DDK errors */
end_comment

begin_define
define|#
directive|define
name|CX_FRAME
value|1
end_define

begin_define
define|#
directive|define
name|CX_CRC
value|2
end_define

begin_define
define|#
directive|define
name|CX_OVERRUN
value|3
end_define

begin_define
define|#
directive|define
name|CX_OVERFLOW
value|4
end_define

begin_define
define|#
directive|define
name|CX_UNDERRUN
value|5
end_define

begin_define
define|#
directive|define
name|CX_BREAK
value|6
end_define

begin_comment
comment|/* clock sources */
end_comment

begin_define
define|#
directive|define
name|CX_CLK_INT
value|0
end_define

begin_define
define|#
directive|define
name|CX_CLK_EXT
value|6
end_define

begin_define
define|#
directive|define
name|CX_CLK_RCV
value|7
end_define

begin_define
define|#
directive|define
name|CX_CLK_DPLL
value|8
end_define

begin_define
define|#
directive|define
name|CX_CLK_DPLL_EXT
value|14
end_define

begin_comment
comment|/* functions dealing with interrupt vector in DOS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
end_if

begin_function_decl
name|int
name|ddk_int_alloc
parameter_list|(
name|int
name|irq
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddk_int_restore
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|cx_probe_irq
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|,
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_int_handler
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_find
parameter_list|(
name|port_t
modifier|*
name|board_ports
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_open_board
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|,
name|int
name|num
parameter_list|,
name|port_t
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
name|cx_close_board
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_start_chan
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|cx_buf_t
modifier|*
name|cb
parameter_list|,
name|unsigned
name|long
name|phys
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  Set port type for old models of Sigma  */
end_comment

begin_function_decl
name|void
name|cx_set_port
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|iftype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  Get port type for old models of Sigma  -1 Fixed port type or auto detect   0 RS232   1 V35   2 RS449  */
end_comment

begin_function_decl
name|int
name|cx_get_port
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_enable_receive
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
name|cx_enable_transmit
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
name|int
name|cx_receive_enabled
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_transmit_enabled
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_set_baud
parameter_list|(
name|cx_chan_t
modifier|*
parameter_list|,
name|unsigned
name|long
name|baud
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_set_mode
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_set_loop
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
name|cx_set_nrzi
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|nrzi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_set_dpll
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
name|unsigned
name|long
name|cx_get_baud
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_get_loop
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_get_nrzi
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_get_dpll
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_send_packet
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|,
name|void
modifier|*
name|attachment
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_buf_free
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_register_transmit
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|void
modifier|*
name|attachment
parameter_list|,
name|int
name|len
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_register_receive
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_register_modem
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_register_error
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|data
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_intr_off
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_intr_on
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cx_checkintr
parameter_list|(
name|cx_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Async functions */
end_comment

begin_function_decl
name|void
name|cx_transmitter_ctl
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_flush_transmit
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_xflow_ctl
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
name|cx_send_break
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|msec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cx_set_async_param
parameter_list|(
name|cx_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|baud
parameter_list|,
name|int
name|bits
parameter_list|,
name|int
name|parity
parameter_list|,
name|int
name|stop2
parameter_list|,
name|int
name|ignpar
parameter_list|,
name|int
name|rtscts
parameter_list|,
name|int
name|ixon
parameter_list|,
name|int
name|ixany
parameter_list|,
name|int
name|symstart
parameter_list|,
name|int
name|symstop
parameter_list|)
function_decl|;
end_function_decl

end_unit

