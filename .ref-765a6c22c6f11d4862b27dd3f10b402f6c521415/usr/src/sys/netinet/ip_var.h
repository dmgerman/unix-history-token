begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ip_var.h	6.1	83/07/29	*/
end_comment

begin_comment
comment|/*  * Overlay for ip header used by other protocols (tcp, udp).  */
end_comment

begin_struct
struct|struct
name|ipovly
block|{
name|caddr_t
name|ih_next
decl_stmt|,
name|ih_prev
decl_stmt|;
comment|/* for protocol sequence q's */
name|u_char
name|ih_x1
decl_stmt|;
comment|/* (unused) */
name|u_char
name|ih_pr
decl_stmt|;
comment|/* protocol */
name|short
name|ih_len
decl_stmt|;
comment|/* protocol length */
name|struct
name|in_addr
name|ih_src
decl_stmt|;
comment|/* source internet address */
name|struct
name|in_addr
name|ih_dst
decl_stmt|;
comment|/* destination internet address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ip reassembly queue structure.  Each fragment  * being reassembled is attached to one of these structures.  * They are timed out after ipq_ttl drops to 0, and may also  * be reclaimed if memory becomes tight.  */
end_comment

begin_struct
struct|struct
name|ipq
block|{
name|struct
name|ipq
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
comment|/* to other reass headers */
name|u_char
name|ipq_ttl
decl_stmt|;
comment|/* time for reass q to live */
name|u_char
name|ipq_p
decl_stmt|;
comment|/* protocol of this fragment */
name|u_short
name|ipq_id
decl_stmt|;
comment|/* sequence id for reassembly */
name|struct
name|ipasfrag
modifier|*
name|ipq_next
decl_stmt|,
modifier|*
name|ipq_prev
decl_stmt|;
comment|/* to ip headers of fragments */
name|struct
name|in_addr
name|ipq_src
decl_stmt|,
name|ipq_dst
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ip header, when holding a fragment.  *  * Note: ipf_next must be at same offset as ipq_next above  */
end_comment

begin_struct
struct|struct
name|ipasfrag
block|{
ifdef|#
directive|ifdef
name|vax
name|u_char
name|ip_hl
range|:
literal|4
decl_stmt|,
name|ip_v
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|u_char
name|ipf_mff
decl_stmt|;
comment|/* copied from (ip_off&IP_MF) */
name|short
name|ip_len
decl_stmt|;
name|u_short
name|ip_id
decl_stmt|;
name|short
name|ip_off
decl_stmt|;
name|u_char
name|ip_ttl
decl_stmt|;
name|u_char
name|ip_p
decl_stmt|;
name|u_short
name|ip_sum
decl_stmt|;
name|struct
name|ipasfrag
modifier|*
name|ipf_next
decl_stmt|;
comment|/* next fragment */
name|struct
name|ipasfrag
modifier|*
name|ipf_prev
decl_stmt|;
comment|/* previous fragment */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipstat
block|{
name|int
name|ips_badsum
decl_stmt|;
comment|/* checksum bad */
name|int
name|ips_tooshort
decl_stmt|;
comment|/* packet too short */
name|int
name|ips_toosmall
decl_stmt|;
comment|/* not enough data */
name|int
name|ips_badhlen
decl_stmt|;
comment|/* ip header length< data size */
name|int
name|ips_badlen
decl_stmt|;
comment|/* ip length< ip header length */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* flags passed to ip_output as last parameter */
end_comment

begin_define
define|#
directive|define
name|IP_FORWARDING
value|0x1
end_define

begin_comment
comment|/* most of ip header exists */
end_comment

begin_define
define|#
directive|define
name|IP_ROUTETOIF
value|0x10
end_define

begin_comment
comment|/* same as SO_DONTROUTE */
end_comment

begin_define
define|#
directive|define
name|IP_ALLOWBROADCAST
value|SS_PRIV
end_define

begin_comment
comment|/* can send broadcast packets */
end_comment

begin_decl_stmt
name|struct
name|ipstat
name|ipstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ipq
name|ipq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip reass. queue */
end_comment

begin_decl_stmt
name|u_short
name|ip_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip packet ctr, for ids */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

