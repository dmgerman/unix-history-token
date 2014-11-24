begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm %s -o - | FileCheck %s
end_comment

begin_struct
struct|struct
name|Bar
block|{
name|float
name|f1
decl_stmt|;
name|float
name|f2
decl_stmt|;
name|unsigned
name|u
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|Bar
name|foo
parameter_list|(
name|__builtin_va_list
name|ap
parameter_list|)
block|{
return|return
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|Bar
argument_list|)
return|;
comment|// CHECK: [[FPOP:%.*]] = getelementptr inbounds %struct.__va_list_tag* {{.*}}, i32 0, i32 1
comment|// CHECK: [[FPO:%.*]] = load i32* [[FPOP]]
comment|// CHECK: [[FPVEC:%.*]] = getelementptr i8* {{.*}}, i32 [[FPO]]
comment|// CHECK: bitcast i8* [[FPVEC]] to<2 x float>*
block|}
end_function

end_unit

