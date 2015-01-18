begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env RC_DEBUG_OPTIONS=1 %clang -target i386-apple-darwin9 -I "path with \spaces" -g -Os %s  -emit-llvm -S -o - | FileCheck %s
end_comment

begin_comment
comment|//<rdar://problem/7256886>
end_comment

begin_comment
comment|// RUN: touch %t.s
end_comment

begin_comment
comment|// RUN: env RC_DEBUG_OPTIONS=1 %clang -### -target i386-apple-darwin9 -c -g %t.s 2>&1 | FileCheck -check-prefix=S %s
end_comment

begin_comment
comment|//<rdar://problem/12955296>
end_comment

begin_comment
comment|// RUN: %clang -### -target i386-apple-darwin9 -c -g %t.s 2>&1 | FileCheck -check-prefix=P %s
end_comment

begin_comment
comment|// CHECK: !0 = !{
end_comment

begin_comment
comment|// CHECK: -I path\5C with\5C \5C\5Cspaces
end_comment

begin_comment
comment|// CHECK: -g -Os
end_comment

begin_comment
comment|// CHECK: -mmacosx-version-min=10.5.0
end_comment

begin_comment
comment|// CHECK: [ DW_TAG_compile_unit ]
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// S: "-dwarf-debug-flags"
end_comment

begin_comment
comment|// P: "-dwarf-debug-producer"
end_comment

begin_comment
comment|// This depends on shell quoting.
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

end_unit

