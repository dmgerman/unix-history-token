begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* str2saddr.c - string value to SSAPaddr */
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
literal|"$Header: /f/osi/compat/RCS/str2saddr.c,v 7.1 91/02/22 09:15:56 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/compat/RCS/str2saddr.c,v 7.1 91/02/22 09:15:56 mrose Interim $  *  *  * $Log:	str2saddr.c,v $  * Revision 7.1  91/02/22  09:15:56  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:23:36  mrose  * Release 6.0  *   */
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
file|"isoaddrs.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|struct
name|SSAPaddr
modifier|*
name|str2saddr
parameter_list|(
name|str
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|;
block|{
specifier|register
name|struct
name|PSAPaddr
modifier|*
name|pa
decl_stmt|;
if|if
condition|(
name|pa
operator|=
name|str2paddr
argument_list|(
name|str
argument_list|)
condition|)
return|return
operator|(
operator|&
name|pa
operator|->
name|pa_addr
operator|)
return|;
return|return
name|NULLSA
return|;
block|}
end_function

end_unit

