begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ast-dump %s | FileCheck %s
end_comment

begin_function_decl
name|void
name|foo1
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|foo2
parameter_list|(
name|void
modifier|*
specifier|const
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|bar
parameter_list|()
block|{
comment|// CHECK:  FunctionDecl {{.*}}<line:{{.*}}, line:{{.*}}> line:{{.*}} bar 'void ()'
name|foo1
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: ImplicitCastExpr {{.*}}<col:{{.*}}> 'void *'<NullToPointer>
name|foo2
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: ImplicitCastExpr {{.*}}<col:{{.*}}> 'void *'<NullToPointer>
block|}
end_function

end_unit

