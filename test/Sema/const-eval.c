begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_define
define|#
directive|define
name|EVAL_EXPR
parameter_list|(
name|testno
parameter_list|,
name|expr
parameter_list|)
value|int test##testno = sizeof(struct{char qq[expr];});
end_define

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_macro
name|EVAL_EXPR
argument_list|(
literal|1
argument_list|,
argument|(_Bool)&x
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|2
argument_list|,
argument|(int)(
literal|1.0
argument|+(double)
literal|4
argument|)
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|3
argument_list|,
argument|(int)(
literal|1.0
argument|+(float)
literal|4.0
argument|)
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|4
argument_list|,
argument|(_Bool)(
literal|1
argument|? (void*)&x :
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|5
argument_list|,
argument|(_Bool)(int[]){
literal|0
argument|}
argument_list|)
end_macro

begin_struct
struct|struct
name|y
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|EVAL_EXPR
argument_list|(
literal|6
argument_list|,
argument|(int)(
literal|1
argument|+(struct y*)
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|7
argument_list|,
argument|(int)&((struct y*)
literal|0
argument|)->y
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|8
argument_list|,
argument|(_Bool)
literal|"asdf"
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|9
argument_list|,
argument|!!&x
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|10
argument_list|,
argument|((void)
literal|1
argument|,
literal|12
argument|)
argument_list|)
end_macro

begin_function_decl
name|void
name|g0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|EVAL_EXPR
argument_list|(
literal|11
argument_list|,
argument|(g0(),
literal|12
argument|)
argument_list|)
end_macro

begin_comment
comment|// FIXME: This should give an error
end_comment

begin_macro
name|EVAL_EXPR
argument_list|(
literal|12
argument_list|,
literal|1.0
argument|&&
literal|2.0
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|13
argument_list|,
argument|x ||
literal|3.0
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|int
name|l_19
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|EVAL_EXPR
argument_list|(
literal|14
argument_list|,
operator|(
literal|1
operator|^
name|l_19
operator|)
operator|&&
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{fields must have a constant size}}
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|int
name|a
decl_stmt|;
name|EVAL_EXPR
argument_list|(
literal|15
argument_list|,
operator|(
name|_Bool
operator|)
operator|&
name|a
argument_list|)
expr_stmt|;
comment|// expected-error {{fields must have a constant size}}
block|}
end_function

begin_comment
comment|// FIXME: Turn into EVAL_EXPR test once we have more folding.
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|g16
init|=
operator|(
literal|1.0f
operator|+
literal|1.0fi
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ?: in constant expressions.
end_comment

begin_decl_stmt
name|int
name|g17
index|[
operator|(
literal|3
condition|?
else|:
literal|1
operator|)
operator|-
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|EVAL_EXPR
argument_list|(
literal|18
argument_list|,
operator|(
call|(
name|int
call|)
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|10
operator|+
literal|10
argument_list|)
operator|)
operator|==
literal|20
condition|?
literal|1
else|:
operator|-
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|s
block|{
name|int
name|a
index|[
operator|(
name|int
operator|)
operator|-
literal|1.0f
index|]
decl_stmt|;
comment|// expected-error {{array size is negative}}
block|}
struct|;
end_struct

begin_expr_stmt
name|EVAL_EXPR
argument_list|(
literal|19
argument_list|,
operator|(
operator|(
name|int
operator|)
operator|&
operator|*
operator|(
name|char
operator|*
operator|)
literal|10
operator|==
literal|10
condition|?
literal|1
else|:
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVAL_EXPR
argument_list|(
literal|20
argument_list|,
name|__builtin_constant_p
argument_list|(
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
literal|10
operator|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVAL_EXPR
argument_list|(
literal|21
argument_list|,
operator|(
name|__imag__
literal|2i
operator|)
operator|==
literal|2
condition|?
literal|1
else|:
operator|-
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVAL_EXPR
argument_list|(
literal|22
argument_list|,
operator|(
name|__real__
argument_list|(
literal|2i+3
argument_list|)
operator|)
operator|==
literal|3
condition|?
literal|1
else|:
operator|-
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|g23
index|[
call|(
name|int
call|)
argument_list|(
literal|1.0
operator|/
literal|1.0
argument_list|)
index|]
init|=
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g24
index|[
call|(
name|int
call|)
argument_list|(
literal|1.0
operator|/
literal|1.0
argument_list|)
index|]
init|=
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{excess elements in array initializer}}
end_comment

begin_decl_stmt
name|int
name|g25
index|[
call|(
name|int
call|)
argument_list|(
literal|1.0
operator|+
literal|1.0
argument_list|)
index|]
decl_stmt|,
name|g26
init|=
sizeof|sizeof
argument_list|(
name|g25
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|EVAL_EXPR
argument_list|(
literal|26
argument_list|,
argument|(_Complex double)
literal|0
argument|? -
literal|1
argument|:
literal|1
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|27
argument_list|,
argument|(_Complex int)
literal|0
argument|? -
literal|1
argument|:
literal|1
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|28
argument_list|,
argument|(_Complex double)
literal|1
argument|?
literal|1
argument|: -
literal|1
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|29
argument_list|,
argument|(_Complex int)
literal|1
argument|?
literal|1
argument|: -
literal|1
argument_list|)
end_macro

begin_comment
comment|// PR4027 + rdar://6808859
end_comment

begin_struct
struct|struct
name|a
block|{
name|int
name|x
decl_stmt|,
name|y
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|a
name|V2
init|=
operator|(
expr|struct
name|a
operator|)
operator|(
expr|struct
name|a
operator|)
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|a
name|V1
init|=
operator|(
expr|struct
name|a
operator|)
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|EVAL_EXPR
argument_list|(
literal|30
argument_list|,
argument|(int)(_Complex float)((
literal|1
argument|<<
literal|30
argument|)-
literal|1
argument|) == (
literal|1
argument|<<
literal|30
argument|) ?
literal|1
argument|: -
literal|1
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|31
argument_list|,
argument|(int*)
literal|0
argument|== (int*)
literal|0
argument|?
literal|1
argument|: -
literal|1
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|32
argument_list|,
argument|(int*)
literal|0
argument|!= (int*)
literal|0
argument|? -
literal|1
argument|:
literal|1
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|33
argument_list|,
argument|(void*)
literal|0
argument|- (void*)
literal|0
argument|==
literal|0
argument|?
literal|1
argument|: -
literal|1
argument_list|)
end_macro

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_macro
name|EVAL_EXPR
argument_list|(
literal|34
argument_list|,
argument|(foo == (void *)
literal|0
argument|) ? -
literal|1
argument|:
literal|1
argument_list|)
end_macro

begin_comment
comment|// No PR. Mismatched bitwidths lead to a crash on second evaluation.
end_comment

begin_decl_stmt
specifier|const
name|_Bool
name|constbool
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_macro
name|EVAL_EXPR
argument_list|(
literal|35
argument_list|,
argument|constbool
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|36
argument_list|,
argument|constbool
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|37
argument_list|,
argument|(
literal|1
argument|,
literal|2.0
argument|) ==
literal|2.0
argument|?
literal|1
argument|: -
literal|1
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|38
argument_list|,
argument|__builtin_expect(
literal|1
argument|,
literal|1
argument|) ==
literal|1
argument|?
literal|1
argument|: -
literal|1
argument_list|)
end_macro

begin_comment
comment|// PR7884
end_comment

begin_macro
name|EVAL_EXPR
argument_list|(
literal|39
argument_list|,
argument|__real__(
literal|1.f
argument|) ==
literal|1
argument|?
literal|1
argument|: -
literal|1
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|40
argument_list|,
argument|__imag__(
literal|1.f
argument|) ==
literal|0
argument|?
literal|1
argument|: -
literal|1
argument_list|)
end_macro

begin_comment
comment|// rdar://8875946
end_comment

begin_function
name|void
name|rdar8875946
parameter_list|()
block|{
name|double
specifier|_Complex
name|P
decl_stmt|;
name|float
specifier|_Complex
name|P2
init|=
literal|3.3f
operator|+
name|P
decl_stmt|;
block|}
end_function

end_unit

