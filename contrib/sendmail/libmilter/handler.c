begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1999-2000 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|id
index|[]
init|=
literal|"@(#)$Id: handler.c,v 8.19.4.2 2000/07/14 06:16:57 msk Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! lint */
end_comment

begin_if
if|#
directive|if
name|_FFR_MILTER
end_if

begin_include
include|#
directive|include
file|"libmilter.h"
end_include

begin_comment
comment|/* **  HANDLE_SESSION -- Handle a connected session in its own context ** **	Parameters: **		ctx -- context structure ** **	Returns: **		MI_SUCCESS/MI_FAILURE */
end_comment

begin_function
name|int
name|mi_handle_session
parameter_list|(
name|ctx
parameter_list|)
name|SMFICTX_PTR
name|ctx
decl_stmt|;
block|{
name|int
name|ret
decl_stmt|;
if|if
condition|(
name|ctx
operator|==
name|NULL
condition|)
return|return
name|MI_FAILURE
return|;
name|ctx
operator|->
name|ctx_id
operator|=
operator|(
name|sthread_t
operator|)
name|sthread_get_id
argument_list|()
expr_stmt|;
comment|/* 	**  detach so resources are free when the thread returns 	**  if we ever "wait" for threads, this call must be removed 	*/
if|if
condition|(
name|pthread_detach
argument_list|(
name|ctx
operator|->
name|ctx_id
argument_list|)
operator|!=
literal|0
condition|)
return|return
name|MI_FAILURE
return|;
name|ret
operator|=
name|mi_engine
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
if|if
condition|(
name|ValidSocket
argument_list|(
name|ctx
operator|->
name|ctx_sd
argument_list|)
condition|)
operator|(
name|void
operator|)
name|close
argument_list|(
name|ctx
operator|->
name|ctx_sd
argument_list|)
expr_stmt|;
if|if
condition|(
name|ctx
operator|->
name|ctx_reply
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|ctx
operator|->
name|ctx_reply
argument_list|)
expr_stmt|;
if|if
condition|(
name|ctx
operator|->
name|ctx_privdata
operator|!=
name|NULL
condition|)
block|{
name|smi_log
argument_list|(
name|SMI_LOG_WARN
argument_list|,
literal|"%s: private data not NULL"
argument_list|,
name|ctx
operator|->
name|ctx_smfi
operator|->
name|xxfi_name
argument_list|)
expr_stmt|;
block|}
name|mi_clr_macros
argument_list|(
name|ctx
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|ctx
operator|=
name|NULL
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_MILTER */
end_comment

end_unit

