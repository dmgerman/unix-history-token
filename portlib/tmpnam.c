begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  **	generate temporary file name  **/
end_comment

begin_expr_stmt
name|int
name|__tmpnumber
literal|0
expr_stmt|;
end_expr_stmt

begin_macro
name|tmpnam
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
operator|-
literal|1
argument_list|,
name|s
argument_list|,
literal|"pl%d%c"
argument_list|,
name|getpid
argument_list|()
argument_list|,
literal|'A'
operator|+
name|__tmpnumber
operator|++
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|)
return|;
block|}
end_block

end_unit

