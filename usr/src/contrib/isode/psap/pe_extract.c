begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pe_extract.c - extract a PE */
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
literal|"$Header: /f/osi/psap/RCS/pe_extract.c,v 7.2 91/02/22 09:36:14 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/pe_extract.c,v 7.2 91/02/22 09:36:14 mrose Interim $  *  *  * $Log:	pe_extract.c,v $  * Revision 7.2  91/02/22  09:36:14  mrose  * Interim 6.8  *   * Revision 7.1  91/01/24  14:50:25  mrose  * update  *   * Revision 7.0  89/11/23  22:13:04  mrose  * Release 6.0  *   */
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
comment|/* assumes that q appears at most once directly under p... */
end_comment

begin_function
name|int
name|pe_extract
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
specifier|register
name|PE
modifier|*
name|p
decl_stmt|,
name|q
decl_stmt|;
switch|switch
condition|(
name|pe
operator|->
name|pe_form
condition|)
block|{
case|case
name|PE_FORM_PRIM
case|:
case|case
name|PE_FORM_ICONS
case|:
break|break;
case|case
name|PE_FORM_CONS
case|:
for|for
control|(
name|p
operator|=
operator|&
name|pe
operator|->
name|pe_cons
init|;
name|q
operator|=
operator|*
name|p
condition|;
name|p
operator|=
operator|&
name|q
operator|->
name|pe_next
control|)
if|if
condition|(
name|q
operator|==
name|r
condition|)
block|{
operator|(
operator|*
name|p
operator|)
operator|=
name|q
operator|->
name|pe_next
expr_stmt|;
name|q
operator|->
name|pe_next
operator|=
name|NULLPE
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|pe_refcnt
operator|>
literal|0
condition|)
name|r
operator|->
name|pe_refcnt
operator|--
expr_stmt|;
return|return
literal|1
return|;
block|}
elseif|else
if|if
condition|(
name|pe_extract
argument_list|(
name|q
argument_list|,
name|r
argument_list|)
condition|)
return|return
literal|1
return|;
break|break;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

