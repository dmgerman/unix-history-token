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

begin_function_decl
name|int
name|f1
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|f2
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|f3
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// We want f1 to start on line 20
end_comment

begin_function
name|int
name|f1
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
block|{
return|return
name|printf
argument_list|(
literal|"f1: %s\n"
argument_list|,
name|s
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// We want f2 to start on line 30
end_comment

begin_function
name|int
name|f2
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
block|{
return|return
name|printf
argument_list|(
literal|"f2: %s\n"
argument_list|,
name|s
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// We want f3 to start on line 40
end_comment

begin_function
name|int
name|f3
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
block|{
return|return
name|printf
argument_list|(
literal|"f3: %s\n"
argument_list|,
name|s
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// We want main to start on line 50
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|f1
argument_list|(
literal|"carp"
argument_list|)
expr_stmt|;
name|f2
argument_list|(
literal|"ding"
argument_list|)
expr_stmt|;
name|f3
argument_list|(
literal|"dong"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

