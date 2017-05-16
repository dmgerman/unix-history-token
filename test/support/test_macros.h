begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===---------------------------- test_macros.h ---------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
name|SUPPORT_TEST_MACROS_HPP
end_ifndef

begin_define
define|#
directive|define
name|SUPPORT_TEST_MACROS_HPP
end_define

begin_include
include|#
directive|include
file|<ciso646>
end_include

begin_comment
comment|// Get STL specific macros like _LIBCPP_VERSION
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|push
end_pragma

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wvariadic-macros"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TEST_CONCAT1
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|X##Y
end_define

begin_define
define|#
directive|define
name|TEST_CONCAT
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|TEST_CONCAT1(X, Y)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__has_feature
end_ifdef

begin_define
define|#
directive|define
name|TEST_HAS_FEATURE
parameter_list|(
name|X
parameter_list|)
value|__has_feature(X)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_HAS_FEATURE
parameter_list|(
name|X
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__has_include
end_ifdef

begin_define
define|#
directive|define
name|TEST_HAS_INCLUDE
parameter_list|(
name|X
parameter_list|)
value|__has_include(X)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_HAS_INCLUDE
parameter_list|(
name|X
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__has_extension
end_ifdef

begin_define
define|#
directive|define
name|TEST_HAS_EXTENSION
parameter_list|(
name|X
parameter_list|)
value|__has_extension(X)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_HAS_EXTENSION
parameter_list|(
name|X
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__has_builtin
end_ifdef

begin_define
define|#
directive|define
name|TEST_HAS_BUILTIN
parameter_list|(
name|X
parameter_list|)
value|__has_builtin(X)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_HAS_BUILTIN
parameter_list|(
name|X
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__is_identifier
end_ifdef

begin_comment
comment|// '__is_identifier' returns '0' if '__x' is a reserved identifier provided by
end_comment

begin_comment
comment|// the compiler and '1' otherwise.
end_comment

begin_define
define|#
directive|define
name|TEST_HAS_BUILTIN_IDENTIFIER
parameter_list|(
name|X
parameter_list|)
value|!__is_identifier(X)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_HAS_BUILTIN_IDENTIFIER
parameter_list|(
name|X
parameter_list|)
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
name|__EDG__
argument_list|)
end_if

begin_define
define|#
directive|define
name|TEST_COMPILER_EDG
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__clang__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|TEST_COMPILER_CLANG
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__apple_build_version__
argument_list|)
end_if

begin_define
define|#
directive|define
name|TEST_COMPILER_APPLE_CLANG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_define
define|#
directive|define
name|TEST_COMPILER_C1XX
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|TEST_COMPILER_GCC
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
name|__apple_build_version__
argument_list|)
end_if

begin_define
define|#
directive|define
name|TEST_APPLE_CLANG_VER
value|(__clang_major__ * 100) + __clang_minor__
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__clang_major__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|TEST_CLANG_VER
value|(__clang_major__ * 100) + __clang_minor__
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|TEST_GCC_VER
value|(__GNUC__ * 100 + __GNUC_MINOR__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make a nice name for the standard version */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TEST_STD_VER
end_ifndef

begin_if
if|#
directive|if
name|__cplusplus
operator|<=
literal|199711L
end_if

begin_define
define|#
directive|define
name|TEST_STD_VER
value|3
end_define

begin_elif
elif|#
directive|elif
name|__cplusplus
operator|<=
literal|201103L
end_elif

begin_define
define|#
directive|define
name|TEST_STD_VER
value|11
end_define

begin_elif
elif|#
directive|elif
name|__cplusplus
operator|<=
literal|201402L
end_elif

begin_define
define|#
directive|define
name|TEST_STD_VER
value|14
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_STD_VER
value|16
end_define

begin_comment
comment|// current year; greater than current standard
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Attempt to deduce GCC version
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LIBCPP_VERSION
argument_list|)
operator|&&
name|TEST_HAS_INCLUDE
argument_list|(
operator|<
name|features
operator|.
name|h
operator|>
argument_list|)
end_if

begin_include
include|#
directive|include
file|<features.h>
end_include

begin_define
define|#
directive|define
name|TEST_HAS_GLIBC
end_define

begin_define
define|#
directive|define
name|TEST_GLIBC_PREREQ
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
value|__GLIBC_PREREQ(major, minor)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Features that were introduced in C++14 */
end_comment

begin_if
if|#
directive|if
name|TEST_STD_VER
operator|>=
literal|14
end_if

begin_define
define|#
directive|define
name|TEST_HAS_EXTENDED_CONSTEXPR
end_define

begin_define
define|#
directive|define
name|TEST_HAS_VARIABLE_TEMPLATES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Features that were introduced after C++14 */
end_comment

begin_if
if|#
directive|if
name|TEST_STD_VER
operator|>
literal|14
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TEST_STD_VER
operator|>=
literal|11
end_if

begin_define
define|#
directive|define
name|TEST_ALIGNOF
parameter_list|(
modifier|...
parameter_list|)
value|alignof(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|TEST_ALIGNAS
parameter_list|(
modifier|...
parameter_list|)
value|alignas(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|TEST_CONSTEXPR
value|constexpr
end_define

begin_define
define|#
directive|define
name|TEST_NOEXCEPT
value|noexcept
end_define

begin_define
define|#
directive|define
name|TEST_NOEXCEPT_FALSE
value|noexcept(false)
end_define

begin_define
define|#
directive|define
name|TEST_NOEXCEPT_COND
parameter_list|(
modifier|...
parameter_list|)
value|noexcept(__VA_ARGS__)
end_define

begin_if
if|#
directive|if
name|TEST_STD_VER
operator|>=
literal|14
end_if

begin_define
define|#
directive|define
name|TEST_CONSTEXPR_CXX14
value|constexpr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_CONSTEXPR_CXX14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TEST_STD_VER
operator|>
literal|14
end_if

begin_define
define|#
directive|define
name|TEST_THROW_SPEC
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_THROW_SPEC
parameter_list|(
modifier|...
parameter_list|)
value|throw(__VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_ALIGNOF
parameter_list|(
modifier|...
parameter_list|)
value|__alignof(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|TEST_ALIGNAS
parameter_list|(
modifier|...
parameter_list|)
value|__attribute__((__aligned__(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|TEST_CONSTEXPR
end_define

begin_define
define|#
directive|define
name|TEST_CONSTEXPR_CXX14
end_define

begin_define
define|#
directive|define
name|TEST_NOEXCEPT
value|throw()
end_define

begin_define
define|#
directive|define
name|TEST_NOEXCEPT_FALSE
end_define

begin_define
define|#
directive|define
name|TEST_NOEXCEPT_COND
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TEST_THROW_SPEC
parameter_list|(
modifier|...
parameter_list|)
value|throw(__VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TEST_ALIGNAS_TYPE
parameter_list|(
modifier|...
parameter_list|)
value|TEST_ALIGNAS(TEST_ALIGNOF(__VA_ARGS__))
end_define

begin_if
if|#
directive|if
operator|!
name|TEST_HAS_FEATURE
argument_list|(
name|cxx_rtti
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__cpp_rtti
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|__GXX_RTTI
argument_list|)
end_if

begin_define
define|#
directive|define
name|TEST_HAS_NO_RTTI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|TEST_HAS_FEATURE
argument_list|(
name|cxx_exceptions
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__cpp_exceptions
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|__EXCEPTIONS
argument_list|)
end_if

begin_define
define|#
directive|define
name|TEST_HAS_NO_EXCEPTIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TEST_HAS_FEATURE
argument_list|(
name|address_sanitizer
argument_list|)
operator|||
name|TEST_HAS_FEATURE
argument_list|(
name|memory_sanitizer
argument_list|)
operator|||
expr|\
name|TEST_HAS_FEATURE
argument_list|(
name|thread_sanitizer
argument_list|)
end_if

begin_define
define|#
directive|define
name|TEST_HAS_SANITIZERS
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
name|_LIBCPP_NORETURN
argument_list|)
end_if

begin_define
define|#
directive|define
name|TEST_NORETURN
value|_LIBCPP_NORETURN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_NORETURN
value|[[noreturn]]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TEST_STD_VER
operator|<
literal|11
end_if

begin_define
define|#
directive|define
name|ASSERT_NOEXCEPT
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASSERT_NOT_NOEXCEPT
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT_NOEXCEPT
parameter_list|(
modifier|...
parameter_list|)
define|\
value|static_assert(noexcept(__VA_ARGS__), "Operation must be noexcept")
end_define

begin_define
define|#
directive|define
name|ASSERT_NOT_NOEXCEPT
parameter_list|(
modifier|...
parameter_list|)
define|\
value|static_assert(!noexcept(__VA_ARGS__), "Operation must NOT be noexcept")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Macros for testing libc++ specific behavior and extensions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LIBCPP_VERSION
argument_list|)
end_if

begin_define
define|#
directive|define
name|LIBCPP_ASSERT
parameter_list|(
modifier|...
parameter_list|)
value|assert(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|LIBCPP_STATIC_ASSERT
parameter_list|(
modifier|...
parameter_list|)
value|static_assert(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|LIBCPP_ASSERT_NOEXCEPT
parameter_list|(
modifier|...
parameter_list|)
value|ASSERT_NOEXCEPT(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|LIBCPP_ASSERT_NOT_NOEXCEPT
parameter_list|(
modifier|...
parameter_list|)
value|ASSERT_NOT_NOEXCEPT(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|LIBCPP_ONLY
parameter_list|(
modifier|...
parameter_list|)
value|__VA_ARGS__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBCPP_ASSERT
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|LIBCPP_STATIC_ASSERT
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|LIBCPP_ASSERT_NOEXCEPT
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|LIBCPP_ASSERT_NOT_NOEXCEPT
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|LIBCPP_ONLY
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|test_macros_detail
block|{
name|template
operator|<
name|class
name|T
operator|,
name|class
name|U
operator|>
expr|struct
name|is_same
block|{ enum
block|{
name|value
operator|=
literal|0
block|}
block|;}
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|is_same
operator|<
name|T
operator|,
name|T
operator|>
block|{ enum
block|{
name|value
operator|=
literal|1
block|}
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace test_macros_detail
end_comment

begin_define
define|#
directive|define
name|ASSERT_SAME_TYPE
parameter_list|(
modifier|...
parameter_list|)
define|\
value|static_assert((test_macros_detail::is_same<__VA_ARGS__>::value), \                  "Types differ uexpectedly")
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TEST_HAS_NO_EXCEPTIONS
end_ifndef

begin_define
define|#
directive|define
name|TEST_THROW
parameter_list|(
modifier|...
parameter_list|)
value|throw __VA_ARGS__
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|TEST_THROW
parameter_list|(
modifier|...
parameter_list|)
value|__builtin_abort()
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|TEST_THROW
parameter_list|(
modifier|...
parameter_list|)
value|::abort()
end_define

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
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_expr_stmt
name|template
operator|<
name|class
name|Tp
operator|>
specifier|inline
name|void
name|DoNotOptimize
argument_list|(
argument|Tp const& value
argument_list|)
block|{
name|asm
specifier|volatile
operator|(
literal|""
operator|:
operator|:
literal|"g"
operator|(
name|value
operator|)
operator|:
literal|"memory"
operator|)
block|; }
else|#
directive|else
include|#
directive|include
file|<intrin.h>
name|template
operator|<
name|class
name|Tp
operator|>
specifier|inline
name|void
name|DoNotOptimize
argument_list|(
argument|Tp const& value
argument_list|)
block|{
specifier|const
specifier|volatile
name|void
operator|*
specifier|volatile
name|unused
operator|=
name|__builtin_addressof
argument_list|(
name|value
argument_list|)
block|;
name|static_cast
operator|<
name|void
operator|>
operator|(
name|unused
operator|)
block|;
name|_ReadWriteBarrier
argument_list|()
block|; }
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|pop
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SUPPORT_TEST_MACROS_HPP
end_comment

end_unit

