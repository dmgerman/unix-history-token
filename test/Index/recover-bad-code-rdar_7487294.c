begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang-cc1 -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// IMPORTANT: This test case intentionally DOES NOT use --disable-free.  It
end_comment

begin_comment
comment|// tests that we are properly reclaiming the ASTs and we do not have a double free.
end_comment

begin_comment
comment|// Previously we tried to free the size expression of the VLA twice.
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|y
index|[
name|x
operator|*
literal|3
index|]
decl_stmt|;
name|help
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: 9:3: error: use of undeclared identifier 'help'
end_comment

begin_comment
comment|// CHECK:  help
end_comment

begin_comment
comment|// CHECK: 14:102: error: expected '}'
end_comment

end_unit

