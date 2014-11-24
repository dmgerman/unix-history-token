begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ast-dump %s | FileCheck %s
end_comment

begin_function_decl
name|void
name|variadic
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_floating_promotion
parameter_list|(
name|__fp16
modifier|*
name|f16
parameter_list|,
name|float
name|f32
parameter_list|,
name|double
name|f64
parameter_list|)
block|{
name|variadic
argument_list|(
literal|3
argument_list|,
operator|*
name|f16
argument_list|,
name|f32
argument_list|,
name|f64
argument_list|)
expr_stmt|;
comment|// CHECK: ImplicitCastExpr {{.*}} 'double'<FloatingCast>
comment|// CHECK-NEXT: '__fp16'
comment|// CHECK: ImplicitCastExpr {{.*}} 'double'<FloatingCast>
comment|// CHECK-NEXT: 'float'
block|}
end_function

end_unit

