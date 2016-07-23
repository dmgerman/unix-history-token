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

begin_decl_stmt
name|int
name|g_global_var
init|=
literal|123
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|g_static_var
init|=
literal|123
decl_stmt|;
end_decl_stmt

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
specifier|static
name|int
name|static_var
init|=
literal|123
decl_stmt|;
name|g_static_var
operator|=
literal|123
expr_stmt|;
comment|// clang bug. Need to touch this variable, otherwise it disappears.
name|int
name|i
init|=
literal|0
decl_stmt|;
comment|// breakpoint 1
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|1
condition|;
operator|++
name|i
control|)
block|{
name|int
name|j
init|=
name|i
operator|*
literal|2
decl_stmt|;
name|printf
argument_list|(
literal|"i = %i, j = %i\n"
argument_list|,
name|i
argument_list|,
name|j
argument_list|)
expr_stmt|;
comment|// breakpoint 2
block|{
name|int
name|k
init|=
name|i
operator|*
name|j
operator|*
literal|3
decl_stmt|;
name|printf
argument_list|(
literal|"i = %i, j = %i\n"
argument_list|,
name|i
argument_list|,
name|j
argument_list|)
expr_stmt|;
comment|// breakpoint 3
block|}
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

