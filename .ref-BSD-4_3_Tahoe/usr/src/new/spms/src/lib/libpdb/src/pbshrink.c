begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbshrink() shrinks the buffer by n characters just before the point  * marked by buffer pointer bp.  */
end_comment

begin_function
name|void
name|pbshrink
parameter_list|(
name|bp
parameter_list|,
name|n
parameter_list|)
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
comment|/* buffer pointer */
name|int
name|n
decl_stmt|;
comment|/* shrink amount */
block|{
specifier|register
name|char
modifier|*
name|lowerbp
decl_stmt|;
comment|/* lower roving buffer pointer */
specifier|register
name|char
modifier|*
name|upperbp
decl_stmt|;
comment|/* upper roving buffer pointer */
for|for
control|(
name|upperbp
operator|=
name|bp
init|;
operator|*
name|upperbp
operator|!=
literal|'\0'
condition|;
name|upperbp
operator|++
control|)
continue|continue;
name|lowerbp
operator|=
name|bp
operator|+
name|n
expr_stmt|;
if|if
condition|(
name|lowerbp
operator|>=
name|upperbp
condition|)
operator|*
name|bp
operator|=
literal|'\0'
expr_stmt|;
while|while
condition|(
name|lowerbp
operator|<=
name|upperbp
condition|)
operator|*
name|bp
operator|++
operator|=
operator|*
name|lowerbp
operator|++
expr_stmt|;
block|}
end_function

end_unit

