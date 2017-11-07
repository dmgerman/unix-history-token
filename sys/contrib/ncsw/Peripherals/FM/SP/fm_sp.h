begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_sp.h   @Description   FM SP  ... */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_SP_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_SP_H
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
file|"fm_sp_common.h"
end_include

begin_include
include|#
directive|include
file|"fm_common.h"
end_include

begin_define
define|#
directive|define
name|__ERR_MODULE__
value|MODULE_FM_SP
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_FmBufferPrefixContent
name|bufferPrefixContent
decl_stmt|;
name|e_FmDmaSwapOption
name|dmaSwapData
decl_stmt|;
name|e_FmDmaCacheOption
name|dmaIntContextCacheAttr
decl_stmt|;
name|e_FmDmaCacheOption
name|dmaHeaderCacheAttr
decl_stmt|;
name|e_FmDmaCacheOption
name|dmaScatterGatherCacheAttr
decl_stmt|;
name|bool
name|dmaWriteOptimize
decl_stmt|;
name|uint16_t
name|liodnOffset
decl_stmt|;
name|bool
name|noScatherGather
decl_stmt|;
name|t_FmBufPoolDepletion
modifier|*
name|p_BufPoolDepletion
decl_stmt|;
name|t_FmBackupBmPools
modifier|*
name|p_BackupBmPools
decl_stmt|;
name|t_FmExtPools
name|extBufPools
decl_stmt|;
block|}
name|t_FmVspEntryDriverParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool
name|valid
decl_stmt|;
specifier|volatile
name|bool
name|lock
decl_stmt|;
name|uint8_t
name|pointedOwners
decl_stmt|;
name|uint16_t
name|absoluteSpId
decl_stmt|;
name|uint8_t
name|internalBufferOffset
decl_stmt|;
name|t_FmSpBufMargins
name|bufMargins
decl_stmt|;
name|t_FmSpIntContextDataCopy
name|intContext
decl_stmt|;
name|t_FmSpBufferOffsets
name|bufferOffsets
decl_stmt|;
name|t_Handle
name|h_Fm
decl_stmt|;
name|e_FmPortType
name|portType
decl_stmt|;
comment|/**< Port type */
name|uint8_t
name|portId
decl_stmt|;
comment|/**< Port Id - relative to type */
name|uint8_t
name|relativeProfileId
decl_stmt|;
name|struct
name|fm_pcd_storage_profile_regs
modifier|*
name|p_FmSpRegsBase
decl_stmt|;
name|t_FmExtPools
name|extBufPools
decl_stmt|;
name|t_FmVspEntryDriverParams
modifier|*
name|p_FmVspEntryDriverParams
decl_stmt|;
block|}
name|t_FmVspEntry
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_SP_H */
end_comment

end_unit

