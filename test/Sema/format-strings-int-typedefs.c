begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -fsyntax-only -verify %s
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scanf
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%jd"
argument_list|,
literal|42.0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'intmax_t' (aka 'long long')}}
name|printf
argument_list|(
literal|"%ju"
argument_list|,
literal|42.0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'uintmax_t' (aka 'unsigned long long')}}
name|printf
argument_list|(
literal|"%zu"
argument_list|,
literal|42.0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'size_t' (aka 'unsigned long')}}
name|printf
argument_list|(
literal|"%td"
argument_list|,
literal|42.0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'ptrdiff_t' (aka 'int')}}
name|printf
argument_list|(
literal|"%lc"
argument_list|,
literal|42.0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'wint_t' (aka 'int')}}
name|printf
argument_list|(
literal|"%ls"
argument_list|,
literal|42.0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'wchar_t *' (aka 'int *')}}
name|printf
argument_list|(
literal|"%S"
argument_list|,
literal|42.0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'wchar_t *' (aka 'int *')}}
name|printf
argument_list|(
literal|"%C"
argument_list|,
literal|42.0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'wchar_t' (aka 'int')}}
name|scanf
argument_list|(
literal|"%jd"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'intmax_t *' (aka 'long long *')}}
name|scanf
argument_list|(
literal|"%ju"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'uintmax_t *' (aka 'unsigned long long *')}}
name|scanf
argument_list|(
literal|"%zu"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'size_t *' (aka 'unsigned long *')}}
name|scanf
argument_list|(
literal|"%td"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'ptrdiff_t *' (aka 'int *')}}
name|scanf
argument_list|(
literal|"%lc"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'wchar_t *' (aka 'int *')}}
name|scanf
argument_list|(
literal|"%ls"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'wchar_t *' (aka 'int *')}}
name|scanf
argument_list|(
literal|"%S"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'wchar_t *' (aka 'int *')}}
name|scanf
argument_list|(
literal|"%C"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'wchar_t *' (aka 'int *')}}
comment|// typedef size_t et al. to something crazy.
typedef|typedef
name|void
modifier|*
name|size_t
typedef|;
typedef|typedef
name|void
modifier|*
name|intmax_t
typedef|;
typedef|typedef
name|void
modifier|*
name|uintmax_t
typedef|;
typedef|typedef
name|void
modifier|*
name|ptrdiff_t
typedef|;
comment|// The warning still fires, because it checks the underlying type.
name|printf
argument_list|(
literal|"%jd"
argument_list|,
operator|(
name|intmax_t
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'intmax_t' (aka 'long long') but the argument has type 'intmax_t' (aka 'void *')}}
name|printf
argument_list|(
literal|"%ju"
argument_list|,
operator|(
name|uintmax_t
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'uintmax_t' (aka 'unsigned long long') but the argument has type 'uintmax_t' (aka 'void *')}}
name|printf
argument_list|(
literal|"%zu"
argument_list|,
operator|(
name|size_t
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'size_t' (aka 'unsigned long') but the argument has type 'size_t' (aka 'void *')}}
name|printf
argument_list|(
literal|"%td"
argument_list|,
operator|(
name|ptrdiff_t
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'ptrdiff_t' (aka 'int') but the argument has type 'ptrdiff_t' (aka 'void *')}}
block|}
end_function

end_unit

