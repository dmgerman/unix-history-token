begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DICTBUILDER_H_001
end_ifndef

begin_define
define|#
directive|define
name|DICTBUILDER_H_001
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
comment|/*======  Dependencies  ======*/
include|#
directive|include
file|<stddef.h>
comment|/* size_t */
comment|/* =====   ZDICTLIB_API : control library symbols visibility   ===== */
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>=
literal|4
operator|)
define|#
directive|define
name|ZDICTLIB_VISIBILITY
value|__attribute__ ((visibility ("default")))
else|#
directive|else
define|#
directive|define
name|ZDICTLIB_VISIBILITY
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|ZSTD_DLL_EXPORT
argument_list|)
operator|&&
operator|(
name|ZSTD_DLL_EXPORT
operator|==
literal|1
operator|)
define|#
directive|define
name|ZDICTLIB_API
value|__declspec(dllexport) ZDICTLIB_VISIBILITY
elif|#
directive|elif
name|defined
argument_list|(
name|ZSTD_DLL_IMPORT
argument_list|)
operator|&&
operator|(
name|ZSTD_DLL_IMPORT
operator|==
literal|1
operator|)
define|#
directive|define
name|ZDICTLIB_API
value|__declspec(dllimport) ZDICTLIB_VISIBILITY
comment|/* It isn't required but allows to generate better code, saving a function pointer load from the IAT and an indirect jump.*/
else|#
directive|else
define|#
directive|define
name|ZDICTLIB_API
value|ZDICTLIB_VISIBILITY
endif|#
directive|endif
comment|/*! ZDICT_trainFromBuffer() :     Train a dictionary from an array of samples.     Samples must be stored concatenated in a single flat buffer `samplesBuffer`,     supplied with an array of sizes `samplesSizes`, providing the size of each sample, in order.     The resulting dictionary will be saved into `dictBuffer`.     @return : size of dictionary stored into `dictBuffer` (<= `dictBufferCapacity`)               or an error code, which can be tested with ZDICT_isError().     Tips : In general, a reasonable dictionary has a size of ~ 100 KB.            It's obviously possible to target smaller or larger ones, just by specifying different `dictBufferCapacity`.            In general, it's recommended to provide a few thousands samples, but this can vary a lot.            It's recommended that total size of all samples be about ~x100 times the target size of dictionary. */
name|ZDICTLIB_API
name|size_t
name|ZDICT_trainFromBuffer
parameter_list|(
name|void
modifier|*
name|dictBuffer
parameter_list|,
name|size_t
name|dictBufferCapacity
parameter_list|,
specifier|const
name|void
modifier|*
name|samplesBuffer
parameter_list|,
specifier|const
name|size_t
modifier|*
name|samplesSizes
parameter_list|,
name|unsigned
name|nbSamples
parameter_list|)
function_decl|;
comment|/*======   Helper functions   ======*/
name|ZDICTLIB_API
name|unsigned
name|ZDICT_getDictID
parameter_list|(
specifier|const
name|void
modifier|*
name|dictBuffer
parameter_list|,
name|size_t
name|dictSize
parameter_list|)
function_decl|;
comment|/**< extracts dictID; @return zero if error (not a valid dictionary) */
name|ZDICTLIB_API
name|unsigned
name|ZDICT_isError
parameter_list|(
name|size_t
name|errorCode
parameter_list|)
function_decl|;
name|ZDICTLIB_API
specifier|const
name|char
modifier|*
name|ZDICT_getErrorName
parameter_list|(
name|size_t
name|errorCode
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|ZDICT_STATIC_LINKING_ONLY
comment|/* ====================================================================================  * The definitions in this section are considered experimental.  * They should never be used with a dynamic library, as they may change in the future.  * They are provided for advanced usages.  * Use them only in association with static linking.  * ==================================================================================== */
typedef|typedef
struct|struct
block|{
name|unsigned
name|selectivityLevel
decl_stmt|;
comment|/* 0 means default; larger => select more => larger dictionary */
name|int
name|compressionLevel
decl_stmt|;
comment|/* 0 means default; target a specific zstd compression level */
name|unsigned
name|notificationLevel
decl_stmt|;
comment|/* Write to stderr; 0 = none (default); 1 = errors; 2 = progression; 3 = details; 4 = debug; */
name|unsigned
name|dictID
decl_stmt|;
comment|/* 0 means auto mode (32-bits random value); other : force dictID value */
name|unsigned
name|reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* reserved space for future parameters */
block|}
name|ZDICT_params_t
typedef|;
comment|/*! ZDICT_trainFromBuffer_advanced() :     Same as ZDICT_trainFromBuffer() with control over more parameters.     `parameters` is optional and can be provided with values set to 0 to mean "default".     @return : size of dictionary stored into `dictBuffer` (<= `dictBufferSize`),               or an error code, which can be tested by ZDICT_isError().     note : ZDICT_trainFromBuffer_advanced() will send notifications into stderr if instructed to, using notificationLevel>0. */
name|ZDICTLIB_API
name|size_t
name|ZDICT_trainFromBuffer_advanced
parameter_list|(
name|void
modifier|*
name|dictBuffer
parameter_list|,
name|size_t
name|dictBufferCapacity
parameter_list|,
specifier|const
name|void
modifier|*
name|samplesBuffer
parameter_list|,
specifier|const
name|size_t
modifier|*
name|samplesSizes
parameter_list|,
name|unsigned
name|nbSamples
parameter_list|,
name|ZDICT_params_t
name|parameters
parameter_list|)
function_decl|;
comment|/*! COVER_params_t :     For all values 0 means default.     k and d are the only required parameters. */
typedef|typedef
struct|struct
block|{
name|unsigned
name|k
decl_stmt|;
comment|/* Segment size : constraint: 0< k : Reasonable range [16, 2048+] */
name|unsigned
name|d
decl_stmt|;
comment|/* dmer size : constraint: 0< d<= k : Reasonable range [6, 16] */
name|unsigned
name|steps
decl_stmt|;
comment|/* Number of steps : Only used for optimization : 0 means default (32) : Higher means more parameters checked */
name|unsigned
name|nbThreads
decl_stmt|;
comment|/* Number of threads : constraint: 0< nbThreads : 1 means single-threaded : Only used for optimization : Ignored if ZSTD_MULTITHREAD is not defined */
name|unsigned
name|notificationLevel
decl_stmt|;
comment|/* Write to stderr; 0 = none (default); 1 = errors; 2 = progression; 3 = details; 4 = debug; */
name|unsigned
name|dictID
decl_stmt|;
comment|/* 0 means auto mode (32-bits random value); other : force dictID value */
name|int
name|compressionLevel
decl_stmt|;
comment|/* 0 means default; target a specific zstd compression level */
block|}
name|COVER_params_t
typedef|;
comment|/*! COVER_trainFromBuffer() :     Train a dictionary from an array of samples using the COVER algorithm.     Samples must be stored concatenated in a single flat buffer `samplesBuffer`,     supplied with an array of sizes `samplesSizes`, providing the size of each sample, in order.     The resulting dictionary will be saved into `dictBuffer`.     @return : size of dictionary stored into `dictBuffer` (<= `dictBufferCapacity`)               or an error code, which can be tested with ZDICT_isError().     Note : COVER_trainFromBuffer() requires about 9 bytes of memory for each input byte.     Tips : In general, a reasonable dictionary has a size of ~ 100 KB.            It's obviously possible to target smaller or larger ones, just by specifying different `dictBufferCapacity`.            In general, it's recommended to provide a few thousands samples, but this can vary a lot.            It's recommended that total size of all samples be about ~x100 times the target size of dictionary. */
name|ZDICTLIB_API
name|size_t
name|COVER_trainFromBuffer
parameter_list|(
name|void
modifier|*
name|dictBuffer
parameter_list|,
name|size_t
name|dictBufferCapacity
parameter_list|,
specifier|const
name|void
modifier|*
name|samplesBuffer
parameter_list|,
specifier|const
name|size_t
modifier|*
name|samplesSizes
parameter_list|,
name|unsigned
name|nbSamples
parameter_list|,
name|COVER_params_t
name|parameters
parameter_list|)
function_decl|;
comment|/*! COVER_optimizeTrainFromBuffer() :     The same requirements as above hold for all the parameters except `parameters`.     This function tries many parameter combinations and picks the best parameters.     `*parameters` is filled with the best parameters found, and the dictionary     constructed with those parameters is stored in `dictBuffer`.      All of the parameters d, k, steps are optional.     If d is non-zero then we don't check multiple values of d, otherwise we check d = {6, 8, 10, 12, 14, 16}.     if steps is zero it defaults to its default value.     If k is non-zero then we don't check multiple values of k, otherwise we check steps values in [16, 2048].      @return : size of dictionary stored into `dictBuffer` (<= `dictBufferCapacity`)               or an error code, which can be tested with ZDICT_isError().               On success `*parameters` contains the parameters selected.     Note : COVER_optimizeTrainFromBuffer() requires about 8 bytes of memory for each input byte and additionally another 5 bytes of memory for each byte of memory for each thread. */
name|ZDICTLIB_API
name|size_t
name|COVER_optimizeTrainFromBuffer
parameter_list|(
name|void
modifier|*
name|dictBuffer
parameter_list|,
name|size_t
name|dictBufferCapacity
parameter_list|,
specifier|const
name|void
modifier|*
name|samplesBuffer
parameter_list|,
specifier|const
name|size_t
modifier|*
name|samplesSizes
parameter_list|,
name|unsigned
name|nbSamples
parameter_list|,
name|COVER_params_t
modifier|*
name|parameters
parameter_list|)
function_decl|;
comment|/*! ZDICT_finalizeDictionary() :      Given a custom content as a basis for dictionary, and a set of samples,     finalize dictionary by adding headers and statistics.      Samples must be stored concatenated in a flat buffer `samplesBuffer`,     supplied with an array of sizes `samplesSizes`, providing the size of each sample in order.      dictContentSize must be>= ZDICT_CONTENTSIZE_MIN bytes.     maxDictSize must be>= dictContentSize, and must be>= ZDICT_DICTSIZE_MIN bytes.      @return : size of dictionary stored into `dictBuffer` (<= `dictBufferCapacity`),               or an error code, which can be tested by ZDICT_isError().     note : ZDICT_finalizeDictionary() will push notifications into stderr if instructed to, using notificationLevel>0.     note 2 : dictBuffer and dictContent can overlap */
define|#
directive|define
name|ZDICT_CONTENTSIZE_MIN
value|128
define|#
directive|define
name|ZDICT_DICTSIZE_MIN
value|256
name|ZDICTLIB_API
name|size_t
name|ZDICT_finalizeDictionary
parameter_list|(
name|void
modifier|*
name|dictBuffer
parameter_list|,
name|size_t
name|dictBufferCapacity
parameter_list|,
specifier|const
name|void
modifier|*
name|dictContent
parameter_list|,
name|size_t
name|dictContentSize
parameter_list|,
specifier|const
name|void
modifier|*
name|samplesBuffer
parameter_list|,
specifier|const
name|size_t
modifier|*
name|samplesSizes
parameter_list|,
name|unsigned
name|nbSamples
parameter_list|,
name|ZDICT_params_t
name|parameters
parameter_list|)
function_decl|;
comment|/* Deprecation warnings */
comment|/* It is generally possible to disable deprecation warnings from compiler,    for example with -Wno-deprecated-declarations for gcc    or _CRT_SECURE_NO_WARNINGS in Visual.    Otherwise, it's also possible to manually define ZDICT_DISABLE_DEPRECATE_WARNINGS */
ifdef|#
directive|ifdef
name|ZDICT_DISABLE_DEPRECATE_WARNINGS
define|#
directive|define
name|ZDICT_DEPRECATED
parameter_list|(
name|message
parameter_list|)
value|ZDICTLIB_API
comment|/* disable deprecation warnings */
else|#
directive|else
define|#
directive|define
name|ZDICT_GCC_VERSION
value|(__GNUC__ * 100 + __GNUC_MINOR__)
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
name|ZDICT_DEPRECATED
parameter_list|(
name|message
parameter_list|)
value|[[deprecated(message)]] ZDICTLIB_API
elif|#
directive|elif
operator|(
name|ZDICT_GCC_VERSION
operator|>=
literal|405
operator|)
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
define|#
directive|define
name|ZDICT_DEPRECATED
parameter_list|(
name|message
parameter_list|)
value|ZDICTLIB_API __attribute__((deprecated(message)))
elif|#
directive|elif
operator|(
name|ZDICT_GCC_VERSION
operator|>=
literal|301
operator|)
define|#
directive|define
name|ZDICT_DEPRECATED
parameter_list|(
name|message
parameter_list|)
value|ZDICTLIB_API __attribute__((deprecated))
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
define|#
directive|define
name|ZDICT_DEPRECATED
parameter_list|(
name|message
parameter_list|)
value|ZDICTLIB_API __declspec(deprecated(message))
else|#
directive|else
pragma|#
directive|pragma
name|message
name|(
literal|"WARNING: You need to implement ZDICT_DEPRECATED for this compiler"
name|)
define|#
directive|define
name|ZDICT_DEPRECATED
parameter_list|(
name|message
parameter_list|)
value|ZDICTLIB_API
endif|#
directive|endif
endif|#
directive|endif
comment|/* ZDICT_DISABLE_DEPRECATE_WARNINGS */
name|ZDICT_DEPRECATED
argument_list|(
literal|"use ZDICT_finalizeDictionary() instead"
argument_list|)
name|size_t
name|ZDICT_addEntropyTablesFromBuffer
parameter_list|(
name|void
modifier|*
name|dictBuffer
parameter_list|,
name|size_t
name|dictContentSize
parameter_list|,
name|size_t
name|dictBufferCapacity
parameter_list|,
specifier|const
name|void
modifier|*
name|samplesBuffer
parameter_list|,
specifier|const
name|size_t
modifier|*
name|samplesSizes
parameter_list|,
name|unsigned
name|nbSamples
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* ZDICT_STATIC_LINKING_ONLY */
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
comment|/* DICTBUILDER_H_001 */
end_comment

end_unit

