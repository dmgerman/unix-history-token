begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)tuba_table.h	7.3 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|tuba_cache
block|{
name|struct
name|radix_node
name|tc_nodes
index|[
literal|2
index|]
decl_stmt|;
comment|/* convenient lookup */
name|int
name|tc_refcnt
decl_stmt|;
name|int
name|tc_time
decl_stmt|;
comment|/* last looked up */
name|int
name|tc_flags
decl_stmt|;
define|#
directive|define
name|TCF_PERM
value|1
name|int
name|tc_index
decl_stmt|;
name|u_short
name|tc_sum_in
decl_stmt|;
comment|/* for inbound cksum */
name|u_short
name|tc_sum_out
decl_stmt|;
comment|/* for outbound cksum */
name|struct
name|iso_addr
name|tc_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ICKSUM
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a = (b) % 0xffff), (a == 0 ? a = 0xffff : a))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|tuba_table_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tuba_cache
modifier|*
modifier|*
name|tuba_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|radix_node_head
modifier|*
name|tuba_tree
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

