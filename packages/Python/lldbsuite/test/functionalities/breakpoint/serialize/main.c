begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- main.c --------------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|// This simple program is to demonstrate the capability of the lldb command
end_comment

begin_comment
comment|// "breakpoint modify -i<count> breakpt-id" to set the number of times a
end_comment

begin_comment
comment|// breakpoint is skipped before stopping.  Ignore count can also be set upon
end_comment

begin_comment
comment|// breakpoint creation by 'breakpoint set ... -i<count>'.
end_comment

begin_function_decl
name|int
name|a
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|b
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|c
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|a
parameter_list|(
name|int
name|val
parameter_list|)
block|{
if|if
condition|(
name|val
operator|<=
literal|1
condition|)
return|return
name|b
argument_list|(
name|val
argument_list|)
return|;
elseif|else
if|if
condition|(
name|val
operator|>=
literal|3
condition|)
return|return
name|c
argument_list|(
name|val
argument_list|)
return|;
comment|// a(3) -> c(3) Find the call site of c(3).
return|return
name|val
return|;
block|}
end_function

begin_function
name|int
name|b
parameter_list|(
name|int
name|val
parameter_list|)
block|{
return|return
name|c
argument_list|(
name|val
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|c
parameter_list|(
name|int
name|val
parameter_list|)
block|{
return|return
name|val
operator|+
literal|3
return|;
comment|// Find the line number of function "c" here.
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
specifier|const
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|A1
init|=
name|a
argument_list|(
literal|1
argument_list|)
decl_stmt|;
comment|// a(1) -> b(1) -> c(1)
name|printf
argument_list|(
literal|"a(1) returns %d\n"
argument_list|,
name|A1
argument_list|)
expr_stmt|;
name|int
name|B2
init|=
name|b
argument_list|(
literal|2
argument_list|)
decl_stmt|;
comment|// b(2) -> c(2) Find the call site of b(2).
name|printf
argument_list|(
literal|"b(2) returns %d\n"
argument_list|,
name|B2
argument_list|)
expr_stmt|;
name|int
name|A3
init|=
name|a
argument_list|(
literal|3
argument_list|)
decl_stmt|;
comment|// a(3) -> c(3) Find the call site of a(3).
name|printf
argument_list|(
literal|"a(3) returns %d\n"
argument_list|,
name|A3
argument_list|)
expr_stmt|;
name|int
name|C1
init|=
name|c
argument_list|(
literal|5
argument_list|)
decl_stmt|;
comment|// Find the call site of c in main.
name|printf
argument_list|(
literal|"c(5) returns %d\n"
argument_list|,
name|C1
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

