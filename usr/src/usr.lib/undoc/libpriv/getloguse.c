begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)getloguse.c	4.3	(Melbourne)	82/05/30	*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/quota.h>
end_include

begin_include
include|#
directive|include
file|<mushmuck.h>
end_include

begin_function_decl
name|long
name|mushlreq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|short
name|mushreq
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|getloguse
argument_list|(
name|uid
argument_list|,
name|usage
argument_list|,
name|maxuse
argument_list|,
name|sess
argument_list|)
specifier|register
name|uid
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|long
modifier|*
name|usage
decl_stmt|,
modifier|*
name|maxuse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|sess
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|usage
condition|)
operator|*
name|usage
operator|=
name|mushlreq
argument_list|(
name|uid
argument_list|,
name|MM_A_USED
argument_list|)
expr_stmt|;
if|if
condition|(
name|maxuse
condition|)
operator|*
name|maxuse
operator|=
name|mushlreq
argument_list|(
name|uid
argument_list|,
name|MM_A_MAXUSE
argument_list|)
expr_stmt|;
if|if
condition|(
name|sess
condition|)
operator|*
name|sess
operator|=
name|mushreq
argument_list|(
name|uid
argument_list|,
name|MM_A_SESS
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

