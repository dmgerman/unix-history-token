begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_asan -O2 %s -o %t&& %run %t
end_comment

begin_comment
comment|// FIXME: printf is not intercepted on Windows yet.
end_comment

begin_comment
comment|// UNSUPPORTED: win32
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|char
name|s
index|[
literal|5
index|]
init|=
block|{
literal|'w'
block|,
literal|'o'
block|,
literal|'r'
block|,
literal|'l'
block|,
literal|'d'
block|}
decl_stmt|;
comment|// Test that %m does not consume an argument. If it does, %s would apply to
comment|// the 5-character buffer, resulting in a stack-buffer-overflow report.
name|printf
argument_list|(
literal|"%m %s, %.5s\n"
argument_list|,
literal|"hello"
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

