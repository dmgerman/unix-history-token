begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	signal.c	4.3	83/07/02	*/
end_comment

begin_comment
comment|/*  * Almost backwards compatible signal.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_macro
name|int
argument_list|(
argument|* signal(s, a)
argument_list|)
end_macro

begin_expr_stmt
operator|(
operator|)
name|int
name|s
operator|,
call|(
modifier|*
name|a
call|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|struct
name|sigvec
name|osv
decl_stmt|,
name|sv
decl_stmt|;
name|sv
operator|.
name|sv_handler
operator|=
name|a
expr_stmt|;
name|sv
operator|.
name|sv_mask
operator|=
name|sv
operator|.
name|sv_onstack
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|sigvec
argument_list|(
name|s
argument_list|,
operator|&
name|sv
argument_list|,
operator|&
name|osv
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
name|BADSIG
operator|)
return|;
return|return
operator|(
name|osv
operator|.
name|sv_handler
operator|)
return|;
block|}
end_block

end_unit

