begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * random-number generator for testing  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|long
name|next
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  - range - generate a random number within an inclusive range  *  * Algorithm from ANSI C standard.  Limitation:  max-min<= 32767.  */
end_comment

begin_function
name|int
name|range
parameter_list|(
name|min
parameter_list|,
name|max
parameter_list|)
name|int
name|min
decl_stmt|;
name|int
name|max
decl_stmt|;
block|{
specifier|register
name|int
name|temp
decl_stmt|;
name|next
operator|=
name|next
operator|*
literal|1103515245
operator|+
literal|12345
expr_stmt|;
name|temp
operator|=
call|(
name|int
call|)
argument_list|(
operator|(
name|next
operator|/
literal|65536
operator|)
operator|%
literal|32768
argument_list|)
expr_stmt|;
return|return
operator|(
name|temp
operator|%
operator|(
name|max
operator|-
name|min
operator|+
literal|1
operator|)
operator|+
name|min
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  - seed - seed random number generator  */
end_comment

begin_function
name|void
name|seed
parameter_list|(
name|n
parameter_list|)
name|long
name|n
decl_stmt|;
block|{
name|next
operator|=
operator|(
name|unsigned
name|long
operator|)
name|n
expr_stmt|;
block|}
end_function

end_unit

