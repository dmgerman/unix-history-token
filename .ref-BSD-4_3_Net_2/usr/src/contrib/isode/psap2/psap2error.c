begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* psap2error.c - return PSAP error code in string form */
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
literal|"$Header: /f/osi/psap2/RCS/psap2error.c,v 7.2 91/02/22 09:37:27 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap2/RCS/psap2error.c,v 7.2 91/02/22 09:37:27 mrose Interim $  *  *  * $Log:	psap2error.c,v $  * Revision 7.2  91/02/22  09:37:27  mrose  * Interim 6.8  *   * Revision 7.1  91/01/11  07:09:14  mrose  * jpo  *   * Revision 7.0  89/11/23  22:14:16  mrose  * Release 6.0  *   */
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
file|"psap2.h"
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
literal|"Rejected by peer"
block|,
literal|"Reason not specified"
block|,
literal|"Temporary congestion"
block|,
literal|"Local limit exceeded"
block|,
literal|"Called presentation address unknown"
block|,
literal|"Protocol version not supported"
block|,
literal|"Default context not supported"
block|,
literal|"User-data not readable"
block|,
literal|"No PSAP available"
block|,
literal|"Unrecognized PPDU"
block|,
literal|"Unexpected PPDU"
block|,
literal|"Unexpected session service primitive"
block|,
literal|"Unrecognized PPDU parameter"
block|,
literal|"Unexpected PPDU parameter"
block|,
literal|"Invalid PPDU parameter value"
block|,
literal|"Abstract syntax not supported"
block|,
literal|"Proposed transfer syntaxes not supported"
block|,
literal|"Local limit on DCS exceeded"
block|,
literal|"Connect request refused on this network connection"
block|,
literal|"Session disconnect"
block|,
literal|"Protocol error"
block|,
literal|"Peer aborted connection"
block|,
literal|"Invalid parameter"
block|,
literal|"Invalid operation"
block|,
literal|"Timer expired"
block|,
literal|"Indications waiting"
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
name|PErrString
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

