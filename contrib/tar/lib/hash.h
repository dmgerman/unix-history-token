begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hash - hashing table processing.    Copyright (C) 1998, 1999 Free Software Foundation, Inc.    Written by Jim Meyering<meyering@ascend.com>, 1998.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|PROTOTYPES
operator|||
name|__STDC__
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
argument_list|(
argument|*Hash_hasher
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|bool
argument_list|(
argument|*Hash_comparator
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
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
argument|*Hash_data_freer
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|bool
argument_list|(
argument|*Hash_processor
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
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

begin_struct
struct|struct
name|hash_table
block|{
comment|/* The array of buckets starts at BUCKET and extends to BUCKET_LIMIT-1,        for a possibility of N_BUCKETS.  Among those, N_BUCKETS_USED buckets        are not empty, there are N_ENTRIES active entries in the table.  */
name|struct
name|hash_entry
modifier|*
name|bucket
decl_stmt|;
name|struct
name|hash_entry
modifier|*
name|bucket_limit
decl_stmt|;
name|unsigned
name|n_buckets
decl_stmt|;
name|unsigned
name|n_buckets_used
decl_stmt|;
name|unsigned
name|n_entries
decl_stmt|;
comment|/* Tuning arguments, kept in a physicaly separate structure.  */
specifier|const
name|Hash_tuning
modifier|*
name|tuning
decl_stmt|;
comment|/* Three functions are given to `hash_initialize', see the documentation        block for this function.  In a word, HASHER randomizes a user entry        into a number up from 0 up to some maximum minus 1; COMPARATOR returns        true if two user entries compare equally; and DATA_FREER is the cleanup        function for a user entry.  */
name|Hash_hasher
name|hasher
decl_stmt|;
name|Hash_comparator
name|comparator
decl_stmt|;
name|Hash_data_freer
name|data_freer
decl_stmt|;
comment|/* A linked list of freed struct hash_entry structs.  */
name|struct
name|hash_entry
modifier|*
name|free_entry_list
decl_stmt|;
if|#
directive|if
name|USE_OBSTACK
comment|/* Whenever obstacks are used, it is possible to allocate all overflowed        entries into a single stack, so they all can be freed in a single        operation.  It is not clear if the speedup is worth the trouble.  */
name|struct
name|obstack
name|entry_stack
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

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

begin_decl_stmt
name|unsigned
name|hash_get_n_buckets
name|PARAMS
argument_list|(
operator|(
specifier|const
name|Hash_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|hash_get_n_buckets_used
name|PARAMS
argument_list|(
operator|(
specifier|const
name|Hash_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|hash_get_n_entries
name|PARAMS
argument_list|(
operator|(
specifier|const
name|Hash_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|hash_get_max_bucket_length
name|PARAMS
argument_list|(
operator|(
specifier|const
name|Hash_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|hash_table_ok
name|PARAMS
argument_list|(
operator|(
specifier|const
name|Hash_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hash_print_statistics
name|PARAMS
argument_list|(
operator|(
specifier|const
name|Hash_table
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|hash_lookup
name|PARAMS
argument_list|(
operator|(
specifier|const
name|Hash_table
operator|*
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Walking.  */
end_comment

begin_decl_stmt
name|void
modifier|*
name|hash_get_first
name|PARAMS
argument_list|(
operator|(
specifier|const
name|Hash_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|hash_get_next
name|PARAMS
argument_list|(
operator|(
specifier|const
name|Hash_table
operator|*
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|hash_get_entries
name|PARAMS
argument_list|(
operator|(
specifier|const
name|Hash_table
operator|*
operator|,
name|void
operator|*
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|hash_do_for_each
name|PARAMS
argument_list|(
operator|(
specifier|const
name|Hash_table
operator|*
operator|,
name|Hash_processor
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocation and clean-up.  */
end_comment

begin_decl_stmt
name|unsigned
name|hash_string
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hash_reset_tuning
name|PARAMS
argument_list|(
operator|(
name|Hash_tuning
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Hash_table
modifier|*
name|hash_initialize
name|PARAMS
argument_list|(
operator|(
name|unsigned
operator|,
specifier|const
name|Hash_tuning
operator|*
operator|,
name|Hash_hasher
operator|,
name|Hash_comparator
operator|,
name|Hash_data_freer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hash_clear
name|PARAMS
argument_list|(
operator|(
name|Hash_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hash_free
name|PARAMS
argument_list|(
operator|(
name|Hash_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Insertion and deletion.  */
end_comment

begin_decl_stmt
name|bool
name|hash_rehash
name|PARAMS
argument_list|(
operator|(
name|Hash_table
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|hash_insert
name|PARAMS
argument_list|(
operator|(
name|Hash_table
operator|*
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|hash_delete
name|PARAMS
argument_list|(
operator|(
name|Hash_table
operator|*
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

