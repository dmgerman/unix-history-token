begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Normally we should loose foo and keep _start and _init.     With -u foo, we should keep that as well.  */
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

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|".init"
argument_list|)
operator|)
argument_list|)
name|_init
argument_list|()
block|{ }
end_decl_stmt

begin_expr_stmt
name|int
name|foo
argument_list|()
end_expr_stmt

begin_asm
asm|__asm__("foo");
end_asm

begin_function
name|int
name|foo
parameter_list|()
block|{
specifier|static
name|int
name|x
init|=
literal|1
decl_stmt|;
return|return
name|x
operator|++
return|;
block|}
end_function

end_unit

