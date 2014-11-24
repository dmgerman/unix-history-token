begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Make sure that arguments that begin with @ are left as is in the argument
end_comment

begin_comment
comment|// stream, and also that @file arguments continue to be processed.
end_comment

begin_comment
comment|// RUN: echo "%s -D FOO"> %t.args
end_comment

begin_comment
comment|// RUN: %clang -rpath @executable_path/../lib @%t.args -### 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-D" "FOO"
end_comment

begin_comment
comment|// CHECK: "-rpath" "@executable_path/../lib"
end_comment

end_unit

