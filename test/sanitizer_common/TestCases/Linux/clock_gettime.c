begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -Wl,-as-needed -o %t&& %run %t
end_comment

begin_comment
comment|// Regression test for PR15823
end_comment

begin_comment
comment|// (http://llvm.org/bugs/show_bug.cgi?id=15823).
end_comment

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

begin_function
name|int
name|main
parameter_list|()
block|{
name|struct
name|timespec
name|ts
decl_stmt|;
name|clock_gettime
argument_list|(
name|CLOCK_REALTIME
argument_list|,
operator|&
name|ts
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

