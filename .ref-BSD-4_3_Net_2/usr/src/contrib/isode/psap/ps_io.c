begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ps_io.c - presentation stream I/O dispatch */
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
literal|"$Header: /f/osi/psap/RCS/ps_io.c,v 7.1 91/02/22 09:36:38 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/ps_io.c,v 7.1 91/02/22 09:36:38 mrose Interim $  *  *  * $Log:	ps_io.c,v $  * Revision 7.1  91/02/22  09:36:38  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:13:24  mrose  * Release 6.0  *   */
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
name|ps_io
parameter_list|(
name|ps
parameter_list|,
name|io
parameter_list|,
name|data
parameter_list|,
name|n
parameter_list|,
name|in_line
parameter_list|)
specifier|register
name|PS
name|ps
decl_stmt|;
specifier|register
name|IFP
name|io
decl_stmt|;
specifier|register
name|PElementData
name|data
decl_stmt|;
specifier|register
name|PElementLen
name|n
decl_stmt|;
name|int
name|in_line
decl_stmt|;
block|{
specifier|register
name|int
name|cc
decl_stmt|;
if|if
condition|(
name|io
operator|==
name|NULLIFP
condition|)
return|return
name|ps_seterr
argument_list|(
name|ps
argument_list|,
name|PS_ERR_EOF
argument_list|,
name|NOTOK
argument_list|)
return|;
while|while
condition|(
name|n
operator|>
literal|0
condition|)
switch|switch
condition|(
name|cc
operator|=
call|(
modifier|*
name|io
call|)
argument_list|(
name|ps
argument_list|,
name|data
argument_list|,
name|n
argument_list|,
name|in_line
argument_list|)
condition|)
block|{
case|case
name|NOTOK
case|:
return|return
name|NOTOK
return|;
case|case
name|OK
case|:
return|return
name|ps_seterr
argument_list|(
name|ps
argument_list|,
name|PS_ERR_EOF
argument_list|,
name|NOTOK
argument_list|)
return|;
default|default:
name|data
operator|+=
name|cc
operator|,
name|n
operator|-=
name|cc
expr_stmt|;
name|ps
operator|->
name|ps_byteno
operator|+=
name|cc
expr_stmt|;
break|break;
block|}
return|return
name|OK
return|;
block|}
end_function

end_unit

