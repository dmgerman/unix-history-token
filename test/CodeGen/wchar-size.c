begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s -check-prefix=LONG-WCHAR
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-windows-msvc -emit-llvm -o - %s | FileCheck %s -check-prefix=SHORT-WCHAR
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm -o - -fshort-wchar %s | FileCheck %s -check-prefix=SHORT-WCHAR
end_comment

begin_comment
comment|// Note: -fno-short-wchar implies the target default is used; so there is no
end_comment

begin_comment
comment|// need to test this separately here.
end_comment

begin_comment
comment|// LONG-WCHAR: !{{[0-9]+}} = !{i32 {{[0-9]+}}, !"wchar_size", i32 4}
end_comment

begin_comment
comment|// SHORT-WCHAR: !{{[0-9]+}} = !{i32 {{[0-9]+}}, !"wchar_size", i32 2}
end_comment

end_unit

