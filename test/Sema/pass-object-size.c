begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -triple x86_64-linux-gnu -Wincompatible-pointer-types
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Tests for the pass_object_size attribute
end_comment

begin_comment
comment|// Non-failure cases are covered in test/CodeGen/pass-object-size.c
end_comment

begin_decl_stmt
name|void
name|a
argument_list|(
name|void
operator|*
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-error{{'pass_object_size' attribute takes one argument}}
end_comment

begin_decl_stmt
name|void
name|b
argument_list|(
name|void
operator|*
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|1.0
argument_list|)
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-error{{'pass_object_size' attribute requires parameter 1 to be an integer constant}}
end_comment

begin_decl_stmt
name|void
name|c
argument_list|(
name|void
operator|*
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-error{{'pass_object_size' attribute requires integer constant between 0 and 3 inclusive}}
end_comment

begin_decl_stmt
name|void
name|d
argument_list|(
name|void
operator|*
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
operator|-
literal|1
argument_list|)
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-error{{'pass_object_size' attribute requires integer constant between 0 and 3 inclusive}}
end_comment

begin_decl_stmt
name|void
name|e
argument_list|(
name|void
operator|*
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|1ULL
operator|<<
literal|32
argument_list|)
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-error{{integer constant expression evaluates to value 4294967296 that cannot be represented in a 32-bit unsigned integer type}}
end_comment

begin_decl_stmt
name|void
name|f
argument_list|(
name|char
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|0
argument_list|)
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-error{{'pass_object_size' attribute only applies to constant pointer arguments}}
end_comment

begin_decl_stmt
name|void
name|g
argument_list|(
specifier|const
name|char
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|0
argument_list|)
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-error{{'pass_object_size' attribute only applies to constant pointer arguments}}
end_comment

begin_decl_stmt
name|void
name|h
argument_list|(
name|char
operator|*
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|0
argument_list|)
operator|)
argument_list|)
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|//expected-error{{pass_object_size attribute only applies to constant pointer arguments}}
end_comment

begin_decl_stmt
name|void
name|i
argument_list|(
name|char
operator|*
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|0
argument_list|)
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// OK -- const is only necessary on definitions, not decls.
end_comment

begin_decl_stmt
name|void
name|j
argument_list|(
name|char
operator|*
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|0
argument_list|)
operator|,
name|pass_object_size
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-error{{'pass_object_size' attribute can only be applied once per parameter}}
end_comment

begin_define
define|#
directive|define
name|PS
parameter_list|(
name|N
parameter_list|)
value|__attribute__((pass_object_size(N)))
end_define

begin_define
define|#
directive|define
name|overloaded
value|__attribute__((overloadable))
end_define

begin_decl_stmt
name|void
name|Overloaded
argument_list|(
name|void
operator|*
name|p
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
name|overloaded
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-note{{previous declaration is here}}
end_comment

begin_decl_stmt
name|void
name|Overloaded
argument_list|(
name|void
operator|*
name|p
name|PS
argument_list|(
literal|1
argument_list|)
argument_list|)
name|overloaded
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-error{{conflicting pass_object_size attributes on parameters}}
end_comment

begin_decl_stmt
name|void
name|Overloaded2
argument_list|(
name|void
operator|*
name|p
name|PS
argument_list|(
literal|1
argument_list|)
argument_list|,
name|void
operator|*
name|p2
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
name|overloaded
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-note{{previous declaration is here}}
end_comment

begin_decl_stmt
name|void
name|Overloaded2
argument_list|(
name|void
operator|*
name|p
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|,
name|void
operator|*
name|p2
name|PS
argument_list|(
literal|1
argument_list|)
argument_list|)
name|overloaded
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-error{{conflicting pass_object_size attributes on parameters}}
end_comment

begin_decl_stmt
name|void
name|Overloaded3
argument_list|(
name|void
operator|*
name|p
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|,
name|void
operator|*
name|p2
argument_list|)
name|overloaded
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-note{{previous declaration is here}}
end_comment

begin_decl_stmt
name|void
name|Overloaded3
argument_list|(
name|void
operator|*
name|p
argument_list|,
name|void
operator|*
name|p2
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
name|overloaded
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-error{{conflicting pass_object_size attributes on parameters}}
end_comment

begin_function_decl
name|void
name|TakeFn
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|TakeFnOvl
argument_list|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
name|overloaded
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|TakeFnOvl
argument_list|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
operator|*
argument_list|)
argument_list|)
name|overloaded
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|NotOverloaded
argument_list|(
name|void
operator|*
name|p
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|IsOverloaded
argument_list|(
name|void
operator|*
name|p
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
name|overloaded
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|IsOverloaded
argument_list|(
name|char
operator|*
name|p
argument_list|)
name|overloaded
decl_stmt|;
end_decl_stmt

begin_comment
comment|// char* inestead of void* is intentional
end_comment

begin_function
name|void
name|FunctionPtrs
parameter_list|()
block|{
name|void
function_decl|(
modifier|*
name|p
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
init|=
name|NotOverloaded
function_decl|;
comment|//expected-error{{cannot take address of function 'NotOverloaded' because parameter 1 has pass_object_size attribute}}
name|void
function_decl|(
modifier|*
name|p2
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
init|=
operator|&
name|NotOverloaded
function_decl|;
comment|//expected-error{{cannot take address of function 'NotOverloaded' because parameter 1 has pass_object_size attribute}}
name|void
function_decl|(
modifier|*
name|p3
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
init|=
name|IsOverloaded
function_decl|;
comment|//expected-warning{{incompatible pointer types initializing 'void (*)(void *)' with an expression of type '<overloaded function type>'}} expected-note@-6{{candidate address cannot be taken because parameter 1 has pass_object_size attribute}} expected-note@-5{{type mismatch}}
name|void
function_decl|(
modifier|*
name|p4
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
init|=
operator|&
name|IsOverloaded
function_decl|;
comment|//expected-warning{{incompatible pointer types initializing 'void (*)(void *)' with an expression of type '<overloaded function type>'}} expected-note@-7{{candidate address cannot be taken because parameter 1 has pass_object_size attribute}} expected-note@-6{{type mismatch}}
name|void
function_decl|(
modifier|*
name|p5
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
init|=
name|IsOverloaded
function_decl|;
name|void
function_decl|(
modifier|*
name|p6
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
init|=
operator|&
name|IsOverloaded
function_decl|;
name|TakeFn
argument_list|(
name|NotOverloaded
argument_list|)
expr_stmt|;
comment|//expected-error{{cannot take address of function 'NotOverloaded' because parameter 1 has pass_object_size attribute}}
name|TakeFn
argument_list|(
operator|&
name|NotOverloaded
argument_list|)
expr_stmt|;
comment|//expected-error{{cannot take address of function 'NotOverloaded' because parameter 1 has pass_object_size attribute}}
name|TakeFnOvl
argument_list|(
name|NotOverloaded
argument_list|)
expr_stmt|;
comment|//expected-error{{cannot take address of function 'NotOverloaded' because parameter 1 has pass_object_size attribute}}
name|TakeFnOvl
argument_list|(
operator|&
name|NotOverloaded
argument_list|)
expr_stmt|;
comment|//expected-error{{cannot take address of function 'NotOverloaded' because parameter 1 has pass_object_size attribute}}
name|int
name|P
decl_stmt|;
call|(
modifier|&
name|NotOverloaded
call|)
argument_list|(
operator|&
name|P
argument_list|)
expr_stmt|;
comment|//expected-error{{cannot take address of function 'NotOverloaded' because parameter 1 has pass_object_size attribute}}
call|(
modifier|&
name|IsOverloaded
call|)
argument_list|(
operator|&
name|P
argument_list|)
expr_stmt|;
comment|//expected-warning{{incompatible pointer types passing 'int *' to parameter of type 'char *'}} expected-note@36{{passing argument to parameter 'p' here}}
block|}
end_function

end_unit

