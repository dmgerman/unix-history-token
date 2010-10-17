begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|int
name|bar
parameter_list|()
block|{
return|return
literal|3
return|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|hide_original_foo
end_pragma

begin_function
name|int
name|hide_original_foo
parameter_list|()
block|{
return|return
literal|1
operator|+
name|bar
argument_list|()
return|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|hide_old_foo
end_pragma

begin_function
name|int
name|hide_old_foo
parameter_list|()
block|{
return|return
literal|10
operator|+
name|bar
argument_list|()
return|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|hide_old_foo1
end_pragma

begin_function
name|int
name|hide_old_foo1
parameter_list|()
block|{
return|return
literal|100
operator|+
name|bar
argument_list|()
return|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|hide_new_foo
end_pragma

begin_function
name|int
name|hide_new_foo
parameter_list|()
block|{
return|return
literal|1000
operator|+
name|bar
argument_list|()
return|;
block|}
end_function

begin_asm
asm|__asm__(".symver hide_original_foo,show_foo@");
end_asm

begin_asm
asm|__asm__(".symver hide_old_foo,show_foo@VERS_1.1");
end_asm

begin_asm
asm|__asm__(".symver hide_old_foo1,show_foo@VERS_1.2");
end_asm

begin_asm
asm|__asm__(".symver hide_new_foo,show_foo@@VERS_2.0");
end_asm

end_unit

