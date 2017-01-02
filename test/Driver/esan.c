begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang     -target x86_64-unknown-linux -fsanitize=efficiency-cache-frag %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -O1 -target x86_64-unknown-linux -fsanitize=efficiency-cache-frag %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -O2 -target x86_64-unknown-linux -fsanitize=efficiency-cache-frag %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -O3 -target x86_64-unknown-linux -fsanitize=efficiency-cache-frag %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang     -target x86_64-unknown-linux -fsanitize=efficiency-working-set %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -O1 -target x86_64-unknown-linux -fsanitize=efficiency-working-set %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -O2 -target x86_64-unknown-linux -fsanitize=efficiency-working-set %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -O3 -target x86_64-unknown-linux -fsanitize=efficiency-working-set %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-linux -fsanitize=efficiency-cache-frag %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-linux -fsanitize=efficiency-working-set %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux -fsanitize=efficiency-cache-frag %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux -fsanitize=efficiency-working-set %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Verify that -fsanitize=efficiency-* invokes esan instrumentation.
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|*
name|a
return|;
block|}
end_function

begin_comment
comment|// CHECK: __esan_init
end_comment

end_unit

