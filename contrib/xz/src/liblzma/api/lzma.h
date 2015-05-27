begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file        api/lzma.h  * \brief       The public API of liblzma data compression library  *  * liblzma is a public domain general-purpose data compression library with  * a zlib-like API. The native file format is .xz, but also the old .lzma  * format and raw (no headers) streams are supported. Multiple compression  * algorithms (filters) are supported. Currently LZMA2 is the primary filter.  *  * liblzma is part of XZ Utils<http://tukaani.org/xz/>. XZ Utils includes  * a gzip-like command line tool named xz and some other tools. XZ Utils  * is developed and maintained by Lasse Collin.  *  * Major parts of liblzma are based on Igor Pavlov's public domain LZMA SDK  *<http://7-zip.org/sdk.html>.  *  * The SHA-256 implementation is based on the public domain code found from  * 7-Zip<http://7-zip.org/>, which has a modified version of the public  * domain SHA-256 code found from Crypto++<http://www.cryptopp.com/>.  * The SHA-256 code in Crypto++ was written by Kevin Springle and Wei Dai.  */
end_comment

begin_comment
comment|/*  * Author: Lasse Collin  *  * This file has been put into the public domain.  * You can do whatever you want with this file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_H
end_define

begin_comment
comment|/*****************************  * Required standard headers *  *****************************/
end_comment

begin_comment
comment|/*  * liblzma API headers need some standard types and macros. To allow  * including lzma.h without requiring the application to include other  * headers first, lzma.h includes the required standard headers unless  * they already seem to be included already or if LZMA_MANUAL_HEADERS  * has been defined.  *  * Here's what types and macros are needed and from which headers:  *  - stddef.h: size_t, NULL  *  - stdint.h: uint8_t, uint32_t, uint64_t, UINT32_C(n), uint64_C(n),  *    UINT32_MAX, UINT64_MAX  *  * However, inttypes.h is a little more portable than stdint.h, although  * inttypes.h declares some unneeded things compared to plain stdint.h.  *  * The hacks below aren't perfect, specifically they assume that inttypes.h  * exists and that it typedefs at least uint8_t, uint32_t, and uint64_t,  * and that, in case of incomplete inttypes.h, unsigned int is 32-bit.  * If the application already takes care of setting up all the types and  * macros properly (for example by using gnulib's stdint.h or inttypes.h),  * we try to detect that the macros are already defined and don't include  * inttypes.h here again. However, you may define LZMA_MANUAL_HEADERS to  * force this file to never include any system headers.  *  * Some could argue that liblzma API should provide all the required types,  * for example lzma_uint64, LZMA_UINT64_C(n), and LZMA_UINT64_MAX. This was  * seen as an unnecessary mess, since most systems already provide all the  * necessary types and macros in the standard headers.  *  * Note that liblzma API still has lzma_bool, because using stdbool.h would  * break C89 and C++ programs on many systems. sizeof(bool) in C99 isn't  * necessarily the same as sizeof(bool) in C++.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_MANUAL_HEADERS
end_ifndef

begin_comment
comment|/* 	 * I suppose this works portably also in C++. Note that in C++, 	 * we need to get size_t into the global namespace. 	 */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* 	 * Skip inttypes.h if we already have all the required macros. If we 	 * have the macros, we assume that we have the matching typedefs too. 	 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|UINT32_C
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|UINT64_C
argument_list|)
expr|\
operator|||
operator|!
name|defined
argument_list|(
name|UINT32_MAX
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|UINT64_MAX
argument_list|)
end_if

begin_comment
comment|/* 		 * MSVC has no C99 support, and thus it cannot be used to 		 * compile liblzma. The liblzma API has to still be usable 		 * from MSVC, so we need to define the required standard 		 * integer types here. 		 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|__int8
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int32
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|uint64_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Use the standard inttypes.h. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_comment
comment|/* 				 * C99 sections 7.18.2 and 7.18.4 specify 				 * that C++ implementations define the limit 				 * and constant macros only if specifically 				 * requested. Note that if you want the 				 * format macros (PRIu64 etc.) too, you need 				 * to define __STDC_FORMAT_MACROS before 				 * including lzma.h, since re-including 				 * inttypes.h with __STDC_FORMAT_MACROS 				 * defined doesn't necessarily work. 				 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC_LIMIT_MACROS
end_ifndef

begin_define
define|#
directive|define
name|__STDC_LIMIT_MACROS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC_CONSTANT_MACROS
end_ifndef

begin_define
define|#
directive|define
name|__STDC_CONSTANT_MACROS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 		 * Some old systems have only the typedefs in inttypes.h, and 		 * lack all the macros. For those systems, we need a few more 		 * hacks. We assume that unsigned int is 32-bit and unsigned 		 * long is either 32-bit or 64-bit. If these hacks aren't 		 * enough, the application has to setup the types manually 		 * before including lzma.h. 		 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UINT32_C
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_define
define|#
directive|define
name|UINT32_C
parameter_list|(
name|n
parameter_list|)
value|n ## UI32
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UINT32_C
parameter_list|(
name|n
parameter_list|)
value|n ## U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UINT64_C
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|n
parameter_list|)
value|n ## UI64
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Get ULONG_MAX. */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_if
if|#
directive|if
name|ULONG_MAX
operator|==
literal|4294967295UL
end_if

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|n
parameter_list|)
value|n ## ULL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|n
parameter_list|)
value|n ## UL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UINT32_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINT32_MAX
value|(UINT32_C(4294967295))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UINT64_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINT64_MAX
value|(UINT64_C(18446744073709551615))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifdef LZMA_MANUAL_HEADERS */
end_comment

begin_comment
comment|/******************  * LZMA_API macro *  ******************/
end_comment

begin_comment
comment|/*  * Some systems require that the functions and function pointers are  * declared specially in the headers. LZMA_API_IMPORT is for importing  * symbols and LZMA_API_CALL is to specify the calling convention.  *  * By default it is assumed that the application will link dynamically  * against liblzma. #define LZMA_API_STATIC in your application if you  * want to link against static liblzma. If you don't care about portability  * to operating systems like Windows, or at least don't care about linking  * against static liblzma on them, don't worry about LZMA_API_STATIC. That  * is, most developers will never need to use LZMA_API_STATIC.  *  * The GCC variants are a special case on Windows (Cygwin and MinGW).  * We rely on GCC doing the right thing with its auto-import feature,  * and thus don't use __declspec(dllimport). This way developers don't  * need to worry about LZMA_API_STATIC. Also the calling convention is  * omitted on Cygwin but not on MinGW.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_API_IMPORT
end_ifndef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LZMA_API_STATIC
argument_list|)
operator|&&
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LZMA_API_IMPORT
value|__declspec(dllimport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LZMA_API_IMPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_API_CALL
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LZMA_API_CALL
value|__cdecl
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LZMA_API_CALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_API
end_ifndef

begin_define
define|#
directive|define
name|LZMA_API
parameter_list|(
name|type
parameter_list|)
value|LZMA_API_IMPORT type LZMA_API_CALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***********  * nothrow *  ***********/
end_comment

begin_comment
comment|/*  * None of the functions in liblzma may throw an exception. Even  * the functions that use callback functions won't throw exceptions,  * because liblzma would break if a callback function threw an exception.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lzma_nothrow
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|lzma_nothrow
value|throw()
end_define

begin_elif
elif|#
directive|elif
name|__GNUC__
operator|>
literal|3
operator|||
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|3
operator|)
end_elif

begin_define
define|#
directive|define
name|lzma_nothrow
value|__attribute__((__nothrow__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|lzma_nothrow
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/********************  * GNU C extensions *  ********************/
end_comment

begin_comment
comment|/*  * GNU C extensions are used conditionally in the public API. It doesn't  * break anything if these are sometimes enabled and sometimes not, only  * affects warnings and optimizations.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|3
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lzma_attribute
end_ifndef

begin_define
define|#
directive|define
name|lzma_attribute
parameter_list|(
name|attr
parameter_list|)
value|__attribute__(attr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* warn_unused_result was added in GCC 3.4. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lzma_attr_warn_unused_result
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|<
literal|4
end_if

begin_define
define|#
directive|define
name|lzma_attr_warn_unused_result
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|lzma_attribute
end_ifndef

begin_define
define|#
directive|define
name|lzma_attribute
parameter_list|(
name|attr
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|lzma_attr_pure
end_ifndef

begin_define
define|#
directive|define
name|lzma_attr_pure
value|lzma_attribute((__pure__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|lzma_attr_const
end_ifndef

begin_define
define|#
directive|define
name|lzma_attr_const
value|lzma_attribute((__const__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|lzma_attr_warn_unused_result
end_ifndef

begin_define
define|#
directive|define
name|lzma_attr_warn_unused_result
define|\
value|lzma_attribute((__warn_unused_result__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**************  * Subheaders *  **************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * Subheaders check that this is defined. It is to prevent including  * them directly from applications.  */
define|#
directive|define
name|LZMA_H_INTERNAL
value|1
comment|/* Basic features */
include|#
directive|include
file|"lzma/version.h"
include|#
directive|include
file|"lzma/base.h"
include|#
directive|include
file|"lzma/vli.h"
include|#
directive|include
file|"lzma/check.h"
comment|/* Filters */
include|#
directive|include
file|"lzma/filter.h"
include|#
directive|include
file|"lzma/bcj.h"
include|#
directive|include
file|"lzma/delta.h"
include|#
directive|include
file|"lzma/lzma12.h"
comment|/* Container formats */
include|#
directive|include
file|"lzma/container.h"
comment|/* Advanced features */
include|#
directive|include
file|"lzma/stream_flags.h"
include|#
directive|include
file|"lzma/block.h"
include|#
directive|include
file|"lzma/index.h"
include|#
directive|include
file|"lzma/index_hash.h"
comment|/* Hardware information */
include|#
directive|include
file|"lzma/hardware.h"
comment|/*  * All subheaders included. Undefine LZMA_H_INTERNAL to prevent applications  * re-including the subheaders.  */
undef|#
directive|undef
name|LZMA_H_INTERNAL
ifdef|#
directive|ifdef
name|__cplusplus
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
comment|/* ifndef LZMA_H */
end_comment

end_unit

