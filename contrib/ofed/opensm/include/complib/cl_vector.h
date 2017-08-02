begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	This file contains vector definitions.  Vector provides dynmically  *	resizable array functionality.  Objects in a Vector are not relocated  *	when the array is resized.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_VECTOR_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_VECTOR_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_qlist.h>
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
comment|/****h* Component Library/Vector * NAME *	Vector * * DESCRIPTION *	The Vector is a self-sizing array. Like a traditonal array, a vector *	allows efficient constant time access to elements with a specified index. *	A vector grows transparently as the user adds elements to the array. * *	As the vector grows in size, it does not relocate existing elements in *	memory. This allows using pointers to elements stored in a Vector. * *	Users can supply an initializer functions that allow a vector to ensure *	that new items added to the vector are properly initialized. A vector *	calls the initializer function on a per object basis when growing the *	array. The initializer is optional. * *	The initializer function can fail, and returns a cl_status_t. The vector *	will call the destructor function, if provided, for an element that *	failed initialization. If an initializer fails, a vector does not call *	the initializer for objects in the remainder of the new memory allocation. * *	The cl_vector_t structure should be treated as opaque and should be *	manipulated only through the provided functions. * * SEE ALSO *	Structures: *		cl_vector_t * *	Callbacks: *		cl_pfn_vec_init_t, cl_pfn_vec_dtor_t, cl_pfn_vec_apply_t, *		cl_pfn_vec_find_t * *	Item Manipulation: *		cl_vector_set_obj, cl_vector_obj * *	Initialization: *		cl_vector_construct, cl_vector_init, cl_vector_destroy * *	Manipulation: *		cl_vector_get_capacity, cl_vector_set_capacity, *		cl_vector_get_size, cl_vector_set_size, cl_vector_set_min_size *		cl_vector_get_ptr, cl_vector_get, cl_vector_at, cl_vector_set * *	Search: *		cl_vector_find_from_start, cl_vector_find_from_end *		cl_vector_apply_func *********/
end_comment

begin_comment
comment|/****d* Component Library: Vector/cl_pfn_vec_init_t * NAME *	cl_pfn_vec_init_t * * DESCRIPTION *	The cl_pfn_vec_init_t function type defines the prototype for functions *	used as initializer for elements being allocated by a vector. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|cl_status_t
function_decl|(
modifier|*
name|cl_pfn_vec_init_t
function_decl|)
parameter_list|(
name|IN
name|void
modifier|*
specifier|const
name|p_element
parameter_list|,
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	p_element *		[in] Pointer to an element being added to a vector. * *	context *		[in] Context provided in a call to cl_vector_init. * * RETURN VALUES *	Return CL_SUCCESS to indicate that the element was initialized successfully. * *	Other cl_status_t values will be returned by the cl_vector_init, *	cl_vector_set_size, and cl_vector_set_min_size functions. * *	In situations where the vector's size needs to grows in order to satisfy *	a call to cl_vector_set, a non-successful status returned by the *	initializer callback causes the growth to stop. * * NOTES *	This function type is provided as function prototype reference for *	the initializer function provided by users as an optional parameter to *	the cl_vector_init function. * * SEE ALSO *	Vector, cl_vector_init *********/
end_comment

begin_comment
comment|/****d* Component Library: Vector/cl_pfn_vec_dtor_t * NAME *	cl_pfn_vec_dtor_t * * DESCRIPTION *	The cl_pfn_vec_dtor_t function type defines the prototype for functions *	used as destructor for elements being deallocated from a vector. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cl_pfn_vec_dtor_t
function_decl|)
parameter_list|(
name|IN
name|void
modifier|*
specifier|const
name|p_element
parameter_list|,
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	p_element *		[in] Pointer to an element being deallocated from a vector. * *	context *		[in] Context provided in a call to cl_vector_init. * * RETURN VALUE *	This function does not return a value. * * NOTES *	This function type is provided as function prototype reference for *	the destructor function provided by users as an optional parameter to *	the cl_vector_init function. * * SEE ALSO *	Vector, cl_vector_init *********/
end_comment

begin_comment
comment|/****d* Component Library: Vector/cl_pfn_vec_apply_t * NAME *	cl_pfn_vec_apply_t * * DESCRIPTION *	The cl_pfn_vec_apply_t function type defines the prototype for functions *	used to iterate elements in a vector. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cl_pfn_vec_apply_t
function_decl|)
parameter_list|(
name|IN
specifier|const
name|size_t
name|index
parameter_list|,
name|IN
name|void
modifier|*
specifier|const
name|p_element
parameter_list|,
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	index *		[in] Index of the element. * *	p_element *		[in] Pointer to an element at the specified index in the vector. * *	context *		[in] Context provided in a call to cl_vector_apply_func. * * RETURN VALUE *	This function does not return a value. * * NOTES *	This function type is provided as function prototype reference for *	the function passed by users as a parameter to the cl_vector_apply_func *	function. * * SEE ALSO *	Vector, cl_vector_apply_func *********/
end_comment

begin_comment
comment|/****d* Component Library: Vector/cl_pfn_vec_find_t * NAME *	cl_pfn_vec_find_t * * DESCRIPTION *	The cl_pfn_vec_find_t function type defines the prototype for functions *	used to find elements in a vector. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|cl_status_t
function_decl|(
modifier|*
name|cl_pfn_vec_find_t
function_decl|)
parameter_list|(
name|IN
specifier|const
name|size_t
name|index
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
specifier|const
name|p_element
parameter_list|,
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	index *		[in] Index of the element. * *	p_element *		[in] Pointer to an element at the specified index in the vector. * *	context *		[in] Context provided in a call to cl_vector_find_from_start or *		cl_vector_find_from_end. * * RETURN VALUES *	Return CL_SUCCESS if the element was found. This stops vector iteration. * *	CL_NOT_FOUND to continue the vector iteration. * * NOTES *	This function type is provided as function prototype reference for the *	function provided by users as a parameter to the cl_vector_find_from_start *	and cl_vector_find_from_end functions. * * SEE ALSO *	Vector, cl_vector_find_from_start, cl_vector_find_from_end *********/
end_comment

begin_comment
comment|/****i* Component Library: Vector/cl_pfn_vec_copy_t * NAME *	cl_pfn_vec_copy_t * * DESCRIPTION *	The cl_pfn_vec_copy_t function type defines the prototype for functions *	used to copy elements in a vector. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cl_pfn_vec_copy_t
function_decl|)
parameter_list|(
name|IN
name|void
modifier|*
specifier|const
name|p_dest
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
specifier|const
name|p_src
parameter_list|,
name|IN
specifier|const
name|size_t
name|size
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	p_dest *		[in] Pointer to the destination buffer into which to copy p_src. * *	p_src *		[in] Pointer to the destination buffer from which to copy. * *	size *		[in] Number of bytes to copy. * * RETURN VALUE *	This function does not return a value. * * SEE ALSO *	Vector *********/
end_comment

begin_comment
comment|/****s* Component Library: Vector/cl_vector_t * NAME *	cl_vector_t * * DESCRIPTION *	Vector structure. * *	The cl_vector_t structure should be treated as opaque and should be *	manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_vector
block|{
name|size_t
name|size
decl_stmt|;
name|size_t
name|grow_size
decl_stmt|;
name|size_t
name|capacity
decl_stmt|;
name|size_t
name|element_size
decl_stmt|;
name|cl_pfn_vec_init_t
name|pfn_init
decl_stmt|;
name|cl_pfn_vec_dtor_t
name|pfn_dtor
decl_stmt|;
name|cl_pfn_vec_copy_t
name|pfn_copy
decl_stmt|;
specifier|const
name|void
modifier|*
name|context
decl_stmt|;
name|cl_qlist_t
name|alloc_list
decl_stmt|;
name|void
modifier|*
modifier|*
name|p_ptr_array
decl_stmt|;
name|cl_state_t
name|state
decl_stmt|;
block|}
name|cl_vector_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	size *		 Number of elements successfully initialized in the vector. * *	grow_size *		 Number of elements to allocate when growing. * *	capacity *		 total # of elements allocated. * *	element_size *		 Size of each element. * *	pfn_init *		 User supplied element initializer. * *	pfn_dtor *		 User supplied element destructor. * *	pfn_copy *		 Copy operator. * *	context *		 User context for callbacks. * *	alloc_list *		 List of allocations. * *	p_ptr_array *		 Internal array of pointers to elements. * *	state *		State of the vector. * * SEE ALSO *	Vector *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_construct * NAME *	cl_vector_construct * * DESCRIPTION *	The cl_vector_construct function constructs a vector. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_vector_construct
parameter_list|(
name|IN
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling cl_vector_destroy without first calling cl_vector_init. * *	Calling cl_vector_construct is a prerequisite to calling any other *	vector function except cl_vector_init. * * SEE ALSO *	Vector, cl_vector_init, cl_vector_destroy *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_init * NAME *	cl_vector_init * * DESCRIPTION *	The cl_vector_init function initializes a vector for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_vector_init
parameter_list|(
name|IN
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
specifier|const
name|size_t
name|min_size
parameter_list|,
name|IN
specifier|const
name|size_t
name|grow_size
parameter_list|,
name|IN
specifier|const
name|size_t
name|element_size
parameter_list|,
name|IN
name|cl_pfn_vec_init_t
name|pfn_init
name|OPTIONAL
parameter_list|,
name|IN
name|cl_pfn_vec_dtor_t
name|pfn_dtor
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
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure to inititalize. * *	min_size *		[in] Initial number of elements. * *	grow_size *		[in] Number of elements to allocate when incrementally growing *		the vector.  A value of zero disables automatic growth. * *	element_size *		[in] Size of each element. * *	pfn_init *		[in] Initializer callback to invoke for every new element. *		See the cl_pfn_vec_init_t function type declaration for details about *		the callback function. * *	pfn_dtor *		[in] Destructor callback to invoke for elements being deallocated. *		See the cl_pfn_vec_dtor_t function type declaration for details about *		the callback function. * *	context *		[in] Value to pass to the callback functions to provide context. * * RETURN VALUES *	CL_SUCCESS if the vector was initialized successfully. * *	CL_INSUFFICIENT_MEMORY if the initialization failed. * *	cl_status_t value returned by optional initializer function specified by *	the pfn_init parameter. * * NOTES *	The constructor and initializer functions, if any, are invoked for every *	new element in the array. * * SEE ALSO *	Vector, cl_vector_construct, cl_vector_destroy, cl_vector_set, *	cl_vector_get, cl_vector_get_ptr, cl_vector_at *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_destroy * NAME *	cl_vector_destroy * * DESCRIPTION *	The cl_vector_destroy function destroys a vector. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_vector_destroy
parameter_list|(
name|IN
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	cl_vector_destroy frees all memory allocated for the vector. The vector *	is left initialized to a zero capacity and size. * *	This function should only be called after a call to cl_vector_construct *	or cl_vector_init. * * SEE ALSO *	Vector, cl_vector_construct, cl_vector_init *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_get_capacity * NAME *	cl_vector_get_capacity * * DESCRIPTION *	The cl_vector_get_capacity function returns the capacity of a vector. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|size_t
name|cl_vector_get_capacity
parameter_list|(
name|IN
specifier|const
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_vector
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_vector
operator|->
name|state
operator|==
name|CL_INITIALIZED
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_vector
operator|->
name|capacity
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure whose capacity to return. * * RETURN VALUE *	Capacity, in elements, of the vector. * * NOTES *	The capacity is the number of elements that the vector can store, and *	can be greater than the number of elements stored. To get the number of *	elements stored in the vector, use cl_vector_get_size. * * SEE ALSO *	Vector, cl_vector_set_capacity, cl_vector_get_size *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_get_size * NAME *	cl_vector_get_size * * DESCRIPTION *	The cl_vector_get_size function returns the size of a vector. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|size_t
name|cl_vector_get_size
parameter_list|(
name|IN
specifier|const
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_vector
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_vector
operator|->
name|state
operator|==
name|CL_INITIALIZED
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_vector
operator|->
name|size
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure whose size to return. * * RETURN VALUE *	Size, in elements, of the vector. * * SEE ALSO *	Vector, cl_vector_set_size, cl_vector_get_capacity *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_get_ptr * NAME *	cl_vector_get_ptr * * DESCRIPTION *	The cl_vector_get_ptr function returns a pointer to an element *	stored in a vector at a specified index. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|cl_vector_get_ptr
parameter_list|(
name|IN
specifier|const
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
specifier|const
name|size_t
name|index
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_vector
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_vector
operator|->
name|state
operator|==
name|CL_INITIALIZED
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_vector
operator|->
name|p_ptr_array
index|[
name|index
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure from which to get a *		pointer to an element. * *	index *		[in] Index of the element. * * RETURN VALUE *	Pointer to the element stored at specified index. * * NOTES *	cl_vector_get_ptr provides constant access times regardless of the index. * *	cl_vector_get_ptr does not perform boundary checking. Callers are *	responsible for providing an index that is within the range of the vector. * * SEE ALSO *	Vector, cl_vector_get, cl_vector_at, cl_vector_set, cl_vector_get_size *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_get * NAME *	cl_vector_get * * DESCRIPTION *	The cl_vector_get function copies an element stored in a vector at a *	specified index. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|cl_vector_get
parameter_list|(
name|IN
specifier|const
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
specifier|const
name|size_t
name|index
parameter_list|,
name|OUT
name|void
modifier|*
specifier|const
name|p_element
parameter_list|)
block|{
name|void
modifier|*
name|p_src
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_vector
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_vector
operator|->
name|state
operator|==
name|CL_INITIALIZED
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_element
argument_list|)
expr_stmt|;
comment|/* Get a pointer to the element. */
name|p_src
operator|=
name|cl_vector_get_ptr
argument_list|(
name|p_vector
argument_list|,
name|index
argument_list|)
expr_stmt|;
name|p_vector
operator|->
name|pfn_copy
argument_list|(
name|p_src
argument_list|,
name|p_element
argument_list|,
name|p_vector
operator|->
name|element_size
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure from which to get a copy of *		an element. * *	index *		[in] Index of the element. * *	p_element *		[out] Pointer to storage for the element. Contains a copy of the *		desired element upon successful completion of the call. * * RETURN VALUE *	This function does not return a value. * * NOTES *	cl_vector_get provides constant time access regardless of the index. * *	cl_vector_get does not perform boundary checking on the vector, and *	callers are responsible for providing an index that is within the range *	of the vector. To access elements after performing boundary checks, *	use cl_vector_at. * *	The p_element parameter contains a copy of the desired element upon *	return from this function. * * SEE ALSO *	Vector, cl_vector_get_ptr, cl_vector_at *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_at * NAME *	cl_vector_at * * DESCRIPTION *	The cl_vector_at function copies an element stored in a vector at a *	specified index, performing boundary checks. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_vector_at
parameter_list|(
name|IN
specifier|const
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
specifier|const
name|size_t
name|index
parameter_list|,
name|OUT
name|void
modifier|*
specifier|const
name|p_element
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure from which to get a copy of *		an element. * *	index *		[in] Index of the element. * *	p_element *		[out] Pointer to storage for the element. Contains a copy of the *		desired element upon successful completion of the call. * * RETURN VALUES *	CL_SUCCESS if an element was found at the specified index. * *	CL_INVALID_SETTING if the index was out of range. * * NOTES *	cl_vector_at provides constant time access regardless of the index, and *	performs boundary checking on the vector. * *	Upon success, the p_element parameter contains a copy of the desired element. * * SEE ALSO *	Vector, cl_vector_get, cl_vector_get_ptr *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_set * NAME *	cl_vector_set * * DESCRIPTION *	The cl_vector_set function sets the element at the specified index. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_vector_set
parameter_list|(
name|IN
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
specifier|const
name|size_t
name|index
parameter_list|,
name|IN
name|void
modifier|*
specifier|const
name|p_element
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure into which to store *		an element. * *	index *		[in] Index of the element. * *	p_element *		[in] Pointer to an element to store in the vector. * * RETURN VALUES *	CL_SUCCESS if the element was successfully set. * *	CL_INSUFFICIENT_MEMORY if the vector could not be resized to accommodate *	the new element. * * NOTES *	cl_vector_set grows the vector as needed to accommodate the new element, *	unless the grow_size parameter passed into the cl_vector_init function *	was zero. * * SEE ALSO *	Vector, cl_vector_get *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_set_capacity * NAME *	cl_vector_set_capacity * * DESCRIPTION *	The cl_vector_set_capacity function reserves memory in a vector for a *	specified number of elements. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_vector_set_capacity
parameter_list|(
name|IN
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
specifier|const
name|size_t
name|new_capacity
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure whose capacity to set. * *	new_capacity *		[in] Total number of elements for which the vector should *		allocate memory. * * RETURN VALUES *	CL_SUCCESS if the capacity was successfully set. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory to satisfy the *	operation. The vector is left unchanged. * * NOTES *	cl_vector_set_capacity increases the capacity of the vector. It does *	not change the size of the vector. If the requested capacity is less *	than the current capacity, the vector is left unchanged. * * SEE ALSO *	Vector, cl_vector_get_capacity, cl_vector_set_size, *	cl_vector_set_min_size *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_set_size * NAME *	cl_vector_set_size * * DESCRIPTION *	The cl_vector_set_size function resizes a vector, either increasing or *	decreasing its size. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_vector_set_size
parameter_list|(
name|IN
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
specifier|const
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure whose size to set. * *	size *		[in] Number of elements desired in the vector. * * RETURN VALUES *	CL_SUCCESS if the size of the vector was set successfully. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory to complete the *	operation. The vector is left unchanged. * * NOTES *	cl_vector_set_size sets the vector to the specified size. If size is *	smaller than the current size of the vector, the size is reduced. *	The destructor function, if any, will be invoked for all elements that *	are above size. Likewise, the constructor and initializer, if any, will *	be invoked for all new elements. * *	This function can only fail if size is larger than the current capacity. * * SEE ALSO *	Vector, cl_vector_get_size, cl_vector_set_min_size, *	cl_vector_set_capacity *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_set_min_size * NAME *	cl_vector_set_min_size * * DESCRIPTION *	The cl_vector_set_min_size function resizes a vector to a specified size *	if the vector is smaller than the specified size. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_vector_set_min_size
parameter_list|(
name|IN
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
specifier|const
name|size_t
name|min_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure whose minimum size to set. * *	min_size *		[in] Minimum number of elements that the vector should contain. * * RETURN VALUES *	CL_SUCCESS if the vector size is greater than or equal to min_size.  This *	could indicate that the vector's capacity was increased to min_size or *	that the vector was already of sufficient size. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory to resize the vector. *	The vector is left unchanged. * * NOTES *	If min_size is smaller than the current size of the vector, the vector is *	unchanged. The vector is unchanged if the size could not be changed due *	to insufficient memory being available to perform the operation. * * SEE ALSO *	Vector, cl_vector_get_size, cl_vector_set_size, cl_vector_set_capacity *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_apply_func * NAME *	cl_vector_apply_func * * DESCRIPTION *	The cl_vector_apply_func function invokes a specified function for every *	element in a vector. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_vector_apply_func
parameter_list|(
name|IN
specifier|const
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
name|cl_pfn_vec_apply_t
name|pfn_callback
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
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure whose elements to iterate. * *	pfn_callback *		[in] Function invoked for every element in the array. *		See the cl_pfn_vec_apply_t function type declaration for details *		about the callback function. * *	context *		[in] Value to pass to the callback function. * * RETURN VALUE *	This function does not return a value. * * NOTES *	cl_vector_apply_func invokes the specified function for every element *	in the vector, starting from the beginning of the vector. * * SEE ALSO *	Vector, cl_vector_find_from_start, cl_vector_find_from_end, *	cl_pfn_vec_apply_t *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_find_from_start * NAME *	cl_vector_find_from_start * * DESCRIPTION *	The cl_vector_find_from_start function uses a specified function to *	search for elements in a vector starting from the lowest index. * * SYNOPSIS */
end_comment

begin_function_decl
name|size_t
name|cl_vector_find_from_start
parameter_list|(
name|IN
specifier|const
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
name|cl_pfn_vec_find_t
name|pfn_callback
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
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure to inititalize. * *	pfn_callback *		[in] Function invoked to determine if a match was found. *		See the cl_pfn_vec_find_t function type declaration for details *		about the callback function. * *	context *		[in] Value to pass to the callback function. * * RETURN VALUES *	Index of the element, if found. * *	Size of the vector if the element was not found. * * NOTES *	cl_vector_find_from_start does not remove the found element from *	the vector. The index of the element is returned when the function *	provided by the pfn_callback parameter returns CL_SUCCESS. * * SEE ALSO *	Vector, cl_vector_find_from_end, cl_vector_apply_func, cl_pfn_vec_find_t *********/
end_comment

begin_comment
comment|/****f* Component Library: Vector/cl_vector_find_from_end * NAME *	cl_vector_find_from_end * * DESCRIPTION *	The cl_vector_find_from_end function uses a specified function to search *	for elements in a vector starting from the highest index. * * SYNOPSIS */
end_comment

begin_function_decl
name|size_t
name|cl_vector_find_from_end
parameter_list|(
name|IN
specifier|const
name|cl_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
name|cl_pfn_vec_find_t
name|pfn_callback
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
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_vector_t structure to inititalize. * *	pfn_callback *		[in] Function invoked to determine if a match was found. *		See the cl_pfn_vec_find_t function type declaration for details *		about the callback function. * *	context *		[in] Value to pass to the callback function. * * RETURN VALUES *	Index of the element, if found. * *	Size of the vector if the element was not found. * * NOTES *	cl_vector_find_from_end does not remove the found element from *	the vector. The index of the element is returned when the function *	provided by the pfn_callback parameter returns CL_SUCCESS. * * SEE ALSO *	Vector, cl_vector_find_from_start, cl_vector_apply_func, *	cl_pfn_vec_find_t *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_VECTOR_H_ */
end_comment

end_unit

