begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       sysdefs.h
end_comment

begin_comment
comment|/// \brief      Common includes, definitions, system-specific things etc.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file is used also by the lzma command line tool, that's why this
end_comment

begin_comment
comment|/// file is separate from common.h.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_SYSDEFS_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_SYSDEFS_H
end_define

begin_comment
comment|//////////////
end_comment

begin_comment
comment|// Includes //
end_comment

begin_comment
comment|//////////////
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Get standard-compliant stdio functions under MinGW and MinGW-w64.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__MINGW32__
end_ifdef

begin_define
define|#
directive|define
name|__USE_MINGW_ANSI_STDIO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// size_t and NULL
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_INTTYPES_H
end_ifdef

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
comment|// C99 says that inttypes.h always includes stdint.h, but some systems
end_comment

begin_comment
comment|// don't do that, and require including stdint.h separately.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDINT_H
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Some pre-C99 systems have SIZE_MAX in limits.h instead of stdint.h. The
end_comment

begin_comment
comment|// limits are also used to figure out some macros missing from pre-C99 systems.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Be more compatible with systems that have non-conforming inttypes.h.
end_comment

begin_comment
comment|// We assume that int is 32-bit and that long is either 32-bit or 64-bit.
end_comment

begin_comment
comment|// Full Autoconf test could be more correct, but this should work well enough.
end_comment

begin_comment
comment|// Note that this duplicates some code from lzma.h, but this is better since
end_comment

begin_comment
comment|// we can work without inttypes.h thanks to Autoconf tests.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UINT32_C
end_ifndef

begin_if
if|#
directive|if
name|UINT_MAX
operator|!=
literal|4294967295U
end_if

begin_error
error|#
directive|error
error|UINT32_C is not defined and unsigned int is not 32-bit.
end_error

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|UINT32_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINT32_MAX
value|UINT32_C(4294967295)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIu32
end_ifndef

begin_define
define|#
directive|define
name|PRIu32
value|"u"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIx32
end_ifndef

begin_define
define|#
directive|define
name|PRIx32
value|"x"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIX32
end_ifndef

begin_define
define|#
directive|define
name|PRIX32
value|"X"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ULONG_MAX
operator|==
literal|4294967295UL
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|UINT64_C
end_ifndef

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|n
parameter_list|)
value|n ## ULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIu64
end_ifndef

begin_define
define|#
directive|define
name|PRIu64
value|"llu"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIx64
end_ifndef

begin_define
define|#
directive|define
name|PRIx64
value|"llx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIX64
end_ifndef

begin_define
define|#
directive|define
name|PRIX64
value|"llX"
end_define

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
name|UINT64_C
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|PRIu64
end_ifndef

begin_define
define|#
directive|define
name|PRIu64
value|"lu"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIx64
end_ifndef

begin_define
define|#
directive|define
name|PRIx64
value|"lx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIX64
end_ifndef

begin_define
define|#
directive|define
name|PRIX64
value|"lX"
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
name|UINT64_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINT64_MAX
value|UINT64_C(18446744073709551615)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Incorrect(?) SIZE_MAX:
end_comment

begin_comment
comment|//   - Interix headers typedef size_t to unsigned long,
end_comment

begin_comment
comment|//     but a few lines later define SIZE_MAX to INT32_MAX.
end_comment

begin_comment
comment|//   - SCO OpenServer (x86) headers typedef size_t to unsigned int
end_comment

begin_comment
comment|//     but define SIZE_MAX to INT32_MAX.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__INTERIX
argument_list|)
operator|||
name|defined
argument_list|(
name|_SCO_DS
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|SIZE_MAX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// The code currently assumes that size_t is either 32-bit or 64-bit.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_MAX
end_ifndef

begin_if
if|#
directive|if
name|SIZEOF_SIZE_T
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|SIZE_MAX
value|UINT32_MAX
end_define

begin_elif
elif|#
directive|elif
name|SIZEOF_SIZE_T
operator|==
literal|8
end_elif

begin_define
define|#
directive|define
name|SIZE_MAX
value|UINT64_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|size_t is not 32-bit or 64-bit
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SIZE_MAX
operator|!=
name|UINT32_MAX
operator|&&
name|SIZE_MAX
operator|!=
name|UINT64_MAX
end_if

begin_error
error|#
directive|error
error|size_t is not 32-bit or 64-bit
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_comment
comment|// Pre-C99 systems lack stdbool.h. All the code in LZMA Utils must be written
end_comment

begin_comment
comment|// so that it works with fake bool type, for example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    bool foo = (flags& 0x100) != 0;
end_comment

begin_comment
comment|//    bool bar = !!(flags& 0x100);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This works with the real C99 bool but breaks with fake bool:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    bool baz = (flags& 0x100);
end_comment

begin_comment
comment|//
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDBOOL_H
end_ifdef

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|HAVE__BOOL
end_if

begin_typedef
typedef|typedef
name|unsigned
name|char
name|_Bool
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bool
value|_Bool
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|__bool_true_false_are_defined
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// string.h should be enough but let's include strings.h and memory.h too if
end_comment

begin_comment
comment|// they exists, since that shouldn't do any harm, but may improve portability.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRINGS_H
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MEMORY_H
end_ifdef

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// As of MSVC 2013, inline and restrict are supported with
end_comment

begin_comment
comment|// non-standard keywords.
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

begin_ifndef
ifndef|#
directive|ifndef
name|inline
end_ifndef

begin_define
define|#
directive|define
name|inline
value|__inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|restrict
end_ifndef

begin_define
define|#
directive|define
name|restrict
value|__restrict
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
comment|////////////
end_comment

begin_comment
comment|// Macros //
end_comment

begin_comment
comment|////////////
end_comment

begin_undef
undef|#
directive|undef
name|memzero
end_undef

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset(s, 0, n)
end_define

begin_comment
comment|// NOTE: Avoid using MIN() and MAX(), because even conditionally defining
end_comment

begin_comment
comment|// those macros can cause some portability trouble, since on some systems
end_comment

begin_comment
comment|// the system headers insist defining their own versions.
end_comment

begin_define
define|#
directive|define
name|my_min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)< (y) ? (x) : (y))
end_define

begin_define
define|#
directive|define
name|my_max
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)> (y) ? (x) : (y))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ARRAY_SIZE
end_ifndef

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|array
parameter_list|)
value|(sizeof(array) / sizeof((array)[0]))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__GNUC__
operator|==
literal|4
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|3
operator|)
operator|||
name|__GNUC__
operator|>
literal|4
end_if

begin_define
define|#
directive|define
name|lzma_attr_alloc_size
parameter_list|(
name|x
parameter_list|)
value|__attribute__((__alloc_size__(x)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|lzma_attr_alloc_size
parameter_list|(
name|x
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

end_unit

