begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * @file  *  * @brief This file contains the implementation of an iterator class.  *        This class will allow for iterating across the elements of a  *        container.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_SCI_ITERATORS
argument_list|)
end_if

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//*     I N C L U D E S
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_include
include|#
directive|include
file|<dev/isci/scil/sci_base_iterator.h>
end_include

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//*     P R I V A T E   M E M B E R S
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//*     P R O T E C T E D   M E T H O D S
end_comment

begin_comment
comment|//*
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @brief Return the size of an iterator object.  *  * @return U32 : size of iterator object in bytes.  *  */
end_comment

begin_function
name|U32
name|sci_iterator_get_object_size
parameter_list|(
name|void
parameter_list|)
block|{
return|return
sizeof|sizeof
argument_list|(
name|SCI_BASE_ITERATOR_T
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * @brief Initialize the interator.  *  * @param[in] iterator This parameter specifies the iterator to be  *            constructed.  * @param[in] list This parameter specifies the abstract list that will be  *            iterated on by this iterator.  The iterator will by initialized  *            to point to the first element in this abstract list.  *  * @return none  */
end_comment

begin_function
name|void
name|sci_base_iterator_construct
parameter_list|(
name|SCI_ITERATOR_HANDLE_T
name|iterator_handle
parameter_list|,
name|SCI_ABSTRACT_LIST_T
modifier|*
name|list
parameter_list|)
block|{
name|SCI_BASE_ITERATOR_T
modifier|*
name|iterator
init|=
operator|(
name|SCI_BASE_ITERATOR_T
operator|*
operator|)
name|iterator_handle
decl_stmt|;
name|memset
argument_list|(
name|iterator
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|SCI_BASE_ITERATOR_T
argument_list|)
argument_list|)
expr_stmt|;
name|iterator
operator|->
name|list
operator|=
name|list
expr_stmt|;
name|sci_iterator_first
argument_list|(
name|iterator
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * @brief Get the object currently pointed to by this iterator.  *  * @param[in] iterator_handle Handle to an iterator.  *  * @return void * : Object pointed to by this iterator.  * @retval NULL If iterator is not currently pointing to a valid element.  */
end_comment

begin_function
name|void
modifier|*
name|sci_iterator_get_current
parameter_list|(
name|SCI_ITERATOR_HANDLE_T
name|iterator_handle
parameter_list|)
block|{
name|SCI_BASE_ITERATOR_T
modifier|*
name|iterator
init|=
operator|(
name|SCI_BASE_ITERATOR_T
operator|*
operator|)
name|iterator_handle
decl_stmt|;
name|void
modifier|*
name|current_object
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|iterator
operator|->
name|current
operator|!=
name|NULL
condition|)
block|{
name|current_object
operator|=
name|sci_abstract_list_get_object
argument_list|(
name|iterator
operator|->
name|current
argument_list|)
expr_stmt|;
block|}
return|return
name|current_object
return|;
block|}
end_function

begin_comment
comment|/**  * @brief Modify the iterator to point to the first element in the list.  *  * @param[in] iterator  *  * @return none  */
end_comment

begin_function
name|void
name|sci_iterator_first
parameter_list|(
name|SCI_ITERATOR_HANDLE_T
name|iterator_handle
parameter_list|)
block|{
name|SCI_BASE_ITERATOR_T
modifier|*
name|iterator
init|=
operator|(
name|SCI_BASE_ITERATOR_T
operator|*
operator|)
name|iterator_handle
decl_stmt|;
name|iterator
operator|->
name|current
operator|=
name|sci_abstract_list_get_front
argument_list|(
name|iterator
operator|->
name|list
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * @brief Modify the iterator to point to the next element in the list.  *  * @param[in] iterator  *  * @return none  */
end_comment

begin_function
name|void
name|sci_iterator_next
parameter_list|(
name|SCI_ITERATOR_HANDLE_T
name|iterator_handle
parameter_list|)
block|{
name|SCI_BASE_ITERATOR_T
modifier|*
name|iterator
init|=
operator|(
name|SCI_BASE_ITERATOR_T
operator|*
operator|)
name|iterator_handle
decl_stmt|;
if|if
condition|(
name|iterator
operator|->
name|current
operator|!=
name|NULL
condition|)
block|{
name|iterator
operator|->
name|current
operator|=
name|sci_abstract_list_get_next
argument_list|(
name|iterator
operator|->
name|current
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
comment|// !defined(DISABLE_SCI_ITERATORS)
end_comment

end_unit

