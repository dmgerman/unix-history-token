begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)swab.c	5.3 (Berkeley) 3/9/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_comment
comment|/*  * Swab bytes  * Jeffrey Mogul, Stanford  */
end_comment

begin_expr_stmt
name|swab
argument_list|(
name|from
argument_list|,
name|to
argument_list|,
name|n
argument_list|)
specifier|register
name|char
operator|*
name|from
operator|,
operator|*
name|to
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|unsigned
name|long
name|temp
decl_stmt|;
name|n
operator|>>=
literal|1
expr_stmt|;
name|n
operator|++
expr_stmt|;
define|#
directive|define
name|STEP
value|temp = *from++,*to++ = *from++,*to++ = temp
comment|/* round to multiple of 8 */
while|while
condition|(
operator|(
operator|--
name|n
operator|)
operator|&
literal|07
condition|)
name|STEP
expr_stmt|;
name|n
operator|>>=
literal|3
expr_stmt|;
while|while
condition|(
operator|--
name|n
operator|>=
literal|0
condition|)
block|{
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
name|STEP
expr_stmt|;
block|}
block|}
end_block

end_unit

