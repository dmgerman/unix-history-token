begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2007, 2008  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: radix.h,v 1.13 2008/12/01 23:47:45 tbox Exp $ */
end_comment

begin_comment
comment|/*  * This source was adapted from MRT's RCS Ids:  * Id: radix.h,v 1.6 1999/08/03 03:32:53 masaki Exp  * Id: mrt.h,v 1.57.2.6 1999/12/28 23:41:27 labovit Exp  * Id: defs.h,v 1.5.2.2 2000/01/15 14:19:16 masaki Exp  */
end_comment

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/net.h>
end_include

begin_include
include|#
directive|include
file|<isc/refcount.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_RADIX_H
end_ifndef

begin_define
define|#
directive|define
name|_RADIX_H
end_define

begin_define
define|#
directive|define
name|NETADDR_TO_PREFIX_T
parameter_list|(
name|na
parameter_list|,
name|pt
parameter_list|,
name|bits
parameter_list|)
define|\
value|do { \ 		memset(&(pt), 0, sizeof(pt)); \ 		if((na) != NULL) { \ 			(pt).family = (na)->family; \ 			(pt).bitlen = (bits); \ 			if ((pt).family == AF_INET6) { \ 				memcpy(&(pt).add.sin6,&(na)->type.in6, \ 				       ((bits)+7)/8); \ 			} else \ 				memcpy(&(pt).add.sin,&(na)->type.in, \ 				       ((bits)+7)/8); \ 		} else { \ 			(pt).family = AF_UNSPEC; \ 			(pt).bitlen = 0; \ 		} \ 		isc_refcount_init(&(pt).refcount, 0); \ 	} while(0)
end_define

begin_typedef
typedef|typedef
struct|struct
name|isc_prefix
block|{
name|unsigned
name|int
name|family
decl_stmt|;
comment|/* AF_INET | AF_INET6, or AF_UNSPEC for "any" */
name|unsigned
name|int
name|bitlen
decl_stmt|;
comment|/* 0 for "any" */
name|isc_refcount_t
name|refcount
decl_stmt|;
union|union
block|{
name|struct
name|in_addr
name|sin
decl_stmt|;
name|struct
name|in6_addr
name|sin6
decl_stmt|;
block|}
name|add
union|;
block|}
name|isc_prefix_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_radix_destroyfunc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_radix_processfunc_t
function_decl|)
parameter_list|(
name|isc_prefix_t
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|isc_prefix_tochar
parameter_list|(
name|prefix
parameter_list|)
value|((char *)&(prefix)->add.sin)
end_define

begin_define
define|#
directive|define
name|isc_prefix_touchar
parameter_list|(
name|prefix
parameter_list|)
value|((u_char *)&(prefix)->add.sin)
end_define

begin_define
define|#
directive|define
name|BIT_TEST
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|)
value|((f)& (b))
end_define

begin_comment
comment|/*  * We need "first match" when we search the radix tree to preserve  * compatibility with the existing ACL implementation. Radix trees  * naturally lend themselves to "best match". In order to get "first match"  * behavior, we keep track of the order in which entries are added to the  * tree--and when a search is made, we find all matching entries, and  * return the one that was added first.  *  * An IPv4 prefix and an IPv6 prefix may share a radix tree node if they  * have the same length and bit pattern (e.g., 127/8 and 7f::/8).  To  * disambiguate between them, node_num and data are two-element arrays;  * node_num[0] and data[0] are used for IPv4 addresses, node_num[1]  * and data[1] for IPv6 addresses.  The only exception is a prefix of  * 0/0 (aka "any" or "none"), which is always stored as IPv4 but matches  * IPv6 addresses too.  */
end_comment

begin_define
define|#
directive|define
name|ISC_IS6
parameter_list|(
name|family
parameter_list|)
value|((family) == AF_INET6 ? 1 : 0)
end_define

begin_typedef
typedef|typedef
struct|struct
name|isc_radix_node
block|{
name|isc_uint32_t
name|bit
decl_stmt|;
comment|/* bit length of the prefix */
name|isc_prefix_t
modifier|*
name|prefix
decl_stmt|;
comment|/* who we are in radix tree */
name|struct
name|isc_radix_node
modifier|*
name|l
decl_stmt|,
modifier|*
name|r
decl_stmt|;
comment|/* left and right children */
name|struct
name|isc_radix_node
modifier|*
name|parent
decl_stmt|;
comment|/* may be used */
name|void
modifier|*
name|data
index|[
literal|2
index|]
decl_stmt|;
comment|/* pointers to IPv4 and IPV6 data */
name|int
name|node_num
index|[
literal|2
index|]
decl_stmt|;
comment|/* which node this was in the tree, 					   or -1 for glue nodes */
block|}
name|isc_radix_node_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RADIX_TREE_MAGIC
value|ISC_MAGIC('R','d','x','T');
end_define

begin_define
define|#
directive|define
name|RADIX_TREE_VALID
parameter_list|(
name|a
parameter_list|)
value|ISC_MAGIC_VALID(a, RADIX_TREE_MAGIC);
end_define

begin_typedef
typedef|typedef
struct|struct
name|isc_radix_tree
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_radix_node_t
modifier|*
name|head
decl_stmt|;
name|isc_uint32_t
name|maxbits
decl_stmt|;
comment|/* for IP, 32 bit addresses */
name|int
name|num_active_node
decl_stmt|;
comment|/* for debugging purposes */
name|int
name|num_added_node
decl_stmt|;
comment|/* total number of nodes */
block|}
name|isc_radix_tree_t
typedef|;
end_typedef

begin_function_decl
name|isc_result_t
name|isc_radix_search
parameter_list|(
name|isc_radix_tree_t
modifier|*
name|radix
parameter_list|,
name|isc_radix_node_t
modifier|*
modifier|*
name|target
parameter_list|,
name|isc_prefix_t
modifier|*
name|prefix
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Search 'radix' for the best match to 'prefix'.  * Return the node found in '*target'.  *  * Requires:  * \li	'radix' to be valid.  * \li	'target' is not NULL and "*target" is NULL.  * \li	'prefix' to be valid.  *  * Returns:  * \li	ISC_R_NOTFOUND  * \li	ISC_R_SUCCESS  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_radix_insert
parameter_list|(
name|isc_radix_tree_t
modifier|*
name|radix
parameter_list|,
name|isc_radix_node_t
modifier|*
modifier|*
name|target
parameter_list|,
name|isc_radix_node_t
modifier|*
name|source
parameter_list|,
name|isc_prefix_t
modifier|*
name|prefix
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Insert 'source' or 'prefix' into the radix tree 'radix'.  * Return the node added in 'target'.  *  * Requires:  * \li	'radix' to be valid.  * \li	'target' is not NULL and "*target" is NULL.  * \li	'prefix' to be valid or 'source' to be non NULL and contain  *	a valid prefix.  *  * Returns:  * \li	ISC_R_NOMEMORY  * \li	ISC_R_SUCCESS  */
end_comment

begin_function_decl
name|void
name|isc_radix_remove
parameter_list|(
name|isc_radix_tree_t
modifier|*
name|radix
parameter_list|,
name|isc_radix_node_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Remove the node 'node' from the radix tree 'radix'.  *  * Requires:  * \li	'radix' to be valid.  * \li	'node' to be valid.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_radix_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_radix_tree_t
modifier|*
modifier|*
name|target
parameter_list|,
name|int
name|maxbits
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a radix tree with a maximum depth of 'maxbits';  *  * Requires:  * \li	'mctx' to be valid.  * \li	'target' to be non NULL and '*target' to be NULL.  * \li	'maxbits' to be less than or equal to RADIX_MAXBITS.  *  * Returns:  * \li	ISC_R_NOMEMORY  * \li	ISC_R_SUCCESS  */
end_comment

begin_function_decl
name|void
name|isc_radix_destroy
parameter_list|(
name|isc_radix_tree_t
modifier|*
name|radix
parameter_list|,
name|isc_radix_destroyfunc_t
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy a radix tree optionally calling 'func' to clean up node data.  *  * Requires:  * \li	'radix' to be valid.  */
end_comment

begin_function_decl
name|void
name|isc_radix_process
parameter_list|(
name|isc_radix_tree_t
modifier|*
name|radix
parameter_list|,
name|isc_radix_processfunc_t
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Walk a radix tree calling 'func' to process node data.  *  * Requires:  * \li	'radix' to be valid.  * \li	'func' to point to a function.  */
end_comment

begin_define
define|#
directive|define
name|RADIX_MAXBITS
value|128
end_define

begin_define
define|#
directive|define
name|RADIX_NBIT
parameter_list|(
name|x
parameter_list|)
value|(0x80>> ((x)& 0x7f))
end_define

begin_define
define|#
directive|define
name|RADIX_NBYTE
parameter_list|(
name|x
parameter_list|)
value|((x)>> 3)
end_define

begin_define
define|#
directive|define
name|RADIX_DATA_GET
parameter_list|(
name|node
parameter_list|,
name|type
parameter_list|)
value|(type *)((node)->data)
end_define

begin_define
define|#
directive|define
name|RADIX_DATA_SET
parameter_list|(
name|node
parameter_list|,
name|value
parameter_list|)
value|((node)->data = (void *)(value))
end_define

begin_define
define|#
directive|define
name|RADIX_WALK
parameter_list|(
name|Xhead
parameter_list|,
name|Xnode
parameter_list|)
define|\
value|do { \ 	isc_radix_node_t *Xstack[RADIX_MAXBITS+1]; \ 	isc_radix_node_t **Xsp = Xstack; \ 	isc_radix_node_t *Xrn = (Xhead); \ 	while ((Xnode = Xrn)) { \ 	    if (Xnode->prefix)
end_define

begin_define
define|#
directive|define
name|RADIX_WALK_ALL
parameter_list|(
name|Xhead
parameter_list|,
name|Xnode
parameter_list|)
define|\
value|do { \ 	isc_radix_node_t *Xstack[RADIX_MAXBITS+1]; \ 	isc_radix_node_t **Xsp = Xstack; \ 	isc_radix_node_t *Xrn = (Xhead); \ 	while ((Xnode = Xrn)) { \ 	    if (1)
end_define

begin_define
define|#
directive|define
name|RADIX_WALK_BREAK
value|{ \ 	    if (Xsp != Xstack) { \ 		Xrn = *(--Xsp); \ 	     } else { \ 		Xrn = (radix_node_t *) 0; \ 	    } \ 	    continue; }
end_define

begin_define
define|#
directive|define
name|RADIX_WALK_END
define|\
value|if (Xrn->l) { \ 		if (Xrn->r) { \ 		    *Xsp++ = Xrn->r; \ 		} \ 		Xrn = Xrn->l; \ 	    } else if (Xrn->r) { \ 		Xrn = Xrn->r; \ 	    } else if (Xsp != Xstack) { \ 		Xrn = *(--Xsp); \ 	    } else { \ 		Xrn = (isc_radix_node_t *) 0; \ 	    } \ 	} \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RADIX_H */
end_comment

end_unit

