begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// PR6433 - Don't crash on va_arg(typedef).
end_comment

begin_typedef
typedef|typedef
name|double
name|gdouble
typedef|;
end_typedef

begin_function
name|void
name|focus_changed_cb
parameter_list|()
block|{
name|__builtin_va_list
name|pa
decl_stmt|;
name|double
name|mfloat
decl_stmt|;
name|mfloat
operator|=
name|__builtin_va_arg
argument_list|(
operator|(
name|pa
operator|)
argument_list|,
name|gdouble
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|vararg
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|function_as_vararg
parameter_list|()
block|{
comment|// CHECK: define {{.*}}function_as_vararg
comment|// CHECK-NOT: llvm.trap
name|vararg
argument_list|(
literal|0
argument_list|,
name|focus_changed_cb
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

