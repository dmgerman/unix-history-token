begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* conn_abort.c - abort association */
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
literal|"$Header: /f/osi/quipu/RCS/conn_abort.c,v 7.2 91/02/22 09:38:27 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * $Header: /f/osi/quipu/RCS/conn_abort.c,v 7.2 91/02/22 09:38:27 mrose Interim $  *  *  * $Log:	conn_abort.c,v $  * Revision 7.2  91/02/22  09:38:27  mrose  * Interim 6.8  *   * Revision 7.1  90/10/17  11:53:19  mrose  * sync  *   * Revision 7.0  89/11/23  22:16:43  mrose  * Release 6.0  *   */
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
file|"quipu/dsap.h"
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

begin_function_decl
name|struct
name|connection
modifier|*
name|conn_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|conn_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ds_log
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|net_send_abort
argument_list|(
name|conn
argument_list|)
specifier|register
expr|struct
name|connection
operator|*
name|conn
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|int
name|result
decl_stmt|;
name|struct
name|DSAPindication
name|di_s
decl_stmt|;
name|struct
name|DSAPindication
modifier|*
name|di
init|=
operator|&
name|di_s
decl_stmt|;
name|struct
name|DSAPabort
modifier|*
name|da
init|=
operator|&
operator|(
name|di
operator|->
name|di_abort
operator|)
decl_stmt|;
name|DLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_TRACE
argument_list|,
operator|(
literal|"net_send_abort"
operator|)
argument_list|)
expr_stmt|;
name|DLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_NOTICE
argument_list|,
operator|(
literal|"D-ABORT.REQUEST:<%d>"
operator|,
name|conn
operator|->
name|cn_ad
operator|)
argument_list|)
expr_stmt|;
name|result
operator|=
name|DUAbortRequest
argument_list|(
name|conn
operator|->
name|cn_ad
argument_list|,
name|di
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|!=
name|OK
condition|)
block|{
name|ds_log
argument_list|(
name|da
argument_list|,
literal|"D-ABORT.REQUEST"
argument_list|)
expr_stmt|;
block|}
name|conn
operator|->
name|cn_state
operator|=
name|CN_FAILED
expr_stmt|;
name|conn
operator|->
name|cn_ad
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ADT: Needs improving */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|void
name|ds_log
parameter_list|(
name|da
parameter_list|,
name|str
parameter_list|)
name|struct
name|DSAPabort
modifier|*
name|da
decl_stmt|;
name|char
modifier|*
name|str
decl_stmt|;
block|{
name|LLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_EXCEPTIONS
argument_list|,
operator|(
literal|"DSAP abort : %s"
operator|,
name|str
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

