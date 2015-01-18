begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple i386-apple-darwin9 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple thumbv6-apple-ios4.0 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-mingw32 -DMS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple i686-pc-win32 -DMS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple i686-linux-gnu -DALLOWED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-unknown-freebsd -DALLOWED %s
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
name|long
name|notLongEnough
init|=
literal|1
decl_stmt|;
name|long
name|long
name|quiteLong
init|=
literal|2
decl_stmt|;
name|printf
argument_list|(
literal|"%Ld"
argument_list|,
name|notLongEnough
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'long long' but the argument has type 'long'}}
name|printf
argument_list|(
literal|"%Ld"
argument_list|,
name|quiteLong
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|ALLOWED
comment|// expected-warning@-4 {{length modifier 'L' results in undefined behavior or no effect with 'd' conversion specifier}}
comment|// expected-note@-5 {{did you mean to use 'll'?}}
comment|// expected-warning@-6 {{length modifier 'L' results in undefined behavior or no effect with 'd' conversion specifier}}
comment|// expected-note@-7 {{did you mean to use 'll'?}}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MS
name|printf
argument_list|(
literal|"%Z\n"
argument_list|,
name|quiteLong
argument_list|)
expr_stmt|;
comment|// expected-warning{{invalid conversion specifier 'Z'}}
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|testAlwaysInvalid
parameter_list|()
block|{
comment|// We should not suggest 'll' here!
name|printf
argument_list|(
literal|"%Lc"
argument_list|,
literal|'a'
argument_list|)
expr_stmt|;
comment|// expected-warning {{length modifier 'L' results in undefined behavior or no effect with 'c' conversion specifier}}
name|printf
argument_list|(
literal|"%Ls"
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
comment|// expected-warning {{length modifier 'L' results in undefined behavior or no effect with 's' conversion specifier}}
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|ALLOWED
end_ifdef

begin_comment
comment|// PR 9466: clang: doesn't know about %Lu, %Ld, and %Lx
end_comment

begin_function
name|void
name|printf_longlong
parameter_list|(
name|long
name|long
name|x
parameter_list|,
name|unsigned
name|long
name|long
name|y
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%Ld"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%Lu"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%Lx"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%Ld"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%Lu"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%Lx"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%Ls"
argument_list|,
literal|"hello"
argument_list|)
expr_stmt|;
comment|// expected-warning {{length modifier 'L' results in undefined behavior or no effect with 's' conversion specifier}}
block|}
end_function

begin_function
name|void
name|scanf_longlong
parameter_list|(
name|long
name|long
modifier|*
name|x
parameter_list|,
name|unsigned
name|long
name|long
modifier|*
name|y
parameter_list|)
block|{
name|scanf
argument_list|(
literal|"%Ld"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%Lu"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%Lx"
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%Ld"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%Lu"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%Lx"
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
name|scanf
argument_list|(
literal|"%Ls"
argument_list|,
literal|"hello"
argument_list|)
expr_stmt|;
comment|// expected-warning {{length modifier 'L' results in undefined behavior or no effect with 's' conversion specifier}}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

