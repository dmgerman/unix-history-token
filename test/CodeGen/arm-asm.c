begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumb %s -emit-llvm -o - | FileCheck %s
end_comment

begin_function
name|int
name|t1
parameter_list|()
block|{
specifier|static
name|float
name|k
init|=
literal|1.0f
decl_stmt|;
comment|// CHECK: flds s15
asm|__asm__
specifier|volatile
asm|("flds s15, %[k] \n" :: [k] "Uv" (k) : "s15");
return|return
literal|0
return|;
block|}
end_function

end_unit

