begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumb-apple-darwin -target-abi aapcs -target-cpu cortex-m3 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-apple-darwin -target-abi apcs-gnu -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-APCS
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|void
name|test_generic_interrupt
parameter_list|()
block|{
comment|// CHECK: define arm_aapcscc void @test_generic_interrupt() [[GENERIC_ATTR:#[0-9]+]]
comment|// CHECK-APCS: define void @test_generic_interrupt() [[GENERIC_ATTR:#[0-9]+]]
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"IRQ"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|test_irq_interrupt
parameter_list|()
block|{
comment|// CHECK: define arm_aapcscc void @test_irq_interrupt() [[IRQ_ATTR:#[0-9]+]]
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"FIQ"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|test_fiq_interrupt
parameter_list|()
block|{
comment|// CHECK: define arm_aapcscc void @test_fiq_interrupt() [[FIQ_ATTR:#[0-9]+]]
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"SWI"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|test_swi_interrupt
parameter_list|()
block|{
comment|// CHECK: define arm_aapcscc void @test_swi_interrupt() [[SWI_ATTR:#[0-9]+]]
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"ABORT"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|test_abort_interrupt
parameter_list|()
block|{
comment|// CHECK: define arm_aapcscc void @test_abort_interrupt() [[ABORT_ATTR:#[0-9]+]]
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|"UNDEF"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|test_undef_interrupt
parameter_list|()
block|{
comment|// CHECK: define arm_aapcscc void @test_undef_interrupt() [[UNDEF_ATTR:#[0-9]+]]
block|}
end_function

begin_comment
comment|// CHECK: attributes [[GENERIC_ATTR]] = { nounwind alignstack=8 {{"interrupt"[^=]}}
end_comment

begin_comment
comment|// CHECK: attributes [[IRQ_ATTR]] = { nounwind alignstack=8 "interrupt"="IRQ"
end_comment

begin_comment
comment|// CHECK: attributes [[FIQ_ATTR]] = { nounwind alignstack=8 "interrupt"="FIQ"
end_comment

begin_comment
comment|// CHECK: attributes [[SWI_ATTR]] = { nounwind alignstack=8 "interrupt"="SWI"
end_comment

begin_comment
comment|// CHECK: attributes [[ABORT_ATTR]] = { nounwind alignstack=8 "interrupt"="ABORT"
end_comment

begin_comment
comment|// CHECK: attributes [[UNDEF_ATTR]] = { nounwind alignstack=8 "interrupt"="UNDEF"
end_comment

begin_comment
comment|// CHECK-APCS: attributes [[GENERIC_ATTR]] = { nounwind "interrupt"
end_comment

end_unit

