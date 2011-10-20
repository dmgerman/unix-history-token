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

begin_comment
comment|// expected-warning {{Should have -Wparentheses}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_warning
argument_list|(
operator|-
name|Wfoo
argument_list|)
end_if

begin_comment
comment|// expected-error {{builtin warning check macro requires a parenthesized string}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|// expected-warning {{Not a valid warning flag}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

