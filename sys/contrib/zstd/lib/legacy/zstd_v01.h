begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under both the BSD-style license (found in the  * LICENSE file in the root directory of this source tree) and the GPLv2 (found  * in the COPYING file in the root directory of this source tree).  * You may select, at your option, one of the above-listed licenses.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ZSTD_V01_H_28739879432
end_ifndef

begin_define
define|#
directive|define
name|ZSTD_V01_H_28739879432
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
comment|/* ************************************* *  Includes ***************************************/
include|#
directive|include
file|<stddef.h>
comment|/* size_t */
comment|/* ************************************* *  Simple one-step function ***************************************/
comment|/** ZSTDv01_decompress() : decompress ZSTD frames compliant with v0.1.x format     compressedSize : is the exact source size     maxOriginalSize : is the size of the 'dst' buffer, which must be already allocated.                       It must be equal or larger than originalSize, otherwise decompression will fail.     return : the number of bytes decompressed into destination buffer (originalSize)              or an errorCode if it fails (which can be tested using ZSTDv01_isError()) */
name|size_t
name|ZSTDv01_decompress
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
name|maxOriginalSize
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|compressedSize
parameter_list|)
function_decl|;
comment|/** ZSTDv01_getFrameSrcSize() : get the source length of a ZSTD frame compliant with v0.1.x format     compressedSize : The size of the 'src' buffer, at least as large as the frame pointed to by 'src'     return : the number of bytes that would be read to decompress this frame              or an errorCode if it fails (which can be tested using ZSTDv01_isError()) */
name|size_t
name|ZSTDv01_findFrameCompressedSize
parameter_list|(
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|compressedSize
parameter_list|)
function_decl|;
comment|/** ZSTDv01_isError() : tells if the result of ZSTDv01_decompress() is an error */
name|unsigned
name|ZSTDv01_isError
parameter_list|(
name|size_t
name|code
parameter_list|)
function_decl|;
comment|/* ************************************* *  Advanced functions ***************************************/
typedef|typedef
name|struct
name|ZSTDv01_Dctx_s
name|ZSTDv01_Dctx
typedef|;
name|ZSTDv01_Dctx
modifier|*
name|ZSTDv01_createDCtx
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|size_t
name|ZSTDv01_freeDCtx
parameter_list|(
name|ZSTDv01_Dctx
modifier|*
name|dctx
parameter_list|)
function_decl|;
name|size_t
name|ZSTDv01_decompressDCtx
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
name|maxOriginalSize
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|compressedSize
parameter_list|)
function_decl|;
comment|/* ************************************* *  Streaming functions ***************************************/
name|size_t
name|ZSTDv01_resetDCtx
parameter_list|(
name|ZSTDv01_Dctx
modifier|*
name|dctx
parameter_list|)
function_decl|;
name|size_t
name|ZSTDv01_nextSrcSizeToDecompress
parameter_list|(
name|ZSTDv01_Dctx
modifier|*
name|dctx
parameter_list|)
function_decl|;
name|size_t
name|ZSTDv01_decompressContinue
parameter_list|(
name|ZSTDv01_Dctx
modifier|*
name|dctx
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
name|maxDstSize
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
comment|/**   Use above functions alternatively.   ZSTD_nextSrcSizeToDecompress() tells how much bytes to provide as 'srcSize' to ZSTD_decompressContinue().   ZSTD_decompressContinue() will use previous data blocks to improve compression if they are located prior to current block.   Result is the number of bytes regenerated within 'dst'.   It can be zero, which is not an error; it just means ZSTD_decompressContinue() has decoded some header. */
comment|/* ************************************* *  Prefix - version detection ***************************************/
define|#
directive|define
name|ZSTDv01_magicNumber
value|0xFD2FB51E
comment|/* Big Endian version */
define|#
directive|define
name|ZSTDv01_magicNumberLE
value|0x1EB52FFD
comment|/* Little Endian version */
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
comment|/* ZSTD_V01_H_28739879432 */
end_comment

end_unit

