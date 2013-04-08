begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__has_warning
end_ifndef

begin_error
error|#
directive|error
error|Should have __has_warning
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_warning
argument_list|(
literal|"not valid"
argument_list|)
end_if

begin_comment
comment|// expected-warning {{__has_warning expected option name}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-warning@+2 {{Should have -Wparentheses}}
end_comment

begin_if
if|#
directive|if
name|__has_warning
argument_list|(
literal|"-Wparentheses"
argument_list|)
end_if

begin_warning
warning|#
directive|warning
warning|Should have -Wparentheses
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+2 {{expected string literal in '__has_warning'}}
end_comment

begin_comment
comment|// expected-error@+1 {{expected value in expression}}
end_comment

begin_if
if|#
directive|if
name|__has_warning
argument_list|(
operator|-
name|Wfoo
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-warning@+3 {{Not a valid warning flag}}
end_comment

begin_if
if|#
directive|if
name|__has_warning
argument_list|(
literal|"-Wnot-a-valid-warning-flag-at-all"
argument_list|)
end_if

begin_else
else|#
directive|else
end_else

begin_warning
warning|#
directive|warning
warning|Not a valid warning flag
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+2 {{builtin warning check macro requires a parenthesized string}}
end_comment

begin_comment
comment|// expected-error@+1 {{invalid token}}
end_comment

begin_if
if|#
directive|if
name|__has_warning
literal|"not valid"
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Macro expansion does not occur in the parameter to __has_warning
end_comment

begin_comment
comment|// (as is also expected behaviour for ordinary macros), so the
end_comment

begin_comment
comment|// following should not expand:
end_comment

begin_define
define|#
directive|define
name|MY_ALIAS
value|"-Wparentheses"
end_define

begin_comment
comment|// expected-error@+1 2{{expected}}
end_comment

begin_if
if|#
directive|if
name|__has_warning
argument_list|(
name|MY_ALIAS
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
name|HAS_WARNING
parameter_list|(
name|X
parameter_list|)
value|__has_warning(X)
end_define

begin_if
if|#
directive|if
operator|!
name|HAS_WARNING
argument_list|(
name|MY_ALIAS
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

end_unit

