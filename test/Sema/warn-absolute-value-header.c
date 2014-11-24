begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux-gnu -fsyntax-only -verify %s -Wabsolute-value
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux-gnu -fsyntax-only %s -Wabsolute-value -fdiagnostics-parseable-fixits 2>&1 | FileCheck %s
end_comment

begin_function_decl
name|int
name|abs
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Wrong signature
end_comment

begin_function_decl
name|int
name|fabsf
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning@-1{{incompatible redeclaration of library function 'fabsf'}}
end_comment

begin_comment
comment|// expected-note@-2{{'fabsf' is a builtin with type 'float (float)'}}
end_comment

begin_function
name|void
name|test_int
parameter_list|(
name|int
name|i
parameter_list|,
name|unsigned
name|u
parameter_list|,
name|long
name|long
name|ll
parameter_list|,
name|float
name|f
parameter_list|,
name|double
name|d
parameter_list|)
block|{
operator|(
name|void
operator|)
name|abs
argument_list|(
name|i
argument_list|)
expr_stmt|;
comment|// Remove abs call
operator|(
name|void
operator|)
name|abs
argument_list|(
name|u
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2{{remove the call to 'abs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:12}:""
name|int
name|llabs
decl_stmt|;
operator|(
name|void
operator|)
name|llabs
expr_stmt|;
comment|// Conflict in names, no notes
operator|(
name|void
operator|)
name|abs
argument_list|(
name|ll
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{absolute value function 'abs' given an argument of type 'long long' but has parameter of type 'int' which may cause truncation of value}}
comment|// Conflict in names, no notes
operator|(
name|void
operator|)
name|abs
argument_list|(
name|f
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{using integer absolute value function 'abs' when argument is of floating point type}}
comment|// Suggest header.
operator|(
name|void
operator|)
name|abs
argument_list|(
name|d
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{using integer absolute value function 'abs' when argument is of floating point type}}
comment|// expected-note@-2{{use function 'fabs' instead}}
comment|// expected-note@-3{{include the header<math.h> or explicitly provide a declaration for 'fabs'}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-4]]:9-[[@LINE-4]]:12}:"fabs"
block|}
end_function

end_unit

