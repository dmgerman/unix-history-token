begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pe_error.c - presentation element error to string */
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
literal|"$Header: /f/osi/psap/RCS/pe_error.c,v 7.3 91/02/22 09:36:12 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/pe_error.c,v 7.3 91/02/22 09:36:12 mrose Interim $  *  *  * $Log:	pe_error.c,v $  * Revision 7.3  91/02/22  09:36:12  mrose  * Interim 6.8  *   * Revision 7.2  91/01/11  07:09:08  mrose  * jpo  *   * Revision 7.1  90/10/23  20:43:44  mrose  * update  *   * Revision 7.0  89/11/23  22:13:03  mrose  * Release 6.0  *   */
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
file|"psap.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|pe_errorlist
index|[]
init|=
block|{
literal|"Error 0"
block|,
literal|"Overflow"
block|,
literal|"Out of memory"
block|,
literal|"No such bit"
block|,
literal|"Malformed universal timestring"
block|,
literal|"Malformed generalized timestring"
block|,
literal|"No such member"
block|,
literal|"Not a primitive form"
block|,
literal|"Not a constructor form"
block|,
literal|"Class/ID mismatch in constructor"
block|,
literal|"Malformed object identifier"
block|,
literal|"Malformed bitstring"
block|,
literal|"Type not supported"
block|,
literal|"Signed integer not expected"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|pe_maxerror
init|=
sizeof|sizeof
name|pe_errorlist
operator|/
sizeof|sizeof
name|pe_errorlist
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|char
modifier|*
name|pe_error
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
specifier|static
name|char
name|buffer
index|[
literal|30
index|]
decl_stmt|;
if|if
condition|(
name|c
operator|<
name|pe_maxerror
operator|&&
operator|(
name|bp
operator|=
name|pe_errorlist
index|[
name|c
index|]
operator|)
condition|)
return|return
name|bp
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
name|c
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
end_function

end_unit

