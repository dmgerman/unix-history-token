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
file|<stdint.h>
end_include

begin_comment
comment|// This simple program is to test the lldb Python API SBValue.GetChildAtIndex().
end_comment

begin_decl_stmt
name|int
name|g_my_int
init|=
literal|100
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|days_of_week
index|[
literal|7
index|]
init|=
block|{
literal|"Sunday"
block|,
literal|"Monday"
block|,
literal|"Tuesday"
block|,
literal|"Wednesday"
block|,
literal|"Thursday"
block|,
literal|"Friday"
block|,
literal|"Saturday"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|weekdays
index|[
literal|5
index|]
init|=
block|{
literal|"Monday"
block|,
literal|"Tuesday"
block|,
literal|"Wednesday"
block|,
literal|"Thursday"
block|,
literal|"Friday"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
modifier|*
name|g_table
index|[
literal|2
index|]
init|=
block|{
name|days_of_week
block|,
name|weekdays
block|}
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|MyInt
typedef|;
end_typedef

begin_struct
struct|struct
name|MyStruct
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
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
name|uint32_t
name|uinthex
init|=
literal|0xE0A35F10
decl_stmt|;
name|int32_t
name|sinthex
init|=
literal|0xE0A35F10
decl_stmt|;
name|int
name|i
decl_stmt|;
name|MyInt
name|a
init|=
literal|12345
decl_stmt|;
name|struct
name|MyStruct
name|s
init|=
block|{
literal|11
block|,
literal|22
block|}
decl_stmt|;
name|int
modifier|*
name|my_int_ptr
init|=
operator|&
name|g_my_int
decl_stmt|;
name|printf
argument_list|(
literal|"my_int_ptr points to location %p\n"
argument_list|,
name|my_int_ptr
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|str_ptr
init|=
name|days_of_week
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|7
condition|;
operator|++
name|i
control|)
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|str_ptr
index|[
name|i
index|]
argument_list|)
expr_stmt|;
comment|// Break at this line
comment|// and do str_ptr_val.GetChildAtIndex(5, lldb.eNoDynamicValues, True).
return|return
literal|0
return|;
block|}
end_function

end_unit

