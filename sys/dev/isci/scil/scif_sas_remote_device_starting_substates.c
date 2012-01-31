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
comment|/**  * @file  *  * @brief This file contains the entrance and exit methods for the starting  *        sub-state machine states (AWAIT COMPELTE).  The starting sub-state  *        machine manages the steps necessary to initialize and configure  *        a remote device.  */
end_comment

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_remote_device.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_domain.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_logger.h>
end_include

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//* P R O T E C T E D   M E T H O D S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @brief This method implements the actions taken when entering the  *        STARTING AWAIT COMPLETE substate.  This includes setting the  *        state handler methods.  *  * @param[in]  object This parameter specifies the base object for which  *             the state transition is occurring.  This is cast into a  *             SCIF_SAS_REMOTE_DEVICE object in the method implementation.  *  * @return none  */
end_comment

begin_function
specifier|static
name|void
name|scif_sas_remote_device_starting_await_complete_substate_enter
parameter_list|(
name|SCI_BASE_OBJECT_T
modifier|*
name|object
parameter_list|)
block|{
name|SCIF_SAS_REMOTE_DEVICE_T
modifier|*
name|fw_device
init|=
operator|(
name|SCIF_SAS_REMOTE_DEVICE_T
operator|*
operator|)
name|object
decl_stmt|;
name|SET_STATE_HANDLER
argument_list|(
name|fw_device
argument_list|,
name|scif_sas_remote_device_starting_substate_handler_table
argument_list|,
name|SCIF_SAS_REMOTE_DEVICE_STARTING_SUBSTATE_AWAIT_COMPLETE
argument_list|)
expr_stmt|;
name|fw_device
operator|->
name|domain
operator|->
name|device_start_in_progress_count
operator|++
expr_stmt|;
name|fw_device
operator|->
name|domain
operator|->
name|device_start_count
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * @brief This method implements the actions taken when entering the  *        STARTING COMPLETE substate.  This includes setting the  *        state handler methods.  *  * @param[in]  object This parameter specifies the base object for which  *             the state transition is occurring.  This is cast into a  *             SCIF_SAS_REMOTE_DEVICE object in the method implementation.  *  * @return none  */
end_comment

begin_function
specifier|static
name|void
name|scif_sas_remote_device_starting_complete_substate_enter
parameter_list|(
name|SCI_BASE_OBJECT_T
modifier|*
name|object
parameter_list|)
block|{
name|SCIF_SAS_REMOTE_DEVICE_T
modifier|*
name|fw_device
init|=
operator|(
name|SCIF_SAS_REMOTE_DEVICE_T
operator|*
operator|)
name|object
decl_stmt|;
name|SET_STATE_HANDLER
argument_list|(
name|fw_device
argument_list|,
name|scif_sas_remote_device_starting_substate_handler_table
argument_list|,
name|SCIF_SAS_REMOTE_DEVICE_STARTING_SUBSTATE_AWAIT_READY
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|SCI_BASE_STATE_T
name|scif_sas_remote_device_starting_substate_table
index|[
name|SCIF_SAS_REMOTE_DEVICE_STARTING_SUBSTATE_MAX_STATES
index|]
init|=
block|{
block|{
name|SCIF_SAS_REMOTE_DEVICE_STARTING_SUBSTATE_AWAIT_COMPLETE
block|,
name|scif_sas_remote_device_starting_await_complete_substate_enter
block|,
name|NULL
block|}
block|,
block|{
name|SCIF_SAS_REMOTE_DEVICE_STARTING_SUBSTATE_AWAIT_READY
block|,
name|scif_sas_remote_device_starting_complete_substate_enter
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

