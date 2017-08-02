begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Declaration of list.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_LIST_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_LIST_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_qlist.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qpool.h>
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
comment|/****h* Component Library/List * NAME *	List * * DESCRIPTION *	List stores objects in a doubly linked list. * *	Unlike quick list, users pass pointers to the object being stored, rather *	than to a cl_list_item_t structure.  Insertion operations on a list can *	fail, and callers should trap for such failures. * *	Use quick list in situations where insertion failures cannot be tolerated. * *	List is not thread safe, and users must provide serialization. * *	The list functions operates on a cl_list_t structure which should be *	treated as opaque and should be manipulated only through the provided *	functions. * * SEE ALSO *	Types: *		cl_list_iterator_t * *	Structures: *		cl_list_t * *	Callbacks: *		cl_pfn_list_apply_t, cl_pfn_list_find_t * *	Initialization/Destruction: *		cl_list_construct, cl_list_init, cl_list_destroy * *	Iteration: *		cl_list_next, cl_list_prev, cl_list_head, cl_list_tail, *		cl_list_end * *	Manipulation: *		cl_list_insert_head, cl_list_insert_tail, *		cl_list_insert_array_head, cl_list_insert_array_tail, *		cl_list_insert_prev, cl_list_insert_next, *		cl_list_remove_head, cl_list_remove_tail, *		cl_list_remove_object, cl_list_remove_item, cl_list_remove_all * *	Search: *		cl_is_object_in_list, cl_list_find_from_head, cl_list_find_from_tail, *		cl_list_apply_func * *	Attributes: *		cl_list_count, cl_is_list_empty, cl_is_list_inited *********/
end_comment

begin_comment
comment|/****s* Component Library: List/cl_list_t * NAME *	cl_list_t * * DESCRIPTION *	List structure. * *	The cl_list_t structure should be treated as opaque and should be *	manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_list
block|{
name|cl_qlist_t
name|list
decl_stmt|;
name|cl_qpool_t
name|list_item_pool
decl_stmt|;
block|}
name|cl_list_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	list *		Quick list of items stored in the list. * *	list_item_pool *		Quick pool of list objects for storing objects in the quick list. * * SEE ALSO *	List *********/
end_comment

begin_comment
comment|/****d* Component Library: List/cl_list_iterator_t * NAME *	cl_list_iterator_t * * DESCRIPTION *	Iterator type used to walk a list. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|cl_list_item_t
modifier|*
name|cl_list_iterator_t
typedef|;
end_typedef

begin_comment
comment|/* * NOTES *	The iterator should be treated as opaque to prevent corrupting the list. * * SEE ALSO *	List, cl_list_head, cl_list_tail, cl_list_next, cl_list_prev, *	cl_list_obj *********/
end_comment

begin_comment
comment|/****d* Component Library: List/cl_pfn_list_apply_t * NAME *	cl_pfn_list_apply_t * * DESCRIPTION *	The cl_pfn_list_apply_t function type defines the prototype for functions *	used to iterate objects in a list. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cl_pfn_list_apply_t
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
comment|/* * PARAMETERS *	p_object *		[in] Pointer to an object stored in a list. * *	context *		[in] Context provided in a call to cl_list_apply_func. * * RETURN VALUE *	This function does not return a value. * * NOTES *	This function type is provided as function prototype reference for the *	function provided by users as a parameter to the cl_list_apply_func *	function. * * SEE ALSO *	List, cl_list_apply_func *********/
end_comment

begin_comment
comment|/****d* Component Library: List/cl_pfn_list_find_t * NAME *	cl_pfn_list_find_t * * DESCRIPTION *	The cl_pfn_list_find_t function type defines the prototype for functions *	used to find objects in a list. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|cl_status_t
function_decl|(
modifier|*
name|cl_pfn_list_find_t
function_decl|)
parameter_list|(
name|IN
specifier|const
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
comment|/* * PARAMETERS *	p_object *		[in] Pointer to an object stored in a list. * *	context *		[in] Context provided in a call to ListFindFromHead or ListFindFromTail. * * RETURN VALUES *	Return CL_SUCCESS if the desired item was found.  This stops list iteration. * *	Return CL_NOT_FOUND to continue the list iteration. * * NOTES *	This function type is provided as function prototype reference for the *	function provided by users as a parameter to the cl_list_find_from_head *	and cl_list_find_from_tail functions. * * SEE ALSO *	List, cl_list_find_from_head, cl_list_find_from_tail *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_construct * NAME *	cl_list_construct * * DESCRIPTION *	The cl_list_construct function constructs a list. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_list_construct
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to cl_list_t object whose state to initialize. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling cl_list_init, cl_list_destroy and cl_is_list_inited. * *	Calling cl_list_construct is a prerequisite to calling any other *	list function except cl_list_init. * * SEE ALSO *	List, cl_list_init, cl_list_destroy, cl_is_list_inited *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_is_list_inited * NAME *	cl_is_list_inited * * DESCRIPTION *	The cl_is_list_inited function returns whether a list was *	initialized successfully. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|cl_is_list_inited
parameter_list|(
name|IN
specifier|const
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|)
block|{
comment|/* CL_ASSERT that a non-null pointer is provided. */
name|CL_ASSERT
argument_list|(
name|p_list
argument_list|)
expr_stmt|;
comment|/* 	 * The pool is the last thing initialized.  If it is initialized, the 	 * list is initialized too. 	 */
return|return
operator|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure whose initilization state *		to check. * * RETURN VALUES *	TRUE if the list was initialized successfully. * *	FALSE otherwise. * * NOTES *	Allows checking the state of a list to determine if invoking *	member functions is appropriate. * * SEE ALSO *	List *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_init * NAME *	cl_list_init * * DESCRIPTION *	The cl_list_init function initializes a list for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_list_init
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|,
name|IN
specifier|const
name|size_t
name|min_items
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to cl_list_t structure to initialize. * *	min_items *		[in] Minimum number of items that can be stored.  All necessary *		allocations to allow storing the minimum number of items is performed *		at initialization time. * * RETURN VALUES *	CL_SUCCESS if the list was initialized successfully. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory for initialization. * * NOTES *	The list will always be able to store at least as many items as specified *	by the min_items parameter. * * SEE ALSO *	List, cl_list_construct, cl_list_destroy, cl_list_insert_head, *	cl_list_insert_tail, cl_list_remove_head, cl_list_remove_tail *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_destroy * NAME *	cl_list_destroy * * DESCRIPTION *	The cl_list_destroy function destroys a list. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_list_destroy
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to cl_list_t structure to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	cl_list_destroy does not affect any of the objects stored in the list, *	but does release all memory allocated internally.  Further operations *	should not be attempted on the list after cl_list_destroy is invoked. * *	This function should only be called after a call to cl_list_construct *	or cl_list_init. * *	In debug builds, cl_list_destroy asserts if the list is not empty. * * SEE ALSO *	List, cl_list_construct, cl_list_init *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_is_list_empty * NAME *	cl_is_list_empty * * DESCRIPTION *	The cl_is_list_empty function returns whether a list is empty. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|cl_is_list_empty
parameter_list|(
name|IN
specifier|const
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_list
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|cl_is_qlist_empty
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure. * * RETURN VALUES *	TRUE if the specified list is empty. * *	FALSE otherwise. * * SEE ALSO *	List, cl_list_count, cl_list_remove_all *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_insert_head * NAME *	cl_list_insert_head * * DESCRIPTION *	The cl_list_insert_head function inserts an object at the head of a list. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_status_t
name|cl_list_insert_head
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|,
name|IN
specifier|const
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
name|p_list
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Get a list item to add to the list. */
name|p_pool_obj
operator|=
operator|(
name|cl_pool_obj_t
operator|*
operator|)
name|cl_qpool_get
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|p_pool_obj
condition|)
return|return
operator|(
name|CL_INSUFFICIENT_MEMORY
operator|)
return|;
name|p_pool_obj
operator|->
name|p_object
operator|=
name|p_object
expr_stmt|;
name|cl_qlist_insert_head
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|,
operator|&
name|p_pool_obj
operator|->
name|pool_item
operator|.
name|list_item
argument_list|)
expr_stmt|;
return|return
operator|(
name|CL_SUCCESS
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure into which to insert the object. * *	p_object *		[in] Pointer to an object to insert into the list. * * RETURN VALUES *	CL_SUCCESS if the insertion was successful. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory for the insertion. * * NOTES *	Inserts the specified object at the head of the list.  List insertion *	operations are guaranteed to work for the minimum number of items as *	specified in cl_list_init by the min_items parameter. * * SEE ALSO *	List, cl_list_insert_tail, cl_list_insert_array_head, *	cl_list_insert_array_tail, cl_list_insert_prev, cl_list_insert_next, *	cl_list_remove_head *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_insert_tail * NAME *	cl_list_insert_tail * * DESCRIPTION *	The cl_list_insert_tail function inserts an object at the tail of a list. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_status_t
name|cl_list_insert_tail
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|,
name|IN
specifier|const
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
name|p_list
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Get a list item to add to the list. */
name|p_pool_obj
operator|=
operator|(
name|cl_pool_obj_t
operator|*
operator|)
name|cl_qpool_get
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|p_pool_obj
condition|)
return|return
operator|(
name|CL_INSUFFICIENT_MEMORY
operator|)
return|;
name|p_pool_obj
operator|->
name|p_object
operator|=
name|p_object
expr_stmt|;
name|cl_qlist_insert_tail
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|,
operator|&
name|p_pool_obj
operator|->
name|pool_item
operator|.
name|list_item
argument_list|)
expr_stmt|;
return|return
operator|(
name|CL_SUCCESS
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure into which to insert the object. * *	p_object *		[in] Pointer to an object to insert into the list. * * RETURN VALUES *	CL_SUCCESS if the insertion was successful. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory for the insertion. * * NOTES *	Inserts the specified object at the tail of the list.  List insertion *	operations are guaranteed to work for the minimum number of items as *	specified in cl_list_init by the min_items parameter. * * SEE ALSO *	List, cl_list_insert_head, cl_list_insert_array_head, *	cl_list_insert_array_tail, cl_list_insert_prev, cl_list_insert_next, *	cl_list_remove_tail *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_insert_array_head * NAME *	cl_list_insert_array_head * * DESCRIPTION: *	The cl_list_insert_array_head function inserts an array of objects *	at the head of a list. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_list_insert_array_head
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
specifier|const
name|p_array
parameter_list|,
name|IN
name|uint32_t
name|item_count
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|item_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure into which to insert the objects. * *	p_array *		[in] Pointer to the first object in an array. * *	item_count *		[in] Number of objects in the array. * *	item_size *		[in] Size of the objects added to the list.  This is the stride in the *		array from one object to the next. * * RETURN VALUES *	CL_SUCCESS if the insertion was successful. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory for the insertion. * * NOTES *	Inserts all objects in the array to the head of the list, preserving the *	ordering of the objects.  If not successful, no items are added. *	List insertion operations are guaranteed to work for the minimum number *	of items as specified in cl_list_init by the min_items parameter. * * SEE ALSO *	List, cl_list_insert_array_tail, cl_list_insert_head, cl_list_insert_tail, *	cl_list_insert_prev, cl_list_insert_next *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_insert_array_tail * NAME *	cl_list_insert_array_tail * * DESCRIPTION *	The cl_list_insert_array_tail function inserts an array of objects *	at the tail of a list. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_list_insert_array_tail
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
specifier|const
name|p_array
parameter_list|,
name|IN
name|uint32_t
name|item_count
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|item_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure into which to insert the objects. * *	p_array *		[in] Pointer to the first object in an array. * *	item_count *		[in] Number of objects in the array. * *	item_size *		[in] Size of the objects added to the list.  This is the stride in the *		array from one object to the next. * * RETURN VALUES *	CL_SUCCESS if the insertion was successful. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory for the insertion. * * NOTES *	Inserts all objects in the array to the tail of the list, preserving the *	ordering of the objects.  If not successful, no items are added. *	List insertion operations are guaranteed to work for the minimum number *	of items as specified in cl_list_init by the min_items parameter. * * SEE ALSO *	List, cl_list_insert_array_head, cl_list_insert_head, cl_list_insert_tail, *	cl_list_insert_prev, cl_list_insert_next *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_insert_next * NAME *	cl_list_insert_next * * DESCRIPTION *	The cl_list_insert_next function inserts an object in a list after *	the object associated with a given iterator. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_status_t
name|cl_list_insert_next
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|,
name|IN
name|cl_list_iterator_t
name|iterator
parameter_list|,
name|IN
specifier|const
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
name|p_list
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Get a list item to add to the list. */
name|p_pool_obj
operator|=
operator|(
name|cl_pool_obj_t
operator|*
operator|)
name|cl_qpool_get
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|p_pool_obj
condition|)
return|return
operator|(
name|CL_INSUFFICIENT_MEMORY
operator|)
return|;
name|p_pool_obj
operator|->
name|p_object
operator|=
name|p_object
expr_stmt|;
name|cl_qlist_insert_next
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|,
operator|(
name|cl_list_item_t
operator|*
operator|)
name|iterator
argument_list|,
operator|&
name|p_pool_obj
operator|->
name|pool_item
operator|.
name|list_item
argument_list|)
expr_stmt|;
return|return
operator|(
name|CL_SUCCESS
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure into which to insert the object. * *	iterator *		[in] cl_list_iterator_t returned by a previous call to cl_list_head, *		cl_list_tail, cl_list_next, or cl_list_prev. * *	p_object *		[in] Pointer to an object to insert into the list. * * RETURN VALUES *	CL_SUCCESS if the insertion was successful. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory for the insertion. * * SEE ALSO *	List, cl_list_insert_prev, cl_list_insert_head, cl_list_insert_tail, *	cl_list_insert_array_head, cl_list_insert_array_tail *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_insert_prev * NAME *	cl_list_insert_prev * * DESCRIPTION *	The cl_list_insert_prev function inserts an object in a list before *	the object associated with a given iterator. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_status_t
name|cl_list_insert_prev
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|,
name|IN
name|cl_list_iterator_t
name|iterator
parameter_list|,
name|IN
specifier|const
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
name|p_list
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Get a list item to add to the list. */
name|p_pool_obj
operator|=
operator|(
name|cl_pool_obj_t
operator|*
operator|)
name|cl_qpool_get
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|p_pool_obj
condition|)
return|return
operator|(
name|CL_INSUFFICIENT_MEMORY
operator|)
return|;
name|p_pool_obj
operator|->
name|p_object
operator|=
name|p_object
expr_stmt|;
name|cl_qlist_insert_prev
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|,
operator|(
name|cl_list_item_t
operator|*
operator|)
name|iterator
argument_list|,
operator|&
name|p_pool_obj
operator|->
name|pool_item
operator|.
name|list_item
argument_list|)
expr_stmt|;
return|return
operator|(
name|CL_SUCCESS
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure into which to insert the object. * *	iterator *		[in] cl_list_iterator_t returned by a previous call to cl_list_head, *		cl_list_tail, cl_list_next, or cl_list_prev. * *	p_object *		[in] Pointer to an object to insert into the list. * * RETURN VALUES *	CL_SUCCESS if the insertion was successful. * *	CL_INSUFFICIENT_MEMORY if there was not enough memory for the insertion. * * SEE ALSO *	List, cl_list_insert_next, cl_list_insert_head, cl_list_insert_tail, *	cl_list_insert_array_head, cl_list_insert_array_tail *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_remove_head * NAME *	cl_list_remove_head * * DESCRIPTION *	The cl_list_remove_head function removes an object from the head of a list. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|cl_list_remove_head
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|)
block|{
name|cl_pool_obj_t
modifier|*
name|p_pool_obj
decl_stmt|;
name|void
modifier|*
name|p_obj
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_list
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* See if the list is empty. */
if|if
condition|(
name|cl_is_qlist_empty
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|)
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
comment|/* Get the item at the head of the list. */
name|p_pool_obj
operator|=
operator|(
name|cl_pool_obj_t
operator|*
operator|)
name|cl_qlist_remove_head
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|)
expr_stmt|;
name|p_obj
operator|=
operator|(
name|void
operator|*
operator|)
name|p_pool_obj
operator|->
name|p_object
expr_stmt|;
comment|/* Place the pool item back into the pool. */
name|cl_qpool_put
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|,
operator|&
name|p_pool_obj
operator|->
name|pool_item
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_obj
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure from which to remove an object. * * RETURN VALUES *	Returns the pointer to the object formerly at the head of the list. * *	NULL if the list was empty. * * SEE ALSO *	List, cl_list_remove_tail, cl_list_remove_all, cl_list_remove_object, *	cl_list_remove_item, cl_list_insert_head *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_remove_tail * NAME *	cl_list_remove_tail * * DESCRIPTION *	The cl_list_remove_tail function removes an object from the tail of a list. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|cl_list_remove_tail
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|)
block|{
name|cl_pool_obj_t
modifier|*
name|p_pool_obj
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_list
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* See if the list is empty. */
if|if
condition|(
name|cl_is_qlist_empty
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|)
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
comment|/* Get the item at the head of the list. */
name|p_pool_obj
operator|=
operator|(
name|cl_pool_obj_t
operator|*
operator|)
name|cl_qlist_remove_tail
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|)
expr_stmt|;
comment|/* Place the list item back into the pool. */
name|cl_qpool_put
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|,
operator|&
name|p_pool_obj
operator|->
name|pool_item
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
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure from which to remove an object. * * RETURN VALUES *	Returns the pointer to the object formerly at the tail of the list. * *	NULL if the list was empty. * * SEE ALSO *	List, cl_list_remove_head, cl_list_remove_all, cl_list_remove_object, *	cl_list_remove_item, cl_list_insert_head *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_remove_all * NAME *	cl_list_remove_all * * DESCRIPTION *	The cl_list_remove_all function removes all objects from a list, *	leaving it empty. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|cl_list_remove_all
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_list
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Return all the list items to the pool. */
name|cl_qpool_put_list
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|,
operator|&
name|p_list
operator|->
name|list
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure from which to remove all objects. * * RETURN VALUE *	This function does not return a value. * * SEE ALSO *	List, cl_list_remove_head, cl_list_remove_tail, cl_list_remove_object, *	cl_list_remove_item *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_remove_object * NAME *	cl_list_remove_object * * DESCRIPTION *	The cl_list_remove_object function removes a specific object from a list. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|cl_list_remove_object
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
specifier|const
name|p_object
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure from which to remove the object. * *	p_object *		[in] Pointer to an object to remove from the list. * * RETURN VALUES *	CL_SUCCESS if the object was removed. * *	CL_NOT_FOUND if the object was not found in the list. * * NOTES *	Removes the first occurrence of an object from a list. * * SEE ALSO *	List, cl_list_remove_item, cl_list_remove_head, cl_list_remove_tail, *	cl_list_remove_all *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_remove_item * NAME *	cl_list_remove_item * * DESCRIPTION *	The cl_list_remove_item function removes an object from the head of a list. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|cl_list_remove_item
parameter_list|(
name|IN
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|,
name|IN
name|cl_list_iterator_t
name|iterator
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_list
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
argument_list|)
expr_stmt|;
name|cl_qlist_remove_item
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|,
operator|(
name|cl_list_item_t
operator|*
operator|)
name|iterator
argument_list|)
expr_stmt|;
comment|/* Place the list item back into the pool. */
name|cl_qpool_put
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|,
operator|(
name|cl_pool_item_t
operator|*
operator|)
name|iterator
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure from which to remove the item. * *	iterator *		[in] cl_list_iterator_t returned by a previous call to cl_list_head, *		cl_list_tail, cl_list_next, or cl_list_prev. * * RETURN VALUE *	This function does not return a value. * * SEE ALSO *	List, cl_list_remove_object, cl_list_remove_head, cl_list_remove_tail, *	cl_list_remove_all *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_is_object_in_list * NAME *	cl_is_object_in_list * * DESCRIPTION *	The cl_is_object_in_list function returns whether an object *	is stored in a list. * * SYNOPSIS */
end_comment

begin_function_decl
name|boolean_t
name|cl_is_object_in_list
parameter_list|(
name|IN
specifier|const
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
specifier|const
name|p_object
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure in which to look for the object. * *	p_object *		[in] Pointer to an object stored in a list. * * RETURN VALUES *	TRUE if p_object was found in the list. * *	FALSE otherwise. * * SEE ALSO *	List *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_end * NAME *	cl_list_end * * DESCRIPTION *	The cl_list_end function returns returns the list iterator for *	the end of a list. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_list_iterator_t
name|cl_list_end
parameter_list|(
name|IN
specifier|const
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_list
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|cl_qlist_end
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure for which the iterator for the *		object at the head is to be returned. * * RETURN VALUE *	cl_list_iterator_t for the end of the list. * * NOTES *	Use cl_list_obj to retrieve the object associated with the *	returned cl_list_iterator_t. * * SEE ALSO *	List, cl_list_head, cl_list_tail, cl_list_next, cl_list_prev, *	cl_list_obj *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_head * NAME *	cl_list_head * * DESCRIPTION *	The cl_list_head function returns returns a list iterator for *	the head of a list. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_list_iterator_t
name|cl_list_head
parameter_list|(
name|IN
specifier|const
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_list
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|cl_qlist_head
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure for which the iterator for the *		object at the head is to be returned. * * RETURN VALUES *	cl_list_iterator_t for the head of the list. * *	cl_list_iterator_t for the end of the list if the list is empty. * * NOTES *	Use cl_list_obj to retrieve the object associated with the *	returned cl_list_iterator_t. * * SEE ALSO *	List, cl_list_tail, cl_list_next, cl_list_prev, cl_list_end, *	cl_list_obj *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_tail * NAME *	cl_list_tail * * DESCRIPTION *	The cl_list_tail function returns returns a list iterator for *	the tail of a list. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_list_iterator_t
name|cl_list_tail
parameter_list|(
name|IN
specifier|const
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_list
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|cl_qlist_tail
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure for which the iterator for the *		object at the tail is to be returned. * * RETURN VALUES *	cl_list_iterator_t for the tail of the list. * *	cl_list_iterator_t for the end of the list if the list is empty. * * NOTES *	Use cl_list_obj to retrieve the object associated with the * *	returned cl_list_iterator_t. * * SEE ALSO *	List, cl_list_head, cl_list_next, cl_list_prev, cl_list_end, *	cl_list_obj *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_next * NAME *	cl_list_next * * DESCRIPTION *	The cl_list_next function returns a list iterator for the object stored *	in a list after the object associated with a given list iterator. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_list_iterator_t
name|cl_list_next
parameter_list|(
name|IN
name|cl_list_iterator_t
name|iterator
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|iterator
argument_list|)
expr_stmt|;
return|return
operator|(
name|cl_qlist_next
argument_list|(
name|iterator
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure for which the iterator for the *		next object is to be returned. * *	iterator *		[in] cl_list_iterator_t returned by a previous call to cl_list_head, *		cl_list_tail, cl_list_next, or cl_list_prev. * * RETURN VALUES *	cl_list_iterator_t for the object following the object associated with *	the list iterator specified by the iterator parameter. * *	cl_list_iterator_t for the end of the list if the list is empty. * * NOTES *	Use cl_list_obj to retrieve the object associated with the *	returned cl_list_iterator_t. * * SEE ALSO *	List, cl_list_prev, cl_list_head, cl_list_tail, cl_list_end, *	cl_list_obj *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_prev * NAME *	cl_list_prev * * DESCRIPTION *	The cl_list_prev function returns a list iterator for the object stored *	in a list before the object associated with a given list iterator. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_list_iterator_t
name|cl_list_prev
parameter_list|(
name|IN
name|cl_list_iterator_t
name|iterator
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|iterator
argument_list|)
expr_stmt|;
return|return
operator|(
name|cl_qlist_prev
argument_list|(
name|iterator
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure for which the iterator for the *		next object is to be returned. * *	iterator *		[in] cl_list_iterator_t returned by a previous call to cl_list_head, *		cl_list_tail, cl_list_next, or cl_list_prev. * * RETURN VALUES *	cl_list_iterator_t for the object preceding the object associated with *	the list iterator specified by the iterator parameter. * *	cl_list_iterator_t for the end of the list if the list is empty. * * NOTES *	Use cl_list_obj to retrieve the object associated with the *	returned cl_list_iterator_t. * * SEE ALSO *	List, cl_list_next, cl_list_head, cl_list_tail, cl_list_end, *	cl_list_obj *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_obj * NAME *	cl_list_obj * * DESCRIPTION *	The cl_list_obj function returns the object associated *	with a list iterator. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|cl_list_obj
parameter_list|(
name|IN
name|cl_list_iterator_t
name|iterator
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|iterator
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|void
operator|*
operator|)
operator|(
operator|(
name|cl_pool_obj_t
operator|*
operator|)
name|iterator
operator|)
operator|->
name|p_object
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	iterator *		[in] cl_list_iterator_t returned by a previous call to cl_list_head, *		cl_list_tail, cl_list_next, or cl_list_prev whose object is requested. * * RETURN VALUE *	Pointer to the object associated with the list iterator specified *	by the iterator parameter. * * SEE ALSO *	List, cl_list_head, cl_list_tail, cl_list_next, cl_list_prev *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_find_from_head * NAME *	cl_list_find_from_head * * DESCRIPTION *	The cl_list_find_from_head function uses a specified function *	to search for an object starting from the head of a list. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_list_iterator_t
name|cl_list_find_from_head
parameter_list|(
name|IN
specifier|const
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|,
name|IN
name|cl_pfn_list_find_t
name|pfn_func
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
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure to search. * *	pfn_func *		[in] Function invoked to determine if a match was found. *		See the cl_pfn_list_find_t function type declaration for details *		about the callback function. * *	context *		[in] Value to pass to the callback functions to provide context. * * RETURN VALUES *	Returns the iterator for the object if found. * *	Returns the iterator for the list end otherwise. * * NOTES *	cl_list_find_from_head does not remove the found object from *	the list.  The iterator for the object is returned when the function *	provided by the pfn_func parameter returns CL_SUCCESS.  The function *	specified by the pfn_func parameter must not perform any list *	operations as these would corrupt the list. * * SEE ALSO *	List, cl_list_find_from_tail, cl_list_apply_func_t, *	cl_pfn_list_find_t *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_find_from_tail * NAME *	cl_list_find_from_tail * * DESCRIPTION *	The cl_list_find_from_tail function uses a specified function *	to search for an object starting from the tail of a list. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_list_iterator_t
name|cl_list_find_from_tail
parameter_list|(
name|IN
specifier|const
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|,
name|IN
name|cl_pfn_list_find_t
name|pfn_func
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
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure to search. * *	pfn_func *		[in] Function invoked to determine if a match was found. *		See the cl_pfn_list_find_t function type declaration for details *		about the callback function. * *	context *		[in] Value to pass to the callback functions to provide context. * * RETURN VALUES *	Returns the iterator for the object if found. * *	Returns the iterator for the list end otherwise. * * NOTES *	cl_list_find_from_tail does not remove the found object from *	the list.  The iterator for the object is returned when the function *	provided by the pfn_func parameter returns CL_SUCCESS.  The function *	specified by the pfn_func parameter must not perform any list *	operations as these would corrupt the list. * * SEE ALSO *	List, cl_list_find_from_head, cl_list_apply_func_t, *	cl_pfn_list_find_t *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_apply_func * NAME *	cl_list_apply_func * * DESCRIPTION *	The cl_list_apply_func function executes a specified function for every *	object stored in a list. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_list_apply_func
parameter_list|(
name|IN
specifier|const
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|,
name|IN
name|cl_pfn_list_apply_t
name|pfn_func
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
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure to iterate. * *	pfn_func *		[in] Function invoked for every item in a list. *		See the cl_pfn_list_apply_t function type declaration for details *		about the callback function. * *	context *		[in] Value to pass to the callback functions to provide context. * * RETURN VALUE *	This function does not return a value. * * NOTES *	cl_list_apply_func invokes the specified callback function for every *	object stored in the list, starting from the head.  The function specified *	by the pfn_func parameter must not perform any list operations as these *	would corrupt the list. * * SEE ALSO *	List, cl_list_find_from_head, cl_list_find_from_tail, *	cl_pfn_list_apply_t *********/
end_comment

begin_comment
comment|/****f* Component Library: List/cl_list_count * NAME *	cl_list_count * * DESCRIPTION *	The cl_list_count function returns the number of objects stored in a list. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|size_t
name|cl_list_count
parameter_list|(
name|IN
specifier|const
name|cl_list_t
modifier|*
specifier|const
name|p_list
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_list
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|cl_is_qpool_inited
argument_list|(
operator|&
name|p_list
operator|->
name|list_item_pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|cl_qlist_count
argument_list|(
operator|&
name|p_list
operator|->
name|list
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_list *		[in] Pointer to a cl_list_t structure whose object to count. * * RETURN VALUES *	Number of objects stored in the specified list. * * SEE ALSO *	List *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_LIST_H_ */
end_comment

end_unit

