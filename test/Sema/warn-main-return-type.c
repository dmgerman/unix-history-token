begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fdiagnostics-parseable-fixits -x c++ %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// expected-note@+1 5{{previous definition is here}}
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-error@+3 {{conflicting types for 'main}}
end_comment

begin_comment
comment|// expected-warning@+2 {{return type of 'main' is not 'int'}}
end_comment

begin_comment
comment|// expected-note@+1 {{change return type to 'int'}}
end_comment

begin_function
name|void
name|main
parameter_list|()
block|{
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:1-[[@LINE-1]]:5}:"int"
block|}
end_function

begin_comment
comment|// expected-error@+3 {{conflicting types for 'main}}
end_comment

begin_comment
comment|// expected-warning@+2 {{return type of 'main' is not 'int'}}
end_comment

begin_comment
comment|// expected-note@+1 {{change return type to 'int'}}
end_comment

begin_function
name|double
name|main
parameter_list|()
block|{
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:1-[[@LINE-1]]:7}:"int"
return|return
literal|0.0
return|;
block|}
end_function

begin_comment
comment|// TODO: Store qualifier source locations for return types so
end_comment

begin_comment
comment|// we can replace the full type with this fix-it.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// expected-error@+3 {{conflicting types for 'main}}
end_comment

begin_comment
comment|// expected-warning@+2 {{return type of 'main' is not 'int'}}
end_comment

begin_comment
comment|// expected-note@+1 {{change return type to 'int'}}
end_comment

begin_function
specifier|const
name|float
name|main
parameter_list|()
block|{
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:7-[[@LINE-1]]:12}:"int"
return|return
literal|0.0f
return|;
block|}
end_function

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// expected-error@+3 {{conflicting types for 'main}}
end_comment

begin_comment
comment|// expected-warning@+2 {{return type of 'main' is not 'int'}}
end_comment

begin_comment
comment|// expected-note@+1 {{change return type to 'int'}}
end_comment

begin_function
name|fptr
name|main
parameter_list|()
block|{
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:1-[[@LINE-1]]:5}:"int"
return|return
operator|(
name|fptr
operator|)
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-error@+2 {{conflicting types for 'main}}
end_comment

begin_comment
comment|// expected-warning@+1 {{return type of 'main' is not 'int'}}
end_comment

begin_macro
name|void
end_macro

begin_expr_stmt
operator|*
operator|(
operator|*
name|main
argument_list|()
operator|)
operator|(
name|int
name|a
operator|)
block|{
return|return
operator|(
name|fptr
operator|)
literal|0
return|;
block|}
end_expr_stmt

end_unit

