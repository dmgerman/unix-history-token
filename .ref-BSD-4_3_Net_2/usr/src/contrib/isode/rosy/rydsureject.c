begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rydsureject.c - ROSY: reject invocation */
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
literal|"$Header: /f/osi/rosy/RCS/rydsureject.c,v 7.1 91/02/22 09:41:59 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/rosy/RCS/rydsureject.c,v 7.1 91/02/22 09:41:59 mrose Interim $  *  *  * $Log:	rydsureject.c,v $  * Revision 7.1  91/02/22  09:41:59  mrose  * Interim 6.8  *   * Revision 6.0  89/03/18  23:42:51  mrose  * Release 5.0  *   */
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
file|"rosy.h"
end_include

begin_define
define|#
directive|define
name|missingP
parameter_list|(
name|p
parameter_list|)
define|\
value|{ \     if (p == NULL) \ 	return rosaplose (roi, ROS_PARAMETER, NULLCP, \ 			    "mandatory parameter \"%s\" missing", "p"); \ }
end_define

begin_comment
comment|/*
comment|U-REJECT */
end_comment

begin_function
name|int
name|RyDsUReject
parameter_list|(
name|sd
parameter_list|,
name|id
parameter_list|,
name|reason
parameter_list|,
name|priority
parameter_list|,
name|roi
parameter_list|)
name|int
name|sd
decl_stmt|;
name|int
name|id
decl_stmt|,
name|reason
decl_stmt|,
name|priority
decl_stmt|;
name|struct
name|RoSAPindication
modifier|*
name|roi
decl_stmt|;
block|{
name|int
name|result
decl_stmt|;
specifier|register
name|struct
name|opsblk
modifier|*
name|opb
decl_stmt|;
name|missingP
argument_list|(
name|roi
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|opb
operator|=
name|findopblk
argument_list|(
name|sd
argument_list|,
name|id
argument_list|,
name|OPB_RESPONDER
argument_list|)
operator|)
operator|==
name|NULLOPB
condition|)
return|return
name|rosaplose
argument_list|(
name|roi
argument_list|,
name|ROS_PARAMETER
argument_list|,
name|NULLCP
argument_list|,
literal|"invocation %d not in progress on association %d"
argument_list|,
name|id
argument_list|,
name|sd
argument_list|)
return|;
if|if
condition|(
operator|(
name|result
operator|=
name|RoURejectRequest
argument_list|(
name|sd
argument_list|,
operator|&
name|id
argument_list|,
name|reason
argument_list|,
name|priority
argument_list|,
name|roi
argument_list|)
operator|)
operator|!=
name|NOTOK
condition|)
name|freeopblk
argument_list|(
name|opb
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

end_unit

