begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pe_expunge.c - expunge a PE */
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
literal|"$Header: /f/osi/psap/RCS/pe_expunge.c,v 7.2 91/02/22 09:36:13 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/pe_expunge.c,v 7.2 91/02/22 09:36:13 mrose Interim $  *  *  * $Log:	pe_expunge.c,v $  * Revision 7.2  91/02/22  09:36:13  mrose  * Interim 6.8  *   * Revision 7.1  91/02/12  18:32:46  mrose  * upate  *   * Revision 7.0  89/11/23  22:13:03  mrose  * Release 6.0  *   */
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

begin_function
name|PE
name|pe_expunge
parameter_list|(
name|pe
parameter_list|,
name|r
parameter_list|)
name|PE
name|pe
decl_stmt|,
name|r
decl_stmt|;
block|{
if|if
condition|(
name|r
condition|)
block|{
if|if
condition|(
name|pe
operator|==
name|r
condition|)
return|return
name|r
return|;
if|if
condition|(
name|pe_extract
argument_list|(
name|pe
argument_list|,
name|r
argument_list|)
condition|)
if|if
condition|(
name|pe
operator|->
name|pe_realbase
operator|&&
operator|!
name|r
operator|->
name|pe_realbase
condition|)
block|{
name|r
operator|->
name|pe_realbase
operator|=
name|pe
operator|->
name|pe_realbase
expr_stmt|;
name|pe
operator|->
name|pe_realbase
operator|=
name|NULL
expr_stmt|;
block|}
name|r
operator|->
name|pe_refcnt
operator|++
expr_stmt|;
block|}
name|pe_free
argument_list|(
name|pe
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
end_function

end_unit

