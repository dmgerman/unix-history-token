begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ip_var.h	4.2	81/11/15	*/
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
name|ip_addr
name|ih_src
decl_stmt|;
comment|/* source internet address */
name|struct
name|ip_addr
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
name|ip_addr
name|ipq_src
decl_stmt|,
name|ipq_dst
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ip header, when holding a fragment.  */
end_comment

begin_struct
struct|struct
name|ipasfrag
block|{
name|u_char
name|ip_hl
range|:
literal|4
decl_stmt|,
name|ip_v
range|:
literal|4
decl_stmt|;
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|ipq
name|ipq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip reass. queue */
end_comment

begin_function_decl
name|struct
name|ipq
modifier|*
name|ip_freef
parameter_list|()
function_decl|;
end_function_decl

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

