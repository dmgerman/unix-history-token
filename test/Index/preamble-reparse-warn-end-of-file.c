begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: mkdir -p %t
end_comment

begin_comment
comment|// RUN: touch %t/header.h
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -test-load-source-reparse 2 local %s -I %t 2>&1> %t.out.txt | FileCheck -check-prefix=STDERR %s
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t.out.txt %s
end_comment

begin_comment
comment|// CHECK: preamble-reparse-warn-end-of-file.c:[[@LINE+6]]:6: FunctionDecl=test:[[@LINE+6]]:6
end_comment

begin_comment
comment|// STDERR: preamble-reparse-warn-end-of-file.c:[[@LINE+5]]:14: error: expected '}'
end_comment

begin_comment
comment|// STDERR: preamble-reparse-warn-end-of-file.c:[[@LINE+4]]:14: error: expected '}'
end_comment

begin_include
include|#
directive|include
file|"header.h"
end_include

begin_function
name|void
name|test
parameter_list|()
block|{
end_function

end_unit

