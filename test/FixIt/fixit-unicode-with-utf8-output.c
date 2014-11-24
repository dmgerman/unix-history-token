begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This test is an additional set of checks for the fixit-unicode.c test for
end_comment

begin_comment
comment|// systems capable of outputting Unicode characters to the standard output in
end_comment

begin_comment
comment|// the UTF-8 encoding.
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only %S/fixit-unicode.c 2>&1 | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// REQUIRES: utf8-capable-terminal
end_comment

begin_comment
comment|// CHECK: warning: format specifies type 'int' but the argument has type 'long'
end_comment

begin_comment
comment|// CHECK: {{^  printf\("â: %d", 1L\);}}
end_comment

begin_comment
comment|// CHECK: {{^             ~~   \^~}}
end_comment

begin_comment
comment|// CHECK: error: use of undeclared identifier 'à¸sss'; did you mean 'à¸ssss'?
end_comment

begin_comment
comment|// CHECK: {{^          \^}}
end_comment

begin_comment
comment|// CHECK: {{^          à¸ssss}}
end_comment

begin_comment
comment|// CHECK: error: use of undeclared identifier 'ssà¸s'; did you mean 'ssà¸ss'?
end_comment

begin_comment
comment|// CHECK: {{^          \^}}
end_comment

begin_comment
comment|// CHECK: {{^          ssà¸ss}}
end_comment

begin_comment
comment|// CHECK: error: use of undeclared identifier 'ssä¸äºä¸'; did you mean 'sä¸äºä¸'?
end_comment

begin_comment
comment|// CHECK: {{^                        \^~~~~~~~}}
end_comment

begin_comment
comment|// CHECK: {{^                        sä¸äºä¸}}
end_comment

begin_comment
comment|// CHECK: error: use of undeclared identifier 'sssssssss'; did you mean 'sssssssssà¸'?
end_comment

begin_comment
comment|// CHECK: {{^          \^}}
end_comment

begin_comment
comment|// CHECK: {{^          sssssssssà¸}}
end_comment

end_unit

