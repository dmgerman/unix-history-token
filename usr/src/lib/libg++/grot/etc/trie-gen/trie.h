begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Data and member functions for generating a minimal-prefix trie.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)        This file is part of GNU TRIE-GEN.        GNU TRIE-GEN is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.        GNU TRIE-GEN is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with GNU trie-gen; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_include
include|#
directive|include
file|"compact.h"
end_include

begin_decl_stmt
name|class
name|Trie
block|{
name|public
label|:
name|Trie
argument_list|(
argument|int n
argument_list|)
block|:
name|matrix
argument_list|(
name|n
argument_list|)
operator|,
name|total_size
argument_list|(
argument|n
argument_list|)
block|{
name|keys
operator|=
name|new
name|char
operator|*
index|[
name|n
index|]
block|; }
name|void
name|insert
argument_list|(
argument|char *str
argument_list|,
argument|int len
argument_list|)
expr_stmt|;
name|void
name|output
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|sort
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|const
name|int
name|DEFAULT_SIZE
init|=
literal|1000
decl_stmt|;
comment|/* Starting guess on the total number of keys. */
name|private
label|:
specifier|const
name|int
name|MAX_SIGNED_CHAR
init|=
literal|127
decl_stmt|;
specifier|const
name|int
name|MAX_SIGNED_SHORT
init|=
literal|32767
decl_stmt|;
specifier|const
name|int
name|MAX_ASCII
init|=
literal|128
decl_stmt|;
name|Compact_Matrix
name|matrix
decl_stmt|;
comment|/* Dynamic table encoding the trie DFA. */
name|char
modifier|*
modifier|*
name|keys
decl_stmt|;
comment|/* Dynamic resizable table to store input keys. */
name|int
name|column
init|=
literal|0
decl_stmt|;
comment|/* Tracks the current column during trie generation. */
name|int
name|total_size
decl_stmt|;
comment|/* Total size of the keyword table. */
name|int
name|current_size
decl_stmt|;
comment|/* Current size of the keyword table. */
name|int
name|max_row
init|=
literal|1
decl_stmt|;
comment|/* Largest row in the trie so far. */
name|int
name|max_key_len
init|=
literal|0
decl_stmt|;
comment|/* Length of the longest keyword. */
name|void
name|resize
parameter_list|(
name|int
name|new_size
parameter_list|)
function_decl|;
name|void
name|build
parameter_list|(
name|int
name|hi
parameter_list|,
name|int
name|lo
init|=
literal|0
parameter_list|,
name|int
name|col
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|int
name|cmp
parameter_list|(
name|char
modifier|*
modifier|*
name|s1
parameter_list|,
name|char
modifier|*
modifier|*
name|s2
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

