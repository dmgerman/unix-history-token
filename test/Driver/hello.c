begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-echo -o %t %s 2> %t.log&&
end_comment

begin_comment
comment|// Make sure we used clang.
end_comment

begin_comment
comment|// RUN: grep 'clang-cc" .*hello.c' %t.log&&
end_comment

begin_comment
comment|// RUN: %t> %t.out&&
end_comment

begin_comment
comment|// RUN: grep "I'm a little driver, short and stout." %t.out
end_comment

begin_comment
comment|// FIXME: We don't have a usable assembler on Windows, so we can't build real
end_comment

begin_comment
comment|// apps yet.
end_comment

begin_comment
comment|// XFAIL: win32
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
name|printf
argument_list|(
literal|"I'm a little driver, short and stout."
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

