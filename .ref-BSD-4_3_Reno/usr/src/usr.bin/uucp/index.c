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
literal|"@(#)index.c	5.2 (Berkeley) 1/22/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  *	return pointer to character c  *  *	return codes:  *		NULL  -  character not found  *		pointer  -  pointer to character  */
end_comment

begin_function
name|char
modifier|*
name|index
parameter_list|(
name|str
parameter_list|,
name|c
parameter_list|)
specifier|register
name|char
name|c
decl_stmt|,
decl|*
name|str
decl_stmt|;
end_function

begin_block
block|{
for|for
control|(
init|;
operator|*
name|str
operator|!=
literal|'\0'
condition|;
name|str
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|str
operator|==
name|c
condition|)
return|return
name|str
return|;
block|}
return|return
name|NULL
return|;
block|}
end_block

end_unit

