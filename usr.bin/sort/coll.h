begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 2009 Gabor Kovesdan<gabor@FreeBSD.org>  * Copyright (C) 2012 Oleg Moskalenko<mom040267@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__COLL_H__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__COLL_H__
end_define

begin_include
include|#
directive|include
file|"bwstring.h"
end_include

begin_include
include|#
directive|include
file|"sort.h"
end_include

begin_comment
comment|/*  * Sort hint data for -n  */
end_comment

begin_struct
struct|struct
name|n_hint
block|{
name|unsigned
name|long
name|long
name|n1
decl_stmt|;
name|unsigned
name|char
name|si
decl_stmt|;
name|bool
name|empty
decl_stmt|;
name|bool
name|neg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Sort hint data for -g  */
end_comment

begin_struct
struct|struct
name|g_hint
block|{
name|double
name|d
decl_stmt|;
name|bool
name|nan
decl_stmt|;
name|bool
name|notnum
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Sort hint data for -M  */
end_comment

begin_struct
struct|struct
name|M_hint
block|{
name|int
name|m
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Status of a sort hint object  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HS_ERROR
init|=
operator|-
literal|1
block|,
name|HS_UNINITIALIZED
init|=
literal|0
block|,
name|HS_INITIALIZED
init|=
literal|1
block|}
name|hint_status
typedef|;
end_typedef

begin_comment
comment|/*  * Sort hint object  */
end_comment

begin_struct
struct|struct
name|key_hint
block|{
name|hint_status
name|status
decl_stmt|;
union|union
block|{
name|struct
name|n_hint
name|nh
decl_stmt|;
name|struct
name|g_hint
name|gh
decl_stmt|;
name|struct
name|M_hint
name|Mh
decl_stmt|;
block|}
name|v
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Key value  */
end_comment

begin_struct
struct|struct
name|key_value
block|{
name|struct
name|bwstring
modifier|*
name|k
decl_stmt|;
comment|/* key string */
name|struct
name|key_hint
name|hint
index|[
literal|0
index|]
decl_stmt|;
comment|/* key sort hint */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Set of keys container object.  */
end_comment

begin_struct
struct|struct
name|keys_array
block|{
name|struct
name|key_value
name|key
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parsed -k option data  */
end_comment

begin_struct
struct|struct
name|key_specs
block|{
name|struct
name|sort_mods
name|sm
decl_stmt|;
name|size_t
name|c1
decl_stmt|;
name|size_t
name|c2
decl_stmt|;
name|size_t
name|f1
decl_stmt|;
name|size_t
name|f2
decl_stmt|;
name|bool
name|pos1b
decl_stmt|;
name|bool
name|pos2b
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Single entry in sort list.  */
end_comment

begin_struct
struct|struct
name|sort_list_item
block|{
name|struct
name|bwstring
modifier|*
name|str
decl_stmt|;
name|struct
name|keys_array
name|ka
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Function type, used to compare two list objects  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|listcoll_t
function_decl|)
parameter_list|(
name|struct
name|sort_list_item
modifier|*
modifier|*
name|ss1
parameter_list|,
name|struct
name|sort_list_item
modifier|*
modifier|*
name|ss2
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|key_specs
modifier|*
name|keys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|keys_num
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Main localised symbols. These must be wint_t as they may hold WEOF.  */
end_comment

begin_decl_stmt
specifier|extern
name|wint_t
name|symbol_decimal_point
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|wint_t
name|symbol_thousands_sep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|wint_t
name|symbol_negative_sign
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|wint_t
name|symbol_positive_sign
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* funcs */
end_comment

begin_function_decl
name|cmpcoll_t
name|get_sort_func
parameter_list|(
name|struct
name|sort_mods
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|keys_array
modifier|*
name|keys_array_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|keys_array_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|key_value
modifier|*
name|get_key_from_keys_array
parameter_list|(
name|struct
name|keys_array
modifier|*
name|ka
parameter_list|,
name|size_t
name|ind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_key_on_keys_array
parameter_list|(
name|struct
name|keys_array
modifier|*
name|ka
parameter_list|,
name|struct
name|bwstring
modifier|*
name|s
parameter_list|,
name|size_t
name|ind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clean_keys_array
parameter_list|(
specifier|const
name|struct
name|bwstring
modifier|*
name|s
parameter_list|,
name|struct
name|keys_array
modifier|*
name|ka
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sort_list_item
modifier|*
name|sort_list_item_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sort_list_item_set
parameter_list|(
name|struct
name|sort_list_item
modifier|*
name|si
parameter_list|,
name|struct
name|bwstring
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sort_list_item_clean
parameter_list|(
name|struct
name|sort_list_item
modifier|*
name|si
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|sort_list_item_size
parameter_list|(
name|struct
name|sort_list_item
modifier|*
name|si
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|preproc
parameter_list|(
name|struct
name|bwstring
modifier|*
name|s
parameter_list|,
name|struct
name|keys_array
modifier|*
name|ka
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|top_level_str_coll
parameter_list|(
specifier|const
name|struct
name|bwstring
modifier|*
parameter_list|,
specifier|const
name|struct
name|bwstring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_coll
parameter_list|(
name|struct
name|keys_array
modifier|*
name|ks1
parameter_list|,
name|struct
name|keys_array
modifier|*
name|ks2
parameter_list|,
name|size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|str_list_coll
parameter_list|(
name|struct
name|bwstring
modifier|*
name|str1
parameter_list|,
name|struct
name|sort_list_item
modifier|*
modifier|*
name|ss2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|list_coll_by_str_only
parameter_list|(
name|struct
name|sort_list_item
modifier|*
modifier|*
name|ss1
parameter_list|,
name|struct
name|sort_list_item
modifier|*
modifier|*
name|ss2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|list_coll
parameter_list|(
name|struct
name|sort_list_item
modifier|*
modifier|*
name|ss1
parameter_list|,
name|struct
name|sort_list_item
modifier|*
modifier|*
name|ss2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|list_coll_offset
parameter_list|(
name|struct
name|sort_list_item
modifier|*
modifier|*
name|ss1
parameter_list|,
name|struct
name|sort_list_item
modifier|*
modifier|*
name|ss2
parameter_list|,
name|size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|listcoll_t
name|get_list_call_func
parameter_list|(
name|size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __COLL_H__ */
end_comment

end_unit

