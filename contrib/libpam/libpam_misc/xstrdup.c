begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Header: /home/morgan/pam/Linux-PAM-0.53/libpam_misc/RCS/xstrdup.c,v 1.4 1996/11/10 20:10:56 morgan Exp $ */
end_comment

begin_comment
comment|/*  * $Log: xstrdup.c,v $  * Revision 1.4  1996/11/10 20:10:56  morgan  * modification for stack paranoia  *  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<security/pam_misc.h>
end_include

begin_comment
comment|/*  * Safe duplication of character strings. "Paranoid"; don't leave  * evidence of old token around for later stack analysis.  */
end_comment

begin_function
name|char
modifier|*
name|xstrdup
parameter_list|(
specifier|const
name|char
modifier|*
name|x
parameter_list|)
block|{
specifier|register
name|char
modifier|*
name|new
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|x
operator|!=
name|NULL
condition|)
block|{
specifier|register
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|x
index|[
name|i
index|]
condition|;
operator|++
name|i
control|)
empty_stmt|;
comment|/* length of string */
if|if
condition|(
operator|(
name|new
operator|=
name|malloc
argument_list|(
operator|++
name|i
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|i
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
while|while
condition|(
name|i
operator|--
operator|>
literal|0
condition|)
block|{
name|new
index|[
name|i
index|]
operator|=
name|x
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
name|x
operator|=
name|NULL
expr_stmt|;
block|}
return|return
name|new
return|;
comment|/* return the duplicate or NULL on error */
block|}
end_function

end_unit

