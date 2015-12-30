begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that we use the Windows tokenizer for clang-cl response files. The
end_comment

begin_comment
comment|// trailing backslash before the space should be interpreted as a literal
end_comment

begin_comment
comment|// backslash. PR23709
end_comment

begin_comment
comment|// RUN: echo '/I%S\Inputs\cl-response-file\ /DFOO=2'> %t.rsp
end_comment

begin_comment
comment|// RUN: %clang_cl /c -### @%t.rsp -- %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-I" "{{.*}}\\Inputs\\cl-response-file\\" "-D" "FOO=2"
end_comment

end_unit

