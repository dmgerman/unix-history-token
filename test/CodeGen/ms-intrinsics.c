begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple i686--windows -Oz -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s -check-prefixes CHECK,CHECK-I386,CHECK-INTEL
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple thumbv7--windows -Oz -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefixes CHECK,CHECK-ARM,CHECK-ARM-X64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple x86_64--windows -Oz -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefixes CHECK,CHECK-X64,CHECK-ARM-X64,CHECK-INTEL
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_function
name|void
name|test__stosb
parameter_list|(
name|unsigned
name|char
modifier|*
name|Dest
parameter_list|,
name|unsigned
name|char
name|Data
parameter_list|,
name|size_t
name|Count
parameter_list|)
block|{
return|return
name|__stosb
argument_list|(
name|Dest
argument_list|,
name|Data
argument_list|,
name|Count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-I386: define{{.*}}void @test__stosb
end_comment

begin_comment
comment|// CHECK-I386:   tail call void @llvm.memset.p0i8.i32(i8* %Dest, i8 %Data, i32 %Count, i32 1, i1 true)
end_comment

begin_comment
comment|// CHECK-I386:   ret void
end_comment

begin_comment
comment|// CHECK-I386: }
end_comment

begin_comment
comment|// CHECK-X64: define{{.*}}void @test__stosb
end_comment

begin_comment
comment|// CHECK-X64:   tail call void @llvm.memset.p0i8.i64(i8* %Dest, i8 %Data, i64 %Count, i32 1, i1 true)
end_comment

begin_comment
comment|// CHECK-X64:   ret void
end_comment

begin_comment
comment|// CHECK-X64: }
end_comment

begin_function
name|void
name|test__ud2
parameter_list|(
name|void
parameter_list|)
block|{
name|__ud2
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-INTEL-LABEL: define{{.*}} void @test__ud2()
end_comment

begin_comment
comment|// CHECK-INTEL: call void @llvm.trap()
end_comment

begin_function
name|void
name|test__int2c
parameter_list|(
name|void
parameter_list|)
block|{
name|__int2c
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-INTEL-LABEL: define{{.*}} void @test__int2c()
end_comment

begin_comment
comment|// CHECK-INTEL: call void asm sideeffect "int $$0x2c", ""() #[[NORETURN:[0-9]+]]
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
modifier|*
name|test_ReturnAddress
parameter_list|()
block|{
return|return
name|_ReturnAddress
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define{{.*}}i8* @test_ReturnAddress()
end_comment

begin_comment
comment|// CHECK: = tail call i8* @llvm.returnaddress(i32 0)
end_comment

begin_comment
comment|// CHECK: ret i8*
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_function
name|void
modifier|*
name|test_AddressOfReturnAddress
parameter_list|()
block|{
return|return
name|_AddressOfReturnAddress
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// CHECK-INTEL-LABEL: define i8* @test_AddressOfReturnAddress()
end_comment

begin_comment
comment|// CHECK-INTEL: = tail call i8* @llvm.addressofreturnaddress()
end_comment

begin_comment
comment|// CHECK-INTEL: ret i8*
end_comment

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
name|long
modifier|*
name|Index
parameter_list|,
name|unsigned
name|long
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
name|long
modifier|*
name|Index
parameter_list|,
name|unsigned
name|long
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
operator|||
name|defined
argument_list|(
name|__arm__
argument_list|)
end_if

begin_function
name|unsigned
name|char
name|test_BitScanForward64
parameter_list|(
name|unsigned
name|long
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
comment|// CHECK-ARM-X64: define{{.*}}i8 @test_BitScanForward64(i32* {{[a-z_ ]*}}%Index, i64 {{[a-z_ ]*}}%Mask){{.*}}{
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[ISNOTZERO:%[a-z0-9._]+]] = icmp eq i64 %Mask, 0
end_comment

begin_comment
comment|// CHECK-ARM-X64:   br i1 [[ISNOTZERO]], label %[[END_LABEL:[a-z0-9._]+]], label %[[ISNOTZERO_LABEL:[a-z0-9._]+]]
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[END_LABEL]]:
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[RESULT:%[a-z0-9._]+]] = phi i8 [ 0, %[[ISZERO_LABEL:[a-z0-9._]+]] ], [ 1, %[[ISNOTZERO_LABEL]] ]
end_comment

begin_comment
comment|// CHECK-ARM-X64:   ret i8 [[RESULT]]
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[ISNOTZERO_LABEL]]:
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[INDEX:%[0-9]+]] = tail call i64 @llvm.cttz.i64(i64 %Mask, i1 true)
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[TRUNC_INDEX:%[0-9]+]] = trunc i64 [[INDEX]] to i32
end_comment

begin_comment
comment|// CHECK-ARM-X64:   store i32 [[TRUNC_INDEX]], i32* %Index, align 4
end_comment

begin_comment
comment|// CHECK-ARM-X64:   br label %[[END_LABEL]]
end_comment

begin_function
name|unsigned
name|char
name|test_BitScanReverse64
parameter_list|(
name|unsigned
name|long
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
comment|// CHECK-ARM-X64: define{{.*}}i8 @test_BitScanReverse64(i32* {{[a-z_ ]*}}%Index, i64 {{[a-z_ ]*}}%Mask){{.*}}{
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[ISNOTZERO:%[0-9]+]] = icmp eq i64 %Mask, 0
end_comment

begin_comment
comment|// CHECK-ARM-X64:   br i1 [[ISNOTZERO]], label %[[END_LABEL:[a-z0-9._]+]], label %[[ISNOTZERO_LABEL:[a-z0-9._]+]]
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[END_LABEL]]:
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[RESULT:%[a-z0-9._]+]] = phi i8 [ 0, %[[ISZERO_LABEL:[a-z0-9._]+]] ], [ 1, %[[ISNOTZERO_LABEL]] ]
end_comment

begin_comment
comment|// CHECK-ARM-X64:   ret i8 [[RESULT]]
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[ISNOTZERO_LABEL]]:
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[REVINDEX:%[0-9]+]] = tail call i64 @llvm.ctlz.i64(i64 %Mask, i1 true)
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[TRUNC_REVINDEX:%[0-9]+]] = trunc i64 [[REVINDEX]] to i32
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[INDEX:%[0-9]+]] = xor i32 [[TRUNC_REVINDEX]], 63
end_comment

begin_comment
comment|// CHECK-ARM-X64:   store i32 [[INDEX]], i32* %Index, align 4
end_comment

begin_comment
comment|// CHECK-ARM-X64:   br label %[[END_LABEL]]
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
comment|// CHECK: define{{.*}}i8* @test_InterlockedExchangePointer(i8** {{[a-z_ ]*}}%Target, i8* {{[a-z_ ]*}}%Value){{.*}}{
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
comment|// CHECK: define{{.*}}i8* @test_InterlockedCompareExchangePointer(i8** {{[a-z_ ]*}}%Destination, i8* {{[a-z_ ]*}}%Exchange, i8* {{[a-z_ ]*}}%Comparand){{.*}}{
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
name|char
name|test_InterlockedExchange8
parameter_list|(
name|char
specifier|volatile
modifier|*
name|value
parameter_list|,
name|char
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedExchange8
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i8 @test_InterlockedExchange8(i8*{{[a-z_ ]*}}%value, i8{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw xchg i8* %value, i8 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i8 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|short
name|test_InterlockedExchange16
parameter_list|(
name|short
specifier|volatile
modifier|*
name|value
parameter_list|,
name|short
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedExchange16
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i16 @test_InterlockedExchange16(i16*{{[a-z_ ]*}}%value, i16{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw xchg i16* %value, i16 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i16 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|long
name|test_InterlockedExchange
parameter_list|(
name|long
specifier|volatile
modifier|*
name|value
parameter_list|,
name|long
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
name|char
name|test_InterlockedExchangeAdd8
parameter_list|(
name|char
specifier|volatile
modifier|*
name|value
parameter_list|,
name|char
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedExchangeAdd8
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i8 @test_InterlockedExchangeAdd8(i8*{{[a-z_ ]*}}%value, i8{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw add i8* %value, i8 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i8 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|short
name|test_InterlockedExchangeAdd16
parameter_list|(
name|short
specifier|volatile
modifier|*
name|value
parameter_list|,
name|short
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedExchangeAdd16
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i16 @test_InterlockedExchangeAdd16(i16*{{[a-z_ ]*}}%value, i16{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw add i16* %value, i16 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i16 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|long
name|test_InterlockedExchangeAdd
parameter_list|(
name|long
specifier|volatile
modifier|*
name|value
parameter_list|,
name|long
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
name|char
name|test_InterlockedExchangeSub8
parameter_list|(
name|char
specifier|volatile
modifier|*
name|value
parameter_list|,
name|char
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedExchangeSub8
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i8 @test_InterlockedExchangeSub8(i8*{{[a-z_ ]*}}%value, i8{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw sub i8* %value, i8 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i8 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|short
name|test_InterlockedExchangeSub16
parameter_list|(
name|short
specifier|volatile
modifier|*
name|value
parameter_list|,
name|short
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedExchangeSub16
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i16 @test_InterlockedExchangeSub16(i16*{{[a-z_ ]*}}%value, i16{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw sub i16* %value, i16 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i16 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|long
name|test_InterlockedExchangeSub
parameter_list|(
name|long
specifier|volatile
modifier|*
name|value
parameter_list|,
name|long
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
name|char
name|test_InterlockedOr8
parameter_list|(
name|char
specifier|volatile
modifier|*
name|value
parameter_list|,
name|char
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedOr8
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i8 @test_InterlockedOr8(i8*{{[a-z_ ]*}}%value, i8{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw or i8* %value, i8 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i8 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|short
name|test_InterlockedOr16
parameter_list|(
name|short
specifier|volatile
modifier|*
name|value
parameter_list|,
name|short
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedOr16
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i16 @test_InterlockedOr16(i16*{{[a-z_ ]*}}%value, i16{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw or i16* %value, i16 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i16 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|long
name|test_InterlockedOr
parameter_list|(
name|long
specifier|volatile
modifier|*
name|value
parameter_list|,
name|long
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
name|char
name|test_InterlockedXor8
parameter_list|(
name|char
specifier|volatile
modifier|*
name|value
parameter_list|,
name|char
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedXor8
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i8 @test_InterlockedXor8(i8*{{[a-z_ ]*}}%value, i8{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw xor i8* %value, i8 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i8 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|short
name|test_InterlockedXor16
parameter_list|(
name|short
specifier|volatile
modifier|*
name|value
parameter_list|,
name|short
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedXor16
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i16 @test_InterlockedXor16(i16*{{[a-z_ ]*}}%value, i16{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw xor i16* %value, i16 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i16 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|long
name|test_InterlockedXor
parameter_list|(
name|long
specifier|volatile
modifier|*
name|value
parameter_list|,
name|long
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
name|char
name|test_InterlockedAnd8
parameter_list|(
name|char
specifier|volatile
modifier|*
name|value
parameter_list|,
name|char
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedAnd8
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i8 @test_InterlockedAnd8(i8*{{[a-z_ ]*}}%value, i8{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw and i8* %value, i8 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i8 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|short
name|test_InterlockedAnd16
parameter_list|(
name|short
specifier|volatile
modifier|*
name|value
parameter_list|,
name|short
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedAnd16
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i16 @test_InterlockedAnd16(i16*{{[a-z_ ]*}}%value, i16{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RESULT:%[0-9]+]] = atomicrmw and i16* %value, i16 %mask seq_cst
end_comment

begin_comment
comment|// CHECK:   ret i16 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|long
name|test_InterlockedAnd
parameter_list|(
name|long
specifier|volatile
modifier|*
name|value
parameter_list|,
name|long
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
name|char
name|test_InterlockedCompareExchange8
parameter_list|(
name|char
specifier|volatile
modifier|*
name|Destination
parameter_list|,
name|char
name|Exchange
parameter_list|,
name|char
name|Comperand
parameter_list|)
block|{
return|return
name|_InterlockedCompareExchange8
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
comment|// CHECK: define{{.*}}i8 @test_InterlockedCompareExchange8(i8*{{[a-z_ ]*}}%Destination, i8{{[a-z_ ]*}}%Exchange, i8{{[a-z_ ]*}}%Comperand){{.*}}{
end_comment

begin_comment
comment|// CHECK: [[TMP:%[0-9]+]] = cmpxchg volatile i8* %Destination, i8 %Comperand, i8 %Exchange seq_cst seq_cst
end_comment

begin_comment
comment|// CHECK: [[RESULT:%[0-9]+]] = extractvalue { i8, i1 } [[TMP]], 0
end_comment

begin_comment
comment|// CHECK: ret i8 [[RESULT]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|short
name|test_InterlockedCompareExchange16
parameter_list|(
name|short
specifier|volatile
modifier|*
name|Destination
parameter_list|,
name|short
name|Exchange
parameter_list|,
name|short
name|Comperand
parameter_list|)
block|{
return|return
name|_InterlockedCompareExchange16
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
comment|// CHECK: define{{.*}}i16 @test_InterlockedCompareExchange16(i16*{{[a-z_ ]*}}%Destination, i16{{[a-z_ ]*}}%Exchange, i16{{[a-z_ ]*}}%Comperand){{.*}}{
end_comment

begin_comment
comment|// CHECK: [[TMP:%[0-9]+]] = cmpxchg volatile i16* %Destination, i16 %Comperand, i16 %Exchange seq_cst seq_cst
end_comment

begin_comment
comment|// CHECK: [[RESULT:%[0-9]+]] = extractvalue { i16, i1 } [[TMP]], 0
end_comment

begin_comment
comment|// CHECK: ret i16 [[RESULT]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|long
name|test_InterlockedCompareExchange
parameter_list|(
name|long
specifier|volatile
modifier|*
name|Destination
parameter_list|,
name|long
name|Exchange
parameter_list|,
name|long
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
name|__int64
name|test_InterlockedCompareExchange64
parameter_list|(
name|__int64
specifier|volatile
modifier|*
name|Destination
parameter_list|,
name|__int64
name|Exchange
parameter_list|,
name|__int64
name|Comperand
parameter_list|)
block|{
return|return
name|_InterlockedCompareExchange64
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
comment|// CHECK: define{{.*}}i64 @test_InterlockedCompareExchange64(i64*{{[a-z_ ]*}}%Destination, i64{{[a-z_ ]*}}%Exchange, i64{{[a-z_ ]*}}%Comperand){{.*}}{
end_comment

begin_comment
comment|// CHECK: [[TMP:%[0-9]+]] = cmpxchg volatile i64* %Destination, i64 %Comperand, i64 %Exchange seq_cst seq_cst
end_comment

begin_comment
comment|// CHECK: [[RESULT:%[0-9]+]] = extractvalue { i64, i1 } [[TMP]], 0
end_comment

begin_comment
comment|// CHECK: ret i64 [[RESULT]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|short
name|test_InterlockedIncrement16
parameter_list|(
name|short
specifier|volatile
modifier|*
name|Addend
parameter_list|)
block|{
return|return
name|_InterlockedIncrement16
argument_list|(
name|Addend
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i16 @test_InterlockedIncrement16(i16*{{[a-z_ ]*}}%Addend){{.*}}{
end_comment

begin_comment
comment|// CHECK: [[TMP:%[0-9]+]] = atomicrmw add i16* %Addend, i16 1 seq_cst
end_comment

begin_comment
comment|// CHECK: [[RESULT:%[0-9]+]] = add i16 [[TMP]], 1
end_comment

begin_comment
comment|// CHECK: ret i16 [[RESULT]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|long
name|test_InterlockedIncrement
parameter_list|(
name|long
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
name|short
name|test_InterlockedDecrement16
parameter_list|(
name|short
specifier|volatile
modifier|*
name|Addend
parameter_list|)
block|{
return|return
name|_InterlockedDecrement16
argument_list|(
name|Addend
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define{{.*}}i16 @test_InterlockedDecrement16(i16*{{[a-z_ ]*}}%Addend){{.*}}{
end_comment

begin_comment
comment|// CHECK: [[TMP:%[0-9]+]] = atomicrmw sub i16* %Addend, i16 1 seq_cst
end_comment

begin_comment
comment|// CHECK: [[RESULT:%[0-9]+]] = add i16 [[TMP]], -1
end_comment

begin_comment
comment|// CHECK: ret i16 [[RESULT]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|long
name|test_InterlockedDecrement
parameter_list|(
name|long
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm__
argument_list|)
end_if

begin_function
name|__int64
name|test_InterlockedExchange64
parameter_list|(
name|__int64
specifier|volatile
modifier|*
name|value
parameter_list|,
name|__int64
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedExchange64
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-ARM-X64: define{{.*}}i64 @test_InterlockedExchange64(i64*{{[a-z_ ]*}}%value, i64{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[RESULT:%[0-9]+]] = atomicrmw xchg i64* %value, i64 %mask seq_cst
end_comment

begin_comment
comment|// CHECK-ARM-X64:   ret i64 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK-ARM-X64: }
end_comment

begin_function
name|__int64
name|test_InterlockedExchangeAdd64
parameter_list|(
name|__int64
specifier|volatile
modifier|*
name|value
parameter_list|,
name|__int64
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedExchangeAdd64
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-ARM-X64: define{{.*}}i64 @test_InterlockedExchangeAdd64(i64*{{[a-z_ ]*}}%value, i64{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[RESULT:%[0-9]+]] = atomicrmw add i64* %value, i64 %mask seq_cst
end_comment

begin_comment
comment|// CHECK-ARM-X64:   ret i64 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK-ARM-X64: }
end_comment

begin_function
name|__int64
name|test_InterlockedExchangeSub64
parameter_list|(
name|__int64
specifier|volatile
modifier|*
name|value
parameter_list|,
name|__int64
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedExchangeSub64
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-ARM-X64: define{{.*}}i64 @test_InterlockedExchangeSub64(i64*{{[a-z_ ]*}}%value, i64{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[RESULT:%[0-9]+]] = atomicrmw sub i64* %value, i64 %mask seq_cst
end_comment

begin_comment
comment|// CHECK-ARM-X64:   ret i64 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK-ARM-X64: }
end_comment

begin_function
name|__int64
name|test_InterlockedOr64
parameter_list|(
name|__int64
specifier|volatile
modifier|*
name|value
parameter_list|,
name|__int64
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedOr64
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-ARM-X64: define{{.*}}i64 @test_InterlockedOr64(i64*{{[a-z_ ]*}}%value, i64{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[RESULT:%[0-9]+]] = atomicrmw or i64* %value, i64 %mask seq_cst
end_comment

begin_comment
comment|// CHECK-ARM-X64:   ret i64 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK-ARM-X64: }
end_comment

begin_function
name|__int64
name|test_InterlockedXor64
parameter_list|(
name|__int64
specifier|volatile
modifier|*
name|value
parameter_list|,
name|__int64
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedXor64
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-ARM-X64: define{{.*}}i64 @test_InterlockedXor64(i64*{{[a-z_ ]*}}%value, i64{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[RESULT:%[0-9]+]] = atomicrmw xor i64* %value, i64 %mask seq_cst
end_comment

begin_comment
comment|// CHECK-ARM-X64:   ret i64 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK-ARM-X64: }
end_comment

begin_function
name|__int64
name|test_InterlockedAnd64
parameter_list|(
name|__int64
specifier|volatile
modifier|*
name|value
parameter_list|,
name|__int64
name|mask
parameter_list|)
block|{
return|return
name|_InterlockedAnd64
argument_list|(
name|value
argument_list|,
name|mask
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-ARM-X64: define{{.*}}i64 @test_InterlockedAnd64(i64*{{[a-z_ ]*}}%value, i64{{[a-z_ ]*}}%mask){{.*}}{
end_comment

begin_comment
comment|// CHECK-ARM-X64:   [[RESULT:%[0-9]+]] = atomicrmw and i64* %value, i64 %mask seq_cst
end_comment

begin_comment
comment|// CHECK-ARM-X64:   ret i64 [[RESULT:%[0-9]+]]
end_comment

begin_comment
comment|// CHECK-ARM-X64: }
end_comment

begin_function
name|__int64
name|test_InterlockedIncrement64
parameter_list|(
name|__int64
specifier|volatile
modifier|*
name|Addend
parameter_list|)
block|{
return|return
name|_InterlockedIncrement64
argument_list|(
name|Addend
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-ARM-X64: define{{.*}}i64 @test_InterlockedIncrement64(i64*{{[a-z_ ]*}}%Addend){{.*}}{
end_comment

begin_comment
comment|// CHECK-ARM-X64: [[TMP:%[0-9]+]] = atomicrmw add i64* %Addend, i64 1 seq_cst
end_comment

begin_comment
comment|// CHECK-ARM-X64: [[RESULT:%[0-9]+]] = add i64 [[TMP]], 1
end_comment

begin_comment
comment|// CHECK-ARM-X64: ret i64 [[RESULT]]
end_comment

begin_comment
comment|// CHECK-ARM-X64: }
end_comment

begin_function
name|__int64
name|test_InterlockedDecrement64
parameter_list|(
name|__int64
specifier|volatile
modifier|*
name|Addend
parameter_list|)
block|{
return|return
name|_InterlockedDecrement64
argument_list|(
name|Addend
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-ARM-X64: define{{.*}}i64 @test_InterlockedDecrement64(i64*{{[a-z_ ]*}}%Addend){{.*}}{
end_comment

begin_comment
comment|// CHECK-ARM-X64: [[TMP:%[0-9]+]] = atomicrmw sub i64* %Addend, i64 1 seq_cst
end_comment

begin_comment
comment|// CHECK-ARM-X64: [[RESULT:%[0-9]+]] = add i64 [[TMP]], -1
end_comment

begin_comment
comment|// CHECK-ARM-X64: ret i64 [[RESULT]]
end_comment

begin_comment
comment|// CHECK-ARM-X64: }
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|unsigned
name|char
name|test_interlockedbittestandset
parameter_list|(
specifier|volatile
name|long
modifier|*
name|ptr
parameter_list|,
name|long
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

begin_function
name|void
name|test__fastfail
parameter_list|()
block|{
name|__fastfail
argument_list|(
literal|42
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define{{.*}} void @test__fastfail()
end_comment

begin_comment
comment|// CHECK-ARM: call void asm sideeffect "udf #251", "{r0}"(i32 42) #[[NORETURN:[0-9]+]]
end_comment

begin_comment
comment|// CHECK-INTEL: call void asm sideeffect "int $$0x29", "{cx}"(i32 42) #[[NORETURN]]
end_comment

begin_comment
comment|// Attributes come last.
end_comment

begin_comment
comment|// CHECK: attributes #[[NORETURN]] = { noreturn{{.*}} }
end_comment

end_unit

