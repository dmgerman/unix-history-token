begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* acsaperror.c - return AcSAP error code in string form */
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
literal|"$Header: /f/osi/acsap/RCS/acsaperror.c,v 7.2 91/02/22 09:14:07 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/acsap/RCS/acsaperror.c,v 7.2 91/02/22 09:14:07 mrose Interim $  *  *  * $Log:	acsaperror.c,v $  * Revision 7.2  91/02/22  09:14:07  mrose  * Interim 6.8  *   * Revision 7.1  91/01/11  07:09:04  mrose  * jpo  *   * Revision 7.0  89/11/23  21:21:48  mrose  * Release 6.0  *   */
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
file|"acsap.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|reject_err0
index|[]
init|=
block|{
literal|"Accepted"
block|,
literal|"Permanent"
block|,
literal|"Transient"
block|,
literal|"Rejected by service-user: null"
block|,
literal|"Rejected by service-user: no reason given"
block|,
literal|"Application context name not supported"
block|,
literal|"Calling AP title not recognized"
block|,
literal|"Calling AP invocation-ID not recognized"
block|,
literal|"Calling AE qualifier not recognized"
block|,
literal|"Calling AE invocation-ID not recognized"
block|,
literal|"Called AP title not recognized"
block|,
literal|"Called AP invocation-ID not recognized"
block|,
literal|"Called AE qualifier not recognized"
block|,
literal|"Called AE invocation-ID not recognized"
block|,
literal|"Rejected by service-provider: null"
block|,
literal|"Rejected by service-provider: no reason given"
block|,
literal|"No common acse version"
block|,
literal|"Address unknown"
block|,
literal|"Connect request refused on this network connection"
block|,
literal|"Local limit exceeded"
block|,
literal|"Presentation disconnect"
block|,
literal|"Protocol error"
block|,
literal|"Peer aborted association"
block|,
literal|"Invalid parameter"
block|,
literal|"Invalid operation"
block|,
literal|"Timer expired"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|reject_err0_cnt
init|=
sizeof|sizeof
name|reject_err0
operator|/
sizeof|sizeof
name|reject_err0
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|char
modifier|*
name|AcErrString
parameter_list|(
name|code
parameter_list|)
specifier|register
name|int
name|code
decl_stmt|;
block|{
specifier|static
name|char
name|buffer
index|[
literal|50
index|]
decl_stmt|;
if|if
condition|(
name|code
operator|<
name|reject_err0_cnt
condition|)
return|return
name|reject_err0
index|[
name|code
index|]
return|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"unknown error code %d"
argument_list|,
name|code
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
end_function

end_unit

