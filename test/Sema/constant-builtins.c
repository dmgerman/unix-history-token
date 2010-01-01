begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify -pedantic
end_comment

begin_comment
comment|// Math stuff
end_comment

begin_decl_stmt
name|float
name|g0
init|=
name|__builtin_huge_val
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|g1
init|=
name|__builtin_huge_valf
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|double
name|g2
init|=
name|__builtin_huge_vall
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|g3
init|=
name|__builtin_inf
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|g4
init|=
name|__builtin_inff
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|double
name|g5
init|=
name|__builtin_infl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// GCC misc stuff
end_comment

begin_function_decl
specifier|extern
name|int
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|h0
init|=
name|__builtin_types_compatible_p
argument_list|(
name|int
argument_list|,
name|float
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//int h1 = __builtin_choose_expr(1, 10, f());
end_comment

begin_comment
comment|//int h2 = __builtin_expect(0, 0);
end_comment

begin_function_decl
name|short
name|somefunc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|short
name|t
init|=
name|__builtin_constant_p
argument_list|(
literal|5353
argument_list|)
condition|?
literal|42
else|:
name|somefunc
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

