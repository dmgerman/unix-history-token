begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_BASE_LIBRARY_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_BASE_LIBRARY_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the protected interface structures, constants  *        and interface methods for the SCI_BASE_LIBRARY object.  *  */
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
file|<dev/isci/scil/sci_library.h>
include|#
directive|include
file|<dev/isci/scil/sci_pool.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_object.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_logger.h>
include|#
directive|include
file|<dev/isci/scil/sci_controller_constants.h>
comment|/**  * @struct SCI_BASE_LIBRARY  *  * @brief This structure contains all of the objects common to all library  *        sub-objects.  */
typedef|typedef
struct|struct
name|SCI_BASE_LIBRARY
block|{
comment|/**     * This class derives directly from the base object class.  As a result,     * the field is named "parent" and is the first field contained in the     * structure.     */
name|SCI_BASE_OBJECT_T
name|parent
decl_stmt|;
comment|/**     * This field provides the logger object to be utilized by all objects     * contained inside of a library.     */
name|SCI_BASE_LOGGER_T
name|logger
decl_stmt|;
comment|// Create a pool structure to manage free controller indices.
name|SCI_POOL_CREATE
argument_list|(
name|controller_id_pool
argument_list|,
name|U16
argument_list|,
name|SCI_MAX_CONTROLLERS
argument_list|)
expr_stmt|;
block|}
name|SCI_BASE_LIBRARY_T
typedef|;
comment|/**  * @brief This method will construct the base library object.  *  * @param[in] this_library This parameter specifies the library object  *            to be constructed.  * @param[in] max_controllers This parameter specifies the maximum number  *            of controllers to be supported by this library.  *  * @return none  */
name|void
name|sci_base_library_construct
parameter_list|(
name|SCI_BASE_LIBRARY_T
modifier|*
name|this_library
parameter_list|,
name|U32
name|max_controllers
parameter_list|)
function_decl|;
comment|/**  * This macro provides common code for allocating a controller from a library.  * It will ensure that we successfully allocate an available controller index  * and return SCI_FAILURE_INSUFFICIENT_RESOURCES if unsuccessful.  */
define|#
directive|define
name|SCI_BASE_LIBRARY_ALLOCATE_CONTROLLER
parameter_list|( \
name|library
parameter_list|, \
name|controller_ptr
parameter_list|, \
name|rc
parameter_list|\ )
define|\
value|{ \    U16 index; \    *rc = SCI_SUCCESS; \    if (! sci_pool_empty((library)->parent.controller_id_pool)) \    { \       sci_pool_get((library)->parent.controller_id_pool, index); \       *controller_ptr = (SCI_CONTROLLER_HANDLE_T) \& (library)->controllers[index]; \    } \    else \       *rc = SCI_FAILURE_INSUFFICIENT_RESOURCES; \ }
comment|/**  * This macro provides common code for freeing a controller to a library.  * It calculates the index to the controller instance in the array by  * determining the offset.  */
define|#
directive|define
name|SCI_BASE_LIBRARY_FREE_CONTROLLER
parameter_list|( \
name|library
parameter_list|, \
name|controller
parameter_list|, \
name|CONTROLLER_TYPE
parameter_list|, \
name|rc
parameter_list|\ )
define|\
value|{ \    U16 index = (U16) \                ((((char *)(controller)) - ((char *)(library)->controllers))\                 / sizeof(CONTROLLER_TYPE)); \    *rc = SCI_SUCCESS; \    if (  (index< SCI_MAX_CONTROLLERS) \&& (! sci_pool_full((library)->parent.controller_id_pool)) ) \    { \       sci_pool_put((library)->parent.controller_id_pool, index); \    } \    else \       *rc = SCI_FAILURE_CONTROLLER_NOT_FOUND; \ }
comment|/**  * This macro provides common code for constructing library. It  * It initialize and fill the library's controller_id_pool.  */
define|#
directive|define
name|SCI_BASE_LIBRARY_CONSTRUCT
parameter_list|( \
name|library
parameter_list|, \
name|base_library
parameter_list|, \
name|max_controllers
parameter_list|, \
name|CONTROLLER_TYPE
parameter_list|, \
name|status
parameter_list|\ )
define|\
value|{ \    U32 controller_index; \    sci_base_object_construct(&(base_library)->parent,&(base_library)->logger); \    sci_pool_initialize((base_library)->controller_id_pool); \    for (controller_index = 0; controller_index< max_controller_count; controller_index++) \    { \       SCI_BASE_LIBRARY_FREE_CONTROLLER( \          library, \&library->controllers[controller_index], \          CONTROLLER_TYPE, \&status \       ); \    } \ }
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
comment|// _SCI_BASE_LIBRARY_H_
end_comment

end_unit

