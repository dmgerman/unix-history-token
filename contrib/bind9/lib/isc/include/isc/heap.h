begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1997-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: heap.h,v 1.16.206.2 2006/04/17 18:27:20 explorer Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_HEAP_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_HEAP_H
value|1
end_define

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
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
comment|/*%  * The comparision function returns ISC_TRUE if the first argument has  * higher priority than the second argument, and ISC_FALSE otherwise.  */
end_comment

begin_typedef
typedef|typedef
name|isc_boolean_t
function_decl|(
modifier|*
name|isc_heapcompare_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%  * The index function allows the client of the heap to receive a callback  * when an item's index number changes.  This allows it to maintain  * sync with its external state, but still delete itself, since deletions  * from the heap require the index be provided.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_heapindex_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%  * The heapaction function is used when iterating over the heap.  *  * NOTE:  The heap structure CANNOT BE MODIFIED during the call to  * isc_heap_foreach().  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_heapaction_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_heap
name|isc_heap_t
typedef|;
end_typedef

begin_function_decl
name|isc_result_t
name|isc_heap_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_heapcompare_t
name|compare
parameter_list|,
name|isc_heapindex_t
name|index
parameter_list|,
name|unsigned
name|int
name|size_increment
parameter_list|,
name|isc_heap_t
modifier|*
modifier|*
name|heapp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Create a new heap.  The heap is implemented using a space-efficient  * storage method.  When the heap elements are deleted space is not freed  * but will be reused when new elements are inserted.  *  * Requires:  *\li	"mctx" is valid.  *\li	"compare" is a function which takes two void * arguments and  *	returns ISC_TRUE if the first argument has a higher priority than  *	the second, and ISC_FALSE otherwise.  *\li	"index" is a function which takes a void *, and an unsigned int  *	argument.  This function will be called whenever an element's  *	index value changes, so it may continue to delete itself from the  *	heap.  This option may be NULL if this functionality is unneeded.  *\li	"size_increment" is a hint about how large the heap should grow  *	when resizing is needed.  If this is 0, a default size will be  *	used, which is currently 1024, allowing space for an additional 1024  *	heap elements to be inserted before adding more space.  *\li	"heapp" is not NULL, and "*heap" is NULL.  *  * Returns:  *\li	ISC_R_SUCCESS		- success  *\li	ISC_R_NOMEMORY		- insufficient memory  */
end_comment

begin_function_decl
name|void
name|isc_heap_destroy
parameter_list|(
name|isc_heap_t
modifier|*
modifier|*
name|heapp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Destroys a heap.  *  * Requires:  *\li	"heapp" is not NULL and "*heap" points to a valid isc_heap_t.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_heap_insert
parameter_list|(
name|isc_heap_t
modifier|*
name|heap
parameter_list|,
name|void
modifier|*
name|elt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Inserts a new element into a heap.  *  * Requires:  *\li	"heapp" is not NULL and "*heap" points to a valid isc_heap_t.  */
end_comment

begin_function_decl
name|void
name|isc_heap_delete
parameter_list|(
name|isc_heap_t
modifier|*
name|heap
parameter_list|,
name|unsigned
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Deletes an element from a heap, by element index.  *  * Requires:  *\li	"heapp" is not NULL and "*heap" points to a valid isc_heap_t.  *\li	"index" is a valid element index, as provided by the "index" callback  *	provided during heap creation.  */
end_comment

begin_function_decl
name|void
name|isc_heap_increased
parameter_list|(
name|isc_heap_t
modifier|*
name|heap
parameter_list|,
name|unsigned
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Indicates to the heap that an element's priority has increased.  * This function MUST be called whenever an element has increased in priority.  *  * Requires:  *\li	"heapp" is not NULL and "*heap" points to a valid isc_heap_t.  *\li	"index" is a valid element index, as provided by the "index" callback  *	provided during heap creation.  */
end_comment

begin_function_decl
name|void
name|isc_heap_decreased
parameter_list|(
name|isc_heap_t
modifier|*
name|heap
parameter_list|,
name|unsigned
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Indicates to the heap that an element's priority has decreased.  * This function MUST be called whenever an element has decreased in priority.  *  * Requires:  *\li	"heapp" is not NULL and "*heap" points to a valid isc_heap_t.  *\li	"index" is a valid element index, as provided by the "index" callback  *	provided during heap creation.  */
end_comment

begin_function_decl
name|void
modifier|*
name|isc_heap_element
parameter_list|(
name|isc_heap_t
modifier|*
name|heap
parameter_list|,
name|unsigned
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Returns the element for a specific element index.  *  * Requires:  *\li	"heapp" is not NULL and "*heap" points to a valid isc_heap_t.  *\li	"index" is a valid element index, as provided by the "index" callback  *	provided during heap creation.  *  * Returns:  *\li	A pointer to the element for the element index.  */
end_comment

begin_function_decl
name|void
name|isc_heap_foreach
parameter_list|(
name|isc_heap_t
modifier|*
name|heap
parameter_list|,
name|isc_heapaction_t
name|action
parameter_list|,
name|void
modifier|*
name|uap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Iterate over the heap, calling an action for each element.  The  * order of iteration is not sorted.  *  * Requires:  *\li	"heapp" is not NULL and "*heap" points to a valid isc_heap_t.  *\li	"action" is not NULL, and is a function which takes two arguments.  *	The first is a void *, representing the element, and the second is  *	"uap" as provided to isc_heap_foreach.  *\li	"uap" is a caller-provided argument, and may be NULL.  *  * Note:  *\li	The heap structure CANNOT be modified during this iteration.  The only  *	safe function to call while iterating the heap is isc_heap_element().  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_HEAP_H */
end_comment

end_unit

