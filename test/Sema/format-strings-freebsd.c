begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple i386-unknown-freebsd %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-unknown-freebsd %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-scei-ps4 %s
end_comment

begin_comment
comment|// Test FreeBSD kernel printf extensions.
end_comment

begin_function_decl
name|int
name|freebsd_kernel_printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__freebsd_kprintf__
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
name|check_freebsd_kernel_extensions
parameter_list|(
name|int
name|i
parameter_list|,
name|long
name|l
parameter_list|,
name|char
modifier|*
name|s
parameter_list|,
name|short
name|h
parameter_list|)
block|{
comment|// %b expects an int and a char *
name|freebsd_kernel_printf
argument_list|(
literal|"reg=%b\n"
argument_list|,
name|i
argument_list|,
literal|"\10\2BITTWO\1BITONE\n"
argument_list|)
expr_stmt|;
comment|// no-warning
name|freebsd_kernel_printf
argument_list|(
literal|"reg=%b\n"
argument_list|,
name|l
argument_list|,
literal|"\10\2BITTWO\1BITONE\n"
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int' but the argument has type 'long'}}
name|freebsd_kernel_printf
argument_list|(
literal|"reg=%b\n"
argument_list|,
name|i
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'long'}}
name|freebsd_kernel_printf
argument_list|(
literal|"reg=%b\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{more '%' conversions than data arguments}}
name|freebsd_kernel_printf
argument_list|(
literal|"reg=%b\n"
argument_list|,
name|i
argument_list|,
literal|"\10\2BITTWO\1BITONE\n"
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// expected-warning{{data argument not used by format string}}
comment|// %D expects an unsigned char * and a char *
name|freebsd_kernel_printf
argument_list|(
literal|"%6D"
argument_list|,
name|s
argument_list|,
literal|":"
argument_list|)
expr_stmt|;
comment|// no-warning
name|freebsd_kernel_printf
argument_list|(
literal|"%6D"
argument_list|,
name|i
argument_list|,
literal|":"
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'void *' but the argument has type 'int'}}
name|freebsd_kernel_printf
argument_list|(
literal|"%6D"
argument_list|,
name|s
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'int'}}
name|freebsd_kernel_printf
argument_list|(
literal|"%6D"
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning{{more '%' conversions than data arguments}}
name|freebsd_kernel_printf
argument_list|(
literal|"%6D"
argument_list|,
name|s
argument_list|,
literal|":"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{data argument not used by format string}}
name|freebsd_kernel_printf
argument_list|(
literal|"%*D"
argument_list|,
literal|42
argument_list|,
name|s
argument_list|,
literal|":"
argument_list|)
expr_stmt|;
comment|// no-warning
name|freebsd_kernel_printf
argument_list|(
literal|"%*D"
argument_list|,
literal|42
argument_list|,
name|i
argument_list|,
literal|":"
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'void *' but the argument has type 'int'}}
name|freebsd_kernel_printf
argument_list|(
literal|"%*D"
argument_list|,
literal|42
argument_list|,
name|s
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'int'}}
name|freebsd_kernel_printf
argument_list|(
literal|"%*D"
argument_list|,
literal|42
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning{{more '%' conversions than data arguments}}
name|freebsd_kernel_printf
argument_list|(
literal|"%*D"
argument_list|,
literal|42
argument_list|,
name|s
argument_list|,
literal|":"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{data argument not used by format string}}
comment|// %r expects an int
name|freebsd_kernel_printf
argument_list|(
literal|"%r"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// no-warning
name|freebsd_kernel_printf
argument_list|(
literal|"%r"
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int' but the argument has type 'long'}}
name|freebsd_kernel_printf
argument_list|(
literal|"%lr"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'long' but the argument has type 'int'}}
name|freebsd_kernel_printf
argument_list|(
literal|"%lr"
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// h modifier expects a short
name|freebsd_kernel_printf
argument_list|(
literal|"%hr"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'short' but the argument has type 'int'}}
name|freebsd_kernel_printf
argument_list|(
literal|"%hr"
argument_list|,
name|h
argument_list|)
expr_stmt|;
comment|// no-warning
name|freebsd_kernel_printf
argument_list|(
literal|"%hy"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'short' but the argument has type 'int'}}
name|freebsd_kernel_printf
argument_list|(
literal|"%hy"
argument_list|,
name|h
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// %y expects an int
name|freebsd_kernel_printf
argument_list|(
literal|"%y"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// no-warning
name|freebsd_kernel_printf
argument_list|(
literal|"%y"
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int' but the argument has type 'long'}}
name|freebsd_kernel_printf
argument_list|(
literal|"%ly"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'long' but the argument has type 'int'}}
name|freebsd_kernel_printf
argument_list|(
literal|"%ly"
argument_list|,
name|l
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

end_unit

