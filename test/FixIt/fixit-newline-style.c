begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -pedantic -Wunused-label -x c %s 2>&1 | FileCheck %s -strict-whitespace
end_comment

begin_comment
comment|// This file intentionally uses a CRLF newline style
end_comment

begin_comment
comment|//<rdar://problem/12639047>
end_comment

begin_comment
comment|// CHECK: warning: unused label 'ddd'
end_comment

begin_comment
comment|// CHECK-NEXT: {{^  ddd:}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^  \^~~~$}}
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|ddd
label|:
empty_stmt|;
block|}
end_function

end_unit

