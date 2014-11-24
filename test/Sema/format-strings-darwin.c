begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple i386-apple-darwin9 -Wformat-non-iso -DALLOWED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple thumbv6-apple-ios4.0 -Wformat-non-iso -DALLOWED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-mingw32 -Wformat-non-iso %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple i686-pc-win32 -Wformat-non-iso %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple i686-linux-gnu -Wformat-non-iso %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-unknown-freebsd -Wformat-non-iso %s
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scanf
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|()
block|{
name|int
name|justRight
init|=
literal|1
decl_stmt|;
name|long
name|tooLong
init|=
literal|2
decl_stmt|;
name|printf
argument_list|(
literal|"%D"
argument_list|,
name|justRight
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%D"
argument_list|,
name|tooLong
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%U"
argument_list|,
name|justRight
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%U"
argument_list|,
name|tooLong
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%O"
argument_list|,
name|justRight
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%O"
argument_list|,
name|tooLong
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ALLOWED
comment|// expected-warning@-8 {{'D' conversion specifier is not supported by ISO C}} expected-note@-8 {{did you mean to use 'd'?}}
comment|// expected-warning@-8 {{'D' conversion specifier is not supported by ISO C}} expected-note@-8 {{did you mean to use 'd'?}} expected-warning@-8 {{format specifies type 'int' but the argument has type 'long'}}
comment|// expected-warning@-8 {{'U' conversion specifier is not supported by ISO C}} expected-note@-8 {{did you mean to use 'u'?}}
comment|// expected-warning@-8 {{'U' conversion specifier is not supported by ISO C}} expected-note@-8 {{did you mean to use 'u'?}} expected-warning@-8 {{format specifies type 'unsigned int' but the argument has type 'long'}}
comment|// expected-warning@-8 {{'O' conversion specifier is not supported by ISO C}} expected-note@-8 {{did you mean to use 'o'?}}
comment|// expected-warning@-8 {{'O' conversion specifier is not supported by ISO C}} expected-note@-8 {{did you mean to use 'o'?}} expected-warning@-8 {{format specifies type 'unsigned int' but the argument has type 'long'}}
else|#
directive|else
comment|// expected-warning@-15 {{invalid conversion specifier 'D'}}
comment|// expected-warning@-15 {{invalid conversion specifier 'D'}}
comment|// expected-warning@-15 {{invalid conversion specifier 'U'}}
comment|// expected-warning@-15 {{invalid conversion specifier 'U'}}
comment|// expected-warning@-15 {{invalid conversion specifier 'O'}}
comment|// expected-warning@-15 {{invalid conversion specifier 'O'}}
endif|#
directive|endif
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|ALLOWED
end_ifdef

begin_function
name|void
name|testPrintf
parameter_list|(
name|short
name|x
parameter_list|,
name|long
name|y
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%hD"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'd'?}}
name|printf
argument_list|(
literal|"%lD"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'd'?}}
name|printf
argument_list|(
literal|"%hU"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'u'?}}
name|printf
argument_list|(
literal|"%lU"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'u'?}}
name|printf
argument_list|(
literal|"%hO"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'o'?}}
name|printf
argument_list|(
literal|"%lO"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'o'?}}
name|printf
argument_list|(
literal|"%+'0.5lD"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'd'?}}
name|printf
argument_list|(
literal|"% '0.5lD"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'd'?}}
name|printf
argument_list|(
literal|"%#0.5lO"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'o'?}}
name|printf
argument_list|(
literal|"%'0.5lU"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'u'?}}
block|}
end_function

begin_function
name|void
name|testScanf
parameter_list|(
name|short
modifier|*
name|x
parameter_list|,
name|long
modifier|*
name|y
parameter_list|)
block|{
name|scanf
argument_list|(
literal|"%hD"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'd'?}}
name|scanf
argument_list|(
literal|"%lD"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'd'?}}
name|scanf
argument_list|(
literal|"%hU"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'u'?}}
name|scanf
argument_list|(
literal|"%lU"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'u'?}}
name|scanf
argument_list|(
literal|"%hO"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'o'?}}
name|scanf
argument_list|(
literal|"%lO"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifier is not supported by ISO C}} expected-note {{did you mean to use 'o'?}}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

