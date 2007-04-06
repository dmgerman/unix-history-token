begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AVL_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_AVL_IMPL_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_comment
comment|/*  * This is a private header file.  Applications should not directly include  * this file.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * generic AVL tree implementation for kernel use  *  * There are 5 pieces of information stored for each node in an AVL tree  *  * 	pointer to less than child  * 	pointer to greater than child  * 	a pointer to the parent of this node  *	an indication  [0/1]  of which child I am of my parent  * 	a "balance" (-1, 0, +1)  indicating which child tree is taller  *  * Since they only need 3 bits, the last two fields are packed into the  * bottom bits of the parent pointer on 64 bit machines to save on space.  */
ifndef|#
directive|ifndef
name|_LP64
struct|struct
name|avl_node
block|{
name|struct
name|avl_node
modifier|*
name|avl_child
index|[
literal|2
index|]
decl_stmt|;
comment|/* left/right children */
name|struct
name|avl_node
modifier|*
name|avl_parent
decl_stmt|;
comment|/* this node's parent */
name|unsigned
name|short
name|avl_child_index
decl_stmt|;
comment|/* my index in parent's avl_child[] */
name|short
name|avl_balance
decl_stmt|;
comment|/* balance value: -1, 0, +1 */
block|}
struct|;
define|#
directive|define
name|AVL_XPARENT
parameter_list|(
name|n
parameter_list|)
value|((n)->avl_parent)
define|#
directive|define
name|AVL_SETPARENT
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((n)->avl_parent = (p))
define|#
directive|define
name|AVL_XCHILD
parameter_list|(
name|n
parameter_list|)
value|((n)->avl_child_index)
define|#
directive|define
name|AVL_SETCHILD
parameter_list|(
name|n
parameter_list|,
name|c
parameter_list|)
value|((n)->avl_child_index = (unsigned short)(c))
define|#
directive|define
name|AVL_XBALANCE
parameter_list|(
name|n
parameter_list|)
value|((n)->avl_balance)
define|#
directive|define
name|AVL_SETBALANCE
parameter_list|(
name|n
parameter_list|,
name|b
parameter_list|)
value|((n)->avl_balance = (short)(b))
else|#
directive|else
comment|/* _LP64 */
comment|/*  * for 64 bit machines, avl_pcb contains parent pointer, balance and child_index  * values packed in the following manner:  *  * |63                                  3|        2        |1          0 |  * |-------------------------------------|-----------------|-------------|  * |      avl_parent hi order bits       | avl_child_index | avl_balance |  * |                                     |                 |     + 1     |  * |-------------------------------------|-----------------|-------------|  *  */
struct|struct
name|avl_node
block|{
name|struct
name|avl_node
modifier|*
name|avl_child
index|[
literal|2
index|]
decl_stmt|;
comment|/* left/right children nodes */
name|uintptr_t
name|avl_pcb
decl_stmt|;
comment|/* parent, child_index, balance */
block|}
struct|;
comment|/*  * macros to extract/set fields in avl_pcb  *  * pointer to the parent of the current node is the high order bits  */
define|#
directive|define
name|AVL_XPARENT
parameter_list|(
name|n
parameter_list|)
value|((struct avl_node *)((n)->avl_pcb& ~7))
define|#
directive|define
name|AVL_SETPARENT
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|((n)->avl_pcb = (((n)->avl_pcb& 7) | (uintptr_t)(p)))
comment|/*  * index of this node in its parent's avl_child[]: bit #2  */
define|#
directive|define
name|AVL_XCHILD
parameter_list|(
name|n
parameter_list|)
value|(((n)->avl_pcb>> 2)& 1)
define|#
directive|define
name|AVL_SETCHILD
parameter_list|(
name|n
parameter_list|,
name|c
parameter_list|)
define|\
value|((n)->avl_pcb = (uintptr_t)(((n)->avl_pcb& ~4) | ((c)<< 2)))
comment|/*  * balance indication for a node, lowest 2 bits. A valid balance is  * -1, 0, or +1, and is encoded by adding 1 to the value to get the  * unsigned values of 0, 1, 2.  */
define|#
directive|define
name|AVL_XBALANCE
parameter_list|(
name|n
parameter_list|)
value|((int)(((n)->avl_pcb& 3) - 1))
define|#
directive|define
name|AVL_SETBALANCE
parameter_list|(
name|n
parameter_list|,
name|b
parameter_list|)
define|\
value|((n)->avl_pcb = (uintptr_t)((((n)->avl_pcb& ~3) | ((b) + 1))))
endif|#
directive|endif
comment|/* _LP64 */
comment|/*  * switch between a node and data pointer for a given tree  * the value of "o" is tree->avl_offset  */
define|#
directive|define
name|AVL_NODE2DATA
parameter_list|(
name|n
parameter_list|,
name|o
parameter_list|)
value|((void *)((uintptr_t)(n) - (o)))
define|#
directive|define
name|AVL_DATA2NODE
parameter_list|(
name|d
parameter_list|,
name|o
parameter_list|)
value|((struct avl_node *)((uintptr_t)(d) + (o)))
comment|/*  * macros used to create/access an avl_index_t  */
define|#
directive|define
name|AVL_INDEX2NODE
parameter_list|(
name|x
parameter_list|)
value|((avl_node_t *)((x)& ~1))
define|#
directive|define
name|AVL_INDEX2CHILD
parameter_list|(
name|x
parameter_list|)
value|((x)& 1)
define|#
directive|define
name|AVL_MKINDEX
parameter_list|(
name|n
parameter_list|,
name|c
parameter_list|)
value|((avl_index_t)(n) | (c))
comment|/*  * The tree structure. The fields avl_root, avl_compar, and avl_offset come  * first since they are needed for avl_find().  We want them to fit into  * a single 64 byte cache line to make avl_find() as fast as possible.  */
struct|struct
name|avl_tree
block|{
name|struct
name|avl_node
modifier|*
name|avl_root
decl_stmt|;
comment|/* root node in tree */
name|int
function_decl|(
modifier|*
name|avl_compar
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
name|size_t
name|avl_offset
decl_stmt|;
comment|/* offsetof(type, avl_link_t field) */
name|ulong_t
name|avl_numnodes
decl_stmt|;
comment|/* number of nodes in the tree */
name|size_t
name|avl_size
decl_stmt|;
comment|/* sizeof user type struct */
block|}
struct|;
comment|/*  * This will only by used via AVL_NEXT() or AVL_PREV()  */
specifier|extern
name|void
modifier|*
name|avl_walk
parameter_list|(
name|struct
name|avl_tree
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AVL_IMPL_H */
end_comment

end_unit

