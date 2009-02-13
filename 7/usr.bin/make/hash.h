begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)hash.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|hash_h_f6312f46
end_ifndef

begin_define
define|#
directive|define
name|hash_h_f6312f46
end_define

begin_comment
comment|/* hash.h --  *  * 	This file contains definitions used by the hash module,  * 	which maintains hash tables.  */
end_comment

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_comment
comment|/*  * The following defines one entry in the hash table.  */
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
comment|/* Link entries within same bucket. */
name|void
modifier|*
name|clientData
decl_stmt|;
comment|/* Data associated with key. */
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
comment|/* Buckets in the table */
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
comment|/*  * The following structure is used by the searching routines  * to record where we are in the search.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Hash_Search
block|{
specifier|const
name|Hash_Table
modifier|*
name|tablePtr
decl_stmt|;
comment|/* Table being searched. */
name|int
name|nextIndex
decl_stmt|;
comment|/* Next bucket to check */
name|Hash_Entry
modifier|*
name|hashEntryPtr
decl_stmt|;
comment|/* Next entry in current bucket */
block|}
name|Hash_Search
typedef|;
end_typedef

begin_comment
comment|/*  * Macros.  */
end_comment

begin_comment
comment|/*  * void *Hash_GetValue(const Hash_Entry *h)  */
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
comment|/*  * Hash_SetValue(Hash_Entry *h, void *val);  */
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
value|((h)->clientData = (val))
end_define

begin_function_decl
name|void
name|Hash_InitTable
parameter_list|(
name|Hash_Table
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Hash_DeleteTable
parameter_list|(
name|Hash_Table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Hash_Entry
modifier|*
name|Hash_FindEntry
parameter_list|(
specifier|const
name|Hash_Table
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Hash_Entry
modifier|*
name|Hash_CreateEntry
parameter_list|(
name|Hash_Table
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|Boolean
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Hash_DeleteEntry
parameter_list|(
name|Hash_Table
modifier|*
parameter_list|,
name|Hash_Entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Hash_Entry
modifier|*
name|Hash_EnumFirst
parameter_list|(
specifier|const
name|Hash_Table
modifier|*
parameter_list|,
name|Hash_Search
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Hash_Entry
modifier|*
name|Hash_EnumNext
parameter_list|(
name|Hash_Search
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hash_h_f6312f46 */
end_comment

end_unit

