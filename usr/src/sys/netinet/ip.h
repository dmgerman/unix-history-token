begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ip.h 1.4 81/10/26 */
end_comment

begin_struct
struct|struct
name|ip
block|{
name|u_char
name|ip_hl
range|:
literal|4
decl_stmt|,
comment|/* header length */
name|ip_v
range|:
literal|4
decl_stmt|;
comment|/* version */
name|u_char
name|ip_tos
decl_stmt|;
comment|/* type of service */
define|#
directive|define
name|ip_mff
value|ip_tos
comment|/* more fragments flag (input) */
name|u_short
name|ip_len
decl_stmt|;
comment|/* total length */
name|u_short
name|ip_id
decl_stmt|;
comment|/* identification */
name|u_short
name|ip_off
decl_stmt|;
comment|/* fragment offset field */
define|#
directive|define
name|ip_df
value|0x4000
comment|/* dont fragment flag */
define|#
directive|define
name|ip_mf
value|0x2000
comment|/* more fragments flag (output) */
name|u_char
name|ip_ttl
decl_stmt|;
comment|/* time to live */
name|u_char
name|ip_p
decl_stmt|;
comment|/* protocol */
name|u_short
name|ip_sum
decl_stmt|;
comment|/* checksum */
define|#
directive|define
name|ip_end
value|ip_sum
comment|/* fragment end */
union|union
block|{
name|struct
name|socket
name|ip_s
decl_stmt|;
comment|/* source address */
name|struct
name|ip
modifier|*
name|ip_nxt
decl_stmt|;
comment|/* next fragment */
block|}
name|I_sun
union|;
define|#
directive|define
name|ip_src
value|I_sun.ip_s
define|#
directive|define
name|ip_next
value|I_sun.ip_nxt
union|union
block|{
name|struct
name|socket
name|ip_d
decl_stmt|;
comment|/* destination address */
name|struct
name|ip
modifier|*
name|ip_prv
decl_stmt|;
comment|/* prev fragment */
block|}
name|I_dun
union|;
define|#
directive|define
name|ip_dst
value|I_dun.ip_d
define|#
directive|define
name|ip_prev
value|I_dun.ip_prv
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ip reassembly queue.  */
end_comment

begin_struct
struct|struct
name|ipq
block|{
name|struct
name|ip
name|iqx
decl_stmt|;
comment|/* dummy ip element for top of list */
name|struct
name|ipq
modifier|*
name|iq_next
decl_stmt|;
comment|/* -> next chain on q */
name|struct
name|ipq
modifier|*
name|iq_prev
decl_stmt|;
comment|/* -> prev chain on q */
name|struct
name|ip
name|iqh
decl_stmt|;
comment|/* fragment header */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPVERSION
value|4
end_define

begin_comment
comment|/* internet protocol version number */
end_comment

begin_define
define|#
directive|define
name|IPLOLINK
value|155
end_define

begin_comment
comment|/* internet link numbers */
end_comment

begin_define
define|#
directive|define
name|IPHILINK
value|158
end_define

begin_define
define|#
directive|define
name|IPLINK
value|IPLOLINK
end_define

begin_define
define|#
directive|define
name|MAXTTL
value|255
end_define

begin_comment
comment|/* maximum time to live (seconds) */
end_comment

begin_define
define|#
directive|define
name|ip_bswap
parameter_list|(
name|p
parameter_list|)
value|{ \ 	p->ip_len = ntohs(p->ip_len); \ 	p->ip_id = ntohs(p->ip_id); \ 	p->ip_off = ntohs(p->ip_off); }
end_define

end_unit

