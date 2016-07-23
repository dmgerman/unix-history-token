begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that the profiling counters and data we create have the linkage we expect
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name c-linkage.c %s -o - -emit-llvm -fprofile-instrument=clang | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @__profc_foo = private global
end_comment

begin_comment
comment|// CHECK: @__profd_foo = private global
end_comment

begin_comment
comment|// CHECK: @__profc_foo_weak = weak hidden global
end_comment

begin_comment
comment|// CHECK: @__profd_foo_weak = weak hidden global
end_comment

begin_comment
comment|// CHECK: @__profc_main = private global
end_comment

begin_comment
comment|// CHECK: @__profd_main = private global
end_comment

begin_comment
comment|// CHECK: @__profc_c_linkage.c_foo_internal = private global
end_comment

begin_comment
comment|// CHECK: @__profd_c_linkage.c_foo_internal = private global
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function_decl
name|void
name|foo_weak
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|foo_weak
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
literal|0
condition|)
block|{}
if|if
condition|(
literal|0
condition|)
block|{}
if|if
condition|(
literal|0
condition|)
block|{}
if|if
condition|(
literal|0
condition|)
block|{}
block|}
end_function

begin_function_decl
specifier|static
name|void
name|foo_internal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|foo
argument_list|()
expr_stmt|;
name|foo_internal
argument_list|()
expr_stmt|;
name|foo_weak
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|foo_internal
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
literal|0
condition|)
block|{}
if|if
condition|(
literal|0
condition|)
block|{}
block|}
end_function

end_unit

