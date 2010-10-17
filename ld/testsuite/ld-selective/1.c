begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* _start should be the only thing left after GC.  */
end_comment

begin_expr_stmt
name|void
name|_start
argument_list|()
end_expr_stmt

begin_asm
asm|__asm__("_start");
end_asm

begin_function
name|void
name|_start
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|dropme1
parameter_list|()
block|{ }
end_function

begin_decl_stmt
name|int
name|dropme2
index|[
literal|102
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

