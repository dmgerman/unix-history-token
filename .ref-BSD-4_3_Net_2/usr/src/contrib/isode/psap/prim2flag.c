begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* prim2flag.c - presentation element to boolean */
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
literal|"$Header: /f/osi/psap/RCS/prim2flag.c,v 7.1 91/02/22 09:36:21 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/prim2flag.c,v 7.1 91/02/22 09:36:21 mrose Interim $  *  *  * $Log:	prim2flag.c,v $  * Revision 7.1  91/02/22  09:36:21  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:13:10  mrose  * Release 6.0  *   */
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
name|int
name|prim2flag
parameter_list|(
name|pe
parameter_list|)
specifier|register
name|PE
name|pe
decl_stmt|;
block|{
if|if
condition|(
name|pe
operator|->
name|pe_form
operator|!=
name|PE_FORM_PRIM
operator|||
name|pe
operator|->
name|pe_prim
operator|==
name|NULLPED
operator|||
name|pe
operator|->
name|pe_len
operator|==
literal|0
condition|)
return|return
name|pe_seterr
argument_list|(
name|pe
argument_list|,
name|PE_ERR_PRIM
argument_list|,
name|NOTOK
argument_list|)
return|;
return|return
operator|(
operator|*
name|pe
operator|->
name|pe_prim
operator|!=
literal|0x00
operator|)
return|;
block|}
end_function

end_unit

