begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|deallocate_foo
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
modifier|*
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
modifier|*
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|abort
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|foobar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|foobar
parameter_list|()
block|{
if|if
condition|(
operator|&
name|deallocate_foo
operator|!=
name|bar
argument_list|()
operator|||
operator|&
name|deallocate_foo
operator|!=
name|foo
argument_list|()
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|deallocate_foo
condition|)
name|printf
argument_list|(
literal|"weak deallocate_foo\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"strong deallocate_foo\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
modifier|*
name|bar
parameter_list|()
block|{
return|return
operator|&
name|deallocate_foo
return|;
block|}
end_function

end_unit

