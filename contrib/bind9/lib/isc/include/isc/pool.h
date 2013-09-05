begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2013  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_OBJPOOL_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_OBJPOOL_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file isc/pool.h  * \brief An object pool is a mechanism for sharing a small pool of  * fungible objects among a large number of objects that depend on them.  *  * This is useful, for example, when it causes performance problems for  * large number of zones to share a single memory context or task object,  * but it would create a different set of problems for them each to have an  * independent task or memory context.  */
end_comment

begin_comment
comment|/***  *** Imports.  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/mem.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*****  ***** Types.  *****/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_pooldeallocator_t
function_decl|)
parameter_list|(
name|void
modifier|*
modifier|*
name|object
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|isc_poolinitializer_t
function_decl|)
parameter_list|(
name|void
modifier|*
modifier|*
name|target
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_pool
name|isc_pool_t
typedef|;
end_typedef

begin_comment
comment|/*****  ***** Functions.  *****/
end_comment

begin_function_decl
name|isc_result_t
name|isc_pool_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|,
name|isc_pooldeallocator_t
name|free
parameter_list|,
name|isc_poolinitializer_t
name|init
parameter_list|,
name|void
modifier|*
name|initarg
parameter_list|,
name|isc_pool_t
modifier|*
modifier|*
name|poolp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a pool of "count" object pointers. If 'free' is not NULL,  * it points to a function that will detach the objects.  'init'  * points to a function that will initialize the arguments, and  * 'arg' to an argument to be passed into that function (for example,  * a relevant manager or context object).  *  * Requires:  *  *\li	'mctx' is a valid memory context.  *  *\li	init != NULL  *  *\li	poolp != NULL&& *poolp == NULL  *  * Ensures:  *  *\li	On success, '*poolp' points to the new object pool.  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|void
modifier|*
name|isc_pool_get
parameter_list|(
name|isc_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns a pointer to an object from the pool. Currently the object  * is chosen from the pool at random.  (This may be changed in the future  * to something that guaratees balance.)  */
end_comment

begin_function_decl
name|int
name|isc_pool_count
parameter_list|(
name|isc_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns the number of objcts in the pool 'pool'.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_pool_expand
parameter_list|(
name|isc_pool_t
modifier|*
modifier|*
name|sourcep
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|,
name|isc_pool_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * If 'size' is larger than the number of objects in the pool pointed to by  * 'sourcep', then a new pool of size 'count' is allocated, the existing  * objects are copied into it, additional ones created to bring the  * total number up to 'count', and the resulting pool is attached to  * 'targetp'.  *  * If 'count' is less than or equal to the number of objects in 'source', then  * 'sourcep' is attached to 'targetp' without any other action being taken.  *  * In either case, 'sourcep' is detached.  *  * Requires:  *  * \li	'sourcep' is not NULL and '*source' is not NULL  * \li	'targetp' is not NULL and '*source' is NULL  *  * Ensures:  *  * \li	On success, '*targetp' points to a valid task pool.  * \li	On success, '*sourcep' points to NULL.  *  * Returns:  *  * \li	#ISC_R_SUCCESS  * \li	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|void
name|isc_pool_destroy
parameter_list|(
name|isc_pool_t
modifier|*
modifier|*
name|poolp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy a task pool.  The tasks in the pool are detached but not  * shut down.  *  * Requires:  * \li	'*poolp' is a valid task pool.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_OBJPOOL_H */
end_comment

end_unit

