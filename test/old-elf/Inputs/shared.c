begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i
init|=
literal|42
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Undefined weak function in a dynamic library.
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
end_macro

begin_function_decl
name|void
name|weakfoo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Regular function in a dynamic library.
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
comment|// Try to call weakfoo so that the reference to weekfoo will be included in
comment|// the resulting .so file.
if|if
condition|(
name|weakfoo
condition|)
name|weakfoo
argument_list|()
expr_stmt|;
name|puts
argument_list|(
literal|"Fooo!!"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

