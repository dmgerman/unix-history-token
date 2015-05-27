begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -triple powerpc64le-linux-gnu | FileCheck %s
end_comment

begin_comment
comment|// Sadly since this requires a register constraint to trigger we have to set
end_comment

begin_comment
comment|// a target here.
end_comment

begin_function
name|void
name|a
parameter_list|(
name|void
parameter_list|)
block|{
specifier|register
name|unsigned
name|long
name|__sc_0
name|__asm__
argument_list|(
literal|"r0"
argument_list|)
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("mfcr %0" : "=&r"(__sc_0) : "0"(__sc_0));
block|}
end_function

begin_comment
comment|// Check that we can generate code for this correctly. The matching input
end_comment

begin_comment
comment|// constraint should not have an early clobber on it.
end_comment

begin_comment
comment|// CHECK: call i64 asm sideeffect "mfcr $0", "=&{r0},{r0}"
end_comment

end_unit

