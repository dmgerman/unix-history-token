begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Compact a sparse 2-D matrix.  Uses the Tarjan and Yao algorithm    taken from the article ``Storing a Sparse Table'' in CACM, 1979.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)        This file is part of GNU TRIE-GEN.        GNU TRIE-GEN is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.        GNU TRIE-GEN is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with GNU trie-gen; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_comment
comment|/* This really should go in the class scope, but alas g++ doesn't like that... */
end_comment

begin_typedef
typedef|typedef
name|int
name|ITEM_TYPE
typedef|;
end_typedef

begin_decl_stmt
name|class
name|Compact_Matrix
block|{
name|public
label|:
name|Compact_Matrix
argument_list|(
argument|ITEM_TYPE *mat
argument_list|,
argument|int rows
argument_list|,
argument|int cols
argument_list|)
empty_stmt|;
name|Compact_Matrix
argument_list|(
argument|int default_rows =
literal|0
argument_list|)
empty_stmt|;
name|ITEM_TYPE
name|operator
argument_list|()
operator|(
name|int
name|i
operator|,
name|int
name|j
operator|)
expr_stmt|;
name|void
name|operator
argument_list|()
operator|(
name|int
name|i
operator|,
name|int
name|j
operator|,
name|ITEM_TYPE
name|value
operator|)
expr_stmt|;
name|void
name|output
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|private
label|:
struct|struct
name|Column_Node
block|{
name|int
name|index
decl_stmt|;
comment|/* Actual column index in the current row. */
name|ITEM_TYPE
name|value
decl_stmt|;
comment|/* Value at this index location. */
name|Column_Node
modifier|*
name|next
decl_stmt|;
comment|/* Pointer to next column in the row. */
name|Column_Node
argument_list|(
argument|Column_Node *p
argument_list|,
argument|int i
argument_list|,
argument|ITEM_TYPE v
argument_list|)
block|:
name|index
argument_list|(
name|i
argument_list|)
operator|,
name|value
argument_list|(
name|v
argument_list|)
operator|,
name|next
argument_list|(
argument|p
argument_list|)
block|{}
block|}
struct|;
struct|struct
name|Row_Node
block|{
name|Column_Node
modifier|*
name|col_list
init|=
literal|0
decl_stmt|;
comment|/* List of column index values for this row. */
name|int
name|count
init|=
literal|0
decl_stmt|;
comment|/* Count of total number of columns in the list. */
block|}
struct|;
specifier|const
name|int
name|MAX_INT
init|=
operator|~
name|unsigned
argument_list|(
literal|0
argument_list|)
operator|>>
literal|1
decl_stmt|;
specifier|const
name|int
name|MAX_SIGNED_CHAR
init|=
literal|127
decl_stmt|;
specifier|const
name|int
name|MAX_ASCII_RANGE
init|=
literal|128
decl_stmt|;
specifier|const
name|int
name|MAX_SIGNED_SHORT
init|=
literal|32767
decl_stmt|;
specifier|const
name|int
name|MAX_UNSIGNED_CHAR
init|=
literal|255
decl_stmt|;
specifier|const
name|int
name|MAX_UNSIGNED_SHORT
init|=
literal|65535
decl_stmt|;
name|int
name|max_col_count
init|=
literal|0
decl_stmt|;
comment|/* Total number of columns in largest row. */
name|int
name|total_cols
init|=
literal|0
decl_stmt|;
comment|/* Total number of columns in the matrix (if applicable). */
name|int
name|total_entries
init|=
literal|0
decl_stmt|;
comment|/* Total number of non-null entries in the matrix. */
name|int
name|compressed_len
init|=
operator|-
literal|1
decl_stmt|;
comment|/* Size of the compacted matrix buffer. */
name|int
modifier|*
name|row_offsets
init|=
literal|0
decl_stmt|;
comment|/* Dynamic buffer used for double-offset indexing. */
name|int
modifier|*
name|checks
init|=
literal|0
decl_stmt|;
comment|/* Dynamic buffer used for double-offset indexing. */
name|int
name|current_rows
init|=
literal|0
decl_stmt|;
comment|/* Current items in ROW_VEC, at this point. */
name|int
name|max_rows
init|=
literal|0
decl_stmt|;
comment|/* Maximum size of ROW_VEC, at this point. */
name|Row_Node
modifier|*
name|row_vec
init|=
literal|0
decl_stmt|;
comment|/* Dynamic buffer indexed by row number. */
name|Column_Node
modifier|*
modifier|*
name|bucket_vec
init|=
literal|0
decl_stmt|;
comment|/* Dynamic buffer used to sort by column count. */
name|ITEM_TYPE
modifier|*
name|values
init|=
literal|0
decl_stmt|;
comment|/* Dynamic buffer containing non-null matrix values. */
name|ITEM_TYPE
modifier|*
name|matrix
init|=
literal|0
decl_stmt|;
comment|/* Pointer to 2-D matrix (if appropriate). */
name|void
name|resize
parameter_list|(
name|int
name|new_size
parameter_list|)
function_decl|;
name|void
name|first_fit_decreasing
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|bucket_sort
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|output_lookup
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|output_arrays
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|dump_entries
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|dump_bucket
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

