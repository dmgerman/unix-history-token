begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* seq_find.c - find an element in a sequence */
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
literal|"$Header: /f/osi/psap/RCS/seq_find.c,v 7.1 91/02/22 09:36:54 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/seq_find.c,v 7.1 91/02/22 09:36:54 mrose Interim $  *  *  * $Log:	seq_find.c,v $  * Revision 7.1  91/02/22  09:36:54  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:13:38  mrose  * Release 6.0  *   */
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
name|seq_find
parameter_list|(
name|pe
parameter_list|,
name|i
parameter_list|)
specifier|register
name|PE
name|pe
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
block|{
specifier|register
name|PE
name|p
decl_stmt|;
if|if
condition|(
name|i
operator|>=
name|pe
operator|->
name|pe_cardinal
condition|)
return|return
name|pe_seterr
argument_list|(
name|pe
argument_list|,
name|PE_ERR_MBER
argument_list|,
name|NULLPE
argument_list|)
return|;
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
name|p
operator|->
name|pe_offset
operator|==
name|i
condition|)
break|break;
return|return
name|p
return|;
block|}
end_function

end_unit

