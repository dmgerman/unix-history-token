begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|FOO
end_define

begin_expr_stmt
name|FOO
name|FOO
end_expr_stmt

begin_comment
comment|// RUN: c-index-test -file-refs-at=%s:3:2 %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -file-refs-at=%s:3:2 %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK:      macro expansion=FOO:1:9
end_comment

begin_comment
comment|// CHECK-NEXT: macro definition=FOO =[1:9 - 1:12]
end_comment

begin_comment
comment|// CHECK-NEXT: macro expansion=FOO:1:9 =[3:1 - 3:4]
end_comment

begin_comment
comment|// CHECK-NEXT: macro expansion=FOO:1:9 =[4:1 - 4:4]
end_comment

end_unit

