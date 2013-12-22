begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c11 -fsyntax-only -triple x86_64-pc-linux -verify %s
end_comment

begin_comment
comment|// Note: these match the types specified by the target above.
end_comment

begin_typedef
typedef|typedef
name|int
name|wchar_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|char16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|char32_t
typedef|;
end_typedef

begin_function
name|void
name|f
parameter_list|()
block|{
name|char
name|a1
index|[]
init|=
literal|"a"
decl_stmt|;
comment|// No error.
name|char
name|a2
index|[]
init|=
literal|u8"a"
decl_stmt|;
comment|// No error.
name|char
name|a3
index|[]
init|=
literal|u"a"
decl_stmt|;
comment|// expected-error{{initializing char array with wide string literal}}
name|char
name|a4
index|[]
init|=
literal|U"a"
decl_stmt|;
comment|// expected-error{{initializing char array with wide string literal}}
name|char
name|a5
index|[]
init|=
literal|L"a"
decl_stmt|;
comment|// expected-error{{initializing char array with wide string literal}}
name|wchar_t
name|b1
index|[]
init|=
literal|"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with non-wide string literal}}
name|wchar_t
name|b2
index|[]
init|=
literal|u8"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with non-wide string literal}}
name|wchar_t
name|b3
index|[]
init|=
literal|u"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with incompatible wide string literal}}
name|wchar_t
name|b4
index|[]
init|=
literal|U"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with incompatible wide string literal}}
name|wchar_t
name|b5
index|[]
init|=
literal|L"a"
decl_stmt|;
comment|// No error.
name|char16_t
name|c1
index|[]
init|=
literal|"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with non-wide string literal}}
name|char16_t
name|c2
index|[]
init|=
literal|u8"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with non-wide string literal}}
name|char16_t
name|c3
index|[]
init|=
literal|u"a"
decl_stmt|;
comment|// No error.
name|char16_t
name|c4
index|[]
init|=
literal|U"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with incompatible wide string literal}}
name|char16_t
name|c5
index|[]
init|=
literal|L"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with incompatible wide string literal}}
name|char32_t
name|d1
index|[]
init|=
literal|"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with non-wide string literal}}
name|char32_t
name|d2
index|[]
init|=
literal|u8"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with non-wide string literal}}
name|char32_t
name|d3
index|[]
init|=
literal|u"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with incompatible wide string literal}}
name|char32_t
name|d4
index|[]
init|=
literal|U"a"
decl_stmt|;
comment|// No error.
name|char32_t
name|d5
index|[]
init|=
literal|L"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with incompatible wide string literal}}
name|int
name|e1
index|[]
init|=
literal|"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with non-wide string literal}}
name|int
name|e2
index|[]
init|=
literal|u8"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with non-wide string literal}}
name|int
name|e3
index|[]
init|=
literal|u"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with incompatible wide string literal}}
name|int
name|e4
index|[]
init|=
literal|U"a"
decl_stmt|;
comment|// expected-error{{initializing wide char array with incompatible wide string literal}}
name|int
name|e5
index|[]
init|=
literal|L"a"
decl_stmt|;
comment|// No error.
name|long
name|f1
index|[]
init|=
literal|"a"
decl_stmt|;
comment|// expected-error{{array initializer must be an initializer list}}
name|long
name|f2
index|[]
init|=
literal|u8"a"
decl_stmt|;
comment|// expected-error{{array initializer must be an initializer list}}}
name|long
name|f3
index|[]
init|=
literal|u"a"
decl_stmt|;
comment|// expected-error{{array initializer must be an initializer list}}
name|long
name|f4
index|[]
init|=
literal|U"a"
decl_stmt|;
comment|// expected-error{{array initializer must be an initializer list}}
name|long
name|f5
index|[]
init|=
literal|L"a"
decl_stmt|;
comment|// expected-error{{array initializer must be an initializer list}}
block|}
end_function

begin_function
name|void
name|g
parameter_list|()
block|{
name|char
name|a
index|[]
init|=
literal|1
decl_stmt|;
comment|// expected-error{{array initializer must be an initializer list or string literal}}
name|wchar_t
name|b
index|[]
init|=
literal|1
decl_stmt|;
comment|// expected-error{{array initializer must be an initializer list or wide string literal}}
name|char16_t
name|c
index|[]
init|=
literal|1
decl_stmt|;
comment|// expected-error{{array initializer must be an initializer list or wide string literal}}
name|char32_t
name|d
index|[]
init|=
literal|1
decl_stmt|;
comment|// expected-error{{array initializer must be an initializer list or wide string literal}}
block|}
end_function

end_unit

