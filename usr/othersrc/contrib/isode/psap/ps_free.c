begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ps_free.c - free a presentation stream */
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
literal|"$Header: /f/osi/psap/RCS/ps_free.c,v 7.1 91/02/22 09:36:34 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/ps_free.c,v 7.1 91/02/22 09:36:34 mrose Interim $  *  *  * $Log:	ps_free.c,v $  * Revision 7.1  91/02/22  09:36:34  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:13:22  mrose  * Release 6.0  *   */
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
name|void
name|ps_free
parameter_list|(
name|ps
parameter_list|)
specifier|register
name|PS
name|ps
decl_stmt|;
block|{
if|if
condition|(
name|ps
operator|->
name|ps_closeP
condition|)
call|(
name|void
call|)
argument_list|(
operator|*
name|ps
operator|->
name|ps_closeP
argument_list|)
argument_list|(
name|ps
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|ps
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

