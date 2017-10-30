begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_sp_common.h   @Description   FM SP  ... */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_SP_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_SP_COMMON_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"error_ext.h"
end_include

begin_include
include|#
directive|include
file|"list_ext.h"
end_include

begin_include
include|#
directive|include
file|"fm_ext.h"
end_include

begin_include
include|#
directive|include
file|"fm_pcd_ext.h"
end_include

begin_include
include|#
directive|include
file|"fsl_fman.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       defaults */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DEFAULT_FM_SP_bufferPrefixContent_privDataSize
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_FM_SP_bufferPrefixContent_passPrsResult
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_FM_SP_bufferPrefixContent_passTimeStamp
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_FM_SP_bufferPrefixContent_allOtherPCDInfo
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_FM_SP_bufferPrefixContent_dataAlign
value|64
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining internal context copying */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|extBufOffset
decl_stmt|;
comment|/**< Offset in External buffer to which internal                                          context is copied to (Rx) or taken from (Tx, Op). */
name|uint8_t
name|intContextOffset
decl_stmt|;
comment|/**< Offset within internal context to copy from                                          (Rx) or to copy to (Tx, Op). */
name|uint16_t
name|size
decl_stmt|;
comment|/**< Internal offset size to be copied */
block|}
name|t_FmSpIntContextDataCopy
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   struct for defining external buffer margins */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|startMargins
decl_stmt|;
comment|/**< Number of bytes to be left at the beginning                                              of the external buffer (must be divisible by 16) */
name|uint16_t
name|endMargins
decl_stmt|;
comment|/**< number of bytes to be left at the end                                              of the external buffer(must be divisible by 16) */
block|}
name|t_FmSpBufMargins
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|dataOffset
decl_stmt|;
name|uint32_t
name|prsResultOffset
decl_stmt|;
name|uint32_t
name|timeStampOffset
decl_stmt|;
name|uint32_t
name|hashResultOffset
decl_stmt|;
name|uint32_t
name|pcdInfoOffset
decl_stmt|;
name|uint32_t
name|manipOffset
decl_stmt|;
block|}
name|t_FmSpBufferOffsets
typedef|;
end_typedef

begin_function_decl
name|t_Error
name|FmSpBuildBufferStructure
parameter_list|(
name|t_FmSpIntContextDataCopy
modifier|*
name|p_FmPortIntContextDataCopy
parameter_list|,
name|t_FmBufferPrefixContent
modifier|*
name|p_BufferPrefixContent
parameter_list|,
name|t_FmSpBufMargins
modifier|*
name|p_FmPortBufMargins
parameter_list|,
name|t_FmSpBufferOffsets
modifier|*
name|p_FmPortBufferOffsets
parameter_list|,
name|uint8_t
modifier|*
name|internalBufferOffset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmSpCheckIntContextParams
parameter_list|(
name|t_FmSpIntContextDataCopy
modifier|*
name|p_FmSpIntContextDataCopy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmSpCheckBufPoolsParams
parameter_list|(
name|t_FmExtPools
modifier|*
name|p_FmExtPools
parameter_list|,
name|t_FmBackupBmPools
modifier|*
name|p_FmBackupBmPools
parameter_list|,
name|t_FmBufPoolDepletion
modifier|*
name|p_FmBufPoolDepletion
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmSpCheckBufMargins
parameter_list|(
name|t_FmSpBufMargins
modifier|*
name|p_FmSpBufMargins
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmSpSetBufPoolsInAscOrderOfBufSizes
parameter_list|(
name|t_FmExtPools
modifier|*
name|p_FmExtPools
parameter_list|,
name|uint8_t
modifier|*
name|orderedArray
parameter_list|,
name|uint16_t
modifier|*
name|sizesArray
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdSpAllocProfiles
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|,
name|uint16_t
name|numOfStorageProfiles
parameter_list|,
name|uint16_t
modifier|*
name|base
parameter_list|,
name|uint8_t
modifier|*
name|log2Num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdSpGetAbsoluteProfileId
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint16_t
name|relativeProfile
parameter_list|,
name|uint16_t
modifier|*
name|p_AbsoluteId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SpInvalidateProfileSw
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|absoluteProfileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SpValidateProfileSw
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|absoluteProfileId
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_SP_COMMON_H */
end_comment

end_unit

