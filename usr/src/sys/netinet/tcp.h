begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tcp.h 1.15 81/11/14 */
end_comment

begin_comment
comment|/*  * Tcp header.  Fits over the ip header after option removed.  *  * SHOULD MAKE A CLEAN HEADER FOR USE BY USERS.  */
end_comment

begin_struct
struct|struct
name|tcpiphdr
block|{
name|struct
name|tcpiphdr
modifier|*
name|t_next
decl_stmt|;
comment|/* -> next tcp on rcv chain */
name|struct
name|tcpiphdr
modifier|*
name|t_prev
decl_stmt|;
comment|/* -> prev tcp on rcv chain */
name|u_char
name|t_x1
decl_stmt|;
comment|/* (unused) */
name|u_char
name|t_pr
decl_stmt|;
comment|/* protocol */
comment|/* by rights, t_len should be a u_short, but this makes operations */
comment|/* on it very dangerous as comparisons become unsigned and comparing */
comment|/* against negative numbers then fails... we don't expect any> 32767 */
comment|/* byte segments, so pragmatically delcare it to be a short */
name|short
name|t_len
decl_stmt|;
comment|/* seg length */
name|struct
name|ip_addr
name|t_s
decl_stmt|;
comment|/* source internet address */
name|struct
name|ip_addr
name|t_d
decl_stmt|;
comment|/* destination internet address */
name|u_short
name|t_src
decl_stmt|;
comment|/* source port */
name|u_short
name|t_dst
decl_stmt|;
comment|/* destination port */
name|seq_t
name|t_seq
decl_stmt|;
comment|/* sequence number */
name|seq_t
name|t_ackno
decl_stmt|;
comment|/* acknowledgement number */
define|#
directive|define
name|t_end
parameter_list|(
name|x
parameter_list|)
value|(x->t_seq + x->t_len - 1)
name|u_char
name|t_x2
range|:
literal|4
decl_stmt|,
comment|/* (unused) */
name|t_off
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
name|t_win
decl_stmt|;
comment|/* window */
name|u_short
name|t_sum
decl_stmt|;
comment|/* checksum */
name|u_short
name|t_urp
decl_stmt|;
comment|/* urgent pointer */
block|}
struct|;
end_struct

end_unit

