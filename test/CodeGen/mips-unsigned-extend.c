begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mips64-unknown-linux -O0 -target-abi n64 -S -emit-llvm %s -o - | FileCheck %s -check-prefix=N64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-unknown-linux -O0 -target-abi n32 -S -emit-llvm %s -o - | FileCheck %s -check-prefix=N32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips-unknown-linux -O0 -target-abi o32 -S -emit-llvm %s -o - | FileCheck %s -check-prefix=O32
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|unsigned
name|a
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|foo1
parameter_list|()
block|{
name|unsigned
name|f
init|=
literal|0xffffffe0
decl_stmt|;
name|foo
argument_list|(
name|f
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// N64: call void @foo(i32 signext %{{[0-9]+}})
end_comment

begin_comment
comment|// N32: call void @foo(i32 signext %{{[0-9]+}})
end_comment

begin_comment
comment|// O32: call void @foo(i32 signext %{{[0-9]+}})
end_comment

end_unit

