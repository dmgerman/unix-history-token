begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that -Werror and -Wfatal-error interact properly.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Verify mode doesn't work with fatal errors, just use FileCheck here.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -Wunused-function -Werror -Wfatal-errors %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck< %t.err %s
end_comment

begin_comment
comment|// CHECK: fatal error: unused function
end_comment

begin_comment
comment|// CHECK: 1 error generated
end_comment

begin_function
specifier|static
name|void
name|f0
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-fatal {{unused function}}
end_comment

end_unit

