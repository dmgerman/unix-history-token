begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|RCSUDPHDR
value|"$Header: udp.h,v 1.1 84/04/05 15:23:56 walsh Exp $"
end_define

begin_struct
struct|struct
name|udp
block|{
comment|/* user dgram proto leader (fits over ip hdr) */
name|char
name|u_x
index|[
literal|8
index|]
decl_stmt|;
comment|/* unused fields from ip */
name|u_char
name|u_x1
decl_stmt|;
comment|/* unused */
name|u_char
name|u_pr
decl_stmt|;
comment|/* protocol number */
name|u_short
name|u_ilen
decl_stmt|;
comment|/* pseudo header length == UDP length */
name|struct
name|in_addr
name|u_s
decl_stmt|;
comment|/* source internet address */
name|struct
name|in_addr
name|u_d
decl_stmt|;
comment|/* destination internet address */
name|u_short
name|u_src
decl_stmt|;
comment|/* source port */
name|u_short
name|u_dst
decl_stmt|;
comment|/* destination port */
name|u_short
name|u_len
decl_stmt|;
comment|/* length */
name|u_short
name|u_sum
decl_stmt|;
comment|/* checksum */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UDPSIZE
value|8
end_define

begin_comment
comment|/* UDP header only */
end_comment

begin_define
define|#
directive|define
name|UDPCKSIZE
value|12
end_define

begin_comment
comment|/* UDP pseudo header */
end_comment

begin_struct
struct|struct
name|udp_stat
block|{
name|struct
name|in_stat
name|u_in
decl_stmt|;
define|#
directive|define
name|u_total
value|u_in.in_total
define|#
directive|define
name|u_badsum
value|u_in.in_badsum
define|#
directive|define
name|u_tooshort
value|u_in.in_tooshort
define|#
directive|define
name|u_drops
value|u_in.in_drops
name|int
name|u_sonospace
decl_stmt|;
comment|/* #udp pkts user socket rcv buf full (drop) */
name|int
name|u_nobuf
decl_stmt|;
comment|/* #udp pkts can't m_get for socket code */
block|}
struct|;
end_struct

begin_comment
comment|/*  * UDP port information  */
end_comment

begin_define
define|#
directive|define
name|UDP_RESERVED
value|1023
end_define

begin_define
define|#
directive|define
name|UDP_USERRESERVED
value|5000
end_define

begin_define
define|#
directive|define
name|UDP_MAXPORT
value|0xffff
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|udp_stat
name|udpstat
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|udp_conn_used
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

