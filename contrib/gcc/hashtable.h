begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Hash tables.    Copyright (C) 2000, 2001, 2003 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_HASHTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_HASHTABLE_H
end_define

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_define
define|#
directive|define
name|GTY
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_comment
comment|/* This is what each hash table entry points to.  It may be embedded    deeply within another object.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|ht_identifier
name|ht_identifier
typedef|;
end_typedef

begin_decl_stmt
name|struct
name|ht_identifier
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
specifier|const
name|unsigned
name|char
modifier|*
name|str
decl_stmt|;
name|unsigned
name|int
name|len
decl_stmt|;
name|unsigned
name|int
name|hash_value
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|HT_LEN
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->len)
end_define

begin_define
define|#
directive|define
name|HT_STR
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->str)
end_define

begin_typedef
typedef|typedef
name|struct
name|ht
name|hash_table
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ht_identifier
modifier|*
name|hashnode
typedef|;
end_typedef

begin_enum
enum|enum
name|ht_lookup_option
block|{
name|HT_NO_INSERT
init|=
literal|0
block|,
name|HT_ALLOC
block|,
name|HT_ALLOCED
block|}
enum|;
end_enum

begin_comment
comment|/* An identifier hash table for cpplib and the front ends.  */
end_comment

begin_struct
struct|struct
name|ht
block|{
comment|/* Identifiers are allocated from here.  */
name|struct
name|obstack
name|stack
decl_stmt|;
name|hashnode
modifier|*
name|entries
decl_stmt|;
comment|/* Call back.  */
name|hashnode
function_decl|(
modifier|*
name|alloc_node
function_decl|)
parameter_list|(
name|hash_table
modifier|*
parameter_list|)
function_decl|;
name|unsigned
name|int
name|nslots
decl_stmt|;
comment|/* Total slots in the entries array.  */
name|unsigned
name|int
name|nelements
decl_stmt|;
comment|/* Number of live elements.  */
comment|/* Link to reader, if any.  For the benefit of cpplib.  */
name|struct
name|cpp_reader
modifier|*
name|pfile
decl_stmt|;
comment|/* Table usage statistics.  */
name|unsigned
name|int
name|searches
decl_stmt|;
name|unsigned
name|int
name|collisions
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Initialize the hashtable with 2 ^ order entries.  */
end_comment

begin_function_decl
specifier|extern
name|hash_table
modifier|*
name|ht_create
parameter_list|(
name|unsigned
name|int
name|order
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Frees all memory associated with a hash table.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ht_destroy
parameter_list|(
name|hash_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|hashnode
name|ht_lookup
parameter_list|(
name|hash_table
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|enum
name|ht_lookup_option
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For all nodes in TABLE, make a callback.  The callback takes    TABLE->PFILE, the node, and a PTR, and the callback sequence stops    if the callback returns zero.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|ht_cb
function_decl|)
parameter_list|(
name|struct
name|cpp_reader
modifier|*
parameter_list|,
name|hashnode
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|ht_forall
parameter_list|(
name|hash_table
modifier|*
parameter_list|,
name|ht_cb
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Dump allocation statistics to stderr.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ht_dump_statistics
parameter_list|(
name|hash_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_HASHTABLE_H */
end_comment

end_unit

