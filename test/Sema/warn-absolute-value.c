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

begin_function_decl
name|long
name|int
name|labs
parameter_list|(
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|int
name|llabs
parameter_list|(
name|long
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|fabsf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|fabs
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|fabsl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|cabsf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|cabs
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|cabsl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_int
parameter_list|(
name|int
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabsf' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'abs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"abs"
operator|(
name|void
operator|)
name|fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabs' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'abs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"abs"
operator|(
name|void
operator|)
name|fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabsl' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'abs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"abs"
operator|(
name|void
operator|)
name|cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabsf' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'abs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"abs"
operator|(
name|void
operator|)
name|cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabs' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'abs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"abs"
operator|(
name|void
operator|)
name|cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabsl' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'abs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"abs"
operator|(
name|void
operator|)
name|__builtin_abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabsf' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_abs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_abs"
operator|(
name|void
operator|)
name|__builtin_fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabs' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_abs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_abs"
operator|(
name|void
operator|)
name|__builtin_fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabsl' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_abs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_abs"
operator|(
name|void
operator|)
name|__builtin_cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabsf' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_abs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_abs"
operator|(
name|void
operator|)
name|__builtin_cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabs' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_abs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_abs"
operator|(
name|void
operator|)
name|__builtin_cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabsl' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_abs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_abs"
block|}
end_function

begin_function
name|void
name|test_long
parameter_list|(
name|long
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// no warning - int and long are same length for this target
operator|(
name|void
operator|)
name|labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabsf' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'labs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"labs"
operator|(
name|void
operator|)
name|fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabs' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'labs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"labs"
operator|(
name|void
operator|)
name|fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabsl' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'labs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"labs"
operator|(
name|void
operator|)
name|cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabsf' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'labs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"labs"
operator|(
name|void
operator|)
name|cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabs' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'labs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"labs"
operator|(
name|void
operator|)
name|cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabsl' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'labs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"labs"
operator|(
name|void
operator|)
name|__builtin_abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// no warning - int and long are same length for
comment|// this target
operator|(
name|void
operator|)
name|__builtin_labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabsf' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_labs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_labs"
operator|(
name|void
operator|)
name|__builtin_fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabs' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_labs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_labs"
operator|(
name|void
operator|)
name|__builtin_fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabsl' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_labs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_labs"
operator|(
name|void
operator|)
name|__builtin_cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabsf' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_labs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_labs"
operator|(
name|void
operator|)
name|__builtin_cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabs' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_labs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_labs"
operator|(
name|void
operator|)
name|__builtin_cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabsl' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_labs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_labs"
block|}
end_function

begin_function
name|void
name|test_long_long
parameter_list|(
name|long
name|long
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{absolute value function 'abs' given an argument of type 'long long' but has parameter of type 'int' which may cause truncation of value}}
comment|// expected-note@-2{{use function 'llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:12}:"llabs"
operator|(
name|void
operator|)
name|labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{absolute value function 'labs' given an argument of type 'long long' but has parameter of type 'long' which may cause truncation of value}}
comment|// expected-note@-2{{use function 'llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"llabs"
operator|(
name|void
operator|)
name|llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabsf' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"llabs"
operator|(
name|void
operator|)
name|fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabs' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"llabs"
operator|(
name|void
operator|)
name|fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabsl' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"llabs"
operator|(
name|void
operator|)
name|cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabsf' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"llabs"
operator|(
name|void
operator|)
name|cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabs' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"llabs"
operator|(
name|void
operator|)
name|cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabsl' when argument is of integer type}}
comment|// expected-note@-2 {{use function 'llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"llabs"
operator|(
name|void
operator|)
name|__builtin_abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{absolute value function '__builtin_abs' given an argument of type 'long long' but has parameter of type 'int' which may cause truncation of value}}
comment|// expected-note@-2{{use function '__builtin_llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:22}:"__builtin_llabs"
operator|(
name|void
operator|)
name|__builtin_labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{absolute value function '__builtin_labs' given an argument of type 'long long' but has parameter of type 'long' which may cause truncation of value}}
comment|// expected-note@-2{{use function '__builtin_llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_llabs"
operator|(
name|void
operator|)
name|__builtin_llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabsf' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_llabs"
operator|(
name|void
operator|)
name|__builtin_fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabs' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_llabs"
operator|(
name|void
operator|)
name|__builtin_fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabsl' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_llabs"
operator|(
name|void
operator|)
name|__builtin_cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabsf' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_llabs"
operator|(
name|void
operator|)
name|__builtin_cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabs' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_llabs"
operator|(
name|void
operator|)
name|__builtin_cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabsl' when argument is of integer type}}
comment|// expected-note@-2 {{use function '__builtin_llabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_llabs"
block|}
end_function

begin_function
name|void
name|test_float
parameter_list|(
name|float
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'abs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:12}:"fabsf"
operator|(
name|void
operator|)
name|labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'labs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"fabsf"
operator|(
name|void
operator|)
name|llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'llabs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"fabsf"
operator|(
name|void
operator|)
name|fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabsf' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"fabsf"
operator|(
name|void
operator|)
name|cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"fabsf"
operator|(
name|void
operator|)
name|cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabsl' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"fabsf"
operator|(
name|void
operator|)
name|__builtin_abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_abs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:22}:"__builtin_fabsf"
operator|(
name|void
operator|)
name|__builtin_labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_labs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_fabsf"
operator|(
name|void
operator|)
name|__builtin_llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_llabs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_fabsf"
operator|(
name|void
operator|)
name|__builtin_fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabsf' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_fabsf"
operator|(
name|void
operator|)
name|__builtin_cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_fabsf"
operator|(
name|void
operator|)
name|__builtin_cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabsl' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_fabsf"
block|}
end_function

begin_function
name|void
name|test_double
parameter_list|(
name|double
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'abs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:12}:"fabs"
operator|(
name|void
operator|)
name|labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'labs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"fabs"
operator|(
name|void
operator|)
name|llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'llabs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"fabs"
operator|(
name|void
operator|)
name|fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{absolute value function 'fabsf' given an argument of type 'double' but has parameter of type 'float' which may cause truncation of value}}
comment|// expected-note@-2{{use function 'fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"fabs"
operator|(
name|void
operator|)
name|fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabsf' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"fabs"
operator|(
name|void
operator|)
name|cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"fabs"
operator|(
name|void
operator|)
name|cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabsl' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"fabs"
operator|(
name|void
operator|)
name|__builtin_abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_abs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:22}:"__builtin_fabs"
operator|(
name|void
operator|)
name|__builtin_labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_labs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_fabs"
operator|(
name|void
operator|)
name|__builtin_llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_llabs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_fabs"
operator|(
name|void
operator|)
name|__builtin_fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{absolute value function '__builtin_fabsf' given an argument of type 'double' but has parameter of type 'float' which may cause truncation of value}}
comment|// expected-note@-2{{use function '__builtin_fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_fabs"
operator|(
name|void
operator|)
name|__builtin_fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabsf' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_fabs"
operator|(
name|void
operator|)
name|__builtin_cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_fabs"
operator|(
name|void
operator|)
name|__builtin_cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabsl' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_fabs"
block|}
end_function

begin_function
name|void
name|test_long_double
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'abs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:12}:"fabsl"
operator|(
name|void
operator|)
name|labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'labs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"fabsl"
operator|(
name|void
operator|)
name|llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'llabs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"fabsl"
operator|(
name|void
operator|)
name|fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{absolute value function 'fabsf' given an argument of type 'long double' but has parameter of type 'float' which may cause truncation of value}}
comment|// expected-note@-2{{use function 'fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"fabsl"
operator|(
name|void
operator|)
name|fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{absolute value function 'fabs' given an argument of type 'long double' but has parameter of type 'double' which may cause truncation of value}}
comment|// expected-note@-2{{use function 'fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"fabsl"
operator|(
name|void
operator|)
name|fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabsf' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"fabsl"
operator|(
name|void
operator|)
name|cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"fabsl"
operator|(
name|void
operator|)
name|cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function 'cabsl' when argument is of floating point type}}
comment|// expected-note@-2 {{use function 'fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"fabsl"
operator|(
name|void
operator|)
name|__builtin_abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_abs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:22}:"__builtin_fabsl"
operator|(
name|void
operator|)
name|__builtin_labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_labs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_fabsl"
operator|(
name|void
operator|)
name|__builtin_llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_llabs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_fabsl"
operator|(
name|void
operator|)
name|__builtin_fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{absolute value function '__builtin_fabsf' given an argument of type 'long double' but has parameter of type 'float' which may cause truncation of value}}
comment|// expected-note@-2{{use function '__builtin_fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_fabsl"
operator|(
name|void
operator|)
name|__builtin_fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1{{absolute value function '__builtin_fabs' given an argument of type 'long double' but has parameter of type 'double' which may cause truncation of value}}
comment|// expected-note@-2{{use function '__builtin_fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_fabsl"
operator|(
name|void
operator|)
name|__builtin_fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabsf' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_fabsl"
operator|(
name|void
operator|)
name|__builtin_cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabs' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_fabsl"
operator|(
name|void
operator|)
name|__builtin_cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using complex absolute value function '__builtin_cabsl' when argument is of floating point type}}
comment|// expected-note@-2 {{use function '__builtin_fabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_fabsl"
block|}
end_function

begin_function
name|void
name|test_complex_float
parameter_list|(
specifier|_Complex
name|float
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'abs' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:12}:"cabsf"
operator|(
name|void
operator|)
name|labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'labs' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"cabsf"
operator|(
name|void
operator|)
name|llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'llabs' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"cabsf"
operator|(
name|void
operator|)
name|fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabsf' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"cabsf"
operator|(
name|void
operator|)
name|fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabs' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"cabsf"
operator|(
name|void
operator|)
name|fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabsl' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"cabsf"
operator|(
name|void
operator|)
name|cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_abs' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:22}:"__builtin_cabsf"
operator|(
name|void
operator|)
name|__builtin_labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_labs' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_cabsf"
operator|(
name|void
operator|)
name|__builtin_llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_llabs' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_cabsf"
operator|(
name|void
operator|)
name|__builtin_fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabsf' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_cabsf"
operator|(
name|void
operator|)
name|__builtin_fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabs' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_cabsf"
operator|(
name|void
operator|)
name|__builtin_fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabsl' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabsf' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_cabsf"
operator|(
name|void
operator|)
name|__builtin_cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_complex_double
parameter_list|(
specifier|_Complex
name|double
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'abs' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:12}:"cabs"
operator|(
name|void
operator|)
name|labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'labs' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"cabs"
operator|(
name|void
operator|)
name|llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'llabs' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"cabs"
operator|(
name|void
operator|)
name|fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabsf' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"cabs"
operator|(
name|void
operator|)
name|fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabs' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"cabs"
operator|(
name|void
operator|)
name|fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabsl' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"cabs"
operator|(
name|void
operator|)
name|cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{absolute value function 'cabsf' given an argument of type '_Complex double' but has parameter of type '_Complex float' which may cause truncation of value}}
comment|// expected-note@-2 {{use function 'cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"cabs"
operator|(
name|void
operator|)
name|cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_abs' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:22}:"__builtin_cabs"
operator|(
name|void
operator|)
name|__builtin_labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_labs' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_cabs"
operator|(
name|void
operator|)
name|__builtin_llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_llabs' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_cabs"
operator|(
name|void
operator|)
name|__builtin_fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabsf' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_cabs"
operator|(
name|void
operator|)
name|__builtin_fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabs' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_cabs"
operator|(
name|void
operator|)
name|__builtin_fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabsl' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_cabs"
operator|(
name|void
operator|)
name|__builtin_cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{absolute value function '__builtin_cabsf' given an argument of type '_Complex double' but has parameter of type '_Complex float' which may cause truncation of value}}
comment|// expected-note@-2 {{use function '__builtin_cabs' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_cabs"
operator|(
name|void
operator|)
name|__builtin_cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_complex_long_double
parameter_list|(
specifier|_Complex
name|long
name|double
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'abs' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:12}:"cabsl"
operator|(
name|void
operator|)
name|labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'labs' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"cabsl"
operator|(
name|void
operator|)
name|llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function 'llabs' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"cabsl"
operator|(
name|void
operator|)
name|fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabsf' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"cabsl"
operator|(
name|void
operator|)
name|fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabs' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"cabsl"
operator|(
name|void
operator|)
name|fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function 'fabsl' when argument is of complex type}}
comment|// expected-note@-2 {{use function 'cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"cabsl"
operator|(
name|void
operator|)
name|cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{absolute value function 'cabsf' given an argument of type '_Complex long double' but has parameter of type '_Complex float' which may cause truncation of value}}
comment|// expected-note@-2 {{use function 'cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:"cabsl"
operator|(
name|void
operator|)
name|cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{absolute value function 'cabs' given an argument of type '_Complex long double' but has parameter of type '_Complex double' which may cause truncation of value}}
comment|// expected-note@-2 {{use function 'cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:"cabsl"
operator|(
name|void
operator|)
name|cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_abs' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:22}:"__builtin_cabsl"
operator|(
name|void
operator|)
name|__builtin_labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_labs' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_cabsl"
operator|(
name|void
operator|)
name|__builtin_llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using integer absolute value function '__builtin_llabs' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_cabsl"
operator|(
name|void
operator|)
name|__builtin_fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabsf' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_cabsl"
operator|(
name|void
operator|)
name|__builtin_fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabs' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_cabsl"
operator|(
name|void
operator|)
name|__builtin_fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{using floating point absolute value function '__builtin_fabsl' when argument is of complex type}}
comment|// expected-note@-2 {{use function '__builtin_cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_cabsl"
operator|(
name|void
operator|)
name|__builtin_cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{absolute value function '__builtin_cabsf' given an argument of type '_Complex long double' but has parameter of type '_Complex float' which may cause truncation of value}}
comment|// expected-note@-2 {{use function '__builtin_cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:"__builtin_cabsl"
operator|(
name|void
operator|)
name|__builtin_cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{absolute value function '__builtin_cabs' given an argument of type '_Complex long double' but has parameter of type '_Complex double' which may cause truncation of value}}
comment|// expected-note@-2 {{use function '__builtin_cabsl' instead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:"__builtin_cabsl"
operator|(
name|void
operator|)
name|__builtin_cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_unsigned_int
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to 'abs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:12}:""
operator|(
name|void
operator|)
name|labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to 'labs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:""
operator|(
name|void
operator|)
name|llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to 'llabs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:""
operator|(
name|void
operator|)
name|fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to 'fabsf' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:""
operator|(
name|void
operator|)
name|fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to 'fabs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:""
operator|(
name|void
operator|)
name|fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to 'fabsl' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:""
operator|(
name|void
operator|)
name|cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to 'cabsf' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:""
operator|(
name|void
operator|)
name|cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to 'cabs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:""
operator|(
name|void
operator|)
name|cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to 'cabsl' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:""
operator|(
name|void
operator|)
name|__builtin_abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_abs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:22}:""
operator|(
name|void
operator|)
name|__builtin_labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_labs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:""
operator|(
name|void
operator|)
name|__builtin_llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_llabs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:""
operator|(
name|void
operator|)
name|__builtin_fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_fabsf' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:""
operator|(
name|void
operator|)
name|__builtin_fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_fabs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:""
operator|(
name|void
operator|)
name|__builtin_fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_fabsl' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:""
operator|(
name|void
operator|)
name|__builtin_cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_cabsf' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:""
operator|(
name|void
operator|)
name|__builtin_cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_cabs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:""
operator|(
name|void
operator|)
name|__builtin_cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned int' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_cabsl' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:""
block|}
end_function

begin_function
name|void
name|test_unsigned_long
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to 'abs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:12}:""
operator|(
name|void
operator|)
name|labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to 'labs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:""
operator|(
name|void
operator|)
name|llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to 'llabs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:""
operator|(
name|void
operator|)
name|fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to 'fabsf' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:""
operator|(
name|void
operator|)
name|fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to 'fabs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:""
operator|(
name|void
operator|)
name|fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to 'fabsl' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:""
operator|(
name|void
operator|)
name|cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to 'cabsf' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:""
operator|(
name|void
operator|)
name|cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to 'cabs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:13}:""
operator|(
name|void
operator|)
name|cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to 'cabsl' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:14}:""
operator|(
name|void
operator|)
name|__builtin_abs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_abs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:22}:""
operator|(
name|void
operator|)
name|__builtin_labs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_labs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:""
operator|(
name|void
operator|)
name|__builtin_llabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_llabs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:""
operator|(
name|void
operator|)
name|__builtin_fabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_fabsf' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:""
operator|(
name|void
operator|)
name|__builtin_fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_fabs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:""
operator|(
name|void
operator|)
name|__builtin_fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_fabsl' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:""
operator|(
name|void
operator|)
name|__builtin_cabsf
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_cabsf' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:""
operator|(
name|void
operator|)
name|__builtin_cabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_cabs' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:23}:""
operator|(
name|void
operator|)
name|__builtin_cabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning@-1 {{taking the absolute value of unsigned type 'unsigned long' has no effect}}
comment|// expected-note@-2 {{remove the call to '__builtin_cabsl' since unsigned values cannot be negative}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:9-[[@LINE-3]]:24}:""
block|}
end_function

end_unit

