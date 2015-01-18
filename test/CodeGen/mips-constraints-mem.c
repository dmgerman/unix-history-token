begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -S -o - -emit-llvm %s \
end_comment

begin_comment
comment|// RUN: | FileCheck %s
end_comment

begin_comment
comment|// This checks that the frontend will accept inline asm memory constraints.
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
comment|// 'R': An address that can be used in a non-macro load or stor'
comment|// This test will result in the higher and lower nibbles being
comment|// switched due to the lwl/lwr instruction pairs.
comment|// CHECK:   %{{[0-9]+}} = call i32 asm sideeffect  "lwl $0, 1 + $1\0A\09lwr $0, 2 + $1\0A\09", "=r,*R,~{$1}"(i32* %{{[0-9,a-f]+}}) #1,
name|int
name|c
init|=
literal|0xffbbccdd
decl_stmt|;
name|int
modifier|*
name|p
init|=
operator|&
name|c
decl_stmt|;
name|int
name|out
init|=
literal|0
decl_stmt|;
asm|__asm volatile (
literal|"lwl %0, 1 + %1\n\t"
literal|"lwr %0, 2 + %1\n\t"
operator|:
literal|"=r"
operator|(
name|out
operator|)
operator|:
literal|"R"
operator|(
operator|*
name|p
operator|)
block|)
function|;
end_function

begin_return
return|return
literal|0
return|;
end_return

unit|}
end_unit

