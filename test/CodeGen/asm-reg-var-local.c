begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-apple-darwin -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Exercise various use cases for local asm "register variables".
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
comment|// CHECK: [[A:%[a-zA-Z0-9]+]] = alloca i32
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
comment|// CHECK: store i32 5, i32* [[A]]
asm|asm
specifier|volatile
asm|("; %0 This asm defines rsi" : "=r"(a));
comment|// CHECK: [[Z:%[a-zA-Z0-9]+]] = call i32 asm sideeffect "; $0 This asm defines rsi", "={rsi},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: store i32 [[Z]], i32* [[A]]
name|a
operator|=
literal|42
expr_stmt|;
comment|// CHECK:  store i32 42, i32* [[A]]
asm|asm
specifier|volatile
asm|("; %0 This asm uses rsi" : : "r"(a));
comment|// CHECK:  [[TMP:%[a-zA-Z0-9]+]] = load i32* [[A]]
comment|// CHECK:  call void asm sideeffect "; $0 This asm uses rsi", "{rsi},~{dirflag},~{fpsr},~{flags}"(i32 [[TMP]])
return|return
name|a
return|;
comment|// CHECK:  [[TMP1:%[a-zA-Z0-9]+]] = load i32* [[A]]
comment|// CHECK:  ret i32 [[TMP1]]
block|}
end_function

end_unit

