begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wformat-nonliteral -isystem %S/Inputs %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wformat-nonliteral -isystem %S/Inputs -fno-signed-char %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_define
define|#
directive|define
name|__need_wint_t
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// For wint_t and wchar_t
end_comment

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

begin_function_decl
name|int
name|vscanf
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
name|format
parameter_list|,
name|va_list
name|arg
parameter_list|)
function_decl|;
end_function_decl

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
comment|// expected-warning {{format string is not a string literal}}
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
comment|// expected-warning {{format string is not a string literal}}
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
comment|// expected-warning {{format string is not a string literal}}
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
comment|// expected-warning {{format string is not a string lit}}
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
comment|// expected-warning {{format string is not a string lit}}
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
comment|// expected-warning {{format string is not a string lit}}
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
name|vscanf
argument_list|(
name|s
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

begin_comment
comment|// When calling a non-variadic format function (vprintf, vscanf, NSLogv, ...),
end_comment

begin_comment
comment|// warn only if the format string argument is a parameter that is not itself
end_comment

begin_comment
comment|// declared as a format string with compatible format.
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(__format__ (__printf__,
literal|2
argument|,
literal|4
argument|))
argument_list|)
end_macro

begin_function
name|void
name|check_string_literal2
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
comment|// no-warning
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
name|vscanf
argument_list|(
name|s
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is not a string literal}}
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
name|b
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int *' but the argument has type 'char *'}}
name|printf
argument_list|(
literal|"%n"
argument_list|,
operator|&
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%hhn"
argument_list|,
operator|(
name|signed
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%hhn"
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%hhn"
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%hhn"
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'signed char *' but the argument has type 'int *'}}
name|printf
argument_list|(
literal|"%hn"
argument_list|,
operator|(
name|short
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%hn"
argument_list|,
operator|(
name|unsigned
name|short
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%hn"
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'short *' but the argument has type 'int *'}}
name|printf
argument_list|(
literal|"%n"
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%n"
argument_list|,
operator|(
name|unsigned
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%n"
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int *' but the argument has type 'char *'}}
name|printf
argument_list|(
literal|"%ln"
argument_list|,
operator|(
name|long
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%ln"
argument_list|,
operator|(
name|unsigned
name|long
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%ln"
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'long *' but the argument has type 'int *'}}
name|printf
argument_list|(
literal|"%lln"
argument_list|,
operator|(
name|long
name|long
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%lln"
argument_list|,
operator|(
name|unsigned
name|long
name|long
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%lln"
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'long long *' but the argument has type 'int *'}}
name|printf
argument_list|(
literal|"%qn"
argument_list|,
operator|(
name|long
name|long
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%qn"
argument_list|,
operator|(
name|unsigned
name|long
name|long
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%qn"
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'long long *' but the argument has type 'int *'}}
name|printf
argument_list|(
literal|"%Ln"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{length modifier 'L' results in undefined behavior or no effect with 'n' conversion specifier}}
comment|// expected-note@-1{{did you mean to use 'll'?}}
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
comment|// expected-warning{{format specifies type 'long' but the argument has type 'int'}}
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
comment|// expected-warning{{format specifies type 'long' but the argument has type 'int'}} expected-warning {{invalid conversion specifier ';'}}
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
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is empty}}
comment|// Don't warn about empty format strings when there are no data arguments.
comment|// This can arise from macro expansions and non-standard format string
comment|// functions.
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|// no-warning
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
literal|"%W%d\n"
argument_list|,
name|x
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{invalid conversion specifier 'W'}}
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
comment|// expected-warning{{format specifies type 'double' but the argument has type 'int'}}
name|printf
argument_list|(
literal|"%qd"
argument_list|,
name|lli
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%qd"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'long long' but the argument has type 'int'}}
name|printf
argument_list|(
literal|"%qp"
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{length modifier 'q' results in undefined behavior or no effect with 'p' conversion specifier}}
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
comment|// expected-warning{{format specifies type 'int' but the argument has type 'long long'}}
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
comment|// expected-warning{{format specifies type 'double' but the argument has type 'long double'}}
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
name|printf
argument_list|(
literal|"%c\n"
argument_list|,
literal|"x"
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int' but the argument has type 'char *'}}
name|printf
argument_list|(
literal|"%c\n"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int' but the argument has type 'double'}}
name|printf
argument_list|(
literal|"Format %d, is %! %f"
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|4.4
argument_list|)
expr_stmt|;
comment|// expected-warning{{invalid conversion specifier '!'}}
block|}
end_function

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_function
name|void
name|should_understand_small_integers
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%hhu"
argument_list|,
operator|(
name|short
operator|)
literal|10
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'unsigned char' but the argument has type 'short'}}
name|printf
argument_list|(
literal|"%hu\n"
argument_list|,
operator|(
name|unsigned
name|char
operator|)
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'unsigned short' but the argument has type 'unsigned char'}}
name|printf
argument_list|(
literal|"%hu\n"
argument_list|,
operator|(
name|uint8_t
operator|)
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'unsigned short' but the argument has type 'uint8_t'}}
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
literal|"%p"
argument_list|,
literal|123
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'void *' but the argument has type 'int'}}
name|printf
argument_list|(
literal|"%.4p"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{precision used with 'p' conversion specifier, resulting in undefined behavior}}
name|printf
argument_list|(
literal|"%+p"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '+' results in undefined behavior with 'p' conversion specifier}}
name|printf
argument_list|(
literal|"% p"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag ' ' results in undefined behavior with 'p' conversion specifier}}
name|printf
argument_list|(
literal|"%0p"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '0' results in undefined behavior with 'p' conversion specifier}}
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
comment|// expected-warning{{flag '+' results in undefined behavior with 's' conversion specifier}}
name|printf
argument_list|(
literal|"% s"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag ' ' results in undefined behavior with 's' conversion specifier}}
name|printf
argument_list|(
literal|"%0s"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '0' results in undefined behavior with 's' conversion specifier}}
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
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'unsigned char (*)[4]'}}
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
comment|// expected-warning{{format specifies type 'int' but the argument has type 'char *'}}
block|}
end_function

begin_function
name|void
name|test13
parameter_list|(
name|short
name|x
parameter_list|)
block|{
name|char
name|bel
init|=
literal|007
decl_stmt|;
name|printf
argument_list|(
literal|"bel: '0%hhd'\n"
argument_list|,
name|bel
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"x: '0%hhd'\n"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'char' but the argument has type 'short'}}
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
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'wchar_t *'}}
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
comment|// expected-warning{{format specifies type 'double' but the argument has type 'int'}}
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
name|printf
argument_list|(
literal|"%%%1$d"
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
literal|"%1$d%%"
argument_list|,
operator|(
name|int
operator|)
literal|2
argument_list|)
expr_stmt|;
comment|// no-warning
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
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'int'}}
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
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'int'}}
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

begin_function
name|void
name|bug7377_bad_length_mod_usage
parameter_list|()
block|{
comment|// Bad length modifiers
name|printf
argument_list|(
literal|"%hhs"
argument_list|,
literal|"foo"
argument_list|)
expr_stmt|;
comment|// expected-warning{{length modifier 'hh' results in undefined behavior or no effect with 's' conversion specifier}}
name|printf
argument_list|(
literal|"%1$zp"
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{length modifier 'z' results in undefined behavior or no effect with 'p' conversion specifier}}
name|printf
argument_list|(
literal|"%ls"
argument_list|,
literal|L"foo"
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%#.2Lf"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|1.234
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// Bad flag usage
name|printf
argument_list|(
literal|"%#p"
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '#' results in undefined behavior with 'p' conversion specifier}}
name|printf
argument_list|(
literal|"%0d"
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%#n"
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '#' results in undefined behavior with 'n' conversion specifier}}
name|printf
argument_list|(
literal|"%-n"
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '-' results in undefined behavior with 'n' conversion specifier}}
name|printf
argument_list|(
literal|"%-p"
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// Bad optional amount use
name|printf
argument_list|(
literal|"%.2c"
argument_list|,
literal|'a'
argument_list|)
expr_stmt|;
comment|// expected-warning{{precision used with 'c' conversion specifier, resulting in undefined behavior}}
name|printf
argument_list|(
literal|"%1n"
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{field width used with 'n' conversion specifier, resulting in undefined behavior}}
name|printf
argument_list|(
literal|"%.9n"
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{precision used with 'n' conversion specifier, resulting in undefined behavior}}
comment|// Ignored flags
name|printf
argument_list|(
literal|"% +f"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag ' ' is ignored when flag '+' is present}}
name|printf
argument_list|(
literal|"%+ f"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag ' ' is ignored when flag '+' is present}}
name|printf
argument_list|(
literal|"%0-f"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '0' is ignored when flag '-' is present}}
name|printf
argument_list|(
literal|"%-0f"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '0' is ignored when flag '-' is present}}
name|printf
argument_list|(
literal|"%-+f"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// PR 7981 - handle '%lc' (wint_t)
end_comment

begin_function
name|void
name|pr7981
parameter_list|(
name|wint_t
name|c
parameter_list|,
name|wchar_t
name|c2
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%lc"
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%lc"
argument_list|,
literal|1.0
argument_list|)
expr_stmt|;
comment|// expected-warning{{the argument has type 'double'}}
name|printf
argument_list|(
literal|"%lc"
argument_list|,
operator|(
name|char
operator|)
literal|1
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%lc"
argument_list|,
operator|&
name|c
argument_list|)
expr_stmt|;
comment|// expected-warning{{the argument has type 'wint_t *'}}
comment|// If wint_t and wchar_t are the same width and wint_t is signed where
comment|// wchar_t is unsigned, an implicit conversion isn't possible.
if|#
directive|if
name|defined
argument_list|(
name|__WINT_UNSIGNED__
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__WCHAR_UNSIGNED__
argument_list|)
operator|||
expr|\
name|__WINT_WIDTH__
operator|>
name|__WCHAR_WIDTH__
name|printf
argument_list|(
literal|"%lc"
argument_list|,
name|c2
argument_list|)
expr_stmt|;
comment|// no-warning
endif|#
directive|endif
block|}
end_function

begin_comment
comment|//<rdar://problem/8269537> -Wformat-security says NULL is not a string literal
end_comment

begin_function
name|void
name|rdar8269537
parameter_list|()
block|{
comment|// This is likely to crash in most cases, but -Wformat-nonliteral technically
comment|// doesn't warn in this case.
name|printf
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Handle functions with multiple format attributes.
end_comment

begin_function_decl
specifier|extern
name|void
name|rdar8332221_vprintf_scanf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|,
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
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|0
end_function_decl

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|__format__
argument_list|(
name|__scanf__
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|rdar8332221
parameter_list|(
name|va_list
name|ap
parameter_list|,
name|int
modifier|*
name|x
parameter_list|,
name|long
modifier|*
name|y
parameter_list|)
block|{
name|rdar8332221_vprintf_scanf
argument_list|(
literal|"%"
argument_list|,
name|ap
argument_list|,
literal|"%d"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{incomplete format specifier}}
block|}
end_function

begin_comment
comment|// PR8641
end_comment

begin_function
name|void
name|pr8641
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%#x\n"
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%#X\n"
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|posix_extensions
parameter_list|()
block|{
comment|// Test %'d, "thousands grouping".
comment|//<rdar://problem/8816343>
name|printf
argument_list|(
literal|"%'d\n"
argument_list|,
literal|123456789
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%'i\n"
argument_list|,
literal|123456789
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%'f\n"
argument_list|,
operator|(
name|float
operator|)
literal|1.0
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%'p\n"
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{results in undefined behavior with 'p' conversion specifier}}
block|}
end_function

begin_comment
comment|// PR8486
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Test what happens when -Wformat is on, but -Wformat-security is off.
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|warning
literal|"-Wformat"
end_pragma

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wformat-security"
end_pragma

begin_function
name|void
name|pr8486
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%s"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'int'}}
block|}
end_function

begin_comment
comment|// PR9314
end_comment

begin_comment
comment|// Don't warn about string literals that are PreDefinedExprs, e.g. __func__.
end_comment

begin_function
name|void
name|pr9314
parameter_list|()
block|{
name|printf
argument_list|(
name|__PRETTY_FUNCTION__
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
name|__func__
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

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
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
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
name|rdar9612060
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'int'}}
block|}
end_function

begin_function
name|void
name|check_char
parameter_list|(
name|unsigned
name|char
name|x
parameter_list|,
name|signed
name|char
name|y
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%c"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%hhu"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%hhi"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%hhi"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%c"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%hhu"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Test suppression of individual warnings.
end_comment

begin_function
name|void
name|test_suppress_invalid_specifier
parameter_list|()
block|{
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wformat-invalid-specifier"
name|printf
argument_list|(
literal|"%@"
argument_list|,
literal|12
argument_list|)
expr_stmt|;
comment|// no-warning
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
block|}
end_function

begin_comment
comment|// Make sure warnings are on for next test.
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|warning
literal|"-Wformat"
end_pragma

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|warning
literal|"-Wformat-security"
end_pragma

begin_comment
comment|// Test that the printf call site is where the warning is attached.  If the
end_comment

begin_comment
comment|// format string is somewhere else, point to it in a note.
end_comment

begin_function
name|void
name|pr9751
parameter_list|()
block|{
specifier|const
name|char
name|kFormat1
index|[]
init|=
literal|"%d %d \n"
decl_stmt|;
comment|// expected-note{{format string is defined here}}}
name|printf
argument_list|(
name|kFormat1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{more '%' conversions than data arguments}}
name|printf
argument_list|(
literal|"%d %s\n"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{more '%' conversions than data arguments}}
specifier|const
name|char
name|kFormat2
index|[]
init|=
literal|"%18$s\n"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat2
argument_list|,
literal|1
argument_list|,
literal|"foo"
argument_list|)
expr_stmt|;
comment|// expected-warning{{data argument position '18' exceeds the number of data arguments (2)}}
name|printf
argument_list|(
literal|"%18$s\n"
argument_list|,
literal|1
argument_list|,
literal|"foo"
argument_list|)
expr_stmt|;
comment|// expected-warning{{data argument position '18' exceeds the number of data arguments (2)}}
specifier|const
name|char
name|kFormat4
index|[]
init|=
literal|"%y"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat4
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{invalid conversion specifier 'y'}}
name|printf
argument_list|(
literal|"%y"
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{invalid conversion specifier 'y'}}
specifier|const
name|char
name|kFormat5
index|[]
init|=
literal|"%."
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{incomplete format specifier}}
name|printf
argument_list|(
literal|"%."
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{incomplete format specifier}}
specifier|const
name|char
name|kFormat6
index|[]
init|=
literal|"%s"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat6
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'int'}}
name|printf
argument_list|(
literal|"%s"
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'int'}}
specifier|const
name|char
name|kFormat7
index|[]
init|=
literal|"%0$"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat7
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{position arguments in format strings start counting at 1 (not 0)}}
name|printf
argument_list|(
literal|"%0$"
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{position arguments in format strings start counting at 1 (not 0)}}
specifier|const
name|char
name|kFormat8
index|[]
init|=
literal|"%1$d %d"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat8
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{cannot mix positional and non-positional arguments in format string}}
name|printf
argument_list|(
literal|"%1$d %d"
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{cannot mix positional and non-positional arguments in format string}}
specifier|const
name|char
name|kFormat9
index|[]
init|=
literal|""
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat9
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{format string is empty}}
name|printf
argument_list|(
literal|""
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{format string is empty}}
specifier|const
name|char
name|kFormat10
index|[]
init|=
literal|"\0%d"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat10
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{format string contains '\0' within the string body}}
name|printf
argument_list|(
literal|"\0%d"
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{format string contains '\0' within the string body}}
specifier|const
name|char
name|kFormat11
index|[]
init|=
literal|"%*d"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat11
argument_list|)
expr_stmt|;
comment|// expected-warning{{'*' specified field width is missing a matching 'int' argument}}
name|printf
argument_list|(
literal|"%*d"
argument_list|)
expr_stmt|;
comment|// expected-warning{{'*' specified field width is missing a matching 'int' argument}}
specifier|const
name|char
name|kFormat12
index|[]
init|=
literal|"%*d"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat12
argument_list|,
literal|4.4
argument_list|)
expr_stmt|;
comment|// expected-warning{{field width should have type 'int', but argument has type 'double'}}
name|printf
argument_list|(
literal|"%*d"
argument_list|,
literal|4.4
argument_list|)
expr_stmt|;
comment|// expected-warning{{field width should have type 'int', but argument has type 'double'}}
specifier|const
name|char
name|kFormat13
index|[]
init|=
literal|"%.3p"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|void
modifier|*
name|p
decl_stmt|;
name|printf
argument_list|(
name|kFormat13
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{precision used with 'p' conversion specifier, resulting in undefined behavior}}
name|printf
argument_list|(
literal|"%.3p"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{precision used with 'p' conversion specifier, resulting in undefined behavior}}
specifier|const
name|char
name|kFormat14
index|[]
init|=
literal|"%0s"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat14
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '0' results in undefined behavior with 's' conversion specifier}}
name|printf
argument_list|(
literal|"%0s"
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '0' results in undefined behavior with 's' conversion specifier}}
specifier|const
name|char
name|kFormat15
index|[]
init|=
literal|"%hhs"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat15
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
comment|// expected-warning{{length modifier 'hh' results in undefined behavior or no effect with 's' conversion specifier}}
name|printf
argument_list|(
literal|"%hhs"
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
comment|// expected-warning{{length modifier 'hh' results in undefined behavior or no effect with 's' conversion specifier}}
specifier|const
name|char
name|kFormat16
index|[]
init|=
literal|"%-0d"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat16
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '0' is ignored when flag '-' is present}}
name|printf
argument_list|(
literal|"%-0d"
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{flag '0' is ignored when flag '-' is present}}
comment|// Make sure that the "format string is defined here" note is not emitted
comment|// when the original string is within the argument expression.
name|printf
argument_list|(
literal|1
condition|?
literal|"yes %d"
else|:
literal|"no %d"
argument_list|)
expr_stmt|;
comment|// expected-warning 2{{more '%' conversions than data arguments}}
specifier|const
name|char
name|kFormat17
index|[]
init|=
literal|"%hu"
decl_stmt|;
comment|// expected-note{{format string is defined here}}}
name|printf
argument_list|(
name|kFormat17
argument_list|,
operator|(
name|int
index|[]
operator|)
block|{
literal|0
block|}
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'unsigned short' but the argument}}
name|printf
argument_list|(
literal|"%a"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'double' but the argument has type 'long double'}}
comment|// Test braced char[] initializers.
specifier|const
name|char
name|kFormat18
index|[]
init|=
block|{
literal|"%lld"
block|}
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat18
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type}}
comment|// Make sure we point at the offending argument rather than the format string.
specifier|const
name|char
name|kFormat19
index|[]
init|=
literal|"%d"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
name|printf
argument_list|(
name|kFormat19
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies}}
block|}
end_function

begin_function
name|void
name|pr18905
parameter_list|()
block|{
specifier|const
name|char
name|s1
index|[]
init|=
literal|"s\0%s"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
specifier|const
name|char
name|s2
index|[
literal|1
index|]
init|=
literal|"s"
decl_stmt|;
comment|// expected-note{{format string is defined here}}
specifier|const
name|char
name|s3
index|[
literal|2
index|]
init|=
literal|"s\0%s"
decl_stmt|;
comment|// expected-warning{{initializer-string for char array is too long}}
specifier|const
name|char
name|s4
index|[
literal|10
index|]
init|=
literal|"s"
decl_stmt|;
specifier|const
name|char
name|s5
index|[
literal|0
index|]
init|=
literal|"%s"
decl_stmt|;
comment|// expected-warning{{initializer-string for char array is too long}}
comment|// expected-note@-1{{format string is defined here}}
name|printf
argument_list|(
name|s1
argument_list|)
expr_stmt|;
comment|// expected-warning{{format string contains '\0' within the string body}}
name|printf
argument_list|(
name|s2
argument_list|)
expr_stmt|;
comment|// expected-warning{{format string is not null-terminated}}
name|printf
argument_list|(
name|s3
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
name|s4
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
name|s5
argument_list|)
expr_stmt|;
comment|// expected-warning{{format string is not null-terminated}}
block|}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|strfmon
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
name|monformat
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|strftime
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
operator|)
argument_list|)
name|dateformat
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Other formats
end_comment

begin_function
name|void
name|test_other_formats
parameter_list|()
block|{
name|char
modifier|*
name|str
init|=
literal|""
decl_stmt|;
name|monformat
argument_list|(
literal|""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{format string is empty}}
name|monformat
argument_list|(
name|str
argument_list|)
expr_stmt|;
comment|// expected-warning{{format string is not a string literal (potentially insecure)}}
name|dateformat
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|// expected-warning{{format string is empty}}
name|dateformat
argument_list|(
name|str
argument_list|)
expr_stmt|;
comment|// no-warning (using strftime non-literal is not unsafe)
block|}
end_function

begin_comment
comment|// Do not warn about unused arguments coming from system headers.
end_comment

begin_comment
comment|//<rdar://problem/11317765>
end_comment

begin_include
include|#
directive|include
file|<format-unused-system-args.h>
end_include

begin_function
name|void
name|test_unused_system_args
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|PRINT1
argument_list|(
literal|"%d\n"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// no-warning{{extra argument is system header is OK}}
block|}
end_function

begin_function
name|void
name|pr12761
parameter_list|(
name|char
name|c
parameter_list|)
block|{
comment|// This should not warn even with -fno-signed-char.
name|printf
argument_list|(
literal|"%hhx"
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Test that we correctly merge the format in both orders.
end_comment

begin_function_decl
specifier|extern
name|void
name|test14_foo
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
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
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|test14_foo
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
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
name|__scanf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|test14_bar
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
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
name|__scanf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|test14_bar
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
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
name|__printf__
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
name|test14_zed
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|test14_foo
argument_list|(
literal|"%"
argument_list|,
literal|"%d"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{incomplete format specifier}}
name|test14_bar
argument_list|(
literal|"%"
argument_list|,
literal|"%d"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{incomplete format specifier}}
block|}
end_function

begin_function
name|void
name|test_qualifiers
parameter_list|(
specifier|volatile
name|int
modifier|*
name|vip
parameter_list|,
specifier|const
name|int
modifier|*
name|cip
parameter_list|,
specifier|const
specifier|volatile
name|int
modifier|*
name|cvip
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%n"
argument_list|,
name|cip
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int *' but the argument has type 'const int *'}}
name|printf
argument_list|(
literal|"%n"
argument_list|,
name|cvip
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int *' but the argument has type 'const volatile int *'}}
name|printf
argument_list|(
literal|"%n"
argument_list|,
name|vip
argument_list|)
expr_stmt|;
comment|// No warning.
name|printf
argument_list|(
literal|"%p"
argument_list|,
name|cip
argument_list|)
expr_stmt|;
comment|// No warning.
name|printf
argument_list|(
literal|"%p"
argument_list|,
name|cvip
argument_list|)
expr_stmt|;
comment|// No warning.
typedef|typedef
name|int
modifier|*
name|ip_t
typedef|;
typedef|typedef
specifier|const
name|int
modifier|*
name|cip_t
typedef|;
name|printf
argument_list|(
literal|"%n"
argument_list|,
operator|(
name|ip_t
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// No warning.
name|printf
argument_list|(
literal|"%n"
argument_list|,
operator|(
name|cip_t
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int *' but the argument has type 'cip_t' (aka 'const int *')}}
block|}
end_function

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

begin_comment
comment|//<rdar://problem/14178260>
end_comment

begin_function_decl
specifier|extern
name|void
name|test_format_security_extra_args
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
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
name|test_format_security_pos
parameter_list|(
name|char
modifier|*
name|string
parameter_list|)
block|{
name|test_format_security_extra_args
argument_list|(
name|string
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning {{format string is not a string literal (potentially insecure)}}
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|warning
literal|"-Wformat-nonliteral"
end_pragma

end_unit

