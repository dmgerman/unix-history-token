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

begin_struct
struct|struct
name|things_to_sum
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
name|int
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|sum_things
parameter_list|(
name|struct
name|things_to_sum
name|tts
parameter_list|)
block|{
return|return
name|tts
operator|.
name|a
operator|+
name|tts
operator|.
name|b
operator|+
name|tts
operator|.
name|c
return|;
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
struct|struct
name|point_tag
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
name|char
name|padding
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
comment|//% self.expect("frame variable pt.padding[0]", DATA_TYPES_DISPLAYED_CORRECTLY, substrs = ["pt.padding[0] = "])
comment|//% self.expect("frame variable pt.padding[1]", DATA_TYPES_DISPLAYED_CORRECTLY, substrs = ["pt.padding[1] = "])
comment|//% self.expect("expression -- (pt.padding[0])", DATA_TYPES_DISPLAYED_CORRECTLY, substrs = ["(char)", " = "])
comment|//% self.expect("image lookup -t point_tag", DATA_TYPES_DISPLAYED_CORRECTLY, substrs = ['padding[]']) # Once rdar://problem/12566646 is fixed, this should display correctly
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
block|,
block|{}
block|}
decl_stmt|;
name|struct
name|rect_tag
name|rect
init|=
block|{
block|{
literal|1
block|,
literal|2
block|,
block|{}
block|}
block|,
block|{
literal|3
block|,
literal|4
block|,
block|{}
block|}
block|}
decl_stmt|;
name|struct
name|things_to_sum
name|tts
init|=
block|{
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|int
name|sum
init|=
name|sum_things
argument_list|(
name|tts
argument_list|)
decl_stmt|;
comment|//% self.expect("expression --&pt == (struct point_tag*)0", substrs = ['false'])
comment|//% self.expect("expression -- sum_things(tts)", substrs = ['9'])
return|return
literal|0
return|;
block|}
end_function

end_unit

