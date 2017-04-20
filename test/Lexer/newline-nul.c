begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s -verify
end_comment

begin_comment
comment|// We used to crash if a line continuation was followed by a nul byte within a
end_comment

begin_comment
comment|// preprocessing directive.
end_comment

begin_if
if|#
directive|if
literal|1
expr|\
expr|#if
name|something_else
end_if

begin_comment
comment|// expected-warning {{null character ignored}} expected-error {{not a valid binary operator}}
end_comment

begin_error
error|#
directive|error
error|error
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error {{#endif without #if}}
end_comment

end_unit

