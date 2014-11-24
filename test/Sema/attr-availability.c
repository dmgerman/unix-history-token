begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 -fsyntax-only -fblocks -verify %s
end_comment

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
literal|10.4
parameter_list|,
name|deprecated
init|=
literal|10.2
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning{{feature cannot be deprecated in OS X version 10.2 before it was introduced in version 10.4; attribute ignored}}
end_comment

begin_function_decl
name|void
name|f1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|obsoleted
init|=
literal|2.1
parameter_list|,
name|deprecated
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning{{feature cannot be obsoleted in iOS version 2.1 before it was deprecated in version 3.0; attribute ignored}}
end_comment

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
name|introduced
init|=
literal|2.1
parameter_list|,
name|deprecated
init|=
literal|2.1
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
name|otheros
parameter_list|,
name|introduced
init|=
literal|2.2
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning{{unknown platform 'otheros' in availability macro}}
end_comment

begin_comment
comment|// rdar://10095131
end_comment

begin_function_decl
specifier|extern
name|void
name|ATSFontGetName
parameter_list|(
specifier|const
name|char
modifier|*
name|oName
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|8.0
parameter_list|,
name|deprecated
init|=
literal|9.0
parameter_list|,
name|message
init|=
literal|"use CTFontCopyFullName"
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{'ATSFontGetName' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
specifier|extern
name|void
name|ATSFontGetPostScriptName
parameter_list|(
name|int
name|flags
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|8.0
parameter_list|,
name|obsoleted
init|=
literal|9.0
parameter_list|,
name|message
init|=
literal|"use ATSFontGetFullPostScriptName"
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{'ATSFontGetPostScriptName' has been explicitly marked unavailable here}}
end_comment

begin_function
name|void
name|test_10095131
parameter_list|()
block|{
name|ATSFontGetName
argument_list|(
literal|"Hello"
argument_list|)
expr_stmt|;
comment|// expected-warning {{'ATSFontGetName' is deprecated: first deprecated in OS X 9.0 - use CTFontCopyFullName}}
name|ATSFontGetPostScriptName
argument_list|(
literal|100
argument_list|)
expr_stmt|;
comment|// expected-error {{'ATSFontGetPostScriptName' is unavailable: obsoleted in OS X 9.0 - use ATSFontGetFullPostScriptName}}
block|}
end_function

begin_comment
comment|// rdar://10711037
end_comment

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macos
argument_list|,
name|unavailable
argument_list|)
operator|)
argument_list|)
comment|// expected-warning {{attribute 'availability' is ignored}}
expr|enum
block|{
name|NSDataWritingFileProtectionWriteOnly
operator|=
literal|0x30000000
block|,
name|NSDataWritingFileProtectionCompleteUntilUserAuthentication
operator|=
literal|0x40000000
block|, }
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|f4
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|deprecated
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f4
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|4.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{feature cannot be deprecated in iOS version 3.0 before it was introduced in version 4.0; attribute ignored}}
end_comment

begin_function_decl
name|void
name|f5
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|deprecated
init|=
literal|3.0
parameter_list|)
operator|,
function_decl|availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|4.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{feature cannot be deprecated in iOS version 3.0 before it was introduced in version 4.0; attribute ignored}}
end_comment

begin_function_decl
name|void
name|f6
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|deprecated
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{previous attribute is here}}
end_comment

begin_function_decl
name|void
name|f6
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|deprecated
init|=
literal|4.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{availability does not match previous declaration}}
end_comment

begin_function_decl
name|void
name|f7
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f7
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|deprecated
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{previous attribute is here}}
end_comment

begin_function_decl
name|void
name|f7
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|deprecated
init|=
literal|4.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{availability does not match previous declaration}}
end_comment

begin_comment
comment|//<rdar://problem/11886458>
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|attribute_availability_with_message
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Missing __has_feature"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macosx
argument_list|,
name|introduced
operator|=
literal|10.5
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f8
parameter_list|()
block|{
name|int
function_decl|(
modifier|^
name|b
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|b
operator|=
operator|^
operator|(
name|int
name|i
operator|)
name|__attribute__
argument_list|(
argument|(availability(macosx,introduced=
literal|10.2
argument|))
argument_list|)
block|{
return|return
literal|1
return|;
block|}
empty_stmt|;
comment|// expected-warning {{'availability' attribute ignored}}
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|x2
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macosx
argument_list|,
name|introduced
operator|=
literal|10.2
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous attribute is here}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x2
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|macosx
argument_list|,
name|introduced
operator|=
literal|10.5
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{availability does not match previous declaration}}
end_comment

end_unit

