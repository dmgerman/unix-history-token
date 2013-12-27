begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_BASE_STATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_BASE_STATE_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the structures, constants, and methods  *        common to all base object definitions.  */
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
file|<dev/isci/scil/sci_base_object.h>
typedef|typedef
name|void
function_decl|(
modifier|*
name|SCI_BASE_STATE_HANDLER_T
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|SCI_STATE_TRANSITION_T
function_decl|)
parameter_list|(
name|SCI_BASE_OBJECT_T
modifier|*
name|base_object
parameter_list|)
function_decl|;
comment|/**  * @struct SCI_BASE_STATE  *  * @brief The base state object abstracts the fields common to all state  *        objects defined in SCI.  */
typedef|typedef
struct|struct
name|SCI_BASE_STATE
block|{
comment|/**     * This field indicates the defined value for this state.  After     * initialization this field should not change.     */
name|U32
name|value
decl_stmt|;
comment|/**     * This field is a function pointer that defines the method to be     * invoked when the state is entered.     */
name|SCI_STATE_TRANSITION_T
name|enter_state
decl_stmt|;
comment|/**     * This field is a function pointer that defines the method to be     * invoked when the state is exited.     */
name|SCI_STATE_TRANSITION_T
name|exit_state
decl_stmt|;
block|}
name|SCI_BASE_STATE_T
typedef|;
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
comment|// _SCI_BASE_STATE_H_
end_comment

end_unit

