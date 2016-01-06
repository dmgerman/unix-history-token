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
enum|enum
name|days
block|{
name|Monday
init|=
literal|10
block|,
name|Tuesday
block|,
name|Wednesday
block|,
name|Thursday
block|,
name|Friday
block|,
name|Saturday
block|,
name|Sunday
block|,
name|kNumDays
block|}
enum|;
name|enum
name|days
name|day
decl_stmt|;
for|for
control|(
name|day
operator|=
name|Monday
operator|-
literal|1
init|;
name|day
operator|<=
name|kNumDays
operator|+
literal|1
condition|;
name|day
operator|++
control|)
block|{
name|printf
argument_list|(
literal|"day as int is %i\n"
argument_list|,
operator|(
name|int
operator|)
name|day
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
comment|// Set break point at this line.
block|}
end_function

end_unit

