begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)radix.h	8.2 (Berkeley) 10/31/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RADIX_H_
end_ifndef

begin_define
define|#
directive|define
name|_RADIX_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_RTABLE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|rn_parent
decl_stmt|;
comment|/* parent */
name|short
name|rn_bit
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
name|rn_offset
value|rn_u.rn_node.rn_Off
end_define

begin_define
define|#
directive|define
name|rn_left
value|rn_u.rn_node.rn_L
end_define

begin_define
define|#
directive|define
name|rn_right
value|rn_u.rn_node.rn_R
end_define

begin_comment
comment|/*  * Annotations to tree concerning potential routes applying to subtrees.  */
end_comment

begin_struct
struct|struct
name|radix_mask
block|{
name|short
name|rm_bit
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
union|union
block|{
name|caddr_t
name|rmu_mask
decl_stmt|;
comment|/* the mask */
name|struct
name|radix_node
modifier|*
name|rmu_leaf
decl_stmt|;
comment|/* for normal routes */
block|}
name|rm_rmu
union|;
name|int
name|rm_refs
decl_stmt|;
comment|/* # of references to this struct */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rm_mask
value|rm_rmu.rmu_mask
end_define

begin_define
define|#
directive|define
name|rm_leaf
value|rm_rmu.rmu_leaf
end_define

begin_comment
comment|/* extra field would make 32 bytes */
end_comment

begin_define
define|#
directive|define
name|MKGet
parameter_list|(
name|m
parameter_list|)
value|{\ 	if (rn_mkfreelist) {\ 		m = rn_mkfreelist; \ 		rn_mkfreelist = (m)->rm_mklist; \ 	} else \ 		R_Malloc(m, struct radix_mask *, sizeof (*(m))); }\  #define MKFree(m) { (m)->rm_mklist = rn_mkfreelist; rn_mkfreelist = (m);}
end_define

begin_typedef
typedef|typedef
name|int
name|walktree_f_t
parameter_list|(
name|struct
name|radix_node
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|radix_node_head
block|{
name|struct
name|radix_node
modifier|*
name|rnh_treetop
decl_stmt|;
name|int
name|rnh_addrsize
decl_stmt|;
comment|/* permit, but not require fixed keys */
name|int
name|rnh_pktsize
decl_stmt|;
comment|/* permit, but not require fixed keys */
name|struct
name|radix_node
modifier|*
function_decl|(
modifier|*
name|rnh_addaddr
function_decl|)
comment|/* add based on sockaddr */
parameter_list|(
name|void
modifier|*
name|v
parameter_list|,
name|void
modifier|*
name|mask
parameter_list|,
name|struct
name|radix_node_head
modifier|*
name|head
parameter_list|,
name|struct
name|radix_node
name|nodes
index|[]
parameter_list|)
function_decl|;
name|struct
name|radix_node
modifier|*
function_decl|(
modifier|*
name|rnh_addpkt
function_decl|)
comment|/* add based on packet hdr */
parameter_list|(
name|void
modifier|*
name|v
parameter_list|,
name|void
modifier|*
name|mask
parameter_list|,
name|struct
name|radix_node_head
modifier|*
name|head
parameter_list|,
name|struct
name|radix_node
name|nodes
index|[]
parameter_list|)
function_decl|;
name|struct
name|radix_node
modifier|*
function_decl|(
modifier|*
name|rnh_deladdr
function_decl|)
comment|/* remove based on sockaddr */
parameter_list|(
name|void
modifier|*
name|v
parameter_list|,
name|void
modifier|*
name|mask
parameter_list|,
name|struct
name|radix_node_head
modifier|*
name|head
parameter_list|)
function_decl|;
name|struct
name|radix_node
modifier|*
function_decl|(
modifier|*
name|rnh_delpkt
function_decl|)
comment|/* remove based on packet hdr */
parameter_list|(
name|void
modifier|*
name|v
parameter_list|,
name|void
modifier|*
name|mask
parameter_list|,
name|struct
name|radix_node_head
modifier|*
name|head
parameter_list|)
function_decl|;
name|struct
name|radix_node
modifier|*
function_decl|(
modifier|*
name|rnh_matchaddr
function_decl|)
comment|/* locate based on sockaddr */
parameter_list|(
name|void
modifier|*
name|v
parameter_list|,
name|struct
name|radix_node_head
modifier|*
name|head
parameter_list|)
function_decl|;
name|struct
name|radix_node
modifier|*
function_decl|(
modifier|*
name|rnh_lookup
function_decl|)
comment|/* locate based on sockaddr */
parameter_list|(
name|void
modifier|*
name|v
parameter_list|,
name|void
modifier|*
name|mask
parameter_list|,
name|struct
name|radix_node_head
modifier|*
name|head
parameter_list|)
function_decl|;
name|struct
name|radix_node
modifier|*
function_decl|(
modifier|*
name|rnh_matchpkt
function_decl|)
comment|/* locate based on packet hdr */
parameter_list|(
name|void
modifier|*
name|v
parameter_list|,
name|struct
name|radix_node_head
modifier|*
name|head
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|rnh_walktree
function_decl|)
comment|/* traverse tree */
parameter_list|(
name|struct
name|radix_node_head
modifier|*
name|head
parameter_list|,
name|walktree_f_t
modifier|*
name|f
parameter_list|,
name|void
modifier|*
name|w
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|rnh_walktree_from
function_decl|)
comment|/* traverse tree below a */
parameter_list|(
name|struct
name|radix_node_head
modifier|*
name|head
parameter_list|,
name|void
modifier|*
name|a
parameter_list|,
name|void
modifier|*
name|m
parameter_list|,
name|walktree_f_t
modifier|*
name|f
parameter_list|,
name|void
modifier|*
name|w
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rnh_close
function_decl|)
comment|/* do something when the last ref drops */
parameter_list|(
name|struct
name|radix_node
modifier|*
name|rn
parameter_list|,
name|struct
name|radix_node_head
modifier|*
name|head
parameter_list|)
function_decl|;
name|struct
name|radix_node
name|rnh_nodes
index|[
literal|3
index|]
decl_stmt|;
comment|/* empty tree for common case */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
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
name|Bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|bcopy(((char *)(a)), ((char *)(b)), (unsigned)(n))
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
comment|/* _KERNEL */
end_comment

begin_function_decl
name|void
name|rn_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rn_inithead
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rn_refines
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|radix_node
modifier|*
name|rn_addmask
argument_list|(
name|void
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
decl_stmt|,
modifier|*
name|rn_addroute
argument_list|(
name|void
operator|*
argument_list|,
name|void
operator|*
argument_list|,
expr|struct
name|radix_node_head
operator|*
argument_list|,
expr|struct
name|radix_node
index|[
literal|2
index|]
argument_list|)
decl_stmt|,
modifier|*
name|rn_delete
argument_list|(
name|void
operator|*
argument_list|,
name|void
operator|*
argument_list|,
expr|struct
name|radix_node_head
operator|*
argument_list|)
decl_stmt|,
modifier|*
name|rn_lookup
argument_list|(
name|void
operator|*
name|v_arg
argument_list|,
name|void
operator|*
name|m_arg
argument_list|,
expr|struct
name|radix_node_head
operator|*
name|head
argument_list|)
decl_stmt|,
modifier|*
name|rn_match
argument_list|(
name|void
operator|*
argument_list|,
expr|struct
name|radix_node_head
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RADIX_H_ */
end_comment

end_unit

