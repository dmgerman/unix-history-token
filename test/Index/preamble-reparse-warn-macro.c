begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: mkdir -p %t
end_comment

begin_comment
comment|// RUN: touch %t/header.h
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -test-load-source-reparse 2 local %s -I %t 2>&1> %t.out.txt | FileCheck %s
end_comment

begin_comment
comment|// CHECK: preamble-reparse-warn-macro.c:[[@LINE+8]]:9: warning: 'MAC' macro redefined
end_comment

begin_comment
comment|// CHECK-NEXT: Number FIX-ITs = 0
end_comment

begin_comment
comment|// CHECK-NEXT: preamble-reparse-warn-macro.c:[[@LINE+2]]:9: note: previous definition is here
end_comment

begin_define
define|#
directive|define
name|MAC
value|1
end_define

begin_include
include|#
directive|include
file|"header.h"
end_include

begin_function_decl
name|void
name|test
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MAC
value|2
end_define

end_unit

