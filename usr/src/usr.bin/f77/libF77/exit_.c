begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	"@(#)exit_.c	1.2"  */
end_comment

begin_macro
name|exit_
argument_list|(
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|long
modifier|*
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|exitcode
decl_stmt|;
if|#
directive|if
name|vax
if|if
condition|(
name|nargs
argument_list|()
operator|==
literal|0
condition|)
name|exitcode
operator|=
literal|0
expr_stmt|;
else|else
endif|#
directive|endif
endif|vax
name|exitcode
operator|=
operator|*
name|n
expr_stmt|;
comment|/* take any segmentation violation here */
name|f_exit
argument_list|()
expr_stmt|;
name|_cleanup
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|exitcode
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

