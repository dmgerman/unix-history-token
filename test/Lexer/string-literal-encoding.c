begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++0x -fsyntax-only -verify %s
end_comment

begin_comment
comment|// This file should be encoded using ISO-8859-1, the string literals should
end_comment

begin_comment
comment|// contain the ISO-8859-1 encoding for the code points U+00C0 U+00E9 U+00EE
end_comment

begin_comment
comment|// U+00F5 U+00FC
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|wchar_t
specifier|const
modifier|*
name|a
init|=
literal|L"Àéîõü"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|char16_t
specifier|const
modifier|*
name|b
init|=
literal|u"Àéîõü"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|char32_t
specifier|const
modifier|*
name|c
init|=
literal|U"Àéîõü"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|wchar_t
specifier|const
modifier|*
name|d
init|=
name|LR
literal|"(Àéîõü)"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|char16_t
specifier|const
modifier|*
name|e
init|=
name|uR
literal|"(Àéîõü)"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|char32_t
specifier|const
modifier|*
name|f
init|=
name|UR
literal|"(Àéîõü)"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|char
specifier|const
modifier|*
name|g
init|=
literal|"Àéîõü"
decl_stmt|;
comment|// expected-warning {{illegal character encoding in string literal}}
name|char
specifier|const
modifier|*
name|h
init|=
literal|u8"Àéîõü"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|char
specifier|const
modifier|*
name|i
init|=
name|R
literal|"(Àéîõü)"
decl_stmt|;
comment|// expected-warning {{illegal character encoding in string literal}}
block|}
end_function

begin_function
name|void
name|g
parameter_list|()
block|{
name|wchar_t
specifier|const
modifier|*
name|a
init|=
literal|L"foo Àéîõü"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|char16_t
specifier|const
modifier|*
name|b
init|=
literal|u"foo Àéîõü"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|char32_t
specifier|const
modifier|*
name|c
init|=
literal|U"foo Àéîõü"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|wchar_t
specifier|const
modifier|*
name|d
init|=
name|LR
literal|"(foo Àéîõü)"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|char16_t
specifier|const
modifier|*
name|e
init|=
name|uR
literal|"(foo Àéîõü)"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|char32_t
specifier|const
modifier|*
name|f
init|=
name|UR
literal|"(foo Àéîõü)"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|char
specifier|const
modifier|*
name|g
init|=
literal|"foo Àéîõü"
decl_stmt|;
comment|// expected-warning {{illegal character encoding in string literal}}
name|char
specifier|const
modifier|*
name|h
init|=
literal|u8"foo Àéîõü"
decl_stmt|;
comment|// expected-error {{illegal character encoding in string literal}}
name|char
specifier|const
modifier|*
name|i
init|=
name|R
literal|"(foo Àéîõü)"
decl_stmt|;
comment|// expected-warning {{illegal character encoding in string literal}}
block|}
end_function

end_unit

