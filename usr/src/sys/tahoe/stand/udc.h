begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	udc.h	1.2	86/01/05	*/
end_comment

begin_struct
struct|struct
name|UDPAC
block|{
comment|/* UDC command packet */
name|char
name|_stx
decl_stmt|;
name|char
name|_pkid
decl_stmt|;
name|char
name|_pksiz
decl_stmt|;
comment|/* 21  bytes */
name|char
name|_pkdev
decl_stmt|;
comment|/* device # */
name|char
name|_pkcmd
decl_stmt|;
comment|/* Command type */
name|char
name|_pkfnc
decl_stmt|;
comment|/* Function type */
name|short
name|_pkcnt
decl_stmt|;
comment|/* # of data blocks (1/4K each) */
name|short
name|_pbsiz
decl_stmt|;
comment|/* Block length size (0x100 = 1/4K) */
name|short
name|_pkmem
index|[
literal|2
index|]
decl_stmt|;
comment|/* Starting memory address.Should be 'long' but 				   we can't write it this way on Tahoe, 				   because of alignment problems - the C 				   will gap after the previous 'short' */
name|short
name|_pcksm
decl_stmt|;
comment|/* Checksum (unused) */
name|long
name|_psecno
decl_stmt|;
comment|/* Starting sector # */
name|char
name|_etx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SECTSIZ
value|256
end_define

begin_comment
comment|/* sector size */
end_comment

begin_define
define|#
directive|define
name|L2SIZ
value|8
end_define

begin_comment
comment|/* log2 of sector size */
end_comment

begin_define
define|#
directive|define
name|L2BSIZ
value|10
end_define

begin_comment
comment|/* log2 of block size */
end_comment

begin_define
define|#
directive|define
name|NUDC
value|1
end_define

begin_comment
comment|/* number of UDC controllers */
end_comment

begin_define
define|#
directive|define
name|NUNIT
value|8
end_define

begin_comment
comment|/* number of units per controller */
end_comment

begin_define
define|#
directive|define
name|NUDDRV
value|5
end_define

begin_comment
comment|/* number of drive types supported */
end_comment

begin_define
define|#
directive|define
name|DK_N
value|1
end_define

begin_comment
comment|/* Monitoring device bit */
end_comment

begin_comment
comment|/* **	Block devices sizes structure */
end_comment

begin_struct
struct|struct
name|size
block|{
name|daddr_t
name|nblocks
decl_stmt|;
name|int
name|block0
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|udaddr
value|( (char *)(0xff0000+IOBASE) )
end_define

begin_define
define|#
directive|define
name|INT
value|0x00d
end_define

begin_comment
comment|/* interrupt offset */
end_comment

begin_define
define|#
directive|define
name|RST
value|0x00f
end_define

begin_comment
comment|/* controller reset offset */
end_comment

begin_define
define|#
directive|define
name|OB1
value|0x101
end_define

begin_define
define|#
directive|define
name|OB2
value|0x103
end_define

begin_define
define|#
directive|define
name|IB1
value|0x181
end_define

begin_define
define|#
directive|define
name|IB2
value|0x183
end_define

begin_define
define|#
directive|define
name|PKID
value|0x187
end_define

begin_comment
comment|/* packet id */
end_comment

begin_define
define|#
directive|define
name|PKLEN
value|0x189
end_define

begin_comment
comment|/* packet length */
end_comment

begin_define
define|#
directive|define
name|PKDEV
value|0x18b
end_define

begin_comment
comment|/* device # */
end_comment

begin_define
define|#
directive|define
name|PKCMD
value|0x18d
end_define

begin_comment
comment|/* command type */
end_comment

begin_define
define|#
directive|define
name|PKSTT
value|0x18f
end_define

begin_comment
comment|/* status type */
end_comment

begin_define
define|#
directive|define
name|STAT1
value|0x191
end_define

begin_comment
comment|/* i/o status result offset */
end_comment

begin_define
define|#
directive|define
name|STAT2
value|0x193
end_define

begin_define
define|#
directive|define
name|DEVSTAT1
value|0x195
end_define

begin_define
define|#
directive|define
name|DEVSTAT2
value|0x197
end_define

begin_define
define|#
directive|define
name|DEVSIZE
value|0x199
end_define

begin_comment
comment|/* # of sectors in device status message */
end_comment

begin_define
define|#
directive|define
name|UDREAD
value|0x10
end_define

begin_define
define|#
directive|define
name|UDWTRY
value|0x01
end_define

begin_comment
comment|/* read with retry */
end_comment

begin_define
define|#
directive|define
name|UDWRITE
value|0x20
end_define

begin_define
define|#
directive|define
name|UDWCRC
value|0x01
end_define

begin_comment
comment|/* write sectors and check CRC */
end_comment

begin_define
define|#
directive|define
name|UDWSECT
value|0x02
end_define

begin_comment
comment|/* write sectors */
end_comment

begin_define
define|#
directive|define
name|UDTEST
value|0x30
end_define

begin_define
define|#
directive|define
name|UDSTAT
value|0x02
end_define

begin_comment
comment|/* Test status */
end_comment

begin_define
define|#
directive|define
name|DEVRDY
value|0x80
end_define

begin_comment
comment|/* device ready bit in status byte */
end_comment

begin_define
define|#
directive|define
name|DEVTYPE
value|0x7
end_define

begin_comment
comment|/* bits 0-2 in status byte define device */
end_comment

begin_define
define|#
directive|define
name|FLP
value|0x1
end_define

begin_define
define|#
directive|define
name|HARDDISK
value|0x2
end_define

begin_define
define|#
directive|define
name|TAPE
value|0x5
end_define

begin_comment
comment|/*  Some I/O addresses used to generate pulses for scopes */
end_comment

begin_define
define|#
directive|define
name|OUT1
value|0xffffb034
end_define

begin_define
define|#
directive|define
name|OUT2
value|0xffffb018
end_define

begin_define
define|#
directive|define
name|OUT3
value|0xffffb020
end_define

begin_define
define|#
directive|define
name|OUT4
value|0xffffb004
end_define

begin_define
define|#
directive|define
name|OUT5
value|0xffffb024
end_define

begin_define
define|#
directive|define
name|OUT6
value|0xffffb00c
end_define

begin_define
define|#
directive|define
name|OUT7
value|0xffffb02c
end_define

begin_define
define|#
directive|define
name|IN1
value|0xffffb030
end_define

begin_define
define|#
directive|define
name|IN2
value|0xffffb03c
end_define

begin_define
define|#
directive|define
name|IN3
value|0xffffb004
end_define

begin_define
define|#
directive|define
name|IN4
value|0xffffb00c
end_define

begin_define
define|#
directive|define
name|IN5
value|0xffffb02c
end_define

begin_decl_stmt
name|int
name|dummy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|vmem
index|[]
index|[
literal|16
operator|*
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IOaddr
parameter_list|(
name|off
parameter_list|)
value|(caddr_t)((int)vmem + ((off)& 0x0fffff))
end_define

begin_decl_stmt
name|int
name|iospace_mapped
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|scope_out
parameter_list|(
name|x
parameter_list|)
value|if(iospace_mapped) movob(IOaddr(OUT
comment|/**/
value|x),0)
end_define

begin_define
define|#
directive|define
name|scope_in
parameter_list|(
name|x
parameter_list|)
value|if(iospace_mapped) dummy =  *IOaddr(IN
comment|/**/
value|x)
end_define

end_unit

