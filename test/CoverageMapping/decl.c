begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Ensure that declarations without definitions don't have maps emitted for them
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only %s> %t
end_comment

begin_comment
comment|// FileCheck -input-file %t %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix BAR -input-file %t %s
end_comment

begin_comment
comment|// FOO: foo:
end_comment

begin_comment
comment|// FOO-NOT: foo:
end_comment

begin_function
specifier|inline
name|int
name|foo
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
specifier|extern
specifier|inline
name|int
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// BAR: bar:
end_comment

begin_comment
comment|// BAR-NOT: bar:
end_comment

begin_function
name|int
name|bar
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|int
name|bar
parameter_list|()
function_decl|;
end_function_decl

end_unit

