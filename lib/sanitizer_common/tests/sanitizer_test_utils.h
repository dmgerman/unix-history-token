begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_test_utils.h ----------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is a part of *Sanitizer runtime.
end_comment

begin_comment
comment|// Common unit tests utilities.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_TEST_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_TEST_UTILS_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_comment
comment|//<windows.h> should always be the first include on Windows.
end_comment

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|// MSVS headers define max/min as macros, so std::max/min gets crazy.
end_comment

begin_undef
undef|#
directive|undef
name|max
end_undef

begin_undef
undef|#
directive|undef
name|min
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SANITIZER_EXTERNAL_TEST_CONFIG
argument_list|)
end_if

begin_define
define|#
directive|define
name|INCLUDED_FROM_SANITIZER_TEST_UTILS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_test_config.h"
end_include

begin_undef
undef|#
directive|undef
name|INCLUDED_FROM_SANITIZER_TEST_UTILS_H
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_define
define|#
directive|define
name|NOINLINE
value|__declspec(noinline)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// defined(_MSC_VER)
end_comment

begin_define
define|#
directive|define
name|NOINLINE
value|__attribute__((noinline))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(_MSC_VER)
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_define
define|#
directive|define
name|UNUSED
value|__attribute__((unused))
end_define

begin_define
define|#
directive|define
name|USED
value|__attribute__((used))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNUSED
end_define

begin_define
define|#
directive|define
name|USED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__has_feature
argument_list|)
end_if

begin_define
define|#
directive|define
name|__has_feature
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_NO_SANITIZE_ADDRESS
end_ifndef

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|address_sanitizer
argument_list|)
operator|||
name|defined
argument_list|(
name|__SANITIZE_ADDRESS__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATTRIBUTE_NO_SANITIZE_ADDRESS
define|\
value|__attribute__((no_sanitize_address))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_NO_SANITIZE_ADDRESS
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
comment|// ATTRIBUTE_NO_SANITIZE_ADDRESS
end_comment

begin_if
if|#
directive|if
name|__LP64__
operator|||
name|defined
argument_list|(
name|_WIN64
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_WORDSIZE
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_WORDSIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Make the compiler thinks that something is going on there.
end_comment

begin_function
specifier|inline
name|void
name|break_optimization
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
asm|__asm__
specifier|__volatile__
asm|("" : : "r" (arg) : "memory");
endif|#
directive|endif
block|}
end_function

begin_comment
comment|// This function returns its parameter but in such a way that compiler
end_comment

begin_comment
comment|// can not prove it.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|NOINLINE
specifier|static
name|T
name|Ident
argument_list|(
argument|T t
argument_list|)
block|{
name|T
name|ret
operator|=
name|t
block|;
name|break_optimization
argument_list|(
operator|&
name|ret
argument_list|)
block|;
return|return
name|ret
return|;
block|}
end_expr_stmt

begin_comment
comment|// Simple stand-alone pseudorandom number generator.
end_comment

begin_comment
comment|// Current algorithm is ANSI C linear congruential PRNG.
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|my_rand_r
parameter_list|(
name|uint32_t
modifier|*
name|state
parameter_list|)
block|{
return|return
operator|(
operator|*
name|state
operator|=
operator|*
name|state
operator|*
literal|1103515245
operator|+
literal|12345
operator|)
operator|>>
literal|16
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|uint32_t
name|global_seed
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|uint32_t
name|my_rand
parameter_list|()
block|{
return|return
name|my_rand_r
argument_list|(
operator|&
name|global_seed
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Set availability of platform-specific functions.
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ANDROID__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_POSIX_MEMALIGN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_POSIX_MEMALIGN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__ANDROID__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_MEMALIGN
value|1
end_define

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_PVALLOC
value|1
end_define

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_MALLOC_USABLE_SIZE
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_MEMALIGN
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_PVALLOC
value|0
end_define

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_MALLOC_USABLE_SIZE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_STRNLEN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_STRNLEN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_PRINTF_L
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_PRINTF_L
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_STRNDUP
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_TEST_HAS_STRNDUP
value|0
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
comment|// SANITIZER_TEST_UTILS_H
end_comment

end_unit

