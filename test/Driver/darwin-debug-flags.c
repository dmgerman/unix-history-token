begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env RC_DEBUG_OPTIONS=1 %clang -ccc-host-triple i386-apple-darwin9 -g -Os %s  -emit-llvm -S -o - | FileCheck %s
end_comment

begin_comment
comment|//<rdar://problem/7256886>
end_comment

begin_comment
comment|// CHECK: !0 = metadata !{
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

end_unit

