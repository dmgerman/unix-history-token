begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* block copy from from to to, count bytes */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)bcopy.c	7.1	7/8/81"
decl_stmt|;
end_decl_stmt

begin_macro
name|bcopy
argument_list|(
argument|from
argument_list|,
argument|to
argument_list|,
argument|count
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|from
decl_stmt|,
modifier|*
name|to
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{
asm|asm("	movc3	12(ap),*4(ap),*8(ap)");
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|register
name|char
modifier|*
name|from
decl_stmt|,
modifier|*
name|to
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
operator|(
name|count
operator|--
operator|)
operator|>
literal|0
condition|)
comment|/* mjm */
operator|*
name|to
operator|++
operator|=
operator|*
name|from
operator|++
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

