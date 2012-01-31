begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_BASE_SUBJECT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_BASE_SUBJECT_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the structures, constants, and methods  *        common to all subjects object definitions.  A subject is a  *        participant in the observer pattern.  A subject represents the  *        object being observed.  */
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
if|#
directive|if
name|defined
argument_list|(
name|SCI_LOGGING
argument_list|)
struct_decl|struct
name|SCI_BASE_OBSERVER
struct_decl|;
comment|/**  * @struct SCI_BASE_SUBJECT  *  * @brief This structure defines the fields common to all subjects that  *        participate in the observer design pattern  */
typedef|typedef
struct|struct
name|SCI_BASE_SUBJECT
block|{
name|struct
name|SCI_BASE_OBSERVER
modifier|*
name|observer_list
decl_stmt|;
block|}
name|SCI_BASE_SUBJECT_T
typedef|;
comment|/**  * @brief This method acts as the basic constructor for the subject.  *  * @param[in] this_subject This fields specifies the subject being  *            constructed.  *  * @return none  */
name|void
name|sci_base_subject_construct
parameter_list|(
name|SCI_BASE_SUBJECT_T
modifier|*
name|this_subject
parameter_list|)
function_decl|;
comment|/**  * @brief This method will call the update method for all  *        observers attached to this subject.  *  * @param[in] this_subject This parameter specifies the subject for  *            which to notify participating observers.  *  * @return none  */
name|void
name|sci_base_subject_notify
parameter_list|(
name|SCI_BASE_SUBJECT_T
modifier|*
name|this_subject
parameter_list|)
function_decl|;
comment|/**  * @brief This method will add an observer to the subject.  *  * @param[in] this_subject This parameter specifies the subject for which  *            an observer is being added.  * @param[in] observer This parameter specifies the observer that wishes  *            it listen for notifications for the supplied subject.  *  * @return none  */
name|void
name|sci_base_subject_attach_observer
parameter_list|(
name|SCI_BASE_SUBJECT_T
modifier|*
name|this_subject
parameter_list|,
name|struct
name|SCI_BASE_OBSERVER
modifier|*
name|observer
parameter_list|)
function_decl|;
comment|/**  * @brief This method will remove the observer from the subject.  *  * @param[in] this_subject  * @param[in] my_observer  *  * @return none  */
name|void
name|sci_base_subject_detach_observer
parameter_list|(
name|SCI_BASE_SUBJECT_T
modifier|*
name|this_subject
parameter_list|,
name|struct
name|SCI_BASE_OBSERVER
modifier|*
name|my_observer
parameter_list|)
function_decl|;
else|#
directive|else
comment|// defined(SCI_LOGGING)
typedef|typedef
name|U8
name|SCI_BASE_SUBJECT_T
typedef|;
define|#
directive|define
name|sci_base_subject_construct
define|#
directive|define
name|sci_base_subject_notify
define|#
directive|define
name|sci_base_subject_attach_observer
define|#
directive|define
name|sci_base_subject_detach_observer
endif|#
directive|endif
comment|// defined(SCI_LOGGING)
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
comment|// _SCI_BASE_SUBJECT_H_
end_comment

end_unit

