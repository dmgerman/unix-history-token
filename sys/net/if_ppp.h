begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * if_ppp.h - Point-to-Point Protocol definitions.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_PPP_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_PPP_H_
end_define

begin_comment
comment|/* XXX this used to be self-contained. */
end_comment

begin_include
include|#
directive|include
file|<net/ppp_defs.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_comment
comment|/*  * Packet sizes  */
end_comment

begin_define
define|#
directive|define
name|PPP_MTU
value|1500
end_define

begin_comment
comment|/* Default MTU (size of Info field) */
end_comment

begin_define
define|#
directive|define
name|PPP_MAXMRU
value|65000
end_define

begin_comment
comment|/* Largest MRU we allow */
end_comment

begin_define
define|#
directive|define
name|PPP_MAXMTU
value|16384
end_define

begin_comment
comment|/* Largest MTU we allow */
end_comment

begin_comment
comment|/*  * Bit definitions for flags.  */
end_comment

begin_define
define|#
directive|define
name|SC_COMP_PROT
value|0x00000001
end_define

begin_comment
comment|/* protocol compression (output) */
end_comment

begin_define
define|#
directive|define
name|SC_COMP_AC
value|0x00000002
end_define

begin_comment
comment|/* header compression (output) */
end_comment

begin_define
define|#
directive|define
name|SC_COMP_TCP
value|0x00000004
end_define

begin_comment
comment|/* TCP (VJ) compression (output) */
end_comment

begin_define
define|#
directive|define
name|SC_NO_TCP_CCID
value|0x00000008
end_define

begin_comment
comment|/* disable VJ connection-id comp. */
end_comment

begin_define
define|#
directive|define
name|SC_REJ_COMP_AC
value|0x00000010
end_define

begin_comment
comment|/* reject adrs/ctrl comp. on input */
end_comment

begin_define
define|#
directive|define
name|SC_REJ_COMP_TCP
value|0x00000020
end_define

begin_comment
comment|/* reject TCP (VJ) comp. on input */
end_comment

begin_define
define|#
directive|define
name|SC_CCP_OPEN
value|0x00000040
end_define

begin_comment
comment|/* Look at CCP packets */
end_comment

begin_define
define|#
directive|define
name|SC_CCP_UP
value|0x00000080
end_define

begin_comment
comment|/* May send/recv compressed packets */
end_comment

begin_define
define|#
directive|define
name|SC_DEBUG
value|0x00010000
end_define

begin_comment
comment|/* enable debug messages */
end_comment

begin_define
define|#
directive|define
name|SC_LOG_INPKT
value|0x00020000
end_define

begin_comment
comment|/* log contents of good pkts recvd */
end_comment

begin_define
define|#
directive|define
name|SC_LOG_OUTPKT
value|0x00040000
end_define

begin_comment
comment|/* log contents of pkts sent */
end_comment

begin_define
define|#
directive|define
name|SC_LOG_RAWIN
value|0x00080000
end_define

begin_comment
comment|/* log all chars received */
end_comment

begin_define
define|#
directive|define
name|SC_LOG_FLUSH
value|0x00100000
end_define

begin_comment
comment|/* log all chars flushed */
end_comment

begin_define
define|#
directive|define
name|SC_RCV_B7_0
value|0x01000000
end_define

begin_comment
comment|/* have rcvd char with bit 7 = 0 */
end_comment

begin_define
define|#
directive|define
name|SC_RCV_B7_1
value|0x02000000
end_define

begin_comment
comment|/* have rcvd char with bit 7 = 1 */
end_comment

begin_define
define|#
directive|define
name|SC_RCV_EVNP
value|0x04000000
end_define

begin_comment
comment|/* have rcvd char with even parity */
end_comment

begin_define
define|#
directive|define
name|SC_RCV_ODDP
value|0x08000000
end_define

begin_comment
comment|/* have rcvd char with odd parity */
end_comment

begin_define
define|#
directive|define
name|SC_MASK
value|0x0fff00ff
end_define

begin_comment
comment|/* bits that user can change */
end_comment

begin_comment
comment|/*  * State bits in sc_flags, not changeable by user.  */
end_comment

begin_define
define|#
directive|define
name|SC_TIMEOUT
value|0x00000400
end_define

begin_comment
comment|/* timeout is currently pending */
end_comment

begin_define
define|#
directive|define
name|SC_VJ_RESET
value|0x00000800
end_define

begin_comment
comment|/* need to reset VJ decomp */
end_comment

begin_define
define|#
directive|define
name|SC_COMP_RUN
value|0x00001000
end_define

begin_comment
comment|/* compressor has been initiated */
end_comment

begin_define
define|#
directive|define
name|SC_DECOMP_RUN
value|0x00002000
end_define

begin_comment
comment|/* decompressor has been initiated */
end_comment

begin_define
define|#
directive|define
name|SC_DC_ERROR
value|0x00004000
end_define

begin_comment
comment|/* non-fatal decomp error detected */
end_comment

begin_define
define|#
directive|define
name|SC_DC_FERROR
value|0x00008000
end_define

begin_comment
comment|/* fatal decomp error detected */
end_comment

begin_define
define|#
directive|define
name|SC_TBUSY
value|0x10000000
end_define

begin_comment
comment|/* xmitter doesn't need a packet yet */
end_comment

begin_define
define|#
directive|define
name|SC_PKTLOST
value|0x20000000
end_define

begin_comment
comment|/* have lost or dropped a packet */
end_comment

begin_define
define|#
directive|define
name|SC_FLUSH
value|0x40000000
end_define

begin_comment
comment|/* flush input until next PPP_FLAG */
end_comment

begin_define
define|#
directive|define
name|SC_ESCAPED
value|0x80000000
end_define

begin_comment
comment|/* saw a PPP_ESCAPE */
end_comment

begin_comment
comment|/*  * Ioctl definitions.  */
end_comment

begin_struct
struct|struct
name|npioctl
block|{
name|int
name|protocol
decl_stmt|;
comment|/* PPP procotol, e.g. PPP_IP */
name|enum
name|NPmode
name|mode
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure describing a CCP configuration option, for PPPIOCSCOMPRESS */
end_comment

begin_struct
struct|struct
name|ppp_option_data
block|{
name|u_char
modifier|*
name|ptr
decl_stmt|;
name|u_int
name|length
decl_stmt|;
name|int
name|transmit
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ifpppstatsreq
block|{
name|char
name|ifr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|struct
name|ppp_stats
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ifpppcstatsreq
block|{
name|char
name|ifr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|struct
name|ppp_comp_stats
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ioctl definitions.  */
end_comment

begin_define
define|#
directive|define
name|PPPIOCGFLAGS
value|_IOR('t', 90, int)
end_define

begin_comment
comment|/* get configuration flags */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSFLAGS
value|_IOW('t', 89, int)
end_define

begin_comment
comment|/* set configuration flags */
end_comment

begin_define
define|#
directive|define
name|PPPIOCGASYNCMAP
value|_IOR('t', 88, int)
end_define

begin_comment
comment|/* get async map */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSASYNCMAP
value|_IOW('t', 87, int)
end_define

begin_comment
comment|/* set async map */
end_comment

begin_define
define|#
directive|define
name|PPPIOCGUNIT
value|_IOR('t', 86, int)
end_define

begin_comment
comment|/* get ppp unit number */
end_comment

begin_define
define|#
directive|define
name|PPPIOCGRASYNCMAP
value|_IOR('t', 85, int)
end_define

begin_comment
comment|/* get receive async map */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSRASYNCMAP
value|_IOW('t', 84, int)
end_define

begin_comment
comment|/* set receive async map */
end_comment

begin_define
define|#
directive|define
name|PPPIOCGMRU
value|_IOR('t', 83, int)
end_define

begin_comment
comment|/* get max receive unit */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSMRU
value|_IOW('t', 82, int)
end_define

begin_comment
comment|/* set max receive unit */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSMAXCID
value|_IOW('t', 81, int)
end_define

begin_comment
comment|/* set VJ max slot ID */
end_comment

begin_define
define|#
directive|define
name|PPPIOCGXASYNCMAP
value|_IOR('t', 80, ext_accm)
end_define

begin_comment
comment|/* get extended ACCM */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSXASYNCMAP
value|_IOW('t', 79, ext_accm)
end_define

begin_comment
comment|/* set extended ACCM */
end_comment

begin_define
define|#
directive|define
name|PPPIOCXFERUNIT
value|_IO('t', 78)
end_define

begin_comment
comment|/* transfer PPP unit */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSCOMPRESS
value|_IOW('t', 77, struct ppp_option_data)
end_define

begin_define
define|#
directive|define
name|PPPIOCGNPMODE
value|_IOWR('t', 76, struct npioctl)
end_define

begin_comment
comment|/* get NP mode */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSNPMODE
value|_IOW('t', 75, struct npioctl)
end_define

begin_comment
comment|/* set NP mode */
end_comment

begin_define
define|#
directive|define
name|PPPIOCGIDLE
value|_IOR('t', 74, struct ppp_idle)
end_define

begin_comment
comment|/* get idle time */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSPASS
value|_IOW('t', 71, struct bpf_program)
end_define

begin_comment
comment|/* set pass filter */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSACTIVE
value|_IOW('t', 70, struct bpf_program)
end_define

begin_comment
comment|/* set active filt */
end_comment

begin_comment
comment|/* PPPIOC[GS]MTU are alternatives to SIOC[GS]IFMTU, used under Ultrix */
end_comment

begin_define
define|#
directive|define
name|PPPIOCGMTU
value|_IOR('t', 73, int)
end_define

begin_comment
comment|/* get interface MTU */
end_comment

begin_define
define|#
directive|define
name|PPPIOCSMTU
value|_IOW('t', 72, int)
end_define

begin_comment
comment|/* set interface MTU */
end_comment

begin_comment
comment|/*  * These two are interface ioctls so that pppstats can do them on  * a socket without having to open the serial device.  */
end_comment

begin_define
define|#
directive|define
name|SIOCGPPPSTATS
value|_IOWR('i', 123, struct ifpppstatsreq)
end_define

begin_define
define|#
directive|define
name|SIOCGPPPCSTATS
value|_IOWR('i', 122, struct ifpppcstatsreq)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ifr_mtu
argument_list|)
end_if

begin_define
define|#
directive|define
name|ifr_mtu
value|ifr_ifru.ifru_metric
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_PPP_H_ */
end_comment

end_unit

