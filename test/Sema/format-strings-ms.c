begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -fms-compatibility -triple=i386-pc-win32 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -fms-compatibility -triple=i386-pc-win32 -Wformat-non-iso -DNON_ISO_WARNING %s
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

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

begin_typedef
typedef|typedef
name|unsigned
name|short
name|wchar_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|NON_ISO_WARNING
end_ifdef

begin_comment
comment|// Split off this test to reduce the warning noise in the rest of the file.
end_comment

begin_function
name|void
name|non_iso_warning_test
parameter_list|(
name|__int32
name|i32
parameter_list|,
name|__int64
name|i64
parameter_list|,
name|wchar_t
name|c
parameter_list|,
name|void
modifier|*
name|p
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%Id"
argument_list|,
name|i32
argument_list|)
expr_stmt|;
comment|// expected-warning{{'I' length modifier is not supported by ISO C}}
name|printf
argument_list|(
literal|"%I32d"
argument_list|,
name|i32
argument_list|)
expr_stmt|;
comment|// expected-warning{{'I32' length modifier is not supported by ISO C}}
name|printf
argument_list|(
literal|"%I64d"
argument_list|,
name|i64
argument_list|)
expr_stmt|;
comment|// expected-warning{{'I64' length modifier is not supported by ISO C}}
name|printf
argument_list|(
literal|"%wc"
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// expected-warning{{'w' length modifier is not supported by ISO C}}
name|printf
argument_list|(
literal|"%Z"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{'Z' conversion specifier is not supported by ISO C}}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|void
name|signed_test
parameter_list|()
block|{
name|short
name|val
init|=
literal|30
decl_stmt|;
name|printf
argument_list|(
literal|"val = %I64d\n"
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type '__int64' (aka 'long long') but the argument has type 'short'}}
name|long
name|long
name|bigval
init|=
literal|30
decl_stmt|;
name|printf
argument_list|(
literal|"val = %I32d\n"
argument_list|,
name|bigval
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type '__int32' (aka 'int') but the argument has type 'long long'}}
name|printf
argument_list|(
literal|"val = %Id\n"
argument_list|,
name|bigval
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type '__int32' (aka 'int') but the argument has type 'long long'}}
block|}
end_function

begin_function
name|void
name|unsigned_test
parameter_list|()
block|{
name|unsigned
name|short
name|val
init|=
literal|30
decl_stmt|;
name|printf
argument_list|(
literal|"val = %I64u\n"
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'unsigned __int64' (aka 'unsigned long long') but the argument has type 'unsigned short'}}
name|unsigned
name|long
name|long
name|bigval
init|=
literal|30
decl_stmt|;
name|printf
argument_list|(
literal|"val = %I32u\n"
argument_list|,
name|bigval
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'unsigned __int32' (aka 'unsigned int') but the argument has type 'unsigned long long'}}
name|printf
argument_list|(
literal|"val = %Iu\n"
argument_list|,
name|bigval
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'unsigned __int32' (aka 'unsigned int') but the argument has type 'unsigned long long'}}
block|}
end_function

begin_function
name|void
name|w_test
parameter_list|(
name|wchar_t
name|c
parameter_list|,
name|wchar_t
modifier|*
name|s
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%wc"
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%wC"
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%C"
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%ws"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%wS"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%S"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%wc"
argument_list|,
operator|&
name|c
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%wC"
argument_list|,
operator|&
name|c
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%C"
argument_list|,
operator|&
name|c
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%ws"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%wS"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%S"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|double
name|bad
decl_stmt|;
name|printf
argument_list|(
literal|"%wc"
argument_list|,
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'wint_t' (aka 'int') but the argument has type 'double'}}
name|printf
argument_list|(
literal|"%wC"
argument_list|,
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'wchar_t' (aka 'unsigned short') but the argument has type 'double'}}
name|printf
argument_list|(
literal|"%C"
argument_list|,
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'wchar_t' (aka 'unsigned short') but the argument has type 'double'}}
name|printf
argument_list|(
literal|"%ws"
argument_list|,
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'wchar_t *' (aka 'unsigned short *') but the argument has type 'double'}}
name|printf
argument_list|(
literal|"%wS"
argument_list|,
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'wchar_t *' (aka 'unsigned short *') but the argument has type 'double'}}
name|printf
argument_list|(
literal|"%S"
argument_list|,
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'wchar_t *' (aka 'unsigned short *') but the argument has type 'double'}}
name|scanf
argument_list|(
literal|"%wc"
argument_list|,
operator|&
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'wchar_t *' (aka 'unsigned short *') but the argument has type 'double *'}}
name|scanf
argument_list|(
literal|"%wC"
argument_list|,
operator|&
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'wchar_t *' (aka 'unsigned short *') but the argument has type 'double *'}}
name|scanf
argument_list|(
literal|"%C"
argument_list|,
operator|&
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'wchar_t *' (aka 'unsigned short *') but the argument has type 'double *'}}
name|scanf
argument_list|(
literal|"%ws"
argument_list|,
operator|&
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'wchar_t *' (aka 'unsigned short *') but the argument has type 'double *'}}
name|scanf
argument_list|(
literal|"%wS"
argument_list|,
operator|&
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'wchar_t *' (aka 'unsigned short *') but the argument has type 'double *'}}
name|scanf
argument_list|(
literal|"%S"
argument_list|,
operator|&
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'wchar_t *' (aka 'unsigned short *') but the argument has type 'double *'}}
block|}
end_function

begin_function
name|void
name|h_test
parameter_list|(
name|char
name|c
parameter_list|,
name|char
modifier|*
name|s
parameter_list|)
block|{
name|double
name|bad
decl_stmt|;
name|printf
argument_list|(
literal|"%hc"
argument_list|,
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int' but the argument has type 'double'}}
name|printf
argument_list|(
literal|"%hC"
argument_list|,
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int' but the argument has type 'double'}}
name|printf
argument_list|(
literal|"%hs"
argument_list|,
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'double'}}
name|printf
argument_list|(
literal|"%hS"
argument_list|,
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'double'}}
name|scanf
argument_list|(
literal|"%hc"
argument_list|,
operator|&
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'double *'}}
name|scanf
argument_list|(
literal|"%hC"
argument_list|,
operator|&
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'double *'}}
name|scanf
argument_list|(
literal|"%hs"
argument_list|,
operator|&
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'double *'}}
name|scanf
argument_list|(
literal|"%hS"
argument_list|,
operator|&
name|bad
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'double *'}}
block|}
end_function

begin_function
name|void
name|z_test
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%Z"
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%hZ"
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%lZ"
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%wZ"
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%hhZ"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{length modifier 'hh' results in undefined behavior or no effect with 'Z' conversion specifier}}
name|scanf
argument_list|(
literal|"%Z"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{invalid conversion specifier 'Z'}}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

