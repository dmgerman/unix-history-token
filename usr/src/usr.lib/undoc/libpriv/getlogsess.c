begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)getlogsess.c	4.3	(Melbourne)	82/05/30	*/
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
name|getlogsess
argument_list|(
name|uid
argument_list|,
name|smax
argument_list|,
name|lgap
argument_list|,
name|left
argument_list|)
specifier|register
name|uid
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|short
modifier|*
name|smax
decl_stmt|,
modifier|*
name|lgap
decl_stmt|,
modifier|*
name|left
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|smax
condition|)
operator|*
name|smax
operator|=
name|mushreq
argument_list|(
name|uid
argument_list|,
name|MM_A_SMAX
argument_list|)
expr_stmt|;
if|if
condition|(
name|lgap
condition|)
operator|*
name|lgap
operator|=
name|mushreq
argument_list|(
name|uid
argument_list|,
name|MM_A_LGAP
argument_list|)
expr_stmt|;
if|if
condition|(
name|left
condition|)
operator|*
name|left
operator|=
name|mushreq
argument_list|(
name|uid
argument_list|,
name|MM_A_LEFT
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

