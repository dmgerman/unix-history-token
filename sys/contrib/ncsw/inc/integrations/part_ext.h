begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**   @File          part_ext.h   @Description   Definitions for the part (integration) module. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PART_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__PART_EXT_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"part_integration_ext.h"
end_include

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|MPC8306
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|MPC8309
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|MPC834x
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|MPC836x
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|MPC832x
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|MPC837x
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|MPC8568
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|MPC8569
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|P1020
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|P1021
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|P1022
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|P1023
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|P2020
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|P2040
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|P2041
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|P3041
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|P4080
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|SC4080
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|P5020
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|MSC814x
argument_list|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"unable to proceed without chip-definition"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(defined(MPC834x) || ... */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  @Description   Part data structure - must be contained in any integration                 data structure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_Part
block|{
name|uintptr_t
function_decl|(
modifier|*
name|f_GetModuleBase
function_decl|)
parameter_list|(
name|t_Handle
name|h_Part
parameter_list|,
name|e_ModuleId
name|moduleId
parameter_list|)
function_decl|;
comment|/**< Returns the address of the module's memory map base. */
name|e_ModuleId
function_decl|(
modifier|*
name|f_GetModuleIdByBase
function_decl|)
parameter_list|(
name|t_Handle
name|h_Part
parameter_list|,
name|uintptr_t
name|baseAddress
parameter_list|)
function_decl|;
comment|/**< Returns the module's ID according to its memory map base. */
block|}
name|t_Part
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PART_EXT_H */
end_comment

end_unit

