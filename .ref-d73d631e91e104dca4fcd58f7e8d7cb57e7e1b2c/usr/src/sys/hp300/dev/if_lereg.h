begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)if_lereg.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|LEID
value|21
end_define

begin_define
define|#
directive|define
name|LEMTU
value|1518
end_define

begin_define
define|#
directive|define
name|LEMINSIZE
value|60
end_define

begin_comment
comment|/* should be 64 if mode DTCR is set */
end_comment

begin_define
define|#
directive|define
name|LERBUF
value|8
end_define

begin_define
define|#
directive|define
name|LERBUFLOG2
value|3
end_define

begin_define
define|#
directive|define
name|LE_RLEN
value|(LERBUFLOG2<< 13)
end_define

begin_define
define|#
directive|define
name|LETBUF
value|1
end_define

begin_define
define|#
directive|define
name|LETBUFLOG2
value|0
end_define

begin_define
define|#
directive|define
name|LE_TLEN
value|(LETBUFLOG2<< 13)
end_define

begin_define
define|#
directive|define
name|vu_char
value|volatile u_char
end_define

begin_comment
comment|/*  * LANCE registers.  */
end_comment

begin_struct
struct|struct
name|lereg0
block|{
name|u_char
name|ler0_pad0
decl_stmt|;
name|vu_char
name|ler0_id
decl_stmt|;
comment|/* ID */
name|u_char
name|ler0_pad1
decl_stmt|;
name|vu_char
name|ler0_status
decl_stmt|;
comment|/* interrupt enable/status */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lereg1
block|{
name|u_short
name|ler1_rdp
decl_stmt|;
comment|/* data port */
name|u_short
name|ler1_rap
decl_stmt|;
comment|/* register select port */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Overlayed on 16K dual-port RAM.  * Current size is 13,758 bytes with 8 x 1518 receive buffers and  * 1 x 1518 transmit buffer.  */
end_comment

begin_struct
struct|struct
name|lereg2
block|{
comment|/* init block */
name|u_short
name|ler2_mode
decl_stmt|;
comment|/* +0x0000 */
name|u_char
name|ler2_padr
index|[
literal|6
index|]
decl_stmt|;
comment|/* +0x0002 */
name|u_long
name|ler2_ladrf0
decl_stmt|;
comment|/* +0x0008 */
name|u_long
name|ler2_ladrf1
decl_stmt|;
comment|/* +0x000C */
name|u_short
name|ler2_rdra
decl_stmt|;
comment|/* +0x0010 */
name|u_short
name|ler2_rlen
decl_stmt|;
comment|/* +0x0012 */
name|u_short
name|ler2_tdra
decl_stmt|;
comment|/* +0x0014 */
name|u_short
name|ler2_tlen
decl_stmt|;
comment|/* +0x0016 */
comment|/* receive message descriptors */
struct|struct
name|lermd
block|{
comment|/* +0x0018 */
name|u_short
name|rmd0
decl_stmt|;
name|u_short
name|rmd1
decl_stmt|;
name|short
name|rmd2
decl_stmt|;
name|u_short
name|rmd3
decl_stmt|;
block|}
name|ler2_rmd
index|[
name|LERBUF
index|]
struct|;
comment|/* transmit message descriptors */
struct|struct
name|letmd
block|{
comment|/* +0x0058 */
name|u_short
name|tmd0
decl_stmt|;
name|u_short
name|tmd1
decl_stmt|;
name|short
name|tmd2
decl_stmt|;
name|u_short
name|tmd3
decl_stmt|;
block|}
name|ler2_tmd
index|[
name|LETBUF
index|]
struct|;
name|char
name|ler2_rbuf
index|[
name|LERBUF
index|]
index|[
name|LEMTU
index|]
decl_stmt|;
comment|/* +0x0060 */
name|char
name|ler2_tbuf
index|[
name|LETBUF
index|]
index|[
name|LEMTU
index|]
decl_stmt|;
comment|/* +0x2FD0 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Control and status bits -- lereg0  */
end_comment

begin_define
define|#
directive|define
name|LE_IE
value|0x80
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|LE_IR
value|0x40
end_define

begin_comment
comment|/* interrupt requested */
end_comment

begin_define
define|#
directive|define
name|LE_LOCK
value|0x08
end_define

begin_comment
comment|/* lock status register */
end_comment

begin_define
define|#
directive|define
name|LE_ACK
value|0x04
end_define

begin_comment
comment|/* ack of lock */
end_comment

begin_define
define|#
directive|define
name|LE_JAB
value|0x02
end_define

begin_comment
comment|/* loss of tx clock (???) */
end_comment

begin_define
define|#
directive|define
name|LE_IPL
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 4)& 0x3) + 3)
end_define

begin_comment
comment|/*  * Control and status bits -- lereg1  */
end_comment

begin_define
define|#
directive|define
name|LE_CSR0
value|0
end_define

begin_define
define|#
directive|define
name|LE_CSR1
value|1
end_define

begin_define
define|#
directive|define
name|LE_CSR2
value|2
end_define

begin_define
define|#
directive|define
name|LE_CSR3
value|3
end_define

begin_define
define|#
directive|define
name|LE_SERR
value|0x8000
end_define

begin_define
define|#
directive|define
name|LE_BABL
value|0x4000
end_define

begin_define
define|#
directive|define
name|LE_CERR
value|0x2000
end_define

begin_define
define|#
directive|define
name|LE_MISS
value|0x1000
end_define

begin_define
define|#
directive|define
name|LE_MERR
value|0x0800
end_define

begin_define
define|#
directive|define
name|LE_RINT
value|0x0400
end_define

begin_define
define|#
directive|define
name|LE_TINT
value|0x0200
end_define

begin_define
define|#
directive|define
name|LE_IDON
value|0x0100
end_define

begin_define
define|#
directive|define
name|LE_INTR
value|0x0080
end_define

begin_define
define|#
directive|define
name|LE_INEA
value|0x0040
end_define

begin_define
define|#
directive|define
name|LE_RXON
value|0x0020
end_define

begin_define
define|#
directive|define
name|LE_TXON
value|0x0010
end_define

begin_define
define|#
directive|define
name|LE_TDMD
value|0x0008
end_define

begin_define
define|#
directive|define
name|LE_STOP
value|0x0004
end_define

begin_define
define|#
directive|define
name|LE_STRT
value|0x0002
end_define

begin_define
define|#
directive|define
name|LE_INIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|LE_BSWP
value|0x4
end_define

begin_define
define|#
directive|define
name|LE_MODE
value|0x0
end_define

begin_comment
comment|/*  * Control and status bits -- lereg2  */
end_comment

begin_define
define|#
directive|define
name|LE_OWN
value|0x8000
end_define

begin_define
define|#
directive|define
name|LE_ERR
value|0x4000
end_define

begin_define
define|#
directive|define
name|LE_STP
value|0x0200
end_define

begin_define
define|#
directive|define
name|LE_ENP
value|0x0100
end_define

begin_define
define|#
directive|define
name|LE_FRAM
value|0x2000
end_define

begin_define
define|#
directive|define
name|LE_OFLO
value|0x1000
end_define

begin_define
define|#
directive|define
name|LE_CRC
value|0x0800
end_define

begin_define
define|#
directive|define
name|LE_RBUFF
value|0x0400
end_define

begin_define
define|#
directive|define
name|LE_MORE
value|0x1000
end_define

begin_define
define|#
directive|define
name|LE_ONE
value|0x0800
end_define

begin_define
define|#
directive|define
name|LE_DEF
value|0x0400
end_define

begin_define
define|#
directive|define
name|LE_TBUFF
value|0x8000
end_define

begin_define
define|#
directive|define
name|LE_UFLO
value|0x4000
end_define

begin_define
define|#
directive|define
name|LE_LCOL
value|0x1000
end_define

begin_define
define|#
directive|define
name|LE_LCAR
value|0x0800
end_define

begin_define
define|#
directive|define
name|LE_RTRY
value|0x0400
end_define

end_unit

