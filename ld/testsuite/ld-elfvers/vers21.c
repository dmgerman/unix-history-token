begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_asm
asm|__asm__(".symver _old_foo,foo@VERS.0");
end_asm

begin_asm
asm|__asm__(".symver _old_bar,bar@VERS.0");
end_asm

begin_asm
asm|__asm__(".symver _old_foobar,foobar@VERS.0");
end_asm

begin_asm
asm|__asm__(".weak  _old_bar");
end_asm

begin_function
name|int
name|bar
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|_old_bar
parameter_list|()
block|{
return|return
name|bar
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|foo
parameter_list|()
block|{
return|return
literal|2
return|;
block|}
end_function

begin_function
name|int
name|_old_foo
parameter_list|()
block|{
return|return
name|foo
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|int
name|_old_foobar
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|foobar
init|=
literal|1
decl_stmt|;
end_decl_stmt

end_unit

