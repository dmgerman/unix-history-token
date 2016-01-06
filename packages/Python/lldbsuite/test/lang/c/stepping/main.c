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

begin_decl_stmt
specifier|const
name|char
modifier|*
name|print_string
init|=
literal|"aaaaaaaaaa\n"
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|a
parameter_list|(
name|int
name|val
parameter_list|)
block|{
name|int
name|return_value
init|=
name|val
decl_stmt|;
comment|// basic break at the start of b
if|if
condition|(
name|val
operator|<=
literal|1
condition|)
block|{
name|return_value
operator|=
name|b
argument_list|(
name|val
argument_list|)
expr_stmt|;
comment|// break here to stop in a before calling b
block|}
elseif|else
if|if
condition|(
name|val
operator|>=
literal|3
condition|)
block|{
name|return_value
operator|=
name|c
argument_list|(
name|val
argument_list|)
expr_stmt|;
block|}
return|return
name|return_value
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
name|int
name|rc
init|=
name|c
argument_list|(
name|val
argument_list|)
decl_stmt|;
comment|// thread step-out while stopped at "c(2)"
return|return
name|rc
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
name|complex
parameter_list|(
name|int
name|first
parameter_list|,
name|int
name|second
parameter_list|,
name|int
name|third
parameter_list|)
block|{
return|return
name|first
operator|+
name|second
operator|+
name|third
return|;
comment|// Step in targeting complex should stop here
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
comment|// frame select 2, thread step-out while stopped at "c(1)"
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
comment|// frame select 1, thread step-out while stopped at "c(3)"
name|printf
argument_list|(
literal|"a(3) returns %d\n"
argument_list|,
name|A3
argument_list|)
expr_stmt|;
name|int
name|A4
init|=
name|complex
argument_list|(
name|a
argument_list|(
literal|1
argument_list|)
argument_list|,
name|b
argument_list|(
literal|2
argument_list|)
argument_list|,
name|c
argument_list|(
literal|3
argument_list|)
argument_list|)
decl_stmt|;
comment|// Stop here to try step in targeting b.
name|int
name|A5
init|=
name|complex
argument_list|(
name|a
argument_list|(
literal|2
argument_list|)
argument_list|,
name|b
argument_list|(
literal|3
argument_list|)
argument_list|,
name|c
argument_list|(
literal|4
argument_list|)
argument_list|)
decl_stmt|;
comment|// Stop here to try step in targeting complex.
name|int
name|A6
init|=
name|complex
argument_list|(
name|a
argument_list|(
literal|4
argument_list|)
argument_list|,
name|b
argument_list|(
literal|5
argument_list|)
argument_list|,
name|c
argument_list|(
literal|6
argument_list|)
argument_list|)
decl_stmt|;
comment|// Stop here to step targeting b and hitting breakpoint.
name|int
name|A7
init|=
name|complex
argument_list|(
name|a
argument_list|(
literal|5
argument_list|)
argument_list|,
name|b
argument_list|(
literal|6
argument_list|)
argument_list|,
name|c
argument_list|(
literal|7
argument_list|)
argument_list|)
decl_stmt|;
comment|// Stop here to make sure bogus target steps over.
name|printf
argument_list|(
literal|"I am using print_string: %s.\n"
argument_list|,
name|print_string
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

