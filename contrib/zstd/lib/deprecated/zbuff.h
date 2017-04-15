begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_comment
comment|/* *************************************************************** *  NOTES/WARNINGS ******************************************************************/
end_comment

begin_comment
comment|/* The streaming API defined here is deprecated.  * Consider migrating towards ZSTD_compressStream() API in `zstd.h`  * See 'lib/README.md'.  *****************************************************************/
end_comment

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
ifndef|#
directive|ifndef
name|ZSTD_BUFFERED_H_23987
define|#
directive|define
name|ZSTD_BUFFERED_H_23987
comment|/* ************************************* *  Dependencies ***************************************/
include|#
directive|include
file|<stddef.h>
comment|/* size_t */
include|#
directive|include
file|"zstd.h"
comment|/* ZSTD_CStream, ZSTD_DStream, ZSTDLIB_API */
comment|/* *************************************************************** *  Compiler specifics *****************************************************************/
comment|/* Deprecation warnings */
comment|/* Should these warnings be a problem,    it is generally possible to disable them,    typically with -Wno-deprecated-declarations for gcc    or _CRT_SECURE_NO_WARNINGS in Visual.    Otherwise, it's also possible to define ZBUFF_DISABLE_DEPRECATE_WARNINGS */
ifdef|#
directive|ifdef
name|ZBUFF_DISABLE_DEPRECATE_WARNINGS
define|#
directive|define
name|ZBUFF_DEPRECATED
parameter_list|(
name|message
parameter_list|)
value|ZSTDLIB_API
comment|/* disable deprecation warnings */
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|(
name|__cplusplus
operator|>=
literal|201402
operator|)
comment|/* C++14 or greater */
define|#
directive|define
name|ZBUFF_DEPRECATED
parameter_list|(
name|message
parameter_list|)
value|[[deprecated(message)]] ZSTDLIB_API
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>=
literal|5
operator|)
operator|)
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
define|#
directive|define
name|ZBUFF_DEPRECATED
parameter_list|(
name|message
parameter_list|)
value|ZSTDLIB_API __attribute__((deprecated(message)))
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>=
literal|3
operator|)
define|#
directive|define
name|ZBUFF_DEPRECATED
parameter_list|(
name|message
parameter_list|)
value|ZSTDLIB_API __attribute__((deprecated))
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
define|#
directive|define
name|ZBUFF_DEPRECATED
parameter_list|(
name|message
parameter_list|)
value|ZSTDLIB_API __declspec(deprecated(message))
else|#
directive|else
pragma|#
directive|pragma
name|message
name|(
literal|"WARNING: You need to implement ZBUFF_DEPRECATED for this compiler"
name|)
define|#
directive|define
name|ZBUFF_DEPRECATED
parameter_list|(
name|message
parameter_list|)
value|ZSTDLIB_API
endif|#
directive|endif
endif|#
directive|endif
comment|/* ZBUFF_DISABLE_DEPRECATE_WARNINGS */
comment|/* ************************************* *  Streaming functions ***************************************/
comment|/* This is the easier "buffered" streaming API, *  using an internal buffer to lift all restrictions on user-provided buffers *  which can be any size, any place, for both input and output. *  ZBUFF and ZSTD are 100% interoperable, *  frames created by one can be decoded by the other one */
typedef|typedef
name|ZSTD_CStream
name|ZBUFF_CCtx
typedef|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_createCStream"
argument_list|)
name|ZBUFF_CCtx
modifier|*
name|ZBUFF_createCCtx
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_freeCStream"
argument_list|)
name|size_t
name|ZBUFF_freeCCtx
parameter_list|(
name|ZBUFF_CCtx
modifier|*
name|cctx
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_initCStream"
argument_list|)
name|size_t
name|ZBUFF_compressInit
parameter_list|(
name|ZBUFF_CCtx
modifier|*
name|cctx
parameter_list|,
name|int
name|compressionLevel
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_initCStream_usingDict"
argument_list|)
name|size_t
name|ZBUFF_compressInitDictionary
parameter_list|(
name|ZBUFF_CCtx
modifier|*
name|cctx
parameter_list|,
specifier|const
name|void
modifier|*
name|dict
parameter_list|,
name|size_t
name|dictSize
parameter_list|,
name|int
name|compressionLevel
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_compressStream"
argument_list|)
name|size_t
name|ZBUFF_compressContinue
parameter_list|(
name|ZBUFF_CCtx
modifier|*
name|cctx
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
modifier|*
name|dstCapacityPtr
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
modifier|*
name|srcSizePtr
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_flushStream"
argument_list|)
name|size_t
name|ZBUFF_compressFlush
parameter_list|(
name|ZBUFF_CCtx
modifier|*
name|cctx
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
modifier|*
name|dstCapacityPtr
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_endStream"
argument_list|)
name|size_t
name|ZBUFF_compressEnd
parameter_list|(
name|ZBUFF_CCtx
modifier|*
name|cctx
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
modifier|*
name|dstCapacityPtr
parameter_list|)
function_decl|;
comment|/*-************************************************* *  Streaming compression - howto * *  A ZBUFF_CCtx object is required to track streaming operation. *  Use ZBUFF_createCCtx() and ZBUFF_freeCCtx() to create/release resources. *  ZBUFF_CCtx objects can be reused multiple times. * *  Start by initializing ZBUF_CCtx. *  Use ZBUFF_compressInit() to start a new compression operation. *  Use ZBUFF_compressInitDictionary() for a compression which requires a dictionary. * *  Use ZBUFF_compressContinue() repetitively to consume input stream. *  *srcSizePtr and *dstCapacityPtr can be any size. *  The function will report how many bytes were read or written within *srcSizePtr and *dstCapacityPtr. *  Note that it may not consume the entire input, in which case it's up to the caller to present again remaining data. *  The content of `dst` will be overwritten (up to *dstCapacityPtr) at each call, so save its content if it matters or change @dst . *  @return : a hint to preferred nb of bytes to use as input for next function call (it's just a hint, to improve latency) *            or an error code, which can be tested using ZBUFF_isError(). * *  At any moment, it's possible to flush whatever data remains within buffer, using ZBUFF_compressFlush(). *  The nb of bytes written into `dst` will be reported into *dstCapacityPtr. *  Note that the function cannot output more than *dstCapacityPtr, *  therefore, some content might still be left into internal buffer if *dstCapacityPtr is too small. *  @return : nb of bytes still present into internal buffer (0 if it's empty) *            or an error code, which can be tested using ZBUFF_isError(). * *  ZBUFF_compressEnd() instructs to finish a frame. *  It will perform a flush and write frame epilogue. *  The epilogue is required for decoders to consider a frame completed. *  Similar to ZBUFF_compressFlush(), it may not be able to output the entire internal buffer content if *dstCapacityPtr is too small. *  In which case, call again ZBUFF_compressFlush() to complete the flush. *  @return : nb of bytes still present into internal buffer (0 if it's empty) *            or an error code, which can be tested using ZBUFF_isError(). * *  Hint : _recommended buffer_ sizes (not compulsory) : ZBUFF_recommendedCInSize() / ZBUFF_recommendedCOutSize() *  input : ZBUFF_recommendedCInSize==128 KB block size is the internal unit, use this value to reduce intermediate stages (better latency) *  output : ZBUFF_recommendedCOutSize==ZSTD_compressBound(128 KB) + 3 + 3 : ensures it's always possible to write/flush/end a full block. Skip some buffering. *  By using both, it ensures that input will be entirely consumed, and output will always contain the result, reducing intermediate buffering. * **************************************************/
typedef|typedef
name|ZSTD_DStream
name|ZBUFF_DCtx
typedef|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_createDStream"
argument_list|)
name|ZBUFF_DCtx
modifier|*
name|ZBUFF_createDCtx
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_freeDStream"
argument_list|)
name|size_t
name|ZBUFF_freeDCtx
parameter_list|(
name|ZBUFF_DCtx
modifier|*
name|dctx
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_initDStream"
argument_list|)
name|size_t
name|ZBUFF_decompressInit
parameter_list|(
name|ZBUFF_DCtx
modifier|*
name|dctx
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_initDStream_usingDict"
argument_list|)
name|size_t
name|ZBUFF_decompressInitDictionary
parameter_list|(
name|ZBUFF_DCtx
modifier|*
name|dctx
parameter_list|,
specifier|const
name|void
modifier|*
name|dict
parameter_list|,
name|size_t
name|dictSize
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_decompressStream"
argument_list|)
name|size_t
name|ZBUFF_decompressContinue
parameter_list|(
name|ZBUFF_DCtx
modifier|*
name|dctx
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
modifier|*
name|dstCapacityPtr
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
modifier|*
name|srcSizePtr
parameter_list|)
function_decl|;
comment|/*-*************************************************************************** *  Streaming decompression howto * *  A ZBUFF_DCtx object is required to track streaming operations. *  Use ZBUFF_createDCtx() and ZBUFF_freeDCtx() to create/release resources. *  Use ZBUFF_decompressInit() to start a new decompression operation, *   or ZBUFF_decompressInitDictionary() if decompression requires a dictionary. *  Note that ZBUFF_DCtx objects can be re-init multiple times. * *  Use ZBUFF_decompressContinue() repetitively to consume your input. *  *srcSizePtr and *dstCapacityPtr can be any size. *  The function will report how many bytes were read or written by modifying *srcSizePtr and *dstCapacityPtr. *  Note that it may not consume the entire input, in which case it's up to the caller to present remaining input again. *  The content of `dst` will be overwritten (up to *dstCapacityPtr) at each function call, so save its content if it matters, or change `dst`. *  @return : 0 when a frame is completely decoded and fully flushed, *            1 when there is still some data left within internal buffer to flush, *>1 when more data is expected, with value being a suggested next input size (it's just a hint, which helps latency), *            or an error code, which can be tested using ZBUFF_isError(). * *  Hint : recommended buffer sizes (not compulsory) : ZBUFF_recommendedDInSize() and ZBUFF_recommendedDOutSize() *  output : ZBUFF_recommendedDOutSize== 128 KB block size is the internal unit, it ensures it's always possible to write a full block when decoded. *  input  : ZBUFF_recommendedDInSize == 128KB + 3; *           just follow indications from ZBUFF_decompressContinue() to minimize latency. It should always be<= 128 KB + 3 . * *******************************************************************************/
comment|/* ************************************* *  Tool functions ***************************************/
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_isError"
argument_list|)
name|unsigned
name|ZBUFF_isError
parameter_list|(
name|size_t
name|errorCode
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_getErrorName"
argument_list|)
specifier|const
name|char
modifier|*
name|ZBUFF_getErrorName
parameter_list|(
name|size_t
name|errorCode
parameter_list|)
function_decl|;
comment|/** Functions below provide recommended buffer sizes for Compression or Decompression operations. *   These sizes are just hints, they tend to offer better latency */
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_CStreamInSize"
argument_list|)
name|size_t
name|ZBUFF_recommendedCInSize
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_CStreamOutSize"
argument_list|)
name|size_t
name|ZBUFF_recommendedCOutSize
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_DStreamInSize"
argument_list|)
name|size_t
name|ZBUFF_recommendedDInSize
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_DStreamOutSize"
argument_list|)
name|size_t
name|ZBUFF_recommendedDOutSize
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* ZSTD_BUFFERED_H_23987 */
ifdef|#
directive|ifdef
name|ZBUFF_STATIC_LINKING_ONLY
ifndef|#
directive|ifndef
name|ZBUFF_STATIC_H_30298098432
define|#
directive|define
name|ZBUFF_STATIC_H_30298098432
comment|/* ====================================================================================  * The definitions in this section are considered experimental.  * They should never be used in association with a dynamic library, as they may change in the future.  * They are provided for advanced usages.  * Use them only in association with static linking.  * ==================================================================================== */
comment|/*--- Dependency ---*/
define|#
directive|define
name|ZSTD_STATIC_LINKING_ONLY
comment|/* ZSTD_parameters, ZSTD_customMem */
include|#
directive|include
file|"zstd.h"
comment|/*--- Custom memory allocator ---*/
comment|/*! ZBUFF_createCCtx_advanced() :  *  Create a ZBUFF compression context using external alloc and free functions */
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_createCStream_advanced"
argument_list|)
name|ZBUFF_CCtx
modifier|*
name|ZBUFF_createCCtx_advanced
parameter_list|(
name|ZSTD_customMem
name|customMem
parameter_list|)
function_decl|;
comment|/*! ZBUFF_createDCtx_advanced() :  *  Create a ZBUFF decompression context using external alloc and free functions */
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_createDStream_advanced"
argument_list|)
name|ZBUFF_DCtx
modifier|*
name|ZBUFF_createDCtx_advanced
parameter_list|(
name|ZSTD_customMem
name|customMem
parameter_list|)
function_decl|;
comment|/*--- Advanced Streaming Initialization ---*/
name|ZBUFF_DEPRECATED
argument_list|(
literal|"use ZSTD_initDStream_usingDict"
argument_list|)
name|size_t
name|ZBUFF_compressInit_advanced
parameter_list|(
name|ZBUFF_CCtx
modifier|*
name|zbc
parameter_list|,
specifier|const
name|void
modifier|*
name|dict
parameter_list|,
name|size_t
name|dictSize
parameter_list|,
name|ZSTD_parameters
name|params
parameter_list|,
name|unsigned
name|long
name|long
name|pledgedSrcSize
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* ZBUFF_STATIC_H_30298098432 */
endif|#
directive|endif
comment|/* ZBUFF_STATIC_LINKING_ONLY */
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

end_unit

