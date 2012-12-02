begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -pedantic %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// PR4287
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_decl_stmt
name|char
modifier|*
name|foo
init|=
literal|"test"
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|test
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test
parameter_list|(
name|fmt
parameter_list|)
name|char
modifier|*
name|fmt
decl_stmt|;
block|{
name|va_list
name|ap
decl_stmt|;
name|char
modifier|*
name|a
decl_stmt|;
name|int
name|x
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|a
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|char
operator|*
argument_list|)
expr_stmt|;
name|x
operator|=
operator|(
name|a
operator|!=
name|foo
operator|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_function_decl
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|exit
argument_list|(
name|test
argument_list|(
literal|""
argument_list|,
name|foo
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

