begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* set_find.c - find member of a set */
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
literal|"$Header: /f/osi/psap/RCS/set_find.c,v 7.1 91/02/22 09:36:59 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/set_find.c,v 7.1 91/02/22 09:36:59 mrose Interim $  *  *  * $Log:	set_find.c,v $  * Revision 7.1  91/02/22  09:36:59  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:13:41  mrose  * Release 6.0  *   */
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
name|set_find
parameter_list|(
name|pe
parameter_list|,
name|class
parameter_list|,
name|id
parameter_list|)
specifier|register
name|PE
name|pe
decl_stmt|;
specifier|register
name|PElementClass
name|class
decl_stmt|;
specifier|register
name|PElementID
name|id
decl_stmt|;
block|{
specifier|register
name|int
name|pe_id
decl_stmt|;
specifier|register
name|PE
name|p
decl_stmt|;
name|pe_id
operator|=
name|PE_ID
argument_list|(
name|class
argument_list|,
name|id
argument_list|)
expr_stmt|;
for|for
control|(
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
if|if
condition|(
name|PE_ID
argument_list|(
name|p
operator|->
name|pe_class
argument_list|,
name|p
operator|->
name|pe_id
argument_list|)
operator|==
name|pe_id
condition|)
break|break;
return|return
name|p
return|;
block|}
end_function

end_unit

