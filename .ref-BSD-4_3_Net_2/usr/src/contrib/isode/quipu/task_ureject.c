begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ns_ro_ureject.c - */
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
literal|"$Header: /f/osi/quipu/RCS/task_ureject.c,v 7.1 91/02/22 09:40:04 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/quipu/RCS/task_ureject.c,v 7.1 91/02/22 09:40:04 mrose Interim $  *  *  * $Log:	task_ureject.c,v $  * Revision 7.1  91/02/22  09:40:04  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:18:17  mrose  * Release 6.0  *   */
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
file|"rosap.h"
end_include

begin_include
include|#
directive|include
file|"quipu/util.h"
end_include

begin_include
include|#
directive|include
file|"quipu/connection.h"
end_include

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|log_dsap
decl_stmt|;
end_decl_stmt

begin_macro
name|send_ro_ureject
argument_list|(
argument|ad
argument_list|,
argument|id_p
argument_list|,
argument|urej
argument_list|)
end_macro

begin_decl_stmt
name|int
name|ad
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|id_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|urej
decl_stmt|;
end_decl_stmt

begin_block
block|{
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
name|roi_s
decl_stmt|;
name|struct
name|RoSAPpreject
modifier|*
name|rop
init|=
operator|&
operator|(
name|roi
operator|->
name|roi_preject
operator|)
decl_stmt|;
name|DLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_TRACE
argument_list|,
operator|(
literal|"send_ro_ureject()"
operator|)
argument_list|)
expr_stmt|;
name|watch_dog
argument_list|(
literal|"RoURejectRequest"
argument_list|)
expr_stmt|;
if|if
condition|(
name|RoURejectRequest
argument_list|(
name|ad
argument_list|,
name|id_p
argument_list|,
name|urej
argument_list|,
name|ROS_NOPRIO
argument_list|,
name|roi
argument_list|)
operator|==
name|NOTOK
condition|)
block|{
name|watch_dog_reset
argument_list|()
expr_stmt|;
name|LLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_EXCEPTIONS
argument_list|,
operator|(
literal|"RO-U-REJECT.REQUEST: %s"
operator|,
name|RoErrString
argument_list|(
name|rop
operator|->
name|rop_reason
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ROS_FATAL
argument_list|(
name|rop
operator|->
name|rop_reason
argument_list|)
operator|||
operator|(
name|rop
operator|->
name|rop_reason
operator|==
name|ROS_PARAMETER
operator|)
condition|)
block|{
name|LLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_FATAL
argument_list|,
operator|(
literal|"RoUReject fatal PReject"
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
name|watch_dog_reset
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

