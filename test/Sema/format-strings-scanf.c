begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wformat-nonliteral %s
end_comment

begin_comment
comment|// Test that -Wformat=0 works:
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Werror -Wformat=0 %s
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

begin_typedef
typedef|typedef
name|__WCHAR_TYPE__
name|wchar_t
typedef|;
end_typedef

begin_function_decl
name|int
name|fscanf
parameter_list|(
name|FILE
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

begin_function_decl
name|int
name|sscanf
parameter_list|(
specifier|const
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
name|my_scanf
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
name|__scanf__
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
name|vscanf
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
name|vfscanf
parameter_list|(
name|FILE
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

begin_function_decl
name|int
name|vsscanf
parameter_list|(
specifier|const
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

begin_function
name|void
name|test
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
modifier|*
name|i
parameter_list|)
block|{
name|scanf
argument_list|(
name|s
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{ormat string is not a string literal}}
name|scanf
argument_list|(
literal|"%0d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{zero field width in scanf format string is unused}}
name|scanf
argument_list|(
literal|"%00d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{zero field width in scanf format string is unused}}
name|scanf
argument_list|(
literal|"%d%[asdfasdfd"
argument_list|,
name|i
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning{{no closing ']' for '%[' in scanf format string}}
name|unsigned
name|short
name|s_x
decl_stmt|;
name|scanf
argument_list|(
literal|"%"
literal|"hu"
literal|"\n"
argument_list|,
operator|&
name|s_x
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%y"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{invalid conversion specifier 'y'}}
name|scanf
argument_list|(
literal|"%%"
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%%%1$d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%1$d%%"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%d"
argument_list|,
name|i
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{data argument not used by format string}}
name|scanf
argument_list|(
literal|"%*d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// // expected-warning{{data argument not used by format string}}
name|scanf
argument_list|(
literal|"%*d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// // expected-warning{{data argument not used by format string}}
name|scanf
argument_list|(
literal|"%*d%1$d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%s"
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%s"
argument_list|,
operator|(
specifier|volatile
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%s"
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
name|scanf
argument_list|(
literal|"%s"
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
name|scanf
argument_list|(
literal|"%hhu"
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
block|}
end_function

begin_function
name|void
name|bad_length_modifiers
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|void
modifier|*
name|p
parameter_list|,
name|wchar_t
modifier|*
name|ws
parameter_list|,
name|long
name|double
modifier|*
name|ld
parameter_list|)
block|{
name|scanf
argument_list|(
literal|"%hhs"
argument_list|,
literal|"foo"
argument_list|)
expr_stmt|;
comment|// expected-warning{{length modifier 'hh' results in undefined behavior or no effect with 's' conversion specifier}}
name|scanf
argument_list|(
literal|"%1$zp"
argument_list|,
operator|&
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{length modifier 'z' results in undefined behavior or no effect with 'p' conversion specifier}}
name|scanf
argument_list|(
literal|"%ls"
argument_list|,
name|ws
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%#.2Lf"
argument_list|,
name|ld
argument_list|)
expr_stmt|;
comment|// expected-warning{{invalid conversion specifier '#'}}
block|}
end_function

begin_comment
comment|// Test that the scanf call site is where the warning is attached.  If the
end_comment

begin_comment
comment|// format string is somewhere else, point to it in a note.
end_comment

begin_function
name|void
name|pr9751
parameter_list|()
block|{
name|int
modifier|*
name|i
decl_stmt|;
name|char
name|str
index|[
literal|100
index|]
decl_stmt|;
specifier|const
name|char
name|kFormat1
index|[]
init|=
literal|"%00d"
decl_stmt|;
comment|// expected-note{{format string is defined here}}}
name|scanf
argument_list|(
name|kFormat1
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{zero field width in scanf format string is unused}}
name|scanf
argument_list|(
literal|"%00d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{zero field width in scanf format string is unused}}
specifier|const
name|char
name|kFormat2
index|[]
init|=
literal|"%["
decl_stmt|;
comment|// expected-note{{format string is defined here}}}
name|scanf
argument_list|(
name|kFormat2
argument_list|,
name|str
argument_list|)
expr_stmt|;
comment|// expected-warning{{no closing ']' for '%[' in scanf format string}}
name|scanf
argument_list|(
literal|"%["
argument_list|,
name|str
argument_list|)
expr_stmt|;
comment|// expected-warning{{no closing ']' for '%[' in scanf format string}}
specifier|const
name|char
name|kFormat3
index|[]
init|=
literal|"%hu"
decl_stmt|;
comment|// expected-note{{format string is defined here}}}
name|scanf
argument_list|(
name|kFormat3
argument_list|,
operator|&
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'unsigned short *' but the argument}}
specifier|const
name|char
name|kFormat4
index|[]
init|=
literal|"%lp"
decl_stmt|;
comment|// expected-note{{format string is defined here}}}
name|scanf
argument_list|(
name|kFormat4
argument_list|,
operator|&
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning {{length modifier 'l' results in undefined behavior or no effect with 'p' conversion specifier}}
block|}
end_function

begin_function
name|void
name|test_variants
parameter_list|(
name|int
modifier|*
name|i
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
modifier|...
parameter_list|)
block|{
name|FILE
modifier|*
name|f
init|=
literal|0
decl_stmt|;
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|fscanf
argument_list|(
name|f
argument_list|,
literal|"%ld"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'long *' but the argument has type 'int *'}}
name|sscanf
argument_list|(
name|buf
argument_list|,
literal|"%ld"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'long *' but the argument has type 'int *'}}
name|my_scanf
argument_list|(
literal|"%ld"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'long *' but the argument has type 'int *'}}
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|vscanf
argument_list|(
literal|"%[abc"
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// expected-warning{{no closing ']' for '%[' in scanf format string}}
name|vfscanf
argument_list|(
name|f
argument_list|,
literal|"%[abc"
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// expected-warning{{no closing ']' for '%[' in scanf format string}}
name|vsscanf
argument_list|(
name|buf
argument_list|,
literal|"%[abc"
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|// expected-warning{{no closing ']' for '%[' in scanf format string}}
block|}
end_function

begin_function
name|void
name|test_scanlist
parameter_list|(
name|int
modifier|*
name|ip
parameter_list|,
name|char
modifier|*
name|sp
parameter_list|,
name|wchar_t
modifier|*
name|ls
parameter_list|)
block|{
name|scanf
argument_list|(
literal|"%[abc]"
argument_list|,
name|ip
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'int *'}}
name|scanf
argument_list|(
literal|"%h[abc]"
argument_list|,
name|sp
argument_list|)
expr_stmt|;
comment|// expected-warning{{length modifier 'h' results in undefined behavior or no effect with '[' conversion specifier}}
name|scanf
argument_list|(
literal|"%l[xyx]"
argument_list|,
name|ls
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%ll[xyx]"
argument_list|,
name|ls
argument_list|)
expr_stmt|;
comment|// expected-warning {{length modifier 'll' results in undefined behavior or no effect with '[' conversion specifier}}
comment|// PR19559
name|scanf
argument_list|(
literal|"%[]% ]"
argument_list|,
name|sp
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%[^]% ]"
argument_list|,
name|sp
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%[a^]% ]"
argument_list|,
name|sp
argument_list|)
expr_stmt|;
comment|// expected-warning {{invalid conversion specifier ' '}}
block|}
end_function

begin_function
name|void
name|test_alloc_extension
parameter_list|(
name|char
modifier|*
modifier|*
name|sp
parameter_list|,
name|wchar_t
modifier|*
modifier|*
name|lsp
parameter_list|,
name|float
modifier|*
name|fp
parameter_list|)
block|{
comment|/* Make sure "%a" gets parsed as a conversion specifier for float,    * even when followed by an 's', 'S' or '[', which would cause it to be    * parsed as a length modifier in C90. */
name|scanf
argument_list|(
literal|"%as"
argument_list|,
name|sp
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'float *' but the argument has type 'char **'}}
name|scanf
argument_list|(
literal|"%aS"
argument_list|,
name|lsp
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'float *' but the argument has type 'wchar_t **'}}
name|scanf
argument_list|(
literal|"%a[bcd]"
argument_list|,
name|sp
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'float *' but the argument has type 'char **'}}
comment|// Test that the 'm' length modifier is only allowed with s, S, c, C or [.
comment|// TODO: Warn that 'm' is an extension.
name|scanf
argument_list|(
literal|"%ms"
argument_list|,
name|sp
argument_list|)
expr_stmt|;
comment|// No warning.
name|scanf
argument_list|(
literal|"%mS"
argument_list|,
name|lsp
argument_list|)
expr_stmt|;
comment|// No warning.
name|scanf
argument_list|(
literal|"%mc"
argument_list|,
name|sp
argument_list|)
expr_stmt|;
comment|// No warning.
name|scanf
argument_list|(
literal|"%mC"
argument_list|,
name|lsp
argument_list|)
expr_stmt|;
comment|// No warning.
name|scanf
argument_list|(
literal|"%m[abc]"
argument_list|,
name|sp
argument_list|)
expr_stmt|;
comment|// No warning.
name|scanf
argument_list|(
literal|"%md"
argument_list|,
name|sp
argument_list|)
expr_stmt|;
comment|// expected-warning{{length modifier 'm' results in undefined behavior or no effect with 'd' conversion specifier}}
comment|// Test argument type check for the 'm' length modifier.
name|scanf
argument_list|(
literal|"%ms"
argument_list|,
name|fp
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char **' but the argument has type 'float *'}}
name|scanf
argument_list|(
literal|"%mS"
argument_list|,
name|fp
argument_list|)
expr_stmt|;
comment|// expected-warning-re{{format specifies type 'wchar_t **' (aka '{{[^']+}}') but the argument has type 'float *'}}
name|scanf
argument_list|(
literal|"%mc"
argument_list|,
name|fp
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char **' but the argument has type 'float *'}}
name|scanf
argument_list|(
literal|"%mC"
argument_list|,
name|fp
argument_list|)
expr_stmt|;
comment|// expected-warning-re{{format specifies type 'wchar_t **' (aka '{{[^']+}}') but the argument has type 'float *'}}
name|scanf
argument_list|(
literal|"%m[abc]"
argument_list|,
name|fp
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char **' but the argument has type 'float *'}}
block|}
end_function

begin_function
name|void
name|test_quad
parameter_list|(
name|int
modifier|*
name|x
parameter_list|,
name|long
name|long
modifier|*
name|llx
parameter_list|)
block|{
name|scanf
argument_list|(
literal|"%qd"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'long long *' but the argument has type 'int *'}}
name|scanf
argument_list|(
literal|"%qd"
argument_list|,
name|llx
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|test_writeback
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
block|{
name|scanf
argument_list|(
literal|"%n"
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int *' but the argument has type 'void *'}}
name|scanf
argument_list|(
literal|"%n %c"
argument_list|,
name|x
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'int *'}}
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
name|scanf
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
block|}
end_function

begin_function
name|void
name|test_qualifiers
parameter_list|(
specifier|const
name|int
modifier|*
name|cip
parameter_list|,
specifier|volatile
name|int
modifier|*
name|vip
parameter_list|,
specifier|const
name|char
modifier|*
name|ccp
parameter_list|,
specifier|volatile
name|char
modifier|*
name|vcp
parameter_list|,
specifier|const
specifier|volatile
name|int
modifier|*
name|cvip
parameter_list|)
block|{
name|scanf
argument_list|(
literal|"%d"
argument_list|,
name|cip
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int *' but the argument has type 'const int *'}}
name|scanf
argument_list|(
literal|"%n"
argument_list|,
name|cip
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int *' but the argument has type 'const int *'}}
name|scanf
argument_list|(
literal|"%s"
argument_list|,
name|ccp
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'const char *'}}
name|scanf
argument_list|(
literal|"%d"
argument_list|,
name|cvip
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'int *' but the argument has type 'const volatile int *'}}
name|scanf
argument_list|(
literal|"%d"
argument_list|,
name|vip
argument_list|)
expr_stmt|;
comment|// No warning.
name|scanf
argument_list|(
literal|"%n"
argument_list|,
name|vip
argument_list|)
expr_stmt|;
comment|// No warning.
name|scanf
argument_list|(
literal|"%c"
argument_list|,
name|vcp
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
name|scanf
argument_list|(
literal|"%d"
argument_list|,
operator|(
name|ip_t
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// No warning.
name|scanf
argument_list|(
literal|"%d"
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

end_unit

