begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header file for generic hash table support.    Copyright (C) 1993, 1994, 1997, 1998 Free Software Foundation, Inc.    Written by Steve Chamberlain<sac@cygnus.com>  This file was lifted from BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN_GCC
end_ifndef

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IN_GCC */
end_comment

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|false
block|,
name|true
block|}
name|boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|PTR
name|hash_table_key
typedef|;
end_typedef

begin_comment
comment|/* Hash table routines.  There is no way to free up a hash table.  */
end_comment

begin_comment
comment|/* An element in the hash table.  Most uses will actually use a larger    structure, and an instance of this will be the first field.  */
end_comment

begin_struct
struct|struct
name|hash_entry
block|{
comment|/* Next entry for this hash code.  */
name|struct
name|hash_entry
modifier|*
name|next
decl_stmt|;
comment|/* The thing being hashed.  */
name|hash_table_key
name|key
decl_stmt|;
comment|/* Hash code.  This is the full hash code, not the index into the      table.  */
name|unsigned
name|long
name|hash
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A hash table.  */
end_comment

begin_struct
struct|struct
name|hash_table
block|{
comment|/* The hash array.  */
name|struct
name|hash_entry
modifier|*
modifier|*
name|table
decl_stmt|;
comment|/* The number of slots in the hash table.  */
name|unsigned
name|int
name|size
decl_stmt|;
comment|/* A function used to create new elements in the hash table.  The      first entry is itself a pointer to an element.  When this      function is first invoked, this pointer will be NULL.  However,      having the pointer permits a hierarchy of method functions to be      built each of which calls the function in the superclass.  Thus      each function should be written to allocate a new block of memory      only if the argument is NULL.  */
name|struct
name|hash_entry
modifier|*
argument_list|(
operator|*
name|newfunc
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_entry
operator|*
operator|,
expr|struct
name|hash_table
operator|*
operator|,
name|hash_table_key
operator|)
argument_list|)
decl_stmt|;
comment|/* A function to compute the hash code for a key in the hash table.  */
name|unsigned
name|long
argument_list|(
operator|*
name|hash
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|hash_table_key
operator|)
argument_list|)
decl_stmt|;
comment|/* A function to compare two keys.  */
name|boolean
argument_list|(
argument|*comp
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|hash_table_key
operator|,
name|hash_table_key
operator|)
argument_list|)
expr_stmt|;
comment|/* An obstack for this hash table.  */
name|struct
name|obstack
name|memory
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Initialize a hash table.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|hash_table_init
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_table
operator|*
operator|,
expr|struct
name|hash_entry
operator|*
call|(
modifier|*
call|)
argument_list|(
expr|struct
name|hash_entry
operator|*
argument_list|,
expr|struct
name|hash_table
operator|*
argument_list|,
name|hash_table_key
argument_list|)
operator|,
name|unsigned
name|long
argument_list|(
operator|*
name|hash
argument_list|)
argument_list|(
name|hash_table_key
argument_list|)
operator|,
name|boolean
argument_list|(
operator|*
name|comp
argument_list|)
argument_list|(
name|hash_table_key
argument_list|,
name|hash_table_key
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize a hash table specifying a size.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|hash_table_init_n
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_table
operator|*
operator|,
expr|struct
name|hash_entry
operator|*
call|(
modifier|*
call|)
argument_list|(
expr|struct
name|hash_entry
operator|*
argument_list|,
expr|struct
name|hash_table
operator|*
argument_list|,
name|hash_table_key
argument_list|)
operator|,
name|unsigned
name|long
argument_list|(
operator|*
name|hash
argument_list|)
argument_list|(
name|hash_table_key
argument_list|)
operator|,
name|boolean
argument_list|(
operator|*
name|comp
argument_list|)
argument_list|(
name|hash_table_key
argument_list|,
name|hash_table_key
argument_list|)
operator|,
name|unsigned
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free up a hash table.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|hash_table_free
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Look up KEY in a hash table.  If CREATE is true, a new entry    will be created for this KEY if one does not already exist.  If    COPY is non-NULL, it is used to copy the KEY before storing it in    the hash table.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|hash_entry
modifier|*
name|hash_lookup
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_table
operator|*
operator|,
name|hash_table_key
name|key
operator|,
name|boolean
name|create
operator|,
name|hash_table_key
argument_list|(
operator|*
name|copy
argument_list|)
argument_list|(
expr|struct
name|obstack
operator|*
argument_list|,
name|hash_table_key
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Base method for creating a hash table entry.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|hash_entry
modifier|*
name|hash_newfunc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_entry
operator|*
operator|,
expr|struct
name|hash_table
operator|*
operator|,
name|hash_table_key
name|key
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Grab some space for a hash table entry.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|hash_allocate
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_table
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Traverse a hash table in a random order, calling a function on each    element.  If the function returns false, the traversal stops.  The    INFO argument is passed to the function.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|hash_traverse
name|PARAMS
argument_list|(
operator|(
expr|struct
name|hash_table
operator|*
operator|,
name|boolean
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|hash_entry
operator|*
argument_list|,
name|hash_table_key
argument_list|)
operator|,
name|hash_table_key
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hash a string K, which is really of type `char*'.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|string_hash
name|PARAMS
argument_list|(
operator|(
name|hash_table_key
name|k
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Compare two strings K1, K2 which are really of type `char*'.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|string_compare
name|PARAMS
argument_list|(
operator|(
name|hash_table_key
name|k1
operator|,
name|hash_table_key
name|k2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copy a string K, which is really of type `char*'.  */
end_comment

begin_decl_stmt
specifier|extern
name|hash_table_key
name|string_copy
name|PARAMS
argument_list|(
operator|(
expr|struct
name|obstack
operator|*
name|memory
operator|,
name|hash_table_key
name|k
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

