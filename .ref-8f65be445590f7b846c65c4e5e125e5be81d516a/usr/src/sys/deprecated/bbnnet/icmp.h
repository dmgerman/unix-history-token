begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|RCSICMPHDR
value|"$Header: icmp.h,v 1.6 85/07/31 09:29:40 walsh Exp $"
end_define

begin_struct
struct|struct
name|icmp
block|{
comment|/* icmp header */
name|u_char
name|ic_type
decl_stmt|;
comment|/* icmp message type */
name|u_char
name|ic_code
decl_stmt|;
comment|/* icmp message sub-type */
name|u_short
name|ic_sum
decl_stmt|;
comment|/* checksum */
union|union
block|{
name|u_char
name|I_off
decl_stmt|;
comment|/* parameter error offset */
name|struct
name|in_addr
name|I_gaddr
decl_stmt|;
comment|/* redirect gateway addr */
struct|struct
block|{
name|u_short
name|I_id
decl_stmt|;
comment|/* echo/timestamp id */
name|u_short
name|I_seq
decl_stmt|;
comment|/* echo/timestamp sequence */
block|}
name|I_iseq
struct|;
name|long
name|I_misc
decl_stmt|;
comment|/* the whole field */
block|}
name|I_un1
union|;
define|#
directive|define
name|ic_off
value|I_un1.I_off
define|#
directive|define
name|ic_gaddr
value|I_un1.I_gaddr
define|#
directive|define
name|ic_id
value|I_un1.I_iseq.I_id
define|#
directive|define
name|ic_seq
value|I_un1.I_iseq.I_seq
define|#
directive|define
name|ic_misc
value|I_un1.I_misc
union|union
block|{
name|struct
name|ip
name|I_iphdr
decl_stmt|;
comment|/* ip/{proto} hdr of original 						 * IP datagram.  Has>=  						 * ICMP_ERRLEN bytes  of 						 * protocol header 						 */
struct|struct
block|{
name|long
name|I_torg
decl_stmt|;
comment|/* originate timestamp */
name|long
name|I_trcv
decl_stmt|;
comment|/* receive timestamp */
name|long
name|I_txmt
decl_stmt|;
comment|/* transmit timestamp */
block|}
name|I_time
struct|;
name|char
name|I_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* echo data */
block|}
name|I_un2
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ic_iphdr
value|I_un2.I_iphdr
end_define

begin_define
define|#
directive|define
name|ic_torg
value|I_un2.I_time.I_torg
end_define

begin_define
define|#
directive|define
name|ic_trcv
value|I_un2.I_time.I_trcv
end_define

begin_define
define|#
directive|define
name|ic_txmt
value|I_un2.I_time.I_txmt
end_define

begin_define
define|#
directive|define
name|ic_data
value|I_un2.I_data
end_define

begin_comment
comment|/* icmp message types */
end_comment

begin_define
define|#
directive|define
name|ICMP_ECHOR
value|0
end_define

begin_comment
comment|/* echo reply */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNRCH
value|3
end_define

begin_comment
comment|/* destination unreachable */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNRCH_NET
value|0
end_define

begin_comment
comment|/* net unreachable */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNRCH_HOST
value|1
end_define

begin_comment
comment|/* host unreachable */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNRCH_PR
value|2
end_define

begin_comment
comment|/* protocol unrch */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNRCH_PORT
value|3
end_define

begin_comment
comment|/* port unreachable */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNRCH_FRAG
value|4
end_define

begin_comment
comment|/* DF on fragment */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNRCH_SRC
value|5
end_define

begin_comment
comment|/* bad source route */
end_comment

begin_define
define|#
directive|define
name|ICMP_UNRCH_NUM
value|6
end_define

begin_define
define|#
directive|define
name|ICMP_SRCQ
value|4
end_define

begin_comment
comment|/* source quench */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIR
value|5
end_define

begin_comment
comment|/* redirect */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIR_NET
value|0
end_define

begin_comment
comment|/* network */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIR_HOST
value|1
end_define

begin_comment
comment|/* host */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIR_TNET
value|2
end_define

begin_comment
comment|/* TOS& network */
end_comment

begin_define
define|#
directive|define
name|ICMP_REDIR_THOST
value|3
end_define

begin_comment
comment|/* TOS& host */
end_comment

begin_define
define|#
directive|define
name|ICMP_ECHO
value|8
end_define

begin_comment
comment|/* echo */
end_comment

begin_define
define|#
directive|define
name|ICMP_TIMEX
value|11
end_define

begin_comment
comment|/* time exceeded */
end_comment

begin_define
define|#
directive|define
name|ICMP_TIMEX_XMT
value|0
end_define

begin_comment
comment|/* in transit */
end_comment

begin_define
define|#
directive|define
name|ICMP_TIMEX_REASS
value|1
end_define

begin_comment
comment|/* reassembly */
end_comment

begin_define
define|#
directive|define
name|ICMP_PARM
value|12
end_define

begin_comment
comment|/* parameter problem */
end_comment

begin_define
define|#
directive|define
name|ICMP_TIMES
value|13
end_define

begin_comment
comment|/* timestamp */
end_comment

begin_define
define|#
directive|define
name|ICMP_TIMESR
value|14
end_define

begin_comment
comment|/* timestamp reply */
end_comment

begin_define
define|#
directive|define
name|ICMP_INFO
value|15
end_define

begin_comment
comment|/* information request */
end_comment

begin_define
define|#
directive|define
name|ICMP_INFOR
value|16
end_define

begin_comment
comment|/* information reply */
end_comment

begin_define
define|#
directive|define
name|ICMPSIZE
value|8
end_define

begin_comment
comment|/* size of min. echo packet */
end_comment

begin_define
define|#
directive|define
name|PINGTIME
value|8
end_define

begin_comment
comment|/* ping interval (in sec/2) */
end_comment

begin_define
define|#
directive|define
name|MAXPING
value|5
end_define

begin_comment
comment|/* no. of pings before decide gway is down */
end_comment

begin_define
define|#
directive|define
name|RT_REINSTATE
value|2
end_define

begin_comment
comment|/* number of ping intervals a gateway stays down. 			 * See ip_gdown() and check_ping(). 			 */
end_comment

begin_define
define|#
directive|define
name|ICMP_ERRLEN
value|8
end_define

begin_comment
comment|/* 64 bits  == 8 bytes */
end_comment

begin_define
define|#
directive|define
name|MY_ECHO_ID
value|0xffff
end_define

begin_comment
comment|/*  * icmp statistics  */
end_comment

begin_struct
struct|struct
name|icmp_stat
block|{
name|struct
name|in_stat
name|ic_in
decl_stmt|;
define|#
directive|define
name|ic_total
value|ic_in.in_total
define|#
directive|define
name|ic_badsum
value|ic_in.in_badsum
define|#
directive|define
name|ic_tooshort
value|ic_in.in_tooshort
define|#
directive|define
name|ic_drops
value|ic_in.in_drops
name|int
name|ic_broadcast
decl_stmt|;
comment|/* #icmp pkts rcv that were broadcast (ign) */
name|int
name|ic_quenches
decl_stmt|;
comment|/* #icmp source quenches received */
name|int
name|ic_redirects
decl_stmt|;
comment|/* #icmp redirects received */
name|int
name|ic_echoes
decl_stmt|;
comment|/* #icmp echo requests respond to */
name|int
name|ic_svpings
decl_stmt|;
comment|/* #pings saved by -1 hack */
name|int
name|ic_pings
decl_stmt|;
comment|/* #pings actually sent */
name|int
name|ic_timex
decl_stmt|;
comment|/* #icmp time exceeded messages received */
name|int
name|ic_parm
decl_stmt|;
comment|/* #icmp parameter problem received */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|icmp_stat
name|icmpstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

