begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Ioctl interface to Cronyx serial drivers.  *  * Copyright (C) 1997-2002 Cronyx Engineering.  * Author: Serge Vakulenko,<vak@cronyx.ru>  *  * Copyright (C) 2001-2005 Cronyx Engineering.  * Author: Roman Kurakin,<rik@FreeBSD.org>  *  * Copyright (C) 2004-2005 Cronyx Engineering.  * Author: Leo Yuriev,<ly@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Cronyx Id: cserial.h,v 1.4.2.2 2005/11/09 13:01:35 rik Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * General channel statistics.  */
end_comment

begin_struct
struct|struct
name|serial_statistics
block|{
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
struct|;
end_struct

begin_comment
comment|/*  * Statistics for E1/G703 channels.  */
end_comment

begin_struct
struct|struct
name|e1_counters
block|{
name|unsigned
name|long
name|bpv
decl_stmt|;
comment|/* bipolar violations */
name|unsigned
name|long
name|fse
decl_stmt|;
comment|/* frame sync errors */
name|unsigned
name|long
name|crce
decl_stmt|;
comment|/* CRC errors */
name|unsigned
name|long
name|rcrce
decl_stmt|;
comment|/* remote CRC errors (E-bit) */
name|unsigned
name|long
name|uas
decl_stmt|;
comment|/* unavailable seconds */
name|unsigned
name|long
name|les
decl_stmt|;
comment|/* line errored seconds */
name|unsigned
name|long
name|es
decl_stmt|;
comment|/* errored seconds */
name|unsigned
name|long
name|bes
decl_stmt|;
comment|/* bursty errored seconds */
name|unsigned
name|long
name|ses
decl_stmt|;
comment|/* severely errored seconds */
name|unsigned
name|long
name|oofs
decl_stmt|;
comment|/* out of frame seconds */
name|unsigned
name|long
name|css
decl_stmt|;
comment|/* controlled slip seconds */
name|unsigned
name|long
name|dm
decl_stmt|;
comment|/* degraded minutes */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e1_statistics
block|{
name|unsigned
name|long
name|status
decl_stmt|;
comment|/* line status bit mask */
name|unsigned
name|long
name|cursec
decl_stmt|;
comment|/* seconds in current interval */
name|unsigned
name|long
name|totsec
decl_stmt|;
comment|/* total seconds elapsed */
name|struct
name|e1_counters
name|currnt
decl_stmt|;
comment|/* current 15-min interval data */
name|struct
name|e1_counters
name|total
decl_stmt|;
comment|/* total statistics data */
name|struct
name|e1_counters
name|interval
index|[
literal|48
index|]
decl_stmt|;
comment|/* 12 hour period data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e3_statistics
block|{
name|unsigned
name|long
name|status
decl_stmt|;
name|unsigned
name|long
name|cursec
decl_stmt|;
name|unsigned
name|long
name|totsec
decl_stmt|;
name|unsigned
name|long
name|ccv
decl_stmt|;
name|unsigned
name|long
name|tcv
decl_stmt|;
name|unsigned
name|long
name|icv
index|[
literal|48
index|]
decl_stmt|;
block|}
struct|;
end_struct

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

begin_define
define|#
directive|define
name|M_G703
value|2
end_define

begin_define
define|#
directive|define
name|M_E1
value|3
end_define

begin_comment
comment|/*  * Receive error codes.  */
end_comment

begin_define
define|#
directive|define
name|ER_FRAMING
value|1
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|ER_CHECKSUM
value|2
end_define

begin_comment
comment|/* parity/CRC error */
end_comment

begin_define
define|#
directive|define
name|ER_BREAK
value|3
end_define

begin_comment
comment|/* break state */
end_comment

begin_define
define|#
directive|define
name|ER_OVERFLOW
value|4
end_define

begin_comment
comment|/* receive buffer overflow */
end_comment

begin_define
define|#
directive|define
name|ER_OVERRUN
value|5
end_define

begin_comment
comment|/* receive fifo overrun */
end_comment

begin_define
define|#
directive|define
name|ER_UNDERRUN
value|6
end_define

begin_comment
comment|/* transmit fifo underrun */
end_comment

begin_define
define|#
directive|define
name|ER_SCC_FRAMING
value|7
end_define

begin_comment
comment|/* subchannel framing error */
end_comment

begin_define
define|#
directive|define
name|ER_SCC_OVERFLOW
value|8
end_define

begin_comment
comment|/* subchannel receive buffer overflow */
end_comment

begin_define
define|#
directive|define
name|ER_SCC_OVERRUN
value|9
end_define

begin_comment
comment|/* subchannel receiver overrun */
end_comment

begin_define
define|#
directive|define
name|ER_SCC_UNDERRUN
value|10
end_define

begin_comment
comment|/* subchannel transmiter underrun */
end_comment

begin_define
define|#
directive|define
name|ER_BUS
value|11
end_define

begin_comment
comment|/* system bus is too busy (e.g PCI) */
end_comment

begin_comment
comment|/*  * E1 channel status.  */
end_comment

begin_define
define|#
directive|define
name|E1_NOALARM
value|0x0001
end_define

begin_comment
comment|/* no alarm present */
end_comment

begin_define
define|#
directive|define
name|E1_FARLOF
value|0x0002
end_define

begin_comment
comment|/* receiving far loss of framing */
end_comment

begin_define
define|#
directive|define
name|E1_CRC4E
value|0x0004
end_define

begin_comment
comment|/* crc4 errors */
end_comment

begin_define
define|#
directive|define
name|E1_AIS
value|0x0008
end_define

begin_comment
comment|/* receiving all ones */
end_comment

begin_define
define|#
directive|define
name|E1_LOF
value|0x0020
end_define

begin_comment
comment|/* loss of framing */
end_comment

begin_define
define|#
directive|define
name|E1_LOS
value|0x0040
end_define

begin_comment
comment|/* loss of signal */
end_comment

begin_define
define|#
directive|define
name|E1_AIS16
value|0x0100
end_define

begin_comment
comment|/* receiving all ones in timeslot 16 */
end_comment

begin_define
define|#
directive|define
name|E1_FARLOMF
value|0x0200
end_define

begin_comment
comment|/* receiving alarm in timeslot 16 */
end_comment

begin_define
define|#
directive|define
name|E1_LOMF
value|0x0400
end_define

begin_comment
comment|/* loss of multiframe sync */
end_comment

begin_define
define|#
directive|define
name|E1_TSTREQ
value|0x0800
end_define

begin_comment
comment|/* test code detected */
end_comment

begin_define
define|#
directive|define
name|E1_TSTERR
value|0x1000
end_define

begin_comment
comment|/* test error */
end_comment

begin_define
define|#
directive|define
name|E3_LOS
value|0x00000002
end_define

begin_comment
comment|/* Lost of synchronization */
end_comment

begin_define
define|#
directive|define
name|E3_TXE
value|0x00000004
end_define

begin_comment
comment|/* Transmit error */
end_comment

begin_comment
comment|/*  * Query the mask of all registered channels, max 128.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETREGISTERED
value|_IOR ('x', 0, char[16])
end_define

begin_comment
comment|/*  * Attach/detach the protocol to the channel.  * The protocol is given by it's name, char[8].  * For example "async", "hdlc", "cisco", "fr", "ppp".  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETPROTO
value|_IOR ('x', 1, char [8])
end_define

begin_define
define|#
directive|define
name|SERIAL_SETPROTO
value|_IOW ('x', 1, char [8])
end_define

begin_comment
comment|/*  * Query/set the hardware mode for the channel.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETMODE
value|_IOR ('x', 2, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETMODE
value|_IOW ('x', 2, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_ASYNC
value|1
end_define

begin_define
define|#
directive|define
name|SERIAL_HDLC
value|2
end_define

begin_define
define|#
directive|define
name|SERIAL_RAW
value|3
end_define

begin_comment
comment|/*  * Get/clear the channel statistics.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETSTAT
value|_IOR ('x', 3, struct serial_statistics)
end_define

begin_define
define|#
directive|define
name|SERIAL_GETESTAT
value|_IOR ('x', 3, struct e1_statistics)
end_define

begin_define
define|#
directive|define
name|SERIAL_GETE3STAT
value|_IOR ('x', 3, struct e3_statistics)
end_define

begin_define
define|#
directive|define
name|SERIAL_CLRSTAT
value|_IO  ('x', 3)
end_define

begin_comment
comment|/*  * Query/set the synchronization mode and baud rate.  * If baud==0 then the external clock is used.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETBAUD
value|_IOR ('x', 4, long)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETBAUD
value|_IOW ('x', 4, long)
end_define

begin_comment
comment|/*  * Query/set the internal loopback mode,  * useful for debugging purposes.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETLOOP
value|_IOR ('x', 5, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETLOOP
value|_IOW ('x', 5, int)
end_define

begin_comment
comment|/*  * Query/set the DPLL mode, commonly used with NRZI  * for channels lacking synchro signals.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETDPLL
value|_IOR ('x', 6, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETDPLL
value|_IOW ('x', 6, int)
end_define

begin_comment
comment|/*  * Query/set the NRZI encoding (default is NRZ).  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETNRZI
value|_IOR ('x', 7, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETNRZI
value|_IOW ('x', 7, int)
end_define

begin_comment
comment|/*  * Invert receive and transmit clock.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETINVCLK
value|_IOR ('x', 8, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETINVCLK
value|_IOW ('x', 8, int)
end_define

begin_comment
comment|/*  * Query/set the E1/G703 synchronization mode.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETCLK
value|_IOR ('x', 9, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETCLK
value|_IOW ('x', 9, int)
end_define

begin_define
define|#
directive|define
name|E1CLK_RECOVERY
value|-1
end_define

begin_define
define|#
directive|define
name|E1CLK_INTERNAL
value|0
end_define

begin_define
define|#
directive|define
name|E1CLK_RECEIVE
value|1
end_define

begin_define
define|#
directive|define
name|E1CLK_RECEIVE_CHAN0
value|2
end_define

begin_define
define|#
directive|define
name|E1CLK_RECEIVE_CHAN1
value|3
end_define

begin_define
define|#
directive|define
name|E1CLK_RECEIVE_CHAN2
value|4
end_define

begin_define
define|#
directive|define
name|E1CLK_RECEIVE_CHAN3
value|5
end_define

begin_comment
comment|/*  * Query/set the E1 timeslot mask.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETTIMESLOTS
value|_IOR ('x', 10, long)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETTIMESLOTS
value|_IOW ('x', 10, long)
end_define

begin_comment
comment|/*  * Query/set the E1 subchannel timeslot mask.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETSUBCHAN
value|_IOR ('x', 11, long)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETSUBCHAN
value|_IOW ('x', 11, long)
end_define

begin_comment
comment|/*  * Query/set the high input sensitivity mode (E1).  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETHIGAIN
value|_IOR ('x', 12, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETHIGAIN
value|_IOW ('x', 12, int)
end_define

begin_comment
comment|/*  * Query the input signal level in santibells.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETLEVEL
value|_IOR ('x', 13, int)
end_define

begin_comment
comment|/*  * Get the channel name.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETNAME
value|_IOR ('x', 14, char [32])
end_define

begin_comment
comment|/*  * Get version string.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETVERSIONSTRING
value|_IOR ('x', 15, char [256])
end_define

begin_comment
comment|/*  * Query/set master channel.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETMASTER
value|_IOR ('x', 16, char [16])
end_define

begin_define
define|#
directive|define
name|SERIAL_SETMASTER
value|_IOW ('x', 16, char [16])
end_define

begin_comment
comment|/*  * Query/set keepalive.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETKEEPALIVE
value|_IOR ('x', 17, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETKEEPALIVE
value|_IOW ('x', 17, int)
end_define

begin_comment
comment|/*  * Query/set E1 configuration.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETCFG
value|_IOR ('x', 18, char)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETCFG
value|_IOW ('x', 18, char)
end_define

begin_comment
comment|/*  * Query/set debug.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETDEBUG
value|_IOR ('x', 19, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETDEBUG
value|_IOW ('x', 19, int)
end_define

begin_comment
comment|/*  * Query/set phony mode (E1).  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETPHONY
value|_IOR ('x', 20, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETPHONY
value|_IOW ('x', 20, int)
end_define

begin_comment
comment|/*  * Query/set timeslot 16 usage mode (E1).  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETUSE16
value|_IOR ('x', 21, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETUSE16
value|_IOW ('x', 21, int)
end_define

begin_comment
comment|/*  * Query/set crc4 mode (E1).  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETCRC4
value|_IOR ('x', 22, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETCRC4
value|_IOW ('x', 22, int)
end_define

begin_comment
comment|/*  * Query/set the timeout to recover after transmit interrupt loss.  * If timo==0 recover will be disabled.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETTIMO
value|_IOR ('x', 23, long)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETTIMO
value|_IOW ('x', 23, long)
end_define

begin_comment
comment|/*  * Query/set port type for old models of Sigma  * -1 Fixed or cable select  * 0  RS-232  * 1  V35  * 2  RS-449  * 3  E1	(only for Windows 2000)  * 4  G.703	(only for Windows 2000)  * 5  DATA	(only for Windows 2000)  * 6  E3	(only for Windows 2000)  * 7  T3	(only for Windows 2000)  * 8  STS1	(only for Windows 2000)  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETPORT
value|_IOR ('x', 25, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETPORT
value|_IOW ('x', 25, int)
end_define

begin_comment
comment|/*  * Add the virtual channel DLCI (Frame Relay).  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_ADDDLCI
value|_IOW ('x', 26, int)
end_define

begin_comment
comment|/*  * Invert receive clock.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETINVRCLK
value|_IOR ('x', 27, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETINVRCLK
value|_IOW ('x', 27, int)
end_define

begin_comment
comment|/*  * Invert transmit clock.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETINVTCLK
value|_IOR ('x', 28, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETINVTCLK
value|_IOW ('x', 28, int)
end_define

begin_comment
comment|/*  * Unframed E1 mode.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETUNFRAM
value|_IOR ('x', 29, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETUNFRAM
value|_IOW ('x', 29, int)
end_define

begin_comment
comment|/*  * E1 monitoring mode.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETMONITOR
value|_IOR ('x', 30, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETMONITOR
value|_IOW ('x', 30, int)
end_define

begin_comment
comment|/*  * Interrupt number.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETIRQ
value|_IOR ('x', 31, int)
end_define

begin_comment
comment|/*  * Reset.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_RESET
value|_IO ('x', 32)
end_define

begin_comment
comment|/*  * Hard reset.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_HARDRESET
value|_IO ('x', 33)
end_define

begin_comment
comment|/*  * Query cable type.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETCABLE
value|_IOR ('x', 34, int)
end_define

begin_comment
comment|/*  * Assignment of HDLC ports to E1 channels.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETDIR
value|_IOR ('x', 35, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETDIR
value|_IOW ('x', 35, int)
end_define

begin_struct
struct|struct
name|dxc_table
block|{
comment|/* cross-connector parameters */
name|unsigned
name|char
name|ts
index|[
literal|32
index|]
decl_stmt|;
comment|/* timeslot number */
name|unsigned
name|char
name|link
index|[
literal|32
index|]
decl_stmt|;
comment|/* E1 link number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * DXC cross-connector settings for E1 channels.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETDXC
value|_IOR ('x', 36, struct dxc_table)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETDXC
value|_IOW ('x', 36, struct dxc_table)
end_define

begin_comment
comment|/*  * Scrambler for G.703.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETSCRAMBLER
value|_IOR ('x', 37, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETSCRAMBLER
value|_IOW ('x', 37, int)
end_define

begin_comment
comment|/*  * Length of cable for T3 and STS-1.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETCABLEN
value|_IOR ('x', 38, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETCABLEN
value|_IOW ('x', 38, int)
end_define

begin_comment
comment|/*  * Remote loopback for E3, T3 and STS-1.  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETRLOOP
value|_IOR ('x', 39, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETRLOOP
value|_IOW ('x', 39, int)
end_define

begin_comment
comment|/*  * G.703 line code  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETLCODE
value|_IOR ('x', 40, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETLCODE
value|_IOW ('x', 40, int)
end_define

begin_comment
comment|/*  * MTU  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETMTU
value|_IOR ('x', 41, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETMTU
value|_IOW ('x', 41, int)
end_define

begin_comment
comment|/*  * Receive Queue Length  */
end_comment

begin_define
define|#
directive|define
name|SERIAL_GETRQLEN
value|_IOR ('x', 42, int)
end_define

begin_define
define|#
directive|define
name|SERIAL_SETRQLEN
value|_IOW ('x', 42, int)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|CRONYX_LYSAP
end_ifdef

begin_define
define|#
directive|define
name|LYSAP_PEER_ADD
value|_IOWR('x', 101, lysap_peer_config_t)
end_define

begin_define
define|#
directive|define
name|LYSAP_PEER_REMOVE
value|_IOW('x', 102, unsigned)
end_define

begin_define
define|#
directive|define
name|LYSAP_PEER_INFO
value|_IOWR('x', 103, lysap_peer_info_t)
end_define

begin_define
define|#
directive|define
name|LYSAP_PEER_COUNT
value|_IOR('x', 104, unsigned)
end_define

begin_define
define|#
directive|define
name|LYSAP_PEER_ENUM
value|_IOWR('x', 105, unsigned)
end_define

begin_define
define|#
directive|define
name|LYSAP_PEER_CLEAR
value|_IOW('x', 106, unsigned)
end_define

begin_define
define|#
directive|define
name|LYSAP_CHAN_ADD
value|_IOWR('x', 111, lysap_channel_config_t)
end_define

begin_define
define|#
directive|define
name|LYSAP_CHAN_REMOVE
value|_IO('x', 112)
end_define

begin_define
define|#
directive|define
name|LYSAP_CHAN_INFO
value|_IOR('x', 113, lysap_channel_info_t)
end_define

begin_define
define|#
directive|define
name|LYSAP_CHAN_COUNT
value|_IOR('x', 114, unsigned)
end_define

begin_define
define|#
directive|define
name|LYSAP_CHAN_ENUM
value|_IOWR('x', 115, unsigned)
end_define

begin_define
define|#
directive|define
name|LYSAP_CHAN_CLEAR
value|_IO('x', 116)
end_define

begin_include
include|#
directive|include
file|"lysap-linux.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CRONYX_LYSAP */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_lysap_channel_t
name|lysap_channel_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_lysap_channel_config_t
name|lysap_channel_config_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_LYSAP_DeviceInterfaceConfig
name|LYSAP_DeviceInterfaceConfig
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_LYSAP_ChannelConfig
name|LYSAP_ChannelConfig
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_lysap_buf_t
name|lysap_buf_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !CRONYX_LYSAP */
end_comment

begin_comment
comment|/*  * Dynamic binder interface.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_chan_t
name|chan_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_proto_t
name|proto_t
typedef|;
end_typedef

begin_function_decl
name|void
name|binder_register_protocol
parameter_list|(
name|proto_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|binder_unregister_protocol
parameter_list|(
name|proto_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|binder_register_channel
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|char
modifier|*
name|prefix
parameter_list|,
name|int
name|minor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|binder_unregister_channel
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Hardware channel driver structure.  */
end_comment

begin_struct_decl
struct_decl|struct
name|sk_buff
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|_chan_t
block|{
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
name|int
name|mtu
decl_stmt|;
comment|/* max packet size */
name|int
name|fifosz
decl_stmt|;
comment|/* total hardware i/o buffer size */
name|int
name|port
decl_stmt|;
comment|/* hardware base i/o port */
name|int
name|irq
decl_stmt|;
comment|/* hardware interrupt line */
name|int
name|minor
decl_stmt|;
comment|/* minor number 0..127, assigned by binder */
name|int
name|debug
decl_stmt|;
comment|/* debug level, 0..2 */
name|int
name|running
decl_stmt|;
comment|/* running, 0..1 */
name|struct
name|_proto_t
modifier|*
name|proto
decl_stmt|;
comment|/* protocol interface data */
name|void
modifier|*
name|sw
decl_stmt|;
comment|/* protocol private data */
name|void
modifier|*
name|hw
decl_stmt|;
comment|/* hardware layer private data */
comment|/* Interface to protocol */
name|int
function_decl|(
modifier|*
name|up
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|down
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|transmit
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|struct
name|sk_buff
modifier|*
name|skb
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_dtr
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_rts
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|query_dtr
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|query_rts
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|query_dsr
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|query_cts
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|query_dcd
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
comment|/* Interface to async protocol */
name|void
function_decl|(
modifier|*
name|set_async_param
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
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
name|void
function_decl|(
modifier|*
name|send_break
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|int
name|msec
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|send_xon
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|send_xoff
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|start_transmitter
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|stop_transmitter
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|flush_transmit_buffer
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
comment|/* Control interface */
name|int
function_decl|(
modifier|*
name|control
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|unsigned
name|int
name|cmd
parameter_list|,
name|unsigned
name|long
name|arg
parameter_list|)
function_decl|;
comment|/* LYSAP interface */
struct|struct
name|lysap_t
block|{
name|lysap_channel_t
modifier|*
name|link
decl_stmt|;
name|int
function_decl|(
modifier|*
name|inspect_config
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|lysap_channel_config_t
modifier|*
parameter_list|,
name|LYSAP_DeviceInterfaceConfig
modifier|*
parameter_list|,
name|LYSAP_ChannelConfig
modifier|*
parameter_list|)
function_decl|;
name|unsigned
name|long
function_decl|(
modifier|*
name|probe_freq
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|unsigned
name|long
name|freq
parameter_list|)
function_decl|;
name|unsigned
name|long
function_decl|(
modifier|*
name|set_freq
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|unsigned
name|long
name|freq
parameter_list|)
function_decl|;
name|unsigned
function_decl|(
modifier|*
name|get_status
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|transmit
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|lysap_buf_t
modifier|*
name|b
parameter_list|)
function_decl|;
name|lysap_buf_t
modifier|*
function_decl|(
modifier|*
name|alloc_buf
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|set_clock_master
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
name|unsigned
name|long
function_decl|(
modifier|*
name|get_master_freq
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
block|}
name|lysap
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Protocol driver structure.  */
end_comment

begin_struct
struct|struct
name|_proto_t
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|_proto_t
modifier|*
name|next
decl_stmt|;
comment|/* Interface to channel */
name|void
function_decl|(
modifier|*
name|receive
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|struct
name|sk_buff
modifier|*
name|skb
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|receive_error
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|int
name|errcode
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|transmit
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|modem_event
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
comment|/* Interface to binder */
name|int
function_decl|(
modifier|*
name|open
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|read
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|unsigned
name|short
name|flg
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|write
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|unsigned
name|short
name|flg
parameter_list|,
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|select
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|st
parameter_list|,
name|struct
name|file
modifier|*
name|filp
parameter_list|)
function_decl|;
name|struct
name|fasync_struct
modifier|*
name|fasync
decl_stmt|;
comment|/* Control interface */
name|int
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|detach
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|control
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|unsigned
name|int
name|cmd
parameter_list|,
name|unsigned
name|long
name|arg
parameter_list|)
function_decl|;
comment|/* LYSAP interface */
name|void
function_decl|(
modifier|*
name|transmit_error
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|int
name|errcode
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|lysap_notify_receive
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|,
name|lysap_buf_t
modifier|*
name|b
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|lysap_notify_transmit
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
name|lysap_buf_t
modifier|*
function_decl|(
modifier|*
name|lysap_get_data
function_decl|)
parameter_list|(
name|chan_t
modifier|*
name|h
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

