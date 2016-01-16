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
value|99
end_define

begin_comment
comment|// greater than current standard
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Features that were introduced in C++11 */
end_comment

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
name|TEST_HAS_RVALUE_REFERENCES
end_define

begin_define
define|#
directive|define
name|TEST_HAS_VARIADIC_TEMPLATES
end_define

begin_define
define|#
directive|define
name|TEST_HAS_INITIALIZER_LISTS
end_define

begin_define
define|#
directive|define
name|TEST_HAS_BASIC_CONSTEXPR
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
name|TEST_HAS_EXTENSION
argument_list|(
name|cxx_decltype
argument_list|)
operator|||
name|TEST_STD_VER
operator|>=
literal|11
end_if

begin_define
define|#
directive|define
name|TEST_DECLTYPE
parameter_list|(
name|T
parameter_list|)
value|decltype(T)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_DECLTYPE
parameter_list|(
name|T
parameter_list|)
value|__typeof__(T)
end_define

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
name|TEST_NOEXCEPT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TEST_HAS_EXTENSION
argument_list|(
name|cxx_static_assert
argument_list|)
operator|||
name|TEST_STD_VER
operator|>=
literal|11
end_if

begin_define
define|#
directive|define
name|TEST_STATIC_ASSERT
parameter_list|(
name|Expr
parameter_list|,
name|Msg
parameter_list|)
value|static_assert(Expr, Msg)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TEST_STATIC_ASSERT
parameter_list|(
name|Expr
parameter_list|,
name|Msg
parameter_list|)
define|\
value|typedef ::test_detail::static_assert_check<sizeof(         \           ::test_detail::static_assert_incomplete_test<(Expr)>)> \     TEST_CONCAT(test_assert, __LINE__)
end_define

begin_empty
empty|#
end_empty

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|test_detail
block|{
name|template
operator|<
name|bool
operator|>
expr|struct
name|static_assert_incomplete_test
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|static_assert_incomplete_test
operator|<
name|true
operator|>
block|{}
expr_stmt|;
name|template
operator|<
name|unsigned
operator|>
expr|struct
name|static_assert_check
block|{}
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace test_detail
end_comment

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
name|__cxx_rtti
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
name|__cxx_exceptions
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SUPPORT_TEST_MACROS_HPP
end_comment

end_unit

