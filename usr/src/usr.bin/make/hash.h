begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * %sccs.include.redist.c%  *  *	@(#)hash.h	5.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* hash.h --  *  * 	This file contains definitions used by the hash module,  * 	which maintains hash tables.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HASH
end_ifndef

begin_define
define|#
directive|define
name|_HASH
end_define

begin_comment
comment|/*   * The following defines one entry in the hash table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Hash_Entry
block|{
name|struct
name|Hash_Entry
modifier|*
name|next
decl_stmt|;
comment|/* Used to link together all the     					 * entries associated with the same 					 * bucket. */
name|ClientData
name|clientData
decl_stmt|;
comment|/* Arbitrary piece of data associated     					 * with key. */
name|unsigned
name|namehash
decl_stmt|;
comment|/* hash value of key */
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* key string */
block|}
name|Hash_Entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Hash_Table
block|{
name|struct
name|Hash_Entry
modifier|*
modifier|*
name|bucketPtr
decl_stmt|;
comment|/* Pointers to Hash_Entry, one     				 * for each bucket in the table. */
name|int
name|size
decl_stmt|;
comment|/* Actual size of array. */
name|int
name|numEntries
decl_stmt|;
comment|/* Number of entries in the table. */
name|int
name|mask
decl_stmt|;
comment|/* Used to select bits for hashing. */
block|}
name|Hash_Table
typedef|;
end_typedef

begin_comment
comment|/*   * The following structure is used by the searching routines  * to record where we are in the search.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Hash_Search
block|{
name|Hash_Table
modifier|*
name|tablePtr
decl_stmt|;
comment|/* Table being searched. */
name|int
name|nextIndex
decl_stmt|;
comment|/* Next bucket to check (after current). */
name|Hash_Entry
modifier|*
name|hashEntryPtr
decl_stmt|;
comment|/* Next entry to check in current bucket. */
block|}
name|Hash_Search
typedef|;
end_typedef

begin_comment
comment|/*  * Macros.  */
end_comment

begin_comment
comment|/*  * ClientData Hash_GetValue(h)   *     Hash_Entry *h;   */
end_comment

begin_define
define|#
directive|define
name|Hash_GetValue
parameter_list|(
name|h
parameter_list|)
value|((h)->clientData)
end_define

begin_comment
comment|/*   * Hash_SetValue(h, val);   *     Hash_Entry *h;   *     char *val;   */
end_comment

begin_define
define|#
directive|define
name|Hash_SetValue
parameter_list|(
name|h
parameter_list|,
name|val
parameter_list|)
value|((h)->clientData = (ClientData) (val))
end_define

begin_comment
comment|/*   * Hash_Size(n) returns the number of words in an object of n bytes   */
end_comment

begin_define
define|#
directive|define
name|Hash_Size
parameter_list|(
name|n
parameter_list|)
value|(((n) + sizeof (int) - 1) / sizeof (int))
end_define

begin_decl_stmt
name|Hash_Entry
modifier|*
name|Hash_CreateEntry
name|__P
argument_list|(
operator|(
name|Hash_Table
operator|*
operator|,
name|char
operator|*
operator|,
name|Boolean
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Hash_DeleteEntry
name|__P
argument_list|(
operator|(
name|Hash_Table
operator|*
operator|,
name|Hash_Entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Hash_DeleteTable
name|__P
argument_list|(
operator|(
name|Hash_Table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Hash_Entry
modifier|*
name|Hash_EnumFirst
name|__P
argument_list|(
operator|(
name|Hash_Table
operator|*
operator|,
name|Hash_Search
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Hash_Entry
modifier|*
name|Hash_EnumNext
name|__P
argument_list|(
operator|(
name|Hash_Search
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Hash_Entry
modifier|*
name|Hash_FindEntry
name|__P
argument_list|(
operator|(
name|Hash_Table
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Hash_InitTable
name|__P
argument_list|(
operator|(
name|Hash_Table
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HASH */
end_comment

end_unit

