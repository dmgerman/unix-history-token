begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* oper_ureject.c - deal with user rejection of an operation */
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
literal|"$Header: /f/osi/quipu/RCS/oper_ureject.c,v 7.3 91/02/22 09:39:37 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * $Header: /f/osi/quipu/RCS/oper_ureject.c,v 7.3 91/02/22 09:39:37 mrose Interim $  *  *  * $Log:	oper_ureject.c,v $  * Revision 7.3  91/02/22  09:39:37  mrose  * Interim 6.8  *   * Revision 7.2  90/10/17  11:54:36  mrose  * sync  *   * Revision 7.1  90/03/15  11:19:05  mrose  * quipu-sync  *   * Revision 7.0  89/11/23  22:17:55  mrose  * Release 6.0  *   */
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
name|oper_ureject
argument_list|(
argument|conn
argument_list|,
argument|rou
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|connection
modifier|*
name|conn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|RoSAPureject
modifier|*
name|rou
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|DLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_TRACE
argument_list|,
operator|(
literal|"oper_ureject"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|rou
operator|->
name|rou_noid
condition|)
block|{
name|LLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_EXCEPTIONS
argument_list|,
operator|(
literal|"Non-specific U-REJECT.INDICATION : %d (%d)"
operator|,
name|rou
operator|->
name|rou_reason
operator|,
name|conn
operator|->
name|cn_ad
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|struct
name|oper_act
modifier|*
name|on
decl_stmt|;
for|for
control|(
name|on
operator|=
name|conn
operator|->
name|cn_operlist
init|;
name|on
operator|!=
name|NULLOPER
condition|;
name|on
operator|=
name|on
operator|->
name|on_next_conn
control|)
if|if
condition|(
name|on
operator|->
name|on_id
operator|==
name|rou
operator|->
name|rou_id
condition|)
break|break;
if|if
condition|(
name|on
operator|==
name|NULLOPER
condition|)
block|{
name|LLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_EXCEPTIONS
argument_list|,
operator|(
literal|"Unlocatable U-REJECT.INDICATION : %d (%d)"
operator|,
name|rou
operator|->
name|rou_reason
operator|,
name|conn
operator|->
name|cn_ad
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|on
operator|->
name|on_state
operator|==
name|ON_ABANDONED
condition|)
block|{
name|LLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_NOTICE
argument_list|,
operator|(
literal|"oper_result - operation had been abandoned"
operator|)
argument_list|)
expr_stmt|;
name|oper_extract
argument_list|(
name|on
argument_list|)
expr_stmt|;
return|return;
block|}
name|oper_fail_wakeup
argument_list|(
name|on
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

