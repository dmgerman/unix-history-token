begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_OBJECT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_OBJECT_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the method and constants associated with  *        the SCI base object.  The SCI base object is the class from which  *        all other objects derive in the Storage Controller Interface.  */
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
file|<dev/isci/scil/sci_status.h>
comment|/**  * @brief This method returns the object to which a previous association was  *        created.  This association represents a link between an SCI object  *        and another SCI object or potentially a user object.  The  *        association essentially acts as a cookie for the user of an object.  *        The user of an SCI object is now able to retrieve a handle to their  *        own object that is managing, or related in someway, to said SCI  *        object.  *  * @param[in]  base_object This parameter specifies the SCI object for  *             which to retrieve the association reference.  *  * @return This method returns a pointer to the object that was previously  *         associated to the supplied base_object parameter.  * @retval SCI_INVALID_HANDLE This value is returned when there is no known  *         association for the supplied base_object instance.  */
if|#
directive|if
name|defined
argument_list|(
name|SCI_OBJECT_USE_ASSOCIATION_FUNCTIONS
argument_list|)
name|void
modifier|*
name|sci_object_get_association
parameter_list|(
name|SCI_OBJECT_HANDLE_T
name|base_object
parameter_list|)
function_decl|;
else|#
directive|else
define|#
directive|define
name|sci_object_get_association
parameter_list|(
name|object
parameter_list|)
value|(*((void **)object))
endif|#
directive|endif
comment|/**  * @brief This method will associate to SCI objects.  *  * @see   For more information about associations please reference the  *        sci_object_get_association() method.  *  * @param[in]  base_object This parameter specifies the SCI object for  *             which to set the association reference.  * @param[in]  associated_object This parameter specifies a pointer to the  *             object being associated.  *  * @return This method will return an indication as to whether the  *         association was set successfully.  * @retval SCI_SUCCESS This value is currently always returned.  */
if|#
directive|if
name|defined
argument_list|(
name|SCI_OBJECT_USE_ASSOCIATION_FUNCTIONS
argument_list|)
name|SCI_STATUS
name|sci_object_set_association
parameter_list|(
name|SCI_OBJECT_HANDLE_T
name|base_object
parameter_list|,
name|void
modifier|*
name|associated_object
parameter_list|)
function_decl|;
else|#
directive|else
define|#
directive|define
name|sci_object_set_association
parameter_list|(
name|base_object
parameter_list|,
name|associated_object
parameter_list|)
define|\
value|((*((void **)base_object)) = (associated_object))
endif|#
directive|endif
comment|/**  * @brief This method will get the logger for an object.  *  * @param[in] object This parameter specifies SCI object for  *       which to retrieve its logger.  *  * @return This method returns a SCI_LOGGER_HANDLE to SCI user.  */
name|SCI_LOGGER_HANDLE_T
name|sci_object_get_logger
parameter_list|(
name|SCI_OBJECT_HANDLE_T
name|object
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
comment|// _SCI_OBJECT_H_
end_comment

end_unit

