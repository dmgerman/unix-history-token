begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Hash tables for Objective C method dispatch.    Copyright (C) 1993, 1995, 1996 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files    compiled with GCC to produce an executable, this does not cause    the resulting executable to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__hash_INCLUDE_GNU
end_ifndef

begin_define
define|#
directive|define
name|__hash_INCLUDE_GNU
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<objc/objc.h>
end_include

begin_comment
comment|/*  * This data structure is used to hold items  *  stored in a hash table.  Each node holds   *  a key/value pair.  *  * Items in the cache are really of type void *.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cache_node
block|{
name|struct
name|cache_node
modifier|*
name|next
decl_stmt|;
comment|/* Pointer to next entry on the list. 				   NULL indicates end of list. */
specifier|const
name|void
modifier|*
name|key
decl_stmt|;
comment|/* Key used to locate the value.  Used 				   to locate value when more than one 				   key computes the same hash 				   value. */
name|void
modifier|*
name|value
decl_stmt|;
comment|/* Value stored for the key. */
block|}
typedef|*
name|node_ptr
typedef|;
end_typedef

begin_comment
comment|/*  * This data type is the function that computes a hash code given a key.  * Therefore, the key can be a pointer to anything and the function specific  * to the key type.   *  * Unfortunately there is a mutual data structure reference problem with this  * typedef.  Therefore, to remove compiler warnings the functions passed to  * hash_new will have to be casted to this type.   */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
function_decl|(
modifier|*
name|hash_func_type
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * This data type is the function that compares two hash keys and returns an  * integer greater than, equal to, or less than 0, according as the first  * parameter is lexicographically greater than, equal to, or less than the  * second.   */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|compare_func_type
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

begin_comment
comment|/*  * This data structure is the cache.  *  * It must be passed to all of the hashing routines  *   (except for new).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cache
block|{
comment|/* Variables used to implement the hash itself.  */
name|node_ptr
modifier|*
name|node_table
decl_stmt|;
comment|/* Pointer to an array of hash nodes.  */
comment|/* Variables used to track the size of the hash table so to determine     when to resize it.  */
name|unsigned
name|int
name|size
decl_stmt|;
comment|/* Number of buckets allocated for the hash table 			(number of array entries allocated for 			"node_table").  Must be a power of two.  */
name|unsigned
name|int
name|used
decl_stmt|;
comment|/* Current number of entries in the hash table.  */
name|unsigned
name|int
name|mask
decl_stmt|;
comment|/* Precomputed mask.  */
comment|/* Variables used to implement indexing through the hash table.  */
name|unsigned
name|int
name|last_bucket
decl_stmt|;
comment|/* Tracks which entry in the array where 			       the last value was returned.  */
comment|/* Function used to compute a hash code given a key.       This function is specified when the hash table is created.  */
name|hash_func_type
name|hash_func
decl_stmt|;
comment|/* Function used to compare two hash keys to see if they are equal.  */
name|compare_func_type
name|compare_func
decl_stmt|;
block|}
typedef|*
name|cache_ptr
typedef|;
end_typedef

begin_comment
comment|/* Two important hash tables.  */
end_comment

begin_decl_stmt
specifier|extern
name|cache_ptr
name|module_hash_table
decl_stmt|,
name|class_hash_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate and initialize a hash table.  */
end_comment

begin_function_decl
name|cache_ptr
name|hash_new
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|,
name|hash_func_type
name|hash_func
parameter_list|,
name|compare_func_type
name|compare_func
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Deallocate all of the hash nodes and the cache itself.  */
end_comment

begin_function_decl
name|void
name|hash_delete
parameter_list|(
name|cache_ptr
name|cache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add the key/value pair to the hash table.  If the    hash table reaches a level of fullness then it will be resized.                                                         assert if the key is already in the hash.  */
end_comment

begin_function_decl
name|void
name|hash_add
parameter_list|(
name|cache_ptr
modifier|*
name|cachep
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Remove the key/value pair from the hash table.      assert if the key isn't in the table.  */
end_comment

begin_function_decl
name|void
name|hash_remove
parameter_list|(
name|cache_ptr
name|cache
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used to index through the hash table.  Start with NULL    to get the first entry.                                                       Successive calls pass the value returned previously.    ** Don't modify the hash during this operation ***                                                        Cache nodes are returned such that key or value can    be extracted.  */
end_comment

begin_function_decl
name|node_ptr
name|hash_next
parameter_list|(
name|cache_ptr
name|cache
parameter_list|,
name|node_ptr
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used to return a value from a hash table using a given key.  */
end_comment

begin_function_decl
name|void
modifier|*
name|hash_value_for_key
parameter_list|(
name|cache_ptr
name|cache
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used to determine if the given key exists in the hash table */
end_comment

begin_function_decl
name|BOOL
name|hash_is_key_in_hash
parameter_list|(
name|cache_ptr
name|cache
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************************************          Useful hashing functions.                    Declared inline for your pleasure.          ************************************************/
end_comment

begin_comment
comment|/* Calculate a hash code by performing some     manipulation of the key pointer.  (Use the lowest bits    except for those likely to be 0 due to alignment.)  */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|hash_ptr
parameter_list|(
name|cache_ptr
name|cache
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|)
block|{
return|return
operator|(
operator|(
name|size_t
operator|)
name|key
operator|/
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|)
operator|&
name|cache
operator|->
name|mask
return|;
block|}
end_function

begin_comment
comment|/* Calculate a hash code by iterating over a NULL     terminate string.  */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|hash_string
parameter_list|(
name|cache_ptr
name|cache
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|)
block|{
name|unsigned
name|int
name|ret
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|ctr
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|*
operator|(
name|char
operator|*
operator|)
name|key
condition|)
block|{
name|ret
operator|^=
operator|*
operator|(
name|char
operator|*
operator|)
name|key
operator|++
operator|<<
name|ctr
expr_stmt|;
name|ctr
operator|=
operator|(
name|ctr
operator|+
literal|1
operator|)
operator|%
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
operator|&
name|cache
operator|->
name|mask
return|;
block|}
end_function

begin_comment
comment|/* Compare two pointers for equality.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|compare_ptrs
parameter_list|(
specifier|const
name|void
modifier|*
name|k1
parameter_list|,
specifier|const
name|void
modifier|*
name|k2
parameter_list|)
block|{
return|return
operator|!
operator|(
name|k1
operator|-
name|k2
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Compare two strings.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|compare_strings
parameter_list|(
specifier|const
name|void
modifier|*
name|k1
parameter_list|,
specifier|const
name|void
modifier|*
name|k2
parameter_list|)
block|{
if|if
condition|(
name|k1
operator|==
name|k2
condition|)
return|return
literal|1
return|;
elseif|else
if|if
condition|(
name|k1
operator|==
literal|0
operator|||
name|k2
operator|==
literal|0
condition|)
return|return
literal|0
return|;
else|else
return|return
operator|!
name|strcmp
argument_list|(
name|k1
argument_list|,
name|k2
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __hash_INCLUDE_GNU */
end_comment

end_unit

