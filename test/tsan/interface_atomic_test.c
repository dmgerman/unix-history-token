begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that we can include header with TSan atomic interface.
end_comment

begin_comment
comment|// RUN: %clang_tsan %s -o %t&& %run %t | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<sanitizer/tsan_interface_atomic.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|__tsan_atomic32
name|a
decl_stmt|;
name|__tsan_atomic32_store
argument_list|(
operator|&
name|a
argument_list|,
literal|100
argument_list|,
name|__tsan_memory_order_release
argument_list|)
expr_stmt|;
name|int
name|res
init|=
name|__tsan_atomic32_load
argument_list|(
operator|&
name|a
argument_list|,
name|__tsan_memory_order_acquire
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|==
literal|100
condition|)
block|{
comment|// CHECK: PASS
name|printf
argument_list|(
literal|"PASS\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
literal|1
return|;
block|}
end_function

end_unit

