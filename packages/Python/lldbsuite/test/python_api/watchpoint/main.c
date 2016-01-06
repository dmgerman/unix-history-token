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
name|int32_t
name|global
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Watchpoint variable declaration.
end_comment

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
name|local
init|=
literal|0
decl_stmt|;
name|printf
argument_list|(
literal|"&global=%p\n"
argument_list|,
operator|&
name|global
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"about to write to 'global'...\n"
argument_list|)
expr_stmt|;
comment|// Set break point at this line.
comment|// When stopped, watch 'global' for read&write.
name|global
operator|=
literal|20
expr_stmt|;
name|local
operator|+=
name|argc
expr_stmt|;
operator|++
name|local
expr_stmt|;
name|printf
argument_list|(
literal|"local: %d\n"
argument_list|,
name|local
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"global=%d\n"
argument_list|,
name|global
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

