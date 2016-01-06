begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- b.c -----------------------------------------------------*- C++ -*-===//
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
specifier|static
name|int
name|__b_global
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|b
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
name|__b_global
decl_stmt|;
return|return
name|result
return|;
block|}
end_function

begin_function
name|int
name|bb
parameter_list|(
name|int
name|arg1
parameter_list|)
block|{
name|int
name|result2
init|=
name|arg1
operator|-
name|__b_global
decl_stmt|;
return|return
name|result2
return|;
block|}
end_function

end_unit

