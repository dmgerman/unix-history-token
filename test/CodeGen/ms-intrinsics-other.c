begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions \
end_comment

begin_comment
comment|// RUN:         -triple x86_64--darwin -Oz -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions \
end_comment

begin_comment
comment|// RUN:         -triple x86_64--linux -Oz -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s
end_comment

begin_comment
comment|// LP64 targets use 'long' as 'int' for MS intrinsics (-fms-extensions)
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_define
define|#
directive|define
name|LONG
value|int
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LONG
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|unsigned
name|char
name|test_BitScanForward
parameter_list|(
name|unsigned
name|LONG
modifier|*
name|Index
parameter_list|,
name|unsigned
name|LONG
name|Mask
parameter_list|)
block|{
return|return
name|_BitScanForward
argument_list|(
name|Index
argument_list|,
name|Mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i8 @test_BitScanForward(i32* {{[a-z_ ]*}}%Index, i32 {{[a-z_ ]*}}%Mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[ISNOTZERO:%[a-z0-9._]+]] = icmp eq i32 %Mask, 0
end_comment

begin_comment
comment|// CHECK:   br i1 [[ISNOTZERO]], label %[[END_LABEL:[a-z0-9._]+]], label %[[ISNOTZERO_LABEL:[a-z0-9._]+]]
end_comment

begin_comment
comment|// CHECK:   [[END_LABEL]]:
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[a-z0-9._]+]] = phi i8 [ 0, %[[ISZERO_LABEL:[a-z0-9._]+]] ], [ 1, %[[ISNOTZERO_LABEL]] ]
end_comment

begin_comment
comment|// CHECK:   ret i8 [[RESULT]]
end_comment

begin_comment
comment|// CHECK:   [[ISNOTZERO_LABEL]]:
end_comment

begin_comment
comment|// CHECK:   [[INDEX:%[0-9]+]] = tail call i32 @llvm.cttz.i32(i32 %Mask, i1 true)
end_comment

begin_comment
comment|// CHECK:   store i32 [[INDEX]], i32* %Index, align 4
end_comment

begin_comment
comment|// CHECK:   br label %[[END_LABEL]]
end_comment

begin_function
name|unsigned
name|char
name|test_BitScanReverse
parameter_list|(
name|unsigned
name|LONG
modifier|*
name|Index
parameter_list|,
name|unsigned
name|LONG
name|Mask
parameter_list|)
block|{
return|return
name|_BitScanReverse
argument_list|(
name|Index
argument_list|,
name|Mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i8 @test_BitScanReverse(i32* {{[a-z_ ]*}}%Index, i32 {{[a-z_ ]*}}%Mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[ISNOTZERO:%[0-9]+]] = icmp eq i32 %Mask, 0
end_comment

begin_comment
comment|// CHECK:   br i1 [[ISNOTZERO]], label %[[END_LABEL:[a-z0-9._]+]], label %[[ISNOTZERO_LABEL:[a-z0-9._]+]]
end_comment

begin_comment
comment|// CHECK:   [[END_LABEL]]:
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[a-z0-9._]+]] = phi i8 [ 0, %[[ISZERO_LABEL:[a-z0-9._]+]] ], [ 1, %[[ISNOTZERO_LABEL]] ]
end_comment

begin_comment
comment|// CHECK:   ret i8 [[RESULT]]
end_comment

begin_comment
comment|// CHECK:   [[ISNOTZERO_LABEL]]:
end_comment

begin_comment
comment|// CHECK:   [[REVINDEX:%[0-9]+]] = tail call i32 @llvm.ctlz.i32(i32 %Mask, i1 true)
end_comment

begin_comment
comment|// CHECK:   [[INDEX:%[0-9]+]] = xor i32 [[REVINDEX]], 31
end_comment

begin_comment
comment|// CHECK:   store i32 [[INDEX]], i32* %Index, align 4
end_comment

begin_comment
comment|// CHECK:   br label %[[END_LABEL]]
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
name|unsigned
name|char
name|test_BitScanForward64
parameter_list|(
name|unsigned
name|LONG
modifier|*
name|Index
parameter_list|,
name|unsigned
name|__int64
name|Mask
parameter_list|)
block|{
return|return
name|_BitScanForward64
argument_list|(
name|Index
argument_list|,
name|Mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i8 @test_BitScanForward64(i32* {{[a-z_ ]*}}%Index, i64 {{[a-z_ ]*}}%Mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[ISNOTZERO:%[a-z0-9._]+]] = icmp eq i64 %Mask, 0
end_comment

begin_comment
comment|// CHECK:   br i1 [[ISNOTZERO]], label %[[END_LABEL:[a-z0-9._]+]], label %[[ISNOTZERO_LABEL:[a-z0-9._]+]]
end_comment

begin_comment
comment|// CHECK:   [[END_LABEL]]:
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[a-z0-9._]+]] = phi i8 [ 0, %[[ISZERO_LABEL:[a-z0-9._]+]] ], [ 1, %[[ISNOTZERO_LABEL]] ]
end_comment

begin_comment
comment|// CHECK:   ret i8 [[RESULT]]
end_comment

begin_comment
comment|// CHECK:   [[ISNOTZERO_LABEL]]:
end_comment

begin_comment
comment|// CHECK:   [[INDEX:%[0-9]+]] = tail call i64 @llvm.cttz.i64(i64 %Mask, i1 true)
end_comment

begin_comment
comment|// CHECK:   [[TRUNC_INDEX:%[0-9]+]] = trunc i64 [[INDEX]] to i32
end_comment

begin_comment
comment|// CHECK:   store i32 [[TRUNC_INDEX]], i32* %Index, align 4
end_comment

begin_comment
comment|// CHECK:   br label %[[END_LABEL]]
end_comment

begin_function
name|unsigned
name|char
name|test_BitScanReverse64
parameter_list|(
name|unsigned
name|LONG
modifier|*
name|Index
parameter_list|,
name|unsigned
name|__int64
name|Mask
parameter_list|)
block|{
return|return
name|_BitScanReverse64
argument_list|(
name|Index
argument_list|,
name|Mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i8 @test_BitScanReverse64(i32* {{[a-z_ ]*}}%Index, i64 {{[a-z_ ]*}}%Mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[ISNOTZERO:%[0-9]+]] = icmp eq i64 %Mask, 0
end_comment

begin_comment
comment|// CHECK:   br i1 [[ISNOTZERO]], label %[[END_LABEL:[a-z0-9._]+]], label %[[ISNOTZERO_LABEL:[a-z0-9._]+]]
end_comment

begin_comment
comment|// CHECK:   [[END_LABEL]]:
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[a-z0-9._]+]] = phi i8 [ 0, %[[ISZERO_LABEL:[a-z0-9._]+]] ], [ 1, %[[ISNOTZERO_LABEL]] ]
end_comment

begin_comment
comment|// CHECK:   ret i8 [[RESULT]]
end_comment

begin_comment
comment|// CHECK:   [[ISNOTZERO_LABEL]]:
end_comment

begin_comment
comment|// CHECK:   [[REVINDEX:%[0-9]+]] = tail call i64 @llvm.ctlz.i64(i64 %Mask, i1 true)
end_comment

begin_comment
comment|// CHECK:   [[TRUNC_REVINDEX:%[0-9]+]] = trunc i64 [[REVINDEX]] to i32
end_comment

begin_comment
comment|// CHECK:   [[INDEX:%[0-9]+]] = xor i32 [[TRUNC_REVINDEX]], 63
end_comment

begin_comment
comment|// CHECK:   store i32 [[INDEX]], i32* %Index, align 4
end_comment

begin_comment
comment|// CHECK:   br label %[[END_LABEL]]
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|LONG
name|test_InterlockedExchange
parameter_list|(
name|LONG
specifier|volatile
modifier|*
name|value
parameter_list|,
name|LONG
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedExchange
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i32 @test_InterlockedExchange(i32*{{[a-z_ ]*}}%value, i32{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw xchg i32* %value, i32 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i32 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|LONG
name|test_InterlockedExchangeAdd
parameter_list|(
name|LONG
specifier|volatile
modifier|*
name|value
parameter_list|,
name|LONG
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedExchangeAdd
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i32 @test_InterlockedExchangeAdd(i32*{{[a-z_ ]*}}%value, i32{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw add i32* %value, i32 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i32 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|LONG
name|test_InterlockedExchangeSub
parameter_list|(
name|LONG
specifier|volatile
modifier|*
name|value
parameter_list|,
name|LONG
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedExchangeSub
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i32 @test_InterlockedExchangeSub(i32*{{[a-z_ ]*}}%value, i32{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw sub i32* %value, i32 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i32 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|LONG
name|test_InterlockedOr
parameter_list|(
name|LONG
specifier|volatile
modifier|*
name|value
parameter_list|,
name|LONG
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedOr
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i32 @test_InterlockedOr(i32*{{[a-z_ ]*}}%value, i32{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw or i32* %value, i32 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i32 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|LONG
name|test_InterlockedXor
parameter_list|(
name|LONG
specifier|volatile
modifier|*
name|value
parameter_list|,
name|LONG
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedXor
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i32 @test_InterlockedXor(i32*{{[a-z_ ]*}}%value, i32{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw xor i32* %value, i32 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i32 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|LONG
name|test_InterlockedAnd
parameter_list|(
name|LONG
specifier|volatile
modifier|*
name|value
parameter_list|,
name|LONG
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedAnd
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i32 @test_InterlockedAnd(i32*{{[a-z_ ]*}}%value, i32{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw and i32* %value, i32 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i32 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|LONG
name|test_InterlockedCompareExchange
parameter_list|(
name|LONG
specifier|volatile
modifier|*
name|Destination
parameter_list|,
name|LONG
name|Exchange
parameter_list|,
name|LONG
name|Comperand
parameter_list|)
block|{
return|return
name|_InterlockedCompareExchange
argument_list|(
name|Destination
argument_list|,
name|Exchange
argument_list|,
name|Comperand
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i32 @test_InterlockedCompareExchange(i32*{{[a-z_ ]*}}%Destination, i32{{[a-z_ ]*}}%Exchange, i32{{[a-z_ ]*}}%Comperand){{.*}}{
end_comment

begin_comment
comment|// CHECK: [[TMP:%[0-9]+]] = cmpxchg volatile i32* %Destination, i32 %Comperand, i32 %Exchange seq_cst seq_cst
end_comment

begin_comment
comment|// CHECK: [[RESULT:%[0-9]+]] = extractvalue { i32, i1 } [[TMP]], 0
end_comment

begin_comment
comment|// CHECK: ret i32 [[RESULT]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|LONG
name|test_InterlockedIncrement
parameter_list|(
name|LONG
specifier|volatile
modifier|*
name|Addend
parameter_list|)
block|{
return|return
name|_InterlockedIncrement
argument_list|(
name|Addend
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i32 @test_InterlockedIncrement(i32*{{[a-z_ ]*}}%Addend){{.*}}{
end_comment

begin_comment
comment|// CHECK: [[TMP:%[0-9]+]] = atomicrmw add i32* %Addend, i32 1 seq_cst
end_comment

begin_comment
comment|// CHECK: [[RESULT:%[0-9]+]] = add i32 [[TMP]], 1
end_comment

begin_comment
comment|// CHECK: ret i32 [[RESULT]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|LONG
name|test_InterlockedDecrement
parameter_list|(
name|LONG
specifier|volatile
modifier|*
name|Addend
parameter_list|)
block|{
return|return
name|_InterlockedDecrement
argument_list|(
name|Addend
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i32 @test_InterlockedDecrement(i32*{{[a-z_ ]*}}%Addend){{.*}}{
end_comment

begin_comment
comment|// CHECK: [[TMP:%[0-9]+]] = atomicrmw sub i32* %Addend, i32 1 seq_cst
end_comment

begin_comment
comment|// CHECK: [[RESULT:%[0-9]+]] = add i32 [[TMP]], -1
end_comment

begin_comment
comment|// CHECK: ret i32 [[RESULT]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|unsigned
name|char
name|test_interlockedbittestandset
parameter_list|(
specifier|volatile
name|LONG
modifier|*
name|ptr
parameter_list|,
name|LONG
name|bit
parameter_list|)
block|{
return|return
name|_interlockedbittestandset
argument_list|(
name|ptr
argument_list|,
name|bit
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define{{.*}} i8 @test_interlockedbittestandset
end_comment

begin_comment
comment|// CHECK: [[MASKBIT:%[0-9]+]] = shl i32 1, %bit
end_comment

begin_comment
comment|// CHECK: [[OLD:%[0-9]+]] = atomicrmw or i32* %ptr, i32 [[MASKBIT]] seq_cst
end_comment

begin_comment
comment|// CHECK: [[SHIFT:%[0-9]+]] = lshr i32 [[OLD]], %bit
end_comment

begin_comment
comment|// CHECK: [[TRUNC:%[0-9]+]] = trunc i32 [[SHIFT]] to i8
end_comment

begin_comment
comment|// CHECK: [[AND:%[0-9]+]] = and i8 [[TRUNC]], 1
end_comment

begin_comment
comment|// CHECK: ret i8 [[AND]]
end_comment

end_unit

