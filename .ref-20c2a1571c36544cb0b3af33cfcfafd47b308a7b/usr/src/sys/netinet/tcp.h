begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tcp.h 1.21 82/01/18 */
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

begin_ifdef
ifdef|#
directive|ifdef
name|TCPTRUEOOB
end_ifdef

begin_comment
comment|/*  * True out-of-band as value added option.  * Advertise willingness with TCPOPT_WILOOB in  * initial segment.  If peer is willing, will receive  * such also.  Then can send TCPOPT_OOBDATA whenever oob data  * exists; peer should ack with TCPOPT_OOBACK in segment.  */
end_comment

begin_define
define|#
directive|define
name|TCPOPT_WILLOOB
value|64
end_define

begin_comment
comment|/* bytes: 64, 2 */
end_comment

begin_define
define|#
directive|define
name|TCPOPT_OOBDATA
value|65
end_define

begin_comment
comment|/* bytes: 65, 8, seq#, data, markseq */
end_comment

begin_define
define|#
directive|define
name|TCPOPT_OOBACK
value|66
end_define

begin_comment
comment|/* bytes: 66, 3, ack# */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

