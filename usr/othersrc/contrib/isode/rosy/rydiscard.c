begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rydiscard.c - ROSY: discard invocation in progress */
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
literal|"$Header: /f/osi/rosy/RCS/rydiscard.c,v 7.1 91/02/22 09:41:53 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/rosy/RCS/rydiscard.c,v 7.1 91/02/22 09:41:53 mrose Interim $  *  *  * $Log:	rydiscard.c,v $  * Revision 7.1  91/02/22  09:41:53  mrose  * Interim 6.8  *   * Revision 6.0  89/03/18  23:42:46  mrose  * Release 5.0  *   */
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
comment|*/
end_comment

begin_function_decl
name|int
name|do_response
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|DISCARD */
end_comment

begin_function
name|int
name|RyDiscard
parameter_list|(
name|sd
parameter_list|,
name|id
parameter_list|,
name|roi
parameter_list|)
name|int
name|sd
decl_stmt|,
name|id
decl_stmt|;
name|struct
name|RoSAPindication
modifier|*
name|roi
decl_stmt|;
block|{
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
name|OPB_INITIATOR
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
name|opb
operator|->
name|opb_resfnx
operator|=
name|opb
operator|->
name|opb_errfnx
operator|=
name|do_response
expr_stmt|;
return|return
name|OK
return|;
block|}
end_function

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|do_response
parameter_list|(
name|sd
parameter_list|,
name|id
parameter_list|,
name|dummy
parameter_list|,
name|value
parameter_list|,
name|roi
parameter_list|)
name|int
name|sd
decl_stmt|,
name|id
decl_stmt|,
name|dummy
decl_stmt|;
name|caddr_t
name|value
decl_stmt|;
name|struct
name|RoSAPindication
modifier|*
name|roi
decl_stmt|;
block|{
return|return
name|OK
return|;
block|}
end_function

end_unit

