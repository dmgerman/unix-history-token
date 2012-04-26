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
comment|/**  * @file  *  * @brief This file contains the base subject method implementations and  *        any constants or structures private to the base subject object.  *        A subject is a participant in the observer design pattern.  A  *        subject represents the object being observed.  */
end_comment

begin_include
include|#
directive|include
file|<dev/isci/scil/sci_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/sci_base_subject.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/sci_base_observer.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SCI_LOGGING
argument_list|)
end_if

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//* P R O T E C T E D    M E T H O D S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_function
name|void
name|sci_base_subject_construct
parameter_list|(
name|SCI_BASE_SUBJECT_T
modifier|*
name|this_subject
parameter_list|)
block|{
name|this_subject
operator|->
name|observer_list
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_comment
comment|// ---------------------------------------------------------------------------
end_comment

begin_function
name|void
name|sci_base_subject_notify
parameter_list|(
name|SCI_BASE_SUBJECT_T
modifier|*
name|this_subject
parameter_list|)
block|{
name|SCI_BASE_OBSERVER_T
modifier|*
name|this_observer
init|=
name|this_subject
operator|->
name|observer_list
decl_stmt|;
while|while
condition|(
name|this_observer
operator|!=
name|NULL
condition|)
block|{
name|sci_base_observer_update
argument_list|(
name|this_observer
argument_list|,
name|this_subject
argument_list|)
expr_stmt|;
name|this_observer
operator|=
name|this_observer
operator|->
name|next
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// ---------------------------------------------------------------------------
end_comment

begin_function
name|void
name|sci_base_subject_attach_observer
parameter_list|(
name|SCI_BASE_SUBJECT_T
modifier|*
name|this_subject
parameter_list|,
name|SCI_BASE_OBSERVER_T
modifier|*
name|observer
parameter_list|)
block|{
name|observer
operator|->
name|next
operator|=
name|this_subject
operator|->
name|observer_list
expr_stmt|;
name|this_subject
operator|->
name|observer_list
operator|=
name|observer
expr_stmt|;
block|}
end_function

begin_comment
comment|// ---------------------------------------------------------------------------
end_comment

begin_function
name|void
name|sci_base_subject_detach_observer
parameter_list|(
name|SCI_BASE_SUBJECT_T
modifier|*
name|this_subject
parameter_list|,
name|SCI_BASE_OBSERVER_T
modifier|*
name|observer
parameter_list|)
block|{
name|SCI_BASE_OBSERVER_T
modifier|*
name|current_observer
init|=
name|this_subject
operator|->
name|observer_list
decl_stmt|;
name|SCI_BASE_OBSERVER_T
modifier|*
name|previous_observer
init|=
name|NULL
decl_stmt|;
comment|// Search list for the item to remove
while|while
condition|(
name|current_observer
operator|!=
name|NULL
operator|&&
name|current_observer
operator|!=
name|observer
condition|)
block|{
name|previous_observer
operator|=
name|current_observer
expr_stmt|;
name|current_observer
operator|=
name|current_observer
operator|->
name|next
expr_stmt|;
block|}
comment|// Was this observer in the list?
if|if
condition|(
name|current_observer
operator|==
name|observer
condition|)
block|{
if|if
condition|(
name|previous_observer
operator|!=
name|NULL
condition|)
block|{
comment|// Remove from middle or end of list
name|previous_observer
operator|->
name|next
operator|=
name|observer
operator|->
name|next
expr_stmt|;
block|}
else|else
block|{
comment|// Remove from the front of the list
name|this_subject
operator|->
name|observer_list
operator|=
name|observer
operator|->
name|next
expr_stmt|;
block|}
comment|// protect the list so people dont follow bad pointers
name|observer
operator|->
name|next
operator|=
name|NULL
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(SCI_LOGGING)
end_comment

end_unit

