begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|int
name|foo1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|foo2
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|xxx1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xxx2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|bar
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|foo1
operator|==
literal|1
condition|)
name|printf
argument_list|(
literal|"bar OK1\n"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|foo1
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"bar OK2\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|foo2
operator|==
literal|1
condition|)
name|printf
argument_list|(
literal|"bar OK3\n"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|foo2
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"bar OK4\n"
argument_list|)
expr_stmt|;
name|foo1
operator|=
operator|-
literal|1
expr_stmt|;
name|foo2
operator|=
operator|-
literal|1
expr_stmt|;
name|xxx1
argument_list|()
expr_stmt|;
name|xxx2
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

