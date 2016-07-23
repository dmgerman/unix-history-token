begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=i686-apple-darwin9 -verify -DVERIFY
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -triple=i686-apple-darwin9
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__has_feature
end_ifndef

begin_error
error|#
directive|error
error|Should have __has_feature
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|something_we_dont_have
argument_list|)
end_if

begin_error
error|#
directive|error
error|Bad
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|__has_builtin
argument_list|(
name|__builtin_huge_val
argument_list|)
operator|||
expr|\
operator|!
name|__has_builtin
argument_list|(
name|__builtin_shufflevector
argument_list|)
operator|||
expr|\
operator|!
name|__has_builtin
argument_list|(
name|__builtin_convertvector
argument_list|)
operator|||
expr|\
operator|!
name|__has_builtin
argument_list|(
name|__builtin_trap
argument_list|)
operator|||
expr|\
operator|!
name|__has_builtin
argument_list|(
name|__c11_atomic_init
argument_list|)
operator|||
expr|\
operator|!
name|__has_feature
argument_list|(
name|attribute_analyzer_noreturn
argument_list|)
operator|||
expr|\
operator|!
name|__has_feature
argument_list|(
name|attribute_overloadable
argument_list|)
end_if

begin_error
error|#
directive|error
error|Clang should have these
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_insanity
argument_list|)
end_if

begin_error
error|#
directive|error
error|Clang should not have this
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|__attribute_deprecated_with_message__
argument_list|)
end_if

begin_error
error|#
directive|error
error|Feature name in double underscores does not work
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Make sure we have x86 builtins only (forced with target triple).
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_builtin
argument_list|(
name|__builtin_ia32_emms
argument_list|)
operator|||
expr|\
name|__has_builtin
argument_list|(
name|__builtin_altivec_abs_v4sf
argument_list|)
end_if

begin_error
error|#
directive|error
error|Broken handling of target-specific builtins
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Macro expansion does not occur in the parameter to __has_builtin,
end_comment

begin_comment
comment|// __has_feature, etc. (as is also expected behaviour for ordinary
end_comment

begin_comment
comment|// macros), so the following should not expand:
end_comment

begin_define
define|#
directive|define
name|MY_ALIAS_BUILTIN
value|__c11_atomic_init
end_define

begin_define
define|#
directive|define
name|MY_ALIAS_FEATURE
value|attribute_overloadable
end_define

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|MY_ALIAS_BUILTIN
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|MY_ALIAS_FEATURE
argument_list|)
end_if

begin_error
error|#
directive|error
error|Alias expansion not allowed
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// But deferring should expand:
end_comment

begin_define
define|#
directive|define
name|HAS_BUILTIN
parameter_list|(
name|X
parameter_list|)
value|__has_builtin(X)
end_define

begin_define
define|#
directive|define
name|HAS_FEATURE
parameter_list|(
name|X
parameter_list|)
value|__has_feature(X)
end_define

begin_if
if|#
directive|if
operator|!
name|HAS_BUILTIN
argument_list|(
name|MY_ALIAS_BUILTIN
argument_list|)
operator|||
operator|!
name|HAS_FEATURE
argument_list|(
name|MY_ALIAS_FEATURE
argument_list|)
end_if

begin_error
error|#
directive|error
error|Expansion should have occurred
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VERIFY
end_ifdef

begin_comment
comment|// expected-error@+1 {{builtin feature check macro requires a parenthesized identifier}}
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
literal|'x'
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// The following are not identifiers:
end_comment

begin_assert
assert|_Static_assert
argument_list|(
operator|!
name|__is_identifier
argument_list|(
literal|"string"
argument_list|)
argument_list|,
literal|"oops"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
operator|!
name|__is_identifier
argument_list|(
literal|'c'
argument_list|)
argument_list|,
literal|"oops"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
operator|!
name|__is_identifier
argument_list|(
literal|123
argument_list|)
argument_list|,
literal|"oops"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
operator|!
name|__is_identifier
argument_list|(
name|int
argument_list|)
argument_list|,
literal|"oops"
argument_list|)
assert|;
end_assert

begin_comment
comment|// The following are:
end_comment

begin_assert
assert|_Static_assert
argument_list|(
name|__is_identifier
argument_list|(
name|abc
comment|/* comment */
argument_list|)
argument_list|,
literal|"oops"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|__is_identifier
comment|/* comment */
argument_list|(
name|xyz
argument_list|)
argument_list|,
literal|"oops"
argument_list|)
assert|;
end_assert

begin_comment
comment|// expected-error@+1 {{too few arguments}}
end_comment

begin_if
if|#
directive|if
name|__is_identifier
argument_list|()
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+1 {{too many arguments}}
end_comment

begin_if
if|#
directive|if
name|__is_identifier
argument_list|(
name|,
operator|(
operator|)
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+1 {{missing ')' after 'abc'}}
end_comment

begin_if
if|#
directive|if
name|__is_identifier
argument_list|(
argument|abc xyz
argument_list|)
end_if

begin_comment
comment|// expected-note {{to match this '('}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+1 {{missing ')' after 'abc'}}
end_comment

begin_if
if|#
directive|if
name|__is_identifier
argument_list|(
name|abc
argument_list|()
argument_list|)
end_if

begin_comment
comment|// expected-note {{to match this '('}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+1 {{missing ')' after '.'}}
end_comment

begin_if
if|#
directive|if
name|__is_identifier
argument_list|(
operator|.
name|abc
argument_list|)
end_if

begin_comment
comment|// expected-note {{to match this '('}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+1 {{nested parentheses not permitted in '__is_identifier'}}
end_comment

begin_if
if|#
directive|if
name|__is_identifier
argument_list|(
operator|(
name|abc
operator|)
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+1 {{missing '(' after '__is_identifier'}} expected-error@+1 {{expected value}}
end_comment

begin_if
if|#
directive|if
name|__is_identifier
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+1 {{unterminated}} expected-error@+1 {{expected value}}
end_comment

begin_if
if|#
directive|if
name|__is_identifier
argument_list|(
argument|#endif  #endif
end_if

end_unit

