begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1985, 1991 Peter J. Nicklin.  * Copyright (c) 1991 Version Technology.  * All Rights Reserved.  *  * $License: VT.1.1 $  * Redistribution and use in source and binary forms,  with or without  * modification,  are permitted provided that the following conditions  * are met:  (1) Redistributions of source code must retain the  above  * copyright  notice,  this  list  of  conditions  and  the  following  * disclaimer.  (2) Redistributions in binary form must reproduce  the  * above  copyright notice,  this list of conditions and the following  * disclaimer in the  documentation  and/or other  materials  provided  * with  the  distribution.  (3) All advertising materials  mentioning  * features or  use  of  this  software  must  display  the  following  * acknowledgement:  ``This  product  includes  software  developed by  * Version Technology.''  Neither the name of Version  Technology  nor  * the  name  of  Peter J. Nicklin  may  be used to endorse or promote  * products derived from this software without specific prior  written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY  * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE  * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE  * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,  * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Report problems and direct questions to nicklin@netcom.com  *  * $Header: hash.h,v 4.3 91/11/25 19:45:47 nicklin Exp $  *  * Hash table definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Singly-linked list block containing a pointer to a hash table  * block for an include file  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_iblk
block|{
name|int
name|i_loop
decl_stmt|;
name|struct
name|_hblk
modifier|*
name|i_hblk
decl_stmt|;
name|struct
name|_iblk
modifier|*
name|i_next
decl_stmt|;
block|}
name|INCBLK
typedef|;
end_typedef

begin_comment
comment|/*  * Hash table block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_hblk
block|{
name|char
modifier|*
name|h_key
decl_stmt|;
comment|/* points to key */
name|char
modifier|*
name|h_def
decl_stmt|;
comment|/* points to definition string */
name|int
name|h_val
decl_stmt|;
comment|/* integer value */
name|struct
name|_iblk
modifier|*
name|h_sub
decl_stmt|;
comment|/* ptr to include subchain */
name|struct
name|_hblk
modifier|*
name|h_tag
decl_stmt|;
comment|/* ptr to auxiliary tag chain */
name|struct
name|_hblk
modifier|*
name|h_next
decl_stmt|;
comment|/* ptr to next block */
block|}
name|HASHBLK
typedef|;
end_typedef

begin_comment
comment|/*  * Hash pointer table struct  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_hash
block|{
name|HASHBLK
modifier|*
modifier|*
name|hashtab
decl_stmt|;
comment|/* hash pointer table */
name|HASHBLK
modifier|*
name|thisblk
decl_stmt|;
comment|/* current hash table block */
name|int
name|headblk
decl_stmt|;
comment|/* index of head of block chain */
name|int
name|hashsiz
decl_stmt|;
comment|/* hash table size */
name|int
name|nk
decl_stmt|;
comment|/* number of keys in table */
block|}
name|HASH
typedef|;
end_typedef

begin_comment
comment|/*  * Functions defined for hash tables  */
end_comment

begin_define
define|#
directive|define
name|htnum
parameter_list|(
name|ht
parameter_list|)
value|((ht)->nk)
end_define

begin_comment
comment|/* return number of keys in table */
end_comment

begin_define
define|#
directive|define
name|htkey
parameter_list|(
name|ht
parameter_list|)
value|((ht)->thisblk->h_key)
end_define

begin_comment
comment|/* return key from current block */
end_comment

begin_define
define|#
directive|define
name|htdef
parameter_list|(
name|ht
parameter_list|)
value|((ht)->thisblk->h_def)
end_define

begin_comment
comment|/* return definition from current block */
end_comment

begin_define
define|#
directive|define
name|htval
parameter_list|(
name|ht
parameter_list|)
value|((ht)->thisblk->h_val)
end_define

begin_comment
comment|/* return value from current block */
end_comment

begin_function_decl
specifier|extern
name|HASHBLK
modifier|*
name|htbrm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove hash table block */
end_comment

begin_function_decl
specifier|extern
name|int
name|hthash
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* compute hash value */
end_comment

begin_function_decl
specifier|extern
name|int
name|htnext
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* set hash table ptr to next block */
end_comment

begin_function_decl
specifier|extern
name|HASH
modifier|*
name|htinit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize hash table */
end_comment

begin_function_decl
specifier|extern
name|HASHBLK
modifier|*
name|htinstall
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* install hash table entry */
end_comment

begin_function_decl
specifier|extern
name|HASHBLK
modifier|*
name|htlookup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find hash table entry */
end_comment

begin_function_decl
specifier|extern
name|void
name|htrewind
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* rewind hash table to first block */
end_comment

begin_function_decl
specifier|extern
name|void
name|htrm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove hash table entry */
end_comment

end_unit

