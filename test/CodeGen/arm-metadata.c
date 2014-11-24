begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7a-linux-gnueabi -emit-llvm -o - %s | FileCheck -check-prefix=DEFAULT %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7a-linux-gnueabi -emit-llvm -o - %s -fshort-enums | FileCheck -check-prefix=SHORT-ENUM %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7a-linux-gnueabi -emit-llvm -o - %s -fshort-wchar | FileCheck -check-prefix=SHORT-WCHAR %s
end_comment

begin_comment
comment|// DEFAULT:  !{{[0-9]+}} = metadata !{i32 1, metadata !"wchar_size", i32 4}
end_comment

begin_comment
comment|// DEFAULT:   !{{[0-9]+}} = metadata !{i32 1, metadata !"min_enum_size", i32 4}
end_comment

begin_comment
comment|// SHORT-WCHAR: !{{[0-9]+}} = metadata !{i32 1, metadata !"wchar_size", i32 2}
end_comment

begin_comment
comment|// SHORT-WCHAR:   !{{[0-9]+}} = metadata !{i32 1, metadata !"min_enum_size", i32 4}
end_comment

begin_comment
comment|// SHORT_ENUM:  !{{[0-9]+}} = metadata !{i32 1, metadata !"wchar_size", i32 4}
end_comment

begin_comment
comment|// SHORT-ENUM:  !{{[0-9]+}} = metadata !{i32 1, metadata !"min_enum_size", i32 1}
end_comment

end_unit

