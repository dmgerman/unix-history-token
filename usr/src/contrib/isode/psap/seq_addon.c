begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* seq_addon.c - add a member to the end of a sequence (efficiency hack) */
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
literal|"$Header: /f/osi/psap/RCS/seq_addon.c,v 7.1 91/02/22 09:36:52 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/seq_addon.c,v 7.1 91/02/22 09:36:52 mrose Interim $  *  *  * $Log:	seq_addon.c,v $  * Revision 7.1  91/02/22  09:36:52  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:13:36  mrose  * Release 6.0  *   */
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
name|seq_addon
parameter_list|(
name|pe
parameter_list|,
name|last
parameter_list|,
name|new
parameter_list|)
name|PE
name|pe
decl_stmt|,
name|last
decl_stmt|,
name|new
decl_stmt|;
block|{
if|if
condition|(
name|pe
operator|==
name|NULLPE
condition|)
return|return
name|NOTOK
return|;
if|if
condition|(
name|last
operator|==
name|NULLPE
condition|)
return|return
name|seq_add
argument_list|(
name|pe
argument_list|,
name|new
argument_list|,
operator|-
literal|1
argument_list|)
return|;
name|new
operator|->
name|pe_offset
operator|=
name|pe
operator|->
name|pe_cardinal
operator|++
expr_stmt|;
name|last
operator|->
name|pe_next
operator|=
name|new
expr_stmt|;
return|return
name|OK
return|;
block|}
end_function

end_unit

