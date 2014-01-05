begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Garbage collection for the GNU compiler.    Copyright (C) 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_GGC_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_GGC_H
end_define

begin_include
include|#
directive|include
file|"statistics.h"
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
comment|/* Internal functions and data structures used by the GTY    machinery.  */
end_comment

begin_comment
comment|/* The first parameter is a pointer to a pointer, the second a cookie.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|gt_pointer_operator
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_include
include|#
directive|include
file|"gtype-desc.h"
end_include

begin_comment
comment|/* One of these applies its third parameter (with cookie in the fourth    parameter) to each pointer in the object pointed to by the first    parameter, using the second parameter.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|gt_note_pointers
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|gt_pointer_operator
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* One of these is called before objects are re-ordered in memory.    The first parameter is the original object, the second is the    subobject that has had its pointers reordered, the third parameter    can compute the new values of a pointer when given the cookie in    the fourth parameter.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|gt_handle_reorder
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|gt_pointer_operator
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Used by the gt_pch_n_* routines.  Register an object in the hash table.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|gt_pch_note_object
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|gt_note_pointers
parameter_list|,
name|enum
name|gt_types_enum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used by the gt_pch_n_* routines.  Register that an object has a reorder    function.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|gt_pch_note_reorder
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|gt_handle_reorder
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Mark the object in the first parameter and anything it points to.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|gt_pointer_walker
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Structures for the easy way to mark roots.    In an array, terminated by having base == NULL.  */
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
name|gt_pointer_walker
name|cb
decl_stmt|;
name|gt_pointer_walker
name|pchw
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LAST_GGC_ROOT_TAB
value|{ NULL, 0, 0, NULL, NULL }
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

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ggc_root_tab
modifier|*
specifier|const
name|gt_pch_cache_rtab
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
name|gt_pch_scalar_rtab
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
name|gt_pointer_walker
name|cb
decl_stmt|;
name|gt_pointer_walker
name|pchw
decl_stmt|;
name|int
function_decl|(
modifier|*
name|marked_p
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LAST_GGC_CACHE_TAB
value|{ NULL, 0, 0, NULL, NULL, NULL }
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
name|ggc_mark
parameter_list|(
name|EXPR
parameter_list|)
define|\
value|do {						\     const void *const a__ = (EXPR);		\     if (a__ != NULL&& a__ != (void *) 1)	\       ggc_set_mark (a__);			\   } while (0)
end_define

begin_comment
comment|/* Actually set the mark on a particular region of memory, but don't    follow pointers.  This function is called by ggc_mark_*.  It    returns zero if the object was not previously marked; nonzero if    the object was already marked, or if, for any other reason,    pointers in this data structure should not be traversed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ggc_set_mark
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return 1 if P has been marked, zero otherwise.    P must have been allocated by the GC allocator; it mustn't point to    static objects, stack variables, or memory allocated with malloc.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ggc_marked_p
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Mark the entries in the string pool.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ggc_mark_stringpool
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call ggc_set_mark on all the roots.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ggc_mark_roots
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Save and restore the string pool entries for PCH.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|gt_pch_save_stringpool
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gt_pch_fixup_stringpool
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gt_pch_restore_stringpool
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* PCH and GGC handling for strings, mostly trivial.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|gt_pch_p_S
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|gt_pointer_operator
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gt_pch_n_S
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gt_ggc_m_S
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize the string pool.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_stringpool
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A GC implementation must provide these functions.  They are internal    to the GC system.  */
end_comment

begin_comment
comment|/* Forward declare the zone structure.  Only ggc_zone implements this.  */
end_comment

begin_struct_decl
struct_decl|struct
name|alloc_zone
struct_decl|;
end_struct_decl

begin_comment
comment|/* Initialize the garbage collector.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_ggc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Start a new GGC zone.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|alloc_zone
modifier|*
name|new_ggc_zone
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free a complete GGC zone, destroying everything in it.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|destroy_ggc_zone
parameter_list|(
name|struct
name|alloc_zone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ggc_pch_data
struct_decl|;
end_struct_decl

begin_comment
comment|/* Return a new ggc_pch_data structure.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|ggc_pch_data
modifier|*
name|init_ggc_pch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The second parameter and third parameters give the address and size    of an object.  Update the ggc_pch_data structure with as much of    that information as is necessary. The bool argument should be true    if the object is a string.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ggc_pch_count_object
parameter_list|(
name|struct
name|ggc_pch_data
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|bool
parameter_list|,
name|enum
name|gt_types_enum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the total size of the data to be written to hold all    the objects previously passed to ggc_pch_count_object.  */
end_comment

begin_function_decl
specifier|extern
name|size_t
name|ggc_pch_total_size
parameter_list|(
name|struct
name|ggc_pch_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The objects, when read, will most likely be at the address    in the second parameter.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ggc_pch_this_base
parameter_list|(
name|struct
name|ggc_pch_data
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assuming that the objects really do end up at the address    passed to ggc_pch_this_base, return the address of this object.    The bool argument should be true if the object is a string.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|ggc_pch_alloc_object
parameter_list|(
name|struct
name|ggc_pch_data
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|bool
parameter_list|,
name|enum
name|gt_types_enum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write out any initial information required.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ggc_pch_prepare_write
parameter_list|(
name|struct
name|ggc_pch_data
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write out this object, including any padding.  The last argument should be    true if the object is a string.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ggc_pch_write_object
parameter_list|(
name|struct
name|ggc_pch_data
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* All objects have been written, write out any final information    required.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ggc_pch_finish
parameter_list|(
name|struct
name|ggc_pch_data
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A PCH file has just been read in at the address specified second    parameter.  Set up the GC implementation for the new objects.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ggc_pch_read
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Allocation.  */
end_comment

begin_comment
comment|/* When set, ggc_collect will do collection.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|ggc_force_collect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The internal primitive.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|ggc_alloc_stat
parameter_list|(
name|size_t
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ggc_alloc
parameter_list|(
name|s
parameter_list|)
value|ggc_alloc_stat (s MEM_STAT_INFO)
end_define

begin_comment
comment|/* Allocate an object of the specified type and size.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|ggc_alloc_typed_stat
parameter_list|(
name|enum
name|gt_types_enum
parameter_list|,
name|size_t
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ggc_alloc_typed
parameter_list|(
name|s
parameter_list|,
name|z
parameter_list|)
value|ggc_alloc_typed_stat (s,z MEM_STAT_INFO)
end_define

begin_comment
comment|/* Like ggc_alloc, but allocates cleared memory.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|ggc_alloc_cleared_stat
parameter_list|(
name|size_t
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ggc_alloc_cleared
parameter_list|(
name|s
parameter_list|)
value|ggc_alloc_cleared_stat (s MEM_STAT_INFO)
end_define

begin_comment
comment|/* Resize a block.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|ggc_realloc_stat
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ggc_realloc
parameter_list|(
name|s
parameter_list|,
name|z
parameter_list|)
value|ggc_realloc_stat (s,z MEM_STAT_INFO)
end_define

begin_comment
comment|/* Like ggc_alloc_cleared, but performs a multiplication.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|ggc_calloc
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free a block.  To be used when known for certain it's not reachable.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ggc_free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ggc_record_overhead
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ggc_free_overhead
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ggc_prune_overhead_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_ggc_loc_statistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Type-safe, C++-friendly versions of ggc_alloc() and gcc_calloc().  */
end_comment

begin_define
define|#
directive|define
name|GGC_NEW
parameter_list|(
name|T
parameter_list|)
value|((T *) ggc_alloc (sizeof (T)))
end_define

begin_define
define|#
directive|define
name|GGC_CNEW
parameter_list|(
name|T
parameter_list|)
value|((T *) ggc_alloc_cleared (sizeof (T)))
end_define

begin_define
define|#
directive|define
name|GGC_NEWVEC
parameter_list|(
name|T
parameter_list|,
name|N
parameter_list|)
value|((T *) ggc_alloc ((N) * sizeof(T)))
end_define

begin_define
define|#
directive|define
name|GGC_CNEWVEC
parameter_list|(
name|T
parameter_list|,
name|N
parameter_list|)
value|((T *) ggc_alloc_cleared ((N) * sizeof(T)))
end_define

begin_define
define|#
directive|define
name|GGC_NEWVAR
parameter_list|(
name|T
parameter_list|,
name|S
parameter_list|)
value|((T *) ggc_alloc ((S)))
end_define

begin_define
define|#
directive|define
name|GGC_CNEWVAR
parameter_list|(
name|T
parameter_list|,
name|S
parameter_list|)
value|((T *) ggc_alloc_cleared ((S)))
end_define

begin_define
define|#
directive|define
name|GGC_RESIZEVEC
parameter_list|(
name|T
parameter_list|,
name|P
parameter_list|,
name|N
parameter_list|)
value|((T *) ggc_realloc ((P), (N) * sizeof (T)))
end_define

begin_define
define|#
directive|define
name|ggc_alloc_rtvec
parameter_list|(
name|NELT
parameter_list|)
define|\
value|((rtvec) ggc_alloc_zone (sizeof (struct rtvec_def) + ((NELT) - 1)	 \ 			   * sizeof (rtx),&rtl_zone))
end_define

begin_define
define|#
directive|define
name|ggc_alloc_tree
parameter_list|(
name|LENGTH
parameter_list|)
value|((tree) ggc_alloc_zone (LENGTH,&tree_zone))
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

begin_define
define|#
directive|define
name|splay_tree_new_ggc
parameter_list|(
name|COMPARE
parameter_list|)
define|\
value|splay_tree_new_with_allocator (COMPARE, NULL, NULL,			 \&ggc_splay_alloc,&ggc_splay_dont_free, \ 				 NULL)
end_define

begin_function_decl
specifier|extern
name|void
modifier|*
name|ggc_splay_alloc
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ggc_splay_dont_free
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Allocate a gc-able string, and fill it with LENGTH bytes from CONTENTS.    If LENGTH is -1, then CONTENTS is assumed to be a    null-terminated string and the memory sized accordingly.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|ggc_alloc_string
parameter_list|(
specifier|const
name|char
modifier|*
name|contents
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|void
name|ggc_collect
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the number of bytes allocated at the indicated address.  */
end_comment

begin_function_decl
specifier|extern
name|size_t
name|ggc_get_size
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write out all GCed objects to F.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|gt_pch_save
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read objects previously saved with gt_pch_save from F.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|gt_pch_restore
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

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
comment|/* At present, we don't really gather any interesting statistics.  */
name|int
name|unused
decl_stmt|;
block|}
name|ggc_statistics
typedef|;
end_typedef

begin_comment
comment|/* Used by the various collectors to gather and print statistics that    do not depend on the collector in use.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ggc_print_common_statistics
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|ggc_statistics
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print allocation statistics.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ggc_print_statistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stringpool_statistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Heuristics.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ggc_min_expand_heuristic
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* APPLE LOCAL begin retune gc params 6124839 */
end_comment

begin_function_decl
specifier|extern
name|int
name|ggc_min_heapsize_heuristic
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_ggc_heuristics
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* APPLE LOCAL end retune gc params 6124839 */
end_comment

begin_comment
comment|/* Zone collection.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GGC_ZONE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|GENERATOR_FILE
argument_list|)
end_if

begin_comment
comment|/* For regular rtl allocations.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|alloc_zone
name|rtl_zone
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For regular tree allocations.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|alloc_zone
name|tree_zone
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For IDENTIFIER_NODE allocations.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|alloc_zone
name|tree_id_zone
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate an object into the specified allocation zone.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|ggc_alloc_zone_stat
parameter_list|(
name|size_t
parameter_list|,
name|struct
name|alloc_zone
modifier|*
name|MEM_STAT_DECL
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ggc_alloc_zone
parameter_list|(
name|s
parameter_list|,
name|z
parameter_list|)
value|ggc_alloc_zone_stat (s,z MEM_STAT_INFO)
end_define

begin_define
define|#
directive|define
name|ggc_alloc_zone_pass_stat
parameter_list|(
name|s
parameter_list|,
name|z
parameter_list|)
value|ggc_alloc_zone_stat (s,z PASS_MEM_STAT)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ggc_alloc_zone
parameter_list|(
name|s
parameter_list|,
name|z
parameter_list|)
value|ggc_alloc (s)
end_define

begin_define
define|#
directive|define
name|ggc_alloc_zone_pass_stat
parameter_list|(
name|s
parameter_list|,
name|z
parameter_list|)
value|ggc_alloc_stat (s PASS_MEM_STAT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

