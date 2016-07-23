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
name|TEST_CONSTEXPR
value|constexpr
end_define

begin_define
define|#
directive|define
name|TEST_NOEXCEPT
value|noexcept
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

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

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
value|static_assert(test_macros_detail::is_same<__VA_ARGS__>::value, \                  "Types differ uexpectedly")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SUPPORT_TEST_MACROS_HPP
end_comment

end_unit

