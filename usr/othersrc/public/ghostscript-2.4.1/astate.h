begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* astate.h */
end_comment

begin_comment
comment|/* State structures for the Ghostscript allocator */
end_comment

begin_comment
comment|/* Define pointers to an allocation state. */
end_comment

begin_comment
comment|/****** Note the _ds (for Turbo C only). ******/
end_comment

begin_typedef
typedef|typedef
name|struct
name|alloc_state_s
name|alloc_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|alloc_state
name|_ds
modifier|*
name|alloc_state_ptr
typedef|;
end_typedef

begin_comment
comment|/* The only instance.... */
end_comment

begin_decl_stmt
specifier|extern
name|alloc_state_ptr
name|alloc_state_current
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Round up sizes of aligned objects. */
end_comment

begin_define
define|#
directive|define
name|log2_align_mod
value|3
end_define

begin_comment
comment|/* log2(sizeof(double)) */
end_comment

begin_define
define|#
directive|define
name|align_mod
value|(1<<log2_align_mod)
end_define

begin_define
define|#
directive|define
name|align_mask
value|(align_mod-1)
end_define

begin_define
define|#
directive|define
name|align_round
parameter_list|(
name|siz
parameter_list|)
value|(uint)(((siz) + align_mask)& -align_mod)
end_define

begin_comment
comment|/* Max object size for separate free list */
end_comment

begin_define
define|#
directive|define
name|max_chain_size
value|350
end_define

begin_comment
comment|/* Structure for a separately allocated block. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|alloc_block_s
name|alloc_block
typedef|;
end_typedef

begin_struct
struct|struct
name|alloc_block_s
block|{
name|alloc_block
modifier|*
name|next
decl_stmt|;
name|uint
name|size
decl_stmt|;
name|int
name|save_level
decl_stmt|;
name|alloc_state_ptr
name|cap
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|alloc_block_size
value|align_round(sizeof(alloc_block))
end_define

begin_comment
comment|/* Structure for a single wholesale allocation 'chunk'. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|alloc_chunk_s
name|alloc_chunk
typedef|;
end_typedef

begin_struct
struct|struct
name|alloc_chunk_s
block|{
comment|/* Note that allocation takes place both from the bottom up */
comment|/* (aligned objects) and from the top down (byte objects). */
name|byte
modifier|*
name|base
decl_stmt|;
name|byte
modifier|*
name|bot
decl_stmt|;
comment|/* bottom of free area */
comment|/* (top of aligned objects) */
name|byte
modifier|*
name|top
decl_stmt|;
comment|/* top of free area */
comment|/* (bottom of byte objects) */
name|byte
modifier|*
name|limit
decl_stmt|;
name|int
name|save_level
decl_stmt|;
comment|/* save level when this chunk */
comment|/* was allocated */
name|alloc_chunk
modifier|*
name|next
decl_stmt|;
comment|/* chain chunks together */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ptr_is_in_chunk
parameter_list|(
name|ptr
parameter_list|,
name|chunk
parameter_list|)
define|\
value|ptr_between(ptr, (chunk)->base, (chunk)->limit)
end_define

begin_comment
comment|/* Structures for save/restore (not defined here). */
end_comment

begin_struct_decl
struct_decl|struct
name|alloc_save_s
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|alloc_change_s
struct_decl|;
end_struct_decl

begin_comment
comment|/* Structure for allocator state.  If we multi-thread some day, */
end_comment

begin_comment
comment|/* this might be instantiated more than once. */
end_comment

begin_struct
struct|struct
name|alloc_state_s
block|{
name|alloc_chunk
name|current
decl_stmt|;
comment|/* the current chunk */
define|#
directive|define
name|cbase
value|current.base
define|#
directive|define
name|cbot
value|current.bot
define|#
directive|define
name|ctop
value|current.top
define|#
directive|define
name|climit
value|current.limit
name|alloc_chunk
modifier|*
name|current_ptr
decl_stmt|;
comment|/* where to put current */
name|uint
name|chunk_size
decl_stmt|;
comment|/* unit for wholesale malloc */
name|uint
name|big_size
decl_stmt|;
comment|/* min size for separate malloc */
name|proc_alloc_t
name|palloc
decl_stmt|;
comment|/* proc for malloc */
name|proc_free_t
name|pfree
decl_stmt|;
comment|/* proc for free */
name|alloc_chunk
modifier|*
name|last_freed
decl_stmt|;
comment|/* cache the last non-current chunk */
comment|/* at the current save level */
comment|/* where we freed an object */
comment|/* Statistics */
name|long
name|used
decl_stmt|;
comment|/* total space used, including */
comment|/* malloc'ed blocks and all chunks */
comment|/* other than the current one */
name|long
name|total
decl_stmt|;
comment|/* total space allocated, */
comment|/* other than malloc'ed blocks */
name|unsigned
name|num_chunks
decl_stmt|;
comment|/* Chain together freed objects within a save level. */
comment|/* We only do this for aligned objects. */
define|#
directive|define
name|num_free_chains
value|((max_chain_size>> log2_align_mod) + 1)
name|char
modifier|*
name|free
index|[
name|num_free_chains
index|]
decl_stmt|;
comment|/* Chain together any malloc'ed objects */
name|alloc_block
modifier|*
name|malloc_chain
decl_stmt|;
comment|/* Keep track of saved states */
name|int
name|save_level
decl_stmt|;
name|struct
name|alloc_save_s
modifier|*
name|saved
decl_stmt|;
name|byte
modifier|*
name|saved_cbot
decl_stmt|;
comment|/* cbot at last save */
name|byte
modifier|*
name|saved_ctop
decl_stmt|;
comment|/* ctop at last save */
name|struct
name|alloc_change_s
modifier|*
name|changes
decl_stmt|;
block|}
struct|;
end_struct

end_unit

