begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lexequ.c - Compare two strings ignoring case */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/compat/RCS/lexequ.c,v 7.2 91/02/22 09:15:25 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * $Header: /f/osi/compat/RCS/lexequ.c,v 7.2 91/02/22 09:15:25 mrose Interim $  *  *  * $Log:	lexequ.c,v $  * Revision 7.2  91/02/22  09:15:25  mrose  * Interim 6.8  *   * Revision 7.1  90/10/15  18:19:55  mrose  * sync  *   * Revision 7.0  89/11/23  21:23:12  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *                                NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"general.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_expr_stmt
name|lexequ
argument_list|(
name|str1
argument_list|,
name|str2
argument_list|)
specifier|register
name|char
operator|*
name|str1
operator|,
operator|*
name|str2
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|str1
operator|==
name|NULL
condition|)
if|if
condition|(
name|str2
operator|==
name|NULL
condition|)
return|return
operator|(
literal|0
operator|)
return|;
else|else
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|str2
operator|==
name|NULL
condition|)
return|return
operator|(
literal|1
operator|)
return|;
while|while
condition|(
name|chrcnv
index|[
operator|*
name|str1
index|]
operator|==
name|chrcnv
index|[
operator|*
name|str2
index|]
condition|)
block|{
if|if
condition|(
operator|*
name|str1
operator|++
operator|==
name|NULL
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|str2
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|chrcnv
index|[
operator|*
name|str1
index|]
operator|>
name|chrcnv
index|[
operator|*
name|str2
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
else|else
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

end_unit

