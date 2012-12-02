begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O3 -triple=x86_64-apple-darwin -target-feature +rtm -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Don't include mm_malloc.h, it's system specific.
end_comment

begin_define
define|#
directive|define
name|__MM_MALLOC_H
end_define

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|unsigned
name|int
name|test_xbegin
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: i32 @llvm.x86.xbegin()
return|return
name|_xbegin
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|test_xend
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: void @llvm.x86.xend()
name|_xend
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_xabort
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: void @llvm.x86.xabort(i8 2)
name|_xabort
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

