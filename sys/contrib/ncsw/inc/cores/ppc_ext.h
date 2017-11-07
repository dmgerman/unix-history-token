begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          ppc_ext.h   @Description   Core API for PowerPC cores                  These routines must be implemented by each specific PowerPC                 core driver. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PPC_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__PPC_EXT_H
end_define

begin_include
include|#
directive|include
file|"part_ext.h"
end_include

begin_define
define|#
directive|define
name|CORE_IS_BIG_ENDIAN
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CORE_E300
argument_list|)
operator|||
name|defined
argument_list|(
name|CORE_E500V2
argument_list|)
end_if

begin_define
define|#
directive|define
name|CORE_CACHELINE_SIZE
value|32
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CORE_E500MC
argument_list|)
operator|||
name|defined
argument_list|(
name|CORE_E5500
argument_list|)
operator|||
name|defined
argument_list|(
name|CORE_E6500
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CORE_CACHELINE_SIZE
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Core not defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(CORE_E300) || ... */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      CORE_TestAndSet   @Description   This routine tries to atomically test-and-set an integer                 in memory to a non-zero value.                  The memory will be set only if it is tested as zero, in which                 case the routine returns the new non-zero value; otherwise the                 routine returns zero.   @Param[in]     p - pointer to a volatile int in memory, on which test-and-set                     operation should be made.   @Retval        Zero        - Operation failed - memory was already set.  @Retval        Non-zero    - Operation succeeded - memory has been set. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|int
name|CORE_TestAndSet
parameter_list|(
specifier|volatile
name|int
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      CORE_InstructionSync   @Description   This routine will cause the core to wait for previous instructions                 (including any interrupts they generate) to complete before the                 synchronization command executes, which purges all instructions                 from the processor's pipeline and refetches the next instruction.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|CORE_InstructionSync
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      CORE_DCacheEnable   @Description   Enables the data cache for memory pages that are                 not cache inhibited.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|CORE_DCacheEnable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      CORE_ICacheEnable   @Description   Enables the instruction cache for memory pages that are                 not cache inhibited.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|CORE_ICacheEnable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      CORE_DCacheDisable   @Description   Disables the data cache.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|CORE_DCacheDisable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      CORE_ICacheDisable   @Description   Disables the instruction cache.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|CORE_ICacheDisable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"e500v2_ext.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PPC_EXT_H */
end_comment

end_unit

