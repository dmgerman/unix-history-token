begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KOBJ_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KOBJ_H_
end_define

begin_comment
comment|/*  * Forward declarations  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|kobj
modifier|*
name|kobj_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|kobj_class
modifier|*
name|kobj_class_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|kobj_method
name|kobj_method_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|kobjop_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|kobj_ops
modifier|*
name|kobj_ops_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|kobjop_desc
modifier|*
name|kobjop_desc_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|malloc_type
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|kobj_method
block|{
name|kobjop_desc_t
name|desc
decl_stmt|;
name|kobjop_t
name|func
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A class is simply a method table and a sizeof value. When the first  * instance of the class is created, the method table will be compiled  * into a form more suited to efficient method dispatch. This compiled  * method table is always the first field of the object.  */
end_comment

begin_define
define|#
directive|define
name|KOBJ_CLASS_FIELDS
define|\
value|const char	*name;
comment|/* class name */
value|\ 	kobj_method_t	*methods;
comment|/* method table */
value|\ 	size_t		size;
comment|/* object size */
value|\ 	u_int		refs;
comment|/* reference count */
value|\ 	kobj_ops_t	ops
end_define

begin_comment
comment|/* compiled method table */
end_comment

begin_struct
struct|struct
name|kobj_class
block|{
name|KOBJ_CLASS_FIELDS
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Implementation of kobj.  */
end_comment

begin_define
define|#
directive|define
name|KOBJ_FIELDS
define|\
value|kobj_ops_t	ops
end_define

begin_struct
struct|struct
name|kobj
block|{
name|KOBJ_FIELDS
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The ops table is used as a cache of results from kobj_lookup_method().  */
end_comment

begin_define
define|#
directive|define
name|KOBJ_CACHE_SIZE
value|256
end_define

begin_struct
struct|struct
name|kobj_ops
block|{
name|kobj_method_t
name|cache
index|[
name|KOBJ_CACHE_SIZE
index|]
decl_stmt|;
name|kobj_class_t
name|cls
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|kobjop_desc
block|{
name|unsigned
name|int
name|id
decl_stmt|;
comment|/* unique ID */
name|kobjop_t
name|deflt
decl_stmt|;
comment|/* default implementation */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Shorthand for constructing method tables.  */
end_comment

begin_define
define|#
directive|define
name|KOBJMETHOD
parameter_list|(
name|NAME
parameter_list|,
name|FUNC
parameter_list|)
value|{&NAME##_desc, (kobjop_t) FUNC }
end_define

begin_define
define|#
directive|define
name|DEFINE_CLASS
parameter_list|(
name|name
parameter_list|,
name|methods
parameter_list|,
name|size
parameter_list|)
define|\ 						\
value|struct kobj_class name ## _class = {		\ 	#name, methods, size			\ }
end_define

begin_comment
comment|/*  * Compile the method table in a class.  */
end_comment

begin_function_decl
name|void
name|kobj_class_compile
parameter_list|(
name|kobj_class_t
name|cls
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Compile the method table, with the caller providing the space for  * the ops table.(for use before malloc is initialised).  */
end_comment

begin_function_decl
name|void
name|kobj_class_compile_static
parameter_list|(
name|kobj_class_t
name|cls
parameter_list|,
name|kobj_ops_t
name|ops
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free the compiled method table in a class.  */
end_comment

begin_function_decl
name|void
name|kobj_class_free
parameter_list|(
name|kobj_class_t
name|cls
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate memory for and initalise a new object.  */
end_comment

begin_function_decl
name|kobj_t
name|kobj_create
parameter_list|(
name|kobj_class_t
name|cls
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|mtype
parameter_list|,
name|int
name|mflags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialise a pre-allocated object.  */
end_comment

begin_function_decl
name|void
name|kobj_init
parameter_list|(
name|kobj_t
name|obj
parameter_list|,
name|kobj_class_t
name|cls
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Delete an object. If mtype is non-zero, free the memory.  */
end_comment

begin_function_decl
name|void
name|kobj_delete
parameter_list|(
name|kobj_t
name|obj
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|mtype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Maintain stats on hits/misses in lookup caches.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KOBJ_STATS
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|kobj_lookup_hits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|kobj_lookup_misses
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|KOBJOPHIT
value|do { kobj_lookup_hits++; } while (0)
end_define

begin_define
define|#
directive|define
name|KOBJOPMISS
value|do { kobj_lookup_misses++; } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KOBJOPHIT
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|KOBJOPMISS
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Lookup the method in the cache and if it isn't there look it up the  * slow way.  */
end_comment

begin_define
define|#
directive|define
name|KOBJOPLOOKUP
parameter_list|(
name|OPS
parameter_list|,
name|OP
parameter_list|)
value|do {					\ 	kobjop_desc_t _desc =&OP##_##desc;				\ 	kobj_method_t *_ce =						\&OPS->cache[_desc->id& (KOBJ_CACHE_SIZE-1)];		\ 	if (_ce->desc != _desc) {					\ 		KOBJOPMISS;						\ 		kobj_lookup_method(OPS->cls->methods, _ce, _desc);	\ 	} else {							\ 		KOBJOPHIT;						\ 	}								\ 	_m = _ce->func;							\ } while(0)
end_define

begin_function_decl
name|void
name|kobj_lookup_method
parameter_list|(
name|kobj_method_t
modifier|*
name|methods
parameter_list|,
name|kobj_method_t
modifier|*
name|ce
parameter_list|,
name|kobjop_desc_t
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_KOBJ_H_ */
end_comment

end_unit

