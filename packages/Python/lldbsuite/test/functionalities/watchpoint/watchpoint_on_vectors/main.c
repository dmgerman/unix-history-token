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

begin_typedef
typedef|typedef
name|signed
name|char
name|v4i8
name|__attribute__
typedef|((
name|vector_size
typedef|(4)));
end_typedef

begin_decl_stmt
name|v4i8
name|global_vector
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

