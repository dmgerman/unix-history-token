begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *******************************************************************************  *  * cpp macro implementation of left-leaning 2-3 red-black trees.  Parent  * pointers are not used, and color bits are stored in the least significant  * bit of right-child pointers (if RB_COMPACT is defined), thus making node  * linkage as compact as is possible for red-black trees.  *  * Usage:  *  *   #include<stdint.h>  *   #include<stdbool.h>  *   #define NDEBUG // (Optional, see assert(3).)  *   #include<assert.h>  *   #define RB_COMPACT // (Optional, embed color bits in right-child pointers.)  *   #include<rb.h>  *   ...  *  *******************************************************************************  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RB_H_
end_ifndef

begin_define
define|#
directive|define
name|RB_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__PGI
end_ifndef

begin_define
define|#
directive|define
name|RB_COMPACT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RB_COMPACT
end_ifdef

begin_comment
comment|/* Node structure. */
end_comment

begin_define
define|#
directive|define
name|rb_node
parameter_list|(
name|a_type
parameter_list|)
define|\
value|struct {								\     a_type *rbn_left;							\     a_type *rbn_right_red;						\ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|rb_node
parameter_list|(
name|a_type
parameter_list|)
define|\
value|struct {								\     a_type *rbn_left;							\     a_type *rbn_right;							\     bool rbn_red;							\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Root structure. */
end_comment

begin_define
define|#
directive|define
name|rb_tree
parameter_list|(
name|a_type
parameter_list|)
define|\
value|struct {								\     a_type *rbt_root;							\ }
end_define

begin_comment
comment|/* Left accessors. */
end_comment

begin_define
define|#
directive|define
name|rbtn_left_get
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|)
define|\
value|((a_node)->a_field.rbn_left)
end_define

begin_define
define|#
directive|define
name|rbtn_left_set
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|,
name|a_left
parameter_list|)
value|do {		\     (a_node)->a_field.rbn_left = a_left;				\ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|RB_COMPACT
end_ifdef

begin_comment
comment|/* Right accessors. */
end_comment

begin_define
define|#
directive|define
name|rbtn_right_get
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|)
define|\
value|((a_type *) (((intptr_t) (a_node)->a_field.rbn_right_red)		\& ((ssize_t)-2)))
end_define

begin_define
define|#
directive|define
name|rbtn_right_set
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|,
name|a_right
parameter_list|)
value|do {		\     (a_node)->a_field.rbn_right_red = (a_type *) (((uintptr_t) a_right)	\       | (((uintptr_t) (a_node)->a_field.rbn_right_red)& ((size_t)1)));	\ } while (0)
end_define

begin_comment
comment|/* Color accessors. */
end_comment

begin_define
define|#
directive|define
name|rbtn_red_get
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|)
define|\
value|((bool) (((uintptr_t) (a_node)->a_field.rbn_right_red)		\& ((size_t)1)))
end_define

begin_define
define|#
directive|define
name|rbtn_color_set
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|,
name|a_red
parameter_list|)
value|do {		\     (a_node)->a_field.rbn_right_red = (a_type *) ((((intptr_t)		\       (a_node)->a_field.rbn_right_red)& ((ssize_t)-2))			\       | ((ssize_t)a_red));						\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbtn_red_set
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|)
value|do {			\     (a_node)->a_field.rbn_right_red = (a_type *) (((uintptr_t)		\       (a_node)->a_field.rbn_right_red) | ((size_t)1));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbtn_black_set
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|)
value|do {			\     (a_node)->a_field.rbn_right_red = (a_type *) (((intptr_t)		\       (a_node)->a_field.rbn_right_red)& ((ssize_t)-2));		\ } while (0)
end_define

begin_comment
comment|/* Node initializer. */
end_comment

begin_define
define|#
directive|define
name|rbt_node_new
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_rbt
parameter_list|,
name|a_node
parameter_list|)
value|do {		\
comment|/* Bookkeeping bit cannot be used by node pointer. */
value|\     assert(((uintptr_t)(a_node)& 0x1) == 0);				\     rbtn_left_set(a_type, a_field, (a_node), NULL);	\     rbtn_right_set(a_type, a_field, (a_node), NULL);	\     rbtn_red_set(a_type, a_field, (a_node));				\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Right accessors. */
end_comment

begin_define
define|#
directive|define
name|rbtn_right_get
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|)
define|\
value|((a_node)->a_field.rbn_right)
end_define

begin_define
define|#
directive|define
name|rbtn_right_set
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|,
name|a_right
parameter_list|)
value|do {		\     (a_node)->a_field.rbn_right = a_right;				\ } while (0)
end_define

begin_comment
comment|/* Color accessors. */
end_comment

begin_define
define|#
directive|define
name|rbtn_red_get
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|)
define|\
value|((a_node)->a_field.rbn_red)
end_define

begin_define
define|#
directive|define
name|rbtn_color_set
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|,
name|a_red
parameter_list|)
value|do {		\     (a_node)->a_field.rbn_red = (a_red);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbtn_red_set
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|)
value|do {			\     (a_node)->a_field.rbn_red = true;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbtn_black_set
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|)
value|do {			\     (a_node)->a_field.rbn_red = false;					\ } while (0)
end_define

begin_comment
comment|/* Node initializer. */
end_comment

begin_define
define|#
directive|define
name|rbt_node_new
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_rbt
parameter_list|,
name|a_node
parameter_list|)
value|do {		\     rbtn_left_set(a_type, a_field, (a_node), NULL);	\     rbtn_right_set(a_type, a_field, (a_node), NULL);	\     rbtn_red_set(a_type, a_field, (a_node));				\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tree initializer. */
end_comment

begin_define
define|#
directive|define
name|rb_new
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_rbt
parameter_list|)
value|do {				\     (a_rbt)->rbt_root = NULL;						\ } while (0)
end_define

begin_comment
comment|/* Internal utility macros. */
end_comment

begin_define
define|#
directive|define
name|rbtn_first
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_rbt
parameter_list|,
name|a_root
parameter_list|,
name|r_node
parameter_list|)
value|do {		\     (r_node) = (a_root);						\     if ((r_node) != NULL) {						\ 	for (;								\ 	  rbtn_left_get(a_type, a_field, (r_node)) != NULL;		\ 	  (r_node) = rbtn_left_get(a_type, a_field, (r_node))) {	\ 	}								\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbtn_last
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_rbt
parameter_list|,
name|a_root
parameter_list|,
name|r_node
parameter_list|)
value|do {		\     (r_node) = (a_root);						\     if ((r_node) != NULL) {						\ 	for (; rbtn_right_get(a_type, a_field, (r_node)) != NULL;	\ 	  (r_node) = rbtn_right_get(a_type, a_field, (r_node))) {	\ 	}								\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbtn_rotate_left
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|,
name|r_node
parameter_list|)
value|do {		\     (r_node) = rbtn_right_get(a_type, a_field, (a_node));		\     rbtn_right_set(a_type, a_field, (a_node),				\       rbtn_left_get(a_type, a_field, (r_node)));			\     rbtn_left_set(a_type, a_field, (r_node), (a_node));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbtn_rotate_right
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|,
name|r_node
parameter_list|)
value|do {		\     (r_node) = rbtn_left_get(a_type, a_field, (a_node));		\     rbtn_left_set(a_type, a_field, (a_node),				\       rbtn_right_get(a_type, a_field, (r_node)));			\     rbtn_right_set(a_type, a_field, (r_node), (a_node));		\ } while (0)
end_define

begin_comment
comment|/*  * The rb_proto() macro generates function prototypes that correspond to the  * functions generated by an equivalently parameterized call to rb_gen().  */
end_comment

begin_define
define|#
directive|define
name|rb_proto
parameter_list|(
name|a_attr
parameter_list|,
name|a_prefix
parameter_list|,
name|a_rbt_type
parameter_list|,
name|a_type
parameter_list|)
define|\
value|a_attr void								\ a_prefix##new(a_rbt_type *rbtree);					\ a_attr bool								\ a_prefix##empty(a_rbt_type *rbtree);					\ a_attr a_type *								\ a_prefix##first(a_rbt_type *rbtree);					\ a_attr a_type *								\ a_prefix##last(a_rbt_type *rbtree);					\ a_attr a_type *								\ a_prefix##next(a_rbt_type *rbtree, a_type *node);			\ a_attr a_type *								\ a_prefix##prev(a_rbt_type *rbtree, a_type *node);			\ a_attr a_type *								\ a_prefix##search(a_rbt_type *rbtree, const a_type *key);		\ a_attr a_type *								\ a_prefix##nsearch(a_rbt_type *rbtree, const a_type *key);		\ a_attr a_type *								\ a_prefix##psearch(a_rbt_type *rbtree, const a_type *key);		\ a_attr void								\ a_prefix##insert(a_rbt_type *rbtree, a_type *node);			\ a_attr void								\ a_prefix##remove(a_rbt_type *rbtree, a_type *node);			\ a_attr a_type *								\ a_prefix##iter(a_rbt_type *rbtree, a_type *start, a_type *(*cb)(	\   a_rbt_type *, a_type *, void *), void *arg);				\ a_attr a_type *								\ a_prefix##reverse_iter(a_rbt_type *rbtree, a_type *start,		\   a_type *(*cb)(a_rbt_type *, a_type *, void *), void *arg);		\ a_attr void								\ a_prefix##destroy(a_rbt_type *rbtree, void (*cb)(a_type *, void *),	\   void *arg);
end_define

begin_comment
comment|/*  * The rb_gen() macro generates a type-specific red-black tree implementation,  * based on the above cpp macros.  *  * Arguments:  *  *   a_attr    : Function attribute for generated functions (ex: static).  *   a_prefix  : Prefix for generated functions (ex: ex_).  *   a_rb_type : Type for red-black tree data structure (ex: ex_t).  *   a_type    : Type for red-black tree node data structure (ex: ex_node_t).  *   a_field   : Name of red-black tree node linkage (ex: ex_link).  *   a_cmp     : Node comparison function name, with the following prototype:  *                 int (a_cmp *)(a_type *a_node, a_type *a_other);  *                                       ^^^^^^  *                                    or a_key  *               Interpretation of comparison function return values:  *                 -1 : a_node<  a_other  *                  0 : a_node == a_other  *                  1 : a_node>  a_other  *               In all cases, the a_node or a_key macro argument is the first  *               argument to the comparison function, which makes it possible  *               to write comparison functions that treat the first argument  *               specially.  *  * Assuming the following setup:  *  *   typedef struct ex_node_s ex_node_t;  *   struct ex_node_s {  *       rb_node(ex_node_t) ex_link;  *   };  *   typedef rb_tree(ex_node_t) ex_t;  *   rb_gen(static, ex_, ex_t, ex_node_t, ex_link, ex_cmp)  *  * The following API is generated:  *  *   static void  *   ex_new(ex_t *tree);  *       Description: Initialize a red-black tree structure.  *       Args:  *         tree: Pointer to an uninitialized red-black tree object.  *  *   static bool  *   ex_empty(ex_t *tree);  *       Description: Determine whether tree is empty.  *       Args:  *         tree: Pointer to an initialized red-black tree object.  *       Ret: True if tree is empty, false otherwise.  *  *   static ex_node_t *  *   ex_first(ex_t *tree);  *   static ex_node_t *  *   ex_last(ex_t *tree);  *       Description: Get the first/last node in tree.  *       Args:  *         tree: Pointer to an initialized red-black tree object.  *       Ret: First/last node in tree, or NULL if tree is empty.  *  *   static ex_node_t *  *   ex_next(ex_t *tree, ex_node_t *node);  *   static ex_node_t *  *   ex_prev(ex_t *tree, ex_node_t *node);  *       Description: Get node's successor/predecessor.  *       Args:  *         tree: Pointer to an initialized red-black tree object.  *         node: A node in tree.  *       Ret: node's successor/predecessor in tree, or NULL if node is  *            last/first.  *  *   static ex_node_t *  *   ex_search(ex_t *tree, const ex_node_t *key);  *       Description: Search for node that matches key.  *       Args:  *         tree: Pointer to an initialized red-black tree object.  *         key : Search key.  *       Ret: Node in tree that matches key, or NULL if no match.  *  *   static ex_node_t *  *   ex_nsearch(ex_t *tree, const ex_node_t *key);  *   static ex_node_t *  *   ex_psearch(ex_t *tree, const ex_node_t *key);  *       Description: Search for node that matches key.  If no match is found,  *                    return what would be key's successor/predecessor, were  *                    key in tree.  *       Args:  *         tree: Pointer to an initialized red-black tree object.  *         key : Search key.  *       Ret: Node in tree that matches key, or if no match, hypothetical node's  *            successor/predecessor (NULL if no successor/predecessor).  *  *   static void  *   ex_insert(ex_t *tree, ex_node_t *node);  *       Description: Insert node into tree.  *       Args:  *         tree: Pointer to an initialized red-black tree object.  *         node: Node to be inserted into tree.  *  *   static void  *   ex_remove(ex_t *tree, ex_node_t *node);  *       Description: Remove node from tree.  *       Args:  *         tree: Pointer to an initialized red-black tree object.  *         node: Node in tree to be removed.  *  *   static ex_node_t *  *   ex_iter(ex_t *tree, ex_node_t *start, ex_node_t *(*cb)(ex_t *,  *     ex_node_t *, void *), void *arg);  *   static ex_node_t *  *   ex_reverse_iter(ex_t *tree, ex_node_t *start, ex_node *(*cb)(ex_t *,  *     ex_node_t *, void *), void *arg);  *       Description: Iterate forward/backward over tree, starting at node.  If  *                    tree is modified, iteration must be immediately  *                    terminated by the callback function that causes the  *                    modification.  *       Args:  *         tree : Pointer to an initialized red-black tree object.  *         start: Node at which to start iteration, or NULL to start at  *                first/last node.  *         cb   : Callback function, which is called for each node during  *                iteration.  Under normal circumstances the callback function  *                should return NULL, which causes iteration to continue.  If a  *                callback function returns non-NULL, iteration is immediately  *                terminated and the non-NULL return value is returned by the  *                iterator.  This is useful for re-starting iteration after  *                modifying tree.  *         arg  : Opaque pointer passed to cb().  *       Ret: NULL if iteration completed, or the non-NULL callback return value  *            that caused termination of the iteration.  *  *   static void  *   ex_destroy(ex_t *tree, void (*cb)(ex_node_t *, void *), void *arg);  *       Description: Iterate over the tree with post-order traversal, remove  *                    each node, and run the callback if non-null.  This is  *                    used for destroying a tree without paying the cost to  *                    rebalance it.  The tree must not be otherwise altered  *                    during traversal.  *       Args:  *         tree: Pointer to an initialized red-black tree object.  *         cb  : Callback function, which, if non-null, is called for each node  *               during iteration.  There is no way to stop iteration once it  *               has begun.  *         arg : Opaque pointer passed to cb().  */
end_comment

begin_define
define|#
directive|define
name|rb_gen
parameter_list|(
name|a_attr
parameter_list|,
name|a_prefix
parameter_list|,
name|a_rbt_type
parameter_list|,
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|)
define|\
value|a_attr void								\ a_prefix##new(a_rbt_type *rbtree) {					\     rb_new(a_type, a_field, rbtree);					\ }									\ a_attr bool								\ a_prefix##empty(a_rbt_type *rbtree) {					\     return (rbtree->rbt_root == NULL);					\ }									\ a_attr a_type *								\ a_prefix##first(a_rbt_type *rbtree) {					\     a_type *ret;							\     rbtn_first(a_type, a_field, rbtree, rbtree->rbt_root, ret);		\     return ret;								\ }									\ a_attr a_type *								\ a_prefix##last(a_rbt_type *rbtree) {					\     a_type *ret;							\     rbtn_last(a_type, a_field, rbtree, rbtree->rbt_root, ret);		\     return ret;								\ }									\ a_attr a_type *								\ a_prefix##next(a_rbt_type *rbtree, a_type *node) {			\     a_type *ret;							\     if (rbtn_right_get(a_type, a_field, node) != NULL) {		\ 	rbtn_first(a_type, a_field, rbtree, rbtn_right_get(a_type,	\ 	  a_field, node), ret);						\     } else {								\ 	a_type *tnode = rbtree->rbt_root;				\ 	assert(tnode != NULL);						\ 	ret = NULL;							\ 	while (true) {							\ 	    int cmp = (a_cmp)(node, tnode);				\ 	    if (cmp< 0) {						\ 		ret = tnode;						\ 		tnode = rbtn_left_get(a_type, a_field, tnode);		\ 	    } else if (cmp> 0) {					\ 		tnode = rbtn_right_get(a_type, a_field, tnode);		\ 	    } else {							\ 		break;							\ 	    }								\ 	    assert(tnode != NULL);					\ 	}								\     }									\     return ret;								\ }									\ a_attr a_type *								\ a_prefix##prev(a_rbt_type *rbtree, a_type *node) {			\     a_type *ret;							\     if (rbtn_left_get(a_type, a_field, node) != NULL) {			\ 	rbtn_last(a_type, a_field, rbtree, rbtn_left_get(a_type,	\ 	  a_field, node), ret);						\     } else {								\ 	a_type *tnode = rbtree->rbt_root;				\ 	assert(tnode != NULL);						\ 	ret = NULL;							\ 	while (true) {							\ 	    int cmp = (a_cmp)(node, tnode);				\ 	    if (cmp< 0) {						\ 		tnode = rbtn_left_get(a_type, a_field, tnode);		\ 	    } else if (cmp> 0) {					\ 		ret = tnode;						\ 		tnode = rbtn_right_get(a_type, a_field, tnode);		\ 	    } else {							\ 		break;							\ 	    }								\ 	    assert(tnode != NULL);					\ 	}								\     }									\     return ret;								\ }									\ a_attr a_type *								\ a_prefix##search(a_rbt_type *rbtree, const a_type *key) {		\     a_type *ret;							\     int cmp;								\     ret = rbtree->rbt_root;						\     while (ret != NULL							\&& (cmp = (a_cmp)(key, ret)) != 0) {				\ 	if (cmp< 0) {							\ 	    ret = rbtn_left_get(a_type, a_field, ret);			\ 	} else {							\ 	    ret = rbtn_right_get(a_type, a_field, ret);			\ 	}								\     }									\     return ret;								\ }									\ a_attr a_type *								\ a_prefix##nsearch(a_rbt_type *rbtree, const a_type *key) {		\     a_type *ret;							\     a_type *tnode = rbtree->rbt_root;					\     ret = NULL;								\     while (tnode != NULL) {						\ 	int cmp = (a_cmp)(key, tnode);					\ 	if (cmp< 0) {							\ 	    ret = tnode;						\ 	    tnode = rbtn_left_get(a_type, a_field, tnode);		\ 	} else if (cmp> 0) {						\ 	    tnode = rbtn_right_get(a_type, a_field, tnode);		\ 	} else {							\ 	    ret = tnode;						\ 	    break;							\ 	}								\     }									\     return ret;								\ }									\ a_attr a_type *								\ a_prefix##psearch(a_rbt_type *rbtree, const a_type *key) {		\     a_type *ret;							\     a_type *tnode = rbtree->rbt_root;					\     ret = NULL;								\     while (tnode != NULL) {						\ 	int cmp = (a_cmp)(key, tnode);					\ 	if (cmp< 0) {							\ 	    tnode = rbtn_left_get(a_type, a_field, tnode);		\ 	} else if (cmp> 0) {						\ 	    ret = tnode;						\ 	    tnode = rbtn_right_get(a_type, a_field, tnode);		\ 	} else {							\ 	    ret = tnode;						\ 	    break;							\ 	}								\     }									\     return ret;								\ }									\ a_attr void								\ a_prefix##insert(a_rbt_type *rbtree, a_type *node) {			\     struct {								\ 	a_type *node;							\ 	int cmp;							\     } path[sizeof(void *)<< 4], *pathp;				\     rbt_node_new(a_type, a_field, rbtree, node);			\
comment|/* Wind. */
value|\     path->node = rbtree->rbt_root;					\     for (pathp = path; pathp->node != NULL; pathp++) {			\ 	int cmp = pathp->cmp = a_cmp(node, pathp->node);		\ 	assert(cmp != 0);						\ 	if (cmp< 0) {							\ 	    pathp[1].node = rbtn_left_get(a_type, a_field,		\ 	      pathp->node);						\ 	} else {							\ 	    pathp[1].node = rbtn_right_get(a_type, a_field,		\ 	      pathp->node);						\ 	}								\     }									\     pathp->node = node;							\
comment|/* Unwind. */
value|\     for (pathp--; (uintptr_t)pathp>= (uintptr_t)path; pathp--) {	\ 	a_type *cnode = pathp->node;					\ 	if (pathp->cmp< 0) {						\ 	    a_type *left = pathp[1].node;				\ 	    rbtn_left_set(a_type, a_field, cnode, left);		\ 	    if (rbtn_red_get(a_type, a_field, left)) {			\ 		a_type *leftleft = rbtn_left_get(a_type, a_field, left);\ 		if (leftleft != NULL&& rbtn_red_get(a_type, a_field,	\ 		  leftleft)) {						\
comment|/* Fix up 4-node. */
value|\ 		    a_type *tnode;					\ 		    rbtn_black_set(a_type, a_field, leftleft);		\ 		    rbtn_rotate_right(a_type, a_field, cnode, tnode);	\ 		    cnode = tnode;					\ 		}							\ 	    } else {							\ 		return;							\ 	    }								\ 	} else {							\ 	    a_type *right = pathp[1].node;				\ 	    rbtn_right_set(a_type, a_field, cnode, right);		\ 	    if (rbtn_red_get(a_type, a_field, right)) {			\ 		a_type *left = rbtn_left_get(a_type, a_field, cnode);	\ 		if (left != NULL&& rbtn_red_get(a_type, a_field,	\ 		  left)) {						\
comment|/* Split 4-node. */
value|\ 		    rbtn_black_set(a_type, a_field, left);		\ 		    rbtn_black_set(a_type, a_field, right);		\ 		    rbtn_red_set(a_type, a_field, cnode);		\ 		} else {						\
comment|/* Lean left. */
value|\ 		    a_type *tnode;					\ 		    bool tred = rbtn_red_get(a_type, a_field, cnode);	\ 		    rbtn_rotate_left(a_type, a_field, cnode, tnode);	\ 		    rbtn_color_set(a_type, a_field, tnode, tred);	\ 		    rbtn_red_set(a_type, a_field, cnode);		\ 		    cnode = tnode;					\ 		}							\ 	    } else {							\ 		return;							\ 	    }								\ 	}								\ 	pathp->node = cnode;						\     }									\
comment|/* Set root, and make it black. */
value|\     rbtree->rbt_root = path->node;					\     rbtn_black_set(a_type, a_field, rbtree->rbt_root);			\ }									\ a_attr void								\ a_prefix##remove(a_rbt_type *rbtree, a_type *node) {			\     struct {								\ 	a_type *node;							\ 	int cmp;							\     } *pathp, *nodep, path[sizeof(void *)<< 4];			\
comment|/* Wind. */
value|\     nodep = NULL;
comment|/* Silence compiler warning. */
value|\     path->node = rbtree->rbt_root;					\     for (pathp = path; pathp->node != NULL; pathp++) {			\ 	int cmp = pathp->cmp = a_cmp(node, pathp->node);		\ 	if (cmp< 0) {							\ 	    pathp[1].node = rbtn_left_get(a_type, a_field,		\ 	      pathp->node);						\ 	} else {							\ 	    pathp[1].node = rbtn_right_get(a_type, a_field,		\ 	      pathp->node);						\ 	    if (cmp == 0) {						\
comment|/* Find node's successor, in preparation for swap. */
value|\ 		pathp->cmp = 1;						\ 		nodep = pathp;						\ 		for (pathp++; pathp->node != NULL; pathp++) {		\ 		    pathp->cmp = -1;					\ 		    pathp[1].node = rbtn_left_get(a_type, a_field,	\ 		      pathp->node);					\ 		}							\ 		break;							\ 	    }								\ 	}								\     }									\     assert(nodep->node == node);					\     pathp--;								\     if (pathp->node != node) {						\
comment|/* Swap node with its successor. */
value|\ 	bool tred = rbtn_red_get(a_type, a_field, pathp->node);		\ 	rbtn_color_set(a_type, a_field, pathp->node,			\ 	  rbtn_red_get(a_type, a_field, node));				\ 	rbtn_left_set(a_type, a_field, pathp->node,			\ 	  rbtn_left_get(a_type, a_field, node));			\
comment|/* If node's successor is its right child, the following code */
value|\
comment|/* will do the wrong thing for the right child pointer.       */
value|\
comment|/* However, it doesn't matter, because the pointer will be    */
value|\
comment|/* properly set when the successor is pruned.                 */
value|\ 	rbtn_right_set(a_type, a_field, pathp->node,			\ 	  rbtn_right_get(a_type, a_field, node));			\ 	rbtn_color_set(a_type, a_field, node, tred);			\
comment|/* The pruned leaf node's child pointers are never accessed   */
value|\
comment|/* again, so don't bother setting them to nil.                */
value|\ 	nodep->node = pathp->node;					\ 	pathp->node = node;						\ 	if (nodep == path) {						\ 	    rbtree->rbt_root = nodep->node;				\ 	} else {							\ 	    if (nodep[-1].cmp< 0) {					\ 		rbtn_left_set(a_type, a_field, nodep[-1].node,		\ 		  nodep->node);						\ 	    } else {							\ 		rbtn_right_set(a_type, a_field, nodep[-1].node,		\ 		  nodep->node);						\ 	    }								\ 	}								\     } else {								\ 	a_type *left = rbtn_left_get(a_type, a_field, node);		\ 	if (left != NULL) {						\
comment|/* node has no successor, but it has a left child.        */
value|\
comment|/* Splice node out, without losing the left child.        */
value|\ 	    assert(!rbtn_red_get(a_type, a_field, node));		\ 	    assert(rbtn_red_get(a_type, a_field, left));		\ 	    rbtn_black_set(a_type, a_field, left);			\ 	    if (pathp == path) {					\ 		rbtree->rbt_root = left;				\ 	    } else {							\ 		if (pathp[-1].cmp< 0) {				\ 		    rbtn_left_set(a_type, a_field, pathp[-1].node,	\ 		      left);						\ 		} else {						\ 		    rbtn_right_set(a_type, a_field, pathp[-1].node,	\ 		      left);						\ 		}							\ 	    }								\ 	    return;							\ 	} else if (pathp == path) {					\
comment|/* The tree only contained one node. */
value|\ 	    rbtree->rbt_root = NULL;					\ 	    return;							\ 	}								\     }									\     if (rbtn_red_get(a_type, a_field, pathp->node)) {			\
comment|/* Prune red node, which requires no fixup. */
value|\ 	assert(pathp[-1].cmp< 0);					\ 	rbtn_left_set(a_type, a_field, pathp[-1].node, NULL);		\ 	return;								\     }									\
comment|/* The node to be pruned is black, so unwind until balance is     */
value|\
comment|/* restored.                                                      */
value|\     pathp->node = NULL;							\     for (pathp--; (uintptr_t)pathp>= (uintptr_t)path; pathp--) {	\ 	assert(pathp->cmp != 0);					\ 	if (pathp->cmp< 0) {						\ 	    rbtn_left_set(a_type, a_field, pathp->node,			\ 	      pathp[1].node);						\ 	    if (rbtn_red_get(a_type, a_field, pathp->node)) {		\ 		a_type *right = rbtn_right_get(a_type, a_field,		\ 		  pathp->node);						\ 		a_type *rightleft = rbtn_left_get(a_type, a_field,	\ 		  right);						\ 		a_type *tnode;						\ 		if (rightleft != NULL&& rbtn_red_get(a_type, a_field,	\ 		  rightleft)) {						\
comment|/* In the following diagrams, ||, //, and \\      */
value|\
comment|/* indicate the path to the removed node.         */
value|\
comment|/*                                                */
value|\
comment|/*      ||                                        */
value|\
comment|/*    pathp(r)                                    */
value|\
comment|/*  //        \                                   */
value|\
comment|/* (b)        (b)                                 */
value|\
comment|/*           /                                    */
value|\
comment|/*          (r)                                   */
value|\
comment|/*                                                */
value|\ 		    rbtn_black_set(a_type, a_field, pathp->node);	\ 		    rbtn_rotate_right(a_type, a_field, right, tnode);	\ 		    rbtn_right_set(a_type, a_field, pathp->node, tnode);\ 		    rbtn_rotate_left(a_type, a_field, pathp->node,	\ 		      tnode);						\ 		} else {						\
comment|/*      ||                                        */
value|\
comment|/*    pathp(r)                                    */
value|\
comment|/*  //        \                                   */
value|\
comment|/* (b)        (b)                                 */
value|\
comment|/*           /                                    */
value|\
comment|/*          (b)                                   */
value|\
comment|/*                                                */
value|\ 		    rbtn_rotate_left(a_type, a_field, pathp->node,	\ 		      tnode);						\ 		}							\
comment|/* Balance restored, but rotation modified subtree    */
value|\
comment|/* root.                                              */
value|\ 		assert((uintptr_t)pathp> (uintptr_t)path);		\ 		if (pathp[-1].cmp< 0) {				\ 		    rbtn_left_set(a_type, a_field, pathp[-1].node,	\ 		      tnode);						\ 		} else {						\ 		    rbtn_right_set(a_type, a_field, pathp[-1].node,	\ 		      tnode);						\ 		}							\ 		return;							\ 	    } else {							\ 		a_type *right = rbtn_right_get(a_type, a_field,		\ 		  pathp->node);						\ 		a_type *rightleft = rbtn_left_get(a_type, a_field,	\ 		  right);						\ 		if (rightleft != NULL&& rbtn_red_get(a_type, a_field,	\ 		  rightleft)) {						\
comment|/*      ||                                        */
value|\
comment|/*    pathp(b)                                    */
value|\
comment|/*  //        \                                   */
value|\
comment|/* (b)        (b)                                 */
value|\
comment|/*           /                                    */
value|\
comment|/*          (r)                                   */
value|\ 		    a_type *tnode;					\ 		    rbtn_black_set(a_type, a_field, rightleft);		\ 		    rbtn_rotate_right(a_type, a_field, right, tnode);	\ 		    rbtn_right_set(a_type, a_field, pathp->node, tnode);\ 		    rbtn_rotate_left(a_type, a_field, pathp->node,	\ 		      tnode);						\
comment|/* Balance restored, but rotation modified        */
value|\
comment|/* subtree root, which may actually be the tree   */
value|\
comment|/* root.                                          */
value|\ 		    if (pathp == path) {				\
comment|/* Set root. */
value|\ 			rbtree->rbt_root = tnode;			\ 		    } else {						\ 			if (pathp[-1].cmp< 0) {			\ 			    rbtn_left_set(a_type, a_field,		\ 			      pathp[-1].node, tnode);			\ 			} else {					\ 			    rbtn_right_set(a_type, a_field,		\ 			      pathp[-1].node, tnode);			\ 			}						\ 		    }							\ 		    return;						\ 		} else {						\
comment|/*      ||                                        */
value|\
comment|/*    pathp(b)                                    */
value|\
comment|/*  //        \                                   */
value|\
comment|/* (b)        (b)                                 */
value|\
comment|/*           /                                    */
value|\
comment|/*          (b)                                   */
value|\ 		    a_type *tnode;					\ 		    rbtn_red_set(a_type, a_field, pathp->node);		\ 		    rbtn_rotate_left(a_type, a_field, pathp->node,	\ 		      tnode);						\ 		    pathp->node = tnode;				\ 		}							\ 	    }								\ 	} else {							\ 	    a_type *left;						\ 	    rbtn_right_set(a_type, a_field, pathp->node,		\ 	      pathp[1].node);						\ 	    left = rbtn_left_get(a_type, a_field, pathp->node);		\ 	    if (rbtn_red_get(a_type, a_field, left)) {			\ 		a_type *tnode;						\ 		a_type *leftright = rbtn_right_get(a_type, a_field,	\ 		  left);						\ 		a_type *leftrightleft = rbtn_left_get(a_type, a_field,	\ 		  leftright);						\ 		if (leftrightleft != NULL&& rbtn_red_get(a_type,	\ 		  a_field, leftrightleft)) {				\
comment|/*      ||                                        */
value|\
comment|/*    pathp(b)                                    */
value|\
comment|/*   /        \\                                  */
value|\
comment|/* (r)        (b)                                 */
value|\
comment|/*   \                                            */
value|\
comment|/*   (b)                                          */
value|\
comment|/*   /                                            */
value|\
comment|/* (r)                                            */
value|\ 		    a_type *unode;					\ 		    rbtn_black_set(a_type, a_field, leftrightleft);	\ 		    rbtn_rotate_right(a_type, a_field, pathp->node,	\ 		      unode);						\ 		    rbtn_rotate_right(a_type, a_field, pathp->node,	\ 		      tnode);						\ 		    rbtn_right_set(a_type, a_field, unode, tnode);	\ 		    rbtn_rotate_left(a_type, a_field, unode, tnode);	\ 		} else {						\
comment|/*      ||                                        */
value|\
comment|/*    pathp(b)                                    */
value|\
comment|/*   /        \\                                  */
value|\
comment|/* (r)        (b)                                 */
value|\
comment|/*   \                                            */
value|\
comment|/*   (b)                                          */
value|\
comment|/*   /                                            */
value|\
comment|/* (b)                                            */
value|\ 		    assert(leftright != NULL);				\ 		    rbtn_red_set(a_type, a_field, leftright);		\ 		    rbtn_rotate_right(a_type, a_field, pathp->node,	\ 		      tnode);						\ 		    rbtn_black_set(a_type, a_field, tnode);		\ 		}							\
comment|/* Balance restored, but rotation modified subtree    */
value|\
comment|/* root, which may actually be the tree root.         */
value|\ 		if (pathp == path) {					\
comment|/* Set root. */
value|\ 		    rbtree->rbt_root = tnode;				\ 		} else {						\ 		    if (pathp[-1].cmp< 0) {				\ 			rbtn_left_set(a_type, a_field, pathp[-1].node,	\ 			  tnode);					\ 		    } else {						\ 			rbtn_right_set(a_type, a_field, pathp[-1].node,	\ 			  tnode);					\ 		    }							\ 		}							\ 		return;							\ 	    } else if (rbtn_red_get(a_type, a_field, pathp->node)) {	\ 		a_type *leftleft = rbtn_left_get(a_type, a_field, left);\ 		if (leftleft != NULL&& rbtn_red_get(a_type, a_field,	\ 		  leftleft)) {						\
comment|/*        ||                                      */
value|\
comment|/*      pathp(r)                                  */
value|\
comment|/*     /        \\                                */
value|\
comment|/*   (b)        (b)                               */
value|\
comment|/*   /                                            */
value|\
comment|/* (r)                                            */
value|\ 		    a_type *tnode;					\ 		    rbtn_black_set(a_type, a_field, pathp->node);	\ 		    rbtn_red_set(a_type, a_field, left);		\ 		    rbtn_black_set(a_type, a_field, leftleft);		\ 		    rbtn_rotate_right(a_type, a_field, pathp->node,	\ 		      tnode);						\
comment|/* Balance restored, but rotation modified        */
value|\
comment|/* subtree root.                                  */
value|\ 		    assert((uintptr_t)pathp> (uintptr_t)path);		\ 		    if (pathp[-1].cmp< 0) {				\ 			rbtn_left_set(a_type, a_field, pathp[-1].node,	\ 			  tnode);					\ 		    } else {						\ 			rbtn_right_set(a_type, a_field, pathp[-1].node,	\ 			  tnode);					\ 		    }							\ 		    return;						\ 		} else {						\
comment|/*        ||                                      */
value|\
comment|/*      pathp(r)                                  */
value|\
comment|/*     /        \\                                */
value|\
comment|/*   (b)        (b)                               */
value|\
comment|/*   /                                            */
value|\
comment|/* (b)                                            */
value|\ 		    rbtn_red_set(a_type, a_field, left);		\ 		    rbtn_black_set(a_type, a_field, pathp->node);	\
comment|/* Balance restored. */
value|\ 		    return;						\ 		}							\ 	    } else {							\ 		a_type *leftleft = rbtn_left_get(a_type, a_field, left);\ 		if (leftleft != NULL&& rbtn_red_get(a_type, a_field,	\ 		  leftleft)) {						\
comment|/*               ||                               */
value|\
comment|/*             pathp(b)                           */
value|\
comment|/*            /        \\                         */
value|\
comment|/*          (b)        (b)                        */
value|\
comment|/*          /                                     */
value|\
comment|/*        (r)                                     */
value|\ 		    a_type *tnode;					\ 		    rbtn_black_set(a_type, a_field, leftleft);		\ 		    rbtn_rotate_right(a_type, a_field, pathp->node,	\ 		      tnode);						\
comment|/* Balance restored, but rotation modified        */
value|\
comment|/* subtree root, which may actually be the tree   */
value|\
comment|/* root.                                          */
value|\ 		    if (pathp == path) {				\
comment|/* Set root. */
value|\ 			rbtree->rbt_root = tnode;			\ 		    } else {						\ 			if (pathp[-1].cmp< 0) {			\ 			    rbtn_left_set(a_type, a_field,		\ 			      pathp[-1].node, tnode);			\ 			} else {					\ 			    rbtn_right_set(a_type, a_field,		\ 			      pathp[-1].node, tnode);			\ 			}						\ 		    }							\ 		    return;						\ 		} else {						\
comment|/*               ||                               */
value|\
comment|/*             pathp(b)                           */
value|\
comment|/*            /        \\                         */
value|\
comment|/*          (b)        (b)                        */
value|\
comment|/*          /                                     */
value|\
comment|/*        (b)                                     */
value|\ 		    rbtn_red_set(a_type, a_field, left);		\ 		}							\ 	    }								\ 	}								\     }									\
comment|/* Set root. */
value|\     rbtree->rbt_root = path->node;					\     assert(!rbtn_red_get(a_type, a_field, rbtree->rbt_root));		\ }									\ a_attr a_type *								\ a_prefix##iter_recurse(a_rbt_type *rbtree, a_type *node,		\   a_type *(*cb)(a_rbt_type *, a_type *, void *), void *arg) {		\     if (node == NULL) {							\ 	return NULL;							\     } else {								\ 	a_type *ret;							\ 	if ((ret = a_prefix##iter_recurse(rbtree, rbtn_left_get(a_type,	\ 	  a_field, node), cb, arg)) != NULL || (ret = cb(rbtree, node,	\ 	  arg)) != NULL) {						\ 	    return ret;							\ 	}								\ 	return a_prefix##iter_recurse(rbtree, rbtn_right_get(a_type,	\ 	  a_field, node), cb, arg);					\     }									\ }									\ a_attr a_type *								\ a_prefix##iter_start(a_rbt_type *rbtree, a_type *start, a_type *node,	\   a_type *(*cb)(a_rbt_type *, a_type *, void *), void *arg) {		\     int cmp = a_cmp(start, node);					\     if (cmp< 0) {							\ 	a_type *ret;							\ 	if ((ret = a_prefix##iter_start(rbtree, start,			\ 	  rbtn_left_get(a_type, a_field, node), cb, arg)) != NULL ||	\ 	  (ret = cb(rbtree, node, arg)) != NULL) {			\ 	    return ret;							\ 	}								\ 	return a_prefix##iter_recurse(rbtree, rbtn_right_get(a_type,	\ 	  a_field, node), cb, arg);					\     } else if (cmp> 0) {						\ 	return a_prefix##iter_start(rbtree, start,			\ 	  rbtn_right_get(a_type, a_field, node), cb, arg);		\     } else {								\ 	a_type *ret;							\ 	if ((ret = cb(rbtree, node, arg)) != NULL) {			\ 	    return ret;							\ 	}								\ 	return a_prefix##iter_recurse(rbtree, rbtn_right_get(a_type,	\ 	  a_field, node), cb, arg);					\     }									\ }									\ a_attr a_type *								\ a_prefix##iter(a_rbt_type *rbtree, a_type *start, a_type *(*cb)(	\   a_rbt_type *, a_type *, void *), void *arg) {				\     a_type *ret;							\     if (start != NULL) {						\ 	ret = a_prefix##iter_start(rbtree, start, rbtree->rbt_root,	\ 	  cb, arg);							\     } else {								\ 	ret = a_prefix##iter_recurse(rbtree, rbtree->rbt_root, cb, arg);\     }									\     return ret;								\ }									\ a_attr a_type *								\ a_prefix##reverse_iter_recurse(a_rbt_type *rbtree, a_type *node,	\   a_type *(*cb)(a_rbt_type *, a_type *, void *), void *arg) {		\     if (node == NULL) {							\ 	return NULL;							\     } else {								\ 	a_type *ret;							\ 	if ((ret = a_prefix##reverse_iter_recurse(rbtree,		\ 	  rbtn_right_get(a_type, a_field, node), cb, arg)) != NULL ||	\ 	  (ret = cb(rbtree, node, arg)) != NULL) {			\ 	    return ret;							\ 	}								\ 	return a_prefix##reverse_iter_recurse(rbtree,			\ 	  rbtn_left_get(a_type, a_field, node), cb, arg);		\     }									\ }									\ a_attr a_type *								\ a_prefix##reverse_iter_start(a_rbt_type *rbtree, a_type *start,		\   a_type *node, a_type *(*cb)(a_rbt_type *, a_type *, void *),		\   void *arg) {								\     int cmp = a_cmp(start, node);					\     if (cmp> 0) {							\ 	a_type *ret;							\ 	if ((ret = a_prefix##reverse_iter_start(rbtree, start,		\ 	  rbtn_right_get(a_type, a_field, node), cb, arg)) != NULL ||	\ 	  (ret = cb(rbtree, node, arg)) != NULL) {			\ 	    return ret;							\ 	}								\ 	return a_prefix##reverse_iter_recurse(rbtree,			\ 	  rbtn_left_get(a_type, a_field, node), cb, arg);		\     } else if (cmp< 0) {						\ 	return a_prefix##reverse_iter_start(rbtree, start,		\ 	  rbtn_left_get(a_type, a_field, node), cb, arg);		\     } else {								\ 	a_type *ret;							\ 	if ((ret = cb(rbtree, node, arg)) != NULL) {			\ 	    return ret;							\ 	}								\ 	return a_prefix##reverse_iter_recurse(rbtree,			\ 	  rbtn_left_get(a_type, a_field, node), cb, arg);		\     }									\ }									\ a_attr a_type *								\ a_prefix##reverse_iter(a_rbt_type *rbtree, a_type *start,		\   a_type *(*cb)(a_rbt_type *, a_type *, void *), void *arg) {		\     a_type *ret;							\     if (start != NULL) {						\ 	ret = a_prefix##reverse_iter_start(rbtree, start,		\ 	  rbtree->rbt_root, cb, arg);					\     } else {								\ 	ret = a_prefix##reverse_iter_recurse(rbtree, rbtree->rbt_root,	\ 	  cb, arg);							\     }									\     return ret;								\ }									\ a_attr void								\ a_prefix##destroy_recurse(a_rbt_type *rbtree, a_type *node, void (*cb)(	\   a_type *, void *), void *arg) {					\     if (node == NULL) {							\ 	return;								\     }									\     a_prefix##destroy_recurse(rbtree, rbtn_left_get(a_type, a_field,	\       node), cb, arg);							\     rbtn_left_set(a_type, a_field, (node), NULL);			\     a_prefix##destroy_recurse(rbtree, rbtn_right_get(a_type, a_field,	\       node), cb, arg);							\     rbtn_right_set(a_type, a_field, (node), NULL);			\     if (cb) {								\ 	cb(node, arg);							\     }									\ }									\ a_attr void								\ a_prefix##destroy(a_rbt_type *rbtree, void (*cb)(a_type *, void *),	\   void *arg) {								\     a_prefix##destroy_recurse(rbtree, rbtree->rbt_root, cb, arg);	\     rbtree->rbt_root = NULL;						\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RB_H_ */
end_comment

end_unit

