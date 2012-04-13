begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_BASE_OBJECT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_BASE_OBJECT_H_
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
file|<dev/isci/scil/sci_object.h>
comment|// Forward declare the logger object
struct_decl|struct
name|SCI_BASE_LOGGER
struct_decl|;
comment|/**  * @struct SCI_BASE_OBJECT  *  * @brief The SCI_BASE_OBJECT object represents the data and functionality  *        that is common to all SCI objects.  It is the base class.  */
typedef|typedef
struct|struct
name|SCI_BASE_OBJECT
block|{
comment|/**     * This field represents an association created by the user for this     * object.  The association can be whatever the user wishes.  Think of     * it as a cookie.     */
name|void
modifier|*
name|associated_object
decl_stmt|;
comment|/**     * This field simply contains a handle to the logger object to be     * utilized when utilizing the logger interface.     */
name|struct
name|SCI_BASE_LOGGER
modifier|*
name|logger
decl_stmt|;
block|}
name|SCI_BASE_OBJECT_T
typedef|;
comment|/**  * @brief This method constructs the sci base object.  *  * @param[in]  base_object This parameter specifies the SCI base  *              object which we whish to construct.  * @param[in]  logger This parameter specifies the logger object to be  *             saved and utilized for this base object.  *  * @return none  */
name|void
name|sci_base_object_construct
parameter_list|(
name|SCI_BASE_OBJECT_T
modifier|*
name|base_object
parameter_list|,
name|struct
name|SCI_BASE_LOGGER
modifier|*
name|logger
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|SCI_LOGGING
argument_list|)
comment|/**  * @brief This method returns the logger to which a previous  *         association was created.  *  * @param[in]  base_object This parameter specifies the SCI base object for  *             which to retrieve the logger.  *  * @return This method returns a pointer to the logger that was  *          previously associated to the supplied base_object  *          parameter.  * @retval NULL This value is returned when there is no logger  *         association for the supplied base_object instance.  */
define|#
directive|define
name|sci_base_object_get_logger
parameter_list|(
name|this_object
parameter_list|)
define|\
value|(((SCI_BASE_OBJECT_T *)(this_object))->logger)
else|#
directive|else
comment|// defined(SCI_LOGGING)
define|#
directive|define
name|sci_base_object_get_logger
parameter_list|(
name|this_object
parameter_list|)
value|NULL
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
comment|// _SCI_BASE_OBJECT_H_
end_comment

end_unit

