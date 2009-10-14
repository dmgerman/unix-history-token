begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -verify -pedantic -fsyntax-only -fblocks=0
end_comment

begin_comment
comment|// PR1966
end_comment

begin_function
specifier|_Complex
name|double
name|test1
parameter_list|()
block|{
return|return
name|__extension__
literal|1.0if
return|;
block|}
end_function

begin_function
specifier|_Complex
name|double
name|test2
parameter_list|()
block|{
return|return
literal|1.0if
return|;
comment|// expected-warning {{imaginary constants are an extension}}
block|}
end_function

begin_comment
comment|// rdar://6097308
end_comment

begin_function
name|void
name|test3
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
operator|(
name|__extension__
name|x
operator|)
operator|=
literal|10
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://6162726
end_comment

begin_function
name|void
name|test4
parameter_list|()
block|{
specifier|static
name|int
name|var
decl_stmt|;
name|var
operator|=
operator|+
literal|5
expr_stmt|;
comment|// expected-warning {{use of unary operator that may be intended as compound assignment (+=)}}
name|var
operator|=
operator|-
literal|5
expr_stmt|;
comment|// expected-warning {{use of unary operator that may be intended as compound assignment (-=)}}
name|var
operator|=
operator|+
literal|5
expr_stmt|;
comment|// no warning when space between the = and +.
name|var
operator|=
operator|-
literal|5
expr_stmt|;
name|var
operator|=
operator|+
literal|5
expr_stmt|;
comment|// no warning when the subexpr of the unary op has no space before it.
name|var
operator|=
operator|-
literal|5
expr_stmt|;
define|#
directive|define
name|FIVE
value|5
name|var
operator|=
operator|-
name|FIVE
expr_stmt|;
comment|// no warning with macros.
name|var
operator|=
operator|-
name|FIVE
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://6319320
end_comment

begin_function
name|void
name|test5
parameter_list|(
name|int
modifier|*
name|X
parameter_list|,
name|float
modifier|*
name|P
parameter_list|)
block|{
operator|(
name|float
operator|*
operator|)
name|X
operator|=
name|P
expr_stmt|;
comment|// expected-error {{assignment to cast is illegal, lvalue casts are not supported}}
define|#
directive|define
name|FOO
value|((float*) X)
name|FOO
operator|=
name|P
expr_stmt|;
comment|// expected-error {{assignment to cast is illegal, lvalue casts are not supported}}
block|}
end_function

begin_function
name|void
name|test6
parameter_list|()
block|{
name|int
name|X
decl_stmt|;
name|X
argument_list|()
expr_stmt|;
comment|// expected-error {{called object type 'int' is not a function or function pointer}}
block|}
end_function

begin_function
name|void
name|test7
parameter_list|(
name|int
modifier|*
name|P
parameter_list|,
specifier|_Complex
name|float
name|Gamma
parameter_list|)
block|{
name|P
operator|=
operator|(
name|P
operator|-
literal|42
operator|)
operator|+
name|Gamma
operator|*
literal|4
expr_stmt|;
comment|// expected-error {{invalid operands to binary expression ('int *' and '_Complex float')}}
block|}
end_function

begin_comment
comment|// rdar://6095061
end_comment

begin_function
name|int
name|test8
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|__builtin_choose_expr
argument_list|(
literal|0
argument_list|,
literal|42
argument_list|,
name|i
argument_list|)
operator|=
literal|10
expr_stmt|;
return|return
name|i
return|;
block|}
end_function

begin_comment
comment|// PR3386
end_comment

begin_struct
struct|struct
name|f
block|{
name|int
name|x
range|:
literal|4
decl_stmt|;
name|float
name|y
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|test9
parameter_list|(
name|struct
name|f
modifier|*
name|P
parameter_list|)
block|{
name|int
name|R
decl_stmt|;
name|R
operator|=
name|__alignof
argument_list|(
name|P
operator|->
name|x
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid application of '__alignof' to bit-field}}
name|R
operator|=
name|__alignof
argument_list|(
name|P
operator|->
name|y
argument_list|)
expr_stmt|;
comment|// ok.
name|R
operator|=
sizeof|sizeof
argument_list|(
name|P
operator|->
name|x
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid application of 'sizeof' to bit-field}}
return|return
name|R
return|;
block|}
end_function

begin_comment
comment|// PR3562
end_comment

begin_function
name|void
name|test10
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
struct|struct
name|S
block|{
name|double
name|a
index|[
name|n
index|]
decl_stmt|;
comment|// expected-error {{fields must have a constant size}}
block|}
name|s
struct|;
name|double
name|x
init|=
name|s
operator|.
name|a
index|[
literal|0
index|]
decl_stmt|;
comment|// should not get another error here.
block|}
end_function

begin_define
define|#
directive|define
name|MYMAX
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|__extension__ ({ __typeof__(A) __a = (A); __typeof__(B) __b = (B); __a< __b ? __b : __a; })
end_define

begin_struct
struct|struct
name|mystruct
block|{
name|int
name|A
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test11
parameter_list|(
name|struct
name|mystruct
name|P
parameter_list|,
name|float
name|F
parameter_list|)
block|{
name|MYMAX
argument_list|(
name|P
argument_list|,
name|F
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid operands to binary expression ('typeof (P)' (aka 'struct mystruct') and 'typeof (F)' (aka 'float'))}}
block|}
end_function

begin_comment
comment|// PR3753
end_comment

begin_function
name|int
name|test12
parameter_list|(
specifier|const
name|char
modifier|*
name|X
parameter_list|)
block|{
return|return
name|X
operator|==
literal|"foo"
return|;
comment|// expected-warning {{comparison against a string literal is unspecified}}
block|}
end_function

begin_comment
comment|// rdar://6719156
end_comment

begin_function
name|void
name|test13
parameter_list|(
name|void
function_decl|(
modifier|^
name|P
function_decl|)
parameter_list|()
parameter_list|)
block|{
comment|// expected-error {{blocks support disabled - compile with -fblocks}}
name|P
argument_list|()
expr_stmt|;
name|P
operator|=
lambda|^
parameter_list|()
block|{}
expr_stmt|;
comment|// expected-error {{blocks support disabled - compile with -fblocks}}
block|}
end_function

begin_function
name|void
name|test14
parameter_list|()
block|{
typedef|typedef
name|long
name|long
name|__m64
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
typedef|typedef
name|short
name|__v4hi
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
comment|// Ok.
name|__v4hi
name|a
decl_stmt|;
name|__m64
name|mask
init|=
call|(
name|__m64
call|)
argument_list|(
operator|(
name|__v4hi
operator|)
name|a
operator|>
operator|(
name|__v4hi
operator|)
name|a
argument_list|)
decl_stmt|;
block|}
end_function

end_unit

