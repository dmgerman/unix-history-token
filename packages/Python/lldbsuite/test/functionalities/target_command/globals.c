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

begin_decl_stmt
name|char
name|my_global_char
init|=
literal|'X'
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|my_global_str
init|=
literal|"abc"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
modifier|*
name|my_global_str_ptr
init|=
operator|&
name|my_global_str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|my_static_int
init|=
literal|228
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
specifier|const
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|printf
argument_list|(
literal|"global char: %c\n"
argument_list|,
name|my_global_char
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"global str: %s\n"
argument_list|,
name|my_global_str
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"argc + my_static_int = %d\n"
argument_list|,
operator|(
name|argc
operator|+
name|my_static_int
operator|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

