begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mipsel-linux-gnu -o - -emit-llvm -S %s |\
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=32EL
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -o - -emit-llvm -S %s |\
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=32EB
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-linux-gnu -o - -emit-llvm -S %s |\
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=64EL
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -o - -emit-llvm -S %s |\
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=64EB
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-linux-gnu -o - -emit-llvm -S -mfp64 %s |\
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=32EL
end_comment

begin_comment
comment|// 32EL: e-p:32:32:32-i1:8:8-i8:8:32-i16:16:32-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-n32-S64
end_comment

begin_comment
comment|// 32EB: E-p:32:32:32-i1:8:8-i8:8:32-i16:16:32-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-n32-S64
end_comment

begin_comment
comment|// 64EL: e-p:64:64:64-i1:8:8-i8:8:32-i16:16:32-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f128:128:128-v64:64:64-n32:64-S128
end_comment

begin_comment
comment|// 64EB: E-p:64:64:64-i1:8:8-i8:8:32-i16:16:32-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f128:128:128-v64:64:64-n32:64-S128
end_comment

end_unit

