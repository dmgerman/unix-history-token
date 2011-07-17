begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o - | FileCheck %s
end_comment

begin_comment
comment|// Exercise various use cases for local asm "register variables".
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// XTARGET: x86_64,i686,i386
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
comment|// CHECK: %a = alloca i32
specifier|register
name|int
name|a
name|asm
argument_list|(
literal|"rsi"
argument_list|)
init|=
literal|5
decl_stmt|;
comment|// CHECK: store i32 5, i32* %a, align 4
asm|asm
specifier|volatile
asm|("; %0 This asm defines rsi" : "=r"(a));
comment|// CHECK: %1 = call i32 asm sideeffect "; $0 This asm defines rsi", "={rsi}
comment|// CHECK: store i32 %1, i32* %a
name|a
operator|=
literal|42
expr_stmt|;
comment|// CHECK:  store i32 42, i32* %a, align 4
asm|asm
specifier|volatile
asm|("; %0 This asm uses rsi" : : "r"(a));
comment|// CHECK:  %2 = load i32* %a, align 4
comment|// CHECK:  call void asm sideeffect "", "{rsi}"(i32 %2) nounwind
comment|// CHECK:  %3 = call i32 asm sideeffect "", "={rsi}"() nounwind
comment|// CHECK:  call void asm sideeffect "; $0 This asm uses rsi", "{rsi},~{dirflag},~{fpsr},~{flags}"(i32 %3)
return|return
name|a
return|;
comment|// CHECK:  %4 = load i32* %a, align 4
comment|// CHECK:  call void asm sideeffect "", "{rsi}"(i32 %4) nounwind
comment|// CHECK:  %5 = call i32 asm sideeffect "", "={rsi}"() nounwind
comment|// CHECK:  store i32 %5, i32* %0, align 4
comment|// CHECK:  %6 = load i32* %0, align 4
comment|// CHECK:  store i32 %6, i32* %retval, align 4
block|}
end_function

end_unit

