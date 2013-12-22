begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -O2 -fno-builtin -o - | FileCheck %s
end_comment

begin_comment
comment|// Check that -fno-builtin is honored.
end_comment

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: define void {{.*}}foo(
end_comment

begin_function
name|void
name|foo
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
comment|// CHECK: call {{.*}}printf
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

