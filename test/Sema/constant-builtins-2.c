begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only %s
end_comment

begin_comment
comment|// Math stuff
end_comment

begin_decl_stmt
name|double
name|g0
init|=
name|__builtin_huge_val
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
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
name|double
name|g3
init|=
name|__builtin_inf
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
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

begin_decl_stmt
name|double
name|g6
init|=
name|__builtin_nan
argument_list|(
literal|""
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|g7
init|=
name|__builtin_nanf
argument_list|(
literal|""
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|double
name|g8
init|=
name|__builtin_nanl
argument_list|(
literal|""
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// GCC constant folds these too (via native strtol):
end_comment

begin_comment
comment|//double       g6_1  = __builtin_nan("1");
end_comment

begin_comment
comment|//float        g7_1  = __builtin_nanf("1");
end_comment

begin_comment
comment|//long double  g8_1  = __builtin_nanl("1");
end_comment

begin_comment
comment|// APFloat doesn't have signalling NaN functions.
end_comment

begin_comment
comment|//double       g9  = __builtin_nans("");
end_comment

begin_comment
comment|//float        g10 = __builtin_nansf("");
end_comment

begin_comment
comment|//long double  g11 = __builtin_nansl("");
end_comment

begin_comment
comment|//int          g12 = __builtin_abs(-12);
end_comment

begin_decl_stmt
name|double
name|g13
init|=
name|__builtin_fabs
argument_list|(
operator|-
literal|12.
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|g13_0
init|=
name|__builtin_fabs
argument_list|(
operator|-
literal|0.
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|g13_1
init|=
name|__builtin_fabs
argument_list|(
operator|-
name|__builtin_inf
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|g14
init|=
name|__builtin_fabsf
argument_list|(
operator|-
literal|12.f
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// GCC doesn't eat this one.
end_comment

begin_comment
comment|//long double  g15 = __builtin_fabsfl(-12.0L);
end_comment

begin_decl_stmt
name|float
name|g16
init|=
name|__builtin_copysign
argument_list|(
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|g17
init|=
name|__builtin_copysignf
argument_list|(
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|double
name|g18
init|=
name|__builtin_copysignl
argument_list|(
literal|1.0L
argument_list|,
operator|-
literal|1.0L
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//double       g19 = __builtin_powi(2.0, 4);
end_comment

begin_comment
comment|//float        g20 = __builtin_powif(2.0f, 4);
end_comment

begin_comment
comment|//long double  g21 = __builtin_powil(2.0L, 4);
end_comment

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

begin_decl_stmt
specifier|extern
name|long
name|int
name|bi0
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern __typeof__(__builtin_expect(0
operator|,
extern|0
end_extern

begin_expr_stmt
unit|))
name|bi0
expr_stmt|;
end_expr_stmt

end_unit

