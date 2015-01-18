begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple i686--windows -Oz -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s -check-prefix CHECK -check-prefix CHECK-I386
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple thumbv7--windows -Oz -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple x86_64--windows -Oz -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-X64
end_comment

begin_comment
comment|// Intrin.h needs size_t, but -ffreestanding prevents us from getting it from
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
file|<Intrin.h>
end_include

begin_function
name|void
modifier|*
name|test_InterlockedExchangePointer
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|Target
parameter_list|,
name|void
modifier|*
name|Value
parameter_list|)
block|{
return|return
name|_InterlockedExchangePointer
argument_list|(
name|Target
argument_list|,
name|Value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i8* @test_InterlockedExchangePointer(i8** %Target, i8* %Value){{.*}}{
end_comment

begin_comment
comment|// CHECK:   %[[TARGET:[0-9]+]] = bitcast i8** %Target to [[iPTR:i[0-9]+]]*
end_comment

begin_comment
comment|// CHECK:   %[[VALUE:[0-9]+]] = ptrtoint i8* %Value to [[iPTR]]
end_comment

begin_comment
comment|// CHECK:   %[[EXCHANGE:[0-9]+]] = atomicrmw xchg [[iPTR]]* %[[TARGET]], [[iPTR]] %[[VALUE]] seq_cst
end_comment

begin_comment
comment|// CHECK:   %[[RESULT:[0-9]+]] = inttoptr [[iPTR]] %[[EXCHANGE]] to i8*
end_comment

begin_comment
comment|// CHECK:   ret i8* %[[RESULT]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|void
modifier|*
name|test_InterlockedCompareExchangePointer
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|Destination
parameter_list|,
name|void
modifier|*
name|Exchange
parameter_list|,
name|void
modifier|*
name|Comparand
parameter_list|)
block|{
return|return
name|_InterlockedCompareExchangePointer
argument_list|(
name|Destination
argument_list|,
name|Exchange
argument_list|,
name|Comparand
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i8* @test_InterlockedCompareExchangePointer(i8** %Destination, i8* %Exchange, i8* %Comparand){{.*}}{
end_comment

begin_comment
comment|// CHECK:   %[[DEST:[0-9]+]] = bitcast i8** %Destination to [[iPTR]]*
end_comment

begin_comment
comment|// CHECK:   %[[EXCHANGE:[0-9]+]] = ptrtoint i8* %Exchange to [[iPTR]]
end_comment

begin_comment
comment|// CHECK:   %[[COMPARAND:[0-9]+]] = ptrtoint i8* %Comparand to [[iPTR]]
end_comment

begin_comment
comment|// CHECK:   %[[XCHG:[0-9]+]] = cmpxchg volatile [[iPTR]]* %[[DEST:[0-9]+]], [[iPTR]] %[[COMPARAND:[0-9]+]], [[iPTR]] %[[EXCHANGE:[0-9]+]] seq_cst seq_cst
end_comment

begin_comment
comment|// CHECK:   %[[EXTRACT:[0-9]+]] = extractvalue { [[iPTR]], i1 } %[[XCHG]], 0
end_comment

begin_comment
comment|// CHECK:   %[[RESULT:[0-9]+]] = inttoptr [[iPTR]] %[[EXTRACT]] to i8*
end_comment

begin_comment
comment|// CHECK:   ret i8* %[[RESULT:[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|long
name|test_InterlockedExchange
parameter_list|(
name|long
modifier|*
name|Target
parameter_list|,
name|long
name|Value
parameter_list|)
block|{
return|return
name|_InterlockedExchange
argument_list|(
name|Target
argument_list|,
name|Value
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i32 @test_InterlockedExchange(i32* %Target, i32 %Value){{.*}}{
end_comment

begin_comment
comment|// CHECK:   %[[EXCHANGE:[0-9]+]] = atomicrmw xchg i32* %Target, i32 %Value seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i32 %[[EXCHANGE:[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_function
name|long
name|test__readfsdword
parameter_list|(
name|unsigned
name|long
name|Offset
parameter_list|)
block|{
return|return
name|__readfsdword
argument_list|(
name|Offset
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-I386: define i32 @test__readfsdword(i32 %Offset){{.*}}{
end_comment

begin_comment
comment|// CHECK-I386:   [[PTR:%[0-9]+]] = inttoptr i32 %Offset to i32 addrspace(257)*
end_comment

begin_comment
comment|// CHECK-I386:   [[VALUE:%[0-9]+]] = load volatile i32 addrspace(257)* [[PTR]], align 4
end_comment

begin_comment
comment|// CHECK-I386:   ret i32 [[VALUE:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK-I386: }
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_function
name|unsigned
name|__int64
name|test__umulh
parameter_list|(
name|unsigned
name|__int64
name|a
parameter_list|,
name|unsigned
name|__int64
name|b
parameter_list|)
block|{
return|return
name|__umulh
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-X64-LABEL: define i64 @test__umulh(i64 %a, i64 %b)
end_comment

begin_comment
comment|// CHECK-X64: = mul nuw i128 %
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

