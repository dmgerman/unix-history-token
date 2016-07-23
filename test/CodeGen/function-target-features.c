begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This test verifies that we produce target-cpu and target-features attributes
end_comment

begin_comment
comment|// on functions when they're different from the standard cpu and have written
end_comment

begin_comment
comment|// features.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s -target-feature +avx | FileCheck %s -check-prefix=AVX-FEATURE
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s -target-feature +avx | FileCheck %s -check-prefix=AVX-NO-CPU
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s -target-feature +avx512f -target-feature +avx512er | FileCheck %s -check-prefix=TWO-AVX
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s -target-cpu corei7 | FileCheck %s -check-prefix=CORE-CPU
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s -target-cpu corei7 -target-feature +avx | FileCheck %s -check-prefix=CORE-CPU-AND-FEATURES
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s -target-cpu x86-64 | FileCheck %s -check-prefix=X86-64-CPU
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s -target-cpu corei7-avx -target-feature -avx | FileCheck %s -check-prefix=AVX-MINUS-FEATURE
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple sparc-unknown-unknown -emit-llvm -o - %s -target-feature +soft-float | FileCheck %s -check-prefix=SOFT-FLOAT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-unknown-unknown -emit-llvm -o - %s -target-feature +soft-float | FileCheck %s -check-prefix=SOFT-FLOAT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips-unknown-unknown -emit-llvm -o - %s -target-feature +soft-float | FileCheck %s -check-prefix=SOFT-FLOAT
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

begin_comment
comment|// AVX-FEATURE: "target-features"{{.*}}+avx
end_comment

begin_comment
comment|// AVX-NO-CPU-NOT: target-cpu
end_comment

begin_comment
comment|// TWO-AVX: "target-features"={{.*}}+avx512er{{.*}}+avx512f
end_comment

begin_comment
comment|// CORE-CPU: "target-cpu"="corei7"
end_comment

begin_comment
comment|// CORE-CPU-AND-FEATURES: "target-cpu"="corei7" "target-features"={{.*}}+avx
end_comment

begin_comment
comment|// X86-64-CPU: "target-cpu"="x86-64"
end_comment

begin_comment
comment|// AVX-MINUS-FEATURE: "target-features"={{.*}}-avx
end_comment

begin_comment
comment|// SOFT-FLOAT: "target-features"={{.*}}+soft-float
end_comment

begin_comment
comment|// NO-SOFT-FLOAT-NOT: "target-features"={{.*}}+soft-float
end_comment

end_unit

