begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -c -O3 -m64 -emit-llvm -o - | llc -march=x86-64 -mtriple=x86_64-apple-darwin | FileCheck %s
end_comment

begin_comment
comment|// r9 used to be clobbered before its value was moved to r10.  7993104.
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
comment|// CHECK: bar
comment|// CHECK: movq  %r9, %r10
comment|// CHECK: movq  %rdi, %r9
comment|// CHECK: bar
specifier|register
name|int
name|lr9
name|asm
argument_list|(
literal|"r9"
argument_list|)
init|=
name|x
decl_stmt|;
specifier|register
name|int
name|lr10
name|asm
argument_list|(
literal|"r10"
argument_list|)
init|=
name|y
decl_stmt|;
name|int
name|foo
decl_stmt|;
asm|asm
specifier|volatile
asm|("bar" : "=r"(lr9) : "r"(lr9), "r"(lr10));
name|foo
operator|=
name|lr9
expr_stmt|;
name|lr9
operator|=
name|x
expr_stmt|;
name|lr10
operator|=
name|foo
expr_stmt|;
asm|asm
specifier|volatile
asm|("bar" : "=r"(lr9) : "r"(lr9), "r"(lr10));
block|}
end_function

end_unit

