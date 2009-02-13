begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AVL_H
end_ifndef

begin_define
define|#
directive|define
name|_AVL_H
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
include|#
directive|include
file|<sys/avl_impl.h>
comment|/*  * This is a generic implemenatation of AVL trees for use in the Solaris kernel.  * The interfaces provide an efficient way of implementing an ordered set of  * data structures.  *  * AVL trees provide an alternative to using an ordered linked list. Using AVL  * trees will usually be faster, however they requires more storage. An ordered  * linked list in general requires 2 pointers in each data structure. The  * AVL tree implementation uses 3 pointers. The following chart gives the  * approximate performance of operations with the different approaches:  *  *	Operation	 Link List	AVL tree  *	---------	 --------	--------  *	lookup		   O(n)		O(log(n))  *  *	insert 1 node	 constant	constant  *  *	delete 1 node	 constant	between constant and O(log(n))  *  *	delete all nodes   O(n)		O(n)  *  *	visit the next  *	or prev node	 constant	between constant and O(log(n))  *  *  * The data structure nodes are anchored at an "avl_tree_t" (the equivalent  * of a list header) and the individual nodes will have a field of  * type "avl_node_t" (corresponding to list pointers).  *  * The type "avl_index_t" is used to indicate a position in the list for  * certain calls.  *  * The usage scenario is generally:  *  * 1. Create the list/tree with: avl_create()  *  * followed by any mixture of:  *  * 2a. Insert nodes with: avl_add(), or avl_find() and avl_insert()  *  * 2b. Visited elements with:  *	 avl_first() - returns the lowest valued node  *	 avl_last() - returns the highest valued node  *	 AVL_NEXT() - given a node go to next higher one  *	 AVL_PREV() - given a node go to previous lower one  *  * 2c.  Find the node with the closest value either less than or greater  *	than a given value with avl_nearest().  *  * 2d. Remove individual nodes from the list/tree with avl_remove().  *  * and finally when the list is being destroyed  *  * 3. Use avl_destroy_nodes() to quickly process/free up any remaining nodes.  *    Note that once you use avl_destroy_nodes(), you can no longer  *    use any routine except avl_destroy_nodes() and avl_destoy().  *  * 4. Use avl_destroy() to destroy the AVL tree itself.  *  * Any locking for multiple thread access is up to the user to provide, just  * as is needed for any linked list implementation.  */
comment|/*  * Type used for the root of the AVL tree.  */
typedef|typedef
name|struct
name|avl_tree
name|avl_tree_t
typedef|;
comment|/*  * The data nodes in the AVL tree must have a field of this type.  */
typedef|typedef
name|struct
name|avl_node
name|avl_node_t
typedef|;
comment|/*  * An opaque type used to locate a position in the tree where a node  * would be inserted.  */
typedef|typedef
name|uintptr_t
name|avl_index_t
typedef|;
comment|/*  * Direction constants used for avl_nearest().  */
define|#
directive|define
name|AVL_BEFORE
value|(0)
define|#
directive|define
name|AVL_AFTER
value|(1)
comment|/*  * Prototypes  *  * Where not otherwise mentioned, "void *" arguments are a pointer to the  * user data structure which must contain a field of type avl_node_t.  *  * Also assume the user data structures looks like:  *	stuct my_type {  *		...  *		avl_node_t	my_link;  *		...  *	};  */
comment|/*  * Initialize an AVL tree. Arguments are:  *  * tree   - the tree to be initialized  * compar - function to compare two nodes, it must return exactly: -1, 0, or +1  *          -1 for<, 0 for ==, and +1 for>  * size   - the value of sizeof(struct my_type)  * offset - the value of OFFSETOF(struct my_type, my_link)  */
specifier|extern
name|void
name|avl_create
parameter_list|(
name|avl_tree_t
modifier|*
name|tree
parameter_list|,
name|int
function_decl|(
modifier|*
name|compar
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
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|offset
parameter_list|)
function_decl|;
comment|/*  * Find a node with a matching value in the tree. Returns the matching node  * found. If not found, it returns NULL and then if "where" is not NULL it sets  * "where" for use with avl_insert() or avl_nearest().  *  * node   - node that has the value being looked for  * where  - position for use with avl_nearest() or avl_insert(), may be NULL  */
specifier|extern
name|void
modifier|*
name|avl_find
parameter_list|(
name|avl_tree_t
modifier|*
name|tree
parameter_list|,
name|void
modifier|*
name|node
parameter_list|,
name|avl_index_t
modifier|*
name|where
parameter_list|)
function_decl|;
comment|/*  * Insert a node into the tree.  *  * node   - the node to insert  * where  - position as returned from avl_find()  */
specifier|extern
name|void
name|avl_insert
parameter_list|(
name|avl_tree_t
modifier|*
name|tree
parameter_list|,
name|void
modifier|*
name|node
parameter_list|,
name|avl_index_t
name|where
parameter_list|)
function_decl|;
comment|/*  * Insert "new_data" in "tree" in the given "direction" either after  * or before the data "here".  *  * This might be usefull for avl clients caching recently accessed  * data to avoid doing avl_find() again for insertion.  *  * new_data	- new data to insert  * here  	- existing node in "tree"  * direction	- either AVL_AFTER or AVL_BEFORE the data "here".  */
specifier|extern
name|void
name|avl_insert_here
parameter_list|(
name|avl_tree_t
modifier|*
name|tree
parameter_list|,
name|void
modifier|*
name|new_data
parameter_list|,
name|void
modifier|*
name|here
parameter_list|,
name|int
name|direction
parameter_list|)
function_decl|;
comment|/*  * Return the first or last valued node in the tree. Will return NULL  * if the tree is empty.  *  */
specifier|extern
name|void
modifier|*
name|avl_first
parameter_list|(
name|avl_tree_t
modifier|*
name|tree
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|avl_last
parameter_list|(
name|avl_tree_t
modifier|*
name|tree
parameter_list|)
function_decl|;
comment|/*  * Return the next or previous valued node in the tree.  * AVL_NEXT() will return NULL if at the last node.  * AVL_PREV() will return NULL if at the first node.  *  * node   - the node from which the next or previous node is found  */
define|#
directive|define
name|AVL_NEXT
parameter_list|(
name|tree
parameter_list|,
name|node
parameter_list|)
value|avl_walk(tree, node, AVL_AFTER)
define|#
directive|define
name|AVL_PREV
parameter_list|(
name|tree
parameter_list|,
name|node
parameter_list|)
value|avl_walk(tree, node, AVL_BEFORE)
comment|/*  * Find the node with the nearest value either greater or less than  * the value from a previous avl_find(). Returns the node or NULL if  * there isn't a matching one.  *  * where     - position as returned from avl_find()  * direction - either AVL_BEFORE or AVL_AFTER  *  * EXAMPLE get the greatest node that is less than a given value:  *  *	avl_tree_t *tree;  *	struct my_data look_for_value = {....};  *	struct my_data *node;  *	struct my_data *less;  *	avl_index_t where;  *  *	node = avl_find(tree,&look_for_value,&where);  *	if (node != NULL)  *		less = AVL_PREV(tree, node);  *	else  *		less = avl_nearest(tree, where, AVL_BEFORE);  */
specifier|extern
name|void
modifier|*
name|avl_nearest
parameter_list|(
name|avl_tree_t
modifier|*
name|tree
parameter_list|,
name|avl_index_t
name|where
parameter_list|,
name|int
name|direction
parameter_list|)
function_decl|;
comment|/*  * Add a single node to the tree.  * The node must not be in the tree, and it must not  * compare equal to any other node already in the tree.  *  * node   - the node to add  */
specifier|extern
name|void
name|avl_add
parameter_list|(
name|avl_tree_t
modifier|*
name|tree
parameter_list|,
name|void
modifier|*
name|node
parameter_list|)
function_decl|;
comment|/*  * Remove a single node from the tree.  The node must be in the tree.  *  * node   - the node to remove  */
specifier|extern
name|void
name|avl_remove
parameter_list|(
name|avl_tree_t
modifier|*
name|tree
parameter_list|,
name|void
modifier|*
name|node
parameter_list|)
function_decl|;
comment|/*  * Return the number of nodes in the tree  */
specifier|extern
name|ulong_t
name|avl_numnodes
parameter_list|(
name|avl_tree_t
modifier|*
name|tree
parameter_list|)
function_decl|;
comment|/*  * Used to destroy any remaining nodes in a tree. The cookie argument should  * be initialized to NULL before the first call. Returns a node that has been  * removed from the tree and may be free()'d. Returns NULL when the tree is  * empty.  *  * Once you call avl_destroy_nodes(), you can only continuing calling it and  * finally avl_destroy(). No other AVL routines will be valid.  *  * cookie - a "void *" used to save state between calls to avl_destroy_nodes()  *  * EXAMPLE:  *	avl_tree_t *tree;  *	struct my_data *node;  *	void *cookie;  *  *	cookie = NULL;  *	while ((node = avl_destroy_nodes(tree,&cookie)) != NULL)  *		free(node);  *	avl_destroy(tree);  */
specifier|extern
name|void
modifier|*
name|avl_destroy_nodes
parameter_list|(
name|avl_tree_t
modifier|*
name|tree
parameter_list|,
name|void
modifier|*
modifier|*
name|cookie
parameter_list|)
function_decl|;
comment|/*  * Final destroy of an AVL tree. Arguments are:  *  * tree   - the empty tree to destroy  */
specifier|extern
name|void
name|avl_destroy
parameter_list|(
name|avl_tree_t
modifier|*
name|tree
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
comment|/* _AVL_H */
end_comment

end_unit

