begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  *  * Define an Alist, a list maintained as a reallocable array, and a for() loop  * macro to generalize its traversal.  Note that the array can be reallocated  * as it is being traversed, thus the offset of each element is recomputed from  * the start of the structure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIST_H
end_ifndef

begin_define
define|#
directive|define
name|_ALIST_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<sys/types.h>
ifdef|#
directive|ifdef
name|illumos
include|#
directive|include
file|<sys/machelf.h>
else|#
directive|else
include|#
directive|include
file|<sys/elf.h>
endif|#
directive|endif
comment|/*  * An Alist implements array lists. The functionality is similar to  * that of a linked list. However, an Alist is represented by a single  * contigious allocation of memory. The head of the memory is a header  * that contains control information for the list. Following the header  * is an array used to hold the user data. In the type definitions that  * follow, we define these as an array with a single element, but when  * we allocate the memory, we actually allocate the amount of memory needed.  *  * There are two "flavors" of array list:  *  *	Alist - Contain arbitrary data, usually structs.  *	APlist - Contain pointers to data allocated elsewhere.  *  * This differentiation is useful, because pointer lists are heavily  * used, and support a slightly different set of operations that are  * unique to their purpose.  *  * Array lists are initially represented by a NULL pointer. The memory  * for the list is only allocated if an item is inserted. This is very  * efficient for data structures that may or may not be needed for a  * given linker operation --- you only pay for what you use. In addition:  *  *	- Array lists grow as needed (memory is reallocated as necessary)  *	- Data is kept contiguously (no unused holes in between elements)  *		at the beginning of the data area. This locality has  *		good cache behavior, as access to adjacent items are  *		highly likely to be in the same page of memory.  *	- Insert/Delete operations at the end of the list are very  *		efficient. However, insert/delete operations elsewhere  *		will cause a relatively expensive overlapped memory  *		copy of the data following the insert/delete location.  *	- As with any generic memory alloctor (i.e. malloc()/free()),  *		array lists are not type safe for the data they contain.  *		Data is managed as (void *) pointers to data of a given  *		length, so the Alist module cannot prevent the caller from  *		inserting/extracting the wrong type of data. The caller  *		must guard against this.  *	- To free an array list, simply call the standard free() function  *		on the list pointer.  */
comment|/*  * Aliste is used to represent list indexes, offsets, and sizes.  */
typedef|typedef
name|size_t
name|Aliste
typedef|;
comment|/*  * Alist is used to hold non-pointer items --- usually structs:  *	- There must be an even number of Aliste fields before the  *		al_data field. This ensures that al_data will have  *		an alignment of 8, no matter whether sizeof(Aliste)  *		is 4 or 8. That means that al_data will have sufficient  *		alignment for any use, just like memory allocated via  *		malloc().  *	- al_nitems and al_next are redundant, in that they are  *		directly related:  *			al_next = al_nitems * al_size  *		We do this to make ALIST_TRAVERSE_BYOFFSET maximally  *		efficient. This doesn't waste space, because of the  *		requirement to have an even # of Alist fields (above).  *  * Note that Alists allow the data to be referenced by 0 based array  * index, or by their byte offset from the start of the Alist memory  * allocation. The index form is preferred for most use, as it is simpler.  * However, by-offset access is used by rtld link maps, and this ability  * is convenient in that case.  */
typedef|typedef
struct|struct
block|{
name|Aliste
name|al_arritems
decl_stmt|;
comment|/* # of items in al_data allocation */
name|Aliste
name|al_nitems
decl_stmt|;
comment|/* # items (index of next avail item) */
name|Aliste
name|al_next
decl_stmt|;
comment|/* offset of next available al_data[] */
name|Aliste
name|al_size
decl_stmt|;
comment|/* size of each al_data[] item */
name|void
modifier|*
name|al_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* data (can grow) */
block|}
name|Alist
typedef|;
comment|/*  * APlist is a variant of Alist that contains pointers. There are several  * benefits to this special type:  *	- API is simpler  *	- Pointers are used directly, instead of requiring a  *		pointer-to-pointer double indirection.  *	- The implementation is slightly more efficient.  *	- Operations that make particular sense for pointers  *		can be supported without confusing the API for the  *		regular Alists.  */
typedef|typedef
struct|struct
block|{
name|Aliste
name|apl_arritems
decl_stmt|;
comment|/* # of items in apl_data allocation */
name|Aliste
name|apl_nitems
decl_stmt|;
comment|/* # items (index of next avail item) */
name|void
modifier|*
name|apl_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* data area: (arrcnt * size) bytes */
block|}
name|APlist
typedef|;
comment|/*  * The ALIST_OFF_DATA and APLIST_OFF_DATA macros give the byte offset  * from the start of an array list to the first byte of the data area  * used to hold user data. The same trick used by the standard offsetof()  * macro is used.  */
define|#
directive|define
name|ALIST_OFF_DATA
value|((size_t)(((Alist *)0)->al_data))
define|#
directive|define
name|APLIST_OFF_DATA
value|((size_t)(((APlist *)0)->apl_data))
comment|/*  * The TRAVERSE macros are intended to be used within a for(), and  * cause the resulting loop to iterate over each item in the loop,  * in order.  *	ALIST_TRAVERSE: Traverse over the items in an Alist,  *		using the zero based item array index to refer to  *		each item.  *	ALIST_TRAVERSE_BY_OFFSET: Traverse over the items in an  *		Alist using the byte offset from the head of the  *		Alist pointer to refer to each item. It should be noted  *		that the first such offset is given by ALIST_OFF_DATA,  *		and as such, there will never be a 0 offset. Some code  *		uses this fact to treat 0 as a reserved value with  *		special meaning.  *  *		By-offset access is convenient for some parts of  *		rtld, where a value of 0 is used to indicate an  *		uninitialized link map control.  *  *	APLIST_TRAVERSE: Traverse over the pointers in an APlist, using  *		the zero based item array index to refer to each pointer.  */
comment|/*  * Within the loop:  *  *	LIST - Pointer to Alist structure for list  *	IDX - The current item index  *	OFF - The current item offset  *	DATA - Pointer to item  */
define|#
directive|define
name|ALIST_TRAVERSE
parameter_list|(
name|LIST
parameter_list|,
name|IDX
parameter_list|,
name|DATA
parameter_list|)
define|\
value|(IDX) = 0, \ 	((LIST) != NULL)&& ((DATA) = (void *)(LIST)->al_data); \ 	\ 	((LIST) != NULL)&& ((IDX)< (LIST)->al_nitems); \ 	\ 	(IDX)++, \ 	(DATA) = (void *) (((LIST)->al_size * (IDX)) + (char *)(LIST)->al_data)
define|#
directive|define
name|ALIST_TRAVERSE_BY_OFFSET
parameter_list|(
name|LIST
parameter_list|,
name|OFF
parameter_list|,
name|DATA
parameter_list|)
define|\
value|(((LIST) != NULL)&& ((OFF) = ALIST_OFF_DATA)&& \ 	(((DATA) = (void *)((char *)(LIST) + (OFF))))); \ 	\ 	(((LIST) != NULL)&& ((OFF)< (LIST)->al_next)); \ 	\ 	(((OFF) += ((LIST)->al_size)), \ 	((DATA) = (void *)((char *)(LIST) + (OFF))))
comment|/*  * Within the loop:  *  *	LIST - Pointer to APlist structure for list  *	IDX - The current item index  *	PTR - item value  *  * Note that this macro is designed to ensure that PTR retains the  * value of the final pointer in the list after exiting the for loop,  * and to avoid dereferencing an out of range address. This is done by  * doing the dereference in the middle expression, using the comma  * operator to ensure that a NULL pointer won't stop the loop.  */
define|#
directive|define
name|APLIST_TRAVERSE
parameter_list|(
name|LIST
parameter_list|,
name|IDX
parameter_list|,
name|PTR
parameter_list|)
define|\
value|(IDX) = 0; \ 	\ 	((LIST) != NULL)&& ((IDX)< (LIST)->apl_nitems)&& \ 	(((PTR) = ((LIST)->apl_data)[IDX]), 1); \ 	\ 	(IDX)++
comment|/*  * Possible values returned by aplist_test()  */
typedef|typedef
enum|enum
block|{
name|ALE_ALLOCFAIL
init|=
literal|0
block|,
comment|/* Memory allocation error */
name|ALE_EXISTS
init|=
literal|1
block|,
comment|/* alist entry already exists */
name|ALE_NOTFND
init|=
literal|2
block|,
comment|/* item not found and insert not required */
name|ALE_CREATE
init|=
literal|3
comment|/* alist entry created */
block|}
name|aplist_test_t
typedef|;
comment|/*  * Access to an Alist item by index or offset. This is needed because the  * size of an item in an Alist is not known by the C compiler, and we  * have to do the indexing arithmetic explicitly.  *  * For an APlist, index the apl_data field directly --- No macro is needed.  */
define|#
directive|define
name|alist_item
parameter_list|(
name|_lp
parameter_list|,
name|_idx
parameter_list|)
define|\
value|((void *)(ALIST_OFF_DATA + ((_idx) * (_lp)->al_size) + (char *)(_lp)))
define|#
directive|define
name|alist_item_by_offset
parameter_list|(
name|_lp
parameter_list|,
name|_off
parameter_list|)
define|\
value|((void *)((_off) + (char *)(_lp)))
comment|/*  * # of items currently found in a list. These macros handle the case  * where the list has not been allocated yet.  */
define|#
directive|define
name|alist_nitems
parameter_list|(
name|_lp
parameter_list|)
value|(((_lp) == NULL) ? 0 : (_lp)->al_nitems)
define|#
directive|define
name|aplist_nitems
parameter_list|(
name|_lp
parameter_list|)
value|(((_lp) == NULL) ? 0 : (_lp)->apl_nitems)
specifier|extern
name|void
modifier|*
name|alist_append
parameter_list|(
name|Alist
modifier|*
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|Aliste
parameter_list|)
function_decl|;
specifier|extern
name|void
name|alist_delete
parameter_list|(
name|Alist
modifier|*
parameter_list|,
name|Aliste
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|alist_delete_by_offset
parameter_list|(
name|Alist
modifier|*
parameter_list|,
name|Aliste
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|alist_insert
parameter_list|(
name|Alist
modifier|*
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|Aliste
parameter_list|,
name|Aliste
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|alist_insert_by_offset
parameter_list|(
name|Alist
modifier|*
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|Aliste
parameter_list|,
name|Aliste
parameter_list|)
function_decl|;
specifier|extern
name|void
name|alist_reset
parameter_list|(
name|Alist
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|aplist_append
parameter_list|(
name|APlist
modifier|*
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|Aliste
parameter_list|)
function_decl|;
specifier|extern
name|void
name|aplist_delete
parameter_list|(
name|APlist
modifier|*
parameter_list|,
name|Aliste
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|aplist_delete_value
parameter_list|(
name|APlist
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|aplist_insert
parameter_list|(
name|APlist
modifier|*
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|Aliste
parameter_list|,
name|Aliste
name|idx
parameter_list|)
function_decl|;
specifier|extern
name|void
name|aplist_reset
parameter_list|(
name|APlist
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|aplist_test_t
name|aplist_test
parameter_list|(
name|APlist
modifier|*
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|Aliste
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALIST_H */
end_comment

end_unit

