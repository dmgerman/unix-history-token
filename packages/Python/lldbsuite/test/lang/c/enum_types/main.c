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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|// Forward declare an enumeration (only works in C, not C++)
end_comment

begin_typedef
typedef|typedef
name|enum
name|ops
name|ops
typedef|;
end_typedef

begin_struct
struct|struct
name|foo
block|{
name|ops
modifier|*
name|op
decl_stmt|;
block|}
struct|;
end_struct

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
operator|-
literal|3
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
name|struct
name|foo
name|f
decl_stmt|;
name|f
operator|.
name|op
operator|=
name|NULL
expr_stmt|;
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
comment|// Set break point at this line.
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

