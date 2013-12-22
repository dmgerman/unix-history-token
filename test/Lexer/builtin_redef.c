begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -D__TIME__=1234 -U__DATE__ -E 2>&1 | FileCheck %s --check-prefix=CHECK-OUT
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -D__TIME__=1234 -U__DATE__ -E 2>&1 | FileCheck %s --check-prefix=CHECK-WARN
end_comment

begin_comment
comment|// RUN: not %clang_cc1 %s -D__TIME__=1234 -U__DATE__ -E 2>&1 -pedantic-errors | FileCheck %s --check-prefix=CHECK-ERR
end_comment

begin_comment
comment|// CHECK-WARN:<command line>:{{.*}} warning: redefining builtin macro
end_comment

begin_comment
comment|// CHECK-WARN:<command line>:{{.*}} warning: undefining builtin macro
end_comment

begin_comment
comment|// CHECK-ERR:<command line>:{{.*}} error: redefining builtin macro
end_comment

begin_comment
comment|// CHECK-ERR:<command line>:{{.*}} error: undefining builtin macro
end_comment

begin_decl_stmt
name|int
name|n
init|=
name|__TIME__
decl_stmt|;
end_decl_stmt

begin_macro
name|__DATE__
end_macro

begin_define
define|#
directive|define
name|__FILE__
value|"my file"
end_define

begin_comment
comment|// CHECK-WARN: :[[@LINE-1]]:9: warning: redefining builtin macro
end_comment

begin_comment
comment|// CHECK-ERR: :[[@LINE-2]]:9: error: redefining builtin macro
end_comment

begin_comment
comment|// CHECK-OUT: int n = 1234;
end_comment

begin_comment
comment|// CHECK-OUT: __DATE__
end_comment

end_unit

