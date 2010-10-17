begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Testcase to verify that reference to foo@BAR and a definition of foo@@BAR  * are not treated as a multiple def.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|bar1
init|=
literal|"asdf"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|bar2
init|=
literal|"asdf"
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|old_foo1
parameter_list|()
function_decl|;
end_function_decl

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

begin_function
name|int
name|original_foo
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

begin_function
name|int
name|old_foo
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

begin_function
name|int
name|new_foo
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

begin_function
name|int
name|main
parameter_list|()
block|{
name|old_foo1
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_asm
asm|__asm__(".symver original_foo,foo@");
end_asm

begin_asm
asm|__asm__(".symver old_foo,foo@VERS_1.1");
end_asm

begin_asm
asm|__asm__(".symver old_foo1,foo@VERS_1.2");
end_asm

begin_asm
asm|__asm__(".symver new_foo,foo@@VERS_1.2");
end_asm

end_unit

