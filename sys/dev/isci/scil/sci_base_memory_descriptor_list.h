begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_BASE_MEMORY_DESCRIPTOR_LIST_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_BASE_MEMORY_DESCRIPTOR_LIST_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the protected interface structures, constants  *        and interface methods for the SCI_BASE_MEMORY_DESCRIPTOR_LIST  *        object.  */
end_comment

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
comment|// __cplusplus
include|#
directive|include
file|<dev/isci/scil/sci_types.h>
include|#
directive|include
file|<dev/isci/scil/sci_memory_descriptor_list.h>
comment|/**  * @struct SCI_BASE_MEMORY_DESCRIPTOR_LIST  *  * @brief This structure contains all of the fields necessary to implement  *        a simple stack for managing the list of available controller indices.  */
typedef|typedef
struct|struct
name|SCI_BASE_MEMORY_DESCRIPTOR_LIST
block|{
comment|/**     * This field indicates the length of the memory descriptor entry array.     */
name|U32
name|length
decl_stmt|;
comment|/**     * This field is utilized to provide iterator pattern functionality.     * It indicates the index of the next memory descriptor in the iteration.     */
name|U32
name|next_index
decl_stmt|;
comment|/**     * This field will point to the list of memory descriptors.     */
name|SCI_PHYSICAL_MEMORY_DESCRIPTOR_T
modifier|*
name|mde_array
decl_stmt|;
comment|/**     * This field simply allows a user to chain memory descriptor lists     * together if desired.  This field will be initialized to     * SCI_INVALID_HANDLE.     */
name|SCI_MEMORY_DESCRIPTOR_LIST_HANDLE_T
name|next_mdl
decl_stmt|;
block|}
name|SCI_BASE_MEMORY_DESCRIPTOR_LIST_T
typedef|;
comment|/**  * @brief This method is invoked to construct an memory descriptor list.  *        It initializes the fields of the MDL.  *  * @param[in]  mdl This parameter specifies the memory descriptor list  *             to be constructed.  * @param[in]  mde_array This parameter specifies the array of memory  *             descriptor entries to be managed by this list.  * @param[in]  mde_array_length This parameter specifies the size of the  *             array of entries.  * @param[in]  next_mdl This parameter specifies a subsequent MDL object  *             to be managed by this MDL object.  *  * @return none.  */
name|void
name|sci_base_mdl_construct
parameter_list|(
name|SCI_BASE_MEMORY_DESCRIPTOR_LIST_T
modifier|*
name|mdl
parameter_list|,
name|SCI_PHYSICAL_MEMORY_DESCRIPTOR_T
modifier|*
name|mde_array
parameter_list|,
name|U32
name|mde_array_length
parameter_list|,
name|SCI_MEMORY_DESCRIPTOR_LIST_HANDLE_T
name|next_mdl
parameter_list|)
function_decl|;
comment|/**  * This macro constructs an memory descriptor entry with the given  * alignment and size  */
define|#
directive|define
name|sci_base_mde_construct
parameter_list|(
name|mde
parameter_list|,
name|alignment
parameter_list|,
name|size
parameter_list|,
name|attributes
parameter_list|)
define|\
value|{ \    (mde)->constant_memory_alignment  = (alignment); \    (mde)->constant_memory_size       = (size); \    (mde)->constant_memory_attributes = (attributes); \ }
comment|/**  * @brief This method validates that the memory descriptor is correctly  *        filled out by the SCI User  *  * @param[in] mde This parameter is the mde entry to validate  * @param[in] alignment This parameter specifies the expected alignment of  *            the memory for the mde.  * @param[in] size This parameter specifies the memory size expected for  *            the mde its value should not have been changed by the SCI  *            User.  * @param[in] attributes This parameter specifies the attributes for the  *            memory descriptor provided.  *  * @return BOOL This method returns an indication as to whether the  *              supplied MDE is valid or not.  * @retval TRUE The MDE is valid.  * @retval FALSE The MDE is not valid.  */
name|BOOL
name|sci_base_mde_is_valid
parameter_list|(
name|SCI_PHYSICAL_MEMORY_DESCRIPTOR_T
modifier|*
name|mde
parameter_list|,
name|U32
name|alignment
parameter_list|,
name|U32
name|size
parameter_list|,
name|U16
name|attributes
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

begin_comment
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SCI_BASE_MEMORY_DESCRIPTOR_LIST_H_
end_comment

end_unit

