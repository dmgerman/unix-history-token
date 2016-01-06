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
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_decl_stmt
name|jmp_buf
name|j
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|do_jump
parameter_list|(
name|void
parameter_list|)
block|{
comment|// We can't let the compiler know this will always happen or it might make
comment|// optimizations that break our test.
if|if
condition|(
operator|!
name|clock
argument_list|()
condition|)
name|longjmp
argument_list|(
name|j
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// non-local goto
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|setjmp
argument_list|(
name|j
argument_list|)
operator|==
literal|0
condition|)
name|do_jump
argument_list|()
expr_stmt|;
else|else
return|return
literal|0
return|;
comment|// destination of longjmp
return|return
literal|1
return|;
block|}
end_function

end_unit

