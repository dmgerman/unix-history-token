begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|attribute_availability
argument_list|)
end_if

begin_error
error|#
directive|error
literal|'availability'
error|attribute is not available
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|f0
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.2
parameter_list|,
name|deprecated
init|=
literal|10.4
parameter_list|,
name|obsoleted
init|=
literal|10.6
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|deprecated
init|=
literal|10.4
parameter_list|,
name|introduced
init|=
literal|10.2
parameter_list|,
name|obsoleted
init|=
literal|10.6
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|deprecated
init|=
literal|10.4.7
parameter_list|,
name|introduced
init|=
literal|10
parameter_list|,
name|obsoleted
init|=
literal|10.6
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|deprecated
init|=
literal|10.4.7
parameter_list|,
name|introduced
init|=
literal|10
parameter_list|,
name|obsoleted
init|=
literal|10.6
parameter_list|,
name|introduced
init|=
literal|10.2
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{redundant 'introduced' availability change; only the last specified change will be used}}
end_comment

begin_function_decl
name|void
name|f4
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.5
parameter_list|)
operator|,
function_decl|availability
parameter_list|(
name|ios
parameter_list|,
name|unavailable
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f5
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.5
parameter_list|)
operator|,
function_decl|availability
parameter_list|(
name|ios
parameter_list|,
name|unavailable
parameter_list|,
name|unavailable
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{redundant 'unavailable' availability change; only the last specified change will be used}}
end_comment

begin_function_decl
name|void
name|f6
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|unavailable
parameter_list|,
name|introduced
init|=
literal|10.5
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning{{'unavailable' availability overrides all other availability information}}
end_comment

begin_function_decl
name|void
name|f7
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|message
init|=
literal|L"wide"
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{expected string literal for optional message in 'availability' attribute}}
end_comment

begin_function_decl
name|void
name|f8
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|message
init|=
literal|"a"
literal|L"b"
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{expected string literal for optional message in 'availability' attribute}}
end_comment

begin_comment
comment|// rdar://10095131
end_comment

begin_enum
enum|enum
name|E
block|{
name|gorf
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macosx
argument_list|,
name|introduced
operator|=
literal|8.5
argument_list|,
name|message
operator|=
literal|10.0
argument_list|)
operator|)
argument_list|)
block|,
comment|// expected-error {{expected string literal for optional message in 'availability' attribute}}
name|garf
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macosx
argument_list|,
name|introduced
operator|=
literal|8.5
argument_list|,
name|message
argument_list|)
operator|)
argument_list|)
block|,
comment|// expected-error {{expected '=' after 'message'}}
name|foo
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macosx
argument_list|,
name|introduced
operator|=
literal|8.5
argument_list|,
name|deprecated
operator|=
literal|9.0
argument_list|,
name|message
operator|=
literal|"Use CTFontCopyPostScriptName()"
argument_list|,
name|deprecated
operator|=
literal|10.0
argument_list|)
operator|)
argument_list|)
comment|// expected-error {{expected ')'}} \
comment|// expected-note {{to match this '('}}
block|}
enum|;
end_enum

end_unit

