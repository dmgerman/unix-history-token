begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dsapreject.c - DSAP: Reject a remote operations event */
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
literal|"$Header: /f/osi/dsap/net/RCS/dsapreject.c,v 7.1 91/02/22 09:21:24 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/dsap/net/RCS/dsapreject.c,v 7.1 91/02/22 09:21:24 mrose Interim $  *  *  * $Log:	dsapreject.c,v $  * Revision 7.1  91/02/22  09:21:24  mrose  * Interim 6.8  *   * Revision 7.0  90/07/26  14:45:57  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *                                NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_include
include|#
directive|include
file|"quipu/util.h"
end_include

begin_include
include|#
directive|include
file|"quipu/dsap.h"
end_include

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|log_dsap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|DRejectRequest
parameter_list|(
name|sd
parameter_list|,
name|reason
parameter_list|,
name|id
parameter_list|)
name|int
name|sd
decl_stmt|;
name|int
name|reason
decl_stmt|;
name|int
name|id
decl_stmt|;
block|{
name|int
name|result
decl_stmt|;
name|struct
name|RoSAPindication
name|roi_s
decl_stmt|;
name|struct
name|RoSAPindication
modifier|*
name|roi
init|=
operator|&
operator|(
name|roi_s
operator|)
decl_stmt|;
name|DLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_TRACE
argument_list|,
operator|(
literal|"DRejectRequest()"
operator|)
argument_list|)
expr_stmt|;
name|watch_dog
argument_list|(
literal|"RoURejectRequest"
argument_list|)
expr_stmt|;
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
name|ROS_NOPRIO
argument_list|,
name|roi
argument_list|)
expr_stmt|;
name|watch_dog_reset
argument_list|()
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|NOTOK
condition|)
block|{
name|LLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_EXCEPTIONS
argument_list|,
operator|(
literal|"DBindReject: RoURejectRequest failed"
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

