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
name|string_not_empty
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
if|if
condition|(
name|s
operator|&&
name|s
index|[
literal|0
index|]
condition|)
return|return
literal|1
return|;
return|return
literal|0
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
name|int
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
init|=
name|string_not_empty
function_decl|;
return|return
name|callback
argument_list|(
literal|0
argument_list|)
return|;
comment|// Set break point at this line.
block|}
end_function

end_unit

