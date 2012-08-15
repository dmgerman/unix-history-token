begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fms-extensions -E | FileCheck %s
end_comment

begin_comment
comment|// We use -fms-extensions to test both _Pragma and __pragma.
end_comment

begin_comment
comment|// A long time ago the pragma lexer's buffer showed through in -E output.
end_comment

begin_comment
comment|// CHECK-NOT: scratch space
end_comment

begin_define
define|#
directive|define
name|push_p
value|_Pragma ("pack(push)")
end_define

begin_decl_stmt
name|push_p
comment|// CHECK: #pragma pack(push)
name|push_p
name|_Pragma
argument_list|(
literal|"pack(push)"
argument_list|)
name|__pragma
argument_list|(
name|pack
argument_list|(
name|push
argument_list|)
argument_list|)
comment|// CHECK: #pragma pack(push)
comment|// CHECK-NEXT: #line 11 "{{.*}}_Pragma-location.c"
comment|// CHECK-NEXT: #pragma pack(push)
comment|// CHECK-NEXT: #line 11 "{{.*}}_Pragma-location.c"
comment|// CHECK-NEXT: #pragma pack(push)
define|#
directive|define
name|__PRAGMA_PUSH_NO_EXTRA_ARG_WARNINGS
value|_Pragma("clang diagnostic push") \ _Pragma("clang diagnostic ignored \"-Wformat-extra-args\"")
define|#
directive|define
name|__PRAGMA_POP_NO_EXTRA_ARG_WARNINGS
value|_Pragma("clang diagnostic pop")
name|void
name|test
argument_list|()
block|{
literal|1
expr_stmt|;
name|_Pragma
argument_list|(
literal|"clang diagnostic push"
argument_list|)
block|\
name|_Pragma
argument_list|(
literal|"clang diagnostic ignored \"-Wformat-extra-args\""
argument_list|)
name|_Pragma
argument_list|(
literal|"clang diagnostic pop"
argument_list|)
literal|2
expr_stmt|;
name|__PRAGMA_PUSH_NO_EXTRA_ARG_WARNINGS
literal|3
expr_stmt|;
name|__PRAGMA_POP_NO_EXTRA_ARG_WARNINGS
block|}
end_decl_stmt

begin_comment
comment|// CHECK: void test () {
end_comment

begin_comment
comment|// CHECK-NEXT:   1;
end_comment

begin_comment
comment|// CHECK-NEXT: #line 24 "{{.*}}_Pragma-location.c"
end_comment

begin_comment
comment|// CHECK-NEXT: #pragma clang diagnostic push
end_comment

begin_comment
comment|// CHECK-NEXT: #pragma clang diagnostic ignored "-Wformat-extra-args"
end_comment

begin_comment
comment|// CHECK-NEXT: #pragma clang diagnostic pop
end_comment

begin_comment
comment|// CHECK:   2;
end_comment

begin_comment
comment|// CHECK-NEXT: #line 28 "{{.*}}_Pragma-location.c"
end_comment

begin_comment
comment|// CHECK-NEXT: #pragma clang diagnostic push
end_comment

begin_comment
comment|// CHECK-NEXT: #line 28 "{{.*}}_Pragma-location.c"
end_comment

begin_comment
comment|// CHECK-NEXT: #pragma clang diagnostic ignored "-Wformat-extra-args"
end_comment

begin_comment
comment|// CHECK-NEXT:   3;
end_comment

begin_comment
comment|// CHECK-NEXT: #line 29 "{{.*}}_Pragma-location.c"
end_comment

begin_comment
comment|// CHECK-NEXT: #pragma clang diagnostic pop
end_comment

begin_comment
comment|// CHECK-NEXT: }
end_comment

end_unit

