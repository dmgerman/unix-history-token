begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ATF_C_DETAIL_MAP_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATF_C_DETAIL_MAP_H
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<atf-c/detail/list.h>
end_include

begin_include
include|#
directive|include
file|<atf-c/error_fwd.h>
end_include

begin_comment
comment|/* ---------------------------------------------------------------------  * The "atf_map_citer" type.  * --------------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|atf_map_citer
block|{
specifier|const
name|struct
name|atf_map
modifier|*
name|m_map
decl_stmt|;
specifier|const
name|void
modifier|*
name|m_entry
decl_stmt|;
name|atf_list_citer_t
name|m_listiter
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atf_map_citer
name|atf_map_citer_t
typedef|;
end_typedef

begin_comment
comment|/* Getters. */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|atf_map_citer_key
parameter_list|(
specifier|const
name|atf_map_citer_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|void
modifier|*
name|atf_map_citer_data
parameter_list|(
specifier|const
name|atf_map_citer_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_map_citer_t
name|atf_map_citer_next
parameter_list|(
specifier|const
name|atf_map_citer_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Operators. */
end_comment

begin_function_decl
name|bool
name|atf_equal_map_citer_map_citer
parameter_list|(
specifier|const
name|atf_map_citer_t
parameter_list|,
specifier|const
name|atf_map_citer_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ---------------------------------------------------------------------  * The "atf_map_iter" type.  * --------------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|atf_map_iter
block|{
name|struct
name|atf_map
modifier|*
name|m_map
decl_stmt|;
name|void
modifier|*
name|m_entry
decl_stmt|;
name|atf_list_iter_t
name|m_listiter
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atf_map_iter
name|atf_map_iter_t
typedef|;
end_typedef

begin_comment
comment|/* Getters. */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|atf_map_iter_key
parameter_list|(
specifier|const
name|atf_map_iter_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|atf_map_iter_data
parameter_list|(
specifier|const
name|atf_map_iter_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_map_iter_t
name|atf_map_iter_next
parameter_list|(
specifier|const
name|atf_map_iter_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Operators. */
end_comment

begin_function_decl
name|bool
name|atf_equal_map_iter_map_iter
parameter_list|(
specifier|const
name|atf_map_iter_t
parameter_list|,
specifier|const
name|atf_map_iter_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ---------------------------------------------------------------------  * The "atf_map" type.  * --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* A list-based map.  Typically very inefficient, but our maps are small  * enough. */
end_comment

begin_struct
struct|struct
name|atf_map
block|{
name|atf_list_t
name|m_list
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atf_map
name|atf_map_t
typedef|;
end_typedef

begin_comment
comment|/* Constructors and destructors */
end_comment

begin_function_decl
name|atf_error_t
name|atf_map_init
parameter_list|(
name|atf_map_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_map_init_charpp
parameter_list|(
name|atf_map_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atf_map_fini
parameter_list|(
name|atf_map_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Getters. */
end_comment

begin_function_decl
name|atf_map_iter_t
name|atf_map_begin
parameter_list|(
name|atf_map_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_map_citer_t
name|atf_map_begin_c
parameter_list|(
specifier|const
name|atf_map_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_map_iter_t
name|atf_map_end
parameter_list|(
name|atf_map_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_map_citer_t
name|atf_map_end_c
parameter_list|(
specifier|const
name|atf_map_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_map_iter_t
name|atf_map_find
parameter_list|(
name|atf_map_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_map_citer_t
name|atf_map_find_c
parameter_list|(
specifier|const
name|atf_map_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|atf_map_size
parameter_list|(
specifier|const
name|atf_map_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|atf_map_to_charpp
parameter_list|(
specifier|const
name|atf_map_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Modifiers. */
end_comment

begin_function_decl
name|atf_error_t
name|atf_map_insert
parameter_list|(
name|atf_map_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Macros. */
end_comment

begin_define
define|#
directive|define
name|atf_map_for_each
parameter_list|(
name|iter
parameter_list|,
name|map
parameter_list|)
define|\
value|for (iter = atf_map_begin(map); \          !atf_equal_map_iter_map_iter((iter), atf_map_end(map)); \          iter = atf_map_iter_next(iter))
end_define

begin_define
define|#
directive|define
name|atf_map_for_each_c
parameter_list|(
name|iter
parameter_list|,
name|map
parameter_list|)
define|\
value|for (iter = atf_map_begin_c(map); \          !atf_equal_map_citer_map_citer((iter), atf_map_end_c(map)); \          iter = atf_map_citer_next(iter))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(ATF_C_DETAIL_MAP_H) */
end_comment

end_unit

