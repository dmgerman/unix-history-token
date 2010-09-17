begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wformat-nonliteral %s
end_comment

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

end_unit

