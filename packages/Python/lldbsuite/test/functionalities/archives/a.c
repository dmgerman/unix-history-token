begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- a.c -----------------------------------------------------*- C++ -*-===//
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

begin_decl_stmt
name|int
name|__a_global
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|a
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
name|int
name|result
init|=
name|arg
operator|+
name|__a_global
decl_stmt|;
return|return
name|result
return|;
comment|// Set file and line breakpoint inside a().
block|}
end_function

begin_function
name|int
name|aa
parameter_list|(
name|int
name|arg1
parameter_list|)
block|{
name|int
name|result1
init|=
name|arg1
operator|-
name|__a_global
decl_stmt|;
return|return
name|result1
return|;
block|}
end_function

end_unit

