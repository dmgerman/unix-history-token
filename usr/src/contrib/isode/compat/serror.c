begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* serror.c - get system error */
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
literal|"$Header: /f/osi/compat/RCS/serror.c,v 7.2 91/02/22 09:15:47 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/compat/RCS/serror.c,v 7.2 91/02/22 09:15:47 mrose Interim $  *  *  * $Log:	serror.c,v $  * Revision 7.2  91/02/22  09:15:47  mrose  * Interim 6.8  *   * Revision 7.1  91/01/11  07:09:12  mrose  * jpo  *   * Revision 7.0  89/11/23  21:23:25  mrose  * Release 6.0  *   */
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

begin_comment
comment|/*
comment|DATA */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|char
modifier|*
name|sys_errname
parameter_list|(
name|i
parameter_list|)
name|int
name|i
decl_stmt|;
block|{
specifier|static
name|char
name|buffer
index|[
literal|30
index|]
decl_stmt|;
if|if
condition|(
literal|0
operator|<
name|i
operator|&&
name|i
operator|<
name|sys_nerr
condition|)
return|return
name|sys_errlist
index|[
name|i
index|]
return|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"Error %d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
end_function

end_unit

