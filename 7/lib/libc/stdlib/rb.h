begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Copyright (C) 2008 Jason Evans<jasone@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer  *    unmodified other than the allowable addition of one or more  *    copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  ******************************************************************************  *  * cpp macro implementation of left-leaning red-black trees.  *  * Usage:  *  *   (Optional, see assert(3).)  *   #define NDEBUG  *  *   (Required.)  *   #include<assert.h>  *   #include<rb.h>  *   ...  *  * All operations are done non-recursively.  Parent pointers are not used, and  * color bits are stored in the least significant bit of right-child pointers,  * thus making node linkage as compact as is possible for red-black trees.  *  * Some macros use a comparison function pointer, which is expected to have the  * following prototype:  *  *   int (a_cmp *)(a_type *a_node, a_type *a_other);  *                         ^^^^^^  *                      or a_key  *  * Interpretation of comparision function return values:  *  *   -1 : a_node<  a_other  *    0 : a_node == a_other  *    1 : a_node>  a_other  *  * In all cases, the a_node or a_key macro argument is the first argument to the  * comparison function, which makes it possible to write comparison functions  * that treat the first argument specially.  *  ******************************************************************************/
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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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
value|struct {								\     a_type *rbt_root;							\     a_type rbt_nil;							\ }
end_define

begin_comment
comment|/* Left accessors. */
end_comment

begin_define
define|#
directive|define
name|rbp_left_get
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
name|rbp_left_set
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

begin_comment
comment|/* Right accessors. */
end_comment

begin_define
define|#
directive|define
name|rbp_right_get
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
name|rbp_right_set
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
name|rbp_red_get
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
name|rbp_color_set
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
name|rbp_red_set
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
name|rbp_black_set
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
name|rbp_node_new
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_tree
parameter_list|,
name|a_node
parameter_list|)
value|do {		\     rbp_left_set(a_type, a_field, (a_node),&(a_tree)->rbt_nil);	\     rbp_right_set(a_type, a_field, (a_node),&(a_tree)->rbt_nil);	\     rbp_red_set(a_type, a_field, (a_node));				\ } while (0)
end_define

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
name|a_tree
parameter_list|)
value|do {				\     (a_tree)->rbt_root =&(a_tree)->rbt_nil;				\     rbp_node_new(a_type, a_field, a_tree,&(a_tree)->rbt_nil);		\     rbp_black_set(a_type, a_field,&(a_tree)->rbt_nil);			\ } while (0)
end_define

begin_comment
comment|/* Tree operations. */
end_comment

begin_define
define|#
directive|define
name|rbp_black_height
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_tree
parameter_list|,
name|r_height
parameter_list|)
value|do {	\     a_type *rbp_bh_t;							\     for (rbp_bh_t = (a_tree)->rbt_root, (r_height) = 0;			\       rbp_bh_t !=&(a_tree)->rbt_nil;					\       rbp_bh_t = rbp_left_get(a_type, a_field, rbp_bh_t)) {		\ 	if (rbp_red_get(a_type, a_field, rbp_bh_t) == false) {		\ 	    (r_height)++;						\ 	}								\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbp_first
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_tree
parameter_list|,
name|a_root
parameter_list|,
name|r_node
parameter_list|)
value|do {		\     for ((r_node) = (a_root);						\       rbp_left_get(a_type, a_field, (r_node)) !=&(a_tree)->rbt_nil;	\       (r_node) = rbp_left_get(a_type, a_field, (r_node))) {		\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbp_last
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_tree
parameter_list|,
name|a_root
parameter_list|,
name|r_node
parameter_list|)
value|do {		\     for ((r_node) = (a_root);						\       rbp_right_get(a_type, a_field, (r_node)) !=&(a_tree)->rbt_nil;	\       (r_node) = rbp_right_get(a_type, a_field, (r_node))) {		\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbp_next
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|,
name|a_tree
parameter_list|,
name|a_node
parameter_list|,
name|r_node
parameter_list|)
value|do {	\     if (rbp_right_get(a_type, a_field, (a_node))			\       !=&(a_tree)->rbt_nil) {						\ 	rbp_first(a_type, a_field, a_tree, rbp_right_get(a_type,	\ 	  a_field, (a_node)), (r_node));				\     } else {								\ 	a_type *rbp_n_t = (a_tree)->rbt_root;				\ 	assert(rbp_n_t !=&(a_tree)->rbt_nil);				\ 	(r_node) =&(a_tree)->rbt_nil;					\ 	while (true) {							\ 	    int rbp_n_cmp = (a_cmp)((a_node), rbp_n_t);			\ 	    if (rbp_n_cmp< 0) {					\ 		(r_node) = rbp_n_t;					\ 		rbp_n_t = rbp_left_get(a_type, a_field, rbp_n_t);	\ 	    } else if (rbp_n_cmp> 0) {					\ 		rbp_n_t = rbp_right_get(a_type, a_field, rbp_n_t);	\ 	    } else {							\ 		break;							\ 	    }								\ 	    assert(rbp_n_t !=&(a_tree)->rbt_nil);			\ 	}								\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbp_prev
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|,
name|a_tree
parameter_list|,
name|a_node
parameter_list|,
name|r_node
parameter_list|)
value|do {	\     if (rbp_left_get(a_type, a_field, (a_node)) !=&(a_tree)->rbt_nil) {\ 	rbp_last(a_type, a_field, a_tree, rbp_left_get(a_type,		\ 	  a_field, (a_node)), (r_node));				\     } else {								\ 	a_type *rbp_p_t = (a_tree)->rbt_root;				\ 	assert(rbp_p_t !=&(a_tree)->rbt_nil);				\ 	(r_node) =&(a_tree)->rbt_nil;					\ 	while (true) {							\ 	    int rbp_p_cmp = (a_cmp)((a_node), rbp_p_t);			\ 	    if (rbp_p_cmp< 0) {					\ 		rbp_p_t = rbp_left_get(a_type, a_field, rbp_p_t);	\ 	    } else if (rbp_p_cmp> 0) {					\ 		(r_node) = rbp_p_t;					\ 		rbp_p_t = rbp_right_get(a_type, a_field, rbp_p_t);	\ 	    } else {							\ 		break;							\ 	    }								\ 	    assert(rbp_p_t !=&(a_tree)->rbt_nil);			\ 	}								\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rb_first
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_tree
parameter_list|,
name|r_node
parameter_list|)
value|do {			\     rbp_first(a_type, a_field, a_tree, (a_tree)->rbt_root, (r_node));	\     if ((r_node) ==&(a_tree)->rbt_nil) {				\ 	(r_node) = NULL;						\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rb_last
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_tree
parameter_list|,
name|r_node
parameter_list|)
value|do {			\     rbp_last(a_type, a_field, a_tree, (a_tree)->rbt_root, r_node);	\     if ((r_node) ==&(a_tree)->rbt_nil) {				\ 	(r_node) = NULL;						\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rb_next
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|,
name|a_tree
parameter_list|,
name|a_node
parameter_list|,
name|r_node
parameter_list|)
value|do {	\     rbp_next(a_type, a_field, a_cmp, a_tree, (a_node), (r_node));	\     if ((r_node) ==&(a_tree)->rbt_nil) {				\ 	(r_node) = NULL;						\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rb_prev
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|,
name|a_tree
parameter_list|,
name|a_node
parameter_list|,
name|r_node
parameter_list|)
value|do {	\     rbp_prev(a_type, a_field, a_cmp, a_tree, (a_node), (r_node));	\     if ((r_node) ==&(a_tree)->rbt_nil) {				\ 	(r_node) = NULL;						\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rb_search
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|,
name|a_tree
parameter_list|,
name|a_key
parameter_list|,
name|r_node
parameter_list|)
value|do {	\     int rbp_se_cmp;							\     (r_node) = (a_tree)->rbt_root;					\     while ((r_node) !=&(a_tree)->rbt_nil				\&& (rbp_se_cmp = (a_cmp)((a_key), (r_node))) != 0) {		\ 	if (rbp_se_cmp< 0) {						\ 	    (r_node) = rbp_left_get(a_type, a_field, (r_node));		\ 	} else {							\ 	    (r_node) = rbp_right_get(a_type, a_field, (r_node));	\ 	}								\     }									\     if ((r_node) ==&(a_tree)->rbt_nil) {				\ 	(r_node) = NULL;						\     }									\ } while (0)
end_define

begin_comment
comment|/*  * Find a match if it exists.  Otherwise, find the next greater node, if one  * exists.  */
end_comment

begin_define
define|#
directive|define
name|rb_nsearch
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|,
name|a_tree
parameter_list|,
name|a_key
parameter_list|,
name|r_node
parameter_list|)
value|do {	\     a_type *rbp_ns_t = (a_tree)->rbt_root;				\     (r_node) = NULL;							\     while (rbp_ns_t !=&(a_tree)->rbt_nil) {				\ 	int rbp_ns_cmp = (a_cmp)((a_key), rbp_ns_t);			\ 	if (rbp_ns_cmp< 0) {						\ 	    (r_node) = rbp_ns_t;					\ 	    rbp_ns_t = rbp_left_get(a_type, a_field, rbp_ns_t);		\ 	} else if (rbp_ns_cmp> 0) {					\ 	    rbp_ns_t = rbp_right_get(a_type, a_field, rbp_ns_t);	\ 	} else {							\ 	    (r_node) = rbp_ns_t;					\ 	    break;							\ 	}								\     }									\ } while (0)
end_define

begin_comment
comment|/*  * Find a match if it exists.  Otherwise, find the previous lesser node, if one  * exists.  */
end_comment

begin_define
define|#
directive|define
name|rb_psearch
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|,
name|a_tree
parameter_list|,
name|a_key
parameter_list|,
name|r_node
parameter_list|)
value|do {	\     a_type *rbp_ps_t = (a_tree)->rbt_root;				\     (r_node) = NULL;							\     while (rbp_ps_t !=&(a_tree)->rbt_nil) {				\ 	int rbp_ps_cmp = (a_cmp)((a_key), rbp_ps_t);			\ 	if (rbp_ps_cmp< 0) {						\ 	    rbp_ps_t = rbp_left_get(a_type, a_field, rbp_ps_t);		\ 	} else if (rbp_ps_cmp> 0) {					\ 	    (r_node) = rbp_ps_t;					\ 	    rbp_ps_t = rbp_right_get(a_type, a_field, rbp_ps_t);	\ 	} else {							\ 	    (r_node) = rbp_ps_t;					\ 	    break;							\ 	}								\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbp_rotate_left
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|,
name|r_node
parameter_list|)
value|do {		\     (r_node) = rbp_right_get(a_type, a_field, (a_node));		\     rbp_right_set(a_type, a_field, (a_node),				\       rbp_left_get(a_type, a_field, (r_node)));				\     rbp_left_set(a_type, a_field, (r_node), (a_node));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbp_rotate_right
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|,
name|r_node
parameter_list|)
value|do {		\     (r_node) = rbp_left_get(a_type, a_field, (a_node));			\     rbp_left_set(a_type, a_field, (a_node),				\       rbp_right_get(a_type, a_field, (r_node)));			\     rbp_right_set(a_type, a_field, (r_node), (a_node));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbp_lean_left
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|,
name|r_node
parameter_list|)
value|do {		\     bool rbp_ll_red;							\     rbp_rotate_left(a_type, a_field, (a_node), (r_node));		\     rbp_ll_red = rbp_red_get(a_type, a_field, (a_node));		\     rbp_color_set(a_type, a_field, (r_node), rbp_ll_red);		\     rbp_red_set(a_type, a_field, (a_node));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbp_lean_right
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|,
name|r_node
parameter_list|)
value|do {		\     bool rbp_lr_red;							\     rbp_rotate_right(a_type, a_field, (a_node), (r_node));		\     rbp_lr_red = rbp_red_get(a_type, a_field, (a_node));		\     rbp_color_set(a_type, a_field, (r_node), rbp_lr_red);		\     rbp_red_set(a_type, a_field, (a_node));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbp_move_red_left
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|,
name|r_node
parameter_list|)
value|do {		\     a_type *rbp_mrl_t, *rbp_mrl_u;					\     rbp_mrl_t = rbp_left_get(a_type, a_field, (a_node));		\     rbp_red_set(a_type, a_field, rbp_mrl_t);				\     rbp_mrl_t = rbp_right_get(a_type, a_field, (a_node));		\     rbp_mrl_u = rbp_left_get(a_type, a_field, rbp_mrl_t);		\     if (rbp_red_get(a_type, a_field, rbp_mrl_u)) {			\ 	rbp_rotate_right(a_type, a_field, rbp_mrl_t, rbp_mrl_u);	\ 	rbp_right_set(a_type, a_field, (a_node), rbp_mrl_u);		\ 	rbp_rotate_left(a_type, a_field, (a_node), (r_node));		\ 	rbp_mrl_t = rbp_right_get(a_type, a_field, (a_node));		\ 	if (rbp_red_get(a_type, a_field, rbp_mrl_t)) {			\ 	    rbp_black_set(a_type, a_field, rbp_mrl_t);			\ 	    rbp_red_set(a_type, a_field, (a_node));			\ 	    rbp_rotate_left(a_type, a_field, (a_node), rbp_mrl_t);	\ 	    rbp_left_set(a_type, a_field, (r_node), rbp_mrl_t);		\ 	} else {							\ 	    rbp_black_set(a_type, a_field, (a_node));			\ 	}								\     } else {								\ 	rbp_red_set(a_type, a_field, (a_node));				\ 	rbp_rotate_left(a_type, a_field, (a_node), (r_node));		\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rbp_move_red_right
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_node
parameter_list|,
name|r_node
parameter_list|)
value|do {	\     a_type *rbp_mrr_t;							\     rbp_mrr_t = rbp_left_get(a_type, a_field, (a_node));		\     if (rbp_red_get(a_type, a_field, rbp_mrr_t)) {			\ 	a_type *rbp_mrr_u, *rbp_mrr_v;					\ 	rbp_mrr_u = rbp_right_get(a_type, a_field, rbp_mrr_t);		\ 	rbp_mrr_v = rbp_left_get(a_type, a_field, rbp_mrr_u);		\ 	if (rbp_red_get(a_type, a_field, rbp_mrr_v)) {			\ 	    rbp_color_set(a_type, a_field, rbp_mrr_u,			\ 	      rbp_red_get(a_type, a_field, (a_node)));			\ 	    rbp_black_set(a_type, a_field, rbp_mrr_v);			\ 	    rbp_rotate_left(a_type, a_field, rbp_mrr_t, rbp_mrr_u);	\ 	    rbp_left_set(a_type, a_field, (a_node), rbp_mrr_u);		\ 	    rbp_rotate_right(a_type, a_field, (a_node), (r_node));	\ 	    rbp_rotate_left(a_type, a_field, (a_node), rbp_mrr_t);	\ 	    rbp_right_set(a_type, a_field, (r_node), rbp_mrr_t);	\ 	} else {							\ 	    rbp_color_set(a_type, a_field, rbp_mrr_t,			\ 	      rbp_red_get(a_type, a_field, (a_node)));			\ 	    rbp_red_set(a_type, a_field, rbp_mrr_u);			\ 	    rbp_rotate_right(a_type, a_field, (a_node), (r_node));	\ 	    rbp_rotate_left(a_type, a_field, (a_node), rbp_mrr_t);	\ 	    rbp_right_set(a_type, a_field, (r_node), rbp_mrr_t);	\ 	}								\ 	rbp_red_set(a_type, a_field, (a_node));				\     } else {								\ 	rbp_red_set(a_type, a_field, rbp_mrr_t);			\ 	rbp_mrr_t = rbp_left_get(a_type, a_field, rbp_mrr_t);		\ 	if (rbp_red_get(a_type, a_field, rbp_mrr_t)) {			\ 	    rbp_black_set(a_type, a_field, rbp_mrr_t);			\ 	    rbp_rotate_right(a_type, a_field, (a_node), (r_node));	\ 	    rbp_rotate_left(a_type, a_field, (a_node), rbp_mrr_t);	\ 	    rbp_right_set(a_type, a_field, (r_node), rbp_mrr_t);	\ 	} else {							\ 	    rbp_rotate_left(a_type, a_field, (a_node), (r_node));	\ 	}								\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|rb_insert
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|,
name|a_tree
parameter_list|,
name|a_node
parameter_list|)
value|do {		\     a_type rbp_i_s;							\     a_type *rbp_i_g, *rbp_i_p, *rbp_i_c, *rbp_i_t, *rbp_i_u;		\     int rbp_i_cmp = 0;							\     rbp_i_g =&(a_tree)->rbt_nil;					\     rbp_left_set(a_type, a_field,&rbp_i_s, (a_tree)->rbt_root);	\     rbp_right_set(a_type, a_field,&rbp_i_s,&(a_tree)->rbt_nil);	\     rbp_black_set(a_type, a_field,&rbp_i_s);				\     rbp_i_p =&rbp_i_s;							\     rbp_i_c = (a_tree)->rbt_root;					\
comment|/* Iteratively search down the tree for the insertion point,      */
value|\
comment|/* splitting 4-nodes as they are encountered.  At the end of each */
value|\
comment|/* iteration, rbp_i_g->rbp_i_p->rbp_i_c is a 3-level path down    */
value|\
comment|/* the tree, assuming a sufficiently deep tree.                   */
value|\     while (rbp_i_c !=&(a_tree)->rbt_nil) {				\ 	rbp_i_t = rbp_left_get(a_type, a_field, rbp_i_c);		\ 	rbp_i_u = rbp_left_get(a_type, a_field, rbp_i_t);		\ 	if (rbp_red_get(a_type, a_field, rbp_i_t)			\&& rbp_red_get(a_type, a_field, rbp_i_u)) {			\
comment|/* rbp_i_c is the top of a logical 4-node, so split it.   */
value|\
comment|/* This iteration does not move down the tree, due to the */
value|\
comment|/* disruptiveness of node splitting.                      */
value|\
comment|/*                                                        */
value|\
comment|/* Rotate right.                                          */
value|\ 	    rbp_rotate_right(a_type, a_field, rbp_i_c, rbp_i_t);	\
comment|/* Pass red links up one level.                           */
value|\ 	    rbp_i_u = rbp_left_get(a_type, a_field, rbp_i_t);		\ 	    rbp_black_set(a_type, a_field, rbp_i_u);			\ 	    if (rbp_left_get(a_type, a_field, rbp_i_p) == rbp_i_c) {	\ 		rbp_left_set(a_type, a_field, rbp_i_p, rbp_i_t);	\ 		rbp_i_c = rbp_i_t;					\ 	    } else {							\
comment|/* rbp_i_c was the right child of rbp_i_p, so rotate  */
value|\
comment|/* left in order to maintain the left-leaning         */
value|\
comment|/* invariant.                                         */
value|\ 		assert(rbp_right_get(a_type, a_field, rbp_i_p)		\ 		  == rbp_i_c);						\ 		rbp_right_set(a_type, a_field, rbp_i_p, rbp_i_t);	\ 		rbp_lean_left(a_type, a_field, rbp_i_p, rbp_i_u);	\ 		if (rbp_left_get(a_type, a_field, rbp_i_g) == rbp_i_p) {\ 		    rbp_left_set(a_type, a_field, rbp_i_g, rbp_i_u);	\ 		} else {						\ 		    assert(rbp_right_get(a_type, a_field, rbp_i_g)	\ 		      == rbp_i_p);					\ 		    rbp_right_set(a_type, a_field, rbp_i_g, rbp_i_u);	\ 		}							\ 		rbp_i_p = rbp_i_u;					\ 		rbp_i_cmp = (a_cmp)((a_node), rbp_i_p);			\ 		if (rbp_i_cmp< 0) {					\ 		    rbp_i_c = rbp_left_get(a_type, a_field, rbp_i_p);	\ 		} else {						\ 		    assert(rbp_i_cmp> 0);				\ 		    rbp_i_c = rbp_right_get(a_type, a_field, rbp_i_p);	\ 		}							\ 		continue;						\ 	    }								\ 	}								\ 	rbp_i_g = rbp_i_p;						\ 	rbp_i_p = rbp_i_c;						\ 	rbp_i_cmp = (a_cmp)((a_node), rbp_i_c);				\ 	if (rbp_i_cmp< 0) {						\ 	    rbp_i_c = rbp_left_get(a_type, a_field, rbp_i_c);		\ 	} else {							\ 	    assert(rbp_i_cmp> 0);					\ 	    rbp_i_c = rbp_right_get(a_type, a_field, rbp_i_c);		\ 	}								\     }									\
comment|/* rbp_i_p now refers to the node under which to insert.          */
value|\     rbp_node_new(a_type, a_field, a_tree, (a_node));			\     if (rbp_i_cmp> 0) {						\ 	rbp_right_set(a_type, a_field, rbp_i_p, (a_node));		\ 	rbp_lean_left(a_type, a_field, rbp_i_p, rbp_i_t);		\ 	if (rbp_left_get(a_type, a_field, rbp_i_g) == rbp_i_p) {	\ 	    rbp_left_set(a_type, a_field, rbp_i_g, rbp_i_t);		\ 	} else if (rbp_right_get(a_type, a_field, rbp_i_g) == rbp_i_p) {\ 	    rbp_right_set(a_type, a_field, rbp_i_g, rbp_i_t);		\ 	}								\     } else {								\ 	rbp_left_set(a_type, a_field, rbp_i_p, (a_node));		\     }									\
comment|/* Update the root and make sure that it is black.                */
value|\     (a_tree)->rbt_root = rbp_left_get(a_type, a_field,&rbp_i_s);	\     rbp_black_set(a_type, a_field, (a_tree)->rbt_root);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|rb_remove
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|,
name|a_tree
parameter_list|,
name|a_node
parameter_list|)
value|do {		\     a_type rbp_r_s;							\     a_type *rbp_r_p, *rbp_r_c, *rbp_r_xp, *rbp_r_t, *rbp_r_u;		\     int rbp_r_cmp;							\     rbp_left_set(a_type, a_field,&rbp_r_s, (a_tree)->rbt_root);	\     rbp_right_set(a_type, a_field,&rbp_r_s,&(a_tree)->rbt_nil);	\     rbp_black_set(a_type, a_field,&rbp_r_s);				\     rbp_r_p =&rbp_r_s;							\     rbp_r_c = (a_tree)->rbt_root;					\     rbp_r_xp =&(a_tree)->rbt_nil;					\
comment|/* Iterate down the tree, but always transform 2-nodes to 3- or   */
value|\
comment|/* 4-nodes in order to maintain the invariant that the current    */
value|\
comment|/* node is not a 2-node.  This allows simple deletion once a leaf */
value|\
comment|/* is reached.  Handle the root specially though, since there may */
value|\
comment|/* be no way to convert it from a 2-node to a 3-node.             */
value|\     rbp_r_cmp = (a_cmp)((a_node), rbp_r_c);				\     if (rbp_r_cmp< 0) {						\ 	rbp_r_t = rbp_left_get(a_type, a_field, rbp_r_c);		\ 	rbp_r_u = rbp_left_get(a_type, a_field, rbp_r_t);		\ 	if (rbp_red_get(a_type, a_field, rbp_r_t) == false		\&& rbp_red_get(a_type, a_field, rbp_r_u) == false) {		\
comment|/* Apply standard transform to prepare for left move.     */
value|\ 	    rbp_move_red_left(a_type, a_field, rbp_r_c, rbp_r_t);	\ 	    rbp_black_set(a_type, a_field, rbp_r_t);			\ 	    rbp_left_set(a_type, a_field, rbp_r_p, rbp_r_t);		\ 	    rbp_r_c = rbp_r_t;						\ 	} else {							\
comment|/* Move left.                                             */
value|\ 	    rbp_r_p = rbp_r_c;						\ 	    rbp_r_c = rbp_left_get(a_type, a_field, rbp_r_c);		\ 	}								\     } else {								\ 	if (rbp_r_cmp == 0) {						\ 	    assert((a_node) == rbp_r_c);				\ 	    if (rbp_right_get(a_type, a_field, rbp_r_c)			\ 	      ==&(a_tree)->rbt_nil) {					\
comment|/* Delete root node (which is also a leaf node).      */
value|\ 		if (rbp_left_get(a_type, a_field, rbp_r_c)		\ 		  !=&(a_tree)->rbt_nil) {				\ 		    rbp_lean_right(a_type, a_field, rbp_r_c, rbp_r_t);	\ 		    rbp_right_set(a_type, a_field, rbp_r_t,		\&(a_tree)->rbt_nil);				\ 		} else {						\ 		    rbp_r_t =&(a_tree)->rbt_nil;			\ 		}							\ 		rbp_left_set(a_type, a_field, rbp_r_p, rbp_r_t);	\ 	    } else {							\
comment|/* This is the node we want to delete, but we will    */
value|\
comment|/* instead swap it with its successor and delete the  */
value|\
comment|/* successor.  Record enough information to do the    */
value|\
comment|/* swap later.  rbp_r_xp is the a_node's parent.      */
value|\ 		rbp_r_xp = rbp_r_p;					\ 		rbp_r_cmp = 1;
comment|/* Note that deletion is incomplete.   */
value|\ 	    }								\ 	}								\ 	if (rbp_r_cmp == 1) {						\ 	    if (rbp_red_get(a_type, a_field, rbp_left_get(a_type,	\ 	      a_field, rbp_right_get(a_type, a_field, rbp_r_c)))	\ 	      == false) {						\ 		rbp_r_t = rbp_left_get(a_type, a_field, rbp_r_c);	\ 		if (rbp_red_get(a_type, a_field, rbp_r_t)) {		\
comment|/* Standard transform.                            */
value|\ 		    rbp_move_red_right(a_type, a_field, rbp_r_c,	\ 		      rbp_r_t);						\ 		} else {						\
comment|/* Root-specific transform.                       */
value|\ 		    rbp_red_set(a_type, a_field, rbp_r_c);		\ 		    rbp_r_u = rbp_left_get(a_type, a_field, rbp_r_t);	\ 		    if (rbp_red_get(a_type, a_field, rbp_r_u)) {	\ 			rbp_black_set(a_type, a_field, rbp_r_u);	\ 			rbp_rotate_right(a_type, a_field, rbp_r_c,	\ 			  rbp_r_t);					\ 			rbp_rotate_left(a_type, a_field, rbp_r_c,	\ 			  rbp_r_u);					\ 			rbp_right_set(a_type, a_field, rbp_r_t,		\ 			  rbp_r_u);					\ 		    } else {						\ 			rbp_red_set(a_type, a_field, rbp_r_t);		\ 			rbp_rotate_left(a_type, a_field, rbp_r_c,	\ 			  rbp_r_t);					\ 		    }							\ 		}							\ 		rbp_left_set(a_type, a_field, rbp_r_p, rbp_r_t);	\ 		rbp_r_c = rbp_r_t;					\ 	    } else {							\
comment|/* Move right.                                        */
value|\ 		rbp_r_p = rbp_r_c;					\ 		rbp_r_c = rbp_right_get(a_type, a_field, rbp_r_c);	\ 	    }								\ 	}								\     }									\     if (rbp_r_cmp != 0) {						\ 	while (true) {							\ 	    assert(rbp_r_p !=&(a_tree)->rbt_nil);			\ 	    rbp_r_cmp = (a_cmp)((a_node), rbp_r_c);			\ 	    if (rbp_r_cmp< 0) {					\ 		rbp_r_t = rbp_left_get(a_type, a_field, rbp_r_c);	\ 		if (rbp_r_t ==&(a_tree)->rbt_nil) {			\
comment|/* rbp_r_c now refers to the successor node to    */
value|\
comment|/* relocate, and rbp_r_xp/a_node refer to the     */
value|\
comment|/* context for the relocation.                    */
value|\ 		    if (rbp_left_get(a_type, a_field, rbp_r_xp)		\ 		      == (a_node)) {					\ 			rbp_left_set(a_type, a_field, rbp_r_xp,		\ 			  rbp_r_c);					\ 		    } else {						\ 			assert(rbp_right_get(a_type, a_field,		\ 			  rbp_r_xp) == (a_node));			\ 			rbp_right_set(a_type, a_field, rbp_r_xp,	\ 			  rbp_r_c);					\ 		    }							\ 		    rbp_left_set(a_type, a_field, rbp_r_c,		\ 		      rbp_left_get(a_type, a_field, (a_node)));		\ 		    rbp_right_set(a_type, a_field, rbp_r_c,		\ 		      rbp_right_get(a_type, a_field, (a_node)));	\ 		    rbp_color_set(a_type, a_field, rbp_r_c,		\ 		      rbp_red_get(a_type, a_field, (a_node)));		\ 		    if (rbp_left_get(a_type, a_field, rbp_r_p)		\ 		      == rbp_r_c) {					\ 			rbp_left_set(a_type, a_field, rbp_r_p,		\&(a_tree)->rbt_nil);				\ 		    } else {						\ 			assert(rbp_right_get(a_type, a_field, rbp_r_p)	\ 			  == rbp_r_c);					\ 			rbp_right_set(a_type, a_field, rbp_r_p,		\&(a_tree)->rbt_nil);				\ 		    }							\ 		    break;						\ 		}							\ 		rbp_r_u = rbp_left_get(a_type, a_field, rbp_r_t);	\ 		if (rbp_red_get(a_type, a_field, rbp_r_t) == false	\&& rbp_red_get(a_type, a_field, rbp_r_u) == false) {	\ 		    rbp_move_red_left(a_type, a_field, rbp_r_c,		\ 		      rbp_r_t);						\ 		    if (rbp_left_get(a_type, a_field, rbp_r_p)		\ 		      == rbp_r_c) {					\ 			rbp_left_set(a_type, a_field, rbp_r_p, rbp_r_t);\ 		    } else {						\ 			rbp_right_set(a_type, a_field, rbp_r_p,		\ 			  rbp_r_t);					\ 		    }							\ 		    rbp_r_c = rbp_r_t;					\ 		} else {						\ 		    rbp_r_p = rbp_r_c;					\ 		    rbp_r_c = rbp_left_get(a_type, a_field, rbp_r_c);	\ 		}							\ 	    } else {							\
comment|/* Check whether to delete this node (it has to be    */
value|\
comment|/* the correct node and a leaf node).                 */
value|\ 		if (rbp_r_cmp == 0) {					\ 		    assert((a_node) == rbp_r_c);			\ 		    if (rbp_right_get(a_type, a_field, rbp_r_c)		\ 		      ==&(a_tree)->rbt_nil) {				\
comment|/* Delete leaf node.                          */
value|\ 			if (rbp_left_get(a_type, a_field, rbp_r_c)	\ 			  !=&(a_tree)->rbt_nil) {			\ 			    rbp_lean_right(a_type, a_field, rbp_r_c,	\ 			      rbp_r_t);					\ 			    rbp_right_set(a_type, a_field, rbp_r_t,	\&(a_tree)->rbt_nil);			\ 			} else {					\ 			    rbp_r_t =&(a_tree)->rbt_nil;		\ 			}						\ 			if (rbp_left_get(a_type, a_field, rbp_r_p)	\ 			  == rbp_r_c) {					\ 			    rbp_left_set(a_type, a_field, rbp_r_p,	\ 			      rbp_r_t);					\ 			} else {					\ 			    rbp_right_set(a_type, a_field, rbp_r_p,	\ 			      rbp_r_t);					\ 			}						\ 			break;						\ 		    } else {						\
comment|/* This is the node we want to delete, but we */
value|\
comment|/* will instead swap it with its successor    */
value|\
comment|/* and delete the successor.  Record enough   */
value|\
comment|/* information to do the swap later.          */
value|\
comment|/* rbp_r_xp is a_node's parent.               */
value|\ 			rbp_r_xp = rbp_r_p;				\ 		    }							\ 		}							\ 		rbp_r_t = rbp_right_get(a_type, a_field, rbp_r_c);	\ 		rbp_r_u = rbp_left_get(a_type, a_field, rbp_r_t);	\ 		if (rbp_red_get(a_type, a_field, rbp_r_u) == false) {	\ 		    rbp_move_red_right(a_type, a_field, rbp_r_c,	\ 		      rbp_r_t);						\ 		    if (rbp_left_get(a_type, a_field, rbp_r_p)		\ 		      == rbp_r_c) {					\ 			rbp_left_set(a_type, a_field, rbp_r_p, rbp_r_t);\ 		    } else {						\ 			rbp_right_set(a_type, a_field, rbp_r_p,		\ 			  rbp_r_t);					\ 		    }							\ 		    rbp_r_c = rbp_r_t;					\ 		} else {						\ 		    rbp_r_p = rbp_r_c;					\ 		    rbp_r_c = rbp_right_get(a_type, a_field, rbp_r_c);	\ 		}							\ 	    }								\ 	}								\     }									\
comment|/* Update root.                                                   */
value|\     (a_tree)->rbt_root = rbp_left_get(a_type, a_field,&rbp_r_s);	\ } while (0)
end_define

begin_comment
comment|/*  * The rb_wrap() macro provides a convenient way to wrap functions around the  * cpp macros.  The main benefits of wrapping are that 1) repeated macro  * expansion can cause code bloat, especially for rb_{insert,remove)(), and  * 2) type, linkage, comparison functions, etc. need not be specified at every  * call point.  */
end_comment

begin_define
define|#
directive|define
name|rb_wrap
parameter_list|(
name|a_attr
parameter_list|,
name|a_prefix
parameter_list|,
name|a_tree_type
parameter_list|,
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|)
define|\
value|a_attr void								\ a_prefix##new(a_tree_type *tree) {					\     rb_new(a_type, a_field, tree);					\ }									\ a_attr a_type *								\ a_prefix##first(a_tree_type *tree) {					\     a_type *ret;							\     rb_first(a_type, a_field, tree, ret);				\     return (ret);							\ }									\ a_attr a_type *								\ a_prefix##last(a_tree_type *tree) {					\     a_type *ret;							\     rb_last(a_type, a_field, tree, ret);				\     return (ret);							\ }									\ a_attr a_type *								\ a_prefix##next(a_tree_type *tree, a_type *node) {			\     a_type *ret;							\     rb_next(a_type, a_field, a_cmp, tree, node, ret);			\     return (ret);							\ }									\ a_attr a_type *								\ a_prefix##prev(a_tree_type *tree, a_type *node) {			\     a_type *ret;							\     rb_prev(a_type, a_field, a_cmp, tree, node, ret);			\     return (ret);							\ }									\ a_attr a_type *								\ a_prefix##search(a_tree_type *tree, a_type *key) {			\     a_type *ret;							\     rb_search(a_type, a_field, a_cmp, tree, key, ret);			\     return (ret);							\ }									\ a_attr a_type *								\ a_prefix##nsearch(a_tree_type *tree, a_type *key) {			\     a_type *ret;							\     rb_nsearch(a_type, a_field, a_cmp, tree, key, ret);			\     return (ret);							\ }									\ a_attr a_type *								\ a_prefix##psearch(a_tree_type *tree, a_type *key) {			\     a_type *ret;							\     rb_psearch(a_type, a_field, a_cmp, tree, key, ret);			\     return (ret);							\ }									\ a_attr void								\ a_prefix##insert(a_tree_type *tree, a_type *node) {			\     rb_insert(a_type, a_field, a_cmp, tree, node);			\ }									\ a_attr void								\ a_prefix##remove(a_tree_type *tree, a_type *node) {			\     rb_remove(a_type, a_field, a_cmp, tree, node);			\ }
end_define

begin_comment
comment|/*  * The iterators simulate recursion via an array of pointers that store the  * current path.  This is critical to performance, since a series of calls to  * rb_{next,prev}() would require time proportional to (n lg n), whereas this  * implementation only requires time proportional to (n).  *  * Since the iterators cache a path down the tree, any tree modification may  * cause the cached path to become invalid.  In order to continue iteration,  * use something like the following sequence:  *  *   {  *       a_type *node, *tnode;  *  *       rb_foreach_begin(a_type, a_field, a_tree, node) {  *           ...  *           rb_next(a_type, a_field, a_cmp, a_tree, node, tnode);  *           rb_remove(a_type, a_field, a_cmp, a_tree, node);  *           rb_foreach_next(a_type, a_field, a_cmp, a_tree, tnode);  *           ...  *       } rb_foreach_end(a_type, a_field, a_tree, node)  *   }  *  * Note that this idiom is not advised if every iteration modifies the tree,  * since in that case there is no algorithmic complexity improvement over a  * series of rb_{next,prev}() calls, thus making the setup overhead wasted  * effort.  */
end_comment

begin_define
define|#
directive|define
name|rb_foreach_begin
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_tree
parameter_list|,
name|a_var
parameter_list|)
value|{		\
comment|/* Compute the maximum possible tree depth (3X the black height). */
value|\     unsigned rbp_f_height;						\     rbp_black_height(a_type, a_field, a_tree, rbp_f_height);		\     rbp_f_height *= 3;							\     {									\
comment|/* Initialize the path to contain the left spine.             */
value|\ 	a_type *rbp_f_path[rbp_f_height];				\ 	a_type *rbp_f_node;						\ 	bool rbp_f_synced = false;					\ 	unsigned rbp_f_depth = 0;					\ 	if ((a_tree)->rbt_root !=&(a_tree)->rbt_nil) {			\ 	    rbp_f_path[rbp_f_depth] = (a_tree)->rbt_root;		\ 	    rbp_f_depth++;						\ 	    while ((rbp_f_node = rbp_left_get(a_type, a_field,		\ 	      rbp_f_path[rbp_f_depth-1])) !=&(a_tree)->rbt_nil) {	\ 		rbp_f_path[rbp_f_depth] = rbp_f_node;			\ 		rbp_f_depth++;						\ 	    }								\ 	}								\
comment|/* While the path is non-empty, iterate.                      */
value|\ 	while (rbp_f_depth> 0) {					\ 	    (a_var) = rbp_f_path[rbp_f_depth-1];
end_define

begin_comment
comment|/* Only use if modifying the tree during iteration. */
end_comment

begin_define
define|#
directive|define
name|rb_foreach_next
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|,
name|a_tree
parameter_list|,
name|a_node
parameter_list|)
define|\
comment|/* Re-initialize the path to contain the path to a_node.  */
define|\
value|rbp_f_depth = 0;						\ 	    if (a_node != NULL) {					\ 		if ((a_tree)->rbt_root !=&(a_tree)->rbt_nil) {		\ 		    rbp_f_path[rbp_f_depth] = (a_tree)->rbt_root;	\ 		    rbp_f_depth++;					\ 		    rbp_f_node = rbp_f_path[0];				\ 		    while (true) {					\ 			int rbp_f_cmp = (a_cmp)((a_node),		\ 			  rbp_f_path[rbp_f_depth-1]);			\ 			if (rbp_f_cmp< 0) {				\ 			    rbp_f_node = rbp_left_get(a_type, a_field,	\ 			      rbp_f_path[rbp_f_depth-1]);		\ 			} else if (rbp_f_cmp> 0) {			\ 			    rbp_f_node = rbp_right_get(a_type, a_field,	\ 			      rbp_f_path[rbp_f_depth-1]);		\ 			} else {					\ 			    break;					\ 			}						\ 			assert(rbp_f_node !=&(a_tree)->rbt_nil);	\ 			rbp_f_path[rbp_f_depth] = rbp_f_node;		\ 			rbp_f_depth++;					\ 		    }							\ 		}							\ 	    }								\ 	    rbp_f_synced = true;
end_define

begin_define
define|#
directive|define
name|rb_foreach_end
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_tree
parameter_list|,
name|a_var
parameter_list|)
define|\
value|if (rbp_f_synced) {						\ 		rbp_f_synced = false;					\ 		continue;						\ 	    }								\
comment|/* Find the successor.                                    */
value|\ 	    if ((rbp_f_node = rbp_right_get(a_type, a_field,		\ 	      rbp_f_path[rbp_f_depth-1])) !=&(a_tree)->rbt_nil) {	\
comment|/* The successor is the left-most node in the right   */
value|\
comment|/* subtree.                                           */
value|\ 		rbp_f_path[rbp_f_depth] = rbp_f_node;			\ 		rbp_f_depth++;						\ 		while ((rbp_f_node = rbp_left_get(a_type, a_field,	\ 		  rbp_f_path[rbp_f_depth-1])) !=&(a_tree)->rbt_nil) {	\ 		    rbp_f_path[rbp_f_depth] = rbp_f_node;		\ 		    rbp_f_depth++;					\ 		}							\ 	    } else {							\
comment|/* The successor is above the current node.  Unwind   */
value|\
comment|/* until a left-leaning edge is removed from the      */
value|\
comment|/* path, or the path is empty.                        */
value|\ 		for (rbp_f_depth--; rbp_f_depth> 0; rbp_f_depth--) {	\ 		    if (rbp_left_get(a_type, a_field,			\ 		      rbp_f_path[rbp_f_depth-1])			\ 		      == rbp_f_path[rbp_f_depth]) {			\ 			break;						\ 		    }							\ 		}							\ 	    }								\ 	}								\     }									\ }
end_define

begin_define
define|#
directive|define
name|rb_foreach_reverse_begin
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_tree
parameter_list|,
name|a_var
parameter_list|)
value|{	\
comment|/* Compute the maximum possible tree depth (3X the black height). */
value|\     unsigned rbp_fr_height;						\     rbp_black_height(a_type, a_field, a_tree, rbp_fr_height);		\     rbp_fr_height *= 3;							\     {									\
comment|/* Initialize the path to contain the right spine.            */
value|\ 	a_type *rbp_fr_path[rbp_fr_height];				\ 	a_type *rbp_fr_node;						\ 	bool rbp_fr_synced = false;					\ 	unsigned rbp_fr_depth = 0;					\ 	if ((a_tree)->rbt_root !=&(a_tree)->rbt_nil) {			\ 	    rbp_fr_path[rbp_fr_depth] = (a_tree)->rbt_root;		\ 	    rbp_fr_depth++;						\ 	    while ((rbp_fr_node = rbp_right_get(a_type, a_field,	\ 	      rbp_fr_path[rbp_fr_depth-1])) !=&(a_tree)->rbt_nil) {	\ 		rbp_fr_path[rbp_fr_depth] = rbp_fr_node;		\ 		rbp_fr_depth++;						\ 	    }								\ 	}								\
comment|/* While the path is non-empty, iterate.                      */
value|\ 	while (rbp_fr_depth> 0) {					\ 	    (a_var) = rbp_fr_path[rbp_fr_depth-1];
end_define

begin_comment
comment|/* Only use if modifying the tree during iteration. */
end_comment

begin_define
define|#
directive|define
name|rb_foreach_reverse_prev
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_cmp
parameter_list|,
name|a_tree
parameter_list|,
name|a_node
parameter_list|)
define|\
comment|/* Re-initialize the path to contain the path to a_node.  */
define|\
value|rbp_fr_depth = 0;						\ 	    if (a_node != NULL) {					\ 		if ((a_tree)->rbt_root !=&(a_tree)->rbt_nil) {		\ 		    rbp_fr_path[rbp_fr_depth] = (a_tree)->rbt_root;	\ 		    rbp_fr_depth++;					\ 		    rbp_fr_node = rbp_fr_path[0];			\ 		    while (true) {					\ 			int rbp_fr_cmp = (a_cmp)((a_node),		\ 			  rbp_fr_path[rbp_fr_depth-1]);			\ 			if (rbp_fr_cmp< 0) {				\ 			    rbp_fr_node = rbp_left_get(a_type, a_field,	\ 			      rbp_fr_path[rbp_fr_depth-1]);		\ 			} else if (rbp_fr_cmp> 0) {			\ 			    rbp_fr_node = rbp_right_get(a_type, a_field,\ 			      rbp_fr_path[rbp_fr_depth-1]);		\ 			} else {					\ 			    break;					\ 			}						\ 			assert(rbp_fr_node !=&(a_tree)->rbt_nil);	\ 			rbp_fr_path[rbp_fr_depth] = rbp_fr_node;	\ 			rbp_fr_depth++;					\ 		    }							\ 		}							\ 	    }								\ 	    rbp_fr_synced = true;
end_define

begin_define
define|#
directive|define
name|rb_foreach_reverse_end
parameter_list|(
name|a_type
parameter_list|,
name|a_field
parameter_list|,
name|a_tree
parameter_list|,
name|a_var
parameter_list|)
define|\
value|if (rbp_fr_synced) {					\ 		rbp_fr_synced = false;					\ 		continue;						\ 	    }								\ 	    if (rbp_fr_depth == 0) {					\
comment|/* rb_foreach_reverse_sync() was called with a NULL   */
value|\
comment|/* a_node.                                            */
value|\ 		break;							\ 	    }								\
comment|/* Find the predecessor.                                  */
value|\ 	    if ((rbp_fr_node = rbp_left_get(a_type, a_field,		\ 	      rbp_fr_path[rbp_fr_depth-1])) !=&(a_tree)->rbt_nil) {	\
comment|/* The predecessor is the right-most node in the left */
value|\
comment|/* subtree.                                           */
value|\ 		rbp_fr_path[rbp_fr_depth] = rbp_fr_node;		\ 		rbp_fr_depth++;						\ 		while ((rbp_fr_node = rbp_right_get(a_type, a_field,	\ 		  rbp_fr_path[rbp_fr_depth-1])) !=&(a_tree)->rbt_nil) {\ 		    rbp_fr_path[rbp_fr_depth] = rbp_fr_node;		\ 		    rbp_fr_depth++;					\ 		}							\ 	    } else {							\
comment|/* The predecessor is above the current node.  Unwind */
value|\
comment|/* until a right-leaning edge is removed from the     */
value|\
comment|/* path, or the path is empty.                        */
value|\ 		for (rbp_fr_depth--; rbp_fr_depth> 0; rbp_fr_depth--) {\ 		    if (rbp_right_get(a_type, a_field,			\ 		      rbp_fr_path[rbp_fr_depth-1])			\ 		      == rbp_fr_path[rbp_fr_depth]) {			\ 			break;						\ 		    }							\ 		}							\ 	    }								\ 	}								\     }									\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RB_H_ */
end_comment

end_unit

