begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Garbage collection for the GNU compiler.    Copyright (C) 1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"varray.h"
end_include

begin_include
include|#
directive|include
file|"gtype-desc.h"
end_include

begin_comment
comment|/* Symbols are marked with `ggc' for `gcc gc' so as not to interfere with    an external gc library that might be linked in.  */
end_comment

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
comment|/* Manipulate global roots that are needed between calls to gc.      THIS ROUTINE IS OBSOLETE, do not use it for new code.  */
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

begin_comment
comment|/* Structures for the easy way to mark roots.    In an array, terminated by having base == NULL.*/
end_comment

begin_struct
struct|struct
name|ggc_root_tab
block|{
name|void
modifier|*
name|base
decl_stmt|;
name|size_t
name|nelt
decl_stmt|;
name|size_t
name|stride
decl_stmt|;
name|void
argument_list|(
argument|*cb
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LAST_GGC_ROOT_TAB
value|{ NULL, 0, 0, NULL }
end_define

begin_comment
comment|/* Pointers to arrays of ggc_root_tab, terminated by NULL.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ggc_root_tab
modifier|*
specifier|const
name|gt_ggc_rtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ggc_root_tab
modifier|*
specifier|const
name|gt_ggc_deletable_rtab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Structure for hash table cache marking.  */
end_comment

begin_struct_decl
struct_decl|struct
name|htab
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ggc_cache_tab
block|{
name|struct
name|htab
modifier|*
modifier|*
name|base
decl_stmt|;
name|size_t
name|nelt
decl_stmt|;
name|size_t
name|stride
decl_stmt|;
name|void
argument_list|(
argument|*cb
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*marked_p
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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LAST_GGC_CACHE_TAB
value|{ NULL, 0, 0, NULL, NULL }
end_define

begin_comment
comment|/* Pointers to arrays of ggc_cache_tab, terminated by NULL.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ggc_cache_tab
modifier|*
specifier|const
name|gt_ggc_cache_rtab
index|[]
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
value|((EXPR) != NULL&& ((void *) (EXPR)) != (void *) 1&& ! ggc_set_mark (EXPR))
end_define

begin_define
define|#
directive|define
name|ggc_mark_rtx
value|gt_ggc_m_7rtx_def
end_define

begin_define
define|#
directive|define
name|ggc_mark_tree
value|gt_ggc_m_9tree_node
end_define

begin_define
define|#
directive|define
name|ggc_mark
parameter_list|(
name|EXPR
parameter_list|)
define|\
value|do {						\     const void *const a__ = (EXPR);		\     if (a__ != NULL&& a__ != (void *) 1)	\       ggc_set_mark (a__);			\   } while (0)
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

begin_comment
comment|/* Resize a block.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|ggc_realloc
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like ggc_alloc_cleared, but performs a multiplication.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|ggc_calloc
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|,
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

begin_define
define|#
directive|define
name|htab_create_ggc
parameter_list|(
name|SIZE
parameter_list|,
name|HASH
parameter_list|,
name|EQ
parameter_list|,
name|DEL
parameter_list|)
define|\
value|htab_create_alloc (SIZE, HASH, EQ, DEL, ggc_calloc, NULL)
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
comment|/* Actually set the mark on a particular region of memory, but don't    follow pointers.  This function is called by ggc_mark_*.  It    returns zero if the object was not previously marked; nonzero if    the object was already marked, or if, for any other reason,    pointers in this data structure should not be traversed.  */
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
comment|/* Return 1 if P has been marked, zero otherwise.    P must have been allocated by the GC allocator; it mustn't point to    static objects, stack variables, or memory allocated with malloc.  */
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
comment|/* The Ith element is the number of bytes allocated by nodes with      code I.  */
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
comment|/* The Ith element is the number of bytes allocated by nodes with      code I.  */
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

begin_comment
comment|/* Heuristics.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ggc_min_expand_heuristic
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
name|int
name|ggc_min_heapsize_heuristic
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
name|init_ggc_heuristics
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

