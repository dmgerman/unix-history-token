begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: cp %s %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pedantic -Wall -fixit %t || true
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -pedantic -Wall -Werror %t
end_comment

begin_comment
comment|/* This is a test of the various code modification hints that are    provided as part of warning or extension diagnostics. All of the    warnings will be fixed by -fixit, and the resulting file should    compile cleanly with -Werror -pedantic. */
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

begin_function
name|void
name|test
parameter_list|()
block|{
comment|// Basic types
name|printf
argument_list|(
literal|"%s"
argument_list|,
operator|(
name|int
operator|)
literal|123
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"abc%0f"
argument_list|,
literal|"testing testing 123"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%u"
argument_list|,
operator|(
name|long
operator|)
operator|-
literal|12
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%p"
argument_list|,
literal|123
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%c\n"
argument_list|,
literal|"x"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%c\n"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// Larger types
name|printf
argument_list|(
literal|"%+.2d"
argument_list|,
operator|(
name|unsigned
name|long
name|long
operator|)
literal|123456
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%1d"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|1.23
argument_list|)
expr_stmt|;
comment|// Flag handling
name|printf
argument_list|(
literal|"%0+s"
argument_list|,
operator|(
name|unsigned
operator|)
literal|31337
argument_list|)
expr_stmt|;
comment|// 0 flag should stay
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
name|printf
argument_list|(
literal|"% +f"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// + flag should stay
name|printf
argument_list|(
literal|"%0-f"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// - flag should stay
comment|// Positional arguments
name|printf
argument_list|(
literal|"%1$f:%2$.*3$f:%4$.*3$f\n"
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// Precision
name|printf
argument_list|(
literal|"%10.5d"
argument_list|,
literal|1l
argument_list|)
expr_stmt|;
comment|// (bug 7394)
name|printf
argument_list|(
literal|"%.2c"
argument_list|,
literal|'a'
argument_list|)
expr_stmt|;
comment|// Ignored flags
name|printf
argument_list|(
literal|"%0-f"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// Bad length modifiers
name|printf
argument_list|(
literal|"%hhs"
argument_list|,
literal|"foo"
argument_list|)
expr_stmt|;
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
block|}
end_function

end_unit

