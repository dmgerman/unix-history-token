begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* servbyname.c - getisoserventbyname */
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
literal|"$Header: /f/osi/compat/RCS/servbyname.c,v 7.1 91/02/22 09:15:48 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/compat/RCS/servbyname.c,v 7.1 91/02/22 09:15:48 mrose Interim $  *  *  * $Log:	servbyname.c,v $  * Revision 7.1  91/02/22  09:15:48  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:23:26  mrose  * Release 6.0  *   */
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
file|"general.h"
end_include

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_include
include|#
directive|include
file|"isoservent.h"
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
name|isoservent
modifier|*
name|getisoserventbyname
parameter_list|(
name|entity
parameter_list|,
name|provider
parameter_list|)
name|char
modifier|*
name|entity
decl_stmt|,
decl|*
name|provider
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|struct
name|isoservent
modifier|*
name|is
decl_stmt|;
name|isodetailor
argument_list|(
name|NULLCP
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|DLOG
argument_list|(
name|addr_log
argument_list|,
name|LLOG_TRACE
argument_list|,
operator|(
literal|"getisoserventbyname \"%s\" \"%s\""
operator|,
name|entity
operator|,
name|provider
operator|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|setisoservent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
while|while
condition|(
name|is
operator|=
name|getisoservent
argument_list|()
condition|)
if|if
condition|(
name|strcmp
argument_list|(
name|entity
argument_list|,
name|is
operator|->
name|is_entity
argument_list|)
operator|==
literal|0
operator|&&
name|strcmp
argument_list|(
name|provider
argument_list|,
name|is
operator|->
name|is_provider
argument_list|)
operator|==
literal|0
condition|)
break|break;
operator|(
name|void
operator|)
name|endisoservent
argument_list|()
expr_stmt|;
if|if
condition|(
name|is
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|addr_log
operator|->
name|ll_events
operator|&
name|LLOG_DEBUG
condition|)
name|_printsrv
argument_list|(
name|is
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
literal|"lookup of local service %s/%s failed"
operator|,
name|provider
operator|,
name|entity
operator|)
argument_list|)
expr_stmt|;
return|return
name|is
return|;
block|}
end_block

end_unit

