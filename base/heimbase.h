begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Portions Copyright (c) 2010 Apple Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIM_BASE_H
end_ifndef

begin_define
define|#
directive|define
name|HEIM_BASE_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

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

begin_typedef
typedef|typedef
name|void
modifier|*
name|heim_object_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|heim_tid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|heim_object_t
name|heim_bool_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|heim_object_t
name|heim_null_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HEIM_BASE_ONCE_INIT
value|0
end_define

begin_typedef
typedef|typedef
name|long
name|heim_base_once_t
typedef|;
end_typedef

begin_comment
comment|/* XXX arch dependant */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__has_extension
argument_list|)
end_if

begin_define
define|#
directive|define
name|__has_extension
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HEIM_REQUIRE_GNUC
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|(((__GNUC__ * 10000) + (__GNUC_MINOR__ * 100) + __GNUC_PATCHLEVEL__)>= \      (((m) * 10000) + ((n) * 100) + (p)))
end_define

begin_if
if|#
directive|if
name|__has_extension
argument_list|(
name|__builtin_expect
argument_list|)
operator|||
name|HEIM_REQUIRE_GNUC
argument_list|(
literal|3
operator|,
literal|0
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|heim_builtin_expect
parameter_list|(
name|_op
parameter_list|,
name|_res
parameter_list|)
value|__builtin_expect(_op,_res)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|heim_builtin_expect
parameter_list|(
name|_op
parameter_list|,
name|_res
parameter_list|)
value|(_op)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
modifier|*
name|heim_retain
parameter_list|(
name|heim_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heim_release
parameter_list|(
name|heim_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|heim_type_dealloc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
modifier|*
name|heim_alloc
parameter_list|(
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|heim_type_dealloc
name|dealloc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|heim_tid_t
name|heim_get_tid
parameter_list|(
name|heim_object_t
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heim_cmp
parameter_list|(
name|heim_object_t
name|a
parameter_list|,
name|heim_object_t
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|heim_get_hash
parameter_list|(
name|heim_object_t
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heim_base_once_f
parameter_list|(
name|heim_base_once_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|heim_abort
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|HEIMDAL_NORETURN_ATTRIBUTE
name|HEIMDAL_PRINTF_ATTRIBUTE
argument_list|(
operator|(
name|printf
operator|,
literal|1
operator|,
literal|2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|heim_abortv
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
name|va_list
name|ap
argument_list|)
name|HEIMDAL_NORETURN_ATTRIBUTE
name|HEIMDAL_PRINTF_ATTRIBUTE
argument_list|(
operator|(
name|printf
operator|,
literal|1
operator|,
literal|0
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|heim_assert
parameter_list|(
name|e
parameter_list|,
name|t
parameter_list|)
define|\
value|(heim_builtin_expect(!(e), 0) ? heim_abort(t ":" #e) : (void)0)
end_define

begin_comment
comment|/*  *  */
end_comment

begin_function_decl
name|heim_null_t
name|heim_null_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|heim_bool_t
name|heim_bool_create
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heim_bool_val
parameter_list|(
name|heim_bool_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Array  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|heim_array_data
modifier|*
name|heim_array_t
typedef|;
end_typedef

begin_function_decl
name|heim_array_t
name|heim_array_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|heim_tid_t
name|heim_array_get_type_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|heim_array_iterator_f_t
function_decl|)
parameter_list|(
name|heim_object_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|heim_array_append_value
parameter_list|(
name|heim_array_t
parameter_list|,
name|heim_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heim_array_iterate_f
parameter_list|(
name|heim_array_t
parameter_list|,
name|heim_array_iterator_f_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__BLOCKS__
end_ifdef

begin_function_decl
name|void
name|heim_array_iterate
parameter_list|(
name|heim_array_t
parameter_list|,
name|void
function_decl|(
modifier|^
function_decl|)
parameter_list|(
name|heim_object_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|size_t
name|heim_array_get_length
parameter_list|(
name|heim_array_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|heim_object_t
name|heim_array_copy_value
parameter_list|(
name|heim_array_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heim_array_delete_value
parameter_list|(
name|heim_array_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__BLOCKS__
end_ifdef

begin_function_decl
name|void
name|heim_array_filter
parameter_list|(
name|heim_array_t
parameter_list|,
name|int
function_decl|(
modifier|^
function_decl|)
parameter_list|(
name|heim_object_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Dict  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|heim_dict_data
modifier|*
name|heim_dict_t
typedef|;
end_typedef

begin_function_decl
name|heim_dict_t
name|heim_dict_create
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|heim_tid_t
name|heim_dict_get_type_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|heim_dict_iterator_f_t
function_decl|)
parameter_list|(
name|heim_object_t
parameter_list|,
name|heim_object_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|heim_dict_add_value
parameter_list|(
name|heim_dict_t
parameter_list|,
name|heim_object_t
parameter_list|,
name|heim_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heim_dict_iterate_f
parameter_list|(
name|heim_dict_t
parameter_list|,
name|heim_dict_iterator_f_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__BLOCKS__
end_ifdef

begin_function_decl
name|void
name|heim_dict_iterate
parameter_list|(
name|heim_dict_t
parameter_list|,
name|void
function_decl|(
modifier|^
function_decl|)
parameter_list|(
name|heim_object_t
parameter_list|,
name|heim_object_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|heim_object_t
name|heim_dict_copy_value
parameter_list|(
name|heim_dict_t
parameter_list|,
name|heim_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heim_dict_delete_key
parameter_list|(
name|heim_dict_t
parameter_list|,
name|heim_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * String  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|heim_string_data
modifier|*
name|heim_string_t
typedef|;
end_typedef

begin_function_decl
name|heim_string_t
name|heim_string_create
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|heim_tid_t
name|heim_string_get_type_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|heim_string_get_utf8
parameter_list|(
name|heim_string_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Number  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|heim_number_data
modifier|*
name|heim_number_t
typedef|;
end_typedef

begin_function_decl
name|heim_number_t
name|heim_number_create
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|heim_tid_t
name|heim_number_get_type_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heim_number_get_int
parameter_list|(
name|heim_number_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|heim_auto_release
modifier|*
name|heim_auto_release_t
typedef|;
end_typedef

begin_function_decl
name|heim_auto_release_t
name|heim_auto_release_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heim_auto_release_drain
parameter_list|(
name|heim_auto_release_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heim_auto_release
parameter_list|(
name|heim_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIM_BASE_H */
end_comment

end_unit

