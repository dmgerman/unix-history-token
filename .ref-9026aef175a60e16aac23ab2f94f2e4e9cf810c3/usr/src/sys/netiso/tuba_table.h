begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)tuba_table.h	8.2 (Berkeley) %G%  */
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
name|tc_sum
decl_stmt|;
comment|/* cksum of nsap inc. length */
name|u_short
name|tc_ssum
decl_stmt|;
comment|/* swab(tc_sum) */
name|struct
name|sockaddr_iso
name|tc_siso
decl_stmt|;
comment|/* for responding */
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
value|{ union { u_short s[2]; long l;} l_util; long x; \ 	l_util.l = (b); x = l_util.s[0] + l_util.s[1]; ADDCARRY(x); \ 	if (x == 0) x = 0xffff; a = x;}
end_define

begin_define
define|#
directive|define
name|SWAB
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{ union { u_char c[2]; u_short s;} s; u_char t; \ 	s.s = (b); t = s.c[0]; s.c[0] = s.c[1]; s.c[1] = t; a = s.s;}
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

