begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-win32 -emit-llvm -fms-extensions -fms-volatile -o -< %s | FileCheck %s
end_comment

begin_function
name|void
name|test1
parameter_list|(
name|int
specifier|volatile
modifier|*
name|p
parameter_list|,
name|int
name|v
parameter_list|)
block|{
name|__iso_volatile_store32
argument_list|(
name|p
argument_list|,
name|v
argument_list|)
expr_stmt|;
comment|// CHECK-LABEL: @test1
comment|// CHECK: store volatile {{.*}}, {{.*}}
block|}
end_function

begin_function
name|int
name|test2
parameter_list|(
specifier|const
name|int
specifier|volatile
modifier|*
name|p
parameter_list|)
block|{
return|return
name|__iso_volatile_load32
argument_list|(
name|p
argument_list|)
return|;
comment|// CHECK-LABEL: @test2
comment|// CHECK: load volatile {{.*}}
block|}
end_function

end_unit

