begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_SIMPLE_LIST_HEADER_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_SIMPLE_LIST_HEADER_
end_define

begin_comment
comment|/**  * @file  *  * @brief This header file contains simple linked list manipulation macros.  *        These macros differ from the SCI_FAST_LIST in that deletion of  *        an element from the list is O(n).  *        The reason for using this implementation over the SCI_FAST_LIST  *        is  *           1) space savings as there is only a single link element instead  *              of the 2 link elements used in the SCI_FAST_LIST and  *           2) it is possible to detach the entire list from its anchor  *              element for processing.  *  * @note Do not use the SCI_SIMPLE_LIST if you need to remove elements from  *       random locations within the list use instead the SCI_FAST_LIST.  */
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//*     P U B L I C    M E T H O D S
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * Initialize the singely linked list anchor.  The other macros require the  * list anchor to be properly initialized.  */
end_comment

begin_define
define|#
directive|define
name|sci_simple_list_init
parameter_list|(
name|anchor
parameter_list|)
define|\
value|{ \    (anchor)->list_head = NULL; \    (anchor)->list_tail = NULL; \    (anchor)->list_count = 0; \ }
end_define

begin_comment
comment|/**  * Initialze the singely linked list element. The other macros require the  * list element to be properly initialized.  */
end_comment

begin_define
define|#
directive|define
name|sci_simple_list_element_init
parameter_list|(
name|list_object
parameter_list|,
name|element
parameter_list|)
define|\
value|{ \    (element)->next = NULL; \    (element)->object = (list_object); \ }
end_define

begin_comment
comment|/**  * See if there are any list elements on this list.  */
end_comment

begin_define
define|#
directive|define
name|sci_simple_list_is_empty
parameter_list|(
name|anchor
parameter_list|)
value|((anchor)->list_head == NULL)
end_define

begin_comment
comment|/**  * Return a pointer to the list element at the head of the list.  The list  * element is not removed from the list.  */
end_comment

begin_define
define|#
directive|define
name|sci_simple_list_get_head
parameter_list|(
name|anchor
parameter_list|)
value|((anchor)->list_head)
end_define

begin_comment
comment|/**  * Retuen a pointer to the lsit element at the tail of the list.  The list  * element is not removed from the list.  */
end_comment

begin_define
define|#
directive|define
name|sci_simple_list_get_tail
parameter_list|(
name|anchor
parameter_list|)
value|((anchor)->list_tail)
end_define

begin_comment
comment|/**  * Return the count of the number of elements in this list.  */
end_comment

begin_define
define|#
directive|define
name|sci_simple_list_get_count
parameter_list|(
name|anchor
parameter_list|)
value|((anchor)->list_count)
end_define

begin_comment
comment|/**  * Return a pointer to the list element following this list element.  * If this is the last element in the list then NULL is returned.  */
end_comment

begin_define
define|#
directive|define
name|sci_simple_list_get_next
parameter_list|(
name|element
parameter_list|)
value|((element)->next)
end_define

begin_comment
comment|/**  * Return the object represented by the list element.  */
end_comment

begin_define
define|#
directive|define
name|sci_simple_list_get_object
parameter_list|(
name|element
parameter_list|)
value|((element)->object)
end_define

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//*     T Y P E S
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @struct  *  * @brief This structure defines the list owner for singely linked list.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SCI_SIMPLE_LIST
block|{
name|struct
name|SCI_SIMPLE_LIST_ELEMENT
modifier|*
name|list_head
decl_stmt|;
name|struct
name|SCI_SIMPLE_LIST_ELEMENT
modifier|*
name|list_tail
decl_stmt|;
name|U32
name|list_count
decl_stmt|;
block|}
name|SCI_SIMPLE_LIST_T
typedef|;
end_typedef

begin_comment
comment|/**  * @struct SCI_SIMPLE_LIST_ELEMENT  *  * @brief This structure defines what a singely linked list element contains.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SCI_SIMPLE_LIST_ELEMENT
block|{
name|struct
name|SCI_SIMPLE_LIST_ELEMENT
modifier|*
name|next
decl_stmt|;
name|void
modifier|*
name|object
decl_stmt|;
block|}
name|SCI_SIMPLE_LIST_ELEMENT_T
typedef|;
end_typedef

begin_comment
comment|/**  * This method will insert the list element to the head of the list contained  * by the anchor.  *  * @note Pushing new elements onto a list is more efficient than inserting  *       them to the tail of the list though both are O(1) operations.  */
end_comment

begin_function
name|INLINE
specifier|static
name|void
name|sci_simple_list_insert_head
parameter_list|(
name|SCI_SIMPLE_LIST_T
modifier|*
name|anchor
parameter_list|,
name|SCI_SIMPLE_LIST_ELEMENT_T
modifier|*
name|element
parameter_list|)
block|{
if|if
condition|(
name|anchor
operator|->
name|list_tail
operator|==
name|NULL
condition|)
block|{
name|anchor
operator|->
name|list_tail
operator|=
name|element
expr_stmt|;
block|}
name|element
operator|->
name|next
operator|=
name|anchor
operator|->
name|list_head
expr_stmt|;
name|anchor
operator|->
name|list_head
operator|=
name|element
expr_stmt|;
name|anchor
operator|->
name|list_count
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * This methos will insert the list element to the tail of the list contained  * by the anchor.  *  * @param[in, out] anchor this is the list into which the element is to be  *                 inserted  * @param[in] element this is the element which to insert into the list.  *  * @note Pushing new elements onto a list is more efficient than inserting  *       them to the tail of the list though both are O(1) operations.  */
end_comment

begin_function
name|INLINE
specifier|static
name|void
name|sci_simple_list_insert_tail
parameter_list|(
name|SCI_SIMPLE_LIST_T
modifier|*
name|anchor
parameter_list|,
name|SCI_SIMPLE_LIST_ELEMENT_T
modifier|*
name|element
parameter_list|)
block|{
if|if
condition|(
name|anchor
operator|->
name|list_tail
operator|==
name|NULL
condition|)
block|{
name|anchor
operator|->
name|list_head
operator|=
name|element
expr_stmt|;
block|}
else|else
block|{
name|anchor
operator|->
name|list_tail
operator|->
name|next
operator|=
name|element
expr_stmt|;
block|}
name|anchor
operator|->
name|list_tail
operator|=
name|element
expr_stmt|;
name|anchor
operator|->
name|list_count
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * This method will remove the list element from the anchor and return the  * object pointed to by that list element.  *  * @param[in, out] anchor this is the list into which the element is to be  *                 inserted  *  * @return the list element at the head of the list.  */
end_comment

begin_function
name|INLINE
specifier|static
name|void
modifier|*
name|sci_simple_list_remove_head
parameter_list|(
name|SCI_SIMPLE_LIST_T
modifier|*
name|anchor
parameter_list|)
block|{
name|void
modifier|*
name|object
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|anchor
operator|->
name|list_head
operator|!=
name|NULL
condition|)
block|{
name|object
operator|=
name|anchor
operator|->
name|list_head
operator|->
name|object
expr_stmt|;
name|anchor
operator|->
name|list_head
operator|=
name|anchor
operator|->
name|list_head
operator|->
name|next
expr_stmt|;
if|if
condition|(
name|anchor
operator|->
name|list_head
operator|==
name|NULL
condition|)
block|{
name|anchor
operator|->
name|list_tail
operator|=
name|NULL
expr_stmt|;
block|}
name|anchor
operator|->
name|list_count
operator|--
expr_stmt|;
block|}
return|return
name|object
return|;
block|}
end_function

begin_comment
comment|/**  * Move all the list elements from source anchor to the dest anchor.  * The source anchor will have all of its elements removed making it  * an empty list and the dest anchor will contain all of the source  * and dest list elements.  *  * @param[in, out] dest_anchor this is the list into which all elements from  *                 the source list are to be moved.  * @param[in, out] source_anchor this is the list which is to be moved to the  *                 destination list.  This list will be empty on return.  *  * @return the list element at the head of the list.  * @note If the destination has list elements use the insert at head  *       or tail routines instead.  */
end_comment

begin_function
name|INLINE
specifier|static
name|void
name|sci_simple_list_move_list
parameter_list|(
name|SCI_SIMPLE_LIST_T
modifier|*
name|dest_anchor
parameter_list|,
name|SCI_SIMPLE_LIST_T
modifier|*
name|source_anchor
parameter_list|)
block|{
operator|*
name|dest_anchor
operator|=
operator|*
name|source_anchor
expr_stmt|;
name|sci_simple_list_init
argument_list|(
name|source_anchor
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * This method will insert the list elements from the source anchor to the  * destination list before all previous elements on the destination list.  *  * @param[in, out] dest_anchor this is the list into which all elements from  *                 the source list are to be moved. The destination list will  *                 now contain both sets of list elements.  * @param[in, out] source_anchor this is the list which is to be moved to the  *                 destination list.  This list will be empty on return.  */
end_comment

begin_function
name|INLINE
specifier|static
name|void
name|sci_simple_list_insert_list_at_head
parameter_list|(
name|SCI_SIMPLE_LIST_T
modifier|*
name|dest_anchor
parameter_list|,
name|SCI_SIMPLE_LIST_T
modifier|*
name|source_anchor
parameter_list|)
block|{
if|if
condition|(
operator|!
name|sci_simple_list_is_empty
argument_list|(
name|source_anchor
argument_list|)
condition|)
block|{
if|if
condition|(
name|sci_simple_list_is_empty
argument_list|(
name|dest_anchor
argument_list|)
condition|)
block|{
comment|// Destination is empty just copy the source on over
operator|*
name|dest_anchor
operator|=
operator|*
name|source_anchor
expr_stmt|;
block|}
else|else
block|{
name|source_anchor
operator|->
name|list_tail
operator|->
name|next
operator|=
name|dest_anchor
operator|->
name|list_head
expr_stmt|;
name|dest_anchor
operator|->
name|list_head
operator|=
name|source_anchor
operator|->
name|list_head
expr_stmt|;
name|dest_anchor
operator|->
name|list_count
operator|+=
name|source_anchor
operator|->
name|list_count
expr_stmt|;
block|}
comment|// Wipe the source list to make sure the list elements can not be accessed
comment|// from two seperate lists at the same time.
name|sci_simple_list_init
argument_list|(
name|source_anchor
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/**  * This method will insert the list elements from the source anchor to the  * destination anchor after all list elements on the destination anchor.  *  * @param[in, out] dest_anchor this is the list into which all elements from  *                 the source list are to be moved. The destination list will  *                 contain both the source and destination list elements.  * @param[in, out] source_anchor this is the list which is to be moved to the  *                 destination list.  This list will be empty on return.  */
end_comment

begin_function
name|INLINE
specifier|static
name|void
name|sci_simple_list_insert_list_at_tail
parameter_list|(
name|SCI_SIMPLE_LIST_T
modifier|*
name|dest_anchor
parameter_list|,
name|SCI_SIMPLE_LIST_T
modifier|*
name|source_anchor
parameter_list|)
block|{
if|if
condition|(
operator|!
name|sci_simple_list_is_empty
argument_list|(
name|source_anchor
argument_list|)
condition|)
block|{
if|if
condition|(
name|sci_simple_list_is_empty
argument_list|(
name|dest_anchor
argument_list|)
condition|)
block|{
comment|// Destination is empty just copy the source on over
operator|*
name|dest_anchor
operator|=
operator|*
name|source_anchor
expr_stmt|;
block|}
else|else
block|{
comment|// If the source list is empty the desination list is the result.
name|dest_anchor
operator|->
name|list_tail
operator|->
name|next
operator|=
name|source_anchor
operator|->
name|list_head
expr_stmt|;
name|dest_anchor
operator|->
name|list_tail
operator|=
name|source_anchor
operator|->
name|list_tail
expr_stmt|;
name|dest_anchor
operator|->
name|list_count
operator|+=
name|source_anchor
operator|->
name|list_count
expr_stmt|;
block|}
comment|// Wipe the source list to make sure the list elements can not be accessed
comment|// from two seperate lists at the same time.
name|sci_simple_list_init
argument_list|(
name|source_anchor
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SCI_SIMPLE_LIST_HEADER_
end_comment

end_unit

