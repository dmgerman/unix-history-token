begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2012 Freescale Semiconductor, Inc  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          sprint_ext.h   @Description   Debug routines (externals).  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SPRINT_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__SPRINT_EXT_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NCSW_LINUX
argument_list|)
operator|&&
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|NCSW_VXWORKS
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"private/stdioP.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|NCSW_FREEBSD
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(NCSW_LINUX)&& defined(__KERNEL__) */
end_comment

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         etc_id   Utility Library Application Programming Interface   @Description   External routines.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         sprint_id Sprint   @Description   Sprint& Sscan module functions,definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      Sprint   @Description   Format a string and place it in a buffer.   @Param[in]     buff - The buffer to place the result into.  @Param[in]     str  - The format string to use.  @Param[in]     ...  - Arguments for the format string.   @Return        Number of bytes formatted. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|int
name|Sprint
parameter_list|(
name|char
modifier|*
name|buff
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      Snprint   @Description   Format a string and place it in a buffer.   @Param[in]     buf  - The buffer to place the result into.  @Param[in]     size - The size of the buffer, including the trailing null space.  @Param[in]     fmt  - The format string to use.  @Param[in]     ...  - Arguments for the format string.   @Return        Number of bytes formatted. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|int
name|Snprint
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|uint32_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      Sscan   @Description   Unformat a buffer into a list of arguments.   @Param[in]     buf  - input buffer.  @Param[in]     fmt  - formatting of buffer.  @Param[out]    ...  - resulting arguments.   @Return        Number of bytes unformatted. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|int
name|Sscan
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of sprint_id group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of etc_id group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SPRINT_EXT_H */
end_comment

end_unit

