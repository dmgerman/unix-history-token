begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)if_dmc.h	7.3 (Berkeley) 5/26/88  */
end_comment

begin_comment
comment|/*  * DMC-11 Interface  */
end_comment

begin_struct
struct|struct
name|dmcdevice
block|{
name|char
name|bsel0
decl_stmt|;
name|char
name|bsel1
decl_stmt|;
name|char
name|bsel2
decl_stmt|;
name|char
name|bsel3
decl_stmt|;
name|short
name|sel4
decl_stmt|;
name|short
name|sel6
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * dmc software packet encapsulation.  This allows the dmc  * link to be multiplexed among several protocols.  * The first eight bytes of the dmc header are garbage,  * since on a vax the uba has been known to mung these  * bytes.  The next two bytes encapsulate packet type.  */
end_comment

begin_struct
struct|struct
name|dmc_header
block|{
name|char
name|dmc_buf
index|[
literal|8
index|]
decl_stmt|;
comment|/* space for uba on vax */
name|short
name|dmc_type
decl_stmt|;
comment|/* encapsulate packet type */
block|}
struct|;
end_struct

begin_comment
comment|/* packet types */
end_comment

begin_define
define|#
directive|define
name|DMC_IPTYPE
value|1
end_define

begin_define
define|#
directive|define
name|DMC_TRAILER
value|2
end_define

begin_define
define|#
directive|define
name|DMC_NTRAILER
value|16
end_define

begin_comment
comment|/*  * DMCMTU includes space for data (1024) +   * protocol header (256) + trailer descriptor (4).  * The software link encapsulation header (dmc_header)  * is handled separately. 	#define DMCMTU  1284  */
end_comment

begin_define
define|#
directive|define
name|DMCMTU
value|1500
end_define

begin_define
define|#
directive|define
name|RDYSCAN
value|16
end_define

begin_comment
comment|/* loop delay for RDYI after RQI */
end_comment

begin_comment
comment|/* defines for bsel0 */
end_comment

begin_define
define|#
directive|define
name|DMC_BACCI
value|0
end_define

begin_define
define|#
directive|define
name|DMC_CNTLI
value|1
end_define

begin_define
define|#
directive|define
name|DMC_PERR
value|2
end_define

begin_define
define|#
directive|define
name|DMC_BASEI
value|3
end_define

begin_define
define|#
directive|define
name|DMC_WRITE
value|0
end_define

begin_comment
comment|/* transmit block */
end_comment

begin_define
define|#
directive|define
name|DMC_READ
value|4
end_define

begin_comment
comment|/* read block */
end_comment

begin_define
define|#
directive|define
name|DMC_RQI
value|0040
end_define

begin_comment
comment|/* port request bit */
end_comment

begin_define
define|#
directive|define
name|DMC_IEI
value|0100
end_define

begin_comment
comment|/* enable input interrupts */
end_comment

begin_define
define|#
directive|define
name|DMC_RDYI
value|0200
end_define

begin_comment
comment|/* port ready */
end_comment

begin_define
define|#
directive|define
name|DMC0BITS
value|"\10\10RDI\7IEI\6RQI"
end_define

begin_comment
comment|/* defines for bsel1 */
end_comment

begin_define
define|#
directive|define
name|DMC_MCLR
value|0100
end_define

begin_comment
comment|/* DMC11 Master Clear */
end_comment

begin_define
define|#
directive|define
name|DMC_RUN
value|0200
end_define

begin_comment
comment|/* clock running */
end_comment

begin_define
define|#
directive|define
name|DMC1BITS
value|"\10\10RUN\7MCLR"
end_define

begin_comment
comment|/* defines for bsel2 */
end_comment

begin_define
define|#
directive|define
name|DMC_BACCO
value|0
end_define

begin_define
define|#
directive|define
name|DMC_CNTLO
value|1
end_define

begin_define
define|#
directive|define
name|DMC_OUX
value|0
end_define

begin_comment
comment|/* transmit block */
end_comment

begin_define
define|#
directive|define
name|DMC_OUR
value|4
end_define

begin_comment
comment|/* read block */
end_comment

begin_define
define|#
directive|define
name|DMC_IEO
value|0100
end_define

begin_comment
comment|/* enable output interrupts */
end_comment

begin_define
define|#
directive|define
name|DMC_RDYO
value|0200
end_define

begin_comment
comment|/* port available */
end_comment

begin_define
define|#
directive|define
name|DMC2BITS
value|"\10\10RDO\7IEO"
end_define

begin_comment
comment|/* defines for CNTLI mode */
end_comment

begin_define
define|#
directive|define
name|DMC_HDPLX
value|02000
end_define

begin_comment
comment|/* half duplex DDCMP operation */
end_comment

begin_define
define|#
directive|define
name|DMC_SEC
value|04000
end_define

begin_comment
comment|/* half duplex secondary station */
end_comment

begin_define
define|#
directive|define
name|DMC_MAINT
value|00400
end_define

begin_comment
comment|/* enter maintenance mode */
end_comment

begin_comment
comment|/* defines for BACCI/O and BASEI mode */
end_comment

begin_define
define|#
directive|define
name|DMC_XMEM
value|0140000
end_define

begin_comment
comment|/* xmem bit position */
end_comment

begin_define
define|#
directive|define
name|DMC_CCOUNT
value|0037777
end_define

begin_comment
comment|/* character count mask */
end_comment

begin_define
define|#
directive|define
name|DMC_RESUME
value|0002000
end_define

begin_comment
comment|/* resume (BASEI only) */
end_comment

begin_comment
comment|/* defines for CNTLO */
end_comment

begin_define
define|#
directive|define
name|DMC_CNTMASK
value|01777
end_define

begin_define
define|#
directive|define
name|DMC_DATACK
value|01
end_define

begin_define
define|#
directive|define
name|DMC_TIMEOUT
value|02
end_define

begin_define
define|#
directive|define
name|DMC_NOBUFS
value|04
end_define

begin_define
define|#
directive|define
name|DMC_MAINTREC
value|010
end_define

begin_define
define|#
directive|define
name|DMC_LOSTDATA
value|020
end_define

begin_define
define|#
directive|define
name|DMC_DISCONN
value|0100
end_define

begin_define
define|#
directive|define
name|DMC_START
value|0200
end_define

begin_define
define|#
directive|define
name|DMC_NEXMEM
value|0400
end_define

begin_define
define|#
directive|define
name|DMC_ERROR
value|01000
end_define

begin_define
define|#
directive|define
name|DMC_FATAL
value|(DMC_ERROR|DMC_NEXMEM|DMC_START|DMC_LOSTDATA|DMC_MAINTREC)
end_define

begin_define
define|#
directive|define
name|CNTLO_BITS
define|\
value|"\10\12ERROR\11NEXMEM\10START\7DISC\5LSTDATA\4MAINT\3NOBUF\2TIMEO\1DATACK"
end_define

end_unit

