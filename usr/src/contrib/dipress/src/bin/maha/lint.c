begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * beta 4.3BSD doesn't have a declaration in its lint library  * for "execlp" so one is included here.  */
end_comment

begin_comment
comment|/*VARARGS*/
end_comment

begin_macro
name|execlp
argument_list|(
argument|f
argument_list|,
argument|a
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|f
decl_stmt|,
modifier|*
name|a
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|(
name|void
operator|)
name|f
expr_stmt|;
operator|(
name|void
operator|)
name|a
expr_stmt|;
block|}
end_block

end_unit

