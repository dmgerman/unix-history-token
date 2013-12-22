begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -include-pch %S/Inputs/badpch-empty.h.gch %s 2>&1 | FileCheck -check-prefix=CHECK-EMPTY %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -include-pch %S/Inputs/badpch-dir.h.gch %s 2>&1 | FileCheck -check-prefix=CHECK-DIR %s
end_comment

begin_comment
comment|// The purpose of this test is to verify that various invalid PCH files are
end_comment

begin_comment
comment|// reported as such.
end_comment

begin_comment
comment|// PR4568: The messages were much improved since the bug was filed on
end_comment

begin_comment
comment|// 2009-07-16, though in the case of the PCH being a directory, the error
end_comment

begin_comment
comment|// message still did not contain the name of the PCH. Also, r149918 which was
end_comment

begin_comment
comment|// submitted on 2012-02-06 introduced a segfault in the case where the PCH is
end_comment

begin_comment
comment|// an empty file and clang was built with assertions.
end_comment

begin_comment
comment|// CHECK-EMPTY: error: input is not a PCH file: '{{.*[/\\]}}badpch-empty.h.gch'
end_comment

begin_comment
comment|// CHECK-DIR:error: no suitable precompiled header file found in directory '{{.*[/\\]}}badpch-dir.h.gch
end_comment

end_unit

