begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Uniform random number generator.  Code courtesy of Bob Morris. Linear congruential generator, suitable for 32 bit machines; multiplication is mod 2**31 */
end_comment

begin_decl_stmt
specifier|static
name|long
name|randx
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_macro
name|srand_
argument_list|(
argument|x
argument_list|)
end_macro

begin_comment
comment|/* subroutine to set seed */
end_comment

begin_decl_stmt
name|long
modifier|*
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|randx
operator|=
operator|*
name|x
expr_stmt|;
block|}
end_block

begin_function
name|double
name|rand_
parameter_list|()
block|{
name|double
name|ldexp
parameter_list|()
function_decl|;
return|return
operator|(
name|ldexp
argument_list|(
call|(
name|double
call|)
argument_list|(
operator|(
operator|(
name|randx
operator|=
name|randx
operator|*
literal|1103515245
operator|+
literal|12345
operator|)
operator|>>
literal|7
operator|)
operator|&
literal|077777777
argument_list|)
argument_list|,
operator|-
literal|24
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

