begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rosaperror.c - return RoSAP error code in string form */
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
literal|"$Header: /f/osi/rosap/RCS/rosaperror.c,v 7.2 91/02/22 09:41:29 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/rosap/RCS/rosaperror.c,v 7.2 91/02/22 09:41:29 mrose Interim $  *  * Based on an TCP-based implementation by George Michaelson of University  * College London.  *  *  * $Log:	rosaperror.c,v $  * Revision 7.2  91/02/22  09:41:29  mrose  * Interim 6.8  *   * Revision 7.1  91/01/11  07:09:20  mrose  * jpo  *   * Revision 6.0  89/03/18  23:42:24  mrose  * Release 5.0  *   */
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
file|"rosap.h"
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
literal|"Authentication failure"
block|,
literal|"Busy"
block|,
literal|"Unrecognized APDU"
block|,
literal|"Mistyped APDU"
block|,
literal|"Badly structured APDU"
block|,
literal|"Duplicate invocation"
block|,
literal|"Unrecognized operation"
block|,
literal|"Mistyped argument"
block|,
literal|"Resource limitation"
block|,
literal|"Initiator releasing"
block|,
literal|"Unrecognized linked ID"
block|,
literal|"Linked response unexpected"
block|,
literal|"Unexpected child operation"
block|,
literal|"Unrecognized invocation"
block|,
literal|"Result response unexpected"
block|,
literal|"Mistyped result"
block|,
literal|"Unrecognized invocation"
block|,
literal|"Error response unexpected"
block|,
literal|"Unrecognized error"
block|,
literal|"Unexpected error"
block|,
literal|"Mistyped parameter"
block|,
literal|"Address unknown"
block|,
literal|"Connect request refused on this network connection"
block|,
literal|"Session disconnect"
block|,
literal|"Protocol error"
block|,
literal|"Congestion at RoSAP"
block|,
literal|"Remote system problem"
block|,
literal|"Association done via async handler"
block|,
literal|"Peer aborted association"
block|,
literal|"RTS disconnect"
block|,
literal|"Presentation disconnect"
block|,
literal|"ACS disconnect"
block|,
literal|"Invalid parameter"
block|,
literal|"Invalid operation"
block|,
literal|"Timer expired"
block|,
literal|"Indications waiting"
block|,
literal|"APDU not transferred"
block|,
literal|"Stub interrupted"
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
name|RoErrString
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
literal|"unknown error code 0x%x"
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

