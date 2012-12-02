begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that -E -M -MF does not cause an "argument unused" error, by adding
end_comment

begin_comment
comment|// -Werror to the clang invocation.  Also check the dependency output, if any.
end_comment

begin_comment
comment|// RUN: %clang -Werror -E -M -MF %t-M.d %s
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t-M.d %s
end_comment

begin_comment
comment|// CHECK: pr13851.o:
end_comment

begin_comment
comment|// CHECK: pr13851.c
end_comment

begin_comment
comment|// Check that -E -MM -MF does not cause an "argument unused" error, by adding
end_comment

begin_comment
comment|// -Werror to the clang invocation.  Also check the dependency output, if any.
end_comment

begin_comment
comment|// RUN: %clang -Werror -E -MM -MF %t-MM.d %s
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t-MM.d %s
end_comment

end_unit

