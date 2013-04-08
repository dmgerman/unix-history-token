begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-feature +prfchw -emit-llvm -o - %s | FileCheck %s
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
name|void
name|prefetch_w
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
name|_m_prefetchw
argument_list|(
name|p
argument_list|)
return|;
comment|// CHECK: @prefetch_w
comment|// CHECK: call void @llvm.prefetch({{.*}}, i32 1, i32 3, i32 1)
block|}
end_function

end_unit

