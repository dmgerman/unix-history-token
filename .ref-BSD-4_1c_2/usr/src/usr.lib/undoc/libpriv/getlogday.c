begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)getlogday.c	4.3	(Melbourne)	82/05/30	*/
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
name|getlogday
argument_list|(
name|uid
argument_list|,
name|dmax
argument_list|,
name|dinc
argument_list|,
name|drem
argument_list|)
specifier|register
name|uid
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|short
modifier|*
name|dmax
decl_stmt|,
modifier|*
name|dinc
decl_stmt|,
modifier|*
name|drem
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|dmax
condition|)
operator|*
name|dmax
operator|=
name|mushreq
argument_list|(
name|uid
argument_list|,
name|MM_A_DMAX
argument_list|)
expr_stmt|;
if|if
condition|(
name|dinc
condition|)
operator|*
name|dinc
operator|=
name|mushreq
argument_list|(
name|uid
argument_list|,
name|MM_A_DINC
argument_list|)
expr_stmt|;
if|if
condition|(
name|drem
condition|)
operator|*
name|drem
operator|=
name|mushreq
argument_list|(
name|uid
argument_list|,
name|MM_A_DREM
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

