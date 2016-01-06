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
struct|struct
name|point_tag
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
comment|// Set break point at this line.
struct|struct
name|rect_tag
block|{
name|struct
name|point_tag
name|bottom_left
decl_stmt|;
name|struct
name|point_tag
name|top_right
decl_stmt|;
block|}
struct|;
name|struct
name|point_tag
name|pt
init|=
block|{
literal|2
block|,
literal|3
block|}
decl_stmt|;
comment|// This is the first executable statement.
name|struct
name|rect_tag
name|rect
init|=
block|{
block|{
literal|1
block|,
literal|2
block|}
block|,
block|{
literal|3
block|,
literal|4
block|}
block|}
decl_stmt|;
name|pt
operator|.
name|x
operator|=
name|argc
expr_stmt|;
name|pt
operator|.
name|y
operator|=
name|argc
operator|*
name|argc
expr_stmt|;
name|rect
operator|.
name|top_right
operator|.
name|x
operator|=
name|rect
operator|.
name|top_right
operator|.
name|x
operator|+
name|argc
expr_stmt|;
name|rect
operator|.
name|top_right
operator|.
name|y
operator|=
name|rect
operator|.
name|top_right
operator|.
name|y
operator|+
name|argc
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

