begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
unit|@
name|interface
name|MyClass
operator|+
operator|(
name|void
operator|)
name|meth
expr_stmt|;
end_expr_stmt

begin_function
unit|@
name|end
define|#
directive|define
name|MACRO2
parameter_list|(
name|x
parameter_list|)
value|x
define|#
directive|define
name|MACRO
parameter_list|(
name|x
parameter_list|)
value|MACRO2(x)
name|void
name|test
parameter_list|()
block|{
name|MACRO
argument_list|(
argument|[MyClass meth]
argument_list|)
empty_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|INVOKE
parameter_list|(
name|METHOD
parameter_list|,
name|CLASS
parameter_list|)
value|[CLASS METHOD]
end_define

begin_function
name|void
name|test2
parameter_list|()
block|{
name|INVOKE
argument_list|(
name|meth
argument_list|,
name|MyClass
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

