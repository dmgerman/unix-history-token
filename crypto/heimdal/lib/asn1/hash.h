begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/*  * hash.h. Header file for hash table functions  */
end_comment

begin_comment
comment|/* $Id: hash.h,v 1.3 1999/12/02 17:05:02 joda Exp $ */
end_comment

begin_struct
struct|struct
name|hashentry
block|{
comment|/* Entry in bucket */
name|struct
name|hashentry
modifier|*
modifier|*
name|prev
decl_stmt|;
name|struct
name|hashentry
modifier|*
name|next
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hashentry
name|Hashentry
typedef|;
end_typedef

begin_struct
struct|struct
name|hashtab
block|{
comment|/* Hash table */
name|int
function_decl|(
modifier|*
name|cmp
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* Compare function */
name|unsigned
function_decl|(
modifier|*
name|hash
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* hash function */
name|int
name|sz
decl_stmt|;
comment|/* Size */
name|Hashentry
modifier|*
name|tab
index|[
literal|1
index|]
decl_stmt|;
comment|/* The table */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hashtab
name|Hashtab
typedef|;
end_typedef

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|Hashtab
modifier|*
name|hashtabnew
parameter_list|(
name|int
name|sz
parameter_list|,
name|int
function_decl|(
modifier|*
name|cmp
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|unsigned
function_decl|(
modifier|*
name|hash
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Make new hash table */
end_comment

begin_function_decl
name|void
modifier|*
name|hashtabsearch
parameter_list|(
name|Hashtab
modifier|*
name|htab
parameter_list|,
comment|/* The hash table */
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  The key */
end_comment

begin_function_decl
name|void
modifier|*
name|hashtabadd
parameter_list|(
name|Hashtab
modifier|*
name|htab
parameter_list|,
comment|/* The hash table */
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The element */
end_comment

begin_function_decl
name|int
name|_hashtabdel
parameter_list|(
name|Hashtab
modifier|*
name|htab
parameter_list|,
comment|/* The table */
name|void
modifier|*
name|ptr
parameter_list|,
comment|/* Key */
name|int
name|freep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free data part? */
end_comment

begin_function_decl
name|void
name|hashtabforeach
parameter_list|(
name|Hashtab
modifier|*
name|htab
parameter_list|,
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|hashadd
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Standard hash function */
end_comment

begin_function_decl
name|unsigned
name|hashcaseadd
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Standard hash function */
end_comment

begin_function_decl
name|unsigned
name|hashjpw
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* another hash function */
end_comment

begin_comment
comment|/* macros */
end_comment

begin_comment
comment|/* Don't free space */
end_comment

begin_define
define|#
directive|define
name|hashtabdel
parameter_list|(
name|htab
parameter_list|,
name|key
parameter_list|)
value|_hashtabdel(htab,key,FALSE)
end_define

begin_define
define|#
directive|define
name|hashtabfree
parameter_list|(
name|htab
parameter_list|,
name|key
parameter_list|)
value|_hashtabdel(htab,key,TRUE)
end_define

begin_comment
comment|/* Do! */
end_comment

end_unit

