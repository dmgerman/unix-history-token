begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*	read one integer from the open file */
end_comment

begin_macro
name|intrd_
argument_list|(
argument|valptr
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|valptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|scanf
argument_list|(
literal|"%d"
argument_list|,
name|valptr
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|getchar
argument_list|()
operator|!=
literal|'\n'
operator|)
condition|)
empty_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/*	read an array from the open file */
end_comment

begin_macro
name|aryrd_
argument_list|(
argument|cntptr
argument_list|,
argument|aryptr
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|cntptr
decl_stmt|,
modifier|*
name|aryptr
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
operator|*
name|cntptr
init|;
name|i
operator|>
literal|0
condition|;
operator|--
name|i
operator|,
operator|++
name|aryptr
control|)
name|scanf
argument_list|(
literal|"%d"
argument_list|,
name|aryptr
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|getchar
argument_list|()
operator|!=
literal|'\n'
operator|)
condition|)
empty_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/* get a logical value */
end_comment

begin_macro
name|logrd_
argument_list|(
argument|ptr
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|ptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|char
name|byte
decl_stmt|;
operator|*
name|ptr
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|byte
operator|=
name|getchar
argument_list|()
operator|)
operator|!=
literal|'\n'
condition|)
block|{
if|if
condition|(
operator|(
name|byte
operator|==
literal|'T'
operator|)
operator|||
operator|(
name|byte
operator|==
literal|'t'
operator|)
condition|)
operator|*
name|ptr
operator|=
literal|1
expr_stmt|;
block|}
return|return;
block|}
end_block

begin_comment
comment|/* wait for end of init flag */
end_comment

begin_macro
name|initnd_
argument_list|()
end_macro

begin_block
block|{
specifier|static
name|int
name|chr
decl_stmt|;
while|while
condition|(
operator|(
name|chr
operator|=
name|getchar
argument_list|()
operator|)
operator|!=
literal|'?'
condition|)
block|{
comment|/* wait for end flag */
if|if
condition|(
name|chr
operator|==
literal|'R'
condition|)
comment|/* check for restore flag */
name|rstrgm_
argument_list|()
expr_stmt|;
comment|/* call restore routine  */
block|}
return|return;
block|}
end_block

begin_comment
comment|/*	write an array to the open pipe */
end_comment

begin_macro
name|arywt_
argument_list|(
argument|cntptr
argument_list|,
argument|aryptr
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|cntptr
decl_stmt|,
modifier|*
name|aryptr
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
operator|*
name|cntptr
init|;
name|i
operator|>
literal|0
condition|;
operator|--
name|i
operator|,
operator|++
name|aryptr
control|)
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
operator|*
name|aryptr
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

end_unit

