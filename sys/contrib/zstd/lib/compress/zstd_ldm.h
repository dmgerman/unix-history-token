begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under both the BSD-style license (found in the  * LICENSE file in the root directory of this source tree) and the GPLv2 (found  * in the COPYING file in the root directory of this source tree).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ZSTD_LDM_H
end_ifndef

begin_define
define|#
directive|define
name|ZSTD_LDM_H
end_define

begin_include
include|#
directive|include
file|"zstd_compress.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*-************************************* *  Long distance matching ***************************************/
define|#
directive|define
name|ZSTD_LDM_DEFAULT_WINDOW_LOG
value|ZSTD_WINDOWLOG_DEFAULTMAX
define|#
directive|define
name|ZSTD_LDM_HASHEVERYLOG_NOTSET
value|9999
comment|/** ZSTD_compressBlock_ldm_generic() :  *  *  This is a block compressor intended for long distance matching.  *  *  The function searches for matches of length at least  *  ldmParams.minMatchLength using a hash table in cctx->ldmState.  *  Matches can be at a distance of up to cParams.windowLog.  *  *  Upon finding a match, the unmatched literals are compressed using a  *  ZSTD_blockCompressor (depending on the strategy in the compression  *  parameters), which stores the matched sequences. The "long distance"  *  match is then stored with the remaining literals from the  *  ZSTD_blockCompressor. */
name|size_t
name|ZSTD_compressBlock_ldm
parameter_list|(
name|ZSTD_CCtx
modifier|*
name|cctx
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|srcSize
parameter_list|)
function_decl|;
name|size_t
name|ZSTD_compressBlock_ldm_extDict
parameter_list|(
name|ZSTD_CCtx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|srcSize
parameter_list|)
function_decl|;
comment|/** ZSTD_ldm_initializeParameters() :  *  Initialize the long distance matching parameters to their default values. */
name|size_t
name|ZSTD_ldm_initializeParameters
parameter_list|(
name|ldmParams_t
modifier|*
name|params
parameter_list|,
name|U32
name|enableLdm
parameter_list|)
function_decl|;
comment|/** ZSTD_ldm_getTableSize() :  *  Estimate the space needed for long distance matching tables. */
name|size_t
name|ZSTD_ldm_getTableSize
parameter_list|(
name|U32
name|hashLog
parameter_list|,
name|U32
name|bucketSizeLog
parameter_list|)
function_decl|;
comment|/** ZSTD_ldm_getTableSize() :  *  Return prime8bytes^(minMatchLength-1) */
name|U64
name|ZSTD_ldm_getHashPower
parameter_list|(
name|U32
name|minMatchLength
parameter_list|)
function_decl|;
comment|/** ZSTD_ldm_adjustParameters() :  *  If the params->hashEveryLog is not set, set it to its default value based on  *  windowLog and params->hashLog.  *  *  Ensures that params->bucketSizeLog is<= params->hashLog (setting it to  *  params->hashLog if it is not). */
name|void
name|ZSTD_ldm_adjustParameters
parameter_list|(
name|ldmParams_t
modifier|*
name|params
parameter_list|,
name|U32
name|windowLog
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ZSTD_FAST_H */
end_comment

end_unit

