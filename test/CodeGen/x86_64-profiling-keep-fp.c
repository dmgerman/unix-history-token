begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -O3 -pg -S -o - %s | \
end_comment

begin_comment
comment|// RUN:   FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -O3 -momit-leaf-frame-pointer -pg -S -o - %s | \
end_comment

begin_comment
comment|// RUN:   FileCheck %s
end_comment

begin_comment
comment|// Test that the frame pointer is kept when compiling with
end_comment

begin_comment
comment|// profiling.
end_comment

begin_comment
comment|//CHECK: pushq %rbp
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

