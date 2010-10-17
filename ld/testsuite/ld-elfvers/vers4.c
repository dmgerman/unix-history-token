begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Testcase to make sure that a versioned symbol definition in an  * application correctly defines the version node, if and only if  * the actual symbol is exported.  This is built both with and without  * -export-dynamic.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
specifier|extern
name|int
name|foo
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

begin_asm
asm|__asm__(".symver new_foo,foo@@VERS_2.0");
end_asm

begin_function
name|int
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|foo
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

