begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: lancereg.h,v 4.300 91/06/09 06:26:05 root Rel41 $ SONY  *  *	@(#)lancereg.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|lance
block|{
name|u_short
name|rdp
decl_stmt|;
comment|/* data port			*/
name|u_short
name|rap
decl_stmt|;
comment|/* address port			*/
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Control and status registers  */
end_comment

begin_define
define|#
directive|define
name|CSR0
value|0
end_define

begin_define
define|#
directive|define
name|CSR1
value|1
end_define

begin_define
define|#
directive|define
name|CSR2
value|2
end_define

begin_define
define|#
directive|define
name|CSR3
value|3
end_define

begin_comment
comment|/*  *	CSR0  */
end_comment

begin_define
define|#
directive|define
name|CSR_ERR
value|0x8000
end_define

begin_comment
comment|/* BABL|CERR|MISS|MERR		*/
end_comment

begin_define
define|#
directive|define
name|CSR_BABL
value|0x4000
end_define

begin_comment
comment|/* transmitter timeout error	*/
end_comment

begin_define
define|#
directive|define
name|CSR_CERR
value|0x2000
end_define

begin_comment
comment|/* collision error		*/
end_comment

begin_define
define|#
directive|define
name|CSR_MISS
value|0x1000
end_define

begin_comment
comment|/* missed packet		*/
end_comment

begin_define
define|#
directive|define
name|CSR_MERR
value|0x0800
end_define

begin_comment
comment|/* memory error			*/
end_comment

begin_define
define|#
directive|define
name|CSR_RINT
value|0x0400
end_define

begin_comment
comment|/* receiver interrupt		*/
end_comment

begin_define
define|#
directive|define
name|CSR_TINT
value|0x0200
end_define

begin_comment
comment|/* transmitter interrupt	*/
end_comment

begin_define
define|#
directive|define
name|CSR_IDON
value|0x0100
end_define

begin_comment
comment|/* initailization done		*/
end_comment

begin_define
define|#
directive|define
name|CSR_INTR
value|0x0080
end_define

begin_comment
comment|/* BABL|MISS|MERR|RINT|TINT|IDON */
end_comment

begin_define
define|#
directive|define
name|CSR_INEA
value|0x0040
end_define

begin_comment
comment|/* interrupt enable		*/
end_comment

begin_define
define|#
directive|define
name|CSR_RXON
value|0x0020
end_define

begin_comment
comment|/* receiver on			*/
end_comment

begin_define
define|#
directive|define
name|CSR_TXON
value|0x0010
end_define

begin_comment
comment|/* transmitter on		*/
end_comment

begin_define
define|#
directive|define
name|CSR_TDMD
value|0x0008
end_define

begin_comment
comment|/* transmit demand		*/
end_comment

begin_define
define|#
directive|define
name|CSR_STOP
value|0x0004
end_define

begin_comment
comment|/* disable chip			*/
end_comment

begin_define
define|#
directive|define
name|CSR_STRT
value|0x0002
end_define

begin_comment
comment|/* enable chip			*/
end_comment

begin_define
define|#
directive|define
name|CSR_INIT
value|0x0001
end_define

begin_comment
comment|/* initialize			*/
end_comment

begin_comment
comment|/*  *	CSR3  */
end_comment

begin_define
define|#
directive|define
name|CSR_BSWP
value|0x0004
end_define

begin_comment
comment|/* byte swap			*/
end_comment

begin_define
define|#
directive|define
name|CSR_ACON
value|0x0002
end_define

begin_comment
comment|/* ALE control			*/
end_comment

begin_define
define|#
directive|define
name|CSR_BCON
value|0x0001
end_define

begin_comment
comment|/* byte control			*/
end_comment

begin_comment
comment|/*  *	Initialization block  */
end_comment

begin_struct
struct|struct
name|init_block
block|{
name|u_short
name|ib_mode
decl_stmt|;
name|u_char
name|ib_padr
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|ib_ladrf
index|[
literal|8
index|]
decl_stmt|;
name|u_short
name|ib_rdra
decl_stmt|;
name|u_short
name|ib_rlen_rdra
decl_stmt|;
name|u_short
name|ib_tdra
decl_stmt|;
name|u_short
name|ib_tlen_tdra
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IB_PROM
value|0x8000
end_define

begin_comment
comment|/* promiscuous mode		*/
end_comment

begin_define
define|#
directive|define
name|IB_INTL
value|0x0040
end_define

begin_comment
comment|/* internal loopback		*/
end_comment

begin_define
define|#
directive|define
name|IB_DRTY
value|0x0020
end_define

begin_comment
comment|/* disable retry		*/
end_comment

begin_define
define|#
directive|define
name|IB_COLL
value|0x0010
end_define

begin_comment
comment|/* force collision		*/
end_comment

begin_define
define|#
directive|define
name|IB_DTCR
value|0x0008
end_define

begin_comment
comment|/* disable transmit CRC		*/
end_comment

begin_define
define|#
directive|define
name|IB_LOOP
value|0x0004
end_define

begin_comment
comment|/* loopback			*/
end_comment

begin_define
define|#
directive|define
name|IB_DTX
value|0x0002
end_define

begin_comment
comment|/* disable the transmitter	*/
end_comment

begin_define
define|#
directive|define
name|IB_DRX
value|0x0001
end_define

begin_comment
comment|/* disable the receiver		*/
end_comment

begin_comment
comment|/*  *	Descriptor rings  */
end_comment

begin_comment
comment|/*  *	Receive message descriptor  */
end_comment

begin_struct
struct|struct
name|recv_msg_desc
block|{
name|u_short
name|rmd_ladr
decl_stmt|;
name|u_short
name|rmd_stat
decl_stmt|;
name|u_short
name|rmd_bcnt
decl_stmt|;
name|u_short
name|rmd_mcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RMD_OWN
value|0x8000
end_define

begin_comment
comment|/* owned by lance		*/
end_comment

begin_define
define|#
directive|define
name|RMD_ERR
value|0x4000
end_define

begin_comment
comment|/* FRAM|OFLO|CRC|BUFF		*/
end_comment

begin_define
define|#
directive|define
name|RMD_FRAM
value|0x2000
end_define

begin_comment
comment|/* framing error		*/
end_comment

begin_define
define|#
directive|define
name|RMD_OFLO
value|0x1000
end_define

begin_comment
comment|/* overflow			*/
end_comment

begin_define
define|#
directive|define
name|RMD_CRC
value|0x0800
end_define

begin_comment
comment|/* CRC error			*/
end_comment

begin_define
define|#
directive|define
name|RMD_BUFF
value|0x0400
end_define

begin_comment
comment|/* buffer error			*/
end_comment

begin_define
define|#
directive|define
name|RMD_STP
value|0x0200
end_define

begin_comment
comment|/* start op packet		*/
end_comment

begin_define
define|#
directive|define
name|RMD_ENP
value|0x0100
end_define

begin_comment
comment|/* end of packet		*/
end_comment

begin_define
define|#
directive|define
name|RMD_HADR
value|0x00ff
end_define

begin_comment
comment|/* high order 8 bit of buffer address */
end_comment

begin_comment
comment|/*  *	Transmit message descriptor  */
end_comment

begin_struct
struct|struct
name|xmit_msg_desc
block|{
name|u_short
name|tmd_ladr
decl_stmt|;
name|u_short
name|tmd_stat
decl_stmt|;
name|u_short
name|tmd_bcnt
decl_stmt|;
name|u_short
name|tmd_error
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TMD_OWN
value|0x8000
end_define

begin_comment
comment|/* owned by lance		*/
end_comment

begin_define
define|#
directive|define
name|TMD_ERR
value|0x4000
end_define

begin_comment
comment|/* LCOL|LCAR|UFLO|RTRY		*/
end_comment

begin_define
define|#
directive|define
name|TMD_MORE
value|0x1000
end_define

begin_comment
comment|/* more than one retry		*/
end_comment

begin_define
define|#
directive|define
name|TMD_ONE
value|0x0800
end_define

begin_comment
comment|/* one retry			*/
end_comment

begin_define
define|#
directive|define
name|TMD_DEF
value|0x0400
end_define

begin_comment
comment|/* deferred			*/
end_comment

begin_define
define|#
directive|define
name|TMD_STP
value|0x0200
end_define

begin_comment
comment|/* start of packet		*/
end_comment

begin_define
define|#
directive|define
name|TMD_ENP
value|0x0100
end_define

begin_comment
comment|/* end of packet		*/
end_comment

begin_define
define|#
directive|define
name|TMD_HADR
value|0x00ff
end_define

begin_comment
comment|/* high order 8 bit of buffer address */
end_comment

begin_define
define|#
directive|define
name|TMD_BUFF
value|0x8000
end_define

begin_comment
comment|/* buffer error			*/
end_comment

begin_define
define|#
directive|define
name|TMD_UFLO
value|0x4000
end_define

begin_comment
comment|/* underflow error		*/
end_comment

begin_define
define|#
directive|define
name|TMD_LCOL
value|0x1000
end_define

begin_comment
comment|/* late collision		*/
end_comment

begin_define
define|#
directive|define
name|TMD_LCAR
value|0x0800
end_define

begin_comment
comment|/* loss of carrier		*/
end_comment

begin_define
define|#
directive|define
name|TMD_RTRY
value|0x0400
end_define

begin_comment
comment|/* retry error			*/
end_comment

begin_define
define|#
directive|define
name|TMD_TDR
value|0x00ff
end_define

begin_comment
comment|/* time domain refrectometry	*/
end_comment

end_unit

