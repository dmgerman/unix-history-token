begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* objectbyname.c - getisobjectbyname */
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
literal|"$Header: /f/osi/psap/RCS/objectbyname.c,v 7.1 91/02/22 09:35:51 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/objectbyname.c,v 7.1 91/02/22 09:35:51 mrose Interim $  *  *  * $Log:	objectbyname.c,v $  * Revision 7.1  91/02/22  09:35:51  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:12:47  mrose  * Release 6.0  *   */
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
name|struct
name|isobject
modifier|*
name|getisobjectbyname
parameter_list|(
name|descriptor
parameter_list|)
name|char
modifier|*
name|descriptor
decl_stmt|;
block|{
specifier|register
name|struct
name|isobject
modifier|*
name|io
decl_stmt|;
name|isodetailor
argument_list|(
name|NULLCP
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|SLOG
argument_list|(
name|addr_log
argument_list|,
name|LLOG_TRACE
argument_list|,
name|NULLCP
argument_list|,
operator|(
literal|"getisobjectbyname \"%s\""
operator|,
name|descriptor
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|(
name|void
operator|)
name|setisobject
argument_list|(
literal|0
argument_list|)
expr_stmt|;
while|while
condition|(
name|io
operator|=
name|getisobject
argument_list|()
condition|)
if|if
condition|(
name|strcmp
argument_list|(
name|descriptor
argument_list|,
name|io
operator|->
name|io_descriptor
argument_list|)
operator|==
literal|0
condition|)
break|break;
operator|(
name|void
operator|)
name|endisobject
argument_list|()
expr_stmt|;
if|if
condition|(
name|io
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|SLOG
argument_list|(
name|addr_log
argument_list|,
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
operator|(
literal|"\tODE: \"%s\"\tOID: %s"
operator|,
name|io
operator|->
name|io_descriptor
operator|,
name|sprintoid
argument_list|(
operator|&
name|io
operator|->
name|io_identity
argument_list|)
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
else|else
name|SLOG
argument_list|(
name|addr_log
argument_list|,
name|LLOG_EXCEPTIONS
argument_list|,
name|NULLCP
argument_list|,
operator|(
literal|"lookup of object \"%s\" failed"
operator|,
name|descriptor
operator|)
argument_list|)
expr_stmt|;
return|return
name|io
return|;
block|}
end_function

end_unit

