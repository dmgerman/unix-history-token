begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that -print-libgcc-file-name correctly respects -rtlib=compiler-rt.
end_comment

begin_comment
comment|// RUN: %clang -rtlib=compiler-rt -print-libgcc-file-name 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=x86_64-pc-linux \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CLANGRT-X8664 %s
end_comment

begin_comment
comment|// CHECK-CLANGRT-X8664: libclang_rt.builtins-x86_64.a
end_comment

begin_comment
comment|// RUN: %clang -rtlib=compiler-rt -print-libgcc-file-name 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=i686-pc-linux \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CLANGRT-I686 %s
end_comment

begin_comment
comment|// CHECK-CLANGRT-I686: libclang_rt.builtins-i686.a
end_comment

end_unit

