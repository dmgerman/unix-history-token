begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O3 -triple=x86_64-apple-darwin -target-feature +fsgsbase -emit-llvm -o - | FileCheck %s
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
file|<x86intrin.h>
end_include

begin_function
name|unsigned
name|int
name|test_readfsbase_u32
parameter_list|()
block|{
comment|// CHECK: @llvm.x86.rdfsbase.32
return|return
name|_readfsbase_u32
argument_list|()
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_readfsbase_u64
parameter_list|()
block|{
comment|// CHECK: @llvm.x86.rdfsbase.64
return|return
name|_readfsbase_u64
argument_list|()
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_readgsbase_u32
parameter_list|()
block|{
comment|// CHECK: @llvm.x86.rdgsbase.32
return|return
name|_readgsbase_u32
argument_list|()
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_readgsbase_u64
parameter_list|()
block|{
comment|// CHECK: @llvm.x86.rdgsbase.64
return|return
name|_readgsbase_u64
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|test_writefsbase_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.wrfsbase.32
name|_writefsbase_u32
argument_list|(
name|__X
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_writefsbase_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.wrfsbase.64
name|_writefsbase_u64
argument_list|(
name|__X
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_writegsbase_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.wrgsbase.32
name|_writegsbase_u32
argument_list|(
name|__X
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_writegsbase_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.wrgsbase.64
name|_writegsbase_u64
argument_list|(
name|__X
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

