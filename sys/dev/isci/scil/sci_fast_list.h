begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_FAST_LIST_HEADER_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_FAST_LIST_HEADER_
end_define

begin_comment
comment|/**  * @file  *  * @brief Header file that contains basic Linked List manipulation macros.  *        These macros implement a double linked list (SCI_FAST_LIST_T) that is  *        circular in nature.  This means that the next and prev pointers for  *        an empty queue head always the address of the queue head  *        SCI_FAST_LIST_T.  Likewise an element that has been removed from  *        a queue will have its next and prev pointer set to the address of  *        the SCI_FAST_LIST_T found in the structure just removed from the  *        queue.   Pointers in this implementation never == NULL.  *  *        Definitions:  *        - anchor : This is ths list container and has a  *                   pointer to both the head and tail of the  *                   list elements  *        - element: This is the list element not the actual  *                   object but the list element which has a  *                   pointer to the object.  */
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//*     P U B L I C   M E T H O D S
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * Initialize the double linked list anchor.  The other macros require the list  * anchor to be set up using this macro.  */
end_comment

begin_define
define|#
directive|define
name|sci_fast_list_init
parameter_list|(
name|anchor
parameter_list|)
define|\
value|{                                                                             \    (anchor)->list_head = NULL;                                                \    (anchor)->list_tail = NULL;                                                \    (anchor)->element_count = 0;                                               \ }
end_define

begin_comment
comment|/**  * Initialize the sci_fast_list_element to point to its owning object  */
end_comment

begin_define
define|#
directive|define
name|sci_fast_list_element_init
parameter_list|(
name|list_object
parameter_list|,
name|element
parameter_list|)
define|\
value|{                                                                             \    (element)->object = (list_object);                                         \    (element)->next = (element)->prev = NULL;                                  \    (element)->owning_list = NULL;                                             \ }
end_define

begin_comment
comment|/**  * See if there is anything on the list by checking the list anchor.  */
end_comment

begin_define
define|#
directive|define
name|sci_fast_list_is_empty
parameter_list|(
name|anchor
parameter_list|)
value|((anchor)->list_head == NULL)
end_define

begin_comment
comment|/**  * Return a pointer to the element at the head of the sci_fast_list.  The  * item is NOT removed from the list.  *  * NOTE: This macro will always return a value, even if the list is empty.  *       You must insure the list is not empty or use Dlist_safeGetHead.  *  * element - A pointer into which to save the address of the structure  *           containing the SCI_FAST_LIST at the list head.  */
end_comment

begin_define
define|#
directive|define
name|sci_fast_list_get_head
parameter_list|(
name|anchor
parameter_list|)
define|\
value|((anchor)->list_head == NULL ? NULL: (anchor)->list_head->object)
end_define

begin_comment
comment|/**  * Return a pointer to the element at the tail of the sci_fast_list.  The item  * is NOT removed from the list.  *  * NOTE: This macro will always return a value, even if the list is empty.  *       You must insure the list is not empty or use Dlist_safeGetHead.  *  * element - A pointer into which to save the address of the structure  *           containing the SCI_FAST_LIST at the list head.  */
end_comment

begin_define
define|#
directive|define
name|sci_fast_list_get_tail
parameter_list|(
name|anchor
parameter_list|)
define|\
value|((anchor)->list_tail == NULL ? NULL: (anchor)->list_head->object)
end_define

begin_comment
comment|/**  * This method will get the next dListField in the SCI_FAST_LIST.  This method  * returns a pointer to a SCI_FAST_LIST object.  */
end_comment

begin_define
define|#
directive|define
name|sci_fast_list_get_next
parameter_list|(
name|element
parameter_list|)
value|((element)->next)
end_define

begin_comment
comment|/**  * This method will get the prev dListField in the SCI_FAST_LIST.  This method  * returns a pointer to a SCI_FAST_LIST object.  */
end_comment

begin_define
define|#
directive|define
name|sci_fast_list_get_prev
parameter_list|(
name|element
parameter_list|)
value|((element)->prev)
end_define

begin_comment
comment|/**  * This method returns the object that is represented by this  * sci_fast_list_element  */
end_comment

begin_define
define|#
directive|define
name|sci_fast_list_get_object
parameter_list|(
name|element
parameter_list|)
value|((element)->object)
end_define

begin_comment
comment|/**  * This method will determine if the supplied dListField is on a SCI_FAST_LIST.  * If the element has only one dListField but can be on more than one list,  * this will only tell you that it is on one of them.  If the element has  * multiple dListFields and can exist on multiple lists at the same time, this  * macro can tell you exactly which list it is on.  */
end_comment

begin_define
define|#
directive|define
name|sci_fast_list_is_on_a_list
parameter_list|(
name|element
parameter_list|)
value|((element)->owning_list != NULL)
end_define

begin_comment
comment|/**  * This method will determine if the supplied dListFieldName is on the given  * specified list?  If the element can be on more than one list, this  * allows you to determine exactly which list it is on.  Performs a linear  * search through the list.  * result - BOOL_T that will contain the result of the search.  *          TRUE - item is on the list described by head.  *          FALSE - item is not on the list.  */
end_comment

begin_define
define|#
directive|define
name|sci_fast_list_is_on_this_list
parameter_list|(
name|anchor
parameter_list|,
name|element
parameter_list|)
define|\
value|((element)->owning_list == (anchor))
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
comment|/**  * @struct SCI_FAST_LIST  *  * @brief the list owner or list anchor for a set of SCI_FAST_LIST  *        elements.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SCI_FAST_LIST
block|{
name|struct
name|SCI_FAST_LIST_ELEMENT
modifier|*
name|list_head
decl_stmt|;
name|struct
name|SCI_FAST_LIST_ELEMENT
modifier|*
name|list_tail
decl_stmt|;
name|int
name|element_count
decl_stmt|;
block|}
name|SCI_FAST_LIST_T
typedef|;
end_typedef

begin_comment
comment|/**  * @struct SCI_FAST_LIST_ELEMENT  *  * @brief This structure defines what a doubly linked list element contains.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SCI_FAST_LIST_ELEMENT
block|{
name|struct
name|SCI_FAST_LIST_ELEMENT
modifier|*
name|next
decl_stmt|;
name|struct
name|SCI_FAST_LIST_ELEMENT
modifier|*
name|prev
decl_stmt|;
name|struct
name|SCI_FAST_LIST
modifier|*
name|owning_list
decl_stmt|;
name|void
modifier|*
name|object
decl_stmt|;
block|}
name|SCI_FAST_LIST_ELEMENT_T
typedef|;
end_typedef

begin_comment
comment|/**  * Insert an element to be the new head of the list hanging off of the list  * anchor.  An empty list has the list anchor pointing to itself.  * dListAnchor - The name of the SCI_FAST_LIST_T element that is the anchor  *               of the queue.  * dListFieldBeingInserted - The SCI_FAST_LIST_T field in the data structure  *                           being queued.  This SCI_FAST_LIST will become  *                           the new list head.  */
end_comment

begin_function
name|INLINE
specifier|static
name|void
name|sci_fast_list_insert_head
parameter_list|(
name|SCI_FAST_LIST_T
modifier|*
name|anchor
parameter_list|,
name|SCI_FAST_LIST_ELEMENT_T
modifier|*
name|element
parameter_list|)
block|{
name|element
operator|->
name|owning_list
operator|=
name|anchor
expr_stmt|;
name|element
operator|->
name|prev
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|anchor
operator|->
name|list_head
operator|==
name|NULL
condition|)
name|anchor
operator|->
name|list_tail
operator|=
name|element
expr_stmt|;
else|else
name|anchor
operator|->
name|list_head
operator|->
name|prev
operator|=
name|element
expr_stmt|;
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
name|element_count
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Insert an element at the tail of the list.  Since the list is circular we  * can add the element at the tail through use the list anchors previous  * pointer.  * dListAnchor - The name of the SCI_FAST_LIST_T element that is the anchor  *               of the queue.  * dListFieldBeingInserted - The SCI_FAST_LIST_T field in the data structure  *                           being queued.  This SCI_FAST_LIST will become  *                           the new list head.  */
end_comment

begin_function
name|INLINE
specifier|static
name|void
name|sci_fast_list_insert_tail
parameter_list|(
name|SCI_FAST_LIST_T
modifier|*
name|anchor
parameter_list|,
name|SCI_FAST_LIST_ELEMENT_T
modifier|*
name|element
parameter_list|)
block|{
name|element
operator|->
name|owning_list
operator|=
name|anchor
expr_stmt|;
name|element
operator|->
name|next
operator|=
name|NULL
expr_stmt|;
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
name|element
operator|->
name|prev
operator|=
name|anchor
operator|->
name|list_tail
expr_stmt|;
name|anchor
operator|->
name|list_tail
operator|=
name|element
expr_stmt|;
name|anchor
operator|->
name|element_count
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * This method will remove a dListFieldName from the head of the list.  *  * NOTE: This macro will always return a value, even if the list is empty.  *       You must insure the list is not empty or use Dlist_safeRemoveHead.  *  * element - A pointer into which to save the address of the structure  *           containing the SCI_FAST_LIST at the list head.  */
end_comment

begin_function
name|INLINE
specifier|static
name|void
modifier|*
name|sci_fast_list_remove_head
parameter_list|(
name|SCI_FAST_LIST_T
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
name|SCI_FAST_LIST_ELEMENT_T
modifier|*
name|element
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
name|element
operator|=
name|anchor
operator|->
name|list_head
expr_stmt|;
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
name|element_count
operator|--
expr_stmt|;
name|element
operator|->
name|next
operator|=
name|element
operator|->
name|prev
operator|=
name|NULL
expr_stmt|;
name|element
operator|->
name|owning_list
operator|=
name|NULL
expr_stmt|;
block|}
return|return
name|object
return|;
block|}
end_function

begin_function
name|INLINE
specifier|static
name|void
modifier|*
name|sci_fast_list_remove_tail
parameter_list|(
name|SCI_FAST_LIST_T
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
name|SCI_FAST_LIST_ELEMENT_T
modifier|*
name|element
decl_stmt|;
if|if
condition|(
name|anchor
operator|->
name|list_tail
operator|!=
name|NULL
condition|)
block|{
name|element
operator|=
name|anchor
operator|->
name|list_tail
expr_stmt|;
name|object
operator|=
name|element
operator|->
name|object
expr_stmt|;
name|anchor
operator|->
name|list_tail
operator|=
name|element
operator|->
name|prev
expr_stmt|;
if|if
condition|(
name|anchor
operator|->
name|list_tail
operator|==
name|NULL
condition|)
name|anchor
operator|->
name|list_head
operator|=
name|NULL
expr_stmt|;
name|anchor
operator|->
name|element_count
operator|--
expr_stmt|;
name|element
operator|->
name|next
operator|=
name|element
operator|->
name|prev
operator|=
name|NULL
expr_stmt|;
name|element
operator|->
name|owning_list
operator|=
name|NULL
expr_stmt|;
block|}
return|return
name|object
return|;
block|}
end_function

begin_comment
comment|/**  * Remove an element from anywhere in the list referenced by name.  */
end_comment

begin_function
name|INLINE
specifier|static
name|void
name|sci_fast_list_remove_element
parameter_list|(
name|SCI_FAST_LIST_ELEMENT_T
modifier|*
name|element
parameter_list|)
block|{
if|if
condition|(
name|element
operator|->
name|next
operator|==
name|NULL
condition|)
name|element
operator|->
name|owning_list
operator|->
name|list_tail
operator|=
name|element
operator|->
name|prev
expr_stmt|;
else|else
name|element
operator|->
name|next
operator|->
name|prev
operator|=
name|element
operator|->
name|prev
expr_stmt|;
if|if
condition|(
name|element
operator|->
name|prev
operator|==
name|NULL
condition|)
name|element
operator|->
name|owning_list
operator|->
name|list_head
operator|=
name|element
operator|->
name|next
expr_stmt|;
else|else
name|element
operator|->
name|prev
operator|->
name|next
operator|=
name|element
operator|->
name|next
expr_stmt|;
name|element
operator|->
name|owning_list
operator|->
name|element_count
operator|--
expr_stmt|;
name|element
operator|->
name|next
operator|=
name|element
operator|->
name|prev
operator|=
name|NULL
expr_stmt|;
name|element
operator|->
name|owning_list
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SCI_FAST_LIST_HEADER_
end_comment

end_unit

