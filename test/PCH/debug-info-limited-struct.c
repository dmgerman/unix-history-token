begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %S/debug-info-limited-struct.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t -emit-llvm %s -debug-info-kind=limited -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: !DICompositeType(tag: DW_TAG_structure_type, name: "foo"
end_comment

begin_comment
comment|// CHECK-NOT:              flags: {{[^,]*}}FlagFwdDecl
end_comment

begin_comment
comment|// CHECK-SAME:             {{$}}
end_comment

end_unit

