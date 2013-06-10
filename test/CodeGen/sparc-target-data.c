begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target sparc-sun-solaris   -o - -emit-llvm -S %s | FileCheck %s -check-prefix=V8
end_comment

begin_comment
comment|// RUN: %clang -target sparcv9-sun-solaris -o - -emit-llvm -S %s | FileCheck %s -check-prefix=V9
end_comment

begin_comment
comment|// V8: E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-n32-S64
end_comment

begin_comment
comment|// V9: E-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-n32:64-S128
end_comment

end_unit

