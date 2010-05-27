begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wformat-nonliteral %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_typedef
typedef|typedef
name|__typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_FILE
name|FILE
typedef|;
end_typedef

begin_function_decl
name|int
name|fprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
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

begin_comment
comment|// expected-note{{passing argument to parameter here}}
end_comment

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
specifier|restrict
parameter_list|,
name|size_t
parameter_list|,
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
name|sprintf
parameter_list|(
name|char
modifier|*
specifier|restrict
parameter_list|,
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
name|vasprintf
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|asprintf
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vprintf
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vsprintf
parameter_list|(
name|char
modifier|*
specifier|restrict
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{passing argument to parameter here}}
end_comment

begin_decl_stmt
name|char
modifier|*
name|global_fmt
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|check_string_literal
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
modifier|...
parameter_list|)
block|{
name|char
modifier|*
name|b
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is not a string literal}}
name|vprintf
argument_list|(
name|s
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// // no-warning
name|fprintf
argument_list|(
name|fp
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is not a string literal}}
name|vfprintf
argument_list|(
name|fp
argument_list|,
name|s
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// no-warning
name|asprintf
argument_list|(
operator|&
name|b
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is not a string lit}}
name|vasprintf
argument_list|(
operator|&
name|b
argument_list|,
name|s
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// no-warning
name|sprintf
argument_list|(
name|buf
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is not a string literal}}
name|snprintf
argument_list|(
name|buf
argument_list|,
literal|2
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is not a string lit}}
name|__builtin___sprintf_chk
argument_list|(
name|buf
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is not a string literal}}
name|__builtin___snprintf_chk
argument_list|(
name|buf
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is not a string lit}}
name|vsprintf
argument_list|(
name|buf
argument_list|,
name|s
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// no-warning
name|vsnprintf
argument_list|(
name|buf
argument_list|,
literal|2
argument_list|,
name|s
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// no-warning
name|vsnprintf
argument_list|(
name|buf
argument_list|,
literal|2
argument_list|,
name|global_fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is not a string literal}}
name|__builtin___vsnprintf_chk
argument_list|(
name|buf
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
name|s
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// no-warning
name|__builtin___vsnprintf_chk
argument_list|(
name|buf
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
name|global_fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is not a string literal}}
comment|// rdar://6079877
name|printf
argument_list|(
literal|"abc"
literal|"%*d"
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"abc\ def"
literal|"%*d"
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// no-warning
comment|//<rdar://problem/6079850>, allow 'unsigned' (instead of 'int') to be used for both
comment|// the field width and precision.  This deviates from C99, but is reasonably safe
comment|// and is also accepted by GCC.
name|printf
argument_list|(
literal|"%*d"
argument_list|,
operator|(
name|unsigned
operator|)
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|check_conditional_literal
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|i
parameter_list|)
block|{
name|printf
argument_list|(
name|i
operator|==
literal|1
condition|?
literal|"yes"
else|:
literal|"no"
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
name|i
operator|==
literal|0
condition|?
operator|(
name|i
operator|==
literal|1
condition|?
literal|"yes"
else|:
literal|"no"
operator|)
else|:
literal|"dont know"
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
name|i
operator|==
literal|0
condition|?
operator|(
name|i
operator|==
literal|1
condition|?
name|s
else|:
literal|"no"
operator|)
else|:
literal|"dont know"
argument_list|)
expr_stmt|;
comment|// expected-warning{{format string is not a string literal}}
name|printf
argument_list|(
literal|"yes"
condition|?
else|:
literal|"no %d"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{data argument not used by format string}}
block|}
end_function

begin_function
name|void
name|check_writeback_specifier
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|char
modifier|*
name|b
decl_stmt|;
name|printf
argument_list|(
literal|"%n"
argument_list|,
operator|&
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{'%n' in format string discouraged}}
name|sprintf
argument_list|(
name|b
argument_list|,
literal|"%d%%%n"
argument_list|,
literal|1
argument_list|,
operator|&
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{'%n' in format string dis}}
block|}
end_function

begin_function
name|void
name|check_invalid_specifier
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s%lb%d"
argument_list|,
literal|"unix"
argument_list|,
literal|10
argument_list|,
literal|20
argument_list|)
expr_stmt|;
comment|// expected-warning {{invalid conversion specifier 'b'}}
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%%%l"
argument_list|)
expr_stmt|;
comment|// expected-warning {{incomplete format specifier}}
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%%%%%ld%d%d"
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifies type 'long' but the argument has type 'int'}}
name|snprintf
argument_list|(
name|buf
argument_list|,
literal|2
argument_list|,
literal|"%%%%%ld%;%d"
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifies type 'long' but the argument has type 'int'}} expected-warning {{invalid conversion specifier ';'}}
block|}
end_function

begin_function
name|void
name|check_null_char_string
parameter_list|(
name|char
modifier|*
name|b
parameter_list|)
block|{
name|printf
argument_list|(
literal|"\0this is bogus%d"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning {{string contains '\0'}}
name|snprintf
argument_list|(
name|b
argument_list|,
literal|10
argument_list|,
literal|"%%%%%d\0%d"
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning {{string contains '\0'}}
name|printf
argument_list|(
literal|"%\0d"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning {{string contains '\0'}}
block|}
end_function

begin_function
name|void
name|check_empty_format_string
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|vprintf
argument_list|(
literal|""
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is empty}}
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is empty}}
block|}
end_function

begin_function
name|void
name|check_wide_string
parameter_list|(
name|char
modifier|*
name|b
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|L"foo %d"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning {{incompatible pointer types}}, expected-warning {{should not be a wide string}}
name|vsprintf
argument_list|(
name|b
argument_list|,
literal|L"bar %d"
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// expected-warning {{incompatible pointer types}}, expected-warning {{should not be a wide string}}
block|}
end_function

begin_function
name|void
name|check_asterisk_precision_width
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%*d"
argument_list|)
expr_stmt|;
comment|// expected-warning {{'*' specified field width is missing a matching 'int' argument}}
name|printf
argument_list|(
literal|"%.*d"
argument_list|)
expr_stmt|;
comment|// expected-warning {{'.*' specified field precision is missing a matching 'int' argument}}
name|printf
argument_list|(
literal|"%*d"
argument_list|,
literal|12
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%*d"
argument_list|,
literal|"foo"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{field width should have type 'int', but argument has type 'char *'}}
name|printf
argument_list|(
literal|"%.*d"
argument_list|,
literal|"foo"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{field precision should have type 'int', but argument has type 'char *'}}
block|}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
operator|)
argument_list|)
name|myprintf
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
name|blah
argument_list|,
operator|...
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_myprintf
parameter_list|()
block|{
name|myprintf
argument_list|(
literal|"%d"
argument_list|,
literal|17
argument_list|,
literal|18
argument_list|)
expr_stmt|;
comment|// okay
block|}
end_function

begin_function
name|void
name|test_constant_bindings
parameter_list|(
name|void
parameter_list|)
block|{
specifier|const
name|char
modifier|*
specifier|const
name|s1
init|=
literal|"hello"
decl_stmt|;
specifier|const
name|char
name|s2
index|[]
init|=
literal|"hello"
decl_stmt|;
specifier|const
name|char
modifier|*
name|s3
init|=
literal|"hello"
decl_stmt|;
name|char
modifier|*
specifier|const
name|s4
init|=
literal|"hello"
decl_stmt|;
specifier|extern
specifier|const
name|char
name|s5
index|[]
decl_stmt|;
name|printf
argument_list|(
name|s1
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
name|s2
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
name|s3
argument_list|)
expr_stmt|;
comment|// expected-warning{{not a string literal}}
name|printf
argument_list|(
name|s4
argument_list|)
expr_stmt|;
comment|// expected-warning{{not a string literal}}
name|printf
argument_list|(
name|s5
argument_list|)
expr_stmt|;
comment|// expected-warning{{not a string literal}}
block|}
end_function

begin_comment
comment|// Test what happens when -Wformat-security only.
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wformat-nonliteral"
end_pragma

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|warning
literal|"-Wformat-security"
end_pragma

begin_function
name|void
name|test9
parameter_list|(
name|char
modifier|*
name|P
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
name|printf
argument_list|(
name|P
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is not a string literal (potentially insecure)}}
name|printf
argument_list|(
name|P
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%n"
argument_list|,
operator|&
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{use of '%n' in format string discouraged }}
block|}
end_function

begin_function
name|void
name|torture
parameter_list|(
name|va_list
name|v8
parameter_list|)
block|{
name|vprintf
argument_list|(
literal|"%*.*d"
argument_list|,
name|v8
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|test10
parameter_list|(
name|int
name|x
parameter_list|,
name|float
name|f
parameter_list|,
name|int
name|i
parameter_list|,
name|long
name|long
name|lli
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s"
argument_list|)
expr_stmt|;
comment|// expected-warning{{more '%' conversions than data arguments}}
name|printf
argument_list|(
literal|"%@"
argument_list|,
literal|12
argument_list|)
expr_stmt|;
comment|// expected-warning{{invalid conversion specifier '@'}}
name|printf
argument_list|(
literal|"\0"
argument_list|)
expr_stmt|;
comment|// expected-warning{{format string contains '\0' within the string body}}
name|printf
argument_list|(
literal|"xs\0"
argument_list|)
expr_stmt|;
comment|// expected-warning{{format string contains '\0' within the string body}}
name|printf
argument_list|(
literal|"%*d\n"
argument_list|)
expr_stmt|;
comment|// expected-warning{{'*' specified field width is missing a matching 'int' argument}}
name|printf
argument_list|(
literal|"%*.*d\n"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{'.*' specified field precision is missing a matching 'int' argument}}
name|printf
argument_list|(
literal|"%*d\n"
argument_list|,
name|f
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{field width should have type 'int', but argument has type 'double'}}
name|printf
argument_list|(
literal|"%*.*d\n"
argument_list|,
name|x
argument_list|,
name|f
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{field precision should have type 'int', but argument has type 'double'}}
name|printf
argument_list|(
literal|"%**\n"
argument_list|)
expr_stmt|;
comment|// expected-warning{{invalid conversion specifier '*'}}
name|printf
argument_list|(
literal|"%n"
argument_list|,
operator|&
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{use of '%n' in format string discouraged (potentially insecure)}}
name|printf
argument_list|(
literal|"%d%d\n"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{more '%' conversions than data arguments}}
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|x
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{data argument not used by format string}}
name|printf
argument_list|(
literal|"%W%d%Z\n"
argument_list|,
name|x
argument_list|,
name|x
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{invalid conversion specifier 'W'}} expected-warning{{invalid conversion specifier 'Z'}}
name|printf
argument_list|(
literal|"%"
argument_list|)
expr_stmt|;
comment|// expected-warning{{incomplete format specifier}}
name|printf
argument_list|(
literal|"%.d"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%."
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{incomplete format specifier}}
name|printf
argument_list|(
literal|"%f"
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifies type 'double' but the argument has type 'int'}}
name|printf
argument_list|(
literal|"%qd"
argument_list|,
name|lli
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"hhX %hhX"
argument_list|,
operator|(
name|unsigned
name|char
operator|)
literal|10
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"llX %llX"
argument_list|,
operator|(
name|long
name|long
operator|)
literal|10
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// This is fine, because there is an implicit conversion to an int.
name|printf
argument_list|(
literal|"%d"
argument_list|,
operator|(
name|unsigned
name|char
operator|)
literal|10
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%d"
argument_list|,
operator|(
name|long
name|long
operator|)
literal|10
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifies type 'int' but the argument has type 'long long'}}
name|printf
argument_list|(
literal|"%Lf\n"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|1.0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%f\n"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|1.0
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifies type 'double' but the argument has type 'long double'}}
comment|// The man page says that a zero precision is okay.
name|printf
argument_list|(
literal|"%.0Lf"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|1.0
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|test11
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|char
modifier|*
name|s
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%p"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%.4p"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{precision used in 'p' conversion specifier (where it has no meaning)}}
name|printf
argument_list|(
literal|"%+p"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '+' results in undefined behavior in 'p' conversion specifier}}
name|printf
argument_list|(
literal|"% p"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag ' ' results in undefined behavior in 'p' conversion specifier}}
name|printf
argument_list|(
literal|"%0p"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '0' results in undefined behavior in 'p' conversion specifier}}
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%+s"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '+' results in undefined behavior in 's' conversion specifier}}
name|printf
argument_list|(
literal|"% s"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag ' ' results in undefined behavior in 's' conversion specifier}}
name|printf
argument_list|(
literal|"%0s"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '0' results in undefined behavior in 's' conversion specifier}}
block|}
end_function

begin_function
name|void
name|test12
parameter_list|(
name|char
modifier|*
name|b
parameter_list|)
block|{
name|unsigned
name|char
name|buf
index|[
literal|4
index|]
decl_stmt|;
name|printf
argument_list|(
literal|"%.4s\n"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%.4s\n"
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifies type 'char *' but the argument has type 'unsigned char (*)[4]'}}
comment|// Verify that we are checking asprintf
name|asprintf
argument_list|(
operator|&
name|b
argument_list|,
literal|"%d"
argument_list|,
literal|"asprintf"
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifies type 'int' but the argument has type 'char *'}}
block|}
end_function

begin_typedef
typedef|typedef
name|struct
name|__aslclient
modifier|*
name|aslclient
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|__aslmsg
modifier|*
name|aslmsg
typedef|;
end_typedef

begin_function_decl
name|int
name|asl_log
parameter_list|(
name|aslclient
name|asl
parameter_list|,
name|aslmsg
name|msg
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test_asl
parameter_list|(
name|aslclient
name|asl
parameter_list|)
block|{
comment|// Test case from<rdar://problem/7341605>.
name|asl_log
argument_list|(
name|asl
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|"Error: %m"
argument_list|)
expr_stmt|;
comment|// no-warning
name|asl_log
argument_list|(
name|asl
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|"Error: %W"
argument_list|)
expr_stmt|;
comment|// expected-warning{{invalid conversion specifier 'W'}}
block|}
end_function

begin_comment
comment|//<rdar://problem/7595366>
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|A
block|}
name|int_t
typedef|;
end_typedef

begin_function
name|void
name|f0
parameter_list|(
name|int_t
name|x
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Unicode test cases.  These are possibly specific to Mac OS X.  If so, they should
end_comment

begin_comment
comment|// eventually be moved into a separate test.
end_comment

begin_typedef
typedef|typedef
name|__WCHAR_TYPE__
name|wchar_t
typedef|;
end_typedef

begin_function
name|void
name|test_unicode_conversions
parameter_list|(
name|wchar_t
modifier|*
name|s
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%S"
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifies type 'char *' but the argument has type 'wchar_t *'}}
name|printf
argument_list|(
literal|"%C"
argument_list|,
name|s
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%c"
argument_list|,
name|s
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|// FIXME: This test reports inconsistent results. On Windows, '%C' expects
comment|// 'unsigned short'.
comment|// printf("%C", 10);
comment|// FIXME: we report the expected type as 'int*' instead of 'wchar_t*'
name|printf
argument_list|(
literal|"%S"
argument_list|,
literal|"hello"
argument_list|)
expr_stmt|;
comment|// expected-warning{{but the argument has type 'char *'}}
block|}
end_function

begin_comment
comment|// Mac OS X supports positional arguments in format strings.
end_comment

begin_comment
comment|// This is an IEEE extension (IEEE Std 1003.1).
end_comment

begin_comment
comment|// FIXME: This is probably not portable everywhere.
end_comment

begin_function
name|void
name|test_positional_arguments
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%0$"
argument_list|,
operator|(
name|int
operator|)
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning{{position arguments in format strings start counting at 1 (not 0)}}
name|printf
argument_list|(
literal|"%1$*0$d"
argument_list|,
operator|(
name|int
operator|)
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning{{position arguments in format strings start counting at 1 (not 0)}}
name|printf
argument_list|(
literal|"%1$d"
argument_list|,
operator|(
name|int
operator|)
literal|2
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%1$d"
argument_list|,
operator|(
name|int
operator|)
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning{{data argument not used by format string}}
name|printf
argument_list|(
literal|"%1$d%1$f"
argument_list|,
operator|(
name|int
operator|)
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifies type 'double' but the argument has type 'int'}}
name|printf
argument_list|(
literal|"%1$2.2d"
argument_list|,
operator|(
name|int
operator|)
literal|2
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%2$*1$.2d"
argument_list|,
operator|(
name|int
operator|)
literal|2
argument_list|,
operator|(
name|int
operator|)
literal|3
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%2$*8$d"
argument_list|,
operator|(
name|int
operator|)
literal|2
argument_list|,
operator|(
name|int
operator|)
literal|3
argument_list|)
expr_stmt|;
comment|// expected-warning{{specified field width is missing a matching 'int' argument}}
block|}
end_function

begin_comment
comment|// PR 6697 - Handle format strings where the data argument is not adjacent to the format string
end_comment

begin_function_decl
name|void
name|myprintf_PR_6697
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|int
name|x
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test_pr_6697
parameter_list|()
block|{
name|myprintf_PR_6697
argument_list|(
literal|"%s\n"
argument_list|,
literal|1
argument_list|,
literal|"foo"
argument_list|)
expr_stmt|;
comment|// no-warning
name|myprintf_PR_6697
argument_list|(
literal|"%s\n"
argument_list|,
literal|1
argument_list|,
operator|(
name|int
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifies type 'char *' but the argument has type 'int'}}
comment|// FIXME: Not everything should clearly support positional arguments,
comment|// but we need a way to identify those cases.
name|myprintf_PR_6697
argument_list|(
literal|"%1$s\n"
argument_list|,
literal|1
argument_list|,
literal|"foo"
argument_list|)
expr_stmt|;
comment|// no-warning
name|myprintf_PR_6697
argument_list|(
literal|"%2$s\n"
argument_list|,
literal|1
argument_list|,
literal|"foo"
argument_list|)
expr_stmt|;
comment|// expected-warning{{data argument position '2' exceeds the number of data arguments (1)}}
name|myprintf_PR_6697
argument_list|(
literal|"%18$s\n"
argument_list|,
literal|1
argument_list|,
literal|"foo"
argument_list|)
expr_stmt|;
comment|// expected-warning{{data argument position '18' exceeds the number of data arguments (1)}}
name|myprintf_PR_6697
argument_list|(
literal|"%1$s\n"
argument_list|,
literal|1
argument_list|,
operator|(
name|int
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{conversion specifies type 'char *' but the argument has type 'int'}}
block|}
end_function

begin_function
name|void
name|rdar8026030
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
block|{
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"\%"
argument_list|)
expr_stmt|;
comment|// expected-warning{{incomplete format specifier}}
block|}
end_function

end_unit

