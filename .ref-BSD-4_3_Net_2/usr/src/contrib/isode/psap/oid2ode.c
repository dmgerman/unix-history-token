begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* oid2ode.c - object identifier to object descriptor  */
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
literal|"$Header: /f/osi/psap/RCS/oid2ode.c,v 7.2 91/02/22 09:35:54 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/oid2ode.c,v 7.2 91/02/22 09:35:54 mrose Interim $  *  *  * $Log:	oid2ode.c,v $  * Revision 7.2  91/02/22  09:35:54  mrose  * Interim 6.8  *   * Revision 7.1  90/07/09  14:43:47  mrose  * sync  *   * Revision 7.0  89/11/23  22:12:49  mrose  * Release 6.0  *   */
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

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|char
modifier|*
name|oid2ode_aux
parameter_list|(
name|identifier
parameter_list|,
name|quoted
parameter_list|)
name|OID
name|identifier
decl_stmt|;
name|int
name|quoted
decl_stmt|;
block|{
name|int
name|events
decl_stmt|;
specifier|register
name|struct
name|isobject
modifier|*
name|io
decl_stmt|;
specifier|static
name|char
name|buffer
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|events
operator|=
name|addr_log
operator|->
name|ll_events
expr_stmt|;
name|addr_log
operator|->
name|ll_events
operator|=
name|LLOG_FATAL
expr_stmt|;
name|io
operator|=
name|getisobjectbyoid
argument_list|(
name|identifier
argument_list|)
expr_stmt|;
name|addr_log
operator|->
name|ll_events
operator|=
name|events
expr_stmt|;
if|if
condition|(
name|io
condition|)
block|{
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buffer
argument_list|,
name|quoted
condition|?
literal|"\"%s\""
else|:
literal|"%s"
argument_list|,
name|io
operator|->
name|io_descriptor
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
return|return
name|sprintoid
argument_list|(
name|identifier
argument_list|)
return|;
block|}
end_function

end_unit

