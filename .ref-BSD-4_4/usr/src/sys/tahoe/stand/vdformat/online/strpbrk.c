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
literal|"@(#)strpbrk.c	1.1 (Berkeley/CCI) 7/5/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*	@(#)strpbrk.c	1.2	*/
end_comment

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_comment
comment|/*  * Return ptr to first occurance of any character from `brkset'  * in the character string `string'; NULL if none exists.  */
end_comment

begin_define
define|#
directive|define
name|NULL
value|(char *) 0
end_define

begin_function
name|char
modifier|*
name|strpbrk
parameter_list|(
name|string
parameter_list|,
name|brkset
parameter_list|)
specifier|register
name|char
modifier|*
name|string
decl_stmt|,
decl|*
name|brkset
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
do|do
block|{
for|for
control|(
name|p
operator|=
name|brkset
init|;
operator|*
name|p
operator|!=
literal|'\0'
operator|&&
operator|*
name|p
operator|!=
operator|*
name|string
condition|;
operator|++
name|p
control|)
empty_stmt|;
if|if
condition|(
operator|*
name|p
operator|!=
literal|'\0'
condition|)
return|return
operator|(
name|string
operator|)
return|;
block|}
do|while
condition|(
operator|*
name|string
operator|++
condition|)
do|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_block

end_unit

