begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)tuba_table.h	7.4 (Berkeley) %G%  */
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
name|ADDCARRY
parameter_list|(
name|x
parameter_list|)
value|(x>= 65535 ? x -= 65535 : x)
end_define

begin_define
define|#
directive|define
name|REDUCE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{ union { u_short s[2]; long l;} l_util; long x; \ 	l_util.l = (b); x = l_util.s[0] + l_util.s[1]; ADDCARRY(x); a = x;}
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

