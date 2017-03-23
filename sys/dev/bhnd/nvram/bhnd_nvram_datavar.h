begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_DATAVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_DATAVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<sys/refcount.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_io.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_nvram_data.h"
end_include

begin_comment
comment|/** Registered NVRAM parser class instances. */
end_comment

begin_expr_stmt
name|SET_DECLARE
argument_list|(
name|bhnd_nvram_data_class_set
argument_list|,
name|bhnd_nvram_data_class
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
modifier|*
name|bhnd_nvram_data_generic_find
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_data_generic_rp_getvar
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
name|cookiep
parameter_list|,
name|void
modifier|*
name|outp
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|,
name|bhnd_nvram_type
name|otype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_data_generic_rp_copy_val
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
name|cookiep
parameter_list|,
name|bhnd_nvram_val
modifier|*
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @see bhnd_nvram_data_probe() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_data_op_probe
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_probe() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_data_op_getvar_direct
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|outp
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|,
name|bhnd_nvram_type
name|otype
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_serialize() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_data_op_serialize
function_decl|)
parameter_list|(
name|bhnd_nvram_data_class
modifier|*
name|cls
parameter_list|,
name|bhnd_nvram_plist
modifier|*
name|props
parameter_list|,
name|bhnd_nvram_plist
modifier|*
name|options
parameter_list|,
name|void
modifier|*
name|outp
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_new() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_data_op_new
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|struct
name|bhnd_nvram_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** Free all resources associated with @p nv. Called by  *  bhnd_nvram_data_release() when the reference count reaches zero. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|bhnd_nvram_data_op_free
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_count() */
end_comment

begin_typedef
typedef|typedef
name|size_t
function_decl|(
name|bhnd_nvram_data_op_count
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_options() */
end_comment

begin_typedef
typedef|typedef
name|bhnd_nvram_plist
modifier|*
function_decl|(
name|bhnd_nvram_data_op_options
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_caps() */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
function_decl|(
name|bhnd_nvram_data_op_caps
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_next() */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
name|bhnd_nvram_data_op_next
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_find() */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
name|bhnd_nvram_data_op_find
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_copy_val() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_data_op_copy_val
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
name|cookiep
parameter_list|,
name|bhnd_nvram_val
modifier|*
modifier|*
name|value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_getvar_order() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_data_op_getvar_order
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
name|cookiep1
parameter_list|,
name|void
modifier|*
name|cookiep2
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_getvar_name() */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
name|bhnd_nvram_data_op_getvar_name
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_getvar() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_data_op_getvar
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
name|cookiep
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|,
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_getvar_ptr() */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
function_decl|(
name|bhnd_nvram_data_op_getvar_ptr
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
name|void
modifier|*
name|cookiep
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|,
name|bhnd_nvram_type
modifier|*
name|type
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_filter_setvar() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_data_op_filter_setvar
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bhnd_nvram_val
modifier|*
name|value
parameter_list|,
name|bhnd_nvram_val
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** @see bhnd_nvram_data_filter_unsetvar() */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|bhnd_nvram_data_op_filter_unsetvar
function_decl|)
parameter_list|(
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * NVRAM data class.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_data_class
block|{
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/**< description */
name|uint32_t
name|caps
decl_stmt|;
comment|/**< capabilities (BHND_NVRAM_DATA_CAP_*) */
name|size_t
name|size
decl_stmt|;
comment|/**< instance size */
name|bhnd_nvram_data_op_probe
modifier|*
name|op_probe
decl_stmt|;
name|bhnd_nvram_data_op_getvar_direct
modifier|*
name|op_getvar_direct
decl_stmt|;
name|bhnd_nvram_data_op_serialize
modifier|*
name|op_serialize
decl_stmt|;
name|bhnd_nvram_data_op_new
modifier|*
name|op_new
decl_stmt|;
name|bhnd_nvram_data_op_free
modifier|*
name|op_free
decl_stmt|;
name|bhnd_nvram_data_op_count
modifier|*
name|op_count
decl_stmt|;
name|bhnd_nvram_data_op_options
modifier|*
name|op_options
decl_stmt|;
name|bhnd_nvram_data_op_caps
modifier|*
name|op_caps
decl_stmt|;
name|bhnd_nvram_data_op_next
modifier|*
name|op_next
decl_stmt|;
name|bhnd_nvram_data_op_find
modifier|*
name|op_find
decl_stmt|;
name|bhnd_nvram_data_op_copy_val
modifier|*
name|op_copy_val
decl_stmt|;
name|bhnd_nvram_data_op_getvar_order
modifier|*
name|op_getvar_order
decl_stmt|;
name|bhnd_nvram_data_op_getvar
modifier|*
name|op_getvar
decl_stmt|;
name|bhnd_nvram_data_op_getvar_ptr
modifier|*
name|op_getvar_ptr
decl_stmt|;
name|bhnd_nvram_data_op_getvar_name
modifier|*
name|op_getvar_name
decl_stmt|;
name|bhnd_nvram_data_op_filter_setvar
modifier|*
name|op_filter_setvar
decl_stmt|;
name|bhnd_nvram_data_op_filter_unsetvar
modifier|*
name|op_filter_unsetvar
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * NVRAM data instance.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_data
block|{
name|struct
name|bhnd_nvram_data_class
modifier|*
name|cls
decl_stmt|;
specifier|volatile
name|u_int
name|refs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Helper macro for BHND_NVRAM_DATA_CLASS_DEFN().  *  * Declares a bhnd_nvram_data_class method implementation with class name  * _cname and method name _mname  */
end_comment

begin_define
define|#
directive|define
name|BHND_NVRAM_DATA_CLASS_DECL_METHOD
parameter_list|(
name|_cname
parameter_list|,
name|_mname
parameter_list|)
define|\
value|static bhnd_nvram_data_op_ ## _mname				\ 	    bhnd_nvram_ ## _cname ## _ ## _mname;
end_define

begin_comment
unit|\
comment|/*  * Helper macro for BHND_NVRAM_DATA_CLASS_DEFN().  *  * Assign a bhnd_nvram_data_class method implementation with class name  * @p _cname and method name @p _mname  */
end_comment

begin_define
define|#
directive|define
name|BHND_NVRAM_DATA_CLASS_ASSIGN_METHOD
parameter_list|(
name|_cname
parameter_list|,
name|_mname
parameter_list|)
define|\
value|.op_ ## _mname = bhnd_nvram_ ## _cname ## _ ## _mname,
end_define

begin_comment
comment|/*  * Helper macro for BHND_NVRAM_DATA_CLASS_DEFN().  *  * Iterate over all bhnd_nvram_data_class method names, calling  * _macro with the class name _cname as the first argument, and  * a bhnd_nvram_data_class method name as the second.  */
end_comment

begin_define
define|#
directive|define
name|BHND_NVRAM_DATA_CLASS_ITER_METHODS
parameter_list|(
name|_cname
parameter_list|,
name|_macro
parameter_list|)
define|\
value|_macro(_cname, probe)					\ 	_macro(_cname, getvar_direct)				\ 	_macro(_cname, serialize)				\ 	_macro(_cname, new)					\ 	_macro(_cname, free)					\ 	_macro(_cname, count)					\ 	_macro(_cname, options)					\ 	_macro(_cname, caps)					\ 	_macro(_cname, next)					\ 	_macro(_cname, find)					\ 	_macro(_cname, copy_val)				\ 	_macro(_cname, getvar_order)				\ 	_macro(_cname, getvar)					\ 	_macro(_cname, getvar_ptr)				\ 	_macro(_cname, getvar_name)				\ 	_macro(_cname, filter_setvar)				\ 	_macro(_cname, filter_unsetvar)
end_define

begin_comment
comment|/**  * Define a bhnd_nvram_data_class with class name @p _n and description  * @p _desc, and register with bhnd_nvram_data_class_set.  */
end_comment

begin_define
define|#
directive|define
name|BHND_NVRAM_DATA_CLASS_DEFN
parameter_list|(
name|_cname
parameter_list|,
name|_desc
parameter_list|,
name|_caps
parameter_list|,
name|_size
parameter_list|)
define|\
value|BHND_NVRAM_DATA_CLASS_ITER_METHODS(_cname,			\ 	    BHND_NVRAM_DATA_CLASS_DECL_METHOD)				\ 									\ 	struct bhnd_nvram_data_class bhnd_nvram_## _cname ## _class = {	\ 		.desc		= (_desc),				\ 		.caps		= (_caps),				\ 		.size		= (_size),				\ 		BHND_NVRAM_DATA_CLASS_ITER_METHODS(_cname,		\ 		    BHND_NVRAM_DATA_CLASS_ASSIGN_METHOD)		\ 	};								\ 									\ 	DATA_SET(bhnd_nvram_data_class_set,				\ 	    bhnd_nvram_## _cname ## _class);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_DATAVAR_H_ */
end_comment

end_unit

