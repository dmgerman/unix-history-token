begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Przemyslaw Skibinski, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ZSTD_ZLIBWRAPPER_H
end_ifndef

begin_define
define|#
directive|define
name|ZSTD_ZLIBWRAPPER_H
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
define|#
directive|define
name|ZLIB_CONST
define|#
directive|define
name|Z_PREFIX
define|#
directive|define
name|ZLIB_INTERNAL
comment|/* disables gz*64 functions but fixes zlib 1.2.4 with Z_PREFIX */
include|#
directive|include
file|<zlib.h>
if|#
directive|if
operator|!
name|defined
argument_list|(
name|z_const
argument_list|)
define|#
directive|define
name|z_const
endif|#
directive|endif
comment|/* returns a string with version of zstd library */
specifier|const
name|char
modifier|*
name|zstdVersion
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/*** COMPRESSION ***/
comment|/* ZWRAP_useZSTDcompression() enables/disables zstd compression during runtime.    By default zstd compression is disabled. To enable zstd compression please use one of the methods:    - compilation with the additional option -DZWRAP_USE_ZSTD=1     - using '#define ZWRAP_USE_ZSTD 1' in source code before '#include "zstd_zlibwrapper.h"'    - calling ZWRAP_useZSTDcompression(1)    All above-mentioned methods will enable zstd compression for all threads.    Be aware that ZWRAP_useZSTDcompression() is not thread-safe and may lead to a race condition. */
name|void
name|ZWRAP_useZSTDcompression
parameter_list|(
name|int
name|turn_on
parameter_list|)
function_decl|;
comment|/* checks if zstd compression is turned on */
name|int
name|ZWRAP_isUsingZSTDcompression
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Changes a pledged source size for a given compression stream.    It will change ZSTD compression parameters what may improve compression speed and/or ratio.    The function should be called just after deflateInit() or deflateReset() and before deflate() or deflateSetDictionary().    It's only helpful when data is compressed in blocks.     There will be no change in case of deflateInit() or deflateReset() immediately followed by deflate(strm, Z_FINISH)     as this case is automatically detected.  */
name|int
name|ZWRAP_setPledgedSrcSize
parameter_list|(
name|z_streamp
name|strm
parameter_list|,
name|unsigned
name|long
name|long
name|pledgedSrcSize
parameter_list|)
function_decl|;
comment|/* Similar to deflateReset but preserves dictionary set using deflateSetDictionary.    It should improve compression speed because there will be less calls to deflateSetDictionary     When using zlib compression this method redirects to deflateReset. */
name|int
name|ZWRAP_deflateReset_keepDict
parameter_list|(
name|z_streamp
name|strm
parameter_list|)
function_decl|;
comment|/*** DECOMPRESSION ***/
typedef|typedef
enum|enum
block|{
name|ZWRAP_FORCE_ZLIB
block|,
name|ZWRAP_AUTO
block|}
name|ZWRAP_decompress_type
typedef|;
comment|/* ZWRAP_setDecompressionType() enables/disables automatic recognition of zstd/zlib compressed data during runtime.    By default auto-detection of zstd and zlib streams in enabled (ZWRAP_AUTO).    Forcing zlib decompression with ZWRAP_setDecompressionType(ZWRAP_FORCE_ZLIB) slightly improves    decompression speed of zlib-encoded streams.    Be aware that ZWRAP_setDecompressionType() is not thread-safe and may lead to a race condition. */
name|void
name|ZWRAP_setDecompressionType
parameter_list|(
name|ZWRAP_decompress_type
name|type
parameter_list|)
function_decl|;
comment|/* checks zstd decompression type */
name|ZWRAP_decompress_type
name|ZWRAP_getDecompressionType
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Checks if zstd decompression is used for a given stream.    If will return 1 only when inflate() was called and zstd header was detected. */
name|int
name|ZWRAP_isUsingZSTDdecompression
parameter_list|(
name|z_streamp
name|strm
parameter_list|)
function_decl|;
comment|/* Similar to inflateReset but preserves dictionary set using inflateSetDictionary.    inflate() will return Z_NEED_DICT only for the first time what will improve decompression speed.    For zlib streams this method redirects to inflateReset. */
name|int
name|ZWRAP_inflateReset_keepDict
parameter_list|(
name|z_streamp
name|strm
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
comment|/* ZSTD_ZLIBWRAPPER_H */
end_comment

end_unit

