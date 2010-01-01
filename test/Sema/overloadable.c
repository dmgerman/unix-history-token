begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
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
comment|// expected-error{{'overloadable' attribute can only be applied to a function}}
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
comment|// expected-error{{no matching function for call to 'accept_funcptr'; candidates are:}}
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

begin_function_decl
name|void
name|promote
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(__overloadable__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{'overloadable' function 'promote' must have a prototype}}
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

end_unit

