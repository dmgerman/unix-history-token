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
literal|"@(#)index.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Return the ptr in sp at which the character c appears;  * NULL if not found  */
end_comment

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_function
name|char
modifier|*
name|index
parameter_list|(
name|sp
parameter_list|,
name|c
parameter_list|)
specifier|register
name|char
modifier|*
name|sp
decl_stmt|,
name|c
decl_stmt|;
block|{
do|do
block|{
if|if
condition|(
operator|*
name|sp
operator|==
name|c
condition|)
return|return
operator|(
name|sp
operator|)
return|;
block|}
do|while
condition|(
operator|*
name|sp
operator|++
condition|)
do|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

