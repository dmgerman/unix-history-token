begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only %s -Wdouble-promotion
end_comment

begin_function
name|float
name|ReturnFloatFromDouble
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|d
return|;
block|}
end_function

begin_function
name|float
name|ReturnFloatFromLongDouble
parameter_list|(
name|long
name|double
name|ld
parameter_list|)
block|{
return|return
name|ld
return|;
block|}
end_function

begin_function
name|double
name|ReturnDoubleFromLongDouble
parameter_list|(
name|long
name|double
name|ld
parameter_list|)
block|{
return|return
name|ld
return|;
block|}
end_function

begin_function
name|double
name|ReturnDoubleFromFloat
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|f
return|;
comment|//expected-warning{{implicit conversion increases floating-point precision: 'float' to 'double'}}
block|}
end_function

begin_function
name|long
name|double
name|ReturnLongDoubleFromFloat
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|f
return|;
comment|//expected-warning{{implicit conversion increases floating-point precision: 'float' to 'long double'}}
block|}
end_function

begin_function
name|long
name|double
name|ReturnLongDoubleFromDouble
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|d
return|;
comment|//expected-warning{{implicit conversion increases floating-point precision: 'double' to 'long double'}}
block|}
end_function

begin_function
name|void
name|Assignment
parameter_list|(
name|float
name|f
parameter_list|,
name|double
name|d
parameter_list|,
name|long
name|double
name|ld
parameter_list|)
block|{
name|d
operator|=
name|f
expr_stmt|;
comment|//expected-warning{{implicit conversion increases floating-point precision: 'float' to 'double'}}
name|ld
operator|=
name|f
expr_stmt|;
comment|//expected-warning{{implicit conversion increases floating-point precision: 'float' to 'long double'}}
name|ld
operator|=
name|d
expr_stmt|;
comment|//expected-warning{{implicit conversion increases floating-point precision: 'double' to 'long double'}}
name|f
operator|=
name|d
expr_stmt|;
name|f
operator|=
name|ld
expr_stmt|;
name|d
operator|=
name|ld
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|DoubleParameter
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LongDoubleParameter
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|ArgumentPassing
parameter_list|(
name|float
name|f
parameter_list|,
name|double
name|d
parameter_list|)
block|{
name|DoubleParameter
argument_list|(
name|f
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicit conversion increases floating-point precision: 'float' to 'double'}}
name|LongDoubleParameter
argument_list|(
name|f
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicit conversion increases floating-point precision: 'float' to 'long double'}}
name|LongDoubleParameter
argument_list|(
name|d
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicit conversion increases floating-point precision: 'double' to 'long double'}}
block|}
end_function

begin_function
name|void
name|BinaryOperator
parameter_list|(
name|float
name|f
parameter_list|,
name|double
name|d
parameter_list|,
name|long
name|double
name|ld
parameter_list|)
block|{
name|f
operator|=
name|f
operator|*
name|d
expr_stmt|;
comment|// expected-warning{{implicit conversion increases floating-point precision: 'float' to 'double'}}
name|f
operator|=
name|d
operator|*
name|f
expr_stmt|;
comment|// expected-warning{{implicit conversion increases floating-point precision: 'float' to 'double'}}
name|f
operator|=
name|f
operator|*
name|ld
expr_stmt|;
comment|// expected-warning{{implicit conversion increases floating-point precision: 'float' to 'long double'}}
name|f
operator|=
name|ld
operator|*
name|f
expr_stmt|;
comment|// expected-warning{{implicit conversion increases floating-point precision: 'float' to 'long double'}}
name|d
operator|=
name|d
operator|*
name|ld
expr_stmt|;
comment|// expected-warning{{implicit conversion increases floating-point precision: 'double' to 'long double'}}
name|d
operator|=
name|ld
operator|*
name|d
expr_stmt|;
comment|// expected-warning{{implicit conversion increases floating-point precision: 'double' to 'long double'}}
block|}
end_function

begin_function
name|void
name|MultiplicationAssignment
parameter_list|(
name|float
name|f
parameter_list|,
name|double
name|d
parameter_list|,
name|long
name|double
name|ld
parameter_list|)
block|{
name|d
operator|*=
name|f
expr_stmt|;
comment|// expected-warning{{implicit conversion increases floating-point precision: 'float' to 'double'}}
name|ld
operator|*=
name|f
expr_stmt|;
comment|// expected-warning{{implicit conversion increases floating-point precision: 'float' to 'long double'}}
name|ld
operator|*=
name|d
expr_stmt|;
comment|// expected-warning{{implicit conversion increases floating-point precision: 'double' to 'long double'}}
comment|// FIXME: These cases should produce warnings as above.
name|f
operator|*=
name|d
expr_stmt|;
name|f
operator|*=
name|ld
expr_stmt|;
name|d
operator|*=
name|ld
expr_stmt|;
block|}
end_function

begin_comment
comment|// FIXME: As with a binary operator, the operands to the conditional operator are
end_comment

begin_comment
comment|// converted to a common type and should produce a warning.
end_comment

begin_function
name|void
name|ConditionalOperator
parameter_list|(
name|float
name|f
parameter_list|,
name|double
name|d
parameter_list|,
name|long
name|double
name|ld
parameter_list|,
name|int
name|i
parameter_list|)
block|{
name|f
operator|=
name|i
condition|?
name|f
else|:
name|d
expr_stmt|;
name|f
operator|=
name|i
condition|?
name|d
else|:
name|f
expr_stmt|;
name|f
operator|=
name|i
condition|?
name|f
else|:
name|ld
expr_stmt|;
name|f
operator|=
name|i
condition|?
name|ld
else|:
name|f
expr_stmt|;
name|d
operator|=
name|i
condition|?
name|d
else|:
name|ld
expr_stmt|;
name|d
operator|=
name|i
condition|?
name|ld
else|:
name|d
expr_stmt|;
block|}
end_function

end_unit

