begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ps_prime.c - prime a presentation stream */
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
literal|"$Header: /f/osi/psap/RCS/ps_prime.c,v 7.2 91/02/22 09:36:39 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/ps_prime.c,v 7.2 91/02/22 09:36:39 mrose Interim $  *  *  * $Log:	ps_prime.c,v $  * Revision 7.2  91/02/22  09:36:39  mrose  * Interim 6.8  *   * Revision 7.1  91/01/07  12:40:37  mrose  * update  *   * Revision 7.0  89/11/23  22:13:25  mrose  * Release 6.0  *   */
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
name|ps_prime
parameter_list|(
name|ps
parameter_list|,
name|waiting
parameter_list|)
specifier|register
name|PS
name|ps
decl_stmt|;
name|int
name|waiting
decl_stmt|;
block|{
if|if
condition|(
name|ps
operator|->
name|ps_primeP
condition|)
return|return
call|(
modifier|*
name|ps
operator|->
name|ps_primeP
call|)
argument_list|(
name|ps
argument_list|,
name|waiting
argument_list|)
return|;
return|return
name|OK
return|;
block|}
end_function

end_unit

