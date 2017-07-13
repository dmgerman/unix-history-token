begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple i686--windows -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s -check-prefix=CHECK -check-prefix=CHECK-I386
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple x86_64--windows -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-X64
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

begin_function
name|void
name|test_ReadWriteBarrier
parameter_list|()
block|{
name|_ReadWriteBarrier
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_ReadWriteBarrier
end_comment

begin_comment
comment|// CHECK:   fence syncscope("singlethread") seq_cst
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|void
name|test_ReadBarrier
parameter_list|()
block|{
name|_ReadBarrier
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_ReadBarrier
end_comment

begin_comment
comment|// CHECK:   fence syncscope("singlethread") seq_cst
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|void
name|test_WriteBarrier
parameter_list|()
block|{
name|_WriteBarrier
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_WriteBarrier
end_comment

begin_comment
comment|// CHECK:   fence syncscope("singlethread") seq_cst
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_function
name|void
name|test__faststorefence
parameter_list|()
block|{
name|__faststorefence
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-X64-LABEL: define void @test__faststorefence
end_comment

begin_comment
comment|// CHECK-X64:   fence seq_cst
end_comment

begin_comment
comment|// CHECK-X64:   ret void
end_comment

begin_comment
comment|// CHECK-X64: }
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

