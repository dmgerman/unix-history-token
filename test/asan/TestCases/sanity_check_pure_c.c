begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Sanity checking a test in pure C.
end_comment

begin_comment
comment|// RUN: %clang_asan -O2 %s -o %t
end_comment

begin_comment
comment|// RUN: not %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// Sanity checking a test in pure C with -pie.
end_comment

begin_comment
comment|// RUN: %clang_asan -O2 %s -pie -fPIE -o %t
end_comment

begin_comment
comment|// RUN: not %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// XFAIL: arm-linux-gnueabi
end_comment

begin_comment
comment|// XFAIL: armv7l-unknown-linux-gnueabihf
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|char
modifier|*
name|x
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|10
operator|*
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
name|x
index|[
literal|5
index|]
return|;
comment|// CHECK: heap-use-after-free
comment|// CHECK: free
comment|// CHECK: main{{.*}}sanity_check_pure_c.c:[[@LINE-4]]
comment|// CHECK: malloc
comment|// CHECK: main{{.*}}sanity_check_pure_c.c:[[@LINE-7]]
block|}
end_function

end_unit

