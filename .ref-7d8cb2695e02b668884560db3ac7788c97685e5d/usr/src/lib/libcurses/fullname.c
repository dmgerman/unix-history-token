begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

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
literal|"@(#)fullname.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * fullname --  *	This routine fills in "def" with the full name of the terminal.  *	This is assumed to be the last name in the list of aliases.  */
end_comment

begin_function
name|char
modifier|*
name|fullname
parameter_list|(
name|bp
parameter_list|,
name|def
parameter_list|)
specifier|register
name|char
modifier|*
name|bp
decl_stmt|,
decl|*
name|def
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
operator|*
name|def
operator|=
literal|'\0'
expr_stmt|;
comment|/* In case no name. */
while|while
condition|(
operator|*
name|bp
operator|&&
operator|*
name|bp
operator|!=
literal|':'
condition|)
block|{
name|cp
operator|=
name|def
expr_stmt|;
comment|/* Start of answer. */
while|while
condition|(
operator|*
name|bp
operator|&&
operator|*
name|bp
operator|!=
literal|':'
operator|&&
operator|*
name|bp
operator|!=
literal|'|'
condition|)
operator|*
name|cp
operator|++
operator|=
operator|*
name|bp
operator|++
expr_stmt|;
comment|/* Copy name over. */
operator|*
name|cp
operator|=
literal|'\0'
expr_stmt|;
comment|/* Zero end of name. */
if|if
condition|(
operator|*
name|bp
operator|==
literal|'|'
condition|)
name|bp
operator|++
expr_stmt|;
comment|/* Skip over '|' if that is case. */
block|}
return|return
operator|(
name|def
operator|)
return|;
block|}
end_block

end_unit

