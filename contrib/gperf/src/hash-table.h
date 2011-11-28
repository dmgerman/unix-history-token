begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Hash table used to check for duplicate keyword entries.     Copyright (C) 1989-1998, 2000, 2002 Free Software Foundation, Inc.    Written by Douglas C. Schmidt<schmidt@ics.uci.edu>    and Bruno Haible<bruno@clisp.org>.     This file is part of GNU GPERF.     GNU GPERF is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU GPERF is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation, Inc.,    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|hash_table_h
end_ifndef

begin_define
define|#
directive|define
name|hash_table_h
value|1
end_define

begin_include
include|#
directive|include
file|"keyword.h"
end_include

begin_comment
comment|/* Hash table of KeywordExt* entries.    Two entries are considered equal if their _selchars are the same and    - if !ignore_length - if their _allchars_length are the same.  */
end_comment

begin_decl_stmt
name|class
name|Hash_Table
block|{
name|public
label|:
comment|/* Constructor.      size is the maximum number of entries.      ignore_length determines a detail in the comparison function.  */
name|Hash_Table
argument_list|(
argument|unsigned int size
argument_list|,
argument|bool ignore_length
argument_list|)
empty_stmt|;
comment|/* Destructor.  */
operator|~
name|Hash_Table
argument_list|()
expr_stmt|;
comment|/* Attempts to insert ITEM in the table.  If there is already an equal      entry in it, returns it.  Otherwise inserts ITEM and returns NULL.  */
name|KeywordExt
modifier|*
name|insert
parameter_list|(
name|KeywordExt
modifier|*
name|item
parameter_list|)
function_decl|;
comment|/* Print the table's contents.  */
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|/* Vector of entries.  */
name|KeywordExt
modifier|*
modifier|*
name|_table
decl_stmt|;
comment|/* Size of the vector.  */
name|unsigned
name|int
name|_size
decl_stmt|;
comment|/* log2(_size).  */
name|unsigned
name|int
name|_log_size
decl_stmt|;
comment|/* A detail of the comparison function.  */
name|bool
specifier|const
name|_ignore_length
decl_stmt|;
comment|/* Statistics: Number of collisions so far.  */
name|unsigned
name|int
name|_collisions
decl_stmt|;
comment|/* Compares two items.  */
name|bool
name|equal
argument_list|(
name|KeywordExt
operator|*
name|item1
argument_list|,
name|KeywordExt
operator|*
name|item2
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

