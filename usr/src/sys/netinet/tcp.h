begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tcp.h 1.16 81/11/15 */
end_comment

begin_comment
comment|/*  * TCP header.  */
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
name|seq_t
name|th_seq
decl_stmt|;
comment|/* sequence number */
name|seq_t
name|th_ackno
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
value|001
define|#
directive|define
name|TH_SYN
value|002
define|#
directive|define
name|TH_RST
value|004
define|#
directive|define
name|TH_EOL
value|010
define|#
directive|define
name|TH_ACK
value|020
define|#
directive|define
name|TH_URG
value|040
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

end_unit

