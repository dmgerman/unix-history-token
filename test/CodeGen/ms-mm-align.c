begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 -target-feature +sse \
end_comment

begin_comment
comment|// RUN:         -triple i686--windows -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s
end_comment

begin_comment
comment|// intrin.h needs size_t, but -ffreestanding prevents us from getting it from
end_comment

begin_comment
comment|// stddef.h.  Work around it with this typedef.
end_comment

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<intrin.h>
end_include

begin_function_decl
name|void
name|capture_ptr
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_mm_align16
parameter_list|(
name|int
name|p
parameter_list|)
block|{
name|_MM_ALIGN16
name|int
name|i
decl_stmt|;
name|capture_ptr
argument_list|(
operator|&
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: alloca i32, align 16
end_comment

end_unit

