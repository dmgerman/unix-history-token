begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)hash.c	1.1	(Berkeley)	3/29/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/*  * Hash function.  Used for pass 2 symbol table and string table,  * and structure/union name passing between passes.  * The hash function is a modular hash of  * the sum of the characters with the sum  * rotated before each successive character  * is added.  * Only 15 bits are used.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FLEXNAMES
end_ifdef

begin_macro
name|hashstr
argument_list|(
argument|s
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|hashstr
argument_list|(
name|s
argument_list|,
name|n
argument_list|)
specifier|register
name|n
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|i
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|FLEXNAMES
while|while
condition|(
operator|*
name|s
condition|)
else|#
directive|else
while|while
condition|(
name|n
operator|--
operator|>
literal|0
operator|&&
operator|*
name|s
condition|)
endif|#
directive|endif
name|i
operator|=
operator|(
name|i
operator|<<
literal|3
operator||
name|i
operator|>>
literal|12
operator|&
literal|0x07
operator|)
operator|+
operator|*
name|s
operator|++
expr_stmt|;
return|return
name|i
operator|&
literal|0x7fff
return|;
block|}
end_block

end_unit

