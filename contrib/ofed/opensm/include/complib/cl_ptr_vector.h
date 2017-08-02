begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	This file contains pointer vector definitions.  Pointer Vector provides  *  dynmically resizable array functionality.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_PTR_VECTOR_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_PTR_VECTOR_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_types.h>
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
comment|/****h* Component Library/Pointer Vector * NAME *	Pointer Vector * * DESCRIPTION *	The Pointer Vector is a self-sizing array of pointers. Like a traditonal *	array, a pointer vector allows efficient constant time access to elements *	with a specified index.  A pointer vector grows transparently as the *	user adds elements to the array. * *	The cl_pointer vector_t structure should be treated as opaque and should be *	manipulated only through the provided functions. * * SEE ALSO *	Structures: *		cl_ptr_vector_t * *	Callbacks: *		cl_pfn_ptr_vec_apply_t, cl_pfn_ptr_vec_find_t * *	Item Manipulation: *		cl_ptr_vector_set, cl_ptr_vector_obj * *	Initialization: *		cl_ptr_vector_construct, cl_ptr_vector_init, cl_ptr_vector_destroy * *	Manipulation: *		cl_ptr_vector_get_capacity, cl_ptr_vector_set_capacity, *		cl_ptr_vector_get_size, cl_ptr_vector_set_size, cl_ptr_vector_set_min_size *		cl_ptr_vector_get_ptr, cl_ptr_vector_get, cl_ptr_vector_at, cl_ptr_vector_set * *	Search: *		cl_ptr_vector_find_from_start, cl_ptr_vector_find_from_end *		cl_ptr_vector_apply_func *********/
end_comment

begin_comment
comment|/****d* Component Library: Pointer Vector/cl_pfn_ptr_vec_apply_t * NAME *	cl_pfn_ptr_vec_apply_t * * DESCRIPTION *	The cl_pfn_ptr_vec_apply_t function type defines the prototype for *	functions used to iterate elements in a pointer vector. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cl_pfn_ptr_vec_apply_t
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
name|element
parameter_list|,
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	index *		[in] Index of the element. * *	p_element *		[in] Pointer to an element at the specified index in the pointer vector. * *	context *		[in] Context provided in a call to cl_ptr_vector_apply_func. * * RETURN VALUE *	This function does not return a value. * * NOTES *	This function type is provided as function prototype reference for *	the function passed by users as a parameter to the cl_ptr_vector_apply_func *	function. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_apply_func *********/
end_comment

begin_comment
comment|/****d* Component Library: Pointer Vector/cl_pfn_ptr_vec_find_t * NAME *	cl_pfn_ptr_vec_find_t * * DESCRIPTION *	The cl_pfn_ptr_vec_find_t function type defines the prototype for *	functions used to find elements in a pointer vector. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|cl_status_t
function_decl|(
modifier|*
name|cl_pfn_ptr_vec_find_t
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
name|element
parameter_list|,
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	index *		[in] Index of the element. * *	p_element *		[in] Pointer to an element at the specified index in the *		pointer vector. * *	context *		[in] Context provided in a call to cl_ptr_vector_find_from_start or *		cl_ptr_vector_find_from_end. * * RETURN VALUES *	Return CL_SUCCESS if the element was found. This stops pointer vector *	iteration. * *	CL_NOT_FOUND to continue the pointer vector iteration. * * NOTES *	This function type is provided as function prototype reference for the *	function provided by users as a parameter to the *	cl_ptr_vector_find_from_start and cl_ptr_vector_find_from_end functions. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_find_from_start, cl_ptr_vector_find_from_end *********/
end_comment

begin_comment
comment|/****s* Component Library: Pointer Vector/cl_ptr_vector_t * NAME *	cl_ptr_vector_t * * DESCRIPTION *	Pointer Vector structure. * *	The cl_ptr_vector_t structure should be treated as opaque and should be *	manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_ptr_vector
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
specifier|const
name|void
modifier|*
modifier|*
name|p_ptr_array
decl_stmt|;
name|cl_state_t
name|state
decl_stmt|;
block|}
name|cl_ptr_vector_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	size *		 Number of elements successfully initialized in the pointer vector. * *	grow_size *		 Number of elements to allocate when growing. * *	capacity *		 total # of elements allocated. * *	alloc_list *		 List of allocations. * *	p_ptr_array *		 Internal array of pointers to elements. * *	state *		State of the pointer vector. * * SEE ALSO *	Pointer Vector *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_construct * NAME *	cl_ptr_vector_construct * * DESCRIPTION *	The cl_ptr_vector_construct function constructs a pointer vector. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_ptr_vector_construct
parameter_list|(
name|IN
name|cl_ptr_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling cl_ptr_vector_destroy without first calling *	cl_ptr_vector_init. * *	Calling cl_ptr_vector_construct is a prerequisite to calling any other *	pointer vector function except cl_ptr_vector_init. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_init, cl_ptr_vector_destroy *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_init * NAME *	cl_ptr_vector_init * * DESCRIPTION *	The cl_ptr_vector_init function initializes a pointer vector for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_ptr_vector_init
parameter_list|(
name|IN
name|cl_ptr_vector_t
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure to inititalize. * *	min_size *		[in] Initial number of elements. * *	grow_size *		[in] Number of elements to allocate when incrementally growing *		the pointer vector.  A value of zero disables automatic growth. * * RETURN VALUES *	CL_SUCCESS if the pointer vector was initialized successfully. * *	CL_INSUFFICIENT_MEMORY if the initialization failed. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_construct, cl_ptr_vector_destroy, *	cl_ptr_vector_set, cl_ptr_vector_get, cl_ptr_vector_at *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_destroy * NAME *	cl_ptr_vector_destroy * * DESCRIPTION *	The cl_ptr_vector_destroy function destroys a pointer vector. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_ptr_vector_destroy
parameter_list|(
name|IN
name|cl_ptr_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	cl_ptr_vector_destroy frees all memory allocated for the pointer vector. * *	This function should only be called after a call to cl_ptr_vector_construct *	or cl_ptr_vector_init. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_construct, cl_ptr_vector_init *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_get_capacity * NAME *	cl_ptr_vector_get_capacity * * DESCRIPTION *	The cl_ptr_vector_get_capacity function returns the capacity of *	a pointer vector. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|size_t
name|cl_ptr_vector_get_capacity
parameter_list|(
name|IN
specifier|const
name|cl_ptr_vector_t
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
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure whose capacity to return. * * RETURN VALUE *	Capacity, in elements, of the pointer vector. * * NOTES *	The capacity is the number of elements that the pointer vector can store, *	and can be greater than the number of elements stored. To get the number *	of elements stored in the pointer vector, use cl_ptr_vector_get_size. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_set_capacity, cl_ptr_vector_get_size *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_get_size * NAME *	cl_ptr_vector_get_size * * DESCRIPTION *	The cl_ptr_vector_get_size function returns the size of a pointer vector. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|cl_ptr_vector_get_size
parameter_list|(
name|IN
specifier|const
name|cl_ptr_vector_t
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
operator|(
name|uint32_t
operator|)
name|p_vector
operator|->
name|size
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure whose size to return. * * RETURN VALUE *	Size, in elements, of the pointer vector. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_set_size, cl_ptr_vector_get_capacity *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_get * NAME *	cl_ptr_vector_get * * DESCRIPTION *	The cl_ptr_vector_get function returns the pointer stored in a *	pointer vector at a specified index. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|cl_ptr_vector_get
parameter_list|(
name|IN
specifier|const
name|cl_ptr_vector_t
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
name|CL_ASSERT
argument_list|(
name|p_vector
operator|->
name|size
operator|>
name|index
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|void
operator|*
operator|)
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
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure from which to get an *		element. * *	index *		[in] Index of the element. * * RETURN VALUE *	Value of the pointer stored at the specified index. * * NOTES *	cl_ptr_vector_get provides constant access times regardless of the index. * *	cl_ptr_vector_get does not perform boundary checking. Callers are *	responsible for providing an index that is within the range of the pointer *	vector. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_at, cl_ptr_vector_set, cl_ptr_vector_get_size *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_at * NAME *	cl_ptr_vector_at * * DESCRIPTION *	The cl_ptr_vector_at function copies an element stored in a pointer *	vector at a specified index, performing boundary checks. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_ptr_vector_at
parameter_list|(
name|IN
specifier|const
name|cl_ptr_vector_t
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
modifier|*
specifier|const
name|p_element
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure from which to get a copy of *		an element. * *	index *		[in] Index of the element. * *	p_element *		[out] Pointer to storage for the pointer element. Contains a copy of *		the desired pointer upon successful completion of the call. * * RETURN VALUES *	CL_SUCCESS if an element was found at the specified index. * *	CL_INVALID_SETTING if the index was out of range. * * NOTES *	cl_ptr_vector_at provides constant time access regardless of *	the index, and performs boundary checking on the pointer vector. * *	Upon success, the p_element parameter contains a copy of the *	desired element. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_get *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_set * NAME *	cl_ptr_vector_set * * DESCRIPTION *	The cl_ptr_vector_set function sets the element at the specified index. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_ptr_vector_set
parameter_list|(
name|IN
name|cl_ptr_vector_t
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
specifier|const
name|void
modifier|*
specifier|const
name|element
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure into which to store *		an element. * *	index *		[in] Index of the element. * *	element *		[in] Pointer to store in the pointer vector. * * RETURN VALUES *	CL_SUCCESS if the element was successfully set. * *	CL_INSUFFICIENT_MEMORY if the pointer vector could not be resized to *	accommodate the new element. * * NOTES *	cl_ptr_vector_set grows the pointer vector as needed to accommodate *	the new element, unless the grow_size parameter passed into the *	cl_ptr_vector_init function was zero. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_get *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_insert * NAME *	cl_ptr_vector_insert * * DESCRIPTION *	The cl_ptr_vector_insert function inserts an element into a pointer vector. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_status_t
name|cl_ptr_vector_insert
parameter_list|(
name|IN
name|cl_ptr_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
specifier|const
name|element
parameter_list|,
name|OUT
name|size_t
modifier|*
specifier|const
name|p_index
name|OPTIONAL
parameter_list|)
block|{
name|cl_status_t
name|status
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
name|status
operator|=
name|cl_ptr_vector_set
argument_list|(
name|p_vector
argument_list|,
name|p_vector
operator|->
name|size
argument_list|,
name|element
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|==
name|CL_SUCCESS
operator|&&
name|p_index
condition|)
operator|*
name|p_index
operator|=
name|p_vector
operator|->
name|size
operator|-
literal|1
expr_stmt|;
return|return
operator|(
name|status
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure into which to store *		an element. * *	element *		[in] Pointer to store in the pointer vector. * *	p_index *		[out] Pointer to the index of the element.  Valid only if *		insertion was successful. * * RETURN VALUES *	CL_SUCCESS if the element was successfully inserted. * *	CL_INSUFFICIENT_MEMORY if the pointer vector could not be resized to *	accommodate the new element. * * NOTES *	cl_ptr_vector_insert places the new element at the end of *	the pointer vector. * *	cl_ptr_vector_insert grows the pointer vector as needed to accommodate *	the new element, unless the grow_size parameter passed into the *	cl_ptr_vector_init function was zero. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_remove, cl_ptr_vector_set *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_remove * NAME *	cl_ptr_vector_remove * * DESCRIPTION *	The cl_ptr_vector_remove function removes and returns the pointer stored *	in a pointer vector at a specified index.  Items beyond the removed item *	are shifted down and the size of the pointer vector is decremented. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
modifier|*
name|cl_ptr_vector_remove
parameter_list|(
name|IN
name|cl_ptr_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
specifier|const
name|size_t
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure from which to get an *		element. * *	index *		[in] Index of the element. * * RETURN VALUE *	Value of the pointer stored at the specified index. * * NOTES *	cl_ptr_vector_get does not perform boundary checking. Callers are *	responsible for providing an index that is within the range of the pointer *	vector. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_insert, cl_ptr_vector_get_size *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_set_capacity * NAME *	cl_ptr_vector_set_capacity * * DESCRIPTION *	The cl_ptr_vector_set_capacity function reserves memory in a *	pointer vector for a specified number of pointers. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_ptr_vector_set_capacity
parameter_list|(
name|IN
name|cl_ptr_vector_t
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
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure whose capacity to set. * *	new_capacity *		[in] Total number of elements for which the pointer vector should *		allocate memory. * * RETURN VALUES *	CL_SUCCESS if the capacity was successfully set. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory to satisfy the *	operation. The pointer vector is left unchanged. * * NOTES *	cl_ptr_vector_set_capacity increases the capacity of the pointer vector. *	It does not change the size of the pointer vector. If the requested *	capacity is less than the current capacity, the pointer vector is left *	unchanged. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_get_capacity, cl_ptr_vector_set_size, *	cl_ptr_vector_set_min_size *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_set_size * NAME *	cl_ptr_vector_set_size * * DESCRIPTION *	The cl_ptr_vector_set_size function resizes a pointer vector, either *	increasing or decreasing its size. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_ptr_vector_set_size
parameter_list|(
name|IN
name|cl_ptr_vector_t
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
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure whose size to set. * *	size *		[in] Number of elements desired in the pointer vector. * * RETURN VALUES *	CL_SUCCESS if the size of the pointer vector was set successfully. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory to complete the *	operation. The pointer vector is left unchanged. * * NOTES *	cl_ptr_vector_set_size sets the pointer vector to the specified size. *	If size is smaller than the current size of the pointer vector, the size *	is reduced. * *	This function can only fail if size is larger than the current capacity. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_get_size, cl_ptr_vector_set_min_size, *	cl_ptr_vector_set_capacity *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_set_min_size * NAME *	cl_ptr_vector_set_min_size * * DESCRIPTION *	The cl_ptr_vector_set_min_size function resizes a pointer vector to a *	specified size if the pointer vector is smaller than the specified size. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_ptr_vector_set_min_size
parameter_list|(
name|IN
name|cl_ptr_vector_t
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
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure whose minimum size to set. * *	min_size *		[in] Minimum number of elements that the pointer vector should contain. * * RETURN VALUES *	CL_SUCCESS if the pointer vector size is greater than or equal to min_size. *	This could indicate that the pointer vector's capacity was increased to *	min_size or that the pointer vector was already of sufficient size. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory to resize the *	pointer vector.  The pointer vector is left unchanged. * * NOTES *	If min_size is smaller than the current size of the pointer vector, *	the pointer vector is unchanged. The pointer vector is unchanged if the *	size could not be changed due to insufficient memory being available to *	perform the operation. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_get_size, cl_ptr_vector_set_size, *	cl_ptr_vector_set_capacity *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_apply_func * NAME *	cl_ptr_vector_apply_func * * DESCRIPTION *	The cl_ptr_vector_apply_func function invokes a specified function for *	every element in a pointer vector. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_ptr_vector_apply_func
parameter_list|(
name|IN
specifier|const
name|cl_ptr_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
name|cl_pfn_ptr_vec_apply_t
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
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure whose elements to iterate. * *	pfn_callback *		[in] Function invoked for every element in the array. *		See the cl_pfn_ptr_vec_apply_t function type declaration for details *		about the callback function. * *	context *		[in] Value to pass to the callback function. * * RETURN VALUE *	This function does not return a value. * * NOTES *	cl_ptr_vector_apply_func invokes the specified function for every element *	in the pointer vector, starting from the beginning of the pointer vector. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_find_from_start, cl_ptr_vector_find_from_end, *	cl_pfn_ptr_vec_apply_t *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_find_from_start * NAME *	cl_ptr_vector_find_from_start * * DESCRIPTION *	The cl_ptr_vector_find_from_start function uses a specified function to *	search for elements in a pointer vector starting from the lowest index. * * SYNOPSIS */
end_comment

begin_function_decl
name|size_t
name|cl_ptr_vector_find_from_start
parameter_list|(
name|IN
specifier|const
name|cl_ptr_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
name|cl_pfn_ptr_vec_find_t
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
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure to inititalize. * *	pfn_callback *		[in] Function invoked to determine if a match was found. *		See the cl_pfn_ptr_vec_find_t function type declaration for details *		about the callback function. * *	context *		[in] Value to pass to the callback function. * * RETURN VALUES *	Index of the element, if found. * *	Size of the pointer vector if the element was not found. * * NOTES *	cl_ptr_vector_find_from_start does not remove the found element from *	the pointer vector. The index of the element is returned when the function *	provided by the pfn_callback parameter returns CL_SUCCESS. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_find_from_end, cl_ptr_vector_apply_func, *	cl_pfn_ptr_vec_find_t *********/
end_comment

begin_comment
comment|/****f* Component Library: Pointer Vector/cl_ptr_vector_find_from_end * NAME *	cl_ptr_vector_find_from_end * * DESCRIPTION *	The cl_ptr_vector_find_from_end function uses a specified function to *	search for elements in a pointer vector starting from the highest index. * * SYNOPSIS */
end_comment

begin_function_decl
name|size_t
name|cl_ptr_vector_find_from_end
parameter_list|(
name|IN
specifier|const
name|cl_ptr_vector_t
modifier|*
specifier|const
name|p_vector
parameter_list|,
name|IN
name|cl_pfn_ptr_vec_find_t
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
comment|/* * PARAMETERS *	p_vector *		[in] Pointer to a cl_ptr_vector_t structure to inititalize. * *	pfn_callback *		[in] Function invoked to determine if a match was found. *		See the cl_pfn_ptr_vec_find_t function type declaration for details *		about the callback function. * *	context *		[in] Value to pass to the callback function. * * RETURN VALUES *	Index of the element, if found. * *	Size of the pointer vector if the element was not found. * * NOTES *	cl_ptr_vector_find_from_end does not remove the found element from *	the pointer vector. The index of the element is returned when the function *	provided by the pfn_callback parameter returns CL_SUCCESS. * * SEE ALSO *	Pointer Vector, cl_ptr_vector_find_from_start, cl_ptr_vector_apply_func, *	cl_pfn_ptr_vec_find_t *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_PTR_VECTOR_H_ */
end_comment

end_unit

