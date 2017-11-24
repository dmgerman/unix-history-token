begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Declaration of the pool.  *	The pool manages a pool of objects.  *	The pool can grow to meet demand, limited only by system memory.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_POOL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_POOL_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_qcomppool.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_comment
comment|/****h* Component Library/Pool * NAME *	Pool * * DESCRIPTION *	The pool provides a self-contained and self-sustaining pool *	of user defined objects. * *	To aid in object oriented design, the pool provides the user *	the ability to specify callbacks that are invoked for each object for *	construction, initialization, and destruction. Constructor and destructor *	callback functions may not fail. * *	A pool does not return memory to the system as the user returns *	objects to the pool. The only method of returning memory to the system is *	to destroy the pool. * *	The Pool functions operate on a cl_pool_t structure which should be treated *	as opaque and should be manipulated only through the provided functions. * * SEE ALSO *	Structures: *		cl_pool_t * *	Callbacks: *		cl_pfn_pool_init_t, cl_pfn_pool_dtor_t * *	Initialization/Destruction: *		cl_pool_construct, cl_pool_init, cl_pool_destroy * *	Manipulation: *		cl_pool_get, cl_pool_put, cl_pool_grow * *	Attributes: *		cl_is_pool_inited, cl_pool_count *********/
end_comment

begin_comment
comment|/****d* Component Library: Pool/cl_pfn_pool_init_t * NAME *	cl_pfn_pool_init_t * * DESCRIPTION *	The cl_pfn_pool_init_t function type defines the prototype for *	functions used as initializers for objects being allocated by a *	pool. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|cl_status_t
function_decl|(
modifier|*
name|cl_pfn_pool_init_t
function_decl|)
parameter_list|(
name|IN
name|void
modifier|*
specifier|const
name|p_object
parameter_list|,
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	p_object *		[in] Pointer to an object to initialize. * *	context *		[in] Context provided in a call to cl_pool_init. * * RETURN VALUES *	Return CL_SUCCESS to indicates that initialization of the object *	was successful and initialization of further objects may continue. * *	Other cl_status_t values will be returned by cl_pool_init *	and cl_pool_grow. * * NOTES *	This function type is provided as function prototype reference for *	the function provided by the user as an optional parameter to the *	cl_pool_init function. * *	The initializer is invoked once per allocated object, allowing the user *	to trap initialization failures. Returning a status other than CL_SUCCESS *	aborts a grow operation, initiated either through cl_pool_init or *	cl_pool_grow, and causes the initiating function to fail. *	Any non-CL_SUCCESS status will be returned by the function that initiated *	the grow operation. * * SEE ALSO *	Pool, cl_pool_init, cl_pool_grow *********/
end_comment

begin_comment
comment|/****d* Component Library: Pool/cl_pfn_pool_dtor_t * NAME *	cl_pfn_pool_dtor_t * * DESCRIPTION *	The cl_pfn_pool_dtor_t function type defines the prototype for *	functions used as destructor for objects being deallocated by a *	pool. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cl_pfn_pool_dtor_t
function_decl|)
parameter_list|(
name|IN
name|void
modifier|*
specifier|const
name|p_object
parameter_list|,
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	p_object *		[in] Pointer to an object to destruct. * *	context *		[in] Context provided in the call to cl_pool_init. * * RETURN VALUE *	This function does not return a value. * * NOTES *	This function type is provided as function prototype reference for *	the function provided by the user as an optional parameter to the *	cl_pool_init function. * *	The destructor is invoked once per allocated object, allowing the user *	to perform any necessary cleanup. Users should not attempt to deallocate *	the memory for the object, as the pool manages object *	allocation and deallocation. * * SEE ALSO *	Pool, cl_pool_init *********/
end_comment

begin_comment
comment|/****s* Component Library: Pool/cl_pool_t * NAME *	cl_pool_t * * DESCRIPTION *	pool structure. * *	The cl_pool_t structure should be treated as opaque and should be *	manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_pool
block|{
name|cl_qcpool_t
name|qcpool
decl_stmt|;
name|cl_pfn_pool_init_t
name|pfn_init
decl_stmt|;
name|cl_pfn_pool_dtor_t
name|pfn_dtor
decl_stmt|;
specifier|const
name|void
modifier|*
name|context
decl_stmt|;
block|}
name|cl_pool_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	qcpool *		Quick composite pool that manages all objects. * *	pfn_init *		Pointer to the user's initializer callback, used by the pool *		to translate the quick composite pool's initializer callback to *		a pool initializer callback. * *	pfn_dtor *		Pointer to the user's destructor callback, used by the pool *		to translate the quick composite pool's destructor callback to *		a pool destructor callback. * *	context *		User's provided context for callback functions, used by the pool *		to when invoking callbacks. * * SEE ALSO *	Pool *********/
end_comment

begin_comment
comment|/****f* Component Library: Pool/cl_pool_construct * NAME *	cl_pool_construct * * DESCRIPTION *	The cl_pool_construct function constructs a pool. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_pool_construct
parameter_list|(
name|IN
name|cl_pool_t
modifier|*
specifier|const
name|p_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to a cl_pool_t structure whose state to initialize. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling cl_pool_init, cl_pool_destroy, and cl_is_pool_inited. * *	Calling cl_pool_construct is a prerequisite to calling any other *	pool function except cl_pool_init. * * SEE ALSO *	Pool, cl_pool_init, cl_pool_destroy, cl_is_pool_inited *********/
end_comment

begin_comment
comment|/****f* Component Library: Pool/cl_is_pool_inited * NAME *	cl_is_pool_inited * * DESCRIPTION *	The cl_is_pool_inited function returns whether a pool was successfully *	initialized. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|cl_is_pool_inited
parameter_list|(
name|IN
specifier|const
name|cl_pool_t
modifier|*
specifier|const
name|p_pool
parameter_list|)
block|{
comment|/* CL_ASSERT that a non-null pointer is provided. */
name|CL_ASSERT
argument_list|(
name|p_pool
argument_list|)
expr_stmt|;
return|return
operator|(
name|cl_is_qcpool_inited
argument_list|(
operator|&
name|p_pool
operator|->
name|qcpool
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to a cl_pool_t structure whose initialization state *		to check. * * RETURN VALUES *	TRUE if the pool was initialized successfully. * *	FALSE otherwise. * * NOTES *	Allows checking the state of a pool to determine if invoking member *	functions is appropriate. * * SEE ALSO *	Pool *********/
end_comment

begin_comment
comment|/****f* Component Library: Pool/cl_pool_init * NAME *	cl_pool_init * * DESCRIPTION *	The cl_pool_init function initializes a pool for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_pool_init
parameter_list|(
name|IN
name|cl_pool_t
modifier|*
specifier|const
name|p_pool
parameter_list|,
name|IN
specifier|const
name|size_t
name|min_count
parameter_list|,
name|IN
specifier|const
name|size_t
name|max_count
parameter_list|,
name|IN
specifier|const
name|size_t
name|grow_size
parameter_list|,
name|IN
specifier|const
name|size_t
name|object_size
parameter_list|,
name|IN
name|cl_pfn_pool_init_t
name|pfn_initializer
name|OPTIONAL
parameter_list|,
name|IN
name|cl_pfn_pool_dtor_t
name|pfn_destructor
name|OPTIONAL
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
specifier|const
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to a cl_pool_t structure to initialize. * *	min_count *		[in] Minimum number of objects that the pool should support. All *		necessary allocations to allow storing the minimum number of items *		are performed at initialization time, and all necessary callbacks *		invoked. * *	max_count *		[in] Maximum number of objects to which the pool is allowed to grow. *		A value of zero specifies no maximum. * *	grow_size *		[in] Number of objects to allocate when incrementally growing the pool. *		A value of zero disables automatic growth. * *	object_size *		[in] Size, in bytes, of each object. * *	pfn_initializer *		[in] Initialization callback to invoke for every new object when *		growing the pool. This parameter is optional and may be NULL. *		See the cl_pfn_pool_init_t function type declaration for details *		about the callback function. * *	pfn_destructor *		[in] Destructor callback to invoke for every object before memory for *		that object is freed. This parameter is optional and may be NULL. *		See the cl_pfn_pool_dtor_t function type declaration for details *		about the callback function. * *	context *		[in] Value to pass to the callback functions to provide context. * * RETURN VALUES *	CL_SUCCESS if the pool was initialized successfully. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory to initialize the *	pool. * *	CL_INVALID_SETTING if a the maximum size is non-zero and less than the *	minimum size. * *	Other cl_status_t value returned by optional initialization callback function *	specified by the pfn_initializer parameter. * * NOTES *	cl_pool_init initializes, and if necessary, grows the pool to *	the capacity desired. * * SEE ALSO *	Pool, cl_pool_construct, cl_pool_destroy, *	cl_pool_get, cl_pool_put, cl_pool_grow, *	cl_pool_count, cl_pfn_pool_init_t, cl_pfn_pool_dtor_t *********/
end_comment

begin_comment
comment|/****f* Component Library: Pool/cl_pool_destroy * NAME *	cl_pool_destroy * * DESCRIPTION *	The cl_pool_destroy function destroys a pool. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|cl_pool_destroy
parameter_list|(
name|IN
name|cl_pool_t
modifier|*
specifier|const
name|p_pool
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_pool
argument_list|)
expr_stmt|;
name|cl_qcpool_destroy
argument_list|(
operator|&
name|p_pool
operator|->
name|qcpool
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to a cl_pool_t structure to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	All memory allocated for objects is freed. The destructor callback, *	if any, will be invoked for every allocated object. Further operations *	on the pool should not be attempted after cl_pool_destroy *	is invoked. * *	This function should only be called after a call to *	cl_pool_construct or cl_pool_init. * *	In a debug build, cl_pool_destroy asserts that all objects are in *	the pool. * * SEE ALSO *	Pool, cl_pool_construct, cl_pool_init *********/
end_comment

begin_comment
comment|/****f* Component Library: Pool/cl_pool_count * NAME *	cl_pool_count * * DESCRIPTION *	The cl_pool_count function returns the number of available objects *	in a pool. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|size_t
name|cl_pool_count
parameter_list|(
name|IN
name|cl_pool_t
modifier|*
specifier|const
name|p_pool
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_pool
argument_list|)
expr_stmt|;
return|return
operator|(
name|cl_qcpool_count
argument_list|(
operator|&
name|p_pool
operator|->
name|qcpool
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to a cl_pool_t structure for which the number of *		available objects is requested. * * RETURN VALUE *	Returns the number of objects available in the specified pool. * * SEE ALSO *	Pool *********/
end_comment

begin_comment
comment|/****f* Component Library: Pool/cl_pool_get * NAME *	cl_pool_get * * DESCRIPTION *	The cl_pool_get function retrieves an object from a pool. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|cl_pool_get
parameter_list|(
name|IN
name|cl_pool_t
modifier|*
specifier|const
name|p_pool
parameter_list|)
block|{
name|cl_pool_obj_t
modifier|*
name|p_pool_obj
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_pool
argument_list|)
expr_stmt|;
name|p_pool_obj
operator|=
operator|(
name|cl_pool_obj_t
operator|*
operator|)
name|cl_qcpool_get
argument_list|(
operator|&
name|p_pool
operator|->
name|qcpool
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|p_pool_obj
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|CL_ASSERT
argument_list|(
name|p_pool_obj
operator|->
name|p_object
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|void
operator|*
operator|)
name|p_pool_obj
operator|->
name|p_object
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to a cl_pool_t structure from which to retrieve *		an object. * * RETURN VALUES *	Returns a pointer to an object. * *	Returns NULL if the pool is empty and can not be grown automatically. * * NOTES *	cl_pool_get returns the object at the head of the pool. If the pool is *	empty, it is automatically grown to accommodate this request unless the *	grow_size parameter passed to the cl_pool_init function was zero. * * SEE ALSO *	Pool, cl_pool_get_tail, cl_pool_put, cl_pool_grow, cl_pool_count *********/
end_comment

begin_comment
comment|/****f* Component Library: Pool/cl_pool_put * NAME *	cl_pool_put * * DESCRIPTION *	The cl_pool_put function returns an object to a pool. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|cl_pool_put
parameter_list|(
name|IN
name|cl_pool_t
modifier|*
specifier|const
name|p_pool
parameter_list|,
name|IN
name|void
modifier|*
specifier|const
name|p_object
parameter_list|)
block|{
name|cl_pool_obj_t
modifier|*
name|p_pool_obj
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_pool
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_object
argument_list|)
expr_stmt|;
comment|/* Calculate the offset to the list object representing this object. */
name|p_pool_obj
operator|=
operator|(
name|cl_pool_obj_t
operator|*
operator|)
operator|(
operator|(
operator|(
name|uint8_t
operator|*
operator|)
name|p_object
operator|)
operator|-
sizeof|sizeof
argument_list|(
name|cl_pool_obj_t
argument_list|)
operator|)
expr_stmt|;
comment|/* good sanity check */
name|CL_ASSERT
argument_list|(
name|p_pool_obj
operator|->
name|p_object
operator|==
name|p_object
argument_list|)
expr_stmt|;
name|cl_qcpool_put
argument_list|(
operator|&
name|p_pool
operator|->
name|qcpool
argument_list|,
operator|&
name|p_pool_obj
operator|->
name|pool_item
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to a cl_pool_t structure to which to return *		an object. * *	p_object *		[in] Pointer to an object to return to the pool. * * RETURN VALUE *	This function does not return a value. * * NOTES *	cl_pool_put places the returned object at the head of the pool. * *	The object specified by the p_object parameter must have been *	retrieved from the pool by a previous call to cl_pool_get. * * SEE ALSO *	Pool, cl_pool_put_tail, cl_pool_get *********/
end_comment

begin_comment
comment|/****f* Component Library: Pool/cl_pool_grow * NAME *	cl_pool_grow * * DESCRIPTION *	The cl_pool_grow function grows a pool by *	the specified number of objects. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_status_t
name|cl_pool_grow
parameter_list|(
name|IN
name|cl_pool_t
modifier|*
specifier|const
name|p_pool
parameter_list|,
name|IN
specifier|const
name|size_t
name|obj_count
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_pool
argument_list|)
expr_stmt|;
return|return
operator|(
name|cl_qcpool_grow
argument_list|(
operator|&
name|p_pool
operator|->
name|qcpool
argument_list|,
name|obj_count
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to a cl_pool_t structure whose capacity to grow. * *	obj_count *		[in] Number of objects by which to grow the pool. * * RETURN VALUES *	CL_SUCCESS if the pool grew successfully. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory to grow the *	pool. * *	cl_status_t value returned by optional initialization callback function *	specified by the pfn_initializer parameter passed to the *	cl_pool_init function. * * NOTES *	It is not necessary to call cl_pool_grow if the pool is *	configured to grow automatically. * * SEE ALSO *	Pool *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_POOL_H_ */
end_comment

end_unit

