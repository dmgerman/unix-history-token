begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep -e "global_ctors.*@A" %t
end_comment

begin_comment
comment|// RUN: grep -e "global_dtors.*@B" %t
end_comment

begin_comment
comment|// RUN: grep -e "global_ctors.*@C" %t
end_comment

begin_comment
comment|// RUN: grep -e "global_dtors.*@D" %t
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|A
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(constructor
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|B
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(destructor
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|A
parameter_list|()
block|{
name|printf
argument_list|(
literal|"A\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|B
parameter_list|()
block|{
name|printf
argument_list|(
literal|"B\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|static
name|void
name|C
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(constructor
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|static
name|void
name|D
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(destructor
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
name|int
name|foo
parameter_list|()
block|{
return|return
literal|10
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|C
parameter_list|()
block|{
name|printf
argument_list|(
literal|"A: %d\n"
argument_list|,
name|foo
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|D
parameter_list|()
block|{
name|printf
argument_list|(
literal|"B\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

