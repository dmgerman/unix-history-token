begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|main
parameter_list|()
block|{
name|char
modifier|*
name|a
init|=
literal|"main(){char*a=%c%s%c;int b='%c';printf(a,b,a,b,b);}"
decl_stmt|;
name|int
name|b
init|=
literal|'"'
decl_stmt|;
name|printf
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

