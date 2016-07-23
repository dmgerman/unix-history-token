begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7a--none-eabi -target-abi aapcs -mfloat-abi soft -fallow-half-arguments-and-returns -emit-llvm -o - -O1 %s | FileCheck %s --check-prefix=CHECK --check-prefix=SOFT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7a--none-eabi -target-abi aapcs -mfloat-abi hard -fallow-half-arguments-and-returns -emit-llvm -o - -O1 %s | FileCheck %s --check-prefix=CHECK --check-prefix=HARD
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7a--none-eabi -target-abi aapcs -mfloat-abi soft -fnative-half-arguments-and-returns -emit-llvm -o - -O1 %s | FileCheck %s --check-prefix=NATIVE
end_comment

begin_decl_stmt
name|__fp16
name|g
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|t1
parameter_list|(
name|__fp16
name|a
parameter_list|)
block|{
name|g
operator|=
name|a
expr_stmt|;
block|}
end_function

begin_comment
comment|// SOFT: define void @t1(i32 [[PARAM:%.*]])
end_comment

begin_comment
comment|// SOFT: [[TRUNC:%.*]] = trunc i32 [[PARAM]] to i16
end_comment

begin_comment
comment|// HARD: define arm_aapcs_vfpcc void @t1(float [[PARAM:%.*]])
end_comment

begin_comment
comment|// HARD: [[BITCAST:%.*]] = bitcast float [[PARAM]] to i32
end_comment

begin_comment
comment|// HARD: [[TRUNC:%.*]] = trunc i32 [[BITCAST]] to i16
end_comment

begin_comment
comment|// CHECK: store i16 [[TRUNC]], i16* bitcast (half* @g to i16*)
end_comment

begin_comment
comment|// NATIVE: define void @t1(half [[PARAM:%.*]])
end_comment

begin_comment
comment|// NATIVE: store half [[PARAM]], half* @g
end_comment

begin_function
name|__fp16
name|t2
parameter_list|()
block|{
return|return
name|g
return|;
block|}
end_function

begin_comment
comment|// SOFT: define i32 @t2()
end_comment

begin_comment
comment|// HARD: define arm_aapcs_vfpcc float @t2()
end_comment

begin_comment
comment|// NATIVE: define half @t2()
end_comment

begin_comment
comment|// CHECK: [[LOAD:%.*]] = load i16, i16* bitcast (half* @g to i16*)
end_comment

begin_comment
comment|// CHECK: [[ZEXT:%.*]] = zext i16 [[LOAD]] to i32
end_comment

begin_comment
comment|// SOFT: ret i32 [[ZEXT]]
end_comment

begin_comment
comment|// HARD: [[BITCAST:%.*]] = bitcast i32 [[ZEXT]] to float
end_comment

begin_comment
comment|// HARD: ret float [[BITCAST]]
end_comment

begin_comment
comment|// NATIVE: [[LOAD:%.*]] = load half, half* @g
end_comment

begin_comment
comment|// NATIVE: ret half [[LOAD]]
end_comment

end_unit

