begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* For compilation instructions see basic1.c. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|baz
init|=
literal|42
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|private_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|val
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unused_data
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|bar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|unused1
parameter_list|()
block|{
name|bar
argument_list|(
name|baz
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|inc
parameter_list|()
block|{
return|return
operator|++
name|private_int
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|foo
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
return|return
name|bar
argument_list|(
name|arg
operator|+
name|val
argument_list|)
operator|+
name|inc
argument_list|()
operator|+
name|baz
operator|++
return|;
block|}
end_function

begin_comment
comment|/* This file was also used to create basic2-custom-linetable.macho.x86_64.o    with a custom clang that had different settings for the linetable    encoding constants: line_base == -1 and line_range == 4.     clang -c -g basic2.c -o basic2-custom-linetable.macho.x86_64.o  */
end_comment

end_unit

