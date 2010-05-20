begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hash - hashing table processing.    Copyright (C) 1998, 1999, 2001, 2003 Free Software Foundation, Inc.    Written by Jim Meyering<meyering@ascend.com>, 1998.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* A generic hash table package.  */
end_comment

begin_comment
comment|/* Make sure USE_OBSTACK is defined to 1 if you want the allocator to use    obstacks instead of malloc, and recompile `hash.c' with same setting.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASH_H_
end_ifndef

begin_define
define|#
directive|define
name|HASH_H_
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_typedef
typedef|typedef
name|size_t
function_decl|(
modifier|*
name|Hash_hasher
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|Hash_comparator
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
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|Hash_data_freer
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|Hash_processor
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

begin_struct
struct|struct
name|hash_entry
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|struct
name|hash_entry
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hash_tuning
block|{
comment|/* This structure is mainly used for `hash_initialize', see the block        documentation of `hash_reset_tuning' for more complete comments.  */
name|float
name|shrink_threshold
decl_stmt|;
comment|/* ratio of used buckets to trigger a shrink */
name|float
name|shrink_factor
decl_stmt|;
comment|/* ratio of new smaller size to original size */
name|float
name|growth_threshold
decl_stmt|;
comment|/* ratio of used buckets to trigger a growth */
name|float
name|growth_factor
decl_stmt|;
comment|/* ratio of new bigger size to original size */
name|bool
name|is_n_buckets
decl_stmt|;
comment|/* if CANDIDATE really means table size */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hash_tuning
name|Hash_tuning
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|hash_table
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|hash_table
name|Hash_table
typedef|;
end_typedef

begin_comment
comment|/* Information and lookup.  */
end_comment

begin_function_decl
name|size_t
name|hash_get_n_buckets
parameter_list|(
specifier|const
name|Hash_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|hash_get_n_buckets_used
parameter_list|(
specifier|const
name|Hash_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|hash_get_n_entries
parameter_list|(
specifier|const
name|Hash_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|hash_get_max_bucket_length
parameter_list|(
specifier|const
name|Hash_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|hash_table_ok
parameter_list|(
specifier|const
name|Hash_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hash_print_statistics
parameter_list|(
specifier|const
name|Hash_table
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|hash_lookup
parameter_list|(
specifier|const
name|Hash_table
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Walking.  */
end_comment

begin_function_decl
name|void
modifier|*
name|hash_get_first
parameter_list|(
specifier|const
name|Hash_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|hash_get_next
parameter_list|(
specifier|const
name|Hash_table
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|hash_get_entries
parameter_list|(
specifier|const
name|Hash_table
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|hash_do_for_each
parameter_list|(
specifier|const
name|Hash_table
modifier|*
parameter_list|,
name|Hash_processor
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Allocation and clean-up.  */
end_comment

begin_function_decl
name|size_t
name|hash_string
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hash_reset_tuning
parameter_list|(
name|Hash_tuning
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Hash_table
modifier|*
name|hash_initialize
parameter_list|(
name|size_t
parameter_list|,
specifier|const
name|Hash_tuning
modifier|*
parameter_list|,
name|Hash_hasher
parameter_list|,
name|Hash_comparator
parameter_list|,
name|Hash_data_freer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hash_clear
parameter_list|(
name|Hash_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hash_free
parameter_list|(
name|Hash_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Insertion and deletion.  */
end_comment

begin_function_decl
name|bool
name|hash_rehash
parameter_list|(
name|Hash_table
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|hash_insert
parameter_list|(
name|Hash_table
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|hash_delete
parameter_list|(
name|Hash_table
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

