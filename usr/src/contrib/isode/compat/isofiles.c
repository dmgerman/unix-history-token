begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* isofiles.c - ISODE files */
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
literal|"$Header: /f/osi/compat/RCS/isofiles.c,v 7.1 91/02/22 09:15:20 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/compat/RCS/isofiles.c,v 7.1 91/02/22 09:15:20 mrose Interim $  *  *  * $Log:	isofiles.c,v $  * Revision 7.1  91/02/22  09:15:20  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:23:07  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
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

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|char
modifier|*
name|_isodefile
parameter_list|(
name|path
parameter_list|,
name|file
parameter_list|)
name|char
modifier|*
name|path
decl_stmt|,
decl|*
name|file
decl_stmt|;
end_function

begin_block
block|{
specifier|static
name|char
name|buffer
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|isodetailor
argument_list|(
name|NULLCP
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* not really recursive */
if|if
condition|(
operator|*
name|file
operator|==
literal|'/'
operator|||
operator|(
operator|*
name|file
operator|==
literal|'.'
operator|&&
operator|(
name|file
index|[
literal|1
index|]
operator|==
literal|'/'
operator|||
operator|(
name|file
index|[
literal|1
index|]
operator|==
literal|'.'
operator|&&
name|file
index|[
literal|2
index|]
operator|==
literal|'/'
operator|)
operator|)
operator|)
condition|)
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|buffer
argument_list|,
name|file
argument_list|)
expr_stmt|;
else|else
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"%s%s"
argument_list|,
name|path
argument_list|,
name|file
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
end_block

end_unit

