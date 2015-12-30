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
name|Convert
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

end_unit

