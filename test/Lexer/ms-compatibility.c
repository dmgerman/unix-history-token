begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -E -fms-compatibility %s | FileCheck --check-prefix=CHECK-MS-COMPAT %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -E %s | FileCheck --check-prefix=CHECK-NO-MS-COMPAT %s
end_comment

begin_define
define|#
directive|define
name|FN
parameter_list|(
name|x
parameter_list|)
value|L#x
end_define

begin_define
define|#
directive|define
name|F
value|L "aaa"
end_define

begin_decl_stmt
name|void
modifier|*
name|v1
init|=
name|FN
argument_list|(
name|aaa
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|v2
init|=
name|F
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-MS-COMPAT: void *v1 = L"aaa";
end_comment

begin_comment
comment|// CHECK-MS-COMPAT: void *v2 = L "aaa";
end_comment

begin_comment
comment|// CHECK-NO-MS-COMPAT: void *v1 = L "aaa";
end_comment

begin_comment
comment|// CHECK-NO-MS-COMPAT: void *v2 = L "aaa";
end_comment

end_unit

