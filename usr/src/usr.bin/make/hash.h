begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)hash.h	5.2 (Berkeley) %G%  */
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

begin_include
include|#
directive|include
file|"list.h"
end_include

begin_comment
comment|/*   * The following defines one entry in the hash table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Hash_Entry
block|{
name|List_Links
name|links
decl_stmt|;
comment|/* Used to link together all the     					 * entries associated with the same 					 * bucket. */
name|ClientData
name|clientData
decl_stmt|;
comment|/* Arbitrary piece of data associated     					 * with key. */
union|union
block|{
name|Address
name|ptr
decl_stmt|;
comment|/* One-word key value to identify 					 * entry. */
name|int
name|words
index|[
literal|1
index|]
decl_stmt|;
comment|/* N-word key value.  Note: the actual 					 * size may be longer if necessary to 					 * hold the entire key. */
name|char
name|name
index|[
literal|4
index|]
decl_stmt|;
comment|/* Text name of this entry.  Note: the 					 * actual size may be longer if 					 * necessary to hold the whole string. 					 * This MUST be the last entry in the 					 * structure!!! */
block|}
name|key
union|;
block|}
name|Hash_Entry
typedef|;
end_typedef

begin_comment
comment|/*   * A hash table consists of an array of pointers to hash  * lists.  Tables can be organized in either of three ways, depending  * on the type of comparison keys:  *  *	Strings:	  these are NULL-terminated; their address  *			  is passed to HashFind as a (char *).  *	Single-word keys: these may be anything, but must be passed  *			  to Hash_Find as an Address.  *	Multi-word keys:  these may also be anything; their address  *			  is passed to HashFind as an Address.  *  *	Single-word keys are fastest, but most restrictive.  */
end_comment

begin_define
define|#
directive|define
name|HASH_STRING_KEYS
value|0
end_define

begin_define
define|#
directive|define
name|HASH_ONE_WORD_KEYS
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|Hash_Table
block|{
name|List_Links
modifier|*
name|bucketPtr
decl_stmt|;
comment|/* Pointer to array of List_Links, one     				 * for each bucket in the table. */
name|int
name|size
decl_stmt|;
comment|/* Actual size of array. */
name|int
name|numEntries
decl_stmt|;
comment|/* Number of entries in the table. */
name|int
name|downShift
decl_stmt|;
comment|/* Shift count, used in hashing function. */
name|int
name|mask
decl_stmt|;
comment|/* Used to select bits for hashing. */
name|int
name|keyType
decl_stmt|;
comment|/* Type of keys used in table:     				 * HASH_STRING_KEYS, HASH_ONE-WORD_KEYS, 				 * or>1 menas keyType gives number of words 				 * in keys. 				 */
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
name|List_Links
modifier|*
name|hashList
decl_stmt|;
comment|/* Hash chain currently being checked. */
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
comment|/*   * Hash_SetValue(h, val);   *     HashEntry *h;   *     char *val;   */
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

begin_comment
comment|/*  * The following procedure declarations and macros  * are the only things that should be needed outside  * the implementation code.  */
end_comment

begin_function_decl
specifier|extern
name|Hash_Entry
modifier|*
name|Hash_CreateEntry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Hash_DeleteTable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Hash_DeleteEntry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Hash_DeleteTable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Hash_Entry
modifier|*
name|Hash_EnumFirst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Hash_Entry
modifier|*
name|Hash_EnumNext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Hash_Entry
modifier|*
name|Hash_FindEntry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Hash_InitTable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Hash_PrintStats
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|_HASH
end_endif

end_unit

