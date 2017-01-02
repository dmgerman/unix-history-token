begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux -O1 -fblocks \
end_comment

begin_comment
comment|// RUN:   -fsanitize=cfi-icall -fsanitize-cfi-cross-dso \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: define void @f() {{.*}} !type !{{.*}} !type !{{.*}}
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
modifier|*
name|pf
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|f
function_decl|;
end_function_decl

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|// Check that we do not crash on non-FunctionDecl definitions.
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|g
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{}
function_decl|;
end_function_decl

end_unit

