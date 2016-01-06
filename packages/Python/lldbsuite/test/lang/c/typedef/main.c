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

begin_function
name|void
name|test
parameter_list|()
block|{
typedef|typedef
name|double
modifier|*
name|a
typedef|;
name|a
name|b
init|=
literal|0
decl_stmt|;
comment|// Set break point 4.
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
typedef|typedef
name|float
name|a
typedef|;
name|int
name|i
init|=
literal|0
decl_stmt|;
comment|// Set break point 1.
name|i
operator|++
expr_stmt|;
name|a
name|floatvariable
init|=
literal|2.7
decl_stmt|;
comment|// Set break point 2.
block|{
typedef|typedef
name|char
name|a
typedef|;
name|i
operator|++
expr_stmt|;
name|a
name|charvariable
init|=
literal|'a'
decl_stmt|;
comment|// Set break point 3.
name|test
argument_list|()
expr_stmt|;
block|}
block|{
name|int
name|c
init|=
literal|0
decl_stmt|;
name|c
operator|++
expr_stmt|;
comment|// Set break point 5.
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
name|i
operator|++
control|)
block|{
typedef|typedef
name|int
name|a
typedef|;
name|a
name|b
decl_stmt|;
name|b
operator|=
literal|7
expr_stmt|;
comment|// Set break point 6.
block|}
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
name|i
operator|++
control|)
block|{
typedef|typedef
name|double
name|a
typedef|;
name|a
name|b
decl_stmt|;
name|b
operator|=
literal|3.14
expr_stmt|;
comment|// Set break point 7.
block|}
name|c
operator|=
literal|1
expr_stmt|;
comment|// Set break point 8.
block|}
name|floatvariable
operator|=
literal|2.5
expr_stmt|;
name|floatvariable
operator|=
literal|2.8
expr_stmt|;
comment|// Set break point 9.
return|return
literal|0
return|;
block|}
end_function

end_unit

