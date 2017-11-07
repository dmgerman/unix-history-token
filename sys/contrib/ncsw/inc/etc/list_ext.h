begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2012 Freescale Semiconductor, Inc  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**   @File          list_ext.h   @Description   External prototypes for list.c */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIST_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__LIST_EXT_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         etc_id   Utility Library Application Programming Interface   @Description   External routines.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         list_id List   @Description   List module functions,definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   List structure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|List
block|{
name|struct
name|List
modifier|*
name|p_Next
decl_stmt|;
comment|/**< A pointer to the next list object     */
name|struct
name|List
modifier|*
name|p_Prev
decl_stmt|;
comment|/**< A pointer to the previous list object */
block|}
name|t_List
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_FIRST/NCSW_LIST_LAST/NCSW_LIST_NEXT/NCSW_LIST_PREV   @Description   Macro to get first/last/next/previous entry in a list.   @Param[in]     p_List - A pointer to a list. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NCSW_LIST_FIRST
parameter_list|(
name|p_List
parameter_list|)
value|(p_List)->p_Next
end_define

begin_define
define|#
directive|define
name|NCSW_LIST_LAST
parameter_list|(
name|p_List
parameter_list|)
value|(p_List)->p_Prev
end_define

begin_define
define|#
directive|define
name|NCSW_LIST_NEXT
value|NCSW_LIST_FIRST
end_define

begin_define
define|#
directive|define
name|NCSW_LIST_PREV
value|NCSW_LIST_LAST
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_INIT   @Description   Macro for initialization of a list struct.   @Param[in]     lst - The t_List object to initialize. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NCSW_LIST_INIT
parameter_list|(
name|lst
parameter_list|)
value|{&(lst),&(lst)}
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST   @Description   Macro to declare of a list.   @Param[in]     listName - The list object name. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NCSW_LIST
parameter_list|(
name|listName
parameter_list|)
value|t_List listName = NCSW_LIST_INIT(listName)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      INIT_LIST   @Description   Macro to initialize a list pointer.   @Param[in]     p_List - The list pointer. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|INIT_LIST
parameter_list|(
name|p_List
parameter_list|)
value|NCSW_LIST_FIRST(p_List) = NCSW_LIST_LAST(p_List) = (p_List)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_OBJECT   @Description   Macro to get the struct (object) for this entry.   @Param[in]     type   - The type of the struct (object) this list is embedded in.  @Param[in]     member - The name of the t_List object within the struct.   @Return        The structure pointer for this entry. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MEMBER_OFFSET
parameter_list|(
name|type
parameter_list|,
name|member
parameter_list|)
value|(PTR_TO_UINT(&((type *)0)->member))
end_define

begin_define
define|#
directive|define
name|NCSW_LIST_OBJECT
parameter_list|(
name|p_List
parameter_list|,
name|type
parameter_list|,
name|member
parameter_list|)
define|\
value|((type *)((char *)(p_List)-MEMBER_OFFSET(type, member)))
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_FOR_EACH   @Description   Macro to iterate over a list.   @Param[in]     p_Pos  - A pointer to a list to use as a loop counter.  @Param[in]     p_Head - A pointer to the head for your list pointer.   @Cautions      You can't delete items with this routine.                 For deletion use NCSW_LIST_FOR_EACH_SAFE(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NCSW_LIST_FOR_EACH
parameter_list|(
name|p_Pos
parameter_list|,
name|p_Head
parameter_list|)
define|\
value|for (p_Pos = NCSW_LIST_FIRST(p_Head); p_Pos != (p_Head); p_Pos = NCSW_LIST_NEXT(p_Pos))
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_FOR_EACH_SAFE   @Description   Macro to iterate over a list safe against removal of list entry.   @Param[in]     p_Pos  - A pointer to a list to use as a loop counter.  @Param[in]     p_Tmp  - Another pointer to a list to use as temporary storage.  @Param[in]     p_Head - A pointer to the head for your list pointer. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NCSW_LIST_FOR_EACH_SAFE
parameter_list|(
name|p_Pos
parameter_list|,
name|p_Tmp
parameter_list|,
name|p_Head
parameter_list|)
define|\
value|for (p_Pos = NCSW_LIST_FIRST(p_Head), p_Tmp = NCSW_LIST_FIRST(p_Pos); \          p_Pos != (p_Head);                                     \          p_Pos = p_Tmp, p_Tmp = NCSW_LIST_NEXT(p_Pos))
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_FOR_EACH_OBJECT_SAFE   @Description   Macro to iterate over list of given type safely.   @Param[in]     p_Pos  - A pointer to a list to use as a loop counter.  @Param[in]     p_Tmp  - Another pointer to a list to use as temporary storage.  @Param[in]     type   - The type of the struct this is embedded in.  @Param[in]     p_Head - A pointer to the head for your list pointer.  @Param[in]     member - The name of the list_struct within the struct.   @Cautions      You can't delete items with this routine.                 For deletion use NCSW_LIST_FOR_EACH_SAFE(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NCSW_LIST_FOR_EACH_OBJECT_SAFE
parameter_list|(
name|p_Pos
parameter_list|,
name|p_Tmp
parameter_list|,
name|p_Head
parameter_list|,
name|type
parameter_list|,
name|member
parameter_list|)
define|\
value|for (p_Pos = NCSW_LIST_OBJECT(NCSW_LIST_FIRST(p_Head), type, member),            \          p_Tmp = NCSW_LIST_OBJECT(NCSW_LIST_FIRST(&p_Pos->member), type, member);    \&p_Pos->member != (p_Head);                                       \          p_Pos = p_Tmp,                                                    \          p_Tmp = NCSW_LIST_OBJECT(NCSW_LIST_FIRST(&p_Pos->member), type, member))
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_FOR_EACH_OBJECT   @Description   Macro to iterate over list of given type.   @Param[in]     p_Pos  - A pointer to a list to use as a loop counter.  @Param[in]     type   - The type of the struct this is embedded in.  @Param[in]     p_Head - A pointer to the head for your list pointer.  @Param[in]     member - The name of the list_struct within the struct.   @Cautions      You can't delete items with this routine.                 For deletion use NCSW_LIST_FOR_EACH_SAFE(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NCSW_LIST_FOR_EACH_OBJECT
parameter_list|(
name|p_Pos
parameter_list|,
name|type
parameter_list|,
name|p_Head
parameter_list|,
name|member
parameter_list|)
define|\
value|for (p_Pos = NCSW_LIST_OBJECT(NCSW_LIST_FIRST(p_Head), type, member);            \&p_Pos->member != (p_Head);                                       \          p_Pos = NCSW_LIST_OBJECT(NCSW_LIST_FIRST(&(p_Pos->member)), type, member))
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_Add   @Description   Add a new entry to a list.                  Insert a new entry after the specified head.                 This is good for implementing stacks.   @Param[in]     p_New  - A pointer to a new list entry to be added.  @Param[in]     p_Head - A pointer to a list head to add it after.   @Return        none. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|NCSW_LIST_Add
parameter_list|(
name|t_List
modifier|*
name|p_New
parameter_list|,
name|t_List
modifier|*
name|p_Head
parameter_list|)
block|{
name|NCSW_LIST_PREV
argument_list|(
name|NCSW_LIST_NEXT
argument_list|(
name|p_Head
argument_list|)
argument_list|)
operator|=
name|p_New
expr_stmt|;
name|NCSW_LIST_NEXT
argument_list|(
name|p_New
argument_list|)
operator|=
name|NCSW_LIST_NEXT
argument_list|(
name|p_Head
argument_list|)
expr_stmt|;
name|NCSW_LIST_PREV
argument_list|(
name|p_New
argument_list|)
operator|=
name|p_Head
expr_stmt|;
name|NCSW_LIST_NEXT
argument_list|(
name|p_Head
argument_list|)
operator|=
name|p_New
expr_stmt|;
block|}
end_function

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_AddToTail   @Description   Add a new entry to a list.                  Insert a new entry before the specified head.                 This is useful for implementing queues.   @Param[in]     p_New  - A pointer to a new list entry to be added.  @Param[in]     p_Head - A pointer to a list head to add it before.   @Return        none. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|NCSW_LIST_AddToTail
parameter_list|(
name|t_List
modifier|*
name|p_New
parameter_list|,
name|t_List
modifier|*
name|p_Head
parameter_list|)
block|{
name|NCSW_LIST_NEXT
argument_list|(
name|NCSW_LIST_PREV
argument_list|(
name|p_Head
argument_list|)
argument_list|)
operator|=
name|p_New
expr_stmt|;
name|NCSW_LIST_PREV
argument_list|(
name|p_New
argument_list|)
operator|=
name|NCSW_LIST_PREV
argument_list|(
name|p_Head
argument_list|)
expr_stmt|;
name|NCSW_LIST_NEXT
argument_list|(
name|p_New
argument_list|)
operator|=
name|p_Head
expr_stmt|;
name|NCSW_LIST_PREV
argument_list|(
name|p_Head
argument_list|)
operator|=
name|p_New
expr_stmt|;
block|}
end_function

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_Del   @Description   Deletes entry from a list.   @Param[in]     p_Entry - A pointer to the element to delete from the list.   @Return        none.   @Cautions      NCSW_LIST_IsEmpty() on entry does not return true after this,                 the entry is in an undefined state. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|NCSW_LIST_Del
parameter_list|(
name|t_List
modifier|*
name|p_Entry
parameter_list|)
block|{
name|NCSW_LIST_PREV
argument_list|(
name|NCSW_LIST_NEXT
argument_list|(
name|p_Entry
argument_list|)
argument_list|)
operator|=
name|NCSW_LIST_PREV
argument_list|(
name|p_Entry
argument_list|)
expr_stmt|;
name|NCSW_LIST_NEXT
argument_list|(
name|NCSW_LIST_PREV
argument_list|(
name|p_Entry
argument_list|)
argument_list|)
operator|=
name|NCSW_LIST_NEXT
argument_list|(
name|p_Entry
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_DelAndInit   @Description   Deletes entry from list and reinitialize it.   @Param[in]     p_Entry - A pointer to the element to delete from the list.   @Return        none. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|NCSW_LIST_DelAndInit
parameter_list|(
name|t_List
modifier|*
name|p_Entry
parameter_list|)
block|{
name|NCSW_LIST_Del
argument_list|(
name|p_Entry
argument_list|)
expr_stmt|;
name|INIT_LIST
argument_list|(
name|p_Entry
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_Move   @Description   Delete from one list and add as another's head.   @Param[in]     p_Entry - A pointer to the list entry to move.  @Param[in]     p_Head  - A pointer to the list head that will precede our entry.   @Return        none. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|NCSW_LIST_Move
parameter_list|(
name|t_List
modifier|*
name|p_Entry
parameter_list|,
name|t_List
modifier|*
name|p_Head
parameter_list|)
block|{
name|NCSW_LIST_Del
argument_list|(
name|p_Entry
argument_list|)
expr_stmt|;
name|NCSW_LIST_Add
argument_list|(
name|p_Entry
argument_list|,
name|p_Head
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_MoveToTail   @Description   Delete from one list and add as another's tail.   @Param[in]     p_Entry - A pointer to the entry to move.  @Param[in]     p_Head  - A pointer to the list head that will follow our entry.   @Return        none. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|NCSW_LIST_MoveToTail
parameter_list|(
name|t_List
modifier|*
name|p_Entry
parameter_list|,
name|t_List
modifier|*
name|p_Head
parameter_list|)
block|{
name|NCSW_LIST_Del
argument_list|(
name|p_Entry
argument_list|)
expr_stmt|;
name|NCSW_LIST_AddToTail
argument_list|(
name|p_Entry
argument_list|,
name|p_Head
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_IsEmpty   @Description   Tests whether a list is empty.   @Param[in]     p_List - A pointer to the list to test.   @Return        1 if the list is empty, 0 otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|NCSW_LIST_IsEmpty
parameter_list|(
name|t_List
modifier|*
name|p_List
parameter_list|)
block|{
return|return
operator|(
name|NCSW_LIST_FIRST
argument_list|(
name|p_List
argument_list|)
operator|==
name|p_List
operator|)
return|;
block|}
end_function

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_Append   @Description   Join two lists.   @Param[in]     p_NewList - A pointer to the new list to add.  @Param[in]     p_Head    - A pointer to the place to add it in the first list.   @Return        none. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|NCSW_LIST_Append
parameter_list|(
name|t_List
modifier|*
name|p_NewList
parameter_list|,
name|t_List
modifier|*
name|p_Head
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      NCSW_LIST_NumOfObjs   @Description   Counts number of objects in the list   @Param[in]     p_List - A pointer to the list which objects are to be counted.   @Return        Number of objects in the list. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|int
name|NCSW_LIST_NumOfObjs
parameter_list|(
name|t_List
modifier|*
name|p_List
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of list_id group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of etc_id group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIST_EXT_H */
end_comment

end_unit

