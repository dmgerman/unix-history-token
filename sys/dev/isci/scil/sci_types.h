begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_TYPES_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the basic data types utilized by an  *        SCI user or implementor.  */
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
file|<dev/isci/types.h>
ifndef|#
directive|ifndef
name|sci_cb_physical_address_upper
error|#
directive|error
literal|"sci_cb_physical_address_upper needs to be defined in appropriate environment.h"
endif|#
directive|endif
ifndef|#
directive|ifndef
name|sci_cb_physical_address_lower
error|#
directive|error
literal|"sci_cb_physical_address_lower needs to be defined in appropriate environment.h"
endif|#
directive|endif
ifndef|#
directive|ifndef
name|sci_cb_make_physical_address
error|#
directive|error
literal|"sci_cb_make_physical_address needs to be defined in appropriate environment.h"
endif|#
directive|endif
ifndef|#
directive|ifndef
name|ASSERT
error|#
directive|error
literal|"ASSERT needs to be defined in appropriate environment.h or system"
endif|#
directive|endif
comment|/**  * This constant defines the value utilized by SCI Components to indicate  * an invalid handle.  */
define|#
directive|define
name|SCI_INVALID_HANDLE
value|0x0
comment|/**  * @typedef SCI_OBJECT_HANDLE_T  * @brief   This typedef just provides an opaque handle for all SCI  *          objects.  */
typedef|typedef
name|void
modifier|*
name|SCI_OBJECT_HANDLE_T
typedef|;
comment|/**  * @typedef SCI_LOGGER_HANDLE_T  * @brief   This typedef just provides an opaque handle for all SCI  *          Logger objects.  */
typedef|typedef
name|void
modifier|*
name|SCI_LOGGER_HANDLE_T
typedef|;
comment|/**  * @typedef SCI_IO_REQUEST_HANDLE_T  * @brief   The SCI_IO_REQUEST_HANDLE_T will be utilized by SCI users as an  *          opaque handle for the various SCI IO Request objects.  */
typedef|typedef
name|void
modifier|*
name|SCI_IO_REQUEST_HANDLE_T
typedef|;
comment|/**  * @typedef SCI_TASK_REQUEST_HANDLE_T  * @brief   The SCI_TASK_REQUEST_HANDLE_T will be utilized by SCI users as an  *          opaque handle for the various SCI Task Management Request objects.  */
typedef|typedef
name|void
modifier|*
name|SCI_TASK_REQUEST_HANDLE_T
typedef|;
comment|/**  * @typedef SCI_PHY_HANDLE_T  * @brief   This typedef just provides an opaque handle for all SCI  *          Phy objects.  */
typedef|typedef
name|void
modifier|*
name|SCI_PHY_HANDLE_T
typedef|;
comment|/**  * @typedef SCI_REMOTE_DEVICE_HANDLE_T  * @brief   The SCI_REMOTE_DEVICE_HANDLE_T will be utilized by SCI users as  *          an opaque handle for the SCI remote device object.  */
typedef|typedef
name|void
modifier|*
name|SCI_REMOTE_DEVICE_HANDLE_T
typedef|;
comment|/**  * @typedef SCI_DOMAIN_HANDLE_T  * @brief   This typedef just provides an opaque handle for all SCI  *          Domain objects.  */
typedef|typedef
name|void
modifier|*
name|SCI_DOMAIN_HANDLE_T
typedef|;
comment|/**  * @typedef SCI_PORT_HANDLE_T  * @brief   This typedef just provides an opaque handle for all SCI  *          SAS or SATA Port objects.  */
typedef|typedef
name|void
modifier|*
name|SCI_PORT_HANDLE_T
typedef|;
comment|/**  * @typedef SCI_MEMORY_DESCRIPTOR_LIST_HANDLE_T  * @brief   The SCI_MEMORY_DESCRIPTOR_LIST_HANDLE_T will be utilized by SCI  *          users as an opaque handle for the SCI MEMORY DESCRIPTOR LIST object.  */
typedef|typedef
name|void
modifier|*
name|SCI_MEMORY_DESCRIPTOR_LIST_HANDLE_T
typedef|;
comment|/**  * @typedef SCI_LOCK_HANDLE_T  * @brief   The SCI_LOCK_HANDLE_T will be utilized by SCI users as an  *          opaque handle for the SCI LOCK object.  A lock denotes a  *          critical code section of some form.  */
typedef|typedef
name|void
modifier|*
name|SCI_LOCK_HANDLE_T
typedef|;
comment|/**  * @typedef SCI_CONTROLLER_HANDLE_T  * @brief   The SCI_CONTROLLER_HANDLE_T will be utilized by SCI users as an  *          opaque handle for all SCI Controller objects.  */
typedef|typedef
name|void
modifier|*
name|SCI_CONTROLLER_HANDLE_T
typedef|;
comment|/**  * @typedef SCI_LIBRARY_HANDLE_T  * @brief   The SCI_LIBRARY_HANDLE_T will be utilized by SCI users as an  *          opaque handle for the SCI Library object.  */
typedef|typedef
name|void
modifier|*
name|SCI_LIBRARY_HANDLE_T
typedef|;
comment|/**  * @typedef SCI_ITERATOR_HANDLE_T  * @brief   The SCI_ITERATOR_T will be utilized by SCI users as an  *          opaque handle for the SCI Iterator object.  */
typedef|typedef
name|void
modifier|*
name|SCI_ITERATOR_HANDLE_T
typedef|;
comment|/**  * @typedef SCI_TIMER_CALLBACK_T  * @brief   This callback defines the format of all other timer callback  *          methods that are to be implemented by an SCI user, including  *          the method that will be invoked as a result of timer expiration.  *  *          Parameters:  *          - The void* value passed into the callback represents the cookie  *            supplied by the SCI component when the timer was created.  *  *          Return:  *          - None  */
typedef|typedef
name|void
function_decl|(
modifier|*
name|SCI_TIMER_CALLBACK_T
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**  * @brief This enumeration is provided so the SCI User can communicate the  *        data direction for an IO request.  */
typedef|typedef
enum|enum
block|{
comment|/**     * The data direction for the request is in (a read operation)     * This is also the value to use for an io request that has no specific     * data direction.     */
name|SCI_IO_REQUEST_DATA_IN
init|=
literal|0
block|,
comment|/**     * The data direction for the request is out (a write operation)     */
name|SCI_IO_REQUEST_DATA_OUT
block|,
comment|/**     * There is no data transfer for the associated request.     */
name|SCI_IO_REQUEST_NO_DATA
block|}
name|SCI_IO_REQUEST_DATA_DIRECTION
typedef|;
comment|/**  * @enum  SCI_LOCK_LEVEL  * @brief This enumeration defines the various lock levels utilized by  *        the SCI component.  These lock levels help inform users, of the  *        library, about what APIs must be protected from other APIs.  *        The higher the lock level the more restricted the access.  For  *        example, APIs specifying lock level 5 are allowed to be executed  *        while an API of lock level 4 is on-going, but the converse is  *        not true.  */
typedef|typedef
enum|enum
block|{
comment|/**     * This value indicates there is no lock level required.  This is     * primarily utilized for situations in which there is a true critical     * code section that merely needs to protect against access to a     * region of memory.     */
name|SCI_LOCK_LEVEL_NONE
block|,
name|SCI_LOCK_LEVEL_1
block|,
name|SCI_LOCK_LEVEL_2
block|,
name|SCI_LOCK_LEVEL_3
block|,
name|SCI_LOCK_LEVEL_4
block|,
name|SCI_LOCK_LEVEL_5
block|}
name|SCI_LOCK_LEVEL
typedef|;
comment|/**  * @enum _SCI_CONTROLLER_MODE  * @brief This enumeration is utilized to indicate the operating mode  *        in which the SCI component should function.  */
typedef|typedef
enum|enum
name|_SCI_CONTROLLER_MODE
block|{
comment|/**     * This enumerant specifies that the SCI component be optimized to     * perform as fast as possible without concern for the amount of     * memory being utilized.     */
name|SCI_MODE_SPEED
block|,
comment|/**     * This enumerant specifies that the SCI component be optimized to     * save memory space without concern for performance of the system.     */
name|SCI_MODE_SIZE
block|}
name|SCI_CONTROLLER_MODE
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
comment|// _SCI_TYPES_H_
end_comment

end_unit

