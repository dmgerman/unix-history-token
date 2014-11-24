begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686--windows -fms-compatibility -Oz -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7--windows -fms-compatibility -Oz -emit-llvm %s -o - | FileCheck %s
end_comment

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
comment|// CHECK:   %[[TARGET:[0-9]+]] = bitcast i8** %Target to i32*
end_comment

begin_comment
comment|// CHECK:   %[[VALUE:[0-9]+]] = ptrtoint i8* %Value to i32
end_comment

begin_comment
comment|// CHECK:   %[[EXCHANGE:[0-9]+]] = atomicrmw xchg i32* %[[TARGET]], i32 %[[VALUE]] seq_cst
end_comment

begin_comment
comment|// CHECK:   %[[RESULT:[0-9]+]] = inttoptr i32 %[[EXCHANGE]] to i8*
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
comment|// CHECK:   %[[DEST:[0-9]+]] = bitcast i8** %Destination to i32*
end_comment

begin_comment
comment|// CHECK:   %[[EXCHANGE:[0-9]+]] = ptrtoint i8* %Exchange to i32
end_comment

begin_comment
comment|// CHECK:   %[[COMPARAND:[0-9]+]] = ptrtoint i8* %Comparand to i32
end_comment

begin_comment
comment|// CHECK:   %[[XCHG:[0-9]+]] = cmpxchg volatile i32* %[[DEST:[0-9]+]], i32 %[[COMPARAND:[0-9]+]], i32 %[[EXCHANGE:[0-9]+]] seq_cst seq_cst
end_comment

begin_comment
comment|// CHECK:   %[[EXTRACT:[0-9]+]] = extractvalue { i32, i1 } %[[XCHG]], 0
end_comment

begin_comment
comment|// CHECK:   %[[RESULT:[0-9]+]] = inttoptr i32 %[[EXTRACT]] to i8*
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

end_unit

