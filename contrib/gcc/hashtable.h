begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Hash tables.    Copyright (C) 2000, 2001 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_struct
struct|struct
name|ht_identifier
block|{
name|unsigned
name|int
name|len
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|str
decl_stmt|;
block|}
struct|;
end_struct

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

begin_comment
comment|/* We want code outside cpplib, such as the compiler front-ends, to be    able to include this header, and to be able to link with    cpphashtbl.o without pulling in any other parts of cpplib.  */
end_comment

begin_struct_decl
struct_decl|struct
name|cpp_reader
struct_decl|;
end_struct_decl

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
argument_list|(
argument|*alloc_node
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|hash_table
operator|*
operator|)
argument_list|)
expr_stmt|;
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

begin_decl_stmt
specifier|extern
name|void
name|gcc_obstack_init
name|PARAMS
argument_list|(
operator|(
expr|struct
name|obstack
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialise the hashtable with 2 ^ order entries.  */
end_comment

begin_decl_stmt
specifier|extern
name|hash_table
modifier|*
name|ht_create
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|order
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Frees all memory associated with a hash table.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ht_destroy
name|PARAMS
argument_list|(
operator|(
name|hash_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|hashnode
name|ht_lookup
name|PARAMS
argument_list|(
operator|(
name|hash_table
operator|*
operator|,
specifier|const
name|unsigned
name|char
operator|*
operator|,
name|unsigned
name|int
operator|,
expr|enum
name|ht_lookup_option
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For all nodes in TABLE, make a callback.  The callback takes    TABLE->PFILE, the node, and a PTR, and the callback sequence stops    if the callback returns zero.  */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*ht_cb
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|cpp_reader
operator|*
operator|,
name|hashnode
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|ht_forall
name|PARAMS
argument_list|(
operator|(
name|hash_table
operator|*
operator|,
name|ht_cb
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dump allocation statistics to stderr.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ht_dump_statistics
name|PARAMS
argument_list|(
operator|(
name|hash_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Approximate positive square root of a host double.  This is for    statistical reports, not code generation.  */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|approx_sqrt
name|PARAMS
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_HASHTABLE_H */
end_comment

end_unit

