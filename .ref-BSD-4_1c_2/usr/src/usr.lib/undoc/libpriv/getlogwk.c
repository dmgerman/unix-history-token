begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)getlogwk.c	4.3	(Melbourne)	82/05/30	*/
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
name|getlogwk
argument_list|(
name|uid
argument_list|,
name|wmax
argument_list|,
name|winc
argument_list|,
name|wrem
argument_list|)
specifier|register
name|uid
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|short
modifier|*
name|wmax
decl_stmt|,
modifier|*
name|winc
decl_stmt|,
modifier|*
name|wrem
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|wmax
condition|)
operator|*
name|wmax
operator|=
name|mushreq
argument_list|(
name|uid
argument_list|,
name|MM_A_WMAX
argument_list|)
expr_stmt|;
if|if
condition|(
name|winc
condition|)
operator|*
name|winc
operator|=
name|mushreq
argument_list|(
name|uid
argument_list|,
name|MM_A_WINC
argument_list|)
expr_stmt|;
if|if
condition|(
name|wrem
condition|)
operator|*
name|wrem
operator|=
name|mushreq
argument_list|(
name|uid
argument_list|,
name|MM_A_WREM
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

