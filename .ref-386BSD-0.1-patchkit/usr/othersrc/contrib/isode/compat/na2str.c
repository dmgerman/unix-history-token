begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* na2str.c - pretty-print NSAPaddr */
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
literal|"$Header: /f/osi/compat/RCS/na2str.c,v 7.2 91/02/22 09:15:37 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/compat/RCS/na2str.c,v 7.2 91/02/22 09:15:37 mrose Interim $  *  *  * $Log:	na2str.c,v $  * Revision 7.2  91/02/22  09:15:37  mrose  * Interim 6.8  *   * Revision 7.1  90/07/09  14:32:05  mrose  * sync  *   * Revision 7.0  89/11/23  21:23:19  mrose  * Release 6.0  *   */
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
comment|Network Address to String */
end_comment

begin_function
name|char
modifier|*
name|na2str
parameter_list|(
name|na
parameter_list|)
specifier|register
name|struct
name|NSAPaddr
modifier|*
name|na
decl_stmt|;
block|{
switch|switch
condition|(
name|na
operator|->
name|na_stack
condition|)
block|{
case|case
name|NA_TCP
case|:
return|return
name|na
operator|->
name|na_domain
return|;
case|case
name|NA_X25
case|:
case|case
name|NA_BRG
case|:
return|return
name|na
operator|->
name|na_dte
return|;
case|case
name|NA_NSAP
case|:
default|default:
return|return
name|sel2str
argument_list|(
name|na
operator|->
name|na_address
argument_list|,
name|na
operator|->
name|na_addrlen
argument_list|,
literal|0
argument_list|)
return|;
block|}
block|}
end_function

end_unit

