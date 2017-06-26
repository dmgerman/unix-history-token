begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -Wincompatible-pointer-types
end_comment

begin_decl_stmt
name|int
name|var
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'overloadable' attribute only applies to functions}}
end_comment

begin_function_decl
name|void
name|params
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
parameter_list|(
function_decl|12
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'overloadable' attribute takes no arguments}}
end_comment

begin_function_decl
name|int
modifier|*
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note 2{{previous overload of function is here}}
end_comment

begin_function_decl
name|float
modifier|*
name|f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{overloaded function 'f' must have the 'overloadable' attribute}}
end_comment

begin_function_decl
name|int
modifier|*
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{redeclaration of 'f' must have the 'overloadable' attribute}} \
end_comment

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_function_decl
name|double
modifier|*
name|f
parameter_list|(
name|double
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// okay, new
end_comment

begin_function
name|void
name|test_f
parameter_list|(
name|int
name|iv
parameter_list|,
name|float
name|fv
parameter_list|,
name|double
name|dv
parameter_list|)
block|{
name|int
modifier|*
name|ip
init|=
name|f
argument_list|(
name|iv
argument_list|)
decl_stmt|;
name|float
modifier|*
name|fp
init|=
name|f
argument_list|(
name|fv
argument_list|)
decl_stmt|;
name|double
modifier|*
name|dp
init|=
name|f
argument_list|(
name|dv
argument_list|)
decl_stmt|;
block|}
end_function

begin_function_decl
name|int
modifier|*
name|accept_funcptr
parameter_list|(
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|()
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//         \
end_comment

begin_comment
comment|// expected-note{{candidate function}}
end_comment

begin_function_decl
name|float
modifier|*
name|accept_funcptr
parameter_list|(
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|double
parameter_list|)
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//  \
end_comment

begin_comment
comment|// expected-note{{candidate function}}
end_comment

begin_function
name|void
name|test_funcptr
parameter_list|(
name|int
function_decl|(
modifier|*
name|f1
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|double
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
name|f2
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|float
parameter_list|)
parameter_list|)
block|{
name|float
modifier|*
name|fp
init|=
name|accept_funcptr
argument_list|(
name|f1
argument_list|)
decl_stmt|;
name|accept_funcptr
argument_list|(
name|f2
argument_list|)
expr_stmt|;
comment|// expected-error{{call to 'accept_funcptr' is ambiguous}}
block|}
end_function

begin_struct
struct|struct
name|X
block|{
name|int
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Y
block|{
name|int
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
modifier|*
name|accept_struct
parameter_list|(
name|struct
name|X
name|x
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__overloadable__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|float
modifier|*
name|accept_struct
parameter_list|(
name|struct
name|Y
name|y
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test_struct
parameter_list|(
name|struct
name|X
name|x
parameter_list|,
name|struct
name|Y
name|y
parameter_list|)
block|{
name|int
modifier|*
name|ip
init|=
name|accept_struct
argument_list|(
name|x
argument_list|)
decl_stmt|;
name|float
modifier|*
name|fp
init|=
name|accept_struct
argument_list|(
name|y
argument_list|)
decl_stmt|;
block|}
end_function

begin_function_decl
name|double
modifier|*
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{conflicting types for 'f'}}
end_comment

begin_function_decl
name|double
name|promote
parameter_list|(
name|float
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__overloadable__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{candidate}}
end_comment

begin_function_decl
name|double
name|promote
parameter_list|(
name|double
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__overloadable__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{candidate}}
end_comment

begin_function_decl
name|long
name|double
name|promote
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__overloadable__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{candidate}}
end_comment

begin_function_decl
name|void
name|promote
parameter_list|(
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__overloadable__
operator|,
function_decl|__unavailable__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// \
end_comment

begin_comment
comment|// expected-note{{candidate function}}
end_comment

begin_function
name|void
name|test_promote
parameter_list|(
name|short
modifier|*
name|sp
parameter_list|)
block|{
name|promote
argument_list|(
literal|1.0
argument_list|)
expr_stmt|;
name|promote
argument_list|(
name|sp
argument_list|)
expr_stmt|;
comment|// expected-error{{call to unavailable function 'promote'}}
block|}
end_function

begin_comment
comment|// PR6600
end_comment

begin_typedef
typedef|typedef
name|double
name|Double
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Double
name|DoubleVec
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|Int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Int
name|IntVec
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_function_decl
name|double
name|magnitude
parameter_list|(
name|DoubleVec
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__overloadable__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|double
name|magnitude
parameter_list|(
name|IntVec
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__overloadable__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|double
name|test_p6600
parameter_list|(
name|DoubleVec
name|d
parameter_list|)
block|{
return|return
name|magnitude
argument_list|(
name|d
argument_list|)
operator|*
name|magnitude
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// PR7738
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|f0
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'overloadable' function 'f0' must have a prototype}}
end_comment

begin_typedef
typedef|typedef
name|int
name|f1_type
parameter_list|()
function_decl|;
end_typedef

begin_decl_stmt
name|f1_type
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|f1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'overloadable' function 'f1' must have a prototype}}
end_comment

begin_function
name|void
name|test
parameter_list|()
block|{
name|f0
argument_list|()
expr_stmt|;
name|f1
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|before_local_1
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{here}}
end_comment

begin_function_decl
name|void
name|before_local_2
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{here}}
end_comment

begin_function_decl
name|void
name|before_local_3
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|local
parameter_list|()
block|{
name|void
name|before_local_1
argument_list|(
name|char
argument_list|)
decl_stmt|;
comment|// expected-error {{must have the 'overloadable' attribute}}
name|void
name|before_local_2
argument_list|(
name|char
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
comment|// expected-error {{conflicting types}}
name|void
name|before_local_3
argument_list|(
name|char
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|void
name|after_local_1
argument_list|(
name|char
argument_list|)
decl_stmt|;
comment|// expected-note {{here}}
name|void
name|after_local_2
argument_list|(
name|char
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
comment|// expected-note {{here}}
name|void
name|after_local_3
argument_list|(
name|char
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
block|}
end_function

begin_function_decl
name|void
name|after_local_1
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{conflicting types}}
end_comment

begin_function_decl
name|void
name|after_local_2
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{must have the 'overloadable' attribute}}
end_comment

begin_function_decl
name|void
name|after_local_3
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Make sure we allow C-specific conversions in C.
end_comment

begin_function
name|void
name|conversions
parameter_list|()
block|{
name|void
name|foo
argument_list|(
name|char
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|void
name|foo
argument_list|(
name|char
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|,
name|enable_if
argument_list|(
name|c
argument_list|,
literal|"nope.jpg"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
name|foo
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
name|void
name|multi_type
argument_list|(
name|unsigned
name|char
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|void
name|multi_type
argument_list|(
name|signed
name|char
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|unsigned
name|char
modifier|*
name|c
decl_stmt|;
name|multi_type
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Ensure that we allow C-specific type conversions in C
end_comment

begin_function
name|void
name|fn_type_conversions
parameter_list|()
block|{
name|void
name|foo
argument_list|(
name|void
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|void
name|foo
argument_list|(
name|char
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|void
function_decl|(
modifier|*
name|ptr1
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
init|=
operator|&
name|foo
function_decl|;
name|void
function_decl|(
modifier|*
name|ptr2
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
init|=
operator|&
name|foo
function_decl|;
name|void
function_decl|(
modifier|*
name|ambiguous
function_decl|)
parameter_list|(
name|int
modifier|*
parameter_list|)
init|=
operator|&
name|foo
function_decl|;
comment|// expected-error{{initializing 'void (*)(int *)' with an expression of incompatible type '<overloaded function type>'}} expected-note@-4{{candidate function}} expected-note@-3{{candidate function}}
name|void
modifier|*
name|vp_ambiguous
init|=
operator|&
name|foo
decl_stmt|;
comment|// expected-error{{initializing 'void *' with an expression of incompatible type '<overloaded function type>'}} expected-note@-5{{candidate function}} expected-note@-4{{candidate function}}
name|void
function_decl|(
modifier|*
name|specific1
function_decl|)
parameter_list|(
name|int
modifier|*
parameter_list|)
init|=
operator|(
name|void
argument_list|(
operator|*
argument_list|)
operator|(
name|void
operator|*
operator|)
operator|)
operator|&
name|foo
function_decl|;
comment|// expected-warning{{incompatible function pointer types initializing 'void (*)(int *)' with an expression of type 'void (*)(void *)'}}
name|void
modifier|*
name|specific2
init|=
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|)
operator|&
name|foo
decl_stmt|;
name|void
name|disabled
argument_list|(
name|void
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|,
name|enable_if
argument_list|(
literal|0
argument_list|,
literal|""
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|void
name|disabled
argument_list|(
name|int
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|,
name|enable_if
argument_list|(
name|c
argument_list|,
literal|""
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|void
name|disabled
argument_list|(
name|char
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|,
name|enable_if
argument_list|(
literal|1
argument_list|,
literal|"The function name lies."
argument_list|)
operator|)
argument_list|)
decl_stmt|;
comment|// To be clear, these should all point to the last overload of 'disabled'
name|void
function_decl|(
modifier|*
name|dptr1
function_decl|)
parameter_list|(
name|char
modifier|*
name|c
parameter_list|)
init|=
operator|&
name|disabled
function_decl|;
name|void
function_decl|(
modifier|*
name|dptr2
function_decl|)
parameter_list|(
name|void
modifier|*
name|c
parameter_list|)
init|=
operator|&
name|disabled
function_decl|;
comment|// expected-warning{{incompatible pointer types initializing 'void (*)(void *)' with an expression of type '<overloaded function type>'}} expected-note@-5{{candidate function made ineligible by enable_if}} expected-note@-4{{candidate function made ineligible by enable_if}} expected-note@-3{{candidate function has type mismatch at 1st parameter (expected 'void *' but has 'char *')}}
name|void
function_decl|(
modifier|*
name|dptr3
function_decl|)
parameter_list|(
name|int
modifier|*
name|c
parameter_list|)
init|=
operator|&
name|disabled
function_decl|;
comment|// expected-warning{{incompatible pointer types initializing 'void (*)(int *)' with an expression of type '<overloaded function type>'}} expected-note@-6{{candidate function made ineligible by enable_if}} expected-note@-5{{candidate function made ineligible by enable_if}} expected-note@-4{{candidate function has type mismatch at 1st parameter (expected 'int *' but has 'char *')}}
name|void
modifier|*
name|specific_disabled
init|=
operator|&
name|disabled
decl_stmt|;
block|}
end_function

begin_function
name|void
name|incompatible_pointer_type_conversions
parameter_list|()
block|{
name|char
name|charbuf
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|ucharbuf
index|[
literal|1
index|]
decl_stmt|;
name|int
name|intbuf
index|[
literal|1
index|]
decl_stmt|;
name|void
name|foo
argument_list|(
name|char
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|void
name|foo
argument_list|(
name|short
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|foo
argument_list|(
name|charbuf
argument_list|)
expr_stmt|;
name|foo
argument_list|(
name|ucharbuf
argument_list|)
expr_stmt|;
comment|// expected-error{{call to 'foo' is ambiguous}} expected-note@-3{{candidate function}} expected-note@-2{{candidate function}}
name|foo
argument_list|(
name|intbuf
argument_list|)
expr_stmt|;
comment|// expected-error{{call to 'foo' is ambiguous}} expected-note@-4{{candidate function}} expected-note@-3{{candidate function}}
name|void
name|bar
argument_list|(
name|unsigned
name|char
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|void
name|bar
argument_list|(
name|signed
name|char
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|bar
argument_list|(
name|charbuf
argument_list|)
expr_stmt|;
comment|// expected-error{{call to 'bar' is ambiguous}} expected-note@-2{{candidate function}} expected-note@-1{{candidate function}}
name|bar
argument_list|(
name|ucharbuf
argument_list|)
expr_stmt|;
name|bar
argument_list|(
name|intbuf
argument_list|)
expr_stmt|;
comment|// expected-error{{call to 'bar' is ambiguous}} expected-note@-4{{candidate function}} expected-note@-3{{candidate function}}
block|}
end_function

begin_function
name|void
name|dropping_qualifiers_is_incompatible
parameter_list|()
block|{
specifier|const
name|char
name|ccharbuf
index|[
literal|1
index|]
decl_stmt|;
specifier|volatile
name|char
name|vcharbuf
index|[
literal|1
index|]
decl_stmt|;
name|void
name|foo
argument_list|(
name|char
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|void
name|foo
argument_list|(
specifier|const
specifier|volatile
name|unsigned
name|char
operator|*
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|foo
argument_list|(
name|ccharbuf
argument_list|)
expr_stmt|;
comment|// expected-error{{call to 'foo' is ambiguous}} expected-note@-3{{candidate function}} expected-note@-2{{candidate function}}
name|foo
argument_list|(
name|vcharbuf
argument_list|)
expr_stmt|;
comment|// expected-error{{call to 'foo' is ambiguous}} expected-note@-4{{candidate function}} expected-note@-3{{candidate function}}
block|}
end_function

begin_comment
comment|// Bug: we used to treat `__typeof__(foo)` as though it was `__typeof__(&foo)`
end_comment

begin_comment
comment|// if `foo` was overloaded with only one function that could have its address
end_comment

begin_comment
comment|// taken.
end_comment

begin_function
name|void
name|typeof_function_is_not_a_pointer
parameter_list|()
block|{
name|void
name|not_a_pointer
argument_list|(
name|void
operator|*
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|void
name|not_a_pointer
argument_list|(
name|char
operator|*
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
decl_stmt|;
name|__typeof__
argument_list|(
name|not_a_pointer
argument_list|)
operator|*
name|fn
expr_stmt|;
name|void
name|take_fn
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
decl_stmt|;
comment|// if take_fn is passed a void (**)(void *), we'll get a warning.
name|take_fn
argument_list|(
name|fn
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

