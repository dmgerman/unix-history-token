begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* oper_preject.c - deal with preject of an operation */
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
literal|"$Header: /f/osi/quipu/RCS/oper_preject.c,v 7.2 91/02/22 09:39:35 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/quipu/RCS/oper_preject.c,v 7.2 91/02/22 09:39:35 mrose Interim $  *  *  * $Log:	oper_preject.c,v $  * Revision 7.2  91/02/22  09:39:35  mrose  * Interim 6.8  *   * Revision 7.1  90/10/17  11:54:34  mrose  * sync  *   * Revision 7.0  89/11/23  22:17:53  mrose  * Release 6.0  *   */
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
name|oper_preject
argument_list|(
argument|conn
argument_list|,
argument|dp
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
name|DSAPpreject
modifier|*
name|dp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|oper_act
modifier|*
name|on
decl_stmt|;
name|DLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_TRACE
argument_list|,
operator|(
literal|"oper_preject"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|dp
operator|->
name|dp_id
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* No identified operation to reject! */
return|return;
block|}
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
name|dp
operator|->
name|dp_id
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
literal|"Unlocatable P-REJECT.INDICATION : %d"
operator|,
name|dp
operator|->
name|dp_reason
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|oper_fail_wakeup
argument_list|(
name|on
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

