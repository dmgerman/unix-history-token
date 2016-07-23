begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm-none-eabi -ffreestanding -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64 -ffreestanding -emit-llvm -o - %s | FileCheck %s
end_comment

begin_struct
specifier|extern
struct|struct
name|T
block|{
name|int
name|b0
range|:
literal|8
decl_stmt|;
name|int
name|b1
range|:
literal|24
decl_stmt|;
name|int
name|b2
range|:
literal|1
decl_stmt|;
block|}
name|g
struct|;
end_struct

begin_function
name|int
name|func
parameter_list|()
block|{
return|return
name|g
operator|.
name|b1
return|;
block|}
end_function

begin_comment
comment|// CHECK: @g = external global %struct.T, align 4
end_comment

begin_comment
comment|// CHECK: %{{.*}} = load i64, i64* bitcast (%struct.T* @g to i64*), align 4
end_comment

end_unit

