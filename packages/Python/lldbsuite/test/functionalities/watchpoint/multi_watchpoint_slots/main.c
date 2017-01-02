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

begin_decl_stmt
name|uint64_t
name|pad0
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint8_t
name|byteArray
index|[
literal|4
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint64_t
name|pad1
init|=
literal|0
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
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
name|i
operator|++
control|)
block|{
name|printf
argument_list|(
literal|"About to write byteArray[%d] ...\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// About to write byteArray
name|pad0
operator|++
expr_stmt|;
name|byteArray
index|[
name|i
index|]
operator|=
literal|7
expr_stmt|;
name|pad1
operator|++
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

