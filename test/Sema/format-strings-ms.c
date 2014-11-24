begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -fms-compatibility -triple=i386-pc-win32 -Wformat-non-iso %s
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
comment|// expected-warning{{'I64' length modifier is not supported by ISO C}} \
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
comment|// expected-warning{{'I32' length modifier is not supported by ISO C}} \
comment|// expected-warning{{format specifies type '__int32' (aka 'int') but the argument has type 'long long'}}
name|printf
argument_list|(
literal|"val = %Id\n"
argument_list|,
name|bigval
argument_list|)
expr_stmt|;
comment|// expected-warning{{'I' length modifier is not supported by ISO C}} \
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
comment|// expected-warning{{'I64' length modifier is not supported by ISO C}} \
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
comment|// expected-warning{{'I32' length modifier is not supported by ISO C}} \
comment|// expected-warning{{format specifies type 'unsigned __int32' (aka 'unsigned int') but the argument has type 'unsigned long long'}}
name|printf
argument_list|(
literal|"val = %Iu\n"
argument_list|,
name|bigval
argument_list|)
expr_stmt|;
comment|// expected-warning{{'I' length modifier is not supported by ISO C}} \
comment|// expected-warning{{format specifies type 'unsigned __int32' (aka 'unsigned int') but the argument has type 'unsigned long long'}}
block|}
end_function

end_unit

