begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 -fsyntax-only -verify %s
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
comment|// expected-warning{{feature cannot be deprecated in Mac OS X version 10.2 before it was introduced in version 10.4; attribute ignored}}
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
comment|// expected-note {{function has been explicitly marked unavailable here}}
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
comment|// expected-warning {{'ATSFontGetName' is deprecated: first deprecated in Mac OS X 9.0 - use CTFontCopyFullName}}
name|ATSFontGetPostScriptName
argument_list|(
literal|100
argument_list|)
expr_stmt|;
comment|// expected-error {{'ATSFontGetPostScriptName' is unavailable: obsoleted in Mac OS X 9.0 - use ATSFontGetFullPostScriptName}}
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

end_unit

