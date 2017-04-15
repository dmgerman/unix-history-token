begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ZSTDMT_COMPRESS_H
end_ifndef

begin_define
define|#
directive|define
name|ZSTDMT_COMPRESS_H
end_define

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
comment|/* Note : All prototypes defined in this file shall be considered experimental.  *        There is no guarantee of API continuity (yet) on any of these prototypes */
comment|/* ===   Dependencies   === */
include|#
directive|include
file|<stddef.h>
comment|/* size_t */
define|#
directive|define
name|ZSTD_STATIC_LINKING_ONLY
comment|/* ZSTD_parameters */
include|#
directive|include
file|"zstd.h"
comment|/* ZSTD_inBuffer, ZSTD_outBuffer, ZSTDLIB_API */
comment|/* ===   Simple one-pass functions   === */
typedef|typedef
name|struct
name|ZSTDMT_CCtx_s
name|ZSTDMT_CCtx
typedef|;
name|ZSTDLIB_API
name|ZSTDMT_CCtx
modifier|*
name|ZSTDMT_createCCtx
parameter_list|(
name|unsigned
name|nbThreads
parameter_list|)
function_decl|;
name|ZSTDLIB_API
name|size_t
name|ZSTDMT_freeCCtx
parameter_list|(
name|ZSTDMT_CCtx
modifier|*
name|cctx
parameter_list|)
function_decl|;
name|ZSTDLIB_API
name|size_t
name|ZSTDMT_compressCCtx
parameter_list|(
name|ZSTDMT_CCtx
modifier|*
name|cctx
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
name|dstCapacity
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|srcSize
parameter_list|,
name|int
name|compressionLevel
parameter_list|)
function_decl|;
comment|/* ===   Streaming functions   === */
name|ZSTDLIB_API
name|size_t
name|ZSTDMT_initCStream
parameter_list|(
name|ZSTDMT_CCtx
modifier|*
name|mtctx
parameter_list|,
name|int
name|compressionLevel
parameter_list|)
function_decl|;
name|ZSTDLIB_API
name|size_t
name|ZSTDMT_resetCStream
parameter_list|(
name|ZSTDMT_CCtx
modifier|*
name|mtctx
parameter_list|,
name|unsigned
name|long
name|long
name|pledgedSrcSize
parameter_list|)
function_decl|;
comment|/**< pledgedSrcSize is optional and can be zero == unknown */
name|ZSTDLIB_API
name|size_t
name|ZSTDMT_compressStream
parameter_list|(
name|ZSTDMT_CCtx
modifier|*
name|mtctx
parameter_list|,
name|ZSTD_outBuffer
modifier|*
name|output
parameter_list|,
name|ZSTD_inBuffer
modifier|*
name|input
parameter_list|)
function_decl|;
name|ZSTDLIB_API
name|size_t
name|ZSTDMT_flushStream
parameter_list|(
name|ZSTDMT_CCtx
modifier|*
name|mtctx
parameter_list|,
name|ZSTD_outBuffer
modifier|*
name|output
parameter_list|)
function_decl|;
comment|/**< @return : 0 == all flushed;>0 : still some data to be flushed; or an error code (ZSTD_isError()) */
name|ZSTDLIB_API
name|size_t
name|ZSTDMT_endStream
parameter_list|(
name|ZSTDMT_CCtx
modifier|*
name|mtctx
parameter_list|,
name|ZSTD_outBuffer
modifier|*
name|output
parameter_list|)
function_decl|;
comment|/**< @return : 0 == all flushed;>0 : still some data to be flushed; or an error code (ZSTD_isError()) */
comment|/* ===   Advanced functions and parameters  === */
ifndef|#
directive|ifndef
name|ZSTDMT_SECTION_SIZE_MIN
define|#
directive|define
name|ZSTDMT_SECTION_SIZE_MIN
value|(1U<< 20)
comment|/* 1 MB - Minimum size of each compression job */
endif|#
directive|endif
name|ZSTDLIB_API
name|size_t
name|ZSTDMT_initCStream_advanced
parameter_list|(
name|ZSTDMT_CCtx
modifier|*
name|mtctx
parameter_list|,
specifier|const
name|void
modifier|*
name|dict
parameter_list|,
name|size_t
name|dictSize
parameter_list|,
comment|/**< dict can be released after init, a local copy is preserved within zcs */
name|ZSTD_parameters
name|params
parameter_list|,
name|unsigned
name|long
name|long
name|pledgedSrcSize
parameter_list|)
function_decl|;
comment|/**< pledgedSrcSize is optional and can be zero == unknown */
comment|/* ZSDTMT_parameter :  * List of parameters that can be set using ZSTDMT_setMTCtxParameter() */
typedef|typedef
enum|enum
block|{
name|ZSTDMT_p_sectionSize
block|,
comment|/* size of input "section". Each section is compressed in parallel. 0 means default, which is dynamically determined within compression functions */
name|ZSTDMT_p_overlapSectionLog
comment|/* Log of overlapped section; 0 == no overlap, 6(default) == use 1/8th of window,>=9 == use full window */
block|}
name|ZSDTMT_parameter
typedef|;
comment|/* ZSTDMT_setMTCtxParameter() :  * allow setting individual parameters, one at a time, among a list of enums defined in ZSTDMT_parameter.  * The function must be called typically after ZSTD_createCCtx().  * Parameters not explicitly reset by ZSTDMT_init*() remain the same in consecutive compression sessions.  * @return : 0, or an error code (which can be tested using ZSTD_isError()) */
name|ZSTDLIB_API
name|size_t
name|ZSTDMT_setMTCtxParameter
parameter_list|(
name|ZSTDMT_CCtx
modifier|*
name|mtctx
parameter_list|,
name|ZSDTMT_parameter
name|parameter
parameter_list|,
name|unsigned
name|value
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
comment|/* ZSTDMT_COMPRESS_H */
end_comment

end_unit

