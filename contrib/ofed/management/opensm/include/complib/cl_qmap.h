begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Declaration of quick map, a binary tree where the caller always provides  *	all necessary storage.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_QMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_QMAP_H_
end_define

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
comment|/****h* Component Library/Quick Map * NAME *	Quick Map * * DESCRIPTION *	Quick map implements a binary tree that stores user provided cl_map_item_t *	structures.  Each item stored in a quick map has a unique 64-bit key *	(duplicates are not allowed).  Quick map provides the ability to *	efficiently search for an item given a key. * *	Quick map does not allocate any memory, and can therefore not fail *	any operations due to insufficient memory.  Quick map can thus be useful *	in minimizing the error paths in code. * *	Quick map is not thread safe, and users must provide serialization when *	adding and removing items from the map. * *	The quick map functions operate on a cl_qmap_t structure which should be *	treated as opaque and should be manipulated only through the provided *	functions. * * SEE ALSO *	Structures: *		cl_qmap_t, cl_map_item_t, cl_map_obj_t * *	Callbacks: *		cl_pfn_qmap_apply_t * *	Item Manipulation: *		cl_qmap_set_obj, cl_qmap_obj, cl_qmap_key * *	Initialization: *		cl_qmap_init * *	Iteration: *		cl_qmap_end, cl_qmap_head, cl_qmap_tail, cl_qmap_next, cl_qmap_prev * *	Manipulation: *		cl_qmap_insert, cl_qmap_get, cl_qmap_remove_item, cl_qmap_remove, *		cl_qmap_remove_all, cl_qmap_merge, cl_qmap_delta, cl_qmap_get_next * *	Search: *		cl_qmap_apply_func * *	Attributes: *		cl_qmap_count, cl_is_qmap_empty, *********/
end_comment

begin_comment
comment|/****i* Component Library: Quick Map/cl_map_color_t * NAME *	cl_map_color_t * * DESCRIPTION *	The cl_map_color_t enumerated type is used to note the color of *	nodes in a map. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_cl_map_color
block|{
name|CL_MAP_RED
block|,
name|CL_MAP_BLACK
block|}
name|cl_map_color_t
typedef|;
end_typedef

begin_comment
comment|/* * VALUES *	CL_MAP_RED *		The node in the map is red. * *	CL_MAP_BLACK *		The node in the map is black. * * SEE ALSO *	Quick Map, cl_map_item_t *********/
end_comment

begin_comment
comment|/****s* Component Library: Quick Map/cl_map_item_t * NAME *	cl_map_item_t * * DESCRIPTION *	The cl_map_item_t structure is used by maps to store objects. * *	The cl_map_item_t structure should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_map_item
block|{
comment|/* Must be first to allow casting. */
name|cl_pool_item_t
name|pool_item
decl_stmt|;
name|struct
name|_cl_map_item
modifier|*
name|p_left
decl_stmt|;
name|struct
name|_cl_map_item
modifier|*
name|p_right
decl_stmt|;
name|struct
name|_cl_map_item
modifier|*
name|p_up
decl_stmt|;
name|cl_map_color_t
name|color
decl_stmt|;
name|uint64_t
name|key
decl_stmt|;
ifdef|#
directive|ifdef
name|_DEBUG_
name|struct
name|_cl_qmap
modifier|*
name|p_map
decl_stmt|;
endif|#
directive|endif
block|}
name|cl_map_item_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	pool_item *		Used to store the item in a doubly linked list, allowing more *		efficient map traversal. * *	p_left *		Pointer to the map item that is a child to the left of the node. * *	p_right *		Pointer to the map item that is a child to the right of the node. * *	p_up *		Pointer to the map item that is the parent of the node. * *	p_nil *		Pointer to the map's NIL item, used as a terminator for leaves. *		The NIL sentinel is in the cl_qmap_t structure. * *	color *		Indicates whether a node is red or black in the map. * *	key *		Value that uniquely represents a node in a map.  This value is *		set by calling cl_qmap_insert and can be retrieved by calling *		cl_qmap_key. * * NOTES *	None of the fields of this structure should be manipulated by users, as *	they are crititcal to the proper operation of the map in which they *	are stored. * *	To allow storing items in either a quick list, a quick pool, or a quick *	map, the map implementation guarantees that the map item can be safely *	cast to a pool item used for storing an object in a quick pool, or cast *	to a list item used for storing an object in a quick list.  This removes *	the need to embed a map item, a list item, and a pool item in objects *	that need to be stored in a quick list, a quick pool, and a quick map. * * SEE ALSO *	Quick Map, cl_qmap_insert, cl_qmap_key, cl_pool_item_t, cl_list_item_t *********/
end_comment

begin_comment
comment|/****s* Component Library: Quick Map/cl_map_obj_t * NAME *	cl_map_obj_t * * DESCRIPTION *	The cl_map_obj_t structure is used to store objects in maps. * *	The cl_map_obj_t structure should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_map_obj
block|{
name|cl_map_item_t
name|item
decl_stmt|;
specifier|const
name|void
modifier|*
name|p_object
decl_stmt|;
block|}
name|cl_map_obj_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	item *		Map item used by internally by the map to store an object. * *	p_object *		User defined context. Users should not access this field directly. *		Use cl_qmap_set_obj and cl_qmap_obj to set and retrieve the value *		of this field. * * NOTES *	None of the fields of this structure should be manipulated by users, as *	they are crititcal to the proper operation of the map in which they *	are stored. * *	Use cl_qmap_set_obj and cl_qmap_obj to set and retrieve the object *	stored in a map item, respectively. * * SEE ALSO *	Quick Map, cl_qmap_set_obj, cl_qmap_obj, cl_map_item_t *********/
end_comment

begin_comment
comment|/****s* Component Library: Quick Map/cl_qmap_t * NAME *	cl_qmap_t * * DESCRIPTION *	Quick map structure. * *	The cl_qmap_t structure should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cl_qmap
block|{
name|cl_map_item_t
name|root
decl_stmt|;
name|cl_map_item_t
name|nil
decl_stmt|;
name|cl_state_t
name|state
decl_stmt|;
name|size_t
name|count
decl_stmt|;
block|}
name|cl_qmap_t
typedef|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	root *		Map item that serves as root of the map.  The root is set up to *		always have itself as parent.  The left pointer is set to point *		to the item at the root. * *	nil *		Map item that serves as terminator for all leaves, as well as *		providing the list item used as quick list for storing map items *		in a list for faster traversal. * *	state *		State of the map, used to verify that operations are permitted. * *	count *		Number of items in the map. * * SEE ALSO *	Quick Map *********/
end_comment

begin_comment
comment|/****d* Component Library: Quick Map/cl_pfn_qmap_apply_t * NAME *	cl_pfn_qmap_apply_t * * DESCRIPTION *	The cl_pfn_qmap_apply_t function type defines the prototype for *	functions used to iterate items in a quick map. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cl_pfn_qmap_apply_t
function_decl|)
parameter_list|(
name|IN
name|cl_map_item_t
modifier|*
specifier|const
name|p_map_item
parameter_list|,
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	p_map_item *		[in] Pointer to a cl_map_item_t structure. * *	context *		[in] Value passed to the callback function. * * RETURN VALUE *	This function does not return a value. * * NOTES *	This function type is provided as function prototype reference for the *	function provided by users as a parameter to the cl_qmap_apply_func *	function. * * SEE ALSO *	Quick Map, cl_qmap_apply_func *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_count * NAME *	cl_qmap_count * * DESCRIPTION *	The cl_qmap_count function returns the number of items stored *	in a quick map. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|cl_qmap_count
parameter_list|(
name|IN
specifier|const
name|cl_qmap_t
modifier|*
specifier|const
name|p_map
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_map
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_map
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
name|p_map
operator|->
name|count
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_map *		[in] Pointer to a cl_qmap_t structure whose item count to return. * * RETURN VALUE *	Returns the number of items stored in the map. * * SEE ALSO *	Quick Map, cl_is_qmap_empty *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_is_qmap_empty * NAME *	cl_is_qmap_empty * * DESCRIPTION *	The cl_is_qmap_empty function returns whether a quick map is empty. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|cl_is_qmap_empty
parameter_list|(
name|IN
specifier|const
name|cl_qmap_t
modifier|*
specifier|const
name|p_map
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_map
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_map
operator|->
name|state
operator|==
name|CL_INITIALIZED
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_map
operator|->
name|count
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_map *		[in] Pointer to a cl_qmap_t structure to test for emptiness. * * RETURN VALUES *	TRUE if the quick map is empty. * *	FALSE otherwise. * * SEE ALSO *	Quick Map, cl_qmap_count, cl_qmap_remove_all *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_set_obj * NAME *	cl_qmap_set_obj * * DESCRIPTION *	The cl_qmap_set_obj function sets the object stored in a map object. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|cl_qmap_set_obj
parameter_list|(
name|IN
name|cl_map_obj_t
modifier|*
specifier|const
name|p_map_obj
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
specifier|const
name|p_object
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_map_obj
argument_list|)
expr_stmt|;
name|p_map_obj
operator|->
name|p_object
operator|=
name|p_object
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_map_obj *		[in] Pointer to a map object stucture whose object pointer *		is to be set. * *	p_object *		[in] User defined context. * * RETURN VALUE *	This function does not return a value. * * SEE ALSO *	Quick Map, cl_qmap_obj *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_obj * NAME *	cl_qmap_obj * * DESCRIPTION *	The cl_qmap_obj function returns the object stored in a map object. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|cl_qmap_obj
parameter_list|(
name|IN
specifier|const
name|cl_map_obj_t
modifier|*
specifier|const
name|p_map_obj
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_map_obj
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|void
operator|*
operator|)
name|p_map_obj
operator|->
name|p_object
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_map_obj *		[in] Pointer to a map object stucture whose object pointer to return. * * RETURN VALUE *	Returns the value of the object pointer stored in the map object. * * SEE ALSO *	Quick Map, cl_qmap_set_obj *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_key * NAME *	cl_qmap_key * * DESCRIPTION *	The cl_qmap_key function retrieves the key value of a map item. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint64_t
name|cl_qmap_key
parameter_list|(
name|IN
specifier|const
name|cl_map_item_t
modifier|*
specifier|const
name|p_item
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_item
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_item
operator|->
name|key
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_item *		[in] Pointer to a map item whose key value to return. * * RETURN VALUE *	Returns the 64-bit key value for the specified map item. * * NOTES *	The key value is set in a call to cl_qmap_insert. * * SEE ALSO *	Quick Map, cl_qmap_insert *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_init * NAME *	cl_qmap_init * * DESCRIPTION *	The cl_qmap_init function initialized a quick map for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_qmap_init
parameter_list|(
name|IN
name|cl_qmap_t
modifier|*
specifier|const
name|p_map
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_map *		[in] Pointer to a cl_qmap_t structure to initialize. * * RETURN VALUES *	This function does not return a value. * * NOTES *	Allows calling quick map manipulation functions. * * SEE ALSO *	Quick Map, cl_qmap_insert, cl_qmap_remove *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_end * NAME *	cl_qmap_end * * DESCRIPTION *	The cl_qmap_end function returns the end of a quick map. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|cl_map_item_t
modifier|*
name|cl_qmap_end
parameter_list|(
name|IN
specifier|const
name|cl_qmap_t
modifier|*
specifier|const
name|p_map
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_map
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_map
operator|->
name|state
operator|==
name|CL_INITIALIZED
argument_list|)
expr_stmt|;
comment|/* Nil is the end of the map. */
return|return
operator|(
operator|&
name|p_map
operator|->
name|nil
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_map *		[in] Pointer to a cl_qmap_t structure whose end to return. * * RETURN VALUE *	Pointer to the end of the map. * * NOTES *	cl_qmap_end is useful for determining the validity of map items returned *	by cl_qmap_head, cl_qmap_tail, cl_qmap_next, or cl_qmap_prev.  If the *	map item pointer returned by any of these functions compares to the end, *	the end of the map was encoutered. *	When using cl_qmap_head or cl_qmap_tail, this condition indicates that *	the map is empty. * * SEE ALSO *	Quick Map, cl_qmap_head, cl_qmap_tail, cl_qmap_next, cl_qmap_prev *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_head * NAME *	cl_qmap_head * * DESCRIPTION *	The cl_qmap_head function returns the map item with the lowest key *	value stored in a quick map. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_map_item_t
modifier|*
name|cl_qmap_head
parameter_list|(
name|IN
specifier|const
name|cl_qmap_t
modifier|*
specifier|const
name|p_map
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_map
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_map
operator|->
name|state
operator|==
name|CL_INITIALIZED
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|cl_map_item_t
operator|*
operator|)
name|p_map
operator|->
name|nil
operator|.
name|pool_item
operator|.
name|list_item
operator|.
name|p_next
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_map *		[in] Pointer to a cl_qmap_t structure whose item with the lowest *		key is returned. * * RETURN VALUES *	Pointer to the map item with the lowest key in the quick map. * *	Pointer to the map end if the quick map was empty. * * NOTES *	cl_qmap_head does not remove the item from the map. * * SEE ALSO *	Quick Map, cl_qmap_tail, cl_qmap_next, cl_qmap_prev, cl_qmap_end, *	cl_qmap_item_t *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_tail * NAME *	cl_qmap_tail * * DESCRIPTION *	The cl_qmap_tail function returns the map item with the highest key *	value stored in a quick map. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_map_item_t
modifier|*
name|cl_qmap_tail
parameter_list|(
name|IN
specifier|const
name|cl_qmap_t
modifier|*
specifier|const
name|p_map
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_map
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_map
operator|->
name|state
operator|==
name|CL_INITIALIZED
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|cl_map_item_t
operator|*
operator|)
name|p_map
operator|->
name|nil
operator|.
name|pool_item
operator|.
name|list_item
operator|.
name|p_prev
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_map *		[in] Pointer to a cl_qmap_t structure whose item with the *		highest key is returned. * * RETURN VALUES *	Pointer to the map item with the highest key in the quick map. * *	Pointer to the map end if the quick map was empty. * * NOTES *	cl_qmap_end does not remove the item from the map. * * SEE ALSO *	Quick Map, cl_qmap_head, cl_qmap_next, cl_qmap_prev, cl_qmap_end, *	cl_qmap_item_t *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_next * NAME *	cl_qmap_next * * DESCRIPTION *	The cl_qmap_next function returns the map item with the next higher *	key value than a specified map item. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_map_item_t
modifier|*
name|cl_qmap_next
parameter_list|(
name|IN
specifier|const
name|cl_map_item_t
modifier|*
specifier|const
name|p_item
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_item
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|cl_map_item_t
operator|*
operator|)
name|p_item
operator|->
name|pool_item
operator|.
name|list_item
operator|.
name|p_next
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_item *		[in] Pointer to a map item whose successor to return. * * RETURN VALUES *	Pointer to the map item with the next higher key value in a quick map. * *	Pointer to the map end if the specified item was the last item in *	the quick map. * * SEE ALSO *	Quick Map, cl_qmap_head, cl_qmap_tail, cl_qmap_prev, cl_qmap_end, *	cl_map_item_t *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_prev * NAME *	cl_qmap_prev * * DESCRIPTION *	The cl_qmap_prev function returns the map item with the next lower *	key value than a precified map item. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_map_item_t
modifier|*
name|cl_qmap_prev
parameter_list|(
name|IN
specifier|const
name|cl_map_item_t
modifier|*
specifier|const
name|p_item
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_item
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|cl_map_item_t
operator|*
operator|)
name|p_item
operator|->
name|pool_item
operator|.
name|list_item
operator|.
name|p_prev
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_item *		[in] Pointer to a map item whose predecessor to return. * * RETURN VALUES *	Pointer to the map item with the next lower key value in a quick map. * *	Pointer to the map end if the specifid item was the first item in *	the quick map. * * SEE ALSO *	Quick Map, cl_qmap_head, cl_qmap_tail, cl_qmap_next, cl_qmap_end, *	cl_map_item_t *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_insert * NAME *	cl_qmap_insert * * DESCRIPTION *	The cl_qmap_insert function inserts a map item into a quick map. *  NOTE: Only if such a key does not alerady exist in the map !!!! * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_map_item_t
modifier|*
name|cl_qmap_insert
parameter_list|(
name|IN
name|cl_qmap_t
modifier|*
specifier|const
name|p_map
parameter_list|,
name|IN
specifier|const
name|uint64_t
name|key
parameter_list|,
name|IN
name|cl_map_item_t
modifier|*
specifier|const
name|p_item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_map *		[in] Pointer to a cl_qmap_t structure into which to add the item. * *	key *		[in] Value to assign to the item. * *	p_item *		[in] Pointer to a cl_map_item_t stucture to insert into the quick map. * * RETURN VALUE *	Pointer to the item in the map with the specified key.  If insertion *	was successful, this is the pointer to the item.  If an item with the *	specified key already exists in the map, the pointer to that item is *	returned - but the new key is NOT inserted... * * NOTES *	Insertion operations may cause the quick map to rebalance. * * SEE ALSO *	Quick Map, cl_qmap_remove, cl_map_item_t *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_get * NAME *	cl_qmap_get * * DESCRIPTION *	The cl_qmap_get function returns the map item associated with a key. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_map_item_t
modifier|*
name|cl_qmap_get
parameter_list|(
name|IN
specifier|const
name|cl_qmap_t
modifier|*
specifier|const
name|p_map
parameter_list|,
name|IN
specifier|const
name|uint64_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_map *		[in] Pointer to a cl_qmap_t structure from which to retrieve the *		item with the specified key. * *	key *		[in] Key value used to search for the desired map item. * * RETURN VALUES *	Pointer to the map item with the desired key value. * *	Pointer to the map end if there was no item with the desired key value *	stored in the quick map. * * NOTES *	cl_qmap_get does not remove the item from the quick map. * * SEE ALSO *	Quick Map, cl_qmap_get_next, cl_qmap_remove *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_get_next * NAME *	cl_qmap_get_next * * DESCRIPTION *	The cl_qmap_get_next function returns the first map item associated with a *	key> the key specified. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_map_item_t
modifier|*
name|cl_qmap_get_next
parameter_list|(
name|IN
specifier|const
name|cl_qmap_t
modifier|*
specifier|const
name|p_map
parameter_list|,
name|IN
specifier|const
name|uint64_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_map *		[in] Pointer to a cl_qmap_t structure from which to retrieve the *		first item with a key> the specified key. * *	key *		[in] Key value used to search for the desired map item. * * RETURN VALUES *	Pointer to the first map item with a key> the desired key value. * *	Pointer to the map end if there was no item with a key> the desired key *	value stored in the quick map. * * NOTES *	cl_qmap_get_next does not remove the item from the quick map. * * SEE ALSO *	Quick Map, cl_qmap_get, cl_qmap_remove *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_remove_item * NAME *	cl_qmap_remove_item * * DESCRIPTION *	The cl_qmap_remove_item function removes the specified map item *	from a quick map. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_qmap_remove_item
parameter_list|(
name|IN
name|cl_qmap_t
modifier|*
specifier|const
name|p_map
parameter_list|,
name|IN
name|cl_map_item_t
modifier|*
specifier|const
name|p_item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_item *		[in] Pointer to a map item to remove from its quick map. * * RETURN VALUES *	This function does not return a value. * *	In a debug build, cl_qmap_remove_item asserts that the item being removed *	is in the specified map. * * NOTES *	Removes the map item pointed to by p_item from its quick map. * * SEE ALSO *	Quick Map, cl_qmap_remove, cl_qmap_remove_all, cl_qmap_insert *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_remove * NAME *	cl_qmap_remove * * DESCRIPTION *	The cl_qmap_remove function removes the map item with the specified key *	from a quick map. * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_map_item_t
modifier|*
name|cl_qmap_remove
parameter_list|(
name|IN
name|cl_qmap_t
modifier|*
specifier|const
name|p_map
parameter_list|,
name|IN
specifier|const
name|uint64_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_map *		[in] Pointer to a cl_qmap_t structure from which to remove the item *		with the specified key. * *	key *		[in] Key value used to search for the map item to remove. * * RETURN VALUES *	Pointer to the removed map item if it was found. * *	Pointer to the map end if no item with the specified key exists in the *	quick map. * * SEE ALSO *	Quick Map, cl_qmap_remove_item, cl_qmap_remove_all, cl_qmap_insert *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_remove_all * NAME *	cl_qmap_remove_all * * DESCRIPTION *	The cl_qmap_remove_all function removes all items in a quick map, *	leaving it empty. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|cl_qmap_remove_all
parameter_list|(
name|IN
name|cl_qmap_t
modifier|*
specifier|const
name|p_map
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_map
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_map
operator|->
name|state
operator|==
name|CL_INITIALIZED
argument_list|)
expr_stmt|;
name|p_map
operator|->
name|root
operator|.
name|p_left
operator|=
operator|&
name|p_map
operator|->
name|nil
expr_stmt|;
name|p_map
operator|->
name|nil
operator|.
name|pool_item
operator|.
name|list_item
operator|.
name|p_next
operator|=
operator|&
name|p_map
operator|->
name|nil
operator|.
name|pool_item
operator|.
name|list_item
expr_stmt|;
name|p_map
operator|->
name|nil
operator|.
name|pool_item
operator|.
name|list_item
operator|.
name|p_prev
operator|=
operator|&
name|p_map
operator|->
name|nil
operator|.
name|pool_item
operator|.
name|list_item
expr_stmt|;
name|p_map
operator|->
name|count
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_map *		[in] Pointer to a cl_qmap_t structure to empty. * * RETURN VALUES *	This function does not return a value. * * SEE ALSO *	Quick Map, cl_qmap_remove, cl_qmap_remove_item *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_merge * NAME *	cl_qmap_merge * * DESCRIPTION *	The cl_qmap_merge function moves all items from one map to another, *	excluding duplicates. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_qmap_merge
parameter_list|(
name|OUT
name|cl_qmap_t
modifier|*
specifier|const
name|p_dest_map
parameter_list|,
name|IN
name|OUT
name|cl_qmap_t
modifier|*
specifier|const
name|p_src_map
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_dest_map *		[out] Pointer to a cl_qmap_t structure to which items should be added. * *	p_src_map *		[in/out] Pointer to a cl_qmap_t structure whose items to add *		to p_dest_map. * * RETURN VALUES *	This function does not return a value. * * NOTES *	Items are evaluated based on their keys only. * *	Upon return from cl_qmap_merge, the quick map referenced by p_src_map *	contains all duplicate items. * * SEE ALSO *	Quick Map, cl_qmap_delta *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_delta * NAME *	cl_qmap_delta * * DESCRIPTION *	The cl_qmap_delta function computes the differences between two maps. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_qmap_delta
parameter_list|(
name|IN
name|OUT
name|cl_qmap_t
modifier|*
specifier|const
name|p_map1
parameter_list|,
name|IN
name|OUT
name|cl_qmap_t
modifier|*
specifier|const
name|p_map2
parameter_list|,
name|OUT
name|cl_qmap_t
modifier|*
specifier|const
name|p_new
parameter_list|,
name|OUT
name|cl_qmap_t
modifier|*
specifier|const
name|p_old
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_map1 *		[in/out] Pointer to the first of two cl_qmap_t structures whose *		differences to compute. * *	p_map2 *		[in/out] Pointer to the second of two cl_qmap_t structures whose *		differences to compute. * *	p_new *		[out] Pointer to an empty cl_qmap_t structure that contains the *		items unique to p_map2 upon return from the function. * *	p_old *		[out] Pointer to an empty cl_qmap_t structure that contains the *		items unique to p_map1 upon return from the function. * * RETURN VALUES *	This function does not return a value. * * NOTES *	Items are evaluated based on their keys.  Items that exist in both *	p_map1 and p_map2 remain in their respective maps.  Items that *	exist only p_map1 are moved to p_old.  Likewise, items that exist only *	in p_map2 are moved to p_new.  This function can be useful in evaluating *	changes between two maps. * *	Both maps pointed to by p_new and p_old must be empty on input.  This *	requirement removes the possibility of failures. * * SEE ALSO *	Quick Map, cl_qmap_merge *********/
end_comment

begin_comment
comment|/****f* Component Library: Quick Map/cl_qmap_apply_func * NAME *	cl_qmap_apply_func * * DESCRIPTION *	The cl_qmap_apply_func function executes a specified function *	for every item stored in a quick map. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|cl_qmap_apply_func
parameter_list|(
name|IN
specifier|const
name|cl_qmap_t
modifier|*
specifier|const
name|p_map
parameter_list|,
name|IN
name|cl_pfn_qmap_apply_t
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
comment|/* * PARAMETERS *	p_map *		[in] Pointer to a cl_qmap_t structure. * *	pfn_func *		[in] Function invoked for every item in the quick map. *		See the cl_pfn_qmap_apply_t function type declaration for *		details about the callback function. * *	context *		[in] Value to pass to the callback functions to provide context. * * RETURN VALUE *	This function does not return a value. * * NOTES *	The function provided must not perform any map operations, as these *	would corrupt the quick map. * * SEE ALSO *	Quick Map, cl_pfn_qmap_apply_t *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_QMAP_H_ */
end_comment

end_unit

