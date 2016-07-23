begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86_64-linux
end_comment

begin_comment
comment|// RUN: %host_cc -O0 -g %s -o %t 2>&1
end_comment

begin_comment
comment|// RUN: %t 2>&1 | llvm-symbolizer -print-source-context-lines=5 -obj=%t | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|inc
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
operator|+
literal|1
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%p\n"
argument_list|,
name|inc
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: inc
end_comment

begin_comment
comment|// CHECK: print_context.c:7
end_comment

begin_comment
comment|// CHECK: 5  : #include
end_comment

begin_comment
comment|// CHECK: 6  :
end_comment

begin_comment
comment|// CHECK: 7>: int inc
end_comment

begin_comment
comment|// CHECK: 8  :   return
end_comment

begin_comment
comment|// CHECK: 9  : }
end_comment

end_unit

