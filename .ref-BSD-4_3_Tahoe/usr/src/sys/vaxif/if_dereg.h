begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)if_dereg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * DEC DEUNA interface  */
end_comment

begin_struct
struct|struct
name|dedevice
block|{
union|union
block|{
name|short
name|p0_w
decl_stmt|;
name|char
name|p0_b
index|[
literal|2
index|]
decl_stmt|;
block|}
name|u_p0
union|;
define|#
directive|define
name|pcsr0
value|u_p0.p0_w
define|#
directive|define
name|pclow
value|u_p0.p0_b[0]
define|#
directive|define
name|pchigh
value|u_p0.p0_b[1]
name|short
name|pcsr1
decl_stmt|;
name|short
name|pcsr2
decl_stmt|;
name|short
name|pcsr3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * PCSR 0 bit descriptions  */
end_comment

begin_define
define|#
directive|define
name|PCSR0_SERI
value|0x8000
end_define

begin_comment
comment|/* Status error interrupt */
end_comment

begin_define
define|#
directive|define
name|PCSR0_PCEI
value|0x4000
end_define

begin_comment
comment|/* Port command error interrupt */
end_comment

begin_define
define|#
directive|define
name|PCSR0_RXI
value|0x2000
end_define

begin_comment
comment|/* Receive done interrupt */
end_comment

begin_define
define|#
directive|define
name|PCSR0_TXI
value|0x1000
end_define

begin_comment
comment|/* Transmit done interrupt */
end_comment

begin_define
define|#
directive|define
name|PCSR0_DNI
value|0x0800
end_define

begin_comment
comment|/* Done interrupt */
end_comment

begin_define
define|#
directive|define
name|PCSR0_RCBI
value|0x0400
end_define

begin_comment
comment|/* Receive buffer unavail intrpt */
end_comment

begin_define
define|#
directive|define
name|PCSR0_FATI
value|0x0100
end_define

begin_comment
comment|/* Fatal error interrupt */
end_comment

begin_define
define|#
directive|define
name|PCSR0_INTR
value|0x0080
end_define

begin_comment
comment|/* Interrupt summary */
end_comment

begin_define
define|#
directive|define
name|PCSR0_INTE
value|0x0040
end_define

begin_comment
comment|/* Interrupt enable */
end_comment

begin_define
define|#
directive|define
name|PCSR0_RSET
value|0x0020
end_define

begin_comment
comment|/* DEUNA reset */
end_comment

begin_define
define|#
directive|define
name|PCSR0_CMASK
value|0x000f
end_define

begin_comment
comment|/* command mask */
end_comment

begin_define
define|#
directive|define
name|PCSR0_BITS
value|"\20\20SERI\17PCEI\16RXI\15TXI\14DNI\13RCBI\11FATI\10INTR\7INTE\6RSET"
end_define

begin_comment
comment|/* bits 0-3 are for the PORT_COMMAND */
end_comment

begin_define
define|#
directive|define
name|CMD_NOOP
value|0x0
end_define

begin_define
define|#
directive|define
name|CMD_GETPCBB
value|0x1
end_define

begin_comment
comment|/* Get PCB Block */
end_comment

begin_define
define|#
directive|define
name|CMD_GETCMD
value|0x2
end_define

begin_comment
comment|/* Execute command in PCB */
end_comment

begin_define
define|#
directive|define
name|CMD_STEST
value|0x3
end_define

begin_comment
comment|/* Self test mode */
end_comment

begin_define
define|#
directive|define
name|CMD_START
value|0x4
end_define

begin_comment
comment|/* Reset xmit and receive ring ptrs */
end_comment

begin_define
define|#
directive|define
name|CMD_BOOT
value|0x5
end_define

begin_comment
comment|/* Boot DEUNA */
end_comment

begin_define
define|#
directive|define
name|CMD_PDMD
value|0x8
end_define

begin_comment
comment|/* Polling demand */
end_comment

begin_define
define|#
directive|define
name|CMD_TMRO
value|0x9
end_define

begin_comment
comment|/* Sanity timer on */
end_comment

begin_define
define|#
directive|define
name|CMD_TMRF
value|0xa
end_define

begin_comment
comment|/* Sanity timer off */
end_comment

begin_define
define|#
directive|define
name|CMD_RSTT
value|0xb
end_define

begin_comment
comment|/* Reset sanity timer */
end_comment

begin_define
define|#
directive|define
name|CMD_STOP
value|0xf
end_define

begin_comment
comment|/* Suspend operation */
end_comment

begin_comment
comment|/*  * PCSR 1 bit descriptions  */
end_comment

begin_define
define|#
directive|define
name|PCSR1_XPWR
value|0x8000
end_define

begin_comment
comment|/* Transceiver power BAD */
end_comment

begin_define
define|#
directive|define
name|PCSR1_ICAB
value|0x4000
end_define

begin_comment
comment|/* Interconnect cabling BAD */
end_comment

begin_define
define|#
directive|define
name|PCSR1_STCODE
value|0x3f00
end_define

begin_comment
comment|/* Self test error code */
end_comment

begin_define
define|#
directive|define
name|PCSR1_PCTO
value|0x0080
end_define

begin_comment
comment|/* Port command timed out */
end_comment

begin_define
define|#
directive|define
name|PCSR1_ILLINT
value|0x0040
end_define

begin_comment
comment|/* Illegal interrupt */
end_comment

begin_define
define|#
directive|define
name|PCSR1_TIMEOUT
value|0x0020
end_define

begin_comment
comment|/* Timeout */
end_comment

begin_define
define|#
directive|define
name|PCSR1_POWER
value|0x0010
end_define

begin_comment
comment|/* Power fail */
end_comment

begin_define
define|#
directive|define
name|PCSR1_RMTC
value|0x0008
end_define

begin_comment
comment|/* Remote console reserved */
end_comment

begin_define
define|#
directive|define
name|PCSR1_STMASK
value|0x0007
end_define

begin_comment
comment|/* State */
end_comment

begin_comment
comment|/* bit 0-3 are for STATE */
end_comment

begin_define
define|#
directive|define
name|STAT_RESET
value|0x0
end_define

begin_define
define|#
directive|define
name|STAT_PRIMLD
value|0x1
end_define

begin_comment
comment|/* Primary load */
end_comment

begin_define
define|#
directive|define
name|STAT_READY
value|0x2
end_define

begin_define
define|#
directive|define
name|STAT_RUN
value|0x3
end_define

begin_define
define|#
directive|define
name|STAT_UHALT
value|0x5
end_define

begin_comment
comment|/* UNIBUS halted */
end_comment

begin_define
define|#
directive|define
name|STAT_NIHALT
value|0x6
end_define

begin_comment
comment|/* NI halted */
end_comment

begin_define
define|#
directive|define
name|STAT_NIUHALT
value|0x7
end_define

begin_comment
comment|/* NI and UNIBUS Halted */
end_comment

begin_define
define|#
directive|define
name|PCSR1_BITS
value|"\20\20XPWR\17ICAB\10PCTO\7ILLINT\6TIMEOUT\5POWER\4RMTC"
end_define

begin_comment
comment|/*  * Port Control Block Base  */
end_comment

begin_struct
struct|struct
name|de_pcbb
block|{
name|short
name|pcbb0
decl_stmt|;
comment|/* function */
name|short
name|pcbb2
decl_stmt|;
comment|/* command specific */
name|short
name|pcbb4
decl_stmt|;
name|short
name|pcbb6
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* PCBB function codes */
end_comment

begin_define
define|#
directive|define
name|FC_NOOP
value|0x00
end_define

begin_comment
comment|/* NO-OP */
end_comment

begin_define
define|#
directive|define
name|FC_LSUADDR
value|0x01
end_define

begin_comment
comment|/* Load and start microaddress */
end_comment

begin_define
define|#
directive|define
name|FC_RDDEFAULT
value|0x02
end_define

begin_comment
comment|/* Read default physical address */
end_comment

begin_define
define|#
directive|define
name|FC_RDPHYAD
value|0x04
end_define

begin_comment
comment|/* Read physical address */
end_comment

begin_define
define|#
directive|define
name|FC_WTPHYAD
value|0x05
end_define

begin_comment
comment|/* Write physical address */
end_comment

begin_define
define|#
directive|define
name|FC_RDMULTI
value|0x06
end_define

begin_comment
comment|/* Read multicast address list */
end_comment

begin_define
define|#
directive|define
name|FC_WTMULTI
value|0x07
end_define

begin_comment
comment|/* Read multicast address list */
end_comment

begin_define
define|#
directive|define
name|FC_RDRING
value|0x08
end_define

begin_comment
comment|/* Read ring format */
end_comment

begin_define
define|#
directive|define
name|FC_WTRING
value|0x09
end_define

begin_comment
comment|/* Write ring format */
end_comment

begin_define
define|#
directive|define
name|FC_RDCNTS
value|0x0a
end_define

begin_comment
comment|/* Read counters */
end_comment

begin_define
define|#
directive|define
name|FC_RCCNTS
value|0x0b
end_define

begin_comment
comment|/* Read and clear counters */
end_comment

begin_define
define|#
directive|define
name|FC_RDMODE
value|0x0c
end_define

begin_comment
comment|/* Read mode */
end_comment

begin_define
define|#
directive|define
name|FC_WTMODE
value|0x0d
end_define

begin_comment
comment|/* Write mode */
end_comment

begin_define
define|#
directive|define
name|FC_RDSTATUS
value|0x0e
end_define

begin_comment
comment|/* Read port status */
end_comment

begin_define
define|#
directive|define
name|FC_RCSTATUS
value|0x0f
end_define

begin_comment
comment|/* Read and clear port status */
end_comment

begin_define
define|#
directive|define
name|FC_DUMPMEM
value|0x10
end_define

begin_comment
comment|/* Dump internal memory */
end_comment

begin_define
define|#
directive|define
name|FC_LOADMEM
value|0x11
end_define

begin_comment
comment|/* Load internal memory */
end_comment

begin_define
define|#
directive|define
name|FC_RDSYSID
value|0x12
end_define

begin_comment
comment|/* Read system ID parameters */
end_comment

begin_define
define|#
directive|define
name|FC_WTSYSID
value|0x13
end_define

begin_comment
comment|/* Write system ID parameters */
end_comment

begin_define
define|#
directive|define
name|FC_RDSERAD
value|0x14
end_define

begin_comment
comment|/* Read load server address */
end_comment

begin_define
define|#
directive|define
name|FC_WTSERAD
value|0x15
end_define

begin_comment
comment|/* Write load server address */
end_comment

begin_comment
comment|/*  * Unibus Data Block Base (UDBB) for ring buffers  */
end_comment

begin_struct
struct|struct
name|de_udbbuf
block|{
name|short
name|b_tdrbl
decl_stmt|;
comment|/* Transmit desc ring base low 16 bits */
name|char
name|b_tdrbh
decl_stmt|;
comment|/* Transmit desc ring base high 2 bits */
name|char
name|b_telen
decl_stmt|;
comment|/* Length of each transmit entry */
name|short
name|b_trlen
decl_stmt|;
comment|/* Number of entries in the XMIT desc ring */
name|short
name|b_rdrbl
decl_stmt|;
comment|/* Receive desc ring base low 16 bits */
name|char
name|b_rdrbh
decl_stmt|;
comment|/* Receive desc ring base high 2 bits */
name|char
name|b_relen
decl_stmt|;
comment|/* Length of each receive entry */
name|short
name|b_rrlen
decl_stmt|;
comment|/* Number of entries in the RECV desc ring */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Transmit/Receive Ring Entry  */
end_comment

begin_struct
struct|struct
name|de_ring
block|{
name|short
name|r_slen
decl_stmt|;
comment|/* Segment length */
name|short
name|r_segbl
decl_stmt|;
comment|/* Segment address (low 16 bits) */
name|char
name|r_segbh
decl_stmt|;
comment|/* Segment address (hi 2 bits) */
name|u_char
name|r_flags
decl_stmt|;
comment|/* Status flags */
name|u_short
name|r_tdrerr
decl_stmt|;
comment|/* Errors */
define|#
directive|define
name|r_lenerr
value|r_tdrerr
name|short
name|r_rid
decl_stmt|;
comment|/* Request ID */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XFLG_OWN
value|0x80
end_define

begin_comment
comment|/* If 0 then owned by driver */
end_comment

begin_define
define|#
directive|define
name|XFLG_ERRS
value|0x40
end_define

begin_comment
comment|/* Error summary */
end_comment

begin_define
define|#
directive|define
name|XFLG_MTCH
value|0x20
end_define

begin_comment
comment|/* Address match on xmit request */
end_comment

begin_define
define|#
directive|define
name|XFLG_MORE
value|0x10
end_define

begin_comment
comment|/* More than one entry required */
end_comment

begin_define
define|#
directive|define
name|XFLG_ONE
value|0x08
end_define

begin_comment
comment|/* One collision encountered */
end_comment

begin_define
define|#
directive|define
name|XFLG_DEF
value|0x04
end_define

begin_comment
comment|/* Transmit deferred */
end_comment

begin_define
define|#
directive|define
name|XFLG_STP
value|0x02
end_define

begin_comment
comment|/* Start of packet */
end_comment

begin_define
define|#
directive|define
name|XFLG_ENP
value|0x01
end_define

begin_comment
comment|/* End of packet */
end_comment

begin_define
define|#
directive|define
name|XFLG_BITS
value|"\10\10OWN\7ERRS\6MTCH\5MORE\4ONE\3DEF\2STP\1ENP"
end_define

begin_define
define|#
directive|define
name|XERR_BUFL
value|0x8000
end_define

begin_comment
comment|/* Buffer length error */
end_comment

begin_define
define|#
directive|define
name|XERR_UBTO
value|0x4000
end_define

begin_comment
comment|/* UNIBUS tiemout #define	XERR_LCOL	0x1000		/* Late collision */
end_comment

begin_define
define|#
directive|define
name|XERR_LCAR
value|0x0800
end_define

begin_comment
comment|/* Loss of carrier */
end_comment

begin_define
define|#
directive|define
name|XERR_RTRY
value|0x0400
end_define

begin_comment
comment|/* Failed after 16 retries */
end_comment

begin_define
define|#
directive|define
name|XERR_TDR
value|0x03ff
end_define

begin_comment
comment|/* TDR value */
end_comment

begin_define
define|#
directive|define
name|XERR_BITS
value|"\20\20BUFL\17UBTO\15LCOL\14LCAR\13RTRY"
end_define

begin_define
define|#
directive|define
name|RFLG_OWN
value|0x80
end_define

begin_comment
comment|/* If 0 then owned by driver */
end_comment

begin_define
define|#
directive|define
name|RFLG_ERRS
value|0x40
end_define

begin_comment
comment|/* Error summary */
end_comment

begin_define
define|#
directive|define
name|RFLG_FRAM
value|0x20
end_define

begin_comment
comment|/* Framing error */
end_comment

begin_define
define|#
directive|define
name|RFLG_OFLO
value|0x10
end_define

begin_comment
comment|/* Message overflow */
end_comment

begin_define
define|#
directive|define
name|RFLG_CRC
value|0x08
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|RFLG_STP
value|0x02
end_define

begin_comment
comment|/* Start of packet */
end_comment

begin_define
define|#
directive|define
name|RFLG_ENP
value|0x01
end_define

begin_comment
comment|/* End of packet */
end_comment

begin_define
define|#
directive|define
name|RFLG_BITS
value|"\10\10OWN\7ERRS\6FRAM\5OFLO\4CRC\2STP\1ENP"
end_define

begin_define
define|#
directive|define
name|RERR_BUFL
value|0x8000
end_define

begin_comment
comment|/* Buffer length error */
end_comment

begin_define
define|#
directive|define
name|RERR_UBTO
value|0x4000
end_define

begin_comment
comment|/* UNIBUS tiemout */
end_comment

begin_define
define|#
directive|define
name|RERR_NCHN
value|0x2000
end_define

begin_comment
comment|/* No data chaining */
end_comment

begin_define
define|#
directive|define
name|RERR_MLEN
value|0x0fff
end_define

begin_comment
comment|/* Message length */
end_comment

begin_define
define|#
directive|define
name|RERR_BITS
value|"\20\20BUFL\17UBTO\16NCHN"
end_define

begin_comment
comment|/* mode description bits */
end_comment

begin_define
define|#
directive|define
name|MOD_HDX
value|0x0001
end_define

begin_comment
comment|/* Half duplex mode */
end_comment

begin_define
define|#
directive|define
name|MOD_LOOP
value|0x0004
end_define

begin_comment
comment|/* Enable internal loopback */
end_comment

begin_define
define|#
directive|define
name|MOD_DTCR
value|0x0008
end_define

begin_comment
comment|/* Disables CRC generation */
end_comment

begin_define
define|#
directive|define
name|MOD_DMNT
value|0x0200
end_define

begin_comment
comment|/* Disable maintenance features */
end_comment

begin_define
define|#
directive|define
name|MOD_ECT
value|0x0400
end_define

begin_comment
comment|/* Enable collision test */
end_comment

begin_define
define|#
directive|define
name|MOD_TPAD
value|0x1000
end_define

begin_comment
comment|/* Transmit message pad enable */
end_comment

begin_define
define|#
directive|define
name|MOD_DRDC
value|0x2000
end_define

begin_comment
comment|/* Disable data chaining */
end_comment

begin_define
define|#
directive|define
name|MOD_ENAL
value|0x4000
end_define

begin_comment
comment|/* Enable all multicast */
end_comment

begin_define
define|#
directive|define
name|MOD_PROM
value|0x8000
end_define

begin_comment
comment|/* Enable promiscuous mode */
end_comment

begin_struct
struct|struct
name|de_buf
block|{
name|struct
name|ether_header
name|db_head
decl_stmt|;
comment|/* header */
name|char
name|db_data
index|[
name|ETHERMTU
index|]
decl_stmt|;
comment|/* packet data */
name|int
name|db_crc
decl_stmt|;
comment|/* CRC - on receive only */
block|}
struct|;
end_struct

end_unit

