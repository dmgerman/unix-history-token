begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* prim2flag.c - presentation element to set */
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
literal|"$Header: /f/osi/psap/RCS/prim2set.c,v 7.1 91/02/22 09:36:26 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/prim2set.c,v 7.1 91/02/22 09:36:26 mrose Interim $  *  *  * $Log:	prim2set.c,v $  * Revision 7.1  91/02/22  09:36:26  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:13:15  mrose  * Release 6.0  *   */
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
name|prim2set
parameter_list|(
name|pe
parameter_list|)
specifier|register
name|PE
name|pe
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|PE
name|p
decl_stmt|;
if|if
condition|(
name|pe
operator|->
name|pe_form
operator|!=
name|PE_FORM_CONS
condition|)
return|return
name|pe_seterr
argument_list|(
name|pe
argument_list|,
name|PE_ERR_CONS
argument_list|,
name|NULLPE
argument_list|)
return|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|p
operator|=
name|pe
operator|->
name|pe_cons
init|;
name|p
condition|;
name|p
operator|=
name|p
operator|->
name|pe_next
control|)
name|p
operator|->
name|pe_offset
operator|=
name|i
operator|++
expr_stmt|;
name|pe
operator|->
name|pe_cardinal
operator|=
name|i
expr_stmt|;
return|return
name|pe
return|;
block|}
end_function

end_unit

