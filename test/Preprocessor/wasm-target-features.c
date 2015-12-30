begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -E -dM %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target wasm32-unknown-unknown -msimd128 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=SIMD128
end_comment

begin_comment
comment|// RUN: %clang -E -dM %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target wasm64-unknown-unknown -msimd128 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=SIMD128
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SIMD128:#define __wasm_simd128__ 1{{$}}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -E -dM %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target wasm32-unknown-unknown -mcpu=mvp \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=MVP
end_comment

begin_comment
comment|// RUN: %clang -E -dM %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target wasm64-unknown-unknown -mcpu=mvp \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=MVP
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MVP-NOT:#define __wasm_simd128__
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -E -dM %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target wasm32-unknown-unknown -mcpu=bleeding-edge \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=BLEEDING_EDGE
end_comment

begin_comment
comment|// RUN: %clang -E -dM %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target wasm64-unknown-unknown -mcpu=bleeding-edge \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=BLEEDING_EDGE
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BLEEDING_EDGE:#define __wasm_simd128__ 1{{$}}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -E -dM %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target wasm32-unknown-unknown -mcpu=bleeding-edge -mno-simd128 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=BLEEDING_EDGE_NO_SIMD128
end_comment

begin_comment
comment|// RUN: %clang -E -dM %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target wasm64-unknown-unknown -mcpu=bleeding-edge -mno-simd128 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=BLEEDING_EDGE_NO_SIMD128
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BLEEDING_EDGE_NO_SIMD128-NOT:#define __wasm_simd128__
end_comment

end_unit

