begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)radix.h	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Radix search tree node layout.  */
end_comment

begin_struct
struct|struct
name|radix_node
block|{
name|struct
name|radix_mask
modifier|*
name|rn_mklist
decl_stmt|;
comment|/* list of masks contained in subtree */
name|struct
name|radix_node
modifier|*
name|rn_p
decl_stmt|;
comment|/* parent */
name|short
name|rn_b
decl_stmt|;
comment|/* bit offset; -1-index(netmask) */
name|char
name|rn_bmask
decl_stmt|;
comment|/* node: mask for bit test*/
name|u_char
name|rn_flags
decl_stmt|;
comment|/* enumerated next */
define|#
directive|define
name|RNF_NORMAL
value|1
comment|/* leaf contains normal route */
define|#
directive|define
name|RNF_ROOT
value|2
comment|/* leaf is root leaf for tree */
define|#
directive|define
name|RNF_ACTIVE
value|4
comment|/* This node is alive (for rtfree) */
union|union
block|{
struct|struct
block|{
comment|/* leaf only data: */
name|caddr_t
name|rn_Key
decl_stmt|;
comment|/* object of search */
name|caddr_t
name|rn_Mask
decl_stmt|;
comment|/* netmask, if present */
name|struct
name|radix_node
modifier|*
name|rn_Dupedkey
decl_stmt|;
block|}
name|rn_leaf
struct|;
struct|struct
block|{
comment|/* node only data: */
name|int
name|rn_Off
decl_stmt|;
comment|/* where to start compare */
name|struct
name|radix_node
modifier|*
name|rn_L
decl_stmt|;
comment|/* progeny */
name|struct
name|radix_node
modifier|*
name|rn_R
decl_stmt|;
comment|/* progeny */
block|}
name|rn_node
struct|;
block|}
name|rn_u
union|;
ifdef|#
directive|ifdef
name|RN_DEBUG
name|int
name|rn_info
decl_stmt|;
name|struct
name|radix_node
modifier|*
name|rn_twin
decl_stmt|;
name|struct
name|radix_node
modifier|*
name|rn_ybro
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXKEYLEN
value|32
end_define

begin_define
define|#
directive|define
name|rn_dupedkey
value|rn_u.rn_leaf.rn_Dupedkey
end_define

begin_define
define|#
directive|define
name|rn_key
value|rn_u.rn_leaf.rn_Key
end_define

begin_define
define|#
directive|define
name|rn_mask
value|rn_u.rn_leaf.rn_Mask
end_define

begin_define
define|#
directive|define
name|rn_off
value|rn_u.rn_node.rn_Off
end_define

begin_define
define|#
directive|define
name|rn_l
value|rn_u.rn_node.rn_L
end_define

begin_define
define|#
directive|define
name|rn_r
value|rn_u.rn_node.rn_R
end_define

begin_comment
comment|/*  * Annotations to tree concerning potential routes applying to subtrees.  */
end_comment

begin_struct
specifier|extern
struct|struct
name|radix_mask
block|{
name|short
name|rm_b
decl_stmt|;
comment|/* bit offset; -1-index(netmask) */
name|char
name|rm_unused
decl_stmt|;
comment|/* cf. rn_bmask */
name|u_char
name|rm_flags
decl_stmt|;
comment|/* cf. rn_flags */
name|struct
name|radix_mask
modifier|*
name|rm_mklist
decl_stmt|;
comment|/* more masks to try */
name|caddr_t
name|rm_mask
decl_stmt|;
comment|/* the mask */
name|int
name|rm_refs
decl_stmt|;
comment|/* # of references to this struct */
block|}
modifier|*
name|rn_mkfreelist
struct|;
end_struct

begin_define
define|#
directive|define
name|MKGet
parameter_list|(
name|m
parameter_list|)
value|{\ 	if (rn_mkfreelist) {\ 		m = rn_mkfreelist; \ 		rn_mkfreelist = (m)->rm_mklist; \ 	} else \ 		R_Malloc(m, struct radix_mask *, sizeof (*(m))); }\  #define MKFree(m) { (m)->rm_mklist = rn_mkfreelist; rn_mkfreelist = (m);}
end_define

begin_struct
specifier|extern
struct|struct
name|radix_node_head
block|{
name|struct
name|radix_node_head
modifier|*
name|rnh_next
decl_stmt|;
name|struct
name|radix_node
modifier|*
name|rnh_treetop
decl_stmt|;
name|int
name|rnh_af
decl_stmt|;
name|struct
name|radix_node
name|rnh_nodes
index|[
literal|3
index|]
decl_stmt|;
block|}
modifier|*
name|radix_node_head
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_define
define|#
directive|define
name|Bcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|bcmp(((char *)(a)), ((char *)(b)), (n))
end_define

begin_define
define|#
directive|define
name|Bzero
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|bzero((char *)(p), (int)(n));
end_define

begin_define
define|#
directive|define
name|R_Malloc
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|,
name|n
parameter_list|)
value|(p = (t) malloc((unsigned int)(n)))
end_define

begin_define
define|#
directive|define
name|Free
parameter_list|(
name|p
parameter_list|)
value|free((char *)p);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Bcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|bcmp(((caddr_t)(a)), ((caddr_t)(b)), (unsigned)(n))
end_define

begin_define
define|#
directive|define
name|Bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|bcopy(((caddr_t)(a)), ((caddr_t)(b)), (unsigned)(n))
end_define

begin_define
define|#
directive|define
name|Bzero
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|bzero((caddr_t)(p), (unsigned)(n));
end_define

begin_define
define|#
directive|define
name|R_Malloc
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|,
name|n
parameter_list|)
value|(p = (t) malloc((unsigned long)(n), M_RTABLE, M_DONTWAIT))
end_define

begin_define
define|#
directive|define
name|Free
parameter_list|(
name|p
parameter_list|)
value|free((caddr_t)p, M_RTABLE);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*KERNEL*/
end_comment

end_unit

