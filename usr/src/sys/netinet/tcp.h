begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)tcp.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|tcp_seq
typedef|;
end_typedef

begin_comment
comment|/*  * TCP header.  * Per RFC 793, September, 1981.  */
end_comment

begin_struct
struct|struct
name|tcphdr
block|{
name|u_short
name|th_sport
decl_stmt|;
comment|/* source port */
name|u_short
name|th_dport
decl_stmt|;
comment|/* destination port */
name|tcp_seq
name|th_seq
decl_stmt|;
comment|/* sequence number */
name|tcp_seq
name|th_ack
decl_stmt|;
comment|/* acknowledgement number */
ifdef|#
directive|ifdef
name|vax
name|u_char
name|th_x2
range|:
literal|4
decl_stmt|,
comment|/* (unused) */
name|th_off
range|:
literal|4
decl_stmt|;
comment|/* data offset */
endif|#
directive|endif
name|u_char
name|th_flags
decl_stmt|;
define|#
directive|define
name|TH_FIN
value|0x01
define|#
directive|define
name|TH_SYN
value|0x02
define|#
directive|define
name|TH_RST
value|0x04
define|#
directive|define
name|TH_PUSH
value|0x08
define|#
directive|define
name|TH_ACK
value|0x10
define|#
directive|define
name|TH_URG
value|0x20
name|u_short
name|th_win
decl_stmt|;
comment|/* window */
name|u_short
name|th_sum
decl_stmt|;
comment|/* checksum */
name|u_short
name|th_urp
decl_stmt|;
comment|/* urgent pointer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TCPOPT_EOL
value|0
end_define

begin_define
define|#
directive|define
name|TCPOPT_NOP
value|1
end_define

begin_define
define|#
directive|define
name|TCPOPT_MAXSEG
value|2
end_define

begin_comment
comment|/*  * Default maximum segment size for TCP.  * With an IP MSS of 576, this is 536,  * but 512 is probably more convenient.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|TCP_MSS
value|536
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TCP_MSS
value|MIN(512, IP_MSS - sizeof (struct tcpiphdr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * User-settable options (used with setsockopt).  */
end_comment

begin_define
define|#
directive|define
name|TCP_NODELAY
value|0x01
end_define

begin_comment
comment|/* don't delay send to coalesce packets */
end_comment

begin_define
define|#
directive|define
name|TCP_MAXSEG
value|0x02
end_define

begin_comment
comment|/* set maximum segment size */
end_comment

end_unit

