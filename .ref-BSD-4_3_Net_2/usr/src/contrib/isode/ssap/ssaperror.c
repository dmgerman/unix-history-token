begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ssaperror.c - return SSAP error code in string form */
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
literal|"$Header: /f/osi/ssap/RCS/ssaperror.c,v 7.2 91/02/22 09:45:45 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/ssap/RCS/ssaperror.c,v 7.2 91/02/22 09:45:45 mrose Interim $  *  *  * $Log:	ssaperror.c,v $  * Revision 7.2  91/02/22  09:45:45  mrose  * Interim 6.8  *   * Revision 7.1  91/01/11  07:09:17  mrose  * jpo  *   * Revision 7.0  89/11/23  22:25:25  mrose  * Release 6.0  *   */
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
file|"ssap.h"
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
literal|"Reason not specified"
block|,
literal|"Temporary congestion"
block|,
literal|"Rejected"
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

begin_decl_stmt
specifier|static
name|char
modifier|*
name|reject_err8
index|[]
init|=
block|{
literal|"unknown error code 0x80"
block|,
literal|"SSAP identifier unknown"
block|,
literal|"SS-user not attached to SSAP"
block|,
literal|"Congestion at SSAP"
block|,
literal|"Proposed protocol versions not supported"
block|,
literal|"Address unknown"
block|,
literal|"Connect request refused on this network connection"
block|,
literal|"Transport disconnect"
block|,
literal|"Provider-initiated abort"
block|,
literal|"Protocol error"
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
name|reject_err8_cnt
init|=
sizeof|sizeof
name|reject_err8
operator|/
sizeof|sizeof
name|reject_err8
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
name|SErrString
parameter_list|(
name|code
parameter_list|)
specifier|register
name|int
name|code
decl_stmt|;
block|{
specifier|register
name|int
name|fcode
decl_stmt|;
specifier|static
name|char
name|buffer
index|[
literal|50
index|]
decl_stmt|;
name|code
operator|&=
literal|0xff
expr_stmt|;
if|if
condition|(
name|code
operator|&
name|SC_BASE
condition|)
block|{
if|if
condition|(
operator|(
name|fcode
operator|=
name|code
operator|&
operator|~
name|SC_BASE
operator|)
operator|<
name|reject_err8_cnt
condition|)
return|return
name|reject_err8
index|[
name|fcode
index|]
return|;
block|}
elseif|else
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

