begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Garbage collection for the GNU compiler.    Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"varray.h"
end_include

begin_comment
comment|/* Symbols are marked with `ggc' for `gcc gc' so as not to interfere with    an external gc library that might be linked in.  */
end_comment

begin_comment
comment|/* These structures are defined in various headers throughout the    compiler.  However, rather than force everyone who includes this    header to include all the headers in which they are declared, we    just forward-declare them here.  */
end_comment

begin_struct_decl
struct_decl|struct
name|eh_status
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|emit_status
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|expr_status
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hash_table
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|label_node
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rtx_def
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rtvec_def
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|stmt_status
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|tree_node
union_decl|;
end_union_decl

begin_struct_decl
struct_decl|struct
name|varasm_status
struct_decl|;
end_struct_decl

begin_comment
comment|/* Constants for general use.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|empty_string
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* empty string */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|digit_vector
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "0" .. "9" */
end_comment

begin_define
define|#
directive|define
name|digit_string
parameter_list|(
name|d
parameter_list|)
value|(digit_vector + ((d) * 2))
end_define

begin_comment
comment|/* Trees that have been marked, but whose children still need marking.  */
end_comment

begin_decl_stmt
specifier|extern
name|varray_type
name|ggc_pending_trees
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Manipulate global roots that are needed between calls to gc.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ggc_add_root
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
name|base
operator|,
name|int
name|nelt
operator|,
name|int
name|size
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ggc_add_rtx_root
name|PARAMS
argument_list|(
operator|(
expr|struct
name|rtx_def
operator|*
operator|*
operator|,
name|int
name|nelt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ggc_add_tree_root
name|PARAMS
argument_list|(
operator|(
expr|union
name|tree_node
operator|*
operator|*
operator|,
name|int
name|nelt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ggc_add_rtx_varray_root
name|PARAMS
argument_list|(
operator|(
expr|struct
name|varray_head_tag
operator|*
operator|*
operator|,
name|int
name|nelt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ggc_add_tree_varray_root
name|PARAMS
argument_list|(
operator|(
expr|struct
name|varray_head_tag
operator|*
operator|*
operator|,
name|int
name|nelt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ggc_add_tree_hash_table_root
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_table
operator|*
operator|*
operator|,
name|int
name|nelt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ggc_del_root
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Types used for mark test and marking functions, if specified, in call    below.  */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*ggc_htab_marked_p
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*ggc_htab_mark
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* Add a hash table to be scanned when all roots have been processed.  We    delete any entry in the table that has not been marked.  The argument is    really htab_t.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ggc_add_deletable_htab
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|ggc_htab_marked_p
operator|,
name|ggc_htab_mark
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mark nodes from the gc_add_root callback.  These functions follow    pointers to mark other objects too.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ggc_mark_rtx_varray
name|PARAMS
argument_list|(
operator|(
expr|struct
name|varray_head_tag
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ggc_mark_tree_varray
name|PARAMS
argument_list|(
operator|(
expr|struct
name|varray_head_tag
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ggc_mark_tree_hash_table
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ggc_mark_roots
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ggc_mark_rtx_children
name|PARAMS
argument_list|(
operator|(
expr|struct
name|rtx_def
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ggc_mark_rtvec_children
name|PARAMS
argument_list|(
operator|(
expr|struct
name|rtvec_def
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If EXPR is not NULL and previously unmarked, mark it and evaluate    to true.  Otherwise evaluate to false.  */
end_comment

begin_define
define|#
directive|define
name|ggc_test_and_set_mark
parameter_list|(
name|EXPR
parameter_list|)
define|\
value|((EXPR) != NULL&& ! ggc_set_mark (EXPR))
end_define

begin_define
define|#
directive|define
name|ggc_mark_rtx
parameter_list|(
name|EXPR
parameter_list|)
define|\
value|do {                                          \     rtx r__ = (EXPR);                           \     if (ggc_test_and_set_mark (r__))            \       ggc_mark_rtx_children (r__);              \   } while (0)
end_define

begin_define
define|#
directive|define
name|ggc_mark_tree
parameter_list|(
name|EXPR
parameter_list|)
define|\
value|do {							\     tree t__ = (EXPR);					\     if (ggc_test_and_set_mark (t__))			\       VARRAY_PUSH_TREE (ggc_pending_trees, t__);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|ggc_mark_nonnull_tree
parameter_list|(
name|EXPR
parameter_list|)
define|\
value|do {							\     tree t__ = (EXPR);					\     if (! ggc_set_mark (t__))				\       VARRAY_PUSH_TREE (ggc_pending_trees, t__);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|ggc_mark_rtvec
parameter_list|(
name|EXPR
parameter_list|)
define|\
value|do {                                          \     rtvec v__ = (EXPR);                         \     if (ggc_test_and_set_mark (v__))            \       ggc_mark_rtvec_children (v__);            \   } while (0)
end_define

begin_define
define|#
directive|define
name|ggc_mark
parameter_list|(
name|EXPR
parameter_list|)
define|\
value|do {						\     const void *a__ = (EXPR);			\     if (a__ != NULL)				\       ggc_set_mark (a__);			\   } while (0)
end_define

begin_comment
comment|/* A GC implementation must provide these functions.  */
end_comment

begin_comment
comment|/* Initialize the garbage collector.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_ggc
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_stringpool
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start a new GGC context.  Memory allocated in previous contexts    will not be collected while the new context is active.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ggc_push_context
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Finish a GC context.  Any uncollected memory in the new context    will be merged with the old context.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ggc_pop_context
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocation.  */
end_comment

begin_comment
comment|/* The internal primitive.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|ggc_alloc
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like ggc_alloc, but allocates cleared memory.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|ggc_alloc_cleared
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ggc_alloc_rtx
parameter_list|(
name|NSLOTS
parameter_list|)
define|\
value|((struct rtx_def *) ggc_alloc (sizeof (struct rtx_def)		  \ 				 + ((NSLOTS) - 1) * sizeof (rtunion)))
end_define

begin_define
define|#
directive|define
name|ggc_alloc_rtvec
parameter_list|(
name|NELT
parameter_list|)
define|\
value|((struct rtvec_def *) ggc_alloc (sizeof (struct rtvec_def)		  \ 				   + ((NELT) - 1) * sizeof (rtx)))
end_define

begin_define
define|#
directive|define
name|ggc_alloc_tree
parameter_list|(
name|LENGTH
parameter_list|)
value|((union tree_node *) ggc_alloc (LENGTH))
end_define

begin_comment
comment|/* Allocate a gc-able string, and fill it with LENGTH bytes from CONTENTS.    If LENGTH is -1, then CONTENTS is assumed to be a    null-terminated string and the memory sized accordingly.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ggc_alloc_string
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|contents
operator|,
name|int
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a copy of S, in GC-able memory.  */
end_comment

begin_define
define|#
directive|define
name|ggc_strdup
parameter_list|(
name|S
parameter_list|)
value|ggc_alloc_string((S), -1)
end_define

begin_comment
comment|/* Invoke the collector.  Garbage collection occurs only when this    function is called, not during allocations.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ggc_collect
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Actually set the mark on a particular region of memory, but don't    follow pointers.  This function is called by ggc_mark_*.  It    returns zero if the object was not previously marked; non-zero if    the object was already marked, or if, for any other reason,    pointers in this data structure should not be traversed.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ggc_set_mark
name|PARAMS
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return 1 if P has been marked, zero otherwise.     P must have been allocated by the GC allocator; it mustn't point to    static objects, stack variables, or memory allocated with malloc.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ggc_marked_p
name|PARAMS
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Callbacks to the languages.  */
end_comment

begin_comment
comment|/* This is the language's opportunity to mark nodes held through    the lang_specific hooks in the tree.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|lang_mark_tree
name|PARAMS
argument_list|(
operator|(
expr|union
name|tree_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The FALSE_LABEL_STACK, declared in except.h, has language-dependent    semantics.  If a front-end needs to mark the false label stack, it    should set this pointer to a non-NULL value.  Otherwise, no marking    will be done.  */
end_comment

begin_extern
extern|extern void (*lang_mark_false_label_stack
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|label_node
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Mark functions for various structs scattered about.  */
end_comment

begin_decl_stmt
name|void
name|mark_eh_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|eh_status
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mark_emit_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|emit_status
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mark_expr_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|expr_status
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mark_stmt_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|stmt_status
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mark_varasm_status
name|PARAMS
argument_list|(
operator|(
expr|struct
name|varasm_status
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mark_optab
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Statistics.  */
end_comment

begin_comment
comment|/* This structure contains the statistics common to all collectors.    Particular collectors can extend this structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ggc_statistics
block|{
comment|/* The Ith element is the number of nodes allocated with code I.  */
name|unsigned
name|num_trees
index|[
literal|256
index|]
decl_stmt|;
comment|/* The Ith element is the number of bytes allocated by nodes with       code I.  */
name|size_t
name|size_trees
index|[
literal|256
index|]
decl_stmt|;
comment|/* The Ith element is the number of nodes allocated with code I.  */
name|unsigned
name|num_rtxs
index|[
literal|256
index|]
decl_stmt|;
comment|/* The Ith element is the number of bytes allocated by nodes with       code I.  */
name|size_t
name|size_rtxs
index|[
literal|256
index|]
decl_stmt|;
comment|/* The total size of the tree nodes allocated.  */
name|size_t
name|total_size_trees
decl_stmt|;
comment|/* The total size of the RTL nodes allocated.  */
name|size_t
name|total_size_rtxs
decl_stmt|;
comment|/* The total number of tree nodes allocated.  */
name|unsigned
name|total_num_trees
decl_stmt|;
comment|/* The total number of RTL nodes allocated.  */
name|unsigned
name|total_num_rtxs
decl_stmt|;
block|}
name|ggc_statistics
typedef|;
end_typedef

begin_comment
comment|/* Return the number of bytes allocated at the indicated address.  */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|ggc_get_size
name|PARAMS
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used by the various collectors to gather and print statistics that    do not depend on the collector in use.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ggc_print_common_statistics
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|ggc_statistics
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print allocation statistics.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ggc_print_statistics
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|stringpool_statistics
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

