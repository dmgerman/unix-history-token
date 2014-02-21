begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIC_SDS_LIBRARY_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIC_SDS_LIBRARY_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the structures used by the core library object.  *        All of the functionality for the core library is in the  *        sci_base_library.h file.  */
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
file|<dev/isci/scil/sci_base_library.h>
include|#
directive|include
file|<dev/isci/scil/scic_sds_pci.h>
comment|// Forward declar the controllers
struct_decl|struct
name|SCIC_SDS_CONTROLLER
struct_decl|;
comment|/**  * @struct SCIC_SDS_LIBRARY  *  * This structure contains data used by the core library.  */
typedef|typedef
struct|struct
name|SCIC_SDS_LIBRARY
block|{
comment|/*    * The SCI_BASE_LIBRARY is the parent object for the SCIC_SDS_LIBRARY    * object.    */
name|SCI_BASE_LIBRARY_T
name|parent
decl_stmt|;
comment|/**     * This is the count of the maximum number of controllers that this library     * can contain.     */
name|U32
name|max_controller_count
decl_stmt|;
comment|/**     * The PCI header for this library object all libraries must have the same     * pci device id.     */
name|U16
name|pci_device
decl_stmt|;
name|U8
name|pci_revision
decl_stmt|;
comment|/**     * This field is the array of controllers that are contained within the     * library object.     */
name|struct
name|SCIC_SDS_CONTROLLER
modifier|*
name|controllers
decl_stmt|;
block|}
name|SCIC_SDS_LIBRARY_T
typedef|;
name|U8
name|scic_sds_library_get_controller_index
parameter_list|(
name|struct
name|SCIC_SDS_LIBRARY
modifier|*
name|library
parameter_list|,
name|struct
name|SCIC_SDS_CONTROLLER
modifier|*
name|controller
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
comment|// _SCIC_SDS_LIBRARY_H_
end_comment

end_unit

